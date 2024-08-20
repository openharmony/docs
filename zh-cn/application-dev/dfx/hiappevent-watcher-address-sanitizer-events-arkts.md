# 订阅踩内存事件（ArkTS）

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

以实现对写数组越界场景生成的踩内存事件订阅为例，说明开发步骤。

1. 新建Native C++工程，目录结构如下：

   ```yml
   entry:
     src:
       main:
         cpp:
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           - entryability:
               - EntryAbility.ets
           - pages:
               - Index.ets
   ```

2. 编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

3. 编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

   ```ts
   hiAppEvent.addWatcher({
     // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
     name: "watcher",
     // 开发者可以订阅感兴趣的系统事件，此处是订阅了踩内存事件
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.ADDRESS_SANITIZER]
       }
     ],
     // 开发者可以自行实现订阅系统事件回调函数，以便对订阅获取到的事件数据进行自定义处理
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
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.time=${eventInfo.params['time']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.bundle_version=${eventInfo.params['bundle_version']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.bundle_name=${eventInfo.params['bundle_name']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.pid=${eventInfo.params['pid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.uid=${eventInfo.params['uid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.type=${eventInfo.params['type']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.log_over_limit=${eventInfo.params['log_over_limit']}`);
         }
       }
     }
   });
   ```

4. 编辑“entry > src > main > cpp > types > libentry > index.d.ts”文件，完整示例代码如下：

   ```ts
   export const test: () => void;
   ```

5. 编辑“entry > src > main > cpp > napi_init.cpp”文件，该文件实现地址越界场景，并提供NAPI接口给应用层代码调用，完整示例代码如下：

   ```c++
   #include "napi/native_api.h"

   static napi_value Test(napi_env env, napi_callback_info info)
   {
       int a[10];
       // 构造数组越界写入
       a[10] = 1;
       return {};
   }

   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "test", nullptr, Test, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END

   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };

   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```

6. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，新增按钮触发踩内存事件：

   ```ts
   import testNapi from 'libentry.so'

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           Button("address-sanitizer").onClick(() => {
             testNapi.test();
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

7. 点击IDE界面中的“entry”，点击“Edit Configurations”，点击“Diagnostics”，勾选“Address Sanitizer”，保存设置。点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“address-sanitizer”，触发一次踩内存事件。应用崩溃后重新进入应用，可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=ADDRESS_SANITIZER
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=ADDRESS_SANITIZER
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.time=1713161197957
   HiAppEvent eventInfo.bundle_version=1.0.0
   HiAppEvent eventInfo.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.pid=12889
   HiAppEvent eventInfo.uid=20020140
   HiAppEvent eventInfo.type=stack-buffer-overflow
   HiAppEvent eventInfo.external_log=["/data/storage/el2/log/hiappevent/ADDRESS_SANITIZER_1713161197960_12889.log"]
   HiAppEvent eventInfo.log_over_limit=false
   ```
