#include "staff_management.hpp"

list<string> StaffManagement::receptionist_username;
list<string> StaffManagement::receptionist_phone_number;
list<string> StaffManagement::receptionist_role;
list<int> StaffManagement::receptionist_ID;



void AddStaff::admin_add_new_staff()
{
   int choice;
        do{
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

            database_staff << receptionist_username.back() << ",";
            database_staff << "default_password" << ",";

            database_staff << receptionist_phone_number.back() << ",";

            database_staff << receptionist_ID.back() << ",";

            database_staff << receptionist_role.back() << endl;
        }
        database_staff.close();


        cout <<"-------------------------\n" << "Add staff successfully\n" << "1. Add another staff\n" << "0. Back\n" << "Please choose: ";
        cin >> choice;
    }while (choice == 1);

    // Khi người dùng chọn 0 (hoặc bất kỳ số nào khác ngoài 1), vòng lặp kết thúc
    if (choice == 0)
    {
        // Gọi hàm để quay lại menu admin
        std::cout << "Returning to Admin Menu.\n"; 
        AdminMenu::admin_menu_list();
    }

}
