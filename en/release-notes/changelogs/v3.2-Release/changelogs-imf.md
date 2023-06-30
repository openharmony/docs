# Input Method Framework Subsystem – Input Method Framework Service Changelog


## @ohos.InputMethodSubtype Change of name, label, and id
Changed the **name**, **label**, and **id** attributes since API version 9.

**Change Impact**

Applications must be adapted to the following changes.

| Name| Before Change| After Change|
| -------- | -------- | -------- |
| label | (1) Value: ID of the input method subtype.| (1) Value: Label of the input method subtype.|
| name | (1) Description: Name of the input method subtype. (2) Value: Label of the input method subtype.| (1) Description: Bundle name of the input method; (2) Value: Bundle name of the input method.|
| id | (1) Value: Bundle name of the input method.| (1) Value: ID of the input method subtype.|

**Adaptation Guide**

Update the code to adapt to the preceding changes.
