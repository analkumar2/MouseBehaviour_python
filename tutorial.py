import pyfirmata
import time
board=pyfirmata.Arduino('COM4')
it=pyfirmata.util.Iterator(board)
it.start()
x=board.get_pin('d:13:o')
while True:
    x.write(1)
    time.sleep(1)
    x.write(0)
    time.sleep(1)