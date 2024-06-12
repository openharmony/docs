# @ohos.customization.customConfig (定制配置)

本模块接口为应用提供定制配置的获取能力，如渠道号等。

>  **说明：**
>
>  本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { customConfig } from '@kit.BasicServicesKit';
```

## customConfig.getChannelId

getChannelId(): string

根据应用的BundleName获取渠道号。

**系统能力**：SystemCapability.Customization.CustomConfig

**返回值：**

|  类型  |  说明  |
| ------ | ----- |
| string | 渠道号 |

**示例：**

  ```ts
    let channelId: string = customConfig.getChannelId();
    console.log('app channelId is ' + channelId);
  ```
