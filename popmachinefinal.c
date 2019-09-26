#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define prc_max 250 
#define prc_min 30
#define nickle 5
#define dime 10
#define quater 25
#define INPUT_MUTIPLE 5 

int dimechange(int i) {
	int result;
	result = i/dime;
	return result;
}
int nicklechange(int i) {
	int result;
	result =(i%dime)/nickle;
	return result;
}

int  main(int argc, char *argv[])
{
	int i=0, pop=0, d, n;
	char p;
		
	if (argc==2) {/*take in arguments from command line*/
	
		pop = atoi (argv[1]); /*check for valid input*/
		
		if(pop>=prc_min&&pop<=prc_max) {/*Check argument is within range*/
		
			if(pop%INPUT_MUTIPLE!=0) {/*Checks argument is in required multiple of user*/

				printf("\n\tPrice must be a multiple of %d \n", INPUT_MUTIPLE);
				return(0);

			} else {/*program introduction*/

				printf("\nWelcome to my C pop machine!\nPop is %d cents\n", pop);
				printf("Please insert any combination of:");
				printf("\n\n  nickels [N or n]\n"); 
				printf("  dimes [D or d]\n  quarters [Q or q]");
				printf("\nYou can also press 'r' or 'R' for coin return\n");
				printf("Or you can press 'e' or 'E' to exit");
			}
		} else if(pop<prc_min||pop>prc_max) {

			printf("\n\tPrice must be between 30 cents to 105 cents\n");
			return(0);
		}
	} else {

		printf("\n\tPlease specify selling price as command argument\n");
		return(0);
	}

	while(i<pop) {/*loop to keep program running until correct amount of money is entered*/
	
		printf("\nEnter coin (NDQR):");
		scanf(" %c",&p);
	
		if(p=='n'||p=='N') {
	
			i=i+nickle;
			printf("\n\tNickel detected\n\tYou have inserted a total of %d cents\n", i);
			if(i<pop) {
				printf("\tPlease insert %d more cents\n", pop-i);
			}
		
		} else if(p=='d'||p=='D') {
	
			i=i+dime;
			printf("\n\tDime detected\n\tYou have inserted a total of %d cents\n", i);
			if(i<pop) {
				printf("\tPlease insert %d more cents\n", pop-i);

			}
	
	
		} else if(p=='q'||p=='Q') {
	
			i=i+quater;
			printf("\n\tQuarter detected\n\tYou have inserted a total of %d cents\n", i);
			if(i<pop) {
				printf("\tPlease insert %d more cents\n", pop-i);
			}
	
		} else if(p=='r'||p=='R') {
	
			d = dimechange(i);
			n = nicklechange(i);
			printf("\n\tChange given: %d cents as %d dime(s) and %d nickel(s)", i, d, n);
			i=0;
	
		} else if(p=='e'||p=='E') {
		
			d = dimechange (i);
			n = nicklechange(i);
			printf("\n\tChange given: %d cents as %d dime(s) and %d nickel(s)", i, d, n);
			printf("\nShutting down\nGoodbye\n");
			return(0);
	
		} else {
			printf("\n\tPlease enter a valid coin\n");
		}
	
		if (i>=pop) {/*when correct amount is exceeded*/
		
			d=(i-pop)/dime;
			n=((i-pop)%dime)/nickle;
			printf("\n\n\tYou have inserted %d cents\n\tPop is dispensed\n\tThank you for your business!\n\tPlease come again\n", i);
			printf("\tChange given: %d cents as %d dime(s) and %d nickel(s)\n", i-pop, d, n);
			i=0;
		}
	}

}


