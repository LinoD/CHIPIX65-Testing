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

void TwoDim_Plots_40M_Board101(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_Board102(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_Board103(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_Board103_70(int i, TString percorso, int tipo, int min, int max);
void TwoDim_Plots_40M_Board103_100(int i, TString percorso, int tipo, int min, int max);

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
	cout << "- 0 per TwoDim_Plots_40M_Board101\n";
	cout << "- 1 per TwoDim_Plots_40M_Board102\n";
	cout << "- 2 per TwoDim_Plots_40M_Board103\n";
	cout << "- 3 per TwoDim_Plots_40M_Board103_70\n";
	
	cin >> funzione;

	switch(funzione){ //switch che permette di scegliere i dati da analizzare
		
		case 0: {
			Dir = Dir0 + "Board101/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Board101(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Board101(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Board101(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Board101(i, Dir, tipo, min, min);
			}
		}break;
		
		case 1: {
			Dir = Dir0 + "Board102/CAL-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_Board102(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board102(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board102(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_Board102(i, Dir, tipo, min, min);
			}
		}break;
		
		
		case 2: {
			Dir = Dir0 + "Board103/CAL-scan/Vth60/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_Board103(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board103(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board103(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_Board103(i, Dir, tipo, min, min);
			}
		}break;
		
		case 3: {
			Dir = Dir0 + "Board103/CAL-scan/Vth65/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_Board103_70(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board103_70(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board103_70(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_Board103_70(i, Dir, tipo, min, min);
			}
		}break;
		
		case 4: {
			Dir = Dir0 + "Board103/CAL-scan/Vth100/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_Board103_100(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board103_100(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_Board103_100(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_Board103_100(i, Dir, tipo, min, min);
			}
		}break;
		
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
void TwoDim_Plots_40M_timing_Board101(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
  
  int nfile = 0;
  
  TString file[] = {"CalSweep-TO2A.", 
		      "CalSweep-TO2B.", 
		      "CalSweep-TO2AP.",
		      "CalSweep-TO2A-C4F.",
		      "CalSweep-TO2B-C4F.",
		      "CalSweep-TO2AP-C4F.",
		      "CalSweep-TO2A-C4F-1.",
		      "CalSweep-TO2B-C4F-1.",
		      "CalSweep-TO2AP-C4F-1.",
		      "CalSweep-TO2A-C24F.",
		      "CalSweep-TO2B-C24F.",
		      "CalSweep-TO2AP-C24F.",
		      "CalSweep-TO2A-C4F-2.",
		      "CalSweep-TO2B-C4F-2.",
		      "CalSweep-TO2AP-C4F-2."};
		      
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
    analisiMC(percorso, file[i], 40, 20, 60, 1., 3.5, tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     //Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 40, 20, 60, 1., 3.5, tipo, min, max, mediath[j], errmediath[j]);
		}
	}
}

// ~~~~~~~~~~~~~~ 1 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_Board102(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
  
  int nfile = 0;
  
  TString file[] = {"20180320202648_board102-CALsw-allch-TO2A_005.", 
		      "20180320203121_board102-CALsw-allch-TO2B_005.", 
		      "20180320203601_board102-CALsw-allch-TO2AP_005.",
		      "20180320203906_board102-CALsw-allch-TO2A-C24_005.",
			    "20180320204329_oard102-CALsw-allch-TO2B-C24_005.",
		      "20180320204753_oard102-CALsw-allch-TO2AP-C24_005.",
		      "20180320205050_oard102-CALsw-allch-TO2A-C2_005.",
		      "20180320205519_oard102-CALsw-allch-TO2A-C2_005.",
		      "20180320202350_oard102-CALsw-allch-TO2AP-C2_004."};
		      
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
    analisiMC(percorso, file[i], 40, 20, 60, 1., 7., tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 40, 20, 60, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
}

// ~~~~~~~~~~~~~~ 2 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_Board103(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
  
  int nfile = 0;
  
  TString file[] = {"CalSweep-TO2A-C2F.", 
		      "CalSweep-TO2A-C4F.", 
		      "CalSweep-TO2A-C24F.",
		      "CalSweep-TO2AP-C2F.",
			  "CalSweep-TO2AP-C4F.",
		      "CalSweep-TO2AP-C24F.",
		      "CalSweep-TO2B-C2F.",
		      "CalSweep-TO2B-C4F.",
		      "CalSweep-TO2B-C24F."};
		      
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
    analisiMC(percorso, file[i], 40, 20, 60, 1., 3.5, tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 40, 20, 60, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
}

// ~~~~~~~~~~~~~~ 3 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_Board103_70(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
  
  int nfile = 0;
  
  TString file[] = {"20180321130103_board103-CALsw-allch-TO2A-C2_000.", 
		      "20180321130553_board103-CALsw-allch-TO2B-C2_000.", 
		      "20180321131042_board103-CALsw-allch-TO2AP-C2_000.",
		      "20180321123514_board103-CALsw-allch-TO2A_000.",
			  "20180321124010_board103-CALsw-allch-TO2B_000.",
		      "20180321124517_board103-CALsw-allch-TO2AP_000.",
		      "20180321124837_board103-CALsw-allch-TO2A-C24_000.",
		      "20180321125318_board103-CALsw-allch-TO2B-C24_000.",
		      "20180321125759_oard103-CALsw-allch-TO2AP-C24_000."};
		      
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
    analisiMC(percorso, file[i], 40, 20, 60, 1., 3.5, tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 40, 20, 60, 1., 10., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
}

// ~~~~~~~~~~~~~~ 4 ~~~~~~~~~~~~~~~ 
void TwoDim_Plots_40M_Board103_100(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
  
  int nfile = 0;
  
  TString file[] = {"CAL_scan_C2_A.", 
		      "CAL_scan_C4_A.", 
		      "CAL_scan_C24_A.",
		      "CAL_scan_C2_B.",
			  "CAL_scan_C24_B.",
		      "CAL_scan_C4_B.",
		      "CAL_scan_C4_AP.",
		      "CAL_scan_C24_AP.",
		      "CAL_scan_C2_AP."};
		      
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
    analisiMC(percorso, file[i], 50, 30, 80, 1., 5, tipo, min, max, mediath[i], errmediath[i]);
    }
  else{
   for(int j = 0; j < dimensione; j++){
     Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
     analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
     //analisiMC(percorso, file[j], 90, 30, 210, 1., 10.); 
     analisiMC(percorso, file[j], 50, 30, 80, 1., 5., tipo, min, max, mediath[j], errmediath[j]);
		}
	}
}
