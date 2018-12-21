#include"AlgorytmPszczeli.hpp"
#include"produkt.hpp"

extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// http://zsi.ii.us.edu.pl/~mboryczka/IntStad/sr_abc.php


std::vector<std::vector<int>> losujRozwiazaniaZOtoczenia(std::vector<int> _rozwiazanieBazowe, int _iloscGenerowanychRozwiazan, int _miaraHamminga, std::vector<std::vector<int>> _macierzDostawcow)
{
    int dlugoscRozwiazania = _rozwiazanieBazowe.size();
    std::vector<int> rozwiazanieWyjsciowe = _rozwiazanieBazowe;

    std::vector<std::vector<int>> wektorWylosowanychRozwiazan;


    for(int lRozwiazan=0;lRozwiazan<_iloscGenerowanychRozwiazan;lRozwiazan++)
    {

    for(int lHamming=0;lHamming<_miaraHamminga;lHamming++)
    {

        std::vector<int> dostawcy;
        int ilDostawcow;

        int wylosowanaPozycja;

        if(_miaraHamminga==dlugoscRozwiazania)//Dzieki temu mozna losowac wszystkie elementy wektora na nowo, podajac miare Hamminga = dl. wektora;
        {
            wylosowanaPozycja = lHamming;
        }else{
                wylosowanaPozycja = rand()%dlugoscRozwiazania;
                }

        dostawcy = _macierzDostawcow[wylosowanaPozycja];
        ilDostawcow = dostawcy.size();
        rozwiazanieWyjsciowe[wylosowanaPozycja] = dostawcy[rand()%ilDostawcow];

    }

    wektorWylosowanychRozwiazan.push_back(rozwiazanieWyjsciowe);
     //Wyswietlanie, dla testu;
        for(lA:rozwiazanieWyjsciowe)
            cout<<BazaSklepow[lA].get_nazwa()<<", ";
        cout<<endl;
        cout<<"------------------"<<endl;
    }
    return wektorWylosowanychRozwiazan;

}

int f_celu(std::vector<int> _wektorRozwiazan)
{
    int dlugoscWektora = _wektorRozwiazan.size();
    std::vector<int> produktyZamawianeID;

    std::vector<int> znalezione;

    for(int lA=0; lA<dlugoscWektora; lA++)
    {
        znalezione = BazaSklepow[_wektorRozwiazan[lA]].szukaj_produktow_nazwa(ListaZamowienia[lA].get_nazwa());

    }
    return 5;//Tymczasowo, co by sie kompilowalo;

}

void algorytm_pszczeli_testy()
{

    //Losowanie poczatkowych rozwiazan:

    std::vector <std::vector<int>> macierzDostawcow;

    for ( element:ListaZamowienia)
    {
        std::vector<int> dostawcy = element.get_listaDostawcow();
        macierzDostawcow.push_back(dostawcy);
    }


    std::vector<int> rozwiazaniePomocniczeStartowe;//Tylko do wystartowania losujRozwiazaniaZOtoczenia potrzebne;

    for(int lElem=0;lElem<ListaZamowienia.size();lElem++)
        {
            rozwiazaniePomocniczeStartowe.push_back(0);
        }


    std::vector<std::vector<int>> rozwiazaniePoczatkowe = losujRozwiazaniaZOtoczenia(rozwiazaniePomocniczeStartowe,5,ListaZamowienia.size(),macierzDostawcow);//losowanie z miarą Hamminga = il. zamawianych elem. => czyli losowanie wszystkich elementów wektora;




vector <vector <int>> najlepsze;
vector <int> f_naj;
const int ilosc_roz=10; //+1
int maxi;
int id_max=0;
int id;
bool policz_max=1;
	while (1)
	{
		//sprawdzenie rozwiazan

		//wybranie elity i najlepszych. Zapamietanie najlepszego rozwiazania.
        for(selekcja:rozwiazaniePoczatkowe)
            {
            maxi=0;     //czyszczenie munimum
            id=0;
            if(policz_max==1)
            {  //jeśli wyłuskanie najgorszego rozwiązania jest nieaktualne, to policz je na nowo
                for(rozwiazanie:najlepsze)
                {
                    f_naj.clear();      //Czyszcze cały wektor
                    f_naj.push_back(5/*f_celu(rozwiazanie)*/);   //wpisanie do wektora wyników funkcji celu najlepszych rozwiązań
                    if(f_celu(rozwiazanie)>maxi)
                    {
                        maxi=f_celu(rozwiazanie);
                        id_max=id;  //zapamiętanie pozycji najgorszego rozwiązania
                    }
                    id++;
                }
                policz_max=0;
            }
            if(f_celu(selekcja)<maxi)
            {
                najlepsze[id_max]=selekcja;
                policz_max=1;   //trzeba policzyć na nowo funkcję celu rozwiązań najlepszych, w celu uzyskania najgorszego spośród nich
            }

        }
	}
		//zapisanie wyników do pliku

		//sprawdzenie warunku stopu i zakończenie programu ( funkcja celu i/lub ilość iteracji )

		//losowanie otoczeń

		//generowanie kolejnej populcji


	//}


}//void algorytm_pszczeli_testy();


