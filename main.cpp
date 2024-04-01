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
    std::vector<std::string> ingrediente;
public:
    //Constructor cu parametrii default
    Prajitura(int codBare_ =-1, std::string denumire_= "",  int pret_=-1,std::vector<std::string> ingrediente_=std::vector<std::string>())
    {
        this->codBare=codBare_;
        this->denumire=denumire_;
        this->ingrediente=ingrediente_;
        this->pret=pret_;

    }
    //Constructor de copiere
    Prajitura(const Prajitura& other)
    {
        this->codBare=other.codBare;
        this->denumire=other.denumire;
        this->pret=other.pret;
        this->ingrediente=other.ingrediente;
    }
    Prajitura& operator=( const Prajitura& other)
    {
        if(this==&other)
            return *this;
        this->codBare=other.codBare;
        this->denumire=other.denumire;
        this->pret=other.pret;
        this->ingrediente=other.ingrediente;
        return *this;

    }

    friend std::ostream& operator <<(std::ostream& os, const Prajitura& p) ;
    friend std::istream& operator >>(std::istream& is, Prajitura& p);

    void ContineCod(const int cod)
    {
        int cifre=1, copie=cod, ok=0;
        while(copie!=0)
        {
            cifre=cifre*10;
            copie=copie/10;
        }
        while( codBare>=cod)
        {
            if( codBare%cifre==cod)
            {
                ok=1;
                break;
            }
            codBare=codBare/10;
        }
        if (ok==1) std::cout<<"Da\n";
        else std::cout<<"Nu\n";

    }
    bool GamaDeLux(const int PretDeLux)
    {
        if(pret>=PretDeLux) return true;
        else return false;
    }
    int GetPret(void) const
    {
        return pret;
    }

    /*void EsteVegan( const std::string& ingrediente_fruct)
    {
        int ok=1;
        for (auto it=ingrediente.begin();it!=ingrediente.end();it++ )
        {
            for( auto it2=ingrediente_fruct.begin(); it2!=ingrediente_fruct.end(); it2++)
                if(*it == *it2) ok=0;
        }
        if (ok==1) std::cout<<"Este vegan";
        else std::cout<<"Nu este vegan";
    }*/

   /* ~Prajitura()
    {
        std::cout<<"~Prajitura\n";
    }*/
private:
};
std::ostream& operator <<(std::ostream& os, const Prajitura& p ) {
    os << "CodBare:" << p.codBare << "\t" << "Denumire:" << p.denumire << "\t" << "Pret:" << p.pret << "\t";
    for (auto it = p.ingrediente.begin(); it != p.ingrediente.end(); it++)
    {
        const std::string ingredient = *it;
        os << ingredient<<" ";
    }
    return os;
}

std:: istream& operator >>(std::istream& is, Prajitura& p)
{
    is>>p.codBare;
    is>>p.denumire;
    is>>p.pret;
    for (auto it = p.ingrediente.begin(); it != p.ingrediente.end(); it++)
    {
        is>>*it;
    }
    return is;
}

class Client{
private:
    int NrClient;
    int plata;
    std::string nume;
    std::list<Prajitura>prajituri; //Prajituri cumparate de clientul dat
public:
    Client(int NrClient_=-1, int plata_=-1, std::string nume_="", std::list<Prajitura> prajituri=[] )
    {
        this->NrClient=NrClient_;
        this->plata=plata_;
        this->nume=nume_;
    }

    explicit Client(const std::list<Prajitura> &prajituri);

    Client(const Client& other)
    {
        this->NrClient=other.NrClient;
        this->plata=other.plata;
        this->nume=other.nume;
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

    //Functia afiseaza produsele vandute care au pretul mai mare decat pretul dat
    std::vector<Prajitura> GetPrajituriVandute(const int PretMin)
    {
        std::vector<Prajitura> PrajiVandute;
        for(auto it=prajituri.begin(); it!=prajituri.end(); it++)
        {
            const Prajitura &praji=*it;
            if(praji.GetPret()>=PretMin)
                PrajiVandute.push_back(praji);
        }
        return PrajiVandute;

    }
    //Afiseaza numele si codul clientilor care au cumparat un anumit tip de prajitura
    void Achizitie(const std::string& NumPraji)
    {
        for (auto it=prajituri.begin(); it!=prajituri.end();it++)
        {
            if(it->denumire==NumPraji) std::cout<<NrClient<<" "<<nume<<std::endl;
        }
    }
    //Sa se afiseze comanda clientilor a caror nume incepe cu lit data/numele
    void GetNume(const char* lit)
    {
        if(nume[0]==lit) std::cout<<prajituri<<std::endl;
    }
private:
};

std::ostream& operator <<(std::ostream& os, const Client& c) {
    os << "NrClient:" << c.NrClient << "\t" << "Nume:" << c.nume << "\t" << "Plata:" << c.plata << "\t";
    return os;
}

std:: istream& operator >>(std::istream& is, Client& c)
{
    is>>c.NrClient;
    is>>c.nume;
    is>>c.plata;
    return is;
}

class Vanzator{
private:
    std::string nume;
    std::list<Client> clienti;
    std::list<Prajitura> prajistoc;
public:
    Vanzator(std::string nume_="", std::lists<Client> clienti_=[], std::lists<Prajitura> prajistoc_=[])
    {
       this->nume=nume_;
       this->clienti=clienti_;
       this->prajistoc=prajistoc_;
    }
    Vanzator(const Vanzator& other)
    {
        this->nume=other.nume;
        this->clienti=other.clienti;
        this->prajistoc=other.prajistoc;
    }
    Vanzator& operator=(const Vanzator& other)
    {
        if (this == &other)
            return *this;
        this->nume=other.nume;
        this->clienti=other.clienti;
        this->prajistoc=other.prajistoc;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vanzator& v)
    friend std::istream& operator>>(std::ostream& is, Vanzator& v)


};


int main()
{
    Prajitura prajitura1(12345,"Bannabread", 20,{"faina", "oua","banane"});
    std:: cout<<prajitura1<<std::endl;
    prajitura1.ContineCod(17);
    bool verif=prajitura1.GamaDeLux(15);
    std::cout<<verif<<std::endl;
    //lprajitura1.EsteVegan({"lapte","oua"})

}