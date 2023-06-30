# CommonEventSubscribeInfo

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.CommonEvent

| Name               | Type          | Readable| Writable| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string> | Yes | No | Name of the common event to publish.                                        |
| publisherPermission | string         | Yes | No | Permissions required for publishers to publish the common event.                                            |
| publisherDeviceId   | string         | Yes | No | Device ID. The value must be the ID of a device on the same network.            |
| userId              | number         | Yes | No | User ID. The value must be an existing user ID in the system. If this parameter is not specified, the default value, which is the ID of the current user, will be used. |
| priority            | number         | Yes | No | Subscriber priority. The value ranges from –100 to +1000.                    |
