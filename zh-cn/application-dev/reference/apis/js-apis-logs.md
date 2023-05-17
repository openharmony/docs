# console (日志打印)

本模块提供基础的日志打印能力，支持按照日志级别打印日志信息。

如果需要使用更高级的日志打印服务，比如按照指定标识筛选日志内容，推荐使用[`@ohos.hilog`](js-apis-hilog.md)。

> **说明：**
>
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## console.debug

debug(message: string): void

打印debug级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.log

log(message: string): void

打印debug级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.info

info(message: string): void

打印info级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.warn

warn(message: string): void

打印warn级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.error

error(message: string): void

打印error级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


**示例：**

```
export default {    
  clickConsole(){        
    var versionCode = 1;        
    console.info('Hello World. The current version code is ' + versionCode);        
    console.log(`versionCode: ${versionCode}`);        
    // 以下写法从API Version 6开始支持console.log('versionCode:%d.', versionCode);    
  }
}
```

在DevEco Studio的底部，切换到“HiLog”窗口。选择当前的设备及进程，日志级别选择Info，搜索内容设置为“Hello World”。此时窗口仅显示符合条件的日志，效果如图所示：

![zh-cn_image_0000001200913929](figures/zh-cn_image_0000001200913929.png)

## console.assert<sup>10+</sup>

assert(value?: Object, ...arguments: Object[]): void

若value为假，打印后续内容。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| value | Object | 否    | 值 |
| arguments | Object | 否    | 错误消息打印。 |

**示例：**
```
console.assert(true, 'does nothing');

console.assert(false, 'console %s work', 'didn\'t');
// Assertion console:ohos didn't work

console.assert();
// Assertion failed
```
## console.count<sup>10+</sup>

count(label?: string): void

维护一个内部计数器, 并输出调用label的console.count()次数。默认值为'default'。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计数器标签名。 |

**示例：**
```
console.count()
// default: 1
console.count('default')
// default: 2
console.count('abc')
// abc: 1
console.count('xyz')
// xyz: 1
console.count('abc')
abc: 2
console.count()
// default: 3
```

## console.countReset<sup>10+</sup>

countReset(label?: string): void

清除label名的计数。默认值为'default'。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计数器标签名。 |

**示例：**
```
console.count('abc');
// abc: 1
console.countReset('abc');
console.count('abc');
// abc: 1
```

## console.dir<sup>10+</sup>

dir(dir?: Object): void

打印对象内容。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| dir | Object | 否    | 需要打印内容的对象。 |

## console.dirxml<sup>10+</sup>

dirxml(...arguments: Object[]): void 

此方法调用 console.log() 将接收到的参数传给它。此方法不会产生任何 XML 格式。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 要打印的信息。 |

## console.group<sup>10+</sup>

group(...arguments: Object[]): void

将后续行的缩进增加 groupIndentation 长度的空格。
如果提供需要打印的信息，首先先打印信息，没有额外的缩进。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 要打印的信息。 |
## console.groupCollapsed<sup>10+</sup>

groupCollapsed(...arguments: Object[]): void

group的别名。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 要打印的信息。|

## console.groupEnd<sup>10+</sup>

groupEnd(): void

将后续行的缩进减少 groupIndentation 长度的空格。

**系统能力：** SystemCapability.Utils.Lang

## console.table<sup>10+</sup>

table(tableData?: Object): void

以表格形式打印数据。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| tableData | Object | 否    | 要打印为表格形式的对象。 |

**示例：**
```
console.table([1, 2, 3]);
// ┌─────────┬────────┐
// │ (index) │ Values │
// ├─────────┼────────┤
// │    0    │   1    │
// │    1    │   2    │
// │    2    │   3    │ 
// └─────────┴────────┘

console.table({ a: [1, 2, 3, 4, 5], b: 5, c: { e: 5 } });

// ┌─────────┬───┬───┬───┬───┬───┬───┬────────┐
// │ (index) │ 0 │ 1 │ 2 │ 3 │ 4 │ e │ Values │
// ├─────────┼───┼───┼───┼───┼───┼───┼────────┤
// │    a    │ 1 │ 2 │ 3 │ 4 │ 5 │   │        │
// │    b    │   │   │   │   │   │   │   5    │
// │    c    │   │   │   │   │   │ 5 │        │
// └─────────┴───┴───┴───┴───┴───┴───┴────────┘
```
## console.time<sup>10+</sup>

time(label?: string): void

启动可用于计算操作持续时间的计时器。默认值为'default'。可使用console.timeEnd()关闭计时器并打印结果。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计时器标识。 |

## console.timeEnd<sup>10+</sup>

timeEnd(label?: string): void

停止之前通过调用 console.time() 启动的计时器并将结果打印。默认值为'default'。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计时器标识。 |

**示例：**
```
console.time('abc');
console.timeEnd('abc');
// abc: 225.438ms
```

## console.timeLog<sup>10+</sup>

timeLog(label?: string, ...arguments: Object[]): void

对于先前通过调用 console.time() 启动的计时器，打印经过时间和其他 data 参数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计时器标识。 |
| arguments | Object | 否    | 需要打印的其他日志。 |

**示例：**
```
console.time('timer1');
const value = aaa(); // 返回 17
console.timeLog('timer1', value);
// timer1: 365.227ms 17
console.timeEnd('timer1');
// timer1: 513.22ms
```

## console.trace<sup>10+</sup>

trace(...arguments: Object[]): void

打印当前堆栈。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 需要打印的其他日志。 |

**示例：**
```
console.trace();
console.trace("Show the trace");
```