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





void TwoDim_Plots(Int_t i)
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

    Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Studenti/Prove/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<10 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
		 
   	   file =  "board8-to2-VTH60."; 
	   NEVT=50.;
//	   Dir0 = "data/board9/special-test/IBIAS50-75/";
//	   tmin=30;
//           tmax=45;
    }

	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,40,20,60,1.,4.); 
	}
	}
}


void Analysis(int i){

 
  TwoDim_Plots(i);

}
