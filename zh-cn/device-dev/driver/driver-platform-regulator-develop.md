# REGULATOR<a name="title_REGULATORDevelop"></a>

- [概述](#section1_REGULATORDevelop)
- [接口说明](#section2_REGULATORDevelop)
- [开发步骤](#section3_REGULATORDevelop)
- [开发实例](#section4_REGULATORDevelop)

## 概述 <a name="section1_REGULATORDevelop"></a>

REGULATOR模块用于控制系统中某些设备的电压/电流供应。在HDF框架中，REGULATOR模块接口适配模式采用统一服务模式，这需要一个设备服务来作为REGULATOR模块的管理器，统一处理外部访问，这会在配置文件中有所体现。统一服务模式适合于同类型设备对象较多的情况，如REGULATOR可能同时具备十几个控制器，采用独立服务模式需要配置更多的设备节点，且服务会占据内存资源。

图 1 统一服务模式结构图
![image1](figures/统一服务模式结构图.png)

## 接口说明<a name="section2_REGULATORDevelop"></a>

RegulatorMethod 定义：

```c
struct RegulatorMethod {
    int32_t (*open)(struct RegulatorNode *node);
    int32_t (*close)(struct RegulatorNode *node);
    int32_t (*release)(struct RegulatorNode *node);
    int32_t (*enable)(struct RegulatorNode *node);
    int32_t (*disable)(struct RegulatorNode *node);
    int32_t (*forceDisable)(struct RegulatorNode *node);
    int32_t (*setVoltage)(struct RegulatorNode *node, uint32_t minUv, uint32_t maxUv);
    int32_t (*getVoltage)(struct RegulatorNode *node, uint32_t *voltage);
    int32_t (*setCurrent)(struct RegulatorNode *node, uint32_t minUa, uint32_t maxUa);
    int32_t (*getCurrent)(struct RegulatorNode *node, uint32_t *regCurrent);
    int32_t (*getStatus)(struct RegulatorNode *node, uint32_t *status);
};
```

**表 1**  RegulatorMethod 成员的回调函数功能说明

| 成员函数     | 入参                                        | 返回值 | 功能 |
| ------------ | ------------------------------------------- | ------ | ---- |
| open         | **node**：结构体指针，核心层regulator节点； |HDF_STATUS相关状态|打开设备|
| close        | **node**：结构体指针，核心层regulator节点； | HDF_STATUS相关状态 | 关闭设备 |
| release      | **node**：结构体指针，核心层regulator节点； | HDF_STATUS相关状态 | 释放设备句柄 |
| enable       | **node**：结构体指针，核心层regulator节点； | HDF_STATUS相关状态 | 使能 |
| disable      | **node**：结构体指针，核心层regulator节点； | HDF_STATUS相关状态 | 禁用 |
| forceDisable | **node**：结构体指针，核心层regulator节点； | HDF_STATUS相关状态 | 强制禁用 |
| setVoltage   | **node**：结构体指针，核心层regulator节点；<br>**minUv**：uint32_t变量，最小电压；<br>**maxUv**：uint32_t变量，最大电压； | HDF_STATUS相关状态 | 设置电压 |
| getVoltage   | **node**：结构体指针，核心层regulator节点；<br>**voltage**：uint32_t指针，传出电压值； | HDF_STATUS相关状态 | 获取电压 |
| setCurrent   | **node**：结构体指针，核心层regulator节点；<br>**minUa**：uint32_t变量，最小电流；<br>**maxUa**：uint32_t变量，最大电流； | HDF_STATUS相关状态 | 设置电流 |
| getCurrent   | **node**：结构体指针，核心层regulator节点；<br>**regCurrent**：uint32_t指针，传出电流值； | HDF_STATUS相关状态 | 获取电流 |
| getStatus    | **node**：结构体指针，核心层regulator节点；<br>**status**：uint32_t指针，传出状态值； | HDF_STATUS相关状态 | 获取状态 |

## 开发步骤 <a name="section3_REGULATORDevelop"></a>

REGULATOR模块适配的三个环节是配置属性文件、实例化驱动入口、以及实例化核心层接口函数。

1. **实例化驱动入口：**   
   
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。
   
2. **配置属性文件：**   

   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加regulator_config.hcs器件属性文件。

3. **实例化REGULATOR控制器对象：**   
   
   - 初始化RegulatorNode成员。
   
   - 实例化RegulatorNode成员RegulatorMethod，
   
        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化RegulatorNode成员RegulatorMethod，其定义和成员说明见[接口说明](#section2_REGULATORDevelop)。
   
4. **驱动调试：**
   - 【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，数据传输的成功与否等。

## 开发实例 <a name="section4_REGULATORDevelop"></a>

下方将以regulator_virtual.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1. 驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

   一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

   REGULATOR驱动入口参考

   ```c
   struct HdfDriverEntry g_regulatorDriverEntry = {
       .moduleVersion = 1,
       .moduleName = "virtual_regulator_driver",//【必要 且与 HCS文件中里面的moduleName匹配】
       .Init = VirtualRegulatorInit,
       .Release = VirtualRegulatorRelease,
   };
   //调用HDF_INIT将驱动入口注册到HDF框架中
   HDF_INIT(g_regulatorDriverEntry);
   ```

2. 完成驱动入口注册之后，下一步请在device\_info.hcs文件中添加deviceNode信息，并在 regulator\_config.hcs 中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层RegulatorNode成员的默认值或限制范围有密切关系。 如有更多个器件信息，则需要在device\_info文件增加deviceNode信息，以及在regulator\_config文件中增加对应的器件属性**。**

   - device\_info.hcs 配置参考。

     ```c
     root {
       device_info { 
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_regulator :: device {
               device0 :: deviceNode {	//为每一个 regulator 控制器配置一个HDF设备节点，存在多个时【必须】添加，否则不用
                   policy = 1;			// 等于1，向内核态发布服务
                   priority = 50;		// 驱动启动优先级
                   permission = 0644;	// 驱动创建设备节点权限
                   /*【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；*/
                   moduleName = "HDF_PLATFORM_REGULATOR_MANAGER";		
                   serviceName = "HDF_PLATFORM_REGULATOR_MANAGER";		//【必要且唯一】驱动对外发布服务的名称
                  /*【必要】用于配置控制器私有数据，要与regulator_config.hcs中对应控制器保持一致，具体的控制器信息在regulator_config.hcs 中*/
                   deviceMatchAttr = "hdf_platform_regulator_manager";
               }
               device1 :: deviceNode {
                   policy = 0;
                   priority = 55;
                   permission = 0644;
                   moduleName = "linux_regulator_adapter";
                   deviceMatchAttr = "linux_regulator_adapter";
               }
           }
         }
       }
     }
     ```

   - regulator\_config.hcs 配置参考。

     ```c
     root {
         platform {
             regulator_config {
     			match_attr = "linux_regulator_adapter";
     			template regulator_controller {    //【必要】模板配置，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
     			    device_num = 1;
     				name = "";
     			    devName = "regulator_adapter_consumer01";
     				supplyName = "";
     				mode = 1;
     				minUv = 0;
     				maxUv = 20000;
     				minUa = 0;
     				maxUa = 0;
     			}
     			controller_0x130d0000 :: regulator_controller {
     			    device_num = 1;
     			    name = "regulator_adapter_1";
     				devName = "regulator_adapter_consumer01";
     				supplyName = "virtual-regulator-hdf-adapter";
     				mode = 1;
     				minUv = 1000;
     				maxUv = 50000;
     				minUa = 0;
     				maxUa = 0;
     			}
     			controller_0x130d0001 :: regulator_controller {    //存在多个设备时【必须】添加，否则不用
     			    device_num = 1;
     			    name = "regulator_adapter_2";
     				devName = "regulator_adapter_consumer01";
     				supplyName = "virtual2-regulator-hdf-adapter";
     				mode = 2;
     				minUv = 0;
     				maxUv = 0;
     				minUa = 1000;
     				maxUa = 50000;
     			}
             }
         }
     }
     ```

3. 完成驱动入口注册之后，最后一步就是以核心层RegulatorNode对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化RegulatorNode成员RegulatorMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

   - 自定义结构体参考。

     从驱动的角度看，自定义结构体是参数和数据的载体，而且regulator\_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如设备名称等。

     ```c
     // RegulatorNode是核心层控制器结构体，其中的成员在Init函数中会被赋值
     struct RegulatorNode {
         struct RegulatorDesc regulatorInfo;
         struct DListHead node;
         struct RegulatorMethod *ops;
         void *priv;
         struct OsalMutex lock;
     };
     
     struct RegulatorDesc {
         const char *name;              /* regulator 名称 */
         const char *parentName;        /* regulator 父节点名称 */
         struct RegulatorConstraints constraints;    /* regulator 约束信息 */
         uint32_t minUv;                  /* 最小电压值 */
         uint32_t maxUv;                  /* 最大电压值 */
         uint32_t minUa;                  /* 最小电流值 */
         uint32_t maxUa;                  /* 最大电流值 */
         uint32_t status;                 /* regulator的状态，开或关 */
         int useCount;
         int consumerRegNums;             /* regulator用户数量 */
         RegulatorStatusChangecb cb;      /* 当regulator状态改变时，可通过此变量通知 */
     };
     
     struct RegulatorConstraints {
         uint8_t alwaysOn;     /* regulator是否常开 */
         uint8_t mode;         /* 模式：电压或者电流 */
         uint32_t minUv;       /* 最小可设置电压 */
         uint32_t maxUv;       /* 最大可设置电压 */
         uint32_t minUa;       /* 最小可设置电流 */
         uint32_t maxUa;       /* 最大可设置电流 */
     };
     ```
     
   - RegulatorNode成员回调函数结构体RegulatorMethod的实例化，其他成员在Init函数中初始化。
   
     ```c
     // regulator_virtual.c 中的示例：钩子函数的填充
     static struct RegulatorMethod g_method = {
         .enable = VirtualRegulatorEnable,
         .disable = VirtualRegulatorDisable,
         .setVoltage = VirtualRegulatorSetVoltage,
         .getVoltage = VirtualRegulatorGetVoltage,
         .setCurrent = VirtualRegulatorSetCurrent,
         .getCurrent = VirtualRegulatorGetCurrent,
         .getStatus = VirtualRegulatorGetStatus,
     };
     ```
   
   - Init函数参考
   
     入参：
   
     HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。
   
     返回值：
   
     HDF\_STATUS相关状态  （下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。
   
     **表 2**  HDF\_STATUS相关状态
   
     <table><thead align="left"><tr id="row31521027164144"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1990732428164144p0"><a name="entry1990732428164144p0"></a><a name="entry1990732428164144p0"></a>状态(值)</p>
     </th>
     <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry2123581292164144p0"><a name="entry2123581292164144p0"></a><a name="entry2123581292164144p0"></a>问题描述</p>
     </th>
     </tr>
     </thead>
     <tbody><tr id="row1749271383164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry202330388164144p0"><a name="entry202330388164144p0"></a><a name="entry202330388164144p0"></a>HDF_ERR_INVALID_OBJECT</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1717598064164144p0"><a name="entry1717598064164144p0"></a><a name="entry1717598064164144p0"></a>控制器对象非法</p>
     </td>
     </tr>
     <tr id="row1715354988164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry450625221164144p0"><a name="entry450625221164144p0"></a><a name="entry450625221164144p0"></a>HDF_ERR_MALLOC_FAIL</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry361497788164144p0"><a name="entry361497788164144p0"></a><a name="entry361497788164144p0"></a>内存分配失败</p>
     </td>
     </tr>
     <tr id="row1202091366164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry370837906164144p0"><a name="entry370837906164144p0"></a><a name="entry370837906164144p0"></a>HDF_ERR_INVALID_PARAM</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry353311523164144p0"><a name="entry353311523164144p0"></a><a name="entry353311523164144p0"></a>参数非法</p>
     </td>
     </tr>
     <tr id="row602018308164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1984036607164144p0"><a name="entry1984036607164144p0"></a><a name="entry1984036607164144p0"></a>HDF_ERR_IO</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1221756048164144p0"><a name="entry1221756048164144p0"></a><a name="entry1221756048164144p0"></a>I/O 错误</p>
     </td>
     </tr>
     <tr id="row47997479164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1220816374164144p0"><a name="entry1220816374164144p0"></a><a name="entry1220816374164144p0"></a>HDF_SUCCESS</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1903499126164144p0"><a name="entry1903499126164144p0"></a><a name="entry1903499126164144p0"></a>初始化成功</p>
     </td>
     </tr>
     <tr id="row2031856197164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry463793674164144p0"><a name="entry463793674164144p0"></a><a name="entry463793674164144p0"></a>HDF_FAILURE</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry516362874164144p0"><a name="entry516362874164144p0"></a><a name="entry516362874164144p0"></a>初始化失败</p>
     </td>
     </tr>
     </tbody>
     </table>


```c
 函数说明：

 初始化自定义结构体对象，初始化RegulatorNode成员，调用核心层RegulatorNodeAdd函数。

 static int32_t VirtualRegulatorInit(struct HdfDeviceObject *device)
{
    int32_t ret;
    const struct DeviceResourceNode *childNode = NULL;
    ...
    DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
        ret = VirtualRegulatorParseAndInit(device, childNode);//【必要】实现见下
        ...
    }
    ...
}
 
static int32_t VirtualRegulatorParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
{
    int32_t ret;
    struct RegulatorNode *regNode = NULL;
    (void)device;

    regNode = (struct RegulatorNode *)OsalMemCalloc(sizeof(*regNode));//加载hcs文件
    ...
    ret = VirtualRegulatorReadHcs(regNode, node);//读取hcs文件信息
    ...
    regNode->priv = (void *)node;    //实例化节点
    regNode->ops = &g_method;        //实例化ops

    ret = RegulatorNodeAdd(regNode); //挂载节点
    ...
}
```

   - Release 函数参考

     入参：

     HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

     返回值：

     无。

     函数说明：

     释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。

     ```c
     static void VirtualRegulatorRelease(struct HdfDeviceObject *device)
     {
         ...
         RegulatorNodeRemoveAll();//【必要】调用核心层函数，释放RegulatorNode的设备和服务
     }
     ```
