# @ohos.logLibrary (LogLibrary) (System API)

The **LogLibrary** module provides APIs for obtaining various system maintenance and test logs.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';
```

## LogEntry

Defines a **LogEntry** object.

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| name | string | Yes| No| Log file name. |
| mtime | number | Yes| No | Time of the last modification to the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.|
| size | number | Yes| No | File size, in bytes.|

## logLibrary.list

list(logType: string): LogEntry[]

Obtains the list of log files of the specified type in synchronous mode. This API accepts objects of the string type as input parameters and returns a list log files of the specified type.

**Required permission**: ohos.permission.READ_HIVIEW_SYSTEM

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | Yes| Log type, for example, **HILOG**, **FAULTLOG**, **BETACLUB**, or **REMOTELOG**.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| LogEntry[] | Array of log file objects.|

**Error codes**

For details about the error codes, see [Log Library Error Codes](errorcode-loglibrary-sys.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|

**Example**

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

Copies log files of the specified type to the target application directory. This API uses a promise to return the result.

**Required permission**: ohos.permission.READ_HIVIEW_SYSTEM

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

**Parameters**

| Name   | Type                   | Mandatory| Description|
| --------- | ----------------------- | ---- | --------------- |
| logType | string | Yes| Log type, for example, **HILOG**, **FAULTLOG**, **BETACLUB**, or **REMOTELOG**.|
| logName | string | Yes  | Log file name.|
| dest | string | Yes  | Target directory. Enter the relative path of the directory. If this parameter is specified, log files will be saved to the **hiview/dest** folder in the application cache path, that is, **../cache/hiview/dest**. You can enter a multi-level directory.<br>If you leave this parameter empty, log files will be saved to the root directory, that is, the **hiview** folder in the application cache path.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to return the result. Depending on whether the operation is successful, you can use the **then()** or **catch()** method to process the callback.|

**Error codes**

For details about the error codes, see [Log Library Error Codes](errorcode-loglibrary-sys.md).

| ID| Error Message|
| -------- | ---------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**Example**

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

Copies log files of the specified type to the target application directory. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.READ_HIVIEW_SYSTEM

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | Yes| Log type, for example, **HILOG**, **FAULTLOG**, **BETACLUB**, or **REMOTELOG**.|
| logName | string | Yes  | Log file name.|
| dest | string | Yes  | Target directory. Enter the relative path of the directory. If this parameter is specified, log files will be saved to the **hiview/dest** folder in the application cache path, that is, **../cache/hiview/dest**. You can enter a multi-level directory.<br>If you leave this parameter empty, log files will be saved to the root directory, that is, the **hiview** folder in the application cache path.|
| callback  | AsyncCallback&lt;void&gt; | Yes| Callback used to process the received return value. The value **0** indicates that the operation is successful, and any other value indicates that the operation has failed.|

**Error codes**

For details about the error codes, see [Log Library Error Codes](errorcode-loglibrary-sys.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**Example**

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

Moves log files of the specified type to the target application directory. This API uses a promise to return the result.

**Required permission**: ohos.permission.WRITE_HIVIEW_SYSTEM

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

**Parameters**

| Name   | Type                   | Mandatory| Description|
| --------- | ----------------------- | ---- | --------------- |
| logType | string | Yes| Log type, for example, **FAULTLOG**, **BETACLUB**, or **REMOTELOG**.|
| logName | string | Yes  | Log file name.|
| dest | string | Yes  | Target directory. Enter the relative path of the directory. If this parameter is specified, log files will be saved to the **hiview/dest** folder in the application cache path, that is, **../cache/hiview/dest**. You can enter a multi-level directory.<br>If you leave this parameter empty, log files will be saved to the root directory, that is, the **hiview** folder in the application cache path.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to return the result. Depending on whether the operation is successful, you can use the **then()** or **catch()** method to process the callback.|

**Error codes**

For details about the error codes, see [Log Library Error Codes](errorcode-loglibrary-sys.md).

| ID| Error Message|
| -------- | ---------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**Example**

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

Moves log files of the specified type to the target application directory. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.WRITE_HIVIEW_SYSTEM

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | Yes| Log type, for example, **HILOG**, **FAULTLOG**, **BETACLUB**, or **REMOTELOG**.|
| logName | string | Yes  | Log file name.|
| dest | string | Yes  | Target directory. Enter the relative path of the directory. If this parameter is specified, log files will be saved to the **hiview/dest** folder in the application cache path, that is, **../cache/hiview/dest**. You can enter a multi-level directory.<br>If you leave this parameter empty, log files will be saved to the root directory, that is, the **hiview** folder in the application cache path.|
| callback  | AsyncCallback&lt;void&gt; | Yes| Callback used to process the received return value. The value **0** indicates that the operation is successful, and any other value indicates that the operation has failed.|

**Error codes**

For details about the error codes, see [Log Library Error Codes](errorcode-loglibrary-sys.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**Example**

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

Deletes log files of the specified type in synchronous mode.

**Required permission**: ohos.permission.WRITE_HIVIEW_SYSTEM

**System capability**: SystemCapability.HiviewDFX.Hiview.LogLibrary

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| logType | string | Yes| Log type, for example, **FAULTLOG**, **BETACLUB**, or **REMOTELOG**.|
| logName | string | Yes  | Log file name.|

**Error codes**

For details about the error codes, see [Log Library Error Codes](errorcode-loglibrary-sys.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 201 | Permission denied.  |
| 202 | Permission denied, non-system app called system api. |
| 401 | Invalid argument.|
| 21300001 | Source file does not exists.  |

**Example**

```ts
import { logLibrary } from '@kit.PerformanceAnalysisKit';

try {
  logLibrary.remove('FAULTLOG', 'fault_log_test.zip');
} catch (error) {
  console.error(`error code: ${error?.code}, error msg: ${error?.message}`);
}
```
