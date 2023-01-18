# ContinuationExtraParams

The **ContinuationExtraParams** module provides the filter parameters required by the device selection module in the continuation management entry. These filter parameters can be used as an input parameter of [startContinuationDeviceManager](js-apis-continuation-continuationManager.md#continuationmanagerstartcontinuationdevicemanager9).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ContinuationExtraParams

Describes the extra parameters required by the device selection module in the continuation management entry.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceType | Array\<string> | Yes| Yes| Device type.|
| targetBundle | string | Yes| Yes| Name of the target bundle.|
| description | string | Yes| Yes| Device filtering description.|
| filter | any | Yes| Yes| Device filtering parameter.|
| continuationMode | [ContinuationMode](js-apis-continuation-continuationManager.md#continuationmode) | Yes| Yes| Continuation mode.|
| authInfo | { [key: string]: any } | Yes| Yes| Authentication information.|
