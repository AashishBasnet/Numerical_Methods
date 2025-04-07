#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
	return ((x*x)-(4*x)-10);
}
int main(){
	float x1,x2,f1,f2,x3=0.0,f3=0.0,e;
	cout<<"----------SECANT METHOD--------------"<<endl;
	cout<<"Enter initial guesses x1 and x2:"<<endl;
	cin>>x1>>x2;
	cout<<"Enter the stopping condition (epsilon):";
	cin>>e;
	f1 = f(x1);
	f2 = f(x2);
	int iter = 0, max_iter = 100;
	do{
	x3 = ((f2*x1) - (f1*x2))/(f2-f1);
	f3 = f(x3);
	if (((fabs(x3-x2))/(fabs(x3)))>e){
		x1 = x2;
		f1 = f2;
		x2 = x3;
		f2 = f3;
	}
	else{
		cout<<"root is: "<<x3;
		break;
	}
	iter++;
	}while(iter<max_iter);
	return 0;
	}
