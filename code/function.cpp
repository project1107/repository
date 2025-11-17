#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

// 数学函数定义
double func1(double x) { return sin(x); }             // 正弦函数
double func2(double x) { return cos(x); }             // 余弦函数
double func3(double x) { return tan(x); }             // 正切函数
double func4(double x) { return exp(-x*x); }          // 高斯函数
double func5(double x) { return 0.2*x*x*x - 1.5*x; } // 三次函数
double func6(double x) { return 1.0/(1+exp(-x)); }   // Sigmoid函数

// 坐标轴类
class Axes {
public:
    Axes(float width, float height, float originX, float originY, 
         float xMin, float xMax, float yMin, float yMax)
        : width(width), height(height), originX(originX), originY(originY),
          xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax) {}
    
    // 将数学坐标转换为屏幕坐标
    sf::Vector2f mathToScreen(double x, double y) const {
        float screenX = originX + (x - xMin) * (width / (xMax - xMin));
        float screenY = originY - (y - yMin) * (height / (yMax - yMin));
        return sf::Vector2f(screenX, screenY);
    }
    
    // 将屏幕坐标转换为数学坐标
    sf::Vector2f screenToMath(float screenX, float screenY) const {
        double mathX = xMin + (screenX - originX) * (xMax - xMin) / width;
        double mathY = yMin + (originY - screenY) * (yMax - yMin) / height;
        return sf::Vector2f(mathX, mathY);
    }
    
    // 绘制坐标轴
    void draw(sf::RenderWindow& window) {
        // 绘制坐标轴
        sf::VertexArray axes(sf::Lines, 4);
        axes[0].position = sf::Vector2f(0, originY);
        axes[1].position = sf::Vector2f(width, originY);
        axes[2].position = sf::Vector2f(originX, 0);
        axes[3].position = sf::Vector2f(originX, height);
        
        axes[0].color = axes[1].color = axes[2].color = axes[3].color = sf::Color(100, 100, 100);
        
        window.draw(axes);
        
        // 绘制刻度
        sf::VertexArray ticks(sf::Lines);
        
        // X轴刻度
        double xStep = (xMax - xMin) / 10.0;
        for (double x = xMin; x <= xMax; x += xStep) {
            if (fabs(x) < 1e-5) continue; // 跳过原点
            
            sf::Vector2f pos = mathToScreen(x, 0);
            ticks.append(sf::Vertex(sf::Vector2f(pos.x, pos.y - 5), sf::Color(100, 100, 100)));
            ticks.append(sf::Vertex(sf::Vector2f(pos.x, pos.y + 5), sf::Color(100, 100, 100)));
        }
        
        // Y轴刻度
        double yStep = (yMax - yMin) / 10.0;
        for (double y = yMin; y <= yMax; y += yStep) {
            if (fabs(y) < 1e-5) continue; // 跳过原点
            
            sf::Vector2f pos = mathToScreen(0, y);
            ticks.append(sf::Vertex(sf::Vector2f(pos.x - 5, pos.y), sf::Color(100, 100, 100)));
            ticks.append(sf::Vertex(sf::Vector2f(pos.x + 5, pos.y), sf::Color(100, 100, 100)));
        }
        
        window.draw(ticks);
    }
    
    // 平移坐标轴
    void pan(float dx, float dy) {
        originX += dx;
        originY += dy;
    }
    
    // 缩放坐标轴
    void zoom(float factor, float centerX, float centerY) {
        // 保存鼠标位置对应的数学坐标
        sf::Vector2f mathPos = screenToMath(centerX, centerY);
        
        // 缩放
        float newWidth = width * factor;
        float newHeight = height * factor;
        
        // 调整坐标范围
        xMin = mathPos.x - (centerX - originX) * (xMax - xMin) / width * factor;
        xMax = xMin + (xMax - xMin) * width / newWidth;
        
        yMin = mathPos.y - (originY - centerY) * (yMax - yMin) / height * factor;
        yMax = yMin + (yMax - yMin) * height / newHeight;
        
        width = newWidth;
        height = newHeight;
    }
    
    // 重置坐标轴
    void reset() {
        originX = width / 2.0f;
        originY = height / 2.0f;
        xMin = -5.0;
        xMax = 5.0;
        yMin = -3.0;
        yMax = 3.0;
    }
    
private:
    float width, height;
    float originX, originY;
    double xMin, xMax, yMin, yMax;
};

// 函数图类
class FunctionPlot {
public:
    FunctionPlot(const Axes& axes, double (*func)(double), sf::Color color, int samples = 500)
        : axes(axes), func(func), color(color), samples(samples) {}
    
    // 绘制函数图像
    void draw(sf::RenderWindow& window) {
        sf::VertexArray curve(sf::LineStrip);
        
        double xStep = (axes.getXMax() - axes.getXMin()) / samples;
        
        for (int i = 0; i <= samples; ++i) {
            double x = axes.getXMin() + i * xStep;
            double y = func(x);
            
            // 跳过无效点（如tan(x)的奇点）
            if (std::isfinite(y)) {
                sf::Vector2f pos = axes.mathToScreen(x, y);
                curve.append(sf::Vertex(pos, color));
            }
        }
        
        window.draw(curve);
    }
    
private:
    const Axes& axes;
    double (*func)(double);
    sf::Color color;
    int samples;
};

// 按钮类
class Button {
public:
    Button(float x, float y, float width, float height, const std::string& text, sf::Color color)
        : position(x, y), size(width, height), text(text), color(color), hover(false) {}
    
    void draw(sf::RenderWindow& window) {
        sf::RectangleShape rect(size);
        rect.setPosition(position);
        rect.setFillColor(hover ? sf::Color(color.r + 40, color.g + 40, color.b + 40) : color);
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color::Black);
        window.draw(rect);
        
        // 绘制文本
        static sf::Font font;
        static bool fontLoaded = false;
        if (!fontLoaded) {
            font.loadFromFile("arial.ttf"); // 需要字体文件
            fontLoaded = true;
        }
        
        sf::Text textObj(text, font, 18);
        textObj.setPosition(position.x + 10, position.y + 5);
        textObj.setFillColor(sf::Color::Black);
        window.draw(textObj);
    }
    
    bool contains(float x, float y) const {
        return x >= position.x && x <= position.x + size.x &&
               y >= position.y && y <= position.y + size.y;
    }
    
    void setHover(bool isHover) {
        hover = isHover;
    }
    
private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::string text;
    sf::Color color;
    bool hover;
};

int main() {
    const int width = 1000;
    const int height = 700;
    
    sf::RenderWindow window(sf::VideoMode(width, height), "函数图像绘制程序", sf::Style::Close);
    window.setFramerateLimit(60);
    
    // 创建坐标轴
    Axes axes(width - 200, height - 100, width/2 - 100, height/2, -5.0, 5.0, -3.0, 3.0);
    
    // 创建函数图
    std::vector<FunctionPlot> plots;
    plots.emplace_back(axes, func1, sf::Color::Red);     // 正弦函数
    plots.emplace_back(axes, func2, sf::Color::Green);   // 余弦函数
    plots.emplace_back(axes, func3, sf::Color::Blue);    // 正切函数
    plots.emplace_back(axes, func4, sf::Color::Magenta); // 高斯函数
    plots.emplace_back(axes, func5, sf::Color::Cyan);    // 三次函数
    plots.emplace_back(axes, func6, sf::Color(255, 165, 0)); // Sigmoid函数
    
    // 创建按钮
    std::vector<Button> buttons;
    buttons.emplace_back(width - 180, 20, 160, 40, "重置视图", sf::Color(200, 200, 200));
    buttons.emplace_back(width - 180, 70, 160, 40, "缩放+", sf::Color(200, 200, 200));
    buttons.emplace_back(width - 180, 120, 160, 40, "缩放-", sf::Color(200, 200, 200));
    
    // 创建图例
    std::vector<std::pair<std::string, sf::Color>> legend = {
        {"sin(x)", sf::Color::Red},
        {"cos(x)", sf::Color::Green},
        {"tan(x)", sf::Color::Blue},
        {"exp(-x²)", sf::Color::Magenta},
        {"0.2x³ - 1.5x", sf::Color::Cyan},
        {"Sigmoid(x)", sf::Color(255, 165, 0)}
    };
    
    // 主循环变量
    sf::Vector2i lastMousePos;
    bool panning = false;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                
            // 鼠标按钮事件
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // 检查按钮点击
                    for (auto& btn : buttons) {
                        if (btn.contains(event.mouseButton.x, event.mouseButton.y)) {
                            if (btn.getText() == "重置视图") {
                                axes.reset();
                            } else if (btn.getText() == "缩放+") {
                                axes.zoom(0.8, width/2 - 100, height/2);
                            } else if (btn.getText() == "缩放-") {
                                axes.zoom(1.2, width/2 - 100, height/2);
                            }
                        }
                    }
                    
                    // 开始拖动
                    if (event.mouseButton.x < width - 200) {
                        panning = true;
                        lastMousePos = sf::Mouse::getPosition(window);
                    }
                }
            }
            
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    panning = false;
                }
            }
            
            // 鼠标移动事件
            if (event.type == sf::Event::MouseMoved) {
                // 更新按钮悬停状态
                for (auto& btn : buttons) {
                    btn.setHover(btn.contains(event.mouseMove.x, event.mouseMove.y));
                }
                
                // 拖动平移
                if (panning) {
                    sf::Vector2i currentMousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f delta = sf::Vector2f(currentMousePos - lastMousePos);
                    axes.pan(delta.x, delta.y);
                    lastMousePos = currentMousePos;
                }
            }
            
            // 鼠标滚轮缩放
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    float zoomFactor = (event.mouseWheelScroll.delta > 0) ? 0.8f : 1.2f;
                    axes.zoom(zoomFactor, event.mouseWheelScroll.x, event.mouseWheelScroll.y);
                }
            }
        }
        
        // 绘制
        window.clear(sf::Color(30, 30, 40)); // 深蓝色背景
        
        // 绘制坐标网格
        sf::VertexArray grid(sf::Lines);
        double xStep = (axes.getXMax() - axes.getXMin()) / 20.0;
        for (double x = axes.getXMin(); x <= axes.getXMax(); x += xStep) {
            if (fabs(x) < 1e-5) continue;
            sf::Vector2f start = axes.mathToScreen(x, axes.getYMin());
            sf::Vector2f end = axes.mathToScreen(x, axes.getYMax());
            grid.append(sf::Vertex(start, sf::Color(50, 50, 60)));
            grid.append(sf::Vertex(end, sf::Color(50, 50, 60)));
        }
        
        double yStep = (axes.getYMax() - axes.getYMin()) / 20.0;
        for (double y = axes.getYMin(); y <= axes.getYMax(); y += yStep) {
            if (fabs(y) < 1e-5) continue;
            sf::Vector2f start = axes.mathToScreen(axes.getXMin(), y);
            sf::Vector2f end = axes.mathToScreen(axes.getXMax(), y);
            grid.append(sf::Vertex(start, sf::Color(50, 50, 60)));
            grid.append(sf::Vertex(end, sf::Color(50, 50, 60)));
        }
        window.draw(grid);
        
        // 绘制坐标轴
        axes.draw(window);
        
        // 绘制函数图像
        for (auto& plot : plots) {
            plot.draw(window);
        }
        
        // 绘制按钮
        for (auto& btn : buttons) {
            btn.draw(window);
        }
        
        // 绘制图例
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            // 如果找不到字体，使用默认字体
            // 实际应用中应处理字体加载失败的情况
        }
        
        for (int i = 0; i < legend.size(); ++i) {
            // 绘制颜色标记
            sf::RectangleShape colorRect(sf::Vector2f(20, 20));
            colorRect.setPosition(width - 180, 200 + i * 30);
            colorRect.setFillColor(legend[i].second);
            window.draw(colorRect);
            
            // 绘制函数名称
            sf::Text funcName(legend[i].first, font, 18);
            funcName.setPosition(width - 150, 200 + i * 30);
            funcName.setFillColor(sf::Color::White);
            window.draw(funcName);
        }
        
        // 绘制标题
        sf::Text title("函数图像可视化", font, 32);
        title.setPosition(30, 20);
        title.setFillColor(sf::Color(220, 220, 255));
        window.draw(title);
        
        // 绘制操作提示
        sf::Text hint1("操作提示:", font, 20);
        hint1.setPosition(width - 180, 450);
        hint1.setFillColor(sf::Color(200, 200, 200));
        window.draw(hint1);
        
        sf::Text hint2("鼠标拖动: 平移视图", font, 16);
        hint2.setPosition(width - 180, 480);
        hint2.setFillColor(sf::Color(180, 180, 200));
        window.draw(hint2);
        
        sf::Text hint3("鼠标滚轮: 缩放视图", font, 16);
        hint3.setPosition(width - 180, 500);
        hint3.setFillColor(sf::Color(180, 180, 200));
        window.draw(hint3);
        
        sf::Text hint4("按钮: 重置或缩放", font, 16);
        hint4.setPosition(width - 180, 520);
        hint4.setFillColor(sf::Color(180, 180, 200));
        window.draw(hint4);
        
        window.display();
    }
    
    return 0;
}