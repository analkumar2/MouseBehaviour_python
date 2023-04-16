from everywhereml.arduino import Sketch, Ino, H
import numpy as np
import cv2
import serial

sketch = Sketch(name="oddball", folder="oddball") # defining our folder where the ino script is stored
if sketch.compile(board="Arduino Uno").is_successful: #Compiling the ino code for arduino uno
    print("Log", sketch.output)
    print("Sketch stats", sketch.stats)
else:
    print("ERROR", sketch.output)

sketch.upload(port='COM') # uploading the sketch to arduino

#######################################################

# Change the serial port name and baud rate as per your configuration
ser = serial.Serial('COM4', 9600)  #Define which port the arduino is connected to. Also specify baud rate. baud rate should be the same as in the ino

if ser.isOpen():
    ser.close()
ser.open() #Open serial communication

data = 0
internalswitch = 0
outputnum = iter(np.arange(0,10,1)) #Trial number. Iter so that new files can be created with proper numbering
while True:
    print('waiting for signal')
    print(data,internalswitch)
    if ser.isOpen(): #read the serial port
        data = ser.readline().decode().strip() #read the serial port and store into data
        print(f'rawdata = {data}')
        data = int(data) #convert data into integer
    if data == 1 and internalswitch == 0: #If arduino asks to start recording but camera was not recording
        print('starting recording')
        internalswitch = 1 #keeps track of whether the recording is going on or not
        cap = cv2.VideoCapture(0)
        fourcc = cv2.VideoWriter_fourcc(*'XVID')
        try:
            out = cv2.VideoWriter(f'OutputV/output_{next(outputnum)}.avi',fourcc, 20.0, (640,480))
        except StopIteration: #If number of trials are exceeded, we close the loop
            cap.release()
            out.release()
            cv2.destroyAllWindows()
            print('All done')
            break
    if internalswitch == 1: #If camera is supposed to record
        print('continuing recording')
        ret, frame = cap.read()
        if ret==True:
            out.write(frame)

    if data == 0 and internalswitch == 1: #If arduino asks to stop recording but camera was recording
        internalswitch = 0 
        cap.release()
        out.release()
        cv2.destroyAllWindows()
        print('video saved')