# Updating Widget Content Through the message Event

On the widget page, the **postCardAction** API can be used to trigger a message event to start a FormExtensionAbility, which then updates the widget content. The following is an example of this widget update mode.

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/arkui-ts/ts-container-formlink.md).

- On the widget page, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the message event to start the FormExtensionAbility. Use [LocalStorageProp](../quick-start/arkts-localstorage.md#localstorageprop) to decorate the widget data to be updated.
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('title') title: string = 'Title default';
    @LocalStorageProp('detail') detail: string = 'Description default';
  
    build() {
      Column() {
        Column() {
          Text(`${this.title}`)
            .margin(5).fontWeight(FontWeight.Medium).fontSize('14fp')
          Text(`${this.detail}`)
            .margin(5).fontColor(Color.Gray).fontSize('12fp').height('25%')
        }.width('100%').alignItems(HorizontalAlign.Start)
        Button('UPDATE')
          .margin(15).width('90%')
          .onClick(() => {
            postCardAction(this, {
              'action': 'message',
              'params': {
                'msgTest': 'messageEvent'
              }
            });
          })
      }.width('90%').height('90%').margin('5%')
    }
  }
  ```
  
- Call the [updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform) API to update the widget in the **onFormEvent** callback of the FormExtensionAbility.
  
  ```ts
  import formBindingData from '@ohos.app.form.formBindingData';
  import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
  import formProvider from '@ohos.app.form.formProvider';
  
  export default class EntryFormAbility extends FormExtensionAbility {
    onFormEvent(formId: string, message: string) {
      // Called when a specified message event defined by the form provider is triggered.
      console.info(`FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
      let formData = new Map<Object, string>();
      formData.set('title', 'Title Update.'); // It matches the widget layout.
      formData.set('detail', 'Description update success.'); // It matches the widget layout.
      let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
      formProvider.updateForm(formId, formInfo).then(() => {
        console.info('FormAbility updateForm success.');
      });
    }

    ...
  }
  ```

  The figure below shows the effect.
  
  | Initial State                                               | After Clicking                                             |
  | ------------------------------------------------------- | ----------------------------------------------------- |
  | ![WidgetUpdateBefore](figures/widget-update-before.PNG) | ![WidgetUpdateAfter](figures/widget-update-after.PNG) |
