#ifndef PARAMETRY_HPP
#define PARAMETRY_HPP
#include <string>

//ParametryProgramu-----------------------------------------------------------------------//

//>>Klasa ta zawiera wszystkie parametry niezbedne do dzialania programu;
//>>W programie utworzony jest 1 obiekt "ProgParam" - z niego odczytywane sa parametry;
//>>W programie bedzie rowniez std::vector<ParametryProgramu> - jego kolenje elementy
// beda przekopiowywane do "ProgParam", co pozwoli na wielokrotne wykonanie programu
//z roznymi parametrami;

class ParametryProgramu{
private:
    int iloscFurazerek = 10;
    double zadanaJakosc = 5;
    double wspCenaJakosc = 0.5;
    double wspKaraJakosc = 0.5;

    int ilosc_roz = 10;//+1 rozwiazania elitarne

    int iloscElita = 1; //Suma ma dawac iloscFurazerek;
    int iloscNajlepsze = 5;
    int iloscZwiadowcy = 4;

    int otoczenieElitaIlosc = 5;
    int otoczenieNajlepszeIlosc = 3;
    int otoczenieZwiadowcyIlosc = 2;

    int otoczenieElitaHamming = 1;
    int otoczenieNajlepszeHamming = 2;
    int otoczenieZwiadowcyHamming = 2;

    bool rodziceWPopulacji = true;

    int iloscIteracjiAlgorytmuMax = 200;

    std::string NazwaPliku = "Eksperyment";

public:
    int get_iloscFurazerek();
    void set_iloscFurazerek(int _iloscFurazerek);

    int get_iloscElita();
    void set_iloscElita(int _iloscElita);

    int get_iloscNajlepsze();
    void set_iloscNajlepsze(int _iloscNajlepsze);

    int get_iloscZwiadowcy();
    void set_iloscZwiadowcy(int _iloscZwiadowcy);

    int get_otoczenieElitaIlosc();
    void set_otoczenieElitaIlosc(int _otoczenieElitaIlosc);

    int get_otoczenieNajlepszeIlosc();
    void set_otoczenieNajlepszeIlosc(int _otoczenieNajlepszeIlosc);

    int get_otoczenieZwiadowcyIlosc();
    void set_otoczenieZwiadowcyIlosc(int _otoczenieZwiadowcyIlosc);

    int get_otoczenieElitaHamming();
    void set_otoczenieElitaHamming(int _otoczenieElitaHamming);

    int get_otoczenieNajlepszeHamming();
    void set_otoczenieNajlepszeHamming(int _otoczenieNajlepszeHamming);

    int get_otoczenieZwiadowcyHamming();
    void set_otoczenieZwiadowcyHamming(int _otoczenieZwiadowcyHamming);

    double get_zadanaJakosc();
    void set_zadanaJakosc(double _zadanaJakosc);

    double get_wspCenaJakosc();
    void set_wspCenaJakosc(double _wspCenaJakosc);

    double get_wspKaraJakosc();
    void set_wspKaraJakosc(double _wspKaraJakosc);

    int get_ilosc_roz();
    void set_ilosc_roz(int _ilosc_roz);

    bool get_rodziceWPopulacji();
    void set_rodziceWPopulacji(bool _rodziceWPopulacji);

    int get_iloscIteracjiAlgorytmuMax();
    void set_iloscIteracjiAlgorytmuMax(int _iloscIteracjiAlgorytmuMax);

    std::string get_NazwaPliku();
    void set_NazwaPliku(std::string _NazwaPliku);
};

//Koniec ParametryProgramu----------------------------------------------------------------//




#endif // PARAMETRY_HPP
