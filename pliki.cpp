#include"pliki.hpp"

#include"produkt.hpp"
#include<fstream>

extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;

using std::cout;
using std::cin;
using std::endl;

int wczytajBaze()//zwraca -1, gdy nie uda siê pliku otworzyæ. Jak OK, to zwraca 0;
{

    std::fstream plikBazaTowarow;
    plikBazaTowarow.open("BazaTowarow.txt", std::ios::in);
    if(plikBazaTowarow.good() == false)
    {
        cout<<"Plik z baza towarow nie moze byc otwarty..."<<endl;
        return(-1);
    }

    std::string liniaProdukt;

    double cena;
    double cenaPrzesylkiSklep;
    std::string producent;
    std::string nazwa;
    std::string sklep;

    while(!plikBazaTowarow.eof())
    {
        getline(plikBazaTowarow,liniaProdukt);
        //cout<<liniaProdukt<<endl;

        //Dekodowanie danych z linii//
            int poz1 = 2;
            int poz2 = 2;
            const int ilTokenow = 5;

            std::string token[ilTokenow];


            if(liniaProdukt[0]=='$' && liniaProdukt[1] == ';')//Sprawdzanie pocz¹tku linii;
            {

            for(int ltok = 0; ltok<ilTokenow; ltok++)//Rozbijanie linii na tokeny;
            {
                if(ltok == ilTokenow-1)
                {
                    poz2 = liniaProdukt.find_first_of(";#",poz1);//Sprawdzanie koñca linii;
                }else{
                        poz2 = liniaProdukt.find_first_of(";",poz1);
                     }

                for(int lpoz = poz1; lpoz<poz2;lpoz++)
                {
                    token[ltok] += liniaProdukt[lpoz];
                }
                poz1 = poz2+1;

            }

            //Dodawanie produktu do bazy;
            cena = std::stod(token[3]);
            cenaPrzesylkiSklep = std::stod(token[4]);
            producent = token[2];
            sklep = token[1];
            nazwa = token[0];

            BazaProduktow.push_back(Produkt(nazwa,sklep,producent,cena,cenaPrzesylkiSklep));

            //Przyporzadkowanie produktu do sklepu;
            (BazaSklepow[BazaSklepow.size()-1]).dodaj_produkt(BazaProduktow[(int)(BazaProduktow.size()-1)].get_id());



            }else{
                    if(liniaProdukt[0] == '@' && liniaProdukt[1] == ';')//Poczatek linii z nazwa sklepu;
                        {
                            std::string nazwaSklepu;
                            int pozKoniecNazwy = liniaProdukt.find_first_of(";#",2);
                            for( int lpoz = 2; lpoz<pozKoniecNazwy; lpoz++)
                            {
                                nazwaSklepu += liniaProdukt[lpoz];
                            }
                            //cout<<nazwaSklepu<<endl;
                            BazaSklepow.push_back(Sklep(nazwaSklepu));
                        }
                    }


        //--------------------------//
    }

    plikBazaTowarow.close();

    return 0;

}




int wczytajZamowienie()//zwraca -1, gdy nie uda siê pliku otworzyæ. Jak OK, to zwraca 0;
{

    std::fstream plikBazaTowarow;
    plikBazaTowarow.open("Zamowienie.txt", std::ios::in);
    if(plikBazaTowarow.good() == false)
    {
        cout<<"Plik z zamowieniem nie moze byc otwarty..."<<endl;
        return(-1);
    }

    std::string liniaProdukt;

    double jakosc;
    std::string nazwa;

    while(!plikBazaTowarow.eof())
    {
        getline(plikBazaTowarow,liniaProdukt);
        //cout<<liniaProdukt<<endl;

        //Dekodowanie danych z linii//
            int poz1 = 2;
            int poz2 = 2;
            const int ilTokenow = 2;

            std::string token[ilTokenow];


            if(liniaProdukt[0]=='$' && liniaProdukt[1] == ';')//Sprawdzanie pocz¹tku linii;
            {

            for(int ltok = 0; ltok<ilTokenow; ltok++)//Rozbijanie linii na tokeny;
            {
                if(ltok == ilTokenow-1)
                {
                    poz2 = liniaProdukt.find_first_of(";#",poz1);//Sprawdzanie koñca linii;
                }else{
                        poz2 = liniaProdukt.find_first_of(";",poz1);
                     }

                for(int lpoz = poz1; lpoz<poz2;lpoz++)
                {
                    token[ltok] += liniaProdukt[lpoz];
                }
                poz1 = poz2+1;

            }

            //Dodawanie zamawianego elementu do listy;
            jakosc = std::stod(token[1]);
            nazwa = token[0];

            ListaZamowienia.push_back(ElementZamawiany(nazwa,jakosc));

            //Przyporzadkowanie produktu do sklepu;
            //(BazaSklepow[BazaSklepow.size()-1]).dodaj_produkt(BazaProduktow[(int)(BazaProduktow.size()-1)].get_id());



            }


        //--------------------------//
    }

    plikBazaTowarow.close();




    return 0;

}

int zapiszZamowienie()
{
    std::fstream plikWynik;
    plikWynik.open("Wynik.txt", std::ios::out);
    if(plikWynik.good() == false)
    {
        cout<<"Plik do zapisu nie moze byc otwarty..."<<endl;
        return(-1);
    }
	return 0;
}
