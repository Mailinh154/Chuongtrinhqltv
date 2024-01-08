#include "book.h"
#include "person.h"
#include "book.cpp"
#include "person.cpp"
#include "file.cpp"

void Register(Staff& s, string &username, string &password) {
    int i = 0;
    for(i=0;i<size(sf);i++){  // Kiem tra tai khoan da ton tai hay chua
        if(sf[i].Getaccount() == username){
            cout << "Tai khoan da ton tai! " << endl;
            return;
        }
    }
    s.setAccount(username);
    s.setPassword(password);
    cout << "Dang ky thanh cong" << endl;
    s.set_info();
    sf.push_back(s);
    updateFile3(sf);
}

bool Login(const string username, string password){
    for(auto& staff : sf ){  // Kiem tra tai khoan, mat khau 
        if(staff.Getaccount() == username && staff.Getpassword() == password){
            return true;
            break;
        }
    }
    cout << "Tai khoan hoac mat khau sai" << endl;
    return false;
}

void changePassword(Staff* &s, string username, string currentPassword, string newPassword) { // Doi mat khau
    if (s->Getpassword() == currentPassword) { // Kiem tra tai khoan, mat khau 
        for(auto& staff : hs ){  // Cap nhat trong vector
            if(staff.Getaccount() == username ){
                staff.setPassword(newPassword);
            }
        }
        cout << "Doi mat khau thanh cong!" << endl;
        updateFile3(sf);
    } else {
        cout << "Sai mat khau hien tai! Khong the doi mat khau." << endl;
    }
}

int main(){

    Staff myStaff;
    Staff *myStaffPtr = new Staff;
    int choice;
    string username, password, currentPassword, newPassword;
    docfile1(hs, sach);
    docfile2(sf);
    bool isLoggedIn = false; // Bien xac dinh dang trong dang nhap 
    bool isSearch = false; // Bien xac dinh dang trong qua trinh tim kiem

    while (true) {
        cout << "1. Dang ki\n";
        cout << "2. Dang nhap\n";
        cout << "3. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:

                cout << "Nhap ten dang nhap: ";
                cin >> username;
                cout << "Nhap mat khau: ";
                cin >> password;
                Register(myStaff, username, password);
                break;
                
            case 2:
                
                cout << "Nhap ten dang nhap: ";
                cin >> username;
                cout << "Nhap mat khau: ";
                cin >> password;
                if(Login(username,password)){
                    isLoggedIn = true;

                    for (auto& staff : sf) { // Xac dinh doi tuong dang su dung
                        if (staff.Getaccount() == username && staff.Getpassword() == password) {
                        myStaffPtr = &staff;
                        break;
                        }
                    }

                    cout << "Ban dang dang nhap voi tu cach admin" << endl << endl;
                    while(isLoggedIn){
                        cout << "1. Chinh sua thong tin" << endl;
                        cout << "2. Quan li sach" << endl;
                        cout << "3. Thong ke" <<  endl;
                        cout << "4. Tim kiem sinh vien" << endl;
                        cout << "5. Dang xuat" << endl;
                        cout << "Nhap vao lua chon tiep theo cua ban!: \n";
                        cin >> choice;
                        switch (choice){
                        case 1:
                            myStaffPtr -> print_info(sach);
                            myStaffPtr -> editInfor();
                            break;
                        case 2:
                            myStaffPtr->bookManager(sach);
                            updateFile2(sach);
                            break;
                        case 3:
                            myStaffPtr->Statistical(sach, hs);
                            break;
                        case 4:
                            if(myStaff.searchUser(hs)){
                                isSearch = true;
                                while(isSearch){
                                    cout << "1. Xem thong tin chi tiet nguoi dung" << endl;
                                    cout << "2. Xoa tai khoan" << endl;
                                    cout << "3. Quay tro lai trang chu" << endl;
                                    cout << "Nhap vao lua chon tiep theo cua ban!: \n";
                                    cin >> choice;
                                    switch (choice)
                                    {
                                    case 1:
                                        myStaffPtr -> print_infoUser(hs, sach); 
                                    break;
                                    case 2:
                                        myStaffPtr -> deleteUser(hs, sach); 
                                        updateFile1(hs);
                                    break;
                                    case 3: 
                                        isSearch = false;
                                    break;
                                    default:
                                        cout << "Lua chon khong hop le! " << endl;
                                    break;
                                    }
                                }
                            }
                            break;
                        case 5:
                            isLoggedIn = false;
                            break;
                        default:
                            cout << "Lua chon khong hop le!" << endl;
                            break;
                        }
                    }
                }
            break; 
            case 3:
                return 0;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    }
    delete myStaffPtr;
    return 0;
}
