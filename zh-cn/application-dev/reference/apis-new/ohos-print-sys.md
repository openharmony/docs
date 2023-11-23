# @ohos.print    
该模块为基本打印的操作API，提供调用基础打印功能的接口。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import print from '@ohos.print'    
```  
    
## PrintMargin    
定义打印页边距的接口  
。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| top | number | false | false | 表示页面上边距 |  
| bottom | number | false | false | 表示页面下边距 |  
| left | number | false | false | 表示页面左边距 |  
| right | number | false | false | 表示页面右边距  |  
    
## PrinterRange    
定义打印范围的接口  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| startPage | number | false | false | 表示起始页 |  
| endPage | number | false | false | 表示结束页  |  
| pages | Array<number> | false | false | 表示离散页面 |  
    
## PreviewAttribute    
定义打印预览属性的接口  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| previewRange | PrinterRange | false | true | 表示预览页面范围  |  
| result | number | false | false | 表示预览文件结果 |  
    
## PrintResolution    
定义打印分辨率的接口。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | string | false | true | 表示分辨率ID |  
| horizontalDpi | number | false | true | 表示水平DPI |  
| verticalDpi | number | false | true | 表示垂直DPI |  
    
## PrintPageSize    
定义打印页面尺寸的接口  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | string | false | true | 表示页面尺寸ID |  
| name | string | false | true | 表示页面尺寸名称 |  
| width | number | false | true | 表示页面宽度，单位：毫米 |  
| height | number | false | true |  表示页面高度，单位：毫米 |  
    
## PrinterCapability    
定义打印能力的接口  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| colorMode | number | false | true | 表示色彩模式 |  
| duplexMode | number | false | true | 表示单双面打印模式 |  
| pageSize | Array<PrintPageSize> | false | true |  表示打印机支持的页面尺寸列表 |  
| resolution | Array<PrintResolution> | false | false | 表示打印机支持的分辨率列表  |  
| minMargin | PrintMargin | false | false | 表示打印机最小边距 |  
    
## PrinterInfo    
定义打印信息的接口。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| printerId | string | false | true | 表示打印机ID |  
| printerName | string | false | true | 表示打印机名称 |  
| printerState | PrinterState | false | true |  表示当前打印机状态 |  
| printerIcon | number | false | false | 表示打印机图标的资源ID |  
| description | string | false | false | 表示打印机说明 |  
| capability | PrinterCapability | false | false | 表示打印机功能  |  
| options | Object | false | false | 表示JSON对象字符串 |  
    
## PrintJob    
定义打印任务的接口  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fdList | Array<number> | false | true | 表示待打印文件fd列表 |  
| jobId | string | false | true | 表示打印任务ID |  
| printerId | string | false | true | 表示负责打印的打印机ID |  
| jobState | PrintJobState | false | true | 表示当前打印任务状态 |  
| copyNumber | number | false | true | 表示文件列表副本 |  
| pageRange | PrinterRange | false | true | 表示打印范围大小 |  
| isSequential | boolean | false | true | 表示连续打印 |  
| pageSize | PrintPageSize | false | true | 表示选定的页面尺寸 |  
| isLandscape | boolean | false | true | 表示垂直打印 |  
| colorMode | number | false | true | 表示色彩模式 |  
| duplexMode | number | false | true | 表示单双面打印模式 |  
| margin | PrintMargin | false | false | 表示当前页边距设置 |  
| preview | PreviewAttribute | false | false | 表示预览设置 |  
| options | Object | false | false | 表示JSON对象字符串 |  
    
## PrinterState    
打印机状态的枚举  
    
    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PRINTER_ADDED | 0 | 表示新打印机到达  |  
| PRINTER_REMOVED | 1 | 表示打印机丢失 |  
| PRINTER_CAPABILITY_UPDATED | 2 | 表示打印机更新 |  
| PRINTER_CONNECTED | 3 | 表示打印机已连接 |  
| PRINTER_DISCONNECTED | 4 | 表示打印机已断开连接 |  
| PRINTER_RUNNING | 5 | 表示打印机正在运行 |  
    
## PrintJobState    
打印任务状态的枚举    
    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PRINT_JOB_PREPARE | 0 | 表示打印任务的初始状态 |  
| PRINT_JOB_QUEUED | 1 | 表示打印任务传送到打印机 |  
| PRINT_JOB_RUNNING | 2 | 表示执行打印任务 |  
| PRINT_JOB_BLOCKED | 3 | 表示打印任务已被阻止 |  
| PRINT_JOB_COMPLETED | 4 | 表示打印任务完成 |  
    
## PrintJobSubState    
打印任务子状态的枚举    
    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PRINT_JOB_COMPLETED_SUCCESS | 0 | 表示打印任务成功 |  
| PRINT_JOB_COMPLETED_FAILED | 1 | 表示打印任务失败 |  
| PRINT_JOB_COMPLETED_CANCELLED | 2 | 表示打印任务已取消 |  
| PRINT_JOB_COMPLETED_FILE_CORRUPTED | 3 | 表示打印任务已损坏  |  
| PRINT_JOB_BLOCK_OFFLINE | 4 | 表示打印处于离线状态 |  
| PRINT_JOB_BLOCK_BUSY | 5 | 表示打印被其他进程占用 |  
| PRINT_JOB_BLOCK_CANCELLED | 6 | 示打印任务已取消 |  
| PRINT_JOB_BLOCK_OUT_OF_PAPER | 7 | 表示打印纸张用完 |  
| PRINT_JOB_BLOCK_OUT_OF_INK | 8 | 表示打印墨水用完 |  
| PRINT_JOB_BLOCK_OUT_OF_TONER | 9 | 表示打印墨粉用完 |  
| PRINT_JOB_BLOCK_JAMMED | 10 | 表示打印卡纸 |  
| PRINT_JOB_BLOCK_DOOR_OPEN | 11 | 表示打印盖开启 |  
| PRINT_JOB_BLOCK_SERVICE_REQUEST | 12 | 表示打印服务请求 |  
| PRINT_JOB_BLOCK_LOW_ON_INK | 13 | 表示打印墨水不足 |  
| PRINT_JOB_BLOCK_LOW_ON_TONER | 14 | 表示打印墨粉不足 |  
| PRINT_JOB_BLOCK_REALLY_LOW_ON_INK | 15 | 表示打印墨水量非常低 |  
| PRINT_JOB_BLOCK_BAD_CERTIFICATE | 16 | 表示打印证书有误 |  
| PRINT_JOB_BLOCK_UNKNOWN | 99 | 表示打印未知问题 |  
    
## PrintErrorCode    
打印错误代码的枚举    
    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| E_PRINT_NONE | 0 | 表示没有许可 |  
| E_PRINT_NO_PERMISSION | 201 | 表示没有许可。 |  
| E_PRINT_INVALID_PARAMETER | 401 | 表示无效的参数。 |  
| E_PRINT_GENERIC_FAILURE | 13100001 | 表示一般打印失败 |  
| E_PRINT_RPC_FAILURE | 13100002 | 表示RPC失败  |  
| E_PRINT_SERVER_FAILURE | 13100003 | 表示打印服务失败  |  
| E_PRINT_INVALID_EXTENSION | 13100004 | 表示打印扩展无效 |  
| E_PRINT_INVALID_PRINTER | 13100005 | 表示打印机无效 |  
| E_PRINT_INVALID_PRINT_JOB | 13100006 | 表示打印任务无效 |  
| E_PRINT_FILE_IO | 13100007 | 表示文件输入/输出错误 |  
    
## PrinterExtensionInfo    
定义打印扩展信息的接口  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### 属性    
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| extensionId | string | false | true | 表示打印机扩展的扩展ID  |  
| vendorId | string | false | true | 表示扩展的供应商ID |  
| vendorName | string | false | true | 表示供应商名称 |  
| vendorIcon | number | false | true | 表示供应商图标  |  
| version | string | false | true |  表示当前打印机扩展的版本  |  
    
## queryAllPrinterExtensionInfos    
查询所有已安装的打印机扩展服务  
 **调用形式：**     
    
- queryAllPrinterExtensionInfos(callback: AsyncCallback\<Array\<PrinterExtensionInfo>>): void    
起始版本： 10    
- queryAllPrinterExtensionInfos(): Promise\<Array\<PrinterExtensionInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步查询所有已安装的打印机扩展服务之后的回调 |  
| Promise<Array<PrinterExtensionInfo>> | 查询所有已安装的打印机扩展服务完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
print.queryAllPrinterExtensionInfos((err: BusinessError, extensionInfos: print.PrinterExtensionInfo[]) => {  
    if (err) {  
        console.log('queryAllPrinterExtensionInfos err ' + JSON.stringify(err));  
    } else {  
        console.log('queryAllPrinterExtensionInfos success ' + JSON.stringify(extensionInfos));  
    }  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
print.queryAllPrinterExtensionInfos().then((extensionInfos: print.PrinterExtensionInfo[]) => {  
    console.log('queryAllPrinterExtensionInfos success ' + JSON.stringify(extensionInfos));  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('failed to get AllPrinterExtension bacause ' + JSON.stringify(error));  
})  
    
```    
  
    
## startDiscoverPrinter    
加载特定的打印机扩展并开始发现打印机  
 **调用形式：**     
    
- startDiscoverPrinter(extensionList: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startDiscoverPrinter(extensionList: Array\<string>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| extensionList | Array<string> | true | 要加载的打印机扩展列表 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步开始发现打印机之后的回调 |  
| Promise<void> | 加载特定的打印机扩展并开始发现打印机完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
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
停止发现具有特定打印机扩展的打印机  
 **调用形式：**     
    
- stopDiscoverPrinter(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopDiscoverPrinter(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步停止发现具有特定打印机扩展的打印机之后的回调 |  
| Promise<void> | 停止发现具有特定打印机扩展的打印机完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
print.stopDiscoverPrinter((err: BusinessError, data : void) => {  
    if (err) {  
        console.log('failed to stop Discover Printer because : ' + JSON.stringify(err));  
    } else {  
        console.log('stop Discover Printer success data : ' + JSON.stringify(data));  
    }  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
print.stopDiscoverPrinter().then((data : void) => {  
    console.log('stop Discovery success data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('failed to stop Discovery because : ' + JSON.stringify(error));  
})  
    
```    
  
    
## connectPrinter    
连接特定打印机  
 **调用形式：**     
    
- connectPrinter(printerId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- connectPrinter(printerId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | string | true | 打印机ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步连接特定打印机之后的回调 |  
| Promise<void> | 连接特定打印机完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let printerId: string = 'printerId_32';  
print.connectPrinter(printerId).then((data : void) => {  
    console.log('start connect Printer success data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('failed to connect Printer because : ' + JSON.stringify(error));  
})  
    
```    
  
    
## disconnectPrinter    
断开特定打印机的连接  
 **调用形式：**     
    
- disconnectPrinter(printerId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- disconnectPrinter(printerId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | string | true | 打印机ID  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步断开特定打印机的连接之后的回调 |  
| Promise<void> | 断开特定打印机的连接完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let printerId: string = 'printerId_32';  
print.disconnectPrinter(printerId).then((data : void) => {  
    console.log('start disconnect Printer success data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('failed to disconnect Printer because : ' + JSON.stringify(error));  
})  
    
```    
  
    
## queryPrinterCapability    
查询打印机能力  
 **调用形式：**     
    
- queryPrinterCapability(printerId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- queryPrinterCapability(printerId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | string | true | 打印机ID  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步查询打印机能力之后的回调 |  
| Promise<void> | 查询打印机能力完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let printerId: string = 'printerId_32';  
print.queryPrinterCapability(printerId).then((data : void) => {  
    console.log('start query Printer success data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('failed to query Printer Capability because : ' + JSON.stringify(error));  
})  
    
```    
  
    
## startPrintJob    
开始打印任务  
 **调用形式：**     
    
- startPrintJob(jobInfo: PrintJob, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startPrintJob(jobInfo: PrintJob): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobInfo | PrintJob | true | 打印任务信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步开始打印任务之后的回调 |  
| Promise<void> | 开始打印任务完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let jobInfo : print.PrintJob = {  
    fdList : [0,1],  
    jobId : 'jobId_12',  
    printerId : 'printerId_32',  
    jobState : 3,  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let jobInfo : print.PrintJob = {  
    fdList : [0,1],  
    jobId : 'jobId_12',  
    printerId : 'printerId_32',  
    jobState : 3,  
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
取消已发送到打印机的打印任务  
 **调用形式：**     
    
- cancelPrintJob(jobId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- cancelPrintJob(jobId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobId | string | true |  打印任务ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步取消已发送到打印机的打印任务之后的回调 |  
| Promise<void> | 取消已发送到打印机的打印任务完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let jobId : string = '121212';  
print.cancelPrintJob(jobId).then((data : void) => {  
    console.log('cancelPrintJob success, data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('cancelPrintJob failed, because : ' + JSON.stringify(error));  
})  
    
```    
  
    
## requestPrintPreview    
请求预览打印数据  
 **调用形式：**     
    
- requestPrintPreview(jobInfo: PrintJob, callback: Callback\<number>): void    
起始版本： 10    
- requestPrintPreview(jobInfo: PrintJob): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobInfo | PrintJob | true | 打印任务信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 请求预览打印数据之后的回调 |  
| Promise<number> | 请求预览打印数据完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
let jobInfo : print.PrintJob = {    fdList : [0,1],    jobId : 'jobId_12',    printerId : 'printerId_32',    jobState : 3,    copyNumber : 1,    pageRange : {},    isSequential : false,    pageSize : {id : '', name : '', width : 10, height : 20},    isLandscape : false,    colorMode : 6,    duplexMode : 6,    margin : undefined,    preview : undefined,    options : undefined};print.requestPrintPreview(jobInfo, (num : number) => {    console.log('requestPrintPreview success, num : ' + JSON.stringify(num));})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let jobInfo : print.PrintJob = {  
    fdList : [0,1],  
    jobId : 'jobId_12',  
    printerId : 'printerId_32',  
    jobState : 3,  
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
  
    
## on('printerStateChange')    
注册打印机状态变化事件回调，使用callback回调。  
 **调用形式：**     
    
- on(type: 'printerStateChange', callback: (state: PrinterState, info: PrinterInfo) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 表示打印机状态改变  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印机状态改变之后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
  
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
  
    
## off('printerStateChange')    
取消注册打印机状态变化事件回调，使用callback回调。  
 **调用形式：**     
    
- off(type: 'printerStateChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 表示打印机状态改变 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印机状态改变之后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
print.off('printerStateChange', (data: boolean) => {    console.log('off printerStateChange data : ' + JSON.stringify(data));})    
```    
  
    
## on('jobStateChange')    
注册打印任务状态变化事件回调，使用callback回调。  
 **调用形式：**     
    
- on(type: 'jobStateChange', callback: (state: PrintJobState, job: PrintJob) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  表示打印任务状态改变  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印任务状态改变之后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
print.on('jobStateChange', (state: print.PrintJobState, job: print.PrintJob) => {    console.log('onJobStateChange, state : ' + JSON.stringify(state) + ', job : ' + JSON.stringify(job));})    
```    
  
    
## off('jobStateChange')    
取消注册打印任务状态变化事件回调，使用callback回调。  
 **调用形式：**     
    
- off(type: 'jobStateChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 表示打印任务状态改变 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印任务状态改变之后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
print.off('jobStateChange', (data: boolean) => {    console.log('offJobStateChanged data : ' + JSON.stringify(data));})    
```    
  
    
## on('extInfoChange')    
注册打印扩展信息变化事件回调，使用callback回调。  
 **调用形式：**     
    
- on(type: 'extInfoChange', callback: (extensionId: string, info: string) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  表示打印扩展信息改变 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印扩展信息改变之后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
print.on('extInfoChange', (extensionId: string, info: string) => {    console.log('onExtInfoChange, entensionId : ' + JSON.stringify(extensionId) + ', info : ' + JSON.stringify(info));})    
```    
  
    
## off('extInfoChange')    
取消注册打印扩展信息变化事件回调，使用callback回调。  
 **调用形式：**     
    
- off(type: 'extInfoChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 表示打印扩展信息改变 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印任务扩展信息改变之后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
print.off('extInfoChange', (data: boolean) => {    console.log('offExtInfoChange data : ' + JSON.stringify(data));})    
```    
  
    
## addPrinters    
添加打印机  
 **调用形式：**     
    
- addPrinters(printers: Array\<PrinterInfo>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addPrinters(printers: Array\<PrinterInfo>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printers | Array<PrinterInfo> | true | 表示新到达的打印机列表 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步添加打印机之后的回调 |  
| Promise<void> | 添加打印机完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
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
移除打印机  
 **调用形式：**     
    
- removePrinters(printerIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removePrinters(printerIds: Array\<string>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerIds | Array<string> | true | 表示需移除的打印机列表 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步移除打印机之后的回调 |  
| Promise<void> | 移除打印机完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let printerId : string = '1212';  
print.removePrinters([printerId]).then((data : void) => {  
    console.log('remove printers data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('remove printers error : ' + JSON.stringify(error));  
})  
    
```    
  
    
## updatePrinters    
更新特定打印机的信息  
 **调用形式：**     
    
- updatePrinters(printers: Array\<PrinterInfo>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updatePrinters(printers: Array\<PrinterInfo>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printers | Array<PrinterInfo> | true | 表示待更新的打印机列表 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步更新打印机信息之后的回调 |  
| Promise<void> | 更新打印机完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
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
更新打印机状态  
 **调用形式：**     
    
- updatePrinterState(printerId: string, state: PrinterState, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updatePrinterState(printerId: string, state: PrinterState): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | string | true | 表示打印机ID |  
| state | PrinterState | true | 表示打印机状态 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步更新打印机状态之后的回调 |  
| Promise<void> | 更新打印机状态完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
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
更新打印任务状态  
 **调用形式：**     
    
- updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobId | string | true | 表示打印任务ID |  
| state | PrintJobState | true | 表示打印任务状态 |  
| subState | PrintJobSubState | true | 表示打印任务子状态 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步更新打印任务状态之后的回调 |  
| Promise<void> | 更新打印任务状态完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
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
更新打印扩展状态  
 **调用形式：**     
    
- updateExtensionInfo(info: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateExtensionInfo(info: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | string | true | 表示打印扩展变更信息  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步更新打印扩展状态之后的回调 |  
| Promise<void> | 更新打印扩展状态完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let info : string = 'WIFI_INACTIVE';  
print.updateExtensionInfo(info).then((data : void) => {  
    console.log('update print job state data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('update print job state error : ' + JSON.stringify(error));  
})  
    
```    
  
    
## queryAllPrintJobs    
查询所有打印任务  
 **调用形式：**     
    
- queryAllPrintJobs(callback: AsyncCallback\<void>): void    
起始版本： 10    
- queryAllPrintJobs(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.MANAGE_PRINT_JOB    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步查询所有打印任务之后的回调 |  
| Promise<void> | 查询所有打印任务完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
print.queryAllPrintJobs((err: BusinessError, data : void) => {  
    if (err) {  
        console.log('queryAllPrintJobs failed, because : ' + JSON.stringify(err));  
    } else {  
        console.log('queryAllPrintJobs success, data : ' + JSON.stringify(data));  
    }  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
print.queryAllPrintJobs().then((data : void) => {  
    console.log('queryAllPrintJobs success, data : ' + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
    console.log('queryAllPrintJobs failed, error : ' + JSON.stringify(error));  
})  
    
```    
  
