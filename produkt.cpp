#include "produkt.hpp"


//---------------------------------------------------------------------------------------------------//
//Baza Produktow
//---------------------------------------------------------------------------------------------------//
std::vector< Produkt > BazaProduktow;

/*UWAGA!!! Najpierw trzeba zainicjalizować cala liste produktow z pliku, potem tworzyc ewentualna liste zakupow
bo inaczej nie bedzie sie zgdzalo id produktu z miejscem w BazieProduktow.*/
//---------------------------------------------------------------------------------------------------//


//---------------------------------------------------------------------------------------------------//
//Baza Sklepow
//---------------------------------------------------------------------------------------------------//
std::vector <Sklep> BazaSklepow;
//---------------------------------------------------------------------------------------------------//





//---------------------------------------------------------------------------------------------------//
//Produkt
//---------------------------------------------------------------------------------------------------//

Produkt::Produkt(std::string _nazwa, std::string _sklep, std::string _producent, double _cena, double _cenaPrzesylkiSklep )
{
        produktId = id;
        id = id+1;
        std::cout<<"Test, konstruktor, Produkt, id: "<<produktId<<std::endl;
        nazwa = _nazwa;
        sklep = _sklep;
        producent = _producent;
        cena = _cena;
        cenaPrzesylkiSklep = _cenaPrzesylkiSklep;// Cena wysy³ki ze sklepu (ogólnie), na wypadek, gdyby jakiœ przedmiot wymaga³ wiêkszych kosztów. Potem to siê przeliczy, ile przypada na konkretne przedmioty z tego sklepu. (Koszt przesy³ki siê najwiêkszy weŸmie spoœród przedmiotów z danego sklepu).
}

double Produkt::get_cena()
{
    return cena;
}

double Produkt::get_cena_przesylki_sklep()
{
    return cenaPrzesylkiSklep;
}

std::string Produkt::get_sklep()
{
    return sklep;
}

std::string Produkt::get_nazwa()
{
    return nazwa;
}

std::string Produkt::get_producent()
{
    return producent;
}

int Produkt::get_id()
{
    return produktId;
}


int Produkt::id = 0;





//---------------------------------------------------------------------------------------------------//
//Sklep
//---------------------------------------------------------------------------------------------------//

int Sklep::id = 0;

Sklep::Sklep()
{
    sklepId = id;
    id++;
    std::cout<<"Test, konstruktor, Sklep, id: "<<sklepId<<std::endl;
}

void Sklep::dodaj_produkt(int _produktId)
{
    listaIdProduktow.push_back(_produktId);
}

std::vector<int> Sklep::szukaj_produktow_nazwa( std::string _nazwa)
{
    std::vector<int> znalezioneId;

    for(id : listaIdProduktow)
    {
        if(BazaProduktow[id].get_nazwa() == _nazwa)
        {
            znalezioneId.push_back(id);
        }
    }
    return znalezioneId;
}

int Sklep::get_id()
{
    return sklepId;
}





