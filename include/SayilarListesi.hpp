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
};

ostream& operator<<(ostream& os, SayilarListesi& sayilarlistesi); 

# endif