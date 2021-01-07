# Developing the First Example Program Running on Hi3518<a name="EN-US_TOPIC_0000001053422339"></a>

-   [Acquiring Source Code](#section1726092873119)
-   [Modifying a Program](#s8efc1952ebfe4d1ea717182e108c29bb)
-   [Building](#section234175193114)
-   [Burning](#section57955241588)
-   [Running an Image](#section62131033183710)
-   [Follow-up Learning](#section9712145420182)

This section describes how to modify, compile, burn, and run the first program on the board, and finally print  **Hello OHOS!**.

## Acquiring Source Code<a name="section1726092873119"></a>

You need to acquire  [Hi3518 source code](https://repo.huaweicloud.com/harmonyos/os/1.0/code-1.0.tar.gz), download it on a Linux server, and decompress it. For details, see  [Source Code Acquisition](../get-code/source-code-acquisition.md).

## Modifying a Program<a name="s8efc1952ebfe4d1ea717182e108c29bb"></a>

The following example shows the  **helloworld.c**  code in the  **applications/sample/camera/app/src**  directory. You can customize the content to be printed. For example, you can change OHOS to World. You can use either ISO C or C++ to develop a program.

```
#include <stdio.h>
#include "los_sample.h"

int main(int argc, char **argv)
{
    printf("\n************************************************\n");
    printf("\n\t\tHello OHOS!\n");
    printf("\n************************************************\n\n");

    LOS_Sample(g_num);

    return 0;
}
```

## Building<a name="section234175193114"></a>

If the Linux environment is installed using Docker, perform the compilation by referring to  [Using Docker to Prepare the Build Environment](../get-code/tool-acquisition.md). If the Linux compilation environment is installed using a software package, execute the following command to compile source code in the root directory of the source code package.

```
python build.py ipcamera_hi3518ev300 -b debug
```

The result files are generated in the  **out/ipcamera\_hi3518ev300**  directory.

## Burning<a name="section57955241588"></a>

The USB port is the only burning mode supported by the Hi3518 development board.

1.  Connect the PC and the target development board through the serial port and USB port. In this section, the Hi3518EV300 is used as an example. For details, please refer to  [Introduction to the Hi3518 Development Board](https://device.harmonyos.com/en/docs/start/introduce/oem_camera_start_hi3518-0000001050170473).
2.  <a name="en-us_topic_0000001072392860_li101031912111518"></a>Open Device Manager, then check and record the serial port number corresponding to the development board.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >If the serial port number is not displayed correctly, follow the steps described in  [Installing the Serial Port Driver on the Hi3516 or Hi3518 Series Development Boards](https://device.harmonyos.com/en/docs/ide/user-guides/hi3516_hi3518-drivers-0000001050743695).

    ![](figures/en-us_image_0000001071792503.png)

3.  Go to  **Device Tool**  \>  **Configure**  \>  **Burn**. On the displayed page, set the programming information.

    ![](figures/en-us_image_0000001071514657.png)

4.  Set  **Burning Mode**  to  **usbport**.

    ![](figures/en-us_image_0000001072552464.png)

5.  Set the programming parameters.
    -   Set  **Port number**  to the serial port number recorded in  [2](#en-us_topic_0000001072392860_li101031912111518).
    -   Retain the default values for the baud rate and data bits, which have been adapted for the development board.
    -   Set the memory type. For the Hi3518 series development boards, the memory type is fixed at SPI NOR.
    -   Set the information about the files to be written according to the following table.

        <a name="en-us_topic_0000001072392860_table17829824143410"></a>
        <table><thead align="left"><tr id="en-us_topic_0000001072392860_row1782992414343"><th class="cellrowborder" valign="top" width="25.130000000000003%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001072392860_p198641828133419"><a name="en-us_topic_0000001072392860_p198641828133419"></a><a name="en-us_topic_0000001072392860_p198641828133419"></a>File Name</p>
        </th>
        <th class="cellrowborder" valign="top" width="24.87%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001072392860_p086415289344"><a name="en-us_topic_0000001072392860_p086415289344"></a><a name="en-us_topic_0000001072392860_p086415289344"></a>Start Address</p>
        </th>
        <th class="cellrowborder" valign="top" width="24.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001072392860_p986462863413"><a name="en-us_topic_0000001072392860_p986462863413"></a><a name="en-us_topic_0000001072392860_p986462863413"></a>File Size</p>
        </th>
        <th class="cellrowborder" valign="top" width="25.019999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001072392860_p58291224193410"><a name="en-us_topic_0000001072392860_p58291224193410"></a><a name="en-us_topic_0000001072392860_p58291224193410"></a>Enable</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="en-us_topic_0000001072392860_row4829112453415"><td class="cellrowborder" valign="top" width="25.130000000000003%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001072392860_p18829162417342"><a name="en-us_topic_0000001072392860_p18829162417342"></a><a name="en-us_topic_0000001072392860_p18829162417342"></a>u-boot-<em id="en-us_topic_0000001072392860_i1060617376418"><a name="en-us_topic_0000001072392860_i1060617376418"></a><a name="en-us_topic_0000001072392860_i1060617376418"></a>development board name</em>.bin</p>
        </td>
        <td class="cellrowborder" valign="top" width="24.87%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001072392860_p38298241348"><a name="en-us_topic_0000001072392860_p38298241348"></a><a name="en-us_topic_0000001072392860_p38298241348"></a>0</p>
        </td>
        <td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001072392860_p18295244345"><a name="en-us_topic_0000001072392860_p18295244345"></a><a name="en-us_topic_0000001072392860_p18295244345"></a>1M</p>
        </td>
        <td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001072392860_p1282982415342"><a name="en-us_topic_0000001072392860_p1282982415342"></a><a name="en-us_topic_0000001072392860_p1282982415342"></a>Select the check box.</p>
        </td>
        </tr>
        <tr id="en-us_topic_0000001072392860_row8829192415342"><td class="cellrowborder" valign="top" width="25.130000000000003%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001072392860_p1782912420346"><a name="en-us_topic_0000001072392860_p1782912420346"></a><a name="en-us_topic_0000001072392860_p1782912420346"></a>OHOS_Image.bin</p>
        </td>
        <td class="cellrowborder" valign="top" width="24.87%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001072392860_p1483012483410"><a name="en-us_topic_0000001072392860_p1483012483410"></a><a name="en-us_topic_0000001072392860_p1483012483410"></a>1M</p>
        </td>
        <td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001072392860_p1283032433419"><a name="en-us_topic_0000001072392860_p1283032433419"></a><a name="en-us_topic_0000001072392860_p1283032433419"></a>6M</p>
        </td>
        <td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001072392860_p17830524163416"><a name="en-us_topic_0000001072392860_p17830524163416"></a><a name="en-us_topic_0000001072392860_p17830524163416"></a>Select the check box if this is the first time you are programing flash memory on the development board or if the content related to the kernel and driver is modified.</p>
        </td>
        </tr>
        <tr id="en-us_topic_0000001072392860_row18830192453415"><td class="cellrowborder" valign="top" width="25.130000000000003%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001072392860_p0830162453411"><a name="en-us_topic_0000001072392860_p0830162453411"></a><a name="en-us_topic_0000001072392860_p0830162453411"></a>rootfs.img</p>
        </td>
        <td class="cellrowborder" valign="top" width="24.87%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001072392860_p7830424133418"><a name="en-us_topic_0000001072392860_p7830424133418"></a><a name="en-us_topic_0000001072392860_p7830424133418"></a>7M</p>
        </td>
        <td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001072392860_p1583012413417"><a name="en-us_topic_0000001072392860_p1583012413417"></a><a name="en-us_topic_0000001072392860_p1583012413417"></a>8M</p>
        </td>
        <td class="cellrowborder" rowspan="2" valign="top" width="25.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001072392860_p166645916376"><a name="en-us_topic_0000001072392860_p166645916376"></a><a name="en-us_topic_0000001072392860_p166645916376"></a>Select the check boxes if this is the first time you are programing flash memory on the development board or if the files have been modified. It is recommended that you always select these check boxes.</p>
        </td>
        </tr>
        <tr id="en-us_topic_0000001072392860_row38301424183414"><td class="cellrowborder" valign="top" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001072392860_p983032415348"><a name="en-us_topic_0000001072392860_p983032415348"></a><a name="en-us_topic_0000001072392860_p983032415348"></a>userfs.img</p>
        </td>
        <td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001072392860_p783016244344"><a name="en-us_topic_0000001072392860_p783016244344"></a><a name="en-us_topic_0000001072392860_p783016244344"></a>15M</p>
        </td>
        <td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001072392860_p2830142412349"><a name="en-us_topic_0000001072392860_p2830142412349"></a><a name="en-us_topic_0000001072392860_p2830142412349"></a>1M</p>
        </td>
        </tr>
        </tbody>
        </table>

        ![](figures/en-us_image_0000001071634551.png)


6.  When you have done, click  **Save**  at the bottom to save the settings.
7.  Click  ![](figures/en-us_image_0000001071984309.png)  next to  **Burn**  to start programming.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >If this is the first time you program flash memory on the Hi3516 or Hi3518 board, the message "not find the Devices" may be displayed. In this case, follow the steps in  [Installing the USB Driver on the Hi3516 or Hi3518 Series Development Boards](https://device.harmonyos.com/en/docs/ide/user-guides/usb_driver-0000001058690393)  and start programming again.

    ![](figures/en-us_image_0000001071904257.png)

8.  Restart the development board within 15 seconds.
9.  Wait until the programming is complete. If the following information is displayed on the console, it indicates that the programming is successful.

    ![](figures/usb烧录-6.png)

10. Use the  [serial port tool](https://device.harmonyos.com/en/docs/ide/user-guides/serial_port-0000001057649420)  to modify the bootcmd and bootargs contents of U-Boot. For details, please refer to  [Running an Image on the Hi3518](https://device.harmonyos.com/en/docs/start/introduce/oem_camera_start_example-0000001051610926#EN-US_TOPIC_0000001053422339__section62131033183710).

## Running an Image<a name="section62131033183710"></a>

1.  Connect to a serial port.

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >If the connection fails, rectify the fault by referring to  [What should I do when no command output is displayed?](faq-on-hi3518.md#en-us_topic_0000001053466255_section14871149155911).

    **Figure  1**  Serial port connection<a name="fig056645018495"></a>  
    

    ![](figures/chuankou1-0.png)

    1.  Click  **Serial port**  to enable it.
    2.  Enter the serial port number queried in the "Burning" section \(COM11 is used in this example\) and press  **Enter**  until  **hisillicon**  is displayed.
    3.  Go to  [step 2](#li9441185382314)  if the board is started for the first time or the startup parameters need to be modified; go to  [step 3](#li6442853122312)  otherwise.

2.  <a name="li9441185382314"></a>\(Mandatory for the first burning\) Modify the  **bootcmd**  and  **bootargs**  parameters of U-boot. This step is a fixed operation and the result can be saved. However, you need to perform the following steps again if U-boot needs to be reburnt.

    **Table  1**  Parameters of the U-boot

    <a name="table1336762011222"></a>
    <table><thead align="left"><tr id="row193681920182219"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p3368202016229"><a name="p3368202016229"></a><a name="p3368202016229"></a>Command</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p936812052217"><a name="p936812052217"></a><a name="p936812052217"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10368142032210"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1636882092214"><a name="p1636882092214"></a><a name="p1636882092214"></a>setenv bootcmd "sf probe 0;sf read 0x40000000 0x100000 0x600000;go 0x40000000";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17368202082213"><a name="p17368202082213"></a><a name="p17368202082213"></a>Run this command to set the content of <strong id="b209671361282"><a name="b209671361282"></a><a name="b209671361282"></a>bootcmd</strong>. Select the flash whose number is 0, and read content that has a size of 0x600000 and a start address of 0x100000 to memory address 0x40000000. The size must be the same as that of the <strong id="b12634352103017"><a name="b12634352103017"></a><a name="b12634352103017"></a>OHOS_Image.bin</strong> file in the IDE.</p>
    </td>
    </tr>
    <tr id="row136814209227"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p234414019231"><a name="p234414019231"></a><a name="p234414019231"></a>setenv bootargs "console=ttyAMA0,115200n8 root=flash fstype=jffs2 rw rootaddr=7 M rootsize=8 M";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10368102010223"><a name="p10368102010223"></a><a name="p10368102010223"></a>In this command, <strong id="b1475793912349"><a name="b1475793912349"></a><a name="b1475793912349"></a>bootargs</strong> is set to the serial port output, the baud rate is <strong id="b1310782917185"><a name="b1310782917185"></a><a name="b1310782917185"></a>115200</strong>, the data bit is <strong id="b149010367189"><a name="b149010367189"></a><a name="b149010367189"></a>8</strong>, and the <strong id="b19757173918344"><a name="b19757173918344"></a><a name="b19757173918344"></a>rootfs</strong> is mounted to the flash memory. The file system type is set to <strong id="b875763919342"><a name="b875763919342"></a><a name="b875763919342"></a>jffs2 rw</strong>, which provides the read-write attribute for the JFFS2 file system. rootaddr=7 M rootsize=8 M indicates the actual start address and length of the <strong id="b841582383217"><a name="b841582383217"></a><a name="b841582383217"></a>rootfs.img</strong> file to be burnt, respectively. The file size must be the same as that of the <strong id="b51690521108"><a name="b51690521108"></a><a name="b51690521108"></a>rootfs.img</strong> file in the IDE.</p>
    </td>
    </tr>
    <tr id="row2368120112219"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p20368142072217"><a name="p20368142072217"></a><a name="p20368142072217"></a>saveenv</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19368102020220"><a name="p19368102020220"></a><a name="p19368102020220"></a><strong id="b12547103053713"><a name="b12547103053713"></a><a name="b12547103053713"></a>saveenv</strong> means to save the current configuration.</p>
    </td>
    </tr>
    <tr id="row63689205220"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3368162015223"><a name="p3368162015223"></a><a name="p3368162015223"></a>reset</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p23681820182217"><a name="p23681820182217"></a><a name="p23681820182217"></a><strong id="b29195356377"><a name="b29195356377"></a><a name="b29195356377"></a>reset</strong> means to reset the board.</p>
    </td>
    </tr>
    <tr id="row346253519253"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16462113512251"><a name="p16462113512251"></a><a name="p16462113512251"></a>pri</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p3462335152514"><a name="p3462335152514"></a><a name="p3462335152514"></a><strong id="b18592103953712"><a name="b18592103953712"></a><a name="b18592103953712"></a>pri</strong> means to view the displayed parameters.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >**go 0x40000000**  \(optional\) indicates that the command is fixed in the startup parameters by default and the board automatically starts after it is reset. If you want to manually start the board, press  **Enter**  in the countdown phase of the U-boot startup to interrupt the automatic startup.

3.  <a name="li6442853122312"></a>If  **hisilicon \#**  is displayed during the startup, run the  **reset**  command. After the system automatically starts and  **OHOS**  is displayed, run the  **./bin/camera\_app**  command and then press  **Enter**. The system is started successfully if information shown in the following figure is displayed.

    **Figure  2**  Successful system startup and program execution<a name="fig11838403383"></a>  
    ![](figures/successful-system-startup-and-program-execution.png "successful-system-startup-and-program-execution")


## Follow-up Learning<a name="section9712145420182"></a>

Congratulations! You have finished all steps! You are advised to go on learning how to develop  [Cameras with a Screen](../guide/camera-control.md).

