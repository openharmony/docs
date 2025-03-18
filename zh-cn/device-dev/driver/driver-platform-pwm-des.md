# PWM

## 概述

### 功能简介

PWM即脉冲宽度调制（Pulse Width Modulation）的缩写，是一种对模拟信号电平进行数字编码并将其转换为脉冲的技术。

PWM接口定义了操作PWM设备的通用方法集合，包括：

- PWM设备句柄获取和释放

- PWM周期、占空比、极性的设置

- PWM使能和关闭

- PWM配置信息的获取和设置

### 基本概念

脉冲是“电脉冲”的简称，指电路中电流或电压短暂起伏的现象，其特点是突变和不连续性。脉冲的种类很多，常见的脉冲波形有：三角脉冲、尖脉冲、矩形脉冲、方形脉冲、梯形脉冲及阶梯脉冲等。脉冲的主要参数包括重复周期T（T=1/F，F为重复频率）、脉冲幅度U、脉冲前沿上升时间ts、后沿下降时间t、脉冲宽度tk等。

### 运作机制

在HDF框架中，PWM接口适配模式采用独立服务模式（如图1所示）。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDF设备管理器的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

独立服务模式下，核心层不会统一发布一个服务供上层使用，因此这种模式下驱动要为每个控制器发布一个服务，具体表现为：

- 驱动适配者需要实现HdfDriverEntry的Bind钩子函数以绑定服务。

- device_info.hcs文件中deviceNode的policy字段为1或2，不能为0。

PWM模块各分层作用：

- 接口层提供打开PWM设备、设置PWM设备周期、设置PWM设备占空时间、设置PWM设备极性、设置PWM设备参数、获取PWM设备参数、使能PWM设备、禁止PWM设备、关闭PWM设备的接口。

- 核心层主要提供PWM控制器的添加、移除以及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

**图 1** PWM独立服务模式结构图

![PWM独立服务模式结构图](figures/独立服务模式结构图.png)

## 使用指导

### 场景介绍

通常情况下，在使用马达控制、背光亮度调节时会用到PWM模块。

### 接口说明

PWM模块设备属性如表1所示，PWM模块提供的主要接口如表2所示，具体API[详见](https://gitee.com/openharmony/drivers_hdf_core/blob/master/framework/include/platform/pwm_if.h)。

**表 1** PwmConfig结构体介绍

| 名称 | 描述 |
| -------- | -------- |
| duty | uint32_t类型，占空时间，以纳秒为单位。 |
| period | uint32_t类型，PWM周期，以纳秒为单位。 |
| number | uint32_t类型，要生成的方波数：<br/>-&nbsp;正值：表示将生成指定数量的方波<br/>-&nbsp;0：表示方波将不断产生 |
| polarity | uint8_t类型，极性：正极性/反极性。 |
| status | uint8_t类型，状态：启用状态/禁用状态。 |

**表 2** PWM驱动API接口功能介绍

| 接口名 | 接口描述|
| ------------------------------------------------------------ | ------------------- |
| DevHandle PwmOpen(uint32_t num) | 打开PWM设备 |
| void PwmClose(DevHandle handle)| 关闭PWM设备 |
| int32_t PwmSetPeriod(DevHandle handle, uint32_t period) | 设置PWM设备周期 |
| int32_t PwmSetDuty(DevHandle handle, uint32_t duty) | 设置PWM设备占空时间 |
| int32_t PwmSetPolarity(DevHandle handle, uint8_t polarity) | 设置PWM设备极性 |
| int32_t PwmEnable(DevHandle handle) | 使能PWM设备 |
| int32_t PwmDisable(DevHandle handle) | 禁用PWM设备 |
| int32_t PwmSetConfig(DevHandle handle, struct PwmConfig \*config) | 设置PWM设备参数 |
| int32_t PwmGetConfig(DevHandle handle, struct PwmConfig \*config) | 获取PWM设备参数 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
> 本文涉及PWM的所有接口，支持内核态及用户态使用。

### 开发步骤

使用PWM的一般流程如下图所示。

**图 2** PWM使用流程图

![PWM使用流程图](figures/PWM设备使用流程图.png)

#### 获取PWM设备句柄

在操作PWM设备时，首先要调用PwmOpen获取PWM设备句柄，该函数会返回指定设备号的PWM设备句柄。

```c
DevHandle PwmOpen(uint32_t num);
```

**表 3** PwmOpen参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| num | uint32_t类型，PWM设备号 |
| **返回值** | **返回值描述** |
| handle | 打开PWM设备成功，返回PWM设备句柄 |
| NULL | 打开PWM设备失败 |

假设系统中的PWM设备号为0，获取该PWM设备句柄的示例如下：

```c
uint32_t num = 0;         // PWM设备号
DevHandle handle = NULL;

handle = PwmOpen(num);    // 打开PWM 0设备并获取PWM设备句柄
if (handle == NULL) {
    HDF_LOGE("PwmOpen: open pwm_%u failed.\n", num);
    return HDF_FAILURE;
}
```

#### 销毁PWM设备句柄

关闭PWM设备，系统释放对应的资源。

```c
void PwmClose(DevHandle handle);
```

**表 4** PwmClose参数描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄  |

```c
PwmClose(handle);    // 关闭PWM设备销毁PWM设备句柄
```

#### 使能PWM设备

```c
int32_t PwmEnable(DevHandle handle);
```

**表 5** PwmEnable参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 使能PWM设备成功 |
| 负数 | 使能PWM设备失败 |

```c
int32_t ret;

ret = PwmEnable(handle);    // 启用PWM设备
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmEnable: enable pwm failed, ret:%d\n", ret);
    return ret;
}
```

#### 禁用PWM设备

```c
int32_t PwmDisable(DevHandle handle);
```

**表 6** PwmDisable参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 禁用PWM设备成功 |
| 负数 | 禁用PWM设备失败 |

```c
int32_t ret;

ret = PwmDisable(handle);    // 禁用PWM设备
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmDisable: disable pwm failed, ret:%d\n", ret);
    return ret;
}
```

#### 设置PWM设备周期

```c
int32_t PwmSetPeriod(DevHandle handle, uint32_t period);
```

**表 7** PwmSetPeriod参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| period | uint32_t类型，要设置的周期，单位为纳秒 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置PWM设备周期成功 |
| 负数 | 设置PWM设备周期失败 |

```c
int32_t ret;

ret = PwmSetPeriod(handle, 50000000);    // 设置周期为50000000纳秒
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmSetPeriod: pwm set period failed, ret:%d\n", ret);
    return ret;
}
```

#### 设置PWM设备占空时间

```c
int32_t PwmSetDuty(DevHandle handle, uint32_t duty);
```

**表 8** PwmSetDuty参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| duty | uint32_t类型，要设置的占空时间，单位为纳秒 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置PWM设备占空时间成功 |
| 负数 | 设置PWM设备占空时间失败 |


```c
int32_t ret;

ret = PwmSetDuty(handle, 25000000);    // 设置占空时间为25000000纳秒
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmSetDuty: pwm set duty failed, ret:%d\n", ret);
    return ret;
}
```

#### 设置PWM设备极性

```c
int32_t PwmSetPolarity(DevHandle handle, uint8_t polarity);
```

**表 9** PwmSetPolarity参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| polarity | uint8_t类型，要设置的极性，正/反 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置PWM设备极性成功 |
| 负数 | 设置PWM设备极性失败 |


```c
int32_t ret;

ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);    // 设置极性为反
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmSetPolarity: pwm set polarity failed, ret:%d\n", ret);
    return ret;
}
```

#### 设置PWM设备参数

```c
int32_t PwmSetConfig(DevHandle handle, struct PwmConfig *config);
```

**表 10** PwmSetConfig参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| config | 结构体指针类型，配置参数 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置PWM设备参数成功 |
| 负数 | 设置PWM设备参数失败 |

```c
int32_t ret;
struct PwmConfig pcfg;

pcfg.duty = 25000000;                     // 占空时间为25000000纳秒
pcfg.period = 50000000;                   // 周期为50000000纳秒
pcfg.number = 0;                          // 不断产生方波
pcfg.polarity = PWM_INVERTED_POLARITY;    // 极性为反
pcfg.status = PWM_ENABLE_STATUS;          // 运行状态为启用

ret = PwmSetConfig(handle, &pcfg);        // 设置PWM设备参数
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmSetConfig: pwm set config failed, ret:%d\n", ret);
    return ret;
}
```

#### 获取PWM设备参数

```c
int32_t PwmGetConfig(DevHandle handle, struct PwmConfig *config);
```

**表 11** PwmGetConfig参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | DevHandle类型，PWM设备句柄 |
| config | 结构体指针类型，配置参数 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 获取PWM设备参数成功 |
| 负数 | 获取PWM设备参数失败 |

```c
int32_t ret;
struct PwmConfig pcfg;

ret = PwmGetConfig(handle, &pcfg);    // 获取PWM设备参数
if (ret != HDF_SUCCESS) {
    HDF_LOGE("PwmGetConfig: pwm get config failed, ret:%d\n", ret);
    return ret;
}
```

## 使用实例

下面将基于Hi3516DV300开发板展示使用PWM完整操作，步骤主要如下：

1. 传入PWM设备号，打开PWM设备并获得PWM设备句柄。

2. 通过PWM设备句柄及待设置的周期，设置PWM设备周期。

3. 通过PWM设备句柄及待设置的占空时间，设置PWM设备占空时间。

4. 通过PWM设备句柄及待设置的极性，设置PWM设备极性。

5. 通过PWM设备句柄及待获取的设备参数，获取PWM设备参数。

6. 通过PWM设备句柄，使能PWM设备。

7. 通过PWM设备句柄及待设置的设备参数，设置PWM设备参数。

8. 通过PWM设备句柄，禁用PWM设备。

9. 通过PWM设备句柄，关闭PWM设备。

```c
#include "pwm_if.h"                                               // pwm标准接口头文件
#include "hdf_log.h"                                              // 标准日志打印头文件

static int32_t PwmTestSample(void)
{
    int32_t ret;
    uint32_t num;
    uint32_t period;
    uint32_t duty;
    DevHandle handle = NULL;

    struct PwmConfig pcfg;
    pcfg.duty = 20000000;                                         // 占空时间为20000000纳秒                 
    pcfg.period = 40000000;                                       // 周期为40000000纳秒
    pcfg.number = 100;                                            // 生成100个方波
    pcfg.polarity = PWM_NORMAL_POLARITY;                          // 极性为正
    pcfg.status = PWM_ENABLE_STATUS;                              // 运行状态为启用

    num = 1;                                                      // PWM设备编号，要填写实际平台上的编号

    handle = PwmOpen(num);                                        // 获取PWM设备句柄
    if (handle == NULL) {
        HDF_LOGE("PwmTestSample: open pwm_%u fail!\n", num);
        return HDF_FAILURE;
    }

    period = 50000000;                                            // 设置周期为50000000纳秒
    ret = PwmSetPeriod(handle, period);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmTestSample: pwm set period fail, ret:%d\n", ret);
        goto ERR;
    }

    duty = 25000000;                                              // 设置占空时间为25000000纳秒
    ret = PwmSetDuty(handle, duty);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmTestSample: pwm set duty fail, ret:%d\n", ret);
        goto ERR;
    }

    ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);          // 设置极性为反
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmTestSample: pwm set polarity fail, ret:%d\n", ret);
        goto ERR;
    }

    ret = PwmGetConfig(handle, &pcfg);                            // 获取PWM设备参数
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmTestSample: get pwm config fail, ret:%d\n", ret);
        goto ERR;
    }

    ret = PwmEnable(handle);                                      // 启用PWM设备
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmEnable: enable pwm fail, ret:%d\n", ret);
        goto ERR;
    }

    ret = PwmSetConfig(handle, &pcfg);                            // 设置PWM设备参数
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmTestSample: set pwm config fail, ret:%d\n", ret);
        goto ERR;
    }

    ret = PwmDisable(handle);                                     // 禁用PWM设备
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("PwmTestSample: disable pwm fail, ret:%d\n", ret);
        goto ERR;
    }

    HDF_LOGD("PwmTestSample: all tests end.");
ERR:
    PwmClose(handle);                                             // 销毁PWM设备句柄
    return ret;
}
```
