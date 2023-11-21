/*
Algoritma:
Tinggal cek yang udah menang
*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

//global variabel
char tic_tac_toe_elemen[9];
string P1, P2;
short inputan;

//non void function
bool apakah_ga_replace(){
    if(tic_tac_toe_elemen[inputan] != 'X'){
        if(tic_tac_toe_elemen[inputan] != 'O'){
            return true;
        }else{
            return false;
        }
    }else if(tic_tac_toe_elemen[inputan != 'O']){
        if(tic_tac_toe_elemen[inputan] != 'X'){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
string cek_udah_menang(){
    //cek horizontal
    for(short i = 0; i < 9; i+=3){
        if((tic_tac_toe_elemen[i] == tic_tac_toe_elemen[i+1]) and (tic_tac_toe_elemen[i] == tic_tac_toe_elemen[i+2])){
            if(tic_tac_toe_elemen[i] == 'X'){
                return P1;
            }else{
                return P2;
            }
        }
    }
    //cek vertical
    for(short i = 0; i < 3; i++){
        if((tic_tac_toe_elemen[i] == tic_tac_toe_elemen[i+3]) and (tic_tac_toe_elemen[i] == tic_tac_toe_elemen[i+6])){
            if(tic_tac_toe_elemen[i] == 'X'){
                return P1;
            }else{
                return P2;
            }
        }
    }
    //cek diagonal
    if((tic_tac_toe_elemen[0] == tic_tac_toe_elemen[4]) and (tic_tac_toe_elemen[0] == tic_tac_toe_elemen[8])){
            if(tic_tac_toe_elemen[4] == 'X'){
                return P1;
            }else{
                return P2;
            }
    }
    else if((tic_tac_toe_elemen[2] == tic_tac_toe_elemen[4]) and (tic_tac_toe_elemen[2] == tic_tac_toe_elemen[6])){
            if(tic_tac_toe_elemen[4] == 'X'){
                return P1;
            }else{
                return P2;
            }
    }else{
        return "%34578798786273617354";
    }
}

//void function
void masukkin_ke_array(string Player){
        if(Player == P1){
            tic_tac_toe_elemen[inputan] = 'X';  
        }else{
            tic_tac_toe_elemen[inputan] = 'O';
        }
}
void print_toe(){
    for(short i = 0; i < 9; i++){
        cout << tic_tac_toe_elemen[i];
        if(i % 3 == 2){
            cout << ';' << endl;
        }else{
            cout << ", ";
        }
    }
}
void siapa_player(){
    /*ulang_player1:
    cout << "Siapa player 1: ";
    getline(cin, P1);
    if(P1 == "%34578798786273617354"){
        cout << "Gaboleh" << endl;
        goto ulang_player1;
    }
    ulang_player2:
    cout << "Siapa player 2: ";
    getline(cin, P2);
    if(P2 == "%34578798786273617354"){
        cout << "Gaboleh" << endl;
        goto ulang_player2;
    }*/
    while(true){
        cout << "Siapa player 1: ";
        getline(cin, P1);
        if(P1 != "%34578798786273617354"){
            break;
        }
    }
    while(true){
        cout << "Siapa player 2: ";
        getline(cin, P2);
        if(P2 != "%34578798786273617354"){
            break;
        }
    }   
}
void awal(){
    //jadiin semuanya pakai nomor dulu
    for(short i = 0; i < 9; i++){
        tic_tac_toe_elemen[i] = static_cast<char>(i + 48); //pada ascii '0' = 48
    }
    //print
    cout << "Ini adalah Tic-Tac_Toe" << endl;
    cout << "ketik enter untuk mulai";
    cin.get();
}
void game(){
    siapa_player();
    bool ga_replace;
    string pemenang;
    for(short i = 0; i < 10; i++){ //maksimal loop hanya 9
        print_toe();
        if(i % 2 == 0){//genap maka P1
            cout << P1 << ": "; //X
            cin >> inputan;
            ga_replace = apakah_ga_replace();
            if(ga_replace == true){
                masukkin_ke_array(P1);
            }      
        }else if(i % 2 == 1){//ganjil maka P2
            cout << P2 << ": "; //O
            cin >> inputan;
            ga_replace = apakah_ga_replace();
            if(ga_replace == true){
                masukkin_ke_array(P2);
            } 
        }
        if(ga_replace == false){
            cout << endl << "===UDH ADA===" << endl << endl;
            i--; //kurangi nilai i agar looping diulangi
        }
        //akhir dari game
        pemenang = cek_udah_menang();
        if(pemenang == "%34578798786273617354"){

        }
        else if((pemenang == P1) or (pemenang == P2)){
            if(pemenang == P1){
                cout << P1 << " Menang" << endl; 
            }else{
                cout << P2 << " Menang" << endl;
        }
        print_toe();
        break;
        }
    }
}

int main(){
    awal();
    game();
    cout << "Game Selesai" << endl;
}
