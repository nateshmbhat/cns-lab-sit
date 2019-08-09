#include<bits/stdc++.h>

using namespace std ;

int m[2][2] ;

int findDet(int m[2][2]  , int n ){
    if(n==2) return m[0][0] * m[1][1] - m[0][1]*m[1][0] ;
		else if (n==3) {
			return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])  - m[0][1] *( m[1][0]*m[2][2]-m[2][0]*m[1][2] )  + m[0][2] * (m[1][0]*m[2][1]-m[1][1]*m[2][0] )  ;
		}
		else return 0 ; //invalid input
}

int findDetInverse(int R , int D = 26){ //R is the remainder or determinant
	int i =0 ;
	int p0= 0 , p1 =1 ; 
	int q = 1 ; 
	int q0 , q1 ; 
	while(R!=0){
		q = D/R ;
		int tempD = D ; 
		D = R ; 
		R = tempD%R ; 

		if(i==0) { p0 = 0 ; q0 = q ; }
		else if(i==1){ p1==1 ;q1 = q ; }
		else{
			int temp = p1 ;
			p1 = (p0-p1*(q0))%26 ; 
			if(p1<0)p1 = 26-(abs(p1)%26) ; 
			p0 = temp ;
			
			q0 = q1; 
			q1 = q ;
		}
//		cout<<"p0 , p1 = " << p0 <<" " <<p1<< endl; 

		i++ ; 
	}
	p1 = (p0-p1*(q0))%26 ; 
	return p1 ; 
}


void findInverse(int m[2][2] , int detInverse ) {		
	int adj[2][2] = {0} ; 
	adj[0][0] = m[1][1] ; adj[1][1] = m[0][0]  ; adj[0][1] = -m[0][1] ; adj[1][0] = -m[1][0] ;

	for(int i = 0 ;i < 2 ; i++){
		for(int j = 0 ;j  < 2 ; j++)
			{ 
				adj[i][j] = (adj[i][j]*detInverse )%26  ; 
				if(adj[i][j]<0) adj[i][j] = 26-(abs(adj[i][j])%26) ; 
				cout<< adj[i][j] <<" " ; 
			}
		cout<<endl; 
	}
}


int main(void){
   int n= 2 ;
   cout<<"Enter matrix : " <<endl;
   for(int i =0  ;i < n ; i++) for(int j =0 ;j < n ; j++) cin>>m[i][j] ;  
	 int det = findDet(m , n) ; 
	 cout<<"Det = " << det<<endl; 
	 int detInverse = findDetInverse(det) ; 
	 cout<<"Det inverse = " << detInverse <<endl; 

	 cout<<"\nInverse is " <<endl; 
	findInverse(m , detInverse) ; 
	 
}
