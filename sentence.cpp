/*
 * sentence.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */
#include "sentence.h"

sentence::sentence():index_item(){
	pos = -1;
}
sentence::sentence(vector<string> sent,int npos):index_item(){
	for(int i = 0;sent.size();++i){

	}
	pos = npos;
}
void sentence::setSize(int newSize){
	setSize(sen.size());
}
int sentence::getPos(){
	return 1;
}


