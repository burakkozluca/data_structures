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
    void add(int veri);
    int basamak_count();

    Sayi* next;
    Sayi* prev;
};

ostream& operator<<(ostream& os,Sayi& sayi);

# endif