# 订阅崩溃事件（ArkTS）

## 接口描述

本文介绍如何使用HiAppEvent提供的ArkTs接口订阅应用崩溃事件。接口的详细使用说明（参数限制、取值范围等）请参考[应用事件打点API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

> **说明：**
>
> 使用ArkTS接口可以订阅JsError和NativeCrash两种类型崩溃事件。

### 自定义参数设置接口描述

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt; | 事件自定义参数设置方法。 |

### 订阅接口描述

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

### 崩溃日志配置参数设置接口描述

系统提供了通用的NativeCrash崩溃日志生成功能，但一些应用对NativeCrash崩溃日志打印内容有个性化的需求，因此从**API version 20**开始支持设置崩溃日志配置参数。

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| setEventConfig(name: string, config: Record<string, ParamType>): Promise\<void> | 从API version 20开始，支持设置崩溃日志配置参数，name需设置为崩溃事件名称常量`hiappevent.event.APP_CRASH`。**仅支持NativeCrash类型崩溃。** |

#### 参数设置说明

开发者可以使用上述hiappevent提供的接口，在Record<string, ParamType>中配置崩溃日志打印规格的参数。具体参数说明如下：

| 参数名 | 类型 | 必填 | 说明 |
| -----| ----- | ----- |----- |
| extend_pc_lr_printing | boolean | 否 | true：64位系统打印pc和lr寄存器地址向前248字节、向后256字节范围的内存值。32位系统打印pc和lr寄存器地址向前124字节、向后128字节范围的内存值。<br/>false：64位系统打印pc和lr寄存器地址向前16字节、向后232字节范围的内存值。32位系统化打印pc和lr寄存器地址向前8字节、向后116字节范围的内存值。<br/>缺省时默认为false。<br/> |
| log_file_cutoff_sz_bytes | number | 否 | 单位为byte，取值范围为[0-5242880]。<br/>如果设置，按设置的参数值截断崩溃日志大小。<br/> 如果不设置，默认值取0表示不截断崩溃日志。<br/> |
| simplify_vma_printing | boolean | 否 | true：只打印崩溃日志中出现的地址所属的VMA（Virtual Memory Area，进程地址空间中的区域）映射信息，即崩溃日志中Maps，以减小日志大小。<br/>false：打印所有VMA映射信息。<br/>缺省时默认为false。<br/>|

参数配置示例如下:

```text
let configParams: Record<string, hiAppEvent.ParamType> = {
    "extend_pc_lr_printing": true, // 使能扩展打印pc和lr寄存器附近的内存值
    "log_file_cutoff_sz_bytes": 102400, // 截断崩溃日志到100KB
    "simplify_vma_printing": true // 使能精简打印maps
};
```

以32位系统为例，参考[订阅崩溃事件（ArkTS）接口使用示例](#接口使用示例)开发完成崩溃事件订阅和日志配置参数设置，然后通过[external_log](hiappevent-watcher-crash-events.md#params字段说明)字段获取NativeCrash类型崩溃日志内容。日志中打印如下使能的配置参数列表：

``` text
...
Build info:OpenHarmony 6.0.0.33
Enabled app log configs:    <- 使能的配置参数列表，只打印不是默认值的配置参数
Extend pc lr printing:true  <- extend_pc_lr_printing参数设置为true
Log cut off size:102400B    <- 崩溃日志大小截断到100KB
Simplify maps printing:true <- simplify_vma_printing参数设置为true
Timestamp:2025-05-17 19:17:07.000
...
```

崩溃日志详细说明见[崩溃日志内容说明](cppcrash-guidelines.md#崩溃日志内容说明)中**应用通过hiAppEvent设置崩溃日志配置参数场景**。

## 接口使用示例

### 添加事件观察者

以订阅用户点击按钮触发崩溃生成的崩溃事件为例，说明开发步骤。

1. DevEco Studio新建Native C++模版工程，编辑“entry > src > main > ets > entryability > EntryAbility.ets”文件，导入依赖模块，示例代码如下：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中设置事件的[自定义参数](#自定义参数设置接口描述)和[崩溃日志配置参数](#崩溃日志配置参数设置接口描述)，示例代码如下：

   ```ts
    // 开发者完成参数键值对赋值
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // 开发者可以设置崩溃事件的自定义参数
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_CRASH).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });

    // 构建配置项
    let configParams: Record<string, hiAppEvent.ParamType> = {
      "extend_pc_lr_printing": true, // 使能扩展打印pc和lr寄存器附近的内存值
      "log_file_cutoff_sz_bytes": 102400, // 截断崩溃日志到100KB
      "simplify_vma_printing": true // 使能精简打印maps
    };

    // 开发者可以设置崩溃日志配置参数
    hiAppEvent.setEventConfig(hiAppEvent.event.APP_CRASH, configParams).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event config.`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   ```

3. 编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，在 `onCreate` 函数中添加系统事件的订阅，示例代码如下：

   ```ts
    let watcher: hiAppEvent.Watcher = {
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了崩溃事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_CRASH]
        }
      ],
      // 开发者可以自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // 开发者可以根据事件集合中的事件名称区分不同的系统事件
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // 开发者可以对事件集合中的事件数据进行自定义处理，此处是将事件数据打印在日志中
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // 开发者可以获取到崩溃事件发生的时间戳
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // 开发者可以获取到崩溃事件发生的崩溃类型
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.crash_type=${eventInfo.params['crash_type']}`);
            // 开发者可以获取到崩溃应用的前后台状态
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
            // 开发者可以获取到崩溃应用的版本信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // 开发者可以获取到崩溃应用的包名
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // 开发者可以获取到崩溃应用的进程id
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params['uuid']}`);
            // 开发者可以获取到崩溃事件发生的异常类型、异常原因和异常调用栈
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
            // 开发者可以获取到崩溃事件发生时日志信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
            // 开发者可以获取到崩溃事件发生时的崩溃日志文件
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
            // 开发者可以获取到崩溃事件的自定义数据test_data
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.test_data=${eventInfo.params['test_data']}`);
          }
        }
      }
    };
    hiAppEvent.addWatcher(watcher);
   ```

4. 构造崩溃场景

- 构造NativeCrash类型崩溃

  编辑工程中的“entry > src > main > cpp > napi_init.cpp”文件，`Add`方法中增加如下代码：

  ```cpp
  int *p = nullptr;
  int a = *p; // 空指针解引用，程序会在此处崩溃
  ```

  编辑工程中的“entry > src > main > ets > pages > Index.ets”文件，添加按钮并在其 `onClick` 函数中构造崩溃场景，以触发崩溃事件。示例代码如下：

  ```ts
  Button("appCrash").onClick(()=>{
    // 在按钮点击函数中调用napi_init.cpp中Add方法触发NativeCrash类型崩溃事件
    testNapi.add(2, 3);
  })
    ```

- 构造JsError类型崩溃
  
  编辑工程中的“entry > src > main > ets > pages > Index.ets”文件，添加按钮并在其 `onClick` 函数中构造崩溃场景，以触发崩溃事件。示例代码如下：

  ```ts
  Button("appCrash").onClick(()=>{
    // 在按钮点击函数中构造一个JsError类型崩溃，触发应用崩溃事件
    let result: object = JSON.parse("");
  })
  ```

5. 点击DevEco Studio界面的运行按钮，启动应用工程。在应用界面中点击“appCrash”按钮，触发崩溃事件。系统根据崩溃类型（JsError或NativeCrash）生成相应的崩溃日志并进行回调。
  JsError通过进程内采集故障信息的方式触发回调迅速，而NativeCrash采取进程外采集故障信息，平均耗时约2秒，具体耗时受业务线程数量和进程间通信耗时影响。开发者可以订阅崩溃事件，故障信息采集完成后会异步上报，不会阻塞当前业务。

### 验证观察者是否订阅到崩溃事件

在应用未主动捕获崩溃异常和主动捕获崩溃异常的场景中，崩溃事件会在不同时机得到回调，开发者需要在不同时机验证是否订阅到崩溃事件。

#### 应用未主动捕获崩溃异常场景

若应用未主动捕获崩溃异常，系统处理崩溃后应用将退出，**应用下次启动时**，HiAppEvent将崩溃事件上报给应用已注册的监听，完成回调。

#### 应用主动捕获崩溃异常场景

若应用主动捕获崩溃异常，崩溃事件将在**应用退出前**回调，例如以下两种情况：

1. 异常处理中未主动退出，应用崩溃后将不会退出。
采用[errorManager.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)方法捕获异常会导致JsError类型的崩溃事件在应用退出前回调。若应用主动注册[崩溃异常信号](cppcrash-guidelines.md#哪些信号会生成cppcrash日志)处理函数但未主动退出，会导致NativeCrash类型的崩溃事件在应用退出前回调。

2. 异常处理耗时过长，导致应用退出时间延迟。

在开发调试阶段，HiAppEvent上报事件完成回调后，可以在DevEco Studio的HiLog窗口查看订阅到的JsError类型崩溃事件内容，NativeCrash类型崩溃略有不同，不展开讲述，崩溃事件字段说明详见[崩溃事件介绍](hiappevent-watcher-crash-events.md#事件字段说明)。JsError类型崩溃事件内容样例如下：

```text
HiAppEvent onReceive: domain=OS
HiAppEvent eventName=APP_CRASH
HiAppEvent eventInfo.domain=OS
HiAppEvent eventInfo.name=APP_CRASH
HiAppEvent eventInfo.eventType=1
HiAppEvent eventInfo.params.time=1711440614001
HiAppEvent eventInfo.params.crash_type=JsError
HiAppEvent eventInfo.params.foreground=true
HiAppEvent eventInfo.params.bundle_version=1.0.0
HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
HiAppEvent eventInfo.params.pid=2043
HiAppEvent eventInfo.params.uid=20010043
HiAppEvent eventInfo.params.uuid=b1e953ba0022c112e4502e28e8b3ad6d95cf3c87bae74068038f03b38ce7f66a
HiAppEvent eventInfo.params.exception={"message":"Unexpected Text in JSON","name":"SyntaxError","stack":"at anonymous (entry/src/main/ets/pages/Index.ets:55:34)"}
HiAppEvent eventInfo.params.hilog.size=90
HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1711440614112_2043.log"]
HiAppEvent eventInfo.params.log_over_limit=false
HiAppEvent eventInfo.params.test_data=100
```

### 移除并销毁事件观察者

  ```ts
  // 移除该应用事件观察者以取消订阅事件
  hiAppEvent.removeWatcher(watcher);
  ```
<!--RP1-->
<!--RP1End-->