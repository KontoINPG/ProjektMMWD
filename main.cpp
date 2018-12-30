#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<string>
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
extern ParametryProgramu ProgParam;



int main()
{

srand(time(NULL));//------------------DAŁEM TO TU, ŻEBY O TYM NIE ZAPOMNIEĆ :) ----------------------;

wczytajBaze();

    cout<<"Produkty w bazie:"<<endl;

for (tranzystor : BazaProduktow)
{
    cout<<tranzystor.get_cena()<<", "<<tranzystor.get_cena_przesylki_sklep()<<", "<<tranzystor.get_nazwa()<<", "<<tranzystor.get_sklep()<<", "<<tranzystor.get_producent()<<", "<<tranzystor.get_jakosc()<<endl;
}

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
    cout<<"Element:" <<element.get_nazwa()<<endl;
    cout<<"Dostepny w sklepach:"<<endl;

    for( sklep : element.get_listaDostawcow())
    {
        cout<<BazaSklepow[sklep].get_nazwa()<<endl;
        cout<<sklep<<endl;
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
    zapiszZamowienie(test_wyniku,"Nowy_wynik");*/
    for (int j=1; j<11; j++)
    {
        switch (rand() % 2)
        {
            case 0:
                ProgParam.set_zadanaJakosc(rand()%16);
                break;
            case 1:
                ProgParam.set_wspCenaJakosc((double)rand()/RAND_MAX);
                ProgParam.set_wspKaraJakosc((1-ProgParam.get_wspCenaJakosc()));
                break;
            default:
                break;
        }
        for (int i=1; i<101; i++)
        {
            if(i<10)
                ProgParam.set_NazwaPliku("Seria"+std::to_string(j)+"_Eksperyment0"+std::to_string(i));
            else
                ProgParam.set_NazwaPliku("Seria"+std::to_string(j)+"_Eksperyment"+std::to_string(i));

            switch (rand() % 9)
            {
            case 0:
                ProgParam.set_iloscElita(rand() % 10 + 1);
                ProgParam.set_iloscFurazerek(ProgParam.get_iloscElita()+ProgParam.get_iloscNajlepsze()+ProgParam.get_iloscZwiadowcy());
                break;
            case 1:
                ProgParam.set_iloscNajlepsze(rand() % 10 + 1);
                ProgParam.set_iloscFurazerek(ProgParam.get_iloscElita()+ProgParam.get_iloscNajlepsze()+ProgParam.get_iloscZwiadowcy());
                break;
            case 2:
                ProgParam.set_iloscZwiadowcy(rand() % 10 + 1);
                ProgParam.set_iloscFurazerek(ProgParam.get_iloscElita()+ProgParam.get_iloscNajlepsze()+ProgParam.get_iloscZwiadowcy());
                break;
            case 3:
                ProgParam.set_otoczenieElitaHamming(rand() % 10 +1);
                break;
            case 4:
                ProgParam.set_otoczenieElitaIlosc(rand() % 10 +1);
                break;
            case 5:
                ProgParam.set_otoczenieNajlepszeHamming(rand() % 10 +1);
                break;
            case 6:
                ProgParam.set_otoczenieNajlepszeIlosc(rand() % 10 +1);
                break;
            case 7:
                ProgParam.set_otoczenieZwiadowcyHamming(rand() % 10 +1);
                break;
            case 8:
                ProgParam.set_otoczenieZwiadowcyIlosc(rand() % 10 +1);
                break;
            default:
                break;
            }
            std::vector<int> rozwiazania = algorytm_pszczeli();
        }
    }
    return 0;
}//koniec int main();


