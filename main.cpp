#include<iostream>
#include<map>
#include<vector>

#include"produkt.hpp"

using std::cout;
using std::cin;
using std::endl;

/*class sklep
{
private:

public:
   look_for_component(string name);
   look_for_component(string name, int param);
};

/*

Plik ze sklepem:
dostawa ;
element1 ; producent ; cena ;
element2 ; producent ; cena ;
itd...

*/

/* OPIS MATEMATYCZNY
Dane wejœciowe: *lista elementów do zamówienia;
                *wskaŸnik porz¹dnoœci;

Funkcja celu:   * normalnie suma cen elementów i kosztów przesy³ki, z uwzglêdnieniem wsp. porz¹dnoœci.
                  Nie piszê tego tutaj, bo trudno to tu czytelnie zapisaæ.

Dane wyjœciowe:
                *wektor o d³ugoœci takiej, ile jest elementów. Zawiera dane, z którego sklepu dany element zamówiæ.
*/


extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;


int main()
{
    Produkt tranzystor("BC327","AVT","ST",0.1,15);
    Produkt tranzystor1("BC328","TME","ST",0.15,15);
    cout<<tranzystor.get_cena()<<", "<<tranzystor.get_cena_przesylki_sklep()<<", "<<tranzystor.get_nazwa()<<", "<<tranzystor.get_sklep()<<", "<<tranzystor.get_producent()<<endl;

std::vector< Produkt > listaProduktow;

//Przerabianie nazw producentów na liczby;
std::map<std::string, int> klasyJakosciProducentow;

klasyJakosciProducentow["ST"] = 5;
klasyJakosciProducentow["Freescale"] = 4;

cout<<klasyJakosciProducentow["ST"]<<endl;
cout<<klasyJakosciProducentow["Freescale"]<<endl;

int tabelaDopasowanProducentow[10][10];
tabelaDopasowanProducentow[4][5] = 1;
tabelaDopasowanProducentow[5][4] = 1;

cout<<tabelaDopasowanProducentow[klasyJakosciProducentow["ST"]][klasyJakosciProducentow["Freescale"]]<<endl;

BazaProduktow.push_back(tranzystor);
BazaProduktow.push_back(tranzystor1);

Sklep sklep1;

sklep1.dodaj_produkt(tranzystor.get_id());
sklep1.dodaj_produkt(tranzystor1.get_id());

std::vector<int> idZnalezionych;
idZnalezionych = sklep1.szukaj_produktow_nazwa("BC327");

for(id:idZnalezionych)
{
    cout<<BazaProduktow[id].get_cena()<<", "<<BazaProduktow[id].get_cena_przesylki_sklep()<<", "<<BazaProduktow[id].get_nazwa()<<", "<<BazaProduktow[id].get_sklep()<<", "<<BazaProduktow[id].get_producent()<<endl;
}





}

std::vector< std::string > * losowanie_wektora(int miaraHanninga )
{
return 0;
}
std::map<std::string, int> tabelaKodowanSklepow;

void algorytm_pszczeli(std::vector<Produkt> listaZakupow)
{
    //Losowanie początkowego rozwiązania:
    std::vector<std::string> wektorWyjsciowy;
    int iloscProduktow = listaZakupow.size();

    for(int lA=0;lA<iloscProduktow;lA++)
    {

    }
}
