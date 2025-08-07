# Interface (MacroQuery)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 19.

MacroQuery provides the API to check the support for macro photography.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## isMacroSupported<sup>19+</sup>

isMacroSupported(): boolean

Checks whether macro photography is supported in the current state. This API must be called after [commitConfig](arkts-apis-camera-Session.md#commitconfig11).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
|   boolean  | Check result for the support of macro photography. **true** if supported, **false** otherwise.|

**Example**

```ts
function isMacroSupported(photoSession: camera.PhotoSession): boolean {
  let isSupported: boolean = photoSession.isMacroSupported();
  return isSupported;
}
```
