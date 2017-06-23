#include <iostream>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TMultiGraph.h>
#include <TVirtualFitter.h>
#include <TF1.h>
#include <TMath.h>
#include <TAxis.h>
#include <TFile.h>
#include <TFitResultPtr.h> 
#include <iomanip>
#include <TFitResult.h>

using namespace std;

void Board8_C4F_40M(){
//Dati presi in laboratorio:
//Tp = valore di TPphase a cui si prende la misura; l'errore su TP e' 0
//th = media della soglia ottenuta dal fit della distribuzione ad una determinata TPphase in elettroni
//eth = incertezza sulla media della soglia

float TP[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000, 3200, 3400, 3600};
float eTP[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float th[] = {48.21, 47.51, 46.86, 46.32, 45.91, 45.75, 45.70, 45.88, 46.28, 46.88, 47.79, 49.05, 50.23, 51.43, 51.91, 50.56, 49.89, 48.89};//50.64
float eth[] ={0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.09, 0.11, 0.11, 0.11, 0.10, 0.09};

//no = media del rumore ottenuto dal fit della distribuzione
//eno = incertezza sulla media del rumore

float no[] = {2.27, 2.20, 2.01, 2.16, 2.17, 2.16, 2.33, 2.51, 2.77, 3.21, 2.42};
float eno[] = {0.01, 0.21, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};

float q0;
const int nmisure = 18; //numero di misure effettuate

float q[nmisure]; //vettore carica iniettata in aC (dove a=10^(-18))
float sq[nmisure]; //errore sulla carica

float TPt[nmisure]; //vettore temporale in nanosecondi
cout<<"TP"<<endl;
for(int i = 0; i<nmisure; ++i){
	TPt[i] = 25 - TP[i]*25/3600;
	if(TPt[i]>5) TPt[i] = TPt[i];
	else TPt[i] = TPt[i] + 25;
//	TPt[i] = TP[i]*25/3600;
	cout<<TPt[i]<<endl;
	}
cout<<"CARICA"<<endl;
for(int i = 0; i<nmisure; ++i){
	q[i] = ((th[i]*48.5)-1500)*160/1000;
	sq[i] = (eth[i]*48.5)*160/1000;
	cout<<q[i]<<endl;
	if(i==0) q0 = q[0];
	else if(q[i]<q0) q0 = q[i];
	
	}
	

float f[nmisure]; //funzionale normalizzata a se stessa
float ef[nmisure];

for(int i = 0; i<nmisure; ++i){
	f[i] = (q0)/q[i];
	ef[i] = ((q0)/pow(q[1],2))*sq[i];
}

cout<< "IL VALORE MINIMO DI CARICA INIETTATA E' " << q0 << " aC "<<endl;

TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
csoglia -> cd();
TGraphErrors *gsoglia = new TGraphErrors(nmisure, TPt, q, eTP, sq);
gsoglia->SetMarkerSize(0.6);
gsoglia->SetMarkerStyle(21);
gsoglia->SetTitle("<Q_{in}>(TPphase)_{40 MHz} con C_{f} = 4 fF");
gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
gsoglia->GetYaxis()->SetTitle("<Q_{in}> [aC]");
//gsoglia->SetMarkerColor(kBlue);
gsoglia->Draw("AP");


cout << "********** Fit CARICA **********" << endl;
csoglia->cd();

// TF1 *fitQ = new TF1("fitQ","([0]-[1]*(x-[2]))/(1-TMath::Exp(-(x-[2])/[3]))+[4]",6,25);

//TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-[1]*TMath::Exp(-x/[2]))",8,25);

//TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",8,25);
TF1 *fitQ = new TF1("fitQ","[4]+([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",6,26);


//fitQ->SetParLimits(0,10,60);
fitQ->SetParLimits(1,-25.,25);

//fitQ->SetParLimits(1,0.5,7);
fitQ->SetParLimits( 2,4,25);
//fitQ->SetParLimits(3,7,12);


//TF1 *fitQ = new TF1("fitQ","([0]-[1]*x)/(1-TMath::Exp(-x/[2]+[3]))",6,25);
//TF1 *fitQ = new TF1("fitQ","([0]/([1]-[2]*(TMath::Exp(-[3]/x))+[4]*x))",6,25);
//TVirtualFitter::SetMaxInterations(100000);
gsoglia->Fit(fitQ,"MR");
//fitQ->SetParLimits(3,0.050,0.080);
cout << "Chi^2: " << fitQ->GetChisquare() << endl;
cout << "Probability: " << fitQ->GetProb() << endl;
cout << "number of DoF: " << fitQ->GetNDF() << endl;


TCanvas *cfunzionale = new TCanvas("cfunzionale","f(TPphase)",200,50,600,400);
cfunzionale -> cd();
TGraphErrors *gfunzionale = new TGraphErrors(nmisure, TPt, f, eTP, ef);
gfunzionale->SetMarkerSize(0.6);
gfunzionale->SetMarkerStyle(21);
gfunzionale->SetTitle("F(TPphase)_{40 MHz} con Cf = 4 fF");
gfunzionale->GetXaxis()->SetTitle("TPphase [ns]");
gfunzionale->GetYaxis()->SetTitle("F");
//gfunzionale->SetMarkerColor(kBlue);
gfunzionale->Draw("AP");

cout<< "*********** FIT per FUNZIONALE ***********" << endl;
cfunzionale->cd();


// TF1 *fitf = new TF1("fitf","[0]-[1]*(TMath::Exp(-[2]/x))+[3]*x",6,24);

TF1 *fitf = new TF1("fitf","([0]-[1]*(TMath::Exp(-[2]/x)))*(1-[3]*x)",5,24);


//TVirtualFitter::SetMaxInterations(100000);
//fitf->SetParLimits(0,0,6);
//fitf->SetParLimits(1,10,20);
//fitf->SetParLimits( 2,0,10);
//fitf->SetParLimits(3,0.01,0.05);
gfunzionale->Fit(fitf,"MR");
cout << "Chi^2: " << fitf->GetChisquare() << endl;
cout << "Probability: " << fitf->GetProb() << endl;
cout << "Number of DoF: " << fitf->GetNDF() << endl;

//csoglia->SaveAs("C:\local\ROOT\5.34\macros\macro-studenti\Q.pdf");
//bcfunzionale->SaveAs("C:\local\ROOT\5.34\macros\macro-studenti\F.pdf");


/* 
TCanvas *cnoise = new TCanvas("cnoise","noise(TPphase)",200,50,600,400);
cnoise -> cd();
TGraphErrors *gnoise = new TGraphErrors(nmisure, TP, no, eTP, eno);
gnoise->SetMarkerSize(0.6);
gnoise->SetMarkerStyle(21);
gnoise->SetTitle("<Noise>(TPphase)");
gnoise->GetXaxis()->SetTitle("TPphase");
gnoise->GetYaxis()->SetTitle("<Noise>");
//gnoise->SetMarkerColor(kBlue);
gnoise->Draw("AP");

cout << "********** Fit rumore **********" << endl;
cnoise->cd();
TF1 *fitnoise = new TF1("fitnoise","pol2");
//TVirtualFitter::SetMaxInterations(100000);
gnoise->Fit(fitnoise,"M+");
cout << "Chi^2: " << fitnoise->GetChisquare() << endl;
cout << "Probability: " << fitnoise->GetProb() << endl;
cout << "number of DoF: " << fitnoise->GetNDF() << endl;

cnoise->SaveAs("grafico_noise_TPphase.pdf");

*/
}