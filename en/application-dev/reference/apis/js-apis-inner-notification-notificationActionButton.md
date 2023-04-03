# NotificationActionButton

The **NotificationActionButton** module describes the button displayed in the notification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

| Name     | Type                                           | Readable| Writable| Description                     |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | Yes | Yes | Button title.                 |
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md)   | Yes | Yes | **WantAgent** of the button.|
| extras    | { [key: string]: any }                          | Yes | Yes | Extra information of the button.             |
| userInput<sup>8+</sup> | [NotificationUserInput](js-apis-inner-notification-notificationUserInput.md) | Yes | Yes | User input object.         |
