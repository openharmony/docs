# 订阅应用查杀事件（ArkTS）

## 应用查杀事件规格说明

请参考[应用查杀事件介绍](./hiappevent-watcher-app-killed-events.md)。

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiAppEvent](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md)。

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

为确保开发阶段顺利接收事件回调，建议采用以下方案：创建新的Native C++工程，在ArkTs代码中实现订阅，搭配C++代码的故障注入代码构造故障以触发应用查杀事件。

1. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

   ```ts
   hiAppEvent.addWatcher({
     // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
     name: "watcher",
     // 开发者可以订阅感兴趣的系统事件，此处是订阅了应用查杀事件
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.APP_KILLED]
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
           // 开发者可以获取到应用查杀事件发生的时间戳
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
           // 开发者可以获取到应用的前后台状态
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
           // 开发者可以获取到应用查杀事件发生的原因
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.reason=${eventInfo.params['reason']}`);
         }
       }
     }
   });
   ```

3. 以下为故障注入功能，需要使用C++代码实现，编辑"napi_init.cpp"，新增以下代码：

   ```C++
   #include <thread>
   
   static void NativeLeak()
   {
       constexpr int leak_size_per_time = 500000;
       while (true) {
           char *p = (char *)malloc(leak_size_per_time + 1);
           if (!p) {
               break;
           }
           memset(p, 'a', leak_size_per_time);
           std::this_thread::sleep_for(std::chrono::milliseconds(10));
       }
   }
   
   static napi_value Leak(napi_env env, napi_callback_info info) {
   	std::thread t1(NativeLeak);
   	t1.detach();
       return {};
   }
   ```

4. 编辑"napi_init.cpp"文件，将Leak注册为ArkTS接口：

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "leak", nullptr, Leak, nullptr, nullptr, nullptr, napi_default, nullptr }, // 新增这行
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

5. 编辑"index.d.ts"文件，定义ArkTS接口：

   ```ts
   export const leak: () => void;
   ```

6. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，在build下增加OnClick功能，并调用Leak接口的示例代码：

   ```ts
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   
   const DOMAIN = 0x0000;
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Start To Leak';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize($r('app.float.page_text_font_size'))
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               if (this.message != 'Leaking') {
                 this.message = 'Leaking';
                 hilog.info(DOMAIN, 'testTag', 'Start leaking');
                 testNapi.leak();
               }
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

7. 点击DevEco Studio界面中的运行按钮，运行应用工程，点击屏幕中间的“Start To Leak”按钮，等待2-3分钟，待触发RssThresholdKiller查杀。

8. 应用被查杀后，重新打开应用，会触发查杀事件上报，系统会回调应用的onReceive函数，可以在Log窗口看到对系统事件数据的处理日志。

   应用查杀事件采样栈示例：

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_KILLED
   HiAppEvent eventInfo.params.time=1717597063727
   HiAppEvent eventInfo.params.reason="RssThresholdKiller"
   HiAppEvent eventInfo.params.foreground=true
   ```
