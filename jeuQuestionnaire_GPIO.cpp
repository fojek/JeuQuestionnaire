#include <stdio.h>
#include <iostream>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <wiringPi.h>
#include "global.h"
using namespace std;

// Constantes globales
// Boutons sont sur les GPIO 17, 18, 27, 22, 24 et 23
const int NB_BOUTONS = 4;
const int BOUTON[NB_BOUTONS] = {0,1,2,3}; // Ajouter les # de pin au besoin
const int BUZZER = 4;   // Pin 16 (GPIO 23)


// variables globales
int exitGlobal=1;
int test;
int resultat[NB_BOUTONS]={0,0,0,0};

// Thread d'acquisition des actions
PI_THREAD (WDT)
{
    int position;   // Variable qui contient la position ouverte (1,2,3,4...)
    int firstPass = 0;
    int done[NB_BOUTONS] = {0,0,0,0};
	
    // Jusqu'a la mort de l'application
    while(true)
    {
		
        // Suite a une reinitialisation, ou au premier cycle...
        if (firstPass == 0)
        {

            // Reinitialisation des variables
			position = 0;
            for(int i=0; i<NB_BOUTONS; ++i)
            {
                done[i] = 0;
                resultat[i] = 0;
            }
			
            // Flag
            firstPass = 1;
		}
		
        do
        {
            // Variables
            int boutonEstVrai[NB_BOUTONS] = {0,0,0,0};
            int auMoinsUnBouton = 0;

            // Si un bouton est appuyé ..
            for(int i=0; i<NB_BOUTONS; ++i)
            {
                boutonEstVrai[i] = digitalRead(BOUTON[i]);
                if(boutonEstVrai[i]) auMoinsUnBouton = 1;
            }

            if (auMoinsUnBouton)
            {
                for(int i=0; i<NB_BOUTONS; ++i)
                {
                    // Verifie l'etat des boutons
                    if(boutonEstVrai[i] && (done[i] == 0)) {
                        cout << "\nPese " << i << "...";
                        resultat[position] = i+1;
                        done[i] = 1;
                        ++position;
                    }
                }

                // Delai pour produire un son interessant avec le buzzer
                digitalWrite(BUZZER, 1);
                delayMicroseconds(600);
                digitalWrite(BUZZER, 0);
                delayMicroseconds(600);
			}

        // On attend la commande de sortie
        } while (exitGlobal==1);
		
        exitGlobal = 0;
        firstPass = 0;
	}
}
