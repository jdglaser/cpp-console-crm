/* interface.hpp
interface member function definitions */
#include "interface.h"

// This function handles adding a new customer to the customer table
void interface::handle_add_cust() {
    std::string name, city, state;
    int last_visit, total_sales;
    int last_id = customer_table.get_max_id();
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    cout << "Enter Customer first and last name: ";
    std::getline(cin,name);
    cout << "Enter Customer City: ";
    std::getline(cin,city,'\n');
    cout << "Enter Customer State: ";
    std::getline(cin,state,'\n');
    cout << "Enter Customer's Last Visit (YYYYMMDD): ";
    cin >> last_visit;
    cout << "Enter Customer's Total Sales: ";
    cin >> total_sales;
    customer new_cust(last_id+1,name,last_visit,total_sales,city,state);
    // The id of the new customer should be the max existing ID incremented by 1
    customer_table.insert_row(last_id+1,new_cust);
}

// Function that handles deleting a customer from the table
void interface::handle_delete_cust() {
    int delete_id;
    cout << "Enter customer ID to delete: ";
    cin >> delete_id;
    // Search table for the id
    auto search = customer_table.hashtable.find(delete_id);
    // If the id is found then carry out process else warn user
    if (search != customer_table.hashtable.end()) {
        cout << "Found customer ID " << search->first << " with the following information: " << endl;
        cout << "Name: " << search->second.name << endl;
        cout << "City: " << search->second.city << endl;
        cout << "State: " << search->second.state << endl;
        cout << "Last Visit: " << search->second.format_date() << endl;
        cout << "Total Sales: $" << search->second.total_sales << endl;
        cout << "Are you sure you want to delete this customer? (Y or N)";
        string ans;
        cin >> ans;
        if (ans == "Y") {
            customer_table.hashtable.erase(search->first);
            cout << "Customer deleted." << endl;
        } else {
            cout << "Customer not deleted." << endl;
        }
    } else {
        cout << "No customer ID " +  std::to_string(delete_id) + " exists." << endl;
    }
}

// Function to handle updating customer
void interface::handle_update_cust() {
    int update_id;
    cout << "Enter customer ID to update: ";
    cin >> update_id;
    // Search for customer to update - if found carry out aciton else warn user
    auto search = customer_table.hashtable.find(update_id);
    if (search != customer_table.hashtable.end()) {
        std::string name, city, state;
        int last_visit, total_sales;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Found customer ID " << search->first << endl;
        cout << "Enter updated name: (Currently: " << search->second.name << "): ";
        std::getline(cin,name);
        cout << "Enter updated city: (Currently: " << search->second.city << "): ";
        std::getline(cin,city);
        cout << "Enter updated state: (Currently: " << search->second.state << "): ";
        std::getline(cin,state);
        cout << "Enter updated last visit as YYYYMMDD (Currently: " << search->second.last_visit << "): ";
        cin >> last_visit;
        cout << "Enter updated total sales (Currently: " << search->second.total_sales << "): ";
        cin >> total_sales;
        search->second.name = name;
        search->second.city = city;
        search->second.state = state;
        search->second.last_visit = last_visit;
        search->second.total_sales = total_sales;
        cout << "Customer " << search->first << " updated." << endl;
    } else {
        cout << "No customer ID " +  std::to_string(update_id) + " exists." << endl;
    }
}

// Function that handles showing options menu to user
void interface::show_options() {
    cout << "What would you like to do?" << endl;
    cout << "1 - Add Customer" << endl
    << "2 - Update Customer" << endl
    << "3 - Show Customers Table" << endl
    << "4 - Delete Customer" << endl
    << "5 - Show total sales" << endl
    << "6 - Exit Program" << endl;
}

// Function that handles showing user interface
void interface::show_interface() {
    customer_table.print_table(customer_table.get_max_id());
    int choice;
    // Run until user quits
    do {
        show_options();
        cin >> choice;
        // Add customer
        if (choice == 1)
        {
            handle_add_cust();
            customer_table.print_table(customer_table.get_max_id());
        } else if (choice == 2) // Update customer
        {
            handle_update_cust();
        } else if (choice == 3) // Show n rows of table
        {
            cout << "Select number of customers to show (Enter '*' to show all): " << endl;
            string n_show;
            cin >> n_show;
            if (n_show == "*") {
                customer_table.print_table(customer_table.get_max_id());
            } else {
                customer_table.print_table(stoi(n_show));
            }
            customer_table.write_data();
        } else if (choice == 4) // Delete customer
        {
            handle_delete_cust();
        } else if (choice == 5) {
            cout << "Total company sales are: $"
            << customer_table.get_total_sales() << endl;
        } else if (choice == 6) // Quit program
        {
            continue;
        } else {
            cout << "Please enter a number listed from the menu options (1-6)" << endl; // Fail safe
        }
    } while (choice != 6);
}