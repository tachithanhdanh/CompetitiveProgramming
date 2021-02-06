#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);

	//Read N and K.
	int N, K;
	cin >> N >> K;

	//This variable is used for storing the number of characters
	//on the current line but NOT including the spaces characters.
	int Word_Length = 0;

	for (int i = 0; i < N; ++i){
		string S;
		cin >> S; //Read the next word.
		//Calculate the new length if we put the new word into the current line.
		Word_Length += S.length(); 
		if (Word_Length <= K) { //If it still satisfies the constraint then print that word.
			//If it is not the first ever word then we print a space character
			if(i) cout << " ";	 
			cout << S;
		}
		else { //Else we create a new line and print the word on that line.
			cout << "\n" << S;
			Word_Length = S.length();
		} 
	}	
	return 0;
}