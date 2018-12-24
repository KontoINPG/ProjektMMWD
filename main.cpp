#include<iostream>
#include<map>
#include<vector>
#include<sstream>

#include<ctime>
#include<cstdlib>


#include"produkt.hpp"
#include"pliki.hpp"
#include"AlgorytmPszczeli.hpp"
#include"Parametry.hpp"

using std::cout;
using std::cin;
using std::endl;


extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;




int main()
{

<<<<<<< HEAD
    wczytajBaze();
=======
srand(time(NULL));//------------------DAŁEM TO TU, ŻEBY O TYM NIE ZAPOMNIEĆ :) ----------------------;

wczytajBaze();
>>>>>>> testy


    cout<<"Produkty w bazie:"<<endl;

<<<<<<< HEAD
    for (tranzystor : BazaProduktow)
    {
        cout<<tranzystor.get_cena()<<", "<<tranzystor.get_cena_przesylki_sklep()<<", "<<tranzystor.get_nazwa()<<", "<<tranzystor.get_sklep()<<", "<<tranzystor.get_producent()<<endl;
    }
=======
for (tranzystor : BazaProduktow)
{
    cout<<tranzystor.get_cena()<<", "<<tranzystor.get_cena_przesylki_sklep()<<", "<<tranzystor.get_nazwa()<<", "<<tranzystor.get_sklep()<<", "<<tranzystor.get_producent()<<", "<<tranzystor.get_jakosc()<<endl;
}
>>>>>>> testy

    std::string szukanyElement;
    szukanyElement = "BC327";

    cout<<endl;
    cout<<endl;

    cout<<"Znalezione dla zapytania: "<<szukanyElement<<endl;

    for(sklep : BazaSklepow)
    {
        std::vector<int> idZnalezionych;
        idZnalezionych = sklep.szukaj_produktow_nazwa(szukanyElement);
        if(idZnalezionych[0] != -1)
        {
            for(id:idZnalezionych)
            {
                cout<<BazaProduktow[id].get_cena()<<", "<<BazaProduktow[id].get_cena_przesylki_sklep()<<", "<<BazaProduktow[id].get_nazwa()<<", "<<BazaProduktow[id].get_sklep()<<", "<<BazaProduktow[id].get_producent()<<endl;
            }
        }
    }

    //Dziwne testy------------------------//

    wczytajZamowienie();
    okreslDostepnosc();

    cout<<"------------------------------------------------------"<<endl;
    cout<<ListaZamowienia[0].get_id()<<endl;
    cout<<ListaZamowienia[1].get_id()<<endl;
    cout<<ListaZamowienia[0].get_id()<<endl;

    for(element : ListaZamowienia)
    {
<<<<<<< HEAD
        cout<<"Element:" <<element.get_nazwa()<<endl;
        cout<<"Dostepny w sklepach:"<<endl;

        for( sklep : element.get_listaDostawcow())
        {
            cout<<BazaSklepow[sklep].get_nazwa()<<endl;
        }
        cout<<"-----------------"<<endl<<endl;
    }
    //testowe wywołania
    std::vector <int> parametry;
    parametry.push_back(0);
    parametry.push_back(1);
    parametry.push_back(2);
    parametry.push_back(3);
    nowyPlik("Nowy_wynik", parametry);
    std::vector <int> test_wyniku;
    test_wyniku.push_back(0);
    zapiszZamowienie(test_wyniku,"Nowy_wynik");
}//koniec int main();

std::vector< std::string > * losowanie_wektora(int miaraHanninga )
{
return 0;
}
std::map<std::string, int> tabelaKodowanSklepow;

        cout<<BazaSklepow[sklep].get_nazwa()<<endl;
        cout<<sklep<<endl;
    }
    cout<<"-----------------"<<endl<<endl;
}

algorytm_pszczeli_testy();



}//koniec int main();





