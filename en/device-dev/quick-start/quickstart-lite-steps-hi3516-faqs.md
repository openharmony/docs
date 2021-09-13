# FAQs<a name="EN-US_TOPIC_0000001128470856"></a>

-   [What should I do when the images failed to be burnt over the selected serial port?](#section627268185113)
-   [What should I do when Windows-based PC failed to be connected to the board?](#section195391036568)
-   [What should I do when the image failed to be burnt?](#section571164016565)
-   [What should I do when the message indicating Python cannot be found is displayed during compilation and building?](#section1039835245619)
-   [What should I do when no command output is displayed?](#section14871149155911)

## What should I do when the images failed to be burnt over the selected serial port?<a name="section627268185113"></a>

-   **Symptom**

    **Error: Opening COMxx: Access denied**  is displayed after clicking  **Burn**  and selecting a serial port.

    **Figure  1**  Failed to open the serial port<a name="fig1756105874814"></a>  
    ![](figure/failed-to-open-the-serial-port.png "failed-to-open-the-serial-port")

-   **Possible Causes**

    The serial port has been used.

-   **Solutions**

1.  Search for the terminal using serial-xx from the drop-down list in the  **TERMINAL**  panel.

    **Figure  2**  Checking whether the serial port is used<a name="fig723433664916"></a>  
    ![](figure/checking-whether-the-serial-port-is-used.png "checking-whether-the-serial-port-is-used")

2.  Click the dustbin icon as shown in the following figure to disable the terminal using the serial port.

    **Figure  3**  Disabling the terminal using the serial port<a name="fig197211713185012"></a>  
    ![](figure/disabling-the-terminal-using-the-serial-port.png "disabling-the-terminal-using-the-serial-port")

3.  Click  **Burn**, select the serial port, and start burning images again.

    **Figure  4**  Restarting burning<a name="fig2196042514"></a>  
    ![](figure/restarting-burning.png "restarting-burning")


## What should I do when Windows-based PC failed to be connected to the board?<a name="section195391036568"></a>

-   **Symptom**

    The file image cannot be obtained after clicking  **Burn**  and selecting a serial port.

    **Figure  5**  Failed to obtain the image file due to unavailable connection<a name="fig135261439195819"></a>  
    ![](figure/failed-to-obtain-the-image-file-due-to-unavailable-connection.png "failed-to-obtain-the-image-file-due-to-unavailable-connection")

-   **Possible Causes**

    The board is disconnected from the Windows-based PC.

    Windows Firewall does not allow Visual Studio Code to access the network.

-   **Solutions**

1.  Check whether the network cable is properly connected.
2.  Click  **Windows Firewall**.

    **Figure  6**  Network and firewall setting<a name="fig168416458311"></a>  
    ![](figure/network-and-firewall-setting.png "network-and-firewall-setting")

3.  Click  **Firewall & network protection**, and on the displayed page, click  **Allow applications to communicate through Windows Firewall**.

    **Figure  7**  Firewall and network protection<a name="fig19866154513414"></a>  
    ![](figure/firewall-and-network-protection.png "firewall-and-network-protection")

4.  Select the Visual Studio Code application.

    **Figure  8**  Selecting the Visual Studio Code application<a name="fig9213244657"></a>  
    ![](figure/selecting-the-visual-studio-code-application.png "selecting-the-visual-studio-code-application")

5.  Select the  **Private**  and  **Public**  network access rights for the Visual Studio Code application.

    **Figure  9**  Allowing the Visual Studio Code application to access the network<a name="fig019395421210"></a>  
    ![](figure/allowing-the-visual-studio-code-application-to-access-the-network.png "allowing-the-visual-studio-code-application-to-access-the-network")


## What should I do when the image failed to be burnt?<a name="section571164016565"></a>

-   **Symptom**

    The burning status is not displayed after clicking  **Burn**  and selecting a serial port.

-   **Possible Causes**

    The IDE is not restarted after the DevEco plug-in is installed.

-   **Solutions**

    Restart the IDE.


## What should I do when the message indicating Python cannot be found is displayed during compilation and building?<a name="section1039835245619"></a>

-   **Symptom**

    ![](figure/symptom.png)


-   **Possible Cause 1**: Python is not installed.
-   **Solutions**

    Install Python as instructed in  [Installing and Configuring Python](quickstart-lite-env-setup-linux.md#section1238412211211).

-   **Possible Cause 2**: The soft link that points to the Python does not exist in the usr/bin directory.

    ![](figure/reason-for-not-finding-python.png)

-   **Solutions**

    Run the following commands:

    ```
    # cd /usr/bin/
    # which python3
    # ln -s /usr/local/bin/python3 python
    # python --version
    ```

    Example:

    ![](figure/solution-7.png)


## What should I do when no command output is displayed?<a name="section14871149155911"></a>

-   **Symptom**

    The serial port shows that the connection has been established. After the board is restarted, nothing is displayed when you press  **Enter**.

-   **Possible Cause 1**

    The serial port is connected incorrectly.

-   **Solutions**

    Change the serial port number.

    Start  **Device Manager**  to check whether the serial port connected to the board is the same as that connected to the terminal device. If the serial ports are different, perform step  [1](#section627268185113)  in the  **Running an Image**  section to change the serial port number.


-   **Possible Cause 2**

    The U-Boot of the board is damaged.

-   **Solutions**

    Burn the U-Boot.

    If the fault persists after you perform the preceding operations, the U-Boot of the board may be damaged. You can burn the U-Boot by performing the following steps:


1.  Obtain the U-Boot file.

    >![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
    >The U-Boot file of the two boards can be obtained from the following paths, respectively.
    >Hi3516D V300:  **device\\hisilicon\\hispark\_taurus\\sdk\_liteos\\uboot\\out\\boot\\u-boot-hi3516dv300.bin**
    >Hi3518E V300:  **device\\hisilicon\\hispark\_aries\\sdk\_liteos\\uboot\\out\\boot\\u-boot-hi3518ev300.bin**

2.  Burn the U-Boot file by following the procedures for burning a U-Boot file over USB.

    Select the U-Boot files of corresponding development boards for burning by referring to  [Programming Flash Memory on the Hi3516](https://device.harmonyos.com/en/docs/ide/user-guides/hi3516_upload-0000001052148681)/[Programming Flash Memory on the Hi3518](https://device.harmonyos.com/en/docs/ide/user-guides/hi3518_upload-0000001057313128)

3.  Log in to the serial port after the burning is complete.

    **Figure  10**  Serial port displayed after the U-Boot is burnt<a name="en-us_topic_0000001053466255_fig155914681910"></a>  
    ![](figure/serial-port-displayed-after-the-u-boot-is-burnt.png "serial-port-displayed-after-the-u-boot-is-burnt")


