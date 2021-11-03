# Burning Images<a name="EN-US_TOPIC_0000001153557088"></a>

-   [Prerequisites](#section18547185418328)
-   [Programming Flash Memory Through the Network Port](#section1965361953312)

Burning of a regular system requires DevEco Device Tool v2.2 Beta1 or later.

Hi3516D V300 supports burning of the standard system through the USB port, network port, or serial port, where:

-   **Windows system: Supports burning through the USB port, serial port, or network port**
-   **Linux system: Supports burning through the network port or serial port**

Except for environment setup, the operations of burning are the same for Windows and Linux.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>Currently, the Hi3516D V300 development board supports programming flash memory of the standard system through the USB port, network port, or serial port. This document uses the network port as an example. For details about programming flash memory over other ports, see  [Programming Flash Memory on Hi3516D V300](https://device.harmonyos.com/en/docs/ide/user-guides/hi3516_upload-0000001052148681).

## Prerequisites<a name="section18547185418328"></a>

In DevEco Device Tool, select  **Import Project**  to open the folder where the target file is located. Set  **MCU**  to  **Hi3516DV300**  under  **HiSilicon\_Arm\_Linux**  and  **Framework**  to  **Ohos-sources**  or  **Hpm**.

![](figures/hisilicon-arm-linux.png)

## Programming Flash Memory Through the Network Port<a name="section1965361953312"></a>

The Hi3516DV300 supports burning through the network port in Windows or Linux.

1.  Connect the PC and the target development board through the serial port, network port, and power port. For details, see  [Introduction to the Hi3516 Development Board](https://device.harmonyos.com/en/docs/start/introduce/oem_minitinier_des_3516-0000001152041033).
2.  <a name="en-us_topic_0000001056443961_li1050616379507"></a>Open Device Manager, then check and record the serial port number corresponding to the development board.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >If the serial port number is not displayed correctly, follow the steps described in  [Installing the Serial Port Driver on the Hi3516 or Hi3518 Series Development Boards](https://device.harmonyos.com/en/docs/ide/user-guides/hi3516_hi3518-drivers-0000001050743695).

    ![](figures/hi3516-record-the-serial-port-number.png)

3.  Open DevEco Device Tool, choose  **QUICK ACCESS**  \>  **DevEco Home**  \>  **Projects**, and then click  **Settings**.

    ![](figures/hi3516-deveco-device-tool-setting.png)

4.  On the  **hi3516dv300**  tab page, configure the burning options.

    -   **upload\_port**: Select the serial port number obtained in step  [2](#en-us_topic_0000001056443961_li1050616379507).
    -   **upload\_protocol**: Select the burning protocol  **hiburn-net**.
    -   **upload\_partitions**: Select the files to be burnt. By default,  **fastboot**,  **boot**,  **updater**,  **misc**,  **system**,  **vendor**, and  **userdata**  are burnt at the same time.

    ![](figures/upload-options-2.png)

5.  <a name="en-us_topic_0000001056443961_li85106114532"></a>Check and set the IP address of the network adapter connected to the development board. For details, see  [Setting the IP Address of the Network Port for Burning to Hi3516](https://device.harmonyos.com/en/docs/ide/user-guides/set_ipaddress-0000001141825075).
6.  Set the IP address of the network port for burning:

    -   **upload\_net\_server\_ip**: Select the IP address set in step  [5](#en-us_topic_0000001056443961_li85106114532), such as 192.168.1.2.
    -   **upload\_net\_client\_mask**: Set the subnet mask of the development board, such as 255.255.255.0. Once the  **upload\_net\_server\_ip**  field is set, this field will be automatically populated. Example: 255.255.255.0.
    -   **upload\_net\_client\_gw**: Set the gateway of the development board, such as 192.168.1.1. Once the  **upload\_net\_server\_ip**  field is set, this field will be automatically populated. Example: 192.168.1.1.
    -   **upload\_net\_client\_ip**: Set the IP address of the development board, such as 192.168.1.3. Once the  **upload\_net\_server\_ip**  field is set, this field will be automatically populated. Example: 192.168.1.3.

    ![](figures/ip-address-information-3.png)

7.  When you finish modifying, click  **Save**  in the upper right corner.
8.  Open the project file and go to  ![](figures/2021-01-27_170334.png)  \>  **PROJECT TASKS**  \>  **hi3516dv300**  \>  **Upload**  to start burning.

    ![](figures/en-us_image_0000001215342695.png)

9.  When the following message is displayed, power off the development board and then power it on.

    ![](figures/hi3516-restart-the-development-board.png)

10. If the following message is displayed, it indicates that the burning is successful.

    ![](figures/hi3516-burning-succeeded-net.png)

11. When the burning is successful, perform the operations in  [Running an Image](https://device.harmonyos.com/en/docs/start/introduce/quickstart-standard-running-0000001142160948)  to start the system.

