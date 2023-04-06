# Running an Image


## Starting the System

After the image is burnt and the development board is restarted, the system automatically starts. If the following page is displayed on the screen of the development board, the system is running properly.

**Figure 1** System startup effect 

![quickstart-pkg-3568-running-restart](figures/quickstart-pkg-3568-running-restart.png)


## Running a Hello World Program

1. When the system is running, start the serial port tool (for example, PuTTY), set the baud rate to **1500000**, and connect to the device.
  
   ![rk3568-run-configuration](figures/rk3568-run-configuration.png)

2. Enable the serial port, enter the **helloworld** command in any directory (for example, the root directory of the device) and press **Enter**. If the message "Hello World!" is displayed, the program runs successfully.
   
   ![helloworld](figures/helloworld.png)
