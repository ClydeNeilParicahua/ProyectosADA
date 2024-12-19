#include<iostream>
using namespace std;
int main(){
int T , B;
cin >> T>>B;
int resultado = (T+1)/ 2;
resultado += (T- resultado )% (B -1);
cout << resultado << endl ;

}
