import serial
import time
import keyboard
from pynput import keyboard

# print("Start")
# port="COM4" #This will be different for various devices and on windows it will probably be a COM port.
# bluetooth=serial.Serial(port, 9600)#Start communications with the bluetooth unit
# print("Connected")
# bluetooth.flushInput() #This gives the bluetooth a little kick
# while True:
# 	if keyboard.read_key() == 'w':
# 		bluetooth.write(b'w')
# 		# time.sleep(0.1)
# 	if keyboard.read_key() == 'a':
# 		bluetooth.write(b'a')
# 		# time.sleep(0.1)
# 	if keyboard.read_key() == 's':
# 		bluetooth.write(b's')
# 		# time.sleep(0.1)
# 	if keyboard.read_key() == 'd':
# 		bluetooth.write(b'd')
# 		# time.sleep(0.1)
# 	if keyboard.read_key() == 'q':
# 		break
# bluetooth.close() #Otherwise the connection will remain open until a timeout which ties up the /dev/thingamabob
# print("Done")

print("Start")
port="COM4" #This will be different for various devices and on windows it will probably be a COM port.
bluetooth=serial.Serial(port, 9600)#Start communications with the bluetooth unit
print("Connected")
bluetooth.flushInput() #This gives the bluetooth a little kick

def on_press(key):
    try:
        if key.char == "w":
            bluetooth.write(b'w')
        elif key.char == "a":
            bluetooth.write(b'a')
        elif key.char == "s":
            bluetooth.write(b's')
        elif key.char == "d":
            bluetooth.write(b'd')
    except AttributeError:
        print('special key {0} pressed.'.format(key))

def on_release(key):
    bluetooth.write(b'q')
    if key == keyboard.Key.esc:
        # Stop listener
        return False

with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()

bluetooth.close()
print("Done")