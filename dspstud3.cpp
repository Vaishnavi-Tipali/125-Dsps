#include<iostream>
using namespace std;
int main()
{
int a[10],i,n,key,flag=0;
cout<<"enter the no of student:";
cin>>n;
cout<<"enter the roll no of studentwho attend the training:\n";
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"enter the roll no of he/she attend the class";
cin>>key;
for(i=0;i<n;i++)
{
if(a[i]==key)
{
flag=1;
break;
}
}
if(flag==1)
{
cout<<"student has attend the training.\n";
}
else
{
cout<<"student has not attend the training.\n";
}
return 0;
}

