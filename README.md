# ECE480-Team2-Robot

This is a project for MSU ECE 480 Capstone class. This contains the information needed to run this on a raspberry pi.

## ObjectDetection

This portion includes four modules. Here are their basic functions:

### SystemMain.py
- Handle the PiCamera and main loop
- Sends frame to object detection
- Can be run in debug mode, slows down inputs. To do so change the debug variable to 1 on line 33.

### ObjectDetection.py
- Takes in an image and processes it
- Deal with image thresholding and contour finding
- Fits ellipse to contours to objectify their size
- Returns a list of found contours

### ObjectTracking.py
- Takes contour information
- Removes duplicate contours, keeping the largest
- Finds type of utensil that is in the middle of the frame
- Queues up a signal to the servo using threads
- The thread allows us to call time.sleep() without putting the main code thread to sleep

### ServoController.py
- Allows control of the servo using RaspberryPi's gpiozero module
- Sets the desired tray location, as well as has an optional delay
- This delay is used to make this queue functionality work
- This sets the tray to the center at start, for calibrating purposes

To begin to run it on this specific pi you must first activate the OpenCV python environment.
To do this run the following commands on the terminal from the home directory:

\$ source OpenCV-master-pi3/bin/activate
\$ cd SilverwareDetection/
\$ python3 SystemMain.py

Also it is worth noting you can configure the pi to use SSH, along with Putty, XLaunch, and WinSCP. This may be
easier than using built in editors and the monitor to code on.

If you want to run this on your own pi all you need is a PiCamera, pi (preferably 4), and a few pip installs

\$ pip install numpy
\$ pip install opencv-python

You can also run just ObjectDetection.py on any system, as long as both numpy and opencv-python are installed

(There is a chance I'm missing some needed PIPs, it's been a while since I configured the pi, sorry)

## ArduinoCode

The Arduino code allows the speed of the conveyor belt to be controlled.

The conveyor belt system needs improvment. It still sticks after rebuilding it.

## Links
[YouTube Playlist](https://www.youtube.com/playlist?list=PLnDNTc2u1OkN70uiq_mDI1dUAa3VBpEik)



