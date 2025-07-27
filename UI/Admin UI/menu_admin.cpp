#include "menu_admin.hpp"
#include "Employee Management\Admin\Staff Management\staff_management.hpp"
void AdminMenu::admin_menu_list()
{
    int choice ;
    cout << "---ADMIN MENU---\n";
    cout << "1. Receptionist management\n";
    cout << "2. Room management\n";
    cout << "3. Service management\n";
    cout << "0. Back\n";
    cout << "Please choose\n";
    cin >> choice;
    if(choice == 1)
    {
        int manage_staff_choice;
        cout << "---Manage staff---\n";
        cout <<"1. Add staff\n" << "2. Change staff's information\n" << "3. Delete staff\n" << "4. Set up work shifts for staff\n" << "5. Staff list\n" << "6. Work schedule\n" << "0. Back\n";
        cout << "Please choose: ";
        cin >> manage_staff_choice;
        switch (manage_staff_choice)
        {
        case 1:
            /* code */
            AddStaff::admin_add_new_staff();
            
            break;
        
        default:
            break;
        }
    }
}