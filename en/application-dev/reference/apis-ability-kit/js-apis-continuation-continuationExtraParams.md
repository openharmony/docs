# ContinuationExtraParams

The ContinuationExtraParams module provides the filter parameters required by the device selection module in the continuation management entry. These filter parameters can be used as an input parameter of [startContinuationDeviceManager](js-apis-continuation-continuationManager.md#continuationmanagerstartcontinuationdevicemanager9-1).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ContinuationExtraParams

Describes the extra parameters required by the device selection module in the continuation management entry.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceType | Array\<string> | No| Yes| Device type.|
| targetBundle | string | No| Yes| Name of the target bundle.|
| description | string | No| Yes| Device filtering description.|
| filter | any | No| Yes| Device filtering parameter.|
| continuationMode | [continuationManager.ContinuationMode](js-apis-continuation-continuationManager.md#continuationmode) | No| Yes| Continuation mode.|
| authInfo | Record<string, Object> | No| Yes| Authentication information.|
