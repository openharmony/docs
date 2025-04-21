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
| bundleName | string               | No | Yes | Bundle name. This parameter is left empty by default.              |
| code       | number               | No | Yes | Common event data received by the subscriber. The value of this field is the same as that of the **code** field in [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md#commoneventpublishdata) when the publisher uses [commonEventManager.publish](./js-apis-commonEventManager.md#commoneventmanagerpublish-1) to publish a common event. The default value is **0**.          |
| data       | string               | No | Yes | Common event data received by the subscriber. The value of this field is the same as that of the **data** field in [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md#commoneventpublishdata) when the publisher uses [commonEventManager.publish](./js-apis-commonEventManager.md#commoneventmanagerpublish-1) to publish a common event.|
| parameters | {[key: string]: any} | No | Yes | Additional information about the common event received by the subscriber. The value of this field is the same as that of the **parameters** field in [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md#commoneventpublishdata) when the publisher uses [commonEventManager.publish](./js-apis-commonEventManager.md#commoneventmanagerpublish-1) to publish a common event.          |
