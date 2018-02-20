 /* Analisi dei file di dati
    
	autore: Cristina Sauda - cristina.sauda@edu.unito.it
	ultima modifica: 2018/02/15
	
	per eseguire:
	 + 
	 + 
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

// ~~~~~~~~~~~~~~~~~~~ Dichiarazioni ~~~~~~~~~~~~~~~~~~~
void Analysis(int i); //funzione principale
void TwoDim_Plots_40M_timing(int i, char so = "l"); //funzione che prende i dati e li manda all'analisi
void TwoDim_Plots_40M_timing_range(int i, char so);
void TwoDim_Plots_20M_timing(int i, int type, int min, int max, char so);
void TwoDim_Plots_20M_timing(int i, char so);
void TwoDim_Plots_If160_timing(int i, char so);
void TwoDim_Plots_If40_timing(int i, char so);
void TwoDim_Plots_If10_timing(int i, char so);
void TwoDim_Plots_If40_20M_timing(int i, char so);
void TwoDim_Plots_Pdoppi_20M_timing(int i, char so);
void TwoDim_Plots_C4F_timing(int i, char so);
void TwoDim_Plots_Vth90_timing(int i, char so);
void TwoDim_Plots_Pmezzi_timing(int i, char so);
void TwoDim_Plots_Pdoppi_timing(int i, char so);
void TwoDim_Plots_Vthchange_20M_timing(int i, char so);
void TwoDim_Plots_Vthchange1200_20M_timing(int i, char so);
void TwoDim_Plots_sensore7_Board2(int i, char so);
void TwoDim_Plots_sensore12_Board4(int i, char so);
void TwoDim_Plots_sensore12_Board4_PILA(int i, char so);
void TwoDim_Plots_40M_timing_Vth(int i, char so = "l");


// ~~~~~~~~~~~~~~~~~~ Implementazioni ~~~~~~~~~~~~~~~~~~
// ---------------- Funzione principale ----------------
  void Analysis(int i){
	  char so;
	  
	  cout << "Inserire un carattere per selezionare la cartella principale da cui prendere i file:\n";
	  cout << "- l per linux o ubuntu\n";
	  cout << "- w per windows\n";
	  cout << "- c per CERN\n";
	  cin >> so;
	  
//  TwoDim_Plots_40M_timing(i, type, min, max);
//  TwoDim_Plots_40M_timing_range(i);
//  TwoDim_Plots_20M_timing(i, type, min, max);
//  TwoDim_Plots_20M_timing(i);
//  TwoDim_Plots_If160_timing(i);
//  TwoDim_Plots_If40_timing(i);
//  TwoDim_Plots_If10_timing(i);
//  TwoDim_Plots_If40_20M_timing(i);
//  TwoDim_Plots_Pdoppi_20M_timing(i);
//  TwoDim_Plots_C4F_timing(i);
//  TwoDim_Plots_Vth90_timing(i);
//  TwoDim_Plots_Pmezzi_timing(i);
//  TwoDim_Plots_Pdoppi_timing(i);
//  TwoDim_Plots_Vthchange_20M_timing(i);
//  TwoDim_Plots_Vthchange1200_20M_timing(i);
//  TwoDim_Plots_sensore7_Board2(i);
//  TwoDim_Plots_sensore12_Board4(i);
//  TwoDim_Plots_sensore12_Board4_PILA(i);
  TwoDim_Plots_40M_timing_Vth(i,so);
}


// -----------------------------------------------------
// ---------------- Funzione principale ----------------
// -----------------------------------------------------

void TwoDim_Plots_40M_timing(int i, char so){
	
	//inizializzazione dei parametri
	float xmin = 30.;
	float xmax = 300.;
    float tmin = 30.;
    float tmax = 65.;
	float par0 = 40.;
	float par1 = 2.;
	float NEVT = 200.;
	
	int nfile = 0;
	
	TString Dir0;
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
	
	if(so == "l"){
		Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/TPphase-scan/"; 
	} 
	else if(so == "w"){
		Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";
	} 
	else if(so == "c"){
		Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
	}
		
	if(i != 30){
		Macro_scurve(Dir0,file[i],xmin,xmax,par0,par1,NEVT);
		analisiTHR2(Dir0,file[i],320,tmin,tmax,0.,10.,23.); 
		analisiMC(Dir0,file[i],60,20,80,1.,4.,type,min,max);
	}
	else{
		for(int j = 0; j < 18; j++){
			Macro_scurve(Dir0,file[j],xmin,xmax,par0,par1,NEVT);
			analisiTHR2(Dir0,file[j],320,tmin,tmax,0.,10.,23.); 
			analisiMC(Dir0,file[j],60,20,80,1.,4.,type,min,max);			
		}
	}
}


void TwoDim_Plots_40M_timing_Vth(int i, char so){
	
	//inizializzazione dei parametri
	float xmin = 30.;
	float xmax = 300.;
    float tmin = 30.;
    float tmax = 65.;
	float par0 = 40.;
	float par1 = 2.;
	float NEVT = 200.;
	
	int nfile = 0;
	
	TString Dir0, Dir;
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
	
	if(so == "l"){
		Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/VTH-scan/"; 
	} 
	else if(so == "w"){
		Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";
	} 
	else if(so == "c"){
		Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
	}
		
	if(i != 30){
		Dir = Dir0+"";
		Macro_scurve_Vth(Dir,file[i],xmin,xmax,par0,par1,NEVT);
		analisiTHR2(Dir,file[i],320,tmin,tmax,0.,10.,23.); 
		analisiMC(Dir,file[i],60,20,80,1.,4.);
		//analisiMC(Dir,file[i],60,20,80,1.,4.,type,min,max);
	}
	else{
		Dir = Dir0+"";
		for(int j = 0; j < 18; j++){
			Macro_scurve_Vth(Dir,file[j],xmin,xmax,par0,par1,NEVT);
			analisiTHR2(Dir,file[j],320,tmin,tmax,0.,10.,23.); 
			analisiMC(Dir,file[j],60,20,80,1.,4.,type,min,max);			
		}
	}
}
