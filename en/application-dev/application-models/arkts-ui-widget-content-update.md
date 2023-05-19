# Updating Widget Content by Widget Host (for System Applications Only)


Widgets that are updated periodically are subject to the scheduled time or interval settings. To offer more flexible updates, the widget host can provide a button to proactively trigger a widget update. Specifically, the widget host calls the [requestForm](../reference/apis/js-apis-app-form-formHost.md#requestform) API to request a widget update. The system then calls the [onUpdateForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback in the FormExtensionAbility of the widget provider. In the callback, the [updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform) API can be used to update the widget content. For details about the **onUpdateForm** lifecycle callback, see [Updating Widget Content Through FormExtensionAbility](arkts-ui-widget-event-formextensionability.md).

```ts
import formHost from '@ohos.app.form.formHost';

@Entry()
@Component
struct WidgetCard {
  formId = ...; // Widget ID

  build() {
    Button (`Update Widget`)
      .type(ButtonType.Capsule)
      .width('50%')
      .height(50)
      .onClick(() => {
        console.info('FormAbility update form click');
        // formId is the ID of the widget to be updated.
        formHost.requestForm(this.formId.toString()).then(() => {
          console.info('Succeeded in requestForming.');
        });
      })

    ...
  }
}
```
