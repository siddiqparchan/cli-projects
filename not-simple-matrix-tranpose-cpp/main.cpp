#include <iostream>

namespace ordo_base{
    int baris;
    int kolom;
}

namespace ordo_tranpos{
    int baris = 0;
    int kolom = 0;
}

//nama alternative
#define baris_tranpos ordo_base::kolom
#define kolom_tranpos ordo_base::baris

int main(){
    std::system("clear");

    std::cout << "==ini adalah kalkulator perkalian matrix==" << std::endl;
    std::cout << "===========Silahkan Masukkan Ordo=========" << std::endl;

    std::cout << "Berapa Baris: ";
    std::cin >> ordo_base::baris;

    std::cout << "Berapa Kolom: ";
    std::cin >> ordo_base::kolom;

    char matrix_base[ordo_base::baris][ordo_base::kolom];
    //dibalik nanti secara jumlah
    char matrix_tranpos[ordo_base::kolom][ordo_base::baris];

    std::cout << std::endl;

    std::cout << "==Silahkan masukkan matrix sesuai format==" << std::endl;
    //Masukkan matrix
    for(short i = 0; i < ordo_base::baris; i++){
        for(short j = 0; j < ordo_base::kolom; j++){
            std::cin >> matrix_base[i][j];
        }
    }

    //tranpos
    for(short i = 0; i < ordo_base::baris; i++){
        ordo_tranpos::baris = 0;
        for(short j = 0; j < ordo_base::kolom; j++){
            matrix_tranpos[ordo_tranpos::baris][ordo_tranpos::kolom] = matrix_base[i][j];
            ordo_tranpos::baris++;
        }
        ordo_tranpos::kolom++;
    }

    //output
    std::cout << std::endl;
    std::cout << "===============Tranposnya=================" << std::endl;
    for(short i = 0; i < baris_tranpos; i++){
        std::cout << '[';
        for(short j = 0; j < kolom_tranpos; j++){
            std::cout << matrix_tranpos[i][j];
            if(j != kolom_tranpos - 1){
                std::cout << ' ';
            }
        }
        std::cout << ']' << std::endl;
    }

    std::cout << "==============End of File=================" << std::endl;
    return 0;
}