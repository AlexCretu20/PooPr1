#include "Prajitura.h"
std::ostream& operator <<(std::ostream& os, const Prajitura& p ) {
    os << "CodBare:" << p.codBare << "\t" << "Denumire:" << p.denumire << "\t" << "Pret:" << p.pret<< "\t"<<"Stoc:"<<p.stoc<<"\t"<<"Ingrediente:";
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
    is>>p.stoc;
    is>>p.nringrediente;
    p.ingrediente.clear(); // ca sa nu imi suprascrie ingredientele
    for (auto it =0; it < p.nringrediente; it++)
    {
        std::string ingredient;
        is >> ingredient;
        p.ingrediente.push_back(ingredient);
    }
    return is;
}
bool Prajitura:: GamaDeLux(const int PretDeLux)
{
    if(pret>=PretDeLux) return true;
    else return false;
}

void Prajitura:: ContineCod(const int cod)
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

void Prajitura:: EsteVegan( const std::vector<std::string> ingrediente_fruct)
{
    int ok=1;
    for (auto i:ingrediente )
    {
        for( auto j:ingrediente_fruct)
            if(i==j) ok=0;
    }
    if (ok==1) std::cout<<"Este vegan"<<std::endl;
    else std::cout<<"Nu este vegan"<<std::endl;
}

int Prajitura:: ScadeStoc(int StocNou)
{
    stoc=stoc-StocNou;
    return stoc;
}