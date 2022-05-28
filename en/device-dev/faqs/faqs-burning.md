# Burning<a name="EN-US_TOPIC_0000001170009518"></a>


## Mini and Small Systems<a name="section278314413530"></a>

### "Error: Opening COMxx: Access denied" Is Displayed After a Serial Port Is Selected for Burning<a name="section18988185615914"></a>

-   **Symptom**

    **Error: Opening COMxx: Access denied**  is displayed after clicking  **Burn**  and selecting a serial port.

    ![](figures/failed-to-open-the-serial-port.png)

-   **Possible Causes**

    The serial port has been used.

-   Solution

    The serial port may be in use. Perform the following steps to troubleshoot:

    1.  Search for the serial port from the drop-down list in the  **TERMINAL**  panel.

        ![](figures/terminal-list.png)

    2.  Click the dustbin for the terminal using the serial port to disable the terminal.


### What should I do when the image failed to be burnt?<a name="section1370982513317"></a>

-   **Symptom**

    The burning status is not displayed after clicking  **Burn**  and selecting a serial port.

-   **Possible Causes**

    The IDE is not restarted after the DevEco plug-in is installed.

-   **Solutions**

    Restart the IDE.


### What should I do when no command output is displayed?<a name="section183421944953"></a>

-   **Symptom**

    The serial port shows that the connection has been established. After the board is restarted, nothing is displayed when you press  **Enter**.

-   **Possible Cause 1**

    The serial port is connected incorrectly.

-   **Solutions**

    Change the serial port number.

    Start  **Device Manager**  to check whether the serial port connected to the board is the same as that connected to the terminal device. If the serial ports are different, perform step 1 in the  **Running an Image**  section to change the serial port number.


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

    Select the U-Boot files of corresponding development boards for burning by referring to  [Programming Flash Memory on the Hi3516](../quick-start/quickstart-lite-steps-hi3516-running.md)/[Programming Flash Memory on the Hi3518](../quick-start/quickstart-ide-lite-steps-hi3516-burn.md)

3.  Log in to the serial port after the burning is complete.

    **Figure  1**  Serial port displayed after the U-Boot is burnt<a name="en-us_topic_0000001128470856_en-us_topic_0000001053466255_fig155914681910"></a>  
    ![](figures/serial-port-displayed-after-the-u-boot-is-burnt.png "serial-port-displayed-after-the-u-boot-is-burnt")


### What should I do when Windows-based PC failed to be connected to the board?<a name="section1215410450215"></a>

-   **Symptom**

    The file image cannot be obtained after clicking  **Burn**  and selecting a serial port.

    **Figure  2**  Failed to obtain the image file due to unavailable connection<a name="en-us_topic_0000001128470856_fig135261439195819"></a>  
    ![](figures/failed-to-obtain-the-image-file-due-to-unavailable-connection.png "failed-to-obtain-the-image-file-due-to-unavailable-connection")

-   **Possible Causes**

    The board is disconnected from the Windows-based PC.

    Windows Firewall does not allow Visual Studio Code to access the network.

-   **Solutions**

1.  Check whether the network cable is properly connected.
2.  Click  **Windows Firewall**.

    ![](figures/hi3516-network-and-firewall-setting.png)

3.  Click  **Firewall & network protection**, and on the displayed page, click  **Allow applications to communicate through Windows Firewall**.

    ![](figures/hi3516-firewall-and-network-protection.png)

4.  Select the Visual Studio Code application.

    ![](figures/hi3516-selecting-the-visual-studio-code-application.png)

5.  Select the  **Private**  and  **Public**  network access rights for the Visual Studio Code application.

    ![](figures/hi3516-allowing-the-visual-studio-code-application-to-access-the-network.png)


