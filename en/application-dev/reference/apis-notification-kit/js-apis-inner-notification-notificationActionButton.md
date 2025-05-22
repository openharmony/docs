# NotificationActionButton

The **NotificationActionButton** module provides APIs for describing the button displayed in the notification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Attributes

**System capability**: SystemCapability.Notification.Notification

| Name     | Type                                           | Read Only| Optional| Description                     |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | No | No | Button title.                 |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)   | No | No | **WantAgent** of the button.|
| extras    | { [key: string]: any }                          | No | Yes | Extra information of the button. Not supported currently.             |
| userInput<sup>8+</sup> | [NotificationUserInput](js-apis-inner-notification-notificationUserInput.md) | No | Yes | User input object. ID entered by a subscriber.         |
