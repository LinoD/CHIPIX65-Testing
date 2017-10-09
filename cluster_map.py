import sys

import ROOT 

from ROOT import TCanvas
from ROOT import TF1
from ROOT import TMath

fileName = sys.argv[1]

f = open(fileName, "rb")


l = f.read()

nChar = len(l)

fileName_noisy = sys.argv[2]
noisy_pixels = []
count_noisy = 0

total_events = 0
event_counter = 0
packetNumber = 0
eventBytes = 0
kCode = 0
counter = 0
cluster = 0
number_of_hits = 0
cluster_signal = 0
cluster_pixels = 0
cluster_size = 0
noisy_hit = 0
total_ToT = 0

for line in open(fileName_noisy, "r").readlines():
	print line
	noisy_pixels.append(line.rstrip('\n')) 
	count_noisy += 1

print "Noisy pixels",noisy_pixels[0:count_noisy]

histo_pixel = ROOT.TH2F("histo_pixel","histo_pixel",64,-0.5,63.5,64,-0.5,63.5)
#cvs2 = TCanvas("Hits per pixel","Hits per pixel")

x = int(raw_input("Minimum number of pixels in the cluster "))
print "The number is ", x

y = int(raw_input("Maximum number of pixels in the cluster "))
print "The number is ", y

w = int(raw_input("Minimum size of ToT in the cluster "))
print "The number is ", w

z = int(raw_input("Maximum size of ToT in the cluster (cannot be less than 7) "))
print "The number is ", z


for i in range(0, len(l))  :

	a = int(l[i].encode("hex"), 16)

	
	if(a == 220 and (event_counter == 0 or event_counter == 23 + 15*cluster) and noisy_hit ==0 and (cluster_size >= x and cluster_size <= y) and (total_ToT >= w and total_ToT <= z)):
		raw_input("Press Enter to continue...")

	#print "Continua" 

	if (event_counter == 0 or event_counter == 23 + 15*cluster):
		if a == 220:
			event_counter = 0
			print("\n")
			print "NEW CLUSTER"
			#print "%s \t %d" % ("Event number",total_events)
			total_events += 1
			event_counter = 0
			packetNumber = 0
			eventBytes = 0
			kCode = 0
			counter = 0
			bin = None
			bin_prev = None
			bin_64bit = None
			if(total_events > 1):
				noisy_hit = 0
			cluster_signal = 0
			cluster_pixels = 0
			cluster = 0
			cluster_size = 0
			total_ToT = 0
			histo_pixel.Reset()

		else:
			counter = 8	
			kCode = 0		
			cluster += 1
			total_events += 1
			bin = None
			bin_prev = None
			bin_64bit = None
			#print "%s \t %s" % ("Bin_prev",bin_prev)  


	#print "%s \t %d" % ("Event counter",event_counter)
	#print "%s \t %d" % ("Cluster",cluster)
	#print "%s \t %d" % ("counter",counter)

	if (counter >= 2 and counter <=5):                                 #Packet number is in the header
		packetNumber+=256**(5-event_counter)*int(l[i].encode("hex"), 16)
		#print "%s \t %d" % ("Packet number",packetNumber)

	if (counter == 6 or counter == 7):				       #EventBytes is in the header
		eventBytes = 256**(7-event_counter)*int(l[i].encode("hex"), 16)
		#if event_counter == 7:
			#print "%s \t %d" % ("Event bytes",eventBytes)
	
	if (counter >= 8 and counter <=10):
		kCode+=int(l[i].encode("hex"), 16)
		#print "%s \t %d" % ("kCode",kCode)

	if (kCode == 123):
		if (counter != 13 and counter != 16 and counter != 19 and counter != 22):
			bin = format(int(l[i].encode("hex"), 16),'08b')
			if(counter == 11):
				bin_prev = bin
				#print "%s \t %s" % ("Bin",bin)  
				#print "%s \t %s" % ("Bin_prev",bin_prev)  
			if(counter > 11):
				bin_64bit = ''.join(map(str, [str(bin),str(bin_prev)]))
				#bin_64bit = ''.join(map(bin, [bin(bin),bin(bin_prev)]))
				#print "%s \t %s" % ("Bin",bin)  
				#print "%s \t %s" % ("Bin_64bit",bin_64bit)  
				bin_prev = bin_64bit
			if(counter == 21):
				macrocolumn = int(bin_64bit[0:4],2)
				#print "%s \t %s" % ("MacroColumn",macrocolumn) 
				timestamp = bin_64bit[4:14]
				print "%s \t %s" % ("TimeStamp",timestamp) 
				macrorow = int(bin_64bit[14:18],2)
				#print "%s \t %s" % ("MacroRow",macrorow) 
				pixelmap = bin_64bit[18:34]
				#print "%s \t %s" % ("PixelMap",pixelmap) 
				pixel_colpito = []
				count_pix_colpito = 0
				for k in range(0,16):
					#print pixelmap[k]
					if(int(pixelmap[k],2) == 1):
						pixel_colpito.append(15-k)
						count_pix_colpito += 1
						number_of_hits +=1
						#print "%s \t %i" % ("Count_pix_colpito",count_pix_colpito)
				print "Indirizzo pixel colpiti",pixel_colpito[0:count_pix_colpito+1]
				#print "%s \t %i" % ("Count_pix_colpito",count_pix_colpito)
				num_hit_pixels = []
				pix_num = []
				column = []
				row = []
				ToT = []

				for m in range(0,count_pix_colpito):
					row_region = pixel_colpito[m]%4
					column_region = int(pixel_colpito[m]/4)
					pix_num.append(256*macrocolumn + 4*macrorow + 64*column_region + row_region)
					row.append(4*macrorow + row_region)
					column.append(4*macrocolumn + column_region)
					#print "%s \t %i \t %s \t %i" % ("macrocolumn",macrocolumn,"column_region",column_region)
					noisy_hit = 0
					cluster_size += 1	
				
				#print "Pixel colpiti",pix_num[0:count_pix_colpito+1]
				ToT_6 = int(bin_64bit[34:39],2)
				ToT.append(ToT_6+1)
				
				#print "%s \t %s" % ("ToT_6",ToT_6) 
				ToT_5 = int(bin_64bit[39:44],2)
				ToT.append(ToT_5+1)
			
				#print "%s \t %s" % ("ToT_5",ToT_5)
				ToT_4 = int(bin_64bit[44:49],2)
				ToT.append(ToT_4+1)
				
				#print "%s \t %s" % ("ToT_4",ToT_4)
				ToT_3 = int(bin_64bit[49:54],2)
				ToT.append(ToT_3+1)
				
				#print "%s \t %s" % ("ToT_3",ToT_3)
				ToT_2 = int(bin_64bit[54:59],2)
				ToT.append(ToT_2+1)
				
				#print "%s \t %s" % ("ToT_2",ToT_2)
				ToT_1 = int(bin_64bit[59:64],2)		
				ToT.append(ToT_1+1)	

				if(count_pix_colpito > 6):
					for f in range (6,count_pix_colpito):
						ToT.append(33)
					
				total_ToT = total_ToT + ToT_6 + ToT_5 + ToT_4 + ToT_3 + ToT_2 + ToT_1

				print "ToT",ToT[::-1]  #Prints the list in reverse order, which corresponds to the pixel hit
				#print total_ToT
				print "Cluster size", cluster_size

				for g in range(0,count_noisy):
					if(pix_num[0] == int(noisy_pixels[g])):
						noisy_hit = 1 
				#print "%s \t %s" % ("ToT_1",ToT_1)
				#region_signal = ToT_6+ToT_5+ToT_4+ToT_3+ToT_2+ToT_1
				#cluster_signal += region_signal
				#cluster_pixels += count_pix_colpito
				#print "Column",column[0:count_pix_colpito+1]
				#print "row",row[0:count_pix_colpito+1]
				#print "ToT",ToT[0:6]
				#print x
				#print y
				#print "%s \t %i \t %s \t %i \t %s \t %i" % ("column",column[0:count_pix_colpito],"row",row,"pixel",pix_num[count_pix_colpito-1])
				if(noisy_hit == 0):				
					for m in range(0,count_pix_colpito):
						histo_pixel.Fill(column[m],row[m],ToT[count_pix_colpito-1-m])
						#print "%s \t %i \t %s \t %i \t %s \t %i" % ("column",column[m],"row",row[m],"pixel",ToT[count_pix_colpito-1-m])
					if((cluster_size >= x and cluster_size <= y) and (total_ToT >= w and total_ToT <= z)):
						histo_pixel.SetMinimum(0.5)	
						histo_pixel.SetMaximum(33.5)
						histo_pixel.SetNdivisions(33,"Z")
						histo_pixel.Draw("COLZ")	
						ROOT.gStyle.SetOptStat(0)
						#print "%s \t %i \t %i \t %i \t %i" % ("Cluster pixels",packetNumber,event_counter,cluster_pixels,count_pix_colpito)
						#print "%s \t %s" % ("Cluster charge",region_signal)
					#else:
						#print "Cluster size and/or ToT out of desired range"
				#if (noisy_hit ==1):
					#print "Noisy pixel"
				

	event_counter += 1
	counter += 1

