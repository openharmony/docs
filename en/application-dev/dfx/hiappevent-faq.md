# HiAppEvent FAQs

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @junjie_shi-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## What should I do if the subscribed events cannot be found?

**Symptom**

In the development and debugging phase, when a fault such as crash or freeze occurs, the events subscribed through HiAppEvent cannot be obtained in the **HiLog** window of DevEco Studio.

**Possible Causes and Solutions**

The application exits after the crash or freeze event occurs.

You can restart the application and view the event content.


## What should I do if the external_log log file cannot be obtained?

**Symptom**

The following log is displayed in HiLog:

- eventInfo.params.external_log=[]

- HiAppEvent file does not exist

**Possible Causes and Solutions**

**Scenario 1**

The directory containing the **external_log** file reaches its space limit.

The **external_log** file is stored in the [application sandbox](../file-management/app-sandbox-directory.md), and the directory space is limited. You can use the **log_over_limit** field to determine whether the directory containing the external_log file reaches its space limit. If the value of **log_over_limit** is **true**, the directory reaches its space limit and the log file cannot be written.

**external_log** is a string array. For example:

**external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_timestamp_xxxx.log"]**.

**Solutions**

Clear historical log files by referring to the solution in [What should I do if the external_log file cannot be deleted](what-should-I-do-if-the-external-log-file-cannot-be-deleted).

**Scenario 2**

Some system events (such as time-consuming launch events) do not have **external_log** files.

**Solutions**

Check whether the event contains **external_log** by referring to [System Events](event-subscription-overview.md#system-events).

**Scenario 3**

The fault event occurs before the event subscription.

System events are not subscribed to before the **addWatcher()** API is called. Therefore, the events before event subscription do not have the **external_log** file.

**Solutions**

Check whether the event occurs before the event subscription. The **external_log** file of an event can be obtained only when the event occurs after event subscription.

**Scenario 4**

The system event fails to be triggered.

If no system event occurs, no **external_log** file is generated.

**Solutions**

Obtain other logs of the system event to check whether the system event is triggered successfully.

**Scenario 5**

The **external_log** log file is deleted after being generated.

For example, the system event C is subscribed to by modules A and B in an application. After processing the callback of system event C, module A deletes the **external_log** file. When module B accesses the **external_log** file in the callback of system event C, a message is displayed, indicating that the log file does not exist.

**Solutions**

Check whether the **external_log** file is deleted by other modules.


## What should I do if the external_log file cannot be deleted

**Symptom**

The directory containing the **external_log** files reaches its space limit, but the **external_log** files cannot be deleted.

**Solution**

- If you have the permission to access the **/data/app** directory of the device, you can manually delete the **external_log** files. File directory:
  **/data/app/el2/100/log/application bundle name/hiappevent** (or **resourcelimit** or **watchdog**).

- If you do not have the permission to access the **/data/app** directory of the device, you can delete the **external_log** file from the application code. The sample code is as follows: For details about the file deletion API, see [fs.unlink](../reference/apis-core-file-kit/js-apis-file-fs.md#fsunlink).

**Code Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

if (eventInfo.params['external_log'] != undefined) {
  for (let index = 0; index < eventInfo.params['external_log'].length; ++index) {
    let externalLog: string = eventInfo.params['external_log'][index];
    hilog.info(0x0000, 'testTag', `externalLog=${externalLog}`);
    // Verify the access permission.
    let res = fs.accessSync(externalLog);
    if (res) {
      hilog.info(0x0000, 'testTag', `HiAppEvent file exists`);
    } else {
      hilog.error(0x0000, 'testTag', `HiAppEvent file does not exist`);
    }
    // Verify the read and write permissions.
    fs.open(externalLog, fs.OpenMode.READ_WRITE).then((file: fs.File) => {
      hilog.info(0x0000, 'testTag', `HiAppEvent file=${externalLog} fd=${file.fd}`);
      fs.closeSync(file);
    }).catch((err: BusinessError) => {
      hilog.info(0x0000, 'testTag',
        `HiAppEvent open file=${externalLog} failed with error message=${err.message}, error code=${err.code}`);
    });
    // Delete the external_log file.
    fs.unlink(externalLog).then(() => {
      console.info("HiAppEvent remove file:" + externalLog + " succeed");
    }).catch((err: BusinessError) => {
      console.error("HiAppEvent remove file:" + externalLog + " failed with error message: " + err.message +
        ", error code: " + err.code);
    });
  }
}
```

Log about accessing and deleting the **external_log** file:

```text
externalLog=/data/storage/el2/log/hiappevent/APP_CRASH_1751081104816_35595.log
HiAppEvent file exists
HiAppEvent file=/data/storage/el2/log/hiappevent/APP_CRASH_1751081104816_35595.log fd=61
HiAppEvent remove file:/data/storage/el2/log/hiappevent/APP_CRASH_1751081104816_35595.log succeed
```


> **NOTE**
>
> The path of **external_log** is the application sandbox directory, not the actual physical path. The application has the permission to access its own sandbox directory. The **external_log** space is limited. After processing log files, delete them in a timely manner.


## Does a thread or process receive only its own event callbacks within the same application?

No, the thread or process also receives event callbacks from other threads or processes within the same application. For example, if an application has two processes (process A and process B) and process A has called **addWatcher()** to subscribe to crash events, process A can receive the crash callback when process B crashes. As long as the application names of processes A and B are the same, the callback can be received.

**API Reference**

[hiAppEvent.addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher)
