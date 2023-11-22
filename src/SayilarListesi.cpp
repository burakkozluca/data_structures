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

void SayilarListesi::removeMax(SayilarListesi* baslangic)
{
    //en büyük elemanı silmek için sayi classına number ekle
    //bu sayede basamaklarla uğraşmamız oluruz.
    Sayi* iter = baslangic->getter();
    Sayi* max = iter;
    while (iter != nullptr)
    {
        if (iter->sayi > max->sayi)
            max = iter;
        else if (iter->sayi == max->sayi && iter->basamak_count() > max->basamak_count())
            max = iter;

        iter = iter->next;
    }
    if(max->prev == 0)
    {
        if(max->next == 0)
            first = 0;
        else
        {
            first = max->next;
            max->next->prev = 0;
        }
    }
    else
    {
        if(max->next == 0)
            max->prev->next = 0;
        else
        {
            max->prev->next = max->next;
            max->next->prev = max->prev;
        }
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
        os << *iter;
        iter = iter->next;
        if(iter != 0)
            cout << endl;
    }
    return os;
}