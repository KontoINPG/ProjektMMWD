#ifndef PRODUKT_HPP
#define PRODUKT_HPP

#include<string>
#include<iostream>
#include<vector>
#include<map>


class Produkt{
private:

    double cena;
    double cenaPrzesylkiSklep;
    std::string producent;
    std::string nazwa;
    std::string sklep;
    int produktId;
	double jakosc;


    static int id;


public:

    Produkt(std::string _nazwa, std::string _sklep, std::string _producent, double _cena, double _cenaPrzesylkiSklep, double _jakosc );
    //Produkt(){}
    double get_cena();
    double get_cena_przesylki_sklep();
	double get_jakosc();
    std::string get_producent();
    std::string get_sklep();
    std::string get_nazwa();
    int get_id();
};




class Sklep{
private:
    std::vector<int> listaIdProduktow;//Przechowuje unikatowe ID produktow;
    int sklepId;
    std::string nazwa;

    static int id;
public:
    Sklep (std::string _nazwa);
    std::vector<int> szukaj_produktow_nazwa( std::string _nazwa); //Zwroci tablice z unikatowymi ID produktow; //Jak nic nie znajdzie, to wektor z -1 zwroci;
    int get_id();
    void dodaj_produkt( int _produktId );
    std::string get_nazwa();
};


class ElementZamawiany{

private:
    static int id;

    int elementId;
    double jakosc;
    std::string nazwa;
    std::vector< int > listaDostawcow;

public:
   ElementZamawiany(std::string _nazwa, double _jakosc);

   double get_jakosc();
   std::string get_nazwa();
   std::vector<int> get_listaDostawcow();
   void set_listaDostawcow(std::vector<int> _listaDostawcow);
   int get_id();
   void dodaj_dostawce(int _id);

   };


void okreslDostepnosc();//Sprawdza, w ktorych sklepach mozna kupic produkty z listy zamowien;


#endif // PRODUKT_HPP



