# @ohos.hilog (HiLog)

The HiLog subsystem allows your applications or services to output logs based on the specified type, level, and format string. Such logs help you learn the running status of applications and better debug programs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { hilog } from '@kit.PerformanceAnalysisKit';
```

## hilog.isLoggable

isLoggable(domain: number, tag: string, level: LogLevel) : boolean

Checks whether logs are printable based on the specified service domain, log tag, and log level.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type                 | Mandatory| Description                                                        |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| domain | number                | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**. If the value exceeds the range, logs cannot be printed.<br>You can define the value as required.|
| tag    | string                | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| level  | [LogLevel](#loglevel) | Yes  | Log level.                                                  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** logs are printable based on the specified service domain, log tag, and log level; returns **false** otherwise.|

**Example**

```js
hilog.isLoggable(0x0001, "testTag", hilog.LogLevel.INFO);
```

## LogLevel

Log level.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

| Name |   Value  | Description                                                        |
| ----- | ------ | ------------------------------------------------------------ |
| DEBUG | 3      | Log level used to record more detailed process information than INFO logs to help developers analyze service processes and locate faults.|
| INFO  | 4      | Log level used to record key service process nodes and exceptions that occur during service running,<br>for example, no network signal or login failure.<br>These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.|
| WARN  | 5      | Log level used to record severe, unexpected faults that have little impact on users and can be rectified by the programs themselves or through simple operations.|
| ERROR | 6      | Log level used to record program or functional errors that affect the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.|
| FATAL | 7      | Log level used to record program or functionality crashes that cannot be rectified.              |

## hilog.debug

debug(domain: number, tag: string, format: string, ...args: any[]) : void

Prints DEBUG logs.

DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**. If the value exceeds the range, logs cannot be printed.<br>You can define the value as required.|
| tag    | string | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| format | string | Yes  | Format string used to output logs in a specified format. It can contain several elements, where the parameter type and privacy identifier are mandatory.<br>Parameters labeled **{public}** are public data and are displayed in plaintext; parameters labeled **{private}** (default value) are private data and are filtered by **\<private>**.|
| args   | any[]  | No  | Variable-length parameter list corresponding to the format string. The number and type of parameters must map to the identifier in the format string.|

**Example**

This example is used to output a DEBUG log with the format string being `"%{public}s World %{private}d"`. The variable `%{public}s` is a plaintext string, and the variable `%{private}d` is a private integer.

```js
hilog.debug(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

If `"hello"` is filled in `%{public}s` and `3` in `%{private}d`, the output log is as follows:

```
08-05 12:21:47.579  2695 2703 D A00001/testTag: hello World <private>
```

## hilog.info

info(domain: number, tag: string, format: string, ...args: any[]) : void

Prints INFO logs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**. If the value exceeds the range, logs cannot be printed.<br>You can define the value as required. |
| tag    | string | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| format | string | Yes  | Format string used to output logs in a specified format. It can contain several elements, where the parameter type and privacy identifier are mandatory.<br>Parameters labeled **{public}** are public data and are displayed in plaintext; parameters labeled **{private}** (default value) are private data and are filtered by **\<private>**.|
| args   | any[]  | No  | Variable-length parameter list corresponding to the format string. The number and type of parameters must map to the identifier in the format string.|

**Example**

This example is used to output an INFO log with the format string being `"%{public}s World %{private}d"`. The variable `%{public}s` is a plaintext string, and the variable `%{private}d` is a private integer.

```js
hilog.info(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

If `"hello"` is filled in `%{public}s` and `3` in `%{private}d`, the output log is as follows:

```
08-05 12:21:47.579  2695 2703 I A00001/testTag: hello World <private>
```

## hilog.warn

warn(domain: number, tag: string, format: string, ...args: any[]) : void

Prints WARN logs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**. If the value exceeds the range, logs cannot be printed.<br>You can define the value as required. |
| tag    | string | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| format | string | Yes  | Format string used to output logs in a specified format. It can contain several elements, where the parameter type and privacy identifier are mandatory.<br>Parameters labeled **{public}** are public data and are displayed in plaintext; parameters labeled **{private}** (default value) are private data and are filtered by **\<private>**.|
| args   | any[]  | No  | Variable-length parameter list corresponding to the format string. The number and type of parameters must map to the identifier in the format string.|

**Example**

This example is used to output a WARN log with the format string being `"%{public}s World %{private}d"`. The variable `%{public}s` is a plaintext string, and the variable `%{private}d` is a private integer.

```js
hilog.warn(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

If `"hello"` is filled in `%{public}s` and `3` in `%{private}d`, the output log is as follows:

```
08-05 12:21:47.579  2695 2703 W A00001/testTag: hello World <private>
```

## hilog.error

error(domain: number, tag: string, format: string, ...args: any[]) : void

Prints ERROR logs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**. If the value exceeds the range, logs cannot be printed.<br>You can define the value as required. |
| tag    | string | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| format | string | Yes  | Format string used to output logs in a specified format. It can contain several elements, where the parameter type and privacy identifier are mandatory.<br>Parameters labeled **{public}** are public data and are displayed in plaintext; parameters labeled **{private}** (default value) are private data and are filtered by **\<private>**.|
| args   | any[]  | No  | Variable-length parameter list corresponding to the format string. The number and type of parameters must map to the identifier in the format string.|

**Example**

This example is used to output an ERROR log with the format string being `"%{public}s World %{private}d"`. The variable `%{public}s` is a plaintext string, and the variable `%{private}d` is a private integer.

```js
hilog.error(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

If `"hello"` is filled in `%{public}s` and `3` in `%{private}d`, the output log is as follows:

```
08-05 12:21:47.579  2695 2703 E A00001/testTag: hello World <private>
```

## hilog.fatal

fatal(domain: number, tag: string, format: string, ...args: any[]) : void

Prints FATAL logs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| domain | number | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**. If the value exceeds the range, logs cannot be printed.<br>You can define the value as required. |
| tag    | string | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| format | string | Yes  | Format string used to output logs in a specified format. It can contain several elements, where the parameter type and privacy identifier are mandatory.<br>Parameters labeled **{public}** are public data and are displayed in plaintext; parameters labeled **{private}** (default value) are private data and are filtered by **\<private>**.|
| args   | any[]  | No  | Variable-length parameter list corresponding to the format string. The number and type of parameters must map to the identifier in the format string.|

**Example**

This example is used to output a FATAL log with the format string being `"%{public}s World %{private}d"`. The variable `%{public}s` is a plaintext string, and the variable `%{private}d` is a private integer.

```js
hilog.fatal(0x0001, "testTag", "%{public}s World %{private}d", "hello", 3);
```

If `"hello"` is filled in `%{public}s` and `3` in `%{private}d`, the output log is as follows:

```
08-05 12:21:47.579  2695 2703 F A00001/testTag: hello World <private>
```

## hilog.setMinLogLevel<sup>15+</sup>

setMinLogLevel(level: LogLevel): void

Sets the minimum log level. When a process prints logs, both the minimum log level and the global log level are verified. Therefore, the minimum log level cannot be lower than the global log level. The default value of [global log level](../../dfx/hilog.md#displaying-and-setting-log-levels) is **Info**.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type                 | Mandatory| Description                                                        |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| level  | [LogLevel](#loglevel) | Yes  | Log level.                                                  |

**Example**

Print five HiLog logs of different levels and call the **setMinLogLevel** API twice during the printing.

```js
hilog.info(0x0001, "testTag", 'this is an info level log, id: %{public}d', 1);
hilog.setMinLogLevel(hilog.LogLevel.WARN);
hilog.info(0x0001, "testTag", 'this is an info level log, id: %{public}d', 2);
hilog.error(0x0001, 'testTag', 'this is an error level log, id: %{public}d', 3);
hilog.setMinLogLevel(hilog.LogLevel.DEBUG);
hilog.debug(0x0001, "testTag", 'this is a debug level log, id: %{public}d', 4);
hilog.info(0x0001, "testTag", 'this is an info level log, id: %{public}d', 5);
```

The default value of the global log level is **Info**. Therefore, the first log is printed normally. When the minimum log level of the process is set to **Warn**, the second log fails to be printed because its level is lower than the minimum-log-level log level, and the third log is printed normally. When the minimum log level of the process is set to **Debug**, the fourth log fails to be printed because its level is lower than the global log level, and the fifth log is printed. The result is as follows:

```
08-07 23:50:01.532   13694-13694   A00001/testTag                  com.example.hilogemo  I     this is an info level log, id: 1
08-07 23:50:01.532   13694-13694   A00001/testTag                  com.example.hilogemo  E     this is an error level log, id: 3
08-07 23:50:01.532   13694-13694   A00001/testTag                  com.example.hilogemo  I     this is an info level log, id: 5
```

## Parameter Format

Parameters in the log are printed in the following format:

%{[private flag]}specifier

|  Privacy Flag| Description|
| ------------ | ---- |
|      Unspecified     | The default value is **private**, indicating that parameters in plaintext are not printed.|
|  private     | Prints private parameters.|
|  public      | Prints parameters in plaintext.|

| Specifier| Description| Example|
| ------------ | ---- | ---- |
|      d/i      | Prints logs of the **number** and **bigint** types.| 123 |
|   s     | Prints logs of the **string undefined bool** and **null** types.| "123" |

**Example**
```js
let testObj: Record<string, string | number> = {
    'name': "Jack",
    'age': 22
}
let isBol = true;
let bigNum = BigInt(1234567890123456789);
hilog.info(0x0001, "jsHilogTest", "print object: %{public}s", JSON.stringify(testObj));
hilog.info(0x0001, "jsHilogTest", "private flag: %{private}s %s, print null: %{public}s", "hello", "world", null);
hilog.info(0x0001, "jsHilogTest", "print undefined: %{public}s", undefined);
hilog.info(0x0001, "jsHilogTest", "print number: %{public}d %{public}i", 123, 456);
hilog.info(0x0001, "jsHilogTest", "print bigNum: %{public}d %{public}i", bigNum, bigNum);
hilog.info(0x0001, "jsHilogTest", "print boolean: %{public}s", isBol);
```

**Log printing result**:
```
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print object: {"name":"Jack","age":22}
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: private flag: <private> <private>, print null: null
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print undefined: undefined
08-09 13:26:29.094  2266  2266 I A00001/jsHilogTest: print number: 123 456
08-09 13:26:29.095  2266  2266 I A00001/jsHilogTest: print bigNum: 1234567890123456768 1234567890123456768
08-09 13:26:29.095  2266  2266 I A00001/jsHilogTest: print boolean: true
```
