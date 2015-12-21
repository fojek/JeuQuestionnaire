#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

#include <wiringPi.h>

/* Boutons sont sur les GPIO 2, 3, 4 et 17 */
#define BOUTON_1 2  // Pin 3
#define BOUTON_2 3  // Pin 5
#define BOUTON_3 4  // Pin 7
#define BOUTON_4 17 // Pin 11

int exit_global;

PI_THREAD (WDT) {
	while(1) {
		if(exit_global == 1) {
		}
	}
}

int * attenteBouton(void) {
	exit_global = 1;
	int position = 0;
	int done[3];
	int resultat[3];
	
	do {
		/* Si un bouton est pressé .. */
		if (digitalRead(BOUTON_1) || digitalRead(BOUTON_2) || digitalRead(BOUTON_3) || digitalRead(BOUTON_4)) {
			/* Bouton 1 */
			if(digitalRead(BOUTON_1) {
				if (done[0] == 0) {
					resultat[position] = 1;
					done[0] = 1;
					++position;
				}
			}
			/* Bouton 2 */
			elseif (digitalRead(BOUTON_2) {
				if (done[1] == 0) {
					resultat[position] = 2;
					done[1] = 1;
					++position;
				}
			}
			/* Bouton 3 */
			elseif (digitalRead(BOUTON_3) {
				if (done[2] == 0) {
					resultat[position] = 3;
					done[2] = 1;
					++position;
				}
			}
			/* Bouton 4 */
			elseif (digitalRead(BOUTON_4) {
				if (done[3] == 0) {
					resultat[position] = 4;
					done[3] = 1;
					++position;
				}
			}
			else {
				/* oups. */
			}
		}
	} while ((position < 3) || exit_global);

	return * resultat;
}

int main (int argc, char *argv [])
{
	wiringPiSetup();
	
	/* Les boutons en tant qu'entrées */
	pinMode (BOUTON_1, INPUT);
	pinMode (BOUTON_2, INPUT);
	pinMode (BOUTON_3, INPUT);
	pinMode (BOUTON_4, INPUT);
	
	piThreadCreate (WDT);
	
	do {
		resultat = attenteBouton();
		printf("\nBoutons, dans l'ordre : %i, %i, %i et %i.\n", (&resultat)[0],(&resultat)[1],(&resultat)[2],(&resultat)[3]); 
	} while (1)
	
	return 0;
}

/*
	delay (1) ;    
	pinMode (0, OUTPUT);
    digitalWrite (100 + row, 0);
	delayMicroseconds(500);
	piThreadCreate (attenteBouton);
	delay (2000);
*/