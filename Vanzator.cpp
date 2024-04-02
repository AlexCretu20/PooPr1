#include "Vanzator.h"
std::ostream& operator<<(std::ostream& os, const Vanzator& v)
{
    os<<"Nume:"<<v.nume<<"\t"<<"Salariu:"<<v.salariul<<"\t"<<"Clienti:";
    for(auto i: v.clienti)
    {
        os<<i.GetNume()<<",";
    }
    os<<"\t"<<"Stoc:";

    for(auto i:v.prajistoc)
    {
        os<<i.GetDenumire()<<",";
    }
    os<<"\n";
    return os;
}
std:: istream& operator>>(std::istream& is, Vanzator& v)
{
    is>>v.salariul>>v.nume;
    is>>v.nrcl;
    v.clienti.clear();
    for(auto i=0;i<v.nrcl;i++)
    {
        Client cl;
        is>>cl;
        v.clienti.push_back(cl);
    }
    is>>v.nrpr;
    v.prajistoc.clear();
    for(int i=0;i<v.nrpr;i++)
    {
        Prajitura praji;
        is>>praji;
        v.prajistoc.push_back(praji);
    }
    return is;
}

std::vector<Prajitura>Vanzator:: GetPrajiStoc(void) const
{
    std::vector<Prajitura> prajiClient;
    for(auto i:prajistoc)
    {
        prajiClient.push_back(i);
    }
    return prajiClient;
}
void Vanzator:: VanzareMin(int P)
{
    for(auto i: clienti)
    {
        if(i.GetPlata()>P) std::cout<<i.GetNume()<<",";
    }
}

int Vanzator:: Profit() {
    int pr = 0;
    for (auto i: clienti) {
        pr = pr + i.GetPlata();
    }
    return pr;
}

void Vanzator:: ActualizeazaStoc()
{
    for(auto i: clienti)
    {
        std::vector<Prajitura> prajiClient=i.GetPraji();
        for (auto j:prajiClient)
        {
            for(auto k:prajistoc)
            {
                if(j.GetDenumire()==k.GetDenumire()) j.ScadeStoc(k.GetStoc());
            }
        }
    }
}
