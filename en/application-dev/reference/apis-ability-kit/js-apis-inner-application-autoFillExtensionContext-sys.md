# AutoFillExtensionContext (System API)

The **AutoFillExtensionContext** module, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), provides the context environment for the AutoFillExtensionAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model. 
> The APIs provided by this module are system APIs.

## Usage

Before using the **AutoFillExtensionContext** module, you must define a child class that inherits from **AutoFillExtensionAbility**.

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onCreate() {
    let AutoFillExtensionContext = this.context;
  }
}
```

## AutoFillExtensionContext.reloadInModal<sup>13+</sup>

reloadInModal(customData: CustomData): Promise\<void>

Starts a modal page.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name    | Type                                                     | Mandatory| Description                        |
| ---------- | --------------------------------------------------------- | ---- | ---------------------------- |
| customData | [CustomData](js-apis-inner-application-customData-sys.md) | Yes  | Custom information for starting the modal page.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Not System App. Interface caller is not a system app.        |
| 401      | If the input parameter is not valid parameter.               |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |

**Example**

The autofill service is triggered when a user touches the account and password text box, and an account selection page is displayed in the **onFillRequest** lifecycle of the [AutoFillExtensionAbility](js-apis-app-ability-autoFillExtensionAbility-sys.md).

When an account is selected, **reloadInModal** is called to trigger the autofill service again, and a modal page is started in the** onFillRequest** lifecycle of the AutoFillExtensionAbility.

```ts
// AutoFillAbility.ts
import { AutoFillExtensionAbility, autoFillManager, UIExtensionContentSession } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class AutoFillAbility extends AutoFillExtensionAbility {
  // ...
  onFillRequest(session: UIExtensionContentSession,
                request: autoFillManager.FillRequest,
                callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    try {
      let storage_fill: LocalStorage = new LocalStorage(
        {
          'session': session,
          'message': "AutoFill Page",
          'fillCallback': callback,
          'viewData': request.viewData,
          'autoFillExtensionContext': this.context,
          'customData': request.customData
        });
      if (request.customData == undefined) {
        // Load the autofill processing page.
        session.loadContent('pages/AccountPage', storage_fill);
      } else {
        // Start a modal page.
        session.loadContent('pages/ReloadInModal', storage_fill);
      }
    } catch (err) {
      hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed to load content');
    }
  }
}
```

When the user selects an account on the account selection page, the **reloadInModal** API is called.

```ts
// AccountPage.ets
import { autoFillManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storage: LocalStorage = LocalStorage.getShared();
let viewData: autoFillManager.ViewData | undefined = storage.get<autoFillManager.ViewData>('viewData');
let context: common.AutoFillExtensionContext | undefined = storage.get<common.AutoFillExtensionContext>('autoFillExtensionContext');

@Entry
@Component
struct AccountPage {
  build() {
    Row() {
      Column() {
        List({ space: 10, initialIndex: 0 }) {
          ListItem() {
            Text('HelloWorld789456')
              .width('100%')
              .height(40)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(5)
          }
          .onClick(() => {
            if (viewData != undefined) {
              if (context != undefined) {
                context.reloadInModal({ data: { viewData: 20, text: 'HelloWorld789456' } }).then(() => {
                  console.info('reloadInModal successfully.')
                }).catch((err: BusinessError) => {
                  console.error('reloadInModal failed.')
                })
              }
            }
          })
        }
        // ...
      }
      .width('100%')
      .shadow(ShadowStyle.OUTER_FLOATING_SM)
    }
    .height('100%')
    .shadow(ShadowStyle.OUTER_FLOATING_SM)
  }
}
```
