#include "../include/SayilarListesi.hpp"

SayilarListesi::SayilarListesi()
{

}

SayilarListesi::~SayilarListesi()
{

}

void SayilarListesi::add(Sayi *sayi)
{
    if(first == NULL)
        first = sayi;
    else
    {
        Sayi* iter = first;
        while(iter->next != 0)
            iter = iter->next;
        iter->next = sayi;
        sayi->prev = iter;
    } 
}

Sayi* SayilarListesi::getter()
{
    return first;
}

ostream& operator<<(ostream& os, SayilarListesi& sayilarlistesi)
{
    os << "Sayilar Listesi: " << endl;

    Sayi* iter = sayilarlistesi.getter();
    while(iter != nullptr)
    {
        os << iter->getter();
        iter = iter->next;
        if(iter != 0)
            cout << endl;
    }
    return os;
}