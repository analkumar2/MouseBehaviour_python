1. main.ino gets uploaded to arduino.
2. camera starts
3. as soon as we press 's' on the keyboard, the signal goes to arduino and it starts the main function there.
4. Arduino sends signal to laptop to start recording.
5. After each trial, a signal from arduino goes to laptop that asks the python script to stop recording and save. 
6. When all the trials end, it prints on terminal 'All done'

Currently only works for windows. FOr linux we just need to install the camera and give proper arduino port name
Also does not take any keyboard input as of now. But that should also be fairly easy to implement.