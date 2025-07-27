#include "staff_management.hpp"

list<string> StaffManagement::receptionist_username;
list<string> StaffManagement::receptionist_phone_number;
list<string> StaffManagement::receptionist_role;
list<int> StaffManagement::receptionist_ID;



void AddStaff::admin_add_new_staff()
{
    add_new_staff: 
        uint8_t choice = 0;
        cout << "---ADD STAFF---\n";
        cout << "Enter staff name: ";
        string new_staff_username, new_staff_phone_number, new_staff_role;
        cin >> new_staff_username;
        cout << "Enter phone number: ";
        cin >> new_staff_phone_number;
        cout << "Enter work position: ";
        cin >> new_staff_role;
        receptionist_username.push_back(new_staff_username);
        receptionist_phone_number.push_back(new_staff_phone_number);
        receptionist_phone_number.push_back(new_staff_phone_number);
        receptionist_role.push_back(new_staff_role);

        /** Tạo ID random cho mỗi nhân viên */
            // Tạo nguồn random từ phần cứng
        random_device rd;

        // Sử dụng bộ sinh số ngẫu nhiên Mersenne Twister
        mt19937 gen(rd());

        // Sinh số nguyên trong khoảng từ 0 đến 999 (tức là nhỏ hơn 1000)
        uniform_int_distribution<> dis(0, 999);

        // Tạo số ngẫu nhiên
        int new_staff_ID = dis(gen);

        receptionist_ID.push_back(new_staff_ID);


        /*Ghi những thông tin của nhân viên vào databse nhân viên*/
        fstream database_staff("database/receptionist.csv", ios::app);
        if(database_staff.is_open())
        {
            string& last_element = receptionist_username.back();
            database_staff << last_element << ",";
            database_staff << "default_password" << ",";
            last_element = receptionist_phone_number.back();
            database_staff << last_element << ",";
            last_element = receptionist_ID.back();
            database_staff << last_element << ",";
            last_element = receptionist_role.back();
            database_staff << last_element << endl;
        }


        cout <<"-------------------------\n" << "Add staff successfully\n" << "1. Add another staff\n" << "0. Back\n" << "Please choose: ";
        cin >> choice;
        if(choice == 1)
            goto add_new_staff;
        else if(choice == 0)
        {
            AdminMenu::admin_menu_list();
        }

}
