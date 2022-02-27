# Python3 program to find the longest subsequence 
# of vowels in the specified order 

vowels = ['a', 'e', 'i', 'o', 'u'] 

# Mapping values for vowels 
mapping = {'a': 0, 'e': 1, 'i': 2, 'o': 3, 'u': 4} 

# Function to check if given subsequence 
# contains all the vowels or not 
def isValidSequence(subList): 
	
	for vowel in vowels: 
		if vowel not in subList: 
			return False
			
	return True

# Function to find the longest subsequence of vowels 
# in the given string in specified order 
def longestSubsequence(string, subList, index): 
	
	# If we have reached the end of the string, 
	# return the subsequence 
	# if it is valid, else return an empty list 
	if index == len(string): 
		if isValidSequence(subList) == True: 
			return subList 
		else: 
			return [] 
		
	else: 
		# If there is no vowel in the subsequence yet, 
		# add vowel at current index if it is 'a', 
		# else move on to the next character 
		# in the string 
		if len(subList) == 0: 
			
			if string[index] != 'a': 
				return longestSubsequence(string, subList, index + 1) 
			else: 
				return longestSubsequence(string, subList + \ 
							[string[index]], index + 1) 
		
		# If the last vowel in the subsequence until 
		# now is same as the vowel at current index, 
		# add it to the subsequence 
		elif mapping[subList[-1]] == mapping[string[index]]: 
			return longestSubsequence(string, subList + \ 
							[string[index]], index + 1) 
		
		# If the vowel at the current index comes 
		# right after the last vowel 
		# in the subsequence, we have two options: 
		# either to add the vowel in 
		# the subsequence, or move on to next character. 
		# We choose the one which gives the longest subsequence. 
		elif (mapping[subList[-1]] + 1) == mapping[string[index]]: 
			
			sub1 = longestSubsequence(string, subList + \ 
								[string[index]], index + 1) 
			sub2 = longestSubsequence(string, subList, index + 1) 
			
			if len(sub1) > len(sub2): 
				return sub1 
			else: 
				return sub2 
				
		else: 
			return longestSubsequence(string, subList, index + 1) 

# Driver Code 
if __name__ == "__main__": 
		
	string = "aeiaaioooauuaeiou"
	
	subsequence = longestSubsequence(string, [], 0) 
	if len(subsequence) == 0: 
		print("No subsequence possible") 
	else: 
		print(subsequence) 