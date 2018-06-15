# Grafitti-Bot-2.0
# Abstract: 
Graffiti bot 2.0 is a fully automated bot capable of creating given designs(upto
dimensions 90cmx90cm) on wall or on any vertical surface. It works by spraying tiny
dots(analogous to pixels in a digital picture) at the right locations to create a whole picture.
# Acknowledgement: 
We would like to express our special thanks to Shivam Srivastava
sir , Gautham Sriram Sir , Sushant Samuel Sir , Bhaskar sir for guiding us through the journey.
# Motivation: 
It takes a lot of time,human effort and money to create graffitis on wall. Even
finding the right skilled person is difficult. If a human creates graffiti, we have limited choices.
Solving this problem is the real motivation behind creating this bot. With this bot, we can
choose any design from web or give it a picture clicked from smartphone. It is fully
automated,means there is no need to watch it. Just give it a picture and leave it.
# Hardware: 
The frame of the bot is shown below

![design](https://user-images.githubusercontent.com/27297472/41453027-de953736-7091-11e8-8647-68c7ccd4eaa1.png)

![design2](https://user-images.githubusercontent.com/27297472/41453125-281275e0-7092-11e8-9848-4180ad67ff64.png)


## Mechanical components used are-
1) Plywood with a square cut inside it.
2) 4 Steel rods(diameter-8mm, length-1m) + end clamps

![steelrods](https://user-images.githubusercontent.com/27297472/41453178-4fdcb09a-7092-11e8-9a50-cfa1f599890a.png)

3) Bevel gears

![bevelgears](https://user-images.githubusercontent.com/27297472/41453187-5c248fda-7092-11e8-8595-d36057b8cc00.png)

4)Timing belt(length-6m)+6 gears

![timingbelt](https://user-images.githubusercontent.com/27297472/41453791-aba86246-7094-11e8-944e-80390099e1b0.png)

5) 4 Linear bearings(8mm wide, compatible with the steel rods)

![linearbearings](https://user-images.githubusercontent.com/27297472/41482411-2b5eab68-70f3-11e8-8323-8a60b81fe6c1.png)

6) Spray-gun

![spraygun](https://user-images.githubusercontent.com/27297472/41482458-5190dd1a-70f3-11e8-8429-fb1ceae4f7b2.png)

7) Compressor with pressure regulator( The one at MARS)
Electronics components used are-
1) Arduino Mega

![arduinomega](https://user-images.githubusercontent.com/27297472/41482491-69776656-70f3-11e8-8122-d65bcba77733.png)

2) Raspberry pi 3

![raspberrypi](https://user-images.githubusercontent.com/27297472/41482596-b242fd78-70f3-11e8-9a23-27cc52552d91.png)

3) 2 Rotary Encoders

![rotaryencoder](https://user-images.githubusercontent.com/27297472/41482628-d2df98f2-70f3-11e8-8396-eca467a45bf1.png)

4) 2 high torque dc motors(12 volt)

![dcmotor](https://user-images.githubusercontent.com/27297472/41482647-e2f24f14-70f3-11e8-94ff-903275ec128a.png)

5) Motor driver(LN298N) to run the two dc motors

![motordriver](https://user-images.githubusercontent.com/27297472/41482671-efd2466c-70f3-11e8-928a-bd8cfc823864.png)

6) 1 servo motor( and a 7806 voltage regulator IC for driving the servo)

![servomotor](https://user-images.githubusercontent.com/27297472/41482716-175ab476-70f4-11e8-82ab-ec696e16982c.png)

7) 1 power bank to supply raspberry pi.(Arduino was powered from the pi).

8) 12 volt, 5 A power adapter to supply all the motors.
# Software:
1) <b>Arduino software</b> - The movement of both the dc motors and the servo motor is
controlled by the arduino code with the help of the feedback from the rotary
encoders.
2) <b>Python</b> - The image/design to be drawn is processed in python.Image processing
includes compressing the image, converting into binary image with proper threshold
and then finding the coordinates of the dark pixels and sending it to the arduino.
3) <b>Raspberry pi</b> - It is used as the main computer in the bot. Image processing is done
in pi but before this, one has to install python in it. Moreover, pi is uploading different
codes into the arduino along with powering it. Moreover pi also provides the flexibility
to change the code or to give a new picture from our laptop wirelessly. In short, we
can select a new design as well as change the code(if needed) from our laptop from
a distance.
# Working: 
This bot comprises a spray gun which contains paint. This spray-gun is
connected to a air compressor which provides necessary pressure for spraying paint. The
spray-gun has a button which when pressed,sprays paint on the wall. The spray-gun is
mounted on a platform which (with the help of linear bearings,timing belts and gears) can
cover all the coordinates(x,y) on the wall. The two dc motors and rotary encoders are
responsible for taking the spray-gun platform to the required coordinates.
First of all, the given image is processed by raspberry pi with the help of ‘image-processing’
code in python. Image processing includes compressing the image,converting into binary
image with proper threshold and then finding the coordinates of the dark pixels. Pi now
sends the coordinates(x,y) to the arduino. Now the arduino signals the motor driver to drive
both the dc motors until the required coordinates(x,y) is not achieved.
As the spray gun moves, the arduino continuously checks the coordinates through the two
rotary encoders which also rotates along with the motors. After reaching the required
location, the arduino signals the servo motor to push the button on the spray gun. This
sprays a tiny dot and then the pi sends the coordinates of the next dark pixel to the arduino
and the process is repeated until all coordinates are covered.
# Current Problems and Future Improvements:
1)Currently, this bot can create a whole graffiti in a single color only. It would be better if
many colors are involved.

2)Drawing speed is slow. It takes about 2 hours to create a single graffiti.It would be better if
the time could be minimised.

3)Graffiti resolution is low. The bot currently draws a 120x120 pixels graffiti and still takes
2-3 hours to make it. It is not that it can’t draw higher resolutions graffiti now; it can; but then
the time taken will be too much(~10 to 12 hours or more depending upon resolution). Low
resolution graffiti appears fine from large distance but not so much from close. The size of
spray gun nozzle can be changed to change the size of a single pixel.

4)For increasing the speed, two things must be done

  a) Instead of spraying discrete dots even to make a straight line, it should spray
     continuously. For this further improvement in image processing code is required.

  b) Higher speed motor for y-direction is needed which should also have sufficient
     torque.

5)Currently, we are using oil paint. It creates certain problems

  a) The paint drys after some time and blocks the nozzle of the spray gun. Then it has to be
     cleaned physically.

  b) As we are using turpentine oil to dilute the paint, the mixture dries over time and
     creates different shades in a single painting. This problem is small but noticeable.

# Team Members:
[Pradhyuman Mathur](https://www.facebook.com/pradhyuman.mathur)

[Anil Kumar Surisetty](https://www.facebook.com/anilkumar.surisetty.99?ref=br_rs)

[Yash Jha](https://www.facebook.com/profile.php?id=100007398224649&ref=br_rs)

[Saurabh Sonker](https://www.facebook.com/sourabh.sonker.908?ref=br_rs)

[Swapnil Thigale](https://www.facebook.com/swapnil.thigale.657?ref=br_rs)

[Vikasdeep Singh](https://www.facebook.com/vikasdeep.singh.90?ref=br_rs)

[Ashish Verma](https://www.facebook.com/profile.php?id=100011799060769)

[Pratik Rode](https://www.facebook.com/pratik.rode.31?ref=br_rs)

# Mentors: 
[Dhruv Gamdha](https://www.facebook.com/dhruv.gamdha?ref=br_rs), [Sushant Samuel Sir](https://www.facebook.com/sushant.samuel.3?ref=br_rs) , [Gautham Sriram Sir](https://www.facebook.com/gauthams1?ref=br_rs) , [Pankaj Singh](https://www.facebook.com/pankajmindfreak?ref=br_rs)
# Special Credits: 
Entire Mechanical Team(Swapnil, Saurabh,Yash,Vikasdeep)

[Sunil Saini](https://www.facebook.com/thesunilsaini?ref=br_rs)

[Prashant Kumar](https://www.facebook.com/profile.php?id=100011588744611&ref=br_rs)

[Aman Singh](https://www.facebook.com/amanHomecoming?ref=br_rs)
# Video: 
https://photos.app.goo.gl/A7auj8XTkAY1Xj749
https://photos.app.goo.gl/zs8fSWbSq7UiyRTx7
# Thank You!!!
