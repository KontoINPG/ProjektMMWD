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
//Lista Zamowienia
//---------------------------------------------------------------------------------------------------//
std::vector <ElementZamawiany> ListaZamowienia;
//---------------------------------------------------------------------------------------------------//





//---------------------------------------------------------------------------------------------------//
//Produkt
//---------------------------------------------------------------------------------------------------//

Produkt::Produkt(std::string _nazwa, std::string _sklep, std::string _producent, double _cena, double _cenaPrzesylkiSklep )
{
        produktId = id;
        id = id+1;
        //std::cout<<"Test, konstruktor, Produkt, id: "<<produktId<<std::endl;
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

Sklep::Sklep(std::string _nazwa)
{
    sklepId = id;
    id++;
    nazwa = _nazwa;
    //std::cout<<"Test, konstruktor, Sklep, id: "<<sklepId<<std::endl;
}

void Sklep::dodaj_produkt(int _produktId)
{
    listaIdProduktow.push_back(_produktId);
}

std::vector<int> Sklep::szukaj_produktow_nazwa( std::string _nazwa)
{
    std::vector<int> znalezioneId;
    bool czyZnaleziono = false;

    for(id : listaIdProduktow)
    {
        if(BazaProduktow[id].get_nazwa() == _nazwa)
        {
            znalezioneId.push_back(id);
            czyZnaleziono = true;
        }
    }

    if(czyZnaleziono==false)
    {
        znalezioneId.push_back(-1);
    }

return znalezioneId;


}

std::string Sklep::get_nazwa()
{
    return nazwa;
}

int Sklep::get_id()
{
    return sklepId;
}


//---------------------------------------------------------------------------------------------------//
//ElementZamawiany
//---------------------------------------------------------------------------------------------------//

int ElementZamawiany::id = 0;

ElementZamawiany::ElementZamawiany(std::string _nazwa, double _jakosc)
{
    elementId = id;
    id++;
    nazwa = _nazwa;
    jakosc = _jakosc;
}


double ElementZamawiany::get_jakosc()
{
    return jakosc;
}

std::string ElementZamawiany::get_nazwa()
{
    return nazwa;
}

std::vector<int> ElementZamawiany::get_listaDostawcow()
{
    return listaDostawcow;
}

void ElementZamawiany::set_listaDostawcow(std::vector<int> _listaDostawcow)
{
    listaDostawcow = _listaDostawcow;
}

int ElementZamawiany::get_id()
{
    return elementId;
}

void ElementZamawiany::dodaj_dostawce(int _id)
{
    listaDostawcow.push_back(_id);
}




void okreslDostepnosc()
{
    for(element : ListaZamowienia)
    {
       std::string nazwaElementu = element.get_nazwa();

       for(sklep : BazaSklepow)
       {
           std::vector<int> idSklepow = sklep.szukaj_produktow_nazwa(nazwaElementu);
           if(idSklepow[0] != -1)//Czyli, jezeli cos znalazlo;
           {
                for(id : idSklepow)
                {
                    element.dodaj_dostawce(id);

                    std::cout<<"OkrDost"<<std::endl;
                    std::cout<<element.get_nazwa()<<std::endl;
                    std::cout<<id<<std::endl;
                    std::cout<<"-------------------------------------"<<std::endl;//################################################-TU JUŻ JEST ŹLE!
                }
           }
       }

    }
}



