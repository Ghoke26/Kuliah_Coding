#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <conio.h>


using namespace std;
string mengulang;

void loading(int berapakali,int karakter, int kecepatan)
{
    for(int e = 1; e <=berapakali; e++)
    {
        std::cout << char(karakter);
        Sleep(kecepatan);
    }  
}

void gotoxy(int samping, int bawah)
{
    COORD coord = {0, 0};
    coord.X = samping;
    coord.Y = bawah;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void hidecursor(bool hide) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = hide;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void border(int berapakali, int karakter)
{
    for (int z = 1; z <= berapakali; z++)
    {
        std::cout << char(karakter);
    }
    std::cout << "" << std::endl;
}

void loginborder()
{
    system("cls");
    gotoxy(40, 10);
    border(40, 220);

    gotoxy(40, 20);
    border(40, 220);
    gotoxy(58, 12);
    cout << "LOGIN";
}


string getPassword()
{
    string password;
    char ch;
    while ((ch = _getch()) != 13)
    {
        if (ch == 8)
        {
            if (password.length() != 0)
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    return password;
}

bool login()
{
    hidecursor(false);
    string login = "asd";
    string password, username;
    int ulang = 4;

    system("cls");
    gotoxy(40, 10);
    loading(40, 220, 30);

    gotoxy(40, 20);
    loading(40, 220, 30);

    gotoxy(58, 12);
    cout << "LOGIN";

    while (ulang >= 0)
    {
    Kembali:
        ulang--;
        system("color 0A");

        loginborder();
        gotoxy(50, 15);
        hidecursor(true);
        cout << "Username : ";
        cin >> username;

        gotoxy(50, 17);
        cout << "Password : ";
        password = getPassword();

        if (password == login && username == login)
        {
            system("color A0");
            gotoxy(52, 22);
            cout << "Login berhasil!!" << endl;
            gotoxy(44, 26);
            system("pause");
            return true;
            break;
        }
        else if (ulang == 0)
        {
            system("Color 40");
            gotoxy(48, 22);
            cout << "Tidak dapat Login lagi!" << endl;
            gotoxy(44, 24);
            system("pause");
            system("cls");
            return false;
            break;
        }
        else
        {
            system("color 4");
            gotoxy(44, 22);
            cout << "Login gagal, silahkan coba lagi" << endl;
            gotoxy(50, 24);
            cout << "Sisa " << ulang << " percobaan lagi!" << endl;
            gotoxy(44, 26);
            system("pause");
            goto Kembali;
        }
    }

    cin.ignore();
    gotoxy(0, 30);
}




struct Pembaca {
    string nama;
    string alamat;
    string judul_buku;
    Pembaca* next;
    Pembaca* prev;
};


struct Buku {
    string judul, penulis;
    int tahunTerbit;
    Buku* next;
    Buku* prev;
};




Pembaca *headPembaca = nullptr, *tailPembaca = nullptr, *newNodePembaca, *curPembaca;


Buku* head = nullptr, *tail = nullptr, *cur = nullptr, *newNode = nullptr, *del = nullptr;




string getJudulBuku(int noBuku) {
    Buku* temp = head;
    int loop = 1;
    while (temp != nullptr) {
        if (loop == noBuku) {
            return temp->judul;
        }
        loop++;
        temp = temp->next;
    }
    return "Buku tidak ditemukan";
}

void createPembaca(string nama, string alamat , int nojudul) {
    newNodePembaca = new Pembaca;
    newNodePembaca->nama = nama;
    newNodePembaca->alamat = alamat;
    newNodePembaca->judul_buku = getJudulBuku(nojudul);
    newNodePembaca->next = nullptr;
    newNodePembaca->prev = nullptr;

    if (headPembaca == nullptr) {
        headPembaca = newNodePembaca;
        tailPembaca = newNodePembaca;
    } else {
        newNodePembaca->prev = tailPembaca;
        tailPembaca->next = newNodePembaca;
        tailPembaca = newNodePembaca;
    }
}


void printPembaca()
{
        curPembaca = headPembaca;
        int no = 1;

        loading(155,223,10);
        Sleep(10);
        cout<<"\n|                                                                    DAFTAR PEMBACA                                                                       |"<<endl;
        Sleep(10);
        cout<<"==========================================================================================================================================================|"<<endl;
        Sleep(10);
        cout<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<"No"<<setw(40) << left << "Nama Pembaca" << setw(20) << left << " " << setw(20) << left << "Alamat" << setw(20) << left << " " << setw(30) << left << "Buku"<<"|" << endl;
        Sleep(10);
        cout<<"==========================================================================================================================================================|"<<endl;


        while (curPembaca !=nullptr)
        {
            Sleep(40);
            cout<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<no<<setw(40) << left << curPembaca->nama << setw(20) << left << " " << setw(20) << left << curPembaca->alamat << setw(20) << left << " " << setw(30) << left << curPembaca->judul_buku<<"|" << endl;
            curPembaca = curPembaca->next;
            no++;
        }

        loading(155,196,1);
        cout<<endl;


}

bool cek_string(const string& input_user) {
    for (size_t e = 0; e < input_user.size(); e++) {
        if (!isdigit(input_user[e])) {
            return false;
        }
    }
    return true;
}


void createData(string judul, string penulis, int tahun) {
    newNode = new Buku;
    newNode->judul = judul;
    newNode->penulis = penulis;
    newNode->tahunTerbit = tahun;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


void printBox(const string& judul, const string& penulis, int tahunTerbit) {
    string tahunStr = to_string(tahunTerbit);
    int width = max({judul.length(), penulis.length(), tahunStr.length()}) + 4;

    cout << "+" << string(width, '-') << "+" << endl;
    cout << "| " << judul << string(width - judul.length() - 2, ' ') << " |" << endl;
    cout << "| " << penulis << string(width - penulis.length() - 2, ' ') << " |" << endl;
    cout << "| " << tahunStr << string(width - tahunStr.length() - 2, ' ') << " |" << endl;
    cout << "+" << string(width, '-') << "+" << endl;
}


void printData()
{
    cur = head;
    int i = 1;


    cout<<"==========================================================================================================================================================|"<<endl;
    cout<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<"No"<<setw(40) << left << "Judul Buku" << setw(20) << left << " " << setw(20) << left << "tahun" << setw(20) << left << " " << setw(30) << left << "penulis"<<"|" << endl;
    cout<<"==========================================================================================================================================================|"<<endl;


    while (cur !=nullptr)
    {
        cout<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<i<<setw(40) << left << cur->judul << setw(20) << left << " " << setw(20) << left << cur->tahunTerbit << setw(20) << left << " " << setw(30) << left << cur->penulis<<"|" << endl;
        
        cur = cur->next;
        i++;
    }
    
    cout<<"==========================================================================================================================================================|"<<endl;
    cout<<endl;
}

void deleteData(int nomor) {
    if (head == nullptr) {
        cout << "Daftar buku masih kosong." << endl;
        return;
    }

    int i = 1;
    Buku* cur = head;
    Buku* prev = nullptr;
    while (cur != nullptr) {
        if (i == nomor) {
            if (prev == nullptr) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        i++;
        cur = cur->next;
    }
    cout << "Nomor buku tidak ditemukan." << endl;
}






// sortingggggg
void sortJudul(Buku** head,string besarKecil) {
    
    Buku* cur = *head;

    if (besarKecil == "asc")
    {
            while (cur != nullptr) {
            Buku* next = cur->next;
            while (next != nullptr) {
                if (cur->judul > next->judul) {
                    swap(cur->judul,next->judul);
                }
                next = next->next;
            }
            cur = cur->next;
        }
    }

    else if (besarKecil =="desc")  {

            Buku* cur = *head;
                while (cur != nullptr) {
                Buku* next = cur->next;
                while (next != nullptr) {
                    if (cur->judul < next->judul) {
                        swap(cur->judul,next->judul);
                    }
                    next = next->next;
                }
                cur = cur->next;
            }

        }
    
}

void sortPenulis(Buku** head, string besarKecil) {
    Buku* cur = *head;

        if (besarKecil == "asc")
        {
            while (cur != nullptr) {
                Buku* next = cur->next;
                while (next != nullptr) {
                    if (cur->penulis > next->penulis) {
                        swap(cur->penulis,next->penulis);
                    }
                    next = next->next;
                }
                cur = cur->next;
            }
            
        }
            else if (besarKecil =="desc")
            {
                while (cur != nullptr) {
                    Buku* next = cur->next;
                    while (next != nullptr) {
                        if (cur->penulis < next->penulis) {
                            swap(cur->penulis,next->penulis);
                        }
                        next = next->next;
                    }
                    cur = cur->next;
                }
    
            }
}

void sortTahun(Buku** head,string besarKecil) {
    Buku* cur = *head;
    if (besarKecil =="asc")
    {
        
        while (cur != nullptr) {
            Buku* next = cur->next;
            while (next != nullptr) {
                if (cur->tahunTerbit > next->tahunTerbit) {
                    swap(cur->tahunTerbit,next->tahunTerbit);
                }
                next = next->next;
            }
            cur = cur->next;
        }

    }

        else if (besarKecil =="desc")
        {
            while (cur != nullptr) {
                Buku* next = cur->next;
                while (next != nullptr) {
                    if (cur->tahunTerbit < next->tahunTerbit) {
                        swap(cur->tahunTerbit,next->tahunTerbit);
                    }
                    next = next->next;
                }
                cur = cur->next;
            }
        }
}



void updateBuku(int noBuku, string newJudul, string newPenulis, int newTahunTerbit) {
    Buku* temp = head;
    int loop = 1;
    while (temp != nullptr) {
        if (loop == noBuku) {
            temp->judul = newJudul;
            temp->penulis = newPenulis;
            temp->tahunTerbit = newTahunTerbit;
            break;
        }
        loop++;
        temp = temp->next;
    }
}




// Menu Sorting ASC DESC
void menuSortingAscending()
{
    string pilih;

        while (true)
        {
            menuAscending :
                system("cls");
                system("Color 7");
                cout << "+=========================================+" << endl;
                cout << "|                ASCENDING                |" << endl;
                cout << "+=========================================+" << endl;
                cout << "| 1. Sort By Judul                        |" << endl;
                cout << "| 2. Sort By Penulis                      |" << endl;
                cout << "| 3. Sort By Tahun Terbit                 |" << endl;
                cout << "| 99. Kembali                             |" << endl;
                cout << "+=========================================+" << endl;
                cout << "|->> Pilih : ";
                cin>>pilih;

                    if (pilih !="1" && pilih !="2" && pilih !="3" && pilih !="99"){
                        cout<<"harap pilih menu dengan benar"<<endl;
                        system("Color C");
                        system("pause");
                        goto menuAscending;
                    }

                        else if( pilih =="99")
                        {
                            break;
                        }
                        
                            else{
                                    switch (stoi(pilih))
                                    {
                                        case 1:
                                                system("cls");
                                                cout<<"\n\n+============================+"<<endl;
                                                cout<<"| Judul Ascending            |"<<endl;
                                                sortJudul(&head,"asc");
                                                printData();
                                                system("pause");
                                            break;
                                        
                                        case 2:
                                                system("cls");
                                                cout<<"\n\n+============================+"<<endl;
                                                cout<<"| Penulis Ascending          |"<<endl;
                                                    sortPenulis(&head,"asc");
                                                    printData();
                                                    system("pause");
                                            break;
                                        case 3:
                                                system("cls");
                                                cout<<"\n\n+============================+"<<endl;
                                                cout<<"| Tahun terbit Ascending     |"<<endl;
                                                    sortTahun(&head,"asc");
                                                    printData();
                                                    system("pause");
                                            break;
                                    }
                                }
        }


} 


void menuSortingDiscending()
{
    string pilih;
    
    while (true)
    {
            menuDiscending :
                system("cls");
                cout << "+=========================================+" << endl;
                cout << "|                DESCENDING               |" << endl;
                cout << "+=========================================+" << endl;
                cout << "| 1. Sort By Judul                        |" << endl;
                cout << "| 2. Sort By Penulis                      |" << endl;
                cout << "| 3. Sort By Tahun Terbit                 |" << endl;
                cout << "| 99. Kembali                             |" << endl;
                cout << "+=========================================+" << endl;
                cout << "|->> Pilih : ";
                    cin>>pilih;

                if (pilih !="1" && pilih !="2" && pilih !="3" && pilih !="99"){
                    cout<<"harap pilih menu dengan benar"<<endl;
                    system("pause");
                    goto menuDiscending;
                }
                else if( pilih =="99")
                {
                    break;
                }
                
                    else{

                            switch (stoi(pilih))
                            {
                                case 1:
                                        system("cls");
                                        cout<<"\n\n+============================+"<<endl;
                                        cout<<"| Judul Descending           |"<<endl;
                                            sortJudul(&head,"desc");
                                            printData();
                                            system("pause");
                                    break;
                                
                                case 2:
                                        system("cls");
                                        cout<<"\n\n+============================+"<<endl;
                                        cout<<"| Penulis Descending         |"<<endl;
                                            sortPenulis(&head,"desc");
                                            printData();
                                            system("pause");
                                    break;
                                case 3:
                                        system("cls");
                                        cout<<"\n\n+============================+"<<endl;
                                        cout<<"| Tahun Terbit Descending    |"<<endl;
                                            sortTahun(&head,"desc");
                                            printData();
                                            system("pause");
                                    break;
                                }
                        }
        
    }


} 


//  Menu sorting 

void MenuSorting()
{
    string pilih;


        if (head == nullptr)
            {
                system("cls");
                cout<<"Mohon maaf belum ada data"<<endl;
                system("pause");
            }

            else{

                do
                    {
                        system("cls");
                        system("Color 7");
                        printData();

                        cout << "+=========================================+" << endl;
                        cout << "|                SORTING                  |" << endl;
                        cout << "+=========================================+" << endl;
                        cout << "| 1. Ascending                            |" << endl;
                        cout << "| 2. Descending                           |" << endl;
                        cout << "| 99. Kembali                             |" << endl;
                        cout << "+=========================================+" << endl;
                        cout << "|->> Pilih : ";
                        cin>>pilih;

                        if (pilih !="1" && pilih !="2" && pilih !="99"){
                            cout<<"harap masukan input dengan benar!"<<endl;
                            system("Color 0C");
                            system("pause");
                        }

                        else{

                            switch (stoi(pilih))
                            {
                            case 1:
                                    menuSortingAscending();
                                break;
                            case 2:
                                    menuSortingDiscending();
                            default:
                                break;
                            }
                        }

                    } while (pilih!= "99");
                    
            }

}


//searching
void cariJudul()
{
    string cariData;
    cin.ignore();
    cout << "Masukan judul buku: ";
    getline(cin, cariData);

    system("cls");

    cout << "+==========================================+" << endl;
    cout << "| ==  Hasil pencarian berdasarkan judul == |" << endl;
    cout << "+==========================================+" << endl;
    Buku* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->judul.find(cariData) != string::npos) {
            printBox(temp->judul, temp->penulis, temp->tahunTerbit);
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Buku tidak ditemukan" << endl;
    }
    system("pause");


} 

void cariTahunterbit()
{
    string cariData;
    cin.ignore();

    cariTahun : 
    system("Color 7");
    cout << "Masukan tahun terbit: ";
    getline(cin, cariData);

    if (!cek_string(cariData)) {
        cout << "Harap masukan angka!" << endl;
        system("Color C0");
        system("pause");
        goto cariTahun;
    }

    int tahunCari = stoi(cariData);
    system("cls");

    cout << "+=================================================+" << endl;
    cout << "| ==  Hasil pencarian berdasarkan Tahun Terbit == |" << endl;
    cout << "+=================================================+" << endl;

    Buku* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->tahunTerbit == tahunCari) {
            printBox(temp->judul, temp->penulis, temp->tahunTerbit);
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Buku tidak ditemukan" << endl;
    }
    system("pause");
        
} 


void cariPenulis()
{
    string cariData;
    cin.ignore();
    cout << "Masukan penulis buku: ";
    getline(cin, cariData);

    system("cls");

        cout << "+===========================================+" << endl;
        cout << "| ==  Hasil pencarian berdasarkan Penulis == |" << endl;
        cout << "+===========================================+" << endl;

    Buku* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->penulis.find(cariData) != string::npos) {
            printBox(temp->judul, temp->penulis, temp->tahunTerbit);
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Buku tidak ditemukan" << endl;
    }
    system("pause");

}

void menuCaribuku()
{
    string pilih;


    if (head == nullptr){
        system("cls");
        cout<<"Mohon maaf belum ada data"<<endl;
        system("pause");
    }

        else{
            
            do
            {
                system("cls");
                system("Color 7");
                printData();

                    cout << "+=========================================+" << endl;
                    cout << "|                SEARCHING                |" << endl;
                    cout << "+=========================================+" << endl;
                    cout << "| 1. Berdasarkan Judul                    |" << endl;
                    cout << "| 2. Berdasarkan Tahun                    |" << endl;
                    cout << "| 3. Berdasarkan Penulis                  |" << endl;
                    cout << "| 99. Kembali                             |" << endl;
                    cout << "+=========================================+" << endl;
                    cout << "|->> Pilih : ";
                    cin>>pilih;

                    if (pilih !="1" && pilih !="2"  && pilih !="3" &&  pilih !="99"){
                        cout<<"harap masukan input dengan benar!"<<endl;
                        system("Color 0C");
                        system("pause");
                    }

                        else{

                            switch (stoi(pilih))
                            {
                            case 1:
                                    cariJudul();
                                break;
                            case 2:
                                    cariTahunterbit();
                                break;
                            case 3:
                                    cariPenulis();
                                break;

                            default:
                                break;
                            }
                        }

            } while (pilih!= "99");
        }
}







// create data
void tambahBuku()
{
    string pilih,buku,penulis,tahunStr;


    do
    {
       
    system("cls");

        printData();

        cin.ignore();

        cout<<"=========================+"<<endl;
        cout<<"|       Tambah Buku      |"<<endl;
        cout<<"+========================+"<<endl;
        cout<<"Masukan Judul Buku : ";
        getline(cin,buku);

            cout<<"Masukan Penulis Buku : ";
            getline(cin,penulis);
            
            tahunnya :
                cout<<"Masukan tahun terbit : ";
                cin>>tahunStr;

                if (!cek_string(tahunStr))
                {
                    system("Color 0C");
                    cout<<"harap masukan angka!"<<endl;
                    system("pause");
                    system("Color 07");
                    cout<<"\n";
                    
                    goto tahunnya;
                }

                 

                    createData(buku,penulis,stoi(tahunStr));
                    system("cls");
                    printData();
    
        ulang :
                cout<<"\nApakah ingin menambah buku lagi [y/t] : ";
                cin>>mengulang;

                if (mengulang =="y" || mengulang =="Y"){
                    continue;
                }
                    else if(mengulang =="t" || mengulang =="Y"){
                        break;
                    }
                        else{
                            cout<<"masukan input dengan benar "<<endl;
                            goto ulang;
                        }
    } while (mengulang == "y" || mengulang == "Y");

}
 

void upadateBuku()
{
    string pilih, buku, penulis,tahunStr;
    Buku* temp = head;
    bool found = false;

        if (head == nullptr){
            system("cls");
            cout<<"Mohon maaf belum ada data"<<endl;
            system("pause");
        }

            else{

                do
                {
                cin.ignore();
                pilih_no :
                    system("cls");
                    printData();

                    cout<<"pilih no berapa yang mau di Update : ";
                    cin>>pilih;

                    if (!cek_string(pilih))
                        {
                            system("Color 0C");
                            cout<<"harap masukan angka!"<<endl;
                            system("pause");
                            system("Color 07");
                            cout<<"\n";
                            
                            goto pilih_no;
                        }
                
                int loop = 1;
                cur = head;
               while (cur != nullptr) {
                if (loop == stoi(pilih)) {
                    found = true;
                    break;
                }
                loop++;
                cur = cur->next;
            }
                

        if (found)
        {
            cin.ignore();
                         cout<<"Masukan Judul : ";
                         getline(cin,buku);

                            tahunnya :
                                    cout<<"Masukan tahun terbit : ";
                                    getline(cin,tahunStr);

                                    if (!cek_string(tahunStr))
                                    {
                                        system("Color 0C");
                                        cout<<"harap masukan angka!"<<endl;
                                        system("pause");
                                        system("Color 07");
                                        cout<<"\n";
                                        
                                        goto tahunnya;
                                    }

                            cout<<"Masukan Penulis Buku : ";
                            getline(cin,penulis);

                    
                                updateBuku(stoi(pilih),buku,penulis,stoi(tahunStr));

                        system("cls");
                        printData();
        }
        else{
            cout<<"nomor "<<pilih<<" tidak ada di dalam data "<<endl;
        }
        
                    
                   
                    

                        
                        ulang :
                                cout<<"\nApakah ingin Update buku lagi  [y/t] : ";
                                cin>>mengulang;

                                if (mengulang =="y" || mengulang =="Y"){
                                    continue;
                                }
                                    else if(mengulang =="t" || mengulang =="Y"){
                                        break;
                                    }
                                        else{
                                            cout<<"masukan input dengan benar "<<endl;
                                            goto ulang;
                                    }
                } while (mengulang == "y" || mengulang == "Y");
            }

}


void hapusBuku()
{
    string pilih_hapus;

        if (head == nullptr){
            system("cls");
            cout<<"Mohon maaf belum ada data"<<endl;
            system("pause");
        }
            else{
                
                do
                {
                    hapus :
                    system("cls");
                    printData();
                        cout<<"Masukan no berapa buku yang ingin di hapus : ";
                        cin>>pilih_hapus;
                        
                          if (!cek_string(pilih_hapus))
                            {
                                system("Color 0C");
                                cout<<"harap masukan angka!"<<endl;
                                system("pause");
                                system("Color 07");
                                cout<<"\n";
                                
                                goto hapus;
                            }

                        

                        deleteData(stoi(pilih_hapus));

                        system("cls");
                        printData();
                        ulang :
                                cout<<"\nApakah ingin Hapus buku lagi  [y/t] : ";
                                cin>>mengulang;

                                if (mengulang =="y" || mengulang =="Y"){
                                    continue;
                                }
                                    else if(mengulang =="t" || mengulang =="Y"){
                                        break;
                                    }
                                        else{
                                            cout<<"masukan input dengan benar "<<endl;
                                            goto ulang;
                                        }

                } while (mengulang == "y" || mengulang == "Y");
            }

}


void Author(){

    int detikNama = 35;
    int detikLoading = 1500;
    int jarak = 35;



    system("cls");
    hidecursor(false);

    gotoxy(49, 5);
    cout<<"Mohon Tunggu Sebentar..."<<endl<<endl;
    gotoxy(43, 7);
    loading(36,223,30);


    gotoxy(58, 12);
    system("Color 40");
        cout<<"3"<<endl;
    gotoxy(100, 12);
        
    gotoxy(58, 12);
    Sleep(detikLoading);
    system("Color 60");
        cout<<"2"<<endl;
    gotoxy(100, 12);

    gotoxy(58, 12);
    Sleep(detikLoading);
    system("Color 20");
        cout<<"1"<<endl;

    Sleep(detikLoading);
    system("cls");

    system("Color B0");
    gotoxy(jarak, 5);
    Sleep(detikNama);
        cout<<"+===================================================+"<<endl;
    gotoxy(jarak, 6);
    Sleep(detikNama);
        cout<<"|                    Author                         |"<<endl<<endl;
    gotoxy(jarak, 7);
    Sleep(detikNama);
        cout<<"+===================================================+"<<endl;
    gotoxy(jarak, 8);
    Sleep(detikNama);
        cout<<"|     NIM     |            NAMA                     |"<<endl;
    gotoxy(jarak, 9);
    Sleep(detikNama);
        cout<<"+===================================================+"<<endl;
    gotoxy(jarak, 10);
    Sleep(detikNama);
        cout<<"| 672023213 - Alam Aji Pamungkas                    |"<< endl;
    gotoxy(jarak, 11);
    Sleep(detikNama);
        cout<<"| 672023129 - Eleazar Abdiel Hasiholan Simbolon     |"<< endl;
    gotoxy(jarak, 12);
    Sleep(detikNama);
        cout<<"| 672023083 - Harta Arayko                          |"<< endl;
    gotoxy(jarak, 13);
    Sleep(detikNama);
        cout<<"| 672020227 - Eza Efrizal R                         |"<< endl;
    gotoxy(jarak, 14);
    Sleep(detikNama);
        cout<<"+===================================================+"<<endl;
    gotoxy(48, 15);
    hidecursor(true);
    system("pause");
    system("Color 7");

}

// Menu Opsi admin
void menuAdmin() {
    string pilihMenu;


do {

    system("cls");
        system("Color 7");
        cout << "+=========================================+" << endl;
        cout << "|                  Menu                   |" << endl;
        cout << "+=========================================+" << endl;
        cout << "| 1. Tampilkan Buku                       |" << endl;
        cout << "| 2. Cari Buku                            |" << endl;
        cout << "| 3. Tambah Buku                          |" << endl;
        cout << "| 4. Update Buku                          |" << endl;
        cout << "| 5. Hapus Buku                           |" << endl;
        cout << "| 99. Kembali                             |" << endl;
        cout << "+=========================================+" << endl;
        cout << "->> Pilih Menu : ";
        cin >> pilihMenu;

     
            if (pilihMenu != "1" && pilihMenu != "2" && pilihMenu != "3" && pilihMenu != "4" && pilihMenu != "5" && pilihMenu != "99") {
                cout << "Mohon maaf, input tidak valid. Silakan coba lagi." << endl;
                system("Color C");
                system("pause");
            }

                else{
                        switch (stoi(pilihMenu)) {
                            case 1:
                                     MenuSorting();
                                break;
                            case 2:
                                cout << "2. Cari Buku" << endl;
                                    menuCaribuku();
                                break;
                            case 3:
                                cout << "3. Tambah Buku" << endl;
                                    tambahBuku();
                                break;
                            case 4:
                                cout << "4. Update Buku" << endl;
                                    upadateBuku();
                                break;
                            case 5:
                                cout << "5. Hapus Buku" << endl;
                                     hapusBuku();
                                break;
                            case 99 :
                                return;
                    }
                }

        cin.ignore();
    } while (pilihMenu != "99");
}

void bacaBuku(){
    string nama, alamat,pilih;
    int i = 1;
    Buku* cur = head;
    bool found = false;
    Buku* prev = nullptr;


        masukannomor:
            system("cls");
            printData();
            cin.ignore();

            std::cout << "Masukkan nomor buku yang ingin Dibaca: ";
            std::cin >> pilih;

            if (!cek_string(pilih))
            {
                system("Color 0C");
                cout<<"Input tidak valid silahkan masukan dengan benar !"<<endl;
                system("pause");
                system("Color 07");
                goto masukannomor;
            }
            
            int nomor = stoi(pilih);
            
            while (cur != nullptr) {

            if (i == nomor) {
                found = true;
                std::cout << "Buku yang dibaca adalah : " << cur->judul;
                break;
            }
                prev = cur;
                i++;
                cur = cur->next;
            }
                cin.ignore();

                if (found) {
                    cout << "\nSilakan masukkan nama :";
                    getline(cin,nama);

                    std::cout << "Silakan Masukan Alamat :";
                    getline(cin,alamat);

                    createPembaca(nama,alamat,nomor);

            } else {
                cout << "Buku tidak ditemukan!" << std::endl;
            }

        system("pause");

}



void pinjamBuku() {
    string nama, alamat,nomor,durasi;

    do {
        masukannomor :
        system("cls");
        printData();
        cin.ignore();

        cout << "Masukkan nomor buku yang ingin dipinjam: ";
        cin >> nomor;

         if (!cek_string(nomor))
            {
                system("Color 0C");
                cout<<"Input tidak valid silahkan masukan dengan benar !"<<endl;
                system("pause");
                system("Color 07");
                goto masukannomor;
            }
        

        Buku* cur = head;
        int found = 0;
        Buku* prev = nullptr;

        int i = 1;

        while (cur != nullptr) {
            if (i == stoi(nomor)) {
                found = 1;
                cout << "Buku yang dipinjam adalah : " << cur->judul;
                break;
            }
            prev = cur;
            i++;
            cur = cur->next;
        }
        cin.ignore();
        if (found) {
            cout << "\nSilakan masukkan nama :";
            getline(cin, nama);

            cout << "\nSilakan masukkan alamat :";
            getline(cin, alamat);

            masukandurasi :
            cout << "\nBerapa lama Anda ingin meminjam buku ini (dalam hari): ";
            cin >> durasi;

            if (!cek_string(durasi))
            {
                system("Color 0C");
                cout<<"Input tidak valid silahkan masukan dengan benar !"<<endl;
                system("pause");
                system("Color 07");
                goto masukandurasi;
            }


            time_t now = time(0);
            tm* ltm = localtime(&now);
            ltm->tm_mday += stoi(durasi);
            mktime(ltm);

            char waktu[11];

            struct tm* local = localtime(&now);
            strftime(waktu, sizeof(waktu), "%H:%M:%S", local);
        


            char buffer[80];
            strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
            string batas_waktu = buffer;

            int pengembalian = stoi(batas_waktu) + stoi(durasi);

            ofstream file;
            file.open("hasil_peminjaman.txt", ios::trunc);
            if (file.is_open()) {

                file<<"+================================================================================================================+"<<endl;
                file<<"|                                            Struk Peminjaman Buku                                               |"<<endl;
                file<<"+================================================================================================================+"<<endl;
                file<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<"Judul Buku"<<setw(3)<<left<<" : "<<setw(40) << left <<cur->judul<<setw(47)<<right<<"|"<<endl;
                file<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<"Nama Peminjam"<<setw(3)<<left<<" : "<<setw(40) << left <<nama<<setw(47)<<right<<"|"<<endl;
                file<<"|"<<setw(3)<<" "<<left<<setw(20)<<left<<"Alamat Peminjam"<<setw(3)<<left<<" : "<<setw(40) << left << alamat<<setw(47)<<right<<"|"<<endl;
                file<<"+================================================================================================================|"<<endl;
                file<<setw(55)<<right<<"|"<<setw(3)<<right<<" "<<setw(20)<<left<<"Durasi Peminjaman"<<setw(5)<<right<<": "<<setw(3)<<left<<durasi<<left<<"hari"<<setw(24)<<right<<"|"<<endl;
                // file<<setw(55)<<right<<"|"<<setw(3)<<right<<" "<<setw(20)<<left<<"Batas Pengembalian"<<setw(5)<<right<<": "<<setw(20)<<left<<waktu<<setw(11)<<right<<"|"<<endl;
                file<<setw(55)<<right<<"|"<<setw(3)<<right<<" "<<setw(20)<<left<<"Jam Peminjaman"<<setw(5)<<right<<": "<<setw(20)<<left<<waktu<<setw(11)<<right<<"|"<<endl;
                file<<setw(55)<<right<<"+"<<"==========================================================+"<<endl;                
                file.close();

                // Membuka file hasil_peminjaman.txt dengan Notepad
                system("notepad hasil_peminjaman.txt");
            } else {
                cout << "Tidak dapat membuka file!" << endl;
            }

            deleteData(stoi(nomor));

        } else {
            cout << "Buku tidak ditemukan!" << endl;
        }

    
    ulang:

        cout << "\nApakah Anda ingin meminjam buku lagi [y/t]: ";
        cin >> mengulang;

        if (mengulang == "y" || mengulang == "Y") {
            continue;
        } else if (mengulang == "t" || mengulang == "T") {
            break;
        } else {
            cout << "Masukkan input dengan benar " << endl;
            goto ulang;
        }

    } while (mengulang != "t" && mengulang != "T");
}




void menuPerpustakaan()
{
    string pilih_menu;



        do
        {
            system("cls");

                cout<<"+======================================+"<<endl;
                cout<<"|             Perpustakaan             |"<<endl;
                cout<<"+======================================+"<<endl;
                cout<<"| 1. Tampilkan Buku                    |"<<endl;
                cout<<"| 2. Daftar Pembaca                    |"<<endl;
                cout<<"| 3. Baca Buku                         |"<<endl;
                cout<<"| 4. Pinjam Buku                       |"<<endl;
                cout<<"| 99. Kembali                          |"<<endl;
                cout<<"+======================================+"<<endl;
                cout<<"Pilih Menu [1-4] : ";
                cin>>pilih_menu;


                if (pilih_menu != "1" && pilih_menu != "2" && pilih_menu != "3" && pilih_menu != "4" && pilih_menu != "99"){
                    cout<<"Input tidak valid"<<endl;
                    system("pause");
                }
                else{
                    switch (stoi(pilih_menu)) {
                        case 1:
                                system("cls");
                                printData();
                                system("pause");
                            break;
                        case 2 :
                                if (headPembaca == nullptr){
                                    cout<<"Belum ada data pembaca"<<endl;
                                }
                                else{
                                system("cls");
                                printPembaca(); 

                                }
                                system("pause");

                            break;
                        case 3 :
                            cout<<"Baca Buku"<<endl;
                            bacaBuku();
                            break;
                        case 4 :
                            system("cls");
                            pinjamBuku();
                            system("pause");
                            break;
                    }

                }

        } while (pilih_menu !="99");

}



void eksit()
{
    hidecursor(false);
    system("cls");
gotoxy(30,10);
    loading(60,196,10);
    Sleep(5);    
    
gotoxy(30,11);
    cout<<"|     Terima kasih telah menggunakan perpustakaan kami!    |";
 
    
gotoxy(30,12);
    loading(60,196,10);



gotoxy(30,14);
    system("Color B0");
    cin.ignore();
    cin.get();
    system("cls");
    exit(0);
    return;
}



int main() {

    createData("Laskar Pelangi", "Andrea Hirata", 2005);
    createData("Sang Pemimpin", "Andrea Hirata", 2006);
    createData("Zahir", " Paulo Coelho", 2005);
    createData("Kutukan bangsa titan", " Rick Riordan", 2007);
    createData("Negeri 5 Menara", " Ahmad Fuadi", 2009);

    string menu_pilih;

do
{

    system("cls");
    system("Color 7");
    cout<<"+===========================================+"<<endl;
    cout<<"|                   Menu                    |"<<endl;
    cout<<"|===========================================+"<<endl;
    cout<<"| 1. Admin                                  |"<<endl;
    cout<<"| 2. Perpustakaan                           |"<<endl;
    cout<<"| 3. Author                                 |"<<endl;
    cout<<"| 4. Exit                                   |"<<endl;
    cout<<"|===========================================|"<<endl;
    cout<<"-> Pilih Menu : ";
    cin>>menu_pilih;

    if (menu_pilih !="1" && menu_pilih !="2" && menu_pilih !="3" && menu_pilih !="4"){
         cout << "Mohon maaf, input tidak valid. Silakan coba lagi." << endl;
         system("Color 0C");
        system("pause");
    }

    else{

        switch (stoi(menu_pilih))
        {
            case 1:
                if (login() == true)
                {
                    menuAdmin();
                }
                break;
            case 2:
                menuPerpustakaan();
                break;
            case 3:
                Author();
                break;    
            case 4:
                eksit();
            default:
                break;
        }

    }

} while (menu_pilih !="4");



    cout<<"\n\n\n+++ Program Berakhir +++"<<endl;
    return 0;

}