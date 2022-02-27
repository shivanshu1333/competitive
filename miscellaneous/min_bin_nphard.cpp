// C++ program to find number of bins required using 
// First Fit Decreasing algorithm. 
#include <bits/stdc++.h> 
using namespace std; 

/* Copy firstFit() from above */

// Returns number of bins required using first fit 
// decreasing offline algorithm 
int firstFitDec(int weight[], int n, int c) 
{ 
	// First sort all weights in decreasing order 
	sort(weight, weight + n, std::greater<int>()); 

	// Now call first fit for sorted items 
	return firstFit(weight, n, c); 
} 

// Driver program 
int main() 
{ 
	int weight[] = { 2, 5, 4, 7, 1, 3, 8 }; 
	int c = 10; 
	int n = sizeof(weight) / sizeof(weight[0]); 
	cout << "Number of bins required in First Fit "
		<< "Decreasing : " << firstFitDec(weight, n, c); 
	return 0; 
} 
