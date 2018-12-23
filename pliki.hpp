#ifndef PLIKI_HPP
#define PLIKI_HPP
#include<vector>
#include<string>

int wczytajBaze();

int wczytajZamowienie();

int zapiszZamowienie(std::vector <int> Wynik, std::string plik_nazwa);

int nowyPlik(std::string plik_nazwa, std::vector <int> _parametry);
#endif // PLIKI_HPP
