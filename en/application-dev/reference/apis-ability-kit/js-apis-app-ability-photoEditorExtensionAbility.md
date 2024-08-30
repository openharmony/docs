# @ohos.app.ability.PhotoEditorExtensionAbility (Image Editing)
The PhotoEditorExtensionAbility, which inherits from the ExtensionAbility, enables your application to provide an image editing page for applications that do not have the image editing capability. After an application uses **startAbilityByType** to start a vertical domain panel with available image editing applications that have implemented the PhotoEditorExtensionAbility, the user can select one of the applications on the panel to display an image editing page.
> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the stage model.
## Modules to Import
```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';
```
## Properties
**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension
|  Name|Type  |Read Only  |Mandatory  |Description  |
| ------------ | ------------ | ------------ | ------------ | ------------ |
|  context | [PhotoEditorExtensionContext](./js-apis-app-ability-photoEditorExtensionContext.md)  | No | No | Context. |

## PhotoEditorExtensionAbility.onCreate
onCreate(): void

Called to initialize the service logic when a PhotoEditorExtensionAbility is created.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension

**Example**

```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExamplePhotoEditorAbility';

export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
  onCreate() {
    console.info(TAG, `onCreate`);
  }
}

```
## PhotoEditorExtensionAbility.onStartContentEditing
onStartContentEditing(uri: string, want: Want, session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is created for this PhotoEditorExtensionAbility. The instance can be used to read the original image and load a page.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension

**Parameters**
| Name|  Type| Mandatory | Description |
| ------------ | ------------ | ------------ | ------------ |
|  uri |  string |  Yes| [URI](../apis-core-file-kit/js-apis-file-fileuri.md) of the image to edit. The format is file://\<bundleName>/\<sandboxPath>. |
| want  | [Want](./js-apis-app-ability-want.md)  | Yes | Want information, including the ability name and bundle name. |
|  session |  [UIExtensionContentSession](./js-apis-app-ability-uiExtensionContentSession.md) | Yes |  UI content information related to the PhotoEditorExtensionAbility.|


**Example**

```ts
import { PhotoEditorExtensionAbility, Want, UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExamplePhotoEditorAbility';

export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
  onStartContentEditing(uri: string, want: Want, session: UIExtensionContentSession) {
    console.info(TAG, `onStartContentEditing want: ${JSON.stringify(want)}, uri: ${uri}`);
  }
}

```
## PhotoEditorExtensionAbility.onForeground
onForeground(): void

Called when this PhotoEditorExtensionAbility is switched from the background to the foreground.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension

**Example**

```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExamplePhotoEditorAbility';

export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
  onForeground() {
    console.info(TAG, `onForeground`);
  }
}

```
## PhotoEditorExtensionAbility.onBackground
onBackground(): void

Called when this PhotoEditorExtensionAbility is switched from the foreground to the background.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension

**Example**

```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExamplePhotoEditorAbility';

export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
  onBackground() {
    console.info(TAG, `onBackground`);
  }
}

```
## PhotoEditorExtensionAbility.onDestroy
onDestroy(): void | Promise\<void>

Called to clear resources when this PhotoEditorExtensionAbility is destroyed.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension

**Return value**
|  Type|Description  |
| ------------ | ------------ |
|  Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExamplePhotoEditorAbility';

export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
  onDestroy() {
    console.info(TAG, `onDestroy`);
  }
}

```
