#include<iostream>
using namespace std ; 

int gcd(int m , int n ){
	return n==0?m:gcd(n,m%n) ; 
}

int main(void){
	int m , n ; 
	cout<<"Enter m and n : " ; cin>> m>>n ; 
	cout<<"GCD = " << gcd(m , n ) <<endl ; 

}
