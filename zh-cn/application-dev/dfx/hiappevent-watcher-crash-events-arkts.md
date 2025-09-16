# 订阅崩溃事件（ArkTS）
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

本文介绍如何使用HiAppEvent提供的ArkTS接口订阅应用崩溃事件。接口的详细使用说明（参数限制、取值范围等）请参考[@ohos.hiviewdfx.hiAppEvent (应用事件打点)ArkTS API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

> **说明：**
>
> 使用ArkTS接口可以订阅JsError和NativeCrash两种崩溃事件。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

### 添加事件观察者

**建议在应用启动后、执行业务逻辑前添加事件观察者，以确保能够订阅到崩溃事件。**

以订阅用户点击按钮触发崩溃生成的崩溃事件为例，说明开发步骤。

1. DevEco Studio新建Native C++模板工程，编辑“entry > src > main > ets > entryability > EntryAbility.ets”文件，导入依赖模块。示例代码如下：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中设置事件的[崩溃事件自定义参数](hiappevent-watcher-crash-events.md#崩溃事件自定义参数设置)和[崩溃日志规格自定义参数](hiappevent-watcher-crash-events.md#崩溃日志规格自定义参数设置)，示例代码如下：

   ```ts
    // 构建崩溃事件的自定义参数
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // 开发者可以设置崩溃事件的自定义参数
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_CRASH).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   
    // 构建崩溃日志规格自定义参数
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

3. 编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，在 `onCreate` 函数中订阅系统事件。示例代码如下：

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

      编辑工程中的“entry > src > main > cpp > napi_init.cpp”文件，Add方法中增加如下代码：

      ```cpp
      int *p = nullptr;
      int a = *p; // 空指针解引用，程序会在此处崩溃
      ```

       编辑工程中的“entry > src > main > ets > pages > Index.ets”文件，添加按钮并在其onClick函数中构造崩溃场景，以触发崩溃事件。示例代码如下：

      ```ts
      Button("NativeCrash").onClick(()=>{
        // 在按钮点击函数中调用napi_init.cpp中Add方法触发NativeCrash类型崩溃事件
        testNapi.add(2, 3);
      })
      ```

    - 构造JsError类型崩溃

      编辑工程中的“entry > src > main > ets > pages > Index.ets”文件，添加按钮并在其onClick函数中构造崩溃场景，以触发崩溃事件。示例代码如下：

      ```ts
      Button("JsError").onClick(()=>{
        // 在按钮点击函数中构造一个JsError类型崩溃，触发应用崩溃事件
        let result: object = JSON.parse("");
      })
      ```

5. 点击DevEco Studio界面的运行按钮，启动应用工程。在应用界面中点击“NativeCrash”或“JsError”按钮，触发崩溃事件。系统根据崩溃类型生成相应的日志并进行回调。

> **说明：**
>
> JsError通过进程内采集故障信息触发回调，速度快，而NativeCrash采取进程外采集故障信息，平均耗时约2秒，具体受业务线程数量和进程间通信影响。开发者可订阅崩溃事件，故障信息采集完成后异步上报，不阻塞当前业务。

### 验证观察者是否订阅到崩溃事件

在应用主动捕获崩溃异常和未主动捕获崩溃异常的场景下，崩溃事件的回调时机不同，需在不同时间验证是否订阅到崩溃事件。

**应用未主动捕获崩溃异常场景**

若应用未主动捕获崩溃异常，系统处理崩溃后应用将退出。**应用下次启动时**，HiAppEvent将崩溃事件上报给已注册的监听，完成回调。

**应用主动捕获崩溃异常场景**

若应用主动捕获崩溃异常，崩溃事件将在**应用退出前**回调，例如以下两种情况：

1. 异常处理中未主动退出，应用崩溃后将不会退出。

   采用[errorManger.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)方法捕获异常会导致JsError类型的崩溃事件在应用退出前回调。若应用主动注册[崩溃信号](cppcrash-guidelines.md#系统处理的崩溃信号)处理函数但未主动退出，会导致NativeCrash类型的崩溃事件在应用退出前回调。

2. 异常处理耗时过长，导致应用退出延迟。

在开发调试阶段，HiAppEvent上报事件完成回调后，可以在DevEco Studio的HiLog窗口查看JsError类型崩溃事件内容。NativeCrash类型崩溃事件内容略有不同，具体参见[崩溃事件字段说明](hiappevent-watcher-crash-events.md#事件字段说明)。JsError类型崩溃事件内容样例如下：

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

### 移除事件观察者

```ts
// 移除该应用事件观察者以取消订阅事件
hiAppEvent.removeWatcher(watcher);
```
<!--RP1-->
<!--RP1End-->
