# ContinuationExtraParams

The ContinuationExtraParams module provides the filter parameters required by the device selection module in the continuation management entry. These filter parameters can be used as an input parameter of [startContinuationDeviceManager](js-apis-continuation-continuationManager.md#continuationmanagerstartcontinuationdevicemanager9-1).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ContinuationExtraParams

Describes the extra parameters required by the device selection module in the continuation management entry.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceType | Array\<string> | No| No| Device type.|
| targetBundle | string | No| No| Name of the target bundle.|
| description | string | No| No| Device filtering description.|
| filter | any | No| No| Device filtering parameter.|
| continuationMode | [ContinuationMode](js-apis-continuation-continuationManager.md#continuationmode) | No| No| Continuation mode.|
| authInfo | Record<string, Object> | No| No| Authentication information.|
