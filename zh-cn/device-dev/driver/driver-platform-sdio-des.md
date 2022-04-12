# SDIO


## 概述

- SDIO是安全数字输入输出接口（Secure Digital Input and Output）的缩写，是从SD内存卡接口的基础上演化出来的一种外设接口。SDIO接口兼容以前的SD内存卡，并且可以连接支持SDIO接口的设备。

- SDIO的应用比较广泛，目前，有许多手机都支持SDIO功能，并且很多SDIO外设也被开发出来，使得手机外接外设更加容易。常见的SDIO外设有WLAN、GPS、CAMERA、蓝牙等。

- SDIO总线有两端，其中一端是主机端（HOST），另一端是设备端（DEVICE）。所有的通信都是由HOST端发出命令开始的，在DEVICE端只要能解析HOST的命令，就可以同HOST进行通信了。SDIO的HOST可以连接多个DEVICE，如下图所示：
  - CLK信号：HOST给DEVICE的时钟信号。
  - VDD信号：电源信号。
  - VSS信号：Ground信号。
  - D0-3信号：4条数据线，其中，DAT1信号线复用为中断线，在1BIT模式下DAT0用来传输数据，在4BIT模式下DAT0-DAT3用来传输数据。
  - CMD信号：用于HOST发送命令和DEVICE回复响应。

    **图1** SDIO的HOST-DEVICE连接示意图

    ![image](figures/SDIO的HOST-DEVICE连接示意图.png "SDIO的HOST-DEVICE连接示意图")

- SDIO接口定义了操作SDIO的通用方法集合，包括打开/关闭SDIO控制器、独占/释放HOST、使能/去使能设备、申请/释放中断、读写、获取/设置公共信息等。


## 接口说明

  **表1** SDIO驱动API接口功能介绍

| 功能分类 | 接口描述 | 
| -------- | -------- |
| SDIO设备打开/关闭接口 | -&nbsp;SdioOpen：打开指定总线号的SDIO控制器<br/>-&nbsp;SdioClose：关闭SDIO控制器 | 
| SDIO读写接口 | -&nbsp;SdioReadBytes：从指定地址开始，增量读取指定长度的数据<br/>-&nbsp;SdioWriteBytes：从指定地址开始，增量写入指定长度的数据<br/>-&nbsp;SdioReadBytesFromFixedAddr：从固定地址读取指定长度的数据<br/>-&nbsp;SdioWriteBytesToFixedAddr：向固定地址写入指定长度的数据<br/>-&nbsp;SdioReadBytesFromFunc0：从SDIO&nbsp;function&nbsp;0的指定地址空间读取指定长度的数据<br/>-&nbsp;SdioWriteBytesToFunc0：向SDIO&nbsp;function&nbsp;0的指定地址空间写入指定长度的数据 | 
| SDIO设置块大小接口 | SdioSetBlockSize：设置块的大小 | 
| SDIO获取/设置公共信息接口 | -&nbsp;SdioGetCommonInfo：获取公共信息<br/>-&nbsp;SdioSetCommonInfo：设置公共信息 | 
| SDIO刷新数据接口 | SdioFlushData：刷新数据 | 
| SDIO独占/释放HOST接口 | -&nbsp;SdioClaimHost：独占Host<br/>-&nbsp;SdioReleaseHost：释放Host | 
| SDIO使能/去使能功能设备接口 | -&nbsp;SdioEnableFunc：使能SDIO功能设备<br/>-&nbsp;SdioDisableFunc：去使能SDIO功能设备 | 
| SDIO申请/释放中断接口 | -&nbsp;SdioClaimIrq：申请中断<br/>-&nbsp;SdioReleaseIrq：释放中断 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本文涉及的所有接口，目前只支持在内核态使用，不支持在用户态使用。


## 使用指导


### 使用流程

使用SDIO的一般流程如下图所示。

  **图2** SDIO使用流程图

  ![image](figures/SDIO使用流程图.png "SDIO使用流程图")


### 打开SDIO控制器

在使用SDIO进行通信前，首先要调用SdioOpen获取SDIO控制器的设备句柄，该函数会返回指定总线号的SDIO控制器的设备句柄。

  
```
DevHandle SdioOpen(int16_t mmcBusNum, struct SdioFunctionConfig *config);
```

  **表2** SdioOpen函数的参数和返回值描述

| 参数 | 参数描述 | 
| -------- | -------- |
| mmcBusNum | 总线号 | 
| config | SDIO功能配置信息 | 
| **返回值** | **返回值描述** | 
| NULL | 获取SDIO控制器的设备句柄失败 | 
| 设备句柄 | SDIO控制器的设备句柄 | 

  打开SDIO控制器的示例如下：
  
```
DevHandle handle = NULL;
struct SdioFunctionConfig config;
config.funcNr = 1;
config.vendorId = 0x123;
config.deviceId = 0x456;
/* 打开总线号为1的SDIO控制器 */
handle = SdioOpen(1, &config);
if (handle == NULL) {
    HDF_LOGE("SdioOpen: failed!\n");
}
```


### 独占HOST

获取到SDIO控制器的设备句柄之后，需要先独占HOST才能进行SDIO后续的一系列操作，独占HOST函数如下所示：

  
```
void SdioClaimHost(DevHandle handle);
```

  **表3** SdioClaimHost函数的参数描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 

独占HOST示例如下：

  
```
SdioClaimHost(handle); /* 独占HOST */
```


### 使能SDIO设备

在访问寄存器之前，需要先使能SDIO设备，使能SDIO设备的函数如下所示：

  
```
int32_t SdioEnableFunc(DevHandle handle);
```

  **表4** SdioEnableFunc函数的参数和返回值描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 
| **返回值** | **返回值描述** | 
| 0 | SDIO使能成功 | 
| 负数 | SDIO使能失败 | 

使能SDIO设备的示例如下：

  
```
int32_t ret;
/* 使能SDIO设备 */
ret = SdioEnableFunc(handle);
if (ret != 0) {
    HDF_LOGE("SdioEnableFunc: failed, ret %d\n", ret);
}
```


### 注册SDIO中断

在通信之前，还需要注册SDIO中断，注册SDIO中断函数如下图所示：

  
```
int32_t SdioClaimIrq(DevHandle handle, SdioIrqHandler *handler);
```

  **表5** SdioClaimIrq函数的参数和返回值描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 
| handler | 中断服务函数指针 | 
| **返回值** | **返回值描述** | 
| 0 | 注册中断成功 | 
| 负数 | 注册中断失败 | 

  注册SDIO中的示例如下：
  
```
/* 中断服务函数需要根据各自平台的情况去实现 */
static void SdioIrqFunc(void *data)
{
    if (data == NULL) {
        HDF_LOGE("SdioIrqFunc: data is NULL.\n");
        return;
    }
    /* 需要开发者自行添加具体实现 */
}

int32_t ret;
/* 注册SDIO中断 */
ret = SdioClaimIrq(handle, SdioIrqFunc);
if (ret != 0) {
    HDF_LOGE("SdioClaimIrq: failed, ret %d\n", ret);
}
```


### 进行SDIO通信

- 向SDIO设备增量写入指定长度的数据

  对应的接口函数如下所示：

  
  ```
  int32_t SdioWriteBytes(DevHandle handle, uint8_t *data, uint32_t addr, uint32_t size);
  ```

  **表6** SdioWriteBytes函数的参数和返回值描述

  | 参数 | 参数描述 | 
  | -------- | -------- |
  | handle | SDIO控制器的设备句柄 | 
  | data | 待写入数据的指针 | 
  |   addr | 待写入数据的起始地址 | 
  | size | 待写入数据的长度 | 
  | **返回值** | **返回值描述** | 
  | 0 | SDIO写数据成功 | 
  | 负数 | SDIO写数据失败 | 

  向SDIO设备增量写入指定长度的数据的示例如下：

  
  ```
  int32_t ret;
  uint8_t wbuff[] = {1,2,3,4,5};
  uint32_t addr = 0x100 + 0x09;
  /* 向SDIO设备起始地址0x109，增量写入5个字节的数据 */
  ret = SdioWriteBytes(handle, wbuff, addr, sizeof(wbuff) / sizeof(wbuff[0]));
  if (ret != 0) {
      HDF_LOGE("SdioWriteBytes: failed, ret %d\n", ret);
  }
  ```

- 从SDIO设备增量读取指定长度的数据

  对应的接口函数如下所示：

  
  ```
  int32_t SdioReadBytes(DevHandle handle, uint8_t *data, uint32_t addr, uint32_t size);
  ```

  **表7** SdioReadBytes函数的参数和返回值描述

  | 参数 | 参数描述 | 
  | -------- | -------- |
  | handle | SDIO控制器的设备句柄 | 
  | data | 接收读取数据的指针 | 
  | addr | 待读取数据的起始地址 | 
  | size | 待读取数据的长度 | 
  | **返回值** | **返回值描述** | 
  | 0 | SDIO读数据成功 | 
  | 负数 | SDIO读数据失败 | 

  从SDIO设备增量读取指定长度的数据的示例如下：

  
  ```
  int32_t ret;
  uint8_t rbuff[5] = {0};
  uint32_t addr = 0x100 + 0x09;
  /* 从SDIO设备起始地址0x109，增量读取5个字节的数据 */
  ret = SdioReadBytes(handle, rbuff, addr, 5);
  if (ret != 0) {
      HDF_LOGE("SdioReadBytes: failed, ret %d\n", ret);
  }
  ```

- 向SDIO设备的固定地址写入指定长度的数据
  对应的接口函数如下所示：

    
  ```
  int32_t SdioWriteBytesToFixedAddr(DevHandle handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t scatterLen);
  ```

    **表8** SdioWriteBytesToFixedAddr函数的参数和返回值描述
  
  | 参数 | 参数描述 | 
  | -------- | -------- |
  | handle | SDIO控制器的设备句柄 | 
  | data | 待写入数据的指针 | 
  | addr | 待写入数据的固定地址 | 
  | size | 待写入数据的长度 | 
  | scatterLen | 集散表的长度。如果该字段不为0，则data为集散表类型。 | 
  | **返回值** | **返回值描述** | 
  | 0 | SDIO写数据成功 | 
  | 负数 | SDIO写数据失败 | 

  向SDIO设备的固定地址写入指定长度的数据的示例如下：

    
  ```
  int32_t ret;
  uint8_t wbuff[] = {1，2，3，4，5};
  uint32_t addr = 0x100 + 0x09;
  /* 向SDIO设备固定地址0x109写入5个字节的数据 */
  ret = SdioWriteBytesToFixedAddr(handle, wbuff, addr, sizeof(wbuff) / sizeof(wbuff[0]), 0);
  if (ret != 0) {
      HDF_LOGE("SdioWriteBytesToFixedAddr: failed, ret %d\n", ret);
  }
  ```

- 从SDIO设备的固定地址读取指定长度的数据
  对应的接口函数如下所示：

    
  ```
  int32_t SdioReadBytesFromFixedAddr(DevHandle handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t scatterLen);
  ```

    **表9** SdioReadBytesFromFixedAddr函数的参数和返回值描述
  
  | 参数 | 参数描述 | 
  | -------- | -------- |
  | handle | SDIO控制器的设备句柄 | 
  | data | 接收读取数据的指针 | 
  | addr | 待读取数据的起始地址 | 
  | size | 待读取数据的长度 | 
  | scatterLen | 集散表的长度。如果该字段不为0，则data为集散表类型。 | 
  | **返回值** | **返回值描述** | 
  | 0 | SDIO读数据成功 | 
  | 负数 | SDIO读数据失败 | 

  从SDIO设备的固定地址读取指定长度的数据的示例如下：

    
  ```
  int32_t ret;
  uint8_t rbuff[5] = {0};
  uint32_t addr = 0x100 + 0x09;
  /* 从SDIO设备固定地址0x109中读取5个字节的数据 */
  ret = SdioReadBytesFromFixedAddr(handle, rbuff, addr, 5, 0);
  if (ret != 0) {
      HDF_LOGE("SdioReadBytesFromFixedAddr: failed, ret %d\n", ret);
  }
  ```

- 向SDIO function 0的指定地址空间写入指定长度的数据

  当前只支持写入一个字节的数据，对应的接口函数如下所示：

  
  ```
  int32_t SdioWriteBytesToFunc0(DevHandle handle, uint8_t *data, uint32_t addr, uint32_t size);
  ```

  **表10** SdioWriteBytesToFunc0函数的参数和返回值描述

  | 参数 | 参数描述 | 
  | -------- | -------- |
  | handle | SDIO控制器的设备句柄 | 
  | data | 待写入数据的指针 | 
  | addr | 待写入数据的起始地址 | 
  | size | 待写入数据的长度 | 
  | **返回值** | **返回值描述** | 
  | 0 | SDIO写数据成功 | 
  | 负数 | SDIO写数据失败 | 

  向SDIO function 0的指定地址空间写入指定长度的数据的示例如下：

  
  ```
  int32_t ret;
  uint8_t wbuff = 1;
  /* 向SDIO function 0地址0x2中写入1字节的数据 */
  ret = SdioWriteBytesToFunc0(handle, &wbuff, 0x2, 1);
  if (ret != 0) {
      HDF_LOGE("SdioWriteBytesToFunc0: failed, ret %d\n", ret);
  }
  ```

- 从SDIO function 0的指定地址空间读取指定长度的数据

  当前只支持读取一个字节的数据，对应的接口函数如下所示：

  
  ```
  int32_t SdioReadBytesFromFunc0(DevHandle handle, uint8_t *data, uint32_t addr, uint32_t size);
  ```

  **表11** SdioReadBytesFromFunc0函数的参数和返回值描述

  | 参数 | 参数描述 | 
  | -------- | -------- |
  | handle | SDIO控制器的设备句柄 | 
  | data | 接收读取数据的指针 | 
  | addr | 待读取数据的起始地址 | 
  | size | 待读取数据的长度 | 
  | **返回值** | **返回值描述** | 
  | 0 | SDIO读数据成功 | 
  | 负数 | SDIO读数据失败 | 

  从SDIO function 0的指定地址空间读取指定长度的数据的示例如下：

  
  ```
  int32_t ret;
  uint8_t rbuff;
  /* 从SDIO function 0设备地址0x2中读取1字节的数据 */
  ret = SdioReadBytesFromFunc0(handle, &rbuff, 0x2, 1);
  if (ret != 0) {
      HDF_LOGE("SdioReadBytesFromFunc0: failed, ret %d\n", ret);
  }
  ```


### 释放SDIO中断

通信完成之后，需要释放SDIO中断，函数如下所示：

int32_t SdioReleaseIrq(DevHandle handle);

  **表12** SdioReleaseIrq函数的参数和返回值描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 
| **返回值** | **返回值描述** | 
| 0 | 释放SDIO中断成功 | 
| 负数 | 释放SDIO中断失败 | 

释放SDIO中断的示例如下：

  
```
int32_t ret;
/* 释放SDIO中断 */
ret = SdioReleaseIrq(handle);
if (ret != 0) {
    HDF_LOGE("SdioReleaseIrq: failed, ret %d\n", ret);
}
```


### 去使能SDIO设备

通信完成之后，还需要去使能SDIO设备，函数如下所示：

int32_t SdioDisableFunc(DevHandle handle);

  **表13** SdioDisableFunc函数的参数和返回值描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 
| **返回值** | **返回值描述** | 
| 0 | 去使能SDIO设备成功 | 
| 负数 | 去使能SDIO设备失败 | 

去使能SDIO设备的示例如下：

  
```
int32_t ret;
/* 去使能SDIO设备 */
ret = SdioDisableFunc(handle);
if (ret != 0) {
    HDF_LOGE("SdioDisableFunc: failed, ret %d\n", ret);
}
```


### 释放HOST

通信完成之后，还需要释放去HOST，函数如下所示：

  
```
void SdioReleaseHost(DevHandle handle);
```

  **表14** SdioReleaseHost函数的参数描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 

释放HOST的示例如下：

  
```
SdioReleaseHost(handle); /* 释放HOST */
```


### 关闭SDIO控制器

SDIO通信完成之后，最后需要关闭SDIO控制器，函数如下所示：

  
```
void SdioClose(DevHandle handle);
```

该函数会释放掉申请的资源。

  **表15** SdioClose函数的参数描述

| 参数 | 参数描述 | 
| -------- | -------- |
| handle | SDIO控制器的设备句柄 | 

关闭SDIO控制器的示例如下：

  
```
SdioClose(handle); /* 关闭SDIO控制器 */
```


## 使用实例

  SDIO设备完整的使用示例如下所示，首先打开总线号为1的SDIO控制器，然后独占HOST、使能设备、注册中断，接着进行SDIO通信（读写等），通信完成之后，释放中断、去使能设备、释放HOST，最后关闭SDIO控制器。
  
```
#include "hdf_log.h"
#include "sdio_if.h"

#define TEST_FUNC_NUM 1              /* 本测试用例中，使用编号为1的I/O function */
#define TEST_FBR_BASE_ADDR 0x100     /* 编号为1的I/O function的FBR基地址 */
#define TEST_ADDR_OFFSET 9           /* 本测试用例中，需要读写的寄存器的地址偏移 */
#define TEST_DATA_LEN 3              /* 本测试用例中，读写数据的长度 */
#define TEST_BLOCKSIZE 2             /* 本测试用例中，数据块的大小，单位字节 */

/* 中断服务函数，需要根据各自平台的情况去实现 */
static void SdioIrqFunc(void *data)
{
    if (data == NULL) {
        HDF_LOGE("SdioIrqFunc: data is NULL.\n");
        return;
    }
    /* 需要开发者自行添加具体的实现 */
}

void SdioTestSample(void)
{
    int32_t ret;  
    DevHandle handle = NULL;
    uint8_t data[TEST_DATA_LEN] = {0};
    struct SdioFunctionConfig config = {1, 0x123, 0x456};
    uint8_t val;
    uint32_t addr;
    
    /* 打开总线号为1的SDIO设备 */
    handle = SdioOpen(1, &config);
    if (handle == NULL) {
        HDF_LOGE("SdioOpen: failed!\n");
        return;
    }
    /* 独占HOST */
    SdioClaimHost(handle);
    /* 使能SDIO设备 */
    ret = SdioEnableFunc(handle);
    if (ret != 0) {
        HDF_LOGE("SdioEnableFunc: failed, ret %d\n", ret);
        goto ENABLE_ERR;
    }
    /* 注册中断 */
    ret = SdioClaimIrq(handle, SdioIrqFunc);
    if (ret != 0) {
        HDF_LOGE("SdioClaimIrq: failed, ret %d\n", ret);
        goto CLAIM_IRQ_ERR;
    }
    /* 设置块大小为2字节 */
    ret = SdioSetBlockSize(handle, TEST_BLOCKSIZE);
    if (ret != 0) {
        HDF_LOGE("SdioSetBlockSize: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 从SDIO设备增量地址读取3字节的数据 */
    addr = TEST_FBR_BASE_ADDR * TEST_FUNC_NUM + TEST_ADDR_OFFSET;
    ret = SdioReadBytes(handle, data, addr, TEST_DATA_LEN);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 向SDIO设备增量地址写入3字节的数据 */
    ret = SdioWriteBytes(handle, data, addr, TEST_DATA_LEN);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 从SDIO设备读取1字节的数据 */
    ret = SdioReadBytes(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 向SDIO设备写入1字节的数据 */
    ret = SdioWriteBytes(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 从SDIO设备固定地址读取3字节的数据 */
    ret = SdioReadBytesFromFixedAddr(handle, data, addr, TEST_DATA_LEN, 0);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytesFromFixedAddr: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 向SDIO设备固定地址写入1字节的数据 */
    ret = SdioWriteBytesToFixedAddr(handle, data, addr, 1, 0);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytesToFixedAddr: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 从SDIO function 0读取1字节的数据 */
    addr = 0x02;
    ret = SdioReadBytesFromFunc0(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytesFromFunc0: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* 向SDIO function 0写入1字节的数据 */
    ret = SdioWriteBytesToFunc0(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytesToFunc0: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
COMM_ERR:
    /* 释放中断 */
    ret = SdioReleaseIrq(handle);
    if (ret != 0) {
        HDF_LOGE("SdioReleaseIrq: failed, ret %d\n", ret);
    }
CLAIM_IRQ_ERR:
    /* 去使能SDIO设备 */
    ret = SdioDisableFunc(handle);
    if (ret != 0) {
        HDF_LOGE("SdioDisableFunc: failed, ret %d\n", ret);
    }
ENABLE_ERR:
    /* 释放HOST */
    SdioReleaseHost(handle);
    /* 关闭SDIO设备 */
    SdioClose(handle); 
}
```
