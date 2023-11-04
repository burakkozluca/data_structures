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
        Sayi* sayi = new Sayi();
        SayilarListesi* sayilar = new SayilarListesi();
        //her sayi sayilar listesine sayi bağlı listesi olarak eklenecek.
        while(getline(str, number, ' '))
        {
            sayi->add(number);
        }
        sayilar->add(sayi);
        cout << *sayilar << endl;
        cout << *sayi << endl;
        delete sayi;
        delete sayilar;
    }

    File.close();
}
