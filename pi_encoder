import RPi.GPIO as GPIO 
GPIO.setmode(GPIO.BCM) 

enc_A = 15
enc_B = 17

counter=0

GPIO.setup(enc_A, GPIO.IN)
GPIO.setup(enc_B, GPIO.IN,pull_up_down = GPIO.PUD_DOWN)

def risingA(a):
    global counter
    if GPIO.input(enc_B)== 1:
        counter=counter+1
    else:
        counter=counter-1
    print "A:"+str(counter)

def risingB(b):
    global counter
    if GPIO.input(enc_A)== 0:
        counter=counter-1
    else:
        counter=counter+1    
    print "B:"+str(counter)

GPIO.add_event_detect(enc_A, GPIO.RISING, callback=risingA)
GPIO.add_event_detect(enc_B, GPIO.RISING, callback=risingB)

oldCounter = -999

while True :
    if counter != oldCounter :
        print counter
        oldCounter = counter
