# @ohos.print (打印)

该模块为基本打印的操作API，提供调用基础打印功能的接口。

> **说明：**  
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { print } from '@kit.BasicServicesKit';
```

## PrintTask

打印任务完成后的事件监听回调接口类。

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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

第三方应用程序实现此接口来渲染要打印的文件。

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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
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
| files | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp）和pdf。系统应用传入uri时，需先调用uriPermissionManager.grantUriPermission()接口给打印应用授权，此接口为系统接口。三方应用建议使用[print](#print11-2)。 |
| callback | AsyncCallback&lt;PrintTask&gt; | 是 | 异步获取打印完成之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let files = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入fd
//let files = ['fd://1', 'fd://2'];
print.print(files, (err: BusinessError, printTask: print.PrintTask) => {
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
| files | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp）和pdf。系统应用传入uri时，需先调用uriPermissionManager.grantUriPermission()接口给打印应用授权，此接口为系统接口。三方应用建议使用[print](#print11-2)。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | 打印完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let files = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入fd
//let files = ['fd://1', 'fd://2'];
print.print(files).then((printTask: print.PrintTask) => {
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
| files | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp）和pdf。系统应用传入uri时，需先调用uriPermissionManager.grantUriPermission()接口给打印应用授权，此接口为系统接口。三方应用建议使用[print](#print11-2)。 |
| context | Context | 是 | 用于启动打印的UIAbilityContext |
| callback | AsyncCallback&lt;PrintTask&gt; | 是 | 异步获取打印完成之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let files = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入fd
//let files = ['fd://1', 'fd://2'];
let context = getContext(this);
print.print(files, context, (err: BusinessError, printTask: print.PrintTask) => {
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
| files | Array&lt;string&gt; | 是 | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp）和pdf。系统应用传入uri时，需先调用uriPermissionManager.grantUriPermission()接口给打印应用授权，此接口为系统接口。三方应用建议使用[print](#print11-2)。 |
| context | Context | 是 | 用于启动打印的UIAbilityContext |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | 打印完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let files = ['file://data/print/a.png', 'file://data/print/b.png'];
//或者传入fd
//let files = ['fd://1', 'fd://2'];
let context = getContext(this);
print.print(files, context).then((printTask: print.PrintTask) => {
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
| printAdapter | PrintDocumentAdapter | 是 | 表示三方应用实现的功能 |
| printAttributes | PrintAttributes | 是 | 表示打印参数 |
| context | Context | 是 | 用于启动打印的UIAbilityContext |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | 打印完成结果 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobName : string = "jobName";
let printAdapter : print.PrintDocumentAdapter | null = null;
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

定义打印参数的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| copyNumber | number | 否 | 表示文件列表副本 |
| pageRange | PrintPageRange | 否 | 表示待打印文件的范围 |
| pageSize | PrintPageSize \| PrintPageType | 否 | 表示代打印文件的页面大小 |
| directionMode | PrintDirectionMode | 否 | 表示待打印文件的方向 |
| colorMode | PrintColorMode | 否 | 表示待打印文件的色彩模式 |
| duplexMode | PrintDuplexMode | 否 | 表示待打印文件的单双面模式 |

## PrintPageRange<sup>11+</sup>

定义打印范围的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| startPage | number | 否 | 表示起始页 |
| endPage | number | 否 | 表示结束页 |
| pages | Array&lt;number&gt; | 否 | 表示离散页面 |


## PrintPageSize<sup>11+</sup>

定义打印页面尺寸的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| id | string | 是 | 表示页面尺寸ID |
| name | string | 是 | 表示页面尺寸名称 |
| width | number | 是 | 表示页面宽度，单位：毫米 |
| height | number | 是 | 表示页面高度，单位：毫米 |



## PrintDirectionMode<sup>11+</sup>

打印纸张方向的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| DIRECTION_MODE_AUTO | 0 | 表示自动选择纸张方向 |
| DIRECTION_MODE_PORTRAIT | 1 | 表示纵向打印 |
| DIRECTION_MODE_LANDSCAPE | 2 | 表示横向打印 |

## PrintColorMode<sup>11+</sup>

打印色彩模式的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| COLOR_MODE_MONOCHROME | 0 | 表示黑白打印 |
| COLOR_MODE_COLOR | 1 | 表示彩色打印 |

## PrintDuplexMode<sup>11+</sup>

打印单双面模式的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| DUPLEX_MODE_NONE | 0 | 表示单面打印 |
| DUPLEX_MODE_LONG_EDGE | 1 | 表示双面打印长边翻转 |
| DUPLEX_MODE_SHORT_EDGE | 2 | 表示双面打印短边翻转 |

## PrintPageType<sup>11+</sup>

打印纸张类型的枚举。

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

打印任务状态的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PREVIEW_DESTROY | 0 | 表示预览失败 |
| PRINT_TASK_SUCCEED | 1 | 表示打印任务成功 |
| PRINT_TASK_FAIL | 2 | 表示打印任务失败 |
| PRINT_TASK_CANCEL | 3 | 表示打印任务取消 |
| PRINT_TASK_BLOCK | 4 | 表示打印任务阻塞 |

## PrintFileCreationState<sup>11+</sup>

打印文件创建状态的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| PRINT_FILE_CREATED | 0 | 表示打印文件创建成功 |
| PRINT_FILE_CREATION_FAILED | 1 | 表示打印文件创建失败|
| PRINT_FILE_CREATED_UNRENDERED | 2 | 表示打印文件创建成功但未渲染 |

