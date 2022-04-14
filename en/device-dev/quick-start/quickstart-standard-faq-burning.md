# Fixing Burning Issues


## What should I do if Error: Opening COMxx: Access denied is displayed when I start burning

- **Symptom**

  Error: Opening COMxx: Access denied is displayed after clicking Burn and selecting a serial port.

    **Figure 1** Failed to open the serial port

    ![en-us_image_0000001271202461](figures/en-us_image_0000001271202461.png)

- **Possible Causes**

  The serial port is in use.

- **Solution**

1. Search for the terminal using serial-xx from the drop-down list in the **TERMINAL** panel.

     **Figure 2** Checking whether the serial port is in use

     ![en-us_image_0000001271202473](figures/en-us_image_0000001271202473.png)

2. Click the dustbin icon as shown below to disable the terminal using the serial port.

     **Figure 3** Disabling the terminal using the serial port

     ![en-us_image_0000001271202469](figures/en-us_image_0000001271202469.png)

3. Click **Burn**, select the serial port, and start burning images again.

     **Figure 4** Restarting the burning task

     ![en-us_image_0000001271562449](figures/en-us_image_0000001271562449.png)


## What should I do when Windows-based PC failed to be connected to the board?

- **Symptom**

  The file image cannot be obtained after clicking Burn and selecting a serial port.

    **Figure 5** Failed to obtain the file image due to network disconnection

    ![en-us_image_0000001226922306](figures/en-us_image_0000001226922306.png)

- **Possible Causes**

  The board is disconnected from the Windows-based PC.

  Windows Firewall does not allow Visual Studio Code to access the network.

- **Solution**

1. Check whether the network cable is properly connected.

2. Click **Windows Firewall**.

     **Figure 6** Network and firewall settings

     ![en-us_image_0000001226634732](figures/en-us_image_0000001226634732.png)

3. Click **Firewall & network protection**, and on the displayed page, click **Allow an app through the firewall**.

     **Figure 7** Firewall & network protection

     ![en-us_image_0000001271202457](figures/en-us_image_0000001271202457.png)

4. Select Visual Studio Code.

     **Figure 8** Selecting Visual Studio Code

     ![en-us_image_0000001271234765](figures/en-us_image_0000001271234765.png)

5. Select the **Private** and **Public** network access rights for Visual Studio Code.

     **Figure 9** Allowing Visual Studio Code to access the network

     ![en-us_image_0000001271474585](figures/en-us_image_0000001271474585.png)


## What should I do when the image failed to be burnt?

- **Symptom**

  The burning status is not displayed after clicking Burn and selecting a serial port.

- **Possible Causes**

  The IDE is not restarted after the DevEco plug-in is installed.

- **Solution**

  Restart the IDE.
