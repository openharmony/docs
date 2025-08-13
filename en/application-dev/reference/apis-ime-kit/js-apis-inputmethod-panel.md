# @ohos.inputMethod.Panel (Input Method Panel)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

The **inputMethod.Panel** module provides APIs for managing the attributes of the input method panel.

> **NOTE**
>
>The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { PanelInfo, PanelType, PanelFlag } from '@kit.IMEKit';
```

## PanelInfo

Defines the attributes of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | [PanelType](#paneltype) | Yes| Type of the input method panel.|
| flag | [PanelFlag](#panelflag) | No| State type of the input method panel.<br>- The default value is **FLAG_FIXED**.<br>- Currently, this parameter is used to describe the state type of the soft keyboard.|

##  PanelType

Enumerates the types of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| SOFT_KEYBOARD | 0    | Soft keyboard.|
| STATUS_BAR    | 1    | Status bar.|

##  PanelFlag

Enumerates the state types of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| FLAG_FIXED     | 0    | Fixed state type.                                            |
| FLAG_FLOATING  | 1    | Floating state type.                                            |
| FLAG_CANDIDATE | 2    | Candidate state type.<br>- When in the candidate state type, the input method panel is a window displaying candidates based on user input.<br>- The input method service does not proactively control the visibility of the candidate panel. You need to control the visibility on your own.|
