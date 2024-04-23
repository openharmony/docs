使用 HiChecker检测问题（ArkTS/JS）

## 简介

HiChecker可以作为应用开发阶段使用的检测工具，用于检测代码运行过程中部分易忽略的问题，如应用线程出现耗时调用、应用进程中元能力资源泄露等问题。开发者可以通过日志记录或进程crash等形式查看具体问题并进行修改，提升应用的使用体验

## 基本概念

**规则常量**：HiChecker使用常量来表示已有的告警规则或者检测规则，一个常量表示一种规则，可以通过HiChecker的接口控制规则的添加和删除。

## 实现原理

1. 应用程序通过HiChecker函数接口控制规则的增删查改。

2. 子系统有耗时调用或者内存泄露时通过HiChecker通知有对应规则的事件发生，HiChecker检测条件满足时做对应的操作。

## 约束与限制

- 支持应用增加、删除不同的告警通知规则，目前支持记录流水日志（默认），应用崩溃两种规则。
- 相关检测条件满足时，支持Native回栈到关键触发点，暂不支持JS回栈。

## 接口说明

检测模式接口由HiChecker模块提供，详细API请参考[检测模式API参考](../reference/apis-performance-analysis-kit/js-apis-hichecker.md)。

| 接口名 | 描述 |
| -------- | -------- |
| hichecker.addCheckRule(rule: bigint) | 需要添加的规则 |
| hichecker.removeCheckRule(rule: bigint) | 需要删除的规则 |
| hichecker.containsCheckRule(rule: bigint) | 需要查询的规则 |

## 开发步骤

在应用启动执行页面加载后，开始分布式跟踪；完成业务之后，停止分布式跟踪。

1. 新建一个ArkTS应用工程，在“Project”窗口点击“entry &gt; src &gt; main &gt; ets &gt; entryability ”，打开工程中的“EntryAbility.ets”文件；在页面执行加载后，在自己的业务中调用HiChecker的接口，添加检测规则， 示例代码如下：

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import hilog from '@ohos.hilog';
   import window from '@ohos.window';
   import hichecker from '@ohos.hichecker';
   import image from '@ohos.multimedia.image';
   import Want from '@ohos.app.ability.Want';
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       // 添加检测规则
       hichecker.addCheckRule(hichecker.RULE_CAUTION_PRINT_LOG|hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);
       let filePath: string = this.context.cacheDir + '/test.JPG';
       const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
       const imagePackerApi = image.createImagePacker();
       let packOpts: image.PackingOption = { format:"image/jpeg", quality:98 };
       imagePackerApi.packing(imageSourceApi, packOpts);
       // 以上5行通过image子系统触发检测规则
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreateend');
     }
   
     onDestroy() {
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
     }
   
     onWindowStageCreate(windowStage: window.WindowStage) {
       // Main window is created, set main page for this ability
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
   
       windowStage.loadContent('pages/Index', (err, data) => {
         if (err.code) {
           hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
           return;
         }
         hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
       });
     }
   
     onWindowStageDestroy() {
       // Main window is destroyed, release UI related resources
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
     }
   
     onForeground() {
       // Ability has brought to foreground
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
     }
   
     onBackground() {
       // Ability has back to background
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
     }
   }
   ```
   
2. 在shell中依次执行如下命令：

   ```shell
   hdc shell
   hilog|grep RULE_THREAD_CHECK_SLOW_PROCESS
   ```

   安装hap后运行，shell窗口有如下结果说明检测成功

   ```shell
   08-05 19:04:05.037  7791  7791 I C02d0b/HICHECKER: CautionMsg:trigger:RULE_THREAD_CHECK_SLOW_PROCESS,Trigger: pid = 1705, tid = 1705
   08-05 19:04:11.851  7843  7843 I C02d0b/HICHECKER: CautionMsg:trigger:RULE_THREAD_CHECK_SLOW_PROCESS,Trigger: pid = 1747, tid = 1747
   ```
