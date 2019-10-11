#include<bits/stdc++.h>

using namespace std ; 

int main(void){

	int S[256] , T[256] ; 
	int key[100] , pt[100] ; 
	int j =0, i = 0 ,n ; 
	string keyString , ptString ; 
	cout<<"Enter plaintext : " ; cin>>ptString ; 
	cout<<"Enter key of same length : " ; cin>>keyString ; 
	n = keyString.length() ; 
	for(i =0 ;i<keyString.length() ; i++) key[i] = keyString[i] ; 
	for(i =0 ;i<ptString.length() ; i++) pt[i] = ptString[i] ; 

	cout<<"plaintext in bytes : " ;
	for(i =0 ;i < n ; i++) cout<<pt[i]<<" " ; 
	cout<<endl; 

	for(i =0 ;i<256 ; i++){
		S[i] = i ; 
		T[i] = key[i%n] ; 
	}
	
	for(i =0 ;i < 256 ; i++)
	{
		j = (j+S[i] + T[i])%256 ; 
		swap(S[i] , S[j]) ;
	}

	vector<int> keystream ; 
	i = 0 , j =0 ; 
	for(int p = 0 ; p<n ; p++){
		i = (i+1)%256 ;  
		j = (j+S[i])%256 ; 
		swap(S[i] , S[j]) ; 
		int t = (S[i]+S[j])%256 ; 
		int k = S[t] ; 
		keystream.push_back(k) ; 
	}
	
	cout<<"keystream is : "  ; 
	for(i =0 ;i < keystream.size() ; i++) 
		cout<<keystream[i] << " " ;
	cout<<endl<<"Cipher text is : " ; 
	for(i =0 ;i < keystream.size() ; i++) 
		cout<<(pt[i]=pt[i]^keystream[i])<<" "  ; 
	
	cout<<endl<<"Plaintext after decryption : " ; 
	for(i =0 ;i < keystream.size() ; i++) 
		cout<<(pt[i]^keystream[i])<<" "  ; 
	
	cout<<endl;
}

/*

Enter plaintext : hello
Enter key of same length : yello 
plaintext in bytes : 104 101 108 108 111 
keystream is : 248 30 202 165 16 
Cipher text is : 144 123 166 201 127 
Plaintext after decryption : 104 101 108 108 111 



Enter plaintext : ramesh
Enter key of same length : ganesh
plaintext in bytes : 114 97 109 101 115 104 
keystream is : 147 9 65 204 1 213 
Cipher text is : 225 104 44 169 114 189 
Plaintext after decryption : 114 97 109 101 115 104 

*/