/* customer.h
customer class for CRM
Class that handles and stores information about the individual customer*/

#include <iostream>
#include <fstream>

using namespace std;

// Declare customer class
class customer {
    public:
        int id;
        string name;
        string city;
        string state;
        int last_visit;
        int total_sales;

    customer(int i_id,string i_name,int i_last_visit,int i_total_sales=0,string i_city="NULL",string i_state="NULL")
        :id(i_id),
        name(i_name),
        last_visit(i_last_visit),
        total_sales(i_total_sales),
        city(i_city),
        state(i_state)
    {
    }
    
    void show_customer();
    std::string format_date();
};