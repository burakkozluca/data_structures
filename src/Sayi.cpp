#include "../include/Sayi.hpp"

using namespace std;

Sayi::Sayi()
{
    // cout << "Default constructor called" << endl;
}

Sayi::~Sayi()
{
    // cout << "Default destructor called" << endl;
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
    os << "Basamaklistesi: " << endl;
    
    Basamak* iter = sayi.getter();
    while (iter != 0)
    {
        os << iter->sayi;
        iter = iter->next;
        if(iter != 0)
            cout << endl;
    }
    return os;
}