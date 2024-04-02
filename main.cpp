//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "Prajitura.h"
#include "Client.h"
#include "Vanzator.h"

int main() {
    std::ifstream f("praji.txt");
    Prajitura p;
    std::vector<Prajitura> prajituri;
    while(f>>p )
    {
        prajituri.push_back(p);
        std::cout<<p<<std::endl;
    }
    for(auto i:prajituri)
    {
        i.ContineCod(77);
        bool verif=i.GamaDeLux(30);
        std::cout<<verif<<std::endl;
        i.EsteVegan({"lapte","oua"});
        std::cout<<"-------------\n";
    }

    std::ifstream f2("clienti.txt");
    Client cl;
    std::vector<Client> clienti;
    while(f2>>cl)
    {
        clienti.push_back(cl);
    }
    for(auto i:clienti) {
        std::cout << i << std::endl;
    }
    for(auto i:clienti)
    {
        std::vector<Prajitura> prajituriCump = i.PrajituriCumparate(12);
        for (auto i: prajituriCump) {
            std::cout << "Nume:" << i.GetDenumire() << ", Pret:" << i.GetPret() << std::endl;
        }
        i.Achizitie("Amandina");
        i.NumeClient('P');
    }
    std::cout<<"---------\n";

    std:: ifstream f3("vanzator.txt");
    Vanzator vn;
    std::vector<Vanzator> vanzare;
    while(f3>>vn)
    {
        vanzare.push_back(vn);
    }
    for(auto i:vanzare)
    {
        std::cout<<i<<std::endl;
        i.VanzareMin(20);
        int profit;
        profit=i.Profit();
        std::cout<<profit<<"\n";
        i.ActualizeazaStoc();
        for (auto j:i.GetPrajiStoc())
        {
            std::cout<<j.GetDenumire()<<"\t"<<j.GetStoc()<<"\n";
        }
    }

    return 0;

}