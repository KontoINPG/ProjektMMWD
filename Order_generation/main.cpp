#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


int main()
{
    srand(time(NULL));
    std::fstream plikBazaTowarow;
    plikBazaTowarow.open("Zamowienie.txt", std::ios::out);
    if(plikBazaTowarow.good() == false)
    {
        std::cout<<"Plik z baza towarow nie moze byc otwarty..."<<std::endl;
        return(-1);
    }
    for (int j=300; j<350; j++)
    {
        if(rand() % 101<40)
        {
            plikBazaTowarow << "$;BC" << j << ";" << rand() % 16 + 1 << ";#" << std::endl;
        }
    }
}
