# GPIO<a name="ZH-CN_TOPIC_0000001222282165"></a>

-   [概述](#section1826197354103451)
-   [接口说明](#section752964871810)
-   [开发步骤](#section731175315103451)
-   [开发实例](#section800425816103451)

## 概述<a name="section1826197354103451"></a>

GPIO（General-purpose input/output）即通用型输入输出，在HDF框架中，

GPIO的接口适配模式采用无服务模式，用于不需要在用户态提供API的设备类型，或者没有用户态和内核区分的OS系统，其关联方式是DevHandle直接指向设备对象内核态地址（DevHandle是一个void类型指针）。

**图 1**  GPIO无服务模式结构图<a name="fig5511033193814"></a>  
![](figures/GPIO无服务模式结构图.png "GPIO无服务模式结构图")

## 接口说明<a name="section752964871810"></a>

GpioMethod定义：

```
struct GpioMethod {
  int32_t (*request)(struct GpioCntlr *cntlr, uint16_t local);// 【可选】
  int32_t (*release)(struct GpioCntlr *cntlr, uint16_t local);// 【可选】
  int32_t (*write)(struct GpioCntlr *cntlr, uint16_t local, uint16_t val);
  int32_t (*read)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *val);
  int32_t (*setDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t dir);
  int32_t (*getDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *dir);
  int32_t (*toIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *irq);// 【可选】
  int32_t (*setIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t mode, GpioIrqFunc func, void *arg);
  int32_t (*unsetIrq)(struct GpioCntlr *cntlr, uint16_t local);
  int32_t (*enableIrq)(struct GpioCntlr *cntlr, uint16_t local);
  int32_t (*disableIrq)(struct GpioCntlr *cntlr, uint16_t local);
}
```

**表 1**  GpioMethod结构体成员的回调函数功能说明

<a name="table105024430564"></a>
<table><thead align="left"><tr id="row150394355618"><th class="cellrowborder" align="center" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p650344375617"><a name="p650344375617"></a><a name="p650344375617"></a>函数成员</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p1450394313564"><a name="p1450394313564"></a><a name="p1450394313564"></a>入参</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p65031243145610"><a name="p65031243145610"></a><a name="p65031243145610"></a>出参</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p65030430564"><a name="p65030430564"></a><a name="p65030430564"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p9503104313563"><a name="p9503104313563"></a><a name="p9503104313563"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row950310439569"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1550310436563"><a name="p1550310436563"></a><a name="p1550310436563"></a>write</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p2503194315613"><a name="p2503194315613"></a><a name="p2503194315613"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号 ;val：uint16_t，电平传入值;</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p105031443205616"><a name="p105031443205616"></a><a name="p105031443205616"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p145035434561"><a name="p145035434561"></a><a name="p145035434561"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p195031043195615"><a name="p195031043195615"></a><a name="p195031043195615"></a>GPIO引脚写入电平值</p>
</td>
</tr>
<tr id="row115036433568"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p155031843135611"><a name="p155031843135611"></a><a name="p155031843135611"></a>read</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p45033436562"><a name="p45033436562"></a><a name="p45033436562"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p9503943165614"><a name="p9503943165614"></a><a name="p9503943165614"></a>val：uint16_t 指针，用于传出电平值 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p12504194305619"><a name="p12504194305619"></a><a name="p12504194305619"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p9504943125620"><a name="p9504943125620"></a><a name="p9504943125620"></a>GPIO引脚读取电平值</p>
</td>
</tr>
<tr id="row4504174312563"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p0504174395612"><a name="p0504174395612"></a><a name="p0504174395612"></a>setDir</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p65041043125616"><a name="p65041043125616"></a><a name="p65041043125616"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号 ;dir：uint16_t，管脚方向传入值;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p45044436563"><a name="p45044436563"></a><a name="p45044436563"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p175047436561"><a name="p175047436561"></a><a name="p175047436561"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p15504543115611"><a name="p15504543115611"></a><a name="p15504543115611"></a>设置GPIO引脚输入/输出方向</p>
</td>
</tr>
<tr id="row6504174385620"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p10504114325614"><a name="p10504114325614"></a><a name="p10504114325614"></a>getDir</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p15504184375619"><a name="p15504184375619"></a><a name="p15504184375619"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p5504343135617"><a name="p5504343135617"></a><a name="p5504343135617"></a>dir：uint16_t 指针，用于传出管脚方向值 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1450464314563"><a name="p1450464314563"></a><a name="p1450464314563"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p20504104385610"><a name="p20504104385610"></a><a name="p20504104385610"></a>读GPIO引脚输入/输出方向</p>
</td>
</tr>
<tr id="row750419431561"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1950414335619"><a name="p1950414335619"></a><a name="p1950414335619"></a>setIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p115049434567"><a name="p115049434567"></a><a name="p115049434567"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号;mode：uint16_t，表示触发模式（边沿或电平）;func：函数指针，中断服务程序 ;arg：void指针，中断服务程序入参;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1350414345615"><a name="p1350414345615"></a><a name="p1350414345615"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p10504643145610"><a name="p10504643145610"></a><a name="p10504643145610"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p10504194375613"><a name="p10504194375613"></a><a name="p10504194375613"></a>将GPIO引脚设置为中断模式</p>
</td>
</tr>
<tr id="row35041243125616"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1650413438568"><a name="p1650413438568"></a><a name="p1650413438568"></a>unsetIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1550484310568"><a name="p1550484310568"></a><a name="p1550484310568"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1850494310566"><a name="p1850494310566"></a><a name="p1850494310566"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p2504134316569"><a name="p2504134316569"></a><a name="p2504134316569"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p150410432569"><a name="p150410432569"></a><a name="p150410432569"></a>取消GPIO中断设置</p>
</td>
</tr>
<tr id="row5504124335615"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1350464365618"><a name="p1350464365618"></a><a name="p1350464365618"></a>enableIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1750414316563"><a name="p1750414316563"></a><a name="p1750414316563"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p8505104315612"><a name="p8505104315612"></a><a name="p8505104315612"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p135051043175619"><a name="p135051043175619"></a><a name="p135051043175619"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p14505204345619"><a name="p14505204345619"></a><a name="p14505204345619"></a>使能GPIO管脚中断</p>
</td>
</tr>
<tr id="row1250517432566"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p115052430563"><a name="p115052430563"></a><a name="p115052430563"></a>disableIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p165051435567"><a name="p165051435567"></a><a name="p165051435567"></a>cntlr：结构体指针，核心层GPIO控制器;local：uint16_t，GPIO端口标识号;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p750514438565"><a name="p750514438565"></a><a name="p750514438565"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p150544375618"><a name="p150544375618"></a><a name="p150544375618"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p15505154355613"><a name="p15505154355613"></a><a name="p15505154355613"></a>禁止GPIO管脚中断</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section731175315103451"></a>

GPIO模块适配的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。GPIO控制器分组管理所有管脚，相关参数会在属性文件中有所体现；驱动入口和接口函数的实例化环节是厂商驱动接入HDF的核心环节。

1.  **实例化驱动入口：**
    -   实例化HdfDriverEntry结构体成员。
    -   调用HDF\_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2.  **配置属性文件：**
    -   在device\_info.hcs文件中添加deviceNode描述。
    -   【可选】添加gpio\_config.hcs器件属性文件。

3.  **实例化GPIO控制器对象：**
    -   初始化GpioCntlr成员。
    -   实例化GpioCntlr成员GpioMethod。

        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化GpioCntlr成员GpioMethod，详见[接口说明](#section752964871810)。


4.  **驱动调试：**

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如GPIO控制状态，中断响应情况等。


## 开发实例<a name="section800425816103451"></a>

下方将以gpio\_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1.  驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    GPIO 驱动入口参考：

    ```
    struct HdfDriverEntry g_gpioDriverEntry = {
      .moduleVersion = 1,
      .Bind = Pl061GpioBind,            //GPIO不需要实现Bind,本例是一个空实现，厂商可根据自身需要添加相关操作
      .Init = Pl061GpioInit,            //见Init参考
      .Release = Pl061GpioRelease,      //见Release参考
      .moduleName = "hisi_pl061_driver",//【必要且需要与HCS文件中里面的moduleName匹配】
    };
    //调用HDF_INIT将驱动入口注册到HDF框架中
    HDF_INIT(g_gpioDriverEntry);
    ```

2.  完成驱动入口注册之后，下一步请在device\_info.hcs文件中添加deviceNode信息，并在 gpio\_config.hcs 中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层GpioCntlr 成员的默认值或限制范围有密切关系。

    本例只有一个GPIO控制器，如有多个器件信息，则需要在device\_info文件增加deviceNode信息，以及在gpio\_config文件中增加对应的器件属性。

    -   device\_info.hcs 配置参考。

        ```
        root {
        device_info {
            platform :: host {
            hostName = "platform_host";
            priority = 50;
            device_gpio :: device {
                device0 :: deviceNode {
                policy = 0;        // 等于0，不需要发布服务
                priority = 10;     // 驱动启动优先级
                permission = 0644; // 驱动创建设备节点权限
                moduleName = "hisi_pl061_driver";          //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；
                deviceMatchAttr = "hisilicon_hi35xx_pl061";//【必要】用于配置控制器私有数据，要与 gpio_config.hcs 中 
                                                            //对应控制器保持一致，其他控制器信息也在文件中
                }
            }
            }
        }
        }
        ```

    -   gpio\_config.hcs 配置参考。

        ```
        root {
        platform {
            gpio_config {
            controller_0x120d0000 {
                match_attr = "hisilicon_hi35xx_pl061"; //【必要】必须和device_info.hcs中的deviceMatchAttr值一致
                groupNum = 12;       //【必要】GPIO组索引 需要根据设备情况填写
                bitNum = 8;          //【必要】每组GPIO管脚数 
                regBase = 0x120d0000;//【必要】物理基地址
                regStep = 0x1000;    //【必要】寄存器偏移步进
                irqStart = 48;       //【必要】开启中断
                irqShare = 0;        //【必要】共享中断
            }
            }
        }
        } 
        ```

3.  完成驱动入口注册之后，最后一步就是以核心层GpioCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化GpioCntlr成员GpioMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
    -   自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且gpio\_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层GpioCntlr对象，例如索引、管脚数等。

        ```
        struct Pl061GpioCntlr {
          struct GpioCntlr cntlr;//【必要】 是核心层控制对象，其成员定义见下面
          volatile unsigned char *regBase; //【必要】寄存器基地址
          uint32_t phyBase;      //【必要】 物理基址
          uint32_t regStep;      //【必要】 寄存器偏移步进
          uint32_t irqStart;     //【必要】 中断开启
          uint16_t groupNum;     //【必要】 用于描述厂商的GPIO端口号的参数
          uint16_t bitNum;       //【必要】 用于描述厂商的GPIO端口号的参数
          uint8_t irqShare;      //【必要】 共享中断
          struct Pl061GpioGroup *groups;   //【可选】 根据厂商需要设置
        };
        struct Pl061GpioGroup {  //包括寄存器地址，中断号，中断函数和和锁
          volatile unsigned char *regBase;
          unsigned int index;
          unsigned int irq;
          OsalIRQHandle irqFunc;
          OsalSpinlock lock;
        };
        
        // GpioCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
        struct GpioCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          struct GpioMethod *ops;
          struct DListHead list;
          OsalSpinlock spin;
          uint16_t start;
          uint16_t count;
          struct GpioInfo *ginfos;
          void *priv;
        };
        ```

    -   GpioCntlr成员回调函数结构体GpioMethod的实例化，其他成员在Init函数中初始化。

        ```
        //GpioMethod结构体成员都是回调函数，厂商需要根据表1完成相应的函数功能。
        static struct GpioMethod g_method = {
            .request = NULL,
            .release = NULL,
            .write = Pl061GpioWrite,          //写管脚
            .read = Pl061GpioRead,            //读管脚
            .setDir = Pl061GpioSetDir,        //设置管脚方向
            .getDir = Pl061GpioGetDir,        //获取管脚方向
            .toIrq = NULL,
            .setIrq = Pl061GpioSetIrq,        //设置管脚中断，如不具备此能力可忽略
            .unsetIrq = Pl061GpioUnsetIrq,    //取消管脚中断设置，如不具备此能力可忽略
            .enableIrq = Pl061GpioEnableIrq,  //使能管脚中断，如不具备此能力可忽略
            .disableIrq = Pl061GpioDisableIrq,//禁止管脚中断，如不具备此能力可忽略
        };
        ```

    -   Init函数参考

        入参：

        HdfDeviceObject这个是整个驱动对外暴露的接口参数，具备HCS配置文件的信息。

        返回值：

        HDF\_STATUS相关状态（下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。

        **表 2**  Init函数说明

        <a name="table165981547354"></a>
        <table><thead align="left"><tr id="row8599145423516"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p959995453515"><a name="p959995453515"></a><a name="p959995453515"></a>状态(值)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p185991854163519"><a name="p185991854163519"></a><a name="p185991854163519"></a>问题描述</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row13599195483515"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p125993545359"><a name="p125993545359"></a><a name="p125993545359"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p125991454153519"><a name="p125991454153519"></a><a name="p125991454153519"></a>控制器对象非法</p>
        </td>
        </tr>
        <tr id="row35997541354"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p19600454153511"><a name="p19600454153511"></a><a name="p19600454153511"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1600145423514"><a name="p1600145423514"></a><a name="p1600145423514"></a>内存分配失败</p>
        </td>
        </tr>
        <tr id="row9600155423514"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p146001546357"><a name="p146001546357"></a><a name="p146001546357"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10600754133512"><a name="p10600754133512"></a><a name="p10600754133512"></a>参数非法</p>
        </td>
        </tr>
        <tr id="row146001254143516"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p66007542357"><a name="p66007542357"></a><a name="p66007542357"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2600135416357"><a name="p2600135416357"></a><a name="p2600135416357"></a>I/O 错误</p>
        </td>
        </tr>
        <tr id="row36001544351"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p660095417357"><a name="p660095417357"></a><a name="p660095417357"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17600165411353"><a name="p17600165411353"></a><a name="p17600165411353"></a>初始化成功</p>
        </td>
        </tr>
        <tr id="row14600154103518"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p46001544356"><a name="p46001544356"></a><a name="p46001544356"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p160035415356"><a name="p160035415356"></a><a name="p160035415356"></a>初始化失败</p>
        </td>
        </tr>
        </tbody>
        </table>

        函数说明：

        初始化自定义结构体对象，初始化GpioCntlr成员，调用核心层GpioCntlrAdd函数，【可选】接入VFS。

        ```
        static int32_t Pl061GpioInit(struct HdfDeviceObject *device)
        {
          ...
          struct Pl061GpioCntlr *pl061 = &g_pl061;//利用静态全局变量完成初始化
                                                  //static struct Pl061GpioCntlr g_pl061 = {
                                                  //    .groups = NULL,
                                                  //    .groupNum = PL061_GROUP_MAX,
                                                  //    .bitNum = PL061_BIT_MAX,
                                                  //};
          ret = Pl061GpioReadDrs(pl061, device->property);//利用从gpio_config.HCS文件读取的属性值来初始化自定义结构体对象成员
          ...
          pl061->regBase = OsalIoRemap(pl061->phyBase, pl061->groupNum * pl061->regStep);//地址映射
          ...
          ret = Pl061GpioInitCntlrMem(pl061);     // 内存分配
          ...
          pl061->cntlr.count = pl061->groupNum * pl061->bitNum;//【必要】管脚数量计算
          pl061->cntlr.priv = (void *)device->property;        //【必要】存储设备属性
          pl061->cntlr.ops = &g_method;           // 【必要】GpioMethod的实例化对象的挂载 
          pl061->cntlr.device = device;           // 【必要】使HdfDeviceObject与GpioCntlr可以相互转化的前提
          ret = GpioCntlrAdd(&pl061->cntlr);      // 【必要】调用此函数填充核心层结构体，返回成功信号后驱动才完全接入平台核心层
          ...
          Pl061GpioDebugCntlr(pl061);
          #ifdef PL061_GPIO_USER_SUPPORT            //【可选】若支持用户级的虚拟文件系统，则接入
          if (GpioAddVfs(pl061->bitNum) != HDF_SUCCESS) {
              HDF_LOGE("%s: add vfs fail!", __func__);
          }
          #endif
          ...
        }
        ```

    -   Release 函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。

        ```
        static void Pl061GpioRelease(struct HdfDeviceObject *device)
        {
           struct GpioCntlr *cntlr = NULL;
           struct Pl061GpioCntlr *pl061 = NULL;
           ...
           cntlr = GpioCntlrFromDevice(device);//【必要】通过强制转换获取核心层控制对象
                                               //return (device == NULL) ? NULL : (struct GpioCntlr *)device->service;
           ...
           #ifdef PL061_GPIO_USER_SUPPORT
           GpioRemoveVfs();//与Init中GpioAddVfs相反
           #endif
           GpioCntlrRemove(cntlr);             //【必要】取消设备信息、服务等内容在核心层上的挂载
           pl061 = ToPl061GpioCntlr(cntlr);    //return (struct Pl061GpioCntlr *)cntlr;
           Pl061GpioRleaseCntlrMem(pl061);     //【必要】锁和内存的释放
           OsalIoUnmap((void *)pl061->regBase);//【必要】解除地址映射
           pl061->regBase = NULL;
        }
        ```



