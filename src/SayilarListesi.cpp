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
    Sayi* iter = baslangic->getter();
    Sayi* max = iter;
    while(iter != 0)
    {
        Basamak* B_iter = iter->getter();
        Basamak* B_max = B_iter;
        std::cout << "iter->basamak_count(): " << iter->basamak_count() << std::endl;
        std::cout << "max->basamak_count():  " << max->basamak_count() << std::endl;
        if(iter->basamak_count() > max->basamak_count())
            max = iter;
        else if(iter->basamak_count() == max->basamak_count())
        {   
            // std::cout << "B_iter->basamak: " << B_iter->basamak << std::endl;
            while(B_iter != 0)
            {
                std::cout << "B_iter->basamak: " << B_iter->basamak << std::endl;
                std::cout << "B_max->basamak:  " << B_max->basamak << std::endl;
                if(B_iter->basamak > B_max->basamak){
                    max = iter; std::cout<< "girdiiiiii" <<std::endl;}
                else if(B_iter->basamak == B_max->basamak)
                {
                    std::cout << "girdi" << std::endl;
                    B_iter = B_iter->next;
                    B_max = B_max->next;
                }
                else
                    B_iter = B_iter->next;
            }
        }
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
    {   std::cout  << "sildi"<< std::endl;
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