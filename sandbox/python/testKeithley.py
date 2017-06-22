
import serial
import sys


if(len(sys.argv) == 2) :
	portName = sys.argv[1]
else :
	portName = "/dev/ttyUSB0"


s = serial.Serial()

s.port      = portName                 # target port for connection
s.baudrate  = 9600                     # Baud rate
s.bytesize  = serial.EIGHTBITS         # number of payload bits per byte
s.parity    = serial.PARITY_NONE       # enable/disable parity check
s.stopbits  = serial.STOPBITS_ONE      # number of stop bits
s.timeout   = None                     # timeout in seconds
s.xonoff    = False                    # enable/disable software flow control
s.rtscts    = False                    # enable/disable RTS/CTS hardware flow control
s.dsrdtr    = False                    # enable/disable DSR/DTR hardware flow control 


s.open()

cmd = '*RST'

s.write( cmd + '\r\n' )
