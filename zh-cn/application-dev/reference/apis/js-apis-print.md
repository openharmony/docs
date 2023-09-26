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

on(type: 'block' | 'succeed' | 'fail' | 'cancel', callback: Callback&lt;void&gt;): void

注册打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 注册监听，<br/>可选监听字段：block/succeed/fail/cancel <br/>依次表示打印：阻塞/成功/失败/取消 |
| callback| Callback&lt;void&gt; | 是 | 打印完成后处于相应状态的回调 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;PrintTask&gt; | 打印完成结果 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
  printTask.on('succeed', () => {
    console.log('print state is succeed');
  })
  printTask.on('block', () => {
    console.log('print state is block');
  })
  printTask.on('succeed', () => {
    console.log('print state is succeed');
  })
  printTask.on('fail', () => {
    console.log('print state is fail');
  })
  printTask.on('cancel', () => {
    console.log('print state is cancel');
  })
  // ...
}).catch((error: BusinessError) => {
  console.log('print err ' + JSON.stringify(error));
})
```

### off

off(type: 'block' | 'succeed' | 'fail' | 'cancel', callback?: Callback&lt;void&gt;): void

取消打印完成后的监听，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听，<br/>可选监听字段：block/succeed/fail/cancel <br/>依次表示打印：阻塞/成功/失败/取消 |
| callback| Callback&lt;void&gt; | 否 | 取消相应状态监听成功后的回调 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;PrintTask&gt; | 打印完成结果 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
  printTask.off('succeed', () => {
    console.log('unregister state succeed');
  })
  printTask.off('block', () => {
    console.log('unregister state block');
  })
  printTask.off('succeed', () => {
    console.log('unregister state succeed');
  })
  printTask.off('fail', () => {
    console.log('unregister state fail');
  })
  printTask.off('cancel', () => {
    console.log('unregister state cancel');
  })
  // ...
}).catch((error: BusinessError) => {
  console.log('print err ' + JSON.stringify(error));
})
```

## print

print(files: Array&lt;string&gt;, callback: AsyncCallback&lt;PrintTask&gt;): void

打印接口，传入文件进行打印，使用callbak异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | 是 | 待打印文件列表，仅支持图片和pdf |
| callback| AsyncCallback&lt;PrintTask&gt; | 是 | 异步获取打印完成之后的回调 |

**示例：**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

//传入文件的uri
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
// 或者传入fd
// let file = ['fd://1', 'fd://2'];
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
| file | Array&lt;string&gt; | 是 | 待打印文件列表，仅支持图片和pdf |

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
// 或者传入fd
// let file = ['fd://1', 'fd://2'];
print.print(file).then((printTask: print.PrintTask) => {
  printTask.on('succeed', () => {
    console.log('print state is succeed');
  })
  // ...
}).catch((error: BusinessError) => {
  console.log('print err ' + JSON.stringify(error));
})
```