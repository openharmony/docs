# RTC


## 概述

RTC（real-time clock）为操作系统中的实时时钟设备，为操作系统提供精准的实时时间和定时报警功能。当设备下电后，通过外置电池供电，RTC继续记录操作系统时间；设备上电后，RTC提供实时时钟给操作系统，确保断电后系统时间的连续性。


## 接口说明

  **表1** RTC设备API接口功能介绍

| 功能分类 | 接口描述 | 
| -------- | -------- | -------- |
| RTC句柄操作 | RtcOpen：获取RTC设备驱动句柄<br/>RtcClose：释放RTC设备驱动句柄 |
| RTC时间操作接口 | RtcReadTime：读RTC时间信息，包括年、月、星期、日、时、分、秒、毫秒<br/>RtcWriteTime：写RTC时间信息，包括年、月、星期、日、时、分、秒、毫秒 |
| RTC报警操作接口 | RtcReadAlarm：读RTC报警时间信息<br/>RtcWriteAlarm：写RTC报警时间信息<br/>RtcRegisterAlarmCallback：注册报警超时回调函数<br/>RtcAlarmInterruptEnable：使能/去使能RTC报警中断 |
| RTC配置操作 | RtcGetFreq：读RTC外接晶振频率<br/>RtcSetFreq：配置RTC外接晶振频率<br/>RtcReset：RTC复位 |
| 读写用户定义寄存器 | RtcReadReg：读用户自定义寄存器<br/>RtcWriteReg：写用户自定义寄存器 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**</br>
> 本文涉及的所有接口，仅限内核态使用，不支持在用户态使用。


## 使用指导


### 使用流程

在操作系统启动过程中，驱动管理模块根据配置文件加载RTC驱动，RTC驱动会检测RTC器件并初始化驱动。

使用RTC设备的一般流程如下图所示。

  **图1** RTC设备使用流程图

  ![image](figures/RTC设备使用流程图.png "RTC设备使用流程图")


### 创建RTC设备句柄

RTC驱动加载成功后，使用驱动框架提供的查询接口并调用RTC设备驱动接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**</br>
> 当前操作系统支持一个RTC设备。

DevHandle RtcOpen(void);

  **表2** RtcOpen参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| void | NA |
| **返回值** | **描述** |
| handle | 操作成功返回&nbsp;&nbsp;指针类型 |
| NULL | 操作失败 |


```
DevHandle  handle = NULL;

/* 获取RTC句柄 */
handle = RtcOpen();
if (handle  == NULL) {
    /* 错误处理 */
}
```


### 销毁RTC设备句柄

销毁RTC设备句柄，系统释放对应的资源。

void RtcClose(DevHandle handle);

  **表3** RtcClose参数描述

| **参数** | **描述** |
| -------- | -------- |
| handle | RTC设备句柄 |


```
/* 销毁RTC句柄 */
RtcClose(handle);
```


### 注册RTC定时报警回调函数

系统启动后需要注册RTC定时报警回调函数，报警超时后触发回调函数。

int32_t RtcRegisterAlarmCallback(DevHandle handle, enum RtcAlarmIndex alarmIndex, RtcAlarmCallback cb);

  **表4** RtcRegisterAlarmCallback参数和返回值描述

| **参数** | **描述** | 
| -------- | -------- |
| handle | RTC设备句柄 | 
| alarmIndex | 报警索引 | 
| cb | 定时报警回调函数 | 
| **返回值** | **描述** | 
| 0 | 操作成功 | 
| 负数 | 操作失败 | 

  注册RTC_ALARM_INDEX_A的定时报警处理函数， 示例如下：

```
/* 用户注册RTC定时报警回调函数的方法 */
int32_t RtcAlarmACallback(enum RtcAlarmIndex alarmIndex)
{
    if (alarmIndex == RTC_ALARM_INDEX_A) {
        /* 报警A的处理 */
    } else if (alarmIndex == RTC_ALARM_INDEX_B) {
        /* 报警B的处理 */
    } else {
        /* 错误处理 */
    }
    return 0;
}
int32_t ret;
/* 注册报警A的定时回调函数 */
ret = RtcRegisterAlarmCallback(handle, RTC_ALARM_INDEX_A, RtcAlarmACallback);
if (ret != 0) {
    /* 错误处理 */
}
```


### 操作RTC

- 读取RTC时间。

系统从RTC读取时间信息，包括年、月、星期、日、时、分、秒、毫秒，则可以通过以下函数完成：

int32_t RtcReadTime(DevHandle handle, struct RtcTime \*time);

  **表5** RtcReadTime参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle     | RTC设备句柄                                             |
| time       | RTC读取时间信息，包括年、月、星期、日、时、分、秒、毫秒 |
| **返回值** | **描述**                                          |
| 0          | 操作成功                                                |
| 负数       | 操作失败                                                |


```
int32_t ret;
struct RtcTime tm;

/* 系统从RTC读取时间信息 */
ret = RtcReadTime(handle, &tm);
if (ret != 0) {
    /* 错误处理 */
}
```

- 设置RTC时间

设置RTC时间，则可以通过以下函数完成:

int32_t RtcWriteTime(DevHandle handle, struct RtcTime \*time);

  **表6** RtcWriteTime参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle | RTC设备句柄 |
| time | 写RTC时间信息，包括年、月、星期、日、时、分、秒、毫秒 |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> RTC起始时间为UTC 1970/01/01 Thursday 00:00:00，年的最大取值按照用户器件手册要求计算配置，星期不用配置。


```
int32_t ret;
struct RtcTime tm;

/* 设置RTC时间为 UTC 2020/01/01 00:59:00 .000 */
tm.year = 2020;
tm.month = 01;
tm.day = 01;
tm.hour= 00;
tm.minute = 59;
tm.second = 00;
tm.millisecond = 0;
/* 写RTC时间信息 */
ret = RtcWriteTime(handle, &tm);
if (ret != 0) {
    /* 错误处理 */
}
```

- 读取RTC报警时间

如果需要读取定时报警时间，则可以通过以下函数完成：

int32_t RtcReadAlarm(DevHandle handle, enum RtcAlarmIndex alarmIndex, struct RtcTime \*time);

  **表7** RtcReadAlarm参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle | RTC设备句柄 |
| alarmIndex | 报警索引 |
| time | RTC报警时间信息，包括年、月、星期、日、时、分、秒、毫秒 |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数       | 操作失败 |


```
int32_t ret;
struct RtcTime alarmTime;

/* 读RTC_ALARM_INDEX_A索引的RTC定时报警时间信息 */
ret = RtcReadAlarm(handle, RTC_ALARM_INDEX_A, &alarmTime);
if (ret != 0) {
    /* 错误处理 */
}
```

- 设置RTC报警时间

根据报警索引设置RTC报警时间，通过以下函数完成：

int32_t RtcWriteAlarm(DevHandle handle, enum RtcAlarmIndex  alarmIndex, struct RtcTime \*time);

  **表8** RtcWriteAlarm参数和返回值描述

| **参数** | **参数描述** |
| -------- | -------- |
| handle | RTC设备句柄 |
| alarmIndex | 报警索引 |
| time | RTC报警时间信息，包括年、月、星期、日、时、分、秒、毫秒 |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**</br>
> RTC起始时间为UTC 1970/01/01 Thursday 00:00:00，年的最大取值按照用户器件手册要求计算配置，星期不用配置。


```
int32_t ret;
struct RtcTime alarmTime;

/* 设置RTC报警时间为2020/01/01 00:59:59 .000 */
alarmTime.year = 2020;
alarmTime.month = 01;
alarmTime.day = 01;
alarmTime.hour = 00;
alarmTime.minute = 59;
alarmTime.second = 59;
alarmTime.millisecond = 0;
/* 设置RTC_ALARM_INDEX_A索引的定时报警时间 */
ret = RtcWriteAlarm(handle, RTC_ALARM_INDEX_A, &alarmTime);
if (ret != 0) {
    /* 错误处理 */
}
```

- 设置定时报警中断使能或去使能

在启动报警操作前，需要先设置报警中断使能，报警超时后会触发告警回调函数，可以通过以下函数完成：

int32_t RtcAlarmInterruptEnable(DevHandle handle, enum RtcAlarmIndex alarmIndex, uint8_t enable);

  **表9** RtcAlarmInterruptEnable参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle     | RTC设备句柄 |
| alarmIndex | 报警索引 |
| enable     | RTC报警中断配置，1：使能，0：去使能 |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |


```
int32_t ret;

/* 设置RTC报警中断使能 */
ret = RtcAlarmInterruptEnable(handle, RTC_ALARM_INDEX_A, 1);
if (ret != 0) {
    /* 错误处理 */
}
```

- 读取RTC外频

读取RTC外接晶体振荡频率，可以通过以下函数完成：

int32_t RtcGetFreq(DevHandle handle, uint32_t \*freq);

  **表10** RtcGetFreq参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle | RTC设备句柄 |
| freq | RTC的外接晶体振荡频率，单位（HZ） |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |


```
int32_t ret;
uint32_t freq = 0;

/* 读取RTC外接晶体振荡频率 */
ret = RtcGetFreq(handle, &freq);
if (ret != 0) {
    /* 错误处理 */
}
```

- 配置RTC外频

配置RTC外接晶体振荡频率，可以通过以下函数完成：

int32_t RtcSetFreq(DevHandle handle, uint32_t freq);

  **表11** RtcSetFreq参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle | RTC设备句柄 |
| freq | RTC的外接晶体振荡频率，单位（HZ） |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |


```
int32_t ret;
uint32_t freq = 32768; /* 32768 Hz */

/* 设置RTC外接晶体振荡频率，注意按照器件手册要求配置RTC外频 */
ret = RtcSetFreq(handle, freq);
if (ret != 0) {
    /* 错误处理 */
}
```

- 复位RTC

复位RTC，复位RTC后各配置寄存器恢复默认值，可以通过以下函数完成：

int32_t RtcReset(DevHandle handle);

  **表12** RtcReset参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle     | RTC设备句柄 |
| **返回值** | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |


```
int32_t ret;

/* 复位RTC，各配置寄存器恢复默认值 */
ret = RtcReset(handle);
if (ret != 0) {
    /* 错误处理 */
}
```

- 读取RTC自定义寄存器配置

按照用户定义的寄存器索引，读取对应的寄存器配置，一个索引对应一字节的配置值，通过以下函数完成：

int32_t RtcReadReg(DevHandle handle, uint8_t usrDefIndex, uint8_t \*value);

  **表13** RtcReadReg参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle      | RTC设备句柄 |
| usrDefIndex | 用户定义的寄存器对应索引 |
| value       | 寄存器值 |
| **返回值**  | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |


```
int32_t ret;
uint8_t usrDefIndex = 0; /* 定义0索引对应用户定义的第一个寄存器*/
uint8_t value = 0;

/* 按照用户定义的寄存器索引，读取对应的寄存器配置，一个索引对应一字节的配置值 */
ret = RtcReadReg(handle, usrDefIndex, &value);
if (ret != 0) {
    /* 错误处理 */
}
```

- 设置RTC自定义寄存器配置

按照用户定义的寄存器索引，设置对应的寄存器配置，一个索引对应一字节的配置值，通过以下函数完成：

int32_t RtcWriteReg(DevHandle handle, uint8_t usrDefIndex, uint8_t value);

  **表14** RtcWriteReg参数和返回值描述

| **参数** | **描述** |
| -------- | -------- |
| handle | RTC设备句柄 |
| usrDefIndex | 用户定义的寄存器对应索引 |
| value | 寄存器值 |
| **返回值**  | **描述** |
| 0 | 操作成功 |
| 负数 | 操作失败 |


```
int32_t ret;
uint8_t usrDefIndex = 0; /* 定义0索引对应用户定义第一个寄存器*/
uint8_t value = 0x10;

/* 按照用户的定义的寄存器索引，设置对应的寄存器配置，一个索引对应一字节的配置值 */
ret = RtcWriteReg(handle, usrDefIndex, value);
if (ret != 0) {
    /* 错误处理 */
}
```


## 使用实例

本实例提供RTC接口的完整使用流程：

1. 系统启动，驱动管理模块会识别系统当前的RTC器件;

2. 驱动管理模块完成RTC设备的初始化和设备创建；

3. 用户通过不同API，对该RTC设备进行对应的操作；

4. 关闭RTC设备，释放设备资源。

示例如下：


```
#include "rtc_if.h"
int32_t RtcAlarmACallback(enum RtcAlarmIndex alarmIndex)
{
    if (alarmIndex == RTC_ALARM_INDEX_A) {
        /* 报警A的处理 */
        printf("RTC Alarm A callback function\n\r");
    } else if (alarmIndex == RTC_ALARM_INDEX_B) {
        /* 报警B的处理 */
        printf("RTC Alarm B callback function\n\r");
    } else {
        /* 错误处理 */
    }
    return 0;
}

void RtcTestSample(void)
{
    int32_t ret;
    struct RtcTime tm;
    struct RtcTime alarmTime;
    uint32_t freq;
    DevHandle handle = NULL;

    /* 获取RTC设备句柄 */
    handle = RtcOpen();
    if (handle == NULL) {
        /* 错误处理 */
    }
    /* 注册报警A的定时回调函数 */
    ret = RtcRegisterAlarmCallback(handle, RTC_ALARM_INDEX_A, RtcAlarmACallback);
    if (ret != 0) {
        /* 错误处理 */
    }
    /* 设置RTC外接晶体振荡频率，注意按照器件手册要求配置RTC外频 */
    freq = 32768; /* 32768 Hz */
    ret = RtcSetFreq(handle, freq);
    if (ret != 0) {
        /* 错误处理 */
    }
    /* 设置RTC报警中断使能 */
    ret = RtcAlarmInterruptEnable(handle, RTC_ALARM_INDEX_A, 1);
    if (ret != 0) {
        /* 错误处理 */
    }
    /* 设置RTC时间为2020/01/01 00:00:10 .990 */
    tm.year = 2020;
    tm.month = 01;
    tm.day = 01;
    tm.hour= 0;
    tm.minute = 0;
    tm.second = 10;
    tm.millisecond = 990;
    /* 写RTC时间信息 */
    ret = RtcWriteTime(handle, &tm);
    if (ret != 0) {
        /* 错误处理 */
    }
    /* 设置RTC报警时间为2020/01/01 00:00:30 .100 */
    alarmTime.year = 2020;
    alarmTime.month = 01;
    alarmTime.day = 01;
    alarmTime.hour = 0;
    alarmTime.minute = 0;
    alarmTime.second = 30;
    alarmTime.millisecond = 100;
    /* 设置RTC_ALARM_INDEX_A索引定时报警时间信息, 定时时间到后会打印"RTC Alarm A callback function" */
    ret = RtcWriteAlarm(handle, RTC_ALARM_INDEX_A, &alarmTime);
    if (ret != 0) {
        /* 错误处理 */
    }

    /* 读取RTC实时时间 */
    ret = RtcReadTime(handle, &tm);
    if (ret != 0) {
        /* 错误处理 */
    }
    sleep(5)
    printf("RTC read time:\n\r");
    printf("year-month-date-weekday hour:minute:second .millisecond %04u-%02u-%02u-%u %02u:%02u:%02u .%03u",
        tm.year, tm.month, tm.day, tm.weekday, tm.hour, tm.minute, tm.second, tm.millisecond);
    /* 销毁RTC设备句柄 */
    RtcClose(handle);
}
```