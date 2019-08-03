#include<bits/stdc++.h>
#include<ctype.h>

using namespace std ; 

void encrypt(char * s , int key ){
	key = key%26 ; 
	for(int i =0 ;i < strlen(s) ; i++){
		s[i] = (s[i]+key)%('z'+1) ; 
		if(s[i]<'a') s[i]+='a' ; 
		}
}

void decrypt(char * s , int key){
	key = key%26 ; 
	for(int i =0 ;i < strlen(s) ; i++){
		s[i]-=key ;
		if(s[i]<'a'){ s[i]= 'z'-('a'-s[i])+1  ; }
	}
}

int main(void){
	char arr[100] ; 
	int key ; 
	cout<<"Enter (lowercase) string : " ; cin>>arr ; 
	cout<<"Enter key : "  ; cin>>key   ; 
	encrypt(arr,key) ; 
	cout<<"cypher text = " << arr <<endl; 
	decrypt(arr,key) ; 
	cout<<"plain text = " << arr <<endl; 

}
