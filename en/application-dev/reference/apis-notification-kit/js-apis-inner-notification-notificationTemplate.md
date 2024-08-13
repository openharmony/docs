# NotificationTemplate

The **NotificationTemplate** module describes the notification template.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Attributes

**System capability**: SystemCapability.Notification.Notification

| Name | Type                  | Read Only | Optional | Description      |
| ---- | ---------------------- | ---- | ----|----------- |
| name | string                 | No | No  | Template name. Currently, only **downloadTemplate** is supported.|
| data | Record<string, Object> | No | No  | Template data.<br> - **title**: title of the file. This parameter is mandatory, and the value is of the string type.<br> - **fileName**: name of the file to be downloaded. This parameter is mandatory, and the value is of the string type.<br> - **progressValue**: download progress. The value is a number. |
