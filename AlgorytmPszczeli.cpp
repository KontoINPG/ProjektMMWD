#include"AlgorytmPszczeli.hpp"
#include"produkt.hpp"

extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;

using std::cout;
using std::cin;
using std::endl;

// http://zsi.ii.us.edu.pl/~mboryczka/IntStad/sr_abc.php

void algorytm_pszczeli_testy()
{

    //Losowanie początkowych rozwi¹zañ:

    int ilFurazerek = 5;
    std::vector< std::vector<int>> rozwiazaniePoczatkowe;

    for (int furazerka = 0; furazerka<ilFurazerek; furazerka++)
    {
        std::vector<int> rozwiazanie;
        for( element : ListaZamowienia)
        {
            int wylosowanySklepID;
            std::vector<int> dostawcy;
            int ilDostawcow;

            dostawcy = element.get_listaDostawcow();
            ilDostawcow = dostawcy.size();
            wylosowanySklepID = dostawcy[rand()%ilDostawcow];
            rozwiazanie.push_back(wylosowanySklepID);
        }
        rozwiazaniePoczatkowe.push_back(rozwiazanie);

        //Wyświetlanie, dla testu;
        for(lA:rozwiazanie)
            cout<<BazaSklepow[lA].get_nazwa()<<", ";
        cout<<endl;
        cout<<"------------------"<<endl;
    }


	while (1)
	{
		//sprawdzenie rozwiazan

		//wybranie elity i najlepszych. Zapamietanie najlepszego rozwiazania.

		//zapisanie wyników do pliku

		//sprawdzenie warunku stopu i zakończenie programu ( funkcja celu i/lub ilość iteracji )

		//losowanie otoczeń

		//generowanie kolejnej populcji


	}
}//void algorytm_pszczeli_testy();


int oblicz_funkcje_celu(std::vector<int> _wektorRozwiazan)
{
    int dlugoscWektora = _wektorRozwiazan.size();
    std::vector<int> produktyZamawianeID;

    std::vector<int> znalezione;

    for(int lA=0; lA<dlugoscWektora; lA++)
    {
        znalezione = _wektorRozwiazan[lA].szukaj_produktow_nazwa(ListaZamowienia[lA].get_nazwa());
    }

}

