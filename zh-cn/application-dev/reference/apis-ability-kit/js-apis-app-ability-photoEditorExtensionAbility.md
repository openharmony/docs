# @ohos.app.ability.PhotoEditorExtensionAbility (支持图片编辑能力的ExtensionAbility组件)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @liusu23-->
<!--Designer: @xukeke-->
<!--Tester: @lusq-->
<!--Adviser: @huipeizi-->

PhotoEditorExtensionAbility继承自[ExtensionAbility](js-apis-app-ability-extensionAbility.md)，开发者可通过PhotoEditorExtensionAbility实现图片编辑扩展页面。应用通过[startAbilityByType](js-apis-inner-application-uiAbilityContext.md#startability)拉起图片编辑类应用扩展面板后，由用户在面板上选择实现了PhotoEditorExtensionAbility的图片编辑扩展页面并拉起该页面。

> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在Stage模型下使用。

## 实现效果

下图为通过PhotoEditorExtensionAbility实现的图片编辑扩展页面示意图，页面的布局与功能可以根据实际需要开发。

![Targetapp_PhotoEditorExtensionAbility](figures/photo-editor-demo.png)

## 导入模块

```ts
import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';
```

## PhotoEditorExtensionAbility

### 属性

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

|  名称 |类型   |只读   |可选   |说明   |
| ------------ | ------------ | ------------ | ------------ | ------------ |
|  context | [PhotoEditorExtensionContext](./js-apis-app-ability-photoEditorExtensionContext.md)  | 否  | 否  | PhotoEditorExtensionAbility的上下文，提供保存图片能力。  |

### onCreate

onCreate(): void

当PhotoEditorExtensionAbility创建时，系统会触发该回调，开发者可以在该回调内执行初始化业务逻辑操作。

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

### onStartContentEditing

onStartContentEditing(uri: string, want: Want, session: UIExtensionContentSession): void

当实现PhotoEditorExtensionAbility的图片编辑扩展界面内容对象创建时，系统会触发该回调，开发者可以在该回调内执行读取原始图片、加载页面等操作。

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

### onForeground

onForeground(): void

当PhotoEditorExtensionAbility从后台转到前台时，系统会触发该回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.AbilityCore

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

### onBackground

onBackground(): void

当PhotoEditorExtensionAbility从前台转到后台时，系统会触发该回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.AbilityCore

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

### onDestroy

onDestroy(): void | Promise\<void>

当PhotoEditorExtensionAbility被销毁时，系统会触发该回调。开发者可以在该生命周期中执行资源清理等相关操作。使用同步回调或Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.AppExtension.PhotoEditorExtension

**返回值：**
|  类型 |说明   |
| ------------ | ------------ |
|  void \| Promise\<void> |  无返回结果或者无返回结果的Promise对象。 |

**示例：**

- 同步回调示例如下：
  ```ts
  import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] ExamplePhotoEditorAbility';

  export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
    onDestroy() {
      console.info(TAG, `onDestroy`);
      // 调用同步函数...
    }
  }

  ```
- Promise异步回调示例如下：

  ```ts
  import { PhotoEditorExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] ExamplePhotoEditorAbility';

  export default class ExamplePhotoEditorAbility extends PhotoEditorExtensionAbility {
    async onDestroy() {
      console.info(TAG, `onDestroy`);
      // 调用异步函数...
    }
  }

  ```