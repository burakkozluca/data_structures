#include "../include/Sayi.hpp"
#include "../include/SayilarListesi.hpp"
#include <fstream>
#include <sstream>

int main()
{
    std::cout << "Program başladı" << std::endl;

    ifstream File("Sayilar.txt",ios::in);
    string satir;

    while(getline(File,satir))
    {
        stringstream str(satir);
        string number;
        int secim;
        SayilarListesi* sayilar = new SayilarListesi();

        while(getline(str, number, ' '))
        {
            Sayi* sayi = new Sayi();

            for (size_t i = 0; i < number.size(); ++i)
            {
                string digitString(1, number[i]);
                sayi->add(digitString);
            }
            sayilar->add(sayi);
            cout << *sayi;
        }
        // cout << "1. Tek Basamaklari Basa Al" << endl;
        // cout << "2. Basamaklari Tersle" << endl;
        // cout << "3. En buyuk cikar" << endl;
        // cout << "4. cikis" << endl;
        // cin >> secim;
        // switch (secim) {
        //     case 1:
        //         cout << "1. Tek Basamaklari Basa Al" << endl;
        //         // Fonksiyon çağır veya işlemi gerçekleştir
        //         break;
        //     case 2:
        //         cout << "2. Basamaklari Tersle" << endl;
        //         // Fonksiyon çağır veya işlemi gerçekleştir
        //         break;
        //     case 3:
        //         cout << "3. En buyuk cikar" << endl;
        //         // Fonksiyon çağır veya işlemi gerçekleştir
        //         break;
        //     case 4:
        //         cout << "Programdan cikiliyor..." << endl;
        //         break;
        //     default:
        //         cout << "Geçersiz secim! Lutfen tekrar deneyin." << endl;
        //         break;
        // }
        delete sayilar;
    }

    File.close();
}
