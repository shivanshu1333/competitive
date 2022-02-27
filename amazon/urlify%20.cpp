// C++ program to replace spaces with %20
#include<stdio.h>
// Maximum length of string after modifications. 
const int MAX = 1000; 
// Replaces spaces with %20 in-place and returns
// new length of modified string. It returns -1
// if modified string cannot be stored in str[]
int change(char s[]){
	// count spaces and find current length 
	int cnt = 0, i; 
	for (i = 0; s[i]; i++) 
		if (s[i] == ' ') 
			cnt++; 

	// Remove trailing spaces 
	while (s[i-1] == ' ') 
	{ 
	cnt--; 
	i--; 
	} 

	// Find new length. 
	int len = i + cnt * 2 + 1; 

	// New length must be smaller than length 
	// of string provided. 
	if (len > MAX) 
		return -1; 

	// Start filling character from end 
	int ind = len - 1; 

	// Fill string termination. 
	s[ind--] = '\0'; 

	// Fill rest of the string from end 
	for (int j=i-1; j>=0; j--) 
	{ 
		// inserts %20 in place of space 
		if (s[j] == ' ') 
		{ 
			s[ind] = '0'; 
			s[ind - 1] = '2'; 
			s[ind - 2] = '%'; 
			ind = ind - 3; 
		} 
		else
		{ 
			s[ind] = s[j]; 
			ind--; 
		} 
	} 

	return len; 
}
int main(){
	char s[MAX] = "Mr John Smith ";
	// Prints the replaced string 
	int new_length = change(s); 
	for (int i=0; i<new_length; i++) 
		printf("%c", s[i]); 
	return 0; 
} 
