#import all ROOT classes

import ROOT

#make the graphic with the point written in data.txt
#format = "lg lg lg" read only 3 first columns into X,Y and EY
 
d = ROOT.TGraphErrors("/home/pietro/scratch/devel/test/170606/data.txt", "%lg %lg %lg")

# create a Canvas

d1 = ROOT.TCanvas ("d1", "grafico", 1200, 600)

# divide the canvas i two parts

d1.Divide(2,1)

# select the first part and draw the TgraphErrors

d1.cd(1)

d.SetMarkerSize(1.0)
d.SetMarkerStyle(21)
d.SetTitle("Retta di Calibrazione")
d.Draw("AP")

#fit the points with a linear function

d.Fit("pol1")

# ask the fit parameters

g = d.GetFunction("pol1")

a = g.GetParameter(0)

b = g.GetParameter(1)

# create an array with the y expected and another one named DNL

Ex=[1,1,1,1,1,1]
DNL= [1,1,1,1,1,1]


x = ROOT.Double()

y = ROOT.Double()

s = 0

while s < d.GetN():

	d.GetPoint(s,x,y)
	Ex[s]= a+b*x
	DNL[s]= (y-Ex[s])/Ex[s]
	s = s + 1

# calculate the DNL of each point

#DNL= [1,1,1,1,1,1]

#s = 0

#while s < 6:

       # d.GetPoint(s,x,y)
       # DNL[s]= (y-Ex[s])/Ex[s]
       # s = s + 1

# create a new graphic "DNL vs x "

w = ROOT.TGraph (6)

s = 0

while s < 6:

        w.SetPoint(s,s,DNL[s])
        s = s + 1

#select the second part of the Canvas and draw it

d1.cd(2)

w.SetTitle("DNL")
w.SetMarkerSize(1.0)
w.SetMarkerStyle(21)



w.Draw("AP")

# save to TFile

pf =ROOT.TFile("prova.root","RECREATE")

d.Write()
w.Write()


pf.Close()

