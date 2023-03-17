# CommonEventData

**System capability**: SystemCapability.Notification.CommonEvent

| Name      | Type                | Readable| Writable| Description                                                   |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | Yes | No | Name of the common event that is being received.                             |
| bundleName | string               | Yes | No | Bundle name.                                             |
| code       | number               | Yes | No | Result code of the common event, which is used to transfer data of the int type.          |
| data       | string               | Yes | No | Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | {[key: string]: any} | Yes | No | Additional information about the common event.                                 |
