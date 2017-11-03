//
// Created by Sai Shan on 2017-11-03.
//

#ifndef COMP345_SENTENCE_H
#define COMP345_SENTENCE_H

#include "index_item.h"

class sentence : private index_item{
private:
    int pos;

public:
    void getPos();
    int size(); // need to override to return num of words in sentence.
};
#endif //COMP345_SENTENCE_H
