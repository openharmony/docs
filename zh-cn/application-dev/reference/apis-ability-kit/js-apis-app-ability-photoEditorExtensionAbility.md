# @ohos.app.ability.PhotoEditorExtensionAbility(图片编辑能力)
PhotoEditorExtensionAbility为开发者提供了图片编辑的能力，继承自ExtensionAbility。应用通过startAbilityByType拉起图片编辑面板后，由用户在面板上选择PhotoEditorExtensionAbility的实现方并拉起应用。
> 说明：<br>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。<br>
> 本模块接口仅可在Stage模型下使用。
## 导入模块
```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';
```
## 属性
**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension
|  名称 |类型   |只读   |必填   |说明   |
| ------------ | ------------ | ------------ | ------------ | ------------ |
|  context | PhotoEditorExtensionContext  | 否  | 否  | 上下文  |

## PhotoEditorExtensionAbility.onCreate
onCreate(): void

PhotoEditorExtensionAbility创建是回调，执行初始化业务逻辑操作。

**模型约束：** 此接口仅可在Stage模型下使用

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

当PhotoEditorExtensionAbility界面内容对象创建后调用，可以执行读取原始图片、加载page等操作。

**模型约束：** 此接口仅可在Stage模型下使用

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**参数：**
| 参数名 |  类型 | 必填  | 说明  |
| ------------ | ------------ | ------------ | ------------ |
|  uri |  string |  是 | 待编辑的原始图片地址。  |
| want  | Want  | 是  | 当前PhotoEditorExtensionAbility的Want类型信息，包括ability名称、bundle名称等。  |
|  session |  UIExtensionContentSession | 是  |  PhotoEditorExtensionAbility界面内容相关信息。 |


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

**模型约束：** 此接口仅可在Stage模型下使用

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

**模型约束：** 此接口仅可在Stage模型下使用

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
onDestroy(): void | Promise<void>

PhotoEditorExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。 在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

**模型约束：** 此接口仅可在Stage模型下使用

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**返回值：**
|  类型 |说明   |
| ------------ | ------------ |
|  Promise<void> |  Promise对象。无返回结果的Promise对象。 |

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