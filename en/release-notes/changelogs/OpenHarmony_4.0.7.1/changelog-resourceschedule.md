# Resource Scheduler Subsystem Changelog

## cl.resourceschedule.reminderAgent.1  

The reminder agent allows you to customize buttons for system applications. Clicking a custom button will redirect you to the specified application page.

**Change Impact**

For system applications developed based on OpenHarmony 4.0.7.1 and later SDK versions, you can set custom buttons for reminders.

**Key API/Component Changes**

| Module| Class| Method/Attribute/Enum/Constant| Change Type|
|  -- | -- | -- | -- |
| reminderAgentManager | ActionButtonType  | ACTION_BUTTON_TYPE_CUSTOM = 2 | Added|
| reminderAgentManager | ActionButton  | wantAgent?: WantAgent | Added|
| reminderAgentManager | WantAgent  | uri?: string | Added|
| reminderAgentManager | ReminderRequest   | actionButton?: [ActionButton?, ActionButton?, ActionButton?] | Changed|

**Adaptation Guide**

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';

let targetReminderAgent: reminderAgentManager.ReminderRequestAlarm = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_ALARM, // The reminder type is alarm clock.
    ...
    actionButton: [
        {
            title: 'Remind later',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
        {
            title: 'Close',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: 'Custom',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CUSTOM,
            wantAgent: {
                pkgName: "com.example.myapplication",
                abilityName: "EntryAbility",
            }
        },
    ]
}
```

## cl.resourceschedule.reminderAgent.2  

The reminder agent allows you to set reminders to automatically disappear at the given time.

**Change Impact**

For system applications developed based on OpenHarmony 4.0.7.1 and later SDK versions, you can set the reminders to disappear automatically.

**Key API/Component Changes**

| Module| Class| Method/Attribute/Enum/Constant| Change Type|
|  -- | -- | -- | -- |
| reminderAgentManager | ReminderRequest | tapDismissed?: boolean | Added|
| reminderAgentManager | ReminderRequest | autoDeletedTime?: number | Added|

**Adaptation Guide**

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';

let targetReminderAgent: reminderAgentManager.ReminderRequestAlarm = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_ALARM, // The reminder type is alarm clock.
    ...
    tapDismissed: true,
    autoDeletedTime: 300,
}
```
