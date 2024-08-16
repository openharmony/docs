# @ohos.logLibrary (维测日志获取)(系统接口)

本模块提供了获取各类系统维测日志的能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 导入模块

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';
```

## LogEntry

日志文件对象接口。

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 是 | 否 | 文件名称。 |
| mtime | number | 是 | 否  | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |
| size | number | 是 | 否  | 文件大小，以字节为单位。 |

## logLibrary.list

list(logType: string): LogEntry[]

以同步方法查询指定类型的日志文件列表，接收string类型的对象作为参数，返回指定类型日志的文件列表信息。

**需要权限：** ohos.permission.READ_HIVIEW_SYSTEM

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | 是 | 日志类型字符串，例如“HILOG”, "FAULTLOG", "BETACLUB", "REMOTELOG"等。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| LogEntry[] | 日志文件对象的数组。 |

**错误码：**

以下错误码的详细介绍请参见[维测日志错误码](errorcode-loglibrary-sys.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|

**示例：**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';

try {
    let logObj = logLibrary.list('HILOG');
    // do something here.
} catch (error) {
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```

## logLibrary.copy

copy(logType: string, logName: string, dest: string): Promise&lt;void&gt;

拷贝指定日志类型的指定文件到目标应用目录下。使用Promise回调。

**需要权限：** ohos.permission.READ_HIVIEW_SYSTEM

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

**参数：**

| 参数名    | 类型                    | 必填 | 说明 |
| --------- | ----------------------- | ---- | --------------- |
| logType | string | 是 | 日志类型字符串，例如“HILOG”, "FAULTLOG", "BETACLUB", "REMOTELOG"等。 |
| logName | string | 是   | 日志文件名称。 |
| dest | string | 是   | 目标目录，需填入相对目录名称。传入dest字串后，日志文件将保存到应用缓存路径下的"hiview/*dest*"文件夹，即"../cache/hiview/*dest*"。可填入多层目录。<br>如果传入空字串，将保存到根目录下，即应用缓存路径下的hiview文件夹。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise实例，可以在其then()、catch()方法中分别对拷贝成功、拷贝异常的回调进行处理。 |

**错误码：**

以下错误码的详细介绍请参见[维测日志错误码](errorcode-loglibrary-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**示例：**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    logLibrary.copy('HILOG', 'hiapplogcat-1.zip', ''
    ).then(
        (val) => {
            // do something here.
        }
    ).catch(
        (err: BusinessError) => {
            // do something here.
        }
    )
} catch (error) {
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```

## logLibrary.copy

copy(logType: string, logName: string, dest: string, callback: AsyncCallback&lt;void&gt;): void

拷贝指定日志类型的指定文件到目标应用目录下。使用callback回调。

**需要权限：** ohos.permission.READ_HIVIEW_SYSTEM

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | 是 | 日志类型字符串，例如“HILOG”, "FAULTLOG", "BETACLUB", "REMOTELOG"等。 |
| logName | string | 是   | 日志文件名称。 |
| dest | string | 是   | 目标目录，需填入相对目录名称。传入dest字串后，日志文件将保存到应用缓存路径下的"hiview/*dest*"文件夹，即"../cache/hiview/*dest*"。可填入多层目录。<br>如果传入空字串，将保存到根目录下，即应用缓存路径下的hiview文件夹。 |
| callback  | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。0表示拷贝成功，其它值表示拷贝失败。 |

**错误码：**

以下错误码的详细介绍请参见[维测日志错误码](errorcode-loglibrary-sys.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**示例：**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';

try {
    logLibrary.copy('HILOG', 'hiapplogcat-1.zip', 'dir1', (error, val) => {
        if (val === undefined) {
            // copy failed.
        } else {
            // copy success.
        }
    });
} catch (error) {
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```

## logLibrary.move

move(logType: string, logName: string, dest: string): Promise&lt;void&gt;

移动指定日志类型的指定文件到目标应用目录下。使用Promise回调。

**需要权限：** ohos.permission.WRITE_HIVIEW_SYSTEM

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

**参数：**

| 参数名    | 类型                    | 必填 | 说明 |
| --------- | ----------------------- | ---- | --------------- |
| logType | string | 是 | 日志类型字符串，例如"FAULTLOG", "BETACLUB", "REMOTELOG"等。 |
| logName | string | 是   | 日志文件名称。 |
| dest | string | 是   | 目标目录，需填入相对目录名称。传入dest字串后，日志文件将保存到应用缓存路径下的"hiview/*dest*"文件夹，即"../cache/hiview/*dest*"。可填入多层目录。<br>如果传入空字串，将保存到根目录下，即应用缓存路径下的hiview文件夹。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise实例，可以在其then()、catch()方法中分别对移动成功、移动异常的回调进行处理。 |

**错误码：**

以下错误码的详细介绍请参见[维测日志错误码](errorcode-loglibrary-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**示例：**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    logLibrary.move('FAULTLOG', 'fault_log_test.zip', ''
    ).then(
        (val) => {
            // do something here.
        }
    ).catch(
        (err: BusinessError) => {
            // do something here.
        }
    )
} catch (error) {
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```

## logLibrary.move

move(logType: string, logName: string, dest: string, callback: AsyncCallback&lt;void&gt;): void

移动指定日志类型的指定文件到目标应用目录下。使用callback回调。

**需要权限：** ohos.permission.WRITE_HIVIEW_SYSTEM

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | 是 | 日志类型字符串，例如“HILOG”, "FAULTLOG", "BETACLUB", "REMOTELOG"等。 |
| logName | string | 是   | 日志文件名称。 |
| dest | string | 是   | 目标目录，需填入相对目录名称。传入dest字串后，日志文件将保存到应用缓存路径下的"hiview/*dest*"文件夹，即"../cache/hiview/*dest*"。可填入多层目录。<br>如果传入空字串，将保存到根目录下，即应用缓存路径下的hiview文件夹。 |
| callback  | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。0表示移动成功，其它值表示移动失败。 |

**错误码：**

以下错误码的详细介绍请参见[维测日志错误码](errorcode-loglibrary-sys.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**示例：**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';

try {
    logLibrary.move('FAULTLOG', 'fault_log_test.zip', 'dir1/dir2', (error, val) => {
        if (val === undefined) {
            // move failed.
        } else {
            // move success.
        }
    });
} catch (error) {
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```

## logLibrary.remove

remove(logType: string, logName: string): void

以同步方法删除指定日志类型的指定文件。

**需要权限：** ohos.permission.WRITE_HIVIEW_SYSTEM

**系统能力：** SystemCapability.HiviewDFX.Hiview.LogLibrary

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | 是 | 日志类型字符串，例如"FAULTLOG", "BETACLUB", "REMOTELOG"等。 |
| logName | string | 是   | 日志文件名称。 |

**错误码：**

以下错误码的详细介绍请参见[维测日志错误码](errorcode-loglibrary-sys.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**示例：**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';

try {
  logLibrary.remove('FAULTLOG', 'fault_log_test.zip');
} catch (error) {
  console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```