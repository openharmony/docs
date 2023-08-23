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

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| label | string | Yes| No| Optional. Label of the input method subtype.|
| name | string | Yes| No| Mandatory. Bundle name of the input method.|
| id | string | Yes| No| Mandatory. ID of the input method subtype.|
| mode | string | Yes| No| Optional. Mode of the input method subtype, including **upper** (uppercase) and **lower** (lowercase).|
| locale | string | Yes| No| Mandatory. Locale of the input method subtype.|
| language | string | Yes| No| Mandatory. Language of the input method subtype.|
| icon | string | Yes| No| Optional. Icon of the input method subtype.|
| iconId | number | Yes| No| Optional. Icon ID of the input method subtype.|
| extra | object | Yes| Yes| Mandatory. Extra information of the input method subtype.|
