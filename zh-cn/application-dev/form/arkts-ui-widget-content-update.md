# 使用方刷新卡片内容（仅对系统应用开放）


当使用方添加了一些周期性刷新的卡片后，由于周期性刷新的时间间隔限制，可以在使用方中提供按钮主动触发卡片的刷新。这种场景下使用方可以通过调用[requestForm](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md#requestform)接口请求卡片刷新，系统会调用卡片提供方FormExtensionAbility中的[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform)生命周期回调，在回调中，可以使用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform)接口刷新卡片内容。onUpdateForm生命周期回调参考[通过message事件刷新卡片内容](arkts-ui-widget-event-formextensionability.md)。

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry()
@Component
struct WidgetCard {
  formId: string = 'formId'; // 卡片ID

  build() {
    Button(`刷新卡片`)
      .type(ButtonType.Capsule)
      .width('50%')
      .height(50)
      .onClick(() => {
        console.info('FormAbility update form click');
        // formId需要为实际需要刷新的卡片ID
        formHost.requestForm(this.formId.toString()).then(() => {
          console.info('Succeeded in requestForming.');
        }).catch((error: BusinessError) => {
          console.error('requestForm fail, error: ' + JSON.stringify(error));
        })
      })

    ...
  }
}
```
