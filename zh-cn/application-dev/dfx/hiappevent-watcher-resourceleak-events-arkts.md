# 订阅资源泄漏事件（ArkTS）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 接口说明

本文介绍如何使用HiAppEvent提供的ArkTS接口订阅资源泄漏事件。接口的具体使用说明（参数使用限制、具体取值范围等）请参考[@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。


### 自定义参数设置接口描述

| 接口名 | 描述 |
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt; | 此方法用于设置事件的自定义参数，在资源泄漏检测事件中，仅支持设置JS内存泄漏事件的参数。<br />**说明**：从API version 20开始，支持该接口。 |

### 自定义配置设置接口描述

| 接口名 | 描述 |
| -------- | -------- |
| setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void> | 此方法用于设置事件的自定义配置。在资源泄漏检测事件中，仅支持设置js内存泄漏事件的配置。<br />**说明**：从API version 20开始，支持该接口。 |

### 接口描述

| 接口名 | 描述 |
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者以订阅应用事件。 |
| removeWatcher(watcher: Watcher): void | 移除应用事件观察者，取消对应用事件的订阅。 |
## 开发步骤

以订阅发生内存泄漏场景生成的资源泄漏事件为例，说明开发步骤。

### 步骤一：新建工程

1. 在DevEco Studio中新建工程，选择“Empty Ability”，编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   import { deviceInfo, BusinessError } from '@kit.BasicServicesKit';
   ```

2. 编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

   ```ts
   // 完成参数键值对赋值
   let params: Record<string, hiAppEvent.ParamType> = {
     "test_data": 100,
   };
   // 设置资源泄漏事件的自定义参数
   hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.RESOURCE_OVERLIMIT).then(() => {
     hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
   });
   // 完成自定义配置键值对赋值
   let configParams: Record<string, hiAppEvent.ParamType> = {
     "js_heap_logtype": "event", // 仅获取事件
   }
   // 设置资源泄漏事件的自定义配置
   hiAppEvent.setEventConfig(hiAppEvent.event.RESOURCE_OVERLIMIT, configParams);
   if (deviceInfo.sdkApiVersion >= 24) {  // API Version 24及以后版本，支持设置页面切换日志
     // 配置页面切换日志
     let switchLogPolicy : hiAppEvent.EventPolicy = {
       "resourceOverlimitPolicy": {
         "pageSwitchLogEnable": true
       }
     };
     // 开发者可以设置资源泄漏日志配置参数
     hiAppEvent.configEventPolicy(switchLogPolicy).then(() => {
       hilog.info(0x0000, 'testTag', `HiAppEvent success to config event policy.`);
     }).catch((err: BusinessError) => {
       hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
     });
   }

   hiAppEvent.addWatcher({
     // 自定义观察者名称，系统会使用名称来标识不同的观察者
     name: "watcher",
     // 订阅感兴趣的系统事件，此处是订阅了资源泄漏事件
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.RESOURCE_OVERLIMIT]
       }
     ],
     // 自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         // 根据事件集合中的事件名称区分不同的系统事件
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // 获取到资源泄漏事件发生时内存信息
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo=${JSON.stringify(eventInfo)}`);
           // 开发者可以获取到资源泄漏事件的页面切换日志
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.page_switch_log=${JSON.stringify(eventInfo.params['page_switch_log'])}`);
         }
       }
     }
   });
   ```

### 步骤二：订阅资源泄漏事件

1. 编辑工程中的“entry > src > main > ets > pages > Index.ets”文件，添加按钮并在其onClick函数构造资源泄漏场景，以触发资源泄漏事件。

   此处需要使用[hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12)设置内存限制，造成内存泄漏，同步在“开发者选项”中打开“系统资源泄漏日志”（开关状态变更后需重启设备）。

   <!--RP1-->
   资源泄漏问题定位可参考[内存泄漏分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-snapshot)。
   <!--RP1End-->

   接口示例代码如下：

   <!-- @[PssLeakEventTS_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   Button('pss leak')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('80%')
     .height('5%')
     .onClick(() => {
       // 设置一个简单的资源泄漏场景
       hilog.info(0x0000, 'testTag', 'click pss leak button');
       testNapi.leakMB(3072);
     })
   Button('js leak')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('80%')
     .height('5%')
     .onClick(() => {
       for (let i = 0; i < 10000; i++) {
         this.leakedArray.push(new Array(500000).fill(1));
       }
     })
   ```

2. 添加 pss leak 相关内容：

   编辑“napi_init.cpp”文件：
   
   - 头文件加入：

   <!-- @[Pss_Leak_Header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   #include <iostream>
   #include <fstream>
   #include <sstream>
   #include <thread>
   ```

   - 定义 pss leak 相关方法：

   <!-- @[Pss_Leak](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   // 读 /proc/self/smaps_rollup 中的 PSS 字段，统计当前进程的 PSS (单位 KB)
   static int GetCurrentProcessPss()
   {
       std::ifstream smapsFile("/proc/self/smaps_rollup");
       if (!smapsFile.is_open()) {
           std::cerr << "Failed to open /proc/self/smaps_rollup" << std::endl;
           return 0;
       }
       std::string line;
       int totalPss = 0;
       while (std::getline(smapsFile, line)) {
           if (line.find("Pss:") == 0) {
               std::istringstream iss(line);
               std::string label;
               int pss;
               iss >> label >>pss;
               totalPss += pss;
           }
       }
       smapsFile.close();
       std::cout << "Current pss: " << totalPss << " KB\r";
       std::cout.flush();
       return totalPss;
   }
   
   // 读取当前进程的 FD 数量
   static int GetCurrentFd()
   {
       std::ifstream fdFile("/proc/self/fd_num");
       if (!fdFile.is_open()) {
           std::cerr << "Failed to open /proc/self/fd_num" << std::endl;
           return 0;
       }
       std::string line;
       int totalPss = 0;
       std::getline(fdFile, line);
       fdFile.close();
       std::cout << "Current fd: " << line << std::endl;
       std::cout.flush();
       return std::stoi(line);
   }
   
   // 申请 size 字节内存并写入数据（用 'a' 填充），制造 native 内存增长
   static bool InjectNativeLeakMallocWithSize(int size, char *p)
   {
       const size_t maxSafe = 1073741824;
       if (size < 0 || size > maxSafe) {
           printf("InjectNativeLeakMallocWithSize invalid size\n");
           return false;
       }
       p = (char *) malloc(size + 1);
       if (!p) {
           printf("InjectNativeLeakMallocWithSize malloc failed\n");
           return false;
       }
       void* err = memset(p, 'a', size);
       if (err == nullptr) {
           printf("InjectNativeLeakMallocWithSize memset failed\n");
           return false;
       }
       return true;
   }
   
   // 循环申请/释放内存，使进程 PSS 持续接近 target
   static void InjectNativeLeakMallocUntil(int target)
   {
       constexpr int leakSizePerTime = 5000000;
       std::vector<char *> mems;
       int curPss = GetCurrentProcessPss();
       while (curPss != 0) {
           char *p = nullptr;
           if (curPss < target) {
               if (!InjectNativeLeakMallocWithSize(leakSizePerTime, p)) {
                   printf("InjectNativeLeakMallocUntil target = %d failed\n", target);
               }
               mems.push_back(p);
               std::cout << "Inject size: " << leakSizePerTime << ", currentSize: " << mems.size() << std::endl;
           } else {
               if (mems.size() > 0) {
                   char *dst = mems[0];
                   mems.erase(mems.begin());
                   free(dst);
               }
               std::cout << "Free size: " << leakSizePerTime << ", currentSize: " << mems.size() << std::endl;
           }
           curPss = GetCurrentProcessPss();
       }
       std::cout << std::endl;
       printf("InjectNativeLeakMallocUntil target = %d success\n", target);
   }
   
   // 启动后台执行的 InjectNativeLeakMallocUntil 线程，使 native 内存占用接近 leakSize
   static void StartNativeLeak(int leakSize)
   {
       std::cout << "Start inject malloc until" << leakSize << "KB" << std::endl;
       std::thread t1(InjectNativeLeakMallocUntil, leakSize);
       t1.detach();
       std::cout << "Inject finished." << std::endl;
   }
   
   // N-API 导出方法
   static napi_value LeakMB(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1];
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       if (argc < 1) {
           napi_throw_type_error(env, nullptr, "Expected 1 argument");
           return nullptr;
       }
       double x = 0;
       if (napi_get_value_double(env, args[0], &x) != napi_ok) {
           napi_throw_type_error(env, nullptr, "Argument must be a number");
           return nullptr;
       }
       const size_t kilobyte = 1024;
       StartNativeLeak(static_cast<size_t>(x * kilobyte));
       napi_value rtn;
       napi_get_undefined(env, &rtn);
       return rtn;
   }
   ```

   - 初始化：

   <!-- @[Pss_Leak_Init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           // ...
           { "leakMB", nullptr, LeakMB, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   编辑“Index.d.ts”文件：

   - 添加类型声明：

   <!-- @[Pss_Leak_Index.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->
   
   ``` TypeScript
   export const leakMB: (size: number) => void;
   ```

3. 点击DevEco Studio界面中的运行按钮，运行应用工程，点击“pss leak”按钮，等待15~30分钟，系统会上报pss内存泄漏事件。

   同一个应用，24小时内至多上报一次资源泄漏事件，如果短时间内要二次上报，需要重启设备。

4. pss内存泄漏事件上报后，系统会回调应用的onReceive函数，可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication", "app_running_unique_id":"26457812872126536953", "bundle_version":"1.0.0","memory":{"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936},"pid":20731,"resource_type":"pss_memory","time":1502348798106,"uid":20010044,"external_log": ["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log", "/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"], "log_over_limit": false}}
   HiAppEvent eventInfo.params.page_switch_log="[\"/data/storage/el2/log/page_switch/snapshot/page_switch-com.example.myapplication-1-1-20260427162423841.log\"]"
   ```

   如上，eventInfo中包含资源泄漏事件的[params字段](hiappevent-watcher-resourceleak-events.md#params字段说明)，可以根据eventInfo中的resource_type字段来判断当前的泄漏类型。

5. 提前在“开发者选项”中开启“系统资源泄漏日志”开关（开启或关闭开关均需重启设备）。点击 DevEco Studio 窗口中的运行按钮，运行应用工程。点击“js leak”按钮，等待 3 到 5 秒，应用会闪退。重新打开应用后，系统将上报JS内存泄漏事件。

   同一个应用，24小时内至多上报一次JS内存泄漏，如果短时间内要二次上报，需要重启设备。

6. JS内存泄漏事件上报后，系统会回调应用的onReceive函数，在该函数中可在Log窗口查看系统事件数据的处理日志。

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication", "app_running_unique_id":"45354125624752145258", "bundle_version":"1.0.0","external_log":[],"log_over_limit":true,"memory":{"limit_size":0,"live_object_size":0},"pid":14941,"resource_type":"js_heap","test_data":100,"time":1752564700511,"uid":20020181}}
   HiAppEvent eventInfo.params.page_switch_log="[\"/data/storage/el2/log/page_switch/snapshot/page_switch-com.example.myapplication-1-1-20260427162423841.log\"]"
   ```

   如上，eventInfo中的“test_data”字段即步骤一中设置的键值对的内容。

## nolog版本订阅js_heap快照

请应用在收到该订阅事件后，首先从事件的external_log字段中获取堆快照文件存储路径，并将其尽快搬移或上传云，然后再删除原堆快照文件，以避免因应用沙箱路径目录剩余存储空间不足（最大2GB）导致下次堆快照文件无法生成。

订阅后生成的.log日志文件需要将后缀名修改为.rawheap文件，再通过[translator工具](../tools/rawheap-translator.md)转换为.heapsnapshot文件，通过DevEco Studio或浏览器打开展示，详情见[离线导入内存快照](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388)。

API version 14后，开发者可以将日志文件后缀名修改为.rawheap后，将其导入DevEco Studio并展示，详情见[离线导入内存快照](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388)。

提供两种方法，任选其一即可。

### 在AppScope/app.json5文件中配置如下环境变量

```text
"appEnvironments": [
  {
    "name": "DFX_RESOURCE_OVERLIMIT_OPTIONS",
    "value": "oomdump:enable"
  }
]
```

**nolog版本虚拟机堆快照生成规格限制**

堆快照文件大小约为0.4至1.2GB（zip压缩后约为50至100MB）。由于体积较大，系统会对堆快照的生成次数进行管控，具体规格如下：

- 整机：每周生成js堆快照的次数为5次，若整机配额用完，则所有应用都无法继续生成堆快照；
- 应用：每周仅有1次生成js堆快照的机会，自应用触发oomdump功能后的7天内，无法再次触发；
- 如果整机剩余存储空间不足30GB，则不会触发oomdump功能。

  开发者在调试期间，可通过将系统时间调整至7天后并重启设备的方式重置应用触发oomdump的次数，以便快速完成功能适配与验证。

> **注意：**
>
> json5配置文件中的value字段内容格式支持键值对集合“key1:value1;key2:value2;...”。目前系统仅支持配置如上键值对的应用，在nolog版本使能oomdump功能。

### 调用setEventConfig并传入以下参数

```ts
let configParams: Record<string, hiAppEvent.ParamType> = {
  "js_heap_logtype": "event_rawheap",
};

hiAppEvent.setEventConfig(hiAppEvent.event.RESOURCE_OVERLIMIT, configParams);
```

setEventConfig方法生成堆快照的数量**不**受到**nolog版本虚拟机堆快照生成规格限制**的约束。
