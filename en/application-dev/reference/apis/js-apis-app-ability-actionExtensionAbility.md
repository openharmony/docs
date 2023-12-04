# @ohos.app.ability.ActionExtensionAbility (ExtensionAbility for Custom Actions)

The **ActionExtensionAbility** module, inherited from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md), provides a custom action service template. An ActionExtensionAbility is used to view and process the content in a host application. For example, you can add a bookmark, translate the selected text into another language, or edit an image on the current page.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## When to Use

The following uses text translation as an example. You must create a request initiator and then an ActionExtensionAbility. The request initiator sends the text to be translated to the ActionExtensionAbility. The ActionExtensionAbility translates the text and sends the translated text to the request initiator.

## Modules to Import

```ts
import ActionExtensionAbility from '@ohos.app.ability.ActionExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | Yes| No| Context.|

## ActionExtensionAbility.onCreate

onCreate(): void

Called to initialize the service logic when an ActionExtensionAbility is being created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

## ActionExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is created for this ActionExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information related to the ActionExtensionAbility, including the ability name and bundle name.|
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the ActionExtensionAbility.|

## ActionExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is destroyed for this ActionExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the ActionExtensionAbility.|

## ActionExtensionAbility.onForeground

onForeground(): void;

Called when this ActionExtensionAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

## ActionExtensionAbility.onBackground

onBackground(): void;

Called when this ActionExtensionAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

## ActionExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;;

Called when this ActionExtensionAbility is destroyed to clear resources.
After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

## Creating an ActionExtensionAbility

To manually create an ActionExtensionAbility in the DevEco Studio project, perform the following steps:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **ActionExtAbility**.

2. In the **ActionExtAbility** directory, right-click and choose **New > TypeScript File** to create a file named **ActionExtAbility.ts**.

    ```text
    ├── ets
    │ ├── ActionExtAbility
    │ │   ├── ActionExtAbility.ts
    └
    ```

3. In the **ActionExtAbility.ts** file, import the ActionExtensionAbility module. Customize a class that inherits from ActionExtensionAbility and implement the lifecycle callbacks.

   ```ts
   import ActionExtensionAbility from '@ohos.app.ability.ActionExtensionAbility';
   const TAG: string = "[ActionExtAbility]";

   export default class ActionExtAbility extends ActionExtensionAbility {
     storage: LocalStorage;
     message: string;
     onCreate() {
       console.info(TAG, `onCreate`);
     }

     onForeground() {
       console.info(TAG, `ononForeground`);
     }

     onBackground() {
       console.info(TAG, `onBackground`);
     }

     onSessionCreate(want, session) {
       console.info(TAG, `onSessionCreate, want: ${want.abilityName}`);
       this.message = want.parameters.shareMessages;
       this.storage = new LocalStorage(
        {
          'session': session,
          'messages': this.message
        });
       session.loadContent('pages/Index', this.storage);
     }

     onSessionDestroy(session) {
       console.info(TAG, `onSessionDestroy`);
     }

     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
   ```

4. Register the ActionExtensionAbility in the [**module.json5** file](../../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **action** and **srcEntry** to the code path of the ActionExtensionAbility component.

   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "name": "ActionExtAbility",
           "icon": "$media:icon",
           "description": "action",
           "type": "action",
           "exported": true,
           "srcEntry": "./ets/ActionExtAbility/ActionExtAbility.ts"
         }
       ]
     }
   }
   ```
