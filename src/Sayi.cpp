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

void Sayi::add(string veri)
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
    os << "##########  ";
    for (int i = 0; i < dugumSayisi; i++) {os << "******* ";} os<<endl;
    os << "#" << ss.str().substr(3, 8) <<"# ";
    temp = iter;
    for (int i = 0; i < dugumSayisi; i++) {
        bb << &iter->basamak;
        os << " * " <<bb.str().substr(11,3) << " *";
        if(iter->next != 0)
            iter = iter->next;
            // std::cout << bb.str() << std::endl;
        } os<<endl;
    iter = temp;
    os << "#--------#  ";
    for (int i = 0; i < dugumSayisi; i++) {os << "******* ";} os<<endl;
    temp = iter;
    os << "#"<< setw(9-dugumSayisi); while(iter != 0){os<<iter->basamak; iter = iter->next;} os <<"# ";
    while(temp != 0){os << " *   " << temp->basamak << " *"; temp = temp->next;}
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