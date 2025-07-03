# LiveFormExtensionContext

**LiveFormExtensionContext**, inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md), is the context of [LiveFormExtensionAbility](./js-apis-app-form-LiveFormExtensionAbility.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import
```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```

## LiveFormExtensionContext

Provides APIs to access specific **LiveFormExtensionAbility** resources.

### setBackgroundImage

setBackgroundImage(res: Resource): Promise&lt;void&gt;

Sets the background image of an interactive widget. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| res | [Resource](../apis-localization-kit/js-apis-resource.md) | Yes| Background image resources, including the resource ID and resource type.|

**Return value**

| Type         | Description                              |
| ------------ | ---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 16501010 | Failed to set the live form background image. |

**Example**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag]LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void {
    try {
      // Add the background image to the scr/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
      this.context.setBackgroundImage($r('app.media.backgroundImage'))
        .then(() => {
          // Carry out normal service processing.
          console.info(TAG, 'setBackgroundImage succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(TAG, `setBackgroundImage failed, code is ${err?.code}, message is ${err?.message}`);
        });
    } catch (err) {
      // Handle input parameter errors.
      console.error(TAG, `setBackgroundImage failed, code is ${err?.code}, message is ${err?.message}`);
    }
  }
};
```
