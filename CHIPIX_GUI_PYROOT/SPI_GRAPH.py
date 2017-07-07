import ROOT


def SpiGraphEx(self):


                self.space    = ROOT.TGHorizontalFrame(self.tab3)   #, 500,500, ROOT.kRaisedFrame) # kRaisedFrame = high relief
                self.vertical  = ROOT.TGVerticalFrame(self.space)   #, 500,500, ROOT.kRaisedFrame)
                self.vertical2 = ROOT.TGVerticalFrame(self.space)   #, 500,500, ROOT.kRaisedFrame)
                self.vertical3 = ROOT.TGVerticalFrame(self.space)   #, 500,500, ROOT.kRaisedFrame)

                self.spiNumber = ROOT.TGNumberEntry(self.vertical, 0, 9, 999, ROOT.TGNumberFormat.kNESHex, ROOT.TGNumberFormat.kNEANonNegative, ROOT.TGNumberFormat.kNELLimitMinMax, 0, 1048575)

                self.spiButton  = ROOT.TGTextButton( self.vertical2, "   &Send SPI command to CHIPIX   ")
                self.Do_spiNumber = ROOT.TPyDispatcher( self.my_spiNumber )
                self.spiButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_spiNumber, 'Dispatch()')

                self.numberframe = ROOT.TGGroupFrame(self.vertical2, "SPI command to send")
                #self.label_space.AddFrame(self.numberframe,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,200,10,0))
                self.label2 = ROOT.TGLabel(self.numberframe, "No input.")
                self.numberframe.AddFrame(self.label2, ROOT.TGLayoutHints(ROOT.kLHintsTop | ROOT.kLHintsLeft,15,200,15,5))

                self.spireceivedButton  = ROOT.TGTextButton( self.vertical3, "   &Received SPI command to CHIPIX   ")
                self.Do_spireceivedButton = ROOT.TPyDispatcher( self.my_received_spi )
                self.spireceivedButton.Connect('Clicked()' , 'TPyDispatcher' , self.Do_spireceivedButton, 'Dispatch()')

                self.number2frame = ROOT.TGGroupFrame(self.vertical3, "Board respoce to SPI command ")
                #self.label_space.AddFrame(self.number2frame,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,200,10,0))
                self.label3 = ROOT.TGLabel(self.number2frame, "No input.")
                self.number2frame.AddFrame(self.label3, ROOT.TGLayoutHints(ROOT.kLHintsTop | ROOT.kLHintsLeft,15,200,15,5))

                self.reset_chipix_Button  = ROOT.TGTextButton( self.tab3, "   &Reset CHIPIX SPI command ")
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

                self.tab3.AddFrame(self.reset_chipix_Button,ROOT.TGLayoutHints(ROOT.kLHintsLeft|ROOT.kLHintsExpandX,10,500,10,0))

                self.tab3.AddFrame(self.space, ROOT.TGLayoutHints(ROOT.kLHintsTop|ROOT.kLHintsLeft, 50, 5, 20, 5))


