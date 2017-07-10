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
#include <TGraphErrors.h>
#include <TFitResult.h>

void grafico(){
	
	const int nmisure = 18;
	
	float eTP[nmisure], q1[nmisure], eq1[nmisure], q2[nmisure], eq2[nmisure];
	
	float TP[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000, 3200, 3400, 3600};
	float th1[] = { 57.91 , 76.30  , 74.04  , 70.56  , 66.81  , 62.94  , 59.60  , 53.42  , 52.43  ,  50.53  ,  48.63  ,  46.55  ,  45.24  ,  44.31  ,  44.04  , 44.61 , 46.44 , 50.08};
	float eth1[] = { 0.1  , 0.24, 0.19, 0.17, 0.16, 0.14, 0.34, 0.19, 0.11, 0.10, 0.10, 0.09, 0.08, 0.08, 0.08, 0.11, 0.30, 0.15};
	float th2[] = {  48.12, 47.68, 46.58, 46.31, 46.1043, 45.60, 45.67, 45.49, 45.82, 46.71, 47.63, 48.82, 50.63, 52.34, 52.58, 51.70, 50.42, 49.36};
	float eth2[] = {0.56, 0.56, 0.56, 0.47, 0.54, 0.50, 0.60, 0.50, 0.51, 0.50, 0.64, 0.80, 1.1, 1.2, 1.3, 0.73, 0.66, 0.76};
	
	for(int i =0; i <19; i++){
		TP[i] = 25- TP[i]*25/3600;
		eTP[i] = 0;
		q1[i] = ((th1*48.5)-1500)*160/1000;
		eq1[i] = (eth1*48.5)*160/1000;
		q2[i] = ((th2*48.5)-1500)*160/1000;
		eq2[i] = (eth2*48.5)*160/1000;
	}
	
	
	TCanvas *carica = new TCanvas("carica","Q(t)",200,10,600,400);
	  carica->SetFillColor(0);
	  carica->cd();
	  
	  TMultiGraph *medie = new TMultiGraph();
	  
	  TGraphErrors *gcarica1 = new TGraphErrors(nmisure,TP,q1,eTP,eq1);
	  gcarica1->SetMarkerSize(0.6);
	  gcarica1->SetMarkerStyle(21);
	  gcarica1->SetMarkerColor(2);
	  medie->Add(gcarica1);
	  
	  TGraphErrors *gcarica2 = new TGraphErrors(nmisure,TP,q2,eTP,eq2);
	  gcarica2->SetMarkerSize(0.6);
	  gcarica2->SetMarkerStyle(21);
	  gcarica2->SetMarkerColor(3);
	  medie->Add(gcarica2);
	  
	  medie->SetTitle("Q(TPphase);TPphase [nt];Q[aC]");
	  medie->Draw("AP");
  
}