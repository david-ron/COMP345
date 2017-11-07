//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_INDEX_H
#define GOOGLER_INDEX_H

#include <vector>
#include "query_result.h"

class index {

public:
    index();
    virtual void normalize()=0;
    virtual ~index();
    virtual std::vector<double> score() =0;
    virtual void print() = 0;
    virtual vector<query_result> query(string, int x)=0;
private:
    int count; // Counts number of sentences and number of documents.

};


#endif //GOOGLER_INDEX_H
