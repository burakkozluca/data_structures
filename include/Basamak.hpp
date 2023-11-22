#ifndef BASAMAK_HPP
# define BASAMAK_HPP

#include <iostream>
#include <string>

using namespace std;

class Basamak
{
public:
    Basamak(int sayi);
    ~Basamak();

    int basamak;
    Basamak* next;
    Basamak* prev;
};

#endif