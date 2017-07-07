
import sys,socket

try :
   import ROOT

except ImportError :
   raise ImportError, "ROOT bindings are required to run this application!"



def ReadGraphEx(self):

                self.ReadGCR = ROOT.TGTextButton( self.tab1,  "   &Read GCR   ")
		self.Do_Read_GCR = ROOT.TPyDispatcher( self.Read_GRC ) # this command translate the python command in C++ launguage I think
		self.ReadGCR.Connect('Clicked()' , 'TPyDispatcher' , self.Do_Read_GCR, 'Dispatch()')


		self.tab1.AddFrame(self.ReadGCR,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 10,10,10, 0))


   		self.ReadScreen = ROOT.TGHorizontalFrame (self.tab1, 600,20)
                self.label1 = ROOT.TGLabel(self.ReadScreen, "Read GCR")
                self.ReadScreen.AddFrame(self.label1,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5,5,5, 5))
                self.tab1.AddFrame(self.ReadScreen,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 0,10,5, 5))

		
		############################################################
		#### Frame of READ PART ####################################
		############################################################

		
		#########################
		#### FIRST PART #########
		#########################

		self.names1 = ROOT.TGHorizontalFrame(self.tab1) # 300, 20, ROOT.kRaisedFrame)
                self.names1.SetBackgroundColor (25)
		self.names1.DrawBorder()

		self.labelTO = ROOT.TGLabel(self.names1, "TO")
		self.labelBG = ROOT.TGLabel(self.names1, "BG/PV.")
		
		self.labelTO.SetTextColor(ROOT.kWhite)

		self.names1.AddFrame(self.labelTO,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5,5,5, 5))
		self.names1.AddFrame(self.labelBG,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 570,5,5, 5))
		
		self.tab1.AddFrame( self.names1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10,- 5, 5) )

		self.names1a = ROOT.TGHorizontalFrame(self.tab1)

		self.verticalTO  = ROOT.TGHorizontalFrame(self.names1a)   #, 500,500, ROOT.kRaisedFrame)
                self.verticalBG  = ROOT.TGHorizontalFrame(self.names1a)   #, 500,500, ROOT.kRaisedFrame)
               
                self.verticalTO.SetBackgroundColor (345)
                self.verticalBG.SetBackgroundColor (456)
		
		self.names1a.AddFrame(self.verticalTO,  ROOT.TGLayoutHints(ROOT.kLHintsLeft, 5 ,5 , 5, 5))
                self.names1a.AddFrame(self.verticalBG, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 105, 5, 5, 5))
              

		self.tab1.AddFrame( self.names1a, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10,- 5, 0) )

		###################################################
		###### TO frames ########
		##################################################

		# First Coloumn
		
		self.verticalTO1 = ROOT.TGVerticalFrame(self.verticalTO,10,100,1)
		self.verticalTO2  = ROOT.TGVerticalFrame(self.verticalTO,5,5)		

		self.verticalTO2.SetBackgroundColor (345)

		self.labelTO1a= ROOT.TGLabel(self.verticalTO1, "PHI AZ Delay") 		
		self.verticalTO1.AddFrame(self.labelTO1a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,130,2,2))
		

		self.textViewTO1a = ROOT.TGLabel(self.verticalTO2, "             " );
                self.verticalTO2.AddFrame(self.textViewTO1a,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,3,2))
		self.textViewTO1a.DrawBorder()

		self.labelTO1b= ROOT.TGLabel(self.verticalTO1, "PHI AZ High Level")
                self.verticalTO1.AddFrame(self.labelTO1b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

		self.textViewTO1b = ROOT.TGLabel(self.verticalTO2, "             " );
                self.verticalTO2.AddFrame(self.textViewTO1b,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

		self.labelTO1c= ROOT.TGLabel(self.verticalTO1, "PHI AZ Low Level")
                self.verticalTO1.AddFrame(self.labelTO1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

		self.textViewTO1c = ROOT.TGLabel(self.verticalTO2, "             " );
                self.verticalTO2.AddFrame(self.textViewTO1c,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

		self.labelTO1d= ROOT.TGLabel(self.verticalTO1, "ICtrl TOT")
                self.verticalTO1.AddFrame(self.labelTO1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

		self.textViewTO1d = ROOT.TGLabel(self.verticalTO2, "             " );
                self.verticalTO2.AddFrame(self.textViewTO1d,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

		self.labelTO1e= ROOT.TGLabel(self.verticalTO1, "VTh Disc")
                self.verticalTO1.AddFrame(self.labelTO1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

		self.textViewTO1e = ROOT.TGLabel(self.verticalTO2, "             " );
                self.verticalTO2.AddFrame(self.textViewTO1e,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))
		
		self.labelTO1f= ROOT.TGLabel(self.verticalTO1, "VBl Disc")
                self.verticalTO1.AddFrame(self.labelTO1f,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

		self.textViewTO1f = ROOT.TGLabel(self.verticalTO2, "             " );
                self.verticalTO2.AddFrame(self.textViewTO1f,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))
		
		self.verticalTO.AddFrame(self.verticalTO1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,5, 5, 5) )
		self.verticalTO.AddFrame(self.verticalTO2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 20,20, 5, 5) )


		# Second Coloumn

		self.verticalTO3 = ROOT.TGVerticalFrame(self.verticalTO)
                self.verticalTO4 = ROOT.TGVerticalFrame(self.verticalTO)

		self.verticalTO4.SetBackgroundColor (345)

                self.labelTO3a= ROOT.TGLabel(self.verticalTO3, "IBiasP1")
                self.verticalTO3.AddFrame(self.labelTO3a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,2,2,2))


                self.textViewTO4a = ROOT.TGLabel(self.verticalTO4, "             " );
                self.verticalTO4.AddFrame(self.textViewTO4a,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.labelTO3b= ROOT.TGLabel(self.verticalTO3, "IBiasP2")
                self.verticalTO3.AddFrame(self.labelTO3b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewTO4b = ROOT.TGLabel(self.verticalTO4, "             " );
                self.verticalTO4.AddFrame(self.textViewTO4b,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelTO3c= ROOT.TGLabel(self.verticalTO3, "IBias Disc")
                self.verticalTO3.AddFrame(self.labelTO3c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewTO4c = ROOT.TGLabel(self.verticalTO4, "             " );
                self.verticalTO4.AddFrame(self.textViewTO4c,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelTO3d= ROOT.TGLabel(self.verticalTO3, "IBias SF")
                self.verticalTO3.AddFrame(self.labelTO3d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewTO4d = ROOT.TGLabel(self.verticalTO4, "             " );
                self.verticalTO4.AddFrame(self.textViewTO4d,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelTO3e= ROOT.TGLabel(self.verticalTO3, "VRef Krum")
                self.verticalTO3.AddFrame(self.labelTO3e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewTO4e = ROOT.TGLabel(self.verticalTO4, "             " );
                self.verticalTO4.AddFrame(self.textViewTO4e,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelTO3f= ROOT.TGLabel(self.verticalTO3, "IBias Feed")
                self.verticalTO3.AddFrame(self.labelTO3f,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))
                                                                                               
		self.textViewTO4f = ROOT.TGLabel(self.verticalTO4, "             " );
                self.verticalTO4.AddFrame(self.textViewTO4f,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.verticalTO.AddFrame(self.verticalTO3, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0,5, 5, 5) )
                self.verticalTO.AddFrame(self.verticalTO4, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,40, 5, 5) )

		############################
		#### BG Vertical Frames
		############################


                self.verticalBG1 = ROOT.TGVerticalFrame(self.verticalBG)
                self.verticalBG2  = ROOT.TGVerticalFrame(self.verticalBG)
		self.verticalBG2.SetBackgroundColor (456)

                self.labelBG1a= ROOT.TGLabel(self.verticalBG1, "ILDac")
                self.verticalBG1.AddFrame(self.labelBG1a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,40,3,2))


                self.textViewBG1a = ROOT.TGLabel(self.verticalBG2, "             " );
                self.verticalBG2.AddFrame(self.textViewBG1a,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.labelBG1b= ROOT.TGLabel(self.verticalBG1, "IGDac")
                self.verticalBG1.AddFrame(self.labelBG1b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBG1b = ROOT.TGLabel(self.verticalBG2, "             " );
                self.verticalBG2.AddFrame(self.textViewBG1b,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelBG1c= ROOT.TGLabel(self.verticalBG1, "VRef Krum")
                self.verticalBG1.AddFrame(self.labelBG1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBG1c = ROOT.TGLabel(self.verticalBG2, "             " );
                self.verticalBG2.AddFrame(self.textViewBG1c,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelBG1d= ROOT.TGLabel(self.verticalBG1, "IKrum")
                self.verticalBG1.AddFrame(self.labelBG1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBG1d = ROOT.TGLabel(self.verticalBG2, "             " );
                self.verticalBG2.AddFrame(self.textViewBG1d,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelBG1e= ROOT.TGLabel(self.verticalBG1, "IFC Bias")
                self.verticalBG1.AddFrame(self.labelBG1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBG1e = ROOT.TGLabel(self.verticalBG2, "             " );
                self.verticalBG2.AddFrame(self.textViewBG1e,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))
                
		self.labelBG1f= ROOT.TGLabel(self.verticalBG1, "IPA In Bias")
                self.verticalBG1.AddFrame(self.labelBG1f,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))                                
		self.textViewBG1f = ROOT.TGLabel(self.verticalBG2, "             " );
                self.verticalBG2.AddFrame(self.textViewBG1f,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.verticalBG.AddFrame(self.verticalBG1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 5, 5, 5) )
                self.verticalBG.AddFrame(self.verticalBG2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,5, 5, 5) )


		#################################
		###### SECOND PART  ###########
		###############################
		
		self.names2 = ROOT.TGHorizontalFrame(self.tab1)	
		self.names2a = ROOT.TGHorizontalFrame(self.tab1)
	
		self.names2.SetBackgroundColor (25)

		self.labelCALL= ROOT.TGLabel(self.names2, "Call Level")
		self.labelBA= ROOT.TGLabel(self.names2, "BA")

 		self.names2.AddFrame(self.labelCALL,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 10,5,5, 5))
		self.names2.AddFrame(self.labelBA,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 150,5,5, 5))

	

		self.verticalCALL = ROOT.TGHorizontalFrame(self.names2a)
                self.verticalBA  = ROOT.TGHorizontalFrame(self.names2a)

		self.verticalBA.SetBackgroundColor (456)
                
		self.names2a.AddFrame(self.verticalCALL, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 5, 55,0, 5))
                self.names2a.AddFrame(self.verticalBA, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 5,5,0, 5))
		
		self.tab1.AddFrame( self.names2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10, 25, 5) )
		self.tab1.AddFrame( self.names2a, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 10, 0, 0) )

		
		######################################
		#### CALL LEVEL Vertical Frames  #####
		######################################

		self.verticalCALL1 = ROOT.TGVerticalFrame(self.verticalCALL)
                self.verticalCALL2  = ROOT.TGVerticalFrame(self.verticalCALL)


                self.textViewCALL1a = ROOT.TGLabel(self.verticalCALL1, "             " );
                self.verticalCALL1.AddFrame(self.textViewCALL1a,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,3,2))

		
                self.GLOBAL = ROOT.TGHorizontalFrame(self.verticalCALL1)
                self.GLOBAL.SetBackgroundColor(25)
                self.labelGLOBAL= ROOT.TGLabel(self.GLOBAL, "Global Bias")
                self.GLOBAL.AddFrame(self.labelGLOBAL,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))
                self.verticalCALL1.AddFrame(self.GLOBAL,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelCALL1c= ROOT.TGLabel(self.verticalCALL1, "IRef")
                self.verticalCALL1.AddFrame(self.labelCALL1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewCALL1c = ROOT.TGLabel(self.verticalCALL2, "             " );
                self.verticalCALL2.AddFrame(self.textViewCALL1c,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))
              
		self.labelCALL1d= ROOT.TGLabel(self.verticalCALL1, "BGR")
                self.verticalCALL1.AddFrame(self.labelCALL1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewCALL1d = ROOT.TGLabel(self.verticalCALL2, "         " );
                self.verticalCALL2.AddFrame(self.textViewCALL1d,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelCALL1e= ROOT.TGLabel(self.verticalCALL1, "Mon Mux")
                self.verticalCALL1.AddFrame(self.labelCALL1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewCALL1e = ROOT.TGLabel(self.verticalCALL2, "             " );
                self.verticalCALL2.AddFrame(self.textViewCALL1e,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))


                self.verticalCALL.AddFrame(self.verticalCALL1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0, 5, 0, 5) )
		self.verticalCALL.AddFrame(self.verticalCALL2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0,5,55, 5) )



		#############################
		#### BA Vertical Frames ######
		##############################

 		self.verticalBA1 = ROOT.TGVerticalFrame(self.verticalBA)
                self.verticalBA2  = ROOT.TGVerticalFrame(self.verticalBA)
		self.verticalBA2.SetBackgroundColor (456)

                self.labelBA1a= ROOT.TGLabel(self.verticalBA1, "OP mode")
                self.verticalBA1.AddFrame(self.labelBA1a, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,2,40,3,2))


                self.textViewBA1a = ROOT.TGLabel(self.verticalBA2, "             " );
                self.verticalBA2.AddFrame(self.textViewBA1a,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,2,2))

                self.labelBA1b= ROOT.TGLabel(self.verticalBA1, "ITrans gain")
                self.verticalBA1.AddFrame(self.labelBA1b,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBA1b = ROOT.TGLabel(self.verticalBA2, "             " );
                self.verticalBA2.AddFrame(self.textViewBA1b,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelBA1c= ROOT.TGLabel(self.verticalBA1, "IDischarge")
                self.verticalBA1.AddFrame(self.labelBA1c,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBA1c = ROOT.TGLabel(self.verticalBA2, "             " );
                self.verticalBA2.AddFrame(self.textViewBA1c,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelBA1d= ROOT.TGLabel(self.verticalBA1, "ICharge")
                self.verticalBA1.AddFrame(self.labelBA1d,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBA1d = ROOT.TGLabel(self.verticalBA2, "             " );
                self.verticalBA2.AddFrame(self.textViewBA1d,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))

                self.labelBA1e= ROOT.TGLabel(self.verticalBA1, "Comp Thr")
                self.verticalBA1.AddFrame(self.labelBA1e,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 2,2,7,2))

                self.textViewBA1e = ROOT.TGLabel(self.verticalBA2, "             " );
                self.verticalBA2.AddFrame(self.textViewBA1e,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,2,2,7,2))
                

                self.verticalBA.AddFrame(self.verticalBA1, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5, 5, 5, 5) )
                self.verticalBA.AddFrame(self.verticalBA2, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 5,5, 5, 5) )

		        
