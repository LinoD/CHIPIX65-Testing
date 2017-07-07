import ROOT

def ADCGraphEx(self):

	self.ADC1 = ROOT.TGHorizontalFrame( self.tab4 )

	self.ReadADCButton = ROOT.TGTextButton( self.ADC1 ,"   Read ADC   ")
      	self.Do_ReadADC = ROOT.TPyDispatcher( self.ReadADC ) # this command translate the python command in C++ launguage I think
	self.ReadADCButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_ReadADC, 'Dispatch()')
	self.ADC1.AddFrame(self.ReadADCButton, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 10,10,10,10))


	self.ReadADCLabel= ROOT.TGLabel(self.ADC1, "ADC reading")
        self.ADC1.AddFrame(self.ReadADCLabel, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,40,2,12,10))


        self.ReadADCValue = ROOT.TGLabel(self.ADC1, "            " )
	self.ReadADCValue.SetForegroundColor(234)
	#self.ReadADCValue.SetBackgroundColor (ROOT.kWhite)

        self.ADC1.AddFrame(self.ReadADCValue,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,10,2,12,10))

	self.tab4.AddFrame(self.ADC1,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 10,10,10,10))



