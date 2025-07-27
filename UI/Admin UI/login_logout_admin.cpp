#include "login_logout_admin.hpp"
#include "staff_management.hpp"
void log_in_admin::LogInAdmin()
{
    log_in_interface: /* log in interface flag*/
        string admin_username, admin_password;
        cout << "Please enter username: ";
        cin.ignore();
        getline(cin, admin_username);
        cout << "Please enter password: ";
        getline(cin, admin_password);
        ifstream file("database/admin.csv");
        if(!file.is_open())
        {
            cout << "Can not open admin database---Please check your console and restart the program\n";
            goto log_in_interface;
        }
         
        /* code */
        string line;
        
        getline(file, line);
          uint16_t found = 0;
        while(getline(file, line))
        {
            stringstream readline(line);
            string username, password, phone, id;

            getline(readline, username, ',');
            getline(readline, password, ',');
            getline(readline, phone, ',');
            getline(readline, id, ',');
            if(username == admin_username && admin_password == password)
            {
                cout << "Log in successfully\n";
                found = 1;
                AdminMenu::admin_menu_list();
                break;
            } 
        }
        if(found == 0)
        {
            cout << "Password or username is wrong, please log in again\n";
            goto log_in_interface;
        }
    file.close();
}

void log_out_admin::LogOutAdmin()
{
    cout << "Log out successfully\n";
    log_in_admin::LogInAdmin();
}