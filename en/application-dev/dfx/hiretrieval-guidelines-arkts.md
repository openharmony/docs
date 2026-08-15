# Using HiRetrieval for App Gray-Scale Data Collection (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @ljy_love_code-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=64258e0e6b719d3b41cdb2b292d7e24160e5581f translatedAt=2026-08-15T01:48:04.229Z pushedAt=2026-08-15T07:21:44.897Z -->

## Overview

<!--RP1-->

The app gray-scale collection feature uses a cloud platform (OS developers can refer to [HiRetrieval Cloud-Side Capabilities](hiretrieval-cloud-server-guidelines.md) to implement their own cloud-side integration)<!--RP1End--> to select devices for targeted fault log collection and upload the collected logs to the cloud. This feature helps you diagnose issues occurring in production environments. The following fault types and corresponding fault logs are currently supported:

- Resource leaks

  - FD leak: File descriptor leak logs and file descriptor stack logs

  - GPU leak: Memory sampling logs and memory stack logs

  - ArkTS OOM leak: ArkTS virtual machine memory snapshot logs

  - RSS leak: **smaps** logs, memory stack logs, ArkTS virtual machine memory snapshot logs, and Kotlin memory snapshot logs

When creating a task on the cloud platform, developers can choose any of the preceding fault types. During the task's active period, if a selected device encounters the specified fault, the corresponding logs are collected automatically and uploaded to the cloud.

> **NOTE**
>
> Multi-instance apps are not currently supported. If [hiRetrieval.init()](../reference/apis-performance-analysis-kit/js-apis-hiretrieval.md#hiretrievalinit) is called in a multi-instance app, error code 36000002 is thrown. For detailed handling steps, see the app gray-scale error code [36000002](../reference/apis-performance-analysis-kit/errorcode-hiviewdfx-hiretrieval.md#36000002).

## Working Principles

### Fault Detection

App gray-scale data collection relies on the HiAppEvent event subscription mechanism to detect faults.

When subscribing to faults with HiAppEvent (by calling [addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher)), the watcher name used is **HiRetrievalWatcher**. Do not use this name for event subscription in custom features to avoid conflicts.

### Fault Log Collection

Fault log collection mainly relies on the fault collection APIs provided by the [HiDebug](../reference/apis-performance-analysis-kit/js-apis-hidebug.md) module. Most logs are collected within the app process.

## How to Develop

1. Import the required modules. The following example uses **EntryAbility.ets**. 

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiRetrieval } from '@kit.PerformanceAnalysisKit';
   ```

2. Call the initialization API in the **onCreate** function to initialize the app gray-scale collection feature.

3. In the **onWindowStageCreate** function, configure **HiRetrievalConfig** and call the **participate** method to participate in the app gray-scale activity. Then, call the **run** API to enable the complete app gray-scale collection functionality.

   <!-- @[hiretrieval_sample_code](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiRetrieval/entry/src/main/ets/entryability/EntryAbility.ets) -->

   ``` TypeScript
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       try {
         this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
       } catch (err) {
         hilog.error(DOMAIN, 'testTag', 'Failed to set colorMode. Cause: %{public}s', JSON.stringify(err));
       }
       // Initialize the app gray-scale collection feature.
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
         // Participate in the app gray-scale collection feature.
         let cfg: hiRetrieval.HiRetrievalConfig = {
           userType: "student",
           deviceType: "Phone",
           deviceModel: "M70",
         };
         hiRetrieval.participate(cfg);
         // Execute the app grayscale collection task.
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

4. After the preceding steps are completed, the app gray-scale data collection module automatically receives gray-scale tasks delivered by the cloud platform and performs the corresponding fault log collection and upload. No additional code is required. The collected fault logs are uploaded to the cloud, where developers can access them to diagnose issues.