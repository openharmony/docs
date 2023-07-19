# HDF驱动开发流程

## 概述

HDF（Hardware Driver Foundation）驱动框架，为驱动开发者提供驱动框架能力，包括驱动加载、驱动服务管理、驱动消息机制和配置管理。并以组件化驱动模型作为核心设计思路，让驱动开发和部署更加规范，旨在构建统一的驱动架构平台，为驱动开发者提供更精准、更高效的驱动管理的开发环境，力求做到一次开发，多系统部署。

### 驱动加载

HDF驱动框架提供把和配置的设备列表匹配成功的驱动程序加载起来的功能。

### 驱动服务管理

HDF框架可以集中管理驱动服务，开发者可直接通过HDF框架对外提供的能力接口获取驱动相关的服务。

### 驱动消息机制

HDF框架提供统一的驱动消息机制，支持用户态应用向内核态驱动发送消息，也支持内核态驱动向用户态应用发送消息。

### 配置管理

HCS（HDF Configuration Source）是HDF驱动框架的配置描述源码，内容以Key-Value为主要形式。它实现了配置代码与驱动代码解耦，便于开发者进行配置管理。

### 驱动模型

HDF框架将一类设备驱动放在同一个Host（设备容器）里面，用于管理一组设备的启动加载等过程。在划分Host时，驱动程序是部署在一个Host还是部署在不同的Host，主要考虑驱动程序之间是否存在耦合性，如果两个驱动程序之间存在依赖，可以考虑将这部分驱动程序部署在一个Host里面，否则部署到独立的Host中是更好的选择。Device对应一个真实的物理设备。DeviceNode是设备的一个部件，Device至少有一个DeviceNode。每个DeviceNode可以发布一个设备服务。驱动即驱动程序，每个DevicdNode唯一对应一个驱动，实现和硬件的功能交互。HDF驱动模型如下图所示：

**图1** HDF驱动模型

![](figures/HDF驱动模型.png)

## 功能描述

### 驱动加载

HDF驱动框架提供把和配置的设备列表匹配成功的驱动程序加载起来的功能，支持按需加载和按序加载两种策略，具体设备的加载策略由配置文件中的preload字段来控制，配置值参考如下：

```c
typedef enum {
    DEVICE_PRELOAD_ENABLE = 0,
    DEVICE_PRELOAD_ENABLE_STEP2 = 1,
    DEVICE_PRELOAD_DISABLE = 2,
    DEVICE_PRELOAD_INVALID
} DevicePreload;
```

#### 按需加载

- preload字段配置为0（DEVICE_PRELOAD_ENABLE），则系统启动过程中默认加载。
- preload字段配置为1（DEVICE_PRELOAD_ENABLE_STEP2），当系统支持快速启动的时候，则在系统完成之后再加载这一类驱动，否则和DEVICE_PRELOAD_ENABLE含义相同。
- preload字段配置为2（DEVICE_PRELOAD_DISABLE），则系统启动过程中默认不加载，支持后续动态加载，当用户态获取驱动服务[消息机制](#驱动消息机制管理)时，如果驱动服务不存在，HDF框架会尝试动态加载该驱动。

#### 按序加载（默认加载策略）

配置文件中的priority（取值范围为整数0到200）是用来表示host（驱动容器）和驱动的优先级的。不同的host内的驱动，host的priority值越小，驱动加载优先级越高；同一个host内驱动的priority值越小，加载优先级越高。

#### 异常恢复（用户态驱动）

当驱动服务异常退出时，恢复策略如下：
- preload字段配置为0（DEVICE_PRELOAD_ENABLE）或1（DEVICE_PRELOAD_ENABLE_STEP2）的驱动服务，由启动模块拉起host并重新加载服务。
- preload字段配置为2（DEVICE_PRELOAD_DISABLE）的驱动服务，需业务模块注册HDF的服务状态监听器，当收到服务退出消息时，业务模块调用LoadDevice重新加载服务。

### 驱动服务管理

驱动服务是HDF驱动设备对外提供能力的对象，由HDF框架统一管理。驱动服务管理主要包含驱动服务的发布和获取。HDF框架定义了驱动对外发布服务的策略，由配置文件中的policy字段来控制，policy字段的取值范围以及含义如下：

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

#### 使用场景

当驱动需要以接口的形式对外提供能力时，可以使用HDF框架的驱动服务管理能力。

#### 接口说明

针对驱动服务管理功能，HDF框架开放了以下接口供开发者调用，如下表所示：

**表1** 服务管理接口

| 方法                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int32_t (*Bind)(struct HdfDeviceObject *deviceObject)        | 需要驱动开发者实现Bind函数，将自己的服务接口绑定到HDF框架中。 |
| const struct HdfObject *DevSvcManagerClntGetService(const char *svcName) | 获取驱动的服务。                                             |
| int HdfDeviceSubscribeService( struct HdfDeviceObject *deviceObject, const char *serviceName, struct SubscriberCallback callback) | 订阅驱动的服务。                                             |


### 驱动消息机制管理

#### 使用场景

当用户态应用和内核态驱动需要交互时，可以使用HDF框架的消息机制来实现。

#### 接口说明

消息机制的功能主要有以下两种：
- 用户态应用发送消息到驱动。
- 用户态应用接收驱动主动上报事件。

**表2** 消息机制接口

| 方法                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| struct HdfIoService *HdfIoServiceBind(const char *serviceName); | 用户态获取驱动的服务，获取该服务之后通过服务中的Dispatch方法向驱动发送消息。 |
| void HdfIoServiceRecycle(struct HdfIoService *service);      | 释放驱动服务。                                               |
| int HdfDeviceRegisterEventListener(struct HdfIoService *target, struct HdfDevEventlistener *listener); | 用户态程序注册接收驱动上报事件的操作方法。                   |
| int32_t HdfDeviceSendEvent(const struct HdfDeviceObject *deviceObject, uint32_t id, const struct HdfSBuf *data) | 驱动主动上报事件接口。                                       |



### 配置管理

#### 配置概述

HCS（HDF Configuration Source）是HDF驱动框架的配置描述源码，内容以Key-Value为主要形式。它实现了配置代码与驱动代码解耦，便于开发者进行配置管理。HC-GEN（HDF Configuration Generator）是HCS配置转换工具，可以将HDF配置文件转换为软件可读取的文件格式：

-   在弱性能环境中，转换为配置树源码或配置树宏定义，驱动可直接调用C代码或宏式APIs获取配置。
-   在高性能环境中，转换为HCB（HDF Configuration Binary）二进制文件，驱动可使用HDF框架提供的配置解析接口获取配置。

以下是使用HCB模式的典型应用场景：

**图2** 配置使用流程图

![](figures/配置使用流程图.png)

HCS经过HC-GEN编译生成HCB文件，HDF驱动框架中的HCS Parser模块会从HCB文件中重建配置树，HDF驱动模块使用HCS Parser提供的配置读取接口获取配置内容。

#### 配置语法

HCS的语法介绍如下：

##### 关键字

HCS配置语法保留了以下关键字。

**表3** HCS配置语法保留关键字

| 关键字     | 用途                       | 说明                                       |
| ---------- | -------------------------- | ------------------------------------------ |
| root       | 配置根节点                 | -                                          |
| include    | 引用其他HCS配置文件        | -                                          |
| delete     | 删除节点或属性             | 只能用于操作include导入的配置树            |
| template   | 定义模板节点               | -                                          |
| match_attr | 用于标记节点的匹配查找属性 | 解析配置时可以使用该属性的值查找到对应节点 |

##### 基本结构

HCS主要分为属性（Attribute）和节点（Node）两种结构。

**属性**

属性即最小的配置单元，是一个独立的配置项。语法如下：

```
  attribute_name = value;
```

-   attribute_name是**字母、数字、下划线**的组合且必须以字母或下划线开头，字母区分大小写。
-   value的可用格式如下：
    -   数字常量，支持二进制、八进制、十进制、十六进制数，具体[数据类型](#数据类型)章节。
    -   字符串，内容使用双引号("")引用。
    -   节点引用。
-   attribute必须以分号（;）结束且必须属于一个node。

**节点**

节点是一组属性的集合，语法如下：

```
  node_name {
      module = "sample";
      ...
  }
```

-   node_name是**字母、数字、下划线**的组合且必须以字母或下划线开头，字母区分大小写。
-   大括号后无需添加结束符“;”。
-   root为保留关键字，用于声明配置表的根节点。每个配置表必须以root节点开始。
-   root节点中必须包含module属性，其值应该为一个字符串，用于表征该配置所属模块。
-   节点中可以增加match_attr属性，其值为一个全局唯一的字符串。当驱动程序在解析配置时可以以该属性的值为参数调用查找接口查找到包含该属性的节点。

##### 数据类型

在属性定义中使用自动数据类型，不显式指定类型，属性支持的数据类型如下：

**整型**

整型长度自动推断，根据实际数据长度给与最小空间占用的类型。

-   二进制，0b前缀，示例：0b1010。
-   八进制，0前缀，示例：0664。
-   十进制 ，无前缀，且支持有符号与无符号，示例：1024，+1024均合法。驱动程序在读取负值时注意使用有符号数读取接口。
-   十六进制，0x前缀，示例：0xff00、0xFF。

**字符串**

字符串使用双引号（""）表示。

**数组**

数组元素支持整型、字符串，不支持混合类型。整型数组中uint32_t uint64_t混用会向上转型为uint64_t数组。整型数组与字符串数组示例如下：

```
attr_foo = [0x01, 0x02, 0x03, 0x04];
attr_bar = ["hello", "world"];
```

**bool类型**

bool类型中**true**表示真，**false**表示假。

##### 预处理

**include**

用于导入其他HCS文件。语法示例如下：

```
#include "foo.hcs"
#include "../bar.hcs"
```

-   文件名必须使用双引号（""），不在同一目录使用相对路径引用。被include文件也必须是合法的HCS文件。
-   多个include，如果存在相同的节点，后者覆盖前者，其余的节点依次展开。

##### 注释

支持两种注释风格。

-   单行注释。

    ```
    // comment
    ```

-   多行注释。

    ```
    /*
    comment
    */
    ```

    >   ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
    >   多行注释不支持嵌套。

##### 引用修改

引用修改的作用是在当前节点中修改另外任意一个节点的内容，语法为：

```
 node :& source_node
```

上述语句表示node中的内容是对source_node节点内容的修改。示例如下：

```
root {
    module = "sample";
    foo {
        foo_ :& root.bar{
            attr = "foo";
        }
        foo1 :& foo2 {
            attr = 0x2;
        }
        foo2 {
            attr = 0x1;
        }
    }

    bar {
        attr = "bar";
    }
}
```

最终生成配置树为：

```
root {
    module = "sample";
    foo {
        foo2 {
            attr = 0x2;
        }
    }
    bar {
        attr = "foo";
    }
}
```

在以上示例中，可以看到foo.foo_节点通过引用将bar.attr属性的值修改为了"foo"，foo.foo1节点通过引用将foo.foo2.attr属性的值修改为了0x2。foo.foo_以及foo.foo1节点表示对目标节点内容的修改，其自身并不会存在最终生成的配置树中。

-   引用同级node，可以直接使用node名称，否则被引用的节点必须使用绝对路径，节点间使用“.”分隔，root表示根节点，格式为root开始的节点路径序列，例如root.foo.bar即为一个合法的绝对路径。
-   如果出现修改冲突（即多处修改同一个属性），编译器将提示warning，因为这种情况下只会生效某一个修改而导致最终结果不确定。

##### 节点复制

节点复制可以实现在节点定义时从另一个节点先复制内容，用于定义内容相似的节点。语法为：

```
 node : source_node
```

上述语句表示在定义"node"节点时将另一个节点"source_node"的属性复制过来。示例如下：

```
root {
    module = "sample";
    foo {
        attr_0 = 0x0;
    }
    bar:foo {
        attr_1 = 0x1;
    }
}
```

上述代码的最终生成配置树为：

```
root {
    module = "sample";
    foo {
        attr_0 = 0x0;
    }
    bar {
        attr_1 = 0x1;
        attr_0 = 0x0;
    }
}
```

在上述示例中，编译后bar节点既包含attr_0属性又包含attr_1属性，在bar中对attr_0的修改不会影响到foo。

当foo和bar在同级node中时可不指定foo的路径，否则需要使用绝对路径引用，绝对路径的介绍请参考[引用修改](#引用修改)。

##### 删除

要对include导入的base配置树中不需要的节点或属性进行删除，可以使用delete关键字。下面的举例中sample1.hcs通过include导入了sample2.hcs中的配置内容，并使用delete删除了sample2.hcs中的attribute2属性和foo_2节点，示例如下：

```
// sample2.hcs
root {
    attr_1 = 0x1;
    attr_2 = 0x2;
    foo_2 {
        t = 0x1;
    }
}

// sample1.hcs
#include "sample2.hcs"
root {
    attr_2 = delete;
    foo_2 : delete {
    }
}
```

上述代码在生成过程中将会删除root.foo_2节点与attr_2，最终生成配置树为：

```
root {
    attr_1 = 0x1;
}
```

>   ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>   在同一个HCS文件中不允许使用delete，建议直接删除不需要的属性。

##### 属性引用

为了在解析配置时快速定位到关联的节点，可以把节点作为属性的右值，通过读取属性查找到对应节点。语法为：

```
 attribute = &node；
```

上述语句表示attribute的值是一个节点node的引用，在解析时可以用这个attribute快速定位到node，便于关联和查询其他node。示例如下：

```
node1 {
    attributes;
}
node2 {
    attr_1 = &root.node1;
}
```

或

```
node2 {
    node1 {
        attributes;
    }
    attr_1 = &node1;
}
```

##### 模板

模板的用途在于生成严格一致的node结构，以便对同类型node进行遍历和管理。使用template关键字定义模板node，子node通过双冒号“::”声明继承关系。子节点可以改写或新增但不能删除template中的属性，子节点中没有定义的属性将使用template中的定义作为默认值。示例如下：

```
root {
    module = "sample";
    template foo {
        attr_1 = 0x1;
        attr_2 = 0x2;
    }

    bar :: foo {
    }

    bar_1 :: foo {
        attr_1 = 0x2;
    }
}
```

​        生成配置树如下：

```
root {
    module = "sample";
    bar {
        attr_1 = 0x1;
        attr_2 = 0x2;
    }
    bar_1 {
        attr_1 = 0x2;
        attr_2 = 0x2;
    }
}
```

在上述示例中，bar和bar_1节点继承了foo节点，生成配置树节点结构与foo保持了完全一致，只是属性的值不同。

#### 配置生成

​        hc-gen是配置生成的工具，可以对HCS配置语法进行检查并把HCS源文件转化成HCB二进制文件。

**hc-gen介绍**

​        hc-gen参数说明：

```
Usage: hc-gen [Options] [File]
options:
  -o <file>   output file name, default same as input
  -a          hcb align with four bytes
  -b          output binary output, default enable
  -t          output config in C language source file style
  -m          output config in macro source file style
  -i          output binary hex dump in C language source file style
  -p <prefix> prefix of generated symbol name
  -d          decompile hcb to hcs
  -V          show verbose info
  -v          show version
  -h          show this help message
```

生成.c/.h配置文件方法：

```
hc-gen -o [OutputCFileName] -t [SourceHcsFileName]
```

生成HCB配置文件方法：

```
hc-gen -o [OutputHcbFileName] -b [SourceHcsFileName]
```

生成宏定义配置文件方法：

```
hc-gen -o [OutputMacroFileName] -m [SourceHcsFileName]
```

反编译HCB文件为HCS方法：

```
hc-gen -o [OutputHcsFileName] -d [SourceHcbFileName]
```

## 开发指导

### 场景介绍

关于驱动的开发我们主要目的是实现驱动代码的编写，但是驱动开发过程中需要服务管理、消息机制管理，才能使驱动在代码编译过程中进行加载。以下开发步骤中介绍了驱动开发、驱动消息机制管理开发、驱动服务管理开发的步骤。

### 驱动开发实例

基于HDF框架的驱动开发主要分为三个部分：驱动实现、驱动编译脚本编写和驱动配置。详细开发流程如下所示：

#### 驱动实现

驱动实现包含驱动业务代码实现和驱动入口注册，具体写法如下：

-   驱动业务代码

    ```c
    #include "hdf_device_desc.h"          // HDF框架对驱动开发相关能力接口的头文件
    #include "hdf_log.h"                  // HDF框架提供的日志接口头文件
    
    #define HDF_LOG_TAG sample_driver     // 打印日志所包含的标签，如果不定义则用默认定义的HDF_TAG标签。
    
    // 将驱动对外提供的服务能力接口绑定到HDF框架。
    int32_t HdfSampleDriverBind(struct HdfDeviceObject *deviceObject)
    {
        HDF_LOGD("Sample driver bind success");
        return HDF_SUCCESS;
    }
    
    // 驱动自身业务初始化的接口
    int32_t HdfSampleDriverInit(struct HdfDeviceObject *deviceObject)
    {
        HDF_LOGD("Sample driver Init success");
        return HDF_SUCCESS;
    }
    
    // 驱动资源释放的接口
    void HdfSampleDriverRelease(struct HdfDeviceObject *deviceObject)
    {
        HDF_LOGD("Sample driver release success");
        return;
    }
    ```

-   驱动入口注册到HDF框架

    ```c
    // 定义驱动入口的对象，必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量。
    struct HdfDriverEntry g_sampleDriverEntry = {
        .moduleVersion = 1,
        .moduleName = "sample_driver",
        .Bind = HdfSampleDriverBind,
        .Init = HdfSampleDriverInit,
        .Release = HdfSampleDriverRelease,
    };
    
    // 调用HDF_INIT将驱动入口注册到HDF框架中。在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动；当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。
    HDF_INIT(g_sampleDriverEntry);
    ```

#### 驱动编译脚本编写

-   ##### LiteOS

    涉及Makefile和BUILD.gn修改：

    -   Makefile部分：

        驱动代码的编译必须要使用HDF框架提供的Makefile模板进行编译。

        ```makefile
        include $(LITEOSTOPDIR)/../../drivers/hdf_core/adapter/khdf/liteos/lite.mk # 【必需】导入hdf预定义内容
        MODULE_NAME :=        #生成的结果文件
        LOCAL_INCLUDE :=      #本驱动的头文件目录
        LOCAL_SRCS :=         #本驱动的源代码文件
        LOCAL_CFLAGS ：=      #自定义的编译选项
        include $(HDF_DRIVER) #导入Makefile模板完成编译
        ```

        编译结果文件链接到内核镜像，添加到**drivers/hdf_core/adapter/khdf/liteos**目录下的**hdf_lite.mk**里面，示例如下：

        ```makefile
        LITEOS_BASELIB +=  -lxxx  #链接生成的静态库
        LIB_SUBDIRS    +=         #驱动代码Makefile的目录
        ```

    -   BUILD.gn部分：

        添加模块BUILD.gn，可参考如下示例：

        ```
        import("//build/lite/config/component/lite_component.gni")
        import("//drivers/hdf_core/adapter/khdf/liteos/hdf.gni")
        module_switch = defined(LOSCFG_DRIVERS_HDF_xxx)
        module_name = "xxx"
        hdf_driver(module_name) {
            sources = [
                "xxx/xxx/xxx.c",           #模块要编译的源码文件
            ]
            public_configs = [ ":public" ] #使用依赖的头文件配置
        }
        config("public") {                 #定义依赖的头文件配置
            include_dirs = [
                "xxx/xxx/xxx",             #依赖的头文件目录
            ]
        }
        ```

        把新增模块的BUILD.gn所在的目录添加到**/drivers/hdf_core/adapter/khdf/liteos/BUILD.gn**里面：

        ```
        group("liteos") {
            public_deps = [ ":$module_name" ]
            deps = [
                "xxx/xxx",#新增模块BUILD.gn所在的目录，/drivers/hdf_core/adapter/khdf/liteos
            ]
        }
        ```

-   ##### Linux

    如果需要定义模块控制宏，需要在模块目录xxx里面添加Kconfig文件，并把Kconfig文件路径添加到**drivers/hdf_core/adapter/khdf/linux/Kconfig**里面：

    ```
    source "drivers/hdf/khdf/xxx/Kconfig" #目录为hdf模块软链接到kernel里面的目录
    ```

    添加模块目录到**drivers/hdf_core/adapter/khdf/linux/Makefile**：

    ```makefile
    obj-$(CONFIG_DRIVERS_HDF)  += xxx/
    ```

    在模块目录xxx里面添加Makefile文件，在Makefile文件里面添加模块代码编译规则：

    ```makefile
    obj-y  += xxx.o
    ```

#### 驱动配置

HDF使用HCS作为配置描述源码，HCS详细介绍[配置管理](#配置概述)。

驱动配置包含两部分，HDF框架定义的驱动设备描述和驱动的私有配置信息，具体写法如下：

-   驱动设备描述（必选）

    HDF框架加载驱动所需要的信息来源于HDF框架定义的驱动设备描述，因此基于HDF框架开发的驱动必须要在HDF框架定义的device_info.hcs配置文件中添加对应的设备描述。驱动的设备描述填写如下所示：

    ```
    root {
        device_info {
            match_attr = "hdf_manager";
            template host {       // host模板，继承该模板的节点（如下sample_host）如果使用模板中的默认值，则节点字段可以缺省。
                hostName = "";
                priority = 100;
                uid = "";         // 用户态进程uid，缺省为空，会被配置为hostName的定义值，即普通用户。
                gid = "";         // 用户态进程gid，缺省为空，会被配置为hostName的定义值，即普通用户组。
                caps = [""];      // 用户态进程Linux capabilities配置，缺省为空，需要业务模块按照业务需要进行配置。
                template device {
                    template deviceNode {
                        policy = 0;
                        priority = 100;
                        preload = 0;
                        permission = 0664;
                        moduleName = "";
                        serviceName = "";
                        deviceMatchAttr = "";
                    }
                }
            }
            sample_host :: host{
                hostName = "host0";    // host名称，host节点是用来存放某一类驱动的容器。
                priority = 100;        // host启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证host的加载顺序。
                caps = ["DAC_OVERRIDE", "DAC_READ_SEARCH"];   // 用户态进程Linux capabilities配置。
                device_sample :: device {        // sample设备节点
                    device0 :: deviceNode {      // sample驱动的DeviceNode节点
                        policy = 1;              // policy字段是驱动服务发布的策略，在驱动服务管理章节有详细介绍。
                        priority = 100;          // 驱动启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证device的加载顺序。
                        preload = 0;             // 驱动按需加载字段。
                        permission = 0664;       // 驱动创建设备节点权限
                        moduleName = "sample_driver";      // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致。
                        serviceName = "sample_service";    // 驱动对外发布服务的名称，必须唯一。
                        deviceMatchAttr = "sample_config"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等。
                    }
                }
            }
        }
    }
    ```

    >   ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
    >
    >   -   uid、gid、caps等配置项是用户态驱动的启动配置，内核态不用配置。
    >   -   根据进程权限最小化设计原则，业务模块uid、gid不用配置，如上面的sample_host，使用普通用户权限，即uid和gid被定义为hostName的定义值。
    >   -   如果普通用户权限不能满足业务要求，需要把uid、gid定义为system或者root权限时，请找安全专家进行评审。
    >   -   进程的uid在文件**base/startup/init/services/etc/passwd**中配置，进程的gid在文件**base/startup/init/services/etc/group**中配置，进程uid和gid配置参考：[系统服务用户组添加方法](https://gitee.com/openharmony/startup_init_lite/wikis)。
    >   -   caps值：格式为caps = ["xxx"]，如果要配置CAP_DAC_OVERRIDE，此处需要填写caps = ["DAC_OVERRIDE"]，不能填写为caps = ["CAP_DAC_OVERRIDE"]。
    >   -   preload：驱动按需加载字段。

-   驱动私有配置信息（可选）

    如果驱动有私有配置，则可以添加一个驱动的配置文件，用来填写一些驱动的默认配置信息。HDF框架在加载驱动的时候，会将对应的配置信息获取并保存在HdfDeviceObject中的property里面，通过Bind和Init（参考[驱动实现](#驱动实现)）传递给驱动。驱动的配置信息示例如下：

    ```
    root {
        SampleDriverConfig {
            sample_version = 1;
            sample_bus = "I2C_0";
            match_attr = "sample_config";   // 该字段的值必须和device_info.hcs中的deviceMatchAttr值一致
        }
    }
    ```

    配置信息定义之后，需要将该配置文件添加到板级配置入口文件hdf.hcs，示例如下：

    ```
    #include "device_info/device_info.hcs"
    #include "sample/sample_config.hcs"
    ```

### 驱动消息机制管理开发

1.  将驱动配置信息中服务策略policy字段设置为2（SERVICE_POLICY_CAPACITY，[policy定义](#驱动服务管理)）。

    ```
    device_sample :: Device {
        policy = 2;
        ...
    }
    ```

2.  配置驱动信息中的服务设备节点权限（permission字段）是框架给驱动创建设备节点的权限，默认是0666，驱动开发者根据驱动的实际使用场景配置驱动设备节点的权限。

3.  在服务实现过程中，实现服务基类成员IDeviceIoService中的Dispatch方法。

    ```c
    // Dispatch是用来处理用户态发下来的消息
    int32_t SampleDriverDispatch(struct HdfDeviceIoClient *device, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
    {
        HDF_LOGI("sample driver lite A dispatch");
        return HDF_SUCCESS;
    }
    int32_t SampleDriverBind(struct HdfDeviceObject *device)
    {
        HDF_LOGI("test for lite os sample driver A Open!");
        if (device == NULL) {
            HDF_LOGE("test for lite os sample driver A Open failed!");
            return HDF_FAILURE;
        }
        static struct ISampleDriverService sampleDriverA = {
            .ioService.Dispatch = SampleDriverDispatch,
            .ServiceA = SampleDriverServiceA,
            .ServiceB = SampleDriverServiceB,
        };
        device->service = (struct IDeviceIoService *)(&sampleDriverA);
        return HDF_SUCCESS;
    }
    ```

4.  驱动定义消息处理函数中的cmd类型。

    ```c
    #define SAMPLE_WRITE_READ 1    // 读写操作码1
    ```

5.  用户态获取服务接口并发送消息到驱动。

    ```c
    int SendMsg(const char *testMsg)
    {
        if (testMsg == NULL) {
            HDF_LOGE("test msg is null");
            return HDF_FAILURE;
        }
        struct HdfIoService *serv = HdfIoServiceBind("sample_driver");
        if (serv == NULL) {
            HDF_LOGE("fail to get service");
            return HDF_FAILURE;
        }
        struct HdfSBuf *data = HdfSbufObtainDefaultSize();
        if (data == NULL) {
            HDF_LOGE("fail to obtain sbuf data");
            return HDF_FAILURE;
        }
        struct HdfSBuf *reply = HdfSbufObtainDefaultSize();
        if (reply == NULL) {
            HDF_LOGE("fail to obtain sbuf reply");
            ret = HDF_DEV_ERR_NO_MEMORY;
            goto out;
        }
        if (!HdfSbufWriteString(data, testMsg)) {
            HDF_LOGE("fail to write sbuf");
            ret = HDF_FAILURE;
            goto out;
        }
        int ret = serv->dispatcher->Dispatch(&serv->object, SAMPLE_WRITE_READ, data, reply);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("fail to send service call");
            goto out;
        }
    out:
        HdfSbufRecycle(data);
        HdfSbbufRecycle(reply);
        HdfIoServiceRecycle(serv);
        return ret;
    }
    ```

6.  用户态接收该驱动上报的消息。

    1.  用户态编写驱动上报消息的处理函数。

        ```c
        static int OnDevEventReceived(void *priv,  uint32_t id, struct HdfSBuf *data)
        {
            OsalTimespec time;
            OsalGetTime(&time);
            HDF_LOGI("%{public}s received event at %{public}llu.%{public}llu", (char *)priv, time.sec, time.usec);
        
            const char *string = HdfSbufReadString(data);
            if (string == NULL) {
                HDF_LOGE("fail to read string in event data");
                return HDF_FAILURE;
            }
            HDF_LOGI("%{public}s: dev event received: %{public}d %{public}s",  (char *)priv, id, string);
            return HDF_SUCCESS;
        }
        ```

    2.  用户态注册接收驱动上报消息的操作方法。

        ```c
        int RegisterListen()
        {
            struct HdfIoService *serv = HdfIoServiceBind("sample_driver");
            if (serv == NULL) {
                HDF_LOGE("fail to get service");
                return HDF_FAILURE;
            }
            static struct HdfDevEventlistener listener = {
                .callBack = OnDevEventReceived,
                .priv ="Service0"
            };
            if (HdfDeviceRegisterEventListener(serv, &listener) != 0) {
                HDF_LOGE("fail to register event listener");
                return HDF_FAILURE;
            }
            ......
            HdfDeviceUnregisterEventListener(serv, &listener);
            HdfIoServiceRecycle(serv);
            return HDF_SUCCESS;
        }
        ```

    3.  驱动上报事件。

        ```c
        int32_t SampleDriverDispatch(HdfDeviceIoClient *client, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
        {
            ... // process api call here
            return HdfDeviceSendEvent(client->device, cmdCode, data);
        }
        ```

### 驱动服务管理开发

驱动服务管理的开发包括驱动服务的编写、绑定、获取或者订阅，详细步骤如下。

#### 驱动服务编写

```c
// 驱动服务结构的定义
struct ISampleDriverService {
    struct IDeviceIoService ioService;       // 服务结构的首个成员必须是IDeviceIoService类型的成员。
    int32_t (*ServiceA)(void);               // 驱动的第一个服务接口。
    int32_t (*ServiceB)(uint32_t inputCode); // 驱动的第二个服务接口，有多个可以依次往下累加。
};

// 驱动服务接口的实现
int32_t SampleDriverServiceA(void)
{
    // 驱动开发者实现业务逻辑
    return HDF_SUCCESS;
}

int32_t SampleDriverServiceB(uint32_t inputCode)
{
    // 驱动开发者实现业务逻辑
    return HDF_SUCCESS;
}
```

#### 驱动服务绑定

开发者实现HdfDriverEntry中的Bind指针函数，如下的SampleDriverBind，把驱动服务绑定到HDF框架中。

```c
int32_t SampleDriverBind(struct HdfDeviceObject *deviceObject)
{
    // deviceObject为HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。
    if (deviceObject == NULL) {
        HDF_LOGE("Sample device object is null!");
        return HDF_FAILURE;
    }
    static struct ISampleDriverService sampleDriverA = {
        .ServiceA = SampleDriverServiceA,
        .ServiceB = SampleDriverServiceB,
    };
    deviceObject->service = &sampleDriverA.ioService;
    return HDF_SUCCESS;
}
```

#### 驱动服务获取

应用程序开发者获取驱动服务有两种方式：通过HDF接口直接获取和通过HDF提供的订阅机制获取。

##### 通过HDF接口直接获取

当驱动服务获取者明确驱动已经加载完成时，获取该驱动的服务可以通过HDF框架提供的能力接口直接获取，如下所示：

```c
const struct ISampleDriverService *sampleService =
        (const struct ISampleDriverService *)DevSvcManagerClntGetService("sample_driver");
if (sampleService == NULL) {
    return HDF_FAILURE;
}
sampleService->ServiceA();
sampleService->ServiceB(5);
```

##### 通过HDF提供的订阅机制获取

当内核态驱动服务获取者对驱动（同一个host）加载的时机不感知时，可以通过HDF框架提供的订阅机制来订阅该驱动服务。当该驱动加载完成时，HDF框架会将被订阅的驱动服务发布给订阅者（驱动服务获取者），实现方式如下所示：

```c
// 订阅回调函数的编写，当被订阅的驱动加载完成后，HDF框架会将被订阅驱动的服务发布给订阅者，通过这个回调函数给订阅者使用。
// object为订阅者的私有数据，service为被订阅的服务对象。
int32_t TestDriverSubCallBack(struct HdfDeviceObject *deviceObject, const struct HdfObject *service)
{
    const struct ISampleDriverService *sampleService =
        (const struct ISampleDriverService *)service;
    if (sampleService == NULL) {
        return HDF_FAILURE;
    }
    sampleService->ServiceA();
    sampleService->ServiceB(5);
}
// 订阅过程的实现
int32_t TestDriverInit(struct HdfDeviceObject *deviceObject)
{
    if (deviceObject == NULL) {
        HDF_LOGE("Test driver init failed, deviceObject is null!");
        return HDF_FAILURE;
    }
    struct SubscriberCallback callBack;
    callBack.deviceObject = deviceObject;
    callBack.OnServiceConnected = TestDriverSubCallBack;
    int32_t ret = HdfDeviceSubscribeService(deviceObject, "sample_driver", callBack);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("Test driver subscribe sample driver failed!");
    }
    return ret;
}
```

## HDF开发实例

下面基于HDF框架，提供一个完整的样例，包含配置文件的添加，驱动代码的实现以及用户态程序和驱动交互的流程。

### 添加配置

在HDF框架的配置文件（例如vendor/hisilicon/xxx/hdf_config/device_info）中添加该驱动的配置信息，如下所示：

```
root {
    device_info {
        match_attr = "hdf_manager";
        template host {
            hostName = "";
            priority = 100;
            template device {
                template deviceNode {
                    policy = 0;
                    priority = 100;
                    preload = 0;
                    permission = 0664;
                    moduleName = "";
                    serviceName = "";
                    deviceMatchAttr = "";
                }
            }
        }
        sample_host :: host {
            hostName = "sample_host";
            sample_device :: device {
                device0 :: deviceNode {
                    policy = 2;
                    priority = 100;
                    preload = 1;
                    permission = 0664;
                    moduleName = "sample_driver";
                    serviceName = "sample_service";
                }
            }
        }
    }
}
```

### 编写驱动代码

基于HDF框架编写的sample驱动代码如下：

```c
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include "hdf_log.h"
#include "hdf_base.h"
#include "hdf_device_desc.h"

#define HDF_LOG_TAG sample_driver

#define SAMPLE_WRITE_READ 123

static int32_t HdfSampleDriverDispatch(
    struct HdfDeviceIoClient *client, int id, struct HdfSBuf *data, struct HdfSBuf *reply)
{
    HDF_LOGI("%{public}s: received cmd %{public}d", __func__, id);
    if (id == SAMPLE_WRITE_READ) {
        const char *readData = HdfSbufReadString(data);
        if (readData != NULL) {
            HDF_LOGE("%{public}s: read data is: %{public}s", __func__, readData);
        }
        if (!HdfSbufWriteInt32(reply, INT32_MAX)) {
            HDF_LOGE("%{public}s: reply int32 fail", __func__);
        }
        return HdfDeviceSendEvent(client->device, id, data);
    }
    return HDF_FAILURE;
}

static void HdfSampleDriverRelease(struct HdfDeviceObject *deviceObject)
{
    // release resources here
    return;
}

static int HdfSampleDriverBind(struct HdfDeviceObject *deviceObject)
{
    if (deviceObject == NULL) {
        return HDF_FAILURE;
    }
    static struct IDeviceIoService testService = {
        .Dispatch = HdfSampleDriverDispatch,
    };
    deviceObject->service = &testService;
    return HDF_SUCCESS;
}

static int HdfSampleDriverInit(struct HdfDeviceObject *deviceObject)
{
    if (deviceObject == NULL) {
        HDF_LOGE("%{public}s::ptr is null!", __func__);
        return HDF_FAILURE;
    }
    HDF_LOGI("Sample driver Init success");
    return HDF_SUCCESS;
}

static struct HdfDriverEntry g_sampleDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "sample_driver",
    .Bind = HdfSampleDriverBind,
    .Init = HdfSampleDriverInit,
    .Release = HdfSampleDriverRelease,
};

HDF_INIT(g_sampleDriverEntry);
```

### 编写用户程序和驱动交互代码

基于HDF框架编写的用户态程序和驱动交互的代码如下（代码可以放在目录drivers/hdf_core/adapter/uhdf下面编译，BUILD.gn可以参考drivers/hdf_core/framework/sample/platform/uart/dev/BUILD.gn）：

```c
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "hdf_log.h"
#include "hdf_sbuf.h"
#include "hdf_io_service_if.h"

#define HDF_LOG_TAG sample_test
#define SAMPLE_SERVICE_NAME "sample_service"

#define SAMPLE_WRITE_READ 123

int g_replyFlag = 0;

static int OnDevEventReceived(void *priv,  uint32_t id, struct HdfSBuf *data)
{
    const char *string = HdfSbufReadString(data);
    if (string == NULL) {
        HDF_LOGE("fail to read string in event data");
        g_replyFlag = 1;
        return HDF_FAILURE;
    }
    HDF_LOGI("%{public}s: dev event received: %{public}u %{public}s",  (char *)priv, id, string);
    g_replyFlag = 1;
    return HDF_SUCCESS;
}

static int SendEvent(struct HdfIoService *serv, char *eventData)
{
    int ret = 0;
    struct HdfSBuf *data = HdfSbufObtainDefaultSize();
    if (data == NULL) {
        HDF_LOGE("fail to obtain sbuf data");
        return 1;
    }

    struct HdfSBuf *reply = HdfSbufObtainDefaultSize();
    if (reply == NULL) {
        HDF_LOGE("fail to obtain sbuf reply");
        ret = HDF_DEV_ERR_NO_MEMORY;
        goto out;
    }

    if (!HdfSbufWriteString(data, eventData)) {
        HDF_LOGE("fail to write sbuf");
        ret = HDF_FAILURE;
        goto out;
    }

    ret = serv->dispatcher->Dispatch(&serv->object, SAMPLE_WRITE_READ, data, reply);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("fail to send service call");
        goto out;
    }

    int replyData = 0;
    if (!HdfSbufReadInt32(reply, &replyData)) {
        HDF_LOGE("fail to get service call reply");
        ret = HDF_ERR_INVALID_OBJECT;
        goto out;
    }
    HDF_LOGI("Get reply is: %{public}d", replyData);
out:
    HdfSbufRecycle(data);
    HdfSbufRecycle(reply);
    return ret;
}

int main()
{
    char *sendData = "default event info";
    struct HdfIoService *serv = HdfIoServiceBind(SAMPLE_SERVICE_NAME);
    if (serv == NULL) {
        HDF_LOGE("fail to get service %s", SAMPLE_SERVICE_NAME);
        return HDF_FAILURE;
    }

    static struct HdfDevEventlistener listener = {
        .callBack = OnDevEventReceived,
        .priv ="Service0"
    };

    if (HdfDeviceRegisterEventListener(serv, &listener) != HDF_SUCCESS) {
        HDF_LOGE("fail to register event listener");
        return HDF_FAILURE;
    }
    if (SendEvent(serv, sendData)) {
        HDF_LOGE("fail to send event");
        return HDF_FAILURE;
    }

    while (g_replyFlag == 0) {
        sleep(1);
    }

    if (HdfDeviceUnregisterEventListener(serv, &listener)) {
        HDF_LOGE("fail to  unregister listener");
        return HDF_FAILURE;
    }

    HdfIoServiceRecycle(serv);
    return HDF_SUCCESS;
}
```

>   ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>   用户态应用程序使用了HDF框架中的消息发送接口，因此在编译用户态程序的过程中需要依赖HDF框架对外提供的hdf_core和osal的动态库，在gn编译文件中添加如下依赖项：
>
>   deps = [
>
>   ​        "//drivers/hdf_core/adapter/uhdf/manager:hdf_core",
>
>   ​        "//drivers/hdf_core/adapter/uhdf/posix:hdf_posix_osal",
>
>   ]
