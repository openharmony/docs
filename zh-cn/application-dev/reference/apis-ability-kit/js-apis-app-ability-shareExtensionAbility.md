# @ohos.app.ability.ShareExtensionAbility (分享模板服务扩展能力)

ShareExtensionAbility是为开发者提供分享操作业务模板，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。ShareExtension为人们提供了一种通过应用程序、社交媒体帐户和其他服务共享当前上下文信息的便捷方式。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 场景介绍

以分享文本为例。用户选择一段文本，拉起要分享应用，此时被分享拉起的应用会根据分享信息将分享模板拉起，并将数据按分享模板内容显示。

## 导入模块

```ts
import { ShareExtensionAbility } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | 否 | 是 | 上下文。 |

## ShareExtensionAbility.onCreate

onCreate(): void

ShareExtensionAbility创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[创建ShareExtensionAbility](#创建shareextensionability)。

## ShareExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

当ShareExtensionAbility界面内容对象创建后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前ShareExtensionAbility的Want类型信息，包括ability名称、bundle名称等。 |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | ShareExtensionAbility界面内容相关信息。 |

**示例：**

参见[创建ShareExtensionAbility](#创建shareextensionability)。

## ShareExtensionAbility.onForeground

onForeground(): void

ShareExtensionAbility生命周期回调，当ShareExtensionAbility从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[创建ShareExtensionAbility](#创建shareextensionability)。

## ShareExtensionAbility.onBackground

onBackground(): void

ShareExtensionAbility生命周期回调，当ShareExtensionAbility从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[创建ShareExtensionAbility](#创建shareextensionability)。

## ShareExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

当ShareExtensionAbility界面内容对象销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | ShareExtensionAbility界面内容相关信息。 |

**示例：**

参见[创建ShareExtensionAbility](#创建shareextensionability)。

## ShareExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

ShareExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。
在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型                                  | 说明                            |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回结果或无返回结果的Promise对象。 |

**示例：**

参见[创建ShareExtensionAbility](#创建shareextensionability)。

## 创建ShareExtensionAbility

在DevEco Studio工程中手动新建一个ShareExtensionAbility，具体步骤如下：

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为ShareExtAbility。

2. 在ShareExtAbility目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为ShareExtAbility.ets。

    ```text
    ├── ets
    │ ├── ShareExtAbility
    │ │   ├── ShareExtAbility.ets
    └
    ```

3. ShareExtAbility.ets文件中，增加导入ShareExtensionAbility的依赖包，自定义类继承ShareExtensionAbility并实现生命周期回调。

  ```ts
  import { ShareExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

  const TAG: string = "[ShareExtAbility]";

  export default class ShareExtAbility extends ShareExtensionAbility {
    onCreate() {
      console.info(TAG, `onCreate`);
    }
    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      console.info(TAG, `onSessionCreate, want: ${want.abilityName}`);
      if (want.parameters) {
        let obj: Record<string, UIExtensionContentSession | object> = {
          'session': session,
          'messages': want.parameters.shareMessages
        }
        let storage: LocalStorage = new LocalStorage(obj);
        session.loadContent('pages/Index', storage);
      }
    }
    onForeground() {
      console.info(TAG, `ononForeground`);
    }
    onBackground() {
      console.info(TAG, `onBackground`);
    }
    onSessionDestroy(session: UIExtensionContentSession) {
      console.info(TAG, `onSessionDestroy`);
    }
    onDestroy() {
      console.info(TAG, `onDestroy`);
    }
  }
  ```

4. 在工程Module对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中注册ShareExtensionAbility，type标签需要设置为“share”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

   ```json
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "name": "ShareExtAbility",
           "icon": "$media:icon",
           "description": "share",
           "type": "share",
           "exported": true,
           "srcEntry": "./ets/ShareExtAbility/ShareExtAbility.ets"
         }
       ]
     }
   }
   ```