import ROOT
		############################################################
		#### TAB 2 #######
		###########################################################

def WriteGraphEx(self):

		self.WWriteGCR = ROOT.TGTextButton( self.tab2 ,"   &Write GCR   ")
		self.Do_Write_GCR = ROOT.TPyDispatcher( self.Write_GCR ) # this command translate the python command in C++ launguage I think
                self.WWriteGCR.Connect('Clicked()' , 'TPyDispatcher' , self.Do_Write_GCR, 'Dispatch()')

		self.tab2.AddFrame(self.WWriteGCR,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 10,10,10, 0))


		self.WWriteScreen = ROOT.TGHorizontalFrame (self.tab2, 600,20)
		self.Wlabel1 = ROOT.TGLabel(self.WWriteScreen, "Write GCR")
		self.WWriteScreen.AddFrame(self.Wlabel1,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5,5,5, 5))
		self.tab2.AddFrame(self.WWriteScreen,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 0,10,5, 5))




		
		#########################
		#### FIRST PART #########
		#########################

		self.Wnames1 = ROOT.TGHorizontalFrame(self.tab2 )
		self.Wnames1.SetBackgroundColor (345)
		self.Wnames1.DrawBorder()

		self.WlabelTO = ROOT.TGLabel(self.Wnames1, "TO")
		self.WlabelBG = ROOT.TGLabel(self.Wnames1, "BG/PV.")
		
		self.WlabelTO.SetTextColor(ROOT.kWhite)

		self.Wnames1.AddFrame(self.WlabelTO,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5,5,5, 5))
		self.Wnames1.AddFrame(self.WlabelBG,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 590,5,5, 5))
		
		self.tab2.AddFrame( self.Wnames1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10,- 5, 5) )

		self.Wnames1a = ROOT.TGHorizontalFrame(self.tab2)

		self.WverticalTO  = ROOT.TGHorizontalFrame(self.Wnames1a)   #, 500,500, ROOT.kRaisedFrame)
                self.WverticalBG  = ROOT.TGHorizontalFrame(self.Wnames1a)   #, 500,500, ROOT.kRaisedFrame)
               
                self.WverticalTO.SetBackgroundColor (345)
                self.WverticalBG.SetBackgroundColor (456)
		
		self.Wnames1a.AddFrame(self.WverticalTO,  ROOT.TGLayoutHints(ROOT.kLHintsLeft, 5 ,5 , 5, 5))
                self.Wnames1a.AddFrame(self.WverticalBG, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 105, 5, 5, 5))
               

		self.tab2.AddFrame( self.Wnames1a, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10,- 5, 0) )

		###################################################
		###### TO frames ########
		##################################################

		# First Coloumn
		
		self.WverticalTO1 = ROOT.TGVerticalFrame(self.WverticalTO,10,100,1)
		self.WverticalTO2  = ROOT.TGVerticalFrame(self.WverticalTO,5,5)		

		self.WlabelTO1a= ROOT.TGLabel(self.WverticalTO1, "PHI AZ Delay") 		
		self.WverticalTO1.AddFrame(self.WlabelTO1a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,82,2,2))
		

		self.PHI_AZ_Delay_WRITE = ROOT.TGNumberEntry(self.WverticalTO2,0,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 31)
		self.WverticalTO2.AddFrame(self.PHI_AZ_Delay_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

		self.WlabelTO1b= ROOT.TGLabel(self.WverticalTO1, "PHI AZ High Level")
                self.WverticalTO1.AddFrame(self.WlabelTO1b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

		self.PHI_AZ_High_Level_WRITE = ROOT.TGNumberEntry(self.WverticalTO2, 20,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 255);
                self.WverticalTO2.AddFrame(self.PHI_AZ_High_Level_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

		self.WlabelTO1c= ROOT.TGLabel(self.WverticalTO1, "PHI AZ Low Level")
                self.WverticalTO1.AddFrame(self.WlabelTO1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

		self.PHI_AZ_Low_Level_WRITE = ROOT.TGNumberEntry(self.WverticalTO2, 3980,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 16383 );
                self.WverticalTO2.AddFrame(self.PHI_AZ_Low_Level_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

		self.WlabelTO1d= ROOT.TGLabel(self.WverticalTO1, "ICtrl TOT")
                self.WverticalTO1.AddFrame(self.WlabelTO1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

		self.ICtrl_TOT_WRITE = ROOT.TGNumberEntry(self.WverticalTO2, 100,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO2.AddFrame(self.ICtrl_TOT_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

		self.WlabelTO1e= ROOT.TGLabel(self.WverticalTO1, "VTh Disc")
                self.WverticalTO1.AddFrame(self.WlabelTO1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

		self.Vth_Disc_WRITE = ROOT.TGNumberEntry(self.WverticalTO2, 1023,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO2.AddFrame(self.Vth_Disc_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))
		
		self.WlabelTO1f= ROOT.TGLabel(self.WverticalTO1, "VBl Disc")
                self.WverticalTO1.AddFrame(self.WlabelTO1f,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

		self.VBL_Disc_WRITE = ROOT.TGNumberEntry(self.WverticalTO2, 450,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO2.AddFrame(self.VBL_Disc_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))
		
		self.WverticalTO.AddFrame(self.WverticalTO1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,5, 5, 5) )
		self.WverticalTO.AddFrame(self.WverticalTO2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,40, 5, 5) )


		# Second Coloumn

		self.WverticalTO3 = ROOT.TGVerticalFrame(self.WverticalTO)
                self.WverticalTO4 = ROOT.TGVerticalFrame(self.WverticalTO)

                self.WlabelTO3a= ROOT.TGLabel(self.WverticalTO3, "IBiasP1")
                self.WverticalTO3.AddFrame(self.WlabelTO3a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,2,2,2))


                self.IBiasP1_WRITE = ROOT.TGNumberEntry(self.WverticalTO4,100,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO4.AddFrame(self.IBiasP1_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelTO3b= ROOT.TGLabel(self.WverticalTO3, "IBiasP2")
                self.WverticalTO3.AddFrame(self.WlabelTO3b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IBiasP2_WRITE = ROOT.TGNumberEntry(self.WverticalTO4, 150,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO4.AddFrame(self.IBiasP2_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelTO3c= ROOT.TGLabel(self.WverticalTO3, "IBias Disc")
                self.WverticalTO3.AddFrame(self.WlabelTO3c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IBias_Disc_WRITE = ROOT.TGNumberEntry(self.WverticalTO4, 200,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO4.AddFrame(self.IBias_Disc_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelTO3d= ROOT.TGLabel(self.WverticalTO3, "IBias SF")
                self.WverticalTO3.AddFrame(self.WlabelTO3d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IBias_SF_WRITE = ROOT.TGNumberEntry(self.WverticalTO4, 100,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO4.AddFrame(self.IBias_SF_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelTO3e= ROOT.TGLabel(self.WverticalTO3, "VRef Krum")
                self.WverticalTO3.AddFrame(self.WlabelTO3e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.VRef_Krum_WRITE = ROOT.TGNumberEntry(self.WverticalTO4, 490,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO4.AddFrame(self.VRef_Krum_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelTO3f= ROOT.TGLabel(self.WverticalTO3, "IBias Feed")
                self.WverticalTO3.AddFrame(self.WlabelTO3f,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))
                                                                                               
		self.IBias_Feed_WRITE = ROOT.TGNumberEntry(self.WverticalTO4, 80,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalTO4.AddFrame(self.IBias_Feed_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WverticalTO.AddFrame(self.WverticalTO3, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0,5, 5, 5) )
                self.WverticalTO.AddFrame(self.WverticalTO4, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,40, 5, 5) )

		############################
		#### BG Vertical Frames
		############################


                self.WverticalBG1 = ROOT.TGVerticalFrame(self.WverticalBG)
                self.WverticalBG2  = ROOT.TGVerticalFrame(self.WverticalBG)

                self.WlabelBG1a= ROOT.TGLabel(self.WverticalBG1, "ILDac")
                self.WverticalBG1.AddFrame(self.WlabelBG1a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,2,2,2))


                self.ILDac_WRITE = ROOT.TGNumberEntry(self.WverticalBG2, 160,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalBG2.AddFrame(self.ILDac_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBG1b= ROOT.TGLabel(self.WverticalBG1, "IGDac")
                self.WverticalBG1.AddFrame(self.WlabelBG1b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IGDac_WRITE = ROOT.TGNumberEntry(self.WverticalBG2, 1023,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalBG2.AddFrame(self.IGDac_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBG1c= ROOT.TGLabel(self.WverticalBG1, "VRef Krum")
                self.WverticalBG1.AddFrame(self.WlabelBG1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.VRef_Krum1_WRITE = ROOT.TGNumberEntry(self.WverticalBG2, 300,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalBG2.AddFrame(self.VRef_Krum1_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBG1d= ROOT.TGLabel(self.WverticalBG1, "IKrum")
                self.WverticalBG1.AddFrame(self.WlabelBG1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IKrum_WRITE = ROOT.TGNumberEntry(self.WverticalBG2, 50,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalBG2.AddFrame(self.IKrum_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBG1e= ROOT.TGLabel(self.WverticalBG1, "IFC Bias")
                self.WverticalBG1.AddFrame(self.WlabelBG1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IFC_Bias_WRITE = ROOT.TGNumberEntry(self.WverticalBG2, 200,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalBG2.AddFrame(self.IFC_Bias_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))
                
		self.WlabelBG1f= ROOT.TGLabel(self.WverticalBG1, "IPA In Bias")
                self.WverticalBG1.AddFrame(self.WlabelBG1f,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))                                
		
		self.IPA_In_Bias_WRITE = ROOT.TGNumberEntry(self.WverticalBG2, 300,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalBG2.AddFrame(self.IPA_In_Bias_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WverticalBG.AddFrame(self.WverticalBG1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 5, 5, 5) )
                self.WverticalBG.AddFrame(self.WverticalBG2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,5, 5, 5) )


		#################################
		###### SECOND PART  ###########
		###############################
		
		self.Wnames2 = ROOT.TGHorizontalFrame(self.tab2)
		self.Wnames2a = ROOT.TGHorizontalFrame(self.tab2)
	
		self.Wnames2.SetBackgroundColor (25)

		self.WlabelCALL= ROOT.TGLabel(self.Wnames2, "Call Level")
		self.WlabelBA= ROOT.TGLabel(self.Wnames2, "BA")

 		self.Wnames2.AddFrame(self.WlabelCALL,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 10,5,5, 5))
		self.Wnames2.AddFrame(self.WlabelBA,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 150,5,5, 5))

	

		self.WverticalCALL = ROOT.TGHorizontalFrame(self.Wnames2a)
                self.WverticalBA  = ROOT.TGHorizontalFrame(self.Wnames2a)

		self.WverticalBA.SetBackgroundColor (456)
                
		self.Wnames2a.AddFrame(self.WverticalCALL, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 5, 55,0, 5))
                self.Wnames2a.AddFrame(self.WverticalBA, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 5,5,0, 5))
		
		self.tab2.AddFrame( self.Wnames2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10, 25, 5) )
		self.tab2.AddFrame( self.Wnames2a, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10, 0, 0) )

		
		######################################
		#### CALL LEVEL Vertical Frames  #####
		######################################

		self.WverticalCALL1 = ROOT.TGVerticalFrame(self.WverticalCALL)
                self.WverticalCALL2  = ROOT.TGVerticalFrame(self.WverticalCALL)


                self.CALL_LEVEL_WRITE = ROOT.TGNumberEntry(self.WverticalCALL1, 0,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1023 );
                self.WverticalCALL1.AddFrame(self.CALL_LEVEL_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))


                self.WGLOBAL = ROOT.TGHorizontalFrame(self.WverticalCALL1)
                self.WGLOBAL.SetBackgroundColor(25)
                self.WlabelGLOBAL= ROOT.TGLabel(self.WGLOBAL, "Global Bias")
                self.WGLOBAL.AddFrame(self.WlabelGLOBAL,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))
                self.WverticalCALL1.AddFrame(self.WGLOBAL,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelCALL1c= ROOT.TGLabel(self.WverticalCALL1, "IRef")
                self.WverticalCALL1.AddFrame(self.WlabelCALL1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IRef_WRITE = ROOT.TGNumberEntry(self.WverticalCALL2, 20,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 31 );
                self.WverticalCALL2.AddFrame(self.IRef_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))
              
		self.WlabelCALL1d= ROOT.TGLabel(self.WverticalCALL1, "BGR")
                self.WverticalCALL1.AddFrame(self.WlabelCALL1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.BGR_WRITE = ROOT.TGNumberEntry(self.WverticalCALL2, 5,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 31 );				   self.WverticalCALL2.AddFrame(self.BGR_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelCALL1e= ROOT.TGLabel(self.WverticalCALL1, "Mon Mux")
                self.WverticalCALL1.AddFrame(self.WlabelCALL1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.Mon_Mux_WRITE = ROOT.TGNumberEntry(self.WverticalCALL2, 16,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 31 );
                self.WverticalCALL2.AddFrame(self.Mon_Mux_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))


                self.WverticalCALL.AddFrame(self.WverticalCALL1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0, 5, 0, 5) )
		self.WverticalCALL.AddFrame(self.WverticalCALL2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0,5,65, 5) )



		#############################
		#### BA Vertical Frames ######
		##############################

 		self.WverticalBA1 = ROOT.TGVerticalFrame(self.WverticalBA)
                self.WverticalBA2  = ROOT.TGVerticalFrame(self.WverticalBA)

                self.WlabelBA1a= ROOT.TGLabel(self.WverticalBA1, "OP mode")
                self.WverticalBA1.AddFrame(self.WlabelBA1a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,2,2,2))


                self.Op_mode_WRITE = ROOT.TGNumberEntry(self.WverticalBA2, 0,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0,1 );
                self.WverticalBA2.AddFrame(self.Op_mode_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBA1b= ROOT.TGLabel(self.WverticalBA1, "ITrans gain")
                self.WverticalBA1.AddFrame(self.WlabelBA1b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.ITrans_gain_WRITE = ROOT.TGNumberEntry(self.WverticalBA2, 8,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0,15 );
                self.WverticalBA2.AddFrame(self.ITrans_gain_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBA1c= ROOT.TGLabel(self.WverticalBA1, "IDischarge")
                self.WverticalBA1.AddFrame(self.WlabelBA1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.IDischarge_WRITE = ROOT.TGNumberEntry(self.WverticalBA2, 28,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 63 );
                self.WverticalBA2.AddFrame(self.IDischarge_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBA1d= ROOT.TGLabel(self.WverticalBA1, "ICharge")
                self.WverticalBA1.AddFrame(self.WlabelBA1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.ICharge_WRITE = ROOT.TGNumberEntry(self.WverticalBA2, 28,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0,63 );
                self.WverticalBA2.AddFrame(self.ICharge_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.WlabelBA1e= ROOT.TGLabel(self.WverticalBA1, "Comp Thr")
                self.WverticalBA1.AddFrame(self.WlabelBA1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,9,2))

                self.Comp_Thr_WRITE = ROOT.TGNumberEntry(self.WverticalBA2, 16,9,999,ROOT.TGNumberFormat.kNESInteger ,ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 31 );
                self.WverticalBA2.AddFrame(self.Comp_Thr_WRITE,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))
                

                self.WverticalBA.AddFrame(self.WverticalBA1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 5, 5, 5) )
                self.WverticalBA.AddFrame(self.WverticalBA2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,5, 5, 5) )


