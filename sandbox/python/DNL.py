
## A simple example for DNL evaluation from MC data

import ROOT, array

cvs = ROOT.TCanvas()
cvs.Divide(2,1)

Npt = 1024

gr = ROOT.TGraph(Npt)
gr.SetName("gr1")
gr.SetTitle("Data")

for i in range( Npt ) :

        gr.SetPoint(i, i+1, 2*(i+1) + ROOT.gRandom.Gaus(0, 0.1) )


gr.Fit("pol1", "VR", "", 0, Npt)

fit = gr.GetFunction("pol1")

xValue = ROOT.Double(0)
yValue = ROOT.Double(0)

yDNL = array.array('d')

gr2 = ROOT.TGraph(Npt)
gr2.SetName("gr2")
gr2.SetTitle("DNL")

for i in range( Npt ) :

        gr.GetPoint(i, xValue, yValue)
        DNL = ( yValue - fit.Eval(xValue) )
        gr2.SetPoint(i, xValue, DNL)
        print xValue, yValue, DNL


gr.SetMarkerSize(1.0)
gr.SetMarkerStyle(21)

gr2.SetMarkerSize(1.0)
gr2.SetMarkerStyle(25)

cvs.cd(1)
gr.Draw("AP")

cvs.cd(2)
gr2.Draw("AL")

ROOT.gPad.Modified()
ROOT.gPad.Update()
