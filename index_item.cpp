//
// Created by Dabu on 2017-11-04.
//

#include "index_item.h"

index_item::index_item() : size(0) { }

int index_item::getSize() {
    return size;
}
void index_item::setSize(int newsize){
	size = newsize;
}
index_item::~index_item(){}
