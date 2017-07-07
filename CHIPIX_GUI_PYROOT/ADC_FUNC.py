import ROOT

import hmac
import hashlib
import sys,socket
import os
from os.path import exists
import string
import time
import MESSAGES
def ReadADC_Ex(self):

	t= 0.0004

        self.send_message(MESSAGES.MESSAGE4)

	time.sleep(t)

        self.received_message()

	self.send_message(MESSAGES.MESSAGE5)

        time.sleep(t)

        measurment = self.received_message()
	
	measurment = self.Read_HexToBin(measurment)

	measurment = string.join(measurment)

        measurment = ''.join(measurment.split())


	ADCValue = int(measurment, 2)
	
	#print dec

	self.ReadADCValue.SetText(str(ADCValue))

