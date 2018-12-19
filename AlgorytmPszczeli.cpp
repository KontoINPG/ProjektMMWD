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
int f_celu (vector <int> roz){
    return 5;
}           //tymczasowa deklaracja w celu kompilacji

void algorytm_pszczeli_testy()
{

    //Losowanie początkowych rozwi¹zañ:

    int ilFurazerek = 5;
    vector< vector<int>> rozwiazaniePoczatkowe;

    for (int furazerka = 0; furazerka<ilFurazerek; furazerka++)
    {
        vector<int> rozwiazanie;
        for( element : ListaZamowienia)
        {
            int wylosowanySklepID;
            vector<int> dostawcy;
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
        for(selekcja:rozwiazaniePoczatkowe){
            maxi=0;     //czyszczenie munimum
            id=0;
            if(policz_max==1){  //jeśli wyłuskanie najgorszego rozwiązania jest nieaktualne, to policz je na nowo
                for(rozwiazanie:najlepsze){
                    f_naj.clear();      //Czyszcze cały wektor
                    f_naj.push_back(5/*f_celu(rozwiazanie)*/);   //wpisanie do wektora wyników funkcji celu najlepszych rozwiązań
                    if(f_celu(rozwiazanie)>maxi)
                        maxi=f_celu(rozwiazanie);
                        id_max=id;  //zapamiętanie pozycji najgorszego rozwiązania
                    id++;
                }
                policz_max=0;
            }
            if(f_celu(selekcja)<maxi){
                najlepsze[id_max]=selekcja;
                policz_max=1;   //trzeba policzyć na nowo funkcję celu rozwiązań najlepszych, w celu uzyskania najgorszego spośród nich
            }

        }
		//zapisanie wyników do pliku

		//sprawdzenie warunku stopu i zakończenie programu ( funkcja celu i/lub ilość iteracji )

		//losowanie otoczeń

		//generowanie kolejnej populcji


	}
}//void algorytm_pszczeli_testy();


