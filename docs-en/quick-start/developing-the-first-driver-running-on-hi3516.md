# Developing the First Driver Running on Hi3516<a name="EN-US_TOPIC_0000001054448621"></a>

-   [Acquiring Source Code](#section0598122434810)
-   [Introduction to Driver](#s8efc1952ebfe4d1ea717182e108c29bb)
-   [Compiling and Burning](#section660016185110)
-   [Running an Image](#section197971119142915)
-   [Follow-up Learning](#section9712145420182)

This section describes how to develop a driver on the board, including introduction, compilation, burning, and running of the driver.

## Acquiring Source Code<a name="section0598122434810"></a>

Acquire the source code by referring to  [Acquiring Source Code](developing-the-first-example-program-running-on-hi3516.md#section215953714245).

## Introduction to Driver<a name="s8efc1952ebfe4d1ea717182e108c29bb"></a>

The following operations take a HDF-based UART driver as an example to show how to add configuration files, code the driver, and compile the code for interactions between the user-space applications and the driver. The driver source code is stored in the  **vendor/huawei/hdf/sample**  directory.

1.  Add Configurations.

    Add driver configurations to the HDF driver configuration file \(for example,  **vendor/hisi/hi35xx/hi3516dv300/config/uart/uart\_config.hcs**\).

    ```
    root {
        platform {
            uart_sample {
                num = 5;            // UART device number
                base = 0x120a0000;  // Base address of the UART register
                irqNum = 38;
                baudrate = 115200;
                uartClk = 24000000;
                wlen = 0x60;
                parity = 0;
                stopBit = 0;
                match_attr = "sample_uart_5";
            }
        }
    }
    ```

    Add the device node information to the HDF device configuration file \(for example,  **vendor/hisi/hi35xx/hi3516dv300/config/device\_info/device\_info.hcs**\)

    ```
    root {
        device_info {
            platform :: host {
                hostName = "platform_host";
                priority = 50;
                device_uart :: device {
                    device5 :: deviceNode {
                        policy = 2;
                        priority = 10;
                        permission = 0660;
                        moduleName = "UART_SAMPLE";
                        serviceName = "HDF_PLATFORM_UART_5";
                        deviceMatchAttr = "sample_uart_5";
                    }
                }
            }
        }
    }
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The configuration files are in the same path as the source code of the UART driver. You need to manually add the files to the path of the Hi3516DV300 development board.

2.  Register a UART driver entry.

    Register the  **HdfDriverEntry**  of the UART driver with the HDF.

    ```
    // Bind the UART driver interface to the HDF.
    static int32_t SampleUartDriverBind(struct HdfDeviceObject *device)
    {
        struct UartHost *uartHost = NULL;
    
        if (device == NULL) {
            return HDF_ERR_INVALID_OBJECT;
        }
        HDF_LOGI("Enter %s:", __func__);
    
        uartHost = UartHostCreate(device);
        if (uartHost == NULL) {
            HDF_LOGE("%s: UartHostCreate failed", __func__);
            return HDF_FAILURE;
        }
        uartHost->service.Dispatch = SampleDispatch;
        return HDF_SUCCESS;
    }
     
    // Obtain configuration information from the HCS of the UART driver.
    static uint32_t GetUartDeviceResource(
        struct UartDevice *device, const struct DeviceResourceNode *resourceNode)
    {
        struct UartResource *resource = &device->resource;
        struct DeviceResourceIface *dri = NULL;
        dri = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
        if (dri == NULL || dri->GetUint32 == NULL) {
            HDF_LOGE("DeviceResourceIface is invalid");
            return HDF_FAILURE;
        }
    
        if (dri->GetUint32(resourceNode, "num", &resource->num, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read num fail");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "base", &resource->base, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read base fail");
            return HDF_FAILURE;
        }
        resource->physBase = (unsigned long)OsalIoRemap(resource->base, 0x48);
        if (resource->physBase == 0) {
            HDF_LOGE("uart config fail to remap physBase");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "irqNum", &resource->irqNum, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read irqNum fail");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "baudrate", &resource->baudrate, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read baudrate fail");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "wlen", &resource->wlen, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read wlen fail");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "parity", &resource->parity, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read parity fail");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "stopBit", &resource->stopBit, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read stopBit fail");
            return HDF_FAILURE;
        }
        if (dri->GetUint32(resourceNode, "uartClk", &resource->uartClk, 0) != HDF_SUCCESS) {
            HDF_LOGE("uart config read uartClk fail");
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
     
    // Attach the configuration and interface of the UART driver to the HDF.
    static int32_t AttachUartDevice(struct UartHost *host, struct HdfDeviceObject *device)
    {
        int32_t ret;
        struct UartDevice *uartDevice = NULL;
        if (device->property == NULL) {
            HDF_LOGE("%s: property is NULL", __func__);
            return HDF_FAILURE;
        }
        uartDevice = (struct UartDevice *)OsalMemCalloc(sizeof(struct UartDevice));
        if (uartDevice == NULL) {
            HDF_LOGE("%s: OsalMemCalloc uartDevice error", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
        ret = GetUartDeviceResource(uartDevice, device->property);
        if (ret != HDF_SUCCESS) {
            (void)OsalMemFree(uartDevice);
            return HDF_FAILURE;
        }
        host->num = uartDevice->resource.num;
        host->priv = uartDevice;
        AddUartDevice(host);
        return InitUartDevice(uartDevice);
    }
     
    // Initialize the UART driver.
    static int32_t SampleUartDriverInit(struct HdfDeviceObject *device)
    {
        int32_t ret;
        struct UartHost *host = NULL;
    
        if (device == NULL) {
            HDF_LOGE("%s: device is NULL", __func__);
            return HDF_ERR_INVALID_OBJECT;
        }
        HDF_LOGI("Enter %s:", __func__);
        host = UartHostFromDevice(device);
        if (host == NULL) {
            HDF_LOGE("%s: host is NULL", __func__);
            return HDF_FAILURE;
        }
        ret = AttachUartDevice(host, device);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: attach error", __func__);
            return HDF_FAILURE;
        }
        host->method = &g_sampleUartHostMethod;
        return ret;
    }
     
    static void DeinitUartDevice(struct UartDevice *device)
    {
        struct UartRegisterMap *regMap = (struct UartRegisterMap *)device->resource.physBase;
        /* Wait for the UART to enter the idle state. */
        while (UartPl011IsBusy(regMap));
        UartPl011ResetRegisters(regMap);
        uart_clk_cfg(0, false);
        OsalIoUnmap((void *)device->resource.physBase);
        device->state = UART_DEVICE_UNINITIALIZED;
    }
     
    // Detach and release the UART driver.
    static void DetachUartDevice(struct UartHost *host)
    {
        struct UartDevice *uartDevice = NULL;
    
        if (host->priv == NULL) {
            HDF_LOGE("%s: invalid parameter", __func__);
            return;
        }
        uartDevice = host->priv;
        DeinitUartDevice(uartDevice);
        (void)OsalMemFree(uartDevice);
        host->priv = NULL;
    }
     
    // Release the UART driver.
    static void SampleUartDriverRelease(struct HdfDeviceObject *device)
    {
        struct UartHost *host = NULL;
        HDF_LOGI("Enter %s:", __func__);
    
        if (device == NULL) {
            HDF_LOGE("%s: device is NULL", __func__);
            return;
        }
        host = UartHostFromDevice(device);
        if (host == NULL) {
            HDF_LOGE("%s: host is NULL", __func__);
            return;
        }
        if (host->priv != NULL) {
            DetachUartDevice(host);
        }
        UartHostDestroy(host);
    }
     
    struct HdfDriverEntry g_sampleUartDriverEntry = {
        .moduleVersion = 1,
        .moduleName = "UART_SAMPLE",
        .Bind = SampleUartDriverBind,
        .Init = SampleUartDriverInit,
        .Release = SampleUartDriverRelease,
    };
     
    HDF_INIT(g_sampleUartDriverEntry);
    ```

3.  Register a UART driver interface.

    Implement the UART driver interface using the template  **UartHostMethod**  provided by the HDF.

    ```
    static int32_t SampleUartHostInit(struct UartHost *host)
    {
        HDF_LOGI("%s: Enter", __func__);
        if (host == NULL) {
            HDF_LOGE("%s: invalid parameter", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        return HDF_SUCCESS;
    }
    
    static int32_t SampleUartHostDeinit(struct UartHost *host)
    {
        HDF_LOGI("%s: Enter", __func__);
        if (host == NULL) {
            HDF_LOGE("%s: invalid parameter", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        return HDF_SUCCESS;
    }
    
    // Write data into the UART device.
    static int32_t SampleUartHostWrite(struct UartHost *host, uint8_t *data, uint32_t size)
    {
        HDF_LOGI("%s: Enter", __func__);
        uint32_t idx;
        struct UartRegisterMap *regMap = NULL;
        struct UartDevice *device = NULL;
    
        if (host == NULL || data == NULL || size == 0) {
            HDF_LOGE("%s: invalid parameter", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        device = (struct UartDevice *)host->priv;
        if (device == NULL) {
            HDF_LOGE("%s: device is NULL", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        regMap = (struct UartRegisterMap *)device->resource.physBase;
        for (idx = 0; idx < size; idx++) {
            UartPl011Write(regMap, data[idx]);
        }
        return HDF_SUCCESS;
    }
     
    // Set the baud rate for the UART device.
    static int32_t SampleUartHostSetBaud(struct UartHost *host, uint32_t baudRate)
    {
        HDF_LOGI("%s: Enter", __func__);
        struct UartDevice *device = NULL;
        struct UartRegisterMap *regMap = NULL;
        UartPl011Error err;
    
        if (host == NULL) {
            HDF_LOGE("%s: invalid parameter", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        device = (struct UartDevice *)host->priv;
        if (device == NULL) {
            HDF_LOGE("%s: device is NULL", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        regMap = (struct UartRegisterMap *)device->resource.physBase;
        if (device->state != UART_DEVICE_INITIALIZED) {
            return UART_PL011_ERR_NOT_INIT;
        }
        if (baudRate == 0) {
            return UART_PL011_ERR_INVALID_BAUD;
        }
        err = UartPl011SetBaudrate(regMap, device->uartClk, baudRate);
        if (err == UART_PL011_ERR_NONE) {
            device->baudrate = baudRate;
        }
        return err;
    }
     
    // Obtain the baud rate of the UART device.
    static int32_t SampleUartHostGetBaud(struct UartHost *host, uint32_t *baudRate)
    {
        HDF_LOGI("%s: Enter", __func__);
        struct UartDevice *device = NULL;
    
        if (host == NULL) {
            HDF_LOGE("%s: invalid parameter", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        device = (struct UartDevice *)host->priv;
        if (device == NULL) {
            HDF_LOGE("%s: device is NULL", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        *baudRate = device->baudrate;
        return HDF_SUCCESS;
    }
     
    // Bind the UART device using HdfUartSampleInit.
    struct UartHostMethod g_sampleUartHostMethod = {
        .Init = SampleUartHostInit,
        .Deinit = SampleUartHostDeinit,
        .Read = NULL,
        .Write = SampleUartHostWrite,
        .SetBaud = SampleUartHostSetBaud,
        .GetBaud = SampleUartHostGetBaud,
        .SetAttribute = NULL,
        .GetAttribute = NULL,
        .SetTransMode = NULL,
    };
    ```

    Add the sample module of the UART driver to the compilation script  **vendor/huawei/hdf/hdf\_vendor.mk**.

    ```
    LITEOS_BASELIB += -lhdf_uart_sample
    LIB_SUBDIRS    += $(VENDOR_HDF_DRIVERS_ROOT)/sample/platform/uart
    ```

4.  Implement the code for interaction between the user-space applications and driver.

    Create the  **/dev/uartdev-5**  node after the UART driver is initialized successfully. The following example shows how to interact with the UART driver through the node.

    ```
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include "hdf_log.h"
    
    #define HDF_LOG_TAG "hello_uart"
    #define INFO_SIZE 16
    
    int main(void)
    {
        int ret;
        int fd;
        const char info[INFO_SIZE] = {" HELLO UART! "};
    
        fd = open("/dev/uartdev-5", O_RDWR);
        if (fd < 0) {
            HDF_LOGE("hello_uart uartdev-5 open failed %d", fd);
            return -1;
        }
        ret = write(fd, info, INFO_SIZE);
        if (ret != 0) {
            HDF_LOGE("hello_uart write uartdev-5 ret is %d", ret);
        }
        ret = close(fd);
        if (ret != 0) {
            HDF_LOGE("hello_uart uartdev-5 close failed %d", fd);
            return -1;
        }
        return ret;
    }
    ```

    Add the  **hello\_uart\_sample**  component to the  **hdf**  subsystem directory in the  **build/lite/product/ipcamera\_hi3516dv300.json**  file.

    ```
    {
      "subsystem": [
        {
          "name": "hdf",
          "component": [
            { "name": "hdf_sample", "dir": "//vendor/huawei/hdf/sample/platform/uart:hello_uart_sample", "features":[] }
          ]
        }
      ]
    }
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >Preceding code snippets are for reference only. You can view the complete sample code in  **vendor/huawei/hdf/sample.**
    >The sample code is not automatically compiled by default. You can add it to the compilation script.


## Compiling and Burning<a name="section660016185110"></a>

Compile and burn images by referring to  [Compiling Code](developing-the-first-example-program-running-on-hi3516.md#section1077671315253)  and  [Burning](developing-the-first-example-program-running-on-hi3516.md#section08153912587).

## Running an Image<a name="section197971119142915"></a>

1.  Connect to a serial port.

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >If the connection fails, rectify the fault by referring to  [What should I do when no command output is displayed?](faqs-1.md#section14871149155911).

    **Figure  1**  Serial port connection<a name="en-us_topic_0000001052906247_fig056645018495"></a>  
    

    ![](figures/chuankou1.png)

    1.  Click  **Serial port**  to enable it.
    2.  Enter the serial port number queried in the "Burning" section \(COM11 is used in this example\) and press  **Enter**  until  **hisillicon**  is displayed.
    3.  Go to step  [2](developing-the-first-example-program-running-on-hi3516.md#l5b42e79a33ea4d35982b78a22913b0b1)  if the board is started for the first time or the startup parameters need to be modified; go to step  [3](developing-the-first-example-program-running-on-hi3516.md#ld26f18828aa44c36bfa36be150e60e49)  otherwise.

2.  \(Mandatory when the board is started for the first time\) Modify the bootcmd and bootargs parameters of U-boot. You need to perform this step only once if the parameters need not to be modified during the operation. The board automatically starts after it is reset.

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >The default waiting time in the U-boot is 2s. You can press  **Enter**  to interrupt the waiting and run the  **reset**  command to restart the system after "hisillicon" is displayed.

    **Table  1**  Parameters of the U-boot

    <a name="en-us_topic_0000001052906247_table1323441103813"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001052906247_row1423410183818"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001052906247_p623461163818"><a name="en-us_topic_0000001052906247_p623461163818"></a><a name="en-us_topic_0000001052906247_p623461163818"></a>Command</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001052906247_p42341014388"><a name="en-us_topic_0000001052906247_p42341014388"></a><a name="en-us_topic_0000001052906247_p42341014388"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001052906247_row1623471113817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001052906247_p102341719385"><a name="en-us_topic_0000001052906247_p102341719385"></a><a name="en-us_topic_0000001052906247_p102341719385"></a>setenv bootcmd "mmc read 0x0 0x80000000 0x800 0x4800; go 0x80000000";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001052906247_p92347120389"><a name="en-us_topic_0000001052906247_p92347120389"></a><a name="en-us_topic_0000001052906247_p92347120389"></a>Run this command to read content that has a size of 0x4800 (9 MB) and a start address of 0x800 (1 MB) to the memory address 0x80000000. The file size must be the same as that of the <strong id="en-us_topic_0000001052906247_b9140538191313"><a name="en-us_topic_0000001052906247_b9140538191313"></a><a name="en-us_topic_0000001052906247_b9140538191313"></a>OHOS_Image.bin</strong> file in the IDE.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001052906247_row12234912381"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001052906247_p172306219392"><a name="en-us_topic_0000001052906247_p172306219392"></a><a name="en-us_topic_0000001052906247_p172306219392"></a>setenv bootargs "console=ttyAMA0,115200n8 root=emmc fstype=vfat rootaddr=10 M rootsize=15 M rw";</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001052906247_p13489329396"><a name="en-us_topic_0000001052906247_p13489329396"></a><a name="en-us_topic_0000001052906247_p13489329396"></a>Run this command to set the output mode to serial port output, baud rate to <strong id="en-us_topic_0000001052906247_b1378372812210"><a name="en-us_topic_0000001052906247_b1378372812210"></a><a name="en-us_topic_0000001052906247_b1378372812210"></a>115200</strong>, data bit to <strong id="en-us_topic_0000001052906247_b27871628822"><a name="en-us_topic_0000001052906247_b27871628822"></a><a name="en-us_topic_0000001052906247_b27871628822"></a>8</strong>, <strong id="en-us_topic_0000001052906247_b678811281528"><a name="en-us_topic_0000001052906247_b678811281528"></a><a name="en-us_topic_0000001052906247_b678811281528"></a>rootfs</strong> to be mounted to the <strong id="en-us_topic_0000001052906247_b978813281220"><a name="en-us_topic_0000001052906247_b978813281220"></a><a name="en-us_topic_0000001052906247_b978813281220"></a>emmc</strong> component, and file system type to <strong id="en-us_topic_0000001052906247_b12788132814217"><a name="en-us_topic_0000001052906247_b12788132814217"></a><a name="en-us_topic_0000001052906247_b12788132814217"></a>vfat</strong>.</p>
    <p id="en-us_topic_0000001052906247_p12481832163913"><a name="en-us_topic_0000001052906247_p12481832163913"></a><a name="en-us_topic_0000001052906247_p12481832163913"></a><strong id="en-us_topic_0000001052906247_b965011165313"><a name="en-us_topic_0000001052906247_b965011165313"></a><a name="en-us_topic_0000001052906247_b965011165313"></a>rootaddr=10 M, rootsize=15 M rw</strong> indicates the start address and size of the rootfs.img file to be burnt, respectively. The file size must be the same as that of the <strong id="en-us_topic_0000001052906247_b69061726113015"><a name="en-us_topic_0000001052906247_b69061726113015"></a><a name="en-us_topic_0000001052906247_b69061726113015"></a>rootfs.img</strong> file in the IDE.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001052906247_row18234161153820"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001052906247_p823417118386"><a name="en-us_topic_0000001052906247_p823417118386"></a><a name="en-us_topic_0000001052906247_p823417118386"></a>saveenv</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001052906247_p32341616389"><a name="en-us_topic_0000001052906247_p32341616389"></a><a name="en-us_topic_0000001052906247_p32341616389"></a><strong id="en-us_topic_0000001052906247_b16238195319315"><a name="en-us_topic_0000001052906247_b16238195319315"></a><a name="en-us_topic_0000001052906247_b16238195319315"></a>saveenv</strong> means to save the current configuration.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001052906247_row192345113811"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001052906247_p7235111183819"><a name="en-us_topic_0000001052906247_p7235111183819"></a><a name="en-us_topic_0000001052906247_p7235111183819"></a>reset</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001052906247_p123781411114016"><a name="en-us_topic_0000001052906247_p123781411114016"></a><a name="en-us_topic_0000001052906247_p123781411114016"></a><strong id="en-us_topic_0000001052906247_b32719232420"><a name="en-us_topic_0000001052906247_b32719232420"></a><a name="en-us_topic_0000001052906247_b32719232420"></a>reset</strong> means to reset the board.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](public_sys-resources/icon-notice.gif) **NOTICE:** 
    >**go 0x80000000**  \(optional\) indicates that the command is fixed in the startup parameters by default and the board automatically starts after it is reset. If you want to manually start the board, press  **Enter**  in the countdown phase of the U-boot startup to interrupt the automatic startup.

3.  Run the  **reset**  command and press  **Enter**  to restart the board. After the board is restarted,  **OHOS**  is displayed when you press  **Enter**.

    **Figure  2**  System startup<a name="en-us_topic_0000001052906247_fig10181006376"></a>  
    

    ![](figures/qi1.png)

4.  In the root directory, run the  **./bin/hello\_uart**  command line to execute the demo program. The compilation result is shown in the following example.

    ```
    OHOS # ./bin/hello_uart
    OHOS #  HELLO UART!
    ```


## Follow-up Learning<a name="section9712145420182"></a>

Congratulations! You have finished all steps! You are advised to go on learning how to develop  [Cameras with a Screen](../guide/screen-and-camera-control.md).

