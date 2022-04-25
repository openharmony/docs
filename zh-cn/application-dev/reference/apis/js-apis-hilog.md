# 日志打印

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import hilog from '@ohos.hilog';
```


## hilog.debug

debug(domain: number, tag: string, format: string, ...args: any[]) : void

debug日志输出，打印debug级别日志。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | 是   | 业务领域。范围0x0~0xFFFFF。                                  |
| tag    | string         | 是   | 字符串常量，标识调用所在的类或者业务行为。                   |
| format | string         | 是   | 格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。 |
| args   | any[]          | 是   | 与格式字符串里参数类型对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

```js
hilog.debug(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**输出：**

```
09-08 12:49:35.941  1547  2452 D FF00/testTag: 1: hello World 3.0
```

## hilog.info

info(domain: number, tag: string, format: string, ...args: any[]) : void

info日志输出，打印info级别日志。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | 是   | 业务领域。范围0x0~0xFFFFF。                                  |
| tag    | string         | 是   | 字符串常量，标识调用所在的类或者业务行为。                   |
| format | string         | 是   | 格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。 |
| args   | any[]  | 是   | 与格式字符串里参数类型对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

```js
hilog.info(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**输出：**

```
09-08 12:49:35.941  1547  2452 I FF00/testTag: 1: hello World 3.0
```

## hilog.warn

warn(domain: number, tag: string, format: string, ...args: any[]) : void

warn日志输出，打印warn级别日志。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | 是   | 业务领域。范围0x0~0xFFFFF。                                  |
| tag    | string         | 是   | 字符串常量，标识调用所在的类或者业务行为。                   |
| format | string         | 是   | 格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。 |
| args   | any[]  | 是   | 与格式字符串里参数类型对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

```js
hilog.warn(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**输出：**

```
09-08 12:49:35.941  1547  2452 W FF00/testTag: 1: hello World 3.0
```

## hilog.error

error(domain: number, tag: string, format: string, ...args: any[]) : void

error日志输出，打印error级别日志。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | 是   | 业务领域。范围0x0~0xFFFFF。                                  |
| tag    | string         | 是   | 字符串常量，标识调用所在的类或者业务行为。                   |
| format | string         | 是   | 格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。 |
| args   | any[]  | 是   | 与格式字符串里参数类型对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

```js
hilog.error(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**输出：**

```
09-08 12:49:35.941  1547  2452 E FF00/testTag: 1: hello World 3.0
```

## hilog.fatal

fatal(domain: number, tag: string, format: string, ...args: any[]) : void

fatal日志输出，打印fatal级别日志。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | 是   | 业务领域。范围0x0~0xFFFFF。                                  |
| tag    | string         | 是   | 字符串常量，标识调用所在的类或者业务行为。                   |
| format | string         | 是   | 格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。 |
| args   | any[]  | 是   | 与格式字符串里参数类型对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**示例：**

```js
hilog.fatal(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**输出：**

```
09-08 12:49:35.941  1547  2452 F FF00/testTag: 1: hello World 3.0
```

## hilog.isLoggable

isLoggable(domain: number, tag: string, level: LogLevel) : boolean

检查一个domain、tag和日志级别是否被禁止打印日志。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**参数：**

| 参数名 | 类型                  | 必填 | 说明                                       |
| ------ | --------------------- | ---- | ------------------------------------------ |
| domain | number                | 是   | 业务领域。范围0x0~0xFFFFF。                |
| tag    | string                | 是   | 字符串常量，标识调用所在的类或者业务行为。 |
| level  | [LogLevel](#loglevel) | 是   | 日志级别。                                 |

**示例：**

```js
hilog.isLoggable(0xFF00, "testTag", hilog.DEBUG);
```

## LogLevel

用于表示事件类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiLog。

| 名称  | 默认值 | 说明        |
| ----- | ------ | ----------- |
| DEBUG | 3      | DEBUG级别。 |
| INFO  | 4      | INFO级别。  |
| WARN  | 5      | WARN级别。  |
| ERROR | 6      | ERROR级别。 |
| FATAL | 7      | FATAL级别。 |