#include <iostream>
using namespace std;

#include "entierlong.h"
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"

int main()
{
    int choix = -1;
    t_EntierLong a, b, c;

    while (choix != 0)
    {
        cout << endl;
        cout << "Fonction :" << endl;
        cout << "1. Addition (a + b)" << endl;
        cout << "2. Soustraction (a - b)" << endl;
        cout << "3. Egalite (a == b ?)" << endl;
        cout << "4. Plus grand en valeur absolue (abs)" << endl;
        cout << "5. Conversion int -> entier long" << endl;
        cout << "6. addition avec signe" << endl;
        cout << "7. soustraction avec signe" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix)
        {
        case 1:
            cout << "a = "; 
            a = litEntierLong();
            cout << "b = "; 
            b = litEntierLong();
            c = addition(a, b);
            if (c.erreur) cout << "Erreur : depassement de capacite" << endl;
            cout << "a + b = "; afficheEntierLong(c);
            break;

        case 2:
            cout << "a = "; a = litEntierLong();
            cout << "b = "; b = litEntierLong();
            c = soustraction(a, b);
            if (c.erreur) cout << "Erreur dans la soustraction" << endl;
            cout << "a - b = "; afficheEntierLong(c);
            break;

        case 3:
            cout << "a = "; a = litEntierLong();
            cout << "b = "; b = litEntierLong();
            if (egalite(a, b)) cout << "a et b sont egaux" << endl;
            else               cout << "a et b sont differents" << endl;
            break;

        case 4:
            cout << "a = "; a = litEntierLong();
            cout << "b = "; b = litEntierLong();
            c = abs(a, b);
            cout << "Le plus grand = "; afficheEntierLong(c);
            break;

        case 5:
        {
            int n;
            cout << "n (int) = "; cin >> n;
            c = Conversionstand_long(n);
            cout << "En entier long : "; afficheEntierLong(c);
            break;
        }
        case 6:
            cout << "a = "; a = litEntierLong();
            cout << "b = "; b = litEntierLong();
            c = additionAvecSigne(a, b);
            if (c.erreur) cout << "Erreur : depassement de capacite" << endl;
            cout << "a + b avec signe = "; afficheEntierLong(c);
            break;
        case 7:
            cout << "a = "; a = litEntierLong();
            cout << "b = "; b = litEntierLong();
            c = soustractionAvecSigne(a, b);
            if (c.erreur) cout << "Erreur : depassement de capacite" << endl;
            cout << "a - b avec signe = "; afficheEntierLong(c);
            break;

        default:
            cout << "Choix invalide" << endl;
        }
    }

    return 0;
}
