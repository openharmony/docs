# HiLog

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import hilog from '@ohos.hilog';
```


## hilog.debug

debug(domain: number, tag: string, format: string, ...args: any[]) : void

Prints logs of the DEBUG level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type | Mandatory | Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | Yes  | Service domain. The value ranges from **0x0** to **0xFFFFF**. |
| tag    | string         | Yes  | String constant used to identify the class or service behavior. |
| format | string         | Yes  | String constant format, including the parameter type and privacy identifier. A parameter without the privacy identifier is treated as a privacy parameter by default. |
| args   | any[]          | Yes  | Variable-length parameter list corresponding to the parameter type in the format string. The number and type of parameters must map to the identifier in the format string. |

**Example**

```js
hilog.debug(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**Output**

```
09-08 12:49:35.941  1547  2452 D FF00/testTag: 1: hello World 3.0
```

## hilog.info

info(domain: number, tag: string, format: string, ...args: any[]) : void

Prints logs of the INFO level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type | Mandatory | Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | Yes  | Service domain. The value ranges from **0x0** to **0xFFFFF**. |
| tag    | string         | Yes  | String constant used to identify the class or service behavior. |
| format | string         | Yes  | String constant format, including the parameter type and privacy identifier. A parameter without the privacy identifier is treated as a privacy parameter by default. |
| args   | any[]  | Yes  | Variable-length parameter list corresponding to the parameter type in the format string. The number and type of parameters must map to the identifier in the format string. |

**Example**

```js
hilog.info(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**Output**

```
09-08 12:49:35.941  1547  2452 I FF00/testTag: 1: hello World 3.0
```

## hilog.warn

warn(domain: number, tag: string, format: string, ...args: any[]) : void

Prints logs of the WARN level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type | Mandatory | Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | Yes  | Service domain. The value ranges from **0x0** to **0xFFFFF**. |
| tag    | string         | Yes  | String constant used to identify the class or service behavior. |
| format | string         | Yes  | String constant format, including the parameter type and privacy identifier. A parameter without the privacy identifier is treated as a privacy parameter by default. |
| args   | any[]  | Yes  | Variable-length parameter list corresponding to the parameter type in the format string. The number and type of parameters must map to the identifier in the format string. |

**Example**

```js
hilog.warn(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**Output**

```
09-08 12:49:35.941  1547  2452 W FF00/testTag: 1: hello World 3.0
```

## hilog.error

error(domain: number, tag: string, format: string, ...args: any[]) : void

Prints logs of the ERROR level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type | Mandatory | Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | Yes  | Service domain. The value ranges from **0x0** to **0xFFFFF**. |
| tag    | string         | Yes  | String constant used to identify the class or service behavior. |
| format | string         | Yes  | String constant format, including the parameter type and privacy identifier. A parameter without the privacy identifier is treated as a privacy parameter by default. |
| args   | any[]  | Yes  | Variable-length parameter list corresponding to the parameter type in the format string. The number and type of parameters must map to the identifier in the format string. |

**Example**

```js
hilog.error(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**Output**

```
09-08 12:49:35.941  1547  2452 E FF00/testTag: 1: hello World 3.0
```

## hilog.fatal

fatal(domain: number, tag: string, format: string, ...args: any[]) : void

Prints logs of the FATAL level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type | Mandatory | Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| domain | number         | Yes  | Service domain. The value ranges from **0x0** to **0xFFFFF**.                                 |
| tag    | string         | Yes  | String constant used to identify the class or service behavior.                  |
| format | string         | Yes  | String constant format, including the parameter type and privacy identifier. A parameter without the privacy identifier is treated as a privacy parameter by default. |
| args   | any[]  | Yes  | Variable-length parameter list corresponding to the parameter type in the format string. The number and type of parameters must map to the identifier in the format string. |

**Example**

```js
hilog.fatal(0xFF00, "testTag", "%d: %{private}s World %{public}f", 1, "hello", 3.0);
```

**Output**

```
09-08 12:49:35.941  1547  2452 F FF00/testTag: 1: hello World 3.0
```

## hilog.isLoggable

isLoggable(domain: number, tag: string, level: LogLevel) : boolean

Checks whether printing is enabled for a domain, tag, or log level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Parameters**

| Name| Type | Mandatory | Description                                      |
| ------ | --------------------- | ---- | ------------------------------------------ |
| domain | number                | Yes  | Service domain. The value ranges from **0x0** to **0xFFFFF**.               |
| tag    | string                | Yes  | String constant used to identify the class or service behavior. |
| level  | [LogLevel](#loglevel) | Yes  | Log level.                                |

**Example**

```js
hilog.isLoggable(0xFF00, "testTag", hilog.DEBUG);
```

## LogLevel

Enumerates event types.

**System capability**: SystemCapability.HiviewDFX.HiLog

| Name | Default Value | Description       |
| ----- | ------ | ----------- |
| DEBUG | 3      | DEBUG level |
| INFO  | 4      | INFO level |
| WARN  | 5      | WARN level |
| ERROR | 6      | ERROR level |
| FATAL | 7      | FATAL level |
