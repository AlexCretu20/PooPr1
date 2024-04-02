#ifndef UNTITLED3_PRAJITURA_H
#define UNTITLED3_PRAJITURA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

class Prajitura {
private:
    int codBare;
    std::string denumire;
    int pret;
    int stoc;
    int nringrediente;
    std::vector<std::string> ingrediente;
public:
    //Constructor cu parametrii default
    Prajitura(int codBare_ =-1, std::string denumire_= "",  int pret_=-1, int stoc_=-1,int nringrediente_=-1,std::vector<std::string> ingrediente_=std::vector<std::string>())
    {
        this->codBare=codBare_;
        this->denumire=denumire_;
        this->ingrediente=ingrediente_;
        this->nringrediente=nringrediente_;
        this->pret=pret_;
        this->stoc=stoc_;

    }
    //Constructor de copiere
    Prajitura(const Prajitura& other)
    {
        this->codBare=other.codBare;
        this->denumire=other.denumire;
        this->pret=other.pret;
        this->stoc=other.stoc;
        this->ingrediente=other.ingrediente;
        this->nringrediente=other.nringrediente;
    }
    Prajitura& operator=( const Prajitura& other)
    {
        if(this==&other)
            return *this;
        this->codBare=other.codBare;
        this->denumire=other.denumire;
        this->pret=other.pret;
        this->ingrediente=other.ingrediente;
        this->stoc=other.stoc;
        this->nringrediente=other.nringrediente;
        return *this;

    }

    int GetPret(void) const
    {
        return pret;
    }
    int GetStoc(void) const
    {
        return stoc;
    }
    std::string GetDenumire(void) const // garanteaza ca nu o sa modifici atributele clasei
    {
        return denumire;
    }

    bool operator==( const Prajitura& other)
    {
        return codBare==other.codBare && denumire==other.denumire && pret==other.pret;
    }
    /*~Prajitura()
    {
        std::cout<<"~Prajitura\n";
    }*/

    friend std::ostream& operator <<(std::ostream& os, const Prajitura& p) ;
    friend std::istream& operator >>(std::istream& is, Prajitura& p);

    void ContineCod(const int cod);
    bool GamaDeLux(const int PretDeLux);
    void EsteVegan( const std::vector<std::string> ingrediente_fruct);
    int ScadeStoc(int StocNou);

private:
};


#endif //UNTITLED3_PRAJITURA_H
