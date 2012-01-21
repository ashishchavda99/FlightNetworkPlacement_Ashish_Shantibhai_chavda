#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
	int data[10];
	int top=-1;
	int np=0;
	void push(int a)
	{
		if(a>9)
		{
			return;
		}
		++top;
		data[top]=a;
		np=a+1;
		cout<<"Push"<<a<<endl;
	}
	void pop()
	{
	       cout<<"POP "<<data[top]<<endl;
		top--;
	}
int main()
{
	char m[10];
	cout<<"Enter String";
	cin>>m;
	int a[10];
	int i;
	for(i=0;i<10;i++)
	{
		a[i]=m[i];
		a[i]-=48;
	}
	int index=0;
	while(index<10)
	{
		for(int i=np;i<a[index];i++)
		{
			push(i);
		}
		while(a[index]==data[top])
		{
			index++;
			pop();
			if(top== -1)
			break;
		}
	}

}
