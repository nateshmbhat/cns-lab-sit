#include<bits/stdc++.h>
using namespace std ;

int key[3][3] ;
int C[1000][3] = {0}  ; //cipher text

int findDet(int m[3][3]  , int n ){
    if(n==2) return m[0][0] * m[1][1] - m[0][1]*m[1][0] ;
	else if (n==3) {
		return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])  - m[0][1] *( m[1][0]*m[2][2]-m[2][0]*m[1][2] )  + m[0][2] * (m[1][0]*m[2][1]-m[1][1]*m[2][0] )  ;
	}
	else return 0 ; //invalid input
}

int mod26(int x){ return x>=0?(x%26):26-(abs(x)%26) ; }

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
	if(i == 1) return p[i] = 1 ;
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


void findInverse(int m[3][3] , int n  , int detInverse , int inverse[3][3] ) {		
	int adj[3][3] = {0} ; 
	if(n==2){
		adj[0][0] = m[1][1] ; adj[1][1] = m[0][0]  ; adj[0][1] = -m[0][1] ; adj[1][0] = -m[1][0] ;
	}
	else{ //n == 3
		int temp[5][5] = {0} ;
		// fill the 5x5 matrix
		for(int i = 0 ;i < 5 ; i++)
			for(int j = 0 ;j  < 5 ; j++)
				temp[i][j] = m[i%3][j%3] ;
		// except first row and column , multiply elements along rows and place them along columns
		for(int i =1 ;i <= 3 ; i++){
			for(int j =1  ; j <= 3 ; j++){
				adj[j-1][i-1] = mod26(temp[i][j]*temp[i+1][j+1]-temp[i][j+1]*temp[i+1][j]) ;
			}
		}
	}
	for(int i = 0 ;i < n ; i++){
		for(int j = 0 ;j  < n ; j++) inverse[i][j] = mod26(adj[i][j]*detInverse) ; 
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
	multiplyMatrices(P, pt.length()/n , n , key , n , n , C) ; 

	string ct = "" ; 
	for(int i =0 ; i< pt.length()/n ; i++){
		for(int j =0 ;j < n ;j++) ct += (C[i][j]+'a') ; 
	}
	return ct ; 
}
string decrypt( string ct , int n){
	// P = C * K^-1
	int P[1000][3]={0} ; //plainttext
	int ctIter = 0  ; 
	int keyInverse[3][3] = {0} ; 
	findInverse(key , n , findDetInverse(findDet(key,n)) , keyInverse ) ; 
	multiplyMatrices(C, ct.length()/n , n , keyInverse , n , n , P) ; 

	string pt = "" ; 
	for(int i =0 ; i< ct.length()/n ; i++){
		for(int j =0 ;j < n ;j++) pt += (P[i][j]+'a') ; 
	}
	return pt ; 
}


int main(void){
   int n ;
   string pt ;
   cout<<"Enter plain text : "  ; cin>> pt ; 
   cout<<"Enter number of rows in keymatrix : " ; cin>>n ;
   cout<<"Enter key matrix  : " <<endl;
   for(int i =0  ;i < n ; i++) for(int j =0 ;j < n ; j++) cin>>key[i][j] ;  
   string ct = encrypt(pt  , n) ; 
   cout<<"Original text	 : " << pt <<endl; 
   cout<<"Cipher text	 : " << ct <<endl;  
   cout<<"Decrypted text : " << decrypt(ct,n) <<endl; 
}

/*
Enter plain text : helloitsme
Enter number of rows in keymatrix : 3
Enter key matrix  : 
17      7       5
21      18      21
2       2       19
Original text    : helloitsme
Cipher text      : rnqdhhxnzzue
Decrypted text : helloitsmexx


------------------------------------------------

Enter plain text : nateshisdancing                  
Enter number of rows in keymatrix : 3
Enter key matrix  : 
3 	10	 20
20 	9 	17
9 	4 	17
Original text    : nateshisdancing
Cipher text      : cyltwlvuxsvvanp
Decrypted text : nateshisdancing

------------------------------------------------

Enter plain text : meetmenow      
Enter number of rows in keymatrix : 2
Enter key matrix  : 
9       4
5       7
Original text    : meetmenow
Cipher text      : yybtyyfubp
Decrypted text : meetmenowx

*/
