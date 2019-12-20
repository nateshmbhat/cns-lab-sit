#include<bits/stdc++.h>
using namespace std ; 

string encrypt(string pt , string key){
	int t = 0 ;   // here  t is to iterate over text
	char matrix[100][100]  ;  
	while(pt.length()%key.length())pt+="x" ;
	int totalRows = pt.length()/key.length() ; 

	for(int r = 0 ; r < totalRows ; cout<<endl ,  r++){
		for(int c = 0 ; c < key.length() ; c++){
			cout<< (matrix[r][c] = pt[t++]) <<'\t' ; 
		}
	}
	string ct ="" ;
	for(char c= '1'  ;  c <= '0'+key.length() ; c++){	
		int col = key.find(c) ;
		for(int i =0 ; i < totalRows ; i++) ct+= matrix[i][col] ; 
	}
	return ct ; 
}

string decrypt(string ct , string key){
	char matrix[100][100]  ; string pt="" ; 
	int t= 0 , totalRows = ceil(ct.length()/key.length()) ;  //t is text iterator
	for(char c='1' ; c<='0'+key.length() ; c++){
		int col = key.find(c) ;
		for(int i= 0 ; i < totalRows ; i++){
			matrix[i][col] = ct[t++] ; 
		}
	}
	for(int i =0 ; i < totalRows ; i++){
		for(int j =0 ;j <key.length() ; j++) pt+=matrix[i][j] ; 	
	}
	return pt ; 
}

int main(void){
	string pt, key ; 
	cout<<"Enter message : " ; cin>>pt ; 
	cout<<"Enter key : " ; cin>>key ; 
	string ct = encrypt(pt , key) ; 
	cout<<"Original text 		: " << pt <<endl; 
	cout<<"Cipher   text		: " << ct <<endl; 
	cout<<"Decrypted text		: " <<  decrypt(ct , key) <<endl; 
}

/*

cnslaba4@linux-HP-Pro-3090-MT:~/Documents/cns-lab-sit-master/transposition$ ./a.out 
Enter message : attackpostponeduntiltwoam
Enter key : 4312567
a	t	t	a	c	k	p	
o	s	t	p	o	n	e	
d	u	n	t	i	l	t	
w	o	a	m	x	x	x	
Original text 		: attackpostponeduntiltwoam
Cipher   text		: ttnaaptmtsuoaodwcoixknlxpetx
Decrypted text		: attackpostponeduntiltwoamxxx

cnslaba4@linux-HP-Pro-3090-MT:~/Documents/cns-lab-sit-master/transposition$ ./a.out 
Enter message : helloitsme
Enter key : 3142
h	e	l	l	
o	i	t	s	
m	e	x	x	
Original text 		: helloitsme
Cipher   text		: eielsxhomlsx
Decrypted text		: helloitsmexx


cnslaba4@linux-HP-Pro-3090-MT:~/Documents/cns-lab-sit-master/transposition$ ./a.out 
Enter message : todayisgood
Enter key : 615423
t	o	d	a	y	i	
s	g	o	o	d	x	
Original text 		: todayisgood
Cipher   text		: ogydixaodots
Decrypted text		: todayisgoodx

*/


