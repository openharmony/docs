# Print

Print模块提供打印管理服务的能力，包括创建打印任务、发现打印机、启动/取消打印任务、查询打印机能力、查询打印预览等。

> **说明：**
> 
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```
import print from "@ohos.print";
```
## 系统能力

SystemCapability.Print.print

## 权限列表

| 权限                                       | 权限等级     | 描述               |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.PRINT | system_basic | 可创建打印任务 |
| ohos.permission.MANAGE_PRINT_JOB | system_basic | 可管理打印机及打印任务 |

## print.print

 print(files: Array<string>, callback: AsyncCallback\<PrintTask>): void;

创建打印任务（callback形式）。

**需要权限：**

ohos.permission.PRINT

**系统能力：**

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | files |Array<string> | 是 | 打印文件路径集合。 | 
  | callback  | AsyncCallback\<[PrintTask](#printTask) >   | 是    | 被指定的回调方法。      |

**示例：**
    
```js
let files: Array<string> = ['./data/app/sample.pdf'];
print.print(files,(err, task) => {
    task.on('blocked', () => {
        console.info("print task block")
    });
    task.on('success', () => {
        console.info("print task success")
    });
    task.on('failed', () => {
        console.info("print task fail")
    });
    task.on('cancelled', () => {
        console.info("print task cancel")
    });
});
  ```
## print.print

print(files: Array<string>): Promise\<PrintTask>;

创建打印任务（promise形式）。

**需要权限：**

ohos.permission.PRINT

**系统能力：**

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | files |Array<string> | 是 | 打印文件路径集合。 | 

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<[PrintTask](#printTask)> | 以Promise形式返回结果。 |


**示例：**
    
```js
let files: Array<string> = ['./data/app/sample.pdf'];
print.print(files).then((task) => {
    task.on('blocked', () => {
        console.info("print task block")
    });
    task.on('success', () => {
        console.info("print task success")
    });
    task.on('failed', () => {
        console.info("print task fail")
    });
    task.on('cancelled', () => {
        console.info("print task cancel")
    });
});
  ```

## print.queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(callback: AsyncCallback<Array\<PrinterExtensionInfo>>): void;

查询所有已安装的打印扩展（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力：**

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback  | AsyncCallback<Array\<[PrinterExtensionInfo](#printerExtensionInfo)>> | 是  | 被指定的回调方法。|

**示例：**
    
```js
 print.queryAllPrinterExtensionInfos((err,data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```

## print.queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(): Promise<Array\<PrinterExtensionInfo>>;

查询所有已安装的打印扩展（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力：**

SystemCapability.Print.print

**参数：**

无

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  |Promise<Array\<[PrinterExtensionInfo](#printerExtensionInfo)>>  | Promise形式返回已安装的打印扩展信息。      | 

**示例：**
    
```js
print.queryAllPrinterExtensionInfos()
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## print.startDiscoverPrinter

startDiscoverPrinter(extensionList: Array<string>, callback: AsyncCallback<boolean>): void;

发现打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | extensionList |  Array<string>| 否 | 扩展ID。|
  | callback  | AsyncCallback<boolean> | 是    | 被指定的回调方法。      | 

**示例：**
    
```js
let extensionList = ['1001','1002'];
print.startDiscoverPrinter(extensionList, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.startDiscoverPrinter

startDiscoverPrinter(extensionList: Array<string>): Promise<boolean>;

发现打印机（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | extensionList |  Array<string>| 否 | 扩展ID。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let extensionList  = ['1001','1002'];
print.startDiscoverPrinter(extensionList)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})

```

## print.stopDiscoverPrinter

stopDiscoverPrinter(callback: AsyncCallback<boolean>): void;

停止发现打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback  | AsyncCallback<boolean> | 是    | 被指定的回调方法。      | 

**示例：**
    
```js
print.stopDiscoverPrinter((err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```

## print.stopDiscoverPrinter

function stopDiscoverPrinter(): Promise<boolean>;

停止发现打印机（primise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

 无

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 


**示例：**
    
```js
print.stopDiscoverPrinter().then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```
## print.connectPrinter

connectPrinter(printerId: string, callback: AsyncCallback<boolean>): void;

发现打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId |  string| 是 | 打印机ID。|
  | callback  | AsyncCallback<boolean> | 是    | 被指定的回调方法。      | 

**示例：**
    
```js
let printerId  = '1001';
print.connectPrinter(printerId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.connectPrinter

 connectPrinter(printerId: string): Promise<boolean>;

发现打印机（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId |  string| 是 | 打印机ID。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let printerId  = '1001';
print.connectPrinter(printerId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})

```

## print.disconnectPrinter

disconnectPrinter(printerId: string, callback: AsyncCallback<boolean>): void;

断开连接打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId |  string| 是 | 打印机ID。|
  | callback  | AsyncCallback<boolean> | 是    | 被指定的回调方法。      | 

**示例：**
    
```js
let printerId  = '1001';
print.disconnectPrinter(printerId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.disconnectPrinter

disconnectPrinter(printerId: string): Promise<boolean>;

发现打印机（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId |  string| 是 | 打印机ID。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let printerId  = '1001';
print.disconnectPrinter(printerId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})

```
## print.queryPrinterCapability

queryPrinterCapability(printerId: string, callback: AsyncCallback\<PrinterCapability>): void;

查询打印机能力（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId |  string| 是 | 打印机ID。|
  | callback  | AsyncCallback\<[PrinterCapability](#printerCapability)> | 是    | 被指定的回调方法。      | 

**示例：**
    
```js
let printerId  = '1001';
print.queryPrinterCapability(printerId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```

## print.queryPrinterCapability

queryPrinterCapability(printerId: string): Promise<PrinterCapability>      

查询打印机能力（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId |  string| 是 | 打印机ID。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<[PrinterCapability](#printerCapability)>  | Promise形式返回打印机能力。      | 

**示例：**
    
```js
let printerId  = '1001';
print.queryPrinterCapability(printerId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})

```
## print.startPrintJob

startPrintJob(jobinfo: PrintJob, callback: AsyncCallback<boolean>): void;

启动打印任务（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobinfo |  [PrintJob](#PrintJob)| 是 | 打印任务。|
  | callback  |AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
let printerState = 1;
let printerRange = {
  startPage : 1,  // start page of sequence
  endPage : 4,  // end page of sequence
  pages : [1,4],  // discrete page of sequence
};
let printerPageSize = {
    id: '1',    // page size id
    name: 'string',  // page size name
    width: 200, // unit: milimeter
    height: 200,  // unit: milimeter
};
let printMargin = {
  top: 1,  // top margin
  bottom: 2,  // bottom margin
  left: 1,  // left side margin
  right: 1,  // right side margin
}
let previewAttribute = {
  previewRange: printerRange,  // preview page range
  result: 'string',        // preview file
}
let printJob = {
  files:['D:/dev/a.docx'],
  jobId:'1001',
  printerId: '2001',      // printer id to take charge of printing
  jobState: printerState,  // current print job state
  copyNumber: 3,      // copies of document list
  pageRange: printerRange,
  isSequential: false,    // sequential print
  pageSize: printerPageSize,  // the selected page size
  isLandscape: false,      // vertical printing
  colorMode: 1,      // color mode
  duplexMode: 1,    // duplex mode
  margin: printMargin,    // current margin setting
  preview: previewAttribute,  // preview setting
  option:''
}

print.startPrintJob(PrintJob, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.startPrintJob

startPrintJob(jobinfo: PrintJob): Promise<boolean>;      

启动打印任务（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobinfo |  [PrintJob](#PrintJob)| 是 | 打印任务。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let printerState = 1;
let printerRange = {
  startPage : 1,  // start page of sequence
  endPage : 4,  // end page of sequence
  pages : [1,4],  // discrete page of sequence
};
let printerPageSize = {
    id: '1',    // page size id
    name: 'string',  // page size name
    width: 200, // unit: milimeter
    height: 200,  // unit: milimeter
};
let printMargin = {
  top: 1,  // top margin
  bottom: 2,  // bottom margin
  left: 1,  // left side margin
  right: 1,  // right side margin
}
let previewAttribute = {
  previewRange: printerRange,  // preview page range
  result: 'string',        // preview file
}
let printJob = {
  files:['D:/dev/a.docx'],
  jobId:'1001',
  printerId: '2001',      // printer id to take charge of printing
  jobState: printerState,  // current print job state
  copyNumber: 3,      // copies of document list
  pageRange: printerRange,
  isSequential: false,    // sequential print
  pageSize: printerPageSize,  // the selected page size
  isLandscape: false,      // vertical printing
  colorMode: 1,      // color mode
  duplexMode: 1,    // duplex mode
  margin: printMargin,    // current margin setting
  preview: previewAttribute,  // preview setting
  option:'string'
}
 
print.startPrintJob(PrintJob).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```
## print.cancelPrintJob

cancelPrintJob(jobId: string, callback: AsyncCallback<boolean>): void;

取消打印任务（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobId |  string| 是 | jobid。|
  | callback  |AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
let jobId = 1;
print.cancelPrintJob(jobId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.cancelPrintJob

cancelPrintJob(jobinfo: PrintJob): Promise<boolean>;     

取消打印任务（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobinfo |  [PrintJob](#PrintJob)| 是 | 打印任务。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let jobId = 1;
print.cancelPrintJob(jobId).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```
## print.requestPrintPreview

requestPrintPreview(jobinfo: PrintJob, callback: (result: string) => void): void;

查询打印预览（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobinfo |  [PrintJob](#PrintJob)| 是 | 打印任务。|
  | callback  |(result: string) => void | 是    | 被指定的回调打印预览地址。      | 

**示例：**
    
```js
let printerState = 1;
let printerRange = {
  startPage : 1,  // start page of sequence
  endPage : 4,  // end page of sequence
  pages : [1,4],  // discrete page of sequence
};
let printerPageSize = {
    id: '1',    // page size id
    name: 'string',  // page size name
    width: 200, // unit: milimeter
    height: 200,  // unit: milimeter
};
let printMargin = {
  top: 1,  // top margin
  bottom: 2,  // bottom margin
  left: 1,  // left side margin
  right: 1,  // right side margin
}
let previewAttribute = {
  previewRange: printerRange,  // preview page range
  result: 'string',        // preview file
}
let printJob = {
  files:['D:/dev/a.docx'],
  jobId:'1001',
  printerId: '2001',      // printer id to take charge of printing
  jobState: printerState,  // current print job state
  copyNumber: 3,      // copies of document list
  pageRange: printerRange,
  isSequential: false,    // sequential print
  pageSize: printerPageSize,  // the selected page size
  isLandscape: false,      // vertical printing
  colorMode: 1,      // color mode
  duplexMode: 1,    // duplex mode
  margin: printMargin,    // current margin setting
  preview: previewAttribute,  // preview setting
  option:'string'
}

print.requestPrintPreview(printJob, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.requestPrintPreview

requestPrintPreview(jobinfo: PrintJob): Promise<string>;

查询打印预览（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobinfo |  [PrintJob](#PrintJob)| 是 | 打印任务。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<string>  | Promise形式返回的打印预览地址。      | 

**示例：**
    
```js
let printerState = 1;
let printerRange = {
  startPage : 1,  // start page of sequence
  endPage : 4,  // end page of sequence
  pages : [1,4],  // discrete page of sequence
};
let printerPageSize = {
    id: '1',    // page size id
    name: 'string',  // page size name
    width: 200, // unit: milimeter
    height: 200,  // unit: milimeter
};
let printMargin = {
  top: 1,  // top margin
  bottom: 2,  // bottom margin
  left: 1,  // left side margin
  right: 1,  // right side margin
}
let previewAttribute = {
  previewRange: printerRange,  // preview page range
  result: 'string',        // preview file
}
let printJob = {
  files:['D:/dev/a.docx'],
  jobId:'1001',
  printerId: '2001',      // printer id to take charge of printing
  jobState: printerState,  // current print job state
  copyNumber: 3,      // copies of document list
  pageRange: printerRange,
  isSequential: false,    // sequential print
  pageSize: printerPageSize,  // the selected page size
  isLandscape: false,      // vertical printing
  colorMode: 1,      // color mode
  duplexMode: 1,    // duplex mode
  margin: printMargin,    // current margin setting
  preview: previewAttribute,  // preview setting
  option:'string'
}
 
print.requestPrintPreview(printJob).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## print.on(type: 'printerStateChange')

on(type: 'printerStateChange', callback: (state: PrinterState, info: PrinterInfo) => void): void;

订阅打印机状态变化事件。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印状态的变化。|
  | callback  |(state: [PrinterState](#printerState), info: [PrinterInfo](#printerInfo)) => void | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
print.on('printerStateChange', (state, info) => {
    if (state == print.PrinterState.PRINTER_ADDED) {
        console.info("printer is added. info: " + JSON.stringify(info));
    }
    if (state == print.PrinterState.PRINTER_REMOVED) {
        console.info("printer is removed. info: " + JSON.stringify(info));
    }
    if (state == print.PrinterState.PRINTER_UPDATED) {
        console.info("printer is updated. info: " + JSON.stringify(info));
    }
    if (state == print.PrinterState.PRINTER_CONNECTED) {
        console.info("printer is connected. info: " + JSON.stringify(info));
    }
    if (state == print.PrinterState.PRINTER_DISCONNECTED) {
        console.info("printer is disConnected. info: " + JSON.stringify(info));
    }
    if (state == print.PrinterState.PRINTER_RUNNING) {
        console.info("printer is running. info: " + JSON.stringify(info));
    }
    if (state == print.PrinterState.PRINTER_UNKNOWN) {
        console.info("printer is unknown. info: " + JSON.stringify(info));
    }
});
```
## print.off(type: 'printerStateChange')

off(type: 'printerStateChange', callback: (boolean) => void): void;

取消订阅printerStateChange事件

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印状态的变化。|
  | callback  |boolean | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
print.off('printerStateChange', (err, data) => {
 console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});

```

## print.on('jobStateChange')

on(type: 'jobStateChange', callback: (state: PrintJobState, job: PrintJob) => void): void;

订阅打印任务状态变化事件。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印任务状态的变化。|
  | callback  |(state: [PrintJobState](#printJobState), job: [PrintJob](#printJob)) => void | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
print.on('jobStateChange', (state, info) => {
    if (state == print.PrintJobState.PRINT_JOB_PREPARE) {
        console.info("the print job is prepare. info:"+JSON.stringify(info));
    }
   if (state == print.PrintJobState.PRINT_JOB_QUEUED) {
       console.info("the print job is queued. info:"+JSON.stringify(info));
    }
   if (state == print.PrintJobState.PRINT_JOB_RUNNING) {
       console.info("the print job is running. info:"+JSON.stringify(info));
    }
   if (state == print.PrintJobState.PRINT_JOB_BLOCKED) {
       console.info("the print job is blocked. info:"+JSON.stringify(info));
    }
   if (state == print.PrintJobState.PRINT_JOB_COMPLETED) {
       console.info("the print job is completed. info:"+JSON.stringify(info));
    }
   if (state == print.PrintJobState.PRINT_JOB_UNKNOWN) {
      console.info("the print job is unknown. info:"+JSON.stringify(info));
    }
});
```
## print.off('jobStateChange')

 off(type: 'jobStateChange', callback?: (boolean) => void): void;

取消订阅printerStateChange事件

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印状态的变化。|
  | callback  |boolean | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
print.off('jobStateChange', (err, data) => {
 console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
}

```

## print.on('extInfoChange')

on(type: 'extInfoChange', callback: (extensionId: string, info: string) => void): void;

订阅打印任务子状态变化事件。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印任务状态的变化。|
  | callback  | (extensionId: string, info: string) => void| 是    | 被指定的回调结果。      | 

**示例：**
    
```js
print.on('extInfoChange', (extensionId, info) => {
     console.info("extInfoChange on. info:"+JSON.stringify(info));
});
```

## print.off('extInfoChange')

off(type: 'extInfoChange', callback?: (boolean) => void): void;

订阅打印任务子状态变化事件。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印任务状态的变化。|
  | callback  | (info: string) => void | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
print.off('extInfoChange', (info) => {
      console.info("extInfoChange off. info:"+JSON.stringify(info));
});
```

## print.addPrinters

addPrinters(printers: Array\<PrinterInfo>, callback: AsyncCallback<boolean>): void;

添加打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printers |  Array\<[PrinterInfo](#PrinterInfo)>| 是 | 打印机信息。|
  | callback |  AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
 
let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
 let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
 let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
  let printerCapability = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
 let printer1 = {
            printerId: '1001', // printer id
            printerName: '打印机2', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: '打印机1', // printer description
            capability: printerCapability,
            option: 'string'  
        }
 let printer2 = {
            printerId: '1002', // printer id
            printerName: '打印机1', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: '打印机2', // printer description
            capability: printerCapability,
            option: 'string'  
        }

 let printers = [printer1, printer2]
 print.addPrinters(printers, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.addPrinters

addPrinters(printers: Array<PrinterInfo>): Promise<boolean>;
  
添加打印机（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printers |  Array\<[PrinterInfo](#PrinterInfo)>| 是 | 打印机信息。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
  let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
 let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
 let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
  let printerCapability = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
 let printer1 = {
            printerId: '1001', // printer id
            printerName: '打印机2', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: '打印机1', // printer description
            capability: printerCapability,
            option: ''  
        }
 let printer2 = {
            printerId: '1002', // printer id
            printerName: '打印机1', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: '打印机2', // printer description
            capability: printerCapability,
            option: ''  
        }

 let printers = [printer1, printer2]
 print.addPrinters(printers).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
 }).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
 })
```

## print.removePrinters

removePrinters(printers: Array<PrinterInfo>, callback: AsyncCallback<boolean>): void;

删除打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printers |  Array\<[PrinterInfo](#PrinterInfo)>| 是 | 打印机信息。|
  | callback |  AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
  let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
 let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
 let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
  let printerCapability = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
 let printer1 = {
            printerId: '1001', // printer id
            printerName: '打印机2', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: '打印机1', // printer description
            capability: printerCapability,
            option: ''  
        }
 let printer2 = {
            printerId: '1002', // printer id
            printerName: '打印机1', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: '打印机2', // printer description
            capability: printerCapability,
            option: ''  
        }

 let printers = [printer1, printer2]
 print.removePrinters(printers, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.removePrinters

removePrinters(printers: Array<PrinterInfo>): Promise<boolean>;
  
删除打印机（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printers |  Array\<[PrinterInfo](#printerInfo)>| 是 | 打印机信息。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
 let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
 let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
 let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
  let printerCapability = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
 let printer1 = {
            printerId: '1001', // printer id
            printerName: '打印机2', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: '打印机1', // printer description
            capability: printerCapability,
            option: ''  
        }
 let printer2 = {
            printerId: '1002', // printer id
            printerName: '打印机1', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: '打印机2', // printer description
            capability: printerCapability,
            option: ''  
        }

 let printers = [printer1, printer2]
 print.removePrinters(printers).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
 }).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
 })
```

## print.updatePrinters

updatePrinters(printers: Array<PrinterInfo>, callback: AsyncCallback<boolean>): void;

更新打印机（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printers |  Array\<[PrinterInfo](#PrinterInfo)>| 是 | 打印机信息。|
  | callback |  AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
  let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
 let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
 let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
  let printerCapability = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
 let printer1 = {
            printerId: '1001', // printer id
            printerName: '打印机2', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: '打印机1', // printer description
            capability: printerCapability,
            option: ''  
        }
 let printer2 = {
            printerId: '1002', // printer id
            printerName: '打印机1', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: '打印机2', // printer description
            capability: printerCapability,
            option: ''  
        }

 let printers = [printer1, printer2]
 print.updatePrinters(printers, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.updatePrinters

updatePrinters(printers: Array<PrinterInfo>): Promise<boolean>;
  
更新打印机（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printers |  Array\<[PrinterInfo](#printerInfo)>| 是 | 打印机信息。|

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
 let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
 let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
 let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
  let printerCapability = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
 let printer1 = {
            printerId: '1001', // printer id
            printerName: '打印机2', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: '打印机1', // printer description
            capability: printerCapability,
            option: ''  
        }
 let printer2 = {
            printerId: '1002', // printer id
            printerName: '打印机1', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: '打印机2', // printer description
            capability: printerCapability,
            option: ''  
        }

 let printers = [printer1, printer2]
 print.updatePrinters(printers).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
 }).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
 })
```

## print.updatePrinterState

updatePrinterState(printerId: string, state: PrinterState,callback: AsyncCallback<boolean>): void;

更新打印机状态（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId | string| 是 | 打印机Id。|
  | state | [PrinterState](#printerState)| 是 | 打印机状态。|
  | callback |  AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
let printerId = '1002';
let printerState = 1;
print.updatePrinterState(printerId, printerState, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.updatePrinterState

 updatePrinterState(printerId: string, state: PrinterState): Promise<boolean>;
  
更新打印机状态（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId | string| 是 | 打印机Id。|
  | state | [PrinterState](#printerState)| 是 | 打印机状态。|
  
  

**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let printerId = 3;
let printerState = 1;
print.updatePrinterState(printerId,printerState).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```
## print.updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState, callback: AsyncCallback<boolean>): void;

更新打印任务状态（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobId | string| 是 | 打印任务Id。|
  | state | [PrintJobState](#printJobState)| 是 | 打印任务状态。|
  | subState | [PrintJobSubState](#printJobSubState)| 是 | 打印任务状态。|
  | callback |  AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
let jobId = '1002';
let printJobState = 1;
let printJobSubState =2;
print.updatePrintJobState(jobId, printJobState, printJobSubState, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState): Promise<boolean>;
  
更新打印任务状态（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
   | jobId | string| 是 | 打印任务Id。|
  | state | [PrintJobState](#printJobState)| 是 | 打印任务状态。|
  | subState | [PrintJobSubState](#printJobSubState)| 是 | 打印任务状态。|
 
**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let jobId = '1002';
let printJobState = 1;
let printJobSubState =2;
print.updatePrintJobState(jobId, printJobState, printJobSubState).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## print.updateExtensionInfo

updateExtensionInfo(info: string, callback: AsyncCallback<boolean>): void;

更新扩展信息（callback形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | info |string| 是 | 扩展信息。|
  | callback |  AsyncCallback<boolean> | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
let info = 'string';
print.updateExtensionInfo(info, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```
## print.updateExtensionInfo

updateExtensionInfo(info: string): Promise<boolean>;
  
更新扩展信息（promise形式）。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | extensionId | string| 是 | 扩展ID。|
  | info |string| 是 | 扩展信息。|
 
**返回值：**

  | 类型 |  说明 | 
  | -------- | -------- |
  | Promise<boolean>  | Promise形式返回执行结果。      | 

**示例：**
    
```js
let info = 'string';
print.updateExtensionInfo(info).then((data)=>{
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## PrintTask

 print接口创建打印任务的通知送信的callback接口

## PrintTask.on

on(type: 'blocked' | 'success' | 'failed' | 'cancelled', callback: () => void): void;

订阅打印任务状态变化事件。

**需要权限：**

ohos.permission.PRINT

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印任务状态的变化。|
  | callback  |() => void | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
   print.PrintTask.on('block', () => {
        console.info("print task block")
    });
    print.PrintTask.on('success', () => {
        console.info("print task success")
    });
    print.PrintTask.on('fail', () => {
        console.info("print task fail")
    });
    print.PrintTask.on('cancel', () => {
        console.info("print task cancel")
    });
 
  ```
## PrintTask.off
    
 off(type: 'blocked' | 'success' | 'failed' | 'cancelled', callback?: (boolean) => void): void;

取消订阅打印任务状态变化事件。

**需要权限：**

ohos.permission.MANAGE_PRINT_JOB

**系统能力**：

SystemCapability.Print.print

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | type | string| 是 | 监听打印任务状态的变化。|
  | callback  |() => void | 是    | 被指定的回调结果。      | 

**示例：**
    
```js
    print.PrintTask.off('block', () => {
        console.info("print task block")
    });
    print.PrintTask.off('success', () => {
        console.info("print task success")
    });
    print.PrintTask.off('fail', () => {
        console.info("print task fail")
    });
    print.PrintTask.off('cancel', () => {
        console.info("print task cancel")
    });

  ```

## PrintMargin

打印文件边距

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print


| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| top                | 只读   | number        | 否    | 上边距。                     |
| bottom                | 只读   | number        | 否    | 下边距。                     |
| left                | 只读   | number        | 否    | 左边距。                     |
| right                | 只读   | number        | 否    | 又边距。                     |

## PrinterRange

打印页范围

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| startPage                | 只读   | number        | 否    | 开始页。                     |
| endPage                | 只读   | number        | 否    | 结束页。                     |
| pages                | 只读   |  Array<number>        | 否    | 总页数。                     |

## PreviewAttribute

打印预览信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| previewRange                | 只读   | [PrinterRange](#printerRange)        | 是    | 打印范围。                     
| result                | 只读   | string        | 否    | 预览文件地址。                     |

## PrinterResolution

打印分辨率信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| id                | 只读   | string       | 是    | 分辨率ID。                     
| horizontalDpi                | 只读   | number        | 是    | 水平DPI。                     |
| verticalDpi                | 只读   | number        | 是    | 垂直DPI。                     |

## PrinterPageSize

打印长宽

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| id                | 只读   | string       | 是    | ID。                     
| name                | 只读   | string        | 是    | 名称。                     |
| width                | 只读   | number        | 是    | 宽度。                     |
| height                | 只读   | number        | 是    | 高度。                     |

## PrinterCapability

打印能力

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| colorMode                | 只读   | number        | 是    | 颜色模式。                     |
| duplexMode                | 只读   | number        | 是    | 双面模式。                     |
| pageSize                | 只读   |  Array<[PrinterPageSize](#printerPageSize)>       | 是    | 打印范围。|       
| resolution                | 只读   |  Array<[PrinterResolution](#printerResolution)>       | 否    | 分别率。|
| minMargin                | 只读   | [PrintMargin](#printMargin)        | 否    | 打印边距。        |  



## PrinterInfo

打印机信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| printerId                | 只读   |  string       | 是    | 打印机id。        |             
| printerName                | 只读   | string       | 是    | 打印机名称。|      
| printerState                | 只读   | [PrinterState](#PrinterState)         | 是    | 打印机状态。  |                   
| printerIcon                | 只读   |  number      | 否    | 打印机按钮。|
| description                | 只读   | string        | 否    | 打印机描述。                     |
| capability                | 只读   |  [PrinterCapability](#printerCapability)        | 否    | 打印机能力。   |
| option                | 只读   | string        | 否    | json对象。   |                  

## PrintJob

打印任务信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| files                | 只读   | Array<string>       | 是    | 打印文件路径。        |             
| jobId                | 只读   |  string       | 是    | 任务id。|                     
| printerId                | 只读   |  string       | 是    | 打印机。|
| jobState                | 只读   |  [PrintJobState](#printJobState)        | 是    | 任务状态。                     
| copyNumber                | 只读   | number        | 是    | 打印份数。                     |
| pageRange                | 只读   | [PrinterRange](#printerRange)       | 是    | 打印范围。   |
| isSequential                | 只读   | boolean       | 是    | 是否按顺序。                     |
| pageSize                | 只读   | [PrinterPageSize](#printerPageSize)         | 是    | 纸张大小。                     | isLandscape                | 只读   | boolean       | 是    | 是否垂直居中。    |
| colorMode                | 只读   | number        | 是    | 色彩模式。                     |
| duplexMode                | 只读   | number        | 是    | 双面模式。                     |
| margin                | 只读   |  [PrintMargin](#printMargin)        | 否    | 打印边距。                     |
| preview                | 只读   |  [PreviewAttribute](#previewAttribute)        | 否   | 预览设置。         |
| option                | 只读   | string        | 否    | json对象。   |   
     
## PrinterState

打印机状态枚举

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 变量                                  | 值        | 说明                                       |
| ------------------------------------ | ---------- | ---------------------------------------- |
| PRINTER_ADDED         | 0 | 打印机添加。                         |
| PRINTER_REMOVED       | 1 | 打印机删除。                         |
| PRINTER_UPDATE_CAP       | 2 | 打印机更新。                         |
| PRINTER_CONNECTED          | 3 | 打印机已连接。                               |
| PRINTER_DISCONNECTED      | 4 | 打印机断开连接。                  |
| PRINTER_RUNNING              | 5 |打印机运行终。                            |
                    
## PrintJobState

打印任务状态枚举

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 变量                                   | 值         | 说明                                       |
| ------------------------------------ | ---------- | ---------------------------------------- |
| PRINT_JOB_PREPARE        | 0 | 打印任务准备。                         |
| PRINT_JOB_QUEUED       | 1 | 开始打印任务。                         |
| PRINT_JOB_RUNNING          | 2 | 打印任务执行中。                               |
| PRINT_JOB_BLOCKED            | 3 | 打印任务阻塞。                  |
| PRINT_JOB_COMPLETED              | 4 | 打印任务完成。                            | 

## PrintJobSubState

打印任务子状态枚举

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 变量                                   | 值         | 说明                                       |
| ------------------------------------ | ---------- | ---------------------------------------- |
| PRINT_JOB_SUCCESS        | 0 | 打印任务成功。                         |
| PRINT_JOB_FAILED       | 1 | 打印任务失败。                         |
| PRINT_JOB_CANCELLED          | 2 | 打印任务取消。                               |
| PRINT_JOB_FILE_CORRUPT            | 3 | 已损坏。                  |
| PRINT_JOB_BLOCK_OFFLINE              | 4 | 打印任务离线。                            |
| PRINT_JOB_BLOCK_BUSY | 5 | 打印任务繁忙。|   
| PRINT_JOB_BLOCK_CANCELLED | 6 | 打印任务已取消。|   
| PRINT_JOB_BLOCK_OUT_OF_PAPER | 7 | 用纸量不足。|   
| PRINT_JOB_BLOCK_OUT_OF_INK | 8 | 墨水用完了。|   
| PRINT_JOB_BLOCK_OUT_OF_TONER | 9 | 碳粉用完。|   
| PRINT_JOB_BLOCK_JAMMED | 10 | 卡纸。|   
| PRINT_JOB_BLOCK_DOOR_OPEN | 11 | 盖子打开。|   
| PRINT_JOB_BLOCK_SERVICE_REQUEST | 12 | 服务请求。|   
| PRINT_JOB_BLOCK_LOW_ON_INK | 13 | 墨水不足。|   
| PRINT_JOB_BLOCK_LOW_ON_TONER | 14 | 碳粉不足。|   
| PRINT_JOB_BLOCK_REALLY_LOW_ON_INK | 15 | 墨水太少。|   
| PRINT_JOB_BLOCK_BAD_CERTIFICATE | 16 | 认证失败。|   
| PRINT_JOB_BLOCK_UNKNOWN | 17 | 未知状态。|   

## PrintErrorCode
打印错误码

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 变量                                   | 值         | 说明                                       |
| ------------------------------------ | ---------- | ---------------------------------------- |
| E_PRINT_NONE        | 0 |  成功。                         |
| E_PRINT_NO_PERMISSION       | 201 | 没有权限。                         |
| E_PRINT_INVALID_PARAMETER   |401| 参数错误。                               |
| E_PRINT_GENERIC_FAILURE            | 13100001 | 打印的一般故障。                  |
| E_PRINT_RPC_FAILURE              | 13100002 | RPC失败。                            |
| E_PRINT_SERVER_FAILURE | 13100003 | 打印服务失败。|   
| E_PRINT_INVALID_EXTENSION | 13100004 | 打印扩展名无效。|   
| E_PRINT_INVALID_PRINTER | 13100005 | 无效打印机。|   
| E_PRINT_INVALID_PRINTJOB | 13100006 | 打印作业无效。|   
| E_PRINT_FILE_IO | 13100007 |文件i/o错误。|   

## PrinterExtensionInfo
打印扩展信息,继承ExtensionAbilityInfo

**系统能力**：以下各项对应的系统能力均为SystemCapability.Print.print

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| extensionId                | 只读   | string      | 是    |打印机分机的扩展标识。        |             
| vendorId                | 只读   |  string       | 是    | 扩展的供应商id。|                     
| vendorName                | 只读   |  string       | 是    | 供应商名称。|
| vendorIcon                | 只读   |  number        | 是    | 供应商的资源id。|              
| version                | 只读   | string        | 是    | 当前打印机扩展的版本。                     |
 
# PrintExtensionAbility

PrintExtensionAbility模块提供PrintExtension打印扩展服务扩展相关接口的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  


## 导入模块

```
import PrintExtensionAbility from '@ohos.PrintExtension';
```

## 权限

无

## 属性

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。


## PrintExtensionAbility.onCreate

onCreate(want: Want): void;

Extension生命周期回调，在创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-application-Want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 | 

**示例：**

```js
class customPrintExtensionAbility extends PrintExtensionAbility {
    onCreate(want) {
      console.log('onCreate, want:' + want.abilityName);
    }
  }
```

## PrintExtensionAbility.onStartDiscoverPrinter

onStartDiscoverPrinter(): void;

Extension生命周期回调，在print.stopDiscoverPrinter调用时回调，执行发现打印机业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  无 

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
    onStartDiscoverPrinter() {
       console.log('start discover Printer');
    }
}
```
## PrintExtensionAbility.onStopDiscoverPrinter

onStopDiscoverPrinter(): void;

Extension生命周期回调，在print.stopDiscoverPrinter调用时回调，执行停止发现打印机业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  无 

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
    onStopDiscoverPrinter() {
       console.log('stop discover Printer');
    }
}
```
## PrintExtensionAbility.onConnectPrinter

onConnectPrinter(printerId: number): void;

Extension生命周期回调，在print.connectPrinter调用时回调，执行连接打印机业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId | number| 是 | 打印机id |

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
    onConnectPrinter(printerId) {
      console.log('connect to printer. printid:'+printerId)
    }
}
```

## PrintExtensionAbility.onDisconnectPrinter

onDisconnectPrinter(printerId: number): void;

Extension生命周期回调，在print.disconnectPrinter调用时回调，执行连接打印机业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId | number| 是 | 打印机id |

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
    onDisconnectPrinter(printerId) {
      console.log('disconnect to printer. printid:'+printerId)
    }
}
```

## PrintExtensionAbility.onStartPrintJob

onStartPrintJob(jobInfo: print.PrintJob): void;

Extension生命周期回调，在print.startPrintJob调用时回调，执行启动打印任务业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobInfo |  [PrintJob](printJob)  | 是 | 打印任务 |

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
     onStartPrintJob(jobInfo) {
       console.log('start print job. jobInfo:'+JSON.stringify(jobInfo))
    }
}
```

## PrintExtensionAbility.onCancelPrintJob

onCancelPrintJob(jobInfo: print.PrintJob): void;

Extension生命周期回调，在print.cancelPrintJob调用时回调，执行取消打印任务业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobInfo |  [PrintJob](printJob)  | 是 | 打印任务 |

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
     onCancelPrintJob(jobInfo) {
       console.log('cancel print job. jobInfo:'+JSON.stringify(jobInfo))
    }
}
```
## PrintExtensionAbility.onRequestPrinterCapability

onRequestPrinterCapability(printerId: number): print.PrinterCapability;

Extension生命周期回调，在print.queryPrinterCapability调用时回调，执行查询打印机能力业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | printerId | number  | 是 | 打印机id |

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
     onRequestPrinterCapability(printerId) {
      console.log('request printer capability. printerId:'+JSON.stringify(printerId))
      let printerPageSizeArr = [
            {
             id: '1',
             name: 'string',
             width: 200,
             height: 200,
            }
        ]
     let printMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
     let printerResolutionArr = [
            {
             id: 2,
             horizontalDpi: 2,
             verticalDpi: 1,
            }
        ]
     let cap = {
            minMargin: printMargin,
            pageSize: printerPageSizeArr,
            resolution: printerResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
     return cap;
    }
}
```

## PrintExtensionAbility.onRequestPreview

onRequestPreview(jobInfo: print.PrintJob): string;

Extension生命周期回调，在[print.requestPrintPreview](print.requestPrintPreview)调用时回调，执行查询打印预览业务逻辑操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | jobInfo |  [PrintJob](printJob)   | 是 | 打印任务 |

**示例：**

```js
  class customPrintExtensionAbility extends PrintExtensionAbility {
    onRequestPreview(jobInfo) {
       console.log('request preview. jobInfo:'+JSON.stringify(jobInfo))
       return '';
    }
}
```
## PrintExtensionAbility.onDestroy

onDestroy(): void;

Extension生命周期回调，在销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.Print.print

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

```js
   class customPrintExtensionAbility extends PrintExtensionAbility {
    onDestroy() {
      console.log('onDestroy');
    }
  }
```