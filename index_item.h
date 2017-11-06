//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_INDEX_ITEM_H
#define GOOGLER_INDEX_ITEM_H

#include <vector>
#include <unordered_map>

using namespace std;

class index_item {
public:
    index_item();
   virtual ~index_item();
    virtual int getSize();
    virtual void setSize(int newsize);
private:
    int size;
};


#endif //GOOGLER_INDEX_ITEM_H
