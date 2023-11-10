# 通过message事件刷新卡片内容

在卡片页面中可以通过**postCardAction**接口触发message事件拉起FormExtensionAbility，然后由FormExtensionAbility刷新卡片内容，下面是这种刷新方式的简单示例。

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/arkui-ts/ts-container-formlink.md)。

- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发message事件拉起FormExtensionAbility。卡片页面中使用[LocalStorageProp](../quick-start/arkts-localstorage.md#localstorageprop)装饰需要刷新的卡片数据。
  
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
  
- 在FormExtensionAbility的onFormEvent生命周期中调用[updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import formBindingData from '@ohos.app.form.formBindingData';
  import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
  import formProvider from '@ohos.app.form.formProvider';

  export default class EntryFormAbility extends FormExtensionAbility {
    onFormEvent(formId: string, message: string) {
      // Called when a specified message event defined by the form provider is triggered.
      console.info(`FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
      class FormDataClass{
        title: string = 'Title Update.' // 和卡片布局中对应
        detail: string = 'Description update success.' // 和卡片布局中对应
      }
      let formData = new FormDataClass();
      let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
      formProvider.updateForm(formId, formInfo).then(() => {
        console.info('FormAbility updateForm success.');
      });
    }
    ...
  }
  ```

  运行效果如下图所示。
  
  | 初始状态                                                | 点击刷新                                              |
  | ------------------------------------------------------- | ----------------------------------------------------- |
  | ![WidgetUpdateBefore](figures/widget-update-before.PNG) | ![WidgetUpdateAfter](figures/widget-update-after.PNG) |
