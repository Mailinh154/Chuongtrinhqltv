#include"person.h"
#include"book.h"

string Person::Getfull_name(){
    return full_name;
}

string Person::Getcccd(){
    return cccd;
}

string Person::Getphone_number (){
    return phone_number ;
}

string Person::Getdate_of_birth(){
    return date_of_birth;
}

string Person:: Getemail(){
    return email;
}

string Person:: Getaccount(){
    return account;
}      

string Person:: Getpassword(){
    return password;
}  

string Person:: GetBorrow(){
    return borrow;
}

int Person:: GetID(){
    return id;
}

void Person::setFullname(string& name) {
    full_name = name;
}

void Person:: setCCCD(string& cccdNumber) {
    cccd = cccdNumber;
}

void Person:: setDateOfBirth(string& dob) {
    date_of_birth = dob;
}

void Person:: setPhoneNumber(string& phone) {
    phone_number = phone;
}

void Person:: setEmail(string& emailAddress) {
    email = emailAddress;
}

void Person:: setAccount(string& acc) {
    account = acc;
}

void Person:: setPassword(string& pass) {
    password = pass;
}

void Person:: setID(int &ID){
    id = ID;
}

void Person:: setBorrow(string& Borrow){
    borrow = Borrow;
}

void Person::borrowBook(vector<book>& listbook){
    int choice;
    bool found = false;
    string idStr;
    cout << "Nhap vao ID sach ban muon muon: ";
    cin >> idStr;
    int id = stoi(idStr);
    vector<int> ID;
    int temp = 0;

    for (char c : borrow) {
        if (isdigit(c)){ // Neu la so, cong vao bien tam
            temp = temp * 10 + (c - '0');
        }
        else if (c == ';') {
            ID.push_back(temp);
            temp = 0;
        }
    }

    if(ID.size() >= 5){
        cout << "Ban dang muon 5 cuon, khong the muon them! " << endl;
        return;
    }

    for(auto& b: listbook){
        if(b.getID() == id){
            found = true;
            for(auto& a: ID){
                if(a == id){
                    cout << "Ban da muon sach: " << b.getName() << " cua tac gia " << b.getAuthor() << endl;
                    cout << "Ban co muon muon them! (Nhan 1 de xac nhan, 0 de huy) " << endl;
                    cin >> choice;
                    if(choice == 1){
                        borrow = borrow + idStr + ";";
                        cout << "Muon sach thanh cong!" << endl;
                        int newNumber = b.getNumber() - 1;
                        b.setNumber(newNumber);
                        return;
                    }
                    if(choice == 0){
                        cout << "Huy thanh cong! " << endl;
                        return;
                    }
                }
            }
            if(b.getNumber() > 0){
                cout << "Ban dang muon sach: " << b.getName() << " cua tac gia " << b.getAuthor() << endl;
                cout << "Nhan 1 de xac nhan, 0 de huy" << endl;
                cin >> choice;
                if(choice == 1){
                    borrow = borrow + idStr + ";";
                    cout << "Muon sach thanh cong!" << endl;
                    int newNumber = b.getNumber() - 1;
                    b.setNumber(newNumber);
                }
                if(choice == 0){
                    cout << "Huy thanh cong! " << endl;
                    break;
                }
            }else{
                cout << "So luong sach khong du!" << endl;
            }
        }
    }
    if(!found){
        cout << "So ID khong hop le hoac khong tim duoc sach co so ID tren! "  << endl;
    }
}


bool Person::searchBook(vector<book>& listbook){
    string idStr;
    string name, author, type;
    vector<book> listbookfound;
    set<string> listauthorfound;
    set<string> listtypefound;
    int choice;
    cout << "1. Tim kiem theo ten sach" << endl;
    cout << "2. Tim kiem theo ten tac gia " << endl;
    cout << "3. Tim kiem theo the loai" << endl;
    cout << "Nhap vao lua chon cua ban: ";
    cin >> choice;

    bool found = false;
    switch (choice){
        case 1:
            cout << "Nhap vao ten sach muon tim: ";
            cin.ignore();
            getline(cin, name);
            for(book& b : listbook){
                if (b.getName().find(name) != string::npos) { // Nhap thanh phan cung co the truy suat qua sach
                    if(!found){
                        cout << "Cac ten sach ban muon tim: " << endl;
                        found = true;
                    }
                    listbookfound.push_back(b);
                }
            }
            if(found){
                cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << endl;
                cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;

                for (book& b : listbookfound) {
                    b.display();
                }
                cout << endl;
            }
            
            break;

        case 2:

            cout << "Nhap vao ten tac gia muon tim: ";
            cin.ignore();
            getline(cin, author);
            for(book& b : listbook){
                if (b.getAuthor().find(author) != string::npos) { // Nhap thanh phan cung co the truy suat qua sach
                    if(!found){
                        cout << "Cac tac pham cua tac gia ban muon tim: " << endl;
                        found = true;
                    }
                    listauthorfound.insert(b.getAuthor());
                }
            }
            if(found){
                cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << endl;
                cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            
                for (auto& a: listauthorfound){
                    for (book& b : listbook) {
                        if(b.getAuthor() == a){
                            b.display();
                        }
                    }
                }  
                cout << endl;
            }
            
            break;
                    
        case 3:

            cout << "Nhap vao ten tac pham theo the loai ban muon tim: ";
            cin.ignore();
            getline(cin, type);
            for(book& b : listbook){ // Kieu nhu list b tro heap
                if (b.getType().find(type) != string::npos) { // Nhap thanh phan cung co the truy suat qua sach
                    if(!found){
                        found = true;
                    }
                    listtypefound.insert(b.getType());
                }
            }

            if(found){
                cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << endl;
                cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            
                for (auto& a: listtypefound){
                    for (book& b : listbook) {
                        if(b.getType() == a){
                            b.display();
                        }
                    }
                }  
                cout << endl;
            }
        
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
    }
    if (!found) {
        cout << "Khong tim thay ket qua ban muon tim! " << endl << endl;
        return false;
    }else{
        return true;
    }
}


void Person::returnBook(vector<book>& listbook){
    bool found = false;
    int idBookReturn;
    vector<int> ID;

    if (borrow.empty()) {
        cout << "Ban dang khong muon sach nao! " << endl;
        return;
    }

    cout << "Nhap vao ID sach muon tra: ";
    cin >> idBookReturn;
    string result;
    int temp = 0;

    int i = 0; // Bien de theo doi vi tri trong chuoi

    while (i < borrow.size()) {
        if (isdigit(borrow[i])) {
            temp = temp * 10 + (borrow[i] - '0');
            i++;
        }
        else if (borrow[i] == ';') {
            if (temp != idBookReturn) {
                ID.push_back(temp);
                result += to_string(temp) + ";";
            }
            if (temp == idBookReturn) {
                ID.push_back(temp);
            }
            temp = 0; // Dat lai bien tam va chuyen sang ky tu tiep theo
            i++;
        }
        else {
            result += borrow[i];
            i++;
        }
    }

    for(int i = 0; i < ID.size(); i++){
        if(idBookReturn == ID[i]){
            found = true;
            for(auto& b: listbook){
                if(b.getID() == idBookReturn){
                    int newNumber = b.getNumber() + 1;
                    b.setNumber(newNumber);   
                }
            }
        }
    }

    setBorrow(result);
    if(found){
        cout << "Tra sach thanh cong !" << endl;
    }else{
        cout << "ID sach tra nhap khong dung hoac dang khong co trong danh sach muon!" << endl;
    }
}

void Person::set_info(){
    cout << "Nhap vao thong tin cua nguoi dung! " << endl;
    cin.ignore();
    cout << "Ho va ten: ";
    getline(cin, full_name);
    cout << "So dien thoai: ";
    getline(cin, phone_number );
    cout << "So can cuoc cong dan: ";
    getline(cin, cccd);
    cout << "Ngay thang nam sinh: ";
    getline(cin, date_of_birth);
    cout << "Email: ";
    getline(cin, email);
}

void Person::print_info(vector<book> listbook){ // Hien thi thong tin nguoi dung
    cout << "Ho va ten: " << full_name << endl;
    cout << "Cccd: " << cccd << endl;
    cout << "date_of_birth: " << date_of_birth << endl;
    cout << "Sdt: " << phone_number  << endl;
    cout << "Email: " << email << endl;
    cout << "Ten tai khoan: " << account << endl;
    cout << "Mat khau: ";
    for(int i=0; i < password.length(); i++){
        cout << "*";
    }
    cout << endl;
}

// Student

string Student::getStudent_id(){
    return student_id;
}

string Student::getClass_name(){
    return class_name;
}

int Student::getCohort(){
    return cohort;
}

string Student::getSchool(){
    return school;
}

string Student::getDepartment(){
    return department;
}

void Student::setStudentID(const string& id) {
    student_id = id;
}

void Student::setClassName(const string& className) {
    class_name = className;
}

void Student::setCohort(int cohortValue) {
    cohort = cohortValue;
}

void Student::setSchool(const string& schoolName) {
    school = schoolName;
}

void Student::setDepartment(const string& departmentName) {
    department = departmentName;
}

void Student::set_info(){
    Person::set_info();
    cout << "MSSV: ";
    getline(cin, student_id);
    cout << "Lop: ";
    getline(cin, class_name);
    cout << "Khoa: ";
    cin >> cohort;
    cin.ignore();
    cout << "Truong: ";
    getline(cin, school);
    cout << "Khoa: ";
    getline(cin, department);
}


void Student::editInformation() {
    cout << "Chinh sua thong tin ca nhan:" << endl;
    cout << "1. Sua ten" << endl;
    cout << "2. Sua so dien thoai" << endl;
    cout << "3. Sua ngay sinh" << endl;
    cout << "4. Sua can cuoc cong dan" << endl;
    cout << "5. Sua Email" << endl;
    cout << "6. Sua ma so sinh vien" << endl;
    cout << "7. Sua lop hoc" << endl;
    cout << "8. Sua khoa" << endl;
    cout << "9. Sua truong hoc" << endl;
    cout << "10. Sua khoa" << endl;
    cout << "Nhap lua chon cua ban: ";
    int choice;
    cin >> choice;
    cin.ignore(); // De xoa bo dem sau khi nhap lua chon so

    switch (choice) {
        case 1:
            cout << "Nhap ten moi: ";
            getline(cin, full_name);
            cout << "Ten da duoc cap nhat!" << endl;
        break;
        case 2:
            cout << "Nhap so dien thoai moi: ";
            getline(cin, phone_number );
            cout << "So dien thoai da duoc cap nhat!" << endl;
        break;
        case 3:
            cout << "Nhap ngay sinh moi: ";
            getline(cin, date_of_birth);
            cout << "Ngay sinh da duoc cap nhat!" << endl;
        break;
        case 4:
            cout << "Nhap vao can cuoc cong dan moi: ";
            getline(cin,cccd);
            cout << "Can cuoc cong dan da duoc cap nhat!" << endl;
        break;
        case 5:
            cout << "Nhap vao email moi: ";
            getline(cin,email);
            cout << "Email da duoc cap nhat! " << endl;
        break;
        case 6:
            cout << "Nhap vao ma so sinh vien moi: ";
            getline(cin,student_id);
            cout << "Ma so sinh vien da duoc cap nhat! " << endl;
        break;
        case 7:
            cout << "Nhap vao lop hoc moi: ";
            getline(cin,class_name);
            cout << "Lop hoc da duoc cap nhat! " << endl;
        break;
        case 8:
            cout << "Nhap vao khoa moi: ";
            cin >> cohort;
            cout << "Khoa da duoc cap nhat! " << endl;
        break;
        case 9:
            cout << "Nhap vao truong hoc moi: ";
            getline(cin,school);
            cout << "Truong hoc da duoc cap nhat! " << endl;
        break;
        case 10:
            cout << "Nhap vao khoa moi: ";
            getline(cin,department);
            cout << "Khoa da duoc cap nhat! " << endl;
        break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        break;
    }
}

void Student::print_info(vector<book> listbook) { 
    Person::print_info(listbook); // Goi ham in thong tin cua lop co so truoc
    cout << "MSSV: " << student_id << endl;
    cout << "Lop: " << class_name << endl;
    cout << "Khoa: " << cohort << endl;
    cout << "Truong: " << school << endl;
    cout << "Khoa: " << department << endl;
    vector<int> ID;
    int temp = 0;
    for (char c : borrow) {
        if (std::isdigit(c)){ // Neu la so, cong vao bien tam
            temp = temp * 10 + (c - '0');
        }
        else if (c == ';') {
            ID.push_back(temp);
            temp = 0;
        }
    }
    cout << "So sach dang muon: " << ID.size() << endl;
    if(ID.size() > 0){
        cout << "Danh sach cac sach dang muon: " << endl;
        cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << endl;
        cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
        for(auto& i: ID){
            for(auto& b: listbook){
                if(b.getID() == i){
                    b.display();
                }
            }
        }
    }
}

void Student::display(){
    cout << left << setw(8) << id << setw(35) << account << setw(15) << password << setw(15) << full_name << endl;
}

string Staff::getStaffID() {
    return staff_id;
}

string Staff::getSchool() {
    return school;
}

string Staff::getDepartment() {
    return department;
}

string Staff::getOffice() {
    return office;
}

void Staff::setStaffID(const string& id) {
    staff_id = id;
}

void Staff::setSchool(const string& schoolName) {
    school = schoolName;
}

void Staff::setDepartment(const string& departmentName) {
    department = departmentName;
}

void Staff::setOffice(const string& officeLocation) {
    office = officeLocation;
}

void Staff::set_info(){
    Person::set_info();
    cout << "Ma giang vien: ";
    getline(cin,staff_id);
    cout << "Truong: ";
    getline(cin,school);
    cout << "Khoa: ";
    getline(cin,department);
    cout << "Phong lam viec: ";
    getline(cin,office);
}

void Staff::print_info(vector<book> listbook) {
    Person::print_info(listbook);
    cout << "Staff ID: " << staff_id << endl;
    cout << "School: " << school << endl;
    cout << "Department: " << department << endl;
    cout << "Office: " << office << endl;
}


void Staff::bookManager(vector<book>& listbook){
    int choice;
    bool found = false;
    book Newbook;
    int id;
    while(true){
    cout <<"1. Them sach" << endl;
    cout <<"2. Xoa sach" << endl;
    cout <<"3. Quay tro lai trang chu" << endl;
    cout <<"Nhap vao lua chon tiep theo cua ban: " << endl;
    cin >> choice;
    switch (choice)
    {
        case 1:
            Newbook.addBook();
            id = listbook.back().getID() + 1;
            Newbook.setID(id);
            listbook.push_back(Newbook);
            cout << "Them sach thanh cong! " << endl;
        return;
        case 2:
            cout << "Cac sach hien co la: " << endl; // Phan nay hoc sau
            cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So sach" << endl;
            cout << setfill('-') << setw(99) << "-" << setfill(' ') << endl;

            for (book& b : listbook) {
                b.display();
            }

            cout << "Nhap vao id sach muon xoa: ";
            cin >> id;
            for(auto& b: listbook){
                if(b.getID() == id){
                    listbook.erase(listbook.begin() + id - 1);
                    found = true;
                }
            }
            if(found){
                cout << "Xoa sach thanh cong! " << endl;
                return;
            }else{
                cout << "Id sach khong ton tai! " << endl;
                return;
            }
            
        case 3:
            return;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
}

void Staff::Statistical(vector<book> listbook, vector<Student> listUser){
    cout <<"So sach: " << listbook.size() << endl;
    cout <<"So nguoi dung: " << listUser.size() << endl;
}

bool Staff::searchUser(vector<Student>& listUser){
    string name;
    bool found = false;
    set<string> listnamefound;
    cin.ignore();
    cout << "Nhap vao ten nguoi dung muon tim: ";
    getline(cin,name);
    for(auto& a : listUser){
        if (a.Getfull_name().find(name) != string::npos) { // Nhap thanh phan cung co the truy suat qua sach
            if(!found){
                cout << "Cac ten nguoi dung ban muon tim: " << endl;
                found = true;
            }
            listnamefound.insert(a.Getfull_name());
        }
    }

    if (found) {
        cout << left << setw(8) << "ID"<< setw(37) << "Tai khoan" << setw(20) << "Mat khau" << setw(20) << "Ho va Ten" << endl;
        cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            
        for (auto& b: listnamefound){
            for (auto& a : listUser) {
                if(a.Getfull_name() == b){
                    a.display();
                }
            }
        }
        return true;
    }else{
        cout << "Khong tim thay ket qua ban muon tim" << endl << endl;
        return false;
    }
}

void Staff::print_infoUser(vector<Student>& listUser, vector<book>& listbook){
    int id;
    cout << "Nhap vao ID nguoi dung muon xem thong tin chi tiet: ";
    cin >> id;
    bool found = false;
    for (auto& a: listUser) {
        if(a.GetID() == id){
            a.print_info(listbook);
            found = true;
        }
    }
    if(!found){
        cout << "ID nguoi dung khong hop le hoac khong tim duoc nguoi dung co ID nhu tren !" << endl;
    }
}

void Staff::deleteUser(vector<Student>& listUser, vector<book>& listbook){
    int id;
    cout << "Nhap vao ID nguoi dung muon xoa: ";
    cin >> id;
    bool found = false;
    for (auto& a: listUser) {
        if(a.GetID() == id){
            found = true;
        }
    }
    if(!found){
        cout << "ID nguoi dung khong hop le hoac khong tim duoc nguoi dung co ID nhu tren !" << endl;
    }else{
        listUser.erase(listUser.begin() + id - 1);
        cout << "Xoa nguoi dung thanh cong! " << endl;
    }
}

void Staff::editInfor() {
    cout << "Chinh sua thong tin ca nhan:" << endl;
    cout << "1. Sua ten" << endl;
    cout << "2. Sua so dien thoai" << endl;
    cout << "3. Sua ngay sinh" << endl;
    cout << "4. Sua can cuoc cong dan" << endl;
    cout << "5. Sua Email" << endl;
    cout << "6. Sua ma so giang vien" << endl;
    cout << "7. Sua truong" << endl;
    cout << "8. Sua khoa" << endl;
    cout << "9. Sua phong lam viec" << endl;
    cout << "Nhap lua chon cua ban: ";
    int choice;
    cin >> choice;
    cin.ignore(); // De xoa bo dem sau khi nhap lua chon so

    switch (choice) {
        case 1:
            cout << "Nhap ten moi: ";
            getline(cin, full_name);
            cout << "Ten da duoc cap nhat!" << endl;
        break;
        case 2:
            cout << "Nhap so dien thoai moi: ";
            getline(cin, phone_number );
            cout << "So dien thoai da duoc cap nhat!" << endl;
        break;
        case 3:
            cout << "Nhap ngay sinh moi: ";
            getline(cin, date_of_birth);
            cout << "Ngay sinh da duoc cap nhat!" << endl;
        break;
        case 4:
            cout << "Nhap vao can cuoc cong dan moi: ";
            getline(cin,cccd);
            cout << "Can cuoc cong dan da duoc cap nhat!" << endl;
        break;
        case 5:
            cout << "Nhap vao email moi: ";
            getline(cin,email);
            cout << "Email da duoc cap nhat! " << endl;
        break;
        case 6:
            cout << "Nhap vao ma so giang vien moi: ";
            getline(cin,staff_id);
            cout << "Ma so giang vien da duoc cap nhat! " << endl;
        break;
        case 7:
            cout << "Nhap vao truong moi: ";
            getline(cin,school);
            cout << "truong da duoc cap nhat! " << endl;
        break;
        case 8:
            cout << "Nhap vao khoa moi: ";
            getline(cin,department);
            cout << "Khoa da duoc cap nhat! " << endl;
        break;
        case 9:
            cout << "Nhap vao phong lam viec moi: ";
            getline(cin,office);
            cout << "Phong lam viec moi da duoc cap nhat! " << endl;
        break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        break;
    }
}
