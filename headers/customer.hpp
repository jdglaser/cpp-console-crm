/*
customer.hpp
Member function definitions of customer class
*/

#include "customer.h"

// Function to format date to YYYY-MM-DD
std::string customer::format_date()
{
    std::string date = std::to_string(customer::last_visit);
    std::string date_form = date.substr(0,4) + "-" + date.substr(4,2) + "-" + date.substr(6,2);
    return date_form;
}