# GPIO


## 概述

GPIO（General-purpose input/output）即通用型输入输出。通常，GPIO控制器通过分组的方式管理所有GPIO管脚，每组GPIO有一个或多个寄存器与之关联，通过读写寄存器完成对GPIO管脚的操作。

GPIO接口定义了操作GPIO管脚的标准方法集合，包括：

- 设置管脚方向：方向可以是输入或者输出（暂不支持高阻态）

- 读写管脚电平值：电平值可以是低电平或高电平

- 设置管脚中断服务函数：设置一个管脚的中断响应函数，以及中断触发方式

- 使能和禁止管脚中断：禁止或使能管脚中断


## 接口说明

  **表1** GPIO驱动API接口功能介绍

| 功能分类 | 接口描述 | 
| -------- | -------- |
| GPIO读写 | -&nbsp;GpioRead：读管脚电平值<br/>-&nbsp;GpioWrite：写管脚电平值 | 
| GPIO配置 | -&nbsp;GpioSetDir：设置管脚方向<br/>-&nbsp;GpioGetDir：获取管脚方向 | 
| GPIO中断设置 | -&nbsp;GpioSetIrq：设置管脚对应的中断服务函数<br/>-&nbsp;GpioUnsetIrq：取消管脚对应的中断服务函数<br/>-&nbsp;GpioEnableIrq：使能管脚中断<br/>-&nbsp;GpioDisableIrq：禁止管脚中断 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
> 本文涉及的所有接口，仅限内核态使用，不支持在用户态使用。


## 使用指导


### 使用流程

GPIO标准API通过GPIO管脚号来操作指定管脚，使用GPIO的一般流程如下图所示。

  **图1** GPIO使用流程图

  ![image](figures/GPIO使用流程图.png "GPIO使用流程图")


### 确定GPIO管脚号

不同SOC芯片由于其GPIO控制器型号、参数、以及控制器驱动的不同，GPIO管脚号的换算方式不一样。

- Hi3516DV300
  控制器管理12组GPIO管脚，每组8个。

  GPIO号 = GPIO组索引 (0~11) \* 每组GPIO管脚数(8) + 组内偏移

  举例：GPIO10_3的GPIO号 = 10 \* 8 + 3 = 83

- Hi3518EV300
  控制器管理10组GPIO管脚，每组10个。

  GPIO号 = GPIO组索引 (0~9) \* 每组GPIO管脚数(10) + 组内偏移

  举例：GPIO7_3的GPIO管脚号 = 7 \* 10 + 3 = 73


### 使用API操作GPIO管脚

- 设置GPIO管脚方向
  在进行GPIO管脚读写前，需要先通过如下函数设置GPIO管脚方向：

  int32_t GpioSetDir(uint16_t gpio, uint16_t dir);

    **表2** GpioSetDir参数和返回值描述
  
  | **参数**| **参数描述** |
  | -------- | -------- |
  | gpio | 待设置的GPIO管脚号 | 
  | dir | 待设置的方向值 | 
  | **返回值** | **返回值描述** | 
  | 0 | 设置成功 | 
  | 负数 | 设置失败 | 

- 读写GPIO管脚

  如果要读取一个GPIO管脚电平，通过以下函数完成：

  int32_t GpioRead(uint16_t gpio, uint16_t \*val);

    **表3** GpioRead参数和返回值描述
  
  | **参数** | **参数描述** | 
  | -------- | -------- | 
  | gpio | 待读取的GPIO管脚号 | 
  | val | 接收读取电平值的指针 | 
  | **返回值** | **返回值描述** | 
  | 0 | 读取成功 | 
  | 负数 | 读取失败 | 

  如果要向GPIO管脚写入电平值，通过以下函数完成：

  int32_t GpioWrite(uint16_t gpio, uint16_t val);

    **表4** GpioWrite参数和返回值描述
  
  | **参数** | **参数描述** | 
  | -------- | -------- |
  | gpio | 待写入的GPIO管脚号 | 
  | val | 待写入的电平值 | 
  | **返回值** | **返回值描述** | 
  | 0 | 写入成功 | 
  | 负数 | 写入失败 | 

  示例代码：

    
  ```
  int32_t ret;
  uint16_t val;
  /* 将3号GPIO管脚配置为输出 */
  ret = GpioSetDir(3, GPIO_DIR_OUT);
  if (ret != 0) {
      HDF_LOGE("GpioSerDir: failed, ret %d\n", ret);
      return;
  }
  /* 向3号GPIO管脚写入低电平GPIO_VAL_LOW */
  ret = GpioWrite(3, GPIO_VAL_LOW);
  if (ret != 0) {
      HDF_LOGE("GpioWrite: failed, ret %d\n", ret);
      return;
  }
  /* 将6号GPIO管脚配置为输入 */
  ret = GpioSetDir(6, GPIO_DIR_IN);
  if (ret != 0) {
      HDF_LOGE("GpioSetDir: failed, ret %d\n", ret);
      return;
  }
  /* 读取6号GPIO管脚的电平值 */
  ret = GpioRead(6, &val);
  ```

- 设置GPIO中断

  如果要为一个GPIO管脚设置中断响应程序，使用如下函数：

  int32_t GpioSetIrq(uint16_t gpio, uint16_t mode, GpioIrqFunc func, void \*arg);

    **表5** GpioSetIrq参数和返回值描述
  
  | **参数** | **参数描述** | 
  | -------- | -------- |
  | gpio | GPIO管脚号 | 
  | mode | 中断触发模式 | 
  | func | 中断服务程序 | 
  | arg | 传递给中断服务程序的入参 | 
  | **返回值** | **返回值描述** | 
  | 0 | 设置成功 | 
  | 负数 | 设置失败 | 

  > ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**<br>
  > 同一时间，只能为某个GPIO管脚设置一个中断服务函数，如果重复调用GpioSetIrq函数，则之前设置的中断服务函数会被取代。

  当不再需要响应中断服务函数时，使用如下函数取消中断设置：

  int32_t GpioUnsetIrq(uint16_t gpio, void \*arg);

    **表6** GpioUnsetIrq参数和返回值描述
  
  | **参数** | **参数描述** | 
  | -------- | -------- |
  | gpio | GPIO管脚号 | 
  | arg  | GPIO中断数据 | 
  | **返回值** | **返回值描述** | 
  | 0 | 取消成功 | 
  | 负数 | 取消失败 | 

  在中断服务程序设置完成后，还需要先通过如下函数使能GPIO管脚的中断：

  int32_t GpioEnableIrq(uint16_t gpio);

    **表7** GpioEnableIrq参数和返回值描述
  
  | **参数** | **参数描述** | 
  | -------- | -------- |
  | gpio | GPIO管脚号 | 
  | **返回值** | **返回值描述** | 
  | 0 | 使能成功 | 
  | 负数 | 使能失败 | 

  > ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**<br>
  > 必须通过此函数使能管脚中断，之前设置的中断服务函数才能被正确响应。

  如果要临时屏蔽此中断，可以通过如下函数禁止GPIO管脚中断：

  int32_t GpioDisableIrq(uint16_t gpio);

    **表8** GpioDisableIrq参数和返回值描述
  
  | **参数** | **参数描述** | 
  | -------- | -------- |
  | gpio | GPIO管脚号 | 
  | **返回值** | **返回值描述** | 
  | 0 | 禁止成功 | 
  | 负数 | 禁止失败 | 

  示例代码：

    
  ```
  /* 中断服务函数*/
  int32_t MyCallBackFunc(uint16_t gpio, void *data)
  {
      HDF_LOGI("%s: gpio:%u interrupt service in! data=%p\n", __func__, gpio, data);
      return 0;
  }
  
  int32_t ret;
  /* 设置中断服务程序为MyCallBackFunc，入参为NULL，中断触发模式为上升沿触发 */
  ret = GpioSetIrq(3, OSAL_IRQF_TRIGGER_RISING, MyCallBackFunc, NULL);
  if (ret != 0) {
      HDF_LOGE("GpioSetIrq: failed, ret %d\n", ret);
      return;
  }
  
  /* 使能3号GPIO管脚中断 */
  ret = GpioEnableIrq(3);
  if (ret != 0) {
      HDF_LOGE("GpioEnableIrq: failed, ret %d\n", ret);
      return;
  }
  
  /* 禁止3号GPIO管脚中断 */
  ret = GpioDisableIrq(3);
  if (ret != 0) {
      HDF_LOGE("GpioDisableIrq: failed, ret %d\n", ret);
      return;
  }
  
  /* 取消3号GPIO管脚中断服务程序 */
  ret = GpioUnsetIrq(3, NULL);
  if (ret != 0) {
      HDF_LOGE("GpioUnSetIrq: failed, ret %d\n", ret);
      return;
  }
  ```


## 使用实例

本实例程序中，我们将测试一个GPIO管脚的中断触发：为管脚设置中断服务函数，触发方式为边沿触发，然后通过交替写高低电平到管脚，产生电平波动，制造触发条件，观察中断服务函数的执行。

首先需要选取一个空闲的GPIO管脚，本例程基于Hi3516DV300某开发板，GPIO管脚选择GPIO10_3，换算成GPIO号为83。

  读者可以根据自己使用的开发板，参考其原理图，选择一个空闲的GPIO管脚即可。
  
```
#include "gpio_if.h"
#include "hdf_log.h"
#include "osal_irq.h"
#include "osal_time.h"

static uint32_t g_irqCnt;

/* 中断服务函数*/
static int32_t TestCaseGpioIrqHandler(uint16_t gpio, void *data)
{
    HDF_LOGE("%s: irq triggered! on gpio:%u, data=%p", __func__, gpio, data);
    g_irqCnt++; /* 如果中断服务函数触发执行，则将全局中断计数加1 */
    return GpioDisableIrq(gpio);
}

/* 测试用例函数 */
static int32_t TestCaseGpioIrqEdge(void)
{
    int32_t ret;
    uint16_t valRead;
    uint16_t mode;
    uint16_t gpio = 83; /* 待测试的GPIO管脚号 */
    uint32_t timeout;

    /* 将管脚方向设置为输出 */
    ret = GpioSetDir(gpio, GPIO_DIR_OUT);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set dir fail! ret:%d\n", __func__, ret);
        return ret;
    }

    /* 先禁止该管脚中断 */
    ret = GpioDisableIrq(gpio);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: disable irq fail! ret:%d\n", __func__, ret);
        return ret;
    }

    /* 为管脚设置中断服务函数，触发模式为上升沿和下降沿共同触发 */
    mode = OSAL_IRQF_TRIGGER_RISING | OSAL_IRQF_TRIGGER_FALLING;
    HDF_LOGE("%s: mode:%0x\n", __func__, mode);
    ret = GpioSetIrq(gpio, mode, TestCaseGpioIrqHandler, NULL);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set irq fail! ret:%d\n", __func__, ret);
        return ret;
    }

    /* 使能此管脚中断 */
    ret = GpioEnableIrq(gpio);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: enable irq fail! ret:%d\n", __func__, ret);
        (void)GpioUnsetIrq(gpio, NULL);
        return ret;
    }

    g_irqCnt = 0; /* 清除全局计数器 */
    timeout = 0;  /* 等待时间清零 */
    /* 等待此管脚中断服务函数触发，等待超时时间为1000毫秒 */
    while (g_irqCnt <= 0 && timeout < 1000) {
        (void)GpioRead(gpio, &valRead);
        (void)GpioWrite(gpio, (valRead == GPIO_VAL_LOW) ? GPIO_VAL_HIGH : GPIO_VAL_LOW);
        HDF_LOGE("%s: wait irq timeout:%u\n", __func__, timeout);
        OsalMDelay(200); /* wait for irq trigger */
        timeout += 200;
    }
    (void)GpioUnsetIrq(gpio, NULL);
    return (g_irqCnt > 0) ? HDF_SUCCESS : HDF_FAILURE;
}
```
