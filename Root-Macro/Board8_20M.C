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

void Board8_20M(){
//Dati presi in laboratorio:
//Tp = valore di TPphase a cui si prende la misura; l'errore su TP e' 0
//th = media della soglia ottenuta dal fit della distribuzione ad una determinata TPphase in elettroni
//eth = incertezza sulla media della soglia

float TP[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000};
float eTP[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float th[] = {58.03, 76.17, 73.68, 70.21, 67.42, 62.92, 59.47, 54.8, 53.00, 50.50, 48.57, 46.52, 45.25, 44.27, 44.15};
float eth[] ={0.14, 0.23, 0.19, 0.17, 0.28, 0.14, 0.35, 3.3, 0.32, 0.10, 0.10, 0.10, 0.08, 0.08, 0.08};
//float eth[] ={4.3, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2};


//no = media del rumore ottenuto dal fit della distribuzione
//eno = incertezza sulla media del rumore

float no[] = {3.18, 2.31, 2.16, 1.758, 1.735, 1.716, 1.715, 1.740, 1.773, 1.830, 1.913, 2.049, 2.218, 2.262, 2.041};
float eno[] = {0.27, 0.43, 0.01, 0.004, 0.004, 0.003, 0.003, 0.001, 0.003, 0.001, 0.003, 0.004, 0.004, 0.010, 0.006};

float q0;
const int nmisure = 15; //numero di misure effettuate

float q[nmisure]; //vettore carica iniettata in aC (dove a=10^(-18))
float sq[nmisure]; //errore sulla carica

float TPt[nmisure]; //vettore temporale in nanosecondi
cout<<"TP"<<endl;
for(int i = 0; i<nmisure; ++i){
	TPt[i] = 50 - TP[i]*50/3600;
	cout<<TPt[i]<<endl;
	}
cout<<"CARICA"<<endl;
for(int i = 0; i<nmisure; ++i){
	q[i] = ((th[i]*48.5)-1500)*160/1000;
	sq[i] = (eth[1]*48.5)*160/1000;
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

TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)_{20 MHz}",200,50,600,400);
csoglia -> cd();
TGraphErrors *gsoglia = new TGraphErrors(nmisure, TPt, q, eTP, sq);
gsoglia->SetMarkerSize(0.6);
gsoglia->SetMarkerStyle(21);
gsoglia->SetTitle("<Q_{in}>(TPphase)_{20 MHz}");
gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
gsoglia->GetYaxis()->SetTitle("<Q_{in}> [aC]");
//gsoglia->SetMarkerColor(kBlue);
gsoglia->Draw("AP");

/*
cout << "********** Fit CARICA **********" << endl;
csoglia->cd();
TF1 *fitQ = new TF1("fitQ","([0]-[1]*(x-[2]))/(1-TMath::Exp(-(x-[2])/[3]))+[4]",6,45);
//TF1 *fitQ = new TF1("fitQ","([0]-[1]*x)/(1-TMath::Exp(-x/[2]+[3]))",6,25);
//TF1 *fitQ = new TF1("fitQ","([0]-[1]*x)/(1-TMath::Exp(-x/[2]+[3]))",6,25);
//TVirtualFitter::SetMaxInterations(100000);
gsoglia->Fit(fitQ,"MR");
//fitQ->SetParLimits(3,0.050,0.080);
cout << "Chi^2: " << fitQ->GetChisquare() << endl;
cout << "Probability: " << fitQ->GetProb() << endl;
cout << "number of DoF: " << fitQ->GetNDF() << endl;
*/

TCanvas *cfunzionale = new TCanvas("cfunzionale","f(TPphase)_{20 MHz}",200,50,600,400);
cfunzionale -> cd();
TGraphErrors *gfunzionale = new TGraphErrors(nmisure, TPt, f, eTP, ef);
gfunzionale->SetMarkerSize(0.6);
gfunzionale->SetMarkerStyle(21);
gfunzionale->SetTitle("F(TPphase)_{20 MHz}");
gfunzionale->GetXaxis()->SetTitle("TPphase [ns]");
gfunzionale->GetYaxis()->SetTitle("F");
//gfunzionale->SetMarkerColor(kBlue);
gfunzionale->Draw("AP");



cout<< "*********** FIT per FUNZIONALE ***********" << endl;
cfunzionale->cd();


//TF1 *fitf = new TF1("fitf","[0]-[1]*(TMath::Exp(-[2]/x))+[3]*x",6,45);
//TF1 *fitf = new TF1("fitf","[0]+[1]*(TMath::Exp(-[2]/x))+[3]*x",6,45);
//TVirtualFitter::SetMaxInterations(100000);
//fitf->SetParLimits(0,0,6);
//fitf->SetParLimits(1,10,20);
//fitf->SetParameter(2,14.25);
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