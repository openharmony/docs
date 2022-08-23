# Burning Code by Using HiTool


To burn code to the Hi3516D V300 development board, you can use HiTool in addition to DevEco Device Tool.


## Prerequisites

- The source code of the development board has been compiled into files for burning.

- [HiTool](http://www.hihope.org/download/download.aspx) has been installed on the client platform (for example, a Windows-based computer).

- The USB driver has been installed on the client platform. For details, see [Installing the USB Port Driver on the Hi3516D V300 Development Board](https://device.harmonyos.com/en/docs/documentation/guide/usb_driver-0000001058690393).

- A serial port terminal tool, such as IPOP, has been installed on the client platform.

- The client platform and development board are connected using a USB cable and serial cable.


## Procedure

1. Prepare the files to be burnt.

   1. On the client platform, create a folder for storing the files to be burnt, for example, **D:\L2**.

   2. Download the compiled source package to the client platform, decompress the package, and copy the files required for burning to the folder created in step 1.

       For the Hi3516D V300 development board, the files required for burning of the standard system are as follows: **boot.img**, **Hi3516DV300-emmc.xml**, **system.img**, **u-boot-hi3516dv300_emmc.bin**, **uImage**, **updater.img**, **userdata.img**, and **vendor.img**.

2. Burn the image files using HiTool.

   1. Open HiTool.

   2. Set up HiTool.

      Set the transfer mode to USB and burning mode to eMMC (the storage medium of the development board is eMMC).

   3. Click **Browse** and select the burning configuration file (for example, **Hi3516DV300-emmc.xml**) from the folder created in step 1.

   4. After clicking the **Burn** button, press and hold the **Update** key next to the serial port on the development board, and remove and insert the USB cable.

       After the burning starts, logs are displayed in the console area at the bottom of HiTool.

       When the burning is complete, HiTool displays a dialog box indicating that the burning is successful.

   5. Click **OK**.

3. Import startup parameters.

   1. Use the terminal tool to enable the serial port.

   2. Restart the development board by removing and inserting its power supply. Press **Enter** in the serial port terminal tool within 3 seconds.

       If **hisilicon \#** is displayed on the terminal tool page, the serial port of the development board is connected.

   3. Copy the following startup parameters in the serial port terminal tool and press **Enter** to complete the setup.
      
       ```
       setenv bootargs 'mem=640M console=ttyAMA0,115200 mmz=anonymous,0,0xA8000000,384M clk_ignore_unused androidboot.selinux=permissive rootdelay=10 hardware=Hi3516DV300 init=/init root=/dev/ram0 rw blkdevparts=mmcblk0:1M(boot),15M(kernel),20M(updater),2M(misc),3307M(system),256M(vendor),-(userdata)';setenv bootcmd 'mmc read 0x0 0x82000000 0x800 0x4800; bootm 0x82000000'
       
       saveenv
       
       reset
       ```

       > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **NOTICE**<br>
       > When entering startup parameters, do not delete blank lines.
