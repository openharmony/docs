# Running a Hello OHOS Program<a name="EN-US_TOPIC_0000001174270695"></a>

-   [Creating a Program](#section204672145202)
-   [Building](#section1077671315253)
-   [Burning](#section1347011412201)
    -   [Programming Flash Memory Through the Network Port](#section1935410617363)

-   [Running an Image](#section24721014162010)
-   [Running a Program](#section5276734182615)

This section describes how to create, compile, burn, and run the first program, and finally print  **Hello OHOS!**  on the develop board.

## Creating a Program<a name="section204672145202"></a>

1.  Create a directory and the program source code.

    Create the  **applications/sample/camera/apps/src/helloworld.c**  directory and file whose code is shown in the following example. You can customize the content to be printed. For example, you can change  **OHOS**  to  **World**. You can use either C or C++ to develop a program.

    ```
    #include <stdio.h>
    
    int main(int argc, char **argv)
    {
        printf("\n************************************************\n");
        printf("\n\t\tHello OHOS!\n");
        printf("\n************************************************\n\n");
    
        return 0;
    }
    ```

2.  Create a build file.

    Create the  **applications/sample/camera/apps/BUILD.gn**  file. The file content is as follows:

    ```
    import("//build/lite/config/component/lite_component.gni")
    lite_component("hello-OHOS") {
      features = [ ":helloworld" ]
    }
    executable("helloworld") {
      output_name = "helloworld"
      sources = [ "src/helloworld.c" ]
      include_dirs = []
      defines = []
      cflags_c = []
      ldflags = []
    }
    ```

3.  Add a new component.

    Add the configuration of the  **hello\_world\_app**  component to the  **build/lite/components/applications.json**  file. The sample code below shows some configurations defined in the  **applications.json**  file, and the code between  **\#\#start\#\#**  and  **\#\#end\#\#**  is the new configuration \(Delete the rows where  **\#\#start\#\#**  and  **\#\#end\#\#**  are located after the configurations are added.\)

    ```
    {
      "components": [
        {
          "component": "camera_sample_communication",
          "description": "Communication related samples.",
          "optional": "true",
          "dirs": [
            "applications/sample/camera/communication"
          ],
          "targets": [
            "//applications/sample/camera/communication:sample"
          ],
          "rom": "",
          "ram": "",
          "output": [],
          "adapted_kernel": [ "liteos_a" ],
          "features": [],
          "deps": {
            "components": [],
            "third_party": []
          }
        },
    ##start##
        {
          "component": "hello_world_app",
          "description": "Communication related samples.",
          "optional": "true",
          "dirs": [
            "applications/sample/camera/apps"
          ],
          "targets": [
            "//applications/sample/camera/apps:hello-OHOS"
          ],
          "rom": "",
          "ram": "",
          "output": [],
          "adapted_kernel": [ "liteos_a" ],
          "features": [],
          "deps": {
            "components": [],
            "third_party": []
          }
        },
    ##end##
        {
          "component": "camera_sample_app",
          "description": "Camera related samples.",
          "optional": "true",
          "dirs": [
            "applications/sample/camera/launcher",
            "applications/sample/camera/cameraApp",
            "applications/sample/camera/setting",
            "applications/sample/camera/gallery",
            "applications/sample/camera/media"
          ],
    ```

4.  Modify the board configuration file.

    Add the  **hello\_world\_app**  component to the  **vendor/hisilicon/hispark\_taurus/config.json**  file. The sample code below shows the configurations of the  **applications**  subsystem, and the code between  **\#\#start\#\#**  and  **\#\#end\#\#**  is the new configuration \(Delete the rows where  **\#\#start\#\#**  and  **\#\#end\#\#**  are located after the configurations are added.\)

    ```
          {
            "subsystem": "applications",
            "components": [
              { "component": "camera_sample_app", "features":[] },
              { "component": "camera_sample_ai", "features":[] },
    ##start##
              { "component": "hello_world_app", "features":[] },
    ##end##
              { "component": "camera_screensaver_app", "features":[] }
            ]
          },
    ```


## Building<a name="section1077671315253"></a>

If the Linux environment is installed using Docker, perform the building by referring to  [Using Docker to Prepare the Build Environment](../get-code/gettools-acquire.md#section107932281315). If the Linux environment is installed using a software package, go to the root directory of the source code and run the following commands for source code compilation:

```
hb set (Set the building path.)
. (Select the current path.)
Select ipcamera_hispark_taurus@hisilicon and press Enter.
hb build -f (Start building.)
```

**Figure  1**  Settings<a name="fig1458988766"></a>  
![](figure/settings.png "settings")

The result files are generated in the  **out/hispark\_taurus/ipcamera\_hispark\_taurus**  directory.

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>The U-Boot file of the Hi3516D V300 development board can be obtained from the following path: device/hisilicon/hispark\_taurus/sdk\_liteos/uboot/out/boot/u-boot-hi3516dv300.bin

## Burning<a name="section1347011412201"></a>

The Hi3516 development board allows you to burn flash memory over the USB port, serial port, or network port. The following uses the network port burning as an example.

### Programming Flash Memory Through the Network Port<a name="section1935410617363"></a>

To program flash memory through the network port in the Windows or Linux environment:

1.  Connect the PC and the target development board through the serial port, network port, and power port. For details, see  [Introduction to the Hi3516 Development Board](https://device.harmonyos.com/en/docs/start/introduce/oem_minitinier_des_3516-0000001152041033).
2.  <a name="en-us_topic_0000001056443961_li142386399535"></a>Open Device Manager, then check and record the serial port number corresponding to the development board.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >If the serial port number is not displayed correctly, follow the steps described in  [Installing the Serial Port Driver on the Hi3516 or Hi3518 Series Development Boards](https://device.harmonyos.com/en/docs/ide/user-guides/hi3516_hi3518-drivers-0000001050743695).

    ![](figure/record-the-serial-port-number-1.png)

3.  Open DevEco Device Tool and go to  **Projects**  \>  **Settings**.

    ![](figure/settings-2.png)

4.  On the  **Partition Configuration**  tab page, modify the settings. In general cases, you can leave the fields at their default settings.
5.  On the  **hi3516dv300**  tab page, configure the programming options.

    -   **upload\_port**: Select the serial port number obtained in step  [2](#en-us_topic_0000001056443961_li142386399535).
    -   **upload\_protocol**: Select the programming protocol  **hiburn-net**.
    -   **upload\_partitions**: Select the file to be programmed. By default, the  **fastboot**,  **kernel**,  **rootfs**, and  **userfs**  files are programmed at the same time.

    ![](figure/hi3516-upload-options.png)

6.  <a name="en-us_topic_0000001056443961_li1558813168234"></a>Check and set the IP address of the network adapter connected to the development board. For details, see  [Setting the IP Address of the Network Port for Programming on Hi3516](https://device.harmonyos.com/en/docs/ide/user-guides/set_ipaddress-0000001141825075).
7.  Set the IP address of the network port for programming:

    -   **upload\_net\_server\_ip**: Select the IP address set in step  [6](#en-us_topic_0000001056443961_li1558813168234), such as 192.168.1.2.
    -   **upload\_net\_client\_mask**: Set the subnet mask of the development board, such as 255.255.255.0. Once the  **upload\_net\_server\_ip**  field is set, this field will be automatically populated.
    -   **upload\_net\_client\_gw**: Set the gateway of the development board, such as 192.168.1.1. Once the  **upload\_net\_server\_ip**  field is set, this field will be automatically populated. 
    -   **upload\_net\_client\_ip**: Set the IP address of the development board, such as 192.168.1.3. Once the  **upload\_net\_server\_ip**  field is set, this field will be automatically populated. 

    ![](figure/ip-address-information.png)

8.  When you finish modifying, click  **Save**  in the upper right corner.
9.  Open the project file and go to  ![](figure/deveco-device-tool-logo.png)  \>  **PROJECT TASKS**  \>  **hi3516dv300**  \>  **Upload**  to start programming.

    ![](figure/start-burning.png)

10. When the following message is displayed, power off the development board and then power it on.

    ![](figure/restart-the-development-board-3.png)

11. Start programming. If the following message is displayed, it indicates that the programming is successful.

    ![](figure/burning-succeeded-4.png)


## Running an Image<a name="section24721014162010"></a>

1.  Connect to a serial port.

    >![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
    >If the connection fails, rectify the fault by referring to  [FAQs](quickstart-lite-steps-hi3516-faqs.md).

    **Figure  2**  Serial port connection<a name="fig139171488431"></a>  
    ![](figure/serial-port-connection.png "serial-port-connection")

    1.  Click  **Monitor**  to enable the serial port.
    2.  Press  **Enter**  repeatedly until  **hisilicon**  displays.
    3.  Go to step  [2](#l5b42e79a33ea4d35982b78a22913b0b1)  if the board is started for the first time or the startup parameters need to be modified; go to step  [3](#ld26f18828aa44c36bfa36be150e60e49)  otherwise.

2.  <a name="l5b42e79a33ea4d35982b78a22913b0b1"></a>\(Mandatory when the board is started for the first time\) Modify the bootcmd and bootargs parameters of U-Boot. You need to perform this step only once if the parameters need not to be modified during the operation. The board automatically starts after it is reset.

    >![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
    >The default waiting time in the U-Boot is 2s. You can press  **Enter**  to interrupt the waiting and run the  **reset**  command to restart the system after "hisilicon" is displayed.

    **Table  1**  Parameters of the U-Boot

    <a name="table1323441103813"></a>
    <table><thead align="left"><tr id="row1423410183818"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p623461163818"><a name="p623461163818"></a><a name="p623461163818"></a>Command</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p42341014388"><a name="p42341014388"></a><a name="p42341014388"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1623471113817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p102341719385"><a name="p102341719385"></a><a name="p102341719385"></a>setenv bootcmd "mmc read 0x0 0x80000000 0x800 0x4800; go 0x80000000";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p92347120389"><a name="p92347120389"></a><a name="p92347120389"></a>Run this command to read content that has a size of 0x4800 (9 MB) and a start address of 0x800 (1 MB) to the memory address 0x80000000. The file size must be the same as that of the <strong id="b9140538191313"><a name="b9140538191313"></a><a name="b9140538191313"></a>OHOS_Image.bin</strong> file in the IDE.</p>
    </td>
    </tr>
    <tr id="row12234912381"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p172306219392"><a name="p172306219392"></a><a name="p172306219392"></a>setenv bootargs "console=ttyAMA0,115200n8 root=emmc fstype=vfat rootaddr=10M rootsize=20M rw";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p13489329396"><a name="p13489329396"></a><a name="p13489329396"></a>Run this command to set the output mode to serial port output, baud rate to <strong id="b1378372812210"><a name="b1378372812210"></a><a name="b1378372812210"></a>115200</strong>, data bit to <strong id="b27871628822"><a name="b27871628822"></a><a name="b27871628822"></a>8</strong>, <strong id="b678811281528"><a name="b678811281528"></a><a name="b678811281528"></a>rootfs</strong> to be mounted to the <strong id="b978813281220"><a name="b978813281220"></a><a name="b978813281220"></a>emmc</strong> component, and file system type to <strong id="b12788132814217"><a name="b12788132814217"></a><a name="b12788132814217"></a>vfat</strong>.</p>
    <p id="p12481832163913"><a name="p12481832163913"></a><a name="p12481832163913"></a><strong id="b965011165313"><a name="b965011165313"></a><a name="b965011165313"></a>rootaddr=10M rootsize=20M rw</strong> indicates the start address and size of the <strong id="b1538675832018"><a name="b1538675832018"></a><a name="b1538675832018"></a>rootfs.img</strong> file to be burnt, respectively. The file size <strong id="b0633135515546"><a name="b0633135515546"></a><a name="b0633135515546"></a>must be the same</strong> as that of the <strong id="b69061726113015"><a name="b69061726113015"></a><a name="b69061726113015"></a>rootfs.img</strong> file in the IDE.</p>
    </td>
    </tr>
    <tr id="row18234161153820"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p823417118386"><a name="p823417118386"></a><a name="p823417118386"></a>saveenv</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p32341616389"><a name="p32341616389"></a><a name="p32341616389"></a><strong id="b16238195319315"><a name="b16238195319315"></a><a name="b16238195319315"></a>saveenv</strong> means to save the current configuration.</p>
    </td>
    </tr>
    <tr id="row192345113811"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7235111183819"><a name="p7235111183819"></a><a name="p7235111183819"></a>reset</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p123781411114016"><a name="p123781411114016"></a><a name="p123781411114016"></a><strong id="b32719232420"><a name="b32719232420"></a><a name="b32719232420"></a>reset</strong> means to reset the board.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
    >**go 0x80000000**  \(optional\) indicates that the command is fixed in the startup parameters by default and the board automatically starts after it is reset. If you want to manually start the board, press  **Enter**  in the countdown phase of the U-Boot startup to interrupt the automatic startup.

3.  <a name="ld26f18828aa44c36bfa36be150e60e49"></a>Run the  **reset**  command and press  **Enter**  to restart the board. After the board is restarted,  **OHOS**  is displayed when you press  **Enter**.

    **Figure  3**  System startup<a name="fig784813366444"></a>  
    ![](figure/system-startup.png "system-startup")


## Running a Program<a name="section5276734182615"></a>

In the root directory, run the  **./bin/helloworld**  command to operate the demo program. The compilation result is shown in the following example.

**Figure  4**  Successful system startup and program execution<a name="fig149821431194515"></a>  
![](figure/successful-system-startup-and-program-execution.png "successful-system-startup-and-program-execution")

