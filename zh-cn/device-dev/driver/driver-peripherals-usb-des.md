# USB

## 概述 

### 功能简介

USB（Universal Serial Bus）通用串行总线，包含了主机端（Host）和设备端（Device）。主机端负责USB总线中的数据传输及端口管理，设备端则可以连接各种外设，所以USB驱动开发又分为主机端驱动开发和设备端驱动开发。

OpenHarmony系统USB模块支持USB业务的开发，提供USB相关的功能，提供用户态第三方功能驱动的USB设备数据读写接口，以及提供创建和删除USB设备，接口的事件获取、打开和关闭等，管道同步异步读写通信，设置USB自定义属性等。

USB DDK（USB DriverDevelop Kit）是HDF驱动框架为开发者提供的USB驱动程序开发套件，包括USB Host DDK及USB Device DDK两部分，支持基于用户态开发USB设备驱动的同时，还提供了丰富的USB驱动开发能力，让广大开发者能精准且高效的开发USB驱动程序。

### 基本概念

- 管道

  管道（Pipe）是主机端和设备端点之间数据传输的模型。任何USB设备一旦上电就存在一个信息管道，即默认的控制管道，USB主机通过该管道来获取设备的描述、配置、状态，并对设备进行配置；管道和端点关联，两者有相同的属性，如支持的传输类型、最大包长度、传输方向等。

- 端点

  端点（Endpoint）是USB设备中的可以进行数据收发的最小单元，支持单向或者双向的数据传输。一个USB设备可以包括若干个端点，不同的端点以端点编号和方向区分。不同端点可以支持不同的传输类型、访问间隔以及最大数据包大小。除端点0外，所有的端点只支持一个方向的数据传输。端点0是一个特殊的端点，它支持双向的控制传输。

- 接口

  应用软件通过和设备之间的数据交换来完成设备的控制和数据传输。由于同一管道只支持一种类型的数据传输，因此这个过程中通常需要多个管道来完成数据交换。像这样用在一起来对设备进行控制的若干管道的集合称为接口。

- 描述符

  描述符（Descriptor）是用于描述设备属性（Attributes）的数据结构，第一个字节表示描述符的大小（字节数），第二个字节表示描述符的类型（Type）。

### 运作机制

#### USB Host DDK

USB Host DDK为开发者提供了主机端USB驱动开发能力，按照功能分为三大类，分别是DDK初始化类、interface对象操作类及request对象操作类。

  **图1** USB Host驱动模型图

  ![image](figures/USB-Host驱动模型图.png "USB-Host驱动模型图")

- USB Interface Pool负责USB Interface管理。提供USB Interface接口对象的申请和回收，USB Interface接口对象用来记录设备端口信息以及资源。USB Interface Pool按照USB Port对USB Interface进行分类管理。同时，此模块还提供了USB DDK API，方便开发者进行USB数据读写操作。

- USB Protocol Layer提供USB协议封装，根据USB协议对设备IO/控制命令进行翻译和解析”，同时负责设备描述符的管理，根据USB Device上报的枚举信息，匹配对应的描述符；构建对应的USB Interface接口对象，并将其加入到USB Interface Pool中管理。

- Device IO Manager负责USB IO请求管理，提供了同步IO和异步IO管理机制，对于异步IO，IO Manager负责将该请求记录下来，然后通过Raw API Library提供的接口依次处理待发送的IO请求；当收到USB控制器应答的处理结果后，IO接收线程负责解析并上报处理结果给上层调用者。

- Raw API Library抽象了底层OS能力，定义了统一的OS能力接口，对外提供了USB RAW API，方便开发者实现更加复杂的驱动功能。

- OS Adapter用于封装与平台（Linux和LiteOS）相关的操作，根据不同平台配置编译对应平台的封装接口。在Linux平台上，访问USB FS的操作，全部都封装在这个模块中；而在LiteOS平台上，基于FreeBSD USB框架的设备访问操作，也都全部封装在这个模块中。

- PNP Notify用于动态监测USB状态变化，当有新设备添加/移除时，变化设备信息。同时将所有USB设备信息都通过KHDF上报给UHDF侧的PNP Notify Manager模块来完成加载/卸载第三方功能驱动。

#### USB Device DDK

USB Device DDK向开发者提供了设备端USB驱动开发能力。例如，USB端口动态注册和去注册能力，开发者可以基于能力实现USB端口的动态添加和组合；动态实例化能力，支持根据动态下发设备、配置、接口及端点描述符创建设备实例及传输通道；用户态的数据发送及接收能力，支持用户态下发送及接收数据；复合设备能力，支持一个物理设备上多个逻辑设备，实现多个逻辑设备间隔离，并支持不同逻辑设备同时被不同的应用进程访问。

  **图2** USB Device驱动模型图

  ![image](figures/USB-Device驱动模型图.png "USB-Device驱动模型图")

- SDK IF负责将USB设备按照设备、接口、管道进行逻辑划分，对配置管理、设备管理、IO管理进行封装。此模块还向开发者提供了设备创建、获取接口、接收Event事件、收发数据等设备测驱动开发的能力接口。

- Configuration Manager负责解析HCS文件描述的USB描述符信息，得到的USB描述符信息用于设备创建，同时模块还提供了自定义属性的读取、创建、删除、修改等操作。

- Device Manager负责根据配置模块解析USB描述符，并根据USB描述符创建设备。同时还负责获取设备、删除设备、获取设备状态，获取设备上面接口信息。

- IO Manager负责数据的读写，包括Events事件、数据读写完成后事件的接收，支持同步和异步模式数据读写。

- Adapter IF主要是对复合设备配置驱动及通用功能驱动设备节点操作进行封装，为上层提供统一的设备管理接口。

- Adapter该模块由复合设备配置驱动及通用功能驱动提供。

## 开发指导

由于内核态开发USB驱动较复杂，需要开发者对USB协议要有较深的了解才能很好的使用，对开发者的要求相对较高。USB DDK的引入是为了让开发者能在用户态更方便的开发USB驱动。

### 场景介绍

USB Host DDK为开发者提供了普通模式和专家模式，普通模式下，开发者可通过USB DDK API直接完成相关USB数据读写操作，不需要过多关注底层的传输细节。专家模式下，开发者通过USB RAW API直接访问OS平台中USB通道的接口，自定义实现更加复杂的功能。USB Device DDk为开发者提供了管理USB设备、接口定义及USB数据请求等功能。下文将介绍相关API。

### 接口说明

USB主机端驱动程序开发相关接口（普通模式）如下，具体接口定义[见源码](https://gitee.com/openharmony/drivers_peripheral/blob/master/usb/interfaces/ddk/host/usb_ddk_interface.h)。

  **表1** USB主机端驱动程序开发相关接口（普通模式）

| 接口名称 | 功能描述 |
| -------- | -------- |
| int32_t&nbsp;UsbInitHostSdk(struct&nbsp;UsbSession&nbsp;\*\*session); | USB主机端驱动开发工具包初始化 |
| struct UsbInterface *UsbClaimInterface(const struct<br/> UsbSession *session, uint8_t busNum, uint8_t usbAddr, <br/>uint8_t interfaceIndex) | 获取USB接口对象 |
| UsbInterfaceHandle&nbsp;\*UsbOpenInterface(const&nbsp;struct<br/>UsbInterface&nbsp;\*interfaceObj); | 打开USB对象接口 |
| int32_t&nbsp;UsbGetPipeInfo(const&nbsp;UsbInterfaceHandle<br/>\*interfaceHandle,&nbsp;uint8_t&nbsp;settingIndex,&nbsp;uint8_t&nbsp;pipeId,<br/>struct&nbsp;UsbPipeInfo&nbsp;\*pipeInfo); | 获取指定可选设置的管道信息 |
| struct&nbsp;UsbRequest&nbsp;\*UsbAllocRequest(const<br/>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;int32_t&nbsp;isoPackets<br/>,&nbsp;int32_t&nbsp;length); | 分配请求对象 |
| int32_t&nbsp;UsbFillRequest(const&nbsp;struct&nbsp;UsbRequest<br/>\*request,&nbsp;const&nbsp;UsbInterfaceHandle&nbsp;\*interfaceHandle,<br/>const&nbsp;struct&nbsp;UsbRequestParams&nbsp;\*params); | 填充请求 |
| int32_t&nbsp;UsbSubmitRequestSync(const&nbsp;struct&nbsp;UsbRequest<br/>\*request); | 发送同步请求 |

USB主机端驱动程序开发相关接口（专家模式）如下，具体接口定义[见源码](https://gitee.com/openharmony/drivers_peripheral/blob/master/usb/interfaces/ddk/host/usb_raw_api.h)。

  **表2** USB主机端驱动程序开发相关接口（专家模式）

| 接口名称 | 功能描述 |
| -------- | -------- |
| int32_t&nbsp;UsbRawInit(struct&nbsp;UsbSession&nbsp;\*\*session); | USB驱动开发工具包专家模式初始化 |
| UsbRawHandle&nbsp;\*UsbRawOpenDevice(const&nbsp;struct<br/>UsbSession&nbsp;\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t<br/>usbAddr); | 打开USB设备对象 |
| int32_t&nbsp;UsbRawSendControlRequest(const&nbsp;struct<br/>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbControlRequestData<br/>\*requestData); | 执行同步控制传输 |
| int32_t&nbsp;UsbRawSendBulkRequest(const&nbsp;struct<br/>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbRequestData<br/>\*requestData); | 执行同步批量传输 |
| int32_t&nbsp;UsbRawSendInterruptRequest(const&nbsp;struct<br/>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbRequestData<br/>\*requestData); | 执行同步中断传输 |
| int32_t&nbsp;UsbRawGetConfigDescriptor(const&nbsp;UsbRawDevice<br/>\*rawDev,&nbsp;uint8_t&nbsp;configIndex,&nbsp;struct<br/>UsbRawConfigDescriptor&nbsp;\*\*config); | 获取给定设备指定ID的设备配置描述符 |
| int32_t&nbsp;UsbRawFillInterruptRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawFillRequestData&nbsp;\*fillData); | 填充中断传输请求所需信息 |
| int32_t&nbsp;UsbRawFillIsoRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawFillRequestData&nbsp;\*fillData); | 填充同步传输（Isochronous&nbsp;Transfers）请求所需信息 |
| int32_t&nbsp;UsbRawSubmitRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request); | 提交一个传输请求 |
| int32_t&nbsp;UsbRawCancelRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request); | 取消一个传输请求 |
| int32_t&nbsp;UsbRawHandleRequests(const&nbsp;UsbRawHandle<br/>\*devHandle); | 传输请求事件完成处理 |

USB设备端用于管理USB设备的相关接口如下，具体接口定义[见源码](https://gitee.com/openharmony/drivers_peripheral/blob/master/usb/interfaces/ddk/device/usbfn_device.h)。

  **表3** USB设备端用于管理USB设备的相关接口

| 接口名称 | 功能描述 |
| -------- | -------- |
| const&nbsp;struct&nbsp;UsbFnDevice&nbsp;\*UsbFnCreateDevice(const<br/>char&nbsp;\*udcName,&nbsp;const&nbsp;struct&nbsp;UsbFnDescriptorData<br/>\*descriptor); | 创建USB设备 |
| int32_t&nbsp;UsbFnRemoveDevice(struct&nbsp;UsbFnDevice<br/>\*fnDevice); | 删除USB设备 |
| const&nbsp;struct&nbsp;UsbFnDevice&nbsp;\*UsbFnGetDevice(const&nbsp;char<br/>\*udcName); | 获取USB设备 |

USB设备端用于USB接口定义的相关接口如下，具体接口定义[见源码](https://gitee.com/openharmony/drivers_peripheral/blob/master/usb/interfaces/ddk/device/usbfn_interface.h)。

  **表4** USB设备端用于USB接口定义的相关接口

| 接口名称 | 功能描述 |
| -------- | -------- |
| int32_t&nbsp;UsbFnStartRecvInterfaceEvent(struct<br/>UsbFnInterface&nbsp;\*interface,&nbsp;uint32_t&nbsp;eventMask,<br/>UsbFnEventCallback&nbsp;callback,&nbsp;void&nbsp;\*context); | 开始接受Event事件 |
| int32_t&nbsp;UsbFnStopRecvInterfaceEvent(struct<br/>UsbFnInterface&nbsp;\*interface); | 停止接受Event事件 |
| UsbFnInterfaceHandle&nbsp;UsbFnOpenInterface(struct&nbsp;UsbFnInterface&nbsp;\*interface); | 打开一个接口 |
| int32_t&nbsp;UsbFnCloseInterface(UsbFnInterfaceHandle&nbsp;handle); | 关闭一个接口 |
| int32_t&nbsp;UsbFnGetInterfacePipeInfo(struct&nbsp;UsbFnInterface<br/>\*interface,&nbsp;uint8_t&nbsp;pipeId,&nbsp;struct&nbsp;UsbFnPipeInfo&nbsp;\*info); | 获取管道信息 |
| int32_t&nbsp;UsbFnSetInterfaceProp(const&nbsp;struct&nbsp;UsbFnInterface<br/>\*interface,&nbsp;const&nbsp;char&nbsp;\*name,&nbsp;const&nbsp;char&nbsp;\*value); | 设置自定义属性 |

USB设备端用于管理USB数据请求的相关接口如下，具体接口定义[见源码](https://gitee.com/openharmony/drivers_peripheral/blob/master/usb/interfaces/ddk/device/usbfn_request.h)。

  **表5** USB设备端用于管理USB数据请求的相关接口

| 接口名称 | 功能描述 |
| -------- | -------- |
| struct&nbsp;UsbFnRequest<br/>\*UsbFnAllocCtrlRequest(UsbFnInterfaceHandle&nbsp;handle,<br/>uint32_t&nbsp;len); | 申请一个控制请求 |
| struct&nbsp;UsbFnRequest&nbsp;\*UsbFnAllocRequest(UsbFnInterfaceHandle&nbsp;handle,<br/>uint8_t&nbsp;pipe,&nbsp;uint32_t&nbsp;len); | 申请一个数据请求 |
| int32_t&nbsp;UsbFnFreeRequest(struct&nbsp;UsbFnRequest&nbsp;\*req); | 释放一个请求 |
| int32_t&nbsp;UsbFnSubmitRequestAsync(struct&nbsp;UsbFnRequest<br/>\*req); | 发送异步请求 |
| int32_t&nbsp;UsbFnSubmitRequestSync(struct&nbsp;UsbFnRequest<br/>\*req,&nbsp;uint32_t&nbsp;timeout); | 发送同步请求 |
| int32_t&nbsp;UsbFnCancelRequest(struct&nbsp;UsbFnRequest&nbsp;\*req); | 取消请求 |


### 开发步骤

USB驱动基于HDF框架、Platform和OSAL基础接口进行开发，不区分操作系统和芯片平台，为不同USB器件提供统一的驱动模型。此处以串口为例，分别介绍USB Host和USB Device驱动开发的详细过程。

#### Host DDK API驱动开发

1. 在设备私有数据HCS中配置，完成主机端驱动总体信息的配置，具体如下：

    ```cpp
    root {
        module = "usb_pnp_device";
        usb_pnp_config {
            match_attr = "usb_pnp_match";
            usb_pnp_device_id = "UsbPnpDeviceId";
            UsbPnpDeviceId {
                idTableList = [
                    "host_acm_table"
                ];
                host_acm_table {
                    // 驱动模块名，该字段的值必须和驱动入口结构的moduleName一致
                    moduleName = "usbhost_acm";
                    // 驱动对外发布服务的名称，必须唯一
                    serviceName = "usbhost_acm_pnp_service";
                    // 驱动私有数据匹配关键字
                    deviceMatchAttr = "usbhost_acm_pnp_matchAttr";
                    // 从该字段开始（包含该字段）之后数据长度，以byte为单位
                    length = 21;
                    // USB驱动匹配规则vendorId+productId+interfaceSubClass+interfaceProtocol+interfaceNumber
                    matchFlag = 0x0303;
                    // 厂商编号
                    vendorId = 0x12D1;
                    // 产品编号
                    productId = 0x5000;
                    // 设备出厂编号，低16位
                    bcdDeviceLow = 0x0000;
                    // 设备出厂编号，高16位
                    bcdDeviceHigh = 0x0000;
                    // USB分配的设备类代码
                    deviceClass = 0;
                    // USB分配的子类代码
                    deviceSubClass = 0;
                    // USB分配的设备协议代码
                    deviceProtocol = 0;
                    // 接口类型，根据实际需要可填写多个
                    interfaceClass = [0];
                    // 接口子类型，根据实际需要可填写多个
                    interfaceSubClass = [2, 0];
                    // 接口所遵循的协议，根据实际需要可填写多个    
                    interfaceProtocol = [1, 2];
                    // 接口的编号，根据实际需要可填写多个
                    interfaceNumber = [2, 3];
                }
            }
        }
    }
    ```

2. USB主机端驱动开发工具包初始化。

    ```cpp
    int32_t UsbInitHostSdk(struct UsbSession **session);
    ```

3. 步骤2初始化完后获取UsbInterface对象。

    ```cpp
    const struct UsbInterface *UsbClaimInterface(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr, uint8_t interfaceIndex);
    ```

4. 打开步骤3获取到的UsbInterface接口对象，获取相应接口的UsbInterfaceHandle对象。

    ```cpp
    UsbInterfaceHandle *UsbOpenInterface(const struct UsbInterface *interfaceObj);
    ```

5. 根据步骤4获取到的UsbInterfaceHandle对象，获取指定索引为pipeIndex的pipeInfo信息。

    ```cpp
    int32_t UsbGetPipeInfo(const UsbInterfaceHandle *interfaceHandle, uint8_t settingIndex, uint8_t pipeId, struct UsbPipeInfo *pipeInfo);
    ```

6. 为步骤4获取到的UsbInterfaceHandle预先分配待发送的IO Request对象。

    ```cpp
    struct UsbRequest *UsbAllocRequest(const UsbInterfaceHandle *interfaceHandle, int32_t isoPackets, int32_t length);
    ```

7. 根据输入参数params填充步骤6预先分配的IO Request。

    ```cpp
    int32_t UsbFillRequest(const struct UsbRequest *request, const UsbInterfaceHandle *interfaceHandle, const struct UsbRequestParams *params);
    ```

8. 提交IO Request对象，可以选择同步或异步两种模式。

    ```cpp
    int32_t UsbSubmitRequestSync(const struct UsbRequest *request); //发送同步IO请求
    int32_t UsbSubmitRequestAsync(const struct UsbRequest *request); //发送异步IO请求
    ```

#### Host RAW API驱动开发

1. 同Host DDK API的步骤1一样，在设备私有数据HCS中配置。

2. 初始化Host RAW，并打开USB设备，然后获取描述符，通过描述符获取接口、端点信息。

    ```cpp
    int32_t UsbRawInit(struct UsbSession **session);
    ```

3. 待步骤2完成后打开USB设备。

    ```cpp
    UsbRawHandle *UsbRawOpenDevice(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr);
    ```

4. 待步骤3完成后获取描述符，通过描述符获取接口、端点信息。

    ```cpp
    int32_t UsbRawGetConfigDescriptor(const UsbRawDevice *rawDev, uint8_t configIndex, struct UsbRawConfigDescriptor **config);
    ```

5. 分配Request，并根据传输类型使用相应接口对Request进行填充。

    ```cpp
    int32_t UsbRawFillBulkRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData); // 填充用于批量传输的请求
    int32_t UsbRawFillControlSetup(const unsigned char *setup, const struct UsbControlRequestData *requestData);
    int32_t UsbRawFillControlRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData); // 填充用于控制传输的请求
    int32_t UsbRawFillInterruptRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData); // 填充用于中断传输的请求
    int32_t UsbRawFillIsoRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData); // 填充用于同步传输的请求
    ```

6. 提交IO Request对象，可以选择同步或异步两种模式。

    ```cpp
    int32_t UsbRawSendControlRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbControlRequestData *requestData); //发送同步USB控制传输请求
    int32_t UsbRawSendBulkRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRequestData *requestData); //发送同步USB批量传输请求
    int32_t UsbRawSendInterruptRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRequestData *requestData); //发送同步执行USB中断传输请求
    int32_t UsbRawSubmitRequest(const struct UsbRawRequest *request); //提交异步IO请求
    ```

#### Device DDK API驱动开发

1. 在设备功能代码中构造描述符。

    ```cpp
    static struct UsbFnFunction g_acmFunction = {
        .funcName = "f_generic.a",                     //功能名称
        .strings = g_acmStrings,                       //字符串
        .fsDescriptors = g_acmFsFunction,              //初始化fs描述符
        .hsDescriptors = g_acmHsFunction,              //初始化hs描述符
        .ssDescriptors = g_acmSsFunction,              //初始化ss描述符
        .sspDescriptors = nullptr,                     //ss描述符置空
    };
    struct UsbFnFunction *g_functions[] = {
    #ifdef CDC_ECM
        &g_ecmFunction,
    #endif
    #ifdef CDC_ACM
        &g_acmFunction,
    #endif
        nullptr};
    static struct UsbFnConfiguration g_masterConfig = { // 配置描述符
        .configurationValue = 1,
        .iConfiguration     = USB_FUNC_CONFIG_IDX,
        .attributes         = USB_CFG_BUS_POWERED,
        .maxPower           = POWER,
        .functions          = g_functions,
    };
    static struct UsbFnConfiguration *g_configs[] = {
        &g_masterConfig,
        nullptr,
    };
    static struct UsbDeviceDescriptor g_cdcUsbFnDeviceDesc = { // 设备描述符
        .bLength            = sizeof(g_cdcUsbFnDeviceDesc),
        .bDescriptorType    = USB_DDK_DT_DEVICE,
        .bcdUSB             = CpuToLe16(BCD_USB),
        .bDeviceClass       = 0,
        .bDeviceSubClass    = 0,
        .bDeviceProtocol    = 0,
        .bMaxPacketSize0    = USB_MAX_PACKET_SIZE,
        .idVendor           = CpuToLe16(DEVICE_VENDOR_ID),
        .idProduct          = CpuToLe16(DEVICE_PRODUCT_ID),
        .bcdDevice          = CpuToLe16(DEVICE_VERSION),
        .iManufacturer      = USB_FUNC_MANUFACTURER_IDX,
        .iProduct           = USB_FUNC_PRODUCT_IDX,
        .iSerialNumber      = USB_FUNC_SERIAL_IDX,
        .bNumConfigurations = 1,
    };
    struct UsbFnDeviceDesc g_acmFnDevice = { //描述符入口
        .deviceDesc = &g_cdcUsbFnDeviceDesc,
        .deviceStrings = g_devStrings,
        .configs = g_configs,
    };
    ```

2. 创建设备。描述符构造完成后，使用UsbFnDeviceCreate函数创建一个USB设备，并传入UDC控制器和UsbFnDescriptorData结构体。

    ```cpp
    if (useHcs == 0) { // 使用代码编写的描述符
        descData.type = USBFN_DESC_DATA_TYPE_DESC;
        descData.descriptor = &g_acmFnDevice;
    } else {             // 使用hcs编写的描述符
        devMgr->descData.type = USBFN_DESC_DATA_TYPE_PROP;
        devMgr->descData.property = device->property;
    }
    // 创建设备
    fnDev = (struct UsbFnDevice *)UsbFnCreateDevice(devMgr->udcName, &devMgr->descData);
    ```

3. 设备创建后，使用UsbFnGetInterface函数获取UsbInterface接口对象，并通过UsbFnGetInterfacePipeInfo函数获取USB管道信息。

    ```cpp
    // 获取接口
    fnIface = (struct UsbFnInterface *)UsbFnGetInterface(fnDev, i);
    // 获取Pipe信息
    UsbFnGetInterfacePipeInfo(fnIface, i, &pipeInfo);
    // 获取Handle
    handle = UsbFnOpenInterface(fnIface);
    // 获取控制（EP0）Request
    req = UsbFnAllocCtrlRequest(acmDevice->ctrlIface.handle, sizeof(struct UsbCdcLineCoding) + sizeof(struct UsbCdcLineCoding));
    // 获取Request
    req = UsbFnAllocCtrlRequest(acmDevice->ctrlIface.handle, sizeof(struct UsbCdcLineCoding) + sizeof(struct UsbCdcLineCoding));
    ```

4. 通过UsbFnStartRecvInterfaceEvent函数接收Event事件，并通过UsbFnEventCallback回调函数对Event事件做出响应。

    ```cpp
    // 开始接收Event事件
    ret = UsbFnStartRecvInterfaceEvent(acmDevice->ctrlIface.fn, 0xff, AcmEventCallback, acmDevice);
    // Event处理回调函数
    static void UsbAcmEventCallback(struct UsbFnEvent *event)
    {
        struct UsbAcmDevice *acm = NULL;
        if (event == NULL || event->context == NULL) {
            HDF_LOGE("%{public}s: event is null", __func__);
            return;
        }
        acm = (struct UsbAcmDevice *)event->context;
        switch (event->type) {
            case USBFN_STATE_BIND:
                HDF_LOGI("%{public}s: receive bind event", __func__);
                break;
            case USBFN_STATE_UNBIND:
                HDF_LOGI("%{public}s: receive unbind event", __func__);
                break;
            case USBFN_STATE_ENABLE:
                HDF_LOGI("%{public}s: receive enable event", __func__);
                AcmEnable(acm);
                break;
            case USBFN_STATE_DISABLE:
                HDF_LOGI("%{public}s: receive disable event", __func__);
                AcmDisable(acm);
                acm->enableEvtCnt = 0;
                break;
            case USBFN_STATE_SETUP:
                HDF_LOGI("%{public}s: receive setup event", __func__);
                if (event->setup != NULL) {
                    AcmSetup(acm, event->setup);
                }
                break;
            case USBFN_STATE_SUSPEND:
                HDF_LOGI("%{public}s: receive suspend event", __func__);
                AcmSuspend(acm);
                break;
            case USBFN_STATE_RESUME:
                HDF_LOGI("%{public}s: receive resume event", __func__);
                AcmResume(acm);
                break;
            default:
                break;
        }
    }
    ```

5. 收发数据，可以选择同步异步发送模式。

    ```cpp
    notify = (struct UsbCdcNotification *)req->buf;
    ...
    ret = memcpy_s((void *)(notify + 1), length, data, length);
    if (ret != EOK) {
        HDF_LOGE("%s: memcpy_s failed", __func__);
        return HDF_FAILURE;
    }
    ret = UsbFnSubmitRequestAsync(req); // 异步发送
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: send notify request failed", __func__);
        acm->notifyReq = req;
    } 
    ```

### 开发实例

本实例提供USB串口驱动开发示例，并简要对具体关键点进行开发说明。

#### Host DDK API驱动开发

```cpp
#include "usb_serial.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "hdf_usb_pnp_manage.h"
#include "osal_mem.h"
#include "osal_time.h"
#include "securec.h"
#include "usb_ddk_interface.h"

#define HDF_LOG_TAG USB_HOST_ACM
#define STR_LEN     512

static struct UsbRequest *g_syncRequest = NULL;  // 定义一个USB请求
static struct UsbRequest *g_ctrlCmdRequest = NULL;
static bool g_acmReleaseFlag = false;
static uint8_t *g_acmReadBuffer = NULL;
...
static int32_t SerialCtrlMsg(struct AcmDevice *acm, uint8_t request, uint16_t value, void *buf, uint16_t len)
{
    int32_t ret;
    if (acm == NULL || buf == NULL || acm->intPipe == NULL) {
        HDF_LOGE("%s:invalid param", __func__);
        return HDF_ERR_IO;
    }
    uint16_t index = acm->intPipe->interfaceId;
    struct UsbControlParams controlParams = {};
    struct UsbRequestParams parmas = {}; // 定义一个USB请求参数对象
    if (acm->ctrlReq == NULL) {
        // 为获取到的UsbInterfaceHandle预先分配待发送的IO Request对象
        acm->ctrlReq = UsbAllocRequest(acm->ctrDevHandle, 0, len);
        if (acm->ctrlReq == NULL) {
            HDF_LOGE("%s: UsbAllocRequest failed", __func__);
            return HDF_ERR_IO;
        }
    }

    controlParams.request = request;
    controlParams.target = USB_REQUEST_TARGET_INTERFACE; // 接口对象
    controlParams.reqType = USB_REQUEST_TYPE_CLASS; // 请求类型
    controlParams.directon = USB_REQUEST_DIR_TO_DEVICE; // 从主机到设备的数据传输
    controlParams.value = value;
    controlParams.index = index;
    controlParams.data = buf;
    controlParams.size = len;

    parmas.interfaceId = USB_CTRL_INTERFACE_ID; // 定义USB控制接口的默认ID
    if (acm->ctrPipe != NULL) {
        parmas.pipeAddress = acm->ctrPipe->pipeAddress; 
        parmas.pipeId = acm->ctrPipe->pipeId;
    }
    parmas.requestType = USB_REQUEST_PARAMS_CTRL_TYPE; // 控制类型
    parmas.timeout = USB_CTRL_SET_TIMEOUT; // 设置超时时间
    parmas.ctrlReq = UsbControlSetUp(&controlParams);
    parmas.callback = NULL;
    // 根据params填充预先分配的IO Request
    ret = UsbFillRequest(acm->ctrlReq, acm->ctrDevHandle, &parmas);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: UsbFillRequest failed, ret = %d ", __func__, ret);
        return ret;
    }
    // 发送同步IO Request
    ret = UsbSubmitRequestSync(acm->ctrlReq);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("UsbSubmitRequestSync failed, ret = %d ", ret);
        return ret;
    }
    if (!acm->ctrlReq->compInfo.status) {
        HDF_LOGE("%s  status=%d ", __func__, acm->ctrlReq->compInfo.status);
    }
    return HDF_SUCCESS;
}
...
static struct UsbInterface *GetUsbInterfaceById(const struct AcmDevice *acm, uint8_t interfaceIndex)
{
    // 获取UsbInterface接口对象
    return UsbClaimInterface(acm->session, acm->busNum, acm->devAddr, interfaceIndex);
}
...
static struct UsbPipeInfo *EnumePipe(
    const struct AcmDevice *acm, uint8_t interfaceIndex, UsbPipeType pipeType, UsbPipeDirection pipeDirection)
{
    struct UsbInterfaceInfo *info = NULL; // 定义一个USB接口信息对象
    UsbInterfaceHandle *interfaceHandle = NULL; // 定义一个USB接口操作句柄，就是void *类型
    if (pipeType == USB_PIPE_TYPE_CONTROL) {
        info = &acm->ctrIface->info;
        interfaceHandle = acm->ctrDevHandle;
    } else {
        // 根据interfaceIndex获取设备句柄
        info = &acm->iface[interfaceIndex]->info;
        interfaceHandle = InterfaceIdToHandle(acm, info->interfaceIndex);
    }

    for (uint8_t i = 0; i <= info->pipeNum; i++) {
        struct UsbPipeInfo p;
        // 获取指定索引为i的pipeInfo信息
        int32_t ret = UsbGetPipeInfo(interfaceHandle, info->curAltSetting, i, &p);
        if (ret < 0) {
            continue;
        }
        if ((p.pipeDirection == pipeDirection) && (p.pipeType == pipeType)) {
            struct UsbPipeInfo *pi = OsalMemCalloc(sizeof(*pi)); // 开辟内存并初始化
            if (pi == NULL) {
                HDF_LOGE("%s: Alloc pipe failed", __func__);
                return NULL;
            }
            p.interfaceId = info->interfaceIndex;
            *pi = p;
            return pi;
        }
    }
    return NULL;
}

static struct UsbPipeInfo *GetPipe(const struct AcmDevice *acm, UsbPipeType pipeType, UsbPipeDirection pipeDirection)
{
    uint8_t i;
    if (acm == NULL) {
        HDF_LOGE("%s: invalid param", __func__);
        return NULL;
    }
    for (i = 0; i < acm->interfaceCnt; i++) {
        struct UsbPipeInfo *p = NULL;
        if (!acm->iface[i]) {
            continue;
        }
        // 获取控制pipe的pipeInfo信息
        p = EnumePipe(acm, i, pipeType, pipeDirection);
        if (p == NULL) {
            continue;
        }
        return p;
    }
    return NULL;
}

/* HdfDriverEntry implementations */
static int32_t UsbSerialDriverBind(struct HdfDeviceObject *device)
{
    struct UsbPnpNotifyServiceInfo *info = NULL;
    errno_t err;
    struct AcmDevice *acm = NULL;
    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }
    //开辟内存空间
    acm = (struct AcmDevice *)OsalMemCalloc(sizeof(*acm));
    if (acm == NULL) {
        HDF_LOGE("%s: Alloc usb serial device failed", __func__);
        return HDF_FAILURE;
    }
    // 初始化互斥锁，&acm->lock表示指向互斥量的指针
    if (OsalMutexInit(&acm->lock) != HDF_SUCCESS) {
        HDF_LOGE("%s:%d OsalMutexInit failed", __func__, __LINE__);
        goto ERROR;
    }
    info = (struct UsbPnpNotifyServiceInfo *)device->priv;
    if (info != NULL) {
        HDF_LOGD("%s:%d busNum=%d,devAddr=%d,interfaceLength=%d", __func__, __LINE__, info->busNum, info->devNum,
            info->interfaceLength);
        acm->busNum = (uint8_t)info->busNum;
        acm->devAddr = (uint8_t)info->devNum;
        acm->interfaceCnt = info->interfaceLength;
        err = memcpy_s((void *)(acm->interfaceIndex), USB_MAX_INTERFACES, (const void *)info->interfaceNumber,
            info->interfaceLength);
        if (err != EOK) {
            HDF_LOGE("%s:%d memcpy_s failed err = %d", __func__, __LINE__, err);
            goto LOCK_ERROR;
        }
    } else {
        HDF_LOGE("%s:%d info is null!", __func__, __LINE__);
        goto LOCK_ERROR;
    }
    acm->device = device;
    device->service = &(acm->service);
    acm->device->service->Dispatch = UsbSerialDeviceDispatch;
    HDF_LOGD("UsbSerialDriverBind=========================OK");
    return HDF_SUCCESS;

LOCK_ERROR:
    if (OsalMutexDestroy(&acm->lock)) {
        HDF_LOGE("%s:%d OsalMutexDestroy failed", __func__, __LINE__);
    }
ERROR:
    OsalMemFree(acm);
    acm = NULL;
    return HDF_FAILURE;
}
...
static int32_t AcmAllocReadRequests(struct AcmDevice *acm)
{
    int32_t ret;
    struct UsbRequestParams readParmas = {};
    for (int32_t i = 0; i < ACM_NR; i++) {
        // 分配待发送的readReq IO Request对象
        acm->readReq[i] = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), 0, acm->readSize);
        if (!acm->readReq[i]) {
            HDF_LOGE("readReq request failed\n");
            goto ERROR;
        }
        readParmas.userData = (void *)acm;
        readParmas.pipeAddress = acm->dataInPipe->pipeAddress;
        readParmas.pipeId = acm->dataInPipe->pipeId;
        readParmas.interfaceId = acm->dataInPipe->interfaceId;
        readParmas.callback = AcmReadBulk;
        readParmas.requestType = USB_REQUEST_PARAMS_DATA_TYPE; /* Data type */
        readParmas.timeout = USB_CTRL_SET_TIMEOUT;
        readParmas.dataReq.numIsoPackets = 0;
        readParmas.dataReq.directon = (((uint8_t)acm->dataInPipe->pipeDirection) >> USB_PIPE_DIR_OFFSET) & 0x1;
        readParmas.dataReq.length = (int)acm->readSize;
        // 根据readParams填充预先分配待发送的readReq IO Request对象
        ret = UsbFillRequest(acm->readReq[i], InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), &readParmas);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: UsbFillRequest failed, ret=%d \n", __func__, ret);
            goto ERROR;
        }
    }
    return HDF_SUCCESS;

ERROR:
    AcmFreeReadRequests(acm);
    return HDF_ERR_MALLOC_FAIL;
}

static int32_t AcmAllocNotifyRequest(struct AcmDevice *acm)
{
    int32_t ret;
    struct UsbRequestParams intParmas = {};
    // 分配待发送的中断IO Request对象
    acm->notifyReq = UsbAllocRequest(InterfaceIdToHandle(acm, acm->intPipe->interfaceId), 0, acm->intSize);
    if (!acm->notifyReq) {
        HDF_LOGE("notifyReq request failed.\n");
        return HDF_ERR_MALLOC_FAIL;
    }
    intParmas.userData = (void *)acm;
    intParmas.pipeAddress = acm->intPipe->pipeAddress;
    intParmas.pipeId = acm->intPipe->pipeId;
    intParmas.interfaceId = acm->intPipe->interfaceId;
    intParmas.callback = AcmCtrlIrq;
    intParmas.requestType = USB_REQUEST_PARAMS_DATA_TYPE;
    intParmas.timeout = USB_CTRL_SET_TIMEOUT;
    intParmas.dataReq.numIsoPackets = 0;
    intParmas.dataReq.directon = (((uint8_t)acm->intPipe->pipeDirection) >> USB_PIPE_DIR_OFFSET) & DIRECTION_MASK;
    intParmas.dataReq.length = (int)acm->intSize;
    // 填充预先分配的中断IO Request
    ret = UsbFillRequest(acm->notifyReq, InterfaceIdToHandle(acm, acm->intPipe->interfaceId), &intParmas);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: UsbFillRequest failed, ret = %d", __func__, ret);
        goto ERROR;
    }
    return HDF_SUCCESS;

ERROR:
    AcmFreeNotifyReqeust(acm);
    return ret;
}

static void AcmReleaseInterfaces(struct AcmDevice *acm)
{
    for (uint8_t i = 0; i < acm->interfaceCnt; i++) {
        if (acm->iface[i]) {
            // 释放一个USB接口对象
            UsbReleaseInterface(acm->iface[i]);
            acm->iface[i] = NULL;
        }
    }
    if (acm->ctrIface) {
        UsbReleaseInterface(acm->ctrIface);
        acm->ctrIface = NULL;
    }
}

static int32_t AcmClaimInterfaces(struct AcmDevice *acm)
{
    for (uint8_t i = 0; i < acm->interfaceCnt; i++) {
        // 获取UsbInterface接口对象
        acm->iface[i] = GetUsbInterfaceById((const struct AcmDevice *)acm, acm->interfaceIndex[i]);
        if (acm->iface[i] == NULL) {
            HDF_LOGE("%s: interface%d is null", __func__, acm->interfaceIndex[i]);
            goto ERROR;
        }
    }
	// 获取控制接口对应的UsbInterface接口对象
    acm->ctrIface = GetUsbInterfaceById((const struct AcmDevice *)acm, USB_CTRL_INTERFACE_ID);
    if (acm->ctrIface == NULL) {
        HDF_LOGE("%s: GetUsbInterfaceById null", __func__);
        goto ERROR;
    }

    return HDF_SUCCESS;

ERROR:
    // 根据acm->interfaceCnt循环释放接口对象
    AcmReleaseInterfaces(acm);
    return HDF_FAILURE;
}

static void AcmCloseInterfaces(struct AcmDevice *acm)
{
    for (uint8_t i = 0; i < acm->interfaceCnt; i++) {
        if (acm->devHandle[i]) {
            // 关闭一个USB设备对象
            UsbCloseInterface(acm->devHandle[i]);
            acm->devHandle[i] = NULL;
        }
    }
    if (acm->ctrDevHandle) {
        UsbCloseInterface(acm->ctrDevHandle);
        acm->ctrDevHandle = NULL;
    }
}

static int32_t AcmOpenInterfaces(struct AcmDevice *acm)
{
    for (uint8_t i = 0; i < acm->interfaceCnt; i++) {
        if (acm->iface[i]) {
            // 打开获取到的UsbInterface接口对象
            acm->devHandle[i] = UsbOpenInterface(acm->iface[i]);
            if (acm->devHandle[i] == NULL) {
                HDF_LOGE("%s: UsbOpenInterface null", __func__);
                goto ERROR;
            }
        }
    }
    acm->ctrDevHandle = UsbOpenInterface(acm->ctrIface);
    if (acm->ctrDevHandle == NULL) {
        HDF_LOGE("%s: ctrDevHandle UsbOpenInterface null", __func__);
        goto ERROR;
    }

    return HDF_SUCCESS;

ERROR:
    // 关闭所有UsbInterface接口对象
    AcmCloseInterfaces(acm);
    return HDF_FAILURE;
}

static int32_t AcmGetPipes(struct AcmDevice *acm)
{
    // 获取dataInPipe的pipeInfo信息
    acm->dataInPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_IN);
    if (acm->dataInPipe == NULL) {
        HDF_LOGE("dataInPipe is null");
        goto ERROR;
    }
	// 获取dataOutPipe的pipeInfo信息
    acm->dataOutPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_OUT);
    if (acm->dataOutPipe == NULL) {
        HDF_LOGE("dataOutPipe is null");
        goto ERROR;
    }
	// 获取控制pipe的pipeInfo信息
    acm->ctrPipe = EnumePipe(acm, acm->ctrIface->info.interfaceIndex, USB_PIPE_TYPE_CONTROL, USB_PIPE_DIRECTION_OUT);
    if (acm->ctrPipe == NULL) {
        HDF_LOGE("ctrPipe is null");
        goto ERROR;
    }
    // 获取中断pipe的pipeInfo信息
    acm->intPipe = GetPipe(acm, USB_PIPE_TYPE_INTERRUPT, USB_PIPE_DIRECTION_IN);
    if (acm->intPipe == NULL) {
        HDF_LOGE("intPipe is null");
        goto ERROR;
    }

    acm->readSize = acm->dataInPipe->maxPacketSize;
    acm->writeSize = acm->dataOutPipe->maxPacketSize;
    acm->ctrlSize = acm->ctrPipe->maxPacketSize;
    acm->intSize = acm->intPipe->maxPacketSize;

    return HDF_SUCCESS;

ERROR:
    // 释放设备中所有的管道信息
    AcmFreePipes(acm);
    return HDF_FAILURE;
}

static void AcmFreeRequests(struct AcmDevice *acm)
{
    if (g_syncRequest != NULL) {
        UsbFreeRequest(g_syncRequest);
        g_syncRequest = NULL;
    }
    AcmFreeReadRequests(acm);
    AcmFreeNotifyReqeust(acm);
    AcmFreeWriteRequests(acm);
    AcmWriteBufFree(acm);
}

static int32_t AcmAllocRequests(const struct AcmDevice *acm)
{
    int32_t ret;

    if (AcmWriteBufAlloc(acm) < 0) {
        HDF_LOGE("%s: AcmWriteBufAlloc failed", __func__);
        return HDF_ERR_MALLOC_FAIL;
    }

    for (int32_t i = 0; i < ACM_NW; i++) {
        struct AcmWb *snd = (struct AcmWb *)&(acm->wb[i]);
        // 分配待发送的IO Request对象
        snd->request = UsbAllocRequest(
            InterfaceIdToHandle((struct AcmDevice *)acm, acm->dataOutPipe->interfaceId), 0, acm->writeSize);
        snd->instance = (struct AcmDevice *)acm; 
        if (snd->request == NULL) {
            HDF_LOGE("%s:%d snd request fail", __func__, __LINE__);
            goto ERROR_ALLOC_WRITE_REQ;
        }
    }

    ret = AcmAllocNotifyRequest((struct AcmDevice *)acm); // 分配并填充中断IO Request对象
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d AcmAllocNotifyRequest fail", __func__, __LINE__);
        goto ERROR_ALLOC_INT_REQ;
    }

    ret = AcmAllocReadRequests((struct AcmDevice *)acm); // 分配并填充readReq IO Request对象
    if (ret) {
        HDF_LOGE("%s:%d AcmAllocReadRequests fail", __func__, __LINE__);
        goto ERROR_ALLOC_READ_REQ;
    }

    return HDF_SUCCESS;

ERROR_ALLOC_READ_REQ:
    AcmFreeNotifyReqeust((struct AcmDevice *)acm);
ERROR_ALLOC_INT_REQ:
    AcmFreeWriteRequests((struct AcmDevice *)acm);
ERROR_ALLOC_WRITE_REQ:
    AcmWriteBufFree((struct AcmDevice *)acm);
    return HDF_FAILURE;
}

static int32_t AcmInit(struct AcmDevice *acm)
{
    int32_t ret;

    if (acm->initFlag) {
        HDF_LOGE("%{public}s: initFlag is true", __func__);
        return HDF_SUCCESS;
    }
	// 初始化Host DDK
    ret = UsbInitHostSdk(NULL);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: UsbInitHostSdk failed", __func__);
        return HDF_ERR_IO;
    }
    acm->session = NULL;
	// 根据acm->interfaceIndex[i]分别获取UsbInterface接口对象
    ret = AcmClaimInterfaces(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmClaimInterfaces failed", __func__);
        goto ERROR_CLAIM_INTERFACES;
    }
    // 根据acm->iface[i]分别打开UsbInterface接口对象
    ret = AcmOpenInterfaces(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmOpenInterfaces failed", __func__);
        goto ERROR_OPEN_INTERFACES;
    }
    // 获取管道信息的指针
    ret = AcmGetPipes(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmGetPipes failed", __func__);
        goto ERROR_GET_PIPES;
    }

    ret = AcmAllocRequests(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmAllocRequests failed", __func__);
        goto ERROR_ALLOC_REQS;
    }

    acm->lineCoding.dwDTERate = CPU_TO_LE32(DATARATE);
    acm->lineCoding.bCharFormat = USB_CDC_1_STOP_BITS;
    acm->lineCoding.bParityType = USB_CDC_NO_PARITY;
    acm->lineCoding.bDataBits = DATA_BITS_LENGTH;
    acm->initFlag = true;

    return HDF_SUCCESS;

ERROR_ALLOC_REQS:
    AcmFreePipes(acm);
ERROR_GET_PIPES:
    // 关闭所有UsbInterface接口对象
    AcmCloseInterfaces(acm);
ERROR_OPEN_INTERFACES:
    // 释放所有UsbInterface接口对象 
    AcmReleaseInterfaces(acm);
ERROR_CLAIM_INTERFACES:
    // 在主机端退出USB DDK，acm->session代表指向会话上下文的指针
    UsbExitHostSdk(acm->session);
    acm->session = NULL;
    return ret;
}

static void AcmRelease(struct AcmDevice *acm)
{
    if (!(acm->initFlag)) {
        HDF_LOGE("%s:%d: initFlag is false", __func__, __LINE__);
        return;
    }

    AcmCloseInterfaces(acm);
    AcmReleaseInterfaces(acm);
    AcmFreeRequests(acm);
    AcmFreePipes(acm);
    // 在主机端退出USB DDK
    UsbExitHostSdk(acm->session);
    acm->session = NULL;

    acm->initFlag = false;
}

static int32_t UsbSerialDriverInit(struct HdfDeviceObject *device)
{
    int32_t ret;
    struct AcmDevice *acm = NULL;

    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)device->service;
    // 初始化互斥锁，&acm->readLock表示指向互斥量的指针
    if (acm == NULL) {
        return HDF_ERR_INVALID_OBJECT;
    }
    OsalMutexInit(&acm->readLock);
    OsalMutexInit(&acm->writeLock);
    HDF_LOGD("%s:%d busNum = %d,devAddr = %d", __func__, __LINE__, acm->busNum, acm->devAddr);
    // 给USB串口设备信息开辟空间并赋值
    ret = UsbSerialDeviceAlloc(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: Serial Device alloc failed", __func__);
    }

    acm->initFlag = false;
    g_acmReleaseFlag = false;

    HDF_LOGD("%s:%d init ok!", __func__, __LINE__);

    return ret;
}

static void UsbSerialDriverRelease(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;

    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return;
    }
    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        HDF_LOGE("%s: acm is null", __func__);
        return;
    }

    g_acmReleaseFlag = true;

    if (acm->initFlag) {
        HDF_LOGE("%s:%d AcmRelease", __func__, __LINE__);
        AcmRelease(acm);
    }
    // 释放usb串口设备信息
    UsbSeriaDevicelFree(acm);
    // 释放互斥锁
    OsalMutexDestroy(&acm->writeLock);
    OsalMutexDestroy(&acm->readLock);
    OsalMutexDestroy(&acm->lock);
    OsalMemFree(acm);
    acm = NULL;
    HDF_LOGD("%s:%d exit", __func__, __LINE__);
}
// 驱动的Bind、Init、及Release操作
struct HdfDriverEntry g_usbSerialDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "usbhost_acm", // 驱动模块名称，必须与hcs文件中配置的名称一致
    .Bind = UsbSerialDriverBind,
    .Init = UsbSerialDriverInit,
    .Release = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialDriverEntry); // 驱动入口
```

#### Host RAW API驱动开发

```cpp
root {
    module = "usb_pnp_device";
    usb_pnp_config {
        match_attr = "usb_pnp_match";
        usb_pnp_device_id = "UsbPnpDeviceId";
        UsbPnpDeviceId {
            idTableList = [
                "host_acm_rawapi_table"
            ];
            host_acm_rawapi_table {    // 驱动配置匹配表信息
                // 驱动模块名，该字段的值必须和驱动入口结构的moduleName一致
                moduleName = "usbhost_acm_rawapi";
                // 驱动对外发布服务的名称，必须唯一
                serviceName = "usbhost_acm_rawapi_service";
                // 驱动私有数据匹配关键字
                deviceMatchAttr = "usbhost_acm_rawapi_matchAttr";
                // 从该字段开始（包含该字段）之后数据长度，以byte为单位
                length = 21;
                // USB驱动匹配规则vendorId+productId+interfaceSubClass+interfaceProtocol+interfaceNumber
                matchFlag = 0x0303;
                // 厂商编号
                vendorId = 0x12D1;
                // 产品编号
                productId = 0x5000;
                // 设备出厂编号，低16位
                bcdDeviceLow = 0x0000;
                // 设备出厂编号，高16位
                bcdDeviceHigh = 0x0000;
                // USB分配的设备类代码
                deviceClass = 0;
                // USB分配的子类代码
                deviceSubClass = 0;
                // USB分配的设备协议代码
                deviceProtocol = 0;
                // 接口类型，根据实际需要可填写多个
                interfaceClass = [0];
                // 接口子类型，根据实际需要可填写多个
                interfaceSubClass = [2, 0];
                // 接口所遵循的协议，根据实际需要可填写多个
                interfaceProtocol = [1, 2];
                // 接口的编号，根据实际需要可填写多个
                interfaceNumber = [2, 3];
            }
        }
    }
}
```

```cpp
#include <unistd.h>

#include "hdf_base.h"
#include "hdf_log.h"
#include "hdf_usb_pnp_manage.h"
#include "osal_mem.h"
#include "osal_time.h"
#include "securec.h"
#include "usb_serial_rawapi.h"

#define HDF_LOG_TAG                   USB_HOST_ACM_RAW_API
#define USB_CTRL_REQ_SIZE             64
#define USB_IO_THREAD_STACK_SIZE      8192
#define USB_RAW_IO_SLEEP_MS_TIME      100
#define USB_RAW_IO_STOP_WAIT_MAX_TIME 3

static struct UsbRawRequest *g_syncRequest = NULL;
static UsbRawIoProcessStatusType g_stopIoStatus = USB_RAW_IO_PROCESS_RUNNING;
struct OsalMutex g_stopIoLock;
static bool g_rawAcmReleaseFlag = false;
...
static int32_t UsbGetConfigDescriptor(UsbRawHandle *devHandle, struct UsbRawConfigDescriptor **config)
{
    UsbRawDevice *dev = NULL;
    int32_t activeConfig;
    int32_t ret;

    if (devHandle == NULL) {
        HDF_LOGE("%s:%d devHandle is null", __func__, __LINE__);
        return HDF_ERR_INVALID_PARAM;
    }
    // 获取主用设备配置
    ret = UsbRawGetConfiguration(devHandle, &activeConfig);
    if (ret) {
        HDF_LOGE("%s:%d UsbRawGetConfiguration failed, ret = %d", __func__, __LINE__, ret);
        return HDF_FAILURE;
    }
    HDF_LOGE("%s:%d activeConfig = %d", __func__, __LINE__, activeConfig);
    // 根据指定的设备句柄获取设备指针
    dev = UsbRawGetDevice(devHandle);
    if (dev == NULL) {
        HDF_LOGE("%s:%d UsbRawGetDevice failed", __func__, __LINE__);
        return HDF_FAILURE;
    }
    // 根据指定的设备ID获取设备配置描述符
    ret = UsbRawGetConfigDescriptor(dev, activeConfig, config);
    if (ret) {
        HDF_LOGE("UsbRawGetConfigDescriptor failed, ret = %d\n", ret);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}
...
    static int32_t UsbAllocWriteRequests(struct AcmDevice *acm)
{
    int32_t i;

    for (i = 0; i < ACM_NW; i++) {
        struct AcmWb *snd = &acm->wb[i];
        // 分配一个具有指定数目的同步传输分组描述符的传输请求
        snd->request = UsbRawAllocRequest(acm->devHandle, 0, acm->dataOutEp->maxPacketSize);
        snd->instance = acm;
        if (snd->request == NULL) {
            HDF_LOGE("%s: UsbRawAllocRequest failed", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
    }

    return HDF_SUCCESS;
}
...
/* HdfDriverEntry implementations */
static int32_t UsbSerialDriverBind(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    struct UsbPnpNotifyServiceInfo *info = NULL;
    errno_t err;

    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }

    acm = (struct AcmDevice *)OsalMemCalloc(sizeof(*acm));
    if (acm == NULL) {
        HDF_LOGE("%s: Alloc usb serial device failed", __func__);
        return HDF_FAILURE;
    }
    if (OsalMutexInit(&acm->lock) != HDF_SUCCESS) {
        HDF_LOGE("%s:%d OsalMutexInit fail", __func__, __LINE__);
        goto ERROR;
    }

    info = (struct UsbPnpNotifyServiceInfo *)device->priv;
    if (info != NULL) {
        acm->busNum = (uint8_t)info->busNum;
        acm->devAddr = (uint8_t)info->devNum;
        acm->interfaceCnt = info->interfaceLength;
        err = memcpy_s((void *)(acm->interfaceIndex), USB_MAX_INTERFACES, (const void *)info->interfaceNumber,
            info->interfaceLength);
        if (err != EOK) {
            HDF_LOGE("%s:%d memcpy_s failed err=%d", __func__, __LINE__, err);
            goto LOCK_ERROR;
        }
    } else {
        HDF_LOGE("%s:%d info is NULL!", __func__, __LINE__);
        goto LOCK_ERROR;
    }

    device->service = &(acm->service);
    device->service->Dispatch = UsbSerialDeviceDispatch;
    acm->device = device;
    HDF_LOGD("UsbSerialDriverBind=========================OK");
    return HDF_SUCCESS;

LOCK_ERROR:
    if (OsalMutexDestroy(&acm->lock)) {
        HDF_LOGE("%s:%d OsalMutexDestroy fail", __func__, __LINE__);
    }
ERROR:
    OsalMemFree(acm);
    acm = NULL;
    return HDF_FAILURE;
}
...
static int32_t UsbAllocReadRequests(struct AcmDevice *acm)
{
    struct UsbRawFillRequestData reqData;
    uint32_t size = acm->dataInEp->maxPacketSize;

    for (int32_t i = 0; i < ACM_NR; i++) {
        // 分配一个具有指定数目的同步传输分组描述符的传输请求
        acm->readReq[i] = UsbRawAllocRequest(acm->devHandle, 0, size);
        if (!acm->readReq[i]) {
            HDF_LOGE("readReq request failed\n");
            return HDF_ERR_MALLOC_FAIL;
        }

        reqData.endPoint = acm->dataInEp->addr;
        reqData.numIsoPackets = 0;
        reqData.callback = AcmReadBulkCallback;
        reqData.userData = (void *)acm;
        reqData.timeout = USB_CTRL_SET_TIMEOUT;
        reqData.length = size;
        // 在批量传输请求中填写所需信息
        int32_t ret = UsbRawFillBulkRequest(acm->readReq[i], acm->devHandle, &reqData);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: FillBulkRequest failed, ret=%d\n", __func__, ret);
            return HDF_FAILURE;
        }
    }

    return HDF_SUCCESS;
}
...
static int32_t UsbAllocNotifyRequest(struct AcmDevice *acm)
{
    struct UsbRawFillRequestData fillRequestData;
    uint32_t size = acm->notifyEp->maxPacketSize;
    int32_t ret;
    // 分配一个具有指定数目的同步传输分组描述符的传输请求
    acm->notifyReq = UsbRawAllocRequest(acm->devHandle, 0, size);
    if (!acm->notifyReq) {
        HDF_LOGE("notifyReq request fail\n");
        return HDF_ERR_MALLOC_FAIL;
    }

    fillRequestData.endPoint = acm->notifyEp->addr;
    fillRequestData.length = size;
    fillRequestData.numIsoPackets = 0;
    fillRequestData.callback = AcmNotifyReqCallback;
    fillRequestData.userData = (void *)acm;
    fillRequestData.timeout = USB_CTRL_SET_TIMEOUT;
    // 在中断传输请求中填充所需的信息
    ret = UsbRawFillInterruptRequest(acm->notifyReq, acm->devHandle, &fillRequestData);
    if (ret) {
        HDF_LOGE("%s: FillInterruptRequest failed, ret=%d", __func__, ret);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}
...
static int32_t UsbSerialInit(struct AcmDevice *acm)
{
    struct UsbSession *session = NULL;
    UsbRawHandle *devHandle = NULL;
    int32_t ret;

    if (acm->initFlag) {
        HDF_LOGE("%s:%d: initFlag is true", __func__, __LINE__);
        return HDF_SUCCESS;
    }
    // 以专家模式初始化USB DDK
    ret = UsbRawInit(NULL);
    if (ret) {
        HDF_LOGE("%s:%d UsbRawInit failed", __func__, __LINE__);
        return HDF_ERR_IO;
    }
    acm->session = session;
    // 打开一个USB设备对象
    devHandle = UsbRawOpenDevice(session, acm->busNum, acm->devAddr);
    if (devHandle == NULL) {
        HDF_LOGE("%s:%d UsbRawOpenDevice failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto ERR_OPEN_DEVICE;
    }
    acm->devHandle = devHandle;
    // 获取主用设备配置、设备指针及配置描述符
    ret = UsbGetConfigDescriptor(devHandle, &acm->config);
    if (ret) {
        HDF_LOGE("%s:%d UsbGetConfigDescriptor failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto ERR_GET_DESC;
    }
    ret = UsbParseConfigDescriptor(acm, acm->config);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d UsbParseConfigDescriptor failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto ERR_PARSE_DESC;
    }

    ret = AcmWriteBufAlloc(acm);
    if (ret < 0) {
        HDF_LOGE("%s:%d AcmWriteBufAlloc failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto ERR_ALLOC_WRITE_BUF;
    }
    ret = UsbAllocWriteRequests(acm);
    if (ret < 0) {
        HDF_LOGE("%s:%d UsbAllocWriteRequests failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto ERR_ALLOC_WRITE_REQS;
    }
    ret = UsbAllocNotifyRequest(acm);
    if (ret) {
        HDF_LOGE("%s:%d UsbAllocNotifyRequests failed", __func__, __LINE__);
        goto ERR_ALLOC_NOTIFY_REQ;
    }
    ret = UsbAllocReadRequests(acm);
    if (ret) {
        HDF_LOGE("%s:%d UsbAllocReadRequests failed", __func__, __LINE__);
        goto ERR_ALLOC_READ_REQS;
    }
    ret = UsbStartIo(acm);
    if (ret) {
        HDF_LOGE("%s:%d UsbAllocReadRequests failed", __func__, __LINE__);
        goto ERR_START_IO;
    }

    acm->lineCoding.dwDTERate = CPU_TO_LE32(DATARATE);
    acm->lineCoding.bCharFormat = USB_CDC_1_STOP_BITS;
    acm->lineCoding.bParityType = USB_CDC_NO_PARITY;
    acm->lineCoding.bDataBits = DATA_BITS_LENGTH;

    ret = UsbRawSubmitRequest(acm->notifyReq);
    if (ret) {
        HDF_LOGE("%s:%d UsbRawSubmitRequest failed", __func__, __LINE__);
        goto ERR_SUBMIT_REQ;
    }

    acm->initFlag = true;

    HDF_LOGD("%s:%d=========================OK", __func__, __LINE__);

    return HDF_SUCCESS;

ERR_SUBMIT_REQ:
    UsbStopIo(acm); // 停止IO线程并释放所有资源
ERR_START_IO:
    UsbFreeReadRequests(acm);
ERR_ALLOC_READ_REQS:
    UsbFreeNotifyReqeust(acm);
ERR_ALLOC_NOTIFY_REQ:
    UsbFreeWriteRequests(acm);
ERR_ALLOC_WRITE_REQS:
    AcmWriteBufFree(acm);
ERR_ALLOC_WRITE_BUF:
    UsbReleaseInterfaces(acm);
ERR_PARSE_DESC:
    UsbRawFreeConfigDescriptor(acm->config);
    acm->config = NULL;
ERR_GET_DESC:
    (void)UsbRawCloseDevice(devHandle); // 关闭USB设备对象
ERR_OPEN_DEVICE:
    UsbRawExit(acm->session); // 退出USB DDK的专家模式

    return ret;
}
...
static void UsbSerialRelease(struct AcmDevice *acm)
{
    if (!(acm->initFlag)) {
        HDF_LOGE("%s:%d: initFlag is false", __func__, __LINE__);
        return;
    }

    /* stop io thread and release all resources */
    UsbStopIo(acm);
    if (g_syncRequest != NULL) {
        UsbRawFreeRequest(g_syncRequest);
        g_syncRequest = NULL;
    }
    UsbFreeReadRequests(acm);
    UsbFreeNotifyReqeust(acm);
    UsbFreeWriteRequests(acm);
    AcmWriteBufFree(acm);
    UsbReleaseInterfaces(acm);
    (void)UsbRawCloseDevice(acm->devHandle);
    UsbRawFreeConfigDescriptor(acm->config);
    acm->config = NULL;
    // 退出USB DDK的专家模式
    UsbRawExit(acm->session);

    acm->initFlag = false;
}

static int32_t UsbSerialDriverInit(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    int32_t ret;

    if (device == NULL) {
        HDF_LOGE("%s:%d device is null", __func__, __LINE__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        return HDF_ERR_INVALID_OBJECT;
    }
    OsalMutexInit(&acm->readLock);
    OsalMutexInit(&acm->writeLock);
	// 设备申请连续的内存
    ret = UsbSerialDeviceAlloc(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d UsbSerialDeviceAlloc failed", __func__, __LINE__);
    }

    acm->initFlag = false;
    g_rawAcmReleaseFlag = false;
    HDF_LOGD("%s:%d init ok!", __func__, __LINE__);
    return ret;
}

static void UsbSerialDriverRelease(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return;
    }

    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        HDF_LOGE("%s: acm is null", __func__);
        return;
    }

    g_rawAcmReleaseFlag = true;

    if (acm->initFlag) {
        HDF_LOGE("%s:%d UsbSerialRelease", __func__, __LINE__);
        UsbSerialRelease(acm);
    }
    UsbSeriaDevicelFree(acm);
    OsalMutexDestroy(&acm->writeLock);
    OsalMutexDestroy(&acm->readLock);
    OsalMutexDestroy(&acm->lock);
    OsalMemFree(acm);
    acm = NULL;
    HDF_LOGD("%s:%d exit", __func__, __LINE__);
}

struct HdfDriverEntry g_usbSerialRawDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "usbhost_acm_rawapi", // 驱动模块名称，必须与hcs文件中配置的名称一致
    .Bind = UsbSerialDriverBind,
    .Init = UsbSerialDriverInit,
    .Release = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialRawDriverEntry);
```

#### Device DDK API驱动开发

USB ACM设备核心代码路径为drivers\peripheral\usb\gadget\function\acm\cdcacm.c。其使用示例如下所示，首先根据描述符创建设备，然后获取接口，打开接口，获取Pipe信息，接收Event事件，接着进行USB通信（读写等），设备卸载时候，关闭接口，停止Event接收，删除设备。

1. 创建设备。

    ```cpp
    static int32_t AcmCreateFuncDevice(struct UsbAcmDevice *acm, struct DeviceResourceIface *iface)
    {
        int32_t ret;
        struct UsbFnDevice *fnDev = NULL;
    // 读取hcs文件中的udc_name节点的字符串值
        if (iface->GetString(acm->device->property, "udc_name", (const char **)&acm->udcName, UDC_NAME) != HDF_SUCCESS) {
            HDF_LOGE("%s: read udc_name failed, use default", __func__);
            return HDF_FAILURE;
        }

        fnDev = (struct UsbFnDevice *)UsbFnGetDevice(acm->udcName);
        if (fnDev == NULL) {
            HDF_LOGE("%s: create usb function device failed", __func__);
            return HDF_FAILURE;
        }
    // 解析acm每一个Iface
        ret = AcmParseEachIface(acm, fnDev);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: get pipes failed", __func__);
            return HDF_FAILURE;
        }

        acm->fnDev = fnDev;
        return HDF_SUCCESS;
    }

    ```

2. 获取接口，打开接口，获取Pipe信息

    ```cpp
    static int32_t AcmParseEachPipe(struct UsbAcmDevice *acm, struct UsbAcmInterface *iface)
    {
        struct UsbFnInterface *fnIface = iface->fn;
        for (uint32_t i = 0; i < fnIface->info.numPipes; i++) {
            struct UsbFnPipeInfo pipeInfo;
            // pipeInfo清除缓存区内容
            (void)memset_s(&pipeInfo, sizeof(pipeInfo), 0, sizeof(pipeInfo));
            /* 获取pipe信息 */
            int32_t ret = UsbFnGetInterfacePipeInfo(fnIface, i, &pipeInfo);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: get pipe info error", __func__);
                return ret;
            }
            // PIPE的中断和管脚
            switch (pipeInfo.type) {
                case USB_PIPE_TYPE_INTERRUPT:
                    acm->notifyPipe.id = pipeInfo.id;
                    acm->notifyPipe.maxPacketSize = pipeInfo.maxPacketSize;
                    acm->ctrlIface = *iface;
                    break;
                case USB_PIPE_TYPE_BULK:
                    if (pipeInfo.dir == USB_PIPE_DIRECTION_IN) {
                        acm->dataInPipe.id = pipeInfo.id;
                        acm->dataInPipe.maxPacketSize = pipeInfo.maxPacketSize;
                        acm->dataIface = *iface;
                    } else {
                        acm->dataOutPipe.id = pipeInfo.id;
                        acm->dataOutPipe.maxPacketSize = pipeInfo.maxPacketSize;
                    }
                    break;
                default:
                    HDF_LOGE("%s: pipe type %d don't support", __func__, pipeInfo.type);
                    break;
            }
        }

        return HDF_SUCCESS;
    }
    /* 获取接口，打开接口获取handle */ 
    static int32_t AcmParseEachIface(struct UsbAcmDevice *acm, struct UsbFnDevice *fnDev)
    {
        struct UsbFnInterface *fnIface = NULL;
        uint32_t i;
        if (fnDev == NULL) {
            return HDF_FAILURE;
        }
        for (i = 0; i < fnDev->numInterfaces; i++) {
            fnIface = (struct UsbFnInterface *)UsbFnGetInterface(fnDev, i);
            if (fnIface == NULL) {
                HDF_LOGE("%s: get interface failed", __func__);
                return HDF_FAILURE;
            }

            if (fnIface->info.subclass == USB_DDK_CDC_SUBCLASS_ACM) {
                (void)AcmParseAcmIface(acm, fnIface);
                fnIface = (struct UsbFnInterface *)UsbFnGetInterface(fnDev, i + 1);
                if (fnIface == NULL) {
                    HDF_LOGE("%s: get interface failed", __func__);
                    return HDF_FAILURE;
                }
                (void)AcmParseAcmIface(acm, fnIface);
                return HDF_SUCCESS;
            }
        }
        return HDF_FAILURE;
    }
    ```

3. 接收Event事件（EP0控制传输）

    ```cpp
    static int32_t AcmAllocCtrlRequests(struct UsbAcmDevice *acm, int32_t num)
    {
        struct DListHead *head = &acm->ctrlPool;
        struct UsbFnRequest *req = NULL;
        struct CtrlInfo *ctrlInfo = NULL;
        int32_t i;

        DListHeadInit(&acm->ctrlPool);
        acm->ctrlReqNum = 0;

        for (i = 0; i < num; i++) {
            // 申请内存
            ctrlInfo = (struct CtrlInfo *)OsalMemCalloc(sizeof(*ctrlInfo));
            if (ctrlInfo == NULL) {
                HDF_LOGE("%s: Allocate ctrlInfo failed", __func__);
                goto OUT;
            }
            ctrlInfo->acm = acm;
            req = UsbFnAllocCtrlRequest(
                acm->ctrlIface.handle, sizeof(struct UsbCdcLineCoding) + sizeof(struct UsbCdcLineCoding));
            if (req == NULL) {
                goto OUT;
            }
            req->complete = AcmCtrlComplete;
            req->context = ctrlInfo;
            DListInsertTail(&req->list, head);
            acm->ctrlReqNum++;
        }
        return HDF_SUCCESS;

    OUT:
        return DListIsEmpty(head) ? HDF_FAILURE : HDF_SUCCESS;
    }
    ```

4. 进行USB通信（读写等）

    ```cpp
    static int32_t AcmSendNotifyRequest(
        struct UsbAcmDevice *acm, uint8_t type, uint16_t value, const void *data, uint32_t length)
    {
        struct UsbFnRequest *req = acm->notifyReq;
        struct UsbCdcNotification *notify = NULL;
        int32_t ret;

        if (req == NULL || req->buf == NULL) {
            HDF_LOGE("%s: req is null", __func__);
            return HDF_FAILURE;
        }

        acm->notifyReq = NULL;
        acm->pending = false;
        req->length = sizeof(*notify) + length;

        notify = (struct UsbCdcNotification *)req->buf;
        notify->bmRequestType = USB_DDK_DIR_IN | USB_DDK_TYPE_CLASS | USB_DDK_RECIP_INTERFACE;
        notify->bNotificationType = type;
        notify->wValue = CPU_TO_LE16(value);
        notify->wIndex = CPU_TO_LE16(acm->ctrlIface.fn->info.index);
        notify->wLength = CPU_TO_LE16(length);
        ret = memcpy_s((void *)(notify + 1), length, data, length);
        if (ret != EOK) {
            HDF_LOGE("%s: memcpy_s failed", __func__);
            return HDF_FAILURE;
        }

        ret = UsbFnSubmitRequestAsync(req);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: send notify request failed", __func__);
            acm->notifyReq = req;
        }

        return ret;
    }
    ```

5. 关闭接口，停止Event接收，删除设备

    ```cpp
    static int32_t AcmReleaseFuncDevice(struct UsbAcmDevice *acm)
    {
        int32_t ret;
        /* 关闭接口 */
        (void)UsbFnInterfaceClose(acm->ctrlIface.handle);
        (void)UsbFnInterfaceClose(acm->dataIface.handle);
        /* 停止接收Event EP0控制传输 */
        (void)UsbFnInterfaceStopRecvEvent(acm->ctrlIface.fn);
        /* 删除设备 */
        ret = UsbFnDeviceRemove(acm->fnDev);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: remove usb function device failed", __func__);
        }
        return ret;
    }
    static int32_t AcmReleaseFuncDevice(struct UsbAcmDevice *acm)
    {
        int32_t ret = HDF_SUCCESS;
        if (acm->fnDev == NULL) {
            HDF_LOGE("%s: fnDev is null", __func__);
            return HDF_FAILURE;
        }
        //释放通知请求
        AcmFreeCtrlRequests(acm);
        AcmFreeNotifyRequest(acm);
         /* 停止接收Event EP0控制传输 */
        (void)UsbFnCloseInterface(acm->ctrlIface.handle);
        (void)UsbFnCloseInterface(acm->dataIface.handle);
        (void)UsbFnStopRecvInterfaceEvent(acm->ctrlIface.fn);
        return ret;
    }
    ```

## 参考

- 代码仓库如下：

  **[drivers\_hdf\_core](https://gitee.com/openharmony/drivers_hdf_core)**

  [drivers\_peripheral](https://gitee.com/openharmony/drivers_peripheral)

  [drivers\_interface](https://gitee.com/openharmony/drivers_interface)

- 代码路径如下：

  USB驱动模型liteos适配：//drivers/hdf_core/adapter/khdf/liteos/model/usb

  USB DDK驱动加载实现：//drivers/hdf_core/framework/model/usb

  USB HDI服务端实现：//drivers/peripheral/usb/hdi_service

  USB HDI对外接口：//out/{product_name}/gen/drivers/interface/usb/v1_0

