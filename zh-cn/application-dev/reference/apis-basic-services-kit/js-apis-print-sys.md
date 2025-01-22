# @ohos.print (打印)(系统接口)

该模块为基本打印的操作API，提供调用基础打印功能的接口。

> **说明：**  
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前界面仅包含本模块的系统接口，其他公开接口参见[@ohos.print (打印)](./js-apis-print-sys.md)。

## 导入模块

```ts
import { print } from '@kit.BasicServicesKit';
```


## PrintMargin

定义打印页边距的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| top | number | 否 | 表示页面上边距 |
| bottom | number | 否 | 表示页面下边距 |
| left | number | 否 | 表示页面左边距 |
| right | number | 否 | 表示页面右边距 |

## PrinterRange

定义打印范围的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| startPage | number | 否 | 表示起始页 |
| endPage | number | 否 | 表示结束页 |
| pages | Array&lt;number&gt; | 否 | 表示离散页面 |

## PreviewAttribute

定义打印预览属性的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| previewRange | PrinterRange | 是 | 表示预览页面范围 |
| result | number | 否 | 表示预览文件结果 |

## PrintResolution

定义打印分辨率的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| id | string | 是 | 表示分辨率ID |
| horizontalDpi | number | 是 | 表示水平DPI |
| verticalDpi | number | 是 | 表示垂直DPI |



## PrinterCapability

定义打印能力的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| colorMode | number | 是 | 表示色彩模式 |
| duplexMode | number | 是 | 表示单双面打印模式 |
| pageSize | Array&lt;PrintPageSize&gt; | 是 | 表示打印机支持的页面尺寸列表 |
| resolution | Array&lt;PrintResolution&gt; | 否 | 表示打印机支持的分辨率列表 |
| minMargin | PrintMargin | 否 | 表示打印机最小边距 |
| options<sup>11+</sup> | Object | 否 | 表示JSON对象字符串 |

## PrinterInfo

定义打印信息的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 表示打印机ID |
| printerName | string | 是 | 表示打印机名称 |
| printerState | PrinterState | 是 | 表示当前打印机状态 |
| printerIcon | number | 否 | 表示打印机图标的资源ID |
| description | string | 否 | 表示打印机说明 |
| capability | PrinterCapability | 否 | 表示打印机功能 |
| options | Object | 否 | 表示JSON对象字符串 |

## PrintJob

定义打印任务的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| fdList | Array&lt;number&gt; | 是 | 表示待打印文件fd列表 |
| jobId | string | 是 | 表示打印任务ID |
| printerId | string | 是 | 表示负责打印的打印机ID |
| jobState | PrintJobState | 是 | 表示当前打印任务状态 |
| jobSubstate<sup>11+</sup> | PrintJobSubState | 是 | 表示当前打印任务子状态 |
| copyNumber | number | 是 | 表示文件列表副本 |
| pageRange | PrinterRange | 是 | 表示打印范围大小 |
| isSequential | boolean | 是 | 表示连续打印 |
| pageSize | PrintPageSize | 是 | 表示选定的页面尺寸 |
| isLandscape | boolean | 是 | 表示垂直打印 |
| colorMode | number | 是 | 表示色彩模式 |
| duplexMode | number | 是 | 表示单双面打印模式 |
| margin | PrintMargin | 否 | 表示当前页边距设置 |
| preview | PreviewAttribute | 否 | 表示预览设置 |
| options | Object | 否 | 表示JSON对象字符串 |

## PrinterExtensionInfo

定义打印扩展信息的接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| extensionId | string | 是 | 表示打印机扩展的扩展ID |
| vendorId | string | 是 | 表示扩展的供应商ID |
| vendorName | string | 是 | 表示供应商名称 |
| vendorIcon | number | 是 | 表示供应商图标 |
| version | string | 是 | 表示当前打印机扩展的版本 |

## queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(callback: AsyncCallback&lt;Array&lt;PrinterExtensionInfo&gt;&gt;): void

查询所有已安装的打印机扩展服务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;PrinterExtensionInfo&gt;&gt; | 是 | 异步查询所有已安装的打印机扩展服务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrinterExtensionInfos((err: BusinessError, extensionInfos: print.PrinterExtensionInfo[]) => {
    if (err) {
        console.log('queryAllPrinterExtensionInfos err ' + JSON.stringify(err));
    } else {
        console.log('queryAllPrinterExtensionInfos success ' + JSON.stringify(extensionInfos));
    }
})
```

## queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(): Promise&lt;Array&lt;PrinterExtensionInfo&gt;&gt;

查询所有已安装的打印机扩展服务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;Array&lt;PrinterExtensionInfo&gt;&gt; | 查询所有已安装的打印机扩展服务完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrinterExtensionInfos().then((extensionInfos: print.PrinterExtensionInfo[]) => {
    console.log('queryAllPrinterExtensionInfos success ' + JSON.stringify(extensionInfos));
    // ...
}).catch((error: BusinessError) => {
    console.log('failed to get AllPrinterExtension bacause ' + JSON.stringify(error));
})
```

## startDiscoverPrinter

startDiscoverPrinter(extensionList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

加载特定的打印机扩展并开始发现打印机，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| extensionList | Array&lt;string&gt; | 是 | 要加载的打印机扩展列表 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步开始发现打印机之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let extensionList: string[] = [];
//extensionList内无信息表示发现所有扩展
print.startDiscoverPrinter(extensionList, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to start Discover Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start Discover Printer success data : ' + JSON.stringify(data));
    }
})
```

## startDiscoverPrinter

startDiscoverPrinter(extensionList: Array&lt;string&gt;): Promise&lt;void&gt;

加载特定的打印机扩展并开始发现打印机，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| extensionList | Array&lt;string&gt; | 是 | 要加载的打印机扩展列表 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 加载特定的打印机扩展并开始发现打印机完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let extensionList: string[] = [];
//extensionList内无信息表示发现所有扩展
print.startDiscoverPrinter(extensionList).then((data : void) => {
    console.log('start Discovery success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to start Discovery because : ' + JSON.stringify(error));
})
```

## stopDiscoverPrinter

stopDiscoverPrinter(callback: AsyncCallback&lt;void&gt;): void

停止发现具有特定打印机扩展的打印机，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步停止发现具有特定打印机扩展的打印机之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.stopDiscoverPrinter((err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to stop Discover Printer because : ' + JSON.stringify(err));
    } else {
        console.log('stop Discover Printer success data : ' + JSON.stringify(data));
    }
})
```

## stopDiscoverPrinter

stopDiscoverPrinter(): Promise&lt;void&gt;

停止发现具有特定打印机扩展的打印机，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 停止发现具有特定打印机扩展的打印机完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.stopDiscoverPrinter().then((data : void) => {
    console.log('stop Discovery success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to stop Discovery because : ' + JSON.stringify(error));
})
```

## connectPrinter

connectPrinter(printerId: string, callback: AsyncCallback&lt;void&gt;): void

连接特定打印机，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 打印机ID |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步连接特定打印机之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.connectPrinter(printerId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to connect Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start connect Printer success data : ' + JSON.stringify(data));
    }
})
```

## connectPrinter

connectPrinter(printerId: string): Promise&lt;void&gt;

连接特定打印机，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 打印机ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 连接特定打印机完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.connectPrinter(printerId).then((data : void) => {
    console.log('start connect Printer success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to connect Printer because : ' + JSON.stringify(error));
})
```

## disconnectPrinter

disconnectPrinter(printerId: string, callback: AsyncCallback&lt;void&gt;): void

断开特定打印机的连接，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 打印机ID |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步断开特定打印机的连接之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.disconnectPrinter(printerId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to disconnect Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start disconnect Printer success data : ' + JSON.stringify(data));
    }
})
```

## disconnectPrinter

disconnectPrinter(printerId: string): Promise&lt;void&gt;

断开特定打印机的连接，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 打印机ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 断开特定打印机的连接完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.disconnectPrinter(printerId).then((data : void) => {
    console.log('start disconnect Printer success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to disconnect Printer because : ' + JSON.stringify(error));
})
```

## queryPrinterCapability

queryPrinterCapability(printerId: string, callback: AsyncCallback&lt;void&gt;): void

查询打印机能力，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 打印机ID |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步查询打印机能力之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.queryPrinterCapability(printerId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to query Printer Capability because : ' + JSON.stringify(err));
    } else {
        console.log('start query Printer Capability success data : ' + JSON.stringify(data));
    }
})
```

## queryPrinterCapability

queryPrinterCapability(printerId: string): Promise&lt;void&gt;

查询打印机能力，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 打印机ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 查询打印机能力完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.queryPrinterCapability(printerId).then((data : void) => {
    console.log('start query Printer success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to query Printer Capability because : ' + JSON.stringify(error));
})
```

## startPrintJob

startPrintJob(jobInfo: PrintJob, callback: AsyncCallback&lt;void&gt;): void

开始打印任务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | 是 | 打印任务信息 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步开始打印任务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.startPrintJob(jobInfo, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to start Print Job because : ' + JSON.stringify(err));
    } else {
        console.log('start Print Job success data : ' + JSON.stringify(data));
    }
})
```

## startPrintJob

startPrintJob(jobInfo: PrintJob): Promise&lt;void&gt;

开始打印任务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | 是 | 打印任务信息 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 开始打印任务完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.startPrintJob(jobInfo).then((data : void) => {
    console.log('start Print success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to start Print because : ' + JSON.stringify(error));
})
```

## cancelPrintJob

cancelPrintJob(jobId: string, callback: AsyncCallback&lt;void&gt;): void

取消已发送到打印机的打印任务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 打印任务ID |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步取消已发送到打印机的打印任务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '121212';
print.cancelPrintJob(jobId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('cancelPrintJob failed, because : ' + JSON.stringify(err));
    } else {
        console.log('cancelPrintJob success, data: ' + JSON.stringify(data));
    }
})
```

## cancelPrintJob

cancelPrintJob(jobId: string): Promise&lt;void&gt;

取消已发送到打印机的打印任务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 打印任务ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 取消已发送到打印机的打印任务完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '121212';
print.cancelPrintJob(jobId).then((data : void) => {
    console.log('cancelPrintJob success, data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('cancelPrintJob failed, because : ' + JSON.stringify(error));
})
```

## requestPrintPreview

requestPrintPreview(jobInfo: PrintJob, callback: Callback&lt;number&gt;): void

请求预览打印数据，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | 是 | 打印任务信息 |
| callback | Callback&lt;number&gt; | 是 | 请求预览打印数据之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.requestPrintPreview(jobInfo, (num : number) => {
    console.log('requestPrintPreview success, num : ' + JSON.stringify(num));

})
```

## requestPrintPreview

requestPrintPreview(jobInfo: PrintJob): Promise&lt;number&gt;

请求预览打印数据，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | 是 | 打印任务信息 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;number&gt; | 请求预览打印数据完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.requestPrintPreview(jobInfo).then((num: number) => {
    console.log('requestPrintPreview success, num : ' + JSON.stringify(num));
}).catch((error: BusinessError) => {
    console.log('requestPrintPreview failed, because : ' + JSON.stringify(error));
})
```

## on

on(type: 'printerStateChange', callback: (state: PrinterState, info: PrinterInfo) => void): void

注册打印机状态变化事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'printerStateChange' | 是 | 表示打印机状态改变 |
| callback | (state: PrinterState, info: PrinterInfo) => void | 是 | 打印机状态改变之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('printerStateChange', (state: print.PrinterState, info: print.PrinterInfo) => {
    if (state === null || info === null) {
        console.log('printer state changed state is null or info is null');
        return;
    } else {
        console.log('on printer state changed, state : ' + JSON.stringify(state));
        console.log('on printer state changed, info : ' + JSON.stringify(info));
    }
})
```

## off

off(type: 'printerStateChange', callback?: Callback&lt;boolean&gt;): void

取消注册打印机状态变化事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'printerStateChange' | 是 | 表示打印机状态改变 |
| callback | Callback&lt;boolean&gt; | 否 | 打印机状态改变之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('printerStateChange', (data: boolean) => {
    console.log('off printerStateChange data : ' + JSON.stringify(data));
})
```

## on

on(type: 'jobStateChange', callback: (state: PrintJobState, job: PrintJob) => void): void

注册打印任务状态变化事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'jobStateChange' | 是 | 表示打印任务状态改变 |
| callback | (state: PrintJobState, job: PrintJob) => void | 是 | 打印任务状态改变之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('jobStateChange', (state: print.PrintJobState, job: print.PrintJob) => {
    console.log('onJobStateChange, state : ' + JSON.stringify(state) + ', job : ' + JSON.stringify(job));
})
```

## off

off(type: 'jobStateChange', callback?: Callback&lt;boolean&gt;): void

取消注册打印任务状态变化事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'jobStateChange' | 是 | 表示打印任务状态改变 |
| callback | Callback&lt;boolean&gt; | 否 | 打印任务状态改变之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('jobStateChange', (data: boolean) => {
    console.log('offJobStateChanged data : ' + JSON.stringify(data));
})
```

## on

on(type: 'extInfoChange', callback: (extensionId: string, info: string) => void): void

注册打印扩展信息变化事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'extInfoChange' | 是 | 表示打印扩展信息改变 |
| callback | (extensionId: string, info: string) => void | 是 | 打印扩展信息改变之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('extInfoChange', (extensionId: string, info: string) => {
    console.log('onExtInfoChange, entensionId : ' + JSON.stringify(extensionId) + ', info : ' + JSON.stringify(info));
})
```

## off

off(type: 'extInfoChange', callback?: Callback&lt;boolean&gt;): void

取消注册打印扩展信息变化事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'extInfoChange' | 是 | 表示打印扩展信息改变 |
| callback | Callback&lt;boolean&gt; | 否 | 打印任务扩展信息改变之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('extInfoChange', (data: boolean) => {
    console.log('offExtInfoChange data : ' + JSON.stringify(data));
})
```

## addPrinters

addPrinters(printers: Array&lt;PrinterInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

添加打印机，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | 是 | 表示新到达的打印机列表 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步添加打印机之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.addPrinters([printerInfo], (err: BusinessError, data : void) => {
    if (err) {
        console.log('addPrinters failed, because : ' + JSON.stringify(err));
    } else {
        console.log('addPrinters success, data : ' + JSON.stringify(data));
    }
})
```

## addPrinters

addPrinters(printers: Array&lt;PrinterInfo&gt;): Promise&lt;void&gt;

添加打印机，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | 是 | 表示新到达的打印机列表 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 添加打印机完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.addPrinters([printerInfo]).then((data : void) => {
    console.log('add printers data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('add printers error : ' + JSON.stringify(error));
})
```

## removePrinters

removePrinters(printerIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

移除打印机，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerIds | Array&lt;string&gt; | 是 | 表示需移除的打印机列表 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步移除打印机之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
print.removePrinters([printerId], (err: BusinessError, data : void) => {
    if (err) {
        console.log('removePrinters failed, because : ' + JSON.stringify(err));
    } else {
        console.log('removePrinters success, data : ' + JSON.stringify(data));
    }
})
```

## removePrinters

removePrinters(printerIds: Array&lt;string&gt;): Promise&lt;void&gt;

移除打印机，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerIds | Array&lt;string&gt; | 是 | 表示需移除的打印机列表 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 移除打印机完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
print.removePrinters([printerId]).then((data : void) => {
    console.log('remove printers data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('remove printers error : ' + JSON.stringify(error));
})
```

## updatePrinters

updatePrinters(printers: Array&lt;PrinterInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

更新特定打印机的信息，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | 是 | 表示待更新的打印机列表 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步更新打印机信息之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.updatePrinters([printerInfo], (err: BusinessError, data : void) => {
    if (err) {
        console.log('updataPrinters failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updataPrinters success, data : ' + JSON.stringify(data));
    }
})
```

## updatePrinters

updatePrinters(printers: Array&lt;PrinterInfo&gt;): Promise&lt;void&gt;

更新特定打印机的信息，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | 是 | 表示待更新的打印机列表 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 更新打印机完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.updatePrinters([printerInfo]).then((data : void) => {
    console.log('update printers data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update printers error : ' + JSON.stringify(error));
})
```

## updatePrinterState

updatePrinterState(printerId: string, state: PrinterState, callback: AsyncCallback&lt;void&gt;): void

更新打印机状态，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 表示打印机ID |
| state | PrinterState | 是 | 表示打印机状态 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步更新打印机状态之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
let state : print.PrinterState = print.PrinterState.PRINTER_CONNECTED;
print.updatePrinterState(printerId, state, (err: BusinessError, data : void) => {
    if (err) {
        console.log('updataPrinterState failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updataPrinterState success, data : ' + JSON.stringify(data));
    }
})
```

## updatePrinterState

updatePrinterState(printerId: string, state: PrinterState): Promise&lt;void&gt;

更新打印机状态，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 表示打印机ID |
| state | PrinterState | 是 | 表示打印机状态 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 更新打印机状态完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
let state : print.PrinterState = print.PrinterState.PRINTER_CONNECTED;
print.updatePrinterState(printerId, state).then((data : void) => {
    console.log('update printer state data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update printer state error : ' + JSON.stringify(error));
})
```

## updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState, callback: AsyncCallback&lt;void&gt;): void

更新打印任务状态，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| state | PrintJobState | 是 | 表示打印任务状态 |
| subState | PrintJobSubState | 是 | 表示打印任务子状态 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步更新打印任务状态之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '3434';
let state : print.PrintJobState = print.PrintJobState.PRINT_JOB_PREPARE;
let subState : print.PrintJobSubState = print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS;
print.updatePrintJobState(jobId, state, subState, (err: BusinessError, data : void) => {
    if (err) {
        console.log('updataPrintJobState failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updatePrintJobState success, data : ' + JSON.stringify(data));
    }
})
```

## updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState): Promise&lt;void&gt;

更新打印任务状态，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| state | PrintJobState | 是 | 表示打印任务状态 |
| subState | PrintJobSubState | 是 | 表示打印任务子状态 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 更新打印任务状态完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '3434';
let state : print.PrintJobState = print.PrintJobState.PRINT_JOB_PREPARE;
let subState : print.PrintJobSubState = print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS;
print.updatePrintJobState(jobId, state, subState).then((data : void) => {
    console.log('update print job state data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update print job state error : ' + JSON.stringify(error));
})
```

## updateExtensionInfo

updateExtensionInfo(info: string, callback: AsyncCallback&lt;void&gt;): void

更新打印扩展状态，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| info | string | 是 | 表示打印扩展变更信息 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步更新打印扩展状态之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let info : string = 'WIFI_INACTIVE';
print.updateExtensionInfo(info, (err: BusinessError, data : void) => {
    if (err) {
        console.log('updateExtensionInfo failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updateExtensionInfo success, data : ' + JSON.stringify(data));
    }
})
```

## updateExtensionInfo

updateExtensionInfo(info: string): Promise&lt;void&gt;

更新打印扩展状态，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| info | string | 是 | 表示打印扩展变更信息 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 更新打印扩展状态完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let info : string = 'WIFI_INACTIVE';
print.updateExtensionInfo(info).then((data : void) => {
    console.log('update print job state data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update print job state error : ' + JSON.stringify(error));
})
```

## queryAllPrintJobs<sup>(deprecated)</sup>

> 从API version 10开始支持，从API version 11开始废弃。
> 建议使用[queryPrintJobList](#queryprintjoblist11)替代。

queryAllPrintJobs(callback: AsyncCallback&lt;void&gt;): void

查询所有打印任务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步查询所有打印任务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrintJobs((err: BusinessError, data : void) => {
    if (err) {
        console.log('queryAllPrintJobs failed, because : ' + JSON.stringify(err));
    } else {
        console.log('queryAllPrintJobs success, data : ' + JSON.stringify(data));
    }
})
```

## queryAllPrintJobs<sup>(deprecated)</sup>

> 从API version 10开始支持，从API version 11开始废弃。
> 建议使用[queryPrintJobList](#queryprintjoblist11-1)替代。

queryAllPrintJobs(): Promise&lt;void&gt;

查询所有打印任务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 查询所有打印任务完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrintJobs().then((data : void) => {
    console.log('queryAllPrintJobs success, data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('queryAllPrintJobs failed, error : ' + JSON.stringify(error));
})
```

## queryPrintJobList<sup>11+</sup>

queryPrintJobList(callback: AsyncCallback&lt;Array&lt;PrintJob&gt;&gt;): void

查询所有打印任务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;PrintJob&gt;&gt; | 是 | 异步查询所有打印任务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryPrintJobList((err: BusinessError, printJobs : print.PrintJob[]) => {
    if (err) {
        console.log('queryPrintJobList failed, because : ' + JSON.stringify(err));
    } else {
        console.log('queryPrintJobList success, data : ' + JSON.stringify(printJobs));
    }
})
```

## queryPrintJobList<sup>11+</sup>

queryPrintJobList(): Promise&lt;Array&lt;PrintJob&gt;&gt;

查询所有打印任务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;Array&lt;PrintJob&gt;&gt; | 查询所有打印任务完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryPrintJobList().then((printJobs : print.PrintJob[]) => {
    console.log('queryPrintJobList success, data : ' + JSON.stringify(printJobs));
}).catch((error: BusinessError) => {
    console.log('queryPrintJobList failed, error : ' + JSON.stringify(error));
})
```

## queryPrintJobById<sup>11+</sup>

queryPrintJobById(jobId: string, callback: AsyncCallback&lt;PrintJob&gt;): void

按打印任务ID查询打印任务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| callback | AsyncCallback&lt;PrintJob&gt; | 是 | 异步按打印任务ID查询打印任务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.queryPrintJobById(jobId, (err: BusinessError, printJob : print.PrintJob) => {
    if (err) {
        console.log('queryPrintJobById failed, because : ' + JSON.stringify(err));
    } else {
        console.log('queryPrintJobById success, data : ' + JSON.stringify(printJob));
    }
})
```

## queryPrintJobById<sup>11+</sup>

queryPrintJobById(jobId: string): Promise&lt;PrintJob&gt;

按打印任务ID查询打印任务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintJob&gt; | 按打印任务ID查询打印任务完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.queryPrintJobById(jobId).then((printJob : print.PrintJob) => {
    console.log('queryPrintJobById data : ' + JSON.stringify(printJob));
}).catch((error: BusinessError) => {
    console.log('queryPrintJobById error : ' + JSON.stringify(error));
})
```

## startGettingPrintFile<sup>11+</sup>

startGettingPrintFile(jobId: string, printAttributes: PrintAttributes, fd: number, onFileStateChanged: Callback&lt;PrintFileCreationState&gt;): void

开始获取打印文件，使用Callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| printAttributes | PrintAttributes | 是 | 表示打印参数 |
| fd | number | 是 | 表示打印文件描述符 |
| onFileStateChanged | Callback&lt;PrintFileCreationState&gt; | 是 | 表示更新文件状态的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string= '1';
class MyPrintAttributes implements print.PrintAttributes {
    copyNumber?: number;
    pageRange?: print.PrintPageRange;
    pageSize?: print.PrintPageSize | print.PrintPageType;
    directionMode?: print.PrintDirectionMode;
    colorMode?: print.PrintColorMode;
    duplexMode?: print.PrintDuplexMode;
}

class MyPrintPageRange implements print.PrintPageRange {
    startPage?: number;
    endPage?: number;
    pages?: Array<number>;
}

class MyPrintPageSize implements print.PrintPageSize {
    id: string = '0';
    name: string = '0';
    width: number = 210;
    height: number = 297;
}

let printAttributes = new MyPrintAttributes();
printAttributes.copyNumber = 2;
printAttributes.pageRange = new MyPrintPageRange();
printAttributes.pageRange.startPage = 0;
printAttributes.pageRange.endPage = 5;
printAttributes.pageRange.pages = [1, 3];
printAttributes.pageSize = print.PrintPageType.PAGE_ISO_A3;
printAttributes.directionMode = print.PrintDirectionMode.DIRECTION_MODE_AUTO;
printAttributes.colorMode = print.PrintColorMode.COLOR_MODE_MONOCHROME;
printAttributes.duplexMode = print.PrintDuplexMode.DUPLEX_MODE_NONE;

let fd : number = 1;
print.startGettingPrintFile(jobId, printAttributes, fd, (state: print.PrintFileCreationState) => {
    console.log('onFileStateChanged success, data : ' + JSON.stringify(state));
})
```

## notifyPrintService<sup>11+</sup>

notifyPrintService(jobId: string, type: 'spooler_closed_for_cancelled' | 'spooler_closed_for_started', callback: AsyncCallback&lt;void&gt;): void

将spooler关闭信息通知打印服务，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| type | 'spooler_closed_for_cancelled' \| 'spooler_closed_for_started' | 是 | 表示spooler关闭信息 |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步将spooler关闭信息通知打印服务之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.notifyPrintService(jobId, 'spooler_closed_for_started', (err: BusinessError, data : void) => {
    if (err) {
        console.log('notifyPrintService failed, because : ' + JSON.stringify(err));
    } else {
        console.log('notifyPrintService success, data : ' + JSON.stringify(data));
    }
})
```

## notifyPrintService<sup>11+</sup>

notifyPrintService(jobId: string, type: 'spooler_closed_for_cancelled' | 'spooler_closed_for_started'): Promise&lt;void&gt;

将spooler关闭信息通知打印服务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| type | 'spooler_closed_for_cancelled' \| 'spooler_closed_for_started' | 是 | 表示spooler关闭信息 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 将spooler关闭信息通知打印服务后的完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.notifyPrintService(jobId, 'spooler_closed_for_started').then((data : void) => {
    console.log('notifyPrintService data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('notifyPrintService error : ' + JSON.stringify(error));
})
```

## getAddedPrinters<sup>12+</sup>

getAddedPrinters(): Promise&lt;Array&lt;string&gt;&gt;

获取cups已添加打印机列表，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | 获取cups已添加打印机列表的完成结果回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.getAddedPrinters().then((printers: string[]) => {
    console.log('getAddedPrinters success ' + JSON.stringify(printers));
    // ...
}).catch((error: BusinessError) => {
    console.log('failed to getAddedPrinters bacause ' + JSON.stringify(error));
})
```

## getPrinterInfoById<sup>12+</sup>

getPrinterInfoById(printerId: string): Promise&lt;PrinterInfo&gt;

根据打印机id获取打印机信息，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | string | 是 | 表示打印机ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrinterInfo&gt; | 根据打印机id获取打印机信息后的完成结果回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1';
print.getPrinterInfoById(printerId).then((printerInfo : print.PrinterInfo) => {
    console.log('getPrinterInfoById data : ' + JSON.stringify(printerInfo));
}).catch((error: BusinessError) => {
    console.log('getPrinterInfoById error : ' + JSON.stringify(error));
})
```

## notifyPrintServiceEvent<sup>12+</sup>

notifyPrintServiceEvent(event: ApplicationEvent): Promise&lt;void&gt;

将打印应用相关事件通知打印服务，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| event | ApplicationEvent | 是 | 表示打印应用事件 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 将打印应用相关事件通知打印服务后的完成结果回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let event : print.ApplicationEvent = print.ApplicationEvent.APPLICATION_CREATED;
print.notifyPrintServiceEvent(event).then((data : void) => {
    console.log('notifyPrintServiceEvent data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('notifyPrintServiceEvent error : ' + JSON.stringify(error));
})
```