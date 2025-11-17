#include<bits/stdc++.h>
using namespace std;
bool flag=true;
stack<char> fuhao;
bool peidui(char a)
{
	if(fuhao.empty())
	{
		cout<<"NO"<<endl;
		if(a=='\0')
		{
			cout<<"?-*/";
		}
		else
		{
			cout<<"?-"<<a<<endl;
		}
		return false;
	}
	else
	{
		if(a==fuhao.top()||(fuhao.top()=='('&&a==')')||(fuhao.top()=='{'&&a=='}')||(fuhao.top()=='['&&a==']'))
		{
			fuhao.pop();
			return true;
		}
		else
		{
			cout<<"NO"<<endl;
			if(fuhao.top()=='\0')
			{
				cout<<"/*-?"<<endl;
			}
			else
			{
				cout<<fuhao.top()<<"-?"<<endl;
			}
			return false;
		}
	}
}
int main()
{
	char c[101];
	char ch;
	while(flag&&cin>>c)
	{
		for(int i=0;flag&&c[i]!='\0';i++)
		{
			ch=c[i];
			if(ch=='/'&&c[i+1]=='*')
			{
				fuhao.push('\0');
				i++;
			}
			else if(ch=='*'&&c[i+1]=='/')
			{
				flag=peidui('\0');
				i++;
			}
			else if(ch=='('||ch=='['||ch=='{')
			{
				fuhao.push(ch);
			}
			else if(ch==')'||ch=='}'||ch==']')
			{
				flag=peidui(ch);
			}
		}
	}
	if(flag&&fuhao.empty())
	{
		cout<<"YES"<<endl;
	}
	else if(flag&&!fuhao.empty())
	{
		cout<<"NO"<<endl;
		if(fuhao.top()=='\0')
		{
			cout<<"/*-?";
		}
		else
		{
			cout<<fuhao.top()<<"-?";
		}
	}
}