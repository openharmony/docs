# @ohos.app.ability.ShareExtensionAbility (ExtensionAbility for Sharing)

The **ShareExtensionAbility** module, inherited from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md), provides a share service template. The ShareExtensionAbility provides a convenient way for people to share current contextual information through applications, social media accounts, and other services. For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## When to Use

The following uses text sharing as an example. A user selects a piece of text and starts the application to be shared. The application starts the sharing template based on the sharing information and displays the data based on the sharing template content.

## Modules to Import

```ts
import { ShareExtensionAbility } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | No| Yes| Context.|

## ShareExtensionAbility.onCreate

onCreate(): void

Called to initialize the service logic when a ShareExtensionAbility is being created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

See [Creating a ShareExtensionAbility](#creating-a-shareextensionability).

## ShareExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is created for this ShareExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information related to the ShareExtensionAbility, including the ability name and bundle name.|
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the ShareExtensionAbility.|

**Example**

See [Creating a ShareExtensionAbility](#creating-a-shareextensionability).

## ShareExtensionAbility.onForeground

onForeground(): void

Called when this ShareExtensionAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

See [Creating a ShareExtensionAbility](#creating-a-shareextensionability).

## ShareExtensionAbility.onBackground

onBackground(): void

Called when this ShareExtensionAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

See [Creating a ShareExtensionAbility](#creating-a-shareextensionability).

## ShareExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is destroyed for this ShareExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the ShareExtensionAbility.|

**Example**

See [Creating a ShareExtensionAbility](#creating-a-shareextensionability).

## ShareExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

Called when this ShareExtensionAbility is destroyed to clear resources.
After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Returns**

| Type                                 | Description                           |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | No return value or a Promise object that returns no result.|

**Example**

See [Creating a ShareExtensionAbility](#creating-a-shareextensionability).

## Creating a ShareExtensionAbility

To manually create a ShareExtensionAbility in the DevEco Studio project, perform the following steps:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **ShareExtAbility**.

2. In the **ShareExtAbility** directory, right-click and choose **New > ArkTS File** to create a file named **ShareExtAbility.ets**.

    ```text
    ├── ets
    │ ├── ShareExtAbility
    │ │   ├── ShareExtAbility.ets
    └
    ```

3. In the **ShareExtAbility.ets** file, import the ShareExtensionAbility module. Customize a class that inherits from **ShareExtensionAbility** and implement the lifecycle callbacks.

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
        console.info(TAG, `onForeground`);
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

4. Register the ShareExtensionAbility in the [**module.json5** file](../../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **share** and **srcEntry** to the code path of the ShareExtensionAbility component.

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
