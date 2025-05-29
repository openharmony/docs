# Updating Widget Content Through the message Event

On the widget page, the [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction) API can be used to trigger a message event to start a FormExtensionAbility, which then updates the widget content. The following is an example of this widget update mode.

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md).

- On the widget page, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the message event to start the FormExtensionAbility. Use [LocalStorageProp](../quick-start/arkts-localstorage.md#localstorageprop) to decorate the widget data to be updated.
  
  ```ts
  let storageUpdateByMsg = new LocalStorage();
  
  @Entry(storageUpdateByMsg)
  @Component
  struct UpdateByMessageCard {
    @LocalStorageProp('title') title: ResourceStr = $r('app.string.default_title');
    @LocalStorageProp('detail') detail: ResourceStr = $r('app.string.DescriptionDefault');
  
    build() {
      Column() {
        Column() {
          Text(this.title)
            .fontColor('#FFFFFF')
            .opacity(0.9)
            .fontSize(14)
            .margin({ top: '8%', left: '10%' })
          Text(this.detail)
            .fontColor('#FFFFFF')
            .opacity(0.6)
            .fontSize(12)
            .margin({ top: '5%', left: '10%' })
        }.width('100%').height('50%')
        .alignItems(HorizontalAlign.Start)
  
        Row() {
          Button() {
            Text($r('app.string.update'))
              .fontColor('#45A6F4')
              .fontSize(12)
          }
          .width(120)
          .height(32)
          .margin({ top: '30%', bottom: '10%' })
          .backgroundColor('#FFFFFF')
          .borderRadius(16)
          .onClick(() => {
            postCardAction(this, {
              action: 'message',
              params: { msgTest: 'messageEvent' }
            });
          })
        }.width('100%').height('40%')
        .justifyContent(FlexAlign.Center)
      }
      .width('100%')
      .height('100%')
      .alignItems(HorizontalAlign.Start)
      .backgroundImage($r('app.media.CardEvent'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```
  
- Call the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) API to update the widget in the **onFormEvent** callback of the FormExtensionAbility.
  
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const TAG: string = 'EntryFormAbility';
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class EntryFormAbility extends FormExtensionAbility {
    onFormEvent(formId: string, message: string): void {
      // Called when a specified message event defined by the form provider is triggered.
      hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
  
      class FormDataClass {
        title: string ='Title Update.'; // It matches the widget layout.
        detail: string = 'Description update success.'; // It matches the widget layout.
      }
  
      let formData = new FormDataClass();
      let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
      formProvider.updateForm(formId, formInfo).then(() => {
        hilog.info(DOMAIN_NUMBER, TAG, 'FormAbility updateForm success.');
      }).catch((error: BusinessError) => {
        hilog.info(DOMAIN_NUMBER, TAG, `Operation updateForm failed. Cause: ${JSON.stringify(error)}`);
      })
    }
    //...
  }
  ```
  
  The figure below shows the effect.
  
  | Initial State                                               | After Clicking                                             |
  | ------------------------------------------------------- | ----------------------------------------------------- |
  | ![WidgetUpdateBefore](figures/widget-update-before.PNG) | ![WidgetUpdateAfter](figures/widget-update-after.PNG) |
