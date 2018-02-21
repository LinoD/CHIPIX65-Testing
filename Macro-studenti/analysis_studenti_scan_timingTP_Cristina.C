 /* Analisi dei file di dati
    
	autore: Cristina Sauda - cristina.sauda@edu.unito.it
	data creazione:  2018/02/15
	ultima modifica: 2018/02/21
	
	per eseguire:
	 + caricare la macro in root con il comando .L analysis_studenti_scan_timingTP_Cristina.C
	 + eseguire l'analisi del file con il comando Analysis(numero che identifica il file che si vuole analizzare) [scrivere -1 per l'analisi complessiva]
 */

#include "Riostream.h"
#include "TAxis.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TMath.h"
#include "TMultiGraph.h"
#include "TString.h"
#include "TStyle.h" 

#include "Macro_scurve.C"
#include "analisi_histo_1d.C"

// ~~~~~~~~~~~~~~~~~~~ Dichiarazioni ~~~~~~~~~~~~~~~~~~~
void Analysis(int i); //funzione principale
void TwoDim_Plots_40M_timing(int i, TString Dir); //funzione che prende i dati e li manda all'analisi per misure standard a 40 MHz facendo variare la carica in ingresso
void TwoDim_Plots_40M_timing_Vth(int i, TString Dir); //funzione che prende i dati e li manda all'analisi per misure standard a 40 MHz facendo variare la tensione del discriminatore


void TwoDim_Plots_40M_timing_range(int i, TString so = "l");
void TwoDim_Plots_20M_timing(int i, int type, int min, int max, TString so = "l");
void TwoDim_Plots_20M_timing(int i, TString so = "l");
void TwoDim_Plots_If160_timing(int i, TString so = "l");
void TwoDim_Plots_If40_timing(int i, TString so = "l");
void TwoDim_Plots_If10_timing(int i, TString so = "l");
void TwoDim_Plots_If40_20M_timing(int i, TString so = "l");
void TwoDim_Plots_Pdoppi_20M_timing(int i, TString so = "l");
void TwoDim_Plots_C4F_timing(int i, TString so = "l");
void TwoDim_Plots_Vth90_timing(int i, TString so = "l");
void TwoDim_Plots_Pmezzi_timing(int i, TString so = "l");
void TwoDim_Plots_Pdoppi_timing(int i, TString so = "l");
void TwoDim_Plots_Vthchange_20M_timing(int i, TString so = "l");
void TwoDim_Plots_Vthchange1200_20M_timing(int i, TString so = "l");
void TwoDim_Plots_sensore7_Board2(int i, TString so = "l");
void TwoDim_Plots_sensore12_Board4(int i, TString so = "l");
void TwoDim_Plots_sensore12_Board4_PILA(int i, TString so = "l");


// ~~~~~~~~~~~~~~~~~~ Implementazioni ~~~~~~~~~~~~~~~~~~
// ---------------- Funzione principale ----------------
void Analysis(int i){
  TString so;
  TString Dir0;
  TString Dir;
  int funzione;
  
  cout << "Inserire un carattere per selezionare la cartella principale da cui prendere i file:\n";
  cout << "- l per ubuntu sul computer di Cristina\n";
  cout << "- e per ubuntu sul computer di Eleonora\n";
  cout << "- w per windows sul computer CHIPIX65\n";
  cout << "- c per i dati del CERN\n";
  cin >> so;

	if(so == "l"){
    Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/Board8_revisione/"; 
  }
  else if(so == "e"){
    Dir0 = "/home/eleonora/GitHub/CHIPIX65-Testing/data/Board8_revisione/"; 
  }
  else if(so == "w"){
    Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/";
  } 
  else if(so == "c"){
    Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
  }

	cout << "Scegliere la funzione da usare\n";
	cout << "- 0 per TwoDim_Plots_40M_timing\n";
	cout << "- 1 per TwoDim_Plots_40M_timing_Vth\n";
	cin >> funzione;

	switch(funzione){
		case 0:{
			Dir = Dir0 + "TPphase-scan/";
			TwoDim_Plots_40M_timing(i, Dir);
		} break;

		case 1: {
			Dir = Dir0 + "VTH-scan/";
			TwoDim_Plots_40M_timing_Vth(i, Dir);
		}	break;
		
		default: {
			cout << "Inizializzazione sbagliata\n";
			return;
		} break;
	}
  //  TwoDim_Plots_40M_timing(i, so);
  //  TwoDim_Plots_40M_timing(i, type, min, max, so);
  //  TwoDim_Plots_40M_timing_range(i, so);
  //  TwoDim_Plots_20M_timing(i, type, min, max, so);
  //  TwoDim_Plots_20M_timing(i, so);
  //  TwoDim_Plots_If160_timing(i, so);
  //  TwoDim_Plots_If40_timing(i, so);
  //  TwoDim_Plots_If10_timing(i, so);
  //  TwoDim_Plots_If40_20M_timing(i, so);
  //  TwoDim_Plots_Pdoppi_20M_timing(i, so);
  //  TwoDim_Plots_C4F_timing(i, so);
  //  TwoDim_Plots_Vth90_timing(i, so);
  //  TwoDim_Plots_Pmezzi_timing(i, so);
  //  TwoDim_Plots_Pdoppi_timing(i, so);
  //  TwoDim_Plots_Vthchange_20M_timing(i, so);
  //  TwoDim_Plots_Vthchange1200_20M_timing(i, so);
  //  TwoDim_Plots_sensore7_Board2(i, so);
  //  TwoDim_Plots_sensore12_Board4(i, so);
  //  TwoDim_Plots_sensore12_Board4_PILA(i, so);
  //  TwoDim_Plots_40M_timing_Vth(i, so);
}


// -----------------------------------------------------
// ---------------- Funzione principale ----------------
// -----------------------------------------------------

void TwoDim_Plots_40M_timing(int i, TString percorso){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 200.;
  
  int nfile = 0;
  
  TString file[18] = {"20170601004206_board8-CALsw-allch-TP200_001.", 
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
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    analisiMC(percorso, file[i], 60, 20, 80, 1., 4.);
    //analisiMC(percorso, file[i], 60, 20, 80, 1., 4., type, min, max);
  }
  else{
    for(int j = 0; j < (int)file.size(); j++){
      Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
      analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
      analisiMC(percorso, file[j], 60, 20, 80, 1., 4.); 
      //analisiMC(percorso, file[j], 60, 20, 80, 1.,4., type, min, max);			
    }
  }
}

/*
void TwoDim_Plots_40M_timing_Vth(int i, TString percorso){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 200.;
	
  int nfile = 0;
  
  TString file[19] = {"20180215215712_board8-VTHsw-allch-TP0_001.", 
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
		      "20180216013245_board8-VTHsw-allch-TP3000_001.",
		      "20180216015601_board8-VTHsw-allch-TP3200_001.",
		      "20180216021051_board8-VTHsw-allch-TP3400_001.",
		      "20180216022544_board8-VTHsw-allch-TP3600_001.q"};
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve_Vth(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    analisiMC(percorso, file[i], 60, 20, 80, 1., 4.);
    //analisiMC(percorso, file[i], 60, 20, 80, 1., 4., type, min, max);
  }
  else{
    for(int j = 0; j < (int)file.size(); j++){
      Macro_scurve_Vth(percorso, file[j], xmin, xmax, par0, par1, NEVT);
      analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
      analisiMC(percorso, file[j], 60, 20, 80, 1., 4.); 
      //analisiMC(percorso, file[j], 60, 20, 80, 1.,4., type, min, max);			
    }
  }
}

*/
