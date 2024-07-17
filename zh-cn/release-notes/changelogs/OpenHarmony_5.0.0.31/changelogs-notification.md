# 通知子系统Changelog

## cl.notificationManager.1 应用请求通知使能接口废弃

**访问级别**

公开接口

**废弃原因**

    1.恶意应用如果在后台调用弹窗，可能存在安全风险。

    2.使用该接口调用弹窗时，弹窗无法跟随应用窗口，UX体验不佳。

**废弃影响**

notificationManager模块废弃接口。

**起始 API Level**

9

**废弃发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**废弃的接口/组件**

|接口声明|替代接口|
|-------|-------|
|requestEnableNotification(callback: AsyncCallback\<void\>): void|requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void\>): void|
|requestEnableNotification(): Promise\<void\>|requestEnableNotification(context: UIAbilityContext): Promise\<void\>|


**适配指导**

需要使用新的替代接口，替代接口为带context入参的请求通知使能接口requestEnableNotification。

废弃前代码示例：

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 请求通知弹窗，不跟随应用窗口
notificationManager.requestEnableNotification().then(() => {
    console.info("requestEnableNotification success");
}).catch((err: BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```
废弃后代码示例：

```ts
import { notificationManager } from '@kit.NotificationKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';

let context = getContext(this) as common.UIAbilityContext;
// 请求通知弹窗，传入UIAbilityContext，弹窗跟随应用窗口
notificationManager.requestEnableNotification(context).then(() => {
    console.info("requestEnableNotification success");
}).catch((err: BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```
