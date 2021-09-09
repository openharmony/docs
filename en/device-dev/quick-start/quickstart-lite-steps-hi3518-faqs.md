# FAQs<a name="EN-US_TOPIC_0000001128311064"></a>

-   [What should I do when the images failed to be burnt over the selected serial port?](#section1498892119619)
-   [What should I do when Windows-based PC failed to be connected to the board?](#section8512971816)
-   [What should I do when the image failed to be burnt?](#section1767804111198)
-   [What should I do when the message indicating Python cannot be found is displayed during compilation and building?](#en-us_topic_0000001053466255_section1039835245619)
-   [What should I do when no command output is displayed?](#en-us_topic_0000001053466255_section14871149155911)

## What should I do when the images failed to be burnt over the selected serial port?<a name="section1498892119619"></a>

-   **Symptom**

    **Error: Opening COMxx: Access denied**  is displayed after clicking  **Burn**  and selecting a serial port.

    **Figure  1**  Failed to open the serial port<a name="en-us_topic_0000001053466255_fig066333283916"></a>  
    ![](figure/failed-to-open-the-serial-port-17.png "failed-to-open-the-serial-port-17")

-   **Possible Causes**

    The serial port has been used.

-   **Solutions**

1.  Search for the terminal using serial-xx from the drop-down list in the  **TERMINAL**  panel.

    **Figure  2**  Checking whether the serial port is used<a name="en-us_topic_0000001053466255_fig165994164420"></a>  
    ![](figure/checking-whether-the-serial-port-is-used-18.png "checking-whether-the-serial-port-is-used-18")

2.  Click the dustbin icon as shown in the following figure to disable the terminal using the serial port.

    **Figure  3**  Disabling the terminal using the serial port<a name="en-us_topic_0000001053466255_fig7911282453"></a>  
    ![](figure/disabling-the-terminal-using-the-serial-port-19.png "disabling-the-terminal-using-the-serial-port-19")

3.  Click  **Burn**, select the serial port, and start burning images again.

    **Figure  4**  Restarting burning<a name="fig87139519227"></a>  
    ![](figure/restarting-burning-20.png "restarting-burning-20")


## What should I do when Windows-based PC failed to be connected to the board?<a name="section8512971816"></a>

-   **Symptom**

    The file image cannot be obtained after clicking  **Burn**  and selecting a serial port.

    **Figure  5**  Failed to obtain the image file due to unavailable connection<a name="en-us_topic_0000001053466255_fig5218920223"></a>  
    ![](figure/failed-to-obtain-the-image-file-due-to-unavailable-connection-21.png "failed-to-obtain-the-image-file-due-to-unavailable-connection-21")

-   **Possible Causes**

    The board is disconnected from the Windows-based PC.

    Windows Firewall does not allow Visual Studio Code to access the network.

-   **Solutions**

1.  Check whether the network cable is properly connected.
2.  Click  **Windows Firewall**.

    **Figure  6**  Network and firewall setting<a name="fig954464811215"></a>  
    ![](figure/network-and-firewall-setting-22.png "network-and-firewall-setting-22")

3.  Click  **Firewall & network protection**, and on the displayed page, click  **Allow applications to communicate through Windows Firewall**.

    **Figure  7**  Firewall and network protection<a name="fig158731526101312"></a>  
    ![](figure/firewall-and-network-protection-23.png "firewall-and-network-protection-23")

4.  Select the Visual Studio Code application.

    **Figure  8**  Selecting the Visual Studio Code application<a name="fig96572537139"></a>  
    ![](figure/selecting-the-visual-studio-code-application-24.png "selecting-the-visual-studio-code-application-24")

5.  Select the  **Private**  and  **Public**  network access rights for the Visual Studio Code application.

    **Figure  9**  Allowing the Visual Studio Code application to access the network<a name="fig18201217161411"></a>  
    ![](figure/allowing-the-visual-studio-code-application-to-access-the-network-25.png "allowing-the-visual-studio-code-application-to-access-the-network-25")


## What should I do when the image failed to be burnt?<a name="section1767804111198"></a>

-   **Symptom**

    The burning status is not displayed after clicking  **Burn**  and selecting a serial port.

-   **Possible Causes**

    The IDE is not restarted after the DevEco plug-in is installed.

-   **Solutions**

    Restart the IDE.


## What should I do when the message indicating Python cannot be found is displayed during compilation and building?<a name="en-us_topic_0000001053466255_section1039835245619"></a>

-   **Symptom**

    ![](figure/error.png)


-   **Possible Cause 1**

    Python is not installed.

-   **Solutions**

    Install Python as instructed in  [Installing and Configuring Python](quickstart-lite-env-setup-linux.md#section1238412211211).

-   **Possible Cause 2**: The soft link that points to the Python does not exist in the usr/bin directory.

    ![](figure/error2.png)

-   **Solutions**

    Run the following commands:

    ```
    # cd /usr/bin/
    # which python3
    # ln -s /usr/local/bin/python3 python
    # python --version
    ```

    Example:

    ![](figure/solution-26.png)


## What should I do when no command output is displayed?<a name="en-us_topic_0000001053466255_section14871149155911"></a>

-   **Symptom**

    The serial port shows that the connection has been established. After the board is restarted, nothing is displayed when you press  **Enter**.

-   **Possible Cause 1**

    The serial port is connected incorrectly.

-   **Solutions**

    Change the serial port number.

    Start  **Device Manager**  to check whether the serial port connected to the board is the same as that connected to the terminal device. If the serial ports are different, perform step  [1](#section1498892119619)  in the  **Running an Image**  section to change the serial port number.


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

    ![](figure/login-serial-port.png)


