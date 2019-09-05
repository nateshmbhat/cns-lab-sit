#include<bits/stdc++.h>
typedef struct{
	int row , col ; 
} Position ; 

using namespace std  ; 

char m[5][5]  = {0} ;

void fillMatrix(string key){
	string oldkey = key  ; 
	key = "" ; 
	for(int i= 0 ;i < oldkey.length() ; i++) key+=(oldkey[i]=='i'?'j':oldkey[i]) ;
	int r =0 , c = 0 ; 
	set<char> charsLeft ;
	for(int l ='a' ; l<='z' ; l++) charsLeft.insert(l) ;
	charsLeft.erase('i') ;
	
	int i = 0 ;
	set<char> charsAdded ;
	while(i<key.length()){
		if(charsLeft.find(key[i])!=charsLeft.end()){		
			m[r][c++] = key[i] ;
			if(c==5){
				r++ ; c = 0 ;
			}
			charsLeft.erase(key[i]) ;
		}
		i++ ;
	}
		
	while(charsLeft.size()>0){
		m[r][c++] = *charsLeft.begin() ;
		if(c==5){
			r++ ; c = 0 ;
		}
		charsLeft.erase(*charsLeft.begin()) ;
	}
}

void showMatrix(){
	for(int i =0 ;i< 5 ; i++){
		for(int j= 0 ;j < 5  ; j++){
			cout<<m[i][j] <<" " ;
		}
		cout<<endl; 
	}
}

Position locateElement(char k){
	for(int i =0  ; i < 5 ; i++)
		for(int j= 0 ;j < 5 ; j++)
			if(m[i][j]==k){
				Position p = {i , j} ; 
				return p ;
			}
}

string preProcessPlainText(string pt){
    string ptcopy = pt ;
    pt = "" ; 
    for(int i =0 ;i < ptcopy.length() ; i++) pt+=(ptcopy[i]=='i'?'j':ptcopy[i]) ; 
	for(int i =1 ; i < pt.length() ; i+=2){
		if(pt[i]==pt[i-1])
			pt.insert(i , "x") ;
	}
	if(pt.length()&1)pt+="x" ; //pad extra x if length is odd
	return pt ;
}

string encipher(string pt){
	pt = preProcessPlainText(pt) ;	
	cout<<endl <<"Processed text = " << pt  ; 
	string cipher = "" ;
	for(int i =1 ; i<pt.length() ; i+=2){
		char a=pt[i-1] , b = pt[i] ;
		Position posa = locateElement(a)  ;
		Position posb = locateElement(b)  ;
		
		if(posa.row==posb.row){
			cipher+=m[posa.row][(posa.col+1)%5] ;
			cipher+=m[posa.row][(posb.col+1)%5] ;
		}
		else if(posa.col==posb.col){
			cipher+=m[(posa.row+1)%5][posa.col] ;
			cipher+=m[(posb.row+1)%5][posa.col] ;
		}
		else{
			cipher+=m[posa.row][posb.col] ;
			cipher+=m[posb.row][posa.col] ;
		}
	}
	return cipher ;
}

string decipher(string pt){
	string cipher = "" ;
	for(int i =1 ; i<pt.length() ; i+=2){
		char a=pt[i-1] , b = pt[i] ;
		Position posa = locateElement(a)  ;
		Position posb = locateElement(b)  ;
		
		if(posa.row==posb.row){
			cipher+=m[posa.row][(posa.col-1>=0?posa.col-1:4)] ;
			cipher+=m[posa.row][(posb.col-1>=0?posb.col-1:4)] ;
		}
		else if(posa.col==posb.col){
			cipher+=m[(posa.row-1>=0?posa.row-1:4)][posa.col] ;
			cipher+=m[(posb.row-1>=0?posb.row-1:4)][posa.col] ;
		}
		else{
			cipher+=m[posa.row][posb.col] ;
			cipher+=m[posb.row][posa.col] ;
		}
	}
	return cipher ;
}

int main(void){
	string msg = "jazz" ;
	string key="monarchy" ;
	cout<<"Enter plain text : "  ; cin >> msg ; 
	while(1){
		cout<<"Enter key : " ; cin>>key ;
		fillMatrix(key) ;
		showMatrix() ;
		string cipher = encipher(msg) ;
		cout<<endl <<"Plain  text = " << msg  ; 
		cout<<endl <<"Cipher text = " << cipher  <<endl ;
		cout<<endl <<"Plain  text after decrypting = " << decipher(cipher)  <<endl;  	
	}
}

/*

Enter plain text : helloitsme
Enter key : monarchy
m o n a r 
c h y b d 
e f g j k 
l p q s t 
u v w x z 

Processed text = helxlojtsmex
Plain  text = helloitsme
Cipher text = cfsupmkslaju

Plain  text after decrypting = helxlojtsmex
Enter key : paymore
p a y m o 
r e b c d 
f g h j k 
l n q s t 
u v w x z 

Processed text = helxlojtsmex
Plain  text = helloitsme
Cipher text = gbsutpksxccv

Plain  text after decrypting = helxlojtsmex
Enter key : wisdom
w j s d o 
m a b c e 
f g h k l 
n p q r t 
u v x y z 

Processed text = helxlojtsmex
Plain  text = helloitsme
Cipher text = lbhzteopwbbz

Plain  text after decrypting = helxlojtsmex
Enter key : enhance
e n h a c 
b d f g j 
k l m o p 
q r s t u 
v w x y z 

Processed text = helxlojtsmex
Plain  text = helloitsme
Cipher text = anmwmpguxshv

Plain  text after decrypting = helxlojtsmex
Enter key : encrypt
e n c r y 
p t a b d 
f g h j k 
l m o q s 
u v w x z 

Processed text = helxlojtsmex
Plain  text = helloitsme
Cipher text = fcqumqgbloru

Plain  text after decrypting = helxlojtsmex


*/