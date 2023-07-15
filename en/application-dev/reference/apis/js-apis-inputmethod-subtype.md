# @ohos.InputMethodSubtype (Input Method Subtype)

The **InputMethodSubtype** module provides APIs for managing the attributes of input method subtypes. Different attribute settings result in different subtypes.

> **NOTE**
>
>The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import InputMethodSubtype from '@ohos.InputMethodSubtype';
```

## Attributes

 

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- | -------- |
| label | string | Yes| No| No| Label of the input method subtype.|
| labelId<sup>10+</sup> | string | Yes| No| No| Label ID of the input method subtype.|
| name | string | Yes| No| Yes| Bundle name of the input method.|
| id | string | Yes| No| Yes| ID of the input method subtype.|
| mode | string | Yes| No| No| Mode of the input method subtype, including **upper** (uppercase) and **lower** (lowercase).|
| locale | string | Yes| No| Yes| Locale of the input method subtype.|
| language | string | Yes| No| Yes| Language of the input method subtype.|
| icon | string | Yes| No| No| Icon of the input method subtype.|
| iconId | number | Yes| No| No| Icon ID of the input method subtype.|
| extra | object | Yes| Yes| No| Extra information of the input method subtype.<br>**NOTE**<br>This parameter is optional since API version 10.|
