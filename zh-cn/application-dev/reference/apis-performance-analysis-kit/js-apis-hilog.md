# @ohos.hilog (HiLog日志打印)

hilog日志系统，使应用/服务可以按照指定级别、标识和格式字符串输出日志内容，帮助开发者了解应用/服务的运行状态，更好地调试程序。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { hilog } from '@kit.PerformanceAnalysisKit';
```

## hilog.isLoggable

isLoggable(domain: number, tag: string, level: LogLevel) : boolean

在打印日志前调用该接口，用于检查指定领域标识、日志标识和级别的日志是否可以打印。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型                  | 必填 | 说明                                                         |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| domain | number                | 是   | 日志对应的领域标识，范围是0x0~0xFFFF，超出范围则日志无法打印。<br/>建议开发者在应用内根据需要自定义划分。 |
| tag    | string                | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| level  | [LogLevel](#loglevel) | 是   | 日志级别。                                                   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果返回true，则该领域标识、日志标识和级别的日志可以打印，否则不能打印。 |

**示例：**

```js
hilog.isLoggable(0x0001, "testTag", hilog.LogLevel.INFO);
```

## LogLevel

日志级别。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

| 名称  |   值   | 说明                                                         |
| ----- | ------ | ------------------------------------------------------------ |
| DEBUG | 3      | 详细的流程记录，通过该级别的日志可以更详细地分析业务流程和定位分析问题。 |
| INFO  | 4      | 用于记录业务关键流程节点，可以还原业务的主要运行过程；<br/>用于记录可预料的非正常情况信息，如无网络信号、登录失败等。<br/>这些日志都应该由该业务内处于支配地位的模块来记录，避免在多个被调用的模块或低级函数中重复记录。 |
| WARN  | 5      | 用于记录较为严重的非预期情况，但是对用户影响不大，应用可以自动恢复或通过简单的操作就可以恢复的问题。 |
| ERROR | 6      | 应用发生了错误，该错误会影响功能的正常运行或用户的正常使用，可以恢复但恢复代价较高，如重置数据等。 |
| FATAL | 7      | 重大致命异常，表明应用即将崩溃，故障无法恢复。               |

## hilog.debug

debug(domain: number, tag: string, format: string, ...args: any[]) : void

打印DEBUG级别的日志。

DEBUG级别的日志在正式发布版本中默认不被打印，只有在调试版本或打开调试开关的情况下才会打印。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | 是   | 日志对应的领域标识，范围是0x0~0xFFFF，超出范围则日志无法打印。<br/>建议开发者在应用内根据需要自定义划分。 |
| tag    | string | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| format | string | 是   | 格式字符串，用于日志的格式化输出。格式字符串中可以设置多个参数，参数需要包含参数类型、隐私标识。<br>隐私标识分为{public}和{private}，缺省为{private}。标识{public}的内容明文输出，标识{private}的内容以\<private>过滤回显。 |
| args   | any[]  | 否   | 与格式字符串format对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

输出一条DEBUG信息，格式字符串为`"%{public}s World %{private}d"`。其中变参`%{public}s`为明文显示的字符串；`%{private}d`为隐私的整型数。

```js
hilog.debug(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

字符串`"hello"`填入`%{public}s`，整型数`3`填入`%{private}d`，输出日志：

```
08-05 12:21:47.579  2695 2703 D A00001/testTag: hello World <private>
```

## hilog.info

info(domain: number, tag: string, format: string, ...args: any[]) : void

打印INFO级别的日志。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | 是   | 日志对应的领域标识，范围是0x0~0xFFFF，超出范围则日志无法打印。<br/>建议开发者在应用内根据需要自定义划分。  |
| tag    | string | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| format | string | 是   | 格式字符串，用于日志的格式化输出。格式字符串中可以设置多个参数，参数需要包含参数类型、隐私标识。<br/>隐私标识分为{public}和{private}，缺省为{private}。标识{public}的内容明文输出，标识{private}的内容以\<private>过滤回显。 |
| args   | any[]  | 否   | 与格式字符串format对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

输出一条INFO信息，格式字符串为`"%{public}s World %{private}d"`。其中变参`%{public}s`为明文显示的字符串；`%{private}d`为隐私的整型数。

```js
hilog.info(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

字符串`"hello"`填入`%{public}s`，整型数`3`填入`%{private}d`，输出日志：

```
08-05 12:21:47.579  2695 2703 I A00001/testTag: hello World <private>
```

## hilog.warn

warn(domain: number, tag: string, format: string, ...args: any[]) : void

打印WARN级别的日志。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | 是   | 日志对应的领域标识，范围是0x0~0xFFFF，超出范围则日志无法打印。<br/>建议开发者在应用内根据需要自定义划分。  |
| tag    | string | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| format | string | 是   | 格式字符串，用于日志的格式化输出。格式字符串中可以设置多个参数，参数需要包含参数类型、隐私标识。<br/>隐私标识分为{public}和{private}，缺省为{private}。标识{public}的内容明文输出，标识{private}的内容以\<private>过滤回显。 |
| args   | any[]  | 否   | 与格式字符串format对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

输出一条WARN信息，格式字符串为`"%{public}s World %{private}d"`。其中变参`%{public}s`为明文显示的字符串；`%{private}d`为隐私的整型数。

```js
hilog.warn(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

字符串`"hello"`填入`%{public}s`，整型数`3`填入`%{private}d`，输出日志：

```
08-05 12:21:47.579  2695 2703 W A00001/testTag: hello World <private>
```

## hilog.error

error(domain: number, tag: string, format: string, ...args: any[]) : void

打印ERROR级别的日志。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | 是   | 日志对应的领域标识，范围是0x0~0xFFFF，超出范围则日志无法打印。<br/>建议开发者在应用内根据需要自定义划分。  |
| tag    | string | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。 tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。|
| format | string | 是   | 格式字符串，用于日志的格式化输出。格式字符串中可以设置多个参数，参数需要包含参数类型、隐私标识。<br/>隐私标识分为{public}和{private}，缺省为{private}。标识{public}的内容明文输出，标识{private}的内容以\<private>过滤回显。 |
| args   | any[]  | 否   | 与格式字符串format对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

输出一条ERROR信息，格式字符串为`"%{public}s World %{private}d"`。其中变参`%{public}s`为明文显示的字符串；`%{private}d`为隐私的整型数。

```js
hilog.error(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

字符串`"hello"`填入`%{public}s`，整型数`3`填入`%{private}d`，输出日志：

```
08-05 12:21:47.579  2695 2703 E A00001/testTag: hello World <private>
```

## hilog.fatal

fatal(domain: number, tag: string, format: string, ...args: any[]) : void

打印FATAL级别的日志。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | 是   | 日志对应的领域标识，范围是0x0~0xFFFF，超出范围则日志无法打印。<br/>建议开发者在应用内根据需要自定义划分。  |
| tag    | string | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| format | string | 是   | 格式字符串，用于日志的格式化输出。格式字符串中可以设置多个参数，参数需要包含参数类型、隐私标识。<br/>隐私标识分为{public}和{private}，缺省为{private}。标识{public}的内容明文输出，标识{private}的内容以\<private>过滤回显。 |
| args   | any[]  | 否   | 与格式字符串format对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

输出一条FATAL信息，格式字符串为`"%{public}s World %{private}d"`。其中变参`%{public}s`为明文显示的字符串；`%{private}d`为隐私的整型数。

```js
hilog.fatal(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

字符串`"hello"`填入`%{public}s`，整型数`3`填入`%{private}d`，输出日志：

```
08-05 12:21:47.579  2695 2703 F A00001/testTag: hello World <private>
```

## hilog.setMinLogLevel<sup>15+</sup>

setMinLogLevel(level: LogLevel): void

设置应用日志打印的最低日志级别，进程在打印日志时，需要同时校验该日志级别和全局日志级别，所以设置的日志级别不能低于全局日志级别，[全局日志级别](../../dfx/hilog.md#查看和设置日志级别)默认为Info。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型                  | 必填 | 说明                                                         |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| level  | [LogLevel](#loglevel) | 是   | 日志级别。                                                   |

**示例：**

打印5条不同级别的hilog日志，在打印过程中调用两次setMinLogLevel接口：

```js
hilog.info(0x0001, "testTag", 'this is an info level log, id: %{public}d', 1);
hilog.setMinLogLevel(hilog.LogLevel.WARN);
hilog.info(0x0001, "testTag", 'this is an info level log, id: %{public}d', 2);
hilog.error(0x0001, 'testTag', 'this is an error level log, id: %{public}d', 3);
hilog.setMinLogLevel(hilog.LogLevel.DEBUG);
hilog.debug(0x0001, "testTag", 'this is a debug level log, id: %{public}d', 4);
hilog.info(0x0001, "testTag", 'this is an info level log, id: %{public}d', 5);
```

全局日志默认级别为Info，第一条日志可以正常打印，在设置进程最低可打印日志级别为Warn后，第二条日志不符合该日志级别，第二条日志打印失败，第三条日志可以正常打印，在设置进程最低日志级别为Debug后，但是全局默认日志级别为Info，所以第四条日志不满足全局日志级别，打印失败，第五条日志可以打印，结果如下所示：

```
08-07 23:50:01.532   13694-13694   A00001/testTag                  com.example.hilogemo  I     this is an info level log, id: 1
08-07 23:50:01.532   13694-13694   A00001/testTag                  com.example.hilogemo  E     this is an error level log, id: 3
08-07 23:50:01.532   13694-13694   A00001/testTag                  com.example.hilogemo  I     this is an info level log, id: 5
```

## 参数格式符

上述接口中，日志打印的格式化参数需按照如下格式打印：

%{[private flag]}specifier

|  隐私标识符（private flag） | 说明 |
| ------------ | ---- |
|      无      | 缺省值默认为private，不打印明文参数。 |
|  private     | 隐私参数类型，不打印明文参数。 |
|  public      | 明文显示参数。 |

| 格式说明符（specifier） | 说明 | 示例 |
| ------------ | ---- | ---- |
|      d/i      | 支持打印number和bigint类型。 | 123 |
|   s     | 支持打印string undefined bool 和null类型。 | "123" |
| o/O | 支持打印object、undefined和null类型。<br>从API version 20开始，支持该能力。 | obj |

**示例：**
```js
let testObj: Record<string, string | number> = {
    'name': "Jack",
    'age': 22
}
let isBol = true;
let bigNum = BigInt(1234567890123456789);
hilog.info(0x0001, "jsHilogTest", "print object: %{public}s", JSON.stringify(testObj));
hilog.info(0x0001, "jsHilogTest", "print object: %{public}o", testObj);
hilog.info(0x0001, "jsHilogTest", "private flag: %{private}s %s, print null: %{public}s", "hello", "world", null);
hilog.info(0x0001, "jsHilogTest", "print undefined: %{public}s", undefined);
hilog.info(0x0001, "jsHilogTest", "print number: %{public}d %{public}i", 123, 456);
hilog.info(0x0001, "jsHilogTest", "print bigNum: %{public}d %{public}i", bigNum, bigNum);
hilog.info(0x0001, "jsHilogTest", "print boolean: %{public}s", isBol);
```

**打印结果：**
```
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print object: {"name":"Jack","age":22}
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print object: {"name":"Jack","age":22}
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: private flag: <private> <private>, print null: null
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print undefined: undefined
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print number: 123 456
08-09 13:26:29.095  2266  2266 I A00001/jsHilogTest: print bigNum: 1234567890123456768 1234567890123456768
08-09 13:26:29.095  2266  2266 I A00001/jsHilogTest: print boolean: true
```