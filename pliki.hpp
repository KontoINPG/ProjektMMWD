#ifndef PLIKI_HPP
#define PLIKI_HPP
#include<vector>
#include<string>

int wczytajBaze();

int wczytajZamowienie();

int zapiszZamowienie(std::vector <int> Wynik, std::string plik_nazwa, int iteracja, double fcelu);

int nowyPlik(std::string plik_nazwa, std::vector <int> _parametry,  std::vector <double> _podstparametry);
#endif // PLIKI_HPP
