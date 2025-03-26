#include<iostream>
using namespace std;
int main(){
	int p;
	int a[50];
	int n,x,i,j;
	cout<<"\n\n ----------------- HORNER'S RULE ----------------------"<<endl<<endl;
	cout<<"Enter the degree of equation: ";
	cin>>n;
	cout<<"Enter the value of x: ";
	cin>>x;
	cout<<"Enter value of a[0] to a[n]: "<<endl;
	for (i = 0; i<=n; i++){
		cout<<"a["<<i<<"]= ";
		cin>>a[i];
	}
	p = a[n];
	cout<<"\n\nSolution:"<<endl;
	cout<<"\n	p"<<n<<" = "<<p;
	for (j = n-1; j>=0;j--){
		p = a[j]+(p*x);
		cout<<"\n	p"<<j<<" = "<<p;
	}
	cout<<"\n\n Hence, the value of f(x) is: "<<p<<endl<<endl;
	return 0;
}
