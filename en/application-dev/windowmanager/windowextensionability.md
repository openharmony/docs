# WindowExtensionAbility (for System Applications Only)


[WindowExtensionAbility](../reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md) is a type of ExtensionAbility component that allows only a system application to be embedded in and displayed over another application.


The WindowExtensionAbility component must be used together with the [UIExtensionComponent](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md) to process services of the started application. WindowExtensionAbility is run in connection mode. A system application must use the UIExtensionComponent to start the WindowExtensionAbility component.

Each ExtensionAbility has its own context. For WindowExtensionAbility,
the context is [WindowExtensionContext](../reference/apis-arkui/js-apis-inner-application-windowExtensionContext-sys.md). In this document, the started WindowExtensionAbility is called the provider, and the UIExtensionComponent that starts the WindowExtensionAbility is called the client.

> **NOTE**
>
> This document involves the use of system APIs. You must use the full SDK for development. <!--Del-->For details, see [Guide to Switching to Full SDK](../faqs/full-sdk-switch-guide.md).<!--DelEnd-->


## Setting an Embedded UIAbility

The **WindowExtensionAbility** class provides **onConnect()**, **onDisconnect()**, and **onWindowReady()** lifecycle callbacks, which can be overridden.

- The **onWindowReady()** callback is invoked when a window is created for the UIAbility.

- The **onConnect()** callback is invoked when the UIExtensionComponent corresponding to the window connects to the UIAbility.

- The **onDisconnect()** callback is invoked when the UIExtensionComponent disconnects from the UIAbility.


**How to Develop**

To implement an embedded application, manually create a WindowExtensionAbility in DevEco Studio as follows:

1. In the **ets** directory of the **Module** project, right-click and choose **New > Directory** to create a directory named **WindowExtAbility**.

2. Right-click the **WindowExtAbility** directory, and choose **New > TypeScript File** to create a file named **WindowExtAbility.ts**.

3. Open the **WindowExtAbility.ts** file and import the dependency package of **WindowExtensionAbility**. Customize a class that inherits from **WindowExtensionAbility** and implement the **onWindowReady()**, **onConnect()**, and **onDisconnect()** lifecycle callbacks.

   ```ts
    import { WindowExtensionAbility, window } from '@kit.ArkUI';
    import { Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class WindowExtAbility extends WindowExtensionAbility {
        onWindowReady(window: window.Window) {
            window.setUIContent('WindowExtAbility/pages/index1',(err:BusinessError) => {
              let pro = window.getWindowProperties();
              console.info(`WindowExtension pro: ${JSON.stringify(pro)}`);
              window.showWindow();
            });
        }

        onConnect(want: Want) {
            console.info('JSWindowExtension onConnect ' + want.abilityName);
        }

        onDisconnect(want: Want) {
            console.info('JSWindowExtension onDisconnect ' + want.abilityName);
        }
    }
   ```

4. Register the WindowExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) corresponding to the **Module** project. Set **type** to **"window"** and **srcEntry** to the code path of the ExtensionAbility component.

   ```json
   {
     "module": {
       "extensionAbilities": [
            {
                "name": "WindowExtAbility",
                "srcEntry": "./ets/WindowExtAbility/WindowExtAbility.ts",
                "icon": "$media:icon",
                "description": "WindowExtension",
                "type": "window",
                "exported": true,
            }
        ],
     }
   }
   ```


## Starting an Embedded UIAbility

System applications can load the created WindowExtensionAbility through the UIExtensionComponent.

**How to Develop**

1. To connect to an embedded application, add the UIExtensionComponent to the corresponding pages in the DevEco Studio project.

2. Set **bundleName** and **abilityName** in the UIExtensionComponent.

3. Set the width and height. The sample code is as follows:

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        UIExtensionComponent({
          abilityName: "WindowExtAbility",
          bundleName: "com.example.WindowExtAbility"})
          .width(500)
          .height(500)
      }
      .width('100%')
    }
    .height('100%')
    .backgroundColor(0x64BB5c)
  }
}
```

