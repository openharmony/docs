# 使用HiRetrieval进行应用灰度采集（ArkTS）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @ljy_love_code-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 简介

<!--RP1-->
应用灰度采集功能通过云端平台（OS开发者参考[HiRetrieval云端功能说明](hiretrieval-cloud-server-guidelines.md)自行提供适配）<!--RP1End-->圈选设备，精准采集故障日志上报云端，帮助开发者定位线上故障，适用于需要获取线上故障详细信息的场景。当前应用灰度采集功能支持的故障类型和对应的故障日志如下：
- 资源泄漏类
  - FD泄漏：句柄泄漏日志、句柄栈日志。
  - GPU泄漏：内存采样日志、内存栈日志。
  - ArkTS OOM泄漏：ArkTS虚拟机内存快照日志。
  - RSS泄漏：smaps日志、内存栈日志、ArkTS虚拟机内存快照日志、Kotlin语言内存快照日志。

开发者在云端新建任务时，可以选择上述故障中的任一。在任务激活期间，被圈选的设备发生了对应故障，则会自动采集对应的日志并上传到云端。

> **注意：**
>
> 当前暂不支持多实例应用，若在多实例应用中调用[hiRetrieval.init()](../reference/apis-performance-analysis-kit/js-apis-hiretrieval.md#hiretrievalinit)，会抛出错误码36000002，详细处理步骤请参考应用灰度错误码[36000002](../reference/apis-performance-analysis-kit/errorcode-hiviewdfx-hiretrieval.md#36000002)。

## 工作原理

### 故障感知

应用灰度采集功能对发生故障的感知主要依赖HiAppEvent的事件订阅机制。

在向HiAppEvent进行故障订阅（即调用[addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher)接口）时，使用的Watcher名称为HiRetrievalWatcher，请勿在自定义的功能中使用此名称订阅事件，以避免出现冲突。

### 故障日志采集

主要依赖[HiDebug](../reference/apis-performance-analysis-kit/js-apis-hidebug.md)模块提供的故障采集接口，大部分日志的采集都在应用进程内进行。

## 应用灰度采集开发指导

1. 导入所需的依赖模块，以EntryAbility.ets为例。 

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiRetrieval } from '@kit.PerformanceAnalysisKit';
   ```

2. 在onCreate函数中调用初始化接口，初始化应用灰度采集功能。

3. 再在onWindowStageCreate函数中，配置HiRetrievalConfig，调用participate方法参与应用灰度活动。最后调用run接口使能应用灰度采集的完整功能。

   <!-- @[hiretrieval_sample_code](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiRetrieval/entry/src/main/ets/entryability/EntryAbility.ets) -->
   
   ``` TypeScript
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       try {
         this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
       } catch (err) {
         hilog.error(DOMAIN, 'testTag', 'Failed to set colorMode. Cause: %{public}s', JSON.stringify(err));
       }
       // 初始化应用灰度采集特性
       try {
         hiRetrieval.init();
       } catch (err) {
         hilog.error(DOMAIN, 'testTag', 'hiretrieval error: %{public}s', JSON.stringify(err));
       }
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onCreate');
     }
   
     onDestroy(): void {
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onDestroy');
     }
   
     onWindowStageCreate(windowStage: window.WindowStage): void {
       // Main window is created, set main page for this ability
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
   
       windowStage.loadContent('pages/Index', (err) => {
         if (err.code) {
           hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
           return;
         }
         hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
       });
   
       try {
         // 参与应用灰度采集特性
         let cfg: hiRetrieval.HiRetrievalConfig = {
           userType: "student",
           deviceType: "Phone",
           deviceModel: "M70",
         };
         hiRetrieval.participate(cfg);
         // 执行应用报告灰度采集任务
         hiRetrieval.run();
       } catch (err) {
         hilog.error(DOMAIN, 'testTag', 'hiretrieval error: %{public}s', JSON.stringify(err));
       }
     }
   
     onWindowStageDestroy(): void {
       // Main window is destroyed, release UI related resources
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
     }
   
     onForeground(): void {
       // Ability has brought to foreground
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');
     }
   
     onBackground(): void {
       // Ability has back to background
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
     }
   }
   ```

4. 完成上述步骤后，应用灰度采集模块将自动接收云端平台所下发的灰度任务，并执行对应的故障日志采集和上传功能。应用开发者无需再编写额外代码。采集的故障日志将上传到云端，开发者可以在云端平台获取，以定位故障。
