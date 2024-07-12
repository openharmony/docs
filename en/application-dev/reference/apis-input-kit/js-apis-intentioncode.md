# @ohos.multimodalInput.intentionCode (Intention Code)

The **intentionCode** module maps the original events of the keyboard to intention codes for normalized interaction. For example, if the mapped event of the space bar on the keyboard is **INTENTION_SELECT**, the intent is to select an item.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { IntentionCode } from '@kit.InputKit';
```

## IntentionCode

Enumerates intention codes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name                              | Value  |  Description       |
| -------------------------------- | ------ | --------------------------- |
| INTENTION_UNKNOWN                |  -1 | Unknown intent                 |
| INTENTION_UP                     |  1 | Up                    |
| INTENTION_DOWN                   |  2 | Down                    |
| INTENTION_LEFT                   |  3 | Left                    |
| INTENTION_RIGHT                  |  4 | Right                    |
| INTENTION_SELECT                 |  5 | Select                           |
| INTENTION_ESCAPE                 |  6 | Escape                           |
| INTENTION_BACK                   |  7 | Back                           |
| INTENTION_FORWARD                |  8 | Forward                           |
| INTENTION_MENU                   |  9 | Menu                           |
| INTENTION_PAGE_UP                |  11 | Page up                        |
| INTENTION_PAGE_DOWN              |  12 | Page down                        |
| INTENTION_ZOOM_OUT               |  13 | Zoom out                       |
| INTENTION_ZOOM_IN                |  14 | Zoom in                        |
