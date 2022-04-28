# PWM<a name="title_PWM_des"></a>

-   [概述](#section1_PWM_des)
    -   [PwmConfig结构体](#section1.1_PWM_des)
-   [接口说明](#section2_PWM_des)
-   [使用指导](#section3_PWM_des)
    -   [使用流程](#section3.1_PWM_des)
    -   [获取PWM设备句柄](#section3.2_PWM_des)
    -   [销毁PWM设备句柄](#section3.3_PWM_des)
    -   [使能](#section3.4_PWM_des)
    -   [禁用](#section3.5_PWM_des)
    -   [设置PWM设备周期](#section3.6_PWM_des)
    -   [设置PWM设备占空时间](#section3.7_PWM_des)
    -   [设置PWM设备极性](#section3.8_PWM_des)
    -   [设置PWM设备参数](#section3.9_PWM_des)
    -   [获取PWM设备参数](#section3.10_PWM_des)

-   [使用实例](#section3_PWM_des)

## 概述<a name="section1_PWM_des"></a>

- PWM是脉冲宽度调制（Pulse Width Modulation）的缩写，是一种对模拟信号电平进行数字编码，转换为脉冲的一种技术。常用于马达控制、背光亮度调节等。

- PWM接口定义了操作PWM设备的通用方法集合，包括：
  - PWM设备句柄获取和销毁。
  - PWM周期、占空比、极性的设置。
  - PWM使能和关闭。
  - PWM配置信息的获取和设置

### PwmConfig结构体<a name="section1.1_PWM_des"></a>

**表1**  PwmConfig结构体介绍

<a name="table1_PWM_des"></a>

| 名称     | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| duty     | 占空时间，以纳秒为单位                                       |
| period   | PWM周期，以纳秒为单位                                        |
| number   | 要生成的方波数。正值表示将生成指定数量的方波，<b>0</b>表示方波将不断产生 |
| polarity | 极性：正极性/反极性                                          |
| status   | 状态：启用状态/禁用状态                                      |

## 接口说明<a name="section2_PWM_des"></a>

**表2**  PWM设备API接口功能介绍

<a name="table2_PWM_des"></a>

<table border="0" cellpadding="0" cellspacing="0" width="800" style="border-collapse:
 collapse;table-layout:fixed;width:700pt">
  <td height="19" class="xl66" width="300" style="height:14.25pt;width:300pt">功能分类</td>
  <td class="xl67" width="250" style="width:250pt">接口名</td>
  <td class="xl67" width="300" style="width:300pt">描述</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="2" height="38" class="xl65" style="height:28.5pt">PWM句柄操作</td>
  <td>PwmOpen</td>
  <td>获取PWM设备驱动句柄</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">PwmClose</td>
  <td>释放PWM设备驱动句柄</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="2" height="38" class="xl65" style="height:28.5pt">使能/禁用PWM</td>
  <td>PwmEnable</td>
  <td>使能PWM</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">PwmDisable</td>
  <td>禁用PWM</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="3" height="57" class="xl65" style="height:42.75pt">PWM配置操作</td>
  <td>PwmSetPeriod</td>
  <td>设置PWM周期</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">PwmSetDuty</td>
  <td>设置PWM占空时间</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">PwmSetPolarity</td>
  <td>设置PWM极性</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td rowspan="2" height="38" class="xl65" style="height:28.5pt">设置/获取PWM配置信息</td>
  <td>PwmSetConfig</td>
  <td>设置PWM设备参数</td>
 </tr>
 <tr height="19" style="height:14.25pt">
  <td height="19" style="height:14.25pt">PwmGetConfig</td>
  <td>获取PWM设备参数</td>
 </tr>
</tbody></table>



> ![icon-note.gif](../public_sys-resources/icon-note.gif) **说明：**
>PWM当前仅限内核态使用，不支持在用户态使用。

## 使用指导<a name="section3_PWM_des"></a>

### 使用流程<a name="section3.1_PWM_des"></a>

在操作系统启动过程中，驱动管理模块根据配置文件加载PWM驱动，PWM驱动会检测PWM器件并初始化驱动。

使用PWM设备的一般流程如[图1](#fig1_PWM_des)所示。

**图 1**  PWM设备使用流程图<a name="fig1_PWM_des"></a>  


![](figures/PWM设备使用流程图.png)

### 获取PWM设备句柄<a name="section3.2_PWM_des"></a>

在操作PWM设备时，首先要调用PwmOpen获取PWM设备句柄，该函数会返回指定设备号的PWM设备句柄。

```c
DevHandle PwmOpen(uint32_t num);
```

**表3**  PwmOpen参数和返回值描述

<a name="table3_PWM_des"></a>

| 参数       | 参数描述                |
| ---------- | ----------------------- |
| num        | PWM设备编号             |
| **返回值** | **返回值描述**          |
| handle     | 获取成功返回PWM设备句柄 |
| NULL       | 获取失败                |


```c
uint32_t num = 0;             /* PWM设备号 */
DevHandle handle = NULL;

/* 获取PWM设备句柄 */
handle = PwmOpen(num);
if (handle  == NULL) {
    /* 错误处理 */
}
```

### 销毁PWM设备句柄<a name="section3.3_PWM_des"></a>

关闭PWM设备，系统释放对应的资源。

```c
void PwmClose(DevHandle handle);
```

**表4**  PwmClose参数描述

<a name="table4_PWM_des"></a>

| 参数   | 参数描述    |
| ------ | ----------- |
| handle | PWM设备句柄 |


```c
/* 销毁PWM设备句柄 */
PwmClose(handle);
```

### 使能<a name="section3.4_PWM_des"></a>

启用PWM设备。

```c
int32_t PwmEnable(DevHandle handle);
```

**表5** PwmEnable参数描述

<a name="table5_PWM_des"></a>

| 参数       | 参数描述       |
| ---------- | -------------- |
| handle     | PWM设备句柄    |
| **返回值** | **返回值描述** |
| 0          | 使能成功       |
| 负数       | 使能失败       |

```c
int32_t ret;

/*启用PWM设备*/
ret = PwmEnable(handle);
if (ret != 0) {
	/*错误处理*/
}
```

### 禁用<a name="section3.5_PWM_des"></a>

禁用PWM设备。

```c
int32_t PwmDisable(DevHandle handle);
```

**表6** PwmDisable参数描述

<a name="table6_PWM_des"></a>

| 参数       | 参数描述       |
| ---------- | -------------- |
| handle     | PWM设备句柄    |
| **返回值** | **返回值描述** |
| 0          | 禁用成功       |
| 负数       | 禁用失败       |

```c
int32_t ret;

/*禁用PWM设备*/
ret = PwmDisable(handle);
if (ret != 0) {
	/*错误处理*/
}
```

### 设置PWM设备周期<a name="section3.6_PWM_des"></a>

设置PWM设备周期。

```c
int32_t PwmSetPeriod(DevHandle handle, uint32_t period);
```

**表7** PwmSetPeriod参数描述

<a name="table7_PWM_des"></a>

| 参数       | 参数描述                 |
| ---------- | ------------------------ |
| handle     | PWM设备句柄              |
| period     | 要设置的周期，单位为纳秒 |
| **返回值** | **返回值描述**           |
| 0          | 设置成功                 |
| 负数       | 设置失败                 |

```c
int32_t ret;

/*设置周期为50000000纳秒*/
ret = PwmSetPeriod(handle, 50000000);
if (ret != 0) {
	/*错误处理*/
}
```
### 设置PWM设备占空时间<a name="section3.7_PWM_des"></a>

设置PWM设备占空时间。

```c
int32_t PwmSetDuty(DevHandle handle, uint32_t duty);
```

**表8** PwmSetDuty参数描述

<a name="table8_PWM_des"></a>

| 参数       | 参数描述                     |
| ---------- | ---------------------------- |
| handle     | PWM设备句柄                  |
| duty       | 要设置的占空时间，单位为纳秒 |
| **返回值** | **返回值描述**               |
| 0          | 设置成功                     |
| 负数       | 设置失败                     |

```c
int32_t ret;

/*设置占空时间为25000000纳秒*/
ret = PwmSetDuty(handle, 25000000);
if (ret != 0) {
	/*错误处理*/
}
```
### 设置PWM设备极性<a name="section3.8_PWM_des"></a>

设置PWM设备极性。

```c
int32_t PwmSetPolarity(DevHandle handle, uint8_t polarity);
```

**表9** PwmSetPolarity参数描述

<a name="table9_PWM_des"></a>

| 参数       | 参数描述            |
| ---------- | ------------------- |
| handle     | PWM设备句柄         |
| polarity   | 要设置的极性，正/反 |
| **返回值** | **返回值描述**      |
| 0          | 设置成功            |
| 负数       | 设置失败            |

```c
int32_t ret;

/*设置极性为反*/
ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);
if (ret != 0) {
	/*错误处理*/
}
```


### 设置PWM设备参数<a name="section3.9_PWM_des"></a>

设置PWM设备参数。

```c
int32_t PwmSetConfig(DevHandle handle, struct PwmConfig *config);
```

**表10** PwmSetConfig参数描述

<a name="table10_PWM_des"></a>

| 参数       | 参数描述       |
| ---------- | -------------- |
| handle     | PWM设备句柄    |
| *config    | 参数指针       |
| **返回值** | **返回值描述** |
| 0          | 设置成功       |
| 负数       | 设置失败       |

```c
int32_t ret;
struct PwmConfig pcfg;
pcfg.duty = 25000000;					/*占空时间为25000000纳秒*/                  
pcfg.period = 50000000;					/*周期为50000000纳秒*/
pcfg.number = 0;						/*不断产生方波*/
pcfg.polarity = PWM_INVERTED_POLARITY;	/*极性为反*/
pcfg.status = PWM_ENABLE_STATUS;		/*运行状态为启用*/

/*设置PWM设备参数*/
ret = PwmSetConfig(handle, &pcfg);
if (ret != 0) {
	/*错误处理*/
}
```

### 获取PWM设备参数<a name="section3.10_PWM_des"></a>

获取PWM设备参数。

```c
int32_t PwmGetConfig(DevHandle handle, struct PwmConfig *config);
```

**表11** PwmGetConfig参数描述

<a name="table11_PWM_des"></a>

| 参数       | 参数描述       |
| ---------- | -------------- |
| handle     | PWM设备句柄    |
| *config    | 参数指针       |
| **返回值** | **返回值描述** |
| 0          | 获取成功       |
| 负数       | 获取失败       |

```c
int32_t ret;
struct PwmConfig pcfg;

/*获取PWM设备参数*/
ret = PwmGetConfig(handle, &pcfg);
if (ret != 0) {
	/*错误处理*/
}
```

## 使用实例<a name="section4_PWM_des"></a>

PWM设备完整的使用示例如下所示，首先获取PWM设备句柄，然后设置设备周期、占空时间、极性，获取设备参数。使能，设置设备参数，禁用，最后销毁PWM设备句柄。

```
void PwmTestSample(void)
{
    int32_t ret;
    uint32_t num;
    DevHandle handle = NULL;

    struct PwmConfig pcfg;
    pcfg.duty = 20000000;					/*占空时间为20000000纳秒*/                  
    pcfg.period = 40000000;					/*周期为40000000纳秒*/
    pcfg.number = 100;						/*生成100个方波*/
    pcfg.polarity = PWM_NORMAL_POLARITY;	/*极性为正*/
    pcfg.status = PWM_ENABLE_STATUS;		/*运行状态为启用*/
    
    /* PWM设备编号，要填写实际平台上的编号 */
    num = 1; 

    /* 获取PWM设备句柄 */
    handle = PwmOpen(num);
    if (handle == NULL) {
        HDF_LOGE("PwmOpen: failed!\n");
        return;
    }

    /*设置周期为50000000纳秒*/
    ret = PwmSetPeriod(handle, 50000000);
    if (ret != 0) {
        HDF_LOGE("PwmSetPeriod: failed, ret %d\n", ret);
        goto _ERR;
    }

    /*设置占空时间为25000000纳秒*/
    ret = PwmSetDuty(handle, 25000000);
    if (ret != 0) {
        HDF_LOGE("PwmSetDuty: failed, ret %d\n", ret);
        goto _ERR;
    }

    /*设置极性为反*/
    ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);
    if (ret != 0) {
        HDF_LOGE("PwmSetPolarity: failed, ret %d\n", ret);
        goto _ERR;
    }
    
    /*获取PWM设备参数*/
    ret = PwmGetConfig(handle, &pcfg);
    if (ret != 0) {
        HDF_LOGE("PwmGetConfig: failed, ret %d\n", ret);
        goto _ERR;
    }
    
    /*启用PWM设备*/
    ret = PwmEnable(handle);
    if (ret != 0) {
	    HDF_LOGE("PwmEnable: failed, ret %d\n", ret);
        goto _ERR;
    }

    /*设置PWM设备参数*/
    ret = PwmSetConfig(handle, &pcfg);
    if (ret != 0) {
        HDF_LOGE("PwmSetConfig: failed, ret %d\n", ret);
        goto _ERR;
    }

    /*禁用PWM设备*/
    ret = PwmDisable(handle);
    if (ret != 0) {
        HDF_LOGE("PwmDisable: failed, ret %d\n", ret);
        goto _ERR;
    }
    
_ERR:
    /* 销毁PWM设备句柄 */
    PwmClose(handle); 
}
```
