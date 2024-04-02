#ifndef UNTITLED3_VANZATOR_H
#define UNTITLED3_VANZATOR_H
//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "Prajitura.h"
#include "Client.h"

class Vanzator{
private:
    int salariul;
    std::string nume;
    int nrcl;
    std::vector<Client> clienti;
    int nrpr;
    std::vector<Prajitura> prajistoc;
public:
    Vanzator(int salariul_=0,std::string nume_="",int nrcl_=-1, std::vector<Client> clienti_=std::vector<Client>(),int nrpr_=-1, std::vector<Prajitura> prajistoc_=std::vector<Prajitura>())
    {
        this->salariul=salariul_;
        this->nume=nume_;
        this->nrcl=nrcl_;
        this->clienti=clienti_;
        this->nrpr=nrpr_;
        this->prajistoc=prajistoc_;
    }
    Vanzator(const Vanzator& other)
    {
        this->salariul=other.salariul;
        this->nume=other.nume;
        this->nrcl=other.nrcl;
        this->clienti=other.clienti;
        this->nrpr=other.nrpr;
        this->prajistoc=other.prajistoc;
    }
    Vanzator& operator=(const Vanzator& other)
    {
        if (this == &other)
            return *this;
        this->salariul=other.salariul;
        this->nume=other.nume;
        this->nrcl=other.nrcl;
        this->clienti=other.clienti;
        this->nrpr=other.nrpr;
        this->prajistoc=other.prajistoc;
        return *this;
    }
    //~Vanzator();

    friend std::ostream& operator<<(std::ostream& os, const Vanzator& v);
    friend std::istream& operator>>(std::istream& is, Vanzator& v);

    std::vector<Prajitura> GetPrajiStoc(void) const;

    //Sa se afiseze clientii care achizitionat de minim p.
    void VanzareMin(int P);

    int Profit() ;
    void CompletareStoc( const Prajitura& prajiNou)
    {
        prajistoc.push_back(prajiNou);
    }
    //O functie care sa actualizeze stocul in functie de clienti
    void ActualizeazaStoc();

};

#endif //UNTITLED3_VANZATOR_H
