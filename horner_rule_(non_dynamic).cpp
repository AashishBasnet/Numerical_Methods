#include<iostream>
#include<conio.h>
using namespace std;
int main() {
	int n, i, m, a, x;
	cout<<"Enter the degree of polynomial \n";
	cin>>n;
		cout<<"input value of x\n";
	cin>>x;
	
	cout<<"Input polynomial coefficients of a"<<n<<"\n";
	cin>>m;
	float p=m;
		for(i=n-1; i>=0; i--){
		cout<<"Enter the value of a"<<i<<"\n";
		cin>>a;
		p=p*x+a;
	}
	cout<<"The functional value is \n"<<p;

	return 0;
}

