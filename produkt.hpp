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


    static int id;


public:

    Produkt(std::string _nazwa, std::string _sklep, std::string _producent, double _cena, double _cenaPrzesylkiSklep );
    //Produkt(){}
    double get_cena();
    double get_cena_przesylki_sklep();
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
    std::vector<int> szukaj_produktow_nazwa( std::string _nazwa); //Zwroci tablice z unikatowymi ID produktow;
    void dodaj_produkt( int _produktId );
    int get_id();
    std::string get_nazwa();
};



#endif // PRODUKT_HPP



