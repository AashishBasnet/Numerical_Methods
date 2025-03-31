#include<iostream>
#include<cmath>
using namespace std;
float g(float x){
	return (((5/x)+x)/2);
}
int main(){
	float x,e,x_prev;
	cout<<"----------FIXED POINT ITERATION METHOD--------------"<<endl;
	cout<<"Enter initial guesses of x:"<<endl;
	cin>>x;
	cout<<"Enter the stopping condition (epsilon):";
	cin>>e;
	int iter = 0, max_iter = 100;
	x_prev = x;
	do{
	x = g(x);
	if ((fabs(x-x_prev))<e){
		break;
	}
	x_prev = x;
	iter++;
	}while(iter<max_iter);
	cout<<"The root is: "<<x;
	return 0;
	}
