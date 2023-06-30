# ADC<a name="1"></a>

## 概述<a name="section1"></a>

### 功能简介<a name="section2"></a>

ADC（Analog to Digital Converter），即模拟-数字转换器，可将模拟信号转换成对应的数字信号，便于存储与计算等操作。除电源线和地线之外，ADC只需要1根线与被测量的设备进行连接，其物理连线如图1所示：

**图 1**  ADC物理连线示意图<a name="fig1"></a>  
![ADC物理连线示意图](figures/ADC物理连线示意图.png)

ADC接口定义了完成AD转换的通用方法集合，包括：

-  ADC设备管理：打开或关闭ADC设备。

-  ADC读取转换结果：读取AD转换结果。

### 基本概念<a name="section3"></a>

- 分辨率

    分辨率指的是ADC模块能够转换的二进制位数，位数越多分辨率越高。

- 转换误差

    转换误差通常是以输出误差的最大值形式给出。它表示A/D转换器实际输出的数字量和理论上的输出数字量之间的差别。常用最低有效位的倍数表示。

- 转换时间

    转换时间是指A/D转换器从转换控制信号到来开始，到输出端得到稳定的数字信号所经过的时间。

### 运作机制<a name="section4"></a>

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型配置器），如果采用独立服务模式则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。ADC模块接口适配模式采用统一服务模式。

### 约束与限制<a name="section5"></a>

ADC模块仅支持轮询方式读取数据。

## 使用指导<a name="section6"></a>

### 场景介绍<a name="section7"></a>

ADC设备通常用于将模拟电压或电流转换为数字量，例如与NTC电阻搭配进行温度测量，或者将其他模拟传感器的输出量转换为数字量的场景。

### 接口说明<a name="section8"></a>

ADC模块提供的主要接口如表1所示，具体API详见//drivers/hdf_core/framework/include/platform/adc_if.h。

**表 1**  ADC驱动API接口功能介绍

<a name="table1"></a>

| 接口名 | 接口描述 |
| -------- | ---------------- |
| DevHandle AdcOpen(uint32_t number)  | 打开ADC设备 |
| void AdcClose(DevHandle handle) | 关闭ADC设备 |
| int32_t AdcRead(DevHandle handle, uint32_t channel, uint32_t \*val) | 读取AD转换结果值 |

### 开发步骤<a name="section9"></a>

使用ADC设备的一般流程如图2所示。

**图 2**  ADC使用流程图<a name="fig2"></a>  
![ADC使用流程图](figures/ADC使用流程图.png) 


#### 打开ADC设备

在进行AD转换之前，首先要调用AdcOpen打开ADC设备。

```c
DevHandle AdcOpen(int16_t number);
```

**表 2**  AdcOpen参数和返回值描述

<a name="table2"></a>

| 参数 | 参数描述 |
| ---------- | ----------------- |
| number | int16_t类型，ADC设备号 |
| **返回值** | **返回值描述** |
| NULL | 打开ADC设备失败 |
| 设备句柄 | 打开的ADC设备句柄 |

假设系统中存在2个ADC设备，编号从0到1，那么我们现在打开1号设备。

```c
DevHandle adcHandle = NULL;  // ADC设备句柄

// 打开ADC设备
adcHandle = AdcOpen(1);
if (adcHandle == NULL) {
    HDF_LOGE("AdcOpen: fail\n");
    return NULL;
}
```

#### 读取AD转换结果

```c
int32_t AdcRead(DevHandle handle, uint32_t channel, uint32_t *val);
```

**表 3**  AdcRead参数和返回值描述

<a name="table3"></a>

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，ADC设备句柄 |
| channel| uint32_t类型，ADC设备通道号 |
| val | uint32_t类型指针，AD转换结果 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 读取成功 |
| 负数 | 读取失败 |

读取转换结果示例（以通道1为例）：

```c
uint32_t value;
int32_t ret;

ret = AdcRead(adcHandle, 1, &value);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("ADC read fail!\n");
    return ret;
}
```

#### 关闭ADC设备

ADC通信完成之后，需要关闭ADC设备。
```c
void AdcClose(DevHandle handle); 
```
**表 4**  AdcClose参数和返回值描述

<a name="table4"></a>

| 参数 | 参数描述 |
| ------ | ----------- |
| handle | DevHandle类型，ADC设备句柄 |
| 返回值 | 返回值描述  |
| 无 | 无 |

关闭ADC设备示例：

```c
AdcClose(adcHandle); // 关闭ADC设备
```

### 使用实例<a name="section10"></a>

本例拟对Hi3516DV300开发板上ADC设备进行简单的读取操作，基本硬件信息如下：

-   SOC：hi3516dv300。

-   硬件连接：电位器挂接在0号ADC设备1通道下。

本例程对测试ADC进行连续读取操作，测试ADC功能是否正常。

示例如下：

```c
#include "adc_if.h"          // ADC标准接口头文件
#include "hdf_log.h"         // 标准日志打印头文件

/// 设备号0，通道号1
#define ADC_DEVICE_NUM  0
#define ADC_CHANNEL_NUM 1
#define ADC_TEST_NUM    30

// ADC例程总入口
static int32_t TestCaseAdc(void)
{
    int32_t i;
    int32_t ret;
    DevHandle adcHandle = NULL;
    uint32_t readBuf[ADC_TEST_NUM] = {0};

    // 打开ADC设备
    adcHandle = AdcOpen(ADC_DEVICE_NUM);
    if (adcHandle == NULL) {
        HDF_LOGE("%s: Open ADC%u fail!", __func__, ADC_DEVICE_NUM);
        return -1;
    }

    // 连续进行30次AD转换并读取转换结果
    for (i = 0; i < ADC_TEST_NUM; i++) {
        ret = AdcRead(adcHandle, ADC_CHANNEL_NUM, &readBuf[i]);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: ADC read fail!:%d", __func__, ret);
            AdcClose(adcHandle);
            return -1;
        }
    }
    HDF_LOGI("%s: ADC read successful!", __func__);

    // 访问完毕关闭ADC设备
    AdcClose(adcHandle);

    return 0;
}
```
