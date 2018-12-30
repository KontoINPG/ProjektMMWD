#ifndef ALGORYTM_PSZCZELI
#define ALGORYTM_PSZCZELI

#include<string>
#include<iostream>
#include<vector>
#include<map>



std::vector<int> algorytm_pszczeli();
double f_celu(std::vector<int> _wektorRozwiazan);
std::vector<std::vector<int>> losujRozwiazaniaZOtoczenia(std::vector<int> _rozwiazanieBazowe, int _iloscGenerowanychRozwiazan, int _miaraHamminga, std::vector<std::vector<int>> _macierzDostawcow);
void elita (std::vector <std::vector <int>> & _najlepsze, std::vector <std::vector <int>> _rozwiazaniePoczatkowe);

#endif // ALGORYTM_PSZCZELI
