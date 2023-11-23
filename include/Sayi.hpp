#ifndef SAYI_HPP
# define SAYI_HPP

#include "Basamak.hpp"
#include <iostream>
#include <string>

using namespace std;

class Sayi
{
private:
    Basamak* first;
public:
    Sayi();
    ~Sayi();
    Basamak* getter();
    void setter(Basamak* basamak);
    void add(int veri);
    int basamak_count();
    int sayi;

    Sayi* next;
    Sayi* prev;
};

ostream& operator<<(ostream& os,Sayi& sayi);

# endif