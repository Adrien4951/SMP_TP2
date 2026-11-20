#include "entierlong.h" //pour le type t_EntierLong
#include "lit_ecrit.h" //pour le type t_EntierLong
#include "utilitaires.h"
#include <iostream>
//#include <cmath>
using namespace std;
t_EntierLong Conversionstand_long(int n)
{
    char Nb[MAXCHIFFRES+1];
    t_EntierLong a;
    if (n < 0)
{
    a.negatif = true;
    n = -n;          
}
else
{
    a.negatif = false;
}

    for (int i = 0; i < MAXCHIFFRES; i++)
    {
        int diviseur = 1;
        for (int j = 0; j < 19-i; ++j) {
            diviseur *= 10;
        }

        if (n/diviseur < 0){
            n = -n;
        }
        a.chiffres[19-i] = n/diviseur;
         n -= ((n/diviseur)*diviseur);
    }
    
    return a;
    // fin
}

bool egalite(t_EntierLong n, t_EntierLong m){

    for (int i = 0; i < MAXCHIFFRES; i++)
    {
        if (n.chiffres[i] != m.chiffres[i])
        {
            return false;
        }
    }
    return true;
}
 t_EntierLong abs (t_EntierLong a, t_EntierLong b){
   a.negatif = false;
   b.negatif = false;
   for (int i = MAXCHIFFRES - 1; i >= 0; i--) {
       if (a.chiffres[i] != b.chiffres[i]) {
               if (a.chiffres[i] < b.chiffres[i]) {
                   cout << "A est plus petit que B" << endl;
                   return b;
                   break;
               } else {
                   cout << "A est plus grand que B" << endl;
                   return a;
                   break;
               }
           }
       }
       if(egalite(a, b)){
           cout << "A est égal à B" << endl;
           return a;
       }
       
   }


