//Checks if a string has all unique characters
//Returns 1 if all unique chars, 0 otherwise
int uniqueCheck (char* str){
	int charcount[128] = {0}; 	//Create an array representing ascii values
	int i;
	for (i = 0; str[i] != '\0'; i ++){
		charcount[(int)str[i]] ++;	//Increment the value at ascii index that represents the character
	} 

	//Verify that all entries are 0 or 1
	for (i = 0; i < 128; i ++){
		if (charcount[i] > 1){
			return 0;
		}
	}
	return 1;
}

//Check if 2 strings are permutations of each other
//2 strings are permutations of each other if they are made of the same characters
int checkPerm(char* str1, char* str2){
	int charcount[128] = {0}; //Create an array representing ascii values
	int i;
	for (i = 0; str1[i] != '\0'; i ++){
		charcount[(int)str1[i]] ++;
	} 
	for (i = 0; str2[i] != '\0'; i ++){
		charcount[(int)str2[i]] --;
	} 

	//Verify that all characters appear the same amount of times in string 1 and string 2
	for (i = 0; i < 128; i ++){
		if (charcount[i] != 0){
			return 0;
		}
	}
	return 1;
}

//Check if a string is a permutation of a palindrome
//A palindrome is a word that is the same forwards and backwards ex. racecar
//Palindromes can have at most 1 letter with an odd frequency
int palinPerm(char* str){
	int charcount[128] = {0}; //Create an array representing ascii values
	int i;
	for (i = 0; str[i] != '\0'; i ++){
		charcount[(int)str[i]] ++;
	} 

	int oddcount = 0;
	//Check that no more than 1 character appears an odd number of times
	for (i = 0; i < 128; i ++){
		if (charcount[i]%2 == 1)
			oddcount ++;
	}
	if (oddcount > 1)
		return 0;
	else
		return 1;

}

//Given a string, reverse it
//Ex. input "dog" should be changed to "god"
void reverse (char* str){
	int front = 0;					//Have one pointer at start of string
	int finalChar = strlen(str) - 1;
	int rear = front + finalChar;		//Have one pointer at rear of string
	char temp;
	while (front < rear){
		temp = str[front];					//Swap values that two pointers are pointing at 
		str[front] = str[rear];
		str[rear] = temp;

		front ++;						//Move the pointers over
		rear --;
	}
	//Alternatively, this could be done using char* pointers instead of using array indexes
}

//Call varius functions that modify strings
int main(){
	if (uniqueCheck("abcdefgg"))
		printf("Should not print\n");
	if (uniqueCheck("abcdefg"))
		printf("Should print\n");
	
	if (checkPerm("doggy", "godgy"))
		printf("Should print\n");
	if (checkPerm("dog", "cat"))
		printf("Should not print\n");

	if (palinPerm("racecra"))
		printf("Should print\n");
	if (palinPerm("dog"))
		printf("Should not print\n");

	char test* = "dog";
	reverse(test);
	printf("What is dog reversed?: %s\n", test);


	return 0;
}