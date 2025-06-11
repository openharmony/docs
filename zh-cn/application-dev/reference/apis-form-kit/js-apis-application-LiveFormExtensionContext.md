# LiveFormExtensionContext

LiveFormExtensionContext是[LiveFormExtensionAbility](./js-apis-app-form-LiveFormExtensionAbility.md)的上下文，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块
```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```

## LiveFormExtensionContext

LiveFormExtensionContext提供允许访问特定于LiveFormExtensionAbility资源的能力。

### setBackgroundImage

setBackgroundImage(res: Resource): Promise&lt;void&gt;

设置互动卡片的背景图。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | ------------------------------------- |
| res | [Resource](../apis-localization-kit/js-apis-resource.md) | 是 | 需要设置的互动卡片背景图对应的资源信息，包括资源id、资源类型等。|

**返回值：**

| 类型          | 说明                               |
| ------------ | ---------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 16501010 | Failed to set the live form background image. |

**示例：**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag]LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void {
    try {
      //请开发者自行在scr/main/resources/base/media路径下添加backgroundImage图片，否则运行时会因资源缺失而报错
      this.context.setBackgroundImage($r('app.media.backgroundImage'))
        .then(() => {
          // 执行正常业务
          console.info(TAG, 'setBackgroundImage succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(TAG, `setBackgroundImage failed, code is ${err?.code}, message is ${err?.message}`);
        });
    } catch (err) {
      // 处理入参错误
      console.error(TAG, `setBackgroundImage failed, code is ${err?.code}, message is ${err?.message}`);
    }
  }
};
```