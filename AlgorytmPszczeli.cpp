#include"AlgorytmPszczeli.hpp"
#include"produkt.hpp"
#include"Parametry.hpp"

#include<limits>

extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;

ParametryProgramu ProgParam; //Obiekt zawierajacy wszystkie ustawienia i parametry;

using std::cout;
using std::cin;
using std::endl;

// http://zsi.ii.us.edu.pl/~mboryczka/IntStad/sr_abc.php


std::vector<std::vector<int>> losujRozwiazaniaZOtoczenia(std::vector<int> _rozwiazanieBazowe, int _iloscGenerowanychRozwiazan, int _miaraHamminga, std::vector<std::vector<int>> _macierzDostawcow)
{
    int dlugoscRozwiazania = _rozwiazanieBazowe.size();
    if (dlugoscRozwiazania == 0)
    {
        cout<<"BLAD: dlugoscRozwiazania = 0"<<endl;
    }
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

        if (ilDostawcow == 0)
    {
        cout<<"BLAD: ilDostawcow = 0"<<endl;
    }
        rozwiazanieWyjsciowe[wylosowanaPozycja] = dostawcy[rand()%ilDostawcow];

    }

    wektorWylosowanychRozwiazan.push_back(rozwiazanieWyjsciowe);
     //Wyswietlanie, dla testu;
       /* for(lA:rozwiazanieWyjsciowe)
            cout<<BazaSklepow[lA].get_nazwa()<<", ";
        cout<<endl;
        cout<<"------------------"<<endl;*/
    }
    return wektorWylosowanychRozwiazan;

}

double f_celu(std::vector<int> _wektorRozwiazan)
{
    int dlugoscWektora = _wektorRozwiazan.size();
    std::vector<int> produktyZamawianeID;

    std::vector<int> znalezione;

    double cenaProduktow = 0;
    double cenaPrzesylek = 0;
    double cenaJakosc = 0;
    double cenaRozwiazania = 0;

    double przesylka = 0;
    std::map<int,double> przesylkiSklepy;

    for(int lA=0; lA<dlugoscWektora; lA++)
    {
        znalezione = BazaSklepow[_wektorRozwiazan[lA]].szukaj_produktow_nazwa(ListaZamowienia[lA].get_nazwa());
        cenaProduktow += BazaProduktow[znalezione[0]].get_cena();

        przesylka = BazaProduktow[znalezione[0]].get_cena_przesylki_sklep();

        if(przesylka>przesylkiSklepy[_wektorRozwiazan[lA]])
        {
            przesylkiSklepy[_wektorRozwiazan[lA]] = przesylka;
        }

        if(ListaZamowienia[lA].get_jakosc() > BazaProduktow[znalezione[0]].get_jakosc())
        {
            cenaJakosc = (ListaZamowienia[lA].get_jakosc() - BazaProduktow[znalezione[0]].get_jakosc()) * ProgParam.get_wspKaraJakosc();
        }
    }

    for(sklepID : _wektorRozwiazan)
    {
        cenaPrzesylek += przesylkiSklepy[sklepID];
    }

    cenaRozwiazania = ProgParam.get_wspCenaJakosc() * (cenaProduktow + cenaPrzesylek) + (1 - ProgParam.get_wspCenaJakosc()) * cenaJakosc;


    return cenaRozwiazania;

}


void elita (std::vector <std::vector <int>> & _najlepsze, std::vector <std::vector <int>> _rozwiazaniePoczatkowe){
    //wybranie elity i najlepszych. Zapamietanie najlepszego rozwiazania.
std::vector <int> f_naj;
int maxi;
int id_max=0;
int id;
bool policz_max=1;
    for(selekcja:_rozwiazaniePoczatkowe)
        {
        maxi=0;     //czyszczenie munimum
        id=0;
        if(policz_max==1)
        {  //jeśli wyłuskanie najgorszego rozwiązania jest nieaktualne, to policz je na nowo
            for(rozwiazanie:_najlepsze)
            {
                f_naj.clear();      //Czyszcze cały wektor
                f_naj.push_back(f_celu(rozwiazanie));   //wpisanie do wektora wyników funkcji celu najlepszych rozwiązań
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
            _najlepsze[id_max]=selekcja;
            policz_max=1;   //trzeba policzyć na nowo funkcję celu rozwiązań najlepszych, w celu uzyskania najgorszego spośród nich
        }
    }
}


std::vector<int> algorytm_pszczeli()
{

    //Wyznaczanie macierzy dostawcow: kazdemu elementowi z listy zamowienia odpowiada wektor z ID potencjalnych dostawcow;

    std::vector <std::vector<int>> macierzDostawcow;

    for ( element:ListaZamowienia)
    {
        std::vector<int> dostawcy = element.get_listaDostawcow();
        macierzDostawcow.push_back(dostawcy);
    }


    //Losowanie poczatkowych rozwiazan:

    std::vector<int> rozwiazaniePomocniczeStartowe;//Tylko do wystartowania losujRozwiazaniaZOtoczenia potrzebne;

    for(int lElem=0;lElem<ListaZamowienia.size();lElem++)
        {
            rozwiazaniePomocniczeStartowe.push_back(0);
        }



    std::vector<std::vector<int>> rozwiazaniePoczatkowe = losujRozwiazaniaZOtoczenia(rozwiazaniePomocniczeStartowe,ProgParam.get_iloscFurazerek(),ListaZamowienia.size(),macierzDostawcow);//losowanie z miarą Hamminga = il. zamawianych elem. => czyli losowanie wszystkich elementów wektora;

    //cout<<"TEST FUNKCJI CELU: "<<f_celu(rozwiazaniePoczatkowe[0])<<endl;


    std::vector<std::vector<int>> populacja;

    populacja = rozwiazaniePoczatkowe;

    std::vector<std::vector<int>> populacjaRozszerzona;

    std::vector<double> cenyRozwiazan;

    int ilEl_Naj = (ProgParam.get_iloscElita()+ProgParam.get_iloscNajlepsze());

    int licznikIteracjiAlgorytmu = 1;

	while (1)
	{



		//losowanie otoczeń-----------------------------//


		//TERAZ NIE MA RODZICOW W ROZWIAZANIACH!!!// <- JUŻ SĄ :)

		for(int lElitaPop = 0; lElitaPop< ProgParam.get_iloscElita(); lElitaPop++)
        {

            for( int lElita = 0; lElita < ProgParam.get_otoczenieElitaIlosc(); lElita++)
            {
                populacjaRozszerzona.push_back(losujRozwiazaniaZOtoczenia(populacja[lElitaPop],1,ProgParam.get_otoczenieElitaHamming(),macierzDostawcow)[0]);
            }

            if(ProgParam.get_rodziceWPopulacji() == true)
            {
                populacjaRozszerzona.push_back(populacja[lElitaPop]);
            }
        }

        for(int lNajlepszePop = 0; lNajlepszePop< ProgParam.get_iloscNajlepsze(); lNajlepszePop++)
        {

            for( int lNajlepsze = 0; lNajlepsze < ProgParam.get_otoczenieNajlepszeIlosc(); lNajlepsze++)
            {
                populacjaRozszerzona.push_back(losujRozwiazaniaZOtoczenia(populacja[ProgParam.get_iloscElita()+lNajlepszePop],1,ProgParam.get_otoczenieNajlepszeHamming(),macierzDostawcow)[0]);
            }
            if(ProgParam.get_rodziceWPopulacji() == true)
            {
                populacjaRozszerzona.push_back(populacja[ProgParam.get_iloscElita()+lNajlepszePop]);
            }
        }

        for(int lZwiadowcyPop = 0; lZwiadowcyPop< ProgParam.get_iloscZwiadowcy(); lZwiadowcyPop++)
        {

            for( int lZwiadowcy = 0; lZwiadowcy < ProgParam.get_otoczenieZwiadowcyIlosc(); lZwiadowcy++)
            {
                populacjaRozszerzona.push_back(losujRozwiazaniaZOtoczenia(populacja[ProgParam.get_iloscElita()+ProgParam.get_iloscNajlepsze()+lZwiadowcyPop],1,ProgParam.get_otoczenieZwiadowcyHamming(),macierzDostawcow)[0]);
            }
            if(ProgParam.get_rodziceWPopulacji() == true)
            {
                populacjaRozszerzona.push_back(populacja[ProgParam.get_iloscElita()+ProgParam.get_iloscNajlepsze()+lZwiadowcyPop]);
            }
        }

		//sprawdzanie rozwiązań i generowanie kolejnej populcji-----------------------------//

		populacja.clear();//Kasowanie populacji przed tworzenem nowej;

		double cenaNajlepsza = std::numeric_limits<double>::infinity();
		int cenaNajlepszaIt = 0;

        //Obliczanie funkcji celu dla calej rozszerzonej populacji;
		for(rozwiazanie : populacjaRozszerzona)
        {
            cenyRozwiazan.push_back(f_celu(rozwiazanie));
        }

        //Wyszukiwanie Elity i Najlepszych;
        for(int lPop = 0;lPop<ilEl_Naj;lPop++)
        {

            cenaNajlepsza = std::numeric_limits<double>::infinity();

            for(int cenaIt = 0; cenaIt < cenyRozwiazan.size(); cenaIt++)
            {
                if(cenyRozwiazan[cenaIt] <= cenaNajlepsza)
                {
                    cenaNajlepsza = cenyRozwiazan[cenaIt];
                    cenaNajlepszaIt = cenaIt;
                }
            }
            cenyRozwiazan[cenaNajlepszaIt] = std::numeric_limits<double>::infinity();
            populacja.push_back(populacjaRozszerzona[cenaNajlepszaIt]);

        }

        //Dolosowywanie Zwiadowcow;
        for(int lZwiad = 0;lZwiad<ProgParam.get_iloscZwiadowcy();lZwiad++)
        {
            populacja.push_back(losujRozwiazaniaZOtoczenia(rozwiazaniePomocniczeStartowe,1,ListaZamowienia.size(),macierzDostawcow)[0]);
        }

        populacjaRozszerzona.clear(); //Kasowanie przed kolejna iteracja;
        cenyRozwiazan.clear();




        //zapisanie wyników do pliku--------------------------------------------------------//
        cout<<"Iteracja: "<<licznikIteracjiAlgorytmu<<", f_celu: "<<cenaNajlepsza<<endl;










		//sprawdzenie warunku stopu i zakończenie programu ( funkcja celu i/lub ilość iteracji )-----------------------//

		if(licznikIteracjiAlgorytmu >= ProgParam.get_iloscIteracjiAlgorytmuMax())
        {
            return populacja[0];
        }

        //zwiekszenie licznika iteracji-----------------------------------------------------//
        licznikIteracjiAlgorytmu++;




	}


}//void algorytm_pszczeli_testy();


