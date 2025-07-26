#include "staff_management.hpp"

void AddStaff::admin_add_new_staff()
{
    cout << "---ADD STAFF__\n";
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
}


AddStaff::AddStaff()
{
    // Tạo nguồn random từ phần cứng
    random_device rd;

    // Sử dụng bộ sinh số ngẫu nhiên Mersenne Twister
    mt19937 gen(rd());

    // Sinh số nguyên trong khoảng từ 0 đến 999 (tức là nhỏ hơn 1000)
    uniform_int_distribution<> dis(0, 999);

    // Tạo số ngẫu nhiên
    int new_staff_ID = dis(gen);

    receptionist_ID.push_back(new_staff_ID);
}

AddStaff::~AddStaff(){}