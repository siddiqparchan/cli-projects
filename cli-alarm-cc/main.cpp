#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

class Alarm{
    private:
    public:
    
        tm waktu_alarm;

        Alarm(){}
        ~Alarm(){}
        void input_waktu_alarm(){
            std::cin >> waktu_alarm.tm_hour;
            std::cin >> waktu_alarm.tm_min;
            std::cout << "====== Alarm sedang berjalan ======" << '\n';
        }
};

int main(){
    //deklarasi alarm 1
    Alarm alarm_1;
    alarm_1.input_waktu_alarm();

    //variabel untuk mendapatkan waktu sekarang
    time_t waktu_sekarang;
    
    //infinite loop buat pengecekan
    while(true){
        time(&waktu_sekarang);

        tm *waktu_sekarang_struct = localtime(&waktu_sekarang);

        if(waktu_sekarang_struct->tm_hour == alarm_1.waktu_alarm.tm_hour
        and waktu_sekarang_struct->tm_min == alarm_1.waktu_alarm.tm_min){
            break;
        }

        std::this_thread::sleep_for(std::chrono::minutes(1));
    }

    std::cout << "Alarm bunyi" << '\n';
}
