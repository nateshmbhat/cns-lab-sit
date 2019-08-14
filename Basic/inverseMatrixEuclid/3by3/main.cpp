#include<bits/stdc++.h>

using namespace std ;

int m[3][3] ;

int findDet(int m[3][3]  , int n ){
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
		i++ ;
	}
	p1 = (p0-p1*(q0))%26 ;
	return p1 ;
}

int mod26(int n){
	n = n%26 ;
	if(n<0) n = 26 - abs(n)%26 ;
	return n ;
}


void findInverse(int m[3][3] , int detInverse ) {
	int temp[5][5] = {0} ;
	int adj[3][3] = {0} ;

// fill the 5x5 matrix
	for(int i = 0 ;i < 5 ; i++){
		for(int j = 0 ;j  < 5 ; j++)
			{
				if(i<3 && j<3) temp[i][j] = m[i][j] ;
				else if(i>=3 && j>=3) temp[i][j] = temp[i][j-3] ;
				else if(j>=3)temp[i][j] = m[i][j-3] ;
				else if(i>=3) temp[i][j] = m[i-3][j] ;
			}
	}

	for(int i =1 ;i <= 3 ; i++){
		for(int j =1  ; j <= 3 ; j++){
			adj[j-1][i-1] = mod26(temp[i][j]*temp[i+1][j+1]-temp[i][j+1]*temp[i+1][j]) ;
			adj[j-1][i-1] = mod26(adj[j-1][i-1] * detInverse) ;
		}
	}


    cout<<endl<<"Inverse Matrix : "<<endl;
	for(int i =0 ;i < 3 ; i++){
		for(int j =0  ; j < 3 ; j++){
			cout << adj[i][j]  <<" " ;
		}
		cout<<endl;
	}
}


int main(void){
	int n= 3 ;
	cout<<"Enter matrix : " <<endl;
	for(int i =0  ;i < n ; i++) for(int j =0 ;j < n ; j++) cin>>m[i][j] ;
	int det = findDet(m , n) ;
	cout<<"Det = " << det<<endl;
	int detInverse = findDetInverse(det) ;
	cout<<"Det inverse = " << detInverse <<endl;
	findInverse(m , detInverse) ;
}
