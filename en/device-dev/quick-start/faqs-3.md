# FAQs<a name="EN-US_TOPIC_0000001105368702"></a>

-   [What should I do when the images failed to be burnt over the selected serial port?](#section627268185113)
-   [What should I do when Windows-based PC failed to be connected to the board?](#section195391036568)
-   [What should I do when the image failed to be burnt?](#section571164016565)
-   [What should I do when the message indicating Python cannot be found is displayed during compilation and building?](#section1039835245619)
-   [What should I do when no command output is displayed?](#section14871149155911)

## What should I do when the images failed to be burnt over the selected serial port?<a name="section627268185113"></a>

-   **Symptom**

    **Error: Opening COMxx: Access denied**  is displayed after clicking  **Burn**  and selecting a serial port.

    **Figure  1**  Failed to open the serial port<a name="fig066333283916"></a>  
    ![](figures/failed-to-open-the-serial-port.png "failed-to-open-the-serial-port")

-   **Possible Causes**

    The serial port has been used.

-   **Solutions**

1.  Search for the terminal using serial-xx from the drop-down list in the  **TERMINAL**  panel.

    **Figure  2**  Checking whether the serial port is used<a name="fig165994164420"></a>  
    ![](figures/checking-whether-the-serial-port-is-used.png "checking-whether-the-serial-port-is-used")

2.  Click the dustbin icon as shown in the following figure to disable the terminal using the serial port.

    **Figure  3**  Disabling the terminal using the serial port<a name="fig7911282453"></a>  
    ![](figures/disabling-the-terminal-using-the-serial-port.png "disabling-the-terminal-using-the-serial-port")

3.  Click  **Burn**, select the serial port, and start burning images again.

    **Figure  4**  Restarting burning<a name="fig1138624316485"></a>  
    

    ![](figures/changjian1.png)


## What should I do when Windows-based PC failed to be connected to the board?<a name="section195391036568"></a>

-   **Symptom**

    The file image cannot be obtained after clicking  **Burn**  and selecting a serial port.

    **Figure  5**  Failed to obtain the image file due to unavailable connection<a name="fig5218920223"></a>  
    ![](figures/failed-to-obtain-the-image-file-due-to-unavailable-connection.png "failed-to-obtain-the-image-file-due-to-unavailable-connection")

-   **Possible Causes**

    The board is disconnected from the Windows-based PC.

    Windows Firewall does not allow Visual Studio Code to access the network.

-   **Solutions**

1.  Check whether the network cable is properly connected.
2.  Click  **Windows Firewall**.

    **Figure  6**  Network and firewall setting<a name="fig62141417794"></a>  
    ![](figures/network-and-firewall-setting.png "network-and-firewall-setting")

3.  Click  **Firewall & network protection**, and on the displayed page, click  **Allow applications to communicate through Windows Firewall**.

    **Figure  7**  Firewall and network protection<a name="fig20703151111116"></a>  
    ![](figures/firewall-and-network-protection.png "firewall-and-network-protection")

4.  Select the Visual Studio Code application.

    **Figure  8**  Selecting the Visual Studio Code application<a name="fig462316612165"></a>  
    ![](figures/selecting-the-visual-studio-code-application.png "selecting-the-visual-studio-code-application")

5.  Select the  **Private**  and  **Public**  network access rights for the Visual Studio Code application.

    **Figure  9**  Allowing the Visual Studio Code application to access the network<a name="fig132725269184"></a>  
    ![](figures/allowing-the-visual-studio-code-application-to-access-the-network.png "allowing-the-visual-studio-code-application-to-access-the-network")


## What should I do when the image failed to be burnt?<a name="section571164016565"></a>

-   **Symptom**

    The burning status is not displayed after clicking  **Burn**  and selecting a serial port.

-   **Possible Causes**

    The IDE is not restarted after the DevEco plug-in is installed.

-   **Solutions**

    Restart the IDE.


## What should I do when the message indicating Python cannot be found is displayed during compilation and building?<a name="section1039835245619"></a>

-   **Symptom**

    ![](figures/en-us_image_0000001105056492.png)


-   **Possible Cause 1**: Python is not installed.
-   **Solutions**

    Install Python by referring to  [Installing and Configuring Python](../quick-start/ubuntu-build-environment.md).

-   **Possible Cause 2**: The soft link that points to the Python does not exist in the usr/bin directory.

    ![](figures/en-us_image_0000001151976069.png)

-   **Solutions**

    Run the following commands:

    ```
    # cd /usr/bin/
    # which python3
    # ln -s /usr/local/bin/python3 python
    # python --version
    ```

    Example:

    ![](figures/en-us_image_0000001152176139.png)


## What should I do when no command output is displayed?<a name="section14871149155911"></a>

-   **Symptom**

    The serial port shows that the connection has been established. After the board is restarted, nothing is displayed when you press  **Enter**.

-   **Possible Cause 1**

    The serial port is connected incorrectly.

-   **Solutions**

    Change the serial port number.

    Start  **Device Manager**  to check whether the serial port connected to the board is the same as that connected to the terminal device. If the serial ports are different, perform step  [1](../quick-start/running-a-hello-ohos-program.md)  in the  **Running an Image**  section to change the serial port number.


-   **Possible Cause 2**

    The U-boot of the board is damaged.

-   **Solutions**

    Burn the U-boot.

    If the fault persists after you perform the preceding operations, the U-boot of the board may be damaged. You can burn the U-boot by performing the following steps:


1.  Obtain the U-boot file.

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >The U-boot file of the two boards can be obtained from the following paths, respectively.
    >Hi3516D V300:  **device\\hisilicon\\hispark\_taurus\\sdk\_liteos\\uboot\\out\\boot\\u-boot-hi3516dv300.bin**
    >Hi3518E V300:  **device\\hisilicon\\hispark\_aries\\sdk\_liteos\\uboot\\out\\boot\\u-boot-hi3518ev300.bin**

2.  Burn the U-boot file by following the procedures for burning a U-boot file over USB.

    Select the U-boot files of corresponding development boards for burning by referring to  [Programming Flash Memory on the Hi3516](https://device.harmonyos.com/en/docs/ide/user-guides/hi3516_upload-0000001052148681)/[Programming Flash Memory on the Hi3518](https://device.harmonyos.com/en/docs/ide/user-guides/hi3518_upload-0000001057313128)

3.  Log in to the serial port after the burning is complete.

    **Figure  10**  Serial port displayed after the U-boot is burnt<a name="en-us_topic_0000001053466255_fig155914681910"></a>  
    ![](figures/serial-port-displayed-after-the-u-boot-is-burnt.png "serial-port-displayed-after-the-u-boot-is-burnt")


