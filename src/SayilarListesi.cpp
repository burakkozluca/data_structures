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

void SayilarListesi::tekBasamaklariKaydirTumSayilar() {
    Sayi* current = first;

    while (current != nullptr) {
        current->tekBasamaklariKaydir();
        current = current->next;
    }
}

void SayilarListesi::basamaklariYerDegistirTumSayilar() {
    Sayi* current = first;

    while (current != nullptr) {
        current->basamaklariYerDegistir();
        current = current->next;
    }
}

// void swapNodes(Basamak* node1, Basamak* node2) {
//     // Node1 ve Node2'nin yerlerini değiştir
//     if (node1 == nullptr || node2 == nullptr) {
//         std::cout << "Hatalı düğüm!" << std::endl;
//         return;
//     }

//     // Node1'in önceki düğümünü güncelle
//     if (node1->prev != nullptr) {
//         node1->prev->next = node2;
//     } else {
//         // Node1 başlangıç düğümü ise, başlangıcı güncelle
//         baslangic = node2;
//     }

//     // Node2'nin önceki düğümünü güncelle
//     if (node2->prev != nullptr) {
//         node2->prev->next = node1;
//     } else {
//         // Node2 başlangıç düğümü ise, başlangıcı güncelle
//         baslangic = node1;
//     }

//     // Node1 ve Node2'nin birbirine bağlı olan next ve prev referanslarını değiştir
//     Basamak* temp = node1->next;
//     node1->next = node2->next;
//     node2->next = temp;

//     temp = node1->prev;
//     node1->prev = node2->prev;
//     node2->prev = temp;
// }



Sayi* SayilarListesi::getter()
{
    return first;
}


ostream& operator<<(ostream& os, SayilarListesi& sayilarlistesi)
{
    Sayi* iter = sayilarlistesi.getter();
    while(iter != nullptr)
    {
        os << *iter;
        iter = iter->next;
    }
    return os;
}