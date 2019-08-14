#include<bits/stdc++.h>

using namespace std ;

int m[3][3] ;

int findDet(int m[3][3]  , int n ){
    if(n==2) return m[0][0] * m[1][1] - m[0][1]*m[1][0] ;
		else if (n==3) {
			return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1] )  - m[0][1] *( m[1][0]*m[2][2]-m[2][0]*m[1][2] )  + m[0][2] * (m[1][0]*m[2][1]-m[1][1]*m[2][0] )  ; 
		}
		else return 0 ; //invalid input
}


int main(void){
   int n ;
   cout<<"Enter n (2 or 3) : "  ; cin>>n ;
   cout<<"Enter matrix : " <<endl;
   for(int i =0  ;i < n ; i++) for(int j =0 ;j < n ; j++) cin>>m[i][j] ;

	 cout<<endl<<"Determinant is " << findDet(m , n) ; 
	 cout<<endl;
   
}
