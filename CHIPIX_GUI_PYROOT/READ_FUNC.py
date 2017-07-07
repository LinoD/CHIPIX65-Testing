import ROOT

import hmac
import hashlib
import sys,socket
import os
from os.path import exists
import string
import time
import MESSAGES

def Read_GRC_Ex(self):

	t = 0.0004

	self.send_message(MESSAGES.MESSAGE1)
 	time.sleep(t)
	self.received_message()
	time.sleep(t)


	#hex_str = self.received_message()
	
	#print hex_str

	### GCR DATA ### it is an array with all the 224 bit of the GCRs

	GCR_DATA = []

	i = 0

	while i < 14 :
	
		self.send_message(MESSAGES.MESSAGE2)
		time.sleep(t)
	
		GCR_X_received_hex = self.received_message()
		GCR_X_received_bin = self.Read_HexToBin( GCR_X_received_hex )
		print GCR_X_received_bin 

		a = 0

		while a < 16 :
			
			GCR_DATA.insert(0,GCR_X_received_bin[15-a]) 
			a = a + 1
		
		i = i + 1

	#print GCR_DATA


	### Phi_AZ delay ###

	Phi_AZ_delay = self.Read_BinToDecimal(GCR_DATA,0,4)
	#print Phi_AZ_delay
	self.textViewTO1a.SetText(str(Phi_AZ_delay))
	
	### Phi_AZ_high_level ###
	
	Phi_AZ_high_level = self.Read_BinToDecimal(GCR_DATA,5,12)
	self.textViewTO1b.SetText(str(Phi_AZ_high_level))

	### Phi_AZ_low_level ###

	Phi_AZ_high_low = self.Read_BinToDecimal(GCR_DATA,13,26)
        self.textViewTO1c.SetText(str(Phi_AZ_high_low))

	### ICtrl_Tot ###
	
	ICtrl_Tot = self.Read_BinToDecimal(GCR_DATA,27,36)
        self.textViewTO1d.SetText(str(ICtrl_Tot))

	### Vth_Disc ###
	
	Vth_Disc = self.Read_BinToDecimal(GCR_DATA,37,46)
        self.textViewTO1e.SetText(str(Vth_Disc))

	### VBI_Disc ###

	VBI_Disc = self.Read_BinToDecimal(GCR_DATA,47,56)
        self.textViewTO1f.SetText(str(VBI_Disc))

	### IBias_P1 ###

	a = self.Read_BinToDecimal(GCR_DATA,57,66)
        self.textViewTO4a.SetText(str(a))

       ### IBias_P2

	a = self.Read_BinToDecimal(GCR_DATA,67,76)
        self.textViewTO4b.SetText(str(a))

	### IBias Disc

	a = self.Read_BinToDecimal(GCR_DATA,77,86)
        self.textViewTO4c.SetText(str(a))

	### IBias SF
	
	a = self.Read_BinToDecimal(GCR_DATA,87,96)
        self.textViewTO4d.SetText(str(a))

	### VRef Krum

	a = self.Read_BinToDecimal(GCR_DATA,97,106)
        self.textViewTO4e.SetText(str(a))

	### IBias Feed

	a = self.Read_BinToDecimal(GCR_DATA,107,116)
        self.textViewTO4f.SetText(str(a))

        ### ILDac

	a = self.Read_BinToDecimal(GCR_DATA,132,141)
        self.textViewBG1a.SetText(str(a))

	### IGDac
	a = self.Read_BinToDecimal(GCR_DATA,142,151)
        self.textViewBG1b.SetText(str(a))

	### VRef Krum

	a = self.Read_BinToDecimal(GCR_DATA,152,161)
        self.textViewBG1c.SetText(str(a))

	### IKrum

	a = self.Read_BinToDecimal(GCR_DATA,162,171)
        self.textViewBG1d.SetText(str(a))

	### IFC_Bias 

	a = self.Read_BinToDecimal(GCR_DATA,172,181)
        self.textViewBG1e.SetText(str(a))

	### IPA in Bias 

	a = self.Read_BinToDecimal(GCR_DATA,182,191)
        self.textViewBG1f.SetText(str(a))

	###CAL  LEVEL

	a = self.Read_BinToDecimal(GCR_DATA,192,201)
        self.textViewCALL1a.SetText(str(a))

	### IRef

        a = self.Read_BinToDecimal(GCR_DATA,117,121)
        self.textViewCALL1c.SetText(str(a))
	### BGR

	a = self.Read_BinToDecimal(GCR_DATA,122,126)
        self.textViewCALL1d.SetText(str(a))
	
	### Mon Mux

	a = self.Read_BinToDecimal(GCR_DATA,127,131)
        self.textViewCALL1e.SetText(str(a))
	
	### OP mode

	a = self.Read_BinToDecimal(GCR_DATA,202,202)
        self.textViewBA1a.SetText(str(a))
	
	### ITrans gain

	a = self.Read_BinToDecimal(GCR_DATA,203,206)
        self.textViewBA1b.SetText(str(a))
	
	### IDiscarge

	a = self.Read_BinToDecimal(GCR_DATA,207,212)
        self.textViewBA1c.SetText(str(a))
	
	### ICharge

	a = self.Read_BinToDecimal(GCR_DATA,213,218)
        self.textViewBA1d.SetText(str(a))
	
	### Comp Thr

	a = self.Read_BinToDecimal(GCR_DATA,219,223)
        self.textViewBA1e.SetText(str(a))

