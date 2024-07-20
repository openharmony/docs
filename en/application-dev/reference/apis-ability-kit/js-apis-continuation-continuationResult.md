# ContinuationResult

The ContinuationResult module describes the device information returned by the continuation management entry.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ContinuationResult

Describes the device information returned by the continuation management entry after [on](js-apis-continuation-continuationManager.md#continuationmanagerondeviceselected9) is called.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | No| Yes| Device ID.|
| type | string | No| Yes| Device type.|
| name | string | No| Yes| Device name.|
