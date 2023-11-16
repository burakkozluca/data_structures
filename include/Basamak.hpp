#ifndef BASAMAK_HPP
# define BASAMAK_HPP

#include <iostream>
#include <string>

using namespace std;

class Basamak
{
public:
    Basamak(string sayi);
    ~Basamak();

    string basamak;
    Basamak* next;
    Basamak* prev;
    void printadress();
};




#endif