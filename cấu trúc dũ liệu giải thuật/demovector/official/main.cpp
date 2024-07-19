#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<map>
// #include<Vector.h>
#define ll long long

using namespace std;

// Danh muc mat hang
typedef struct{
    ll id;
    string name_product;
    string manufactor;
}category_product;

// Hoa don mua ban hang
typedef struct{
    ll id_bill;
    ll id_product;
    string type_bill; // Bill buy or sell
    ll quantity;
    string sale_date;
    ll price;
}bill_product;

class manager
{
private:
    int number;
    vector<category_product>category;
    vector<bill_product>bill;
public:
    void readFile(ifstream &, ifstream &, string, string);
    void writeFile(ofstream &, ofstream &, string, string);
    void inputProduct();
    void printProduct();
    void statisticInventory();
};

void manager::readFile(ifstream &FileCategory, ifstream &FileBill, string FileName_CateGory, string FileName_Bill){
    // Doc file danh muc mat hang
    category_product tempCategory;
    FileCategory.open(FileName_CateGory);
    if (!FileCategory){
        cout << "Error: file not opened!" << endl;
        exit(0);
    }
    while(!FileCategory.eof())
    {
        string temp;
        getline(FileCategory, temp, ' ');
        tempCategory.id = atoi(temp.c_str());
        getline(FileCategory, tempCategory.name_product, ' ');
        getline(FileCategory, tempCategory.manufactor, '\n');
        category.push_back(tempCategory);
    }
    FileCategory.close();
    
    // Doc file hoa don mua ban
    bill_product tempBill;
    FileBill.open(FileName_Bill);
    if (!FileBill){
        cout << "Error: file not opened!" << endl;
        exit(0);
    }
    while(!FileBill.eof()){
        string temp;
        getline(FileBill, temp, ' ');
        tempBill.id_bill = atoi(temp.c_str());
        getline(FileBill, temp, ' ');
        tempBill.id_product = atoi(temp.c_str());
        getline(FileBill, tempBill.type_bill, ' ');
        getline(FileBill, temp, ' ');
        tempBill.quantity = atoi(temp.c_str());
        getline(FileBill, tempBill.sale_date, ' ');
        FileBill >> tempBill.price;
        bill.push_back(tempBill);
    }
}

void manager::printProduct(){
    cout << endl;
    cout << "==================== Danh muc don hang ====================\n" << endl;
    cout << setw(7) << "Ma hang" << setw(15) << "Ten hang" << setw(20) << "Nha san xuat" << endl;
    for (int i = 0; i < category.size(); i ++){
        cout << setw(7) << category[i].id << setw(15) << category[i].name_product
        << setw(20) << category[i].manufactor << endl;
    }
    cout << endl;
    cout << "==================== Hoa don ban hang ====================\n" << endl;
    cout << setw(10) << "Ma hoa hon" << setw(15) << "Ma hang" << setw(20) << "Loai hoa don"
    << setw(20) << "So luong" << setw(20) << "Ngay mua ban" << setw(20) << "Gia mua ban" << endl;
    for (int i = 0; i < bill.size(); i ++){
        cout << setw(10) << bill[i].id_bill << setw(15) << bill[i].id_product
        << setw(20) << bill[i].type_bill << setw(20) << bill[i].quantity
        << setw(20) << bill[i].sale_date << setw(20) << bill[i].price << endl;
    }
}

void manager::writeFile(ofstream &FileCategory, ofstream &FileBill, string FileName_CateGory, string FileName_Bill){
    // Ghi them danh muc mat hang vao file
    category_product tempCategory;
    FileCategory.open(FileName_CateGory, ios::app);
    if (!FileCategory){
        cout << "Error: file not opened." << endl;
        exit(0);
    }
    cout << "So luong mat hang can them vao file " << FileName_CateGory << ": ";
    int numCategory; cin >> numCategory;
    while (numCategory--){
        cout << "Ma hang: "; cin >> tempCategory.id;
        cin.ignore();
        cout << "Ten hang: "; getline(cin, tempCategory.name_product);
        cout << "Nha san xuat: "; getline(cin, tempCategory.manufactor);
        FileCategory << "\n" << tempCategory.id << " " << tempCategory.name_product << " " 
        << tempCategory.manufactor;
    }
    FileCategory.close();

    // Ghi them hoa don vao file
    bill_product tempBill;
    FileBill.open(FileName_Bill, ios::app);
    if (!FileBill){
        cout << "Error: file not opened." << endl;
        exit(0); 
    }
    cout << "So luong hoa don can them vao file " << FileName_Bill << ": ";
    int numBill; cin >> numBill;
    while (numBill--){
        cout << "Ma hoa don: "; cin >> tempBill.id_bill;
        cout << "Ma hang: "; cin >> tempBill.id_product;
        cin.ignore();
        cout << "Loai hoa don: "; getline(cin, tempBill.type_bill);
        cout << "So luong: "; cin >> tempBill.quantity;
        cin.ignore();
        cout << "Ngay mua ban: "; getline(cin, tempBill.sale_date);
        cout << "Gia mua ban: "; cin >> tempBill.price;
        FileBill << "\n" << tempBill.id_bill << " " << tempBill.id_product << " "
        << tempBill.type_bill << " " << tempBill.quantity << " " << tempBill.sale_date
        << " " << tempBill.price;
    }
}

void manager::inputProduct(){
    // Nhap xuat danh muc mat hang
    category_product tempCategory;
    int numCategory;
    cout << "So luong mat hang nhap: "; cin >> numCategory;
    while (numCategory--){
        cout << "Ma hang: "; cin >> tempCategory.id;
        cin.ignore();
        cout << "Ten hang: "; getline(cin, tempCategory.name_product);
        cout << "Nha san xuat: "; getline(cin, tempCategory.manufactor);
        category.push_back(tempCategory);
    }
    cout << endl;

    // Nhap xuat hoa don 
    bill_product tempBill;
    int numBill;
    cout << "So luong hoa don nhap: "; cin >> numBill;
    while (numBill--){
        cout << "Ma hoa don: "; cin >> tempBill.id_bill;
        tempBill.id_product = tempCategory.id;
        cout << "Ma hang: " << tempBill.id_product << endl;
        cin.ignore();
        cout << "Loai hoa don: "; getline(cin, tempBill.type_bill);
        cout << "So luong: "; cin >> tempBill.quantity;
        cin.ignore();
        cout << "Ngay mua ban: "; getline(cin, tempBill.sale_date);
        cout << "Gia mua ban: "; cin >> tempBill.price;
        bill.push_back(tempBill);
    }
}

void manager::statisticInventory(){
    map<ll, ll> PurchaseBill;
    map<ll, ll> SaleBill;
    map<ll, string> NameInventory;
    for (auto it : bill){
        if (it.type_bill == "Mua") PurchaseBill[it.id_product] += it.quantity;
        else SaleBill[it.id_product] += it.quantity;
    }
    for (auto it : category){
        NameInventory[it.id] = it.name_product;
    }
    map<ll, ll> NumInventory;
    for (auto it : PurchaseBill){
        if ((it.second - SaleBill[it.first]) != 0) NumInventory[it.first] = it.second - SaleBill[it.first];
    }
    cout << "==================== Mat hang ton kho ====================\n" << endl;
    cout << setw(7) << "Ma hang" << setw(15) << "Ten hang" << setw(20) << "So luong ton kho" << endl;
    for (auto it : NumInventory){
        cout << setw(7) << it.first << setw(15) << NameInventory[it.first] <<  setw(20) << it.second << endl;
    }
}

int main(){
    manager shop;
    ifstream inCategory, inBill;
    ofstream outCategory, outBill;
    char select;
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Doc danh sach thong tin quan ly tu file vao chuong trinh" << endl;
        cout << "2. Ghi thong tin cua hang quan ly vao file" << endl;
        cout << "3. Nhap xuat cac mat hang" << endl;
        cout << "4. Hien thi toan bo danh sach mat hang hien co" << endl;
        cout << "5. Thong ke mat hang ton kho cua moi mat hang" << endl;
        cout << "Vui long nhap lua chon: ";
        int option; cin >> option;
        if (option == 1) shop.readFile(inCategory, inBill, "danhmucmathang.txt", "hoadonmuaban.txt");
        if (option == 2) shop.writeFile(outCategory, outBill, "danhmucmathang.txt", "hoadonmuaban.txt");
        if (option == 3) shop.inputProduct();
        if (option == 4) shop.printProduct();
        if (option == 5) shop.statisticInventory();
        cout << "Ban co muon tiep tuc khong(Y/N): "; cin >> select;
    }while (select != 'N');
}
