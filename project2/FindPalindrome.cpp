#include <string>
#include <vector>
#include "FindPalindrome.hpp"

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

/** Helper function to convert string to lower case */
static void convertToLowerCase(std::string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

void FindPalindrome::recursiveFindPalindromes(std::vector<std::string>
        candidateSentence, std::vector<std::string> remainingWords)
{
    if(remainingWords.empty()){
        std::string fullSentence = "";
        for(const std::string& word : candidateSentence){
            fullSentence += word;
        }
        
        if(isPalindrome(fullSentence)){
            sentences.push_back(candidateSentence);  
        }
        return;
    }
    
    for(int i = 0; i < remainingWords.size(); i++){
        std::vector<std::string> newCandidate = candidateSentence;
        newCandidate.push_back(remainingWords[i]);
        
        std::vector<std::string> newRemaining;
        for(int j = 0; j < remainingWords.size(); j++){
            if(i != j){  
                newRemaining.push_back(remainingWords[j]);
            }
        }
        
        // Recurse with new vectors
        recursiveFindPalindromes(newCandidate, newRemaining);
	}
}

bool FindPalindrome::isPalindrome(std::string testString) const
{
	// make sure that the string is lower case
	convertToLowerCase(testString);
	// see if the characters are symmetric
	int stringLength = testString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (testString[i] != testString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	//make the varibles then clear them out
	wordList.clear();
	sentences.clear();

}

FindPalindrome::~FindPalindrome()
{
	/*destuctor */
	wordList.clear();
	sentences.clear();
}

int FindPalindrome::number() const
{

return sentences.size();
}

void FindPalindrome::clear()
{
	// TODO 
	sentences.clear();
}

bool FindPalindrome::cutTest1(const std::vector<std::string> & wordVector)
{
	//set up a vector for the charters ther are 26 leters in the alphabet
	int amountOfChars[26] = {0};
	// TODO 
	for(const std::string& word : wordVector){
		/*go through the line and place them in their own place*/
		for(char letter : word){
			/*make sure all of the leters are lowercase the go from a to b,c,d,etc..*/
			amountOfChars[tolower(letter) - 'a']++;
		}
	}
	int amountOfLettersOdd =0 ;
	//go through each leter 
	for (int i = 0 ; i <26; i++){
		//check if its odd
		if(amountOfChars[i] % 2 != 0){
			amountOfLettersOdd++;
		}
	}

	if (amountOfLettersOdd > 1){
		return false;
	}
	return true;
}

bool FindPalindrome::cutTest2(const std::vector<std::string> & wordVector1,
                              const std::vector<std::string> & wordVector2)
{
	/*check for each the two hald string one small and one large*/
	/*assuming the word vectors where allready sliced for me?*/

int correctTimes =0 ;
	for(int i = 0 ; i < wordVector1.size(); i++){
		if(wordVector1[i] == wordVector2[wordVector2.size()-1-i]){
			correctTimes++;
		}
	}
	if(wordVector1.size() == correctTimes){
		return true;
	}
	return false;
}
bool FindPalindrome::add(const std::string & newWord)
{
	// TODO 
	if(newWord  == ""){
	return false;
	}
	// number checker
	for(int i = 0 ; i < newWord.size(); i++){
		if(isdigit(newWord[i] || isspace(newWord[i]))){
			return false;
		}
	}
	/*looking for duplicate words*/
 	 for(const std::string& word : wordList){
		/*compairs the new word to the old one*/
        if(word == newWord){
            return false; 
        }
    }
	wordList.push_back(newWord);
	sentences.clear();
    recursiveFindPalindromes({}, wordList);
	return true;
}

bool FindPalindrome::add(const std::vector<std::string> & wordVector)
{
	/*error checking*/
	for (int i = 0; i< wordVector.size(); i++){
		if(wordVector[i] == ""){
			return false;
		}
	

	for (int j = 0; j < wordVector.size(); j++){
		if(isdigit(wordVector[i][j])){
			return false;
		}
	}	
}
    for (int i = 0; i < wordVector.size(); i++){
        wordList.push_back(wordVector[i]);

    }
	sentences.clear();
    recursiveFindPalindromes({}, wordList);
	return true;
}

std::vector< std::vector<std::string> > FindPalindrome::toVector() const
{
	// TODO
	return sentences;
}

