# CommonEventPublishData

The **CommonEventPublishData** module provides APIs for defining common event content and attributes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> If there is no restriction, any application can subscribe to common events and read related information. In this case, sensitive information should not be carried in common events. The **subscriberPermissions** and **bundleName** parameters of this module can be used to restrict the receiving scope of common events.

## Attributes

**System capability**: SystemCapability.Notification.CommonEvent

| Name                 | Type                | Read Only| Optional| Description                        |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | No | Yes | Bundle name of the subscriber that can receive the common event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| code                  | number               | No | Yes | Result code of the common event. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| data                  | string               | No | Yes | Custom result data of the common event. The data size cannot exceed 64 KB.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| subscriberPermissions | Array\<string>       | No | Yes | Permissions required for subscribers to receive the common event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.            |
| isOrdered             | boolean              | No | Yes | Whether the common event is an ordered one.          |
| isSticky              | boolean              | No | Yes | Whether the common event is a sticky one. Only system applications and system services are allowed to send sticky events.<br>**Required Permissions**: [ohos.permission.COMMONEVENT_STICKY](../../security/AccessToken/permissions-for-all.md#ohospermissioncommonevent_sticky)|
| parameters            | {[key: string]: any} | No | Yes | Additional information about the common event.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
