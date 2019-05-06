#include<iostream>
using namespace std;
int cope(int a,int b,int c)   //如果a,b都大于c则返回10
{
if(a>c&&b>c)
return 10;
else 
return 0;
}
void cppo(int a,int b,int &c)//如果a,b其中之一大于c,修改c值为a
{
 if(a>c||b>c)
 c=a;
else 
c=b;
}
int main()    
{
int a,b,c,d;
cin>>a>>b>>c;
d=cope(a,b,c);
cppo(a,b,c);
cout<<d<<endl;
cout<<c<<endl;
return 0;
}