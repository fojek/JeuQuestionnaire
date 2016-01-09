#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <wiringPi.h>
#include "global.h"

/* Boutons sont sur les GPIO 2, 3, 4 et 17 */
#define BOUTON_1 0 // Pin 11
#define BOUTON_2 1 // Pin 12
#define BOUTON_3 2 // Pin 13
#define BOUTON_4 3 // Pin 15
#define BUZZER   4 // Pin 16

int exit_global;
int test;
int resultat[4]={0,0,0,0};

/* Mesure d'urgence au cas ou */
PI_THREAD (WDT) {
	
	int first_pass = 0;
	int position = 0;
	int done[4] = {0,0,0,0};
	
	while(1) {
		
		if (first_pass == 0) {
			position = 0;
			done[0] = 0;
			done[1] = 0;
			done[2] = 0;
			done[3] = 0;
			resultat[0] = 0;
			resultat[1] = 0;
			resultat[2] = 0;
			resultat[3] = 0;
			
			first_pass = 1;
		}
		
		do {
			/* Si un bouton est appuyé .. */
			if (digitalRead(BOUTON_1) || digitalRead(BOUTON_2) || digitalRead(BOUTON_3) || digitalRead(BOUTON_4)) {

                digitalWrite(BUZZER, 1);
				/* Bouton 1 */
				if(digitalRead(BOUTON_1)) {	

					if (done[0] == 0) {
						printf("\nPese 1...");
						resultat[position] = 1;
						done[0] = 1;
						++position;
					}
				}
				/* Bouton 2 */
				else if (digitalRead(BOUTON_2)) {

					if (done[1] == 0) {
						printf("\nPese 2...");
						resultat[position] = 2;
						done[1] = 1;
						++position;
					}
				}
				/* Bouton 3 */
				else if (digitalRead(BOUTON_3)) {

					if (done[2] == 0) {
						printf("\nPese 3...");
						resultat[position] = 3;
						done[2] = 1;
						++position;
					}
				}
				/* Bouton 4 */
				else if (digitalRead(BOUTON_4)) {

					if (done[3] == 0) {
						printf("\nPese 4...");	
						resultat[position] = 4;
						done[3] = 1;
						++position;
					}
				}
				else {
					/* oups. */
				}
                delayMicroseconds(600);
                digitalWrite(BUZZER, 0);
                delayMicroseconds(600);
			}
		} while (exit_global==1);
		
		exit_global = 0;
		first_pass = 0;
	}
}

/* Routine d'attente des participants
void  attenteBouton(void) {
	exit_global = 1;

}


PI_THREAD (Request) {
    do {
        attenteBouton();
        printf("\nBoutons, dans l'ordre : %i, %i, %i et %i.\n", resultat[0], resultat[1], resultat[2], resultat[3]);
        printf("\nBoutons : %i, %i, %i et %i.\n", digitalRead(BOUTON_1), digitalRead(BOUTON_2), digitalRead(BOUTON_3), digitalRead(BOUTON_4));
    } while (1);
}
*/

/*
	delay (1) ;    
	pinMode (0, OUTPUT);
    digitalWrite (100 + row, 0);
	delayMicroseconds(500);
	piThreadCreate (attenteBouton);
	delay (2000);
*/
