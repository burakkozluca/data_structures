#include "../include/Sayi.hpp"
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

Sayi::Sayi()
{
    // cout << "Default constructor called" << endl;
}

Sayi::~Sayi()
{
    // cout << "Default destructor called" << endl;
}

int Sayi::basamak_count()
{
    int count = 0;
    Basamak* iter = first;
    while (iter != 0)
    {
        count++;
        iter = iter->next;
    }
    return count;
}

void Sayi::add(int veri)
{
    Basamak* basamak = new Basamak(veri);
    if(first == 0)
        first = basamak;
    else
    {
        Basamak* iter = first;
        while (iter->next != 0)
            iter = iter->next;
        iter->next = basamak;
        basamak->prev = iter;
    }
}

void Sayi::basamaklariYerDegistir() {
        // Basamakları sondan başa doğru yer değiştir
        Basamak* prev = nullptr;
        Basamak* current = first;
        Basamak* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

    first = prev;
}

void Sayi::tekBasamaklariKaydir() {
        // Tek basamakları sola, çift basamakları sağa kaydır
        Basamak* current = first;
        Basamak* prev = nullptr;
        Basamak* tekBasamaklar = nullptr;
        Basamak* sonraki = nullptr;

        while (current != nullptr) {
            sonraki = current->next;

            if (current->basamak % 2 == 0) {
                // Tek basamakları sola kaydır
                current->next = tekBasamaklar;
                tekBasamaklar = current;
            } else {
                // Çift basamakları sağa kaydır
                current->next = nullptr;
                if (prev != nullptr) {
                    prev->next = current;
                } else {
                    first = current;
                }
                prev = current;
            }

            current = sonraki;
        }

        // Tek basamakları sona ekleyerek tamamla
        if (prev != nullptr) {
            prev->next = tekBasamaklar;
        } else {
            first = tekBasamaklar;
        }
}

Basamak* Sayi::getter()
{
    return first;
}
void Sayi::setter(Basamak* newFirst)
{
    first = newFirst;
}

ostream& operator<<(ostream& os, Sayi& sayi)
{
    Basamak* iter = sayi.getter();
    Basamak* temp;
    int dugumSayisi = sayi.basamak_count();
    std::stringstream ss,bb;
    ss << &sayi;
    std::string addressString = ss.str();
    std::string lasteightDigits = addressString.substr(addressString.length() - 8);
    os << "##########  ";
    for (int i = 0; i < dugumSayisi; i++) {os << "******* ";} os<<endl;
    os << "#" << lasteightDigits <<"# ";
    temp = iter;
    for (int i = 0; i < dugumSayisi; i++) {
        bb << &iter->basamak;
        std::string addressString = bb.str();
        std::string lastThreeDigits = addressString.substr(addressString.length() - 3);
        os << " * " << lastThreeDigits << " *";
        // std::cout <<"  Adres:  " <<std::hex << std::setw(3)<< &iter->basamak << std::endl;
        if(iter->next != 0)
            iter = iter->next;
    } os<<endl;
    iter = temp;
    os << "#--------#  ";
    for (int i = 0; i < dugumSayisi; i++) {os << "******* ";} os<<endl;
    temp = iter;
    os << "#"<< setw(9-dugumSayisi); while(iter != 0){os<<iter->basamak; iter = iter->next;} os <<"# ";
    iter = temp;
    while(iter != 0){os << " *   " << iter->basamak << " *"; iter = iter->next;}
    os <<endl<< "##########  ";
    for (int i = 0; i < dugumSayisi; i++) {os << "******* ";} os<<endl;
    // while (iter != 0)
    // {
    //     os << iter->basamak;
    //     iter = iter->next; 
    // }
    cout << endl;
    return os;
}