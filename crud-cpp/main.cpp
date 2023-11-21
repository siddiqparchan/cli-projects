#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::ofstream fout;
std::ifstream fin;
std::fstream foutin;
std::stringstream sstr;

using std::cout;
using std::cin;
using std::endl;

char inputan_awal;
char yes_or_no;
short counter_data;
short temp_short;
std::string temp_string;
std::string temp_temp_string;

void awal_banget();
void ga_awal_banget();
void nomor_1();
void nomor_2();
void nomor_3();
void nomor_4();

int main(){
    //baca counter_data
    fin.open("data.txt");
    fin >> counter_data;
    fin.close();
    if(counter_data == 0){
        awal_banget();
    }
    //kalau ga awal banget, maka
    else{
        ga_awal_banget();
    }

    //Pakai enum agar mudah dibaca
    enum opsi{READ = '1', CREATE, UPDATE, DELETE, FINISH};

    while(inputan_awal != FINISH){
        //pakai switch_case
        switch(inputan_awal){
            case READ:
                nomor_1();
                break;
            case CREATE:
                nomor_2();
                break;
            case UPDATE:
                nomor_3();
                break;
            case DELETE:
                nomor_4();
                break;
            default:
                cout << "Mungkin lu salah tekan" << endl;
                break;
        }
        //pakai if
        /*if(inputan_awal == READ){
            nomor_1();
        }
        else if(inputan_awal == CREATE){
            nomor_2();
        }
        else if(inputan_awal == UPDATE){
            nomor_3();
        }
        else if(inputan_awal == DELETE){
            nomor_4();
        }
        else{
            cout << "Mungkin lu salah tekan" << endl; 
        }*/
        
        //ini penggunaan goto, darurat, soalnya kalau pakai cara lain, rasanya ga bisa
        ulangi_lanjut_tadi:
        //selesai
        cout << "Lanjut[y/n]";
        cin >> yes_or_no;
        if((yes_or_no == 'y') or (yes_or_no == 'y')){
            ga_awal_banget();
        }
        else if((yes_or_no == 'n') or (yes_or_no == 'N')){
            break;
        }else{
            //saya rasa, goto di sini ga berbahaya
            goto ulangi_lanjut_tadi;
        }
    }
}

void awal_banget(){
        //awal banget
        cout << "PROGRAM CRUD Data SISWA" << endl;
        cout << "-----rule: Nama[4-7]---" << endl;
        cout << "1: Tampilkan data" << endl;
        cout << "2: Tambah data" << endl;
        cout << "3: Ubah data" << endl;
        cout << "4: Hapus data" << endl;
        cout << "5: Selesai(Keluar dari program)" << endl;
        cout << "-----------------------" << endl;
        
        fout.open("data.txt", std::ios::app);
        counter_data++;
        fout << counter_data << endl;
        fout << "No" << '\t' << '\t' << "Nama" << '\t' << '\t' << "NIS" << '\t' << '\t' << "Jurusan" << endl;
        fout.close();
                
        cout << "Pilih data [1-5]: ";
        cin >> inputan_awal;
}

void ga_awal_banget(){
        system("cls");
        //kalau di unix: "system("clear");"
        cout << "PROGRAM CRUD Data SISWA" << endl;
        cout << "-----rule: Nama[4-7]---" << endl;
        cout << "1: Tampilkan data" << endl;
        cout << "2: Tambah data" << endl;
        cout << "3: Ubah data" << endl;
        cout << "4: Hapus data" << endl;
        cout << "5: Selesai(Keluar dari program)" << endl;
        cout << "-----------------------" << endl;
        cout << "Pilih data [1-5]: ";
        cin >> inputan_awal;
}

void nomor_1(){
            //tampilkan data
            fin.open("data.txt");
            for(short i = 0; i < counter_data; i++){
            if(i == 0){
                std::getline(fin, temp_string);
            }
            std::getline(fin, temp_string);
            cout << temp_string << endl;
            }
            fin.close();

}

void nomor_2(){
            //tambah data
            fout.open("data.txt", std::ios::app);

            fout << counter_data << '\t' << '\t';

            cout << "Nama: ";
            cin.ignore();
            std::getline(cin, temp_string);
            fout << temp_string << '\t' << '\t';

            cout << "NIS: ";
            cin >> temp_short;
            fout << temp_short << '\t' << '\t';

            cout << "Jurusan: ";
            cin.ignore();
            std::getline(cin, temp_string);
            fout << temp_string << '\t' << '\t';

            fout << endl;

            fout.close();
            counter_data++; //data bertambah satu
            
            //perbarui data counter_data
            //jadi idenya kita masukkan seluruh isi file ke temp_string (kecuali baris pertama, nanti dihapus aj if(i==0)), nanti kita replace filenya dengan file baru
            fin.open("data.txt");
            //pastikan kosong
            temp_string.erase();
            for(short i = 0;;){
                std::getline(fin, temp_temp_string);
                if(i == 0){
                    i++;
                    continue;
                }
                if(fin.eof()){
                    break;
                }else{
                    temp_string +=temp_temp_string + '\n';
                }
            }
            fin.close();

            fout.open("data.txt", std::ios::out);
            fout << counter_data << endl;
            fout << temp_string;
            fout.close();
}

void nomor_3(){
            //rewrite
            //ubah data
            //input dari user
            short inputan_ubah;
            cout << "Nomor ke-: ";
            cin >> inputan_ubah;
            inputan_ubah += 2;
            //baca terus masukin ke string
            fin.open("data.txt");
            temp_temp_string.erase();
            for(short i = 1; i <= inputan_ubah; i++){
                std::getline(fin, temp_string);
                if(i == inputan_ubah){
                    sstr << (inputan_ubah-2);
                    sstr >> temp_string;
                    sstr.clear();
                    temp_temp_string += temp_string + '\t' + '\t';

                    cout << "Nama: ";
                    cin.ignore();
                    std::getline(cin, temp_string);
                    temp_temp_string += temp_string + '\t' + '\t';

                    cout << "NIS: ";
                    cin >> temp_short;
                    sstr << temp_short;
                    sstr >> temp_string;
                    sstr.clear();
                    temp_temp_string += temp_string + '\t' + '\t';

                    cout << "Jurusan: ";
                    cin.ignore();
                    std::getline(cin, temp_string);
                    temp_temp_string += temp_string + '\t' + '\t' + '\n';
                }else{
                    temp_temp_string += temp_string + '\n';
                }
            }
            for(short i = inputan_ubah; i < counter_data + 1; i++){
                std::getline(fin, temp_string);
                temp_temp_string += temp_string + '\n';
            }
            fin.close();
            //rewrite
            fout.open("data.txt");
            fout << temp_temp_string;
            fout.close();
}

void nomor_4(){
            //hapus data

            short inputan_hapus;
            cout << "No ke-: ";
            cin >> inputan_hapus;
            counter_data--;//data berkurang satu
            const short batas_loop = inputan_hapus + 2;

            fin.open("data.txt");
            for(short i = 1; i <= batas_loop; i++){
                if(i == 1){
                    std::getline(fin, temp_string);
                    sstr << counter_data;
                    sstr >> temp_temp_string;
                    sstr.clear();
                    temp_temp_string += '\n';
                }
                else if(i < batas_loop){
                std::getline(fin, temp_string);
                temp_temp_string += temp_string + '\n';
                }
                else if(i == batas_loop){
                    //dapetin nomornya dulu
                    fin >> temp_short;
                    std::getline(fin,temp_string);
                }
            }
            for(short i = batas_loop; i < counter_data + 2; i++){
                //untuk nomornya
                sstr << temp_short;
                sstr >> temp_string;
                sstr.clear();
                temp_temp_string += temp_string;
                
                fin >> temp_short;
                std::getline(fin, temp_string);
                temp_temp_string += temp_string + '\n';
            }
            fin.close();

            fout.open("data.txt");
            fout << temp_temp_string;
            fout.close();
}