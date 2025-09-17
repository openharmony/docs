# Interface (Macro)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 19.

Macro inherits from [MacroQuery](arkts-apis-camera-MacroQuery.md).

It provides the API to enable macro photography.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## enableMacro<sup>19+</sup>

enableMacro(enabled: boolean): void

Enables or disables macro photography.
> **NOTE**
>
> Before calling this API, call [isMacroSupported](arkts-apis-camera-MacroQuery.md#ismacrosupported19) to check whether the current device supports macro photography.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | Yes  | Whether to enable macro photography. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                    |
|----------|--------------------------|
| 7400102  | Operation not allowed.   |
| 7400103  | Session not config.      |

**Example**

```ts
function enableMacro(photoSession: camera.PhotoSession): void {
  let isSupported: boolean = photoSession.isMacroSupported();
  if (isSupported) {
    photoSession.enableMacro(true);
  }
}
```
