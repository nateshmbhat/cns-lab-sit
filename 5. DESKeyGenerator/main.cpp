#include <bits/stdc++.h>
 
using namespace std;
 
int permChoiceOne[] = {
   57, 49, 41, 33, 25, 17, 9,
   1, 58, 50, 42, 34, 26, 18,
   10, 2, 59, 51, 43, 35, 27,
   19, 11, 3, 60, 52, 44, 36,
   63, 55, 47, 39, 31, 23, 15,
   7, 62, 54, 46, 38, 30, 22,
   14, 6, 61, 53, 45, 37, 29,
   21, 13, 5, 28, 20, 12, 4};
 
int permChoiceTwo[] = {
   14, 17, 11, 24, 1, 5, 3, 28,
   15, 6, 21, 10, 23, 19, 12, 4,
   26, 8, 16, 7, 27, 20, 13, 2,
   41, 52, 31, 37, 47, 55, 30, 40,
   51, 45, 33, 48, 44, 49, 39, 56,
   34, 53, 46, 42, 50, 36, 29, 32};
 
int leftShiftTable[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
 
string rotateSubKey(string s , int rotation)
{
	return s.substr(rotation,s.length()-rotation) + s.substr(0,rotation) ; 
}
 
 
string firstPermute(string input)
{
 	string res = "" ;
	for(int i =0 ;i < 56  ; i++) res+=input[permChoiceOne[i]-1] ; 
	return res ; 
}

string secondPermute(string input)
{
 	string res = "" ;
	for(int i =0 ;i < 48 ; i++)  res+=input[permChoiceTwo[i]-1] ; 
	return res ; 
}
 
 
void genKeys(string left, string right )
{
   ofstream fout ; 
   fout.open("keygen.txt") ; 
   for (int count = 0; count < 16; count++)
   {
       left = rotateSubKey(left, leftShiftTable[count]);
       right = rotateSubKey(right, leftShiftTable[count]);
 
       string key = secondPermute(left+right) ;
       cout<<"key"<<count+1<<" 	: "  << key<<endl;
       fout<<key<<endl; 
   }
}

 
int main(){
	unsigned long long hexkey  ;
	cout<<"Enter 64 bit key in hex: " ; 
	cin>>hex>>hexkey ; 
	
	string key = bitset<64>(hexkey).to_string() ; 
	key = firstPermute(key) ;
	genKeys(key.substr(0,28) , key.substr(28,28)) ; 
	cout<<endl<<endl ; 
}


/*
  OUTPUT

Enter 64 bit key in hex: 133457799bbcdff1

key1 	: 000110110000001011101111111111000111000001110010
key2 	: 011110011010111011011001110110111100100111100101
key3 	: 010101011111110010001010010000101100111110011001
key4 	: 011100101010110111010110110110110011010100011101
key5 	: 011111001110110000000111111010110101001110101000
key6 	: 011000111010010100111110010100000111101100101111
key7 	: 111011001000010010110111111101100001100010111100
key8 	: 111101111000101000111010110000010011101111111011
key9 	: 111000001101101111101011111011011110011110000001
key10 	: 101100011111001101000111101110100100011001001111
key11 	: 001000010101111111010011110111101101001110000110
key12 	: 011101010111000111110101100101000110011111101001
key13 	: 100101111100010111010001111110101011101001000001
key14 	: 010111110100001110110111111100101110011100111010
key15 	: 101111111001000110001101001111010011111100001010
key16 	: 110010110011110110001011000011100001011111110101

*/