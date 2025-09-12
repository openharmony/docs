# Active Update of ArkTS Widgets

This section provides the development guidelines for active update. For details about the update process, see [Active Update](./arkts-ui-widget-interaction-overview.md#active-update).

## Active Update by Widget Provider

The widget provider can call [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) to actively update the widget. It is recommended that this API be used with the widget lifecycle callbacks [onFormEvent](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent), [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform), and [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform).

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();

@Entry(storage)
@Component
struct Index {
  @StorageLink('formId') formId: string = '';
  @StorageLink('formData') formData: Object | string = '';

  build() {
    Column() {
      Column() {
        //...
        Button() {
          //...
        }
        .onClick(() => {
          console.info(`click to check updateForm, formId: ${this.formId}`);
          const formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(this.formData);
          // formId is the ID of the widget to be updated.
          formProvider.updateForm(this.formId, formInfo).then(() => {
            console.info('updateForm success.');
          }).catch((error: BusinessError) => {
            console.error(`updateForm fail, code: ${error?.code}, message: ${error?.message}`);
          })
        })
        .margin(5)
      }
      //...
    }
    //...
  }
}
```
<!--Del-->

## Active Update by Widget Host (for System Applications Only)

Due to the time limit of interval-based and time-specific updates, the widget host can call [requestForm](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md#requestform) to request the Widget Manager to actively update the widget. The Widget Manager calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) lifecycle callback in the FormExtensionAbility of the widget provider. In the callback, the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API can be called to update the widget content.

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();

@Entry(storage)
@Component
struct Index {
  @StorageLink('formId') formId: number = 0;

  build() {
    Column() {
      Column() {
        //...
        Button() {
          //...
        }
        .onClick(() => {
          console.info(`click to check requestForm, formId: ${this.formId}`);
          // formId is the ID of the widget to be updated.
          formHost.requestForm(this.formId.toString()).then(() => {
            console.info('requestForm success.');
          }).catch((error: BusinessError) => {
            console.error(`requestForm fail, code: ${error?.code}, message: ${error?.message}`);
          })
        })
        .margin(5)
      }
      //...
    }
    //...
  }
}
```
<!--DelEnd-->
