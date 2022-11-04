# 故障日志获取
> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import faultLogger from '@ohos.faultLogger'
```


## FaultType

故障类型枚举。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.Hiview.FaultLogger。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| NO_SPECIFIC | 0 | 不区分故障类型 |
| CPP_CRASH | 2 | C++程序故障类型 |
| JS_CRASH | 3 | JS程序故障类型 |
| APP_FREEZE | 4 | 应用程序卡死故障类型 |

## FaultLogInfo

故障信息数据结构，获取到的故障信息的数据结构。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.Hiview.FaultLogger。

| 名称 | 参数类型 | 说明 |
| -------- | -------- | -------- |
| pid | number | 故障进程的进程id |
| uid | number | 故障进程的用户id |
| type | [FaultType](#faulttype) | 故障类型 |
| timestamp | number | 日志生成时的秒级时间戳 |
| reason | string | 发生故障的原因 |
| module | string | 发生故障的模块 |
| summary | string | 故障的概要 |
| fullLog | string | 故障日志全文 |

## faultLogger.querySelfFaultLog<sup>(deprecated)</sup>

querySelfFaultLog(faultType: FaultType, callback: AsyncCallback&lt;Array&lt;FaultLogInfo&gt;&gt;) : void

> **说明：** 从 API Version 9 开始废弃，建议使用[faultLogger.query](#faultloggerquery9)替代。

获取当前进程故障信息，该方法通过回调方式获取故障信息数组，故障信息数组内最多上报10份故障信息。

**系统能力：** SystemCapability.HiviewDFX.Hiview.FaultLogger

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | 是 | 输入要查询的故障类型。 |
| callback | AsyncCallbackArray&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | 是 | 回调函数，在回调函数中获取故障信息数组。<br/>-&nbsp;value拿到故障信息数组；value为undefined表示获取过程中出现异常，error返回错误提示字符串

**示例：**

```js
function queryFaultLogCallback(error, value) {
    if (error) {
        console.info('error is ' + error);
    } else {
        console.info("value length is " + value.length);
        let len = value.length;
        for (let i = 0; i < len; i++) {
            console.info("log: " + i);
            console.info("Log pid: " + value[i].pid);
            console.info("Log uid: " + value[i].uid);
            console.info("Log type: " + value[i].type);
            console.info("Log timestamp: " + value[i].timestamp);
            console.info("Log reason: " + value[i].reason);
            console.info("Log module: " + value[i].module);
            console.info("Log summary: " + value[i].summary);
            console.info("Log text: " + value[i].fullLog);
        }
    }
}
faultLogger.querySelfFaultLog(faultLogger.FaultType.JS_CRASH, queryFaultLogCallback);
```

## faultLogger.querySelfFaultLog<sup>(deprecated)</sup>

querySelfFaultLog(faultType: FaultType) : Promise&lt;Array&lt;FaultLogInfo&gt;&gt;

> **说明：** 从 API Version 9 开始废弃，建议使用[faultLogger.query](#faultloggerquery9-1)替代。

获取当前进程故障信息，该方法通过Promise方式返回故障信息数组，故障信息数组内最多上报10份故障信息。

**系统能力：** SystemCapability.HiviewDFX.Hiview.FaultLogger

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | 是 | 输入要查询的故障类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Promise实例，可以在其then()方法中获取故障信息实例，也可以使用await。 <br/>-&nbsp;value拿到故障信息数组；value为undefined表示获取过程中出现异常 |

**示例：**

```js
async function getLog() {
    let value = await faultLogger.querySelfFaultLog(faultLogger.FaultType.JS_CRASH);
    if (value) {
        console.info("value length is " + value.length);
        let len = value.length;
        for (let i = 0; i < len; i++) {
            console.info("log: " + i);
            console.info("Log pid: " + value[i].pid);
            console.info("Log uid: " + value[i].uid);
            console.info("Log type: " + value[i].type);
            console.info("Log timestamp: " + value[i].timestamp);
            console.info("Log reason: " + value[i].reason);
            console.info("Log module: " + value[i].module);
            console.info("Log summary: " + value[i].summary);
            console.info("Log text: " + value[i].fullLog);
        }
    }
}
```

## faultLogger.query<sup>9+</sup>

query(faultType: FaultType, callback: AsyncCallback&lt;Array&lt;FaultLogInfo&gt;&gt;) : void

获取当前进程故障信息，该方法通过回调方式获取故障信息数组，故障信息数组内最多上报10份故障信息。

**系统能力：** SystemCapability.HiviewDFX.Hiview.FaultLogger

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | 是 | 输入要查询的故障类型。 |
| callback | AsyncCallbackArray&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | 是 | 回调函数，在回调函数中获取故障信息数组。<br/>-&nbsp;value拿到故障信息数组；value为undefined表示获取过程中出现异常，error返回错误提示字符串

**错误码：**

以下错误码的详细介绍参见[ohos.faultLogger错误码](../errorcodes/errorcode-faultlogger.md)。

| 错误码ID | 错误信息（此处仅提供错误抛出的关键信息） |
| --- | --- |
| 10600001 | The service is not running or broken |

**示例：**

```js
function queryFaultLogCallback(error, value) {
    if (error) {
        console.info('error is ' + error);
    } else {
        console.info("value length is " + value.length);
        let len = value.length;
        for (let i = 0; i < len; i++) {
            console.info("log: " + i);
            console.info("Log pid: " + value[i].pid);
            console.info("Log uid: " + value[i].uid);
            console.info("Log type: " + value[i].type);
            console.info("Log timestamp: " + value[i].timestamp);
            console.info("Log reason: " + value[i].reason);
            console.info("Log module: " + value[i].module);
            console.info("Log summary: " + value[i].summary);
            console.info("Log text: " + value[i].fullLog);
        }
    }
}
try {
    faultLogger.query(faultLogger.FaultType.JS_CRASH, queryFaultLogCallback);
} catch (err) {
    console.error(`code: ${err.code}, message: ${err.message}`);
}
```

## faultLogger.query<sup>9+</sup>

query(faultType: FaultType) : Promise&lt;Array&lt;FaultLogInfo&gt;&gt;

获取当前进程故障信息，该方法通过Promise方式返回故障信息数组，故障信息数组内最多上报10份故障信息。

**系统能力：** SystemCapability.HiviewDFX.Hiview.FaultLogger

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | 是 | 输入要查询的故障类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Promise实例，可以在其then()方法中获取故障信息实例，也可以使用await。 <br/>-&nbsp;value拿到故障信息数组；value为undefined表示获取过程中出现异常 |

**错误码：**

以下错误码的详细介绍参见[ohos.faultLogger错误码](../errorcodes/errorcode-faultlogger.md)。

| 错误码ID | 错误信息（此处仅提供错误抛出的关键信息） |
| --- | --- |
| 10600001 | The service is not running or broken |

**示例：**

```js
async function getLog() {
    try {
        let value = await faultLogger.query(faultLogger.FaultType.JS_CRASH);
        if (value) {
            console.info("value length is " + value.length);
            let len = value.length;
            for (let i = 0; i < len; i++) {
                console.info("log: " + i);
                console.info("Log pid: " + value[i].pid);
                console.info("Log uid: " + value[i].uid);
                console.info("Log type: " + value[i].type);
                console.info("Log timestamp: " + value[i].timestamp);
                console.info("Log reason: " + value[i].reason);
                console.info("Log module: " + value[i].module);
                console.info("Log summary: " + value[i].summary);
                console.info("Log text: " + value[i].fullLog);
            }
        }
    } catch (err) {
        console.error(`code: ${err.code}, message: ${err.message}`);
    }
}
```
