# 通过router或call事件刷新卡片内容


在卡片页面中可以通过**postCardAction**接口触发router事件或者call事件拉起UIAbility，然后由UIAbility刷新卡片内容，下面是这种刷新方式的简单示例。

## 通过router事件刷新卡片内容

- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发router事件至FormExtensionAbility。
  
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

## 通过call事件刷新卡片内容

- 在使用**postCardAction**接口的call事件时，需要在FormExtensionAbility中的onAddForm生命周期回调中更新formId。
  
   ```ts
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     onAddForm(want) {
      let formId = want.parameters["ohos.extra.param.key.form_identity"];
      let dataObj1 = {
        "formId": formId
      };
      let obj1 = formBindingData.createFormBindingData(dataObj1);
      return obj1;
    }
    
     ...
   };
   ```

- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发call事件至UIAbility。
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('detail') detail: string = 'init';
    @LocalStorageProp('formId') formId: string = '0';

    build() {
      Column() {
        Button('拉至后台')
          .margin('20%')
          .onClick(() => {
            console.info('postCardAction to EntryAbility');
            postCardAction(this, {
              'action': 'call',
              'abilityName': 'EntryAbility', // 只能拉起当前应用下的UIAbility
              'params': {
                'method': 'funA',
                'formId': this.formId,
                'detail': 'CallFromCard'
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
  
- 在UIAbility的onCreate生命周期中监听call事件所需的方法，然后在对应方法中调用[updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import formBindingData from '@ohos.app.form.formBindingData';
  import formProvider from '@ohos.app.form.formProvider';
  
  const MSG_SEND_METHOD: string = 'funA'
  
  // 在收到call事件后会触发callee监听的方法
  function FunACall(data) {
    // 获取call事件中传递的所有参数
    let params = JSON.parse(data.readString())
    if (params.formId !== undefined) {
      let curFormId = params.formId;
      let message = params.detail;
      console.info(`UpdateForm formId: ${curFormId}, message: ${message}`);
      let formData = {
        "detail": message
      };
      let formMsg = formBindingData.createFormBindingData(formData)
      formProvider.updateForm(curFormId, formMsg).then((data) => {
        console.info('updateForm success.' + JSON.stringify(data));
      }).catch((error) => {
        console.error('updateForm failed:' + JSON.stringify(error));
      })
    }
    return null;
  }
  export default class EntryAbility extends UIAbility {
    // 如果UIAbility第一次启动，call事件后会触发onCreate生命周期回调
    onCreate(want, launchParam) {
      console.info('Want:' + JSON.stringify(want));
      try {
         // 监听call事件所需的方法
        this.callee.on(MSG_SEND_METHOD, FunACall);
      } catch (error) {
        console.log(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`)
      }
    }
    ...
  }
  ```
