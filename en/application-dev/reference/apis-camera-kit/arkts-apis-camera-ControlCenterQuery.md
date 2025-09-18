# Interface (ControlCenterQuery)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 20.

ControlCenterQuery is used to check whether the camera controller is supported.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## isControlCenterSupported<sup>20+</sup>

isControlCenterSupported(): boolean

Checks whether the camera controller is supported.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type   |Description|
|---------|----|
| boolean | Check result for the support of the camera controller. **true** if supported, **false** otherwise.|

**Example**

```ts
function isControlCenterSupported(videoSession: camera.VideoSession): boolean {
    let isSupported: boolean = videoSession.isControlCenterSupported();
    return isSupported;
}
```

## getSupportedEffectTypes<sup>20+</sup>

getSupportedEffectTypes(): Array\<ControlCenterEffectType\>

Obtains the effect types supported by the camera controller.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type| Description|
|-----|-----|
| Array<[ControlCenterEffectType](arkts-apis-camera-e.md#controlcentereffecttype20)> | Array of effect types supported.|

**Example**

```ts
function getSupportedEffectTypes(videoSession: camera.VideoSession): Array<camera.ControlCenterEffectType> {
    let effectTypes: Array<camera.ControlCenterEffectType> = [];
    effectTypes = videoSession.getSupportedEffectTypes();
    return effectTypes;
}
```
