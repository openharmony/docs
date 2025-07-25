# Adding Widgets to the Home Screen

You can add ArkTS widgets of an application to the home screen

which manages widgets in a unified manner. Applications can call the [openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18) API provided by the [formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md) module to start the widget management page where you can add a widget to the home screen by touching **Add to home screen**.

## How to Develop

Implement the [openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18) method provided by the [formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md) API.

```ts
// entry/src/main/ets/pages/Index.ets

import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        // Add a button and call the openFormManager method to start the widget management page.
        Button('Start the widget management page.')
          .onClick(() => {
            const want: Want = {
              bundleName: 'com.example.formbutton',
              abilityName: 'EntryFormAbility',
              parameters: {
                'ohos.extra.param.key.form_dimension': 2,
                'ohos.extra.param.key.form_name': 'widget',
                'ohos.extra.param.key.module_name': 'entry'
              },
            };
            try {
              formProvider.openFormManager(want);
            } catch (error) {
              console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
            }
          })
          .margin({ top: 10, bottom: 10 })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
