#include "UI\general_UI.hpp"

void General_UI::UI()
{
    int choice;
    cout << "---Please choose your role---\n";
    cout << "1. Admin\n";
    cout << "2. Receptionist\n";
    cin >> choice;
    if(choice == 1)
    {
        log_in_admin::LogInAdmin();
    }
    else if(choice == 2)
    {
        log_in_Receptionist::LogInReceptionist();
    }
}