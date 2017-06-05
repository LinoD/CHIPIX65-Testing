
#!/usr/bin/env python


from ROOT import TH1F, TFile

f = TFile("test.root", "RECREATE")

h = TH1F("histo", "histo", 100, -5, 5)

h.FillRandom("gaus", 10000)

h.Write()

f.Close()
