#include "tokenizer.h"

/*!
 *default constructor
 */
Tokenizer::Tokenizer(){
	fileName = "";
}
/*!
 *
 * @param fileName
 * Parametrized constructor
 */
Tokenizer::Tokenizer(string fileName){
	this->fileName = fileName;
}

/*!
 *
 * @return
 * @return vector<string>
 * This method reads from a file, remove punctuation and insert
 * back the different words into a vector of string.
 * It return that vector at the end.
   */
vector<string> Tokenizer::tokentoDocument(){

	ifstream ifs(fileName.c_str());
	    string word;
	    string newWord;
	    vector<string> v2;
	    if(!ifs){
	        cerr << "Error! File not Found" << endl;
	    }
	    while(ifs>>word){
	        newWord = "";
	        remove_copy_if(word.begin(), word.end(),
	                       back_inserter(newWord),
	                       ptr_fun<int, int>(ispunct));

	        //Algorithm that converts everything to lower case
	        transform(newWord.begin(), newWord.end(), newWord.begin(),::tolower);

	        v2.push_back(newWord); //pushes in the fixed words into a vector passed by user.
	    }

	    return v2;
}
/*!
 + * @param s
 + * @return vector<string>
 + * This methods takes a string and iterate through every character
 + * by checking if it is an space, if so it continues until it reaches a character.
 + * Once it hits one, it keeps of the position of the first character and the last and
 + * insert the corresponding word into the vector string.
 + * Once it has iterate through all the characters, the method return the vector string.
 + */
vector<string> Tokenizer::removeSpace (string  s) {

vector<string> tokens;
unsigned int i = 0;
unsigned int j = 0;

while (i != s.size() && j != s.size()) {

    while (i != s.size() && isspace(s[i])){
        ++i;
        j = i;
    }
    while (j != s.size() && !isspace(s[j])) {
        j++;
    }

    if (i != j) {
        tokens.push_back(s.substr(i, j - i));
        i = j;
    }
}
return tokens;
}
/*!
 + *
 + * @param os
 + * @param t
 + * @return
 + * taking in ostream and a Tokenizer
 + * Overload of the operator <<
 + * Output and appropriate message if the given tokenizer is not initialized properly.
 + * Else, it displays the name of the file.
 + */
ostream & operator << (ostream & os, Tokenizer & t)

{
	if(t.fileName=="")
	{
		os<<"Error, name seems to not be initialized.";
	}
	else{
		os<<"Here is the name of the file of this Tokenizer:"+ t.fileName ;
	}
	return os;
}
