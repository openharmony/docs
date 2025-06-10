# 卡片使用方主动请求刷新卡片内容（仅对系统应用开放）


当使用方添加了一些周期性刷新的卡片后，由于周期性刷新的时间间隔限制，可以在使用方中提供按钮主动触发卡片的刷新。这种场景下使用方可以通过调用[requestForm](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md#requestform)接口请求卡片刷新，系统会调用卡片提供方FormExtensionAbility中的[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)生命周期回调，在回调中，可以使用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口刷新卡片内容。onUpdateForm生命周期回调参考[通过message事件刷新卡片内容](arkts-ui-widget-event-formextensionability.md)。

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
          // formId需要为实际需要刷新的卡片ID
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
