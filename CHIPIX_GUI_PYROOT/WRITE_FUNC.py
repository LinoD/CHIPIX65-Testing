import ROOT, sys, socket, string, MESSAGES, time


def Write_DecToBin_Ex(self,dec_number,num_of_bit):	# give the decimal number and the number maximum of bits that you need 

        number_bin =  range(num_of_bit)

        i = 0

        while i < num_of_bit :

                if dec_number%2 == 0:

                        number_bin[num_of_bit - 1 - i ] = '0'

                else:

                        number_bin[num_of_bit - 1 - i ] = '1'
		
		dec_number = dec_number/2
                i = i + 1

	print number_bin
        return number_bin







def Write_GCR_Ex(self):

	t = 0.0004

	GCR_DATA = []
	
	
	### Comp_Thr  ###

        w = int(self.Comp_Thr_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,5))


        ### ICharge  ###

        w = int(self.ICharge_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,6))


	### IDischarge  ###

        w = int(self.IDischarge_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,6))


	### ITrans_gain  ###

        w = int(self.ITrans_gain_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,4))


	### Op_mode  ###

        w = int(self.Op_mode_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,1))
	
	 ### CALL_LEVEL  ###

        w = int(self.CALL_LEVEL_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


 	### IPA_In_Bias  ###
	
        w = int(self.IPA_In_Bias_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### IFC_Bias  ###

        w = int(self.IFC_Bias_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### IKrum  ###

        w = int(self.IKrum_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### VRef_Krum  ###

        w = int(self.VRef_Krum1_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### IGDac  ###

        w = int(self.IGDac_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### ILDac  ###

        w = int(self.ILDac_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### Mon_Mux  ###

        w = int(self.Mon_Mux_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,5))


	### BGR  ###

        w = int(self.BGR_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,5))



	### IRef  ###

        w = int(self.IRef_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,5))


	### IBias_Feed  ###

        w = int(self.IBias_Feed_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### VRef_Krum  ###

        w = int(self.VRef_Krum_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))



	### IBias_SF  ###

        w = int(self.IBias_SF_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### IBias_Disc  ###

        w = int(self.IBias_Disc_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### IBiasP2  ###

        w = int(self.IBiasP2_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


        ### IBiasP1  ###

        w = int(self.IBiasP1_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))



	
	### VBL_Disch  ###

        w = int(self.VBL_Disc_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))



	### Vth_Disch  ###

        w = int(self.Vth_Disc_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))



	### ICtrl_TOT ###

        w = int(self.ICtrl_TOT_WRITE.GetNumber())
        #print w
        GCR_DATA.extend(self.Write_DecToBin(w,10))


	### PHI_AZ_Low_Level ###

	w = int(self.PHI_AZ_Low_Level_WRITE.GetNumber())
        GCR_DATA.extend(self.Write_DecToBin(w,14))


	### PHI_AZ_High_Level ###
	
	w = int(self.PHI_AZ_High_Level_WRITE.GetNumber())
        GCR_DATA.extend(self.Write_DecToBin(w,8))
	

	### PHI_AZ_Delay ###

	w = int(self.PHI_AZ_Delay_WRITE.GetNumber())
	GCR_DATA.extend(self.Write_DecToBin(w,5))

	print GCR_DATA

	
	self.send_message(MESSAGES.MESSAGE2)
	time.sleep(t)
	self.received_message()
	
	i = 0

	while i < 14:

		b  = 0
	
		GCR_X_DATA = range(16)

		while b < 16 :

			GCR_X_DATA[15 - b] = GCR_DATA[len(GCR_DATA)-1-16*i-b]

			b = b + 1

		print GCR_X_DATA

		GCR_X_DATA.insert(0,'0001') # insert the SPI COMMAND: write on GCR

		#print GCR_X_DATA
	
        	GCR_X_DATA = string.join(GCR_X_DATA)

        	GCR_X_DATA = ''.join(GCR_X_DATA.split())

		print GCR_X_DATA

		MESSAGE_OUT = self.Bin_to_Message(GCR_X_DATA)
		
		time.sleep(t)
		self.send_message(MESSAGE_OUT)

		time.sleep(t)
        	self.received_message()
		
		i = i + 1
	print len(GCR_DATA)
