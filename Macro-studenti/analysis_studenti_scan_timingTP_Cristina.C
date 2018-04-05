 /* Analisi dei file di dati
    
	autore: Cristina Sauda - cristina.sauda@edu.unito.it
	data creazione:  2018/02/15
	ultima modifica: 2018/02/28
	
	per eseguire:
	 + caricare la macro in root con il comando .L analysis_studenti_scan_timingTP_Cristina.C
		(Prima essere sicuridi avere nella stessa cartella le macro Macro_scurve.C analisi_histo_1d_Cristina.C Macro_scurve_Vth.C)
	 + eseguire l'analisi del file con il comando Analysis(numero che identifica il file che si vuole analizzare) [scrivere -1 per l'analisi complessiva] e seguire le indicazioni che seguiranno passo passo
	 
 */

#include "Riostream.h"
#include "TAxis.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TMath.h"
#include "TMultiGraph.h"
#include "TString.h"
#include "TStyle.h" 
#include<vector>

#include "Macro_scurve.C"
#include "analisi_histo_1d_Cristina.C"
//#include "Macro_scurve_Vth.C"

// ~~~~~~~~~~~~~~~~~~~ Dichiarazioni ~~~~~~~~~~~~~~~~~~~
void Analysis(int i); //funzione principale, aggiungere casi allo switch se si aggiungono dati da analizzare

//tutte le funzioni TwoDim_Plots_ecc sono funzioni che permettono di analizzare i dati; ognuna di loro analizza dati presi in condizioni diverse (che vengono riassunte nel nome della funzione)

void TwoDim_Plots_40M_timing_Board8(int i, TString percorso, int tipo, int min, int max); //funzione per misure standard a 40 MHz facendo variare la carica in ingresso sulla board8
void TwoDim_Plots_40M_timing_Vth_Board8(int i, TString percorso, int tipo, int min, int max); //funzione per misure standard a 40 MHz facendo variare la tensione del discriminatore board8

void TwoDim_Plots_40M_timing_Vth_Board9(int i, TString percorso, int tipo, int min, int max); //funzione per misure standard a 40 MHz facendo variare la tensione del discriminatore board9
void TwoDim_Plots_40M_timing_Vth_Ifeed150_Board9(int i, TString percorso, int tipo, int min, int max); //funzione per dati presi con corrente feedback 150 DAC
void TwoDim_Plots_40M_timing_Vth_VCal110_Board9(int i, TString percorso, int tipo, int min, int max);

void grafico_Vth(TString percorso, int dimensione, float TPPhase[], float errTPPhase[], float mediath[], float errmediath[]); //funzione che permette di disegnare il grafico

void TwoDim_Plots_40M_timing_Vth_Board101_TO2A(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_timing_Cal_Board101_TO2A(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_timing_Cal70_Board101_TO2A(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_timing_Vth_Board101_TO2AP(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2(int i, TString percorso, int tipo, int min, int max);

void TwoDim_Plots_40M_timing_Vth_Board102_TO2A(int i, TString percorso, int tipo, int min, int max);

void TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A(int i, TString percorso, int tipo, int min, int max);

void TwoDim_Plots_40M_timing_Vth_Board8_1257(int i, TString percorso, int tipo, int min, int max);
// ~~~~~~~~~~~~~~~~~~ Implementazioni ~~~~~~~~~~~~~~~~~~
// -----------------------------------------------------
// ---------------- Funzione principale ----------------
// -----------------------------------------------------
void Analysis(int i){
  TString so;
  TString Dir0;
  TString Dir;
  int funzione;
  int tipo;
  int min = 1024;
  int max = 2048;
  
  cout << "Inserire un carattere per selezionare la cartella principale da cui prendere i file:\n";
  cout << "- l per ubuntu sul computer di Cristina\n";
  cout << "- w per windows sul computer CHIPIX65\n";
  cout << "- c per i dati del CERN\n";
  cin >> so;

	if(so == "l"){
    Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/"; 
  }
  else if(so == "w"){
    Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/";
  } 
  else if(so == "c"){
    Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
  }

	cout << "\nScegliere la funzione da usare:\n";
	cout << "- 0 per TwoDim_Plots_40M_timing_Board8\n";
	cout << "- 1 per TwoDim_Plots_40M_timing_Vth_Board8\n";
	cout << "- 2 per TwoDim_Plots_40M_timing_Vth_Board9\n";
	cout << "- 3 per TwoDim_Plots_40M_timing_Vth_Ifedd150_Board9\n";
	cout << "- 4 per TwoDim_Plots_40M_timing_Vth_VCal110_Board9\n";
	cout << "- 5 per TwoDim_Plots_40M_timing_Vth_Board101\n";
	cout << "- 6 per TwoDim_Plots_40M_timing_Cal_Board101\n";
	cout << "- 7 per TwoDim_Plots_40M_timing_Cal70_Board101\n";
	cout << "- 8 per TwoDim_Plots_40M_timing_Vth_Board101_TO2AP\n";
	cout << "- 9 per TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2\n";
	cout << "- 10 per TwoDim_Plots_40M_timing_Vth_Board102_TO2A\n";
	cout << "- 11 per TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A\n";
	
	cin >> funzione;

	switch(funzione){ //switch che permette di scegliere i dati da analizzare
		case 0:{
			Dir = Dir0 + "Board8_revisione/TPphase-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Board8(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Board8(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Board8(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Board8(i, Dir, tipo, min, min);
			}
		} break;

		case 1: {
			Dir = Dir0 + "Board8_revisione/VTH-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board8(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board8(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board8(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board8(i, Dir, tipo, min, min);
			}
		}break;
		
		case 2: {
			Dir = Dir0 + "Board9/VTH-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board9(i, Dir, tipo, min, min);
			}
		}break;
		
		case 3: {
			Dir = Dir0 + "Board9/VTH-Ifeed150/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Ifeed150_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Ifeed150_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Ifeed150_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Ifeed150_Board9(i, Dir, tipo, min, min);
			}
		}break;
		
		case 4: {
			Dir = Dir0 + "Board9/VCal100/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_VCal110_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_VCal110_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_VCal110_Board9(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_VCal110_Board9(i, Dir, tipo, min, min);
			}
		}break;
		
		case 5: {
			Dir = Dir0 + "Board101/VTH-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A(i, Dir, tipo, min, min);
			}
		}break;
		
		case 6: {
			Dir = Dir0 + "Board101/CAL-scan/TO2A/Vth60/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Cal_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Cal_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Cal_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Cal_Board101_TO2A(i, Dir, tipo, min, min);
			}
		}break;
		
		case 7: {
			Dir = Dir0 + "Board101/CAL-scan/TO2A/Vth70/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Cal70_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Cal70_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Cal70_Board101_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Cal70_Board101_TO2A(i, Dir, tipo, min, min);
			}
		}break;
		
		case 8: {
			Dir = Dir0 + "Board101/VTH-scan/TO2AP/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board101_TO2AP(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2AP(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2AP(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2AP(i, Dir, tipo, min, min);
			}
		}break;
		
		case 9: {
			Dir = Dir0 + "Board101/VTH-scan/TO2Amod/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2(i, Dir, tipo, min, min);
			}
		}break;
		
		case 10: {
			Dir = Dir0 + "Board102/VTH-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board102_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board102_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board102_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board102_TO2A(i, Dir, tipo, min, min);
			}
		}break;
		
		case 11: {
			Dir = Dir0 + "Board103/VTH-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A(i, Dir, tipo, min, min);
			}
		}break;
		
		case 12:{
			Dir = Dir0 + "Board8_revisione/1257/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth_Board8_1257(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board8_1257(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth_Board8_1257(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth_Board8_1257(i, Dir, tipo, min, min);
			}
		} break;
		
		default: {
			cout << "Inizializzazione sbagliata\n";
			return;
		}break;
	}
}


// -----------------------------------------------------
// ----------------- Funzioni per dati -----------------
// -----------------------------------------------------

// ~~~~~~~~~~~~~~ 0 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Board8(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
  
  int nfile = 0;
  
  TString file[] = {"CALsweep9.",
			  "20170601004206_board8-CALsw-allch-TP200_001.", 
		      "20170531191742_board8-CALsw-allch-TP400_000.", 
		      "20170531194049_board8-CALsw-allch-TP600_000.", 
		      "20170531200358_board8-CALsw-allch-TP800_000.", 
		      "20170531202711_board8-CALsw-allch-TP1000_000.", 
		      "20170601023819_board8-CALsw-allch-TP1200_001.", 
		      "20170531211343_board8-CALsw-allch-TP1400_000.",
		      "20170531213700_board8-CALsw-allch-TP1600_000.",
		      "20170531220020_board8-CALsw-allch-TP1800_000.",
		      "20170531222337_board8-CALsw-allch-TP2000_000.",
		      "20170531224649_board8-CALsw-allch-TP2200_000.",
		      "20170531231001_board8-CALsw-allch-TP2400_000.",
		      "20170531233312_board8-CALsw-allch-TP2600_000.",
		      "20170531235613_board8-CALsw-allch-TP2800_000.",
		      "20170601001908_board8-CALsw-allch-TP3000_000.",
		      "20170706095228_board8-CALsw-allch-TP3200_002.",
		      "20170706111354_board8-CALsw-allch-TP3400_004.",
		      "20170706112546_board8-CALsw-allch-TP3600_004."};
	
	int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 35, 20, 60., 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 35, 20, 60., 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	//grafico(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 1 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board8(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 45.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {/*"VTH_VCal110_000.",*/
	  "20180216024043_board8-VTHsw-allch-TP0_002.",
		      "20180215221204_board8-VTHsw-allch-TP200_001.", 
		      "20180215222655_board8-VTHsw-allch-TP400_001.", 
		      "20180215224146_board8-VTHsw-allch-TP600_001.", 
		      "20180215225644_board8-VTHsw-allch-TP800_001.", 
		      "20180215231140_board8-VTHsw-allch-TP1000_001.", 
		      "20180215232641_board8-VTHsw-allch-TP1200_001.",
		      "20180215234143_board8-VTHsw-allch-TP1400_001.",
		      "20180215235644_board8-VTHsw-allch-TP1600_001.",
		      "20180216001147_board8-VTHsw-allch-TP1800_001.",
		      "20180216002647_board8-VTHsw-allch-TP2000_001.",
		      "20180216004144_board8-VTHsw-allch-TP2200_001.",
		      "20180216005633_board8-VTHsw-allch-TP2400_001.",
		      "20180216010330_board8-VTHsw-allch-TP2600_001.",
		      "20180216011808_board8-VTHsw-allch-TP2800_001.",
		      "20180226150926_board8-VTHsw-allch-TP3000_000.",
		      "20180216015601_board8-VTHsw-allch-TP3200_001."
		      //"20180216021051_board8-VTHsw-allch-TP3400_001."
		      /*"20180216022544_board8-VTHsw-allch-TP3600_001."*/};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 30, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 2 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board9(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180228102027_board9-VTHsw-allch-TP0_000.", 
		      "20180228103738_board9-VTHsw-allch-TP200_000.", 
		      "20180228104733_board9-VTHsw-allch-TP400_000.", 
		      "20180228110507_board9-VTHsw-allch-TP600_000.", 
		      "20180228112223_board9-VTHsw-allch-TP800_000.", 
		      "20180228113455_board9-VTHsw-allch-TP1000_000.", 
		      "20180228115207_board9-VTHsw-allch-TP1200_000.",
		      "20180228120915_board9-VTHsw-allch-TP1400_000.",
		      "20180228122621_board9-VTHsw-allch-TP1600_000.",
		      "20180228124322_board9-VTHsw-allch-TP1800_000.",
		      "20180228130022_board9-VTHsw-allch-TP2000_000.",
		      "20180228131722_board9-VTHsw-allch-TP2200_000.",
		      "20180228133422_board9-VTHsw-allch-TP2400_000.",
		      "20180228135116_board9-VTHsw-allch-TP2600_000.",
		      "20180228140804_board9-VTHsw-allch-TP2800_000.",
		      "20180228161640_board9-VTHsw-allch-TP3000_001.",
		      "20180228150143_board9-VTHsw-allch-TP3200_000."/*,
		      "20180228151827_board9-VTHsw-allch-TP3400_000."
		      "20180228153533_board9-VTHsw-allch-TP3600_000."*/};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 30, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 3 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Ifeed150_Board9(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180228164341_board9-VTHsw-allch-TP0_000.", 
		      "20180228165933_board9-VTHsw-allch-TP200_000.", 
		      "20180228171628_board9-VTHsw-allch-TP400_000.", 
		      "20180228173326_board9-VTHsw-allch-TP600_000.", 
		      "20180228175032_board9-VTHsw-allch-TP800_000.", 
		      "20180228180737_board9-VTHsw-allch-TP1000_000.", 
		      "20180228182450_board9-VTHsw-allch-TP1200_000.",
		      "20180228184155_board9-VTHsw-allch-TP1400_000.",
		      "20180228185905_board9-VTHsw-allch-TP1600_000.",
		      "20180228190922_board9-VTHsw-allch-TP1800_000.",
		      "20180228130022_board9-VTHsw-allch-TP2000_000.",
		      "20180228131722_board9-VTHsw-allch-TP2200_000.",
		      "20180228133422_board9-VTHsw-allch-TP2400_000.",
		      "20180228135116_board9-VTHsw-allch-TP2600_000.",
		      "20180228140804_board9-VTHsw-allch-TP2800_000.",
		      "20180228161640_board9-VTHsw-allch-TP3000_001.",
		      "20180228150143_board9-VTHsw-allch-TP3200_000."/*,
		      "20180228151827_board9-VTHsw-allch-TP3400_000."
		      "20180228153533_board9-VTHsw-allch-TP3600_000."*/};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 0, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 4 ~~~~~~~~~~~~~~~
void TwoDim_Plots_40M_timing_Vth_VCal110_Board9(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 200.;
  float xmax = 320.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"VTH_VCal110_000.", 
		      "20180228103738_board9-VTHsw-allch-TP200_000.", 
		      "20180228104733_board9-VTHsw-allch-TP400_000.", 
		      "20180228110507_board9-VTHsw-allch-TP600_000.", 
		      "20180228112223_board9-VTHsw-allch-TP800_000.", 
		      "20180228113455_board9-VTHsw-allch-TP1000_000.", 
		      "20180228115207_board9-VTHsw-allch-TP1200_000.",
		      "20180228120915_board9-VTHsw-allch-TP1400_000.",
		      "20180228122621_board9-VTHsw-allch-TP1600_000.",
		      "20180228124322_board9-VTHsw-allch-TP1800_000.",
		      "20180228130022_board9-VTHsw-allch-TP2000_000.",
		      "20180228131722_board9-VTHsw-allch-TP2200_000.",
		      "20180228133422_board9-VTHsw-allch-TP2400_000.",
		      "20180228135116_board9-VTHsw-allch-TP2600_000.",
		      "20180228140804_board9-VTHsw-allch-TP2800_000.",
		      "20180228161640_board9-VTHsw-allch-TP3000_001.",
		      "20180228150143_board9-VTHsw-allch-TP3200_000."/*,
		      "20180228151827_board9-VTHsw-allch-TP3400_000."
		      "20180228153533_board9-VTHsw-allch-TP3600_000."*/};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    //analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	//grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 5 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board101_TO2A(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180313130930_board101-TO2A-VTHsw-allch-TP0_000.", 
		      "20180313132108_board101-TO2A-VTHsw-allch-TP200_000.", 
			  	"20180313133248_board101-TO2A-VTHsw-allch-TP400_000.",
		      "20180313134432_board101-TO2A-VTHsw-allch-TP600_000.", 
		      "20180313140116_board101-TO2A-VTHsw-allch-TP800_000.", 
		      "20180313141801_board101-TO2A-VTHsw-allch-TP1000_000.", 
		      "20180313143031_board101-TO2A-VTHsw-allch-TP1200_000.",
		      "20180313144319_board101-TO2A-VTHsw-allch-TP1400_000.",
		      "20180313145607_board101-TO2A-VTHsw-allch-TP1600_000.",
		      "20180313150831_board101-TO2A-VTHsw-allch-TP1800_000.",
		      "20180313152012_board101-TO2A-VTHsw-allch-TP2000_000.",
		      "20180313153113_board101-TO2A-VTHsw-allch-TP2200_000.",
		      "20180313154251_board101-TO2A-VTHsw-allch-TP2400_000.",
		      "20180313155433_board101-TO2A-VTHsw-allch-TP2600_000.",
		      "20180313160624_board101-TO2A-VTHsw-allch-TP2800_000."
		      /*"20180228161640_board9-VTHsw-allch-TP3000_001.",
		      "20180228150143_board9-VTHsw-allch-TP3200_000.",
		      "20180228151827_board9-VTHsw-allch-TP3400_000.",
		      "20180228153533_board9-VTHsw-allch-TP3600_000."*/};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 0, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 6 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Cal_Board101_TO2A(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180313233446_board101-TO2A-CALsw-allch-TP0_003.", 
		      "20180313211843_board101-TO2A-VTHsw-allch-TP200_002.", 
			  "20180313212357_board101-TO2A-VTHsw-allch-TP400_002.",
		      "20180313212912_board101-TO2A-VTHsw-allch-TP600_002.", 
		      "20180313213610_board101-TO2A-VTHsw-allch-TP800_002.", 
		      "20180313214307_board101-TO2A-VTHsw-allch-TP1000_002.", 
		      "20180313214823_board101-TO2A-VTHsw-allch-TP1200_002.",
		      "20180313215340_board101-TO2A-VTHsw-allch-TP1400_002.",
		      "20180313215856_board101-TO2A-VTHsw-allch-TP1600_002.",
		      "20180313220414_board101-TO2A-VTHsw-allch-TP1800_002.",
		      "20180313220930_board101-TO2A-VTHsw-allch-TP2000_002.",
		      "20180313221447_board101-TO2A-VTHsw-allch-TP2200_002.",
		      "20180313222003_board101-TO2A-VTHsw-allch-TP2400_002.",
		      "20180313222519_board101-TO2A-VTHsw-allch-TP2600_002.",
		      "20180313223034_board101-TO2A-VTHsw-allch-TP2800_002.",
		      "20180313223509_board101-TO2A-VTHsw-allch-TP3000_002.",
			  "20180313224625_board101-TO2A-VTHsw-allch-TP3200_002.",
			  "20180313232933_board101-TO2A-VTHsw-allch-TP3400_002."};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 0, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 35, 25, 60, 1., 5., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 7 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Cal70_Board101_TO2A(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180313233446_board101-TO2A-CALsw-allch-TP0_003.", 
		      "20180313211843_board101-TO2A-VTHsw-allch-TP200_002.", 
			  "20180313212357_board101-TO2A-VTHsw-allch-TP400_002.",
		      "20180314135846_board101-TO2A-VTHsw-allch-TP600_001.", 
		      "20180314122843_board101-TO2A-VTHsw-allch-TP800_000.", 
		      "20180314123341_board101-TO2A-VTHsw-allch-TP1000_000.", 
		      "20180314123839_board101-TO2A-VTHsw-allch-TP1200_000.",
		      "20180314124339_board101-TO2A-VTHsw-allch-TP1400_000.",
		      "20180314124836_board101-TO2A-VTHsw-allch-TP1600_000.",
		      "20180314125334_board101-TO2A-VTHsw-allch-TP1800_000.",
		      "20180314125830_board101-TO2A-VTHsw-allch-TP2000_000.",
		      "20180314130328_board101-TO2A-VTHsw-allch-TP2200_000.",
		      "20180314130825_board101-TO2A-VTHsw-allch-TP2400_000.",
		      "20180314131318_board101-TO2A-VTHsw-allch-TP2600_000.",
		      "20180314131810_board101-TO2A-VTHsw-allch-TP2800_000.",
		      "20180314132300_board101-TO2A-VTHsw-allch-TP3000_000.",
			  "20180314133404_board101-TO2A-VTHsw-allch-TP3200_000.",
			  "20180314133857_board101-TO2A-VTHsw-allch-TP3400_000."};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 35, 25, 60, -100, 0, tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 35, 25, 60, 1., 5., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 8 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board101_TO2AP(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180314205248_board101-VTHsw-allch-TP0_002.", 
		      "20180314205949_board101-VTHsw-allch-TP200_002.", 
			  	"20180314210653_board101-VTHsw-allch-TP400_002.",
		      "20180314211351_board101-VTHsw-allch-TP600_002.", 
		      "20180314212055_board101-VTHsw-allch-TP800_002.", 
		      "20180314212801_board8-VTHsw-allch-TP1000_002.", 
		      "20180314213508_board101-VTHsw-allch-TP1200_002.",
		      "20180314214148_board101-VTHsw-allch-TP1400_002.",
		      "20180314214848_board101-VTHsw-allch-TP1600_002.",
		      "20180314215546_board101-VTHsw-allch-TP1800_002.",
		      "20180314220241_board101-VTHsw-allch-TP2000_002.",
		      "20180314220935_board101-VTHsw-allch-TP2200_002.",
		      "20180314221628_board101-VTHsw-allch-TP2400_002.",
		      "20180314222321_board101-VTHsw-allch-TP2600_002.",
		      "20180314223017_board101-VTHsw-allch-TP2800_002.",
		      "20180314223714_board101-VTHsw-allch-TP3000_002.",
		      "20180314225504_board101-VTHsw-allch-TP3200_002.",
		      "20180314230202_board101-VTHsw-allch-TP3400_002."};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 0, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 9 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board101_TO2A_C2(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180320105139_board101-VTHsw-allch-TP0_000.", 
		      "20180322095742_board101-VTHsw-allch-TO2A-C2_TP200_000.", 
			  "20180322100808_board101-VTHsw-allch-TO2A-C2_TP400_000.",
		      "20180322102224_board101-VTHsw-allch-TO2A-C2_TP600_000.", 
		      "20180322103328_board101-VTHsw-allch-TO2A-C2_TP800_000.", 
		      "20180322104435_board101-VTHsw-allch-TO2A-C2_TP1000_000.", 
		      "20180322105553_board101-VTHsw-allch-TO2A-C2_TP1200_000.",
		      "20180320120139_board101-VTHsw-allch-TP1400_000.",
		      "20180320121146_board101-VTHsw-allch-TP1600_000.",
		      "20180320122147_board101-VTHsw-allch-TP1800_000.",
		      "20180320123142_board101-VTHsw-allch-TP2000_000.",
		      "20180320124122_board101-VTHsw-allch-TP2200_000.",
		      "20180320125117_board101-VTHsw-allch-TP2400_000.",
		      "20180320130109_board101-VTHsw-allch-TP2600_000.",
		      "20180320131101_board101-VTHsw-allch-TP2800_000.",
		      "20180320132056_board101-VTHsw-allch-TP3000_000.",
		      "20180320134752_board101-VTHsw-allch-TP3200_000.",
		      "20180320135752_board101-VTHsw-allch-TP3400_000."};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 180, 30, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 180, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 10 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board102_TO2A(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180322121453_board102-VTHsw-allch-TO2A-C4_TP000_000.", 
		      "20180322122559_board102-VTHsw-allch-TO2A-C4_TP200_000.", 
		      "20180322123744_board102-VTHsw-allch-TO2A-C4_TP400_000.", 
		      "20180322124932_board102-VTHsw-allch-TO2A-C4_TP600_000.", 
		      "20180322130204_board102-VTHsw-allch-TO2A-C4_TP1000_000.", 
		      "20180322131435_board102-VTHsw-allch-TO2A-C4_TP1200_000.",
		      "20180322132705_board102-VTHsw-allch-TO2A-C4_TP1200_000.",
		      "20180322133924_board102-VTHsw-allch-TO2A-C4_TP1400_000.",
		      "20180322135143_board102-VTHsw-allch-TO2A-C4_TP1600_000.",
		      "20180322140404_board102-VTHsw-allch-TO2A-C4_TP1800_000.",
		      "20180322141650_board102-VTHsw-allch-TO2A-C4_TP2000_000.",
		      "20180322142911_board102-VTHsw-allch-TO2A-C4_TP2200_000.",
		      "20180322144132_board102-VTHsw-allch-TO2A-C4_TP2400_000.",
		      "20180322145359_board102-VTHsw-allch-TO2A-C4_TP2600_000.",
		      "20180322150534_board102-VTHsw-allch-TO2A-C4_TP2800_000."
		      /*"20180314225504_board101-VTHsw-allch-TP3200_002.",
		      "20180314230202_board101-VTHsw-allch-TP3400_002."*/};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 0, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 11 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_C24_Board103_TO2A(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"20180321235754_board103-VTHsw-allch-TO2A-C24_TP0_002.", 
		      "20180322000952_board103-VTHsw-allch-TO2A-C2_TP200_002.", 
			  "20180322002148_board103-VTHsw-allch-TO2A-C2_TP400_002.",
		      "20180322003344_board103-VTHsw-allch-TO2A-C2_TP600_002.", 
		      "20180322004539_board103-VTHsw-allch-TO2A-C2_TP800_002.", 
		      "20180322005737_board103-VTHsw-allch-TO2A-C2_TP1000_002.", 
		      "20180322010931_board103-VTHsw-allch-TO2A-C2_TP1200_002.",
		      "20180322012126_board103-VTHsw-allch-TO2A-C2_TP1400_002.",
		      "20180322013322_board103-VTHsw-allch-TO2A-C2_TP1600_002.",
		      "20180322014519_board103-VTHsw-allch-TO2A-C2_TP1800_002.",
		      "20180322015710_board103-VTHsw-allch-TO2A-C2_TP2000_002.",
		      "20180322020842_board103-VTHsw-allch-TO2A-C2_TP2200_002.",
		      "20180322022026_board103-VTHsw-allch-TO2A-C2_TP2400_002.",
		      "20180322023203_board103-VTHsw-allch-TO2A-C2_TP2600_002.",
		      "20180322024350_board103-VTHsw-allch-TO2A-C2_TP2800_002.",
		      "20180322025538_board103-VTHsw-allch-TO2A-C2_TP3000_002.",
		      "20180322032242_board103-VTHsw-allch-TO2A-C2_TP3200_002.",
		      "20180322033438_board103-VTHsw-allch-TO2A-C2_TP3400_002."};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 0, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// ~~~~~~~~~~~~~~ 12 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_timing_Vth_Board8_1257(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 45.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {"TP0_I150.",
		      "TP200_I150.", 
		      "TP400_I150.", 
		      "TP600_I150.", 
			  "TP800_I150.", 
			  "TP1000_I150.", 
			  "TP1200_I150.", 
			  "TP1400_I150.", 
			  "TP1600_I150.", 
			  "TP1800_I150.", 
			  "TP2000_I150.", 
			  "TP2200_I150.", 
			  "TP2400_I150.", 
			  "TP2600_I150.", 
			  "TP2800_I150.", 
			  "TP3000_I150.", 
			  "TP3200_I150.", 
			  "TP3400_I150."};
  
  int dimensione = sizeof(file)/sizeof(file[0]);
  const int dim = dimensione;
  
  //vettori che registreranno i valori di soglia per il singolo file
 	float TPPhase[dim], errTPPhase[dim], mediath[dim], errmediath[dim];
 	
 	for(int j=0; j < dimensione; j++){
 		TPPhase[j] = j*200;
 		errTPPhase[j] = 0;
 		mediath[j] = 0;
 		errmediath[j] = 0;
 	}  
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    //analisiMC(percorso, file[i], 90, 30, 210, 1., 10.);
    analisiMC(percorso, file[i], 90, 30, 210, 1., 10., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 90, 30, 210, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
	
	grafico_Vth(percorso, dimensione, TPPhase, errTPPhase, mediath, errmediath);
}

// -----------------------------------------------------
// --------- Funzione per disegnare il grafico ---------
// -----------------------------------------------------
void grafico_Vth(TString percorso, int dim, float TPPhase[], float errTPPhase[], float mediath[], float errmediath[]){
  
 vector<float> TPP;
 vector<float> errTPP;
 vector<float> Th;
 vector<float> errTh;
 int n = 0;
 for(int i = 0; i < dim; i++){ 	
    TPPhase[i] = 25 - TPPhase[i]*25/3600;
    if (TPPhase[i] > 5 )  TPPhase[i]=TPPhase[i];
    else TPPhase[i] = TPPhase[i] + 25;
    mediath[i] = mediath[i]*0.106/200;
    errmediath[i] = errmediath[i]*0.106/200;
    
    if(mediath[i] > 0.02){
    	Th.push_back(mediath[i]);
    	errTh.push_back(errmediath[i]);
    	TPP.push_back(TPPhase[i]);
    	errTPP.push_back(0.);
    }
  }
  
  dim = Th.size();
  
  TCanvas *csoglia = new TCanvas("csoglia","Vth(TPphase)",200,50,600,400);
  csoglia -> cd();
  TGraphErrors *gsoglia = new TGraphErrors(dim, &(TPP[0]), &(Th[0]), &(errTPP[0]), &(errTh[0]));
  //TGraphErrors *gsoglia = new TGraphErrors(dim, TPPhase, mediath, errTPPhase, errmediath);
  gsoglia->SetMarkerSize(0.6);
  gsoglia->SetMarkerStyle(21);
  gsoglia->SetTitle("<V_{th}>(TPphase)_{40 MHz}");
  gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
  gsoglia->GetYaxis()->SetTitle("<V_{th}> [V]");
  //gsoglia->SetMarkerColor(kBlue);
  gsoglia->Draw("AP");
  
  csoglia->cd();
  /*
  float qDAC = 70.;
  float q_c;
  q_c = ((qDAC*48.5)-1500.)*1.6*pow(10.,-19.);
  //cout << " q_c\n" << endl;
  
  float c = 2.4*pow(10.,-15.);*/
  
  //TF1 *fitV = new TF1("fitV","[0]*(1 + TMath::Exp(-(x-[1])/[2]))+[3]*(x+[1])+[4]",10.,20.);
  //TF1 *fitV = new TF1("fitV","[0]+[1]*TMath::Exp(-(x)/[2])+[3]*x",8,31.6);
  //TF1 *fitV = new TF1("fitV","(0.133)*(1-TMath::Exp(-(x-[0])/[1]))-[2]*4.1e14*(x-[0])",8,31.6);
  //TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);
  TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",7.,28.);
  //TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-x*[1]))-[2]*x",10,25);
  fitV->SetParName(0,"Q/C");
  fitV->SetParName(1,"t_{0}");
  fitV->SetParName(2,"#tau");
  fitV->SetParName(3,"i/C");
  fitV->SetParameter(0,0.45);
  fitV->SetParameter(1,10.);
  fitV->SetParameter(2,20.);
  
  
  //TVirtualFitter::SetMaxInterations(100000);
  gsoglia->Fit(fitV,"MR");
  cout << "Chi^2: " << fitV->GetChisquare() << endl;
  cout << "Probability: " << fitV->GetProb() << endl;
  cout << "number of DoF: " << fitV->GetNDF() << endl;
	
	csoglia->SaveAs(".pdf");
	csoglia->SaveAs(".root");
}

void grafico(TString percorso, int dim, float TPPhase[], float errTPPhase[], float mediath[], float errmediath[]){
  
 vector<float> TPP;
 vector<float> errTPP;
 vector<float> Th;
 vector<float> errTh;
 int n = 0;
 for(int i = 0; i < dim; i++){ 	
    TPPhase[i] = 25 - TPPhase[i]*25/3600;
    if (TPPhase[i] > 5 )  TPPhase[i]=TPPhase[i];
    else TPPhase[i] = TPPhase[i] + 25;
      
    mediath[i] = mediath[i]*0.106/200 + 0.49 -0.96;
    errmediath[i] = errmediath[i]*0.106/200;
    
    if(mediath[i] > 0.5){
    	Th.push_back(mediath[i]);
    	errTh.push_back(errmediath[i]);
    	TPP.push_back(TPPhase[i]);
    	errTPP.push_back(0.);
    }
  }
  
  dim = Th.size();
  
  TCanvas *csoglia = new TCanvas("csoglia","Vth(TPphase)",200,50,600,400);
  csoglia -> cd();
  TGraphErrors *gsoglia = new TGraphErrors(dim, &(TPP[0]), &(Th[0]), &(errTPP[0]), &(errTh[0]));
  //TGraphErrors *gsoglia = new TGraphErrors(dim, TPPhase, mediath, errTPPhase, errmediath);
  gsoglia->SetMarkerSize(0.6);
  gsoglia->SetMarkerStyle(21);
  gsoglia->SetTitle("<V_{th}>(TPphase)_{40 MHz}");
  gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
  gsoglia->GetYaxis()->SetTitle("<V_{th}> [V]");
  //gsoglia->SetMarkerColor(kBlue);
  gsoglia->Draw("AP");
  
  csoglia->cd();
  /*
  float qDAC = 70.;
  float q_c;
  q_c = ((qDAC*48.5)-1500.)*1.6*pow(10.,-19.);
  //cout << " q_c\n" << endl;
  
  float c = 2.4*pow(10.,-15.);*/
  
  //TF1 *fitV = new TF1("fitV","[0]*(1 + TMath::Exp(-(x-[1])/[2]))+[3]*(x+[1])+[4]",10.,20.);
  //TF1 *fitV = new TF1("fitV","[0]+[1]*TMath::Exp(-(x)/[2])+[3]*x",8,31.6);
  //TF1 *fitV = new TF1("fitV","(0.133)*(1-TMath::Exp(-(x-[0])/[1]))-[2]*4.1e14*(x-[0])",8,31.6);
  //TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);
  TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",9.,24.);
  //TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-x*[1]))-[2]*x",10,25);
  
  fitV->SetParameter(0,0.1);
  fitV->SetParameter(1,10.);
  fitV->SetParameter(2,20.);
  
  
  //TVirtualFitter::SetMaxInterations(100000);
  gsoglia->Fit(fitV,"MR");
  cout << "Chi^2: " << fitV->GetChisquare() << endl;
  cout << "Probability: " << fitV->GetProb() << endl;
  cout << "number of DoF: " << fitV->GetNDF() << endl;
	
	csoglia->SaveAs(".pdf");
	csoglia->SaveAs(".root");
}


