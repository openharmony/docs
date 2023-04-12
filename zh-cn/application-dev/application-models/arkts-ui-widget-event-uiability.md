# 通过UIAbility刷新卡片内容


在卡片页面中可以通过**postCardAction**接口触发router事件或者call事件拉起UIAbility，然后由UIAbility刷新卡片内容，下面是这种刷新方式的简单示例。


- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发事件至FormExtensionAbility。
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('detail') detail: string = 'init';
  
    build() {
      Column() {
        Button('跳转')
          .margin('20%')
          .onClick(() => {
            console.info('postCardAction to EntryAbility');
            postCardAction(this, {
              'action': 'router',
              'abilityName': 'EntryAbility', // 只能跳转到当前应用下的UIAbility
              'params': {
                'detail': 'RouterFromCard'
              }
            });
          })
        Text(`${this.detail}`).margin('20%')
      }
      .width('100%')
      .height('100%')
    }
  }
  ```
  
- 在UIAbility的onCreate()或者onNewWant()生命周期中可以通过入参want获取卡片的formID和传递过来的参数信息，然后调用[updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import formBindingData from '@ohos.app.form.formBindingData';
  import formProvider from '@ohos.app.form.formProvider';
  import formInfo from '@ohos.app.form.formInfo';
  
  export default class EntryAbility extends UIAbility {
    // 如果UIAbility第一次启动，在收到Router事件后会触发onCreate生命周期回调
    onCreate(want, launchParam) {
      console.info('Want:' + JSON.stringify(want));
      if (want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = want.parameters[formInfo.FormParam.IDENTITY_KEY];
        let message = JSON.parse(want.parameters.params).detail;
        console.info(`UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData = {
          "detail": message + ': onCreate UIAbility.', // 和卡片布局中对应
        };
        let formMsg = formBindingData.createFormBindingData(formData)
        formProvider.updateForm(curFormId, formMsg).then((data) => {
          console.info('updateForm success.' + JSON.stringify(data));
        }).catch((error) => {
          console.error('updateForm failed:' + JSON.stringify(error));
        })
      }
    }
    // 如果UIAbility已在后台运行，在收到Router事件后会触发onNewWant生命周期回调
    onNewWant(want, launchParam) {
      console.info('onNewWant Want:' + JSON.stringify(want));
      if (want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = want.parameters[formInfo.FormParam.IDENTITY_KEY];
        let message = JSON.parse(want.parameters.params).detail;
        console.info(`UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData = {
          "detail": message + ': onNewWant UIAbility.', // 和卡片布局中对应
        };
        let formMsg = formBindingData.createFormBindingData(formData)
        formProvider.updateForm(curFormId, formMsg).then((data) => {
          console.info('updateForm success.' + JSON.stringify(data));
        }).catch((error) => {
          console.error('updateForm failed:' + JSON.stringify(error));
        })
      }
    }
  
    ...
  }
  ```
