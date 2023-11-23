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

void SayilarListesi::shiftSingleDigitsToLeft(SayilarListesi* baslangic){
    Sayi* iter = baslangic->getter();

    while(iter != nullptr){
        // std::cout << *iter << std::endl;
        Basamak* current = iter->getter();
        if(iter->basamak_count() == 1){
            std::cout << "Sayı zaten tek basamaklı" << std::endl;
        }
        else{
            current = current->next; //2. düğüme geç
            while(current != nullptr){
                //std::cout << "Current: " << current->basamak << " Prev: " << current->prev->basamak << std::endl;
                if(current->basamak % 2 == 1 && current->prev->basamak % 2 == 0){
                    std::cout << "Tek basamaklı sayı bulundu: " << current->basamak << std::endl;
                     // Tek basamaklı sayıları sola kaydırmak için düğümleri yer değiştir
                    Basamak* nextNode = current->next;

                    // current ve prev düğümlerini yer değiştir
                    if (current->prev->prev != nullptr) {
                        current->prev->prev->next = current;
                    } else {
                        // Eğer current düğümü listenin başındaysa first'ı güncelle
                        iter->setter(current);
                    }

                    current->prev->next = current->next;  // düzeltme burada
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }

                    current->next = current->prev;  // düzeltme burada
                    current->prev = current->prev->prev;

                    if (current->prev != nullptr) {
                        current->prev->next = current;
                    } else {
                        // Eğer current düğümü listenin başındaysa first'ı güncelle
                        iter->setter(current);
                    }

                    if (nextNode != nullptr) {
                        nextNode->prev = current;
                    }
                }
                current = current->next;
            }
        }
        iter = iter->next;
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