# 全局资源调度子系统Changelog

## cl.backgroundtasks.1 reminderAgentManager.publishReminder 权限管控

**访问级别**

公开接口。

**变更原因**

由于应用存在滥用后台代理提醒能力，利用该能力发送广告、营销类延时提醒，影响用户体验；因此针对此问题，后台代理提醒增加管控机制，未通过管控的应用无法使用后台代理提醒能力。

**变更影响**

该变更为不兼容变更。

变更前：应用使用后台代理提醒创建延时提醒，调用接口成功，返回提醒 id。

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  // 变更前，接口返回成功，reminderId > 0，提醒发布成功
});
```

变更后：应用使用后台代理提醒创建延时提醒，调用接口失败，返回错误码 1700002。

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  // 变更后，接口返回失败，errcode 为 1700002，发布提醒失败
  if (err.code == 1700002) {
      // 受管控，无法使用代理提醒
  }
});
```

**起始 API Level**

9

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

**适配指导**

方案一：

开发者可以使用日历 API，创建延时类提醒，详见[Calendar Kit开发指南](../../../application-dev/calendarmanager/calendarmanager-event-developer.md)。

方案二：

开发者若需要使用后台代理提醒能力，发送延时类提醒，需要提供如下信息，申请方式详见[代理提醒开发指南](../../../application-dev/task-management/agent-powered-reminder.md)。

申请权限名称：后台代理提醒

应用名称：详见配置文件(module.json5)中 label 字段对应的值。

应用包名：详见配置文件(app.json)中 bundleName 字段对应的值。

使用场景：提供申请理由/用途/尽可能附上图片，及使用代理提醒的必要性。
