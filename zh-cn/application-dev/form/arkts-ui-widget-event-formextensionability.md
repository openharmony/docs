# 通过message事件刷新卡片内容

在卡片页面中可以通过[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction)接口触发message事件拉起FormExtensionAbility，然后由FormExtensionAbility刷新卡片内容，下面是这种刷新方式的简单示例。

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)。

- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用postCardAction接口触发message事件拉起FormExtensionAbility。卡片页面中使用[LocalStorageProp](../ui/state-management/arkts-localstorage.md#localstorageprop)装饰需要刷新的卡片数据。
  
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
  
- 在FormExtensionAbility的onFormEvent生命周期中调用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const TAG: string = 'EntryFormAbility';
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class EntryFormAbility extends FormExtensionAbility {
    onFormEvent(formId: string, message: string): void {
      // 当卡片提供方的postCardAction接口的message事件被触发时调用
      hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
  
      class FormDataClass {
        title: string = 'Title Update.'; // 和卡片布局中对应
        detail: string = 'Description update success.'; // 和卡片布局中对应
      }
  
      // 请根据业务替换为实际刷新的卡片数据
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
  
  运行效果如下图所示。
  
  | 初始状态                                                | 点击刷新                                              |
  | ------------------------------------------------------- | ----------------------------------------------------- |
  | ![WidgetUpdateBefore](figures/widget-update-before.PNG) | ![WidgetUpdateAfter](figures/widget-update-after.PNG) |
