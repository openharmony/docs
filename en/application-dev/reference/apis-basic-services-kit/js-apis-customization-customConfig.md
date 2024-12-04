# @ohos.customization.customConfig (Custom Configurations)

This module provides APIs for applications to obtain custom configurations, such as channel IDs.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { customConfig } from '@kit.BasicServicesKit';
```

## customConfig.getChannelId

getChannelId(): string

Obtains the channel ID based on the bundle name of an application.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.Customization.CustomConfig

**Return value**

|  Type |  Description |
| ------ | ----- |
| string | Channel ID|

**Example**

  ```ts
    let channelId: string = customConfig.getChannelId();
    console.log('app channelId is ' + channelId);
  ```
