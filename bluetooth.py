import serial
import time
import keyboard

print("Start")
port="COM4" #This will be different for various devices and on windows it will probably be a COM port.
bluetooth=serial.Serial(port, 9600)#Start communications with the bluetooth unit
print("Connected")
bluetooth.flushInput() #This gives the bluetooth a little kick
control = input()
while True:
	if keyboard.read_key() == 'w':
		bluetooth.write(b'w')
	if keyboard.read_key() == 'a':
		bluetooth.write(b'a')
	if keyboard.read_key() == 's':
		bluetooth.write(b's')
	if keyboard.read_key() == 'd':
		bluetooth.write(b'd')
	if keyboard.read_key() == 'q':
		break
bluetooth.close() #Otherwise the connection will remain open until a timeout which ties up the /dev/thingamabob
print("Done")
