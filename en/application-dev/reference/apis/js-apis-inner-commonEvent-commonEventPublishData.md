# CommonEventPublishData

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.CommonEvent

| Name                 | Type                | Readable| Writable| Description                        |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | Yes | No | Bundle name.                  |
| code                  | number               | Yes | No | Result code of the common event.      |
| data                  | string               | Yes | No | Custom result data of the common event.|
| subscriberPermissions | Array\<string>       | Yes | No | Permissions required for subscribers to receive the common event.            |
| isOrdered             | boolean              | Yes | No | Whether the common event is an ordered one.          |
| isSticky              | boolean              | Yes | No | Whether the common event is a sticky one. Only system applications and system services are allowed to send sticky events.|
| parameters            | {[key: string]: any} | Yes | No | Additional information about the common event.      |
