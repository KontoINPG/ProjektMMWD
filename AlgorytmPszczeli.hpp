#ifndef ALGORYTM_PSZCZELI
#define ALGORYTM_PSZCZELI

#include<string>
#include<iostream>
#include<vector>
#include<map>

void algorytm_pszczeli_testy();
int oblicz_funkcje_celu(std::vector<int> _wektorRozwiazan);
std::vector<std::vector<int>> losujRozwiazaniaZOtoczenia(std::vector<int> _rozwiazanieBazowe, int _iloscGenerowanychRozwiazan, int _miaraHamminga, std::vector<std::vector<int>> _macierzDostawcow);

#endif // ALGORYTM_PSZCZELI
