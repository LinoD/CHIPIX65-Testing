## import ROOT global pointers
from ROOT import gStyle, gPad,  TMultiGraph, TGraphErrors 

## import ROOT classes
from ROOT import TGraph, TLegend, TGaxis, TF1, TFile, TCanvas

## import C-style arrays from the Python standard library
from array import array

## open ROOT file and get histograms
## TString canvo;

Dir="data/CERN/board4/Annealing/-20C/Out/";
### 1
filename=Dir+"20170306062939_TO2-FASTTOT-LINEARITY_013.out_FREQ.root";
file1 = TFile(filename, "READ")
h1 = file1.Get("histo_frq")

Dir="data/CERN/board4/Preirraggiamento/TEMP-20C/Out/";
### 5
filename=Dir+"20170227233528_TO2-FASTTOT-LINEARITY_000.out_FREQ.root";
file5 = TFile(filename, "READ")
h5 = file5.Get("histo_frq")


## create a new canvas
cvsb = TCanvas()

## get rid of histogram title lo leave space for secondary axis
h1.SetTitle("")
#h2.SetTitle("")


h1.SetName("60")
#h2.SetName("100")

h5.SetTitle("")
#h6.SetTitle("")

h5.SetName("60i")
#h6.SetName("100i")


## optionally, normalize all histograms to unit-area

norm = 1.0

scale1 = norm/h1.Integral()
h1.Scale(scale1)

scale5 = norm/h5.Integral()
h5.Scale(scale5)




## draw histograms
h1.Draw()


h5.Draw("same")




## x-axis
DACmin = 100
DACmax = 500

h1.GetXaxis().SetTitle("Fast-Tot Freq [MHz]")
h1.GetXaxis().SetRangeUser(DACmin, DACmax)
h1.GetXaxis().SetTitleFont(132)
h1.GetXaxis().SetTitleSize(0.055)
h1.GetXaxis().SetTitleOffset(0.8)
h1.GetXaxis().SetLabelFont(132)
h1.GetXaxis().SetLabelSize(0.04)
h1.GetXaxis().CenterTitle()
h1.GetXaxis().SetAxisColor(1)
   

## y-axis
h1.GetYaxis().SetTitle("Normalized entries")
###h1.GetYaxis().SetRangeUser(0.001, 0.2)
h1.GetYaxis().SetRangeUser(0.00, 0.30)
h1.GetYaxis().CenterTitle()
h1.GetYaxis().SetDecimals()
h1.GetYaxis().SetTitleOffset(0.8)
h1.GetYaxis().SetTitleFont(132)
h1.GetYaxis().SetTitleSize(0.055)
h1.GetYaxis().SetLabelFont(132)
h1.GetYaxis().SetLabelSize(0.04)




## cosmetics for histograms

h1.SetStats(0)   # delete statistics box


h1.SetLineColor(1)
h5.SetLineColor(1)

h1.SetFillStyle(3004)
h1.SetFillStyle(3004)
h1.SetFillColor(1)




## gaussian fits
h1.Fit("gaus")
h5.Fit("gaus")


fit1 = h1.GetFunction("gaus")
fit1.SetNpx(5000)
fit1.SetLineColor(1)



fit5 = h5.GetFunction("gaus")
fit5.SetNpx(5000)
fit5.SetLineStyle(2)
fit5.SetLineColor(1)




legend = TLegend(.75,.65,.85,.8)
legend.SetHeader("600 Mrad") 
legend.AddEntry("60","","f")

legend.SetFillColor(0)
legend.SetLineColor(0)
legend.SetTextFont(132)
legend.SetTextSize(0.045)
legend.SetTextAlign(11)

Ilegend = TLegend(.75,.45,.85,.6)
Ilegend.SetHeader("0  MRad") 
Ilegend.AddEntry("60i","","f")

Ilegend.SetFillColor(0)
Ilegend.SetLineColor(0)
Ilegend.SetTextFont(132)
Ilegend.SetTextSize(0.045)
Ilegend.SetTextAlign(11)



legend.Draw()
Ilegend.Draw()

title = TLegend(0.12,0.8,0.35,0.85)
title.SetHeader("CHIPIX65") 
#title.SetHeader("VFE-synch") 
title.SetFillColor(0)
title.SetLineColor(0)
title.SetTextFont(132)
title.SetTextSize(0.045)
title.SetTextAlign(11)
title.Draw()


titleb = TLegend(0.12,0.74,0.35,0.75)
titleb.SetHeader("Synchronous front-end") 
titleb.SetFillColor(0)
titleb.SetLineColor(0)
titleb.SetTextFont(132)
titleb.SetTextSize(0.045)
titleb.SetTextAlign(11)
titleb.Draw()

gPad.Modified()
gPad.Update()


