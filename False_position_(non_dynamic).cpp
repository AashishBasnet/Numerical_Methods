#include<iostream>
#include<math.h>
using namespace std;
#define f(x) (x*log10(x)-1.2)
int main()
{
First:
	float x1, x2,f0,f1,f2,x0,e,error,root;
	cout<<"Enter the two initial value for x1 and x2\n";
	cin>>x1;
	cin>>x2;
		cout<<"Enter the accuracy\n";
	cin>>e;
	f1=f(x1);
	f2=f(x2);
	if((f1*f2)>0)
	{
		cout<<"The initial guess is wrong enter it again";
		goto First;
	}
	
step:
	x0=x1-(f1*(x2-x1))/(f2-f1);
	f0=f(x0);

if((f0*f1)<0){
	x2=x0;
	f2=f0;
}
else {
	x1=x0;
	f1=f0;
}
if((f0)<e)
{
	root=x0;
	
	}
	else
	{
		goto step;
	}
		cout<<"The value of root is"<<root;
		
		return 0;	
}
