# PWM<a name="ZH-CN_TOPIC_0000001222082217"></a>


## 概述<a name="section1591602238164144"></a>

PWM（Pulse Width Modulator）即脉冲宽度调节器，在HDF框架中，PWM的接口适配模式采用独立服务模式，在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

**图 1**  PWM独立服务模式结构图<a name="fig983655084219"></a>  

![](figures/独立服务模式结构图.png "PWM独立服务模式结构图")

## 接口说明<a name="section752964871810"></a>

PwmMethod定义：

```
struct PwmMethod {
  int32_t (*setConfig)(struct PwmDev *pwm, struct PwmConfig *config);
  int32_t (*open)(struct PwmDev *pwm);
  int32_t (*close)(struct PwmDev *pwm);
};
```

**表 1**  PwmMethod结构体成员的回调函数功能说明

<a name="table11173154124311"></a>
<table><thead align="left"><tr id="row2173441164311"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p17174144144310"><a name="p17174144144310"></a><a name="p17174144144310"></a>成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p21751441154318"><a name="p21751441154318"></a><a name="p21751441154318"></a>入参</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p191751741144313"><a name="p191751741144313"></a><a name="p191751741144313"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p5175641154315"><a name="p5175641154315"></a><a name="p5175641154315"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row7175154144311"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p3900552134317"><a name="p3900552134317"></a><a name="p3900552134317"></a>setConfig</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p422655084417"><a name="p422655084417"></a><a name="p422655084417"></a><strong id="b10227650134413"><a name="b10227650134413"></a><a name="b10227650134413"></a>pwm</strong>:  结构体指针，核心层PWM控制器；</p>
<p id="p02275502443"><a name="p02275502443"></a><a name="p02275502443"></a><strong id="b322719508445"><a name="b322719508445"></a><a name="b322719508445"></a>config</strong>:  结构体指针，属性传入值;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p18176184112433"><a name="p18176184112433"></a><a name="p18176184112433"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p5176124164314"><a name="p5176124164314"></a><a name="p5176124164314"></a>配置属性</p>
</td>
</tr>
<tr id="row217654124312"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p121761041144314"><a name="p121761041144314"></a><a name="p121761041144314"></a>open</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p2176941144314"><a name="p2176941144314"></a><a name="p2176941144314"></a><strong id="b137308954516"><a name="b137308954516"></a><a name="b137308954516"></a>pwm</strong>:  结构体指针，核心层PWM控制器；</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1317694119435"><a name="p1317694119435"></a><a name="p1317694119435"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p376133118453"><a name="p376133118453"></a><a name="p376133118453"></a>打开设备</p>
</td>
</tr>
<tr id="row8176174110439"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p017684174314"><a name="p017684174314"></a><a name="p017684174314"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1217694118437"><a name="p1217694118437"></a><a name="p1217694118437"></a><strong id="b44731616124513"><a name="b44731616124513"></a><a name="b44731616124513"></a>pwm</strong>:  结构体指针，核心层PWM控制器；</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p16176104115437"><a name="p16176104115437"></a><a name="p16176104115437"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p10893332114514"><a name="p10893332114514"></a><a name="p10893332114514"></a>关闭设备</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section967396342164144"></a>

PWM模块适配HDF框架的三个环节是配置属性文件，实例化驱动入口，以及填充核心层接口函数。

1.  **实例化驱动入口：**
    -   实例化HdfDriverEntry结构体成员。
    -   调用HDF\_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2.  **配置属性文件：**
    -   在device\_info.hcs文件中添加deviceNode描述。
    -   【可选】添加pwm\_config.hcs器件属性文件。

3.  **实例化PWM控制器对象：**
    -   初始化PwmDev成员。
    -   实例化PwmDev成员PwmMethod。

        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化PwmDev成员PwmMethod，其定义和成员说明见[接口说明](#section752964871810)。


4.  **驱动调试：**

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如PWM控制状态，中断响应情况等。


## 开发实例<a name="section1883877829164144"></a>

下方将以pwm\_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1.  驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    PWM驱动入口参考

    ```
    struct HdfDriverEntry g_hdfPwm = {
        .moduleVersion = 1,
        .moduleName = "HDF_PLATFORM_PWM",//【必要 且与 HCS文件中里面的moduleName匹配】
        .Bind = HdfPwmBind,
        .Init = HdfPwmInit,
        .Release = HdfPwmRelease,
    };
    //调用HDF_INIT将驱动入口注册到HDF框架中
    HDF_INIT(g_hdfPwm);
    ```

2.  完成驱动入口注册之后，下一步请在device\_info.hcs文件中添加deviceNode信息，并在 pwm\_config.hcs 中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层PwmDev成员的默认值或限制范围有密切关系。 如有更多个器件信息，则需要在device\_info文件增加deviceNode信息，以及在pwm\_config文件中增加对应的器件属性。
    -   device\_info.hcs 配置参考

        ```
        root {
          device_info { 
            platform :: host {
              hostName = "platform_host";
              priority = 50;
              device_pwm :: device {//为每一个 pwm 控制器配置一个HDF设备节点，存在多个时【必须】添加，否则不用
                device0 :: deviceNode {
                  policy = 1;       // 等于1，向内核态发布服务
                  priority = 80;    // 驱动启动优先级
                  permission = 0644;// 驱动创建设备节点权限
                  moduleName = "HDF_PLATFORM_PWM";   //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；
                  serviceName = "HDF_PLATFORM_PWM_0";//【必要且唯一】驱动对外发布服务的名称
                  deviceMatchAttr = "hisilicon_hi35xx_pwm_0";//【必要】用于配置控制器私有数据，要与 pwm_config.hcs 中对应
                                                             // 控制器保持一致，具体的控制器信息在 pwm_config.hcs 中
                }
                device1 :: deviceNode {
                  policy = 1;
                  priority = 80;
                  permission = 0644;
                  moduleName = "HDF_PLATFORM_PWM";
                  serviceName = "HDF_PLATFORM_PWM_1";
                  deviceMatchAttr = "hisilicon_hi35xx_pwm_1";
                }
              }
            }
          }
        }
        ```

    -   pwm\_config.hcs 配置参考。

        ```
        root {
          platform {
            pwm_config {
              template pwm_device {                   //【必要】模板配置，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
                serviceName = "";
                match_attr = "";
                num = 0;                              //【必要】设备号
                base = 0x12070000;                    //【必要】地址映射需要
              }
              device_0x12070000 :: pwm_device {
                match_attr = "hisilicon_hi35xx_pwm_0";//【必要】需要和device_info.hcs中的deviceMatchAttr值一致
              }
              device_0x12070020 :: pwm_device {       //存在多个设备时【必须】添加，否则不用
                match_attr = "hisilicon_hi35xx_pwm_1";
                num = 1;
                base = 0x12070020;                    //【必要】地址映射需要
              }
            }
          }
        }
        ```

3.  完成驱动入口注册之后，最后一步就是以核心层PwmDev对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化PwmDev成员PwmMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
    -   自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且pwm\_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如设备号等。

        ```
        struct HiPwm {
            struct PwmDev dev;          //【必要】 核心层结构体
            volatile unsigned char *base;
            struct HiPwmRegs *reg;      // 设备属性结构体，可自定义
            bool supportPolarity;
        };
        
        // PwmDev是核心层控制器结构体，其中的成员在Init函数中会被赋值
        struct PwmDev {
            struct IDeviceIoService service;
            struct HdfDeviceObject *device;
            struct PwmConfig cfg;       //属性结构体，相关定义见下
            struct PwmMethod *method;   //钩子函数模板
            bool busy;
            uint32_t num;               //设备号
            OsalSpinlock lock;
            void *priv;                 //私有数据，一般存储自定义结构体首地址，方便调用
        };
        struct PwmConfig {
            uint32_t duty;              // 占空时间 nanoseconds
            uint32_t period;            // pwm 周期 nanoseconds 
            uint32_t number;            // pwm 连续个数
            uint8_t polarity;           // Polarity 
                                        // ------------------- | --------------
                                        // PWM_NORMAL_POLARITY | Normal polarity
                                        // PWM_INVERTED_POLARITY | Inverted polarity
                                        //
            uint8_t status;             // 运行状态
                                        // ------------------ | -----------------
                                        // PWM_DISABLE_STATUS | Disabled
                                        // PWM_ENABLE_STATUS  | Enabled
        };
        ```

    -   PwmDev成员回调函数结构体PwmMethod的实例化，其他成员在Init函数中初始化。

        ```
        // pwm_hi35xx.c 中的示例：钩子函数的填充
        struct PwmMethod g_pwmOps = {
            .setConfig = HiPwmSetConfig,//配置属性
        };
        ```

    -   Init函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        HDF\_STATUS相关状态  （下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。

        <a name="table1057438215164144"></a>
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

        初始化自定义结构体对象，初始化PwmDev成员，调用核心层PwmDeviceAdd函数。

        ```
        //此处bind函数为空函数，可与init函数结合，也可根据厂商需要实现相关操作
        static int32_t HdfPwmBind(struct HdfDeviceObject *obj)
        {
          (void)obj;
          return HDF_SUCCESS;
        }
        
        static int32_t HdfPwmInit(struct HdfDeviceObject *obj)
        {
          int ret;
          struct HiPwm *hp = NULL;
          ...
          hp = (struct HiPwm *)OsalMemCalloc(sizeof(*hp));
          ...
          ret = HiPwmProbe(hp, obj); //【必要】实现见下
          ...
          return ret;
        }
        
        static int32_t HiPwmProbe(struct HiPwm *hp, struct HdfDeviceObject *obj)
        {
            uint32_t tmp;
            struct DeviceResourceIface *iface = NULL;
        
            iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);//初始化自定义结构体HiPwm
            ...
            
            hp->reg = (struct HiPwmRegs *)hp->base;         //初始化自定义结构体HiPwm
            hp->supportPolarity = false;                    //初始化自定义结构体HiPwm
            hp->dev.method = &g_pwmOps;                     //PwmMethod的实例化对象的挂载
            hp->dev.cfg.duty = PWM_DEFAULT_DUTY_CYCLE;      //初始化PwmDev
            hp->dev.cfg.period = PWM_DEFAULT_PERIOD;        //初始化PwmDev
            hp->dev.cfg.polarity = PWM_DEFAULT_POLARITY;    //初始化PwmDev
            hp->dev.cfg.status = PWM_DISABLE_STATUS;        //初始化PwmDev
            hp->dev.cfg.number = 0;                         //初始化PwmDev
            hp->dev.busy = false;                           //初始化PwmDev
            if (PwmDeviceAdd(obj, &(hp->dev)) != HDF_SUCCESS) {//【重要】调用核心层函数，初始化hp->dev 的设备和服务
                OsalIoUnmap((void *)hp->base);
                return HDF_FAILURE;
            }
            return HDF_SUCCESS;
        }
        ```

    -   Release 函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。

        ```
        static void HdfPwmRelease(struct HdfDeviceObject *obj)
        {
            struct HiPwm *hp = NULL;
            ...
            hp = (struct HiPwm *)obj->service;//这里有HdfDeviceObject到HiPwm的强制转化
            ...
            PwmDeviceRemove(obj, &(hp->dev));//【必要】调用核心层函数，释放PwmDev的设备和服务,这里有HiPwm到PwmDev的强制转化
            HiPwmRemove(hp);                 //释放HiPwm
        }
        ```



