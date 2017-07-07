### List of the Functions #####

# SPI_FUNC.my_ConncetEx(self)

# SPI_FUNC.manipolationEx(self,var)

# SPI_FUNC.my_spiNumberEx(self)

# SPI_FUNC.reset_ButtonEx(self)

# SPI_FUNC.my_received_spiEx(self)

# SPI_FUNC.receivedfromfpgaEx(self)

# SPI_FUNC.sniffEx(self)

#others 





import ROOT        
import sys,socket
import os
from os.path import exists
import datetime
import string
import time

global UDP_IP
UDP_IP = "192.168.1.10"
global UDP_PORT
UDP_PORT = 10000


def my_ConnectEx(self):

                # create dgram udp socket send
                try:
                        self.sending = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
                        print 'Connection occurred for sending'
                except socket.error:
                        print 'Failed to create socket'
                        ROOT.TPython.Exec( "execfile( \'error_socket.py\')" )

                # create dgram udp socket reception
                try:
                        self.reception = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
                        self.reception.bind(("192.168.1.1", 10000))
                        self.CONNECTButton.SetTextColor(250)
                        print 'Connection occurred for reception'
                except socket.error:
                        print 'Failed to create socket'
                        ROOT.TPython.Exec( "execfile( \'error_socket.py\')" )





def manipolationEx(self,var):

                # trasform dex in hex

                self.keyboardnumber = var

                b = self.keyboardnumber /16
                a1 = (self.keyboardnumber - (b*16))

                c = b / 16
                a2 = (b - (c*16))

                d = c / 16
                a3 = (c - (d*16))

                e = d / 16
                a4 = (d - (e*16))

                f = e / 16
                a5 = (e - (f*16))

                self.my_hex_number = [a1,a2,a3,a4,a5]

                ## convert log integer to integer

                hex_number = [int(x) for x in self.my_hex_number]

                ## manipolation of the string 

                i = 0
                while i<5:
                        if hex_number[i]>9:
                                if hex_number[i] == 10:
                                        hex_number[i] = 'a'
                                elif hex_number[i] == 11:
                                        hex_number[i] = 'b'
                                elif hex_number[i] == 12:
                                        hex_number[i] = 'c'
                                elif hex_number[i] == 13:
                                        hex_number[i] = 'd'
                                elif hex_number[i] == 14:
                                        hex_number[i] = 'e'
                                elif hex_number[i] == 15:
                                        hex_number[i] = 'f'
                                elif hex_number[i]== 9:
                                        hex_number[i] = '9'
                                elif hex_number[i]== 8:
                                        hex_number[i] = '8'
                                elif hex_number[i]== 7:
                                        hex_number[i] = '7'
                                elif hex_number[i]== 6:
                                        hex_number[i] = '6'
                                elif hex_number[i]== 5:
                                        hex_number[i] = '5'
                                elif hex_number[i]== 4:
                                        hex_number[i] = '4'
                                elif hex_number[i]== 3:
                                        hex_number[i] = '3'
                                elif hex_number[i]== 2:
                                        hex_number[i] = '2'
                                elif hex_number[i]== 1:
                                        hex_number[i] = '1'
                                elif hex_number[i]== 0:
                                        hex_number[i] = '0'
                        i = i+1

                # create a key

                # test led on Arty board
#               self.h=['0','1','0','1','0','0','0','0','1','0','2',str(hex_number[4]),str(hex_number[3]),str(hex_number[2]),str(hex_number[1]),str(hex_number[0])]

                # spi 
                self.h=['0','1','0','1','0','0','0','0','4','a','0',str(hex_number[4]),str(hex_number[3]),str(hex_number[2]),str(hex_number[1]),str(hex_number[0])]

                self.h1 = [self.h[0],self.h[1]]
                self.h2 = [self.h[2],self.h[3]]
                self.h3 = [self.h[4],self.h[5]]
                self.h4 = [self.h[6],self.h[7]]
                self.h5 = [self.h[8],self.h[9]]
                self.h6 = [self.h[10],self.h[11]]
                self.h7 = [self.h[12],self.h[13]]
                self.h8 = [self.h[14],self.h[15]]

                self.new_mess1 = string.join(self.h1)
                self.new_mess1 = ''.join(self.new_mess1.split())
                self.new_mess2 = string.join(self.h2)
                self.new_mess2 = ''.join(self.new_mess2.split())
                self.new_mess3 = string.join(self.h3)
                self.new_mess3 = ''.join(self.new_mess3.split())
                self.new_mess4 = string.join(self.h4)
                self.new_mess4 = ''.join(self.new_mess4.split())
                self.new_mess5 = string.join(self.h5)
                self.new_mess5 = ''.join(self.new_mess5.split())
                self.new_mess6 = string.join(self.h6)
                self.new_mess6 = ''.join(self.new_mess6.split())
                self.new_mess7 = string.join(self.h7)
                self.new_mess7 = ''.join(self.new_mess7.split())
                self.new_mess8 = string.join(self.h8)
                self.new_mess8 = ''.join(self.new_mess8.split())
                self.new_str = "\ x"

                self.newstr1 = "".join((self.new_str, self.new_mess1))
                self.newstr2 = "".join((self.new_str, self.new_mess2))
                self.newstr3 = "".join((self.new_str, self.new_mess3))
                self.newstr4 = "".join((self.new_str, self.new_mess4))
                self.newstr5 = "".join((self.new_str, self.new_mess5))
                self.newstr6 = "".join((self.new_str, self.new_mess6))
                self.newstr7 = "".join((self.new_str, self.new_mess7))
                self.newstr8 = "".join((self.new_str, self.new_mess8))

                self.my_newstr_label = [self.newstr1,self.newstr2,self.newstr3,self.newstr4,self.newstr5,self.newstr6,self.newstr7,self.newstr8]
                self.my_newstr = [self.new_mess1,self.new_mess2,self.new_mess3,self.new_mess4,self.new_mess5,self.new_mess6,self.new_mess7,self.new_mess8]

                self.newstr = string.join(self.my_newstr)
                self.newstr = ''.join(self.newstr.split())

                self.mess_to_send = self.newstr.decode('hex')

                self.my_newstr_label_out = string.join(self.my_newstr_label)
                self.my_newstr_label_out = ''.join(self.my_newstr_label_out.split())

def send_spiEx(self):



                try:
                        # verify the existance of spi command                   
                        test_existence = self.mess_to_send[0]

                        try:
                                self.sending.sendto(self.mess_to_send,(UDP_IP, UDP_PORT))
                        except:
                                print "connect the board"
                                ROOT.TPython.Exec( "execfile( \'error_connection.py\')" )

                except:
                        print "create a string to send"
                     

def my_spiNumberEx(self):


                self.manipolation(self.spiNumber.GetNumberEntry().GetHexNumber())

                self.sent_mess = [self.h[11],self.new_mess7,self.new_mess8]

                print self.sent_mess

                self.sent_mess = string.join(self.sent_mess)

                self.label2.SetText(self.sent_mess)

                self.numberframe.Layout()

                try:
                        # verify the existance of spi command                   
                        test_existence = self.mess_to_send[0]

                        try:
                                self.sending.sendto(self.mess_to_send,(UDP_IP, UDP_PORT))
                        except:
                                print "connect the board"
                                ROOT.TPython.Exec( "execfile( \'error_connection.py\')" )

                except:
                        print "create a string to send"



############################################################################################
## Reset chipix bottons
############################################################################################

def sniffEx(self):

                # set read time out 
                self.reception.settimeout(0.5)

                # receive data from socket
                d = self.reception.recvfrom(64)
                x = d[0]

                return x



                      	#ROOT.TPython.Exec( "execfile( \'error_connection.py\')" )


##############################################################################################
####  received from chip
##############################################################################################

def receivedfromfpgaEx(self):

                messagewrite = []
                messtras = []

                #a = self.sniff()

		self.reception.settimeout(0.5)

                # receive data from socket
                d = self.reception.recvfrom(64)
                x = d[0]
	
		a = x
	
                i = 0

                while i < 8:
                        messagewrite.append(a[i])
                        messtras.append(messagewrite[i].encode("hex"))
                        i = i + 1

                # It displays the value return from the board

                self.messtras_print = string.join(messtras)
                self.label1.SetText("%s " % self.messtras_print)

                #self.textViewtras.AddLine("%s " % self.messtras_print)

                # Parent frame Layout() method will redraw the label showing the new value.

                #self.hexr.Layout()

                return self.messtras_print

def received_spi_Ex(self):

                self.messagewrite = []
                self.messtras = []

                # set read time out 
                self.reception.settimeout(0.5)

                # receive data from socket
                d = self.reception.recvfrom(64)
                x = d[0]
                a = x
                i = 0

                while i < 8:
                       	self.messagewrite.append(a[i])
                        self.messtras.append(self.messagewrite[i].encode("hex"))
                        i = i + 1
		#print self.messtras
		#print type (messtras)
                # It displays the value return from the board

                self.messtras_print = string.join(self.messtras)
		#print messtras_print
                self.messtras_print1 = self.messtras_print[16:]
		#print messtras

def my_received_spiEx(self):

                messagewrite = []
                messtras = []
	
		# set read time out 
                self.reception.settimeout(0.5)

                # receive data from socket
                d = self.reception.recvfrom(64)
                x = d[0]
		a = x
                i = 0

                while i < 8:
                        messagewrite.append(a[i])
                        messtras.append(messagewrite[i].encode("hex"))
                        i = i + 1

                # It displays the value return from the board
		print messtras
                print type (messtras)

                self.messtras_print = string.join(messtras)
                self.messtras_print1 = self.messtras_print[16:]
                self.label3.SetText("%s " % self.messtras_print1)

                # Parent frame Layout() method will redraw the label showing the new value.
		print self.messtras_print
	
                self.number2frame.Layout()
                return self.messtras_print1

def reset_ButtonEx(self):
                
		print "RESET the chip"

                MESSAGE = '\x01\x01\x00\x00\x41\x00\x00\x00' # reset board 
                self.str_reset = MESSAGE

        ## the board is connect? 

                
        	try:

			self.sending.sendto(self.str_reset,(UDP_IP, UDP_PORT))
                	self.receivedfromfpga()
                #return self.receive_test
                
		except:
                        print "you must connect the board"
 

###################################################################################################
##  Plot the calibration level 
###################################################################################################

def my_plotEx(self):

                self.my_Canvas.GetCanvas()#.cd(1)
                self.computation()

                global gr

                Npt = 1024

                gr = ROOT.TGraph(Npt)

                gr.Draw("AP") # if you write "ALP" draw a line from the first to last and go back
                gr.SetMarkerStyle(21)
                gr.SetMarkerSize(0.8)
                gr.SetTitle("Calibration Level;Valori del Cal_Lev(in scala decimale); ")

                for i in range(Npt) :
                        x = float(i)
                        y1 = self.y[i]
                        gr.SetPoint(i, x, y1)
                        ROOT.gPad.Modified()
                        ROOT.gPad.Update()


def my_fitEx(self):

                self.my_Canvas.GetCanvas().cd(1)
                gr.Fit("pol1","RV","",0, 600)
                f2 = ROOT.TF1("f2", gr.Fit, 0, 600, 2)
                f2.SetParNames("a","b");
                f2.SetNpx(10000)
                f2.SetLineStyle(1)
                f2.SetLineColor(1)
                f2.SetLineWidth(1)
                f2.Draw
                ROOT.gPad.Modified()
                ROOT.gPad.Update()


def my_plot2Ex(self):

#               self.my_Canvas.GetCanvas().cd(2)

                global gr2

                Npt = 1024

                gr2 = ROOT.TGraph(Npt)

                gr2.Draw("AP") # if you write "ALP" draw a line from the first to last and go back
                gr2.SetMarkerStyle(21)
                gr2.SetMarkerSize(0.8)


                for i in range(Npt) :
                        x = float(i)
                        y = ROOT.gRandom.Uniform(-0.5, 0.5)
                        gr2.SetPoint(i, x, y)
                        ROOT.gPad.Modified()
                        ROOT.gPad.Update()

        ##############################################################################
        ##### computation
        ##############################################################################

def computationEx(self):

                t = 0.0004
                ## set mux to read the 2 value
                ## all number is decimal here
                self.reset_Button()                     # reset all GCR, automatically the first of 7 GCR became 0
                time.sleep(t)
                # for reset you can't sniff the port because there is response
                self.manipolation(4104)         # write on 8 GCR 
                self.my_spiNumber()                     # send spi command
                self.my_received_spi()          # you must sniff response message to empty the queue
                time.sleep(t)
                self.manipolation(69633)        # bit setting 0001
                self.my_spiNumber()                     # send spi command
                self.my_received_spi()          # you must sniff response message to empty the queue
                time.sleep(t)
                ## send 1024 value
                self.y = []
                n = 1024                                        #  we use DAC(10bit) and ADC 12 bit a 40MHz (2^10=1024)
                self.manipolation(4108)         # 12 GCR
                self.my_spiNumber()                     # send spi command
                self.my_received_spi()          # you must sniff response message to empty the queue
                time.sleep(t)
                for i in range(n):                              # start 0 end 1023
                        z = 69632 + i
                        self.manipolation(z)            # set calibration level
                        self.my_spiNumber()                     # send spi command
                        time.sleep(t)
                        self.my_received_spi()          # you must sniff response message to empty the queue
                        time.sleep(t)
                        self.manipolation(458752)       # start ADC
                        self.my_spiNumber()                     # send spi command
                        time.sleep(t)
                        self.my_received_spi()          # you must sniff response message to empty the queue
                        time.sleep(t)  # sleep for time>0.001s,ADC use to convert possible maximum number 0.000256s
                        self.manipolation(983040)       # Read ADC
                        self.my_spiNumber()                     # send spi command      
                        y_tot = self.my_received_spi()  # sniff on board SPI response, command and payload                      
                        self.y.append(self.ADC10bitfound(y_tot))
                f1.write("0x%s " % self.y)
                f1.write("\n ")



	        ######################################################################################
        ## found ADC number and trasform on integer
        #####################################################################################
def ADC10bitfoundEx(self, hex_word):
                i = 0
                variable = [hex_word[0], hex_word[2], hex_word[3], hex_word[5], hex_word[6]]
                while i<5:
                        try:
                                variable[i] = int(variable[i])
                        except:
                                if variable[i] == 'a':
                                        variable[i] = int(10)
                                elif variable[i] == 'b':
                                        variable[i] = int(11)
                                elif variable[i] == 'c':
                                        variable[i] = int(12)
                                elif variable[i] == 'd':
                                        variable[i] = int(13)
                                elif variable[i] == 'e':
                                        variable[i] = int(14)
                                elif variable[i] == 'f':
                                        variable[i] = int(15)
                        i = i + 1
                print variable
                b = variable[4]+variable[3]*16+variable[2]*16*16
                return b


