# Device Driver Porting<a name="EN-US_TOPIC_0000001200252097"></a>

This section describes how to port device drivers.

## LCD Driver Porting<a name="section1574513454119"></a>

To port an LCD driver, write the driver, create an instance of the corresponding model in the driver, and complete the registration.

The LCD drivers are stored in  **//drivers/framework/model/display/driver/panel**.

1.  Create a panel driver.

    Create an HDF driver and call the  **RegisterPanel**  method to register a model instance during driver initialization.

    ```
    int32_t LCDxxEntryInit(struct HdfDeviceObject *object)
    {
        struct PanelData *panel = CreateYourPanel();
        // Register a model instance.
        if (RegisterPanel(panel) != HDF_SUCCESS) {
            HDF_LOGE("%s: RegisterPanel failed", __func__);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    
    struct HdfDriverEntry g_xxxxDevEntry = {
        .moduleVersion = 1,
        .moduleName = "LCD_XXXX",
        .Init = LCDxxEntryInit,
    };
    
    HDF_INIT(g_xxxxDevEntry);
    ```

2.  Configure and load the panel driver.

    Modify the source code file  **//vendor/vendor\_name/product\_name/config/device\_info/device\_info.hcs**. Add configurations for the device named  **device\_lcd**  for the display host.

    >![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
    >Make sure the value of  **moduleName**  is the same as that of  **moduleName**  in the panel driver.

    ```
    root {
        ...
        display :: host {
            device_lcd :: device {
                    deviceN :: deviceNode {
                        policy = 0;
                        priority = 100;
                        preload = 2;
                        moduleName = "LCD_XXXX";
                    }
            }
        }
    }
    ```


## Touchscreen Driver Porting<a name="section20284142116422"></a>

This section describes how to port a touchscreen driver. The touchscreen drivers are stored in the source code directory  **//drivers/framework/model/input/driver/touchscreen**. To port a touchscreen driver, register a  **ChipDevice**  model instance with the system.

For details about how to develop a touchscreen driver, see  [Touchscreen Development Guidelines](../driver/driver-peripherals-touch-des.md).

1.  Create a touchscreen driver.

    Create the  **touch\_ic\_name.c**  file in the  **touchscreen**  directory. Write the following content:

    ```
    #include "hdf_touch.h"
    
    static int32_t HdfXXXXChipInit(struct HdfDeviceObject *device)
    {
        ChipDevice *tpImpl = CreateXXXXTpImpl();
        if(RegisterChipDevice(tpImpl) != HDF_SUCCESS) {// Register the ChipDevice model instance.
            ReleaseXXXXTpImpl(tpImpl);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    
    struct HdfDriverEntry g_touchXXXXChipEntry = {
        .moduleVersion = 1,
        .moduleName = "HDF_TOUCH_XXXX", // Make sure the value is the same as that in the subsequent configuration.
        .Init = HdfXXXXChipInit,
    };
    
    HDF_INIT(g_touchXXXXChipEntry);
    ```

    The following methods need to be implemented in  **ChipDevice**:

    <a name="table63781245516"></a>
    <table><thead align="left"><tr id="row1639713218557"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p53981829557"><a name="p53981829557"></a><a name="p53981829557"></a>Method</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p739811218557"><a name="p739811218557"></a><a name="p739811218557"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row113981214559"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p339813214552"><a name="p339813214552"></a><a name="p339813214552"></a>int32_t (*Init)(ChipDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139810214552"><a name="p1139810214552"></a><a name="p1139810214552"></a>Initializes the device.</p>
    </td>
    </tr>
    <tr id="row15398122145511"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139820212557"><a name="p1139820212557"></a><a name="p1139820212557"></a>int32_t (*Detect)(ChipDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939820217555"><a name="p939820217555"></a><a name="p939820217555"></a>Detects the device.</p>
    </td>
    </tr>
    <tr id="row183981216550"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p8398142165517"><a name="p8398142165517"></a><a name="p8398142165517"></a>int32_t (*Suspend)(ChipDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p539815218558"><a name="p539815218558"></a><a name="p539815218558"></a>Places the device in sleep mode.</p>
    </td>
    </tr>
    <tr id="row1239842115519"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43981295511"><a name="p43981295511"></a><a name="p43981295511"></a>int32_t (*Resume)(ChipDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p173985245515"><a name="p173985245515"></a><a name="p173985245515"></a>Wakes up the device.</p>
    </td>
    </tr>
    <tr id="row5398326559"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p103981324554"><a name="p103981324554"></a><a name="p103981324554"></a>int32_t (*DataHandle)(ChipDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93980212554"><a name="p93980212554"></a><a name="p93980212554"></a>Reads data from the device and writes touch point data to <strong id="b576475914217"><a name="b576475914217"></a><a name="b576475914217"></a>device</strong> &gt; <strong id="b976511597218"><a name="b976511597218"></a><a name="b976511597218"></a>driver</strong> &gt; <strong id="b117661559162110"><a name="b117661559162110"></a><a name="b117661559162110"></a>frameData</strong>.</p>
    </td>
    </tr>
    <tr id="row03987215550"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1039814295515"><a name="p1039814295515"></a><a name="p1039814295515"></a>int32_t (*UpdateFirmware)(ChipDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18398102105520"><a name="p18398102105520"></a><a name="p18398102105520"></a>Updates the firmware.</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  Configure the product and load the driver.

    All device information of the product is defined in the source code file  **//vendor/vendor\_name/product\_name/config/device\_info/device\_info.hcs**. Modify the file and add configurations to the  **device**  named  **device\_touch\_chip**  in the  **host**  of the  **input**  command.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Make sure the value of  **moduleName**  is the same as that of  **moduleName**  in the touchscreen driver.

    ```
                    deviceN :: deviceNode {
                        policy = 0;
                        priority = 130;
                        preload = 0;
                        permission = 0660;
                        moduleName = "HDF_TOUCH_XXXX";
                        deviceMatchAttr = "touch_XXXX_configs";
                    }
    ```


## WLAN Driver Porting<a name="section0969448164217"></a>

The WLAN driver is divided into two parts. One of the parts manages WLAN devices, and the other part manages WLAN traffic.

**Figure 1**  OpenHarmony WLAN driver architecture<a name="fig155920160203"></a>  


![](figure/hdf_wifi.png)

As shown in  [Figure 1](#fig155920160203), the part on the left manages WLAN devices, and the part on the right manages WLAN traffic. The HDF WLAN framework abstracts these two parts. The porting process of the driver can be considered as the implementation of the APIs required by the two parts. These APIs are described as follows:

<a name="table1349145511213"></a>
<table><thead align="left"><tr id="row867115517211"><th class="cellrowborder" valign="top" width="17.28172817281728%" id="mcps1.1.4.1.1"><p id="p667255120"><a name="p667255120"></a><a name="p667255120"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="39.48394839483948%" id="mcps1.1.4.1.2"><p id="p9672551125"><a name="p9672551125"></a><a name="p9672551125"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="43.23432343234324%" id="mcps1.1.4.1.3"><p id="p166785515214"><a name="p166785515214"></a><a name="p166785515214"></a>API Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16671955128"><td class="cellrowborder" valign="top" width="17.28172817281728%" headers="mcps1.1.4.1.1 "><p id="p86712551023"><a name="p86712551023"></a><a name="p86712551023"></a>HdfChipDriverFactory</p>
</td>
<td class="cellrowborder" valign="top" width="39.48394839483948%" headers="mcps1.1.4.1.2 "><p id="p10671551126"><a name="p10671551126"></a><a name="p10671551126"></a>drivers\framework\include\wifi\hdf_wlan_chipdriver_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="43.23432343234324%" headers="mcps1.1.4.1.3 "><p id="p26725514220"><a name="p26725514220"></a><a name="p26725514220"></a>Factory of the <strong id="b88841282246"><a name="b88841282246"></a><a name="b88841282246"></a>ChipDriver</strong>, which is used to support multiple WLAN interfaces of a chip.</p>
</td>
</tr>
<tr id="row186810552214"><td class="cellrowborder" valign="top" width="17.28172817281728%" headers="mcps1.1.4.1.1 "><p id="p11686551323"><a name="p11686551323"></a><a name="p11686551323"></a>HdfChipDriver</p>
</td>
<td class="cellrowborder" valign="top" width="39.48394839483948%" headers="mcps1.1.4.1.2 "><p id="p11686551723"><a name="p11686551723"></a><a name="p11686551723"></a>drivers\framework\include\wifi\wifi_module.h</p>
</td>
<td class="cellrowborder" valign="top" width="43.23432343234324%" headers="mcps1.1.4.1.3 "><p id="p26814555217"><a name="p26814555217"></a><a name="p26814555217"></a>Manages a specific WLAN interface.</p>
</td>
</tr>
<tr id="row13686559215"><td class="cellrowborder" valign="top" width="17.28172817281728%" headers="mcps1.1.4.1.1 "><p id="p76810555214"><a name="p76810555214"></a><a name="p76810555214"></a>NetDeviceInterFace</p>
</td>
<td class="cellrowborder" valign="top" width="39.48394839483948%" headers="mcps1.1.4.1.2 "><p id="p166818551825"><a name="p166818551825"></a><a name="p166818551825"></a>drivers\framework\include\wifi\net_device.h</p>
</td>
<td class="cellrowborder" valign="top" width="43.23432343234324%" headers="mcps1.1.4.1.3 "><p id="p368195513213"><a name="p368195513213"></a><a name="p368195513213"></a>Communicates with the protocol stack, such as sending data and setting the status of network interfaces.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>For details about the API development, see  [WLAN Development Guidelines](../driver/driver-peripherals-external-des.md).

The porting procedure is as follows:

1.  Create a WLAN chip driver.

    Create the  **hdf\_wlan\_chip\_name.c**  file in  **/device/vendor\_name/peripheral/wifi/chip\_name/**. The sample code is as follows:

    ```
    static int32_t HdfWlanHisiChipDriverInit(struct HdfDeviceObject *device) {
        static struct HdfChipDriverFactory factory = CreateChipDriverFactory(); // Implement the method.
        struct HdfChipDriverManager *driverMgr = HdfWlanGetChipDriverMgr();
        if (driverMgr->RegChipDriver(&factory) != HDF_SUCCESS) {// Register the driver factory.
            HDF_LOGE("%s fail: driverMgr is NULL!", __func__);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    
    struct HdfDriverEntry g_hdfXXXChipEntry = {
        .moduleVersion = 1,
        .Init = HdfWlanXXXChipDriverInit,
        .Release = HdfWlanXXXChipRelease,
        .moduleName = "HDF_WIFI_CHIP_XXX" // Make sure the name is the same as the configured one.
    };
    
    HDF_INIT(g_hdfXXXChipEntry);
    ```

    In the  **CreateChipDriverFactory**  method, create an object of the  **HdfChipDriverFactory**  type. This object provides the following methods:

    <a name="table8351533595"></a>
    <table><thead align="left"><tr id="row25693318916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p125683311913"><a name="p125683311913"></a><a name="p125683311913"></a>Method</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1656103318919"><a name="p1656103318919"></a><a name="p1656103318919"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15612331994"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p185663314920"><a name="p185663314920"></a><a name="p185663314920"></a>const char *driverName</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7563330917"><a name="p7563330917"></a><a name="p7563330917"></a>Indicates the driver name.</p>
    </td>
    </tr>
    <tr id="row20561733993"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13561331297"><a name="p13561331297"></a><a name="p13561331297"></a>int32_t (*InitChip)(struct HdfWlanDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756163312914"><a name="p756163312914"></a><a name="p756163312914"></a>Initializes the chip.</p>
    </td>
    </tr>
    <tr id="row155612337919"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p135633315917"><a name="p135633315917"></a><a name="p135633315917"></a>int32_t (*DeinitChip)(struct HdfWlanDevice *device)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3566331094"><a name="p3566331094"></a><a name="p3566331094"></a>Deinitializes the chip.</p>
    </td>
    </tr>
    <tr id="row18567337916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p157203315917"><a name="p157203315917"></a><a name="p157203315917"></a>void (*ReleaseFactory)(struct HdfChipDriverFactory *factory)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p165716331596"><a name="p165716331596"></a><a name="p165716331596"></a>Releases the <strong id="b17274134462416"><a name="b17274134462416"></a><a name="b17274134462416"></a>HdfChipDriverFactory</strong> object.</p>
    </td>
    </tr>
    <tr id="row1757143314912"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p105710331694"><a name="p105710331694"></a><a name="p105710331694"></a>struct HdfChipDriver *(*Build)(struct HdfWlanDevice *device, uint8_t ifIndex)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457143320911"><a name="p457143320911"></a><a name="p457143320911"></a>Creates an <strong id="b118260459243"><a name="b118260459243"></a><a name="b118260459243"></a>HdfChipDriver</strong>. In the input parameters, <strong id="b28271845162411"><a name="b28271845162411"></a><a name="b28271845162411"></a>device</strong> indicates the device information, and <strong id="b16827144519241"><a name="b16827144519241"></a><a name="b16827144519241"></a>ifIndex</strong> indicates the sequence number of this interface in the chip.</p>
    </td>
    </tr>
    <tr id="row1157153310912"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155714334917"><a name="p155714334917"></a><a name="p155714334917"></a>void (*Release)(struct HdfChipDriver *chipDriver)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95717338919"><a name="p95717338919"></a><a name="p95717338919"></a>Releases the chip driver.</p>
    </td>
    </tr>
    <tr id="row1157143313914"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p19571433993"><a name="p19571433993"></a><a name="p19571433993"></a>uint8_t (*GetMaxIFCount)(struct HdfChipDriverFactory *factory)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14571334915"><a name="p14571334915"></a><a name="p14571334915"></a>Obtains the maximum number of interfaces supported by the current chip.</p>
    </td>
    </tr>
    </tbody>
    </table>

    The  **Build**  method creates an  **HdfChipDriver**  object that manages the specified network interface. This object needs to provide the following methods:

    <a name="table16989183941017"></a>
    <table><thead align="left"><tr id="row61014406100"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p111094011015"><a name="p111094011015"></a><a name="p111094011015"></a>Method</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p11102040201014"><a name="p11102040201014"></a><a name="p11102040201014"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row111014409104"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p21084017106"><a name="p21084017106"></a><a name="p21084017106"></a>int32_t (*init)(struct HdfChipDriver *chipDriver, NetDevice *netDev)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310184012103"><a name="p1310184012103"></a><a name="p1310184012103"></a>Initializes the current network interface. The <strong id="b18435181416253"><a name="b18435181416253"></a><a name="b18435181416253"></a>NetDeviceInterFace</strong> needs to be provided for the <strong id="b1543511144251"><a name="b1543511144251"></a><a name="b1543511144251"></a>netDev</strong>.</p>
    </td>
    </tr>
    <tr id="row210840101012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71064031013"><a name="p71064031013"></a><a name="p71064031013"></a>int32_t (*deinit)(struct HdfChipDriver *chipDriver, NetDevice *netDev)</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p710144015101"><a name="p710144015101"></a><a name="p710144015101"></a>Deinitializes the current network interface.</p>
    </td>
    </tr>
    <tr id="row151094011100"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1910340171018"><a name="p1910340171018"></a><a name="p1910340171018"></a>struct HdfMac80211BaseOps *ops</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p31034071020"><a name="p31034071020"></a><a name="p31034071020"></a>Provides the WLAN basic capability interface set.</p>
    </td>
    </tr>
    <tr id="row91012407102"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191014051019"><a name="p191014051019"></a><a name="p191014051019"></a>struct HdfMac80211STAOps *staOps</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p810104013106"><a name="p810104013106"></a><a name="p810104013106"></a>Provides the interface set required for supporting the STA mode.</p>
    </td>
    </tr>
    <tr id="row17101840111020"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010204081015"><a name="p1010204081015"></a><a name="p1010204081015"></a>struct HdfMac80211APOps *apOps</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p710184013105"><a name="p710184013105"></a><a name="p710184013105"></a>Provides the interface set required for supporting the AP mode.</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  Create a configuration file to describe the chips supported by the driver.

    Create a chip configuration file in the product configuration directory and save it to the source code path  **//vendor/vendor\_name/product\_name/config/wifi/wlan\_chip\_chip\_name.hcs**.

    The sample code is as follows:

    ```
    root {
        wlan_config {
            chip_name :& chipList {
                chip_name :: chipInst {
                    match_attr = "hdf_wlan_chips_chip_name"; /* Indicates the configuration matching attribute, which is used to provide the configuration root of the driver.*/
                    driverName = "driverName"; /* Indicates the driver name, which must be the same as that of driverName in HdfChipDriverFactory.*/
                    sdio {
                        vendorId = 0xXXXX; /* your vendor id */
                        deviceId = [0xXXXX]; /*your supported devices */
                    }
                }
            }
        }
    }
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Replace the values of  **vendor\_name**,  **product\_name**, and  **chip\_name**  in the path and file with the actual names.
    >Set  **vendorId**  and  **deviceId**  to the actual vendor ID and chip ID, respectively.

3.  Edit the configuration file and load the driver.

    All device information of the product is defined in the source code file  **//vendor/vendor\_name/product\_name/config/device\_info/device\_info.hcs**. Modify the file and add configurations to the  **device**  named  **device\_wlan\_chips**  in the  **host**  of the  **network**  command. The sample code is as follows:

    ```
                    deviceN :: deviceNode {
                        policy = 0;
                        preload = 2;
                        moduleName = "HDF_WLAN_CHIPS";
                        deviceMatchAttr = "hdf_wlan_chips_chip_name";
                        serviceName = "driverName";
                    }
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Make sure the value of  **moduleName**  is the same as that of  **moduleName**  in the WLAN driver.

4.  Modify the  **Kconfig**  file to make the ported WLAN driver appear in the kernel configuration.

    Add configurations to  **device/vendor\_name/drivers/Kconfig**. The sample code is as follows:

    ```
    config DRIVERS_HDF_WIFI_chip_name
        bool "Enable chip_name Host driver"
        default n
        depends on DRIVERS_HDF_WLAN   help
          Answer Y to enable chip_name Host driver.
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Replace  **chip\_name**  with the actual chip name.

5.  Modify the build script to enable the driver to participate in the kernel build.

    Add the following content to the end of the source code file  **//device/vendor\_name/drivers/lite.mk**:

    ```
    ifeq ($(LOSCFG_DRIVERS_HDF_WIFI_chip_name), y)
        # After the build is complete, an object named hdf_wlan_chipdriver_chip_name needs to be linked. You are advised to use this name to prevent conflicts.
        LITEOS_BASELIB += -lhdf_wlan_chipdriver_chip_name
        # Add the build directory gpio.
        LIB_SUBDIRS    += ../peripheral/wifi/chip_name
    endif
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Replace  **chip\_name**  with the actual chip name.


