from everywhereml.arduino import Sketch, Ino, H
import numpy as np
import cv2
import serial

sketch = Sketch(name="MyFirstSketch", folder="MyFirstSketch")
if sketch.compile(board="Arduino Uno").is_successful:
    print("Log", sketch.output)
    print("Sketch stats", sketch.stats)
else:
    print("ERROR", sketch.output)

sketch.upload(port='COM')

#######################################################

# Change the serial port name and baud rate as per your configuration
ser = serial.Serial('COM4', 9600) 

if ser.isOpen():
    ser.close()
ser.open()

print('1')
ser.write(b's')
while True:
    print('waiting for signal')
    if ser.isOpen():
        if ser.read() == b'\x01':
            # Start recording
            cap = cv2.VideoCapture(0)
            fourcc = cv2.VideoWriter_fourcc(*'XVID')
            out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))

            while(cap.isOpened()):
                ret, frame = cap.read()
                if ret==True:
                    out.write(frame)
                    if ser.read() == b'\x00':
                        # Stop recording
                        cap.release()
                        out.release()
                        cv2.destroyAllWindows()
                        print("All done")
                        break
                else:
                    break
        elif ser.read() == b'\x00':
            pass