#include<bits/stdc++.h>

using namespace std ;

int getRand(){
	return rand()%1000 ; 
}

int main(void){

	srand(time(0)) ;
	int r = getRand() ; 

	for(int n = r; n<1000000 ; n++){
	bool flag = true ; 

		for(int i =2 ; i<=sqrt(n) ; i++){
			if(n%i==0) { 
				flag = false ; 
				break ; 
			}
	}

	if(flag){
		cout<< n << " " ; 
		break ; 
	}

	}
}
