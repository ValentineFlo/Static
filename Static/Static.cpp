// Static.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

void IncrementStatic()
{
    static int a = 0; // déclarer qu'une seule fois donc compilateur ne remet pas a à 0
    a++;
    std::cout << a << std::endl;
} // a n'est pas détruite en dehors du scope

class Stat
{
public :
    Stat(int A/*, int B*/) : a(A)  /*   b(B){}  Error, il faut définir variable static a l'exterieur de la classe*/
    {
        this->IncrementB();
    }

    void displayAttribute() // on ne peut pas modifier la variable static mais on peut la lire
    {
        std::cout << "Valeur : " << a << " Nbr d'obj : " << b << std::endl;
    }

    static void IncrementB()
    {
        Stat::b++;

    }

private : 
    int a;
    static int b;
};

int Stat::b = 0;

int main()
{
    IncrementStatic();
    IncrementStatic();
    IncrementStatic();

    std::cout << std::endl;

    Stat stat1(10);
    stat1.displayAttribute();
    Stat stat2(1);
    stat2.displayAttribute();
    Stat stat3(5);
    stat3.displayAttribute();

    std::cout << "Hello World!\n";
}

