/* table.h
table class header file. 
Used as the base table class that the customer will inherit  */

// Avoid repeat loading file
#ifndef __table_H_INCLUDED__
#define __table_H_INCLUDED__

#include <iostream>
#include <map>

using namespace std;

// Create as a template so class can be expanded upon in future updates
template <typename K, typename V>
class table  {
    public:
        map<K,V> hashtable;

        void insert_row(K key,V value);
};

// Since we are using a template class we include the table.cpp at the bottom
#include "table.hpp"

#endif