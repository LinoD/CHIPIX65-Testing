 /* Analisi dei file di dati
    
	autore: Cristina Sauda - cristina.sauda@edu.unito.it
	data creazione:  2018/02/15
	ultima modifica: 2018/02/23
	
	per eseguire:
	 + caricare la macro in root con il comando .L analysis_studenti_scan_timingTP_Cristina.C
		(Prima essere sicuridi avere nella stessa cartella le macro Macro_scurve.C analisi_histo_1d_Cristina.C Macro_scurve_Vth.C)
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


//#include "Macro_scurve.C"
#include "analisi_histo_1d_Cristina.C"
#include "Macro_scurve_Vth.C"

// ~~~~~~~~~~~~~~~~~~~ Dichiarazioni ~~~~~~~~~~~~~~~~~~~
void Analysis(int i); //funzione principale
void TwoDim_Plots_40M_timing(int i, TString percorso, int tipo, int min, int max); //funzione che prende i dati e li manda all'analisi per misure standard a 40 MHz facendo variare la carica in ingresso
void TwoDim_Plots_40M_timing_Vth(int i, TString percorso, int tipo, int min, int max); //funzione che prende i dati e li manda all'analisi per misure standard a 40 MHz facendo variare la tensione del discriminatore

void grafico_Vth(TString percorso, int dimensione, float TPPhase[], float errTPPhase[], float mediath[], float errmediath[]); //funzione che permette di disegnare il grafico


void TwoDim_Plots_40M_timing_range(int i, TString percorso);
void TwoDim_Plots_20M_timing(int i, int type, int min, int max, TString percorso);
void TwoDim_Plots_20M_timing(int i, TString percorso);
void TwoDim_Plots_If160_timing(int i, TString percorso);
void TwoDim_Plots_If40_timing(int i, TString percorso);
void TwoDim_Plots_If10_timing(int i, TString percorso);
void TwoDim_Plots_If40_20M_timing(int i, TString percorso);
void TwoDim_Plots_Pdoppi_20M_timing(int i, TString percorso);
void TwoDim_Plots_C4F_timing(int i, TString percorso);
void TwoDim_Plots_Vth90_timing(int i, TString percorso);
void TwoDim_Plots_Pmezzi_timing(int i, TString percorso);
void TwoDim_Plots_Pdoppi_timing(int i, TString percorso);
void TwoDim_Plots_Vthchange_20M_timing(int i, TString percorso);
void TwoDim_Plots_Vthchange1200_20M_timing(int i, TString percorso);
void TwoDim_Plots_sensore7_Board2(int i, TString percorso);
void TwoDim_Plots_sensore12_Board4(int i, TString percorso);
void TwoDim_Plots_sensore12_Board4_PILA(int i, TString percorso);


// ~~~~~~~~~~~~~~~~~~ Implementazioni ~~~~~~~~~~~~~~~~~~
// ---------------- Funzione principale ----------------
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
    Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/Board8_revisione/"; 
  }
  else if(so == "w"){
    Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/";
  } 
  else if(so == "c"){
    Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
  }

	cout << "\nScegliere la funzione da usare:\n";
	cout << "- 0 per TwoDim_Plots_40M_timing\n";
	cout << "- 1 per TwoDim_Plots_40M_timing_Vth\n";
	cin >> funzione;

	switch(funzione){
		case 0:{
			Dir = Dir0 + "TPphase-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing(i, Dir, tipo, min, min);
			}
		} break;

		case 1: {
			Dir = Dir0 + "VTH-scan/";
			
			cout << "\nScegliere il tipo di analisi da eseguire:\n";
			cout << "- 0 per analizzare tutti i pixel\n";
			cout << "- 1 per analizzare un range di pixel\n";
			cout << "- 2 per analizzare alcune righe di pixel\n";
			cout << "- 3 per analizzare un pixel\n";
			cin >> tipo;
			
			if (tipo == 0){
				TwoDim_Plots_40M_timing_Vth(i, Dir, tipo, min, max);
			}
			else if(tipo == 1){
				cout << "\nScegliere il numero del primo pixel da analizzare: ";
				cin >> min;
				cout << "\nScegliere il numero dell'ultimo pixel da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth(i, Dir, tipo, min, max);
			}
			else if(tipo == 2){
				cout << "\nScegliere la prima riga da analizzare: ";
				cin >> min;
				cout << "\nScegliere l'ultima riga da analizzare: ";
				cin >> max;
			
				TwoDim_Plots_40M_timing_Vth(i, Dir, tipo, min, max);
			}
			else if(tipo == 3){
				cout << "\nScegliere il pixel da analizzare: ";
				cin >> min;
			
				TwoDim_Plots_40M_timing_Vth(i, Dir, tipo, min, min);
			}
		}break;
		default: {
			cout << "Inizializzazione sbagliata\n";
			return;
		}break;
	}
  //  TwoDim_Plots_40M_timing(i, Dir);
  //  TwoDim_Plots_40M_timing(i, type, min, max, Dir);
  //  TwoDim_Plots_40M_timing_range(i, Dir);
  //  TwoDim_Plots_20M_timing(i, type, min, max, Dir);
  //  TwoDim_Plots_20M_timing(i, Dir);
  //  TwoDim_Plots_If160_timing(i, Dir);
  //  TwoDim_Plots_If40_timing(i, Dir);
  //  TwoDim_Plots_If10_timing(i, Dir);
  //  TwoDim_Plots_If40_20M_timing(i, Dir);
  //  TwoDim_Plots_Pdoppi_20M_timing(i, Dir);
  //  TwoDim_Plots_C4F_timing(i, Dir);
  //  TwoDim_Plots_Vth90_timing(i, Dir);
  //  TwoDim_Plots_Pmezzi_timing(i, Dir);
  //  TwoDim_Plots_Pdoppi_timing(i, Dir);
  //  TwoDim_Plots_Vthchange_20M_timing(i, Dir);
  //  TwoDim_Plots_Vthchange1200_20M_timing(i, Dir);
  //  TwoDim_Plots_sensore7_Board2(i, Dir);
  //  TwoDim_Plots_sensore12_Board4(i, Dir);
  //  TwoDim_Plots_sensore12_Board4_PILA(i, Dir);
  //  TwoDim_Plots_40M_timing_Vth(i, Dir);
}


// -----------------------------------------------------
// ---------------- Funzione principale ----------------
// -----------------------------------------------------

void TwoDim_Plots_40M_timing(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 200.;
  
  int nfile = 0;
  
  TString file[] = {"20170601004206_board8-CALsw-allch-TP200_001.", 
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
  nfile = (int)file.size();
  
  //chiamata delle analisi
  if(i != -1){
    Macro_scurve(percorso, file[i], xmin, xmax, par0, par1, NEVT);
    //analisiTHR2(percorso, file[i], 320, tmin, tmax, 0., 10., 23.); 
    analisiMC(percorso, file[i], 60, 20, 80, 1., 4.);
    //analisiMC(percorso, file[i], 60, 20, 80, 1., 4., type, min, max);
  }
  else{
    for(int j = 0; j < (int)file->size(); j++){
      Macro_scurve(percorso, file[j], xmin, xmax, par0, par1, NEVT);
      //analisiTHR2(percorso, file[j], 320, tmin, tmax, 0., 10., 23.);
      analisiMC(percorso, file[j], 60, 20, 80, 1., 4.); 
      //analisiMC(percorso, file[j], 60, 20, 80, 1.,4., type, min, max);			
    }
  }
}


void TwoDim_Plots_40M_timing_Vth(int i, TString percorso, int tipo, int min, int max){
  
  //inizializzazione dei parametri
  float xmin = 30.;
  float xmax = 300.;
  float tmin = 30.;
  float tmax = 65.;
  float par0 = 40.;
  float par1 = 2.;
  float NEVT = 50.;
	
  int nfile = 0;
  
  TString file[] = {/*"20180216024043_board8-VTHsw-allch-TP0_002.",*/ 
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
		      "20180216015601_board8-VTHsw-allch-TP3200_001.",
		      "20180216021051_board8-VTHsw-allch-TP3400_001."
		      "20180216022544_board8-VTHsw-allch-TP3600_001."};
  
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

void grafico_Vth(TString percorso, int dim, float TPPhase[], float errTPPhase[], float mediath[], float errmediath[]){
  
 for(int i = 0; i < dim; i++){ 	
    TPPhase[i] = 25 - TPPhase[i]*25/3600;
    if (TPPhase[i] > 5 )  TPPhase[i]=TPPhase[i];
    else TPPhase[i] = TPPhase[i] + 25;
      
    mediath[i] = mediath[i]*0.106/200 +0.49;
    errmediath[i] = errmediath[i]*0.106/200;
    
    //cout << TPPhase[i] << " " <<q << " " << sq << endl;
  }
  //cout << t << " " <<thr << " " << sr << endl;  
  
  TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
  csoglia -> cd();
  TGraphErrors *gsoglia = new TGraphErrors(dim, TPPhase, mediath, errTPPhase, errmediath);
  gsoglia->SetMarkerSize(0.6);
  gsoglia->SetMarkerStyle(21);
  gsoglia->SetTitle("<V_{th}>(TPphase)_{40 MHz}");
  gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
  gsoglia->GetYaxis()->SetTitle("<V_{th}> [mV]");
  //gsoglia->SetMarkerColor(kBlue);
  gsoglia->Draw("AP");
  
  csoglia->cd();
  
  float qDAC = 70.;
  float q_c;
  q_c = ((qDAC*48.5)-1500.)*1.6*pow(10.,-19.);
  cout << " q_c/n" << endl;
  
  float c = 2.4*pow(10.,-15.);
  
  //TF1 *fitV = new TF1("fitV","[0]*(1 + TMath::Exp(-(x-[1])/[2]))+[3]*(x+[1])+[4]",10.,20.);
  //TF1 *fitV = new TF1("fitV","[0]+[1]*TMath::Exp(-(x)/[2])+[3]*x",8,31.6);
  //TF1 *fitV = new TF1("fitV","(0.133)*(1-TMath::Exp(-(x-[0])/[1]))-[2]*4.1e14*(x-[0])",8,31.6);
  //TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);
  TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",10.,25.);
  //TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-x*[1]))-[2]*x",10,11);
  
  fitV->SetParameter(0,0.1);
  fitV->SetParameter(1,10.);
  fitV->SetParameter(2,20.);
  
  
  //TVirtualFitter::SetMaxInterations(100000);
  gsoglia->Fit(fitV,"MR");
  //fitQ->SetParLimits(3,0.050,0.080);
  cout << "Chi^2: " << fitV->GetChisquare() << endl;
  cout << "Probability: " << fitV->GetProb() << endl;
  cout << "number of DoF: " << fitV->GetNDF() << endl;
	
	csoglia->SaveAs(".pdf");
}
