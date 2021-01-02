/**
 * Conways Game of life (Windows) 2 Cells 
 * @author Jorge Luis Villanueva Gamboa
 * @date November 16, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TAM 30 //Board lenght
#define VIVA 2 //Cell no.1
#define MUERTA 0 //Dead cells

int gen=0;
int pob=0;
int spob=0;
void inicializa_tablero();
void despliega_tablero();
void generacion();
int nvecinos(int i, int j);
int snvecinos(int o,int k);
int tablero[TAM][TAM];



int main(int argc, char *argv[]) {
	
	char opc=0;
	inicializa_tablero();
	while(opc!=27){
	despliega_tablero();
	generacion();
	opc=getch();
	gen+=1;
	
	}
	return 0;
}

void inicializa_tablero(){
	srand (time(NULL));
	int Fil, Col;
	for (Fil=0;Fil<TAM;Fil++){
		for (Col=0;Col<TAM;Col++){
			tablero[Fil][Col]=rand()%3;
			
		}
	}
}

void despliega_tablero(){
	int Fil, Col;
	system("cls");
	printf("Welcome To Conway's Game Of Life 2 Cells\n\n");
	for (Fil=0;Fil<TAM;Fil++){
		for (Col=0;Col<TAM;Col++){
			//Generates the 1st type of cells
			if (tablero[Fil][Col]==VIVA){
			printf ("\033[0;31m %c ",2);
			printf ("\033[0m");
			//Cells Counter
			pob++; 	
			}

			//Generates the 2nd type of cells
			if(tablero[Fil][Col]==1){
				printf (" %c ",2);
			//Cells Counter
			spob++;
			}

			//Genterates Dead Cells 
			if(tablero[Fil][Col]==0){
				printf ("\033[0;34m %c",32 );
				printf ("\033[0m");
			}
		}
	printf ("\n");
	}
	printf("\nPress a key to continue, <esc> to stop...");	
	printf("\nGeneration: %d",gen);
	printf("\n\033[0;31mPopulation %c: %d",2,pob);
	printf ("\033[0m");
	printf("\nPopulation %c: %d",2,spob);
	
	pob=0;
	spob=0;
}

void generacion(){
	int Fil,Col,nvec=0,snvec=0;;
	int ntablero[TAM][TAM];

	for (Fil=0;Fil<TAM;Fil++){
		for (Col=0;Col<TAM;Col++){
			ntablero[Fil][Col]=MUERTA;
			nvec = nvecinos(Fil,Col); //Gets neighbors Count
			snvec = snvecinos(Fil,Col);//Gets neighbors Count
			//Rules 1st Cells
			if (tablero[Fil][Col]==VIVA && (nvec==2 || nvec==3)){
				ntablero[Fil][Col]=VIVA;
				
			}
			if (tablero[Fil][Col]==MUERTA && nvec==3){
				ntablero[Fil][Col]=VIVA;
				
			}
			//Rules 2nd Cells
			if (tablero[Fil][Col]==1 && (snvec==2 || snvec==3)){
				ntablero[Fil][Col]=1;
				
			}
			if (tablero[Fil][Col]==0 && snvec==3){
				ntablero[Fil][Col]=1;
				
			}
		}
	}	
	for (Fil=0;Fil<TAM;Fil++){
		for (Col=0;Col<TAM;Col++){
			tablero [Fil][Col] = ntablero[Fil][Col];
		}
	}
}


int nvecinos(int i, int j){
	int Fil, Col, n=0;
	for (Fil=i-1;Fil<=i+1;Fil++){
		for (Col=j-1;Col<=j+1;Col++){
			if (!(Fil==i && Col==j) && Fil >= 0 && Fil < TAM && Col >= 0 && Col < TAM){
				if(tablero[Fil][Col]==VIVA){
					n++;
				}
				
				
			}
				
			}
		}
	
	
	return n;
}
	
	int snvecinos(int o, int k){
		int Fil, Col, n=0;
		for (Fil=o-1;Fil<=o+1;Fil++){
			for (Col=k-1;Col<=k+1;Col++){
				if (!(Fil==o && Col==k) && Fil >= 0 && Fil < TAM && Col >= 0 && Col < TAM){
					if(tablero[Fil][Col]==1){
						n++;
					}
					
					
				}
				
			}
		}
		
		
		return n;
	}
	

	

