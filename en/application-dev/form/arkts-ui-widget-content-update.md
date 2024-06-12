# Updating Widget Content by Widget Host (for System Applications Only)


Widgets that are updated periodically are subject to the scheduled time or interval settings. To offer more flexible updates, the widget host can provide a button to proactively trigger a widget update. Specifically, the widget host calls the [requestForm](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md#requestform) API to request a widget update. The system then calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback in the FormExtensionAbility of the widget provider. In the callback, the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) API can be used to update the widget content. For details about the **onUpdateForm** lifecycle callback, see [Updating Widget Content Through the message Event](arkts-ui-widget-event-formextensionability.md).

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let storage = new LocalStorage();
const TAG: string = 'Index';
const DOMAIN_NUMBER: number = 0xFF00;

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
          hilog.info(DOMAIN_NUMBER, TAG, `FormAbility update form click, formId: ${this.formId}`);
          // formId is the ID of the widget to be updated.
          formHost.requestForm(this.formId.toString()).then(() => {
            hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in requestForming.');
          }).catch((error: BusinessError) => {
            hilog.error(DOMAIN_NUMBER, TAG, `requestForm fail, error: ${JSON.stringify(error)}`);
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
