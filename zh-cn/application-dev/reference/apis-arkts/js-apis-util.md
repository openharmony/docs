# @ohos.util (util工具函数)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong; @lijin1039-->
<!--Designer: @Malzahar; @lijin1039-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

该模块主要提供常用的工具函数，实现字符串编解码（[TextEncoder](#textencoder)，[TextDecoder](#textdecoder)）、有理数运算（[RationalNumber<sup>8+</sup>](#rationalnumber8)）、缓冲区管理（[LRUCache<sup>9+</sup>](#lrucache9)）、范围判断（[ScopeHelper<sup>9+</sup>](#scopehelper9)）、Base64编解码（[Base64Helper<sup>9+</sup>](#base64helper9)）、内置对象类型检查（[types<sup>8+</sup>](#types8)）、对方法进行插桩和替换（[Aspect<sup>11+</sup>](#aspect11)）、虚拟机维测能力（[ArkTSVM<sup>23+</sup>](#arktsvm23)）、二进制流解码（[StringDecoder<sup>12+</sup>](#stringdecoder12)）、堆内存阈值配置（[HeapMemoryThreshold<sup>24+</sup>](#heapmemorythreshold24)）等功能。此外还提供获取对象Hash值（[util.getHash<sup>12+</sup>](#utilgethash12)）、获取主线程栈追踪信息（[util.getMainThreadStackTrace<sup>20+</sup>](#utilgetmainthreadstacktrace20)）等工具函数。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { util } from '@kit.ArkTS';
```
## util.format<sup>9+</sup>

format(format: string,  ...args: Object[]): string

使用样式化字符串将输入内容按特定格式输出，适用于日志输出、用户界面文本格式化等场景。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型     | 必填 | 说明           |
| ------- | -------- | ---- | -------------- |
| format  | string   | 是   | 格式化字符串，可以包含零个或多个占位符，用于指定要插入的参数的位置和格式。 |
| ...args | Object[] | 否   | 替换format参数中占位符的数据，此参数缺失时，直接返回格式化字符串本身。|

**返回值：**

| 类型   | 说明              |
| ------ | -----------------|
| string | 格式化后的字符串。 |

**格式说明符：**

| 格式说明符 | 说明                          |
| ------ | -------------------------------- |
| %s     | 将参数转换为字符串，用于除Object，BigInt和-0之外的所有值。|
| %d     | 将参数作为十进制整数进行格式化输出，用于除Symbol和BigInt之外的所有值。|
| %i     | 将字符串转换为十进制整数，用于除BigInt和Symbol之外的所有值。|
| %f     | 将字符串转换为浮点数，用于除BigInt和Symbol之外的所有值。|
| %j     | 将JavaScript对象序列化为JSON字符串进行格式化输出。|
| %o     | 用于将JavaScript对象进行格式化输出，将对象转换为字符串表示，但不包含对象的原型链信息。|
| %O     | 用于将JavaScript对象进行格式化输出，将对象转换为字符串表示。|
| %c     | CSS样式占位符，仅在浏览器环境中有效，用于指定格式化输出的样式；其余环境会忽略该占位符。|
| %%     | 转义百分号的特殊格式化占位符。|

**示例：**

```ts
import { util } from '@kit.ArkTS';

interface utilAddressType {
  city: string;
  country: string;
}
interface utilPersonType {
  name: string;
  age: number;
  address: utilAddressType;
}

let name = 'John';
let age = 20;
let formattedString = util.format('My name is %s and I am %s years old', name, age);
console.info(formattedString);
// 输出结果：My name is John and I am 20 years old
let num = 10.5;
formattedString = util.format('The number is %d', num);
console.info(formattedString);
// 输出结果：The number is 10.5
num = 100.5;
formattedString = util.format('The number is %i', num);
console.info(formattedString);
// 输出结果：The number is 100
const pi = 3.141592653;
formattedString = util.format('The value of pi is %f', pi);
console.info(formattedString);
// 输出结果：The value of pi is 3.141592653
const obj: Record<string,number | string> = { "name": 'John', "age": 20 };
formattedString = util.format('The object is %j', obj);
console.info(formattedString);
// 输出结果：The object is {"name":"John","age":20}
const person: utilPersonType = {
  name: 'John',
  age: 20,
  address: {
    city: 'New York',
    country: 'USA'
  }
};
console.info(util.format('Formatted object using %%O: %O', person));
console.info(util.format('Formatted object using %%o: %o', person));
/*
输出结果：
Formatted object using %O: { name: 'John',
  age: 20,
  address:
  { city: 'New York',
    country: 'USA' } }
Formatted object using %o: { name: 'John',
  age: 20,
  address:
  { city: 'New York',
    country: 'USA' } }
 */
const percentage = 80;
let arg = 'homework';
formattedString = util.format('John finished %d%% of the %s', percentage, arg);
console.info(formattedString);
// 输出结果：John finished 80% of the homework
```

## util.errnoToString<sup>9+</sup>

errnoToString(errno: number): string

获取系统错误码对应的详细信息。适用于系统调用出错时将数字错误码转换为可读的描述信息，便于开发者快速定位和排查系统级错误，常用于错误日志记录和错误提示显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| errno  | number | 是   | 系统发生错误产生的错误码。 |

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| string | 错误码对应的详细信息，包含可读的错误描述文本，便于开发者定位问题。 |

**示例：**

```ts
let errnum = -1; // -1 : a system error number
let result = util.errnoToString(errnum);
console.info("result = " + result);
// 输出结果：result = operation not permitted
```

**部分错误码及信息示例：**

| 错误码 | 信息                              |
| ------ | -------------------------------- |
| -1     | operation not permitted          |
| -2     | no such file or directory        |
| -3     | no such process                  |
| -4     | interrupted system call          |
| -5     | i/o error                        |
| -11    | resource temporarily unavailable |
| -12    | not enough memory                |
| -13    | permission denied                |
| -100   | network is down                  |

## util.callbackWrapper

callbackWrapper(original: Function): (err: Object, value: Object)=&gt;void

对异步函数进行回调化处理，回调中第一个参数是拒绝原因（如果Promise已解决，则为null），第二个参数是已解决的值。

> **说明：**
>
> 该接口要求参数original必须是异步函数类型。如果传入的参数不是异步函数，不会进行拦截，但是会输出错误信息："callbackWrapper: The type of Parameter must be AsyncFunction"。
>
> 该接口用于将返回Promise的async函数转换为错误优先回调风格的函数，调用此接口返回的函数接收一个回调函数作为第二个入参，调用此方法时会先执行original函数。当original的Promise返回resolve时，入参的回调函数的第一个参数为null，第二个参数为resolve的值。当original的Promise返回reject时，入参的回调函数的第一个参数为错误对象，第二个参数为null。
>
> 由于此方法返回类型的声明为`(err: Object, value: Object) => void`，TypeScript编译器会按照该声明进行参数数量校验，因此当original为无入参的函数时，此接口返回的函数第一个入参需传入一个无效的占位参数。当original为多个入参的函数时，此接口返回的函数当前仅支持传入一个参数，可使用array等容器进行多个入参的传入调用（参照下方示例代码）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| original | Function | 是 | 异步函数，要求函数返回Promise对象。该异步函数的resolve值会作为回调的第二个参数传入，reject原因会作为回调的第一个参数传入。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| (err: Object, value: Object)=&gt;void | 返回一个回调函数，该函数第一个参数err是拒绝原因（如果&nbsp;Promise&nbsp;已解决，则为&nbsp;null），第二个参数value是已解决的值。 |

**示例：**

```ts
// original为一个入参示例
async function fn(input: string) {
  return input;
}
let cb = util.callbackWrapper(fn);
cb('hello world', (err : Object, ret : string) => {
  if (err) throw new Error;
  console.info(ret);
});
// 输出结果：hello world
```

```ts
// original需要传入多个入参场景示例
async function fn(args: Array<string | number | Function>) {
  console.info('args[0]: ' + args[0]); // args[0]: hello world
  console.info('args[1]: ' + args[1]); // args[1]: 8
  return args[0];
}
let cb = util.callbackWrapper(fn);
let args: Array<string | number | Function> = ['hello world', 8]
cb(args, (err : Object, ret : string) => {
  if (err) throw new Error;
  console.info(ret); // 输出结果：hello world
});
```

## util.promisify<sup>9+</sup>

promisify(original: (err: Object, value: Object) =&gt; void): Function

接收一个采用"错误优先"回调模式的函数，即以`(err, value) => callback`作为最后一个参数，并返回其Promise函数。适用于将旧版回调式异步API转换为Promise风格，以便使用async/await语法进行调用，从而简化异步代码编写。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| original | (err: Object, value: Object) =&gt; void | 是 | 回调函数中第一个参数err是拒绝原因（如果&nbsp;Promise&nbsp;已解决，则为&nbsp;null），第二个参数value是已解决的值。  |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Function | 返回一个Promise函数，该Promise在原始回调函数成功执行时resolve为回调的value值，在原始回调函数执行出错时reject为错误对象。 |

**示例：**

```ts
async function fn() {
  return 'hello world';
}
const addCall = util.promisify(util.callbackWrapper(fn));
(async () => {
  try {
    let res: string = await addCall();
    console.info(res);
    // 输出结果：hello world
  } catch (err) {
    console.info(err);
  }
})();
```

## util.generateRandomUUID<sup>9+</sup>

generateRandomUUID(entropyCache?: boolean): string

使用加密安全随机数生成器生成随机的RFC 4122版本4的string类型UUID。为了提升性能，此接口会默认使用缓存，即入参为true，最多可缓存128个随机的UUID。当缓存中128个UUID用尽后，会重新生成，以保证UUID的随机性。如需禁用缓存，请将入参设置为false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| entropyCache | boolean | 否 | 是否使用已缓存的UUID，true表示使用缓存的UUID以提升性能（最多缓存128个UUID，缓存用尽后会重新生成以保证随机性），false表示不使用缓存的UUID，默认true。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 表示此UUID的字符串。 |

**示例：**

```ts
let uuid = util.generateRandomUUID(true);
console.info("RFC 4122 Version 4 UUID:" + uuid);
// 输出随机生成的UUID
```

## util.generateRandomBinaryUUID<sup>9+</sup>

generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array

使用加密安全随机数生成器生成随机的RFC 4122版本4的Uint8Array类型UUID。为了提升性能，此接口会默认使用缓存，即入参为true，最多可缓存128个随机的UUID。当缓存中128个UUID用尽后，会重新生成，以保证UUID的随机性。如需禁用缓存，请将入参设置为false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| entropyCache | boolean | 否 | 是否使用已缓存的UUID，true表示使用缓存的UUID，false表示不使用缓存的UUID，默认true。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 表示此UUID的Uint8Array值。 |

**示例：**

```ts
let uuid = util.generateRandomBinaryUUID(true);
console.info(JSON.stringify(uuid));
// 输出随机生成的UUID
```

## util.parseUUID<sup>9+</sup>

parseUUID(uuid: string): Uint8Array

将generateRandomUUID生成的string类型UUID转换为[util.generateRandomBinaryUUID](#utilgeneraterandombinaryuuid9)生成的UUID，符合RFC 4122版本规范。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uuid | string | 是 | UUID字符串，必须符合RFC 4122版本规范。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回表示此UUID的Uint8Array，如果解析失败，则抛出异常，错误码为10200002。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200002 | Invalid uuid string. |

**示例：**

```ts
let uuid = util.parseUUID("84bdf796-66cc-4655-9b89-d6218d100f9c");
console.info("uuid = " + uuid);
// 输出结果：uuid = 132,189,247,150,102,204,70,85,155,137,214,33,141,16,15,156
```

## util.printf<sup>(deprecated)</sup>

printf(format: string,  ...args: Object[]): string

通过式样化字符串对输入的内容按特定格式输出。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[util.format<sup>9+</sup>](#utilformat9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| format | string | 是 | 式样化字符串。 |
| ...args | Object[] | 否 | 替换式样化字符串通配符的数据，此参数缺失时，默认返回第一个参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 按特定格式式样化后的字符串，包含根据格式说明符处理后的参数值。 |

**示例：**

```ts
let res = util.printf("%s", "hello world!");
console.info(res);
// 输出结果：hello world!
```


## util.getErrorString<sup>(deprecated)</sup>

getErrorString(errno: number): string

获取系统错误码对应的详细信息。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[util.errnoToString<sup>9+</sup>](#utilerrnotostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| errno | number | 是 | 系统发生错误产生的错误码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 错误码对应的详细信息。 |

**示例：**

```ts
let errnum = -1; // -1 : a system error number
let result = util.getErrorString(errnum);
console.info("result = " + result);
// 输出结果：result = operation not permitted
```

## util.promiseWrapper<sup>(deprecated)</sup>

promiseWrapper(original: (err: Object, value: Object) =&gt; void): Object

接收一个采用“错误优先”回调模式的函数，即以`(err, value) => callback`作为最后一个参数，并返回其Promise函数。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，此接口不可用，建议使用[util.promisify<sup>9+</sup>](#utilpromisify9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| original | (err: Object, value: Object) =&gt; void | 是 | 采用错误优先回调模式的函数，第一个参数err是拒绝原因，第二个参数value是已解决的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | 返回promise函数，采用遵循常见的错误优先的回调风格的函数（也就是将(err, value) => ...回调作为最后一个参数）。 |


## util.getHash<sup>12+</sup>

getHash(object: object): number

获取对象的Hash值。

首次获取时，则计算Hash值并保存到对象的Hash域（返回随机的Hash值）；后续获取时，直接从Hash域中返回Hash值（同一对象多次返回值保持不变）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| object | object | 是 | 需要获取Hash值的非原始类型对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 对象的Hash值，首次获取时返回随机值，同一对象多次获取返回值保持不变。 |

**示例：**

```ts
interface Person {
  name: string,
  age: number
}
let obj: Person = { name: 'Jack', age: 20 };
let result1 = util.getHash(obj);
console.info('result1 is ' + result1);
let result2 = util.getHash(obj);
console.info('result2 is ' + result2);
// 输出结果：result1 与 result2 的值相等，且为随机的Hash值。
```

## util.getMainThreadStackTrace<sup>20+</sup>

getMainThreadStackTrace(): string

获取主线程的栈追踪信息，最多返回64层调用帧。

该接口可能对主线程性能产生影响，建议仅在必要时使用，如日志记录、错误分析或调试场景。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 主线程的栈追踪信息。若主线程未处于执行JS代码状态，则返回空字符串。|

**示例：**

```ts
let stack = util.getMainThreadStackTrace();
console.info(stack);
// 输出当前主线程的栈追踪信息。
```
## MultithreadingDetectionOptions

MultithreadingDetectionOptions是一个接口类，用于配置[ArkTSVM.setMultithreadingDetectionEnabled](#setmultithreadingdetectionenabled23)函数的行为参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**属性：**

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| abort  | boolean  | 否       | 是       | 控制检测到多线程问题时是否崩溃。传入true表示检测到多线程问题时立即崩溃，适用于开发调试阶段需要快速暴露多线程问题的场景；传入false表示不崩溃仅上报故障信息，适用于生产环境需要保持服务可用性的场景。默认true。|
| frequency  | number  | 否       | 是       | 多线程安全检测的粒度，表示每发生多少次函数调用进行一次多线程安全检测，该值越大采样频率越低，对应用性能影响越小，但可能漏检部分多线程安全使用问题场景，范围为[100, 2147483647]，默认100。|
| interval  | number  | 否       | 是       | 多线程安全检测的上报故障时间间隔，仅不崩溃时生效，范围为[0,1440]，单位为分钟，默认5分钟。（不建议设为5分钟以下，有严重的性能影响。）|

## ArkTSVM<sup>23+</sup>

ArkTSVM是一个类，用于给开发者提供虚拟机的诊断与维护能力，包括多线程安全检测、堆内存信息获取、内存泄漏防护、全局引用追踪和堆内存预警等功能。

### setMultithreadingDetectionEnabled<sup>23+</sup>

static setMultithreadingDetectionEnabled(enabled: boolean, options?: MultithreadingDetectionOptions): void

若enabled为true则开启，为false则关闭。开启多线程安全检测，多线程问题的C/C++崩溃转储文件（cppcrash文件）里会包含多线程信息（如线程ID、锁状态等）。关闭多线程安全检测，则C/C++崩溃转储文件（cppcrash文件）里不会包含多线程信息。

options是用于配置多线程安全检测的行为参数。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| enabled  | boolean  | 是       | 控制多线程安全检测开关的开启或关闭。true表示开启，false表示关闭。|
| options  | [MultithreadingDetectionOptions](#multithreadingdetectionoptions)  | 否       | 多线程安全检测的参数配置，此参数不填时，对应各属性取[MultithreadingDetectionOptions](#multithreadingdetectionoptions)的默认值。**起始版本：** 26.0.0|

**示例：**

```ts
import { util } from '@kit.ArkTS';

// 打开多线程安全检测开关
util.ArkTSVM.setMultithreadingDetectionEnabled(true);
// 关闭多线程安全检测开关
util.ArkTSVM.setMultithreadingDetectionEnabled(false);
// 设置崩溃行为
util.ArkTSVM.setMultithreadingDetectionEnabled(true, { abort: false });
// 调整检测粒度
util.ArkTSVM.setMultithreadingDetectionEnabled(true, { frequency: 200 });
// 调整上报间隔
util.ArkTSVM.setMultithreadingDetectionEnabled(true, { interval: 10 });
// 同时设置三个参数
util.ArkTSVM.setMultithreadingDetectionEnabled(true, {
  abort: false,
  frequency: 500,
  interval: 60
});
```

### getAllVMHeapMemoryInfo<sup>24+</sup>

static getAllVMHeapMemoryInfo(): Promise<HeapMemoryInfo[]>

获取所有VM线程的堆内存信息，包括线程ID、线程名称、堆类型和堆对象大小，适用于内存泄漏排查、内存使用分析等场景。使用Promise异步回调。

接口获取到的堆包含两种类型：local堆，即应用进程中每个ArkTS线程独有的虚拟机堆；shared堆，即应用进程中所有ArkTS线程共享的虚拟机堆。

> **说明：**
>
> 此接口在执行时会暂停所有VM线程运行以获取内存信息。由于需要等待所有VM线程暂停，高负载场景下调用此接口的耗时可能较高。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<[HeapMemoryInfo](js-apis-util.md#heapmemoryinfo24)[]> | Promise对象，解析为HeapMemoryInfo对象数组，每个对象包含线程ID、线程名称、堆类型和堆对象大小。此方法可以获取local堆和shared堆的内存信息。|

**示例：**

```ts
import { util } from '@kit.ArkTS';

util.ArkTSVM.getAllVMHeapMemoryInfo().then(
  result => {
    result.forEach(info => {
      console.info(info.threadId?.toString());
      console.info(info.threadName);
      console.info(info.heapType);
      console.info(info.heapObjectSize.toString());
    })
  }
);
```

### enableLocalHandleDetection<sup>24+</sup>

static enableLocalHandleDetection(): void

EventHandler和libuv的异步事件循环机制在执行异步任务时，任务将不在当前handle scope的管理范围内执行，创建的napi_value不会被自动回收。若开发者在任务回调中未添加scope，将导致内存泄漏。调用该接口后，可确保这两个机制的任务在scope范围内执行，从而避免内存泄漏。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

``` C++
// napi_init.cpp C++侧示例代码
#include "napi/native_api.h"
#include "uv.h"

static napi_value CreateObject(napi_env env, napi_callback_info info)
{
    uv_loop_s* loop = nullptr;
    napi_status status = napi_get_uv_event_loop(env, &loop);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_uv_event_loop fail");
        return nullptr;
    }
    uv_work_t* work = new uv_work_t;
    work->data = env;
    int ret = uv_queue_work(loop, work,
        [](uv_work_t* work){},
        [](uv_work_t* work, int status){
            napi_env env = static_cast<napi_env>(work->data);
            for (int i = 0; i < 1000; i++) {
                napi_value obj = nullptr;
                // 在libuv提供的异步机制中没有加scope会导致内存泄漏
                napi_create_object(env, &obj);
            }
            delete work;
        }
    );
    if (ret != 0) {
        delete work;
    }
    return nullptr;
}
```

在CMakeLists.txt中添加以下动态链接库：

```txt
libuv.so
```

``` TypeScript
// index.d.ts 接口声明
export const createObject: () => void;
```

``` TypeScript
// Index.ets ArkTS侧示例代码
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
import { util } from '@kit.ArkTS';

try {
  // 若不开启LocalHandle内存泄漏兜底机制，可能导致内存溢出。启用该机制后，系统将自动回收EventHandler和libuv异步任务中创建的napi_value
  util.ArkTSVM.enableLocalHandleDetection();
  testNapi.createObject();
  hilog.info(0x0000, 'testTag', 'Test Node-API createObject success');
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API createObject failed error: %{public}s', error.message);
}
```

**可能出现的问题：**

如果之前内存泄漏的对象被继续使用，使用enableLocalHandleDetection接口后，系统会回收内存泄漏对象。继续使用该对象会导致内存泄漏问题转变为稳定性问题。

``` C++
napi_value global_js_object;
napi_value dangerous_function(napi_env env, napi_callback_info info) {
    napi_value js_obj;
    napi_create_object(env, &js_obj);
    global_js_object = js_obj; // 直接存储到全局变量，开启LocalHandle内存泄漏兜底机制后被释放
    return nullptr;
}
```

### setTrackGlobalRef

static setTrackGlobalRef(enable: boolean): void

开启或关闭napi_ref与全局对象之间的关联追踪。开启后，堆快照中全局对象节点将包含napi_ref的地址信息；关闭后（enable为false），将停止追踪，堆快照中不再显示napi_ref与全局对象之间的关联关系。

开启追踪后，虚拟机会额外记录napi_ref与全局对象的关联关系，可能带来一定的内存和性能开销。在不需要调试时，建议调用`util.ArkTSVM.setTrackGlobalRef(false)`关闭追踪。

该接口的开关为进程级别，进程内的所有线程共享同一开关状态。在任意线程调用本接口设置开关后，将对该进程内所有线程生效。

关于napi_ref的详细说明，请参考[napi_ref](../../napi/use-napi-life-cycle.md#napi_ref)使用指导。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| enable | boolean | 是 | 是否开启追踪。true表示开启追踪（可能带来一定的内存和性能开销），false表示关闭追踪。建议在不需要调试时设置为false以避免性能开销。 |

**示例：**

``` C++
// napi_init.cpp C++侧示例代码
#include "napi/native_api.h"

static napi_value CreateGlobalRef(napi_env env, napi_callback_info info)
{
    napi_value js_obj = nullptr;
    napi_create_object(env, &js_obj);
    // 创建napi_ref，与全局handle建立关联
    napi_ref ref = nullptr;
    napi_create_reference(env, js_obj, 1, &ref);
    // 开启setTrackGlobalRef后，堆快照中将包含该ref对应的native引用地址信息
    return nullptr;
}
```

``` TypeScript
// Index.d.ts 接口声明
export const createGlobalRef: () => void;
```

``` TypeScript
// Index.ets ArkTS侧示例代码
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
import { util } from '@kit.ArkTS';

try {
  // 开启napi_ref与全局handle的关联追踪，开启后堆快照中将包含native引用地址信息
  util.ArkTSVM.setTrackGlobalRef(true);
  testNapi.createGlobalRef();
  hilog.info(0x0000, 'testTag', 'Test Node-API createGlobalRef success');
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API createGlobalRef failed error: %{public}s', error.message);
}
```

### onVMHeapMemoryPressure<sup>24+</sup>

static onVMHeapMemoryPressure(callback: Callback\<string\>, heapMemoryThreshold: HeapMemoryThreshold): boolean

注册一个回调函数，在虚拟机主线程完成垃圾回收后，如果堆内存超过预警阈值则触发回调执行，适用于主动内存管理（在内存压力较大时触发资源清理）、OOM预防等场景。

虚拟机是通过统计存活对象大小来判断是否达到内存预警阈值，由于虚拟机堆存在一定内存碎片以及浮动垃圾，无法保证在OOM前肯定会触发到回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback\<string\> | 是 | 垃圾回收后内存达到预警阈值时触发的回调函数，字符串参数表示内存压力事件的类型。目前事件的类型有三种取值，"LocalHeapMemPressure"，"SharedHeapMemPressure"，"ProcessHeapMemPressure"。 |
| heapMemoryThreshold | [HeapMemoryThreshold](#heapmemorythreshold24) | 是 | 堆内存预警阈值配置，以百分比设置，取值范围为[70, 95]。超出范围时自动限制到有效区间。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 注册成功返回true，当不在主线程调用或回调已注册时返回false。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let callback = (event: string) => {
  console.info('Memory pressure event: ' + event);
};

let threshold: util.HeapMemoryThreshold = {
  localHeapThreshold: 75,
  sharedHeapThreshold: 80,
  processHeapThreshold: 85
};

let result : boolean = util.ArkTSVM.onVMHeapMemoryPressure(callback, threshold);
console.info('Registration result: ' + result);
```

### offVMHeapMemoryPressure<sup>24+</sup>

static offVMHeapMemoryPressure(): void

取消已注册的内存预警回调函数。此接口需要在主线程调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
import { util } from '@kit.ArkTS';

util.ArkTSVM.offVMHeapMemoryPressure();
```

## HeapMemoryThreshold<sup>24+</sup>

堆内存预警阈值配置，用于指定触发回调的堆内存预警阈值。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | ---- |
| localHeapThreshold | number | 否 | 是 | local堆内存预警阈值配置，以百分比设置，取值范围为[70, 95]。超出范围时自动限制到有效区间。若未设置，则不监听local堆。|
| sharedHeapThreshold | number | 否 | 是 | shared堆内存预警阈值配置，以百分比设置，取值范围为[70, 95]。超出范围时自动限制到有效区间。若未设置，则不监听shared堆。|
| processHeapThreshold | number | 否 | 是 | 进程总虚拟机堆内存预警阈值配置，以百分比设置，取值范围为[70, 95]。超出范围时自动限制到有效区间。若未设置，则不监听进程总虚拟机堆大小。|

## HeapMemoryInfo<sup>24+</sup>

描述local堆或shared堆的内存信息，包含线程标识和堆内存大小等详细数据。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| threadId | number | 否 | 是 | 线程ID。如果此内存信息描述的是local堆，该值为表示运行线程ID的整数；如果此内存信息描述的是shared堆，该值为**undefined**。|
| threadName | string | 否 | 是 | 线程名称。如果此内存信息描述的是local堆，该值为表示运行线程名称的字符串；如果此内存信息描述的是shared堆，该值为**undefined**。|
| heapType | string | 否 | 否 | 堆类型。目前有两种取值，"local"表示堆类型为local堆，"shared"表示堆类型为shared堆。|
| heapObjectSize | number | 否 | 否 | 堆对象大小，单位为KB（向上取整的整数）。|

## TextDecoderOptions<sup>11+</sup>

解码相关选项参数，包含两个属性fatal和ignoreBOM。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称      | 类型 | 只读 | 可选 | 说明               |
| --------- | -------- | ---- | ---- | ------------------ |
| fatal     | boolean  | 否   | 是 | 是否显示致命错误，true表示显示致命错误，false表示不显示致命错误，默认值是false。 |
| ignoreBOM | boolean  | 否   | 是 | 是否忽略BOM标记，true表示忽略待解码数据的BOM标记，false表示会对BOM标记解码，默认值是false。  |

## DecodeToStringOptions<sup>12+</sup>

用于配置decodeToString方法在解码字节流时的行为参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| --------- | -------- | ---- | ---- | ------------------ |
| stream | boolean | 否 | 是 | 输入末尾出现的不完整字节序列是否需要追加在下次调用decodeToString的参数中处理。设置为true，则不完整的字节序列会存储在内部缓存区直到下次调用该函数，false则会在当前调用时直接解码。默认为false。 |

## DecodeWithStreamOptions<sup>11+</sup>

解码是否跟随附加数据块相关选项参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| stream | boolean | 否 | 是 | 在随后的[decodeWithStream](#decodewithstreamdeprecated)调用中是否跟随附加数据块。如果以块的形式处理数据，则设置为true；如果处理最后的数据未分块，则设置为false。默认为false。 |

## Aspect<sup>11+</sup>

Aspect类用于封装提供切面能力（Aspect Oriented Programming，简写AOP）的接口，这些接口可用于对类方法进行前后插桩或替换实现。

### addBefore<sup>11+</sup>

static addBefore(targetClass: Object, methodName: string, isStatic: boolean, before: Function): void

在指定的类对象的原方法执行前插入一个函数，适用于日志记录、性能监控、权限校验等需要在方法执行前进行拦截处理的场景。执行addBefore接口后，先运行插入的函数逻辑，再执行指定类对象的原方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型    | 必填 | 说明                                   |
| -------- | ------- | ---- | -------------------------------------|
| targetClass  | Object   | 是   | 指定的类对象。                    |
| methodName   | string   | 是   | 指定的原方法名，不支持read-only方法。                    |
| isStatic     | boolean  | 是   | 指定的原方法是否为静态方法。true表示静态方法，false表示实例方法。      |
| before       | Function | 是   | 要插入的函数对象。函数有参数，则第一个参数是this对象（若isStatic为true，则为类对象即targetClass；若isStatic为false，则为调用方法的实例对象），其余参数是原方法的参数。函数也可以无参数，无参时不做处理。 |

**示例：**

```ts
class MyClass {
  msg: string = 'msg000';
  foo(arg: string): string {
    console.info('foo arg is ' + arg);
    return this.msg;
  }

  static data: string = 'data000';
  static bar(arg: string): string {
    console.info('bar arg is ' + arg);
    return MyClass.data;
  }
}

let asp = new MyClass();
let result = asp.foo('123');
// 输出结果：foo arg is 123
console.info('result is ' + result);
// 输出结果：result is msg000
console.info('asp.msg is ' + asp.msg);
// 输出结果：asp.msg is msg000

util.Aspect.addBefore(MyClass, 'foo', false, (instance: MyClass, arg: string) => {
  console.info('arg is ' + arg);
  instance.msg = 'msg111';
  console.info('msg is changed to ' + instance.msg);
});

result = asp.foo('123');
// 输出结果：arg is 123
// 输出结果：msg is changed to msg111
// 输出结果：foo arg is 123
console.info('result is ' + result);
// 输出结果：result is msg111
console.info('asp.msg is ' + asp.msg);
// 输出结果：asp.msg is msg111


let res = MyClass.bar('456');
// 输出结果：bar arg is 456
console.info('res is ' + res);
// 输出结果：res is data000
console.info('MyClass.data is ' + MyClass.data);
// 输出结果：MyClass.data is data000

util.Aspect.addBefore(MyClass, 'bar', true, (target: Object, arg: string) => {
  console.info('arg is ' + arg);
  let newVal = 'data111';
  Reflect.set(target, 'data', newVal);
  console.info('data is changed to ' + newVal);
});

res = MyClass.bar('456');
// 输出结果：arg is 456
// 输出结果：data is changed to data111
// 输出结果：bar arg is 456
console.info('res is ' + res);
// 输出结果：res is data111
console.info('MyClass.data is ' + MyClass.data);
// 输出结果：MyClass.data is data111
```

### addAfter<sup>11+</sup>

static addAfter(targetClass: Object, methodName: string, isStatic: boolean, after: Function): void

在指定的类方法执行后插入一段逻辑。最终返回插入函数执行后的返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型    | 必填 | 说明                                   |
| -------- | ------- | ---- | -------------------------------------|
| targetClass  | Object   | 是   | 指定的类对象。                    |
| methodName   | string   | 是   | 指定的原方法名，不支持read-only方法。                   |
| isStatic     | boolean  | 是   | 指定的原方法是否为静态方法。true表示静态方法，false表示实例方法。      |
| after        | Function | 是   | 要插入的函数。函数有参数时，则第一个参数是this对象（若isStatic为true，则为类对象即targetClass；若isStatic为false，则为调用方法的实例对象），第二个参数是原方法的返回值（如果原方法没有返回值，则为undefined），其余参数是原方法的参数。函数也可以无参，无参时不做处理。  |

**示例：**

```ts
class MyClass {
  msg: string = 'msg000';
  foo(arg: string): string {
    console.info('foo arg is ' + arg);
    return this.msg;
  }
}

let asp = new MyClass();
let result = asp.foo('123');
// 输出结果：foo arg is 123
console.info('result is ' + result);
// 输出结果：result is msg000
console.info('asp.msg is ' + asp.msg);
// 输出结果：asp.msg is msg000

util.Aspect.addAfter(MyClass, 'foo', false, (instance: MyClass, ret: string, arg: string): string => {
  console.info('arg is ' + arg);
  console.info('ret is ' + ret);
  instance.msg = 'msg111';
  console.info('msg is changed to ' + instance.msg);
  return 'msg222';
});

result = asp.foo('123');
// 输出结果：foo arg is 123
// 输出结果：arg is 123
// 输出结果：ret is msg000
// 输出结果：msg is changed to msg111
console.info('result is ' + result);
// 输出结果：result is msg222
console.info('asp.msg is ' + asp.msg);
// 输出结果：asp.msg is msg111

// 分别添加前置和后置插桩的例子
class AroundTest {
  foo(arg: string) {
    console.info('execute foo with arg ' + arg);
  }
}
util.Aspect.addBefore(AroundTest, 'foo', false, () => {
  console.info('execute before');
});
util.Aspect.addAfter(AroundTest, 'foo', false, () => {
  console.info('execute after');
});

(new AroundTest()).foo('hello');
// 输出结果：execute before
// 输出结果：execute foo with arg hello
// 输出结果：execute after
```

### replace<sup>11+</sup>

static replace(targetClass: Object, methodName: string, isStatic: boolean, instead: Function) : void

将指定类的原方法替换为另一个函数，适用于行为替换、兼容性适配、条件执行等需要完全改变方法实现逻辑的场景。replace接口执行完成后，调用指定的类方法时，仅执行替换后的逻辑。最终返回替换函数执行完毕的返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型    | 必填 | 说明                                   |
| -------- | ------- | ---- | -------------------------------------|
| targetClass  | Object   | 是   | 指定的类对象。                    |
| methodName   | string   | 是   | 指定的原方法名，不支持read-only方法。                  |
| isStatic     | boolean  | 是   | 指定的原方法是否为静态方法。true表示静态方法，false表示实例方法。       |
| instead      | Function | 是   | 要用来替换原方法的函数。函数有参数时，则第一个参数是this对象（若isStatic为true，则为类对象即targetClass；若isStatic为false，则为调用方法的实例对象），其余参数是原方法的参数。函数也可以无参，无参时不做处理。   |

**示例：**

```ts
class MyClass {
  msg: string = 'msg000';
  foo(arg: string): string {
    console.info('foo arg is ' + arg);
    return this.msg;
  }
}

let asp = new MyClass();
let result = asp.foo('123');
// 输出结果：foo arg is 123
console.info('result is ' + result);
// 输出结果：result is msg000
console.info('asp.msg is ' + asp.msg);
// 输出结果：asp.msg is msg000

util.Aspect.replace(MyClass, 'foo', false, (instance: MyClass, arg: string): string => {
  console.info('execute instead');
  console.info('arg is ' + arg);
  instance.msg = 'msg111';
  console.info('msg is changed to ' + instance.msg);
  return 'msg222';
});

result = asp.foo('123');
// 输出结果：execute instead
// 输出结果：arg is 123
// 输出结果：msg is changed to msg111
console.info('result is ' + result);
// 输出结果：result is msg222
console.info('asp.msg is ' + asp.msg);
// 输出结果：asp.msg is msg111
```

## TextDecoder

TextDecoder用于将字节数组解码为字符串，支持utf-8、utf-16le/be、iso-8859和windows-1251等不同的编码格式。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | 是 | 否 | 编码格式。<br/>-&nbsp;支持格式：utf-8、ibm866、iso-8859-2、iso-8859-3、iso-8859-4、iso-8859-5、iso-8859-6、iso-8859-7、iso-8859-8、iso-8859-8-i、iso-8859-10、iso-8859-13、iso-8859-14、iso-8859-15、koi8-r、koi8-u、macintosh、windows-874、windows-1250、windows-1251、windows-1252、windows-1253、windows-1254、windows-1255、windows-1256、windows-1257、windows-1258、x-mac-cyrillic、gbk、gb18030、big5、euc-jp、iso-2022-jp、shift_jis、euc-kr、utf-16be、utf-16le、gb2312、iso-8859-1。 |
| fatal | boolean | 是 | 否 | 是否显示致命错误，true表示显示，false表示不显示。 |
| ignoreBOM | boolean | 是 | 否 | 是否忽略BOM（byte order marker）标记，true表示忽略BOM标记，false表示解码结果包含BOM标记，默认值为false。 |

### constructor<sup>9+</sup>

constructor()

TextDecoder的构造函数，创建一个默认编码格式为'utf-8'的TextDecoder实例，fatal默认为false，ignoreBOM默认为false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let textDecoder = new util.TextDecoder();
let retStr = textDecoder.encoding;
console.info('retStr = ' + retStr);
// 输出结果：retStr = utf-8
```
### create<sup>9+</sup>

static create(encoding?: string, options?: TextDecoderOptions): TextDecoder

替代有参构造函数的功能。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                                             |
| -------- | ------ | ---- | ------------------------------------------------ |
| encoding | string | 否   | 编码格式，支持格式参见[encoding属性](#属性)，默认值是'utf-8'。                      |
| options  | [TextDecoderOptions](#textdecoderoptions11) | 否   | 解码相关选项参数，存在两个属性fatal和ignoreBOM。此参数不填时，对应各属性取其默认值。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [TextDecoder](#textdecoder) | 返回一个用于将字节数组按指定编码格式解码为字符串的TextDecoder对象。 |

**示例：**

```ts
let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let textDecoder = util.TextDecoder.create('utf-8', textDecoderOptions);
let retStr = textDecoder.encoding;
console.info('retStr = ' + retStr);
// 输出结果：retStr = utf-8
```

### decodeToString<sup>12+</sup>

decodeToString(input: Uint8Array, options?: DecodeToStringOptions): string

将输入参数解码后输出对应文本。

> **说明：**
>
> 该接口会正常解析值为\0的字节，将其转换为Unicode字符\u0000（空字符），不会导致解码中断或错误。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | Uint8Array | 是 | 需要解码的数组。 |
| options | [DecodeToStringOptions](#decodetostringoptions12) | 否 | 解码相关选项参数，用于控制解码行为。当需要以流式方式分块处理数据且保留不完整字节序列时传入此参数并设置stream为true；不传入时默认为undefined，即不保留不完整字节序列，直接在当前调用中解码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解码后的数据。 |

**示例：**

```ts
// 当解析不含有\0的字节的示例代码
let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let decodeToStringOptions: util.DecodeToStringOptions = {
  stream: false
}
let textDecoder = util.TextDecoder.create('utf-8', textDecoderOptions);
let uint8 = new Uint8Array([0xEF, 0xBB, 0xBF, 0x61, 0x62, 0x63]);
let retStr = textDecoder.decodeToString(uint8, decodeToStringOptions);
console.info("retStr = " + retStr);
// 输出结果：retStr = abc
```

```ts
// 当解析含有\0的字节的示例代码
let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let decodeToStringOptions: util.DecodeToStringOptions = {
  stream: false
}
let textDecoder = util.TextDecoder.create('utf-8', textDecoderOptions);
let uint8 = new Uint8Array([97, 98, 0, 99]);
let retStr = textDecoder.decodeToString(uint8, decodeToStringOptions);
console.info("retStr = " + retStr);
// 输出结果：retStr = abc
let retJson = JSON.stringify(retStr)
console.info("retJson = " + retJson);
// 输出结果：retJson = ab/u0000c
```

### decodeWithStream<sup>(deprecated)</sup>

decodeWithStream(input: Uint8Array, options?: DecodeWithStreamOptions): string

将输入参数解码后输出对应文本。当input是一个空数组时，返回undefined。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃，建议使用[decodeToString<sup>12+</sup>](#decodetostring12)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | Uint8Array | 是 | 符合格式需要解码的数组。 |
| options | [DecodeWithStreamOptions](#decodewithstreamoptions11) | 否 | 解码相关选项参数。此参数不填时，对应各属性取其默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解码后的数据。 |

**示例：**

```ts
let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let decodeWithStreamOptions: util.DecodeWithStreamOptions = {
  stream: false
}
let textDecoder = util.TextDecoder.create('utf-8', textDecoderOptions);
let uint8 = new Uint8Array(6);
uint8[0] = 0xEF;
uint8[1] = 0xBB;
uint8[2] = 0xBF;
uint8[3] = 0x61;
uint8[4] = 0x62;
uint8[5] = 0x63;
console.info("input num:");
let retStr = textDecoder.decodeWithStream(uint8, decodeWithStreamOptions);
console.info("retStr = " + retStr);
// 输出结果：retStr = abc
```

### constructor<sup>(deprecated)</sup>

constructor(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean })

TextDecoder的构造函数。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[create<sup>9+</sup>](#create9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 否 | 编码格式，默认值是'utf-8'。 |
| options | { fatal?: boolean; ignoreBOM?: boolean } | 否 | 解码相关选项参数，存在两个属性fatal和ignoreBOM。此参数不填时，对应各属性取其默认值。 |

  **表1** options

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fatal | boolean | 否 | 是否显示致命错误，true表示显示致命错误，false表示不显示致命错误，默认值是false。 |
| ignoreBOM | boolean | 否 | 是否忽略BOM标记，true表示忽略待解码数据的BOM标记，false表示会对BOM标记解码，默认值是false。 |

**示例：**

```ts
let textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
```

### decode<sup>(deprecated)</sup>

decode(input: Uint8Array, options?: { stream?: false }): string

通过输入参数解码后输出对应文本。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[decodeToString<sup>12+</sup>](#decodetostring12)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | Uint8Array | 是 | 符合格式需要解码的数组。 |
| options | { stream?: false } | 否 | 解码相关选项参数。不传此参数时，stream默认为false，即不跟随附加数据块。 |

**表2** options

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| stream | boolean | 否 | 在随后的decode()调用中是否跟随附加数据块。如果以块的形式处理数据，则设置为true；如果处理数据未分块，则设置为false。默认为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解码后的数据。 |

**示例：**

```ts
let textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
let uint8 = new Uint8Array(6);
uint8[0] = 0xEF;
uint8[1] = 0xBB;
uint8[2] = 0xBF;
uint8[3] = 0x61;
uint8[4] = 0x62;
uint8[5] = 0x63;
console.info("input num:");
let retStr = textDecoder.decode(uint8, {stream: false});
console.info("retStr = " + retStr);
// 输出结果：retStr = abc
```

## EncodeIntoUint8ArrayInfo<sup>11+</sup>

编码后的信息，包含读取的字符数和写入的字节数。

### 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称      | 类型 | 只读  |可选  | 说明               |
| --------- | -------- | -------- |-------- |------------------ |
| read     | number  | 是 | 否 |已读取的字符数。 |
| written | number   | 是 |否 |已写入的字节数。  |


## TextEncoder

TextEncoder将字符串编码为字节数组，支持多种编码格式。

在使用TextEncoder进行编码时，需要注意不同编码格式下字符所占的字节数不同。务必明确指定编码格式，以确保编码结果正确。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | 是 | 否 |  编码格式。<br/>-&nbsp;支持格式：utf-8、gb2312、gb18030、ibm866、iso-8859-1、iso-8859-2、iso-8859-3、iso-8859-4、iso-8859-5、iso-8859-6、iso-8859-7、iso-8859-8、iso-8859-8-i、iso-8859-10、iso-8859-13、iso-8859-14、iso-8859-15、koi8-r、koi8-u、macintosh、windows-874、windows-1250、windows-1251、windows-1252、windows-1253、windows-1254、windows-1255、windows-1256、windows-1257、windows-1258、gbk、big5、euc-jp、iso-2022-jp、shift_jis、euc-kr、x-mac-cyrillic、utf-16be、utf-16le。 <br/>-&nbsp; 默认值是：'utf-8'。 |


### constructor

constructor()

TextEncoder的构造函数，创建一个默认编码格式为'utf-8'的TextEncoder实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let textEncoder = new util.TextEncoder();
```

### constructor<sup>9+</sup>

constructor(encoding?: string)

TextEncoder的构造函数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| encoding | string | 否 | 编码格式，支持格式参见[encoding属性](#属性-2)，默认值为'utf-8'。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder("utf-8");
```

### create<sup>12+</sup>

static create(encoding?: string): TextEncoder

创建TextEncoder对象的方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| encoding | string | 否 | 编码格式，默认值为'utf-8'。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [TextEncoder](#textencoder) | 返回一个用于将字符串按指定编码格式编码为字节数组的TextEncoder对象。 |

**示例：**

```ts
let textEncoder = util.TextEncoder.create("utf-8");
```

### encodeInto<sup>9+</sup>

encodeInto(input?: string): Uint8Array

将输入参数编码后输出Uint8Array对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| input  | string | 否   | 需要编码的字符串，默认值是空字符串。当入参是空字符串时，返回undefined。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回编码后的Uint8Array对象。当入参为空字符串时，返回undefined。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder();
let result = textEncoder.encodeInto("\uD800¥¥");
console.info("result = " + result);
// 输出结果: result = 237,160,128,194,165,194,165
```

### encodeIntoUint8Array<sup>9+</sup>

encodeIntoUint8Array(input: string, dest: Uint8Array): EncodeIntoUint8ArrayInfo

对字符串进行编码，将结果存储到dest数组。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                                                    |
| ------ | ---------- | ---- | ------------------------------------------------------- |
| input  | string     | 是   | 需要编码的字符串。                                      |
| dest   | Uint8Array | 是   | Uint8Array对象实例，用于将生成的utf-8编码文本放入其中。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [EncodeIntoUint8ArrayInfo](#encodeintouint8arrayinfo11) | 返回一个对象，read表示已编码的字符数，written表示编码字符所占用的字节数。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder();
let buffer = new ArrayBuffer(4);
let uint8 = new Uint8Array(buffer);
let result = textEncoder.encodeIntoUint8Array('abcd', uint8);
console.info("uint8 = " + uint8);
// 输出结果: uint8 = 97,98,99,100
console.info("result.read = " + result.read);
// 输出结果: result.read = 4
console.info("result.written = " + result.written);
// 输出结果: result.written = 4
```

### encodeInto<sup>(deprecated)</sup>

encodeInto(input: string, dest: Uint8Array): { read: number; written: number }

将生成的utf-8编码文本写入dest数组。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[encodeIntoUint8Array<sup>9+</sup>](#encodeintouint8array9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | string | 是 | 需要编码的字符串。 |
| dest | Uint8Array | 是 | Uint8Array对象实例，用于将生成的utf-8编码文本放入其中。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| { read: number; written: number } | 返回一个对象，read表示已编码的字符数，written表示编码字符所占用的字节数。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder();
let buffer = new ArrayBuffer(4);
let uint8 = new Uint8Array(buffer);
let result = textEncoder.encodeInto('abcd', uint8);
console.info("uint8 = " + uint8);
// 输出结果: uint8 = 97,98,99,100
```

### encode<sup>(deprecated)</sup>

encode(input?: string): Uint8Array

将输入字符串编码后输出对应的Uint8Array字节数组。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[encodeInto<sup>9+</sup>](#encodeinto9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | string | 否 | 需要编码的字符串，默认值是空字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回编码后的文本。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder();
let result = textEncoder.encode("\uD800¥¥");
console.info("result = " + result);
// 输出结果: result = 237,160,128,194,165,194,165
```

## RationalNumber<sup>8+</sup>

RationalNumber主要用于有理数的比较，并提供获取分子和分母的方法。RationalNumber内部以分子和分母存储有理数，创建时会自动对分数进行简化。需要注意的是：当分母为0时，有理数表示为Infinity；当分子和分母均为0时，有理数表示为NaN（非数字）。使用[toString()](#tostring8)方法可以将有理数转换为字符串形式，使用该类可以方便地进行有理数的各种操作。

### constructor<sup>9+</sup>

constructor()

RationalNumber的构造函数，创建一个默认分子为0、分母为1的RationalNumber实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let rationalNumber = new util.RationalNumber();
```

### parseRationalNumber<sup>9+</sup>

static parseRationalNumber(numerator: number,denominator: number): RationalNumber

创建具有给定分子和分母的RationalNumber实例。

> **说明：**
>
> 该接口要求参数numerator和denominator必须是整数类型。如果传入的参数是小数类型，不会进行拦截，但是会输出错误信息："parseRationalNumber: The type of Parameter must be integer"。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明             |
| ----------- | ------ | ---- | ---------------- |
| numerator   | number | 是   | 分子，整数类型。取值范围：-Number.MAX_VALUE <= numerator <= Number.MAX_VALUE。|
| denominator | number | 是   | 分母，整数类型。取值范围：-Number.MAX_VALUE <= denominator <= Number.MAX_VALUE。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [RationalNumber](#rationalnumber8) | 具有给定分子和分母的RationalNumber有理数对象。 |

**示例：**

```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
```

### createRationalFromString<sup>8+</sup>

static createRationalFromString(rationalString: string): RationalNumber

使用给定的字符串创建RationalNumber对象。

> **说明：**
>
> 该接口要求参数rationalString是字符串格式。如果传入的参数是小数类型字符串格式，不会进行拦截，但是会输出错误信息："createRationalFromString: The type of Parameter must be integer string"。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| rationalString | string | 是 | 有理数字符串格式，如"3/4"。若传入小数类型字符串格式，不会拦截但会输出错误信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [RationalNumber](#rationalnumber8)​ | 由给定字符串创建的RationalNumber有理数对象。 |

**示例：**

```ts
let rational = util.RationalNumber.createRationalFromString("3/4");
```

### compare<sup>9+</sup>

compare(another: RationalNumber): number​

将当前RationalNumber对象与目标RationalNumber对象进行比较，并返回比较结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型           | 必填 | 说明               |
| ------- | -------------- | ---- | ------------------ |
| another | [RationalNumber](#rationalnumber8) | 是   | 其他的有理数对象。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 两个对象相等时返回0；给定对象小于当前对象时返回1；给定对象大于当前对象时返回-1。 |

**示例：**

```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.compare(rational);
console.info("result = " + result);
// 输出结果：result = -1
```

### valueOf<sup>8+</sup>

valueOf(): number

获取当前RationalNumber对象的整数或浮点数值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回整数或者浮点数的值。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.valueOf();
console.info("result = " + result);
// 输出结果：result = 0.5
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let result = rationalNumber.valueOf();
console.info("result = " + result);
// 输出结果：result = 0.5
```

### equals<sup>8+</sup>

equals(obj: Object): boolean

比较当前的RationalNumber对象与给定对象是否相等。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 用于与当前RationalNumber对象比较的对象，传入非RationalNumber类型时返回false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果给定对象与当前对象相同，则返回true；否则返回false。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.equals(rational);
console.info("result = " + result);
// 输出结果：result = false
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.equals(rational);
console.info("result = " + result);
// 输出结果：result = false
```

### getCommonFactor<sup>9+</sup>

static getCommonFactor(number1: number, number2: number): number

获取两个整数的最大公约数。

> **说明：**
>
> 该接口要求参数number1和number2必须是整数类型。如果传入的参数是小数类型，不会进行拦截，但是会输出错误信息："getCommonFactor: The type of Parameter must be integer"。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明       |
| ------- | ------ | ---- | ---------- |
| number1 | number | 是   | 整数类型。-Number.MAX_VALUE <= number1 <= Number.MAX_VALUE。|
| number2 | number | 是   | 整数类型。-Number.MAX_VALUE <= number2 <= Number.MAX_VALUE。|

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回两个给定数字的最大公约数。 |

**示例：**

```ts
let result = util.RationalNumber.getCommonFactor(4,6);
console.info("result = " + result);
// 输出结果：result = 2
```

### getNumerator<sup>8+</sup>

getNumerator(): number

获取当前RationalNumber对象的分子。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回RationalNumber对象的分子。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.getNumerator();
console.info("result = " + result);
// 输出结果：result = 1
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let result = rationalNumber.getNumerator();
console.info("result = " + result);
// 输出结果：result = 1
```

### getDenominator<sup>8+</sup>

getDenominator(): number

获取当前RationalNumber对象的分母。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回RationalNumber对象的分母。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.getDenominator();
console.info("result = " + result);
// 输出结果：result = 2
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2)
let result = rationalNumber.getDenominator();
console.info("result = " + result);
// 输出结果：result = 2
```

### isZero<sup>8+</sup>

isZero(): boolean

检查当前RationalNumber对象是否为0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果当前对象的值为0，则返回true；否则返回false。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.isZero();
console.info("result = " + result);
// 输出结果：result = false
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let result = rationalNumber.isZero();
console.info("result = " + result);
// 输出结果：result = false
```

### isNaN<sup>8+</sup>

isNaN(): boolean

检查当前RationalNumber对象是否表示非数字(NaN)值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果分母和分子都为0，则返回true；否则返回false。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.isNaN();
console.info("result = " + result);
// 输出结果：result = false
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let result = rationalNumber.isNaN();
console.info("result = " + result);
// 输出结果：result = false
```

### isFinite<sup>8+</sup>

isFinite(): boolean

检查RationalNumber对象是否表示一个有限值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果分母不为0，则返回true；否则返回false。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.isFinite();
console.info("result = " + result);
// 输出结果：result = true
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let result = rationalNumber.isFinite();
console.info("result = " + result);
// 输出结果：result = true
```

### toString<sup>8+</sup>

toString(): string

获取RationalNumber对象的字符串表示形式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回Numerator/Denominator格式的字符串，例如3/5，如果分子为0，则返回0/1。如果分母为0，则返回Infinity。如果分子和分母都为0，则返回NaN。|

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.toString();
console.info("result = " + result);
// 输出结果：result = 1/2
```
API 9及以上建议使用以下写法：
```ts
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);
let result = rationalNumber.toString();
console.info("result = " + result);
// 输出结果：result = 1/2
```

### constructor<sup>(deprecated)</sup>

constructor(numerator: number,denominator: number)

RationalNumber的构造函数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[parseRationalNumber<sup>9+</sup>](#parserationalnumber9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| numerator | number | 是 | 分子，整数类型。取值范围：-Number.MAX_VALUE <= numerator <= Number.MAX_VALUE。 |
| denominator | number | 是 | 分母，整数类型。取值范围：-Number.MAX_VALUE <= denominator <= Number.MAX_VALUE。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
```

### compareTo<sup>(deprecated)</sup>

compareTo(another: RationalNumber): number​

比较当前的RationalNumber对象与给定的对象。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[compare<sup>9+</sup>](#compare9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| another | RationalNumber | 是 | 其他的有理数对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 如果两个对象相等，则返回0；如果给定对象小于当前对象，则返回1；如果给定对象大于当前对象，则返回-1。 |

**示例：**

```ts
let rationalNumber = new util.RationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.compareTo(rational);
console.info("result = " + result);
// 输出结果：result = -1
```

### getCommonDivisor<sup>(deprecated)</sup>

static getCommonDivisor(number1: number,number2: number): number

获取两个指定整数的最大公约数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getCommonFactor<sup>9+</sup>](#getcommonfactor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| number1 | number | 是 | 整数类型。-Number.MAX_VALUE <= number1 <= Number.MAX_VALUE。 |
| number2 | number | 是 | 整数类型。-Number.MAX_VALUE <= number2 <= Number.MAX_VALUE。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回两个给定数字的最大公约数。 |



## LRUCache<sup>9+</sup>

LRUCache用于在缓存空间不足时，将近期最少使用的数据替换为新数据。此设计基于资源访问的考虑：近期访问的数据，可能在不久的将来会再次访问。因此最少访问的数据被认为价值最低，应当优先从缓存中移除。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称   | 类型   | 只读 | 可选 | 说明                   |
| ------ | ------ | ---- | ---- | ---------------------- |
| length | number | 是   | 否   | 当前缓存中值的总数。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
pro.put(1, 8);
let result = pro.length;
console.info('result = ' + result);
// 输出结果：result = 2
```

### constructor<sup>9+</sup>

constructor(capacity?: number)

默认构造函数用于创建一个新的LRUCache实例，默认容量为64。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- | ---------------------------- |
| capacity | number | 否   | 指示要为缓冲区自定义的容量，取值范围为[0, 2147483647]，默认值为64。 |

**示例：**

```ts
let lruCache = new util.LRUCache<number, number>();
```


### updateCapacity<sup>9+</sup>

updateCapacity(newCapacity: number): void

更新缓存容量为指定值，如果newCapacity小于或等于0，则抛出异常。当缓存中值的总数大于指定容量时，会执行删除操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明                         |
| ----------- | ------ | ---- | ---------------------------- |
| newCapacity | number | 是   | 指示要为缓冲区自定义的容量，取值范围为[0, 2147483647]。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.updateCapacity(100);
```

### toString<sup>9+</sup>

toString(): string

返回对象的字符串表示，格式为LRUCache[ maxSize = 缓存区最大值, hits = 查询匹配成功次数, misses = 查询匹配失败次数, hitRate = 查询匹配率 ]。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 返回对象的字符串表示形式。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
pro.get(2);
pro.get(3);
console.info(pro.toString());
// 输出结果：LRUCache[ maxSize = 64, hits = 1, misses = 1, hitRate = 50% ]
// maxSize: 缓存区最大值 hits: 查询值匹配成功的次数 misses: 查询值匹配失败的次数 hitRate: 查询值匹配率
```

### getCapacity<sup>9+</sup>

getCapacity(): number

获取当前缓存的容量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 返回当前缓冲区的容量。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
let result = pro.getCapacity();
console.info('result = ' + result);
// 输出结果：result = 64
```

### clear<sup>9+</sup>

clear(): void

清除当前缓冲区中的键值对，并触发afterRemoval回调方法执行后续操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
let result = pro.length;
pro.clear();
let res = pro.length;
console.info('result = ' + result);
console.info('res = ' + res);
// 输出结果：result = 1
// 输出结果：res = 0
```

### getCreateCount<sup>9+</sup>

getCreateCount(): number

获取对象创建的次数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                |
| ------ | -------------------|
| number | 返回创建对象的次数。 |

**示例：**

```ts
// 创建新类ChildLRUCache继承LRUCache，重写createDefault方法，返回一个非undefined的值。
class ChildLRUCache extends util.LRUCache<number, number> {
  constructor() {
    super();
  }

  createDefault(key: number): number {
    return key;
  }
}
let lru = new ChildLRUCache();
lru.put(2, 10);
lru.get(3);
lru.get(5);
let res = lru.getCreateCount();
console.info('res = ' + res);
// 输出结果：res = 2
```

### getMissCount<sup>9+</sup>

getMissCount(): number

获取查询值不匹配的次数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 返回查询值不匹配的次数。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
pro.get(2);
let result = pro.getMissCount();
console.info('result = ' + result);
// 输出结果：result = 0
```

### getRemovalCount<sup>9+</sup>

getRemovalCount(): number

获取缓存键值对的回收次数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回缓冲区键值对回收的次数。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
pro.updateCapacity(2);
pro.put(50, 22);
let result = pro.getRemovalCount();
console.info('result = ' + result);
// 输出结果：result = 0
```

### getMatchCount<sup>9+</sup>

getMatchCount(): number

获取查询值匹配成功的次数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回查询值匹配成功的次数。 |

**示例：**

  ```ts
  let pro = new util.LRUCache<number, number>();
  pro.put(2, 10);
  pro.get(2);
  let result = pro.getMatchCount();
  console.info('result = ' + result);
  // 输出结果：result = 1
  ```

### getPutCount<sup>9+</sup>

getPutCount(): number

获取将值添加到缓存的次数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | 返回将值添加到缓冲区的次数。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
let result = pro.getPutCount();
console.info('result = ' + result);
// 输出结果：result = 1
```

### isEmpty<sup>9+</sup>

isEmpty(): boolean

检查缓存是否为空。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                     |
| ------- | ---------------------------------------- |
| boolean | 如果缓存不包含任何值，则返回true；否则返回false。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
let result = pro.isEmpty();
console.info('result = ' + result);
// 输出结果：result = false
```

### get<sup>9+</sup>

get(key: K): V | undefined

返回键对应的值。当键不在缓存中时，通过[createDefault](#createdefault9)接口创建，若createDefault创建的值不为undefined时，此时会调用[afterRemoval](#afterremoval9)接口，返回createDefault创建的值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | ---- | ---- | ------------ |
| key    | K    | 是   | 要查询的键。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| V \| undefined | 如果指定的键存在于缓冲区中，则返回与键关联的值；否则返回createDefault创建的值。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
let result  = pro.get(2);
console.info('result = ' + result);
// 输出结果：result = 10
```

### put<sup>9+</sup>

put(key: K,value: V): V

将键值对添加到缓存，返回与添加的键关联的值。当缓存中值的总数超过容量时，执行删除操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                       |
| ------ | ---- | ---- | -------------------------- |
| key    | K    | 是   | 要添加的键。             |
| value  | V    | 是   | 指示与要添加的键关联的值。 |

**返回值：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| V    | 返回与添加的键关联的值。如果键或值为空，则抛出此异常。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
let result = pro.put(2, 10);
console.info('result = ' + result);
// 输出结果：result = 10
```

### values<sup>9+</sup>

values(): V[]

获取当前缓存中所有值，从最近最少访问到最近访问的顺序列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| V[] | 返回当前缓冲区中所有值的列表，顺序为从最近最少访问（Least Recent）到最近访问（Most Recent）。 |

**示例：**

```ts
let pro = new util.LRUCache<number, string>();
pro.put(1, 'A');
pro.put(2, "B");
pro.put(3, 'C');
pro.put(4, 'D')
pro.put(5, 'E')
pro.put(6, 'F')
let result = pro.values();
console.info('result = ' + result);
// 输出结果：result = A,B,C,D,E,F
pro.get(1);
pro.get(2);
result = pro.values();
console.info('result = ' + result);
// 输出结果：result = C,D,E,F,A,B
```

### keys<sup>9+</sup>

keys(): K[]

获取当前缓存中所有键，从最近最少访问到最近访问的顺序列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| K[] | 返回当前缓冲区中所有键的列表，顺序为从最近最少访问（Least Recent）到最近访问（Most Recent）。 |

**示例：**

```ts
let pro = new util.LRUCache<number, string>();
pro.put(1, 'A');
pro.put(2, "B");
pro.put(3, 'C');
pro.put(4, 'D')
pro.put(5, 'E')
pro.put(6, 'F')
let result = pro.keys();
console.info('result = ' + result);
// 输出结果：result = 1,2,3,4,5,6
pro.get(5);
pro.get(3);
result = pro.keys();
console.info('result = ' + result);
// 输出结果：result = 1,2,4,6,5,3
```

### remove<sup>9+</sup>

remove(key: K): V | undefined

从当前缓存中删除指定的键及其关联的值，并返回键关联的值。如果指定的键不存在，则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| key    | K    | 是   | 要删除的键。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| V&nbsp;\|&nbsp;undefined | 返回与已删除键关联的值；如果key不存在，则返回undefined，如果key为null，则抛出异常。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
let result = pro.remove(20);
console.info('result = ' + result);
// 输出结果：result = undefined
```

### afterRemoval<sup>9+</sup>

afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void

删除值后执行后续操作，这些操作由开发者自行实现。本接口会在删除操作时被调用，如[get<sup>9+</sup>](#get9)、[put<sup>9+</sup>](#put9)、[remove<sup>9+</sup>](#remove9)、[clear<sup>9+</sup>](#clear9)、[updateCapacity<sup>9+</sup>](#updatecapacity9)接口。

> **说明：**
>
> 若此回调方法在[clear<sup>9+</sup>](#clear9)、[updateCapacity<sup>9+</sup>](#updatecapacity9)接口调用之后触发执行，传入的key和value参数类型为MapIterator，可参照示例二进行后续操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| isEvict  | boolean | 是   | 当因容量不足而调用该方法时，参数值设置为true，其他情况设置为false。    |
| key      | K       | 是   | 表示删除的键。                                               |
| value    | V       | 是   | 表示删除的值。                                               |
| newValue | V       | 是   | 如果已调用put方法并且要添加的键已经存在，则参数值是关联的新值。其他情况下参数值为空。 |

**示例一：**

```ts
class ChildLRUCache<K, V> extends util.LRUCache<K, V> {
  constructor(capacity?: number) {
    super(capacity);
  }

  afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void {
    if (isEvict === true) {
      console.info('key = ' + key);
      // 输出结果：key = 1
      console.info('value = ' + value);
      // 输出结果：value = 1
      console.info('newValue = ' + newValue);
      // 输出结果：newValue = null
    }
  }
}
let lru = new ChildLRUCache<number, number>(2);
lru.put(1, 1);
lru.put(2, 2);
lru.put(3, 3);
```

**示例二：**

```ts
class TestClass {
  str:string = '';
  constructor(input: string) {
    this.str = input;
  }
}

class ChildLRUCache extends util.LRUCache<string, TestClass> {
  constructor(capacity?: number) {
    super(capacity);
  }

  afterRemoval(isEvict: boolean, key: string, value: TestClass, newValue: TestClass): void {
    if(value.toString().indexOf('[object Map Iterator]') >= 0) {
      console.info('调用clear进入');
      console.info('isEvict = ' + isEvict);
      const keysIterator = (key as ESObject as IterableIterator<string>);
      const valuesIterator = (value as ESObject as IterableIterator<TestClass>);

      let keyEntry = keysIterator.next();
      let valueEntry = valuesIterator.next();
      while (!keyEntry.done && !valueEntry.done) {
        console.info(`key = ${keyEntry.value}, valueStr = ${valueEntry.value.str}`);
        keyEntry = keysIterator.next();
        valueEntry = valuesIterator.next();
      }
    } else {
      console.info('调用put进入');
      console.info('isEvict = ' + isEvict);
      console.info('key = ' + key + '  valueStr = ' + value.str);
    }
  }
}
let test1 = new TestClass('testA');
let test2 = new TestClass('testB');
let test3 = new TestClass('testC');
let lru = new ChildLRUCache(2);
lru.put('aa', test1);
lru.put('bb', test2);
lru.put('cc', test3);    // 删除'aa'键值对
lru.clear();             // 清空整个缓冲区
/*
输出结果：调用put进入
         isEvict = true
         key = aa  valueStr = testA
         调用clear进入
         isEvict = false
         key = bb, valueStr = testB
         key = cc, valueStr = testC
 */
```

### contains<sup>9+</sup>

contains(key: K): boolean

检查当前缓存是否包含指定的键。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| key    | K | 是   | 要检查的键。 |

**返回值：**

| 类型    | 说明                                       |
| ------- | ------------------------------------------ |
| boolean | 如果缓存包含指定的键，则返回true；否则返回false。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
let result = pro.contains(2);
console.info('result = ' + result);
// 输出结果：result = true
```

### createDefault<sup>9+</sup>

createDefault(key: K): V

如果在缓存中未匹配到键，则执行后续操作，参数表示未匹配的键，返回与键关联的值，默认返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| key    | K    | 是   | 表示未匹配的键。 |

**返回值：**

| 类型 | 说明               |
| ---- | ------------------ |
| V    | 返回与键关联的值。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
let result = pro.createDefault(50);
console.info('result = ' + result);
// 输出结果：result = undefined
```

### entries<sup>9+</sup>

entries(): IterableIterator&lt;[K, V]&gt;

返回一个迭代器对象，用于按插入顺序遍历当前对象中的所有键值对（[key, value]）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型        | 说明                 |
| ----------- | -------------------- |
| IterableIterator&lt;[K, V]&gt; | 返回一个迭代器对象，用于按插入顺序遍历当前缓冲区中的所有键值对[key, value]。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
pro.put(3, 15);
let pair = pro.entries();
for (let value of pair) {
  console.info(value[0]+ ', '+ value[1]);
}
// 输出结果：
// 2, 10
// 3, 15
```

### [Symbol.iterator]<sup>9+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回键值对形式的二维数组。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型        | 说明                           |
| ----------- | ------------------------------ |
| IterableIterator&lt;[K, V]&gt; | 返回一个键值对形式的二维数组。 |

**示例：**

```ts
let pro = new util.LRUCache<number, number>();
pro.put(2, 10);
pro.put(3, 15);

for (let value of pro) {
  console.info(value[0]+ ', '+ value[1]);
}
// 输出结果：
// 2, 10
// 3, 15
```

## ScopeComparable<sup>8+</sup>

ScopeComparable类型的值需要实现compareTo方法，确保传入的数据具有可比性。

**系统能力：** SystemCapability.Utils.Lang

### compareTo<sup>8+</sup>

compareTo(other: ScopeComparable): boolean

比较两个值的大小，返回一个布尔值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| other  | [ScopeComparable](#scopecomparable8) | 是  | 表示要比较的值。 |

**返回值：**

| 类型 | 说明               |
| ---- | ------------------ |
| boolean | 调用compareTo的值大于等于传入的值返回true，否则返回false。|

**示例：**

构造新类，实现compareTo方法。后续示例代码中，均以此Temperature类为例。

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}
```

## ScopeType<sup>8+</sup>

type ScopeType = ScopeComparable | number

表示范围中的值的类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 类型 | 说明 |
| -------- | -------- |
| number | 表示值的类型为数字。 |
| [ScopeComparable](#scopecomparable8) | 表示值的类型为ScopeComparable。|

## ScopeHelper<sup>9+</sup>

ScopeHelper接口用于描述一个字段的有效范围，常用于输入值范围校验、配置参数区间判断等场景。构造函数用于创建具有指定下限和上限的对象，并要求这些对象必须具有可比性。通过ScopeHelper，开发者可以方便地进行范围交集、并集计算以及值是否在范围内的判断，避免无效数据进入业务逻辑。

### constructor<sup>9+</sup>

constructor(lowerObj: ScopeType, upperObj: ScopeType)

创建指定下限和上限的作用域实例，返回一个ScopeHelper对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                     | 必填 | 说明                   |
| -------- | ------------------------ | ---- | ---------------------- |
| lowerObj | [ScopeType](#scopetype8) | 是   | 指定作用域实例的下限，需具有可比性。 |
| upperObj | [ScopeType](#scopetype8) | 是   | 指定作用域实例的上限，需具有可比性。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
console.info("range = " + range);
// 输出结果：range = [30, 40]
```

### toString<sup>9+</sup>

toString(): string

该字符串化方法返回当前范围的字符串表示形式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| string | 返回当前范围的字符串表示形式。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.toString();
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### intersect<sup>9+</sup>

intersect(range: ScopeHelper): ScopeHelper

获取给定范围和当前范围的交集。当交集为空集时，抛出异常。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                         | 必填 | 说明               |
| ------ | ---------------------------- | ---- | ------------------ |
| range  | [ScopeHelper](#scopehelper9) | 是   | 传入给定范围。 |

**返回值：**

| 类型                           | 说明                           |
| ------------------------------ | ------------------------------ |
| [ScopeHelper](#scopehelper9) | 返回给定范围和当前范围的交集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let rangeFir = new util.ScopeHelper(tempMiDF, tempMidS);
let result = range.intersect(rangeFir);
console.info("result = " + result);
// 输出结果：result = [35, 39]
```

### intersect<sup>9+</sup>

intersect(lowerObj:ScopeType,upperObj:ScopeType):ScopeHelper

获取当前范围与指定下限和上限范围的交集。当交集为空集时，抛出异常。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                     | 必填 | 说明             |
| -------- | ------------------------ | ---- | ---------------- |
| lowerObj | [ScopeType](#scopetype8) | 是   | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是   | 给定范围的上限。 |

**返回值：**

| 类型                         | 说明                                     |
| ---------------------------- | ---------------------------------------- |
| [ScopeHelper](#scopehelper9) | 返回当前范围与给定下限和上限范围的交集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.intersect(tempMiDF, tempMidS);
console.info("result = " + result);
// 输出结果：result = [35, 39]
```

### getUpper<sup>9+</sup>

getUpper(): ScopeType

获取当前范围的上限。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                     | 说明                   |
| ------------------------ | ---------------------- |
| [ScopeType](#scopetype8) | 返回当前范围的上限值。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.getUpper();
console.info("result = " + result);
// 输出结果：result = 40
```

### getLower<sup>9+</sup>

getLower(): ScopeType

获取当前范围的下限。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                     | 说明                   |
| ------------------------ | ---------------------- |
| [ScopeType](#scopetype8) | 返回当前范围的下限值。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.getLower();
console.info("result = " + result);
// 输出结果：result = 30
```

### expand<sup>9+</sup>

expand(lowerObj: ScopeType,upperObj: ScopeType): ScopeHelper

创建并返回当前范围与给定下限和上限的并集。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                     | 必填 | 说明             |
| -------- | ------------------------ | ---- | ---------------- |
| lowerObj | [ScopeType](#scopetype8) | 是   | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是   | 给定范围的上限。 |

**返回值：**

| 类型                         | 说明                                 |
| ---------------------------- | ------------------------------------ |
| [ScopeHelper](#scopehelper9) | 返回当前范围和给定下限和上限的并集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.expand(tempMiDF, tempMidS);
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### expand<sup>9+</sup>

expand(range: ScopeHelper): ScopeHelper

创建并返回当前范围和给定范围的并集。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                         | 必填 | 说明               |
| ------ | ---------------------------- | ---- | ------------------ |
| range  | [ScopeHelper](#scopehelper9) | 是   | 传入一个给定范围。 |

**返回值：**

| 类型                         | 说明                               |
| ---------------------------- | ---------------------------------- |
| [ScopeHelper](#scopehelper9) | 返回包括当前范围和给定范围的并集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.ScopeHelper(tempLower, tempUpper);
let rangeFir = new util.ScopeHelper(tempMiDF, tempMidS);
let result = range.expand(rangeFir);
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### expand<sup>9+</sup>

expand(value: ScopeType): ScopeHelper

创建并返回当前范围和给定值的并集。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                     | 必填 | 说明             |
| ------ | ------------------------ | ---- | ---------------- |
| value  | [ScopeType](#scopetype8) | 是   | 要检查是否在当前范围内的值。 |

**返回值：**

| 类型                         | 说明                             |
| ---------------------------- | -------------------------------- |
| [ScopeHelper](#scopehelper9) | 返回包括当前范围和给定值的并集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.expand(tempMiDF);
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### contains<sup>9+</sup>

contains(value: ScopeType): boolean

检查给定value是否在当前范围内。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                     | 必填 | 说明             |
| ------ | ------------------------ | ---- | ---------------- |
| value  | [ScopeType](#scopetype8) | 是   | 传入一个给定值。 |

**返回值：**

| 类型    | 说明                                                |
| ------- | --------------------------------------------------- |
| boolean | 如果给定值包含在当前范围内返回true，否则返回false。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.contains(tempMiDF);
console.info("result = " + result);
// 输出结果：result = true
```

### contains<sup>9+</sup>

contains(range: ScopeHelper): boolean

检查给定range是否在当前范围内。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                         | 必填 | 说明               |
| ------ | ---------------------------- | ---- | ------------------ |
| range  | [ScopeHelper](#scopehelper9) | 是   | 传入一个给定范围。 |

**返回值：**

| 类型    | 说明                                                  |
| ------- | ----------------------------------------------------- |
| boolean | 如果给定范围在当前范围内则返回true，否则返回false。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let tempLess = new Temperature(20);
let tempMore = new Temperature(45);
let rangeSec = new util.ScopeHelper(tempLess, tempMore);
let result = range.contains(rangeSec);
console.info("result = " + result);
// 输出结果：result = false
```

### clamp<sup>9+</sup>

clamp(value: ScopeType): ScopeType

将值限定到当前范围内。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                     | 必填 | 说明           |
| ------ | ------------------------ | ---- | -------------- |
| value  | [ScopeType](#scopetype8) | 是   | 传入的给定值。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| [ScopeType](#scopetype8) | 如果传入的value小于下限，返回lowerObj；如果大于上限值，返回upperObj；如果在当前范围内，返回value。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.clamp(tempMiDF);
console.info("result = " + result);
// 输出结果：result = 35
```

## Base64Helper<sup>9+</sup>

Base64Helper类提供Base64编解码和Base64URL编解码功能。Base64编码表包含A-Z、a-z、0-9这62个字符，以及"+"和"/"这两个特殊字符。在编码时，将原始数据按3个字节一组进行划分，得到若干个6位的数字，然后使用Base64编码表中对应的字符来表示这些数字。如果最后剩余1或2个字节，则需要使用"="字符进行补齐。Base64URL编码表包含A-Z、a-z、0-9以及"-"和"_"64个字符，Base64URL编码结果不含"="。

### constructor<sup>9+</sup>

constructor()

Base64Helper的构造函数，创建一个用于Base64编解码的Base64Helper实例。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**示例：**

  ```ts
  let base64 = new util.Base64Helper();
  ```

### encodeSync<sup>9+</sup>

encodeSync(src: Uint8Array, options?: Type): Uint8Array

通过输入参数编码后输出Uint8Array对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| src    | Uint8Array | 是   | 待编码的Uint8Array对象。 |
| options<sup>12+</sup> | [Type](#type10) | 否 | 从API version 12开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.BASIC_URL_SAFE，默认值为：util.Type.BASIC。<br/>util.Type.BASIC表示Base64编码。<br/>util.Type.BASIC_URL_SAFE表示Base64URL编码。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| Uint8Array | 返回编码后的Uint8Array对象。 |

**示例：**

  ```ts
  let base64Helper = new util.Base64Helper();
  let array = new Uint8Array([115,49,51]);
  let result = base64Helper.encodeSync(array);
  console.info("result = " + result);
  // 输出结果：result = 99,122,69,122
  ```


### encodeToStringSync<sup>9+</sup>

encodeToStringSync(src: Uint8Array, options?: Type): string

将输入的Uint8Array字节数组进行Base64编码，返回一个字符串结果。该方法支持多种编码格式，包括标准Base64编码、MIME格式的Base64编码（带有换行符）、URL安全格式的Base64编码等。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| src    | Uint8Array | 是   | 待编码Uint8Array对象。 |
| options<sup>10+</sup>    | [Type](#type10) | 否   | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC，util.Type.MIME，util.Type.BASIC_URL_SAFE 和util.Type.MIME_URL_SAFE，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC，表示Base64编码，返回值没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME，表示使用Base64编码。如果返回值超过76个字符，则会在每76个字符处进行换行，并以'\r\n'结束每行。如果返回值少于76个字符，则会抛出异常。<br/>- 当参数取值为util.Type.BASIC_URL_SAFE，表示Base64URL编码，返回值没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME_URL_SAFE，表示Base64URL编码，返回值每一行不超过76个字符，而且每行以'\r\n'符结束。 |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回编码后的字符串。 |

**示例：**

  ```ts
  // MIME编码
  let base64Helper = new util.Base64Helper();
  let array =
    new Uint8Array([77, 97, 110, 105, 115, 100, 105, 115, 116, 105, 110, 103, 117, 105, 115, 104, 101, 100, 110, 111, 116,
      111, 110, 108, 121, 98, 121, 104, 105, 115, 114, 101, 97, 115, 111, 110, 98, 117, 116, 98, 121, 116, 104, 105, 115,
      115, 105, 110, 103, 117, 108, 97, 114, 112, 97, 115, 115, 105, 111, 110, 102, 114, 111, 109, 111, 116, 104, 101,
      114, 97, 110, 105, 109, 97, 108, 115, 119, 104, 105, 99, 104, 105, 115, 97, 108, 117, 115, 116, 111, 102, 116, 104,
      101, 109, 105, 110, 100, 101, 120, 99, 101, 101, 100, 115, 116, 104, 101, 115, 104, 111, 114, 116, 118, 101, 104,
      101, 109, 101, 110, 99, 101, 111, 102, 97, 110, 121, 99, 97, 114, 110, 97, 108, 112, 108, 101, 97, 115, 117, 114,
      101]);
  let result = base64Helper.encodeToStringSync(array, util.Type.MIME);
  console.info("result = " + result);
  /*
  输出结果：result = TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz
  aW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl
  aGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=
   */

  // BASIC编码
  let base64Helper = new util.Base64Helper();
  let array =
    new Uint8Array([77, 97, 110, 105, 115, 100, 105, 115, 116, 105, 110, 103, 117, 105, 115, 104, 101, 100, 110, 111, 116,
      111, 110, 108, 121, 98, 121, 104, 105, 115, 114, 101, 97, 115, 111, 110, 98, 117, 116, 98, 121, 116, 104, 105, 115,
      115, 105, 110, 103, 117, 108, 97, 114, 112, 97, 115, 115, 105, 111, 110, 102, 114, 111, 109, 111, 116, 104, 101,
      114, 97, 110, 105, 109, 97, 108, 115, 119, 104, 105, 99, 104, 105, 115, 97, 108, 117, 115, 116, 111, 102, 116, 104,
      101, 109, 105, 110, 100, 101, 120, 99, 101, 101, 100, 115, 116, 104, 101, 115, 104, 111, 114, 116, 118, 101, 104,
      101, 109, 101, 110, 99, 101, 111, 102, 97, 110, 121, 99, 97, 114, 110, 97, 108, 112, 108, 101, 97, 115, 117, 114,
      101]);
  let result = base64Helper.encodeToStringSync(array, util.Type.BASIC);
  console.info("result = " + result);
  /*
  输出结果：result = TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNzaW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZlaGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=
   */
  
  // MIME_URL_SAFE编码
  let base64Helper = new util.Base64Helper();
  let array =
    new Uint8Array([77, 97, 110, 105, 115, 100, 105, 115, 116, 105, 110, 103, 117, 105, 115, 104, 101, 100, 110, 111, 116,
      111, 110, 108, 121, 98, 121, 104, 105, 115, 114, 101, 97, 115, 111, 110, 98, 117, 116, 98, 121, 116, 104, 105, 115,
      115, 105, 110, 103, 117, 108, 97, 114, 112, 97, 115, 115, 105, 111, 110, 102, 114, 111, 109, 111, 116, 104, 101,
      114, 97, 110, 105, 109, 97, 108, 115, 119, 104, 105, 99, 104, 105, 115, 97, 108, 117, 115, 116, 111, 102, 116, 104,
      101, 109, 105, 110, 100, 101, 120, 99, 101, 101, 100, 115, 116, 104, 101, 115, 104, 111, 114, 116, 118, 101, 104,
      101, 109, 101, 110, 99, 101, 111, 102, 97, 110, 121, 99, 97, 114, 110, 97, 108, 112, 108, 101, 97, 115, 117, 114,
      101]);
  let result = base64Helper.encodeToStringSync(array, util.Type.BASIC_URL_SAFE);
  console.info("result = " + result);
  /*
  输出结果：result = TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNzaW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZlaGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU
   */
  // MIME_URL_SAFE编码
  let base64Helper = new util.Base64Helper();
  let array =
    new Uint8Array([77, 97, 110, 105, 115, 100, 105, 115, 116, 105, 110, 103, 117, 105, 115, 104, 101, 100, 110, 111, 116,
      111, 110, 108, 121, 98, 121, 104, 105, 115, 114, 101, 97, 115, 111, 110, 98, 117, 116, 98, 121, 116, 104, 105, 115,
      115, 105, 110, 103, 117, 108, 97, 114, 112, 97, 115, 115, 105, 111, 110, 102, 114, 111, 109, 111, 116, 104, 101,
      114, 97, 110, 105, 109, 97, 108, 115, 119, 104, 105, 99, 104, 105, 115, 97, 108, 117, 115, 116, 111, 102, 116, 104,
      101, 109, 105, 110, 100, 101, 120, 99, 101, 101, 100, 115, 116, 104, 101, 115, 104, 111, 114, 116, 118, 101, 104,
      101, 109, 101, 110, 99, 101, 111, 102, 97, 110, 121, 99, 97, 114, 110, 97, 108, 112, 108, 101, 97, 115, 117, 114,
      101]);
  let result = base64Helper.encodeToStringSync(array, util.Type.MIME_URL_SAFE);
  console.info("result = " + result);
  /*
  输出结果：result = TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz
  aW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl
  aGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU
   */
  ```

### decodeSync<sup>9+</sup>

decodeSync(src: Uint8Array | string, options?: Type): Uint8Array

将输入参数解码后输出对应Uint8Array对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                           | 必填 | 说明                          |
| ------ | ------------------------------ | ---- | ----------------------------- |
| src    | Uint8Array&nbsp;\|&nbsp;string | 是   | 待解码的Uint8Array对象或者字符串。 |
| options<sup>10+</sup>    | [Type](#type10) | 否   | 从API version 10开始支持该参数，表示对应的解码格式。<br/>此参数可选，可选值为：util.Type.BASIC，util.Type.MIME，util.Type.BASIC_URL_SAFE和util.Type.MIME_URL_SAFE，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC，表示Base64解码。<br/>- 当参数取值为util.Type.MIME，表示Base64解码，src入参包含回车符、换行符。<br/>- 当参数取值为util.Type.BASIC_URL_SAFE，表示Base64URL解码。<br/>- 当参数取值为util.Type.MIME_URL_SAFE，表示Base64URL解码，src入参包含回车符、换行符。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| Uint8Array | 返回解码后新分配的Uint8Array对象。 |

**示例：**

  ```ts
  let base64Helper = new util.Base64Helper();
  let buff = 'TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz\r\naW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl\r\naGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=\r\n';
  let result = base64Helper.decodeSync(buff, util.Type.MIME);
  console.info("result = " + result);
  /*
  输出结果：result = 77,97,110,105,115,100,105,115,116,105,110,103,117,105,115,104,101,100,110,111,116,111,110,108,121,98,121,104,105,115,114,101,97,115,111,110,98,117,116,98,121,116,104,105,115,115,105,110,103,117,108,97,114,112,97,115,115,105,111,110,102,114,111,109,111,116,104,101,114,97,110,105,109,97,108,115,119,104,105,99,104,105,115,97,108,117,115,116,111,102,116,104,101,109,105,110,100,101,120,99,101,101,100,115,116,104,101,115,104,111,114,116,118,101,104,101,109,101,110,99,101,111,102,97,110,121,99,97,114,110,97,108,112,108,101,97,115,117,114,101
   */
  ```


### encode<sup>9+</sup>

encode(src: Uint8Array, options?: Type): Promise&lt;Uint8Array&gt;

将输入参数异步编码后输出对应Uint8Array对象。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                    |
| ------ | ---------- | ---- | ----------------------- |
| src    | Uint8Array | 是   | 待编码Uint8Array对象。 |
| options<sup>12+</sup> | [Type](#type10) | 否 | 从API version 12开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.BASIC_URL_SAFE，默认值为：util.Type.BASIC。<br/>util.Type.BASIC表示Base64编码。<br/>util.Type.BASIC_URL_SAFE表示Base64URL编码。 |

**返回值：**

| 类型                      | 说明                              |
| ------------------------- | --------------------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象。编码成功时resolve为新分配的Uint8Array对象，编码失败时reject为错误对象。 |

**示例：**

  ```ts
  let base64Helper = new util.Base64Helper();
  let array = new Uint8Array([115,49,51]);
  base64Helper.encode(array).then((val) => {
    console.info(val.toString());
    // 输出结果：99,122,69,122
  })
  ```


### encodeToString<sup>9+</sup>

encodeToString(src: Uint8Array, options?: Type): Promise&lt;string&gt;

将输入参数异步编码后输出对应文本。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                    |
| ------ | ---------- | ---- | ----------------------- |
| src    | Uint8Array | 是   | 异步编码输入Uint8Array对象。 |
| options<sup>10+</sup>    | [Type](#type10) | 否   | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC，util.Type.MIME，util.Type.BASIC_URL_SAFE和util.Type.MIME_URL_SAFE，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC，表示Base64编码，返回值没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME，表示Base64编码，返回值每一行不超过76个字符，而且每行以'\r\n'符结束。<br/>- 当参数取值为util.Type.BASIC_URL_SAFE，表示Base64URL编码，返回值没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME_URL_SAFE，表示Base64URL编码，返回值每一行不超过76个字符，而且每行以'\r\n'符结束。 |

**返回值：**

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| Promise&lt;string&gt; | Promise对象。编码成功时resolve为Base64编码后的字符串，编码失败时reject为错误对象。 |

**示例：**

  ```ts
  let base64Helper = new util.Base64Helper();
  let array = new Uint8Array([77,97,110,105,115,100,105,115,116,105,110,103,117,105,115,104,101,100,110,111,116,111,110,108,121,98,121,104,105,115,114,101,97,115,111,110,98,117,116,98,121,116,104,105,115,115,105,110,103,117,108,97,114,112,97,115,115,105,111,110,102,114,111,109,111,116,104,101,114,97,110,105,109,97,108,115,119,104,105,99,104,105,115,97,108,117,115,116,111,102,116,104,101,109,105,110,100,101,120,99,101,101,100,115,116,104,101,115,104,111,114,116,118,101,104,101,109,101,110,99,101,111,102,97,110,121,99,97,114,110,97,108,112,108,101,97,115,117,114,101]);
  base64Helper.encodeToString(array, util.Type.MIME).then((val) => {
    console.info(val);
    /*
    输出结果：TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz
    aW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl
    aGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=
     */

  })
  ```


### decode<sup>9+</sup>

decode(src: Uint8Array | string, options?: Type): Promise&lt;Uint8Array&gt;

将输入参数异步解码后输出对应Uint8Array对象。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                           | 必填 | 说明                              |
| ------ | ------------------------------ | ---- | --------------------------------- |
| src    | Uint8Array&nbsp;\|&nbsp;string | 是   | 异步解码输入Uint8Array对象或者字符串。 |
| options<sup>10+</sup>    | [Type](#type10) | 否   | 从API version 10开始支持该参数，表示对应的解码格式。<br/>此参数可选，可选值为：util.Type.BASIC，util.Type.MIME，util.Type.BASIC_URL_SAFE和util.Type.MIME_URL_SAFE，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，表示Base64解码。<br/>- 当参数取值为util.Type.MIME时，表示Base64解码，src入参包含回车符、换行符。<br/>- 当参数取值为util.Type.BASIC_URL_SAFE，表示Base64URL解码。<br/>- 当参数取值为util.Type.MIME_URL_SAFE，表示Base64URL解码，src入参包含回车符、换行符。 |

**返回值：**

| 类型                      | 说明                              |
| ------------------------- | --------------------------------- |
| Promise&lt;Uint8Array&gt; | 返回异步解码后新分配的Uint8Array对象。 |

**示例：**

  ```ts
  let base64Helper = new util.Base64Helper();
  let array = 'TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz\r\naW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl\r\naGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=\r\n';
  base64Helper.decode(array, util.Type.MIME).then((val) => {
    console.info(val.toString());
    /*
    输出结果：77,97,110,105,115,100,105,115,116,105,110,103,117,105,115,104,101,100,110,111,116,111,110,108,121,98,121,104,105,115,114,101,97,115,111,110,98,117,116,98,121,116,104,105,115,115,105,110,103,117,108,97,114,112,97,115,115,105,111,110,102,114,111,109,111,116,104,101,114,97,110,105,109,97,108,115,119,104,105,99,104,105,115,97,108,117,115,116,111,102,116,104,101,109,105,110,100,101,120,99,101,101,100,115,116,104,101,115,104,111,114,116,118,101,104,101,109,101,110,99,101,111,102,97,110,121,99,97,114,110,97,108,112,108,101,97,115,117,114,101
     */
  })
  ```

## StringDecoder<sup>12+</sup>

提供将二进制流解码为字符串的能力。支持的编码类型包括：utf-8、iso-8859-2、koi8-r、macintosh、windows-1250、windows-1251、gbk、gb18030、big5、utf-16be、utf-16le等。

### constructor<sup>12+</sup>

constructor(encoding?: string)

StringDecoder的构造函数，创建一个默认编码为'utf-8'的StringDecoder实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                           | 必填 | 说明                              |
| ------ | ------------------------------ | ---- | --------------------------------- |
| encoding  | string | 否   | 输入数据的编码类型。默认值：'utf-8'。 |

**示例：**

  ```ts
  let decoder = new util.StringDecoder();
  ```

### write<sup>12+</sup>

write(chunk: string | Uint8Array): string

返回一个解码后的字符串，确保Uint8Array末尾的任何不完整的多字节字符从返回的字符串中被过滤，并保存在一个内部的buffer中用于下次调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| chunk  | string \| Uint8Array | 是   | 需要解码的字符串。会根据输入的编码类型进行解码，参数为Uint8Array时正常解码，参数为string时会将参数直接返回。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| string | 返回解码后的字符串，不完整的多字节字符已从返回值中过滤，并保存在内部缓冲区中供下次调用处理。 |

**示例：**

  ```ts
  let decoder = new util.StringDecoder('utf-8');
  let input =  new Uint8Array([0xE4, 0xBD, 0xA0, 0xE5, 0xA5, 0xBD]);
  const decoded = decoder.write(input);
  console.info("decoded:", decoded);
  // 输出结果：decoded: 你好
  ```

### end<sup>12+</sup>

end(chunk?: string | Uint8Array): string

结束解码过程，以字符串形式返回存储在内部缓冲区中的所有剩余输入。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| chunk  | string \| Uint8Array | 否   | 需要解码的最后一部分数据。当还有剩余数据需要在结束解码时一并处理时传入此参数；不传入时默认为undefined，即仅返回内部缓冲区中存储的不完整字节序列的解码结果，不再处理新数据。要解码的字符串。默认为undefined。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| string | 返回存储在内部缓冲区中的所有剩余解码内容组成的字符串。 |

**示例：**

  ```ts
  let decoder = new util.StringDecoder('utf-8');
  let input = new Uint8Array([0xE4, 0xBD, 0xA0, 0xE5, 0xA5, 0xBD]);
  const writeString = decoder.write(input.slice(0, 5));
  const endString = decoder.end(input.slice(5));
  console.info("writeString:", writeString);
  // 输出结果：writeString: 你
  console.info("endString:", endString);
  // 输出结果：endString: 好
  ```

## Type<sup>10+</sup>

Base64编码格式枚举。

**系统能力：** SystemCapability.Utils.Lang


| 名称   |值| 说明               |
| ----- |---| ----------------- |
| BASIC | 0 | 表示BASIC编码格式。**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MIME  | 1 | 表示MIME编码格式。**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| BASIC_URL_SAFE<sup>12+</sup> | 2 | 表示BASIC_URL_SAFE编码格式。<br/>从API version 12开始支持此枚举。**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| MIME_URL_SAFE<sup>12+</sup> | 3 | 表示MIME_URL_SAFE编码格式。<br/>从API version 12开始支持此枚举。**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |


## types<sup>8+</sup>

types为不同类型的内置对象提供类型检查，可以避免由于类型错误导致的异常。该模块包含了多个工具函数，用于判断JS对象是否属于各种类型，例如：ArrayBuffer、Map、Set等。

### constructor<sup>8+</sup>

constructor()

Types的构造函数，创建一个用于内置对象类型检查的types实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```ts
  let type = new util.types();
  ```


### isAnyArrayBuffer<sup>8+</sup>

isAnyArrayBuffer(value: Object): boolean

检查value是否为ArrayBuffer或SharedArrayBuffer类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是ArrayBuffer或SharedArrayBuffer类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isAnyArrayBuffer(new ArrayBuffer(0));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isArrayBufferView<sup>8+</sup>

isArrayBufferView(value: Object): boolean

检查value是否为ArrayBufferView类型。

ArrayBufferView类型包括：Int8Array、Int16Array、Int32Array、Uint8Array、Uint8ClampedArray、Uint32Array、Float32Array、Float64Array、DataView。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是ArrayBufferView类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isArrayBufferView(new Int8Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isArgumentsObject<sup>8+</sup>

isArgumentsObject(value: Object): boolean

检查value是否为arguments对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是arguments对象则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  function foo() {
      let result = type.isArgumentsObject(arguments);
      console.info("result = " + result);
  }
  let f = foo();
  // 输出结果：result = true
  ```


### isArrayBuffer<sup>8+</sup>

isArrayBuffer(value: Object): boolean

检查value是否为ArrayBuffer类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是ArrayBuffer类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isArrayBuffer(new ArrayBuffer(0));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isAsyncFunction<sup>8+</sup>

isAsyncFunction(value: Object): boolean

检查value是否为异步函数类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是异步函数则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isAsyncFunction(async () => {});
  console.info("result = " + result);
  // 输出结果：result = true
  ```

> **说明：**
>
> 该接口无法对AsyncGenerator Function进行有效判断，建议通过获取函数的`constructor.name`属性与`'AsyncGeneratorFunction'`做判等的方式替代。
>
> 该接口无法对Sendable class中的async成员函数进行有效判断，无替代方案。

  <!--code_no_check-->
  ```ts
  // /entry/src/main/ets/pages/test.ts
  export async function* asyncGeneratorFunc() {}
  ```

  <!--code_no_check-->
  ```ts
  import { asyncGeneratorFunc } from './test'

  @Sendable
  class SendableClass {
    async asyncFunction() {}
  }

  let type = new util.types();
  let result1 = type.isAsyncFunction(asyncGeneratorFunc);
  console.info("result = " + result1);
  // 输出结果：result = false

  console.info("asyncGeneratorFunc.constructor.name === AsyncGeneratorFunction : " +
    (asyncGeneratorFunc.constructor.name === 'AsyncGeneratorFunction'));
  // 输出结果：asyncGeneratorFunc.constructor.name === AsyncGeneratorFunction : true

  const instance = new SendableClass();
  let result2 = type.isAsyncFunction(instance.asyncFunction);
  console.info("result = " + result2);
  // 输出结果：result = false
  ```


### isBooleanObject<sup>(deprecated)</sup>

isBooleanObject(value: Object): boolean

检查value是否为Boolean对象。

> **说明：**
>
> 从 API version 8开始支持，从API version 14开始废弃。没有替代接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Boolean对象则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isBooleanObject(new Boolean(true));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isBoxedPrimitive<sup>(deprecated)</sup>

isBoxedPrimitive(value: Object): boolean

检查value是否为Boolean、Number、String或Symbol对象类型。

> **说明：**
>
> 从API version 8开始支持，从API version 14开始废弃，没有替代接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Boolean、Number、String或Symbol对象则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isBoxedPrimitive(new Boolean(false));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isDataView<sup>8+</sup>

isDataView(value: Object): boolean

检查value是否为DataView类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是DataView类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  const ab = new ArrayBuffer(20);
  let result = type.isDataView(new DataView(ab));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isDate<sup>8+</sup>

isDate(value: Object): boolean

检查value是否为Date类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Date类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isDate(new Date());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isExternal<sup>8+</sup>

isExternal(value: Object): boolean

检查value是否为native External类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是native&nbsp;External类型则返回true，否则返回false。 |

**示例：**

  ```cpp
  // /entry/src/main/cpp/napi_init.cpp
  #include "napi/native_api.h"
  #include <js_native_api.h>
  #include <stdlib.h>

  napi_value result;
  static napi_value Testexternal(napi_env env, napi_callback_info info) {
      int* raw = (int*) malloc(1024);
      napi_status status = napi_create_external(env, (void*) raw, NULL, NULL, &result);
      if (status != napi_ok) {
          napi_throw_error(env, NULL, "create external failed");
          return NULL;
      }
      return result;
  }

  EXTERN_C_START
  static napi_value Init(napi_env env, napi_value exports)
  {
      napi_property_descriptor desc[] = {
          {"testexternal", nullptr, Testexternal, nullptr, nullptr, nullptr, napi_default, nullptr},
      };
      napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
      return exports;
  }
  EXTERN_C_END
  // 此处已省略模块注册的代码, 你可能需要自行注册Testexternal方法
  // ...

  ```

  <!--code_no_check-->
  ```ts
  import testNapi from 'libentry.so';

  let type = new util.types();
  const data = testNapi.testexternal();
  let result = type.isExternal(data);

  let result01 = type.isExternal(true);
  console.info("result = " + result);
  console.info("result01 = " + result01);
  // 输出结果：result = true
  // 输出结果：result01 = false
  ```


### isFloat32Array<sup>8+</sup>

isFloat32Array(value: Object): boolean

检查value是否为Float32Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Float32Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isFloat32Array(new Float32Array());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isFloat64Array<sup>8+</sup>

isFloat64Array(value: Object): boolean

检查value是否为Float64Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Float64Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isFloat64Array(new Float64Array());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isGeneratorFunction<sup>8+</sup>

isGeneratorFunction(value: Object): boolean

检查value是否是为generator函数类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是generator函数类型则返回true，否则返回false。 |

**示例：**
<!--code_no_check-->
  ```ts
  // /entry/src/main/ets/pages/test.ts
  export function* foo() {}
  ```

  <!--code_no_check-->
  ```ts
  import { foo } from './test'

  let type = new util.types();
  let result = type.isGeneratorFunction(foo);
  console.info("result = " + result);
  // 输出结果：result = true
  ```

> **说明：**
>
> 该接口无法对AsyncGenerator Function进行有效判断，建议通过获取函数的`constructor.name`属性与`'AsyncGeneratorFunction'`做判等的方式替代。

  <!--code_no_check-->
  ```ts
  // /entry/src/main/ets/pages/test.ts
  export async function* asyncGeneratorFunc() {}
  ```

  <!--code_no_check-->
  ```ts
  import { asyncGeneratorFunc } from './test'

  let type = new util.types();
  let result = type.isGeneratorFunction(asyncGeneratorFunc);
  console.info("result = " + result);
  // 输出结果：result = false

  console.info("asyncGeneratorFunc.constructor.name === AsyncGeneratorFunction : " +
    (asyncGeneratorFunc.constructor.name === 'AsyncGeneratorFunction'));
  // 输出结果：asyncGeneratorFunc.constructor.name === AsyncGeneratorFunction : true
  ```


### isGeneratorObject<sup>8+</sup>

isGeneratorObject(value: Object): boolean

检查value是否为generator对象类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是generator对象则返回true，否则返回false。 |

**示例：**
<!--code_no_check-->
  ```ts
  // /entry/src/main/ets/pages/test.ts
  function* foo() {}
  export const generator = foo();
  ```

  <!--code_no_check-->
  ```ts
  import { generator } from './test'

  let type = new util.types();
  let result = type.isGeneratorObject(generator);
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isInt8Array<sup>8+</sup>

isInt8Array(value: Object): boolean

检查value是否为Int8Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Int8Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isInt8Array(new Int8Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isInt16Array<sup>8+</sup>

isInt16Array(value: Object): boolean

检查value是否为Int16Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Int16Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isInt16Array(new Int16Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isInt32Array<sup>8+</sup>

isInt32Array(value: Object): boolean

检查value是否为Int32Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Int32Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isInt32Array(new Int32Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isMap<sup>8+</sup>

isMap(value: Object): boolean

检查value是否为Map类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Map类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isMap(new Map());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isMapIterator<sup>8+</sup>

isMapIterator(value: Object): boolean

检查value是否为Map的Iterator类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**


| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Map的Iterator类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  const map : Map<number,number> = new Map();
  let result = type.isMapIterator(map.keys());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isNativeError<sup>8+</sup>

isNativeError(value: Object): boolean

检查value是否为Error类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Error类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isNativeError(new TypeError());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isNumberObject<sup>(deprecated)</sup>

isNumberObject(value: Object): boolean

检查value是否为Number对象类型。

> **说明：**
>
> 从API version 8开始支持，从API version 14开始废弃，没有替代接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Number对象类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isNumberObject(new Number(0));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isPromise<sup>8+</sup>

isPromise(value: Object): boolean

检查value是否为Promise类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Promise类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isPromise(Promise.resolve(1));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isProxy<sup>8+</sup>

isProxy(value: Object): boolean

检查value是否为Proxy类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Proxy类型则返回true，否则返回false。 |

**示例：**

  ```ts
  class Target{
  }
  let type = new util.types();
  const target : Target = {};
  const proxy = new Proxy(target, target);
  let result = type.isProxy(proxy);
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isRegExp<sup>8+</sup>

isRegExp(value: Object): boolean

检查value是否为RegExp类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是RegExp类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isRegExp(new RegExp('abc'));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isSet<sup>8+</sup>

isSet(value: Object): boolean

检查value是否为Set类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Set类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let set : Set<number> = new Set();
  let result = type.isSet(set);
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isSetIterator<sup>8+</sup>

isSetIterator(value: Object): boolean

检查value是否为Set的Iterator类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Set的Iterator类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  const set : Set<number> = new Set();
  let result = type.isSetIterator(set.keys());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isStringObject<sup>(deprecated)</sup>

isStringObject(value: Object): boolean

检查value是否为String对象类型。

> **说明：**
>
> 从API version 8开始支持，从API version 14开始废弃，没有替代接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是String对象类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isStringObject(new String('foo'));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isSymbolObject<sup>(deprecated)</sup>

isSymbolObject(value: Object): boolean

检查value是否为Symbol对象类型。

> **说明：**
>
> 从API version 8开始支持，从API version 14开始废弃，没有替代接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Symbol对象类型则返回true，否则返回false。 |

**示例：**
<!--code_no_check-->
  ```ts
  // /entry/src/main/ets/pages/test.ts
  export const symbols = Symbol('foo');
  ```

  <!--code_no_check-->
  ```ts
  import { symbols } from './test'

  let type = new util.types();
  let result = type.isSymbolObject(Object(symbols));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isTypedArray<sup>8+</sup>

isTypedArray(value: Object): boolean

检查value是否为TypedArray类型。

TypedArray类型，包括Int8Array、Int16Array、Int32Array、Uint8Array、Uint8ClampedArray、Uint16Array、Uint32Array、Float32Array、Float64Array、BigInt64Array、BigUint64Array。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是TypedArray包含的类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isTypedArray(new Float64Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isUint8Array<sup>8+</sup>

isUint8Array(value: Object): boolean

检查value是否为Uint8Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Uint8Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isUint8Array(new Uint8Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isUint8ClampedArray<sup>8+</sup>

isUint8ClampedArray(value: Object): boolean

检查value是否为Uint8ClampedArray数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Uint8ClampedArray数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isUint8ClampedArray(new Uint8ClampedArray([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isUint16Array<sup>8+</sup>

isUint16Array(value: Object): boolean

检查value是否为Uint16Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Uint16Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isUint16Array(new Uint16Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isUint32Array<sup>8+</sup>

isUint32Array(value: Object): boolean

检查value是否为Uint32Array数组类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Uint32Array数组类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isUint32Array(new Uint32Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isWeakMap<sup>8+</sup>

isWeakMap(value: Object): boolean

检查value是否为WeakMap类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是WeakMap类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let value : WeakMap<object, number> = new WeakMap();
  let result = type.isWeakMap(value);
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isWeakSet<sup>8+</sup>

isWeakSet(value: Object): boolean

检查value是否为WeakSet类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是WeakSet类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isWeakSet(new WeakSet());
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isBigInt64Array<sup>8+</sup>

isBigInt64Array(value: Object): boolean

检查value是否为BigInt64Array类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是BigInt64Array类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isBigInt64Array(new BigInt64Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isBigUint64Array<sup>8+</sup>

isBigUint64Array(value: Object): boolean

检查value是否为BigUint64Array类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是BigUint64Array类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isBigUint64Array(new BigUint64Array([]));
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isModuleNamespaceObject<sup>8+</sup>

isModuleNamespaceObject(value: Object): boolean

检查value是否为Module Namespace Object类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是Module Namespace Object类型则返回true，否则返回false。 |

**示例：**

  ```ts
  // /entry/src/main/ets/pages/test.ts
  export function func() {
    console.info("hello world");
  }
  ```

  <!--code_no_check-->
  ```ts
  import * as nameSpace from './test';

  let type = new util.types();
  let result = type.isModuleNamespaceObject(nameSpace);
  console.info("result = " + result);
  // 输出结果：result = true
  ```


### isSharedArrayBuffer<sup>8+</sup>

isSharedArrayBuffer(value: Object): boolean

检查value是否为SharedArrayBuffer类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是SharedArrayBuffer类型则返回true，否则返回false。 |

**示例：**

  ```ts
  let type = new util.types();
  let result = type.isSharedArrayBuffer(new SharedArrayBuffer(0));
  console.info("result = " + result);
  // 输出结果：result = true
  ```

## AutoFinalizer&lt;T&gt;<sup>22+</sup>

AutoFinalizer是一个接口类，用于在ArkTS对象释放时提供回调。通过实现回调接口，开发者可自定义对象被回收时自动触发的资源清理逻辑。

> **说明：**
>
> AutoFinalizer&lt;T&gt;需要和AutoFinalizerCleaner&lt;T&gt;一起使用，只实现该接口类没有任何功能。

### onFinalization<sup>22+</sup>

onFinalization(heldValue: T): void

开发者需要实现该接口，定义对象被回收时自动触发的资源清理回调。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| heldValue | T | 是 | 当监听的对象被回收时，该值会被传递给`onFinalization`回调方法。 |

## AutoFinalizerCleaner&lt;T&gt;<sup>22+</sup>

AutoFinalizerCleaner是用于关联对象生命周期与资源清理逻辑的工具类，需要和AutoFinalizer&lt;T&gt;一起使用。主要的作用是将实现了AutoFinalizer&lt;T&gt;接口的对象与特定值绑定，当对象被回收时自动触发资源清理回调。只使用AutoFinalizerCleaner而不实现AutoFinalizer接口没有任何功能。

### register&lt;T&gt;<sup>22+</sup>

static register&lt;T&gt;(obj: AutoFinalizer&lt;T&gt;, heldValue: T): void

将`AutoFinalizer`接口的对象与输入值关联，当对象被回收时触发资源清理的回调。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | [AutoFinalizer&lt;T&gt;](#autofinalizert22) | 是 | 实现了`AutoFinalizer`接口的对象，其`onFinalization`方法会在该对象被回收时调用。 |
| heldValue | T | 是 | 当监听的对象被回收时，该值会被传递给`obj.onFinalization`方法。 |

**示例：**

```ts
class DeviceManageViewModel implements util.AutoFinalizer<string> {
  constructor(heldValue: string) {
    util.AutoFinalizerCleaner.register(this, heldValue);
  }

  onFinalization(heldValue: string) {
    console.info("onFinalization: ", heldValue);
    // 等待触发垃圾回收，触发后会输出结果：onFinalization: test
  }
}

const device = new DeviceManageViewModel("test");
```

## LruBuffer<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache<sup>9+</sup>](#lrucache9)替代。

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | 当前缓冲区中值的总数。 |

**示例：**
  <!--code_no_check-->
  ```ts
  let pro : util.LruBuffer<number,number>= new util.LruBuffer();
  pro.put(2,10);
  pro.put(1,8);
  let result = pro.length;
  console.info("result = " + result);
  // 输出结果：result = 2
  ```

### constructor<sup>(deprecated)</sup>

constructor(capacity?: number)

构造函数用于创建一个新的LruBuffer实例，默认容量为64。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.constructor<sup>9+</sup>](#constructor9-3)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| capacity | number | 否 | 指示要为缓冲区自定义的容量，取值范围为[0, 2147483647]，默认值为64。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  ```

### updateCapacity<sup>(deprecated)</sup>

updateCapacity(newCapacity: number): void

将缓冲区容量更新为指定容量，如果newCapacity小于或等于0，则抛出异常。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.updateCapacity<sup>9+</sup>](#updatecapacity9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newCapacity | number | 是 | 指示要为缓冲区自定义的容量，取值范围为[0, 2147483647]。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.updateCapacity(100);
  ```

### toString<sup>(deprecated)</sup>

toString(): string

返回对象的字符串表示形式。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.toString<sup>9+</sup>](#tostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回对象的字符串表示形式。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  pro.remove(20);
  let result = pro.toString();
  console.info("result = " + result);
  // 输出结果：result = Lrubuffer[ maxSize = 64, hits = 1, misses = 0, hitRate = 100% ]
  ```

### getCapacity<sup>(deprecated)</sup>

getCapacity(): number

获取当前缓冲区的容量。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.getCapacity<sup>9+</sup>](#getcapacity9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回当前缓冲区的容量。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  let result = pro.getCapacity();
  console.info("result = " + result);
  // 输出结果：result = 64
  ```

### clear<sup>(deprecated)</sup>

clear(): void

清除当前缓冲区中的键值对，后续调用[afterRemoval](#afterremoval9)方法执行操作。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.clear<sup>9+</sup>](#clear9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.length;
  pro.clear();
  ```

### getCreateCount<sup>(deprecated)</sup>

getCreateCount(): number

获取createDefault()返回值的次数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.getCreateCount<sup>9+</sup>](#getcreatecount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回createDefault()返回值的次数。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(1,8);
  let result = pro.getCreateCount();
  console.info("result = " + result);
  // 输出结果：result = 0
  ```

### getMissCount<sup>(deprecated)</sup>

getMissCount(): number

获取查询值不匹配的次数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.getMissCount<sup>9+</sup>](#getmisscount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回查询值不匹配的次数。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  let result = pro.getMissCount();
  console.info("result = " + result);
  // 输出结果：result = 0
  ```

### getRemovalCount<sup>(deprecated)</sup>

getRemovalCount(): number

获取从缓冲区中逐出值的次数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.getRemovalCount<sup>9+</sup>](#getremovalcount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回从缓冲区中驱逐的次数。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  pro.updateCapacity(2);
  pro.put(50,22);
  let result = pro.getRemovalCount();
  console.info("result = " + result);
  // 输出结果：result = 0
  ```

### getMatchCount<sup>(deprecated)</sup>

getMatchCount(): number

获取查询值匹配成功的次数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.getMatchCount<sup>9+</sup>](#getmatchcount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回查询值匹配成功的次数。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  let result = pro.getMatchCount();
  console.info("result = " + result);
  // 输出结果：result = 1
  ```

### getPutCount<sup>(deprecated)</sup>

getPutCount(): number

获取将值添加到缓冲区的次数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.getPutCount<sup>9+</sup>](#getputcount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回将值添加到缓冲区的次数。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.getPutCount();
  console.info("result = " + result);
  // 输出结果：result = 1
  ```

### isEmpty<sup>(deprecated)</sup>

isEmpty(): boolean

检查当前缓冲区是否为空。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.isEmpty<sup>9+</sup>](#isempty9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果当前缓冲区不包含任何值，则返回true；否则返回false。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.isEmpty();
  console.info("result = " + result);
  // 输出结果：result = false
  ```

### get<sup>(deprecated)</sup>

get(key: K): V | undefined

返回键对应的值。当键不在缓冲区中时，返回undefined。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.get<sup>9+</sup>](#get9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 要查询的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V&nbsp;\|&nbsp;undefined | 如果指定的键存在于缓冲区中，则返回与键关联的值；否则返回undefined。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result  = pro.get(2);
  console.info("result = " + result);
  // 输出结果：result = 10
  ```

### put<sup>(deprecated)</sup>

put(key: K,value: V): V

将键值对添加到缓冲区。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.put<sup>9+</sup>](#put9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 要添加的键。 |
| value | V | 是 | 指示与要添加的键关联的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回与添加的键关联的值；如果要添加的键已经存在，则返回原始值，如果键或值为空，则抛出此异常。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  let result = pro.put(2,10);
  console.info("result = " + result);
  // 输出结果：result = 10
  ```

### values<sup>(deprecated)</sup>

values(): V[]

获取当前缓冲区中所有值从最近访问到最近最少访问的顺序列表。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.values<sup>9+</sup>](#values9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V&nbsp;[] | 按从最近访问到最近最少访问的顺序返回当前缓冲区中所有值的列表。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number|string,number|string> = new util.LruBuffer();
  pro.put(2,10);
  pro.put(2,"anhu");
  pro.put("afaf","grfb");
  let result = pro.values();
  console.info("result = " + result);
  // 输出结果：result = anhu,grfb
  ```

### keys<sup>(deprecated)</sup>

keys(): K[]

获取当前缓冲区中所有键从最近访问到最近最少访问的升序列表。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.keys<sup>9+</sup>](#keys9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K&nbsp;[] | 按升序返回当前缓冲区中所有键的列表，从最近访问到最近最少访问。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.keys();
  console.info("result = " + result);
  // 输出结果：result = 2
  ```

### remove<sup>(deprecated)</sup>

remove(key: K): V | undefined

删除当前缓冲区中指定的键及其关联的值。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.remove<sup>9+</sup>](#remove9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 要删除的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V&nbsp;\|&nbsp;undefined | 返回一个包含已删除键值对的Optional对象；如果key不存在，则返回一个空的Optional对象，如果key为null，则抛出异常。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.remove(20);
  console.info("result = " + result);
  // 输出结果：result = undefined
  ```

### afterRemoval<sup>(deprecated)</sup>

afterRemoval(isEvict: boolean,key: K,value: V,newValue: V): void

删除值后执行后续操作。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.afterRemoval<sup>9+</sup>](#afterremoval9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isEvict | boolean | 是 | 因容量不足而调用该方法时，参数值为true，其他情况为false。 |
| key | K | 是 | 表示删除的键。 |
| value | V | 是 | 表示删除的值。 |
| newValue | V | 是 | 如果已调用put方法并且要添加的键已经存在，则参数值是关联的新值。其他情况下参数值为空。 |

**示例：**

```ts
class ChildLruBuffer<K, V> extends util.LruBuffer<K, V> {
  constructor(capacity?: number) {
    super(capacity);
  }

  afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void {
    if (isEvict === true) {
      console.info('key: ' + key);
      // 输出结果：key: 11
      console.info('value: ' + value);
      // 输出结果：value: 1
      console.info('newValue: ' + newValue);
      // 输出结果：newValue: null
    }
  }
}
let lru: ChildLruBuffer<number, number> = new ChildLruBuffer(2);
lru.put(11, 1);
lru.put(22, 2);
lru.put(33, 3);
```

### contains<sup>(deprecated)</sup>

contains(key: K): boolean

检查当前缓冲区是否包含指定的键。


> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.contains<sup>9+</sup>](#contains9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 表示要检查的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果缓冲区包含指定的键，则返回true；否则返回false。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.contains(20);
  console.info('result = ' + result);
  // 输出结果：result = false
  ```

### createDefault<sup>(deprecated)</sup>

createDefault(key: K): V

当缓冲区中未匹配到指定键时，执行后续处理逻辑，参数表示未匹配到的键，返回与该键关联的值，默认返回undefined。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.createDefault<sup>9+</sup>](#createdefault9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 表示丢失的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回与键关联的值。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  let result = pro.createDefault(50);
  ```

### entries<sup>(deprecated)</sup>

entries(): IterableIterator&lt;[K, V]&gt;

允许迭代包含在这个对象中的所有键值对。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.entries<sup>9+</sup>](#entries9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[K, V]&gt; | 返回一个可迭代数组。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.entries();
  ```

### [Symbol.iterator]<sup>(deprecated)</sup>

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个键值对形式的二维数组。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[LRUCache.[Symbol.iterator]<sup>9+</sup>](#symboliterator9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[K, V]&gt; | 返回一个键值对形式的二维数组。 |

**示例：**

  ```ts
  let pro : util.LruBuffer<number,number> = new util.LruBuffer();
  pro.put(2,10);
  let result = pro[Symbol.iterator]();
  ```

## Scope<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper<sup>9+</sup>](#scopehelper9)替代。

### constructor<sup>(deprecated)</sup>

constructor(lowerObj: ScopeType, upperObj: ScopeType)

创建指定下限和上限的作用域实例，并返回一个Scope对象。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.constructor<sup>9+</sup>](#constructor9-4)替代。


**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| lowerObj | [ScopeType](#scopetype8) | 是 | 指定作用域实例的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是 | 指定作用域实例的上限。 |

**示例：**
```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.Scope(tempLower, tempUpper);
console.info("range = " + range);
// 输出结果：range = [30, 40]
```

### toString<sup>(deprecated)</sup>

toString(): string

该字符串化方法返回一个包含当前范围的字符串表示形式。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.toString<sup>9+</sup>](#tostring9-1)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回包含当前范围对象的字符串表示形式。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.Scope(tempLower, tempUpper);
let result = range.toString();
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### intersect<sup>(deprecated)</sup>

intersect(range: Scope): Scope

获取给定范围和当前范围的交集。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.intersect<sup>9+</sup>](#intersect9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| range | [Scope](#scopedeprecated) | 是 | 传入一个给定范围。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scopedeprecated) | 返回给定范围和当前范围的交集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.Scope(tempLower, tempUpper);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let rangeFir = new util.Scope(tempMiDF, tempMidS);
let result = range.intersect(rangeFir );
console.info("result = " + result);
  // 输出结果：result = [35, 39]
  ```

### intersect<sup>(deprecated)</sup>

intersect(lowerObj:ScopeType,upperObj:ScopeType):Scope

获取当前范围与给定下限和上限范围的交集。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.intersect<sup>9+</sup>](#intersect9-1)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| lowerObj | [ScopeType](#scopetype8) | 是 | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是 | 给定范围的上限。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scopedeprecated) | 返回当前范围与给定下限和上限范围的交集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.Scope(tempLower, tempUpper);
let result = range.intersect(tempMiDF, tempMidS);
console.info("result = " + result);
// 输出结果：result = [35, 39]
```

### getUpper<sup>(deprecated)</sup>

getUpper(): ScopeType

获取当前范围的上限。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.getUpper<sup>9+</sup>](#getupper9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScopeType](#scopetype8) | 返回当前范围的上限值。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.Scope(tempLower, tempUpper);
let result = range.getUpper();
console.info("result = " + result);
// 输出结果：result = 40
```

### getLower<sup>(deprecated)</sup>

getLower(): ScopeType

获取当前范围的下限。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.getLower<sup>9+</sup>](#getlower9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScopeType](#scopetype8) | 返回当前范围的下限值。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.Scope(tempLower, tempUpper);
let result = range.getLower();
console.info("result = " + result);
// 输出结果：result = 30
```

### expand<sup>(deprecated)</sup>

expand(lowerObj: ScopeType,upperObj: ScopeType): Scope

创建并返回包括当前范围和给定下限和上限的并集。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.expand<sup>9+</sup>](#expand9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| lowerObj | [ScopeType](#scopetype8) | 是 | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是 | 给定范围的上限。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scopedeprecated) | 返回当前范围和给定下限和上限的并集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.Scope(tempLower, tempUpper);
let result = range.expand(tempMiDF, tempMidS);
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### expand<sup>(deprecated)</sup>

expand(range: Scope): Scope

创建并返回包括当前范围和给定范围的并集。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.expand<sup>9+</sup>](#expand9-1)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| range | [Scope](#scopedeprecated) | 是 | 传入一个给定范围。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scopedeprecated) | 返回包括当前范围和给定范围的并集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.Scope(tempLower, tempUpper);
let rangeFir = new util.Scope(tempMiDF, tempMidS);
let result = range.expand(rangeFir);
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### expand<sup>(deprecated)</sup>

expand(value: ScopeType): Scope

创建并返回包括当前范围和给定值的并集。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.expand<sup>9+</sup>](#expand9-2)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ScopeType](#scopetype8) | 是 | 传入一个给定值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scopedeprecated) | 返回包括当前范围和给定值的并集。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.Scope(tempLower, tempUpper);
let result = range.expand(tempMiDF);
console.info("result = " + result);
// 输出结果：result = [30, 40]
```

### contains<sup>(deprecated)</sup>

contains(value: ScopeType): boolean

检查给定value是否包含在当前范围内。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.contains<sup>9+</sup>](#contains9-1)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ScopeType](#scopetype8) | 是 | 传入一个给定值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果给定值包含在当前范围内返回true，否则返回false。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.Scope(tempLower, tempUpper);
let result = range.contains(tempMiDF);
console.info("result = " + result);
// 输出结果：result = true
```

### contains<sup>(deprecated)</sup>

contains(range: Scope): boolean

检查给定range是否在当前范围内。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.contains<sup>9+</sup>](#contains9-2)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| range | [Scope](#scopedeprecated) | 是 | 传入一个给定范围。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果给定范围包含在当前范围内返回true，否则返回false。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.Scope(tempLower, tempUpper);
let tempLess = new Temperature(20);
let tempMore = new Temperature(45);
let rangeSec = new util.Scope(tempLess, tempMore);
let result = range.contains(rangeSec);
console.info("result = " + result);
// 输出结果：result = false
```

### clamp<sup>(deprecated)</sup>


clamp(value: ScopeType): ScopeType

将给定值限定到当前范围内。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[ScopeHelper.clamp<sup>9+</sup>](#clamp9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ScopeType](#scopetype8) | 是 | 传入的给定值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScopeType](#scopetype8) | 如果传入的value小于下限，则返回lowerObj；如果大于上限值则返回upperObj；如果在当前范围内，则返回value。 |

**示例：**

```ts
class Temperature implements util.ScopeComparable {
  private readonly _temp: number;

  constructor(value: number) {
    this._temp = value;
  }

  compareTo(value: Temperature) {
    return this._temp >= value.getTemp();
  }

  getTemp() {
    return this._temp;
  }

  toString(): string {
    return this._temp.toString();
  }
}

let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.Scope(tempLower, tempUpper);
let result = range.clamp(tempMiDF);
console.info("result = " + result);
// 输出结果：result = 35
```


## Base64<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper<sup>9+</sup>](#base64helper9)替代。

### constructor<sup>(deprecated)</sup>

constructor()

Base64的构造函数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.constructor<sup>9+</sup>](#constructor9-5)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```ts
  let base64 = new  util.Base64();
  ```

### encodeSync<sup>(deprecated)</sup>

encodeSync(src: Uint8Array): Uint8Array

将输入的Uint8Array字节数组进行Base64编码，返回编码后的Uint8Array数组。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.encodeSync<sup>9+</sup>](#encodesync9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回编码后新分配的Uint8数组。 |

**示例：**

  ```ts
  let base64 = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  let result = base64.encodeSync(array);
  console.info("result = " + result);
  // 输出结果：result = 99,122,69,122
  ```

### encodeToStringSync<sup>(deprecated)</sup>

encodeToStringSync(src: Uint8Array): string

将输入的Uint8Array字节数组进行Base64编码，返回编码后的字符串结果。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.encodeToStringSync<sup>9+</sup>](#encodetostringsync9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回编码后的字符串。 |

**示例：**

  ```ts
  let base64 = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  let result = base64.encodeToStringSync(array);
  console.info("result = " + result);
  // 输出结果：result = czEz
  ```

### decodeSync<sup>(deprecated)</sup>

decodeSync(src: Uint8Array | string): Uint8Array

通过输入参数解码后输出对应文本。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.decodeSync<sup>9+</sup>](#decodesync9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array&nbsp;\|&nbsp;string | 是 | 解码输入Uint8数组或者字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回解码后新分配的Uint8数组。 |

**示例：**

  ```ts
  let base64 = new util.Base64();
  let buff = 'czEz';
  let result = base64.decodeSync(buff);
  console.info("result = " + result);
  // 输出结果：result = 115,49,51
  ```

### encode<sup>(deprecated)</sup>

encode(src: Uint8Array): Promise&lt;Uint8Array&gt;

通过输入参数异步编码后输出对应文本。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.encode<sup>9+</sup>](#encode9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 异步编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | 返回异步编码后新分配的Uint8数组。 |

**示例：**

  ```ts
  let base64 = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  base64.encode(array).then((val) => {
    console.info(val.toString());
    // 输出结果：99,122,69,122
  })
  ```

### encodeToString<sup>(deprecated)</sup>

encodeToString(src: Uint8Array): Promise&lt;string&gt;

通过输入参数异步编码后输出对应文本。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.encodeToString<sup>9+</sup>](#encodetostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 异步编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | 返回异步编码后的字符串。 |

**示例：**

  ```ts
  let base64 = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  base64.encodeToString(array).then((val) => {
      console.info(val);
      // 输出结果：czEz
  })
  ```

### decode<sup>(deprecated)</sup>


decode(src: Uint8Array | string): Promise&lt;Uint8Array&gt;

将输入参数异步解码后输出对应文本。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[Base64Helper.decode<sup>9+</sup>](#decode9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array&nbsp;\|&nbsp;string | 是 | 异步解码输入Uint8数组或者字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | 返回异步解码后新分配的Uint8数组。 |

**示例：**

  ```ts
  let base64 = new util.Base64();
  let array = new Uint8Array([99,122,69,122]);
  base64.decode(array).then((val) => {
    console.info(val.toString());
    // 输出结果：115,49,51
  })
  ```
