
import hmac
import hashlib
import os
from os.path import exists
import string
import time
import ROOT
import sys,socket



MESSAGE1 = '\x01\x01\x00\x00\x4a\x00\x90\x00' # last bin: 1001 0000 0000 0000 0000 --> it writes on the 0 GCR and starts automode
MESSAGE2 = '\x01\x01\x00\x00\x4a\x09\x00\x00' # last bin: 1001 0000 0000 0000 0000 --> it reads on the GCR in automode
MESSAGE3 = '\x01\x01\x00\x00\x4a\x00\x10\x00' # last bin: 0001 0000 0000 0000 0000 --> it writes on the 0 GCR in normal mode
MESSAGE4 = '\x01\x01\x00\x00\x4a\x07\x00\x00' # last bin: 0111 0000 0000 0000 0000 --> it starts ADC
MESSAGE5 = '\x01\x01\x00\x00\x4a\x0f\x00\x00' # last bin: 1111 0000 0000 0000 0000 --> it makes and transmit a measurment of the ADC 

global UDP_IP
UDP_IP = "192.168.1.10"
global UDP_PORT
UDP_PORT = 10000




def Read_HexToBin_Ex(self,messtras):


        last_mess = [messtras[6],messtras[7]]

        last_mess = string.join(last_mess)

        last_mess = ''.join(last_mess.split())

        #print last_mess

        decimal = int(last_mess, 16)

        #print decimal

        i = 0

        vect = range(16)

        while i < 16:

                if decimal%2 == 0:

                        vect[15-i] = '0'
                else:

                        vect[15-i] = '1'

                decimal = decimal/2

                i = i + 1

        #print vect
	return vect

def send_message_Ex(self,MESSAGE):


                self.str_send = MESSAGE

        ## the board is connect? 

                try:
                        self.sending.sendto(self.str_send,(UDP_IP, UDP_PORT))

                except:
                        print "you must connect the board"

		
def received_message_Ex(self):

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
		

		#print messtras

		return messtras


def Read_BinToDecimal_Ex(self,bits_list,first_bit,last_bit):  # i bit si contano da dx verso sx, il primo bit e' 0, secondo e' 1 etc, la funzione ritorna il valore decimale dei bit selezionati


                number_of_bits  = last_bit - first_bit + 1
                #print number_of_bits

                usefull_bits = range(number_of_bits)

                i = 0

                while i < number_of_bits:

                        usefull_bits[i] = str(bits_list[len(bits_list)- 1 -last_bit + i])

			i = i + 1
		
		#print type ( usefull_bits)
               	#print usefull_bits
		
                usefull_bits = string.join(usefull_bits)

                usefull_bits  = ''.join(usefull_bits.split())

                #print usefull_bits

                decimal = int(usefull_bits, 2)

                #print decimal

		return decimal


def Bin_to_Message_Ex(self, bin_str):

                # trasform dex in hex


                decimal = int ( bin_str , 2 )
                print decimal

                b = decimal /16
                a1 = (decimal - (b*16))

                c = b / 16
                a2 = (b - (c*16))

                d = c / 16
                a3 = (c - (d*16))

                e = d / 16
                a4 = (d - (e*16))

                f = e / 16
                a5 = (e - (f*16))

                my_hex_number = [a1,a2,a3,a4,a5]

                ## convert log integer to integer

                hex_number = [int(x) for x in my_hex_number]

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
#               h=['0','1','0','1','0','0','0','0','1','0','2',str(hex_number[4]),str(hex_number[3]),str(hex_number[2]),str(hex_number[1]),str(hex_number[0])]

                # spi 
                h=['0','1','0','1','0','0','0','0','4','a','0',str(hex_number[4]),str(hex_number[3]),str(hex_number[2]),str(hex_number[1]),str(hex_number[0])]

                h1 = [h[0],h[1]]
                h2 = [h[2],h[3]]
                h3 = [h[4],h[5]]
                h4 = [h[6],h[7]]
                h5 = [h[8],h[9]]
                h6 = [h[10],h[11]]
                h7 = [h[12],h[13]]
                h8 = [h[14],h[15]]

                new_mess1 = string.join(h1)
                new_mess1 = ''.join(new_mess1.split())
                new_mess2 = string.join(h2)
                new_mess2 = ''.join(new_mess2.split())
                new_mess3 = string.join(h3)
                new_mess3 = ''.join(new_mess3.split())
                new_mess4 = string.join(h4)
                new_mess4 = ''.join(new_mess4.split())
                new_mess5 = string.join(h5)
                new_mess5 = ''.join(new_mess5.split())
                new_mess6 = string.join(h6)
                new_mess6 = ''.join(new_mess6.split())
                new_mess7 = string.join(h7)
                new_mess7 = ''.join(new_mess7.split())
                new_mess8 = string.join(h8)
                new_mess8 = ''.join(new_mess8.split())
                new_str = "\ x"

                newstr1 = "".join((new_str, new_mess1))
                newstr2 = "".join((new_str, new_mess2))
                newstr3 = "".join((new_str, new_mess3))
                newstr4 = "".join((new_str, new_mess4))
                newstr5 = "".join((new_str, new_mess5))
                newstr6 = "".join((new_str, new_mess6))
                newstr7 = "".join((new_str, new_mess7))
                newstr8 = "".join((new_str, new_mess8))

                my_newstr = [new_mess1,new_mess2,new_mess3,new_mess4,new_mess5,new_mess6,new_mess7,new_mess8]

                newstr = string.join(my_newstr)
                newstr = ''.join(newstr.split())


                print newstr

                mess_to_send = newstr.decode('hex')

                return mess_to_send

