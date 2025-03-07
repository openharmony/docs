# NotificationCommonDef

The **NotificationCommonDef** module provides APIs for describing the **BundleOption** information, that is, the bundle information of a specified application.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleOption

**System capability**: SystemCapability.Notification.Notification

| Name  | Type  | Read Only| Optional| Description  |
| ------ | ------ | ----| -- |  ------ |
| bundle | string | No | No| Application name.|
| uid    | number | No | Yes| UID of an application, which is obtained from [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md). The default value is **0**.|
