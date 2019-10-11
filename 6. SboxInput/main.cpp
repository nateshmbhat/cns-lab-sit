#include<bits/stdc++.h>

using namespace std ; 

int expansionTable[48]=  
{   
	32,1,2,3,4,5,4,5, 
	6,7,8,9,8,9,10,11, 
	12,13,12,13,14,15,16,17, 
	16,17,18,19,20,21,20,21, 
	22,23,24,25,24,25,26,27, 
	28,29,28,29,30,31,32,1 
}; 

string getKeyIFromFile( int round , const char * filename = "keygen.txt"){
	ifstream fin ;
	fin.open(filename) ;
	string temp ; 
	for(int j= 0 ;j < round ; j++) fin >> temp ; 
	return temp ;
}


string applyExpansionPermutation(string input){
	string res="" ; 
	for(int i =0 ;i < 48  ; i++  ){
		res+=input[expansionTable[i]-1] ; 
	}
	return res ; 
}

string performXOR( string s1 , string s2){
	string res = "" ; 
	for(int i= 0 ;i < s1.length() ; i++){
		res+= ( s1[i]==s2[i]?'0':'1' ) ;
	}
	return res ; 
}

string getSboxInput(string input , int round ){
	input = input.substr(32,32);     //  Get last 32 bit data
  input = applyExpansionPermutation(input) ; 
	string key = getKeyIFromFile(round) ; 
	return performXOR(input , key) ; 
}


int main(void){
	string input ; unsigned long long hexval ; int round ; 
	cout<<"Enter 64 bit input in hex : " ; cin >> hex >> hexval ;  
	cout<<"Enter round number i : " ;  cin >> round ; 
	input = bitset<64>(hexval).to_string() ;  
	cout<<"Binary represetation is : " << endl ; 
	cout<<input <<endl ; 
	cout<<"Sbox input is : " <<endl; 
	cout << getSboxInput(input , round)  <<endl; 
}


/*

Enter 64 bit input in hex : cc00ccfff0aaf0aa
Enter round number i : 1
Binary represetation is :
1100110000000000110011001111111111110000101010101111000010101010
Sbox input is :
011000010001011110111010100001100110010100100111



 */
