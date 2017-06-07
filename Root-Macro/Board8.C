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

void Board8(){
//Dati presi in laboratorio:
//Tp = valore di TPphase a cui si prende la misura; l'errore su TP e' 0
//th = media della soglia ottenuta dal fit della distribuzione ad una determinata TPphase in elettroni
//eth = incertezza sulla media della soglia

float TP[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000};
float eTP[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float th[] = {48.27, 47.35, 46.75, 46.17, 45.69, 45.44, 45.36, 45.41, 45.79, 46.38, 47.29, 48.59, 50.15, 51.33, 51.83};
float eth[] ={0.09, 0.09, 0.09, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.09, 0.09, 0.10, 0.13, 0.11};

//no = media del rumore ottenuto dal fit della distribuzione
//eno = incertezza sulla media del rumore

float no[] = {1.853, 1.825, 1.782, 1.758, 1.735, 1.716, 1.715, 1.740, 1.773, 1.830, 1.913, 2.049, 2.218, 2.262, 2.041};
float eno[] = {0.004, 0.004, 0.004, 0.004, 0.004, 0.003, 0.003, 0.001, 0.003, 0.001, 0.003, 0.004, 0.004, 0.010, 0.006};

float q0;
const int nmisure = 15; //numero di misure effettuate

float q[nmisure]; //vettore carica iniettata
float sq[nmisure]; //errore sulla carica

float TPt[nmisure]; //vettore temporale in nanosecondi

for(int i = 0; i<nmisure; ++i){
	TPt[i] = TP[i]*25/3600;
	}

for(int i = 0; i<nmisure; ++i){
	q[i] = (th[i]*48.5)-1500;
	sq[i] = (eth[1]*48.5);
	if(i==0) q0 = q[0];
	else if(q[i]<q0) q0 = q[i];
	//q0 = i==0 ? q[0] : q[i];
	}
	/*
// cond ? comando true : comando false
int a=5;
int x = a<6 ? 1 : 0;
*/

float f[nmisure]; //funzionale normalizzata a se stessa
float ef[nmisure];

for(int i = 0; i<nmisure; ++i){
	f[i] = (q0)/q[i];
	ef[i] = ((q0)/pow(q[1],2))*sq[i];
}

cout<< "il valore minimo di carica iniettata e' " << q0 <<endl;

TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
csoglia -> cd();
TGraphErrors *gsoglia = new TGraphErrors(nmisure, TPt, q, eTP, sq);
gsoglia->SetMarkerSize(0.6);
gsoglia->SetMarkerStyle(21);
gsoglia->SetTitle("<Q_{in}>(TPphase)");
gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
gsoglia->GetYaxis()->SetTitle("<Q_{in}>");
//gsoglia->SetMarkerColor(kBlue);
gsoglia->Draw("AP");

/*
cout << "********** Fit soglia **********" << endl;
csoglia->cd();
cout << "********** Fit parabolico ********** " << endl;
TF1 *fitsoglia = new TF1("fitsoglia","pol2");
//TVirtualFitter::SetMaxInterations(100000);
gsoglia->Fit(fitsoglia,"M+");
cout << "Chi^2: " << fitsoglia->GetChisquare() << endl;
cout << "Probability: " << fitsoglia->GetProb() << endl;
cout << "number of DoF: " << fitsoglia->GetNDF() << endl;
*/

TCanvas *cfunzionale = new TCanvas("cfunzionale","f(TPphase)",200,50,600,400);
cfunzionale -> cd();
TGraphErrors *gfunzionale = new TGraphErrors(nmisure, TPt, f, eTP, ef);
gfunzionale->SetMarkerSize(0.6);
gfunzionale->SetMarkerStyle(21);
gfunzionale->SetTitle("F(TPphase)");
gfunzionale->GetXaxis()->SetTitle("TPphase [ns]");
gfunzionale->GetYaxis()->SetTitle("F");
//gfunzionale->SetMarkerColor(kBlue);
gfunzionale->Draw("AP");

cout<< "*********** FIT per FUNZIONALE ***********" << endl;
cfunzionale->cd();
cout << "********** Fit LINEARE ********** " << endl;


cout << "********** Fit GLOBALE ********** " << endl;
TF1 *fitf = new TF1("fitf","[0]*(-TMath::Exp(-[1]*x))+[2]*x+[3]");
//TVirtualFitter::SetMaxInterations(100000);
//fitf->SetParLimits(0,0,2);
fitf->SetParLimits(1,0.05,0.07);
gfunzionale->Fit(fitf,"M+");
cout << "Chi^2: " << fitf->GetChisquare() << endl;
cout << "Probability: " << fitf->GetProb() << endl;
cout << "Number of DoF: " << fitf->GetNDF() << endl;

csoglia->SaveAs("grafico_soglia_TPphase.pdf");

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