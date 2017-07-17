## import ROOT global pointers
from ROOT import gStyle, gPad,  TMultiGraph, TGraphErrors, TTree 
## import ROOT classes
from ROOT import TGraph, TLegend, TGaxis, TF1, TFile, TCanvas, TMath

## import C-style arrays from the Python standard library
from array import array
import math, os, sys

gStyle.SetOptFit()


MyTreeCSA = TTree("MyTree", "MyTree");
MyTreeDA = TTree("MyTree", "MyTree");

############################################### 10 fF POST
#MyTreeCSA.ReadFile("../data/simu/Cdet10fF/CSA_output_2ke.txt", "TCSA:AmplCSA");
#MyTreeDA.ReadFile("../data/simu/Cdet10fF/DA_output_2ke.txt", "TDA:AmplDA");

###
#MyTreeCSA.ReadFile("../data/simu/Cdet10fF/CSA_output_2ke.txt", "TCSA:AmplCSA");
#MyTreeDA.ReadFile("../data/simu/Cdet10fF/DA_output_2ke.txt", "TDA:AmplDA");


####
#MyTreeCSA.ReadFile("../data/simu/Cdet10fF/FCSA_output_2ke_Ifeed_10nA.txt", "TCSA:AmplCSA");
#MyTreeDA.ReadFile("../data/simu/Cdet10fF/DA_output_2ke_Ifeed_10nA.txt", "TDA:AmplDA");

## 
#MyTreeCSA.ReadFile("../data/simu/Cdet10fF/CSA_output_2ke_Ifeed_40nA.txt", "TCSA:AmplCSA");
#MyTreeDA.ReadFile("../data/simu/Cdet10fF/DA_output_2ke_Ifeed_40nA.txt", "TDA:AmplDA");

####
#MyTreeCSA.ReadFile("../data/simu/Cdet10fF/DA_output_2ke_Ifeed_2virgola5_nA.txt", "TCSA:AmplCSA")
#MyTreeCSA.ReadFile("../data/simu/Cdet10fF/FCSA_output_2ke_Ifeed_2virgola5_nA.txt", "TCSA:AmplCSA");

############################ 0 fF schematics

MyTreeCSA.ReadFile("../data/simu/CSA_output_2ke_Ifeed_20_nA_Thr_600e_schematic.txt", "TCSA:AmplCSA");
MyTreeDA.ReadFile("../data/simu/DA_output_2ke_Ifeed_20_nA_Thr_600e_schematic.txt", "TDA:AmplDA");




######

##Fitd = TCanvas("Fitd","",800,500)

### n in nsec
n = 80;
t = array ( 'd' );

voutCSA = array ( 'd' );
voutDA = array ( 'd' );

#### 3000e-;  1000 e- = 160 aC
carica = 2000;
q = 160*carica/1000.;
cf = 1.8;
tau = 10.E-9;
t0 = 4E-9;
ifeed = 7;

for i in range ( n) :
    t.append( 1E-9 * i);
    y = q/cf/1000 * (1-math.exp( -(1E-9*i-t0)/tau )) -ifeed/cf * (1E-9*i-t0)*1E6; 
    voutCSA.append ( y ); 
CSAth = TGraph(n,t,voutCSA);  


CSA = TCanvas("CSA","",800,500)
##nt = MyTreeCSA.Draw("(AmplCSA-0.4845):(TCSA-0.905E-6)","TCSA>0.905E-6 & TCSA<0.97E-6","");
nt = MyTreeCSA.Draw("(AmplCSA-0.4845):(TCSA-0.90E-6)","TCSA>0.90E-6 & TCSA<0.97E-6","");


CSAgr = TGraph(nt,MyTreeCSA.GetV2(),MyTreeCSA.GetV1());
CSAgr.Draw('');

fitQ = TF1("fitQ","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",9E-9,55E-9);

## q/cf
fitQ.SetParLimits(0,90E-3,250E-3);
## t0
fitQ.SetParLimits(1,1E-9,10E-9);

## tau
fitQ.SetParLimits( 2,3E-9,25E-9);

## Ifeed/cf 
fitQ.SetParLimits(3,1E5,40E6);

CSAgr.Fit(fitQ,"MR");
CSAgr.Fit(fitQ,"MR");

cf=2.5;
par0 = fitQ.GetParameter(0);
Q=par0*cf/0.16*1000;
print "Carica [ke] : ", Q;

par1 = fitQ.GetParameter(1);
t0 = par1*1E9;
print "T0 [ns]", t0;

par2 = fitQ.GetParameter(2);
tau = par2*1E9;
print "Tau [ns] : ",tau;

par3 = fitQ.GetParameter(3);
ifeed = par3*cf/1E6;
print "Ifeed [nA]" , ifeed;

##########
#for i in range ( n) :
#    t.append( 1E-9 * i);
#    y = q/cf/1000 * (1-math.exp( -(1E-9*i-t0)/tau )) -ifeed/cf * (1E-9*i-t0)*1E6; 
#    voutDA.append ( y ); 
#DAgr = TGraph(n,t,voutDA);  

###

DA = TCanvas("DA","",800,500)
##Dnt = MyTreeDA.Draw("AmplDA:(TDA-0.9E-6)", "","");

Dnt = MyTreeDA.Draw("(AmplDA+0.0435):(TDA-0.9E-6)","TDA>0.90E-6 & TDA<1E-6","");
##Dnt = MyTreeDA.Draw("(AmplDA):(TDA-0.90E-6)","TDA>0.90E-6 & TDA<1E-6","");

DAgr = TGraph(Dnt,MyTreeDA.GetV2(),MyTreeDA.GetV1());
DAgr.Draw('');

##ffitQ = TF1("fitQ","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",18E-9,50E-9);
ffitQ = TF1("fitQ","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",15E-9,58E-9);

## q/cf
ffitQ.SetParLimits(0,150E-3,400E-3);
## t0
ffitQ.SetParLimits(1,7E-9,15E-9);

## tau
ffitQ.SetParLimits( 2,8E-9,25E-9);

## Ifeed/cf 
ffitQ.SetParLimits(3,1E5,60E6);

DAgr.Fit(ffitQ,"MR");
DAgr.Fit(ffitQ,"MR");

cf=2.5;
par0 = ffitQ.GetParameter(0);
Q=par0*cf/0.16*1000;
print "Carica [ke] : ", Q;

par1 = ffitQ.GetParameter(1);

t0 = par1*1E9;
print "T0 [ns]", t0;

par2 = ffitQ.GetParameter(2);
tau = par2*1E9;
print "Tau [ns] : ",tau;

par3 = ffitQ.GetParameter(3);
ifeed = par3*cf/1E6;
print "Ifeed [nA]" , ifeed;

