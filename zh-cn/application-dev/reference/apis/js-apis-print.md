# @ohos.print (打印)

该模块为基本打印的操作API，提供调用基础打印功能的接口。

> **说明：**  
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import print from '@ohos.print';
```

## PrintTask

打印任务完成后的事件监听回调接口类

### on

on(type: 'block', callback: Callback&lt;void&gt;): void

注册打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 注册监听，<br/>监听字段：block，<br/>表示打印阻塞 |
| callback | Callback&lt;void&gt; | 是 | 打印完成后处于响应状态的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.on('block', () => {
        console.log('print state is block');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### on

on(type: 'succeed', callback: Callback&lt;void&gt;): void

注册打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 注册监听，<br/>监听字段：succeed，<br/>表示打印成功 |
| callback | Callback&lt;void&gt; | 是 | 打印完成后处于响应状态的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.on('succeed', () => {
        console.log('print state is succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### on

on(type: 'fail', callback: Callback&lt;void&gt;): void

注册打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 注册监听，<br/>监听字段：fail，<br/>表示打印失败 |
| callback | Callback&lt;void&gt; | 是 | 打印完成后处于响应状态的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.on('fail', () => {
        console.log('print state is fail');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### on

on(type: 'cancel', callback: Callback&lt;void&gt;): void

注册打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 注册监听，<br/>监听字段：cancel，<br/>表示打印取消 |
| callback | Callback&lt;void&gt; | 是 | 打印完成后处于响应状态的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.on('cancel', () => {
        console.log('print state is cancel');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### off

off(type: 'block', callback?: Callback&lt;void&gt;): void

取消打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听，<br/>监听字段：block，<br/>表示打印阻塞 |
| callback | Callback&lt;void&gt; | 否 | 取消相应状态监听成功后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.off('block', () => {
        console.log('unregister state block');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### off

off(type: 'succeed', callback?: Callback&lt;void&gt;): void

取消打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听，<br/>监听字段：succeed，<br/>表示打印成功 |
| callback | Callback&lt;void&gt; | 否 | 取消相应状态监听成功后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.off('succeed', () => {
        console.log('unregister state succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### off

off(type: 'fail', callback?: Callback&lt;void&gt;): void

取消打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听，<br/>监听字段：fail，<br/>表示打印失败 |
| callback | Callback&lt;void&gt; | 否 | 取消相应状态监听成功后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.off('fail', () => {
        console.log('unregister state fail');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

### off

off(type: 'cancel', callback?: Callback&lt;void&gt;): void

取消打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听，<br/>监听字段：cancel，<br/>表示打印取消 |
| callback | Callback&lt;void&gt; | 否 | 取消相应状态监听成功后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.off('cancel', () => {
        console.log('unregister state cancel');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

## PrintDocumentAdapter<sup>11+</sup>

第三方应用程序实现此接口来渲染要打印的文件

### onStartLayoutWrite

onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number, writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void

实现这个接口来更新要打印文件，使用writeResultCallback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| oldAttrs | PrintAttributes | 是 | 表示旧打印参数 |
| newAttrs | PrintAttributes | 是 | 表示新打印参数 |
| fd | number | 是 | 表示文件描述符 |
| writeResultCallback | (jobId: string, writeResult: PrintFileCreationState) | 是 | 表示更新要打印的文件完成后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

class MyPrintDocumentAdapter implements print.PrintDocumentAdapter {
    onStartLayoutWrite(jobId: string, oldAttrs: print.PrintAttributes, newAttrs: print.PrintAttributes, fd: number,
        writeResultCallback: (jobId: string, writeResult: print.PrintFileCreationState) => void) {
        writeResultCallback(jobId, print.PrintFileCreationState.PRINT_FILE_CREATED);
    };
    onJobStateChanged(jobId: string, state: print.PrintDocumentAdapterState) {
        if (state == print.PrintDocumentAdapterState.PREVIEW_DESTROY) {
            console.log('PREVIEW_DESTROY');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_SUCCEED) {
            console.log('PRINT_TASK_SUCCEED');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_FAIL) {
            console.log('PRINT_TASK_FAIL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_CANCEL) {
            console.log('PRINT_TASK_CANCEL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_BLOCK) {
            console.log('PRINT_TASK_BLOCK');
        }
    }
}
```

### onJobStateChanged

onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void

实现这个接口来监听打印任务状态的改变。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobId | string | 是 | 表示打印任务ID |
| state | PrintDocumentAdapterState | 是 | 表示打印任务更改为该状态 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

class MyPrintDocumentAdapter implements print.PrintDocumentAdapter {
    onStartLayoutWrite(jobId: string, oldAttrs: print.PrintAttributes, newAttrs: print.PrintAttributes, fd: number,
        writeResultCallback: (jobId: string, writeResult: print.PrintFileCreationState) => void) {
        writeResultCallback(jobId, print.PrintFileCreationState.PRINT_FILE_CREATED);
    };
    onJobStateChanged(jobId: string, state: print.PrintDocumentAdapterState) {
        if (state == print.PrintDocumentAdapterState.PREVIEW_DESTROY) {
            console.log('PREVIEW_DESTROY');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_SUCCEED) {
            console.log('PRINT_TASK_SUCCEED');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_FAIL) {
            console.log('PRINT_TASK_FAIL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_CANCEL) {
            console.log('PRINT_TASK_CANCEL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_BLOCK) {
            console.log('PRINT_TASK_BLOCK');
        }
    }
}
```

## print

print(files: Array&lt;string&gt;, callback: AsyncCallback&lt;PrintTask&gt;): void

打印接口，传入文件进行打印，使用callback异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp） |
| callback | AsyncCallback&lt;PrintTask&gt; | 是 | 异步获取打印完成之后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入id
//let file = ['fd://1', 'fd://2'];
print.print(file, (err: BusinessError, printTask: print.PrintTask) => {
    if (err) {
        console.log('print err ' + JSON.stringify(err));
    } else {
        printTask.on('succeed', () => {
            console.log('print state is succeed');
        })
        // ...
    }
})
```

## print

print(files: Array&lt;string&gt;): Promise&lt;PrintTask&gt;

打印接口，传入文件进行打印，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp） |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | 打印完成结果 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入id
//let file = ['fd://1', 'fd://2'];
print.print(file).then((printTask: print.PrintTask) => {
    printTask.on('succeed', () => {
        console.log('print state is succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

## print<sup>11+</sup>

print(files: Array&lt;string&gt;, context: Context, callback: AsyncCallback&lt;PrintTask&gt;): void

打印接口，传入文件进行打印，使用callback异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp） |
| context | Context | 是 | 用于启动打印的UIAbilityContext |
| callback | AsyncCallback&lt;PrintTask&gt; | 是 | 异步获取打印完成之后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入id
//let file = ['fd://1', 'fd://2'];
let context = getContext(this);
print.print(file, context, (err: BusinessError, printTask: print.PrintTask) => {
    if (err) {
        console.log('print err ' + JSON.stringify(err));
    } else {
        printTask.on('succeed', () => {
            console.log('print state is succeed');
        })
        // ...
    }
})
```

## print<sup>11+</sup>

print(files: Array&lt;string&gt;, context: Context): Promise&lt;PrintTask&gt;

打印接口，传入文件进行打印，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp） |
| context | Context | 是 | 用于启动打印的UIAbilityContext |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | 打印完成结果 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入id
//let file = ['fd://1', 'fd://2'];
let context = getContext(this);
print.print(file, context).then((printTask: print.PrintTask) => {
    printTask.on('succeed', () => {
        console.log('print state is succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

## print<sup>11+</sup>

print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes, context: Context): Promise&lt;PrintTask&gt;

打印接口，传入文件进行打印，三方应用需要更新打印文件，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobName | string | 是 | 表示待打印文件名称 |
| printAdapter | Context | 是 | 表示三方应用实现的功能 |
| printAttributes | PrintAttributes | 是 | 表示打印参数 |
| context | Context | 是 | 用于启动打印的UIAbilityContext |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | 打印完成结果 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let jobName : string = "jobName";
let printAdapter : print.PrintDocumentAdapter;
let printAttributes : print.PrintAttributes = {
    copyNumber: 1,
    pageRange: {
        startPage: 0,
        endPage: 5,
        pages: []
    },
    pageSize: print.PrintPageType.PAGE_ISO_A3,
    directionMode: print.PrintDirectionMode.DIRECTION_MODE_AUTO,
    colorMode: print.PrintColorMode.COLOR_MODE_MONOCHROME,
    duplexMode: print.PrintDuplexMode.DUPLEX_MODE_NONE
}
let context = getContext();

print.print(jobName, printAdapter, printAttributes, context).then((printTask: print.PrintTask) => {
    printTask.on('succeed', () => {
        console.log('print state is succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.log('print err ' + JSON.stringify(error));
})
```

## PrintAttributes<sup>11+</sup>

定义打印参数的接口

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| copyNumber | number | 否 | 表示文件列表副本 |
| pageRange | PrinterRange | 否 | 表示待打印文件的范围 |
| pageSize | PrintPageSize \| PrintPageType | 否 | 表示代打印文件的页面大小 |
| directionMode | PrintDirectionMode | 否 | 表示待打印文件的方向 |
| colorMode | PrintColorMode | 否 | 表示待打印文件的色彩模式 |
| duplexMode | PrintDuplexMode | 否 | 表示待打印文件的单双面模式 |

## PrintMargin

定义打印页边距的接口

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| top | number | 否 | 表示页面上边距 |
| bottom | number | 否 | 表示页面下边距 |
| left | number | 否 | 表示页面左边距 |
| right | number | 否 | 表示页面右边距 |

## PrinterRange<sup>11+</sup>

定义打印范围的接口

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| startPage | number | 否 | 表示起始页 |
| endPage | number | 否 | 表示结束页 |
| pages | Array&lt;number&gt; | 否 | 表示离散页面 |

## PreviewAttribute

定义打印预览属性的接口

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| previewRange | PrinterRange | 是 | 表示预览页面范围 |
| result | number | 否 | 表示预览文件结果 |

## PrintResolution

定义打印分辨率的接口

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| id | string | 是 | 表示分辨率ID |
| horizontalDpi | number | 是 | 表示水平DPI |
| verticalDpi | number | 是 | 表示垂直DPI |

## PrintPageSize<sup>11+</sup>

定义打印页面尺寸的接口

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| id | string | 是 | 表示页面尺寸ID |
| name | string | 是 | 表示页面尺寸名称 |
| width | number | 是 | 表示页面宽度，单位：毫米 |
| height | number | 是 | 表示页面高度，单位：毫米 |

## PrinterCapability

定义打印能力的接口

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

定义打印信息的接口

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

定义打印任务的接口

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

## PrintDirectionMode<sup>11+</sup>

打印纸张方向的枚举

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| DIRECTION_MODE_AUTO | 0 | 表示自动选择纸张方向 |
| DIRECTION_MODE_PORTRAIT | 1 | 表示纵向打印 |
| DIRECTION_MODE_LANDSCAPE | 2 | 表示横向打印 |

## PrintColorMode<sup>11+</sup>

打印色彩模式的枚举

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| COLOR_MODE_MONOCHROME | 0 | 表示黑白打印 |
| COLOR_MODE_COLOR | 1 | 表示彩色打印 |

## PrintDuplexMode<sup>11+</sup>

打印单双面模式的枚举

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| DUPLEX_MODE_NONE | 0 | 表示单面打印 |
| DUPLEX_MODE_LONG_EDGE | 1 | 表示双面打印长边翻转 |
| DUPLEX_MODE_SHORT_EDGE | 2 | 表示双面打印短边翻转 |

## PrintPageType<sup>11+</sup>

打印纸张类型的枚举

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PAGE_ISO_A3 | 0 | 表示A3 |
| PAGE_ISO_A4 | 1 | 表示A4 |
| PAGE_ISO_A5 | 2 | 表示A5 |
| PAGE_JIS_B5 | 3 | 表示B5 |
| PAGE_ISO_C5 | 4 | 表示C5 |
| PAGE_ISO_DL | 5 | 表示DL |
| PAGE_LETTER | 6 | 表示Letter |
| PAGE_LEGAL | 7 | 表示Legal |
| PAGE_PHOTO_4X6 | 8 | 表示4x6相纸 |
| PAGE_PHOTO_5X7 | 9 | 表示5x7相纸 |
| PAGE_INT_DL_ENVELOPE | 10 | 表示INT DL ENVELOPE |
| PAGE_B_TABLOID | 11 | 表示B Tabloid |

## PrintDocumentAdapterState<sup>11+</sup>

打印任务状态的枚举

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PREVIEW_DESTROY | 0 | 表示预览失败 |
| PRINT_TASK_SUCCEED | 1 | 表示打印任务成功 |
| PRINT_TASK_FAIL | 2 | 表示打印任务失败 |
| PRINT_TASK_CANCEL | 3 | 表示打印任务取消 |
| PRINT_TASK_BLOCK | 4 | 表示打印任务阻塞 |

## PrintFileCreationState<sup>11+</sup>

打印文件创建状态的枚举

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PRINT_FILE_CREATED | 0 | 表示打印文件创建成功 |
| PRINT_FILE_CREATION_FAILED | 1 | 表示打印文件创建失败|
| PRINT_FILE_CREATED_UNRENDERED | 2 | 表示打印文件创建成功但未渲染 |

## PrinterState

打印机状态的枚举

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PRINTER_ADDED | 0 | 表示新打印机到达 |
| PRINTER_REMOVED | 1 | 表示打印机丢失 |
| PRINTER_CAPABILITY_UPDATED | 2 | 表示打印机更新 |
| PRINTER_CONNECTED | 3 | 表示打印机已连接 |
| PRINTER_DISCONNECTED | 4 | 表示打印机已断开连接 |
| PRINTER_RUNNING | 5 | 表示打印机正在运行 |

## PrintJobState

打印任务状态的枚举

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PRINT_JOB_PREPARE | 0 | 表示打印任务的初始状态 |
| PRINT_JOB_QUEUED | 1 | 表示打印任务传送到打印机 |
| PRINT_JOB_RUNNING | 2 | 表示执行打印任务|
| PRINT_JOB_BLOCKED | 3 | 表示打印任务已被阻止 |
| PRINT_JOB_COMPLETED | 4 | 表示打印任务完成 |

## PrintJobSubState

打印任务子状态的枚举

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PRINT_JOB_COMPLETED_SUCCESS | 0 | 表示打印任务成功 |
| PRINT_JOB_COMPLETED_FAILED | 1 | 表示打印任务失败 |
| PRINT_JOB_COMPLETED_CANCELLED | 2 | 表示打印任务已取消|
| PRINT_JOB_COMPLETED_FILE_CORRUPTED | 3 | 表示打印任务已损坏 |
| PRINT_JOB_BLOCK_OFFLINE | 4 | 表示打印处于离线状态 |
| PRINT_JOB_BLOCK_BUSY | 5 | 表示打印被其他进程占用 |
| PRINT_JOB_BLOCK_CANCELLED | 6 | 表示打印任务已取消 |
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
| PRINT_JOB_BLOCK_ACCOUNT_ERROR<sup>11+</sup> | 18 | 表示打印账户时出错 |
| PRINT_JOB_BLOCK_PRINT_PERMISSION_ERROR<sup>11+</sup> | 19 | 表示打印许可异常 |
| PRINT_JOB_BLOCK_PRINT_COLOR_PERMISSION_ERROR<sup>11+</sup> | 20 | 表示彩色打印权限异常 |
| PRINT_JOB_BLOCK_NETWORK_ERROR<sup>11+</sup> | 21 | 表示设备未连接到网络 |
| PRINT_JOB_BLOCK_SERVER_CONNECTION_ERROR<sup>11+</sup> | 22 | 表示无法连接服务器 |
| PRINT_JOB_BLOCK_LARGE_FILE_ERROR<sup>11+</sup> | 23 | 表示打印大文件异常 |
| PRINT_JOB_BLOCK_FILE_PARSING_ERROR<sup>11+</sup> | 24 | 表示文件分析异常 |
| PRINT_JOB_BLOCK_SLOW_FILE_CONVERSION<sup>11+</sup> | 25 | 表示文件转换太慢 |
| PRINT_JOB_RUNNING_UPLOADING_FILES<sup>11+</sup> | 26 | 表示正在上传文件 |
| PRINT_JOB_RUNNING_CONVERTING_FILES<sup>11+</sup> | 27 | 表示正在转换文件 |
| PRINT_JOB_BLOCK_UNKNOWN | 99 | 表示打印未知问题 |

## PrintErrorCode

打印错误代码的枚举

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| E_PRINT_NONE | 0 | 表示没有错误 |
| E_PRINT_NO_PERMISSION | 201 | 表示没有许可 |
| E_PRINT_INVALID_PARAMETER | 401 | 表示无效的参数|
| E_PRINT_GENERIC_FAILURE | 13100001 | 表示一般打印失败 |
| E_PRINT_RPC_FAILURE | 13100002 | 表示RPC失败 |
| E_PRINT_SERVER_FAILURE | 13100003 | 表示打印服务失败 |
| E_PRINT_INVALID_EXTENSION | 13100004 | 表示打印扩展无效 |
| E_PRINT_INVALID_PRINTER | 13100005 | 表示打印机无效 |
| E_PRINT_INVALID_PRINT_JOB | 13100006 | 表示打印任务无效 |
| E_PRINT_FILE_IO | 13100007 | 表示文件输入/输出错误 |

## PrinterExtensionInfo

定义打印扩展信息的接口

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

**示例：**

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

**示例：**

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

**示例：**

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

## startDiscoverPrinter

startDiscoverPrinter(extensionList: Array&lt;string&gt;): Promise&lt;void&gt;

加载特定的打印机扩展并开始发现打印机，使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 加载特定的打印机扩展并开始发现打印机完成结果 |

**示例：**

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

stopDiscoverPrinter(callback: AsyncCallback&lt;void&gt;): void

停止发现具有特定打印机扩展的打印机，使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 异步停止发现具有特定打印机扩展的打印机之后的回调 |

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

```ts
import print from '@ohos.print';
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

**示例：**

```ts
import print from '@ohos.print';
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

**示例：**

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

**示例：**

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

**示例：**

```ts
import print from '@ohos.print';

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

**示例：**

```ts
import print from '@ohos.print';
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

**示例：**

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

**示例：**

```ts
import print from '@ohos.print';

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

**示例：**

```ts
import print from '@ohos.print';

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

**示例：**

```ts
import print from '@ohos.print';

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

**示例：**

```ts
import print from '@ohos.print';

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

**示例：**

```ts
import print from '@ohos.print';

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

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

**示例：**

```ts
import print from '@ohos.print';
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

**示例：**

```ts
import print from '@ohos.print';
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

**示例：**

```ts
import print from '@ohos.print';
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

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.queryPrintJobById(jobId, (err: BusinessError, printJob : PrintJob) => {
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

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.queryPrintJobById(jobId).then((printJob : PrintJob) => {
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

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let jobId : string= '1';
class MyPrintAttributes implements print.PrintAttributes {
    copyNumber?: number;
    pageRange?: print.PrinterRange;
    pageSize?: print.PrintPageSize | print.PrintPageType;
    directionMode?: print.PrintDirectionMode;
    colorMode?: print.PrintColorMode;
    duplexMode?: print.PrintDuplexMode;
}

class MyPrinterRange implements print.PrinterRange {
    startPage?: number;
    endPage?: number;
    pages?: Array<number>;
}

class MyPrintPageSize implements print.PrintPageSize {
    id: string;
    name: string;
    width: number;
    height: number;
}

let printAttributes = new MyPrintAttributes();
printAttributes.copyNumber = 2;
printAttributes.pageRange = new MyPrinterRange();
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

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
let type : string = 'spooler_closed_for_started';
print.notifyPrintService(jobId, type).then((data : void) => {
    console.log('queryPrintJobById data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('queryPrintJobById error : ' + JSON.stringify(error));
})
```