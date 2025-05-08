# Console (控制台)

本模块提供了一个简单的调试控制台，类似于浏览器提供的JavaScript控制台机制。

> **说明：**
>
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## console.debug

debug(message: string, ...arguments: any[]): void

以格式化输出方式打印调试信息。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |
| arguments | any[] | 否    | 表示其余要打印的信息或message的替换值。 |

**示例：**

```js
const number = 5;
console.debug('count: %d', number);  // 格式化输出替换message中的文本。
// count: 5 
console.debug('count:', number);  // 打印message以及其余信息
// count: 5 
console.debug('count:'); // 仅打印message
// count: 
```

## console.log

log(message: string, ...arguments: any[]): void

以格式化输出方式打印日志信息。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |
| arguments | any[] | 否    |表示其余要打印的信息或message的替换值。 |

**示例：**

```js
const number = 5;
console.log('count: %d', number);  // 格式化输出替换message中的文本。
// count: 5 
console.log('count:', number);  // 打印message以及其余信息
// count: 5 
console.log('count:'); // 仅打印message
// count: 
```

## console.info

info(message: string, ...arguments: any[]): void

以格式化输出方式打印日志信息。(console.log()的别名）。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |
| arguments | any[] | 否    | 表示其余要打印的信息或message的替换值。 |

**示例：**

```js
const number = 5;
console.info('count: %d', number);  // 格式化输出替换message中的文本。
// count: 5 
console.info('count:', number);  // 打印message以及其余信息
// count: 5 
console.info('count:'); // 仅打印message
// count: 
```

## console.warn

warn(message: string, ...arguments: any[]): void

以格式化输出方式打印警告信息。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的警告信息。 |
| arguments | any[] | 否    | 表示其余要打印的信息或message的替换值。 |

**示例：**

```js
const str = "name should be string";
console.warn('warn: %d', str);  // 格式化输出替换message中的文本。
// warn: name should be string
console.warn('warn:', str);  // 打印message以及其余信息
// warn: name should be string
console.warn('warn:'); // 仅打印message
// warn: 
```

## console.error

error(message: string, ...arguments: any[]): void

以格式化输出方式打印错误信息。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的错误信息。 |
| arguments | any[] | 否    | 表示其余要打印的信息或message的替换值。 |


**示例：**

```js
const str = "value is not defined";
console.error('error: %d', str);  // 格式化输出替换message中的文本。
// error: value is not defined
console.error('error:', str);  // 打印message以及其余信息
// error: value is not defined
console.error('error:'); // 仅打印message
// error: 
```

## console.assert<sup>10+</sup>

assert(value?: Object, ...arguments: Object[]): void

断言打印。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| value | Object | 否    | 语句结果值。若value为假（false）或者省略，则输出以"Assertion failed"开头。如果value为真值（true），则无打印。|
| arguments | Object | 否    | value为假（false）的后续错误消息打印。省略则不打印。|

**示例：**

```js
console.assert(true, 'does nothing');  // 表达式结果值为true, 无打印。
console.assert(2 % 1 == 0, 'does nothing');  // 表达式结果值为true, 无打印。

console.assert(false, 'console %s work', 'didn\'t');
// Assertion failed: console didn't work

console.assert();
// Assertion failed
```

## console.count<sup>10+</sup>

count(label?: string): void

维护一个内部计数器，调用时，打印此标签名以及对应的计数次数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计数器标签名。默认值为'default'。|


**示例：**

```js
console.count()
// default: 1
console.count('default')
// default: 2
console.count('abc')
// abc: 1
console.count('xyz')
// xyz: 1
console.count('abc')
// abc: 2
console.count()
// default: 3
```

## console.countReset<sup>10+</sup>

countReset(label?: string): void

清除指定标签名的计数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计数器标签名。默认值为'default'。|

**示例：**

```js
console.count('abc');
// abc: 1
console.countReset('abc');
console.count('abc');
// abc: 1
```

## console.dir<sup>10+</sup>

dir(dir?: Object): void

打印对象内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| dir | Object | 否    | 需要打印内容的对象。省略则无任何打印。|


**示例：**

```js
class bar {
  baz: boolean = true;
}
let b: bar = {baz: true}
class foo{
  bar: bar = b;
}
let c: foo = {bar: b}
class  c1{
  foo: foo = c;
}
let a: c1 = {foo: c}
console.dir(a);
// Object: {"foo":{"bar":{"baz":true}}}

console.dir(); // 无打印
```


## console.dirxml<sup>10+</sup>

dirxml(...arguments: Object[]): void 

此方法通过内部调用console.log()实现。此方法不会产生任何 XML 格式。使用方法与console.log()一致。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 是    | 要打印的信息。 |

**示例：**

```js
const number = 5;
console.dirxml('count: %d', number);
// count: 5 
console.dirxml('count:', number);
// count: 5 
console.dirxml('count:');
// count: 
```

## console.group<sup>10+</sup>

group(...arguments: Object[]): void

默认将后续行的缩进增加两个空格。
如果提供需要打印的信息，则首先打印信息，没有额外的缩进。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 要打印的信息。 |

**示例：**

```js
console.log("outter");
// outter
console.group();
console.log("level 1");
//   level 1
console.group("in level1");
//   in level1
console.log("level 2");
//     level 2
```


## console.groupCollapsed<sup>10+</sup>

groupCollapsed(...arguments: Object[]): void

使用与功能同console.group()一致。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 要打印的信息。|


**示例：**

```js
console.groupCollapsed("outter");
// outter
console.groupCollapsed();
console.log("level 1");
//   level 1
console.groupCollapsed("in level1");
//   in level1
console.log("level 2");
//     level 2
```

## console.groupEnd<sup>10+</sup>

groupEnd(): void

将后续行的缩进减少两个空格。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**示例：**

```js
console.log("outter");
// outter
console.group();
console.log("level 1");
//   level 1
console.groupEnd();
console.log("outter");
// outter
```


## console.table<sup>10+</sup>

table(tableData?: Object): void

以表格形式打印数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| tableData | Object | 否    | 要打印为表格形式的对象。省略则无任何打印。 |

**示例：**

```js
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

启动可用于计算操作持续时间的计时器。可使用console.timeEnd()关闭计时器并打印经过的时间(单位：ms)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计时器标识。默认值为'default'。 |

**示例：**

```js
console.time('abc');
```

## console.timeEnd<sup>10+</sup>

timeEnd(label?: string): void

停止之前通过调用 console.time() 启动的计时器并将打印经过的时间(单位：ms)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计时器标识。默认值为'default'。 |

**示例：**

```js
console.time('abc');
console.timeEnd('abc');
// abc: 225.438ms
```

## console.timeLog<sup>10+</sup>

timeLog(label?: string, ...arguments: Object[]): void

对于先前通过调用 console.time() 启动的计时器，打印经过时间和其他data参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| label | string | 否    | 计时器标识。默认值为'default'。 |
| arguments | Object | 否    | 需要打印的其他日志。 |

**示例：**

```js
console.time('timer1');
console.timeLog('timer1', 17);
// timer1: 365.227ms 17
console.timeEnd('timer1');
// timer1: 513.22ms
```

## console.trace<sup>10+</sup>

static trace(...arguments: Object[]): void

打印当前堆栈。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| arguments | Object | 否    | 需要打印的其他日志。省略则仅打印堆栈信息。|

**示例：**

```js
console.trace();
// Trace:
//     xxxxxxxxxx(当前堆栈信息)
console.trace("Show the trace");
// Trace: Show the trace
//     xxxxxxxxxx(当前堆栈信息)
```

## console.traceHybridStack<sup>12+</sup>

static traceHybridStack(): void

在主线程/worker线程中可打印当前线程混合堆栈信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
console.traceHybridStack();
// TraceHybridStack:
//     xxxxxxxxxx(当前线程混合堆栈信息)
```