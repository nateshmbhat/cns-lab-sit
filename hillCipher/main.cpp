#include<bits/stdc++.h>

using namespace std ;

int key[3][3] ;

int findDet(int m[3][3]  , int n ){
    if(n==2) return m[0][0] * m[1][1] - m[0][1]*m[1][0] ;
	else if (n==3) {
		return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])  - m[0][1] *( m[1][0]*m[2][2]-m[2][0]*m[1][2] )  + m[0][2] * (m[1][0]*m[2][1]-m[1][1]*m[2][0] )  ;
	}
	else return 0 ; //invalid input
}

int mod26(int x){
	return x>=0?(x%26):26-(abs(x)%26) ; 
}

int findDetInverse(int R , int D = 26){ //R is the remainder or determinant
	int i =0 ;
	int p[100] = {0,1}; 
	int q[100] = {0} ; 
	while(R!=0){
		q[i] = D/R ;
		int oldD = D ;
		D = R ;
		R = oldD%R ;  
		if(i>1){
			p[i] = mod26(p[i-2] - p[i-1]*q[i-2]) ; 
		}
		i++ ; 
	}
	return p[i] = mod26(p[i-2] - p[i-1]*q[i-2]) ; 
}


void multiplyMatrices(int a[1000][3] , int a_rows , int a_cols ,  int b[1000][3] , int b_rows , int b_cols , int res[1000][3]){
	for(int i= 0 ;i < a_rows ; i++){
		for(int j=0 ;j < b_cols ; j++){
			for(int k = 0 ; k < b_rows ; k++)
			{
				res[i][j] += a[i][k]*b[k][j] ; 	
			}
			res[i][j] = mod26(res[i][j]) ;
		}
	}
}


void findInverse(int m[3][3] , int n  , int detInverse ) {		
	int adj[3][3] = {0} ; 
	if(n==2){
		adj[0][0] = m[1][1] ; adj[1][1] = m[0][0]  ; adj[0][1] = -m[0][1] ; adj[1][0] = -m[1][0] ;
	}
	else{ //n == 3
		int temp[5][5] = {0} ;

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
		// except first row and column , multiply elements along rows and place them along columns
		for(int i =1 ;i <= 3 ; i++){
			for(int j =1  ; j <= 3 ; j++){
				adj[j-1][i-1] = mod26(temp[i][j]*temp[i+1][j+1]-temp[i][j+1]*temp[i+1][j]) ;
			}
		}
	}

	int inverse[3][3] = {0} ; 
	for(int i = 0 ;i < n ; i++){
		for(int j = 0 ;j  < n ; j++)
		{
			inverse[i][j] = mod26(adj[i][j]*detInverse) ; 
		}
	}
}

string encrypt( string pt , int n){
	// C = P*K
	int P[1000][3]={0} ; //plainttext
	int ptIter = 0  ; 
	while(pt.length()%n!=0)pt+="x" ;  //pad extra x 
	for(int i =0 ; i< pt.length()/n ; i++){
		for(int j =0 ;j < n ;j++) P[i][j] = pt[ptIter++]-'a' ; 
	}
	int C[1000][3] = {0}  ; //cipher text
	multiplyMatrices(P, pt.length()/n , n , key , n , n , C) ; 

	string ct = "" ; 
	for(int i =0 ; i< pt.length()/n ; i++){
		for(int j =0 ;j < n ;j++) ct += (C[i][j]+'a') ; 
	}
	return ct ; 
}



int main(void){
   int n ;
   string pt ;
   cout<<"Enter plain text : "  ; cin>> pt ; 
   cout<<"Enter number of rows in keymatrix : " ; cin>>n ;
   cout<<"Enter key matrix  : " <<endl;
   for(int i =0  ;i < n ; i++) for(int j =0 ;j < n ; j++) cin>>key[i][j] ;  
   string ct = encrypt(pt  , n) ; 
   cout<<"Cipher text : " << ct ; 
}

