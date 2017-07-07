import ROOT

##################
#### MAIN WINDOW
#################

	        #######################################################################################
                ## when click the cross "close window" icon, terminate the application and exit Python 
                ########################################################################################

def MainWindowEx(self):

                self.CloseWindowDispatcher = ROOT.TPyDispatcher( self.CloseWindow )
                self.Connect( "CloseWindow()", "TPyDispatcher", self.CloseWindowDispatcher, "Dispatch()" )

                ###########################################################################################
                ## build a top frame to contains TABs and a "Quit" button
                ###########################################################################################

                self.topFrame = ROOT.TGHorizontalFrame(self, 650, 100, ROOT.kHorizontalFrame )
                self.Connect( "CloseWindow()", "TPyDispatcher", self.CloseWindowDispatcher, "Dispatch()" )

                self.quitButton  = ROOT.TGTextButton( self.topFrame, "   &Quit   ")
                self.quitButton.Connect    ('Clicked()' , 'TPyDispatcher' , self.CloseWindowDispatcher, 'Dispatch()')
                self.helpButton  = ROOT.TGTextButton( self.topFrame, "   &Help   ")
                self.Do_help = ROOT.TPyDispatcher( self.my_help )
                self.helpButton.Connect    ('Clicked()' , 'TPyDispatcher' , self.Do_help, 'Dispatch()')
                self.connectButton  = ROOT.TGTextButton( self.topFrame, "   &Connect   ")
                self.Do_Connect = ROOT.TPyDispatcher( self.my_Connect )
                self.connectButton.Connect    ('Clicked()' , 'TPyDispatcher' , self.Do_Connect, 'Dispatch()')

                self.topFrame.AddFrame( self.quitButton, ROOT.TGLayoutHints( ROOT.kLHintsRight, 0, 15, 10, 0) )
                self.topFrame.AddFrame( self.helpButton, ROOT.TGLayoutHints( ROOT.kLHintsRight, 0, 15, 10, 0) )
                self.topFrame.AddFrame( self.connectButton, ROOT.TGLayoutHints( ROOT.kLHintsRight, 0, 15, 10, 0) )
                self.AddFrame( self.topFrame, ROOT.TGLayoutHints( ROOT.kLHintsTop | ROOT.kLHintsExpandX, 0, 0, 0, 0) )

                ##############################################################################################
                ## TABs frame
                ###############################################################################################

                self.tabsFrame = ROOT.TGTab(self, 650, 200)
                self.tabsFrame.DrawBorder()







		#################################
                ##   tab LED color test        ##
                #################################

def TabLedEx(self):


                self.tabA = self.tabsFrame.AddTab(" Color test ") # **NOTE! Each tab is now a ROOT.TGCompositeFrame object

                ## create a vertical frame
                self.verticalbuttons  = ROOT.TGVerticalFrame(self.tabA, 200, 200 , ROOT.kRaisedFrame)

                ## create buttons

                self.Turn_on_red    = ROOT.TGTextButton( self.verticalbuttons, "Turn on red led"   , 10 )
                self.Turn_off_red   = ROOT.TGTextButton( self.verticalbuttons, "Turn off red led"  , 20 )
                self.Turn_on_green  = ROOT.TGTextButton( self.verticalbuttons, "Turn on green led" , 30 )
                self.Turn_off_green = ROOT.TGTextButton( self.verticalbuttons, "Turn off green led", 40 )
                self.Turn_on_blue   = ROOT.TGTextButton( self.verticalbuttons, "Turn on blue led"  , 50 )
                self.Turn_off_blue  = ROOT.TGTextButton( self.verticalbuttons, "Turn off blue led" , 60 )

                self.verticalbuttons.AddFrame(self.Turn_on_red,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,10,10,10,0))
               # left right top bottom
                self.verticalbuttons.AddFrame(self.Turn_off_red,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,10,10,10,0))
                self.verticalbuttons.AddFrame(self.Turn_on_green,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,10,10,10,0))
                self.verticalbuttons.AddFrame(self.Turn_off_green,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,10,10,10,0))
                self.verticalbuttons.AddFrame(self.Turn_on_blue,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,10,10,10,0))
                self.verticalbuttons.AddFrame(self.Turn_off_blue,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft,10,10,10,0))

                self.tabA.AddFrame(self.verticalbuttons,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,500,10,0))



                # connect the buttons to a function
                self.Do_send = ROOT.TPyDispatcher( self.send )

                self.Turn_on_red.Connect    ('Clicked()' , 'TPyDispatcher' , self.Do_send, 'Dispatch()')
                self.Turn_off_red.Connect   ('Clicked()' , 'TPyDispatcher' , self.Do_send, 'Dispatch()')
                self.Turn_on_blue.Connect   ('Clicked()' , 'TPyDispatcher' , self.Do_send, 'Dispatch()')
                self.Turn_off_blue.Connect  ('Clicked()' , 'TPyDispatcher' , self.Do_send, 'Dispatch()')
                self.Turn_on_green.Connect  ('Clicked()' , 'TPyDispatcher' , self.Do_send, 'Dispatch()')
                self.Turn_off_green.Connect ('Clicked()' , 'TPyDispatcher' , self.Do_send, 'Dispatch()')




		#############################################################################################
                ###  tab trasmission
                #############################################################################################


def TabHexTransmissionEx(self):

                self.tabB = self.tabsFrame.AddTab(" Test Hex Received ")

                self.label_space = ROOT.TGHorizontalFrame(self.tabB, 500, 500, ROOT.kRaisedFrame)
                self.tabB.AddFrame(self.label_space,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,10,10,0))

                self.hext = ROOT.TGGroupFrame( self.label_space, "Hex Trasmitted")
                self.label = ROOT.TGLabel(self.hext, "No input.")
                self.hext.AddFrame(self.label, ROOT.TGLayoutHints(ROOT.kLHintsTop | ROOT.kLHintsLeft,15,15,15,5))

                self.hexr = ROOT.TGGroupFrame( self.label_space, "Hex Received")
                self.label1 = ROOT.TGLabel(self.hexr, "No input.");
                self.hexr.AddFrame(self.label1, ROOT.TGLayoutHints(ROOT.kLHintsTop | ROOT.kLHintsLeft,15,15,15,5));

                self.label_space.AddFrame(self.hext,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,10,10,0))
                self.label_space.AddFrame(self.hexr,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,10,10,0))

                # TextView Send
                self.textViewsend = ROOT.TGTextViewostream(self.tabB, 100, 200);
                self.tabB.AddFrame(self.textViewsend,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,5,5,5,0))

                # TextView Trasmit from FPGA
                self.textViewtras = ROOT.TGTextViewostream(self.tabB, 100, 200);
                self.tabB.AddFrame(self.textViewtras,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,5,5,5,0))

#               self.ButtonsFrame = ROOT.TGHorizontalFrame( self, 200, 60 )

		


		##############################################################
                ############ tab send received verify
                ##############################################################


def TabTestTransmissionEx(self):

                self.tabC = self.tabsFrame.AddTab(" Test trasmission ")

                self.space = ROOT.TGHorizontalFrame(self.tabC)

                # TextView Send
                self.verify = ROOT.TGTextViewostream(self.tabC, 100, 200);
                self.tabC.AddFrame(self.verify,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,5,5,5,0))



		##############################################################
                ############ last mess on board
                ##############################################################

def TabLastMessEx(self):

                self.tabD = self.tabsFrame.AddTab(" Last word on board ")

                self.space = ROOT.TGHorizontalFrame(self.tabD)

                self.lastButton  = ROOT.TGTextButton( self.tabD, "   &Last word on board   ")
                self.tabD.AddFrame(self.lastButton,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,500,10,0))
                self.Do_last = ROOT.TPyDispatcher( self.my_last_word )
                self.lastButton.Connect    ('Clicked()' , 'TPyDispatcher' , self.Do_last, 'Dispatch()')

                self.resetButton  = ROOT.TGTextButton( self.tabD, "   &Reset counter   ")
                self.tabD.AddFrame(self.resetButton,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,500,10,0))
                self.Do_reset = ROOT.TPyDispatcher( self.my_reset )
                self.resetButton.Connect    ('Clicked()' , 'TPyDispatcher' , self.Do_reset, 'Dispatch()')

                # TextView Send
                self.last = ROOT.TGTextViewostream(self.tabD, 100, 200);
                self.tabD.AddFrame(self.last,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,5,5,5,0))


		##############################################################
                ## spi
                ##############################################################


def TabSpiEx(self):

                self.tabE = self.tabsFrame.AddTab(" Spi ")

                self.space    = ROOT.TGHorizontalFrame(self.tabE)   #, 500,500, ROOT.kRaisedFrame) # kRaisedFrame = high relief
                self.vertical  = ROOT.TGVerticalFrame(self.space)   #, 500,500, ROOT.kRaisedFrame)
                self.vertical2 = ROOT.TGVerticalFrame(self.space)   #, 500,500, ROOT.kRaisedFrame)
                self.vertical3 = ROOT.TGVerticalFrame(self.space)   #, 500,500, ROOT.kRaisedFrame)

                self.spiNumber = ROOT.TGNumberEntry(self.vertical, 0, 9, 999, ROOT.TGNumberFormat.kNESHex, ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1048575)
                self.Do_Setlabel = ROOT.TPyDispatcher( self.my_spiNumber_label )
                self.spiNumber.GetNumberEntry().Connect('ReturnPressed()', 'TPyDispatcher' , self.Do_Setlabel, 'Dispatch()')

                self.spiButton  = ROOT.TGTextButton( self.vertical2, "   &Send SPI command to CHIPIX   ")
                self.Do_spiNumber = ROOT.TPyDispatcher( self.my_spiNumber )
                self.spiButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_spiNumber, 'Dispatch()')

                self.numberframe = ROOT.TGGroupFrame(self.vertical2, "SPI command to send")
                self.label_space.AddFrame(self.numberframe,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,200,10,0))
                self.label2 = ROOT.TGLabel(self.numberframe, "No input.")
                self.numberframe.AddFrame(self.label2, ROOT.TGLayoutHints(ROOT.kLHintsTop | ROOT.kLHintsLeft,15,200,15,5))

                self.spireceivedButton  = ROOT.TGTextButton( self.vertical3, "   &Received SPI command to CHIPIX   ")
                self.Do_spireceivedButton = ROOT.TPyDispatcher( self.my_received_spi )
                self.spireceivedButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_spireceivedButton, 'Dispatch()')

                self.number2frame = ROOT.TGGroupFrame(self.vertical3, "Board respoce to SPI command ")
                self.label_space.AddFrame(self.number2frame,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,200,10,0))
                self.label3 = ROOT.TGLabel(self.number2frame, "No input.")
                self.number2frame.AddFrame(self.label3, ROOT.TGLayoutHints(ROOT.kLHintsTop | ROOT.kLHintsLeft,15,200,15,5))

                self.reset_chipix_Button  = ROOT.TGTextButton( self.tabE, "   &Reset CHIPIX SPI command ")
                self.Do_reset_Button = ROOT.TPyDispatcher( self.reset_Button )
                self.reset_chipix_Button.Connect('Clicked()' , 'TPyDispatcher' , self.Do_reset_Button, 'Dispatch()')

                self.vertical.AddFrame (self.spiNumber, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 50, 5, 5, 5))

                self.vertical2.AddFrame(self.spiButton, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))
                self.vertical2.AddFrame(self.numberframe, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))

                self.vertical3.AddFrame(self.spireceivedButton, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))
                self.vertical3.AddFrame(self.number2frame, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))


                self.space.AddFrame(self.vertical,  ROOT.TGLayoutHints(ROOT.kLHintsLeft, 10, 5, 5, 5))
                self.space.AddFrame(self.vertical2, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 10, 5, 5, 5))
                self.space.AddFrame(self.vertical3, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 10, 5, 5, 5))

                self.tabE.AddFrame(self.reset_chipix_Button,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,500,10,0))

                self.tabE.AddFrame(self.space, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 50, 5, 20, 5))


		###############################################################################################
                ## in this tabulation graph V vs bit
                ###############################################################################################

def TabGraphEx(self):

                self.tabF = self.tabsFrame.AddTab(" Graph V vs Bit ")

                self.h_space    = ROOT.TGHorizontalFrame(self.tabF)

                self.graph_vertical = ROOT.TGVerticalFrame(self.h_space, 500,500, ROOT.kRaisedFrame)
                self.buttons_vertical = ROOT.TGVerticalFrame(self.h_space, 200,200, ROOT.kRaisedFrame)

                self.my_Canvas  = ROOT.TRootEmbeddedCanvas( 'Canvas', self.graph_vertical, 500, 500 )

#               self.my_Canvas.GetCanvas().Divide(2,1)

                self.graph_button = ROOT.TGTextButton( self.buttons_vertical, " &Generate graph V vs Bit for calibration level   ")
                self.Do_my_plot = ROOT.TPyDispatcher( self.my_plot )
                self.graph_button.Connect('Clicked()' , 'TPyDispatcher' , self.Do_my_plot, 'Dispatch()')

                self.fit_button = ROOT.TGTextButton( self.buttons_vertical, " &Fit graph")
                self.Do_fit = ROOT.TPyDispatcher( self.my_fit )
                self.fit_button.Connect('Clicked()' , 'TPyDispatcher' , self.Do_fit, 'Dispatch()')

#               self.dns_button = ROOT.TGTextButton( self.buttons_vertical, " &DNL ")
#               self.Do_my_plot2 = ROOT.TPyDispatcher( self.my_plot2 )
#               self.dns_button.Connect('Clicked()' , 'TPyDispatcher' , self.Do_my_plot2, 'Dispatch()')


                self.graph_vertical.AddFrame(self.my_Canvas, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))
                self.buttons_vertical.AddFrame(self.graph_button, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))
                self.buttons_vertical.AddFrame(self.fit_button, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))
#               self.buttons_vertical.AddFrame(self.dns_button, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))

                self.h_space.AddFrame(self.graph_vertical, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 10, 5, 5, 5))
                self.h_space.AddFrame(self.buttons_vertical, ROOT.TGLayoutHints(ROOT.kLHintsLeft, 10, 5, 5, 5))


                self.tabF.AddFrame(self.h_space, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 5, 5, 5, 5))
 

def WindowAttributeEx(self):

		###############################################################################################
                ## add buttons and tab frame 
                ###############################################################################################

                self.AddFrame(self.topFrame,ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsExpandX, 0, 0, 0, 0) )
                self.AddFrame(self.tabsFrame,ROOT.TGLayoutHints(ROOT.kLHintsExpandX|ROOT.kLHintsExpandY,10,20,0,0) )

                ###################################################################################################
                ###  properties definition of the Window 
                ###################################################################################################

                # Set a name to the main frame
                self.SetWindowName( 'GUI CHIPIX' )
                self.MapSubwindows()

                # Initialize the layout algorithm via Resize()
                self.Resize( self.GetDefaultSize() )

                # Map main frame
                self.MapWindow()
                self.Resize(self.width, self.height)



def CloseWindowEx(self) :

                # verify existence of socket, if there is close it
                try:
                        self.sending.close()
                        self.reception.close()
                        ROOT.gApplication.Terminate(0)
                        raise SystemExit
                        #exit()
                except:
                        ROOT.gApplication.Terminate(0)
                        raise SystemExit
                        #exit()

