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

//Inserire il parametro di analisi che si vuole effettuare:
// 0 se si vuole l'analisis su tutti i pixel del chip
// 1 se si vuole fare l'analisi di una regione di pixel
// 2 se si vuole fare l'analisi di alcune righe del chip

//void TwoDim_Plots_40M_timing(Int_t i, Int_t type, Int_t min, Int_t max)
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
  
  Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";
  //Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/TPphase-scan/"; 
  
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
      
      if (it==16	) {  par0=40; 
	
	file =  "20170706095228_board8-CALsw-allch-TP3200_002."; 
	NEVT=200.;
	
      }
      
      if (it==17	) {  par0=40; 
	
	file =  "20170706111354_board8-CALsw-allch-TP3400_004."; 
	NEVT=200.;
	
      }
      
      if (it==18	) {  par0=40; 
	
	file =  "20170706112546_board8-CALsw-allch-TP3600_004."; 
	NEVT=200.;
	
      }
      
      Dir = Dir0+"";	
      
      Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
      analisiMC(Dir,file,60,20,80,1.,4.); 
      //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max); 
      
    }
    //FileOutRes(Dir,file,i);
  }
}


void TwoDim_Plots_40M_timing_Vth(Int_t i, Int_t type, Int_t min, Int_t max)
//void TwoDim_Plots_40M_timing_Vth(Int_t i)
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
  
  //	Dir0 = "C:/Users/CHIPIX65/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";
  Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/VTH-scan/"; 
  
  it=0;
  Float_t tmax,tmin;
  tmin=30.;
  tmax=65;
  
  while ( it<20 )  {
    it++;
    if (it==i ) {
      
      if (it==1 ) {  par0=40; 
	
	file =  "20180215215712_board8-VTHsw-allch-TP0_001."; 
	NEVT=200.;
	
      }
      if (it==2 ) {  par0=40; 
	
	file =  "20180215221204_board8-VTHsw-allch-TP200_001."; 
	NEVT=200.;
	
      }
      if (it==3 ) {  par0=40; 
	
	file =  "20180215222655_board8-VTHsw-allch-TP400_001."; 
	NEVT=200.;
	
      }
      
      if (it==4	) {  par0=40; 
	
	file = "20180215224146_board8-VTHsw-allch-TP600_001."; 
	NEVT=200.;
	
    }
      if (it==5	) {  par0=40; 
	
	file =  "20180215225644_board8-VTHsw-allch-TP800_001."; 
	NEVT=200.;
	
      }
      
      if (it==6 ) {  par0=40; 
	
	file =  "20180215231140_board8-VTHsw-allch-TP1000_001."; 
	NEVT=200.;
	
      }
      if (it==7	) {  par0=40; 
	
	file =  "20180215232641_board8-VTHsw-allch-TP1200_001."; 
	NEVT=200.;
	
      }
      
      
      if (it==8	) {  par0=40; 
		 
	file =  "20180215234143_board8-VTHsw-allch-TP1400_001.";
	NEVT=200.;
	
      }
      
      if (it==9	) {  par0=40; 
	
	file =  "20180215235644_board8-VTHsw-allch-TP1600_001.";
	NEVT=200.;
	
      }
	
      if (it==10	) {  par0=40; 
	
	file =  "20180216001147_board8-VTHsw-allch-TP1800_001.";  
	NEVT=200.;
	
      }
      
      if (it==11	) {  par0=40; 
	
	file = "20180216002647_board8-VTHsw-allch-TP2000_001."; 
	NEVT=200.;
	
      }
      
      if (it==12	) {  par0=40; 
	
	file =  "20180216004144_board8-VTHsw-allch-TP2200_001."; 
	NEVT=200.;
	
      }
      
      if (it==13	) {  par0=40; 
		 
	file =  "20180216005633_board8-VTHsw-allch-TP2400_001."; 
	NEVT=200.;
	
      }
      
      if (it==14	) {  par0=40; 
	
	file =  "20180216010330_board8-VTHsw-allch-TP2600_001."; 
	NEVT=200.;
	
      }
      
      if (it==15	) {  par0=40; 
	
	file =  "20180216011808_board8-VTHsw-allch-TP2800_001."; 
	NEVT=200.;
	
      }
      
      if (it==16	) {  par0=40; 
	
	file =  "20180216013245_board8-VTHsw-allch-TP3000_001."; 
	NEVT=200.;
	
      }
      
      if (it==17	) {  par0=40; 
	
	file =  "20180216015601_board8-VTHsw-allch-TP3200_001."; 
	NEVT=200.;
	
      }
      
      if (it==18	) {  par0=40; 
	
	file =  "20180216021051_board8-VTHsw-allch-TP3400_001.";
	NEVT=200.;
	
      }
      
      if (it==19	) {  par0=40; 
	
	file =  "20180216022544_board8-VTHsw-allch-TP3600_001."; 
	NEVT=200.;
	
      }
      
      
      Dir = Dir0+"";	
      Macro_scurve_Vth(Dir,file,xmin,xmax,par0,par1,NEVT);
      analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
      analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
      //analisiMC(Dir,file,100,80,200,1.,8.);
      
    }
    //FileOutRes(Dir,file,i);
  }
}

void TwoDim_Plots_40M_timing_loop(Int_t type, Int_t min, Int_t max)
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
  Dir0 = "/home/mimosa/GitHub/CHIPIX65-Testing/data/VTH-scan/";	
  
  it=0;
  int t;
  Float_t tmax,tmin;
  tmin=30.;
  tmax=65;
  //file="pippo";
  
  TString output_filename2, filename,Resfile2;
  
  Resfile2 = Dir0+"Out/"+"Result.txt" ;
  cout << " file to be opened " << Resfile2 << endl;
  ofstream output_file2(Resfile2);
  
  if (output_file2.is_open())
    { cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
  else 
    { cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
      return; }
  
  float mean0 ;
  int n_entries2 ;
  
  
  
  it=0;
  for(it=1;it<19;it++){
    
      
      if (it==1 ) {  par0=40; 
	
	file =  "20180215215712_board8-VTHsw-allch-TP0_001."; 
	NEVT=200.;
	
      }
      if (it==2 ) {  par0=40; 
	
	file =  "20180215221204_board8-VTHsw-allch-TP200_001."; 
	NEVT=200.;
	
      }
      if (it==3 ) {  par0=40; 
	
	file =  "20180215222655_board8-VTHsw-allch-TP400_001."; 
	NEVT=200.;
	
      }
      
      if (it==4	) {  par0=40; 
	
	file = "20180215224146_board8-VTHsw-allch-TP600_001."; 
	NEVT=200.;
	
    }
      if (it==5	) {  par0=40; 
	
	file =  "20180215225644_board8-VTHsw-allch-TP800_001."; 
	NEVT=200.;
	
      }
      
      if (it==6 ) {  par0=40; 
	
	file =  "20180215231140_board8-VTHsw-allch-TP1000_001."; 
	NEVT=200.;
	
      }
      if (it==7	) {  par0=40; 
	
	file =  "20180215232641_board8-VTHsw-allch-TP1200_001."; 
	NEVT=200.;
	
      }
      
      
      if (it==8	) {  par0=40; 
		 
	file =  "20180215234143_board8-VTHsw-allch-TP1400_001.";
	NEVT=200.;
	
      }
      
      if (it==9	) {  par0=40; 
	
	file =  "20180215235644_board8-VTHsw-allch-TP1600_001.";
	NEVT=200.;
	
      }
	
      if (it==10	) {  par0=40; 
	
	file =  "20180216001147_board8-VTHsw-allch-TP1800_001.";  
	NEVT=200.;
	
      }
      
      if (it==11	) {  par0=40; 
	
	file = "20180216002647_board8-VTHsw-allch-TP2000_001."; 
	NEVT=200.;
	
      }
      
      if (it==12	) {  par0=40; 
	
	file =  "20180216004144_board8-VTHsw-allch-TP2200_001."; 
	NEVT=200.;
	
      }
      
      if (it==13	) {  par0=40; 
		 
	file =  "20180216005633_board8-VTHsw-allch-TP2400_001."; 
	NEVT=200.;
	
      }
      
      if (it==14	) {  par0=40; 
	
	file =  "20180216010330_board8-VTHsw-allch-TP2600_001."; 
	NEVT=200.;
	
      }
      
      if (it==15	) {  par0=40; 
	
	file =  "20180216011808_board8-VTHsw-allch-TP2800_001."; 
	NEVT=200.;
	
      }
      
      if (it==16	) {  par0=40; 
	
	file =  "20180216013245_board8-VTHsw-allch-TP3000_001."; 
	NEVT=200.;
	
      }
      
      if (it==17	) {  par0=40; 
	
	file =  "20180216015601_board8-VTHsw-allch-TP3200_001."; 
	NEVT=200.;
	
      }
      
      if (it==18	) {  par0=40; 
	
	file =  "20180216021051_board8-VTHsw-allch-TP3400_001.";
	NEVT=200.;
	
      }
      
      if (it==19	) {  par0=40; 
	
	file =  "20180216022544_board8-VTHsw-allch-TP3600_001."; 
	NEVT=200.;
	
      }
    
    Dir = Dir0+"";	
    
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    //analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    
    
    analisiMC(Dir,file,200,20,220,1.,4.,type,min,max); 
    
    
    n_entries2 = histo_thr->GetEntries();
    
    
    mean0 = histo_thr->GetMean();
    
    if(n_entries2 > 50){
      //  f1thr->GetParameter(0)
      output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
    }
    else {
      //  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
      output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
    }
    
  }
  grafico_VTh(Dir,Resfile2);
}



void Analysis(int i,int type,int min, int max){
//void Analysis(int i){
  //  TwoDim_Plots_40M_timing(i, type, min, max);
  //TwoDim_Plots_40M_timing(i);
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
  //TwoDim_Plots_40M_timing_Vth(i);
  TwoDim_Plots_40M_timing_Vth(i,  type,  min,  max);
}

void Analysis_loop(int type,int min, int max){

    TwoDim_Plots_40M_timing_loop(type, min, max);
  //  TwoDim_Plots_If160_timing_loop(type, min, max);
  //  TwoDim_Plots_If40_timing_loop(type, min, max);
  //  TwoDim_Plots_If10_timing_loop(type, min, max);
  //  TwoDim_Plots_C4F_timing_loop(type, min, max);
  //  TwoDim_Plots_Vth90_timing_loop(type, min, max);
  //  TwoDim_Plots_Pmezzi_timing_loop(type, min, max);
  //  TwoDim_Plots_Pdoppi_timing_loop(type, min, max);
  //  TwoDim_Plots_20M_timing_loop(type, min, max);
  // TwoDim_Plots_If40_20M_timing_loop(type, min, max);
  //  TwoDim_Plots_Pdoppi_20M_timing_loop(type, min, max);
  //  TwoDim_Plots_Vthchange_20M_timing_loop(type, min, max);
  //  TwoDim_Plots_Vthchange1200_20M_timing_loop(type, min, max);
}




void grafico(TString Dir, TString filename){
  
  //const float nmisure = 18;
	
  
  ifstream in(filename);
  if(!in){
    cout<<"Il file"<<filename<<"non esiste"<<endl;
    return;
  }
  
  /*
    ifstream file(filename);
    if (file.is_open())
    { cout << "The file: " << filename << " IS OPEN " << "\n"; }
    else 
    { cout << "The file: " << filename << " IS NOT OPEN " << "\n";
    return;}
  */
  const int n = 18;
  int nmisure = 0;
  float t,thr,ethr,sr,esr, tm, q, sq;
  float TP[n], eTP[n], th[n], eth[n];
  /*
    vector<int> TPphase;
    vector<float> th;
    vector<float> eth;
    vector<float> s;
    vector<float> es;	
  */
  while (in >> t)  {
    //     if((in >> x )){
    
    //       npix.push_back(x);
    in >> thr;
    //        thr.push_back(y);
    in >> ethr;
    //        noise.push_back(z);
    in >> sr;
    in >> esr;
    
    //tm = 25 - t*25/3600;
    tm = 50 - t*50/3600;
    /*if (tm > 5 )  tm=tm;
      else tm = tm + 25;*/
    
    q = ((thr*48.5)-1500)*1.6*pow(10.,-19);
    sq = (ethr*48.5-1500)*1.6*pow(10.,-19);
    //              x=x+2;
    
    /*float qDAC = 70.;
      float q_c;
      q_c = ((qDAC*48.5)-1500.)*1.6*pow(10.,-19.);
      cout << "/n" << q_c << "/n" << endl;
      
      float c = 2.4*pow(10.,-15.);
    */
    /*
      TPphase.push_back(tm);
      th.push_back(q);
      eth.push_back(sq);
      s.push_back(sr);
      es.push_back(0);
      nmisure++;*/
    
    TP[nmisure] = tm;
    eTP[nmisure] = 0;
    th[nmisure] = q;
    eth[nmisure] = sq;
    nmisure++;
    
    //cout << tm << " " <<q << " " << sq << endl;
  }
  //cout << t << " " <<thr << " " << sr << endl;  
  
  TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
  csoglia -> cd();
  TGraphErrors *gsoglia = new TGraphErrors(nmisure, TP, th, eTP, eth);
  gsoglia->SetMarkerSize(0.6);
  gsoglia->SetMarkerStyle(21);
  gsoglia->SetTitle("<Q_{in}>(TPphase)_{20 MHz}");
  gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
  gsoglia->GetYaxis()->SetTitle("<Q_{in}> [aC]");
  //gsoglia->SetMarkerColor(kBlue);
  gsoglia->Draw("AP");
  
  csoglia->cd();
  
  TF1 *fitQ = new TF1("fitQ","[4]+([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",5,31.6);
  //TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);
  
  //	fitQ->SetParLimits(0,10.0,100.0);
  //	fitQ->SetParLimits(1,-5.0,25.0);
  fitQ->SetParLimits(2,5.0,30.0);
  //	fitQ->SetParLimits(3,0.5,20.0);
  //fitQ->SetParLimits(4,7,12);
  
  //TVirtualFitter::SetMaxInterations(100000);
  gsoglia->Fit(fitQ,"MR");
  //fitQ->SetParLimits(3,0.050,0.080);
  cout << "Chi^2: " << fitQ->GetChisquare() << endl;
  cout << "Probability: " << fitQ->GetProb() << endl;
  cout << "number of DoF: " << fitQ->GetNDF() << endl;
  /*
    float TP[nmisure], eTP[nmisure], th[nmisure], eth[nmisure];
    
    TString dummy, dummy1, dummy2, dummy3, dummy4;
    
    cout << " Reading file : " << filename << "\n"; 
    file >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy; 
    //	file >> dummy >> dummy >> dummy >> dummy ; 
    cout << dummy1 << dummy2 << dummy3 << dummy4 << "\n";
  */
  
}

void grafico_VTh(TString Dir, TString filename){
  
  //const float nmisure = 18;
  
  
  ifstream in(filename);
  if(!in){
    cout<<"Il file"<<filename<<"non esiste"<<endl;
    return;
  }
  
  /*
    ifstream file(filename);
    if (file.is_open())
    { cout << "The file: " << filename << " IS OPEN " << "\n"; }
    else 
    { cout << "The file: " << filename << " IS NOT OPEN " << "\n";
    return;}
  */
  const int n = 18;
  int nmisure = 0;
  float t,thr,ethr,sr,esr, tm, vth, svth;
  float TP[n], eTP[n], th[n], eth[n];
  /*
    vector<int> TPphase;
    vector<float> th;
    vector<float> eth;
    vector<float> s;
    vector<float> es;	
  */
  while (in >> t)  {
    //     if((in >> x )){
    
    //       npix.push_back(x);
    in >> thr;
    //        thr.push_back(y);
    in >> ethr;
    //        noise.push_back(z);
    in >> sr;
    in >> esr;
    
    //tm = 25 - t*25/3600;
    tm = 50 - t*50/3600;
    /*if (tm > 5 )  tm=tm;
      else tm = tm + 25;*/
    /*
      q = ((thr*48.5)-1500)*160/1000;
      sq = (ethr*48.5-1500)*160/1000;
    */
    vth = thr*0.106/200 +0.49;
    svth = ethr*0.106/200;
    //              x=x+2;
    /*
      TPphase.push_back(tm);
      th.push_back(q);
      eth.push_back(sq);
      s.push_back(sr);
      es.push_back(0);
      nmisure++;*/
    
    TP[nmisure] = tm;
    eTP[nmisure] = 0;
    th[nmisure] = vth;
    eth[nmisure] = svth;
    nmisure++;
    
    //cout << tm << " " <<q << " " << sq << endl;
  }
  //cout << t << " " <<thr << " " << sr << endl;  
  
  TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
  csoglia -> cd();
  TGraphErrors *gsoglia = new TGraphErrors(nmisure, TP, th, eTP, eth);
  gsoglia->SetMarkerSize(0.6);
  gsoglia->SetMarkerStyle(21);
  gsoglia->SetTitle("<V_{th}>(TPphase)_{20 MHz}");
  gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
  gsoglia->GetYaxis()->SetTitle("<V_{th}> [mV]");
  //gsoglia->SetMarkerColor(kBlue);
  gsoglia->Draw("AP");
  
  csoglia->cd();
  
  float qDAC = 70.;
  float q_c;
  q_c = ((qDAC*48.5)-1500.)*1.6*pow(10.,-19.);
  cout << "/n" << q_c << "/n" << endl;
  
  float c = 2.4*pow(10.,-15.);
  
  //TF1 *fitV = new TF1("fitV","[0]*(1 + TMath::Exp(-(x-[1])/[2]))+[3]*(x+[1])+[4]",8,31.6);
  //TF1 *fitV = new TF1("fitV","[0]+[1]*TMath::Exp(-(x)/[2])+[3]*x",8,31.6);
  //TF1 *fitV = new TF1("fitV","(0.133)*(1-TMath::Exp(-(x-[0])/[1]))-[2]*4.1e14*(x-[0])",8,31.6);
  //TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);
  TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",8,31.6);
  
  //fitV->SetParameter(0,10.0e-9);
  //fitV->SetParameter(1,10.0e-9);
  //fitV->SetParameter(2,20.0e-9);
  //	fitQ->SetParLimits(3,0.5,20.0);
  //fitQ->SetParLimits(4,7,12);
  
  //TVirtualFitter::SetMaxInterations(100000);
  gsoglia->Fit(fitV,"MR");
  //fitQ->SetParLimits(3,0.050,0.080);
  cout << "Chi^2: " << fitV->GetChisquare() << endl;
  cout << "Probability: " << fitV->GetProb() << endl;
  cout << "number of DoF: " << fitV->GetNDF() << endl;
  /*
    float TP[nmisure], eTP[nmisure], th[nmisure], eth[nmisure];
    
    TString dummy, dummy1, dummy2, dummy3, dummy4;
    
    cout << " Reading file : " << filename << "\n"; 
    file >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy; 
    //	file >> dummy >> dummy >> dummy >> dummy ; 
    cout << dummy1 << dummy2 << dummy3 << dummy4 << "\n";
  */
  
}
