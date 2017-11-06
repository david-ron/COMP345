//
// Created by Dabu on 2017-11-04.
//

#include "abstract_tokenizer.h"
abstract_tokenizer::abstract_tokenizer():fileName(""){}
abstract_tokenizer::abstract_tokenizer(string n) : fileName(n) {}

string abstract_tokenizer::getFileName()
{
	return fileName;
}
void abstract_tokenizer::setFileName(string s)
{
	fileName = s;
}
abstract_tokenizer::~abstract_tokenizer(){

}
