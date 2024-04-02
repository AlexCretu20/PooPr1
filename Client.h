#ifndef UNTITLED3_CLIENT_H
#define UNTITLED3_CLIENT_H
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "Prajitura.h"

class Client{
private:
    int NrClient;
    int plata;
    int nrpr;
    std::string nume;
    std::vector<Prajitura>prajituri; //Prajituri cumparate de clientul dat
public:
    Client(int NrClient_=-1, int plata_=-1, std::string nume_=" ", int nrpr_=-1, const std::vector<Prajitura>& prajituri_=std::vector<Prajitura>() )
    {
        this->NrClient=NrClient_;
        this->plata=plata_;
        this->nume=nume_;
        this->nrpr=nrpr_;
        this->prajituri=prajituri_;
    }
    Client(const Client& other)
    {
        this->NrClient=other.NrClient;
        this->plata=other.plata;
        this->nume=other.nume;
        this->nrpr=other.nrpr;
        this->prajituri=other.prajituri;
    }
    Client& operator=(const Client& other)
    {
        if(this==&other)
            return  *this;
        this->NrClient=other.NrClient;
        this->plata=other.plata;
        this->nume=other.nume;
        return *this;
    }
    friend std::ostream& operator <<(std::ostream& os, const Client& c) ;
    friend std::istream& operator >>(std::istream& is, Client& c);

    std::string GetNume() const
    {
        return nume;
    }

    int GetPlata() const
    {
        return plata;
    }

    //Functia afiseaza produsele vandute care au pretul mai mare decat pretul dat
    std::vector<Prajitura> PrajituriCumparate(const int PretMin);

    //Afiseaza numele si codul clientilor care au cumparat un anumit tip de prajitura
    void Achizitie(const std::string& NumPraji);

    //Sa se afiseze comanda clientilor a caror nume incepe cu lit data/numele
    void NumeClient (const char lit);

    std::vector<Prajitura> GetPraji(void) const;

private:
};

#endif //UNTITLED3_CLIENT_H
