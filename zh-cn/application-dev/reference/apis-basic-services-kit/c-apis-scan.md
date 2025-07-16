# ohscan.h


## 概述

向应用提供使用CAPI访问扫描仪设备的能力。

**起始版本：** 12


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Scan_ScannerDevice](#scan_scannerdevice) | 扫描仪设备信息。 |
| [Scan_PictureScanProgress](#scan_picturescanprogress) | 图片扫描进度。 |
| [Scan_ScannerOptions](#scan_scanneroptions) | 扫描仪选项。 |
| [Scan_ScannerDiscoveryCallback](#scan_scannerdiscoverycallback) | 扫描仪发现回调函数。 |


### 枚举类型

| 名称 | 描述 |
| -------- | -------- |
| [Scan_ErrorCode](#scan_errorcode) | 枚举错误码。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Scan_Init](#oh_scan_init) | 用于拉起扫描服务，初始化客户端，并建立与扫描服务的连接。 |
| [OH_Scan_StartScannerDiscovery](#oh_scan_startscannerdiscovery) | 用于搜索扫描仪，注册一个回调函数来处理发现的扫描仪。 |
| [OH_Scan_OpenScanner](#oh_scan_openscanner) | 用于连接扫描仪。 |
| [OH_Scan_CloseScanner](#oh_scan_closescanner) | 用于断开与扫描仪的连接。 |
| [OH_Scan_GetScannerParameter](#oh_scan_getscannerparameter) | 用于获取扫描仪设置选项。 |
| [OH_Scan_SetScannerParameter](#oh_scan_setscannerparameter) | 用于设置扫描仪的选项参数。 |
| [OH_Scan_StartScan](#oh_scan_startscan) | 用于启动扫描仪。 |
| [OH_Scan_CancelScan](#oh_scan_cancelscan) | 用于取消扫描。 |
| [OH_Scan_GetPictureScanProgress](#oh_scan_getpicturescanprogress) | 用于查询图片扫描进度。 |
| [OH_Scan_Exit](#oh_scan_exit) | 用于退出扫描服务，释放客户端内存。 |


## 类型定义说明


### Scan_ScannerDevice

**描述**

扫描仪设备信息。

**起始版本：** 12

| 成员         | 描述     |
| ------------ | -------- |
| scannerId    | 扫描仪id。 |
| manufacturer | 制造商。   |
| model        | 设备型号。 |
| discoverMode | 发现模式。 |
| serialNumber | 序列号。   |

### Scan_PictureScanProgress

**描述**

图片扫描进度。

**起始版本：** 12

| 成员     | 描述                    |
| -------- | ----------------------- |
| progress | 图片扫描进度，范围0~100。 |
| fd       | 图片文件句柄。            |
| isFinal  | 是否有下一张图片。        |

### Scan_ScannerOptions

**描述**

扫描仪选项。

**起始版本：** 12

| 成员         | 描述         |
| ------------ | ------------ |
| titles       | 选项标题。     |
| descriptions | 选项描述信息。 |
| ranges       | 选项范围。     |
| optionCount  | 选项个数。     |

### Scan_ScannerDiscoveryCallback

**描述**

扫描仪发现回调函数。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| devices     | 扫描仪设备。 |
| deviceCount | 设备个数。   |



## 枚举类型说明


### Scan_ErrorCode

**描述**

枚举错误码。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| SCAN_ERROR_NONE | 成功。 |
| SCAN_ERROR_NO_PERMISSION | 没有权限。 |
| SCAN_ERROR_INVALID_PARAMETER | 无效的参数。 |
| SCAN_ERROR_GENERIC_FAILURE | 一般的内部错误。 |
| SCAN_ERROR_RPC_FAILURE | RPC通信错误。 |
| SCAN_ERROR_SERVER_FAILURE | 服务端错误。 |
| SCAN_ERROR_UNSUPPORTED | 不支持该操作。 |
| SCAN_ERROR_CANCELED | 操作被取消。 |
| SCAN_ERROR_DEVICE_BUSY | 设备忙碌。 |
| SCAN_ERROR_INVALID | 无效操作。 |
| SCAN_ERROR_JAMMED | 进纸器卡纸。 |
| SCAN_ERROR_NO_DOCS | 没有纸。 |
| SCAN_ERROR_COVER_OPEN | 扫描仪的盖子被打开。 |
| SCAN_ERROR_IO_ERROR | 扫描仪IO过程中错误。 |
| SCAN_ERROR_NO_MEMORY | 扫描仪没有内存。 |


## 函数说明


### OH_Scan_Init()

```cpp
int32_t OH_Scan_Init();
```

**描述**

这个接口用于拉起扫描服务，初始化客户端，并建立与扫描服务的连接。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常。

### OH_Scan_StartScannerDiscovery()

```cpp
int32_t OH_Scan_StartScannerDiscovery(Scan_ScannerDiscoveryCallback callback);
```

**描述**

这个接口用于搜索扫描仪，注册一个回调函数来处理发现的扫描仪。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称     | 描述                       |
| -------- | -------------------------- |
| callback | 扫描仪发现事件的回调函数。 |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常。

### OH_Scan_OpenScanner()

```cpp
int32_t OH_Scan_OpenScanner(const char* scannerId);
```

**描述**

这个接口用于连接扫描仪。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| scannerId | 扫描仪的id |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_DEVICE_BUSY表示扫描仪忙碌；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数；

返回SCAN_ERROR_IO_ERROR表示扫描仪IO错误；

返回SCAN_ERROR_NO_MEMORY表示没有足够的内存。

### OH_Scan_CloseScanner()

```cpp
int32_t OH_Scan_CloseScanner(const char* scannerId);
```

**描述**

这个接口用于断开与扫描仪的连接。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| scannerId | 扫描仪的id |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数。

### OH_Scan_GetScannerParameter()

```cpp
Scan_ScannerOptions* OH_Scan_GetScannerParameter(const char* scannerId, int32_t* errorCode);
```

**描述**

这个接口用于获取扫描仪设置选项，返回的结构体指针在[OH_Scan_Exit](#oh_scan_exit)时自动释放内存，每个型号的扫描仪在内存中只存储一个副本。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| scannerId | 扫描仪的id |
| errorCode | 错误码     |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常。

### OH_Scan_SetScannerParameter()

```cpp
int32_t OH_Scan_SetScannerParameter(const char* scannerId, const int32_t option, const char* value);
```

**描述**

这个接口用于设置扫描仪的选项参数，选项值的返回通过[OH_Scan_GetScannerParameter](#oh_scan_getscannerparameter)接口获得。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| scannerId | 扫描仪的id |
| option    | 选项编号   |
| value     | 选项值     |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数。

### OH_Scan_StartScan()

```cpp
int32_t OH_Scan_StartScan(const char* scannerId, bool batchMode);
```

**描述**

这个接口用于启动扫描仪。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| scannerId | 扫描仪的id |
| batchMode | 批处理模式 |

**返回：**

返回Scan_ERROR_NONE表示成功；
返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数；

返回SCAN_ERROR_JAMMED表示扫描仪卡纸；

返回SCAN_ERROR_NO_DOCS表示没有纸；

返回SCAN_ERROR_COVER_OPEN表示扫描仪的盖子被打开；

返回SCAN_ERROR_IO_ERROR表示扫描仪IO异常；

返回SCAN_ERROR_NO_MEMORY表示没有足够的内存；

返回SCAN_ERROR_DEVICE_BUSY表示扫描仪忙碌。

### OH_Scan_CancelScan()

```cpp
int32_t OH_Scan_CancelScan(const char* scannerId);
```

**描述**

这个接口用于取消扫描。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| scannerId | 扫描仪的id |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数。

### OH_Scan_GetPictureScanProgress()

```cpp
int32_t OH_Scan_GetPictureScanProgress(const char* scannerId, Scan_PictureScanProgress* prog);
```

**描述**

这个接口用于查询图片扫描进度。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**参数:**

| 名称      | 描述         |
| --------- | ------------ |
| scannerId | 扫描仪的id   |
| prog      | 图片扫描进度 |

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数；

返回SCAN_ERROR_JAMMED表示扫描仪卡纸；

返回SCAN_ERROR_NO_DOCS表示没有纸；

返回SCAN_ERROR_COVER_OPEN表示扫描仪的盖子被打开；

返回SCAN_ERROR_IO_ERROR表示扫描仪IO异常；

返回SCAN_ERROR_NO_MEMORY表示没有足够的内存；

返回SCAN_ERROR_DEVICE_BUSY表示扫描仪忙碌。

### OH_Scan_Exit()

```cpp
int32_t OH_Scan_Exit();
```

**描述**

这个接口用于退出扫描服务，清除客户端内存，取消注册的扫描回调函数。

**系统能力：** ohos.permission.PRINT

**起始版本：** 12

**返回：**

返回Scan_ERROR_NONE表示成功；

返回SCAN_ERROR_NO_PERMISSION表示没有权限；

返回SCAN_ERROR_RPC_FAILURE表示RPC通信错误；

返回SCAN_ERROR_SERVER_FAILURE表示服务端出现异常；

返回SCAN_ERROR_INVALID_PARAMETER表示无效参数。