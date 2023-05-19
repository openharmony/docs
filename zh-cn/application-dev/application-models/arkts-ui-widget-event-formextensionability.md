# 通过message事件刷新卡片内容


在卡片页面中可以通过**postCardAction**接口触发message事件拉起FormExtensionAbility，然后由FormExtensionAbility刷新卡片内容，下面是这种刷新方式的简单示例。


- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发事件至FormExtensionAbility。
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('title') title: string = 'init';
    @LocalStorageProp('detail') detail: string = 'init';
  
    build() {
      Column() {
        Button('刷新')
          .onClick(() => {
            postCardAction(this, {
              'action': 'message',
              'params': {
                'msgTest': 'messageEvent'
              }
            });
          })
        Text(`${this.title}`)
        Text(`${this.detail}`)
      }
      .width('100%')
      .height('100%')
    }
  }
  ```
  
- 在FormExtensionAbility的onFormEvent生命周期中调用[updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import formBindingData from '@ohos.app.form.formBindingData';
  import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
  import formProvider from '@ohos.app.form.formProvider';
  
  export default class EntryFormAbility extends FormExtensionAbility {
    onFormEvent(formId, message) {
      // Called when a specified message event defined by the form provider is triggered.
      console.info(`FormAbility onEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
      let formData = {
        'title': 'Title Update Success.', // 和卡片布局中对应
        'detail': 'Detail Update Success.', // 和卡片布局中对应
      };
      let formInfo = formBindingData.createFormBindingData(formData)
      formProvider.updateForm(formId, formInfo).then((data) => {
        console.info('FormAbility updateForm success.' + JSON.stringify(data));
      }).catch((error) => {
        console.error('FormAbility updateForm failed: ' + JSON.stringify(error));
      })
    }
  
    ...
  }
  ```

  运行效果如下图所示。  
  ![WidgetUpdatePage](figures/WidgetUpdatePage.png)
