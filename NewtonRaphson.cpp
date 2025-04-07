#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
	return ((3*x)-cos(x)-1);
}
float g(float x){
	return (3+sin(x));
}
int main(){
	float x0,x1,f0,f1,g0,e;
	cout<<"----------NEWTON RAPHSON METHOD--------------"<<endl;
	cout<<"Enter initial guess x0:"<<endl;
	cin>>x0;
	cout<<"Enter the stopping condition (epsilon):";
	cin>>e;
	int iter = 0, max_iter = 100;
	do{
	g0 = g(x0);
	f0 = f(x0);
	if (g0 == 0.0)
	{
		cout<<"Division by 0 error"<<endl;
		break;
	}
	x1 = x0-(f0/g0);
	x0 = x1;
	iter ++;
	if (iter > max_iter){
		cout<<"not convergent"<<endl;
		break;
	}
	f1 = f(x1);
	}while(fabs(f1)>e);
	cout<<"Root is:"<<x1;
	return 0;
	}
