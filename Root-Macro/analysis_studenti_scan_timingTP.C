#include "Riostream.h"
// #include "fstream"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TF1.h"
#include "TMath.h"
#include "TString.h"
#include "TAxis.h"
#include "TFile.h"
// #include "vector"
#include "TStyle.h" 


//Analisi per ricavare i valori di soglie e rumore dei dati raccolti facendo variare la TPphase
//per richiamare dati a diverse frequenze guardare la funzione di analisi al fondo
//Controllare i diversi parametri per vedere se ci sono delle discrepanze tra i vari parametri 


void TwoDim_Plots_40M_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX_data/studenti/TPphase-scan/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170601004206_board8-CALsw-allch-TP200_001."; 
	   NEVT=200.;

    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170531191742_board8-CALsw-allch-TP400_000."; 
	   NEVT=200.;

    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170531194049_board8-CALsw-allch-TP600_000."; 
	   NEVT=200.;

    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170531200358_board8-CALsw-allch-TP800_000."; 
	   NEVT=200.;

    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170531202711_board8-CALsw-allch-TP1000_000."; 
	   NEVT=200.;

    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170601023819_board8-CALsw-allch-TP1200_001."; 
	   NEVT=200.;

    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170531211343_board8-CALsw-allch-TP1400_000."; 
	   NEVT=200.;

    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170531213700_board8-CALsw-allch-TP1600_000."; 
	   NEVT=200.;

    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170531220020_board8-CALsw-allch-TP1800_000."; 
	   NEVT=200.;

    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170531222337_board8-CALsw-allch-TP2000_000."; 
	   NEVT=200.;

    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170531224649_board8-CALsw-allch-TP2200_000."; 
	   NEVT=200.;

    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170531231001_board8-CALsw-allch-TP2400_000."; 
	   NEVT=200.;

    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170531233312_board8-CALsw-allch-TP2600_000."; 
	   NEVT=200.;

    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170531235613_board8-CALsw-allch-TP2800_000."; 
	   NEVT=200.;

    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170601001908_board8-CALsw-allch-TP3000_000."; 
	   NEVT=200.;

    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,40,20,60,1.,4.); 
	}
	}
}


void TwoDim_Plots_20M_timing(Int_t i)
{M
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX_data/studenti/TPphase-scan-20MHz/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170609032045_board8-CALsw-allch-TP200_002."; 
	   NEVT=50.;

    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170609033841_board8-CALsw-allch-TP400_002."; 
	   NEVT=50.;

    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170608203404_board8-CALsw-allch-TP600_000."; 
	   NEVT=50.;

    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170608205129_board8-CALsw-allch-TP800_000."; 
	   NEVT=50.;

    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170608210902_board8-CALsw-allch-TP1000_000."; 
	   NEVT=50.;

    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170608212630_board8-CALsw-allch-TP1200_000."; 
	   NEVT=50.;

    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170608214411_board8-CALsw-allch-TP1400_000."; 
	   NEVT=50.;

    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170608215647_board8-CALsw-allch-TP1600_000."; 
	   NEVT=50.;

    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170608220928_board8-CALsw-allch-TP1800_000."; 
	   NEVT=50.;

    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170608222208_board8-CALsw-allch-TP2000_000."; 
	   NEVT=50.;

    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170608224740_board8-CALsw-allch-TP2400_000."; 
	   NEVT=50.;

    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170609021557_board8-CALsw-allch-TP2200_001."; 
	   NEVT=50.;

    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170608230028_board8-CALsw-allch-TP2600_000."; 
	   NEVT=50.;

    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170608231319_board8-CALsw-allch-TP2800_000."; 
	   NEVT=50.;

    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170608232610_board8-CALsw-allch-TP3000_000."; 
	   NEVT=50.;

    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.); 
	}
	}
}

//Dati presi facendo variare la tensione ad un diverso valore di corrente di scarica Ifeed = 160 DAC
void TwoDim_Plots_If160_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Ifeed160/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
		 
   	   file =  "220170614222316_board8-CALsw-allch-TP1200_001."; 
	   NEVT=50.;

    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170614223825_board8-CALsw-allch-TP1400_001."; 
	   NEVT=50.;

    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170614224900_board8-CALsw-allch-TP1600_001."; 
	   NEVT=50.;

    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170614225947_board8-CALsw-allch-TP1800_001."; 
	   NEVT=50.;

    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170615021655_board8-CALsw-allch-TP2000_002."; 
	   NEVT=50.;

    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170615022743_board8-CALsw-allch-TP2200_002."; 
	   NEVT=50.;

    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170614233152_board8-CALsw-allch-TP2400_001."; 
	   NEVT=50.;

    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170614234238_board8-CALsw-allch-TP2600_001."; 
	   NEVT=50.;

    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170614235323_board8-CALsw-allch-TP2800_001."; 
	   NEVT=50.;

    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170615000402_board8-CALsw-allch-TP3000_001."; 
	   NEVT=50.;

    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170614215338_board8-CALsw-allch-TP3600_001."; 
	   NEVT=50.;

    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170615012926_board8-CALsw-allch-TP1200_002."; 
	   NEVT=50.;

    }
	
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.); 
	}
	}
}


void TwoDim_Plots_If40_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Ifeed40/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170615210326_board8-CALsw-allch-i40-TP200_003."; 
	   NEVT=50.;

    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170615211500_board8-CALsw-allch-i40-TP400_003."; 
	   NEVT=50.;

    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170615212701_board8-CALsw-allch-i40-TP600_003."; 
	   NEVT=50.;

    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170615213127_board8-CALsw-allch-i40-TP800_003."; 
	   NEVT=50.;

    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170615214253_board8-CALsw-allch-i40-TP1000_003."; 
	   NEVT=50.;

    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170615215454_board8-CALsw-allch-i40-TP12000_003."; 
	   NEVT=50.;

    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170615220656_board8-CALsw-allch-i40-TP1400_003."; 
	   NEVT=50.;

    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170615221527_board8-CALsw-allch-i40-TP1600_003."; 
	   NEVT=50.;

    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170615222400_board8-CALsw-allch-i40-TP1800_003."; 
	   NEVT=50.;

    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170615223232_board8-CALsw-allch-i40-TP2000_003."; 
	   NEVT=50.;

    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170615224104_board8-CALsw-allch-i40-TP2200_003."; 
	   NEVT=50.;

    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170615224934_board8-CALsw-allch-i40-TP2400_003."; 
	   NEVT=50.;

    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170615225805_board8-CALsw-allch-i40-TP2600_003."; 
	   NEVT=50.;

    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170615230636_board8-CALsw-allch-i40-TP2800_003."; 
	   NEVT=50.;

    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170615231507_board8-CALsw-allch-i40-TP3000_003."; 
	   NEVT=50.;

    }
	
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.); 
	}
	}
}

void Analysis(int i){

 
//  TwoDim_Plots_40M_timing(i);
//  TwoDim_Plots_20M_timing(i);
//  TwoDim_Plots_If160_timing(i);
  TwoDim_Plots_If40_timing(i);

}
