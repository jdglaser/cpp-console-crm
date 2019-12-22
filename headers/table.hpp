/* table.hpp
Table member class definitions */
#include "table.h"

// Class to add a new row to the table
template <typename K, typename V>
void table<K,V>::insert_row(K key, V value) {
    hashtable.emplace(key,value);
}
