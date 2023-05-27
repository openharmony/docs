# NotificationActionButton

The **NotificationActionButton** module describes the button displayed in the notification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

| Name     | Type                                           | Read-only| Mandatory| Description                     |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | No | Yes | Button title.                 |
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md)   | No | Yes | **WantAgent** of the button.|
| extras    | { [key: string]: any }                          | No | No | Extra information of the button.             |
| userInput<sup>8+</sup> | [NotificationUserInput](js-apis-inner-notification-notificationUserInput.md) | No | No | User input object.         |
