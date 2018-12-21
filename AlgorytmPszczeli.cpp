#include"AlgorytmPszczeli.hpp"
#include"produkt.hpp"

extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;

using std::cout;
using std::cin;
using std::endl;

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


    losujRozwiazaniaZOtoczenia(rozwiazaniePomocniczeStartowe,5,ListaZamowienia.size(),macierzDostawcow);//losowanie z miarą Hamminga = il. zamawianych elem. => czyli losowanie wszystkich elementów wektora;

    /*int ilFurazerek = 5;
    std::vector< std::vector<int>> rozwiazaniePoczatkowe;

    for (int furazerka = 0; furazerka<ilFurazerek; furazerka++)
    {
        std::vector<int> rozwiazanie;
        int iloscElementowZamowienia = ListaZamowienia.size();

        for(int lElem=0;lElem<iloscElementowZamowienia;lElem++)
        {
            int wylosowanySklepID;
            std::vector<int> dostawcy;
            int ilDostawcow;

            dostawcy = macierzDostawcow[lElem];
            ilDostawcow = dostawcy.size();
            wylosowanySklepID = dostawcy[rand()%ilDostawcow];
            rozwiazanie.push_back(wylosowanySklepID);
        }
        rozwiazaniePoczatkowe.push_back(rozwiazanie);
*/



   // }


	//while (1)
	//{
		//sprawdzenie rozwiazan

		//wybranie elity i najlepszych. Zapamietanie najlepszego rozwiazania.

		//zapisanie wyników do pliku

		//sprawdzenie warunku stopu i zakończenie programu ( funkcja celu i/lub ilość iteracji )

		//losowanie otoczeń

		//generowanie kolejnej populcji


	//}
}//void algorytm_pszczeli_testy();


int f_celu(std::vector<int> _wektorRozwiazan)
{
    int dlugoscWektora = _wektorRozwiazan.size();
    std::vector<int> produktyZamawianeID;

    std::vector<int> znalezione;

    for(int lA=0; lA<dlugoscWektora; lA++)
    {
        znalezione = BazaSklepow[_wektorRozwiazan[lA]].szukaj_produktow_nazwa(ListaZamowienia[lA].get_nazwa());

    }

}

