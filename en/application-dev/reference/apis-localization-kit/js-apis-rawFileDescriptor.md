# RawFileDescriptor

Provides the descriptor of the HAP where the rawfile is located.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Import a module.

```js
import { resourceManager } from '@kit.LocalizationKit'
```

## RawFileDescriptor

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name    | Type   | Read-Only  | Optional | Description          |
| ------ | ------  | ---- | ---- | ------------------ |
| fd     | number  | No   | No| Pointer to the file descriptor.|
| offset | number  | No   | No| Start offset.     |
| length | number  | No   | No| File length.      |
