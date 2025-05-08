# 订阅崩溃事件（ArkTS）

## 接口描述

本文主要介绍如何使用HiAppEvent提供的ArkTs接口订阅应用崩溃事件，接口的详细使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

> **说明：**
>
> 使用ArkTS接口订阅崩溃事件，包含JsError和NativeCrash两种崩溃类型。

### 自定义参数设置接口描述

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt; | 事件自定义参数设置方法。 |

### 订阅接口描述

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 接口使用示例

### 添加事件观察者

以实现对用户点击按钮触发崩溃场景生成的崩溃事件订阅为例，说明开发步骤。

1. 新建一个ArkTS应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中设置事件的[自定义参数](#自定义参数设置接口描述)和[崩溃日志配置参数](hiappevent-watcher-crash-events.md#崩溃日志配置参数设置介绍)，示例代码如下：

   ```ts
    // 开发者完成参数键值对赋值
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // 开发者可以设置崩溃事件的自定义参数
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_CRASH).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set svent param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });

    // 构建配置项
    let configParams: Record<string, hiAppEvent.ParamType> = {
      "extend_pc_lr_printing": true, // 使能扩展打印pc和lr寄存器附近的内存值
      "log_file_cutoff_sz_bytes": 102400, // 截断崩溃日志到100KB
      "simplify_vma_printing": true, // 使能精简打印maps
    };

    // 开发者可以设置崩溃日志配置参数
    hiAppEvent.setEventConfig(hiAppEvent.event.APP_CRASH, configParams).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set svent config`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   ```

3. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

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

4. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，添加按钮并在其onClick函数构造崩溃场景，以触发崩溃事件，示例代码如下：

   ```ts
    Button("appCrash").onClick(()=>{
      // 在按钮点击函数中构造一个crash场景，触发应用崩溃事件
      let result: object = JSON.parse("");
    })
   ```

5. 点击DevEco Studio界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“appCrash”，触发一次崩溃事件。崩溃事件发生后，系统会根据崩溃类型（JsError或NativeCrash）生成不同类型的崩溃日志，然后再进行回调。

JsError通过进程内采集故障信息的方式通常触发回调迅速，而NativeCrash采取进程外采集故障信息，平均耗时约2秒，具体耗时受业务线程数量、进程间通信耗时影响。开发者可以订阅崩溃事件，故障信息采集完成后会异步上报，不会阻塞当前业务。

### 验证观察者是否订阅到崩溃事件

#### 应用未主动捕获崩溃异常场景

若应用未主动捕获崩溃异常，则系统处理崩溃后应用退出，应用下次启动后HiAppEvent将崩溃事件上报给应用已注册的监听，完成回调。

#### 应用主动捕获崩溃异常场景

若应用主动捕获崩溃异常，崩溃事件会在应用退出前回调，如下两种场景：

场景1：异常处理中未主动退出，应用发生崩溃后将不会退出。

例如采用[errorManger.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)方法捕获JsError崩溃；应用主动注册NativeCrash崩溃信号处理函数未主动退出。

场景2：异常处理耗时太久，应用退出时机延后。

在开发调试阶段HiAppEvent上报事件完成回调后，可以在DevEco Studio HiLog窗口看到订阅到的崩溃事件内容：

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

32位系统崩溃日志中打印如下内容，说明崩溃日志配置参数设置成功：

``` text
...
Build info:xxx
Enabled app log configs:
Extend pc lr printing:true
Log cut off size:102400B
Simplify maps printing:true
Timestamp:xxx
...
Memory Near Register: <-  故障现场寄存器的地址（地址必须在有效内存中）附近内存值，括号表示寄存器里地址的所属内存
...
lr(/system/lib/ld-musl-arm.so.1): <- 打印256字节长度lr寄存器地址附近的内存值
    f7998dd4 e0824000
    f7998dd8 e3510000
    f7998ddc 0a000003
    f7998de0 e8910003
    f7998de4 e1a02004
    f7998de8 eb0030ec
    f7998dec ea000000
    f7998df0 e3a00000
    f7998df4 e3500000
    f7998df8 11a04000
    f7998dfc e1a00004
    f7998e00 e8bd8c10
    f7998e04 fff98074
    f7998e08 fff978ee
    f7998e0c e92d4c80
    f7998e10 e28db008
    f7998e14 e3a070f8
    f7998e18 e1a01000
    f7998e1c ef000000
    f7998e20 e3a07001
    f7998e24 e1a00001
    f7998e28 ef000000
    f7998e2c eafffffc
    f7998e30 e92d4800
    f7998e34 e1a0b00d
    f7998e38 ebffffff
    f7998e3c e92d4890
    f7998e40 e28db008
    f7998e44 e24dd020
    f7998e48 e3a00006
    f7998e4c eb012ae8
    f7998e50 e59f10b0
    f7998e54 e3a00000
    f7998e58 e59fc0ac
    f7998e5c e3a070af
    f7998e60 e08f1001
    f7998e64 e3a02000
    f7998e68 e08fc00c
    f7998e6c e3a03008
    f7998e70 ef000000
    f7998e74 e3a04000
    f7998e78 e1a0000c
    f7998e7c eb018f61
    f7998e80 e28d1008
    f7998e84 f2c00050
    f7998e88 e3a070ae
    f7998e8c e3a02000
    f7998e90 e1a00001
    f7998e94 e3a03008
    f7998e98 f4400acd
    f7998e9c e5804000
    f7998ea0 e3a00006
    f7998ea4 ef000000
    f7998ea8 e3a070ee
    f7998eac e3a01006
    f7998eb0 ee1d0f70
    f7998eb4 e3a02000
    f7998eb8 e3a03008
    f7998ebc e51000b0
    f7998ec0 ef000000
    f7998ec4 e58d4004
    f7998ec8 e1a0100d
    f7998ecc e3a00020
    f7998ed0 e3a070af
pc(/system/lib/ld-musl-arm.so.1): <- 打印256字节长度pc寄存器地址附近的内存值
    f79e3a14 e1a0200d
    f79e3a18 e3a070af
    f79e3a1c e3a03008
    f79e3a20 ef000000
    f79e3a24 e3a07014
    f79e3a28 e34f5fff
    f79e3a2c ef000000
    f79e3a30 e3700a01
    f79e3a34 9a000003
    f79e3a38 e2606000
    f79e3a3c ebfed4bb
    f79e3a40 e5806000
    f79e3a44 e3e00000
    f79e3a48 ee1d1f70
    f79e3a4c e3a07f43
    f79e3a50 e1a02004
    f79e3a54 e51110b0
    f79e3a58 ef000000
    f79e3a5c e1a04000
    f79e3a60 e1500005
    f79e3a64 9a000003
    f79e3a68 e2644000
    f79e3a6c ebfed4af
    f79e3a70 e5804000
    f79e3a74 e3e04000
    f79e3a78 e3a00002
    f79e3a7c e1a0100d
    f79e3a80 e3a070af
    f79e3a84 e3a02000
    f79e3a88 e3a03008
    f79e3a8c ef000000
    f79e3a90 e1a00004
    f79e3a94 e24bd010
    f79e3a98 e8bd88f0
    f79e3a9c fff71854
    f79e3aa0 e92d48f0
    f79e3aa4 e28db010
    f79e3aa8 e24dd020
    f79e3aac e5914010
    f79e3ab0 e1a0c002
    f79e3ab4 e5916000
    f79e3ab8 e5913014
    f79e3abc e2942102
    f79e3ac0 e5915004
    f79e3ac4 e2a33000
    f79e3ac8 e2962102
    f79e3acc e2b52000
    f79e3ad0 03530000
    f79e3ad4 0a000003
    f79e3ad8 ebfed494
    f79e3adc e3a0105f
    f79e3ae0 e5801000
    f79e3ae4 ea00001e
    f79e3ae8 e2812008
    f79e3aec e2811018
    f79e3af0 e58d4008
    f79e3af4 e35c0000
    f79e3af8 e5922000
    f79e3afc e3a07068
    f79e3b00 e5911000
    f79e3b04 e58d2004
    f79e3b08 e28d2010
    f79e3b0c e58d100c
    f79e3b10 e1a0100d
...
Maps:                     <- simplify_vma_printing设置为true时与设置为false对比，打印Maps行数减少很多
ba0000-ba9000 r--p 00000000 /data/test/test_signalhandler
ba9000-bd8000 r-xp 00008000 /data/test/test_signalhandler
bd8000-bdb000 r--p 00036000 /data/test/test_signalhandler
bdb000-bdc000 rw-p 00038000 /data/test/test_signalhandler
f7480000-f74e9000 r--p 00000000 /system/lib/libc++.so
f74e9000-f758b000 r-xp 00068000 /system/lib/libc++.so
f758b000-f7591000 r--p 00109000 /system/lib/libc++.so
f7591000-f7592000 rw-p 0010e000 /system/lib/libc++.so
f7592000-f7598000 rw-p 00000000 [anon:libc++.so.bss]
f75c0000-f75c3000 r--p 00000000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f75c3000-f75d1000 r-xp 00002000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f75d1000-f75d2000 r--p 0000f000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f75d2000-f75d3000 rw-p 0000f000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f769b000-f769e000 rw-p 00000000 [anon:native_heap:brk]
f76d3000-f76d4000 rw-p 00000000 [anon:native_heap:brk]
f78d8000-f78e7000 rw-p 00000000 [anon:native_heap:brk]
f78ff000-f7900000 r-xp 00000000 [vdso]
f7900000-f795a000 r--p 00000000 /system/lib/ld-musl-arm.so.1
f795a000-f7a1d000 r-xp 00059000 /system/lib/ld-musl-arm.so.1
f7a1d000-f7a1e000 r--p 0011b000 /system/lib/ld-musl-arm.so.1
f7a1e000-f7a20000 rw-p 0011b000 /system/lib/ld-musl-arm.so.1
f7a20000-f7a30000 rw-p 00000000 [anon:ld-musl-arm.so.1.bss]
ffa53000-ffa74000 rw-p 00000000 [stack]
OpenFiles:
...
[truncated]  <- 日志截断的标志符，如果有打印说明日志被截断了
```

### 移除并销毁事件观察者

  ```ts
  // 移除该应用事件观察者以取消订阅事件
  hiAppEvent.removeWatcher(watcher);
  ```
<!--RP1-->
<!--RP1End-->