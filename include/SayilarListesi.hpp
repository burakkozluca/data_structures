#ifndef SAYILARLISTESI_HPP
# define SAYILARLISTESI_HPP

#include "Sayi.hpp"

class SayilarListesi
{
private:
    Sayi* first;
public:
    SayilarListesi();
    ~SayilarListesi();

    Sayi* getter();
    void add(Sayi* sayi);
    void removeMax(SayilarListesi* baslangic);
    void swapNodes(Basamak* node1, Basamak* node2);
    void shiftSingleDigitsToLeft(SayilarListesi* baslangic);
    void basamaklariYerDegistirTumSayilar();

    SayilarListesi* next;
    SayilarListesi* prev;
};

ostream& operator<<(ostream& os, SayilarListesi& sayilarlistesi); 

# endif