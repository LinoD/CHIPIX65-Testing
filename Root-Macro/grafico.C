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

 
using namespace std;

void grafico(){
	
	
	
	float TP1[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000, 3200, 3400, 3600};
	float TP2[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000, 3200, 3400, 3600};
	//float th1[] = {57.91, 76.30, 74.04, 70.56, 66.81, 62.94, 59.60, 53.42, 52.43,  50.53,  48.63,  46.55,  45.24,  44.31,  44.04, 44.61, 46.44, 50.08};
	float th1[] = {57.91, 76.30, 74.04, 70.56, 66.94, 62.94, 59.60, 53.42, 52.43, 50.53, 48.63, 46.55, 45.24, 44.31, 44.04, 44.61, 46.44, 50.08};
	float eth1[] = { 0.1  , 0.24, 0.19, 0.17, 0.16, 0.14, 0.34, 0.19, 0.11, 0.10, 0.10, 0.09, 0.08, 0.08, 0.08, 0.11, 0.30, 0.15};
	float th2[] = {  48.12, 47.68, 46.58, 46.31, 46.1043, 45.60, 45.67, 45.49, 45.82, 46.71, 47.63, 48.82, 50.63, 52.34, 52.58, 51.70, 50.42, 49.36};
	float eth2[] = {0.56, 0.56, 0.56, 0.47, 0.54, 0.50, 0.60, 0.50, 0.51, 0.50, 0.64, 0.80, 1.1, 1.2, 1.3, 0.73, 0.66, 0.76};
	float eTP1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	float eTP2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	//const float nmisure = 18;
	
	//float q1[nmisure], eq1[nmisure], q2[nmisure], eq2[nmisure];
	
	/*for(int i = 0; i < nmisure+1; i++){
		
		cout << th1[i] << "   " << th2[i]<< endl;
		TP1[i] = 25- TP1[i]*25/3600;
		TP2[i] = 25- TP2[i]*25/3600;
		//eTP1[i] = 0;
		//eTP2[i] = 0;
		q1[i] = ((th1*48.5)-1500)*160/1000;
		eq1[i] = (eth1*48.5)*160/1000;
		q2[i] = ((th2*48.5)-1500)*160/1000;
		eq2[i] = (eth2*48.5)*160/1000;
		
		cout<< TP1[i] << "   " << q1[i] << "   " << eq1[i] << "   " << TP2[i] << "   " << q2[i] << "   " << eq2[i] << endl;
	}*/
	
	const int nmisure = 18; //numero di misure effettuate

float q1[nmisure]; //vettore carica iniettata in aC (dove a=10^(-18))
float sq1[nmisure]; //errore sulla carica
float q2[nmisure]; //vettore carica iniettata in aC (dove a=10^(-18))
float sq2[nmisure]; //errore sulla carica

float TPt[nmisure];
float TPt2[nmisure]; //vettore temporale in nanosecondi
cout<<"TP"<<endl;
for(int i = 0; i<nmisure; ++i){
	TPt[i] = 25 - TP1[i]*25/3600;
	TPt2[i] = 25 - TP2[i]*25/3600;
    /*if(5 < TPt[i] ) TPt[i] = TPt[i];
	else TPt[i] = TPt[i] + 25;*/
	if(5 < TPt2[i] ) TPt2[i] = TPt2[i];
	else TPt2[i] = TPt2[i] + 25;
//	TPt[i] = TP[i]*25/3600;
	//cout<<TPt[i]<<endl;
	}
cout<<"CARICA"<<endl;
for(int i = 0; i<nmisure; ++i){
	q1[i] = ((th1[i]*48.5)-1500)*160/1000;
	sq1[i] = (eth1[1]*48.5)*160/1000;
	q2[i] = ((th2[i]*48.5)-1500)*160/1000;
	sq2[i] = (eth2[1]*48.5)*160/1000;
	//cout<<q[i]<<endl;
	/*if(i==0) q0 = q[0];
	else if(q[i]<q0) q0 = q[i];*/
	
	}
	
	
	TCanvas *carica = new TCanvas("carica","Q(t)",200,10,600,400);
	  carica->SetFillColor(0);
	  carica->cd();
	  
	  TMultiGraph *medie = new TMultiGraph();
	  
	  TGraphErrors *gcarica1 = new TGraphErrors(nmisure,TPt,q1,eTP1,sq1);
	  gcarica1->SetMarkerSize(0.6);
	  gcarica1->SetMarkerStyle(21);
	  gcarica1->SetMarkerColor(2);
	  medie->Add(gcarica1);
	  
	  TGraphErrors *gcarica2 = new TGraphErrors(nmisure,TPt2,q2,eTP2,sq2);
	  gcarica2->SetMarkerSize(0.6);
	  gcarica2->SetMarkerStyle(21);
	  gcarica2->SetMarkerColor(3);
	  medie->Add(gcarica2);
	  
	  medie->SetTitle("Q(TPphase);TPphase [nt];Q[aC]");
	  medie->Draw("AP");
  
}