# MIPI CSI<a name="title_MIPI_CSIDes"></a>


## 概述<a name="section1_MIPI_CSIDes"></a>

- CSI（Camera Serial Interface）是由MIPI联盟下Camera工作组指定的接口标准。CSI-2是MIPI CSI第二版，主要由应用层、协议层、物理层组成，最大支持4通道数据传输、单线传输速度高达1Gb/s。

- 物理层支持HS(High Speed)和LP(Low Power)两种工作模式。HS模式下采用低压差分信号，功耗较大，但数据传输速率可以很高（数据速率为80M～1Gbps）；LP模式下采用单端信号，数据速率很低（<10Mbps），但是相应的功耗也很低。两种模式的结合保证了MIPI总线在需要传输大量数据（如图像）时可以高速传输，而在不需要传输大数据量时又能够减少功耗。

- 图1显示了简化的CSI接口。D-PHY采用1对源同步的差分时钟和1～4对差分数据线来进行数据传输。数据传输采用DDR方式，即在时钟的上下边沿都有数据传输。

  **图 1**  CSI发送、接收接口<a name="fig1_MIPI_CSIDes"></a>  
  ![](figures/CSI发送-接收接口.png)

### ComboDevAttr结构体<a name="section1.1_MIPI_CSIDes"></a>

**表** **1** ComboDevAttr结构体介绍

<a name="table1_MIPI_CSIDes"></a>

| 名称      | 描述                                                  |
| --------- | ----------------------------------------------------- |
| devno     | 设备号                                                |
| inputMode | 输入模式：MIPI/LVDS/SUBSLVDS/HISPI/DC                 |
| dataRate  | Mipi Rx，SLVS输入速率                                 |
| imgRect   | MIPI Rx设备裁剪区域（与原始传感器输入图像大小相对应） |
| MIPIAttr  | Mipi设备属性                                          |
| lvdsAttr  | LVDS/SubLVDS/HiSPi设备属性                            |

### ExtDataType结构体<a name="section1.2_MIPI_CSIDes"></a>

**表** **2** ExtDataType结构体介绍

<a name="table2_MIPI_CSIDes"></a>

| 名称            | 描述                            |
| --------------- | ------------------------------- |
| devno           | 设备号                          |
| num             | sensor号                        |
| extDataBitWidth | 图片的位深                      |
| extDataType     | 定义YUV和原始数据格式以及位深度 |

### 接口说明<a name="section1.3_MIPI_CSIDes"></a>

**表 3**  MIPI CSI API接口功能介绍

<a name="table3_MIPI_CSIDes"></a>

  | 功能分类 | 接口名 | 
| -------- | -------- |
| 获取/释放MIPI CSI控制器操作句柄 | MipiCsiOpen：获取MIPI CSI控制器操作句柄<br/>MipiCsiClose：释放MIPI CSI控制器操作句柄 | 
| MIPI CSI相应配置 | MipiCsiSetComboDevAttr：设置MIPI，CMOS或者LVDS相机的参数给控制器，参数包括工作模式，图像区域，图像深度，数据速率和物理通道等<br/>MipiCsiSetExtDataType(可选)：设置YUV和RAW数据格式和位深<br/>MipiCsiSetHsMode：设置MIPI&nbsp;RX的Lane分布。根据硬件连接的形式选择具体的mode<br/>MipiCsiSetPhyCmvmode：设置共模电压模式 | 
| 复位/撤销复位Sensor | MipiCsiResetSensor：复位Sensor<br/>MipiCsiUnresetSensor：撤销复位Sensor | 
| 复位/撤销复位MIPI&nbsp;RX | MipiCsiResetRx：复位MIPI&nbsp;RX。不同的s32WorkingViNum有不同的enSnsType<br/>MipiCsiUnresetRx：撤销复位MIPI&nbsp;RX | 
| 使能/关闭MIPI的时钟 | MipiCsiEnableClock：使能MIPI的时钟。根据上层函数电泳传递的enSnsType参数决定是用MIPI还是LVDS<br/>MipiCsiDisableClock：关闭MIPI设备的时钟 | 
| 使能/禁用MIPI上的Sensor时钟 | MipiCsiEnableSensorClock：使能MIPI上的Sensor时钟<br/>MipiCsiDisableSensorClock：关闭Sensor的时钟 | 


## 使用指导<a name="section2_MIPI_CSIDes"></a>

### 使用流程<a name="section2.1_MIPI_CSIDes"></a>

使用MIPI CSI的一般流程如[图2](#fig2_MIPI_CSIDes)所示。

**图 2**  MIPI CSI使用流程图<a name="fig2_MIPI_CSIDes"></a>  


![](figures/MIPI-CSI使用流程图.png)

### 获取MIPI CSI控制器操作句柄<a name="section2.2_MIPI_CSIDes"></a>

在进行MIPI CSI进行通信前，首先要调用MipiCsiOpen获取控制器操作句柄，该函数会返回指定通道ID的控制器操作句柄。

```c
DevHandle MipiCsiOpen(uint8_t id);
```

**表 4**  MipiCsiOpen的参数和返回值描述

<a name="table4_MIPI_CSIDes"></a>

| 参数       | 参数描述                                        |
| ---------- | ----------------------------------------------- |
| id         | MIPI CSI通道ID                                  |
| **返回值** | **返回值描述**                                  |
| NULL       | 获取失败                                        |
| 设备句柄   | 获取到指令通道的控制器操作句柄，类型为DevHandle |

假设系统中的MIPI CSI通道为0，获取该通道控制器操作句柄的示例如下：

```c
DevHandle MipiCsiHandle = NULL;  /* 设备句柄 */
id = 0;      /* MIPI CSI通道ID */

/* 获取控制器操作句柄 */
MipiCsiHandle = MipiCsiOpen(id);
if (MipiCsiHandle == NULL) {
    HDF_LOGE("MipiCsiOpen: failed\n");
    return;
}
```

### MIPI CSI相应配置<a name="section2.3_MIPI_CSIDes"></a>

-   写入MIPI CSI配置

    ```c
    int32_t MipiCsiSetComboDevAttr(DevHandle handle, ComboDevAttr *pAttr);
    ```

    **表 5**  MipiCsiSetComboDevAttr的参数和返回值描述

    <a name="table5_MIPI_CSIDes"></a>

    | 参数       | 参数描述                   |
    | ---------- | -------------------------- |
    | handle     | 控制器操作句柄             |
    | pAttr      | MIPI CSI相应配置结构体指针 |
    | **返回值** | **返回值描述**             |
    | 0          | 设置成功                   |
    | 负数       | 设置失败                   |

    ```c
    int32_t ret;
    struct ComboDevAttr attr;

    /* 当前配置如下 */
    (void)memset_s(&attr, sizeof(ComboDevAttr), 0, sizeof(ComboDevAttr));
    attr.devno = 0; /* 设备0 */
    attr.inputMode = INPUT_MODE_MIPI; /* 输入模式为MIPI */
    attr.dataRate = MIPI_DATA_RATE_X1; /* 每时钟输出1像素 */
    attr.imgRect.x = 0; /* 0: 图像传感器左上位置 */
    attr.imgRect.y = 0; /* 0: 图像传感器右上位置 */
    attr.imgRect.width = 2592; /* 2592: 图像传感器宽度大小 */
    attr.imgRect.height = 1944; /* 1944: 图像传感器高度尺寸 */
    /* 写入配置数据 */
    ret = MipiCsiSetComboDevAttr(MipiCsiHandle, &attr);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetComboDevAttr fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   设置YUV和RAW数据格式和位深

    ```c
    int32_t MipiCsiSetExtDataType(DevHandle handle, ExtDataType* dataType);
    ```

    **表 6**  MipiCsiSetExtDataType的参数和返回值描述

    <a name="table6_MIPI_CSIDes"></a>

    | 参数       | 参数描述                        |
    | ---------- | ------------------------------- |
    | handle     | 控制器操作句柄                  |
    | dataType   | 定义YUV和原始数据格式以及位深度 |
    | **返回值** | **返回值描述**                  |
    | 0          | 设置成功                        |
    | 负数       | 设置失败                        |

    ```c
    int32_t ret;
    struct ExtDataType dataType;

    /* 配置YUV和RAW数据格式和位深参数 */
    dataType.devno = 0; /* 设备0 */
    dataType.num = 0;   /* sensor 0 */
    dataType.extDataBitWidth[0] = 12; /* 位深数组元素0 */
    dataType.extDataBitWidth[1] = 12; /* 位深数组元素1 */
    dataType.extDataBitWidth[2] = 12; /* 位深数组元素2 */

    dataType.extDataType[0] = 0x39; /* 定义YUV和原始数据格式以及位深度元素0 */
    dataType.extDataType[1] = 0x39; /* 定义YUV和原始数据格式以及位深度元素1 */
    dataType.extDataType[2] = 0x39; /* 定义YUV和原始数据格式以及位深度元素2 */
    /* 设置YUV和RAW数据格式和位深 */
    ret = MipiCsiSetExtDataType(MipiCsiHandle, &dataType);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetExtDataType fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   设置MIPI RX的Lane分布

    ```c
    int32_t MipiCsiSetHsMode(DevHandle handle, LaneDivideMode laneDivideMode);
    ```

    **表 7**  MipiCsiSetHsMode的参数和返回值描述

    <a name="table7_MIPI_CSIDes"></a>

    | 参数           | 参数描述       |
    | -------------- | -------------- |
    | handle         | 控制器操作句柄 |
    | laneDivideMode | lane模式参数   |
    | **返回值**     | **返回值描述** |
    | 0              | 设置成功       |
    | 负数           | 设置失败       |

    ```c
    int32_t ret;
    enum LaneDivideMode mode;

    /* lane模式参数为0 */
    mode = LANE_DIVIDE_MODE_0;
    /* 设置MIPI RX的 Lane分布 */
    ret = MipiCsiSetHsMode(MipiCsiHandle, mode);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetHsMode fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   设置共模电压模式

    ```c
    int32_t MipiCsiSetPhyCmvmode(DevHandle handle, uint8_t devno, PhyCmvMode cmvMode);
    ```

    **表 8**  MipiCsiSetPhyCmvmode的参数和返回值描述

    <a name="table8_MIPI_CSIDes"></a>

    | 参数       | 参数描述         |
    | ---------- | ---------------- |
    | handle     | 控制器操作句柄   |
    | cmvMode    | 共模电压模式参数 |
    | devno      | 设备编号         |
    | **返回值** | **返回值描述**   |
    | 0          | 设置成功         |
    | 负数       | 设置失败         |

    ```c
    int32_t ret;
    enum PhyCmvMode mode;
    uint8_t devno;
    
    /* 共模电压模式参数为0 */
    mode = PHY_CMV_GE1200MV;
    /* 设备编号为0 */
    devno = 0;
    /* 设置共模电压模式 */
    ret = MipiCsiSetPhyCmvmode(MipiCsiHandle, devno, mode);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetPhyCmvmode fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

### 复位/撤销复位Sensor<a name="section2.4_MIPI_CSIDes"></a>

-   复位Sensor

    ```c
    int32_t MipiCsiResetSensor(DevHandle handle, uint8_t snsResetSource);
    ```

    **表 9**  MipiCsiResetSensor的参数和返回值描述

    <a name="table9_MIPI_CSIDes"></a>

    | 参数           | 参数描述                                         |
    | -------------- | ------------------------------------------------ |
    | handle         | 控制器操作句柄                                   |
    | snsResetSource | 传感器的复位信号线号，在软件中称为传感器的复位源 |
    | **返回值**     | **返回值描述**                                   |
    | 0              | 复位成功                                         |
    | 负数           | 复位失败                                         |

    ```c
    int32_t ret;
    uint8_t snsResetSource;

    /* 传感器复位信号线号为0 */
    snsResetSource = 0;
    /* 复位sensor */
    ret = MipiCsiResetSensor(MipiCsiHandle, snsResetSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiResetSensor fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   撤销复位Sensor

    ```c
    int32_t MipiCsiUnresetSensor(DevHandle handle, uint8_t snsResetSource);
    ```

    **表 10**  MipiCsiUnresetSensor的参数和返回值描述

    <a name="table10_MIPI_CSIDes"></a>

    | 参数           | 参数描述                                         |
    | -------------- | ------------------------------------------------ |
    | handle         | 控制器操作句柄                                   |
    | snsResetSource | 传感器的复位信号线号，在软件中称为传感器的复位源 |
    | **返回值**     | **返回值描述**                                   |
    | 0              | 撤销复位成功                                     |
    | 负数           | 撤销复位失败                                     |

    ```c
    int32_t ret;
    uint8_t snsResetSource;

    /* 传感器撤销复位信号线号为0 */
    snsResetSource = 0;
    /* 撤销复位sensor */
    ret = MipiCsiUnresetSensor(MipiCsiHandle, snsResetSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiUnresetSensor fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

### 复位/撤销复位MIPI RX<a name="section2.5_MIPI_CSIDes"></a>

-   复位MIPI RX

    ```c
    int32_t MipiCsiResetRx(DevHandle handle, uint8_t comboDev);
    ```

    **表 11**  MipiCsiResetRx的参数和返回值描述

    <a name="table11_MIPI_CSIDes"></a>

    | 参数       | 参数描述              |
    | ---------- | --------------------- |
    | handle     | 控制器操作句柄        |
    | comboDev   | MIPI RX或LVDS通路序号 |
    | **返回值** | **返回值描述**        |
    | 0          | 复位成功              |
    | 负数       | 复位失败              |

    ```c
    int32_t ret;
    uint8_t comboDev;

    /* 通路序号为0 */
    comboDev = 0;
    /* 复位MIPI RX */
    ret = MipiCsiResetRx(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiResetRx fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   撤销复位MIPI RX

    ```c
    int32_t MipiCsiUnresetRx(DevHandle handle, uint8_t comboDev);
    ```

    **表 12**  MipiCsiUnresetRx的参数和返回值描述

    <a name="table12_MIPI_CSIDes"></a>

    | 参数       | 参数描述              |
    | ---------- | --------------------- |
    | handle     | 控制器操作句柄        |
    | comboDev   | MIPI RX或LVDS通路序号 |
    | **返回值** | **返回值描述**        |
    | 0          | 撤销复位成功          |
    | 负数       | 撤销复位失败          |

    ```c
    int32_t ret;
    uint8_t comboDev;

    /* 通路序号为0 */
    comboDev = 0;
    /* 撤销复位MIPI RX */
    ret = MipiCsiUnresetRx(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiUnresetRx fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

### 使能/关闭MIPI的时钟<a name="section2.6_MIPI_CSIDes"></a>

-   使能MIPI的时钟

    ```c
    int32_t MipiCsiEnableClock(DevHandle handle, uint8_t comboDev);
    ```

    **表 13**  MipiCsiEnableClock的参数和返回值描述

    <a name="table13_MIPI_CSIDes"></a>

    | 参数       | 参数描述       |
    | ---------- | -------------- |
    | handle     | 控制器操作句柄 |
    | comboDev   | 通路序号       |
    | **返回值** | **返回值描述** |
    | 0          | 使能成功       |
    | 负数       | 使能失败       |

    ```c
    int32_t ret;
    uint8_t comboDev;

    /* 通路序号为0 */
    comboDev = 0;
    /* 使能MIPI的时钟 */
    ret = MipiCsiEnableClock(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiEnableClock fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   关闭MIPI的时钟

    ```c
    int32_t MipiCsiDisableClock(DevHandle handle, uint8_t comboDev);
    ```

    **表 14**  MipiCsiDisableClock的参数和返回值描述

    <a name="table14_MIPI_CSIDes"></a>

    | 参数       | 参数描述       |
    | ---------- | -------------- |
    | handle     | 控制器操作句柄 |
    | comboDev   | 通路序号       |
    | **返回值** | **返回值描述** |
    | 0          | 关闭成功       |
    | 负数       | 关闭失败       |

    ```c
    int32_t ret;
    uint8_t comboDev;

    /* 通路序号为0 */
    comboDev = 0;
    /* 关闭MIPI的时钟 */
    ret = MipiCsiDisableClock(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiDisableClock fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

### 使能/关闭MIPI上的Sensor时钟<a name="section2.7_MIPI_CSIDes"></a>

-   使能MIPI上的Sensor时钟

    ```c
    int32_t MipiCsiEnableSensorClock(DevHandle handle, uint8_t snsClkSource);
    ```

    **表 15**  MipiCsiEnableSensorClock的参数和返回值描述

    <a name="table15_MIPI_CSIDes"></a>

    | 参数         | 参数描述                                         |
    | ------------ | ------------------------------------------------ |
    | handle       | 控制器操作句柄                                   |
    | snsClkSource | 传感器的时钟信号线号，在软件中称为传感器的时钟源 |
    | **返回值**   | **返回值描述**                                   |
    | 0            | 使能成功                                         |
    | 负数         | 使能失败                                         |

    ```c
    int32_t ret;
    uint8_t snsClkSource;

    /* 传感器的时钟信号线号为0 */
    snsClkSource = 0;
    /* 使能MIPI上的sensor时钟 */
    ret = MipiCsiEnableSensorClock(MipiCsiHandle, snsClkSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiEnableSensorClock fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

-   关闭MIPI上的Sensor时钟

    ```c
    int32_t MipiCsiDisableSensorClock(DevHandle handle, uint8_t snsClkSource);
    ```

    **表 16**  MipiCsiDisableSensorClock的参数和返回值描述

    <a name="table16_MIPI_CSIDes"></a>

    | 参数         | 参数描述                                         |
    | ------------ | ------------------------------------------------ |
    | handle       | 控制器操作句柄                                   |
    | snsClkSource | 传感器的时钟信号线号，在软件中称为传感器的时钟源 |
    | **返回值**   | **返回值描述**                                   |
    | 0            | 关闭成功                                         |
    | 负数         | 关闭失败                                         |

    ```c
    int32_t ret;
    uint8_t snsClkSource;

    /* 传感器的时钟信号线号为0 */
    snsClkSource = 0;
    /* 关闭MIPI上的Sensor时钟 */
    ret = MipiCsiDisableSensorClock(MipiCsiHandle, snsClkSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiDisableSensorClock fail! ret=%d\n", __func__, ret);
        return -1;
    }
    ```

### 释放MIPI CSI控制器操作句柄<a name="section2.8_MIPI_CSIDes"></a>

MIPI CSI使用完成之后，需要释放控制器操作句柄，释放句柄的函数如下所示：

```c
void MipiCsiClose(DevHandle handle);
```

该函数会释放掉由MipiCsiOpen申请的资源。

**表 17**  MipiCsiClose的参数和返回值描述

<a name="table17_MIPI_CSIDes"></a>

 | 参数         | 参数描述                                         |
 | ------------ | ------------------------------------------------ |
 | handle       | MIPI CSI控制器操作句柄                                  |

```c
MipiCsiClose(MIPIHandle); /* 释放掉MIPI CSI控制器操作句柄 */
```

## 使用实例<a name="section3_MIPI_CSIDes"></a>

MIPI CSI完整的使用示例如下所示：

```c
#include "hdf.h"
#include "MIPI_csi_if.h"

void PalMipiCsiTestSample(void)
{
    uint8_t id;
    int32_t ret;
    uint8_t comboDev;
    uint8_t snsClkSource;
    uint8_t devno;
    enum LaneDivideMode mode;
    enum PhyCmvMode mode;
    struct ComboDevAttr attr;
    struct ExtDataType dataType;
    DevHandle MipiCsiHandle = NULL;
    
    /* 控制器ID号 */
    id = 0; 
    /* 获取控制器操作句柄 */
    MipiCsiHandle = MipiCsiOpen(id);
    if (MipiCsiHandle == NULL) {
        HDF_LOGE("MipiCsiOpen: failed!\n");
        return;
    }
    
    /* lane模式参数为0 */
    mode = LANE_DIVIDE_MODE_0;
    /* 设置MIPI RX的 Lane分布 */
    ret = MipiCsiSetHsMode(MipiCsiHandle, mode);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetHsMode fail! ret=%d\n", __func__, ret);
        return;
    }

    /* 通路序号为0 */
    comboDev = 0;
    /* 使能MIPI的时钟 */
    ret = MipiCsiEnableClock(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiEnableClock fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 复位MIPI RX */
    ret = MipiCsiResetRx(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiResetRx fail! ret=%d\n", __func__, ret);
        return;
    }

    /* 传感器的时钟信号线号为0 */
    snsClkSource = 0;
    /* 使能MIPI上的sensor时钟 */
    ret = MipiCsiEnableSensorClock(MipiCsiHandle, snsClkSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiEnableSensorClock fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 复位sensor */
    ret = MipiCsiResetSensor(MipiCsiHandle, snsResetSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiResetSensor fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* MIPI参数配置如下 */
    (void)memset_s(&attr, sizeof(ComboDevAttr), 0, sizeof(ComboDevAttr));
    attr.devno = 0; /* 设备0 */
    attr.inputMode = INPUT_MODE_MIPI; /* 输入模式为MIPI */
    attr.dataRate = MIPI_DATA_RATE_X1; /* 每时钟输出1像素 */
    attr.imgRect.x = 0; /* 0: 图像传感器左上位置 */
    attr.imgRect.y = 0; /* 0: 图像传感器右上位置 */
    attr.imgRect.width = 2592; /* 2592: 图像传感器宽度大小 */
    attr.imgRect.height = 1944; /* 1944: 图像传感器高度尺寸 */
    /* 写入配置数据 */
    ret = MipiCsiSetComboDevAttr(MipiCsiHandle, &attr);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetComboDevAttr fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 共模电压模式参数为0 */
    mode = PHY_CMV_GE1200MV;
    /* 设备编号为0 */
    devno = 0;
    /* 设置共模电压模式 */
    ret = MipiCsiSetPhyCmvmode(MipiCsiHandle, devno, mode);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiSetPhyCmvmode fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 通路序号为0 */
    comboDev = 0;
    /* 撤销复位MIPI RX */
    ret = MipiCsiUnresetRx(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiUnresetRx fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 关闭MIPI的时钟 */
    ret = MipiCsiDisableClock(MipiCsiHandle, comboDev);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiDisableClock fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 传感器撤销复位信号线号为0 */
    snsResetSource = 0;
    /* 撤销复位sensor */
    ret = MipiCsiUnresetSensor(MipiCsiHandle, snsResetSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiUnresetSensor fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 关闭MIPI上的sensor时钟 */
    ret = MipiCsiDisableSensorClock(MipiCsiHandle, snsClkSource);
    if (ret != 0) {
        HDF_LOGE("%s: MipiCsiDisableSensorClock fail! ret=%d\n", __func__, ret);
        return;
    }
    
    /* 释放MIPI DSI设备句柄 */
    MipiCsiClose(MipiCsiHandle); 
}
```

