# Interface (AutoDeviceSwitchQuery)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

AutoDeviceSwitchQuery is used to check whether a device supports automatic camera switch.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## isAutoDeviceSwitchSupported<sup>13+</sup>

isAutoDeviceSwitchSupported(): boolean

Checks whether the device supports automatic camera switch.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description         |
| ----------------------------------------------- |-------------|
| boolean               | Check result for the support of automatic camera switch. **true** if supported, **false** otherwise.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isAutoDeviceSwitchSupported(session: camera.PhotoSession): boolean {
  let isSupported = false;
  isSupported = session.isAutoDeviceSwitchSupported();
  return isSupported;
}
```
