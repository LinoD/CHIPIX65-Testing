## import ROOT global pointers
from ROOT import gStyle, gPad,  TMultiGraph, TGraphErrors 

## import ROOT classes
from ROOT import TGraph, TLegend, TGaxis, TF1, TFile, TCanvas

## import C-style arrays from the Python standard library
from array import array

## open ROOT file and get histograms
## TString canvo;

###Dir="data/Board1/CERN_meaasurements/Ifeed75-Vbl350/Out/";
Dir="data/Board1/CERN_meaasurements/Ifeed75_Vbl350_FastToT/Out/";
### 1
### filename="201702161831_STDPARA_B7-VSCAN-320-6-VTH70.out_thr.root";
#filename=Dir+"20170321131508_TO2-CALSWEEP-VTH60_000.out_thr.root";
filename=Dir+"20170321144635_TO2-CALSWEEP-VTH60_000.out_thr.root";
file1 = TFile(filename, "READ")
h1 = file1.Get("histo_thr")

### 2
##filename=Dir+"20170321131737_TO2-CALSWEEP-VT100_000.out_thr.root";
filename=Dir+"20170321145603_TO2-CALSWEEP-VT100_000.out_thr.root";
file2 = TFile(filename, "READ")
h2 = file2.Get("histo_thr")


### 3
###filename="201702161831_STDPARA_B7-VSCAN-320-6-VTH110.out_thr.root";
##filename=Dir+"20170321132008_TO2-CALSWEEP-VTH140_000.out_thr.root"
filename=Dir+"20170321150528_TO2-CALSWEEP-VTH140_000.out_thr.root"
file3 = TFile(filename, "READ")
h3 = file3.Get("histo_thr")

### 4
#filename=Dir+"20170321132243_TO2-CALSWEEP-VTH180_000.out_thr.root"
filename=Dir+"20170321151539_TO2-CALSWEEP-VTH180_000.out_thr.root"
file4 = TFile(filename, "READ")
h4 = file4.Get("histo_thr")

Dir="data/CERN/board4/Annealed/Ifeed75-Vbl350/Out/";
### 5
#filename=Dir+"20170321132243_TO2-CALSWEEP-VTH180_000.out_thr.root"
filename=Dir+"20170321172719_TO2-CALSWEEP-VTH60_000.out_thr.root";
file5 = TFile(filename, "READ")
h5 = file5.Get("histo_thr")

### 6
##filename=Dir+"20170321131737_TO2-CALSWEEP-VT100_000.out_thr.root";
filename=Dir+"20170321173639_TO2-CALSWEEP-VT100_000.out_thr.root";
file6 = TFile(filename, "READ")
h6 = file6.Get("histo_thr")

### 7
###filename="201702161831_STDPARA_B7-VSCAN-320-6-VTH110.out_thr.root";
##filename=Dir+"20170321132008_TO2-CALSWEEP-VTH140_000.out_thr.root"
filename=Dir+"20170321174606_TO2-CALSWEEP-VTH140_000.out_thr.root"
file7 = TFile(filename, "READ")
h7 = file7.Get("histo_thr")

### 8
#filename=Dir+"20170321132243_TO2-CALSWEEP-VTH180_000.out_thr.root"
filename=Dir+"20170321175544_TO2-CALSWEEP-VTH180_000.out_thr.root"
file8 = TFile(filename, "READ")
h8 = file8.Get("histo_thr")


## create a new canvas
cvsb = TCanvas()

## get rid of histogram title lo leave space for secondary axis
h1.SetTitle("")
h2.SetTitle("")
h3.SetTitle("")
h4.SetTitle("")

h1.SetName("60")
h2.SetName("100")
h3.SetName("140")
h4.SetName("180")

h5.SetTitle("")
h6.SetTitle("")
h7.SetTitle("")
h8.SetTitle("")

h5.SetName("60i")
h6.SetName("100i")
h7.SetName("140i")
h8.SetName("180i")


## optionally, normalize all histograms to unit-area

norm = 1.0

scale1 = norm/h1.Integral()
scale2 = norm/h2.Integral()
scale3 = norm/h3.Integral()
scale4 = norm/h4.Integral()

h1.Scale(scale1)
h2.Scale(scale2)
h3.Scale(scale3)
h4.Scale(scale4)


scale5 = norm/h5.Integral()
scale6 = norm/h6.Integral()
scale7 = norm/h7.Integral()
scale8 = norm/h8.Integral()

h5.Scale(scale5)
h6.Scale(scale6)
h7.Scale(scale7)
h8.Scale(scale8)



## draw histograms
h1.Draw()
h2.Draw("same")
h3.Draw("same")
h4.Draw("same")

h5.Draw("same")
h6.Draw("same")
h7.Draw("same")
h8.Draw("same")



## x-axis
DACmin = 30
DACmax = 90

h1.GetXaxis().SetTitle("Threshold [charge DAC units]")
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
h1.GetYaxis().SetRangeUser(0.00, 0.28)
h1.GetYaxis().CenterTitle()
h1.GetYaxis().SetDecimals()
h1.GetYaxis().SetTitleOffset(0.8)
h1.GetYaxis().SetTitleFont(132)
h1.GetYaxis().SetTitleSize(0.055)
h1.GetYaxis().SetLabelFont(132)
h1.GetYaxis().SetLabelSize(0.04)


## additional y-axis on the top side for charges
## **NOTE: update the GUI BEFORE adding the third axis
gPad.Modified()
gPad.Update()

Qinj = TF1("fQinj", "(-1500.0 + 48.5*x)*1e-3", 0.0, 1024.0)    # DAC code to charge conversion

Qmin = Qinj.Eval(DACmin)
Qmax = Qinj.Eval(DACmax)

xMin = Qmin
xMax = Qmax

f = TF1("f", "x", xMin, xMax)   # generate charge-axis values using a linear function

x1 = gPad.GetUxmin()
y1 = gPad.GetUymax()
x2 = gPad.GetUxmax()
y2 = gPad.GetUymax()

chargeAxis = TGaxis(x1, y1 ,x2 ,y2, "f", 510, "-R")

chargeAxis.SetTitle("Threshold [ke]")
chargeAxis.CenterTitle()
chargeAxis.SetTitleOffset(0.8)
chargeAxis.SetTitleFont(132)
chargeAxis.SetTitleSize(0.055)
chargeAxis.SetLabelFont(132)
chargeAxis.SetLabelSize(0.04)

chargeAxis.Draw()


## cosmetics for histograms

h1.SetStats(0)   # delete statistics box
h2.SetStats(0)
h3.SetStats(0)
h4.SetStats(0)

h1.SetLineColor(1)
h2.SetLineColor(1)
h3.SetLineColor(1)
h4.SetLineColor(1)

h5.SetLineColor(1)
h6.SetLineColor(2)
h7.SetLineColor(8)
h8.SetLineColor(4)



h1.SetFillStyle(3004)
h2.SetFillStyle(3004)
h3.SetFillStyle(3004)
h4.SetFillStyle(3004)


h1.SetFillStyle(3004)
h2.SetFillStyle(3004)
h3.SetFillStyle(3004)
h4.SetFillStyle(3004)


h1.SetFillColor(1)
h2.SetFillColor(2)
h3.SetFillColor(8)
h4.SetFillColor(4)

#h5.SetFillColor(1)
#h6.SetFillColor(2)
#h7.SetFillColor(3)
#h8.SetFillColor(4)

## gaussian fits
h1.Fit("gaus")
h2.Fit("gaus")
h3.Fit("gaus")
h4.Fit("gaus")

h5.Fit("gaus")
h6.Fit("gaus")
h7.Fit("gaus")
h8.Fit("gaus")


fit1 = h1.GetFunction("gaus")
fit1.SetNpx(5000)
fit1.SetLineColor(1)

fit2 = h2.GetFunction("gaus")
fit2.SetNpx(5000)
fit2.SetLineColor(2)

fit3 = h3.GetFunction("gaus")
fit3.SetNpx(5000)
fit3.SetLineColor(8)

fit4 = h4.GetFunction("gaus")
fit4.SetNpx(5000)
fit4.SetLineColor(4)


fit5 = h5.GetFunction("gaus")
fit5.SetNpx(5000)
fit5.SetLineStyle(2)
fit5.SetLineColor(1)

fit6 = h6.GetFunction("gaus")
fit6.SetNpx(5000)
fit6.SetLineStyle(2)
fit6.SetLineColor(1)

fit7 = h7.GetFunction("gaus")
fit7.SetNpx(5000)
fit7.SetLineStyle(2)
fit7.SetLineColor(1)


fit8 = h8.GetFunction("gaus")
fit8.SetNpx(5000)
fit8.SetLineStyle(2)
fit8.SetLineColor(1)



legend = TLegend(.45,.65,.58,.83)
legend.SetHeader("0 Mrad") 
legend.AddEntry("60","","f")
legend.AddEntry("100","","f")
legend.AddEntry("140","","f")
legend.AddEntry("180", "","f")
legend.SetFillColor(0)
legend.SetLineColor(0)
legend.SetTextFont(132)
legend.SetTextSize(0.045)
legend.SetTextAlign(11)


Ilegend = TLegend(.55,.65,.8,.83)
Ilegend.SetHeader("600  MRad") 
Ilegend.AddEntry("60i","Vth = 60 DAC units ","f")
Ilegend.AddEntry("100i","Vth = 100 DAC units ","f")
Ilegend.AddEntry("140i","Vth = 140 DAC units ","f")
Ilegend.AddEntry("180i", "Vth = 180 DAC units","f")
Ilegend.SetFillColor(0)
Ilegend.SetLineColor(0)
Ilegend.SetTextFont(132)
Ilegend.SetTextSize(0.045)
Ilegend.SetTextAlign(11)



legend.Draw()
Ilegend.Draw()

title = TLegend(0.12,0.8,0.35,0.85)
title.SetHeader("CHIPIX65") 
#title.AddEntry("","VFE-synch")
title.SetFillColor(0)
title.SetLineColor(0)
title.SetTextFont(132)
title.SetTextSize(0.045)
title.SetTextAlign(11)
title.Draw()

astitle = TLegend(0.12,0.73,0.35,0.75)
astitle.SetHeader("Synchronous front-end") 
astitle.SetFillColor(0)
astitle.SetLineColor(0)
astitle.SetTextFont(132)
astitle.SetTextSize(0.044)
astitle.SetTextAlign(11)
astitle.Draw()



gPad.Modified()
gPad.Update()



#############################################################################

## experimental values prima irragggamento

bxData = [60., 100., 140. ,180.]
bthr     = [38.32,51.02,63.87,76.61 ]
bsigmath = [2.34,2.39,2.42,2.45]
bnois    = [1.85,1.89,1.92,1.91]
bsigman  = [0,20,0.19,0.19,0.19]

bex = [0, 0, 0, 0]
bethr = [.04, .04, .04, .04]

## experimental values dopo irragggamento
xData = [60., 100., 140. ,180.]
thr     = [39.54,52.23,65.37,79.65]
sigmath = [2.,2.,2.,2.]
nois    = [1.,1.,1.,1.]
sigman  = [0,0,0.,0.,0.]

ex = [0, 0, 0, 0]
ethr = [.4, .4, .4, .4]


#print type(xData)
#print type(yData)

## number of points
Npt = len(xData)
Nptb = len(bxData)

xMin =  50
xMax =  190

## ---- Filling Array 
# after irrad

xDataArray = array('f', xData)
xDataEArray = array('f', ex)
thrArray = array('f', thr)   # 'f' = float, 'd' = double, 'i' = integer etc.
ethrArray = array('f', ethr)   # 'f' = flo

sigmathArray = array('f',sigmath)
noisArray = array('f',nois)
sigman = array('f',sigman)

# before irrad

bxDataArray = array('f', bxData)
bthrArray = array('f', bthr)   # 'f' = float, 'd' = double, 'i' = integer etc.
bxDataEArray = array('f', bex)
bethrArray = array('f', bethr)   # 'f' = flo

bsigmathArray = array('f',bsigmath)
bnoisArray = array('f',bnois)
bsigman = array('f',bsigman)


### -------------------------------------------------------------------------------------------------------------- THR plots

threshold = TCanvas("Threshold","",800,500)

## after IRR
mg = TMultiGraph()
gr = TGraphErrors(Npt, xDataArray, thrArray, xDataEArray, ethrArray)
gr.SetName("gr")
gr.SetMarkerStyle(25)
gr.SetMarkerSize(1.2)
gr.Fit("pol1", "VR", "", xMin, xMax)

f = gr.GetFunction("pol1")
f.SetNpx(1000)
f.SetLineWidth(1)

## before IRR

bgr = TGraphErrors(Npt, bxDataArray, bthrArray, bxDataEArray, bethrArray)
bgr.SetName("bgr")
bgr.SetMarkerStyle(21)
bgr.SetMarkerSize(1.2)
bgr.Fit("pol1", "VR", "", xMin, xMax)
bf = bgr.GetFunction("pol1")
bf.SetNpx(1000)
bf.SetLineWidth(1)

mg.Add(gr,"AP")
mg.Add(bgr,"AP")
mg.Draw("a")

sDACmin=35
sDACmax=85

## cosmetics
mg.SetTitle("")
mg.GetXaxis().SetTitle("Set Threshold [Vth DAC units]")
mg.GetXaxis().SetTitleSize(0.055)
mg.GetXaxis().SetTitleOffset(0.8)
mg.GetXaxis().CenterTitle()
mg.GetYaxis().SetTitle("Mean Threshold [charge DAC units]")
mg.GetYaxis().SetLabelSize(0.04)
mg.GetYaxis().SetTitleOffset(0.6)
mg.GetYaxis().SetTitleSize(0.05)
mg.GetYaxis().CenterTitle()
mg.GetYaxis().SetRangeUser(sDACmin,sDACmax)

sQinj = TF1("Qinj","(-1500.0 + 48.5*x)*1e-3", 0.0, 1024.0)    # DAC code to charge conversion
sQmin = sQinj.Eval(sDACmin)
sQmax = sQinj.Eval(sDACmax)
yMin = sQmin
yMax = sQmax
print Qmin
print Qmax


ff = TF1("ff", "x", yMin, yMax)   # generate charge-axis values using a linear function
x1 = gPad.GetUxmax()
y1 = gPad.GetUymin()
x2 = gPad.GetUxmax()
y2 = gPad.GetUymax()
schargeAxis = TGaxis(x1, y1 ,x2 ,y2, "ff", 510, "+L")

schargeAxis.SetTitle("Mean Threshold [ke]")
schargeAxis.CenterTitle()
schargeAxis.SetTitleOffset(0.8)
schargeAxis.SetTitleFont(132)
schargeAxis.SetTitleSize(0.05)
schargeAxis.SetLabelFont(132)
schargeAxis.SetLabelSize(0.04)
schargeAxis.Draw()


## update the GUI after cosmetics changes
#gPad.Modified()
#gPad.Update()


## save the plot into a ROOT file
fff = TFile("myGraph.root", "recreate")

## optionally, open the TBrowser
#b = TBrowser()

### 
ttitle = TLegend(0.15,0.8,0.4,0.85)
ttitle.SetHeader("CHIPIX65") 
ttitle.SetFillColor(0)
ttitle.SetLineColor(0)
ttitle.SetTextFont(132)
ttitle.SetTextSize(0.044)
ttitle.SetTextAlign(11)
ttitle.Draw()

stitle = TLegend(0.15,0.55,0.4,0.75)
stitle.SetHeader("Synchronous front-end") 

stitle.SetFillColor(0)
stitle.SetLineColor(0)
stitle.SetTextFont(132)
stitle.SetTextSize(0.044)
stitle.SetTextAlign(11)
stitle.Draw()
stitle.AddEntry("","","")
stitle.AddEntry(bgr,"Pre-Irradiation ","P")
stitle.AddEntry(gr, "600 Mrad at T=-20C","P")


## update the GUI after cosmetics changes
gPad.Modified()
gPad.Update()


mg.Write()
fff.Close()

######

