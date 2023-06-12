# 资源调度子系统ChangeLog


## cl.resourceschedule.reminderAgent.1  

提醒代理支持系统应用设置自定义按钮，并且自定义按钮可跳转指定应用界面。

**变更影响**

基于OpenHarmony4.0.7.1及之后的SDK版本开发的系统应用，可设置提醒自定义按钮。

**关键接口/组件变更**

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|  -- | -- | -- | -- |
| reminderAgentManager | ActionButtonType  | ACTION_BUTTON_TYPE_CUSTOM = 2 | 新增 |
| reminderAgentManager | ActionButton  | wantAgent?: WantAgent | 新增 |
| reminderAgentManager | WantAgent  | uri?: string | 新增 |
| reminderAgentManager | ReminderRequest   | actionButton?: [ActionButton?, ActionButton?, ActionButton?] | 变更 |

**适配指导**<br>

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';

let targetReminderAgent: reminderAgentManager.ReminderRequestAlarm = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_ALARM, // 提醒类型为闹钟类型
    ...
    actionButton: [
        {
            title: '稍后提醒',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
        {
            title: '关闭',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: '自定义',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CUSTOM,
            wantAgent: {
                pkgName: "com.example.myapplication",
                abilityName: "EntryAbility",
            }
        },
    ]
}
```
