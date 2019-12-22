/* Interface class
Handles table interface and user inputs */

#include <iostream>
#include "cust_table.h"

class interface {
    public:
        // Pointer to customer table - all input actions will affect this table
        cust_table& customer_table;

        interface(cust_table& i_cust_table)
            : customer_table(i_cust_table)
        {};

        void show_interface();
        void show_options();
        void handle_add_cust();
        void handle_update_cust();
        void handle_delete_cust();
};