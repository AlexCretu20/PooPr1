#include "Client.h"
std::ostream& operator <<(std::ostream& os, const Client& c) {
    os << "NrClient:" << c.NrClient << "\t" << "Nume:" << c.nume << "\t" << "Plata:" << c.plata << "\t"<<"Prajituri:";
    for(const auto i:c.prajituri)
    {
        os<<i.GetDenumire()<<",";
    }
    os<<"\n";
    return os;
}

std:: istream& operator >>(std::istream& is, Client& c)
{
    is>>c.NrClient>>c.nume>>c.plata>>c.nrpr;
    Prajitura praji;
    c.prajituri.clear();
    for(int i=0;i<c.nrpr;i++)
    {
        is>>praji;
        c.prajituri.push_back(praji);
    }
    return is;
}
std::vector<Prajitura>Client::  PrajituriCumparate(const int PretMin)
{
    std::vector<Prajitura> PrajiCumparate;
    for(auto it=prajituri.begin(); it!=prajituri.end(); it++)
    {
        const Prajitura &praji=*it;
        if(praji.GetPret()>=PretMin)
            PrajiCumparate.push_back(praji);
    }
    return PrajiCumparate;
}
void Client:: Achizitie(const std::string& NumPraji)
{
    for (auto it=prajituri.begin(); it!=prajituri.end();it++)
    {
        if(it->GetDenumire()==NumPraji) std::cout<<NrClient<<" "<<nume<<std::endl;
    }
}
void Client:: NumeClient (const char lit)
{
    if(nume[0]==lit)
    {
        for (auto i:prajituri)
        {
            std::cout<<i.GetDenumire()<<" ";
        }
    }
}
std::vector<Prajitura>Client:: GetPraji(void) const
{
    std::vector<Prajitura> prajiClient;
    for(auto i:prajituri)
    {
        prajiClient.push_back(i);
    }
    return prajiClient;
}
