# CommonEventData

Common event data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

| Name      | Type                | Read Only| Optional| Description                                                   |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | No | No | Name of the common event that is being received.                             |
| bundleName | string               | No | Yes | Bundle name. This parameter is left empty by default.                                             |
| code       | number               | No | Yes | Result code of the common event, which is used to transfer data of the int type.          |
| data       | string               | No | Yes | Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | {[key: string]: any} | No | Yes | Additional information about the common event.                                 |
