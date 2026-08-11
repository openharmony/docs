# LiveFormExtensionContext

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=62f2cf3101049cbc3c2c61a2e11dc625dab4e15c translatedAt=2026-07-31T08:25:38.109Z pushedAt=2026-07-31T09:28:46.669Z -->

LiveFormExtensionContext is the context of [LiveFormExtensionAbility](./js-apis-app-form-LiveFormExtensionAbility.md), and inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md). It provides the capability to access specific LiveFormExtensionAbility resources and supports starting an app page from an interactive widget. This is applicable to scenarios where an interactive widget needs to respond to user taps and navigate to an app page, addressing the limitation that an interactive widget cannot proactively start an app page.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

> **NOTE**
>
> - Before API version 22, import is performed through `import LiveFormExtensionContext from 'application/LiveFormExtensionContext';`. This import method is highlighted in red in DevEco Studio, but does not affect compilation and running. You can directly use LiveFormExtensionContext.
>
> - Since API version 22, import is supported through `import { common } from '@kit.AbilityKit';`, and LiveFormExtensionContext can be used through `common.LiveFormExtensionContext`.

## LiveFormExtensionContext

LiveFormExtensionContext provides the capability to access resources specific to LiveFormExtensionAbility.

### startAbilityByLiveForm

startAbilityByLiveForm(want: Want): Promise&lt;void&gt;

Starts the interactive widget provider (application) page. This API uses a promise to return the result.

This API can only be used to start the page of the interactive widget provider (application). If this API is used to start the page of another application, error code 16501011 will be reported.

This API can only be called within the click event callback and must be called directly. Delayed calls are not supported. Otherwise, the error code 16501011 will be reported.

**Use cases:**

- Navigate to the app home page or details page by tapping in the active state of an interactive widget.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| want  |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | Yes   | Information about the app page to be started. Value rule: Only explicit **Want** is supported, and the **bundleName** and **abilityName** fields must be included. For details, see [Starting an App Component with Explicit Want](../../../application-dev/application-models/ability-startup-with-explicit-want.md). |

**Return value** 

  | Type| Description   |
  | ------ | ------ |
  | Promise&lt;void&gt;  |  Promise that returns no value. | 

**Error codes**

For details about the error codes, see [Widget Error Codes](errorcode-form.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported due to limited device capabilities.                 |
| 16500050 | An IPC connection error happened.                            |
| 16500100 | Failed to obtain the configuration information.                        |
| 16501000 | An internal functional error occurred.                       |
| 16501011 | The form can not support this operation.                       |

**Example**

```ts
// MyLiveFormExtensionAbility.ets
import { LiveFormInfo, LiveFormExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession } from '@kit.AbilityKit';

export default class MyLiveFormExtensionAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    // 1. Pass LiveFormExtensionContext to the widget page component.
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('context', this.context);
    session.loadContent('pages/MyLiveFormPage', storage);
  }
};
```

```ts
// pages/MyLiveFormPage.ets
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct MyLiveFormPage {
  private storageForMyLiveFormPage: LocalStorage | undefined = undefined;
  private liveFormContext: common.LiveFormExtensionContext | undefined = undefined;

  aboutToAppear(): void {
    // 2. Obtain LiveFormExtensionContext.
    this.storageForMyLiveFormPage = this.getUIContext().getSharedLocalStorage();
    this.liveFormContext = this.storageForMyLiveFormPage?.get<common.LiveFormExtensionContext>('context');
  }

   private startAbilityByLiveForm(): void {
    try {
      // Replace the Want information with the actual one.
      this.liveFormContext?.startAbilityByLiveForm({
        bundleName: 'com.example.liveformdemo',
        abilityName: 'EntryAbility',
      })
        .then(() => {
          console.info('startAbilityByLiveForm succeed');
        })
        .catch((err: BusinessError) => {
          console.error(`startAbilityByLiveForm failed, code is ${err?.code}, message is ${err?.message}`);
        });
    } catch (err) {
      console.error(`startAbilityByLiveForm failed, code is ${err?.code}, message is ${err?.message}`);
    }
  }

  build() {
    // Replace the page with the actual one.
    Stack() {
      Column()
        .width('50%')
        .height('50%')
        .backgroundColor('#2875F5')
    }
    .width('100%')
    .height('100%')
    .onClick(() => {
      // 3. Use the API in the click event callback.
      console.info('MyLiveFormPage click to start ability');
      if (!this.liveFormContext) {
        console.info('MyLiveFormPage liveFormContext is empty');
        return;
      }
      this.startAbilityByLiveForm();
    });
  }
}
```