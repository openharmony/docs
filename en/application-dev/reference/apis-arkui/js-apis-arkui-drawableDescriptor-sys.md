# @ohos.arkui.drawableDescriptor (DrawableDescriptor) (System API)

The **DrawableDescriptor** module provides APIs for obtaining **pixelMap** objects, including the foreground, background, mask, and layered icons.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device, but not in DevEco Studio Previewer.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.arkui.drawableDescriptor (DrawableDescriptor)](js-apis-arkui-drawableDescriptor.md).

## Modules to Import

```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@kit.ArkUI';
```

## DrawableDescriptor

### constructor

constructor()

Creates a **DrawableDescriptor** or **LayeredDrawableDescriptor** object. The [getDrawableDescriptor](../apis-localization-kit/js-apis-resource-manager.md#getdrawabledescriptor10) or [getDrawableDescriptorByName](../apis-localization-kit/js-apis-resource-manager.md#getdrawabledescriptorbyname10) API is required for object construction.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
