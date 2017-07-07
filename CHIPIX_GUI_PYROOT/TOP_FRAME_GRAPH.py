
import sys,socket

try :
   import ROOT

except ImportError :
   raise ImportError, "ROOT bindings are required to run this application!"


def TopFrameGraphEx(self):

                self.SetWindowName( 'GUI CHIPIX' )

		
 		#######################################################################################
                ## when click the cross "close window" icon, terminate the application and exit Python 
                ########################################################################################

                self.CloseWindowDispatcher = ROOT.TPyDispatcher( self.CloseWindow ) # this command translate the python command in C++ launguage I think

		self.Connect( "CloseWindow()", "TPyDispatcher", self.CloseWindowDispatcher, "Dispatch()" )




		###########################################################################################
                ## build a top frame to contains TABs and a "Quit" button
                ###########################################################################################

		# create a FRAME

                self.topFrame = ROOT.TGHorizontalFrame(self, 650, 100, ROOT.kHorizontalFrame )
	
		# put the  button QUIT in the frame

                self.QUITButton = ROOT.TGTextButton( self.topFrame, "   &Caterina  ")

		self.topFrame.AddFrame( self.QUITButton, ROOT.TGLayoutHints( ROOT.kLHintsRight, 0, 15, 10, 0) )

                self.AddFrame( self.topFrame, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0, 0, 0, 0) )

		# connect the button QUIT to its function

                self.QUITButton.Connect('Clicked()' , 'TPyDispatcher' , self.CloseWindowDispatcher, 'Dispatch()')
 
		# put the button CONNECT in the frame

		self.CONNECTButton  = ROOT.TGTextButton( self.topFrame, "   &Connect   ")

		self.topFrame.AddFrame( self.CONNECTButton, ROOT.TGLayoutHints( ROOT.kLHintsLeft, 15, 0, 10, 0) )

                # connect the button CONNECT to its function

	        self.Do_Connect = ROOT.TPyDispatcher( self.my_Connect ) # this command translate the python command in C++ launguage I think

		self.CONNECTButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_Connect, 'Dispatch()')

		
		# put the button  DISCONNECT in the frame

                self.DISCONNECTButton  = ROOT.TGTextButton( self.topFrame, "   &Disconnect   ")

                self.topFrame.AddFrame( self.DISCONNECTButton, ROOT.TGLayoutHints( ROOT.kLHintsLeft, 20, 0, 10, 0) )

                # connect the button CONNECT to its function

                self.Do_Disconnect = ROOT.TPyDispatcher( self.my_Disconnect ) # this command translate the python command in C++ launguage I think

                self.DISCONNECTButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_Disconnect, 'Dispatch()')

                ##############################################################################################

                self.tabsFrame = ROOT.TGTab(self, 650, 200)
                self.tabsFrame.DrawBorder()

                self.tab1 = self.tabsFrame.AddTab("  READ  ") # **NOTE! Each tab is now a ROOT.TGCompositeFrame object

                self.tab2 = self.tabsFrame.AddTab("  WRITE   ") # **NOTE! Each tab is now a ROOT.TGCompositeFrame object

                self.tab3 = self.tabsFrame.AddTab("  SPI   ") # **NOTE! Each tab is now a ROOT.TGCompositeFrame object

		self.tab4 = self.tabsFrame.AddTab("  ADC   ") # **NOTE! Each tab is now a ROOT.TGCompositeFrame object


                # ad the Tabs to the Frame

                self.AddFrame(self.tabsFrame,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,10,20,20,0) )
		
def GuiAttributesEx(self):

		
	 	self.MapSubwindows()


                # Initialize the layout algorithm via Resize()
                self.Resize( self.GetDefaultSize() )

                # Map main frame
                self.MapWindow()
                self.Resize(self.width, self.height)

