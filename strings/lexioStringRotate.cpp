bool compareSeq(char S[], int x, int y, int n) {
    for (int i = 0; i < n; i++) { 
        if (S[x] < S[y]) 
            return false; 
        else if (S[x] > S[y]) 
            return true; 
        x = (x + 1) % n; 
        y = (y + 1) % n; 
    } 
    return true; 
} 
// Function to find starting index 
// of lexicographically smallest sequence 
int smallestSequence(char S[], int n) {
    int index = 0; 
    for (int i = 1; i < n; i++) 
  
        // if new sequence is smaller 
        if (compareSeq(S, index, i, n)) 
  
            // change index of current min 
            index = i; 
  
    return index; 
} 
// Function to print lexicographically 
// smallest sequence 
void printSmallestSequence(char S[], int n) { 
    int starting_index = smallestSequence(S, n); 
    for (int i = 0; i < n; i++) 
        cout << S[(starting_index + i) % n]; 
}