# @ohos.InputMethodSubtype (Input Method Subtype)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

The **InputMethodSubtype** module provides APIs for managing the attributes of input method subtypes. The input method subtype allows the input method to switch to a specific mode or language, for example, the Chinese or English keyboard.

> **NOTE**
>
>The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
```

## InputMethodSubtype

Defines the attributes of input method subtypes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| label | string | Yes| Yes| Optional. Label of the input method subtype.|
| labelId<sup>10+</sup> | number | Yes| Yes| Optional. Label ID of the input method subtype.|
| name | string | Yes| No| Mandatory. Bundle name of the application to which the input method subtype belongs.|
| id | string | Yes| No| Mandatory. ID of the input method subtype.|
| mode | 'upper' \| 'lower' | Yes| Yes| Optional. Mode of the input method subtype, including **upper** (uppercase) and **lower** (lowercase).|
| locale | string | Yes| No| Mandatory. Locale of the input method subtype.|
| language | string | Yes| No| Mandatory. Language of the input method subtype.|
| icon | string | Yes| Yes| Optional. Icon of the input method subtype. It can be obtained by using **iconId**. This parameter is reserved.|
| iconId | number | Yes| Yes| Optional. Icon ID of the input method subtype.|
| extra | object | No| Yes| Mandatory. Extra information of the input method subtype.<br>**NOTE**<br>- This parameter is optional since API version 10.<br>- This parameter is reserved and currently has no specific meaning.|
