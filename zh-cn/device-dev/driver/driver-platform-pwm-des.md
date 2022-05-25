# PWM


## 概述

PWM是脉冲宽度调制（Pulse Width Modulation）的缩写，是一种对模拟信号电平进行数字编码并将其转换为脉冲的技术。常用于马达控制、背光亮度调节等。

PWM接口定义了操作PWM设备的通用方法集合，包括：
- PWM设备句柄获取和释放。

- PWM周期、占空比、极性的设置。

- PWM使能和关闭。

- PWM配置信息的获取和设置。


### PwmConfig结构体

  **表1** PwmConfig结构体介绍

| 名称 | 描述 | 
| -------- | -------- |
| duty | 占空时间，以纳秒为单位。 | 
| period | PWM周期，以纳秒为单位。 | 
| number | 要生成的方波数：<br/>-&nbsp;正值：表示将生成指定数量的方波<br/>-&nbsp;0：表示方波将不断产生 | 
| polarity | 极性：正极性/反极性。 | 
| status | 状态：启用状态/禁用状态。 | 


## 接口说明

  **表2** PWM驱动API接口功能介绍

| 功能分类 | 接口描述 | 
| -------- | -------- |
| PWM句柄操作 | -&nbsp;PwmOpen：获取PWM设备驱动句柄<br/>-&nbsp;PwmClose：释放PWM设备驱动句柄 | 
| 使能/禁用PWM | -&nbsp;PwmEnable：使能PWM<br/>-&nbsp;PwmDisable：禁用PWM | 
| PWM配置操作 | -&nbsp;PwmSetPeriod：设置PWM周期<br/>-&nbsp;PwmSetDuty：设置PWM占空时间<br/>-&nbsp;PwmSetPolarity：设置PWM极性 | 
| 设置/获取PWM配置信息 | -&nbsp;PwmSetConfig：设置PWM设备参数<br/>-&nbsp;PwmGetConfig：获取PWM设备参数 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
> 本文涉及的所有接口，仅限内核态使用，不支持在用户态使用。


## 使用指导


### 使用流程

使用PWM的一般流程如下图所示。

  **图1** PWM使用流程图

![image](figures/PWM设备使用流程图.png "PWM设备使用流程图")


### 获取PWM设备句柄

在操作PWM设备时，首先要调用PwmOpen获取PWM设备句柄，该函数会返回指定设备号的PWM设备句柄。


```
DevHandle PwmOpen(uint32_t num);
```

  **表3** PwmOpen参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| num        | PWM设备编号             |
| **返回值** | **返回值描述**          |
| handle     | 获取成功，返回PWM设备句柄 |
| NULL       | 获取失败                |

假设系统中的PWM设备号为0，获取该PWM设备句柄的示例如下：


```
uint32_t num = 0;             /* PWM设备号 */
DevHandle handle = NULL;

/* 获取PWM设备句柄 */
handle = PwmOpen(num);
if (handle  == NULL) {
    /* 错误处理 */
}
```


### 销毁PWM设备句柄

关闭PWM设备，系统释放对应的资源。


```
voidPwmClose(DevHandle handle);
```

  **表4** PwmClose参数描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle   | PWM设备句柄  |


```
/* 销毁PWM设备句柄 */
PwmClose(handle);
```


### 使能

启用PWM设备。


```
int32_t PwmEnable(DevHandle handle);
```

  **表5** PwmEnable参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄    |
| **返回值** | **返回值描述** |
| 0          | 使能成功       |
| 负数       | 使能失败       |


```
int32_t ret;

/*启用PWM设备*/
ret = PwmEnable(handle);
if (ret != 0) {
	/*错误处理*/
}
```


### 禁用

禁用PWM设备。


```
int32_t PwmDisable(DevHandle handle);
```

  **表6** PwmDisable参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄    |
| **返回值** | **返回值描述** |
| 0          | 禁用成功       |
| 负数       | 禁用失败       |


```
int32_t ret;

/* 禁用PWM设备 */
ret = PwmDisable(handle);
if (ret != 0) {
	/* 错误处理 */
}
```


### 设置PWM设备周期

设置PWM设备周期。


```
int32_t PwmSetPeriod(DevHandle handle, uint32_t period);
```

  **表7** PwmSetPeriod参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄              |
| period     | 要设置的周期，单位为纳秒 |
| **返回值** | **返回值描述**           |
| 0          | 设置成功                 |
| 负数       | 设置失败                 |


```
int32_t ret;

/* 设置周期为50000000纳秒 */
ret = PwmSetPeriod(handle, 50000000);
if (ret != 0) {
	/*错误处理*/
}
```


### 设置设备占空时间

设置PWM设备占空时间。


```
int32_t PwmSetDuty(DevHandle handle, uint32_t duty);
```

  **表8** PwmSetDuty参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄                  |
| duty       | 要设置的占空时间，单位为纳秒 |
| **返回值** | **返回值描述**               |
| 0          | 设置成功                     |
| 负数       | 设置失败                     |


```
int32_t ret;

/* 设置占空时间为25000000纳秒 */
ret = PwmSetDuty(handle, 25000000);
if (ret != 0) {
	/* 错误处理 */
}
```


### 设置PWM设备极性

设置PWM设备极性。


```
int32_t PwmSetPolarity(DevHandle handle, uint8_t polarity);
```

  **表9** PwmSetPolarity参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄         |
| polarity   | 要设置的极性，正/反 |
| **返回值** | **返回值描述**      |
| 0          | 设置成功            |
| 负数       | 设置失败            |


```
int32_t ret;

/* 设置极性为反 */
ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);
if (ret != 0) {
	/* 错误处理 */
}
```


### 设置PWM设备参数

设置PWM设备参数。


```
int32_t PwmSetConfig(DevHandle handle, struct PwmConfig *config);
```

  **表10** PwmSetConfig参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄    |
| \*config   | 参数指针       |
| **返回值** | **返回值描述** |
| 0          | 设置成功       |
| 负数       | 设置失败       |


```
int32_t ret;
struct PwmConfig pcfg;
pcfg.duty = 25000000;			/* 占空时间为25000000纳秒 */                  
pcfg.period = 50000000;			/* 周期为50000000纳秒 */
pcfg.number = 0;			/* 不断产生方波 */
pcfg.polarity = PWM_INVERTED_POLARITY;	/* 极性为反 */
pcfg.status = PWM_ENABLE_STATUS;	/* 运行状态为启用 */

/* 设置PWM设备参数 */
ret = PwmSetConfig(handle, &pcfg);
if (ret != 0) {
	/* 错误处理 */
}
```


### 获取PWM设备参数

获取PWM设备参数。


```
int32_t PwmGetConfig(DevHandle handle, struct PwmConfig *config);
```

  **表11** PwmGetConfig参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle     | PWM设备句柄    |
| \*config   | 参数指针       |
| **返回值** | **返回值描述** |
| 0          | 获取成功       |
| 负数       | 获取失败       |


```
int32_t ret;
struct PwmConfig pcfg;

/*获取PWM设备参数*/
ret = PwmGetConfig(handle, &pcfg);
if (ret != 0) {
	/*错误处理*/
}
```


## 使用实例

PWM设备完整的使用示例如下所示，首先获取PWM设备句柄，然后设置设备周期、占空时间、极性，获取设备参数。使能，设置设备参数，禁用，最后销毁PWM设备句柄。


```
void PwmTestSample(void)
{
    int32_t ret;
    uint32_t num;
    DevHandle handle = NULL;

    struct PwmConfig pcfg;
    pcfg.duty = 20000000;			/* 占空时间为20000000纳秒 */                  
    pcfg.period = 40000000;			/* 周期为40000000纳秒 */
    pcfg.number = 100;				/* 生成100个方波 */
    pcfg.polarity = PWM_NORMAL_POLARITY;	/* 极性为正 */
    pcfg.status = PWM_ENABLE_STATUS;		/* 运行状态为启用 */

    /* PWM设备编号，要填写实际平台上的编号 */
    num = 1; 

    /* 获取PWM设备句柄 */
    handle = PwmOpen(num);
    if (handle == NULL) {
        HDF_LOGE("PwmOpen: failed!\n");
        return;
    }

    /* 设置周期为50000000纳秒 */
    ret = PwmSetPeriod(handle, 50000000);
    if (ret != 0) {
        HDF_LOGE("PwmSetPeriod: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* 设置占空时间为25000000纳秒 */
    ret = PwmSetDuty(handle, 25000000);
    if (ret != 0) {
        HDF_LOGE("PwmSetDuty: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* 设置极性为反 */
    ret = PwmSetPolarity(handle, PWM_INVERTED_POLARITY);
    if (ret != 0) {
        HDF_LOGE("PwmSetPolarity: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* 获取PWM设备参数 */
    ret = PwmGetConfig(handle, &pcfg);
    if (ret != 0) {
        HDF_LOGE("PwmGetConfig: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* 启用PWM设备 */
    ret = PwmEnable(handle);
    if (ret != 0) {
	    HDF_LOGE("PwmEnable: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* 设置PWM设备参数 */
    ret = PwmSetConfig(handle, &pcfg);
    if (ret != 0) {
        HDF_LOGE("PwmSetConfig: failed, ret %d\n", ret);
        goto _ERR;
    }

    /* 禁用PWM设备 */
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
