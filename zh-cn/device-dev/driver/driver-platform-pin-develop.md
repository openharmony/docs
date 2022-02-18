# PIN<a name="title_PinDevelop"></a>

- [概述](#section1_PinDevelop)
- [接口说明](#section2_PinDevelop)
- [开发步骤](#section3_PinDevelop)
- [开发实例](#section4_PinDevelop)

## 概述 <a name="section1_PinDevelop"></a>

PIN模块用于控制系统中管脚的状态和功能特性。在HDF框架中，PIN的接口适配模式采用无服务模式，用于不需要在用户态提供API的设备类型，或者没有用户态和内核区分的OS系统，其关联方式是DevHandle直接指向设备对象内核态地址（DevHandle是一个void类型指针）。

图 1 无服务模式结构图
![image1](figures/无服务模式结构图.png)

## 接口说明<a name="section2_PinDevelop"></a>

PinCntlrMethod定义：

```c
struct PinCntlrMethod {
    int32_t (*SetPinPull)(struct PinCntlr *cntlr, uint32_t index, enum PinPullType pullType);
    int32_t (*GetPinPull)(struct PinCntlr *cntlr, uint32_t index, enum PinPullType *pullType);
    int32_t (*SetPinStrength)(struct PinCntlr *cntlr, uint32_t index, uint32_t strength);
    int32_t (*GetPinStrength)(struct PinCntlr *cntlr, uint32_t index, uint32_t *strength);
    int32_t (*SetPinFunc)(struct PinCntlr *cntlr, uint32_t index, const char *funcName);
    int32_t (*GetPinFunc)(struct PinCntlr *cntlr, uint32_t index, const char **funcName);
};
```

**表 1**  PinCntlrMethod成员的回调函数功能说明

| 成员函数     | 入参                                        | 返回值 | 功能 |
| ------------ | ------------------------------------------- | ------ | ---- |
| SetPinPull | **cntlr**：结构体指针，核心层Pin控制器；<br>**index**：uint32_t变量，管脚索引号；<br/>**pullType**：枚举常量，Pin管脚推拉方式； |HDF_STATUS相关状态|设置Pin管脚推拉方式|
| GetPinPull | **cntlr**：结构体指针，核心层Pin控制器；<br/>**index**：uint32_t变量，管脚索引号；<br/>**pullType**：枚举常量指针，传出Pin管脚推拉方式； | HDF_STATUS相关状态 | 获取Pin管脚推拉方式 |
| SetPinStrength | **cntlr**：结构体指针，核心层Pin控制器；<br/>**index**：uint32_t变量，管脚索引号；<br/>**strength**：uint32_t变量，Pin推拉强度； | HDF_STATUS相关状态 | 设置Pin推拉强度 |
| GetPinStrength | **cntlr**：结构体指针，核心层Pin控制器；<br/>**index**：uint32_t变量，管脚索引号；<br/>**strength**：uint32_t变量指针，传出Pin推拉强度； | HDF_STATUS相关状态 | 获取Pin推拉强度 |
| SetPinFunc | **cntlr**：结构体指针，核心层Pin控制器；<br/>**index**：uint32_t变量，管脚索引号；<br/>**funcName**：char指针常量，传入Pin管脚功能； | HDF_STATUS相关状态 | 设置Pin管脚功能 |
| GetPinFunc | **cntlr**：结构体指针，核心层Pin控制器；<br/>**index**：uint32_t变量，管脚索引号；<br/>**funcName**：char双重指针常量，传出Pin管脚功能； | HDF_STATUS相关状态 | 获取Pin管脚功能 |

## 开发步骤 <a name="section3_PinDevelop"></a>

PIN模块适配的三个环节是实例化驱动入口、配置属性文件、以及实例化核心层接口函数。

1. **实例化驱动入口：**
   
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。
   
2. **配置属性文件：**

   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加pin_config.hcs器件属性文件。

3. **实例化PIN控制器对象：**
   
   - 初始化PinCntlr成员。
   
   - 实例化PinCntlr成员PinCntlrMethod。
   
        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化PinCntlr成员PinCntlrMethod，其定义和成员说明见[接口说明](#section2_PINDevelop)。
   
4. **驱动调试：**
   
   - 【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，数据传输的成功与否等。

## 开发实例 <a name="section4_PinDevelop"></a>

下方将以pin_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1. 驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

   一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

   PIN驱动入口参考

   ```c
   static struct HdfDriverEntry g_hi35xxPinDriverEntry = {
       .moduleVersion = 1,
       .Bind = Hi35xxPinBind,
       .Init = Hi35xxPinInit,
       .Release = Hi35xxPinRelease,
       .moduleName = "hi35xx_pin_driver",//【必要且与HCS文件中里面的moduleName匹配】
   };
   //调用HDF_INIT将驱动入口注册到HDF框架中
   HDF_INIT(g_hi35xxPinDriverEntry);
   ```

2. 完成驱动入口注册之后，下一步请在device\_info.hcs文件中添加deviceNode信息，并在pin\_config.hcs中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层PinCntlr成员的默认值或限制范围有密切关系。
   
    >![](../public_sys-resources/icon-note.gif) **说明：** 
   >如有更多个器件信息，则需要在device\_info文件增加deviceNode信息，以及在pin\_config文件中增加对应的器件属性。

   - device\_info.hcs 配置参考。

     ```c
     root {
       device_info { 
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_pin :: device {
                     device0 :: deviceNode {   //为每一个Pin控制器配置一个HDF设备节点，存在多个时须添加，否则不用
                         policy = 0;			  //2:用户态可见,1:内核态可见,0:不需要发布服务
                         priority = 10;        // 驱动启动优先级
                         permission = 0644;    // 驱动创建设备节点权限
                         /*【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；*/
                         moduleName = "hi35xx_Pin_driver";
                         /*【必要】用于配置控制器私有数据，要与Pin_config.hcs中对应控制器保持一致，具体的控制器信息在Pin_config.hcs 中*/
                         deviceMatchAttr = "hisilicon_hi35xx_Pin_0";
                     }
                     device1 :: deviceNode {
                         policy = 0;
                         priority = 10;
                         permission = 0644;
                         moduleName = "hi35xx_Pin_driver";
                         deviceMatchAttr = "hisilicon_hi35xx_Pin_1";
                     }
               		...
           }
         }
       }
     }
     ```

   - Pin\_config.hcs 配置参考。

     ```c
     root {
         platform {
             Pin_config_hi35xx {
                 template Pin_controller {    //【必要】模板配置，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
                     number = 0;              //【必要】controller 编号
                     regStartBasePhy = 0;     //【必要】寄存器物理基地址起始地址
                     regSize = 0;             //【必要】寄存器位宽
                     PinCount = 0;            //【必要】管脚数量
                     match_attr = "";
                     template Pin_desc {
                         PinName = "";        //【必要】管脚名称
                         init = 0;            //【必要】寄存器默认值
                         F0 = "";             //【必要】功能0
                         F1 = "";             //功能1
                         F2 = "";             //功能2
                         F3 = "";             //功能3
                         F4 = "";             //功能4
                         F5 = "";             //功能5
                     }
                 }
                 controller_0 :: Pin_controller {
                     number = 0;
                     regStartBasePhy = 0x10FF0000;
                     regSize = 0x48;
                     PinCount = 18;
                     match_attr = "hisilicon_hi35xx_Pin_0";
                     T1 :: Pin_desc {
                         PinName = "T1";
                         init = 0x0600;
                         F0 = "EMMC_CLK";
                         F1 = "SFC_CLK";
                         F2 = "SFC_BOOT_MODE";
                     }
                     ...
                 }
                 ...//每个Pin控制器对应一个controller节点，如存在多个Pin控制器，请依次添加对应的controller节点。
             }
         }
     }
     ```
   
3. 完成驱动入口注册之后，最后一步就是对核心层PinCntlr对象的初始化，包括厂商自定义结构体（传递参数和数据），实例化PinCntlr成员PinCntlrMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

   - 自定义结构体参考。

     从驱动的角度看，PinCntlr结构体是参数和数据的载体，HDF框架通过DeviceResourceIface将pin\_config.hcs文件中的数值读入其中。

     ```c
     // PinCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
     struct PinCntlr {
         struct IDeviceIoService service;
         struct HdfDeviceObject *device;
         struct PinCntlrMethod *method;
         struct DListHead node;
         OsalSPinlock sPin;
         uint16_t number;
         uint16_t PinCount;
         struct PinDesc *Pins;
         void *priv;
     };
     
     struct PinDesc {
         const char *PinName;    //Pin管脚名
         void *priv;
     };
     ```
     
   - 实例化PinCntlr成员PinCntlrMethod，其他成员在Init函数中初始化。
   
     ```c
     // Pin_hi35xx.c 中的示例：钩子函数的填充
     static struct PinCntlrMethod g_method = {
         .SetPinPull = Hi35xxPinSetPull,
         .GetPinPull = Hi35xxPinGetPull,
         .SetPinStrength = Hi35xxPinSetStrength,
         .GetPinStrength = Hi35xxPinGetStrength,
         .SetPinFunc = Hi35xxPinSetFunc,
         .GetPinFunc = Hi35xxPinGetFunc,
     };
     ```
     
   - Init函数参考
   
     入参：
   
     HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。
   
     返回值：
   
     HDF\_STATUS相关状态  （下表为部分展示，如需使用其他状态，可见/drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。
   
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

      函数说明：
      初始化自定义结构体和PinCntlr成员，并通过调用核心层PinCntlrAdd函数挂载Pin控制器。

        ```c
        static int32_t Hi35xxPinInit(struct HdfDeviceObject *device)
        {
            ...
            struct Hi35xxPinCntlr *hi35xx = NULL;
            ...
            ret = Hi35xxPinCntlrInit(device, hi35xx);    //读取hcs文件信息
            ...
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = Hi35xxPinParsePinNode(childNode, hi35xx, index);    //【必要】实现如下
                ...
            }
     
            hi35xx->cntlr.method = &g_method;    //实例化ops
            ret = PinCntlrAdd(&hi35xx->cntlr);   //挂载控制器
            ...
        }
     
        static int32_t Hi35xxPinParsePinNode(const struct DeviceResourceNode *node,
                                             struct Hi35xxPinCntlr *hi35xx,
                                             int32_t index)
        {
            ...
            hi35xx->cntlr.Pins[index].PinName = hi35xx->desc[index].PinName;    //实例化PinName
            hi35xx->cntlr.Pins[index].priv = (void *)node;					    //实例化节点
            ...
        }

   
   - Release 函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。

        ```c
        static void Hi35xxPinRelease(struct HdfDeviceObject *device)
        {
        struct PinCntlr *cntlr = NULL;
        ...
        PinCntlrRemove(cntlr);//【必要】调用核心层函数，释放PinCntlr的设备和服务
        ...
        }
        ```
