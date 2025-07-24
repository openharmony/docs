# Constants

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

| Name                                   | Type     | Read-Only| Description              |
| --------------------------------------- | ----------|---| ------------------ |
| DEFAULT_VOLUME_GROUP_ID<sup>9+</sup>    | number    | Yes| Default volume group ID.<br>**System capability**: SystemCapability.Multimedia.Audio.Volume      |
| DEFAULT_INTERRUPT_GROUP_ID<sup>9+</sup> | number    | Yes| Default audio interruption group ID.<br>**System capability**: SystemCapability.Multimedia.Audio.Interrupt      |

**Example**

```ts
import { audio } from '@kit.AudioKit';

const defaultVolumeGroupId = audio.DEFAULT_VOLUME_GROUP_ID;
const defaultInterruptGroupId = audio.DEFAULT_INTERRUPT_GROUP_ID;
```
