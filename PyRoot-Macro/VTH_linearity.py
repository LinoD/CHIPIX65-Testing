## import ROOT global pointers
from ROOT import gStyle, gPad

## import ROOT classes
from ROOT import TGraph, TLegend, TGaxis, TF1, TFile, TCanvas


## open ROOT file and get histograms
file = TFile("C2FThr_new.root", "READ")

cvs = file.Get("thresholds")
cvs.Draw()

h1 = cvs.GetPrimitive("Vth = 65 DAC counts")
h2 = cvs.GetPrimitive("Vth = 80 DAC counts")
h3 = cvs.GetPrimitive("Vth = 120 DAC counts")
h4 = cvs.GetPrimitive("Vth = 160 DAC counts")


## create a new canvas
cvs2 = TCanvas()

## get rid of histogram title lo leave space for secondary axis
h1.SetTitle("")
h2.SetTitle("")
h3.SetTitle("")
h4.SetTitle("")


## optionally, normalize all histograms to unit-area

norm = 1000.0

scale1 = norm/h1.Integral()
scale2 = norm/h2.Integral()
scale3 = norm/h3.Integral()
scale4 = norm/h4.Integral()

h1.Scale(scale1)
h2.Scale(scale2)
h3.Scale(scale3)
h4.Scale(scale4)


## draw histograms
h1.Draw()
h2.Draw("same")
h3.Draw("same")
h4.Draw("same")


## x-axis
DACmin = 30
DACmax = 80

h1.GetXaxis().SetTitle("DAC counts")
h1.GetXaxis().SetRangeUser(DACmin, DACmax)
h1.GetXaxis().SetTitleFont(132)
h1.GetXaxis().SetTitleSize(0.055)
h1.GetXaxis().SetTitleOffset(1.0)
h1.GetXaxis().SetLabelFont(132)
h1.GetXaxis().SetLabelSize(0.04)
h1.GetXaxis().CenterTitle()
h1.GetXaxis().SetAxisColor(1)
   

## y-axis
h1.GetYaxis().SetTitle("entries")
###h1.GetYaxis().SetRangeUser(0.001, 0.2)
h1.GetYaxis().SetRangeUser(0.001, 240)
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

chargeAxis.SetTitle("threshold [ke]")
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

h1.SetFillStyle(3004)
h2.SetFillStyle(3004)
h3.SetFillStyle(3004)
h4.SetFillStyle(3004)

h1.SetFillColor(1)
h2.SetFillColor(2)
h3.SetFillColor(3)
h4.SetFillColor(4)


## gaussian fits
h1.Fit("gaus")
h2.Fit("gaus")
h3.Fit("gaus")
h4.Fit("gaus")

fit1 = h1.GetFunction("gaus")
fit1.SetNpx(5000)
fit1.SetLineColor(1)

fit2 = h2.GetFunction("gaus")
fit2.SetNpx(5000)
fit2.SetLineColor(2)

fit3 = h3.GetFunction("gaus")
fit3.SetNpx(5000)
fit3.SetLineColor(3)

fit4 = h4.GetFunction("gaus")
fit4.SetNpx(5000)
fit4.SetLineColor(4)


legend = TLegend(.45,.70,.85,.85)
legend.AddEntry("Vth = 60 DAC counts",  "   Vth = 60 DAC counts","f")
legend.AddEntry("Vth = 80 DAC counts",  "   Vth = 80 DAC counts","f")
legend.AddEntry("Vth = 120 DAC counts", "   Vth = 120 DAC counts","f")
legend.AddEntry("Vth = 160 DAC counts", "   Vth = 160 DAC counts","f")


legend.SetFillColor(0)
legend.SetLineColor(0)
legend.SetTextFont(132)
legend.SetTextSize(0.045)
legend.SetTextAlign(11)

legend.Draw()

gPad.Modified()
gPad.Update()

