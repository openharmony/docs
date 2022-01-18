# I3C 

- [概述](#1)
- [开发步骤](#2)
- [开发实例](#3)

## 概述 <a name="1"></a>

I3C(Improved Inter Integrated Circuit)总线是由MIPI Alliance开发的一种简单、低成本的双向二线制同步串行总线。在HDF框架中，I3C模块接口适配模式采用统一服务模式，这需要一个设备服务来作为I3C模块的管理器，统一处理外部访问，这会在配置文件中有所体现。统一服务模式适合于同类型设备对象较多的情况，如I3C可能同时具备十几个控制器，采用独立服务模式需要配置更多的设备节点，且服务会占据内存资源。

![image1](figures/统一服务模式结构图.png)

## 开发步骤 <a name="2"></a>

I3C模块适配的四个环节是实例化驱动入口、配置属性文件、实例化I3C控制器对象以及注册中断处理子程序。

1. **实例化驱动入口：** 
    - 实例化HdfDriverEntry结构体成员。
    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. **配置属性文件：**
   
    - 在device_info.hcs文件中添加deviceNode描述。
    - 【可选】添加i3c_config.hcs器件属性文件。
  
3. **实例化I3C控制器对象：**
   
    - 初始化I3cCntlr成员。
    - 实例化I3cCntlr成员I3cMethod方法集合，其定义和成员函数说明见下文。
  
4. **注册中断处理子程序：**
    为控制器注册中断处理程序，实现设备热接入和IBI（带内中断）功能。

    I3cMethod定义：
    ```c
    struct I3cMethod {
        int32_t (*sendCccCmd)(struct I3cCntlr *cntlr, struct I3cCccCmd *ccc);
        int32_t (*transfer)(struct I3cCntlr *cntlr, struct I3cMsg *msgs, int16_t count);
        int32_t (*i2cTransfer)(struct I3cCntlr *cntlr, struct I3cMsg *msgs, int16_t count);
        int32_t (*setConfig)(struct I3cCntlr *cntlr, struct I3cConfig *config);
        int32_t (*getConfig)(struct I3cCntlr *cntlr, struct I3cConfig *config);
        int32_t (*requestIbi)(struct I3cDevice *dev);
        void (*freeIbi)(struct I3cDevice *dev);
    };
    ```

    表1 I3cMethod结构体成员的回调函数功能说明

    |函数成员|入参|出参|返回值|功能|
    |-|-|-|-|-|
    |sendCccCmd|**cntlr**: 结构体指针，核心层I3C控制器;<br />**ccc**：传入的通用命令代码结构体指针;|**ccc**：传出的通用命令代码结构体指针;|HDF_STATUS相关状态|发送CCC（Common command Code，即通用命令代码）|
    |Transfer  |**cntlr**: 结构体指针，核心层I3C控制器;<br />**msgs**：结构体指针，用户消息 ;<br />**count**：int16_t，消息数量|**msgs**：结构体指针，用户消息 ;|HDF_STATUS相关状态|使用I3C模式传递用户消息|
    |i2cTransfer |**cntlr**: 结构体指针，核心层I3C控制器;<br />**msgs**：结构体指针，用户消息 ;<br />**count**：int16_t，消息数量|**msgs**：结构体指针，用户消息 ;|HDF_STATUS相关状态|使用I2C模式传递用户消息|
    |setConfig|**cntlr**: 结构体指针，核心层I3C控制器; <br />**config**:  控制器配置参数|无|HDF_STATUS相关状态|设置I3C控制器配置参数|
    |getConfig|**cntlr**: 结构体指针，核心层I3C控制器;|**config**:  控制器配置参数|HDF_STATUS相关状态|获取I3C控制器配置参数|
    |requestIbi|**device**: 结构体指针，核心层I3C设备;|无|HDF_STATUS相关状态|为I3C设备请求IBI（In-Bind Interrupt，即带内中断）|
    |freeIbi|**device**: 结构体指针，核心层I3C设备;|无|HDF_STATUS相关状态|释放IBI|

## 开发实例 <a name="3"></a>

1. 驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    I3C驱动入口参考：

    > I3C模块这种类型的控制器会出现很多个控制器挂接的情况，因而在HDF框架中首先会为这类型的控制器创建一个管理器对象，并同时对外发布一个管理器服务来统一处理外部访问。这样，用户需要打开某个控制器时，会先获取到管理器服务，然后管理器服务根据用户指定参数查找到指定控制器。
    >
    > I3C管理器服务的驱动由核心层实现，**厂商不需要关注这部分内容的实现，但在实现Init函数的时候需要调用核心层的I3cCntlrAdd函数，它会实现相应功能。**

    ```c
    static struct HdfDriverEntry g_virtualI3cDriverEntry = {
        .moduleVersion = 1,
        .Init = VirtualI3cInit,
        .Release = VirtualI3cRelease,
        .moduleName = "virtual_i3c_driver",//【必要且与 HCS 里面的名字匹配】
    };
    HDF_INIT(g_virtualI3cDriverEntry);   //调用HDF_INIT将驱动入口注册到HDF框架中
    
    /* 核心层i3c_core.c管理器服务的驱动入口 */
    struct HdfDriverEntry g_i3cManagerEntry = {
        .moduleVersion = 1,
        .Init     = I3cManagerInit,
        .Release  = I3cManagerRelease,
        .moduleName = "HDF_PLATFORM_I3C_MANAGER",//这与device_info文件中device0对应
    };
    HDF_INIT(g_i3cManagerEntry);
    ```

2. 完成驱动入口注册之后，下一步请在device_info.hcs文件中添加deviceNode信息，并在i3c_config.hcs中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值对于厂商驱动的实现以及核心层I3cCntlr相关成员的默认值或限制范围有密切关系。

    **统一服务模式**的特点是device_info文件中第一个设备节点必须为I3C管理器，其各项参数必须如下设置: 
    
    |成员名|值|
    |-|-|
    |moduleName |HDF_PLATFORM_I3C_MANAGER|
    |serviceName|无（预留）|
    |policy|0|
    |cntlrMatchAttr| 无（预留）|
    
    从第二个节点开始配置具体I3C控制器信息，此节点并不表示某一路I3C控制器，而是代表一个资源性质设备，用于描述一类I3C控制器的信息。本例只有一个I3C控制器，如有多个控制器，则需要在device_info文件增加deviceNode信息，以及在i3c_config文件中增加对应的器件属性。

    - device_info.hcs 配置参考

        ```c
        root {
            device_i3c :: device {
                device0 :: deviceNode {
                    policy = 0;
                    priority = 52;
                    permission = 0644;
                    serviceName = "HDF_PLATFORM_I3C_MANAGER";
                    moduleName = "HDF_PLATFORM_I3C_MANAGER";
                }
            }
            i3c_virtual :: deviceNode {
                policy = 0;         // 等于0，不需要发布服务
                priority = 56;      // 驱动启动优先级
                permission = 0644;  // 驱动创建设备节点权限
                moduleName = "virtual_i3c_driver";        //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；
                serviceName = "VIRTUAL_I3C_DRIVER";       //【必要】驱动对外发布服务的名称，必须唯一
                deviceMatchAttr = "virtual_i3c";          //【必要】用于配置控制器私有数据，要与i3c_config.hcs中对应控制器保持一致
            }                                             // 具体的控制器信息在 i3c_config.hcs 中
        }
        ```

    - i3c_config.hcs 配置参考

        ```c
        root {
            platform {
                i3c_config {
                    match_attr = "virtual_i3c";  //【必要】需要和device_info.hcs中的deviceMatchAttr值一致
                    template i3c_controller {    // 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
                        busId = 0;               //【必要】i3c总线号
                        busMode = 0x0;           // 总线模式，0x0:纯净; 0x1:混合高速; 0x2:混合受限; 0x3: 混合低速;
                        regBasePhy = 0x120b0000; //【必要】物理基地址
                        regSize = 0xd1;          //【必要】寄存器位宽
                        IrqNum = 20;             //【必要】中断号
                        i3cMaxRate = 12900000;   //【可选】i3c模式最大时钟速率
                        i3cRate = 12500000;      //【可选】i3c模式时钟速率
                        i2cFmRate = 1000000;     //【可选】i2c FM模式时钟速率
                        i2cFmPlusRate = 400000;  //【可选】i2c FM+模式时钟速率
                    }
                    controller_0 :: i3c_controller {
                        busId = 18;
                        IrqNum = 20;
                    }
                }
            }
        }
        ```

3. 配置属性文件完成后，要以核心层I3cCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化I3cCntlr成员I3cMethod（让用户可以通过接口来调用驱动底层函数）。

    此步骤需要通过实现HdfDriverEntry成员函数（Bind，Init，Release）来完成。

    - 自定义结构体参考
      
        > 从驱动的角度看，自定义结构体是参数和数据的载体，而且i3c_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层I3cCntlr对象，例如设备号、总线号等。
    
        ```c
        struct VirtualI3cCntlr {
            struct I3cCntlr cntlr;   //【必要】是核心层控制对象，具体描述见下面
            volatile unsigned char *regBase;//【必要】寄存器基地址
            uint32_t regBasePhy;     //【必要】寄存器物理基地址
            uint32_t regSize;        //【必要】寄存器位宽
            uint16_t busId;          //【必要】设备号
            uint16_t busMode;
            uint16_t IrqNum;
            uint32_t i3cMaxRate;
            uint32_t i3cRate;
            uint32_t i2cFmRate;
            uint32_t i2cFmPlusRate;
        };

        /* I3cCntlr是核心层控制器结构体，其中的成员在Init函数中被赋值 */
        struct I3cCntlr {
            OsalSpinlock lock;
            void *owner;
            int16_t busId;
            struct I3cConfig config;
            uint16_t addrSlot[(I3C_ADDR_MAX + 1) / ADDRS_PER_UINT16];
            struct I3cIbiInfo *ibiSlot[I3C_IBI_MAX];
            const struct I3cMethod *ops;
            const struct I3cLockMethod *lockOps;
            void *priv;
        };
        ```

        > **【重要】** I3cCntlr成员回调函数结构体I3cMethod的实例化，I3cLockMethod回调函数结构体本例未实现，若要实例化，可参考I2C驱动开发，其他成员在Init函数中初始化

    
    - **init函数参考**
    
        > **入参：** 
        >  HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息
        > 
        > **返回值：**
        > HDF_STATUS相关状态 （下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS 定义）
        
        |状态(值)|问题描述|
        |:-|:-:|
        |HDF_ERR_INVALID_OBJECT|控制器对象非法|
        |HDF_ERR_INVALID_PARAM |参数非法|
        |HDF_ERR_MALLOC_FAIL   |内存分配失败|
        |HDF_ERR_IO            |I/O 错误|
        |HDF_SUCCESS           |传输成功|
        |HDF_FAILURE           |传输失败|
    
        > **函数说明：**
        > 初始化自定义结构体对象，初始化I3cCntlr成员，调用核心层I3cCntlrAdd函数。

        ```c
        static int32_t VirtualI3cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct VirtualI3cCntlr *virtual = NULL;    //【必要】自定义结构体对象
            (void)device;
    
            virtual = (struct VirtualI3cCntlr *)OsalMemCalloc(sizeof(*virtual)); //【必要】内存分配
            if (virtual == NULL) {
                HDF_LOGE("%s: Malloc virtual fail!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
    
            ret = VirtualI3cReadDrs(virtual, node);     //【必要】将i3c_config文件的默认值填充到结构体中
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
                goto __ERR__;
            }
            ...
            virtual->regBase = OsalIoRemap(virtual->regBasePhy, virtual->regSize);//【必要】地址映射
            ret = OsalRegisterIrq(hi35xx->softIrqNum, OSAL_IRQF_TRIGGER_NONE, I3cIbiHandle, "I3C", virtual); //【必要】注册中断程序
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: register irq failed!", __func__);
                return ret;
            }
            ...
            VirtualI3cCntlrInit(virtual);              //【必要】I3C设备的初始化
            virtual->cntlr.priv = (void *)node;        //【必要】存储设备属性
            virtual->cntlr.busId = virtual->busId;     //【必要】初始化I3cCntlr成员
            virtual->cntlr.ops = &g_method;            //【必要】I3cMethod的实例化对象的挂载
            (void)OsalSpinInit(&virtual->spin);
            ret = I3cCntlrAdd(&virtual->cntlr);        //【必要且重要】调用此函数将控制器添加至核心，返回成功信号后驱动才完全接入平台核心层 
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: add i3c controller failed! ret = %d", __func__, ret);
                (void)OsalSpinDestroy(&virtual->spin);
                goto __ERR__;
            }

            return HDF_SUCCESS;
        __ERR__:                                       //若控制器添加失败，需要执行去初始化相关函数
            if (virtual != NULL) {
                OsalMemFree(virtual);
                virtual = NULL;
            }

            return ret;
        }
    
        static int32_t VirtualI3cInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            const struct DeviceResourceNode *childNode = NULL;

            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is NULL", __func__);
                return HDF_ERR_INVALID_OBJECT;
            }

            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = VirtualI3cParseAndInit(device, childNode);
                if (ret != HDF_SUCCESS) {
                    break;
                }
            }

            return ret;
        }
        ```

    - **Release 函数参考**

        > **入参：** 
        > HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息 。
        > 
        > **返回值：**
        > 无。
        > 
        > **函数说明：**
        > 释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。
    
        ```c
        static void VirtualI3cRemoveByNode(const struct DeviceResourceNode *node)
        {
            int32_t ret;
            int16_t busId;
            struct I3cCntlr *cntlr = NULL;
            struct VirtualI3cCntlr *virtual = NULL;
            struct DeviceResourceIface *drsOps = NULL;
        
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                HDF_LOGE("%s: invalid drs ops fail!", __func__);
                return;
            }
        
            ret = drsOps->GetUint16(node, "busId", (uint16_t *)&busId, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read busId fail!", __func__);
                return;
            }
        ...
        /* 可以调用I3cCntlrGet函数通过设备的cntlrNum获取I3cCntlr对象， 以及调用I3cCntlrRemove函数来释放I3cCntlr对象的内容 */
            cntlr = I3cCntlrGet(busId);
            if (cntlr != NULL && cntlr->priv == node) {
                I3cCntlrPut(cntlr);
                I3cCntlrRemove(cntlr);                    //【必要】主要是从管理器驱动那边移除I3cCntlr对象
                virtual = (struct VirtualI3cCntlr *)cntlr;//【必要】通过强制转换获取自定义的对象并进行release操作
                (void)OsalSpinDestroy(&virtual->spin);
                OsalMemFree(virtual);
            }
            return;
        }
        
        static void VirtualI3cRelease(struct HdfDeviceObject *device)
        {
            const struct DeviceResourceNode *childNode = NULL;

            HDF_LOGI("%s: enter", __func__);

            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is NULL", __func__);
                return;
            }
        ...
        //遍历、解析i3c_config.hcs中的所有配置节点，并分别进行release操作
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                VirtualI3cRemoveByNode(childNode); //函数定义如上
            }
        }
        ```

4. 最后一步，实现中断处理程序，在中断处理程序中通过判断中断产生的地址，实现热接入、IBI等操作。

    ```c
    static int32_t VirtualI3cReservedAddrWorker(struct VirtualI3cCntlr *virtual, uint16_t addr)
    {
        (void)virtual;
        switch (addr) {
            case I3C_HOT_JOIN_ADDR:
                 VirtualI3cHotJoin(virtual);
                break;
            case I3C_RESERVED_ADDR_7H3E:
            case I3C_RESERVED_ADDR_7H5E:
            case I3C_RESERVED_ADDR_7H6E:
            case I3C_RESERVED_ADDR_7H76:
            case I3C_RESERVED_ADDR_7H7A:
            case I3C_RESERVED_ADDR_7H7C:
            case I3C_RESERVED_ADDR_7H7F:
            /* 广播地址单比特错误的所有情形 */
            HDF_LOGW("%s: broadcast Address single bit error!", __func__);
                break;
            default:
                HDF_LOGD("%s: Reserved address which is not supported!", __func__);
                break;
        }
        
        return HDF_SUCCESS;
    }
    ```

    ```c
    static int32_t I3cIbiHandle(uint32_t irq, void *data)
    {
        struct VirtualI3cCntlr *virtual = NULL;
        struct I3cDevice *device = NULL;
        uint16_t ibiAddr;
        char *testStr = "Hello I3C!";

        (void)irq;
        if (data == NULL) {
            HDF_LOGW("%s: data is NULL!", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        virtual = (struct VirtualI3cCntlr *)data;
        /* 【必要】获取产生中断的地址，使用CHECK_RESERVED_ADDR宏判断该地址是否为I3C保留地址 */
        ibiAddr = VirtualI3cGetIbiAddr();
        if (CHECK_RESERVED_ADDR(ibiAddr) == I3C_ADDR_RESERVED) {
            HDF_LOGD("%s: Calling VirtualI3cResAddrWorker...", __func__);
            return VirtualI3cReservedAddrWorker(virtual, ibiAddr);
        } else {
            HDF_LOGD("%s: Calling I3cCntlrIbiCallback...", __func__);
            device = GetDeviceByAddr(&virtual->cntlr, ibiAddr);
            if (device == NULL) {
                HDF_LOGE("func:%s device is NULL!",__func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            if (device->ibi->payload > VIRTUAL_I3C_TEST_STR_LEN) {
                /* 将字符串"Hello I3C!"放入IBI缓冲区内 */
                *device->ibi->data = *testStr;
            }
            /* 根据产生IBI的I3C设备调用IBI回调函数 */
            return I3cCntlrIbiCallback(device);
        }

        return HDF_SUCCESS;
    }
    ```