#include <iostream>
#include <string.h>
using namespace std;

//strutture
struct Anagrafica{
	char nome[10];
	char cognome[10];
	char codicefiscale[16];
	char sesso;
	int cap;
	
};

//variabili globali
int L=50;
int totale_persone=0;
Anagrafica archivio[50];

//funzioni
void waitChar(){
    do{
        cout << "Premi invio per continuare...";
    } while (getchar()!='\n');
}

int menu(){
	system("clear");
	int selezione;
	cout << "-----------------Menu principale-------------------" << endl << endl;
	cout << "[1] Aggiungi persone" << endl;
	cout << "[2] Cerca una persona per cognome" << endl;
	cout << "[0] Esci dal programma" << endl;
	cout << "\t\tPersone presenti: " << totale_persone << endl;
	cout << "Selezione: ";
	cin >> selezione;
	return selezione;
}

void inserisci() {	
	bool exit=false;
	int i=totale_persone;
	string scelta;
	while(i<L && !exit){
		cout << "Persona numero: " << i+1 << endl;
		cout << "Inserisci nome: ";
		cin >> archivio[i].nome;
		cout << "Inserisci cognome: ";
		cin >> archivio[i].cognome;
		cout << "Inserisci sesso: ";
		cin >> archivio[i].sesso;
		cout << "Inserisci codice fiscale: ";
		cin >> archivio[i].codicefiscale;
		cout << "Inserisci cap: ";
		cin >> archivio[i].cap;
		cout << "Vuoi uscire? [Si/No]" << endl;
		cin >> scelta;
		i++;
		totale_persone++;
		if(scelta=="Si"){
			exit = true;
		}
	}	
}

void cerca(string cognome){
	bool trovata=false;
	for(int i=0; i<L; i++){
		if(archivio[i].cognome==cognome){
			cout << "Persona trovata! Numero persona: " << i+1 << endl << endl;
			cout << "Nome: " << archivio[i].nome << endl;
			cout << "Cognome: " << archivio[i].cognome << endl;
			cout << "Sesso: " << archivio[i].sesso << endl;
			cout << "Codice fiscale: " << archivio[i].codicefiscale << endl;
			cout << "Cap: " << archivio[i].cap << endl;
			trovata=true;
		}
	}
	
	if(!trovata){
		cout << "Persona non trovata :(" << endl;
	}
}	

//main function
int main(){
	int selezione;
	string cognome;
	
	do{
		selezione = menu();
		switch(selezione){
			case 1:
				system("clear");
				inserisci();
				waitChar();
				break;
			case 2:
				system("clear");
				cout << "Inserisci il cognome da cercare: ";
				cin >> cognome;
				cerca(cognome);
                waitChar();
				break;
			case 0:
				system("clear");
				break;
			default:
				cout << "Selezione non valida" << endl;
                waitChar();
				break;
		}
	} while (selezione!=0);
	
	cout << "PROGRAMMA TERMINATO!" << endl << endl << endl << endl << endl;

    waitChar();
	return 0;
}
