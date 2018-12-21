#ifndef PARAMETRY_HPP
#define PARAMETRY_HPP


//ParametryProgramu-----------------------------------------------------------------------//

//>>Klasa ta zawiera wszystkie parametry niezbedne do dzialania programu;
//>>W programie utworzony jest 1 obiekt "ProgParam" - z niego odczytywane sa parametry;
//>>W programie bedzie rowniez std::vector<ParametryProgramu> - jego kolenje elementy
// beda przekopiowywane do "ProgParam", co pozwoli na wielokrotne wykonanie programu
//z roznymi parametrami;

class ParametryProgramu{
private:
    int iloscFurazerek = 5;
    double zadanaJakosc = 5;
    double wspCenaJakosc = 0.5;

public:
    int get_iloscFurazerek();
    void set_iloscFurazerek(int _iloscFurazerek);

    double get_zadanaJakosc();
    void set_zadanaJakosc(double _zadanaJakosc);

    double get_wspCenaJakosc();
    void set_wspCenaJakosc(double _wspCenaJakosc);



};

//Koniec ParametryProgramu----------------------------------------------------------------//




#endif // PARAMETRY_HPP
