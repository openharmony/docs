# @ohos.app.ability.PhotoEditorExtensionAbility(图片编辑能力)
PhotoEditorExtensionAbility继承自ExtensionAbility，开发者可通过PhotoEditorExtensionAbility实现图片编辑扩展页面。应用通过startAbilityByType拉起图片编辑类应用扩展面板后，由用户在面板上选择实现了PhotoEditorExtensionAbility的图片编辑扩展页面并拉起该页面。
> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在Stage模型下使用。
## 导入模块
```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';
```
## 属性
**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension
|  名称 |类型   |只读   |必填   |说明   |
| ------------ | ------------ | ------------ | ------------ | ------------ |
|  context | [PhotoEditorExtensionContext](./js-apis-app-ability-photoEditorExtensionContext.md)  | 否  | 否  | 上下文  |

## PhotoEditorExtensionAbility.onCreate
onCreate(): void

PhotoEditorExtensionAbility创建时回调，执行初始化业务逻辑操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**示例：**

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

当PhotoEditorExtensionAbility界面内容对象创建后调用，可以执行读取原始图片、加载页面等操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**参数：**
| 参数名 |  类型 | 必填  | 说明  |
| ------------ | ------------ | ------------ | ------------ |
|  uri |  string |  是 | 待编辑的原始图片[uri](../apis-core-file-kit/js-apis-file-fileuri.md)，格式为file://\<bundleName>/\<sandboxPath>。  |
| want  | [Want](./js-apis-app-ability-want.md)  | 是  | 当前PhotoEditorExtensionAbility的Want类型信息，包括ability名称、bundle名称等。  |
|  session |  [UIExtensionContentSession](./js-apis-app-ability-uiExtensionContentSession.md) | 是  |  PhotoEditorExtensionAbility界面内容相关信息。 |


**示例：**

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

PhotoEditorExtensionAbility生命周期回调，当PhotoEditorExtensionAbility从后台转到前台时触发。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**示例：**

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

PhotoEditorExtensionAbility生命周期回调，当PhotoEditorExtensionAbility从前台转到后台时触发。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**示例：**

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

PhotoEditorExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。 

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**返回值：**
|  类型 |说明   |
| ------------ | ------------ |
|  Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExamplePhotoEditorAbility';

export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
  onDestroy() {
    console.info(TAG, `onDestroy`);
  }
}

```