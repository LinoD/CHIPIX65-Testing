
import sys,socket
import TOP_FRAME_GRAPH
import READ_GRAPH
import READ_FUNC
import WRITE_GRAPH
import WRITE_FUNC
import SPI_GRAPH
import SPI_FUNC
import ADC_GRAPH
import ADC_FUNC
import MESSAGES

try :
   import ROOT

except ImportError :
   raise ImportError, "ROOT bindings are required to run this application!"


###################################################################################################
### gui structure
###################################################################################################

class my_Canvas( ROOT.TGMainFrame ):

        #################################################################################
        ###### constructor
        ################################################################################

        def __init__( self, parent, width, height ):
                fMain = ROOT.TGMainFrame.__init__( self, parent, width, height )

		self.width = width
		self.height = height

		global UDP_IP
                UDP_IP = "192.168.1.10"
                global UDP_PORT
                UDP_PORT = 10000
		
		TOP_FRAME_GRAPH.TopFrameGraphEx(self)

		# Graphics of the READ tab

		READ_GRAPH.ReadGraphEx(self)
		
		# Graphics of the WRITE tab
		
		WRITE_GRAPH.WriteGraphEx(self)

		# Graphics of the SPI tab
		
		SPI_GRAPH.SpiGraphEx(self)

		# Graphics of the ADC tab

		ADC_GRAPH.ADCGraphEx(self)

		TOP_FRAME_GRAPH.GuiAttributesEx(self)
	

	###################################################################################################
        ##   CloseWindows() override   #####################################################################
        ####################################################################################################


        def CloseWindow(self) :

                        ROOT.gApplication.Terminate(0)
                        raise SystemExit
                        #exit()


        ########################################################################################################



	

	def my_Disconnect(self):

		self.sending = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
		self.sending.close()
                self.CONNECTButton.SetTextColor(1)
                print 'Disconnected'
 
	def my_Connect(self):

		SPI_FUNC.my_ConnectEx(self)

	def my_spiNumber_label(self):

		SPI_FUNC.my_spiNumber_labelEx(self)

	def manipolation(self,var):

		SPI_FUNC.manipolationEx(self,var)
	
	def my_spiNumber(self):

		 SPI_FUNC.my_spiNumberEx(self)

	def reset_Button(self):

		 SPI_FUNC.reset_ButtonEx(self)

	def send_spi(self):

		SPI_FUNC.send_spiEx(self)

	def received_spi(self):

		SPI_FUNC.received_spi_Ex(self)

	def my_received_spi(self):

		 SPI_FUNC.my_received_spiEx(self)
	
	def sniff(self):

		SPI_FUNC.sniffEx(self)

	def receivedfromfpga(self):

		 SPI_FUNC.receivedfromfpgaEx(self)

	def ReadADC(self):

		ADC_FUNC.ReadADC_Ex(self)

	def Read_HexToBin(self,messtras):

		messtrass = MESSAGES.Read_HexToBin_Ex(self,messtras)
		return messtrass

	def send_message(self,MESSAGE):
		
		MESSAGES.send_message_Ex(self,MESSAGE)

	def received_message(self):

		messtrass = MESSAGES.received_message_Ex(self)
		return messtrass

	def Read_GRC(self):

		READ_FUNC.Read_GRC_Ex(self)
		
	def Read_BinToDecimal(self,lits_list,first_bit,last_bit):
		
		decimal = MESSAGES.Read_BinToDecimal_Ex(self,lits_list,first_bit,last_bit)
		return decimal

	def Write_DecToBin(self,dec_number,num_of_bit):

		bin_number = WRITE_FUNC.Write_DecToBin_Ex(self,dec_number,num_of_bit)
		return bin_number 

	def Write_GCR(self):

		WRITE_FUNC.Write_GCR_Ex(self)

	def Bin_to_Message(self, bin_str):

		message =  MESSAGES.Bin_to_Message_Ex(self, bin_str)
		return message

if __name__ == '__main__':


	a = ROOT.gApplication
	window = my_Canvas( ROOT.gClient.GetRoot(), 900, 650 )
	a.Run()

