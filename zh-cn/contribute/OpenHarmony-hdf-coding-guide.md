# OpenHarmony HDF驱动编程规范

## 前言

### 目的

OpenHarmony的目标是面向全场景、全连接、全智能时代，基于开源的方式，搭建一个智能终端设备操作系统的框架和平台，促进万物互联产业的繁荣发展。具有“硬件互助，资源共享”、“一次开发，多端部署”、“统一OS，弹性部署”的技术特性。

HDF（Hardware Driver Foundation）驱动框架，为开发者提供驱动框架能力，包括驱动加载、驱动服务管理和驱动消息机制。旨在构建统一的驱动架构平台，为开发者提供更精准、更高效的开发环境，力求做到一次开发，多系统部署。

因此，对基于HDF实现的OpenHarmony驱动代码需要有一定的编程规约，以满足驱动代码的“一次开发，多端部署”技术特性。本文以此为初衷，结合OpenHarmony和HDF的特点，拟定了相关编程规约，用于指导驱动代码的开发编码，提升代码的规范性及可移植性，供开发者参考。

## 编程规范

### 总则

#### 【规则】OpenHarmony的驱动程序，应当使用HDF框架提供的能力实现

【说明】HDF驱动框架提供了驱动加载、驱动服务管理和驱动消息机制，同时还提供了操作系统抽象层(OSAL, Operating System Abstraction Layer)和平台抽象层(PAL, Platform Abstraction Layer)来保证驱动程序的跨系统跨平台部署的特性。除此之外，HDF提供了驱动模型的抽象、公共工具、外围器件框架等能力。开发者应该基于HDF提供的这些能力开发驱动，从而保证驱动程序可以在各种形态的OpenHarmony上进行部署。

#### 【规则】开发者应当遵循此规范要求，开发能够同时满足内核态和用户态的驱动

【说明】内核态驱动与用户态驱动天然存在着差异，两种形态适用的场景也不尽相同。开发者在业务设计和开发的时候应当遵循此规范，使用HDF提供的OSAL、PAL等特性来屏蔽形态的差异，来保证开发的驱动同时满足内核态和用户态。

#### 【建议】使用HDF框架时，编译脚本应当包含drivers/framework/include目录，而不是子模块目录

【说明】drivers/framework/include目录是HDF对外暴露的头文件根目录，此目录下面按照功能划分为核心框架、OSAL和PAL等多个子模块目录。在使用对应头文件时，建议编译脚本包含到drivers/framework/include目录，这样在代码中进行引用时，可以避免重复包含，也便于区分对应子模块，达到驱动范围内的统一。

【样例】

```gn
config("xxxx_private_config") {
  include_dirs = [
    "//drivers/framework/include",
    "//drivers/framework/include/core", # 不建议
  ]
}
```

```c
#include <core/hdf_device_desc.h>
#include <hdf_device_desc.h> // 不建议
```

### HDF核心框架

#### 【规则】应当按照驱动入口对象HdfDriverEntry中的职责定义来实现Bind、Init和Release方法，避免职责不单一引入问题

【说明】HdfDriverEntry对象是HDF驱动的入口，其中的三个方法指针均有各自的职责，开发者需按照方法职责来实现对应函数。

```c
struct HdfDriverEntry g_sampleDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "sample_driver",
    .Bind = SampleDriverBind, // 职责：绑定驱动对外提供的服务接口到HDF
    .Init = SampleDriverInit, // 职责：初始化驱动自身的业务
    .Release = SampleDriverRelease, // 职责：释放驱动资源，发生异常时也会调用
};

HDF_INIT(g_sampleDriverEntry);
```

#### 【规则】驱动服务的结构定义，首个成员必须是IDeviceIoService类型

【说明】HDF框架内部实现约束，驱动定义的服务接口，首个成员必须是IDeviceIoService类型。

【样例】

```c
struct ISampleDriverService {
    struct IDeviceIoService ioService; // 首个成员必须是IDeviceIoService类型
    int32_t (*FunctionA)(void); // 驱动的第一个服务接口
    int32_t (*FunctionB)(uint32_t inputCode); // 驱动的第二个服务接口，可以依次往下累加
};
```

【样例】

```c
struct ISampleDriverService {
    struct IDeviceIoService ioService; // 首个成员必须是IDeviceIoService类型
    void *instance; // 也可以封装服务实例，在实例中提供服务接口
};
```

#### 【规则】在HdfDriverEntry的Bind方法中，必须完成全部驱动服务接口的绑定，禁止将服务接口未定义或定义为空

【说明】驱动定义的服务接口，均是对外暴露的，如果未定义或定义为空，可能会导致外部调用时产生异常，从而降低驱动的可靠性。

【样例】

```c
int32_t SampleDriverBind(struct HdfDeviceObject *deviceObject)
{
    static struct ISampleDriverService sampleDriver = {
        .FunctionA = SampleDriverServiceA,
        .FunctionB = NULL, // 禁止定义为空
    };
    // 将ioService与HDF创建的设备对象进行绑定
    deviceObject->service = &sampleDriver.ioService;
    return HDF_SUCCESS;
}
```

#### 【建议】在HdfDriverEntry的Init方法中，应当调用HdfDeviceSetClass接口，对驱动的类型进行定义

【说明】驱动的类型可以用于归类当前设备的驱动程序，也可以用来查询当前设备的驱动能力。为了便于后续驱动的统一管理，建议通过HdfDeviceSetClass接口来设置当前驱动的类型。

【样例】

```c
int32_t SampleDriverInit(struct HdfDeviceObject *deviceObject)
{
    // 设置驱动的类型为DISPLAY
    if (!HdfDeviceSetClass(deviceObject, DEVICE_CLASS_DISPLAY)) {
        HDF_LOGE("HdfDeviceSetClass failed");
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}
```

### HCS配置规范

HCS(HDF Configuration Source)是HDF驱动框架的配置描述源码，内容以Key-Value为主要形式。它实现了配置代码与驱动代码解耦，便于开发者进行配置管理。

驱动配置包含两部分，HDF框架定义的驱动设备描述和驱动的私有配置信息。

**设备描述信息**

HDF框架加载驱动所需要的信息来源于HDF框架定义的驱动设备描述，因此基于HDF框架开发的驱动必须要在HDF框架定义的device_info.hcs配置文件中添加对应的设备描述。

#### 【规则】在进行驱动设备配置之前，应当明确驱动所属的硬件和部署形态，规划需要配置的目录和文件

【说明】在OpenHarmony源码的vendor目录下，按照芯片厂商、开发板、配置的目录进行规划，HDF驱动的配置位于hdf_config目录下。根据硬件规格，此hdf_config目录下存放内核态配置信息或者分别内核态和用户态的配置信息。开发者应当根据驱动所属的硬件和部署形态，确定在哪一个目录下进行配置。

【样例】

```bash
$openharmony_src_root/vendor/hisilicon/hispark_taurus/hdf_config # 内核态配置文件目录，无用户态

$openharmony_src_root/vendor/hisilicon/hispark_taurus_standard/hdf_config/khdf # 内核态配置文件目录
$openharmony_src_root/vendor/hisilicon/hispark_taurus_standard/hdf_config/uhdf # 用户态配置文件目录
$openharmony_src_root/vendor/hisilicon/hispark_taurus_standard/hdf_config/khdf/device_info/device_info.hcs # 内核态驱动设备描述配置文件
$openharmony_src_root/vendor/hisilicon/hispark_taurus_standard/hdf_config/khdf/lcd/lcd_config.hcs # 内核态驱动私有配置文件
```

#### 【规则】驱动设备在配置时，应当充分使用已有的配置信息，继承已有的配置模板

【说明】在HDF框架定义的device_info.hcs配置文件中，已经配置好了host、device和deviceNode的模板，开发者在配置驱动设备时，应该充分利用已有配置信息和HCS的继承特性，减少重复的配置工作量。

【样例】

```
root {
    device_info {
        match_attr = "hdf_manager";
        template host { // host模板
            hostName = "";
            priority = 100; // host启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证host的加载顺序
            template device { // device模板
                template deviceNode { // deviceNode模板
                    policy = 0; // policy字段是驱动服务发布的策略
                    priority = 100; // 驱动启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证device的加载顺序
                    preload = 0; // 驱动按需加载字段
                    permission = 0664; // 驱动创建设备节点权限
                    moduleName = "";
                    serviceName = "";
                    deviceMatchAttr = "";
                }
            }
        }
        // 继承模板的节点如果使用模板中的默认值，则节点字段可以缺省
        sample_host :: host { // sample_host继承了host模板
            hostName = "host0"; // host名称，host节点是用来存放某一类驱动的容器
            device_sample :: device { // device_sample继承了device模板
                device0 :: deviceNode { // device0继承了deviceNode模板
                    policy = 1; // 覆写了模板中的policy值
                    moduleName = "sample_driver"; // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
                    serviceName = "sample_service"; // 驱动对外发布服务的名称，必须唯一
                    deviceMatchAttr = "sample_config"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等
                }
            }
        }
    }
}
```

#### 【规则】驱动模型的设计和归类应当满足业务需要和既定类型，禁止重复配置Host和Device

【说明】HDF框架将一类设备驱动放在同一个Host里面，开发者也可以将Host中的驱动功能分层独立开发和部署，支持一个驱动多个Node，HDF驱动模型如下图所示：

![HDF驱动模型.png](figures/HDF驱动模型.png)

开发者应当将同一类的设备放在同一个Host里面，在新增设备时，检查是否已经存在同类型的Host。如果已存在Host，则将Device配置在此Host中，禁止重复配置Host。一个驱动设备应该只属于一类驱动类型，因此也禁止将同一个Device配置在不同Host当中。

#### 【规则】驱动服务必须按照业务规则设置对外发布的策略，禁止设置不必要的发布策略

【说明】驱动服务是HDF驱动设备对外提供能力的对象，由HDF框架统一管理。HDF框架定义了驱动对外发布服务的策略，是由配置文件中的policy字段来控制，policy字段的取值范围以及含义如下：

```c
typedef enum {
    /* 驱动不提供服务 */
    SERVICE_POLICY_NONE = 0,
    /* 驱动对内核态发布服务 */
    SERVICE_POLICY_PUBLIC = 1,
    /* 驱动对内核态和用户态都发布服务 */
    SERVICE_POLICY_CAPACITY = 2,
    /* 驱动服务不对外发布服务，但可以被订阅 */
    SERVICE_POLICY_FRIENDLY = 3,
    /* 驱动私有服务不对外发布服务，也不能被订阅 */
    SERVICE_POLICY_PRIVATE = 4,
    /* 错误的服务策略 */
    SERVICE_POLICY_INVALID
} ServicePolicy;
```

因此，驱动服务应该按照业务规则来设置发布策略，禁止设置不必要的发布策略，如内核态驱动设置用户态的发布策略。

【样例】

```
root {
    device_info {
        sample_host {
            sample_device {
                device0 {
                    policy = 1; // 驱动对内核态发布服务
                    ...
                }
            }
        }
    }
}
```

#### 【规则】驱动创建设备节点权限必须与驱动的发布规则互相匹配

【说明】在HDF框架定义的device_info.hcs配置文件中，permission为驱动创建的设备节点权限字段。该字段的取值使用Unix文件权限的八进制数字模式来表示，长度为4位，例如0644。permission字段仅在驱动服务对用户态发布服务时（即policy = 2）才会生效。

开发者应当保证驱动服务的发布策略与设备节点的权限互相匹配，否则可能会导致驱动服务无法访问或设备节点的权限被放大。

【样例】

```
root {
    device_info {
        sample_host {
            sample_device {
                device0 {
                    policy = 2; // 驱动对内核态和用户态都发布服务
                    permission = 0640; // 建议值
                    ...
                }
            }
        }
    }
}
```

【反例】

```
root {
    device_info {
        sample_host {
            sample_device {
                device0 {
                    policy = 2; // 驱动对内核态和用户态都发布服务
                    permission = 0777; // 权限过大
                    ...
                }
            }
        }
    }
}
```

【反例】

```
root {
    device_info {
        sample_host {
            sample_device {
                device0 {
                    policy = 1; // 驱动对内核态发布服务，不会创建设备节点
                    permission = 0640; // 冗余配置
                    ...
                }
            }
        }
    }
}
```

#### 【规则】应当根据业务要求配置是否按需加载

【说明】在HDF框架定义的device_info.hcs配置文件中，preload为驱动按需加载字段，取值的范围见如下枚举：

```c
typedef enum {
    /* 系统启动时默认加载 */
    DEVICE_PRELOAD_ENABLE = 0,
    /* 当系统支持快启时，则在快启完成后再加载；如果系统不支持快启，与DEVICE_PRELOAD_ENABLE含义相同 */
    DEVICE_PRELOAD_ENABLE_STEP2,
    /* 系统启动时默认不加载，当使用时HDF框架会尝试动态加载 */
    DEVICE_PRELOAD_DISABLE,
    /* 无效值 */
    DEVICE_PRELOAD_INVALID
} DevicePreload;
```

开发者应当根据驱动的业务要求，将preload字段配置为相应的值，从而HDF框架可以按照preload规则进行驱动的加载。

【样例】

```
root {
    device_info {
        sample_host {
            sample_device {
                device0 {
                    preload = 2; // 使用时按需加载
                    ...
                }
            }
        }
    }
}
```

#### 【建议】当preload字段配置为默认加载时，应当根据业务要求配置按序加载的优先级

【说明】在HDF框架定义的device_info.hcs配置文件中，priority字段（取值范围为整数0到200）是用来表示Host和驱动的优先级。不同的Host内的驱动，Host的priority值越小，驱动加载优先级越高；同一个Host内驱动的priority值越小，加载优先级越高。priority字段的默认值为100，当未配置或字段值相同时，HDF框架将不保证驱动的加载顺序。开发者应当根据业务场景的要求，配置priority字段，保证各个驱动的启动顺序。

【样例】

```
root {
    device_info {
        sample_host0 {
        priority = 100;
            sample_device {
                device0 {
                    preload = 0; // 默认加载
                    priority = 100; // HDF保证在device1之前加载
                    ...
                }
                device1 {
                    preload = 0; // 默认加载
                    priority = 200; // HDF保证在device0之后加载
                    ...
                }
            }
        }
        sample_host1 {
            priority = 100; // 由于与sample_host0的优先级相同，HDF将不保证加载顺序
            ...
        }
    }
}
```

**驱动私有配置信息**

如果驱动有私有配置，则可以添加一个驱动的配置文件，用来填写一些驱动的默认配置信息，HDF框架在加载驱动的时候，会将对应的配置信息获取并保存在HdfDeviceObject中的property里面，通过Bind和Init传递给驱动。

#### 【规则】驱动私有配置文件应当按照器件类型或者模块进行目录划分，并放置在相应的目录下

【说明】开发者应当对驱动的私有配置文件进行合理的目录规划，禁止将私有配置文件放置在配置的根目录下。

【样例】

```bash
$openharmony_src_root/vendor/hisilicon/hispark_taurus_standard/hdf_config/khdf/sample/sample_config.hcs # 正确，将私有配置文件放置在了sample目录下

$openharmony_src_root/vendor/hisilicon/hispark_taurus_standard/hdf_config/khdf/sample_config.hcs # 错误，将私有配置文件放置在了配置根目录下
```

#### 【规则】应当将驱动私有配置文件包含到hdf_config配置目录下的hdf.hcs文件中

【说明】hdf.hcs文件是配置信息的汇总文件，在HDF编译和运行时，将会解析此文件中的内容，加载驱动的私有配置信息到驱动的设备节点中。开发者应当保证hdf.hcs文件中包含了驱动的私有配置文件，从而保证驱动能够正确初始化。

【样例】

```c
#include "device_info/device_info.hcs"
#include "sample/sample_config.hcs" // 包含驱动私有配置文件

root {
    module = "hisilicon,hi35xx_chip";
}
```

#### 【规则】驱动私有配置信息中的matchAttr字段值，必须与device_info.hcs中配置的deviceMatchAttr字段值一致

【说明】HDF框架会通过match_attr字段的值，来与驱动设备进行关联。如果配置错误，将导致私有配置信息无法获取。

【样例】

```
root {
    sample_config {
        ...
        match_attr = "sample_config"; // 该字段的值必须和device_info.hcs中的deviceMatchAttr值一致
    }
}
```

#### 【规则】驱动私有配置信息中的字段名，使用下划线命名法

【说明】由于C/C++语言编程指导的命名规则要求，驱动的私有配置信息中的字段名，应当使用下划线命名法。这样，在实现代码中对私有配置数据结构进行定义时，可以满足命名规则，也便于代码和配置文件的统一管理。

【样例】

```
root {
    sample_config {
        sample_version = 1; // 使用下划线命名
        sample_bus = "I2C_0";
        match_attr = "sample_config";
    }
}
```

### HCS宏

驱动的私有配置信息会被加载到HdfDeviceObject中的property中，因此会占用一定的内存空间，这在轻量和小型系统中带来的缺点尤为明显。为了减少私有配置信息的内存占用，HDF框架提供了HCS宏，来解析驱动的私有配置信息。

#### 【规则】在内存敏感或跨系统类型的驱动场景下，应当使用HCS宏来解析驱动的私有配置信息

【说明】开发者应当明确驱动的使用场景，如果对内存敏感或者需要跨轻量、小型和标准系统使用，应当使用HCS宏来解析驱动的私有配置信息，从而保证驱动的性能和可移植性。

【样例】

```c
#include <utils/hcs_macro.h>

#define SAMPLE_CONFIG_NODE HCS_NODE(HCS_ROOT, sample_config)

ASSERT_EQ(HCS_PROP(SAMPLE_CONFIG_NODE, sampleVersion), 1);
ASSERT_EQ(HCS_PROP(SAMPLE_CONFIG_NODE, sample_bus), "I2C_0");
ASSERT_EQ(HCS_PROP(SAMPLE_CONFIG_NODE, match_attr), "sample_config");
```

### HDF工具

#### 【规则】在使用HdfSbuf进行数据通信时，应当明确通信的场景，并根据相应场景确定创建的HdfSbuf类型

【说明】HdfSbuf是HDF进行数据传输时的数据结构，此结构根据通信的场景区分为不同的类型，定义在hdf_sbuf.h头文件的枚举中：

```c
enum HdfSbufType {
    SBUF_RAW = 0,   /* SBUF used for communication between the user space and the kernel space */
    SBUF_IPC,      /* SBUF used for inter-process communication (IPC) */
    SBUF_IPC_HW,    /* Reserved for extension */
    SBUF_TYPE_MAX,  /* Maximum value of the SBUF type */
};
```

开发者在进行数据通信时，应当明确是跨用户态和内核态通信场景，还是用户态的进程间通信，从而创建相应的HdfSbuf。

【样例】

```c
void SampleDispatchBetweenUserAndKernel()
{
    int32_t ret;
    /* 跨用户态和内核态进行通信的场景 */
    struct HdfSBuf *data = HdfSBufTypedObtain(SBUF_RAW);
    ...
    ret = sample->dispatcher->Dispatch(&sample->object, CMD_SAMPLE_DISPATCH, data, NULL);
    ...
    HdfSBufRecycle(data);
}
```

【样例】

```c++
void SampleDispatchIpc()
{
    /* 跨进程进行通信的场景 */
    struct HdfSBuf *data = HdfSBufTypedObtain(SBUF_IPC);
    ...
    int ret = sample->dispatcher->Dispatch(sample, CMD_SAMPLE_DISPATCH, data, nullptr);
    ...
    HdfSBufRecycle(data);
}
```

#### 【规则】在使用HDF的日志打印时，应当明确定义HDF_LOG_TAG日志打印的标签

【说明】HDF框架提供了一套日志打印工具hdf_log.h，开发者可以直接使用HDF的日志打印进行驱动运行日志的输出。HDF_LOG_TAG宏的作用是定义日志打印的标签，开发者必须在打印日志前进行定义。

【样例】

```c
#include <hdf_log.h>

#define HDF_LOG_TAG sample_driver // 定义日志的标签

int32_t SampleDriverInit(struct HdfDeviceObject *deviceObject)
{
    HDF_LOGI("sample driver is initialized"); // 使用HDF日志工具打印日志
    return HDF_SUCCESS;
}
```

#### 【规则】应当对HDF框架方法的返回值进行有效判断，并使用HDF提供的错误码

【说明】HDF框架提供的方法有明确的错误码返回值，开发者在使用时应当进行判断，而不是选择忽略。对应的返回值为hdf_base.h头文件中的错误码，开发者在使用HDF或实现自定义方法时，应当统一使用HDF提供的错误码。

【样例】

```c
int32_t SampleDriverInit(struct HdfDeviceObject *deviceObject)
{
    int32_t ret;
    // 判断设备类型设置是否成功
    if (!HdfDeviceSetClass(deviceObject, DEVICE_CLASS_DISPLAY)) {
        HDF_LOGE("HdfDeviceSetClass failed");
        return HDF_FAILURE;
    }
    ret = InitDiver();
    // 自定义方法使用HDF的错误码
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("init driver is failed");
        return ret;
    }
    return HDF_SUCCESS;
}
```

### OSAL框架

HDF OSAL框架屏蔽了OpenHarmony各个系统类型之间的接口差异，对外提供统一的OS接口，包括内存管理、线程、互斥体、自旋锁、信号量、定时器、文件、中断、时间、原子、固件、I/O操作模块。

#### 【规则】跨轻量、小型和标准系统类型的驱动，必须通过OSAL框架来使用操作系统接口

【说明】OSAL屏蔽了OS接口之间的差异，开发者应当基于OSAL来操作OS的接口，保证驱动能够跨系统类型运行。

【样例】

```c
#include <osal/osal_mem.h>
#include <util/hdf_log.h>

struct DevHandle *SampleInit(void)
{
    struct DevHandle *handle = (struct DevHandle *)OsalMemCalloc(sizeof(struct DevHandle));
    if (handle == NULL) {
        HDF_LOGE("OsalMemCalloc handle failed");
        return NULL;
    }
    return handle;
}
```

【样例】

```c
#include <osal/osal_time.h>

void SampleSleep(uint32_t timeMs)
{
    OsalMSleep(timeMs);
}
```

### PAL框架

HDF PAL框架对平台类驱动进行了抽象，并对外提供统一的操作接口，包括GPIO、I2C、SPI、UART、RTC、SDIO、EMMC、DSI、PWM、WATCHDOG等模块。

#### 【规则】跨轻量、小型和标准系统类型的驱动，必须通过PAL框架来使用平台驱动

【说明】PAL屏蔽了不同系统类型之间的平台驱动接口差异，开发者应当基于PAL来操作这些接口，保证驱动能够跨系统类型运行。

【样例】

```c
#include <platform/gpio_if.h>
#include <util/hdf_log.h>
#include <osal/osal_irq.h>
#include <osal/osal_time.h>

static uint32_t g_irqCnt;

/* GPIO中断服务样例函数 */
static int32_t SampleGpioIrqHandler(uint16_t gpio, void *data)
{
    HDF_LOGE("%s: irq triggered, on gpio:%u, data=%p", __func__, gpio, data);
    g_irqCnt++; // 如果中断服务函数触发执行，则将全局中断计数加1
    return GpioDisableIrq(gpio);
}

/* GPIO样例函数 */
static int32_t SampleGpioIrqEdge(void)
{
    int32_t ret;
    uint16_t valRead;
    uint16_t mode;
    uint16_t gpio = 83; // 待测试的GPIO管脚号
    uint32_t timeout;

    /* 将管脚方向设置为输出 */
    ret = GpioSetDir(gpio, GPIO_DIR_OUT);
    ...
    /* 禁止该管脚中断 */
    ret = GpioDisableIrq(gpio);
    ...
    /* 为管脚设置中断服务函数，触发模式为上升沿和下降沿共同触发 */
    mode = OSAL_IRQF_TRIGGER_RISING | OSAL_IRQF_TRIGGER_FALLING;
    ret = GpioSetIrq(gpio, mode, SampleGpioIrqHandler, NULL);
    ...
    /* 使能此管脚中断 */
    ret = GpioEnableIrq(gpio);
    ...
    g_irqCnt = 0; // 清除全局计数器
    timeout = 0;  // 等待时间清零
    /* 等待此管脚中断服务函数触发，等待超时时间为1000毫秒 */
    while (g_irqCnt <= 0 && timeout < 1000) {
        ret = GpioRead(gpio, &valRead);
        ...
        ret = GpioWrite(gpio, (valRead == GPIO_VAL_LOW) ? GPIO_VAL_HIGH : GPIO_VAL_LOW);
        ...
        OsalMDelay(200); // 等待中断触发
        timeout += 200;
    }
    ret = GpioUnSetIrq(gpio);
    ...
    return (g_irqCnt > 0) ? HDF_SUCCESS : HDF_FAILURE;
}
```
