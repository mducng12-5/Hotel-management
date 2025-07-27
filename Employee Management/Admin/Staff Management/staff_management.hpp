#ifndef staff_management_hpp
#define staff_management_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <iterator>
#include <fstream>

#include "UI\Admin UI\menu_admin.hpp"

using namespace std;

class StaffManagement
{
    protected:
        static list<string> receptionist_username;
        static list<int> receptionist_ID;
        static list<string> receptionist_phone_number;
        static list<string> receptionist_role;
};

class AddStaff : public StaffManagement
{
    public:
        AddStaff(){}
        ~AddStaff(){}
        static void admin_add_new_staff();
};


#endif