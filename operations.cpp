//addition n1+n2 de deux entiers longs n1 et n2 de même signe;
#include "entierlong.h" //pour le type t_EntierLong
#include "lit_ecrit.h" //pour le type t_EntierLong
#include "utilitaires.h"
#include <iostream>
t_EntierLong addition(t_EntierLong n, t_EntierLong m){
t_EntierLong result;
 int retenue = 0;
    for (int i = 0; i < MAXCHIFFRES; i++)
    {
      
        if ((n.chiffres[i] + m.chiffres[i] + retenue) > 9)
        {
           
            result.chiffres[i] = (n.chiffres[i] + m.chiffres[i]+retenue) - 10;
            retenue = 1;
        }
        else
        {
            result.chiffres[i] = n.chiffres[i] + m.chiffres[i] + retenue;
            retenue = 0;
        }
        if (i == MAXCHIFFRES - 1 && retenue == 1)
        {
            result.erreur = true; // Indique que le résultat dépasse la capacité maximale
        }

    }
    //return true;
    return result;
}


t_EntierLong soustraction(t_EntierLong n, t_EntierLong m){
t_EntierLong result;
//t_EntierLong p = abs(n,m);
 int retenue = 0;
 if(egalite(abs(n,m),m)){
    result.erreur = true;
 }
    for (int i = 0; i < MAXCHIFFRES; i++)
    {
      
        if ((n.chiffres[i] - m.chiffres[i] - retenue) < 0)
        {
           
            result.chiffres[i] = (n.chiffres[i] - m.chiffres[i] - retenue) + 10;
            retenue = 1;
        }
        else
        {
            result.chiffres[i] = n.chiffres[i] - m.chiffres[i] - retenue;
            retenue = 0;
        }
        if (i == MAXCHIFFRES - 1 && retenue == 1)
        {
            result.erreur = true; // Indique que le résultat dépasse la capacité maximale
        }

    }
    //return true;
    return result;
}


t_EntierLong additionAvecSigne(t_EntierLong a, t_EntierLong b)
{
    t_EntierLong c;

    if (a.negatif == b.negatif)          // même signe
    {
        c = addition(a, b);
        c.negatif = a.negatif;
    }
    else if (egalite(a, b))              // a == b et signes opposés -> 0
    {
        c = Conversionstand_long(0);
    }
    else if (egalite(abs(a, b), a))      // a > b
    {
        c = soustraction(a, b);
        c.negatif = a.negatif;
    }
    else                                  // a < b
    {
        c = soustraction(b, a);
        c.negatif = b.negatif;
    }
    return c;
}

t_EntierLong soustractionAvecSigne(t_EntierLong a, t_EntierLong b)
{
    b.negatif = !b.negatif;              // a - b = a + (-b)
    return additionAvecSigne(a, b);
}