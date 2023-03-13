# InputMethodCommon

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **InputMethodCommon** module provides the common attributes defined by the input method framework.

## Direction

Enumerates the directions of cursor movement.

 **System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value  | Description      |
| ------------ | ---- | ---------- |
| CURSOR_UP    | 1    | The cursor moves upward.|
| CURSOR_DOWN  | 2    | The cursor moves downward.|
| CURSOR_LEFT  | 3    | The caret moves leftward.|
| CURSOR_RIGHT | 4    | The caret moves rightward.|

## Range

Describes the range of the selected text.

 **System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name | Type  | Readable| Writable| Description                              |
| ----- | ------ | ---- | ---- | ---------------------------------- |
| start | number | Yes  | Yes  | Index of the first selected character in the text box.|
| end   | number | Yes  | Yes  | Index of the last selected character in the text box.|

## Movement

Describes the direction in which the cursor moves when the text is selected.

 **System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name     | Type                   | Readable| Writable| Description                              |
| --------- | ----------------------- | ---- | ---- | ---------------------------------- |
| direction | [Direction](#direction) | Yes  | Yes  | Direction in which the cursor moves when the text is selected.|
