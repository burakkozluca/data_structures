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

Basamak* Sayi::getter()
{
    return first;
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