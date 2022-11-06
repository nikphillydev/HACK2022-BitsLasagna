import serial
import time

print("Start")
port="COM4" #This will be different for various devices and on windows it will probably be a COM port.
bluetooth=serial.Serial(port, 9600)#Start communications with the bluetooth unit
print("Connected")
bluetooth.flushInput() #This gives the bluetooth a little kick
control = input()
while control != 'q':
	if control == 'w':
		bluetooth.write(b'w')
	if control == 'a':
		bluetooth.write(b'a')
	if control == 's':
		bluetooth.write(b's')
	if control == 'd':
		bluetooth.write(b'd')
	control = input()
bluetooth.close() #Otherwise the connection will remain open until a timeout which ties up the /dev/thingamabob
print("Done")
