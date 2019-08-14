#include<bits/stdc++.h>

using namespace std ;

int getRand(){
		return rand()%1000 ; 
}

int main(void){

		srand(time(0)) ;
		int r = getRand() ; 
		cout<<"Random number = " << r << endl; 
		bool flag = true ;
		for(int i = 2 ; i <= sqrt(r) ; i++){
			if(r%i==0){
				flag = false ;
				break ; 
			}
		}
		if(flag) cout<<"It is a prime number "  ; 
		else cout<<"It is a composite number" ; 

}
