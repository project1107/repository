# <center><font face="仿宋" font color="red"> markedown </font>
## <center><font face="楷体" font color="blue" size=4> Hello World </font></center>
1. **标题**
# 1
## 2
### 3
#### 4
##### 5
###### 6
####### 5
2. **引用**
   >这里是引用
   >>嵌套引用
3. **列表**
   1. 无序列表
      - 1
      + 2
      * 3
     - + *  * 嵌套
   2. 有序列表
       1. 1
       2. 2
       3. 1. 1. 1. 嵌套
   3. todolist
      - [ ] 1
      - [x] 2
      - [ ] 3
4. **表格**
    | 左对齐 | 居中 | 右对齐 |
    | :--- | :--: | ----: |
    | 1 | 2 | 3 |
    |a|b|c|
5. **段落**
    * 换行? —— 两个以上空格后换行/空一行
    * 分割线 —— 三个以上-/_/*
    ***
    ---
    ___
    * 字体  
        | 字体 |代码|
        |---|---|
        | *斜体* | * * |
        | ==高亮== | == == |
        | **粗体** | ** ** |
        | ***斜粗体*** | *** *** |
        | ~~删除线~~ | ~~ ~~ |
        | 链接 | [链接](地址) |
        | 图片 | ![图片](图片地址) |
        | <u>下划线</u> | <u> </u> |
    * 脚注
        脚注[^1]
        [^1]: 脚注内容
6. **代码**
    ```c++
    #include <iostream>
    using namespace std;
    int main()
    {
        cout << "Hello World!" << endl;
    }
    ```
    ```python
    print("Hello World!")
    ```
    ```java
    public class HelloWorld {
        public static void main(String[] args) {
            System.out.println("Hello World!");
        }
    }
    ```
    `print("Hello World!");`
7. **超链接**
    [百度](https://www.baidu.com)
    [百度](https://www.baidu.com "百度")
    [百度] : https://www.baidu.com
    [百度] : https://www.baidu.com "百度"
8. **图片**
    * 使用图床保存图片并实现插入
        [图床]:https://img.remit.ee/
    * 使用markdown语法插入图片
    ![图片](https://www.baidu.com/img/bd_logo1.png)
    ![图片](https://www.baidu.com/img/bd_logo1.png "百度")
    ![图片] : https://www.baidu.com/img/bd_logo1.png
    ![图片] : https://www.baidu.com/img/bd_logo1.png "百度"
    使用html语言实现调整图片大小和位置



    <a href="https://imgchr.com/"><div align=center><imgsrc="https://www.baidu.com/img/bd_logo1.png" alt="pFZHwAe.jpg"border="0" width="80%" height="60%"/></div></a>
width height设置宽高
div align=center 设置居中
/括住表示结束

# 其他
* 插入latex公式  latex语法
    行内显示公式：$E=mc^2$
    块级公式：$$E=mc^2$$
* html/css语法
ctrl+shift+p搜索markdown preview enhanced:customize css
在style中使用css语法改标题格式
h1{ 
    text-align: center;
}
一级标题居中
* 个性化设置
  文件-首选项-设置
# 导出为pdf文件
有markdown-pdf插件，右键直接转为pdf导出  不推荐，通过html间接导出

右键浏览器打开，选择打印，选择pdf保存