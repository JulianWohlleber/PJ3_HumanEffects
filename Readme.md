#PRJ3_HumanEffects

Since humen exist they affect on their environment. One of the resulting effects is that animal species like the Galapagos tortoise extinct.  
My flipdotwork faces this issue and breaks it down into two binary states; the moment you're sharing area with animals your taking impact on their daily behaviour. This is why progress for humen often means means regress for nature.   
In my flipdotwork I  equated this circumstance with a simple step forward - as the spectator steps forward and verges the object,  the tortose sitting in its recess in the box dies.

[link to Video](https://vimeo.com/123685335) 

##IDEA  
When I started to realize my project, my first idea was to use facedetection with the help of the simple cv library and the raspberry pi with a usb web-cam.  The goal was to make an task for the spectator which was impossible to solve: Face the text on the Flipdot and read it. At the moment, the spectator would look at the dot, the dot would flip. The spectator would realize there is something written on the dot, but each time he would try to face it, it would dissappear.  
Unfortunatly the facedetection of simple cv was to inaccurate: As the head was tilted, no face was detected anymore. Another Problem was, that the raspberry Pi was way too slow to interpret the pictures that came from the usb cam via simple cv. It wouldve been too easy to trick out the system, so the whole charm of my project would've been lost.  
Thats why I decided to look for new Hardware that would solve my Problem. As a simple but good solution i found the analog sharp IR distance sensor *Sharp GP2Y0A21*.  This sensor also enabled me, to use the arduino board for this project.

##REALISATION - Software
Because the distance sensor measures nothing but distance, I decided to place a recess in the box the hardware would be in. In this recess the flipdot would be located, so that the spectator needs to come closer to see the flipdot.   
At the beginning i tried to write the code completely on my own. But a Problem appeared: The distance sensor  gave out completely different values with analogRead() on each launch. So sometimes the values were accurate enough to detect an approach but often also not.   
That's were I want to give a special thanks to Phillip Pfingsttag, who gave me the DistanceGP2Y0A21YK-library as well as a nice and organised presentation and explanation of Sharp-Distance sensors and also a thanks to Fabian Morón Zirfas who arranged this meeting.  
The DistanceGP2Y0A21YK-library enabled my distance sensor not only to detect objects or persons but also to measure the distance between the object and the sensor itsself. That gave me even more possibilities. After some time of coding and testing, i decided, that 30 cm were the perfect distance for my project.  
 
**The final code looks like this:**

	// Sharp IR GP2Y0A21YK Distance Test

	#define sensor 0 // Sharp IR GP2Y0A21YK (10-80cm, analog)

	//dot position
	int read_on = 6;
	int read_off = 5;

	//minimal distance to flip
	int maxdistance = 30;

	boolean state = true;

	void setup() {
	Serial.begin(9600); // start the serial port
	}

	void loop() {
  
 	 // 5v - Read Sensor
  	float volts = analogRead(sensor)*0.0048828125;  // value from sensor * 	(5/1024)
  	int distance = 28*pow(volts, -1); // worked out from datasheet graph
  	//delay(100); // slow down serial port 
  
 
  
  	//flip dot position 1
  	if (distance <= maxdistance && distance > 0 && state == true){
    	digitalWrite(read_on, LOW);
    	digitalWrite(read_off, HIGH);
    	Serial.print("flop");
    	state = false;  
  	}
  
  	//flipdot position 2
  	if((distance > maxdistance || distance == 0) && state == false){
    	digitalWrite(read_on, HIGH);
    	digitalWrite(read_off, LOW);
    	Serial.print("flip");
    	state = true;
	}

	delay(20);
	digitalWrite(read_off, LOW);
	digitalWrite(read_off, LOW);
	Serial.println(distance);
	Serial.print(state);
	delay(200);
	}  
  
  
##REALISATION - Hardware
Until this point my project was a hardware-prototype: Everything was just connected barely on the breadboard of my teensy kit. Thats why I decided to solder everything to a plate to built a stable and by transportation unaffected circuit.   
For the wrapping i used a tee box, which was painted white and later grinded for a used look. I wanted my object to look like it was just washed ashore from the see.  
On the top of the box i drilled a huge whole where i recessed a brass pipe. On the bottom of the pipe the Flipdot should be located, so that the spectator should not see the inside of the box, but the Flipdot and its surrounding area.   
The Sharpsensor was recessed in the front of the box, so that it would recognize an approaching person.

##FINISH
The plan was to extend the flipdot area, so that a text could've been written next to the tortoise. 
Unfortunatly the Flipdot was to weak to flip an extension, why i was limited to the flipdot area.  
The Video was recorded in Sicily with the help of my Girlfrind Annette Münzenmaier. Then it was Cut with the help of Final Cut Pro, and uploaded to vimeo.



