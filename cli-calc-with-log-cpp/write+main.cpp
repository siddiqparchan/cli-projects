#include <iostream>
#include <fstream>
#include <ctime>

struct time{
	int menit, jam, tanggal, bulan, tahun;
};

int main(){
	using std::cout;
	using std::cin;
	using std::fstream;
	using std::endl;
	using std::ios;

	long long pertama;
	long long kedua;
	char oper;
	long long hasil;
	fstream file;
	//waktu-waktuan
	//struct yang berisi nanti untuk waktu saat ini
	struct tm waktu_sekarang;
	//time_t adalah sebuah tipe data khusus, time(NULL) = waktu sekarang
	time_t now = time(NULL); //now = dari 1 JAN 1970 kalau ga salah
	//Konversi waktu dari 1970, ke waktu sekarang
	waktu_sekarang = *localtime(&now);
	struct time waktu;
	//dapatkan data dari struct tm, dijadikan ke int
	waktu.menit = waktu_sekarang.tm_min;
	waktu.jam = waktu_sekarang.tm_hour;
	waktu.tanggal = waktu_sekarang.tm_mday;
	waktu.bulan = waktu_sekarang.tm_mon + 1; //karena januari=0 dan desember=11
	waktu.tahun = waktu_sekarang.tm_year + 1900; //karena tahun 1900=0 di sini

	cout << "Program Calculator (Support +, -, x, :, %)" << endl;
	cout << "NOTE: Tidak ada koma saat pembagian" << endl;
	cout << "Format: Angka Operator Angka" << endl;

	file.open("Log.txt", ios::out | ios::app);
	file << "Program dibuka: ";
	file << waktu.jam << ":" << waktu.menit << ' ';
	file << waktu.tanggal << '/' << waktu.bulan << '/' << waktu.tahun << endl;

	//oper = y untuk permulaan 
	oper = 'y';
	while(oper == 'y'){
		cin >> pertama >> oper >> kedua;
		if(oper == '+'){
			hasil = pertama + kedua;
			cout << "Hasil: " << hasil << endl;
		}
		if(oper == '-'){
			hasil = pertama - kedua;
			cout << "Hasil: " << hasil << endl;	
		}
		if(oper == 'x'){
			hasil = pertama * kedua;
			cout << "Hasil: " << hasil << endl;
		}
		if(oper == ':'){
			hasil = pertama / kedua;
			cout << "Hasil: " << hasil << endl;
		}
		if(oper == '%'){
			hasil = pertama % kedua;
			cout << "Hasil: " << hasil << endl;
		}
		file << pertama << oper << kedua << '=' << hasil << endl;
		cout << "Lanjut? [y/n] "; cin >> oper;
	}
	//ulang lagi pengaturan waktunya, karena yang sebelumnya hanya ngesave waktu pada waktu tadi
	now = time(NULL);
	waktu_sekarang = *localtime(&now);
	waktu.menit = waktu_sekarang.tm_min;
	waktu.jam = waktu_sekarang.tm_hour;
	waktu.tanggal = waktu_sekarang.tm_mday;
	waktu.bulan = waktu_sekarang.tm_mon + 1; 
	waktu.tahun = waktu_sekarang.tm_year + 1900;

	file << "Program ditutup: ";
	file << waktu.jam << ":" << waktu.menit << ' ';
	file << waktu.tanggal << '/' << waktu.bulan << '/' << waktu.tahun << endl;
	file.close();

	cout << "Terima kasih telah menggunakan" << endl;

	return 0;
}