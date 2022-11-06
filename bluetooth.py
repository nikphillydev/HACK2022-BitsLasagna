import serial
import time
import keyboard
from pynput import keyboard


print("Start")
port="COM4" 
bluetooth=serial.Serial(port, 9600) #connect to BT
print("Connected")
bluetooth.flushInput() 

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
        elif key.char == "q":
            bluetooth.write(b'q')
        elif key.char == "e":
            bluetooth.write(b'e')
    except AttributeError:
        print('special key {0} pressed.'.format(key))

def on_release(key):
    bluetooth.write(b'z')
    if key == keyboard.Key.esc:
        # Stop listener
        return False

with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()

bluetooth.close()
print("Done")