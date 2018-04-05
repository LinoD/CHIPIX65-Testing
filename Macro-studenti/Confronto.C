/*Grafici confronto
    
	autore: Cristina Sauda - cristina.sauda@edu.unito.it
	data creazione:  2018/04/02
	ultima modifica: 2018/04/02
	
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

void Confronto(){
	
	const int nmisure = 3;
	const int sA = 27.71;
	const int sAP = 22.63;
	
	float Capacity[nmisure], eC[nmisure], sdisp[nmisure], Guadagno[nmisure], errth[nmisure], eA101[nmisure], eB101[nmisure], eAP101[nmisure], eA102[nmisure], eB102[nmisure], eAP102[nmisure], eA103[nmisure], eB103[nmisure], eAP103[nmisure];
	
	Capacity[0]= 1.6;
	Capacity[1] = 2.4;
	Capacity[2] =4.;
	float Tensione[] = {60, 70, 110};

	float thA101[] = {334., 556., 739.};
	float sA101[] = {110., 136., 138.};
	float thB101[] = {311., 541., 749.};
	float sB101[] = {105., 133., 145.};
	float thAP101[] = {316., 563., 776.};
	float sAP101[] = {95., 122., 128.};
	
	for(int i = 0; i < nmisure; i++){
		eA101[i] = sA101[i]/sA;
		eB101[i] = sB101[i]/sA;
		eAP101[i] = sAP101[i]/sAP;
	}
	
	float thA102[] = {634., 712., 975.};
	float sA102[] = {109., 136., 170.};
	float thB102[] = {667., 709., 987.};
	float sB102[] = {103., 148., 188.};
	float thAP102[] = {636., 747., 1012.};
	float sAP102[] = {112., 129., 145.};
	
	for(int i = 0; i < nmisure; i++){
		eA102[i] = sA102[i]/sA;
		eB102[i] = sB102[i]/sA;
		eAP102[i] = sAP102[i]/sAP;
	}
	
	float thA103[] = {175., 335., 518.};
	float sA103[] = {108., 132., 164.};
	float thB103[] = {174., 327., 524.};
	float sB103[] = {109., 139., 177.};
	float thAP103[] = {188., 362., 562.};
	float sAP103[] = {97., 132., 161.};
	
	for(int i = 0; i < nmisure; i++){
		eA103[i] = sA103[i]/sA;
		eB103[i] = sB103[i]/sA;
		eAP103[i] = sAP103[i]/sAP;
	}
	
	for(int i =0; i<nmisure;i++){
		eC[i] = 0;
		sdisp[i] = 0.1*48.5;
		Guadagno[i] = 1./Capacity[i];
		Tensione[i] = Tensione[i]*0.160/200;
		errth[i] = 48.5;
	}
	
//-------------------------------------------------	
//---------- Confronto soglie - capacità ----------
//-------------------------------------------------

// ---------- CHIP 101 -----------

	TCanvas *cvs101 = new TCanvas("cvs101", "Confronto 101", 200, 10, 600, 400);
	cvs101-> SetFillColor(0);
	cvs101->cd();
	
	TMultiGraph *confrontoth101 = new TMultiGraph();
	
	TGraphErrors *gA101th = new TGraphErrors(nmisure, Capacity, thA101, eC, errth);
	gA101th->SetMarkerSize(1.);
	gA101th->SetMarkerStyle(21);
	gA101th->SetMarkerColor(2);
	confrontoth101->Add(gA101th);


	TGraphErrors *gB101th = new TGraphErrors(nmisure, Capacity, thB101, eC, errth);
	gB101th->SetMarkerSize(1.);
	gB101th->SetMarkerStyle(21);
	gB101th->SetMarkerColor(3);
	confrontoth101->Add(gB101th);
	
	
	TGraphErrors *gAP101th = new TGraphErrors(nmisure, Capacity, thAP101, eC, errth);
	gAP101th->SetMarkerSize(1.);
	gAP101th->SetMarkerStyle(21);
	gAP101th->SetMarkerColor(4);
	confrontoth101->Add(gAP101th);
	
	
	confrontoth101->Draw("AP");
	confrontoth101->SetTitle("Threshold(C) Chip101");
	confrontoth101->GetXaxis()->SetTitle("C  [fF]");
	confrontoth101->GetYaxis()->SetTitle("Th  [e]");
	
	cvs101->SaveAs(".pdf");
	
// ---------- CHIP 102 -----------

	TCanvas *cvs102 = new TCanvas("cvs102", "Confronto 102", 200, 10, 600, 400);
	cvs102-> SetFillColor(0);
	cvs102->cd();
	
	TMultiGraph *confrontoth102 = new TMultiGraph();
	
	TGraphErrors *gA102th = new TGraphErrors(nmisure, Capacity, thA102, eC, errth);
	gA102th->SetMarkerSize(1.);
	gA102th->SetMarkerStyle(21);
	gA102th->SetMarkerColor(2);
	confrontoth102->Add(gA102th);


	TGraphErrors *gB102th = new TGraphErrors(nmisure, Capacity, thB102, eC, errth);
	gB102th->SetMarkerSize(1.);
	gB102th->SetMarkerStyle(21);
	gB102th->SetMarkerColor(3);
	confrontoth102->Add(gB102th);
	
	
	TGraphErrors *gAP102th = new TGraphErrors(nmisure, Capacity, thAP102, eC, errth);
	gAP102th->SetMarkerSize(1.);
	gAP102th->SetMarkerStyle(21);
	gAP102th->SetMarkerColor(4);
	confrontoth102->Add(gAP102th);
	
	
	confrontoth102->Draw("AP");
	confrontoth102->SetTitle("Threshold(C) Chip102");
	confrontoth102->GetXaxis()->SetTitle("C  [fF]");
	confrontoth102->GetYaxis()->SetTitle("Th  [e]");
	
	cvs102->SaveAs(".pdf");
	
	// ---------- CHIP 103 -----------

	TCanvas *cvs103 = new TCanvas("cvs103", "Confronto 103", 200, 10, 600, 400);
	cvs103-> SetFillColor(0);
	cvs103->cd();
	
	TMultiGraph *confrontoth103 = new TMultiGraph();
	
	TGraphErrors *gA103th = new TGraphErrors(nmisure, Capacity, thA103, eC, errth);
	gA103th->SetMarkerSize(1.);
	gA103th->SetMarkerStyle(21);
	gA103th->SetMarkerColor(2);
	confrontoth103->Add(gA103th);


	TGraphErrors *gB103th = new TGraphErrors(nmisure, Capacity, thB103, eC, errth);
	gB103th->SetMarkerSize(1.);
	gB103th->SetMarkerStyle(21);
	gB103th->SetMarkerColor(3);
	confrontoth103->Add(gB103th);
	
	
	TGraphErrors *gAP103th = new TGraphErrors(nmisure, Capacity, thAP103, eC, errth);
	gAP103th->SetMarkerSize(1.);
	gAP103th->SetMarkerStyle(21);
	gAP103th->SetMarkerColor(4);
	confrontoth103->Add(gAP103th);
	
	
	confrontoth103->Draw("AP");
	confrontoth103->SetTitle("Threshold(C) Chip103");
	confrontoth103->GetXaxis()->SetTitle("C  [fF]");
	confrontoth103->GetYaxis()->SetTitle("Th  [e]");
	
	cvs103->SaveAs(".pdf");
	
//---------- Confronto dispersione - capacità ----------	
	
	TCanvas *cvs1 = new TCanvas("cvs1", "Confronto Dispersione", 200, 10, 600, 400);
	cvs1-> SetFillColor(0);
	cvs1->cd();
	
	TMultiGraph *confrontodisp = new TMultiGraph();
	
	TGraphErrors *gA101disp = new TGraphErrors(nmisure, Capacity, sA101, eC, sdisp);
	gA101disp->SetMarkerSize(1.);
	gA101disp->SetMarkerStyle(21);
	gA101disp->SetMarkerColor(2);
	confrontodisp->Add(gA101disp);


	TGraphErrors *gB101disp = new TGraphErrors(nmisure, Capacity, sB101, eC, sdisp);
	gB101disp->SetMarkerSize(1.);
	gB101disp->SetMarkerStyle(21);
	gB101disp->SetMarkerColor(3);
	confrontodisp->Add(gB101disp);
	
	
	TGraphErrors *gAP101disp = new TGraphErrors(nmisure, Capacity, sAP101, eC, sdisp);
	gAP101disp->SetMarkerSize(1.);
	gAP101disp->SetMarkerStyle(21);
	gAP101disp->SetMarkerColor(4);
	confrontodisp->Add(gAP101disp);
	
	
	confrontodisp->Draw("AP");
	confrontodisp->SetTitle("Dispersione(Guadagno)");
	confrontodisp->GetXaxis()->SetTitle("C  [fF]");
	confrontodisp->GetYaxis()->SetTitle("Dispersione  [e]");
	
	cvs1->SaveAs(".pdf");
	
//---------- Confronto dispersione - guadagno ----------		
	TCanvas *cvsG101 = new TCanvas("cvsG101", "Confronto Dispersione 101", 200, 10, 600, 400);
	cvsG101-> SetFillColor(0);
	cvsG101->cd();
	
	TMultiGraph *confrontoGuadagno = new TMultiGraph();
	
	TGraphErrors *gA101G = new TGraphErrors(nmisure, Guadagno, sA101, eC, sdisp);
	gA101G->SetMarkerSize(1.);
	gA101G->SetMarkerStyle(21);
	gA101G->SetMarkerColor(2);
	confrontoGuadagno->Add(gA101G);


	TGraphErrors *gB101G = new TGraphErrors(nmisure, Guadagno, sB101, eC, sdisp);
	gB101G->SetMarkerSize(1.);
	gB101G->SetMarkerStyle(21);
	gB101G->SetMarkerColor(3);
	confrontoGuadagno->Add(gB101G);
	
	
	TGraphErrors *gAP101G= new TGraphErrors(nmisure, Guadagno, sAP101, eC, sdisp);
	gAP101G->SetMarkerSize(1.);
	gAP101G->SetMarkerStyle(21);
	gAP101G->SetMarkerColor(4);
	confrontoGuadagno->Add(gAP101G);
	
	
	confrontoGuadagno->Draw("AP");
	confrontoGuadagno->SetTitle("Dispersione(Guadagno) Chip101");
	confrontoGuadagno->GetXaxis()->SetTitle("1/C  [1/fF]");
	confrontoGuadagno->GetYaxis()->SetTitle("Dispersione  [e]");
	
	cvsG101->SaveAs(".pdf");
	
	TCanvas *cvsG102 = new TCanvas("cvsG102", "Confronto Dispersione 102", 200, 10, 600, 400);
	cvsG102-> SetFillColor(0);
	cvsG102->cd();
	
	TMultiGraph *confrontoGuadagno102 = new TMultiGraph();
	
	TGraphErrors *gA102G = new TGraphErrors(nmisure, Guadagno, sA102, eC, sdisp);
	gA102G->SetMarkerSize(1.);
	gA102G->SetMarkerStyle(21);
	gA102G->SetMarkerColor(2);
	confrontoGuadagno102->Add(gA102G);


	TGraphErrors *gB102G = new TGraphErrors(nmisure, Guadagno, sB102, eC, sdisp);
	gB102G->SetMarkerSize(1.);
	gB102G->SetMarkerStyle(21);
	gB102G->SetMarkerColor(3);
	confrontoGuadagno102->Add(gB102G);
	
	
	TGraphErrors *gAP102G= new TGraphErrors(nmisure, Guadagno, sAP102, eC, sdisp);
	gAP102G->SetMarkerSize(1.);
	gAP102G->SetMarkerStyle(21);
	gAP102G->SetMarkerColor(4);
	confrontoGuadagno102->Add(gAP102G);
	
	
	confrontoGuadagno102->Draw("AP");
	confrontoGuadagno102->SetTitle("Dispersione(Guadagno) Chip102");
	confrontoGuadagno102->GetXaxis()->SetTitle("1/C  [1/fF]");
	confrontoGuadagno102->GetYaxis()->SetTitle("Dispersione  [e]");
	
	cvsG102->SaveAs(".pdf");
	
	TCanvas *cvsG103 = new TCanvas("cvsG103", "Confronto Dispersione 103", 200, 10, 600, 400);
	cvsG103-> SetFillColor(0);
	cvsG103->cd();
	
	TMultiGraph *confrontoGuadagno103 = new TMultiGraph();
	
	TGraphErrors *gA103G = new TGraphErrors(nmisure, Guadagno, sA103, eC, sdisp);
	gA103G->SetMarkerSize(1.);
	gA103G->SetMarkerStyle(21);
	gA103G->SetMarkerColor(2);
	confrontoGuadagno103->Add(gA103G);


	TGraphErrors *gB103G = new TGraphErrors(nmisure, Guadagno, sB103, eC, sdisp);
	gB103G->SetMarkerSize(1.);
	gB103G->SetMarkerStyle(21);
	gB103G->SetMarkerColor(3);
	confrontoGuadagno103->Add(gB103G);
	
	
	TGraphErrors *gAP103G= new TGraphErrors(nmisure, Guadagno, sAP103, eC, sdisp);
	gAP103G->SetMarkerSize(1.);
	gAP103G->SetMarkerStyle(21);
	gAP103G->SetMarkerColor(4);
	confrontoGuadagno103->Add(gAP103G);
	
	
	confrontoGuadagno103->Draw("AP");
	confrontoGuadagno103->SetTitle("Dispersione(Guadagno) Chip103");
	confrontoGuadagno103->GetXaxis()->SetTitle("1/C  [1/fF]");
	confrontoGuadagno103->GetYaxis()->SetTitle("Dispersione  [e]");
	
	cvsG103->SaveAs(".pdf");
	
//-------------------------------------------------	
//---------- Confronto soglia - tensione ----------	
//-------------------------------------------------
	
// Regione A	
	float VA1031[] = {175., 362., 640.};
	float VA1032[] = {335., 498., 1048.};
	float VA1033[] = {518., 701., 1419.};
	
	
	TCanvas *cvs3 = new TCanvas("cvs3", "Confronto tensione Discriminatore per la regione A", 200, 10, 600, 400);
	cvs3-> SetFillColor(0);
	cvs3->cd();
	
	TMultiGraph *confrontoVA = new TMultiGraph();
	
	TGraphErrors *gA103V1 = new TGraphErrors(nmisure, Tensione, VA1031, eC, errth);
	gA103V1->SetMarkerSize(1.);
	gA103V1->SetMarkerStyle(21);
	gA103V1->SetMarkerColor(2);
	TF1 *fitAV1 = new TF1("fitAV1","pol1");
	fitAV1->SetLineColor(2);
	gA103V1->Fit(fitAV1, "M+");
	cout << "Chi^2: " << fitAV1->GetChisquare() << endl;
  cout << "Probability: " << fitAV1->GetProb() << endl;
  cout << "number of DoF: " << fitAV1->GetNDF() << endl;
	confrontoVA->Add(gA103V1);


	TGraphErrors *gA103V2 = new TGraphErrors(nmisure, Tensione, VA1032, eC, errth);
	gA103V2->SetMarkerSize(1.);
	gA103V2->SetMarkerStyle(21);
	gA103V2->SetMarkerColor(3);
	TF1 *fitAV2 = new TF1("fitAV2","pol1");
	fitAV2->SetLineColor(3);
	gA103V2->Fit(fitAV2, "M+");
	cout << "Chi^2: " << fitAV2->GetChisquare() << endl;
  cout << "Probability: " << fitAV2->GetProb() << endl;
  cout << "number of DoF: " << fitAV2->GetNDF() << endl;
	confrontoVA->Add(gA103V2);
	
	
	TGraphErrors *gA103V3= new TGraphErrors(nmisure, Tensione, VA1033, eC, errth);
	gA103V3->SetMarkerSize(1.);
	gA103V3->SetMarkerStyle(21);
	gA103V3->SetMarkerColor(4);
	TF1 *fitAV3 = new TF1("fitBV1","pol1");
	fitAV3->SetLineColor(4);
	gA103V3->Fit(fitAV3, "M+");
	cout << "Chi^2: " << fitAV3->GetChisquare() << endl;
  cout << "Probability: " << fitAV3->GetProb() << endl;
  cout << "number of DoF: " << fitAV3->GetNDF() << endl;
	confrontoVA->Add(gA103V3);
	
	
	confrontoVA->Draw("AP");
	confrontoVA->SetTitle("Threshold(V_{th}) A");
	confrontoVA->GetXaxis()->SetTitle("V_{th}  [V]");
	confrontoVA->GetYaxis()->SetTitle("Th  [e]");
	
	cvs3->SaveAs(".pdf");
	
// Regione B	
	float VB1031[] = {174., 353., 650.};
	float VB1032[] = {327., 499., 1051.};
	float VB1033[] = {524., 701., 1435.};
	 
	TCanvas *cvs4 = new TCanvas("cvs4", "Confronto tensione Discriminatore per la regione B", 200, 10, 600, 400);
	cvs4-> SetFillColor(0);
	cvs4->cd();
	
	TMultiGraph *confrontoVB = new TMultiGraph();
	
	TGraphErrors *gB103V1 = new TGraphErrors(nmisure, Tensione, VB1031, eC, errth);
	gB103V1->SetMarkerSize(1.);
	gB103V1->SetMarkerStyle(21);
	gB103V1->SetMarkerColor(2);
	TF1 *fitBV1 = new TF1("fitBV1","pol1");
	fitBV1->SetLineColor(2);
	gB103V1->Fit(fitBV1, "M+");
	cout << "Chi^2: " << fitBV1->GetChisquare() << endl;
  cout << "Probability: " << fitBV1->GetProb() << endl;
  cout << "number of DoF: " << fitBV1->GetNDF() << endl;
	confrontoVB->Add(gB103V1);


	TGraphErrors *gB103V2 = new TGraphErrors(nmisure, Tensione, VB1032, eC, errth);
	gB103V2->SetMarkerSize(1.);
	gB103V2->SetMarkerStyle(21);
	gB103V2->SetMarkerColor(3);
	TF1 *fitBV2 = new TF1("fitBV2","pol1");
	fitBV2->SetLineColor(3);
	gB103V2->Fit(fitBV2, "M+");
	cout << "Chi^2: " << fitBV2->GetChisquare() << endl;
  cout << "Probability: " << fitBV2->GetProb() << endl;
  cout << "number of DoF: " << fitBV2->GetNDF() << endl;
	confrontoVB->Add(gB103V2);
	
	
	TGraphErrors *gB103V3= new TGraphErrors(nmisure, Tensione, VB1033, eC, errth);
	gB103V3->SetMarkerSize(1.);
	gB103V3->SetMarkerStyle(21);
	gB103V3->SetMarkerColor(4);
	TF1 *fitBV3 = new TF1("fitBV3","pol1");
	fitBV3->SetLineColor(4);
	gB103V3->Fit(fitBV3, "M+");
	cout << "Chi^2: " << fitBV3->GetChisquare() << endl;
  cout << "Probability: " << fitBV3->GetProb() << endl;
  cout << "number of DoF: " << fitBV3->GetNDF() << endl;
	confrontoVB->Add(gB103V3);
	
	
	confrontoVB->Draw("AP");
	confrontoVB->SetTitle("Threshold(V_{th}) B");
	confrontoVB->GetXaxis()->SetTitle("V_{th}  [V]");
	confrontoVB->GetYaxis()->SetTitle("Th  [e]");
	
	cvs4->SaveAs(".pdf");
	
// Regione A'	
	float VAP1031[] = {188., 344., 675.};
	float VAP1032[] = {362., 535., 1099.};
	float VAP1033[] = {562., 745., 1496.};
	 
	TCanvas *cvs5 = new TCanvas("cvs5", "Confronto tensione Discriminatore per la regione A'", 200, 10, 600, 400);
	cvs5-> SetFillColor(0);
	cvs5->cd();
	
	TMultiGraph *confrontoVAP = new TMultiGraph();
	
	TGraphErrors *gAP103V1 = new TGraphErrors(nmisure, Tensione, VAP1031, eC, errth);
	gAP103V1->SetMarkerSize(1.);
	gAP103V1->SetMarkerStyle(21);
	gAP103V1->SetMarkerColor(2);
	TF1 *fitAPV1 = new TF1("fitAPV1","pol1");
	fitAPV1->SetLineColor(2);
	gAP103V1->Fit(fitAPV1, "M+");
	cout << "Chi^2: " << fitAPV1->GetChisquare() << endl;
  cout << "Probability: " << fitAPV1->GetProb() << endl;
  cout << "number of DoF: " << fitAPV1->GetNDF() << endl;
	confrontoVAP->Add(gAP103V1);


	TGraphErrors *gAP103V2 = new TGraphErrors(nmisure, Tensione, VAP1032, eC, errth);
	gAP103V2->SetMarkerSize(1.);
	gAP103V2->SetMarkerStyle(21);
	gAP103V2->SetMarkerColor(3);
	TF1 *fitAPV2 = new TF1("fitAPV2","pol1");
	fitAPV2->SetLineColor(3);
	gAP103V2->Fit(fitAPV2, "M+");
	cout << "Chi^2: " << fitAPV2->GetChisquare() << endl;
  cout << "Probability: " << fitAPV2->GetProb() << endl;
  cout << "number of DoF: " << fitAPV2->GetNDF() << endl;
	confrontoVAP->Add(gAP103V2);
	
	
	TGraphErrors *gAP103V3= new TGraphErrors(nmisure, Tensione, VAP1033, eC, errth);
	gAP103V3->SetMarkerSize(1.);
	gAP103V3->SetMarkerStyle(21);
	gAP103V3->SetMarkerColor(4);
	TF1 *fitAPV3 = new TF1("fitAPV3","pol1");
	fitAPV3->SetLineColor(4);
	gAP103V3->Fit(fitAPV3, "M+");
	cout << "Chi^2: " << fitAPV3->GetChisquare() << endl;
  cout << "Probability: " << fitAPV3->GetProb() << endl;
  cout << "number of DoF: " << fitAPV3->GetNDF() << endl;
	confrontoVAP->Add(gAP103V3);
	
	
	confrontoVAP->Draw("AP");
	confrontoVAP->SetTitle("Threshold(V_{th}) A'");
	confrontoVAP->GetXaxis()->SetTitle("V_{th}  [V]");
	confrontoVAP->GetYaxis()->SetTitle("Th  [e]");
	
	cvs5->SaveAs(".pdf");
}
