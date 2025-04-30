# OH_Print

## 概述

向应用提供使用CAPI访问打印系统的能力。

**起始版本：** 12

## 汇总

### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Print_StringList](#print_stringlist) | 打印机设备列表。 |
| [Print_Property](#print_property) | 打印机属性。 |
| [Print_PropertyList](#print_propertylist) | 打印机属性列表。 |
| [Print_Resolution](#print_resolution) | 打印分辨率单元。 |
| [Print_Margin](#print_margin) | 打印边距。 |
| [Print_PageSize](#print_pagesize) | 打印纸张尺寸。 |
| [Print_PrinterCapability](#print_printercapability) | 打印机能力。 |
| [Print_DefaultValue](#print_defaultvalue) | 打印默认信息。 |
| [Print_PrinterInfo](#print_printerinfo) | 打印机信息。 |
| [Print_PrintJob](#print_printjob) | 打印任务。 |
| [Print_Range](#print_range) | 打印范围。 |
| [Print_PrintAttributes](#print_printattributes) | 打印属性。 |
| [Print_WriteResultCallback](#print_writeresultcallback) | 写结果回调。 |
| [Print_OnStartLayoutWrite](#print_onstartlayoutwrite) | 开始布局回调。 |
| [Print_OnJobStateChanged](#print_onjobstatechanged) | 打印任务状态回调。 |
| [Print_PrintDocCallback](#print_printdoccallback) | 打印文件状态回调。 |
| [Print_PrinterDiscoveryCallback](#print_printerdiscoverycallback) | 打印机发现回调。 |
| [Print_PrinterChangeCallback](#print_printerchangecallback) | 打印机状态变化回调。 |

### 枚举类型

| 名称 | 描述 |
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode) | 枚举错误码。 |
| [Print_PrinterState](#print_printerstate) | 打印机状态码。 |
| [Print_DiscoveryEvent](#print_discoveryevent) | 打印机发现事件。 |
| [Print_PrinterEvent](#print_printerevent) | 打印机状态改变事件。 |
| [Print_DuplexMode](#print_duplexmode) | 打印单双面模式。 |
| [Print_ColorMode](#print_colormode) | 打印色彩模式。 |
| [Print_OrientationMode](#print_orientationmode) | 打印方向。 |
| [Print_Quality](#print_quality) | 打印质量。 |
| [Print_DocumentFormat](#print_documentformat) | 打印机文件类型。 |
| [Print_JobDocAdapterState](#print_jobdocadapterstate) | 打印任务状态。 |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Print_Init](#oh_print_init) | 拉起打印服务，初始化打印客户端，并建立到打印服务的连接。 |
| [OH_Print_Release](#oh_print_release) | 关闭与打印服务的连接，解除注册的回调，并释放打印客户端资源。 |
| [OH_Print_StartPrinterDiscovery](#oh_print_startprinterdiscovery) | 启动发现打印机。 |
| [OH_Print_StopPrinterDiscovery](#oh_print_stopprinterdiscovery) | 停止发现打印机。 |
| [OH_Print_ConnectPrinter](#oh_print_connectprinter) | 使用打印机id连接打印机。 |
| [OH_Print_StartPrintJob](#oh_print_startprintjob) | 启动打印任务。 |
| [OH_Print_RegisterPrinterChangeListener](#oh_print_registerprinterchangelistener) | 注册打印机状态变化事件。 |
| [OH_Print_UnregisterPrinterChangeListener](#oh_print_unregisterprinterchangelistener) | 注销打印机状态变化事件。 |
| [OH_Print_QueryPrinterList](#oh_print_queryprinterlist) | 查询打印机列表。 |
| [OH_Print_ReleasePrinterList](#oh_print_releaseprinterlist) | 释放打印机列表。 |
| [OH_Print_QueryPrinterInfo](#oh_print_queryprinterinfo) | 查询打印机信息。 |
| [OH_Print_ReleasePrinterInfo](#oh_print_releaseprinterinfo) | 释放打印机信息内存。 |
| [OH_Print_LaunchPrinterManager](#oh_print_launchprintermanager) | 启动打印机管理窗口。 |
| [OH_Print_QueryPrinterProperties](#oh_print_queryprinterproperties) | 查询打印机属性。 |
| [OH_Print_ReleasePrinterProperties](#oh_print_releaseprinterproperties) | 释放打印机属性。 |
| [OH_Print_UpdatePrinterProperties](#oh_print_updateprinterproperties) | 更新打印机属性。 |
| [OH_Print_RestorePrinterProperties](#oh_print_restoreprinterproperties) | 根据属性关键字列表将打印机属性恢复为默认设置。 |
| [OH_Print_StartPrintByNative](#oh_print_startprintbynative) | 启动打印。 |

## 类型定义说明

### Print_StringList

**描述**

打印机设备列表。

**起始版本：** 12

| 成员         | 描述     |
| ------------ | -------- |
| count    | 字符串个数。 |
| list | 字符串指针数组。   |

### Print_Property

**描述**

打印机属性。

**起始版本：** 12

| 成员     | 描述                    |
| -------- | ----------------------- |
| key | 属性关键字。 |
| value       | 属性值。            |

### Print_PropertyList

**描述**

打印机属性列表。

**起始版本：** 12

| 成员         | 描述         |
| ------------ | ------------ |
| count       | 属性个数。     |
| list | 属性指针数组。 |

### Print_Resolution

**描述**

打印分辨率单元。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| horizontalDpi     | 水平分辨率(dpi)。 |
| verticalDpi | 垂直分辨率(dpi)。   |

### Print_Margin

**描述**

打印边距。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| leftMargin     | 左边距(微米)。 |
| topMargin | 顶部边距(微米)。   |
| rightMargin | 右边距(微米)。   |
| bottomMargin | 底边距(微米)。   |

### Print_PageSize

**描述**

打印纸张尺寸。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| id     | 纸张编号。 |
| name | 纸张名称。   |
| width | 纸张宽度(微米)。   |
| height | 纸张高度(微米)。   |

### Print_PrinterCapability

**描述**

打印机能力。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| supportedColorModes     | 支持的颜色模式列表。 |
| supportedColorModesCount | 支持的颜色模式个数。   |
| supportedDuplexModes | 支持的双面模式列表。   |
| supportedDuplexModesCount | 支持的双面模式个数。   |
| supportedPageSizes | 支持的纸张尺寸列表。   |
| supportedPageSizesCount | 支持的纸张尺寸个数。   |
| supportedMediaTypes | 支持的介质类型(JSON字符串数组格式)。   |
| supportedQualities | 支持的打印质量列表。   |
| supportedQualitiesCount | 支持的打印质量个数。   |
| supportedPaperSources | 支持的纸张来源(JSON字符串数组格式)。   |
| supportedCopies | 支持的最大打印份数。   |
| supportedResolutions | 支持的分辨率列表。   |
| supportedResolutionsCount | 支持的分辨率个数。   |
| supportedOrientations | 支持的打印方向列表。   |
| supportedOrientationsCount | 支持的打印方向个数。   |
| advancedCapability | 高级能力(JSON格式)。   |

### Print_DefaultValue

**描述**

打印机默认信息。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| defaultColorMode     | 默认颜色模式。 |
| defaultDuplexMode | 默认双面模式。   |
| defaultMediaType | 默认介质类型。   |
| defaultPageSizeId | 默认纸张尺寸ID。   |
| defaultMargin | 默认边距。   |
| defaultPaperSource | 默认纸张来源。   |
| defaultPrintQuality | 默认打印质量。   |
| defaultCopies | 默认打印份数。   |
| defaultResolution | 默认分辨率。   |
| defaultOrientation | 默认打印方向。   |
| otherDefaultValues | 其他默认值(JSON格式)。   |

### Print_PrinterInfo

**描述**

打印机信息。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| printerState     | 打印机状态。 |
| capability | 打印机能力。   |
| defaultValue | 打印机默认属性。   |
| isDefaultPrinter | 是否是默认打印机。   |
| printerId | 打印机ID。   |
| printerName | 打印机名称。   |
| description | 打印机描述。   |
| location | 打印机位置。   |
| makeAndModel | 打印机制造商和型号信息。   |
| printerUri | 打印机URI。   |
| detailInfo | 详细信息(JSON格式)。   |

### Print_PrintJob

**描述**

打印任务。

**起始版本：** 12

| 参数        | 描述       |
| ----------- | ---------- |
| jobName     | 打印任务名称。 |
| fdList | 打印文件描述符数组。   |
| fdListCount | 打印文件描述符数量。   |
| printerId | 打印机ID。   |
| copyNumber | 打印份数。   |
| paperSource | 纸张来源。   |
| mediaType | 介质类型。   |
| pageSizeId | 纸张尺寸ID。   |
| colorMode | 颜色模式。   |
| duplexMode | 双面模式。   |
| resolution | 分辨率。   |
| printMargin | 打印边距。   |
| borderless | 是否无边距打印。   |
| orientationMode | 打印方向。   |
| printQuality | 打印质量。   |
| documentFormat | 文档格式。   |
| advancedOptions | 高级选项(JSON格式)。   |

### Print_Range

**描述**

打印范围。

**起始版本：** 13

| 参数        | 描述       |
| ----------- | ---------- |
| startPage     | 打印起始页码。 |
| endPage | 打印结束页码。   |
| pagesArrayLen | 打印页数组长度。   |
| pagesArray | 打印页数组。   |

### Print_PrintAttributes

**描述**

打印属性。

**起始版本：** 13

| 参数        | 描述       |
| ----------- | ---------- |
| pageRange     | 打印范围。 |
| pageSize | 纸张尺寸。   |
| pageMargin | 页边距。   |
| copyNumber | 打印份数。   |
| duplexMode | 双面模式。   |
| colorMode | 颜色模式。   |
| isSequential | 是否顺序打印。   |
| isLandscape | 是否横向打印。   |
| hasOption | 是否有打印选项。   |
| options | 打印选项(256字节)。   |

### Print_WriteResultCallback

**描述**

写结果回调。

**起始版本：** 13

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| jobId     | 打印任务ID。 |
| code | 写结果状态码。   |

### Print_OnStartLayoutWrite

**描述**

开始布局回调。

**起始版本：** 13

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| jobId     | 打印任务ID。 |
| fd | 文件描述符。   |
| oldAttrs | 上一个打印属性。   |
| newAttrs | 当前打印属性。   |
| writeCallback | 写结果回调函数。   |

### Print_OnJobStateChanged

**描述**

打印任务状态变化回调。

**起始版本：** 13

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| jobId     | 打印任务ID。 |
| state | 打印任务状态。   |

### Print_PrintDocCallback

**描述**

打印文档状态回调。

**起始版本：** 13

| 参数        | 描述       |
| ----------- | ---------- |
| startLayoutWriteCb     | 开始布局写回调。 |
| jobStateChangedCb | 任务状态变化回调。   |

### Print_PrinterDiscoveryCallback

**描述**

打印机发现回调。

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| event     | 发现事件。 |
| printerInfo | 打印机信息。   |

### Print_PrinterChangeCallback

**描述**

打印机状态变化回调。

**起始版本：** 12

**参数:**

| 名称      | 描述       |
| --------- | ---------- |
| event     | 变化事件。 |
| printerInfo | 打印机信息。   |

## 枚举类型说明

### Print_ErrorCode

**描述**

枚举错误码。

**起始版本：** 12

| 枚举值 | 描述 | 值 |
| -------- | -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 | 0 |
| PRINT_ERROR_NO_PERMISSION | 权限验证失败。 | 201 |
| PRINT_ERROR_INVALID_PARAMETER | 无效参数。 | 401 |
| PRINT_ERROR_GENERIC_FAILURE | 一般内部错误。 | 24300001 |
| PRINT_ERROR_RPC_FAILURE | RPC通信错误。 | 24300002 |
| PRINT_ERROR_SERVER_FAILURE | 服务端错误。 | 24300003 |
| PRINT_ERROR_INVALID_EXTENSION | 无效扩展。 | 24300004 |
| PRINT_ERROR_INVALID_PRINTER | 无效打印机。 | 24300005 |
| PRINT_ERROR_INVALID_PRINT_JOB | 无效打印任务。 | 24300006 |
| PRINT_ERROR_FILE_IO | 文件读写失败。 | 24300007 |
| PRINT_ERROR_UNKNOWN | 未知错误。 | 24300255 |

### Print_PrinterState

**描述**

打印机状态码。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| PRINTER_IDLE | 打印机空闲。 |
| PRINTER_BUSY | 打印机忙碌。 |
| PRINTER_UNAVAILABLE | 打印机不可用。 |

### Print_DiscoveryEvent

**描述**

打印机发现事件。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| PRINTER_DISCOVERED | 发现打印机。 |
| PRINTER_LOST | 丢失打印机。 |
| PRINTER_CONNECTING | 正在连接打印机。 |
| PRINTER_CONNECTED | 已连接打印机。 |

### Print_PrinterEvent

**描述**

打印机事件。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| PRINTER_ADDED | 添加打印机。 |
| PRINTER_DELETED | 删除打印机。 |
| PRINTER_STATE_CHANGED | 打印机状态改变。 |
| PRINTER_INFO_CHANGED | 打印机信息变更。 |
| PRINTER_PREFERENCE_CHANGED | 打印机首选项变更。 |

### Print_DuplexMode

**描述**

打印双面模式。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| DUPLEX_MODE_ONE_SIDED | 单面打印。 |
| DUPLEX_MODE_TWO_SIDED_LONG_EDGE | 长边双面打印。 |
| DUPLEX_MODE_TWO_SIDED_SHORT_EDGE | 短边双面打印。 |

### Print_ColorMode

**描述**

打印色彩模式。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| COLOR_MODE_MONOCHROME | 单色模式。 |
| COLOR_MODE_COLOR | 彩色模式。 |
| COLOR_MODE_AUTO | 自动模式。 |

### Print_OrientationMode

**描述**

打印方向。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| ORIENTATION_MODE_PORTRAIT | 纵向。 |
| ORIENTATION_MODE_LANDSCAPE | 横向。 |
| ORIENTATION_MODE_REVERSE_LANDSCAPE | 反向横向。 |
| ORIENTATION_MODE_REVERSE_PORTRAIT | 反向纵向。 |
| ORIENTATION_MODE_NONE | 未指定。 |

### Print_Quality

**描述**

打印质量。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| PRINT_QUALITY_DRAFT | 草稿质量。 |
| PRINT_QUALITY_NORMAL | 普通质量。 |
| PRINT_QUALITY_HIGH | 高质量。 |

### Print_DocumentFormat

**描述**

文档格式。

**起始版本：** 12

| 枚举值 | 描述 | MIME类型 |
| -------- | -------- | -------- |
| DOCUMENT_FORMAT_AUTO | 自动识别。 | application/octet-stream. |
| DOCUMENT_FORMAT_JPEG | JPEG图像。 | image/jpeg. |
| DOCUMENT_FORMAT_PDF | PDF文档。 | application/pdf. |
| DOCUMENT_FORMAT_POSTSCRIPT | PostScript文档。 | application/postscript. |
| DOCUMENT_FORMAT_TEXT | 纯文本。 | text/plain. |

### Print_JobDocAdapterState

**描述**

打印任务文档适配器状态。

**起始版本：** 13

| 枚举值 | 描述 |
| -------- | -------- |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY | 打印预览能力销毁。 |
| PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED | 打印任务成功。 |
| PRINT_DOC_ADAPTER_PRINT_TASK_FAIL | 打印任务失败。 |
| PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL | 打印任务取消。 |
| PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK | 打印任务阻塞。 |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED | 因取消导致的预览能力销毁。 |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED | 因任务开始导致的预览能力销毁。 |

## 函数说明

### OH_Print_Init()

```cpp
Print_ErrorCode OH_Print_Init();
```

**描述**

拉起打印服务，初始化打印客户端，并建立到打印服务的连接。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |
| PRINT_ERROR_SERVER_FAILURE | CUPS服务无法启动。 |

### OH_Print_Release()

```cpp
Print_ErrorCode OH_Print_Release();
```

**描述**

关闭与打印服务的连接，解除注册的回调，并释放打印客户端资源。

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |

### OH_Print_StartPrinterDiscovery()

```cpp
Print_ErrorCode OH_Print_StartPrinterDiscovery(Print_PrinterDiscoveryCallback callback);
```

**描述**

启动打印机发现过程。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| callback | 打印机发现事件回调函数。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |
| PRINT_ERROR_SERVER_FAILURE | 从BMS查询打印扩展列表失败。 |
| PRINT_ERROR_INVALID_EXTENSION | 没有可用的打印扩展。 |

### OH_Print_StopPrinterDiscovery()

```cpp
Print_ErrorCode OH_Print_StopPrinterDiscovery();
```

**描述**

停止打印机发现过程。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |

### OH_Print_ConnectPrinter()

```cpp
Print_ErrorCode OH_Print_ConnectPrinter(const char *printerId);
```

**描述**

使用打印机ID连接打印机。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerId | 要连接的打印机ID。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |
| PRINT_ERROR_INVALID_PRINTER | 打印机不在已发现列表中。 |
| PRINT_ERROR_SERVER_FAILURE | 无法找到负责该打印机的扩展。 |

### OH_Print_StartPrintJob()

```cpp
Print_ErrorCode OH_Print_StartPrintJob(const Print_PrintJob *printJob);
```

**描述**

启动打印任务。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printJob | 指向包含打印任务信息的Print_PrintJob结构体指针 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |
| PRINT_ERROR_INVALID_PRINTER | 打印机不在已连接列表中。 |
| PRINT_ERROR_SERVER_FAILURE | 无法在打印服务中创建打印任务。 |
| PRINT_ERROR_INVALID_PRINT_JOB | 无法在任务队列中找到该任务。 |

### OH_Print_RegisterPrinterChangeListener()

```cpp
Print_ErrorCode OH_Print_RegisterPrinterChangeListener(Print_PrinterChangeCallback callback);
```

**描述**

注册打印机状态变化监听器。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| callback | 打印机状态变化回调函数。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |

### OH_Print_UnregisterPrinterChangeListener()

```cpp
void OH_Print_UnregisterPrinterChangeListener();
```

**描述**

注销打印机状态变化监听器。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

### OH_Print_QueryPrinterList()

```cpp
Print_ErrorCode OH_Print_QueryPrinterList(Print_StringList *printerIdList);
```

**描述**

查询已添加的打印机列表。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerIdList | 用于存储查询结果的Print_StringList指针。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_INVALID_PARAMETER | printerIdList为NULL。 |
| PRINT_ERROR_INVALID_PRINTER | 无法查询到任何已连接打印机。 |
| PRINT_ERROR_GENERIC_FAILURE | 无法复制打印机ID列表。 |

### OH_Print_ReleasePrinterList()

```cpp
void OH_Print_ReleasePrinterList(Print_StringList *printerIdList);
```

**描述**

释放查询打印机列表时分配的内存。

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerIdList | 要释放的打印机ID列表。 |

### OH_Print_QueryPrinterInfo()

```cpp
Print_ErrorCode OH_Print_QueryPrinterInfo(const char *printerId, Print_PrinterInfo **printerInfo);
```

**描述**

根据打印机ID查询打印机信息。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerId | 要查询的打印机ID。 |
| printerInfo | 用于存储查询结果的Print_PrinterInfo指针。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |
| PRINT_ERROR_INVALID_PARAMETER | printerId或printerInfo为NULL。 |
| PRINT_ERROR_INVALID_PRINTER | 无法在已连接打印机列表中找到该打印机。 |

### OH_Print_ReleasePrinterInfo()

```cpp
void OH_Print_ReleasePrinterInfo(Print_PrinterInfo *printerInfo);
```

**描述**

释放查询打印机信息时分配的内存。

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerInfo | 要释放的打印机信息指针。 |

### OH_Print_LaunchPrinterManager()

```cpp
Print_ErrorCode OH_Print_LaunchPrinterManager();
```

**描述**

启动系统打印机管理窗口。

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_GENERIC_FAILURE | 无法启动打印机管理窗口。 |

### OH_Print_QueryPrinterProperties()

```cpp
Print_ErrorCode OH_Print_QueryPrinterProperties(const char *printerId, 
                                              const Print_StringList *propertyKeyList,
                                              Print_PropertyList *propertyList);
```

**描述**

根据属性关键字列表查询打印机属性值。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerId | 要查询的打印机ID。 |
| propertyKeyList | 要查询的属性关键字列表。 |
| propertyList | 用于存储查询结果的属性列表。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_INVALID_PARAMETER | 参数为NULL或关键字列表为空。 |
| PRINT_ERROR_INVALID_PRINTER | 找不到指定打印机的属性。 |
| PRINT_ERROR_GENERIC_FAILURE | 无法复制打印机属性。 |

### OH_Print_ReleasePrinterProperties()

```cpp
void OH_Print_ReleasePrinterProperties(Print_PropertyList *propertyList);
```

**描述**

释放查询打印机属性时分配的内存。

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| propertyList | 要释放的属性列表指针。 |

### OH_Print_UpdatePrinterProperties()

```cpp
Print_ErrorCode OH_Print_UpdatePrinterProperties(const char *printerId, 
                                               const Print_PropertyList *propertyList);
```

**描述**

根据属性键值对列表设置打印机属性。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerId | 要设置的打印机ID。 |
| propertyList | 要设置的属性列表。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |

### OH_Print_RestorePrinterProperties()

```cpp
Print_ErrorCode OH_Print_RestorePrinterProperties(const char *printerId, 
                                                const Print_StringList *propertyKeyList);
```

**描述**

根据属性关键字列表将打印机属性恢复为默认设置。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printerId | 要恢复的打印机ID。 |
| propertyKeyList | 要恢复的属性关键字列表。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |

### OH_Print_StartPrintByNative()

```cpp
Print_ErrorCode OH_Print_StartPrintByNative(const char *printJobName,
                                          Print_PrintDocCallback printDocCallback,
                                          void *context);
```

**描述**

启动打印服务。

**权限:** ohos.permission.PRINT

**系统能力:** SystemCapability.Print.PrintFramework

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| printJobName | 打印任务名称。 |
| printDocCallback | 打印文档状态回调。 |
| context | 调用者应用上下文。 |

**返回值:**

| 错误码 | 描述 |
| -------- | -------- |
| PRINT_ERROR_NONE | 操作成功。 |
| PRINT_ERROR_NO_PERMISSION | 缺少打印权限。 |
| PRINT_ERROR_RPC_FAILURE | 无法连接打印服务。 |
