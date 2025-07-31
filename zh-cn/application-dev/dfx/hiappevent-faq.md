# HiAppEvent常见问题


## 查不到已通过HiAppEvent订阅的事件内容

**问题现象**

在开发调试阶段，崩溃、应用冻屏等故障发生后，无法在DevEco Studio的HiLog窗口中获取已通过HiAppEvent订阅的事件内容。

**可能的原因&amp;解决措施**

发生崩溃、应用冻屏等故障后，应用已退出。

解决办法：再次启动应用，查看相应的事件内容。


## 无法获取external_log日志文件

**问题现象**

Hilog中出现如下日志：

- eventInfo.params.external_log=[]

- HiAppEvent file does not exist

**可能的原因&amp;解决措施**

**情况一**：

external_log日志文件所在目录的空间已达到上限。

external_log所在的目录为[应用沙箱目录](../file-management/app-sandbox-directory.md)，目录空间受限。log_over_limit字段用于判断external_log日志文件所在目录的空间是否达到上限。如果log_over_limit的值为true，表示external_log日志文件所在目录空间已达到上限，事件包含的日志文件将无法写入。

external_log是一个字符串数组。例如：

external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_时间戳_xxxx.log"]。

**可采取的解决措施**：

参考[无法删除external_log日志文件](#无法删除external_log日志文件)中的解决措施，清理历史日志文件。

**情况二**：

部分系统事件（如启动耗时事件）本身没有external_log，因而没有external_log日志文件。

**可采取的解决措施**：

查看对应的事件介绍章节，确认事件是否包含external_log：[系统事件](event-subscription-overview.md#系统事件)。

**情况三**：

事件发生在事件订阅之前。

在调用事件订阅接口addWatcher()前，没有开始监听系统事件。因此事件订阅之前的事件没有external_log日志文件。

**可采取的解决措施**：

确认事件订阅与事件发生的时序关系。先事件订阅，然后事件发生，才能获取到事件的external_log日志文件。

**情况四**：

系统事件没有触发成功。

如果系统事件没发生，就不会有external_log日志文件。

**可采取的解决措施**：

查看系统事件的其他日志，确认系统事件是否已经触发成功。

**情况五**：

external_log日志文件生成后又被删除了。

例如，在一个应用中，A和B两个模块都订阅了系统事件C。A模块处理完系统事件C的回调后，删除了external_log日志文件。随后B模块在系统事件C的回调中访问external_log日志文件，会提示日志文件不存在。

**可采取的解决措施**：

检查其他模块是否已删除external_log日志文件。


## 无法删除external_log日志文件

**问题现象**

external_log日志文件所在目录的空间已达到上限，但无法删除external_log日志文件。

**解决措施**

- 开发者如果有权限访问设备的/data/app目录，可以手动删除external_log日志文件。文件目录为
  /data/app/el2/100/log/应用包名/hiappevent（或resourcelimit或watchdog）。

- 开发者若没有权限访问设备的/data/app目录，可以在应用代码中删除external_log日志文件。代码示例如下。文件删除接口可以参考[fs.unlink](../reference/apis-core-file-kit/js-apis-file-fs.md#fsunlink)。

**代码示例**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

if (eventInfo.params['external_log'] != undefined) {
  for (let index = 0; index < eventInfo.params['external_log'].length; ++index) {
    let externalLog: string = eventInfo.params['external_log'][index];
    hilog.info(0x0000, 'testTag', `externalLog=${externalLog}`);
    // 验证访问权限：
    let res = fs.accessSync(externalLog);
    if (res) {
      hilog.info(0x0000, 'testTag', `HiAppEvent file exists`);
    } else {
      hilog.error(0x0000, 'testTag', `HiAppEvent file does not exist`);
    }
    // 验证读写权限：
    fs.open(externalLog, fs.OpenMode.READ_WRITE).then((file: fs.File) => {
      hilog.info(0x0000, 'testTag', `HiAppEvent file=${externalLog} fd=${file.fd}`);
      fs.closeSync(file);
    }).catch((err: BusinessError) => {
      hilog.info(0x0000, 'testTag',
        `HiAppEvent open file=${externalLog} failed with error message=${err.message}, error code=${err.code}`);
    });
    // 删除external_log日志文件：
    fs.unlink(externalLog).then(() => {
      console.info("HiAppEvent remove file:" + externalLog + " succeed");
    }).catch((err: BusinessError) => {
      console.error("HiAppEvent remove file:" + externalLog + " failed with error message: " + err.message +
        ", error code: " + err.code);
    });
  }
}
```

访问及删除external_log日志文件的日志：

```text
externalLog=/data/storage/el2/log/hiappevent/APP_CRASH_1751081104816_35595.log
HiAppEvent file exists
HiAppEvent file=/data/storage/el2/log/hiappevent/APP_CRASH_1751081104816_35595.log fd=61
HiAppEvent remove file:/data/storage/el2/log/hiappevent/APP_CRASH_1751081104816_35595.log succeed
```


> **说明：**
>
> external_log返回的路径是应用沙箱目录，非真实物理路径。应用有权限访问自己的沙箱目录。external_log日志空间受限，应用处理完日志文件后应及时删除。


## 同一应用内，事件的回调不区分线程、进程

例如，在同一个应用内，有A、B两个进程，进程A已调用addWatcher()接口订阅崩溃事件。如果进程B发生崩溃，进程A能收到进程B的崩溃回调。只要进程A和B的应用名一致即可。

**接口参考链接**

[hiAppEvent.addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher)。
