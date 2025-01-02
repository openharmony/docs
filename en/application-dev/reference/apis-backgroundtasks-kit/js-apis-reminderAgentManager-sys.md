# @ohos.reminderAgentManager (Agent-Powered Reminders) (System API)

The reminderAgentManager module provides APIs related to agent-powered reminders. When your application is frozen or exits, the timing and notification functions of your application will be taken over by a system service running in the background. You can use the APIs to create scheduled reminders for countdown timers, calendar events, and alarm clocks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.reminderAgentManager (Agent-Powered Reminders)](js-apis-reminderAgentManager.md).


## Modules to Import

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';
```

## ActionButtonType

Enumerates the button types.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CUSTOM<sup>10+</sup>  | 2 | Custom button.|

## ActionButton

Defines the button on the reminder displayed.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantAgent<sup>10+</sup> | [WantAgent](./js-apis-reminderAgentManager.md#wantagent) | No| Information about the ability that is displayed after the button is clicked.|
| dataShareUpdate<sup>11+</sup> | [DataShareUpdate](#datashareupdate11) | No| The application database will be updated after a click on the button.|

## DataShareUpdate<sup>11+</sup>

Defines the parameter information used to update the database.

The data provider needs to set the ID, read/write permissions, and basic information of the table to be shared under **proxyDatas** in the **module.json5** file. For details about the configuration method, see [Data Proxy](../../database/share-data-by-silent-access.md).

**System capability**: SystemCapability.Notification.ReminderAgent


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the data, which is the unique identifier for cross-application data access.|
| equalTo | Record<string, number \| string \| boolean> | Yes| Filter criteria. Currently, only equal to is supported.|
| value | [ValueBucket](../apis-arkdata/js-apis-data-valuesBucket.md#valuesbucket) | Yes| New data.|

## ReminderRequestCalendar

Defines a reminder for a calendar event.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name                        | Type                                                    | Mandatory| Description                                              |
| ---------------------------- | -------------------------------------------------------- | ---- | -------------------------------------------------- |
| rruleWantAgent<sup>12+</sup> | [WantAgent](./js-apis-reminderAgentManager.md#wantagent) | No  | Custom reminder, which specifies the ServiceExtensionAbility to start.|
