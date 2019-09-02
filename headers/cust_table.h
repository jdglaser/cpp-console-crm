/* cust_table.h
Customer table class for CRM
Inherits from base table class */

// Avoid repeat loading file
#ifndef __cust_table_H_INCLUDED__ 
#define __cust_table_H_INCLUDED__ 

#include <iostream>
#include "table.h"
#include "customer.hpp"

using namespace std;

class cust_table : public table<int,customer>  {
    public:
        std::string filename;

        // Constructor - assign params and fill table with data on class creation
        cust_table(std::string i_filename)
        :filename(i_filename)
        {cust_table::read_data();};
        // Destructor - save the data to local db and empty out in memory table
        ~cust_table() {
            write_data();
            hashtable.clear();
        }
        // Member functions
        void print_table(int n_rows);
        void read_data();
        void write_data();
        int get_max_id();
        int get_total_sales();
};

// Because this class inherits from a template class, we include class definitions script at bottom
#include "cust_table.hpp"

#endif