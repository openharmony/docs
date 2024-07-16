# CommonEventData

Common event data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**Atomic service API**: This API can be used in atomic services since API version 11.

## Attributes

**System capability**: SystemCapability.Notification.CommonEvent

| Name      | Type                | Readable| Writable| Description                                                   |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | Yes | No | Name of the common event that is being received.                             |
| bundleName | string               | Yes | No | Bundle name. This parameter is left empty by default.                                             |
| code       | number               | Yes | No | Result code of the common event, which is used to transfer data of the int type.          |
| data       | string               | Yes | No | Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | {[key: string]: any} | Yes | No | Additional information about the common event.                                 |
