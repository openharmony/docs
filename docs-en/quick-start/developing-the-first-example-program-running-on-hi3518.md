# Developing the First Example Program running on Hi3518<a name="EN-US_TOPIC_0000001053422339"></a>

This section describes how to modify, compile, burn, and run the first program on the board, and finally print  **Hello OHOS!**.

## Acquiring Source Code<a name="section1726092873119"></a>

You need to acquire  [Hi3518 source code](https://repo.huaweicloud.com/harmonyos/os/1.0/code-1.0.tar.gz)  and download it on a Linux server. For details, see  [Source Code Acquisition](../get-code/source-code-acquisition.md).

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

## Compiling Code<a name="section234175193114"></a>

On the Linux server, access the root directory of the source code package and run the following script to compile the source code package. The result files are generated in the  **out/ipcamera\_hi3518ev300**  directory.

Hi3518EV300

```
python build.py ipcamera_hi3518ev300 -b debug
```

## Burning Images<a name="section13453727165513"></a>

Burn images to the Hi3518EV300 board over the serial port.

1.  Connect a serial cable \(USB port\) of the board to the Windows host and start  **Device Manager**  to check whether the serial port number is COM7.

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >To update the USB-to-Serial driver, you need to start  **Device Manager**, right-click the device, and choose  **Update Driver Software**  \>  **Search automatically for updated driver software**.

    **Figure  1**  Successful driver installation<a name="fig44731317340"></a>  
    ![](figures/successful-driver-installation-2.png "successful-driver-installation-2")

2.  Start the HiTool, select the  **Hi3518EV300**  chip, select  **COM7**  for  **Local PC Config**, and select  **Serial**  for  **Transfer Mode**.

    **Figure  2**  Configuring the serial port on HiTool<a name="fig39175210590"></a>  
    ![](figures/configuring-the-serial-port-on-hitool.png "configuring-the-serial-port-on-hitool")

3.  Burn the newly compiled  **OHOS\_Image.bin**  file,  **rootfs.img**, and  **userfs.img**  files to the board. Ensure the file path, flash type, burning start address, and burning length are correct. Modify relevant parameters based on the file size. The value is rounded up, in MB.

    **Figure  3**  Burning images using HiTool<a name="fig86613431218"></a>  
    ![](figures/burning-images-using-hitool.png "burning-images-using-hitool")

4.  Click  **Burn**  and power on the board as required. \(If the board is powered on, power it off and then power it on.\)

    **Figure  4** <a name="fig25501252753"></a>  
    ![](figures/en-us_image_0000001054219799.png "en-us_image_0000001054219799")

5.  Click  **OK**.

    **Figure  5**  Successful burning<a name="fig1527452663210"></a>  
    ![](figures/successful-burning-3.png "successful-burning-3")


## Running an Image<a name="section62131033183710"></a>

1.  Connect to the serial port. After the images are burnt successfully, start the terminal, click  **Settings**, set  **View Title**  to  **Terminal 11**  and  **Port**  to  **COM7**, and click  **OK**  to open the serial port. You have logged in to the U-boot if  **hisilicon \#**  is displayed.

    **Figure  6**  Serial port connection<a name="fig197461744191012"></a>  
    ![](figures/serial-port-connection.png "serial-port-connection")

2.  \(Mandatory for the first burning\) Modify the  **bootcmd**  and  **bootargs**  parameters of U-boot. This step is a fixed operation and the result can be saved. However, you need to perform the following steps again if U-boot needs to be reburnt.

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
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17368202082213"><a name="p17368202082213"></a><a name="p17368202082213"></a>Run this command to set the content of <strong id="b799474113329"><a name="b799474113329"></a><a name="b799474113329"></a>bootcmd</strong>. Select the flash whose number is 0, and read content that has a size of 0x600000 and a start address of 0x100000 to memory address 0x40000000.</p>
    </td>
    </tr>
    <tr id="row136814209227"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p234414019231"><a name="p234414019231"></a><a name="p234414019231"></a>setenv bootargs "console=ttyAMA0,115200n8 root=flash fstype=jffs2 rw rootaddr=7 M rootsize=8 M";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10368102010223"><a name="p10368102010223"></a><a name="p10368102010223"></a>In this command, <strong id="b1475793912349"><a name="b1475793912349"></a><a name="b1475793912349"></a>bootargs</strong> is set to the serial port output, the baud rate is <strong id="b1310782917185"><a name="b1310782917185"></a><a name="b1310782917185"></a>115200</strong>, the data bit is <strong id="b149010367189"><a name="b149010367189"></a><a name="b149010367189"></a>8</strong>, and the <strong id="b19757173918344"><a name="b19757173918344"></a><a name="b19757173918344"></a>rootfs</strong> is mounted to the flash memory. The file system type is set to <strong id="b875763919342"><a name="b875763919342"></a><a name="b875763919342"></a>jffs2 rw</strong>, which provides the read-write attribute for the JFFS2 file system. <strong id="b1645229193620"><a name="b1645229193620"></a><a name="b1645229193620"></a>rootaddr=7 M rootsize=8 M</strong> indicates the actual start address and length of the <strong id="b136501629153613"><a name="b136501629153613"></a><a name="b136501629153613"></a>rootfs.img</strong> file to be burnt, respectively. The size must be the same as that of the compiled files in the HiTool.</p>
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

    **Figure  7**  Startup parameter settings<a name="fig11101652163517"></a>  
    ![](figures/startup-parameter-settings.png "startup-parameter-settings")

3.  If  **hisilicon \#**  is displayed during the startup, run the  **reset**  command. After the system automatically starts and  **OHOS**  is displayed, run the  **./bin/camera\_app**  command and then press  **Enter**. The system is started successfully if information shown in the following figure is displayed.

    **Figure  8**  Successful system startup and program execution<a name="fig11838403383"></a>  
    ![](figures/successful-system-startup-and-program-execution.png "successful-system-startup-and-program-execution")


## Follow-up Learning<a name="section9712145420182"></a>

Congratulations! You have finished all steps! You are advised to go on learning how to develop  [Cameras with a Screen](../guide/camera-control.md).

