#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "contact.h"
// #include "function.cpp"
using namespace std;
int main() {
    Contact contact;
    vector<Contact> contacts;
    contacts = Contact::getData("danhba.csv", contacts);
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Hiển thị toàn bộ thông tin của danh bạ \n";
        cout << "2. Thêm 1 contact vào danh bạ\n";
        cout << "3. Tìm contact theo tên\n";
        cout << "4. Thay đổi thông tin của contact trong danh bạ\n";
        cout << "5. Xóa một contact ra khỏi danh bạ\n";
        cout << "6. Thống kê xem có bao nhiêu contact trong danh bạ\n";
        cout << "7. Sao lưu\n";
        cout << "8. Khôi phục dữ liệu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                contact.display("danhba.csv", contacts);
                break;
            case 2:
                contact.add(contacts);
                break;
            case 3:
                contact.search(contacts);
                break;
            case 4:
                contact.update(contacts);
                break;
            case 5:
                contact.remove(contacts);
                break;
            case 6:
                contact.statistics(contacts);
                break;
            case 7:
                contact.backup(contacts);
                break;
            case 8:
                contact.restore(contacts);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 9);
    
    return 0;
}
