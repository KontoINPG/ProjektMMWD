#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


int main()
{
    srand(time(NULL));
    std::fstream plikBazaTowarow;
    plikBazaTowarow.open("BazaTowarow.txt", std::ios::out);
    if(plikBazaTowarow.good() == false)
    {
        std::cout<<"Plik z baza towarow nie moze byc otwarty..."<<std::endl;
        return(-1);
    }
    plikBazaTowarow << "@;S" << 0 << ";#" << std::endl;
    for (int j=300; j<350; j++)
    {
        plikBazaTowarow << "$;BC" << j << ";S0;ST;0.99;20;1;" << std::endl;
    }
    for (int i=1; i<51; i++)
    {
        plikBazaTowarow << "@;S" << i << ";#" << std::endl;
        for (int j=300; j<350; j++)
        {
            if(rand() % 101<60)
            {
                switch (rand() % 5)
                {

                case 0:
                    plikBazaTowarow << "$;BC" << j << ";S" << i << ";ST;0." << rand() % 100 << ";" << rand() % 21 +1 << ";" << rand() % 16 + 1 << ";" << std::endl;
                    break;
                case 1:
                    plikBazaTowarow << "$;BC" << j << ";S" << i << ";IR;0." << rand() % 100 << ";" << rand() % 21 +1 << ";" << rand() % 16 + 1 << ";" << std::endl;
                    break;
                case 2:
                    plikBazaTowarow << "$;BC" << j << ";S" << i << ";FS;0." << rand() % 100 << ";" << rand() % 21 +1 << ";" << rand() % 16 + 1 << ";" << std::endl;
                    break;
                case 3:
                    plikBazaTowarow << "$;BC" << j << ";S" << i << ";JVC;0." << rand() % 100 << ";" << rand() % 21 +1 << ";" << rand() % 16 + 1 << ";" << std::endl;
                    break;
                case 4:
                    plikBazaTowarow << "$;BC" << j << ";S" << i << ";TCL;0." << rand() % 100 << ";" << rand() % 21 +1 << ";" << rand() % 16 + 1 << ";" << std::endl;
                    break;
                default:
                    break;
                }
            }
        }
    }
}
