# Updating Widget Content Through the router or call Event


On the widget page, the **postCardAction** API can be used to trigger a router or call event to start a UIAbility, which then updates the widget content. The following is an example of this widget update mode.

## Updating Widget Content Through the router Event

- On the widget page, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the router event to the FormExtensionAbility.
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('detail') detail: string = 'init';
  
    build() {
      Column() {
        Button ('Redirect')
          .margin('20%')
          .onClick(() => {
            console.info('postCardAction to EntryAbility');
            postCardAction(this, {
              'action': 'router',
              'abilityName': 'EntryAbility', // Only the UIAbility of the current application is allowed.
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
  
- In the **onCreate()** or **onNewWant()** lifecycle callback of the UIAbility, use the input parameter **want** to obtain the ID (**formID**) and other information of the widget, and then call the [updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform) API to update the widget.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import formBindingData from '@ohos.app.form.formBindingData';
  import formProvider from '@ohos.app.form.formProvider';
  import formInfo from '@ohos.app.form.formInfo';
  
  export default class EntryAbility extends UIAbility {
    // If the UIAbility is started for the first time, onCreate is triggered after the router event is received.
    onCreate(want, launchParam) {
      console.info('Want:' + JSON.stringify(want));
      if (want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = want.parameters[formInfo.FormParam.IDENTITY_KEY];
        let message = JSON.parse(want.parameters.params).detail;
        console.info(`UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData = {
          "detail": message +': onCreate UIAbility.', // Matches the widget layout.
        };
        let formMsg = formBindingData.createFormBindingData(formData)
        formProvider.updateForm(curFormId, formMsg).then((data) => {
          console.info('updateForm success.' + JSON.stringify(data));
        }).catch((error) => {
          console.error('updateForm failed:' + JSON.stringify(error));
        })
      }
    }
    // If the UIAbility is running in the background, onNewWant is triggered after the router event is received.
    onNewWant(want, launchParam) {
      console.info('onNewWant Want:' + JSON.stringify(want));
      if (want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = want.parameters[formInfo.FormParam.IDENTITY_KEY];
        let message = JSON.parse(want.parameters.params).detail;
        console.info(`UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData = {
          "detail": message +': onNewWant UIAbility.', // Matches the widget layout.
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

## Updating Widget Content Through the call Event

- When using the call event of the **postCardAction** API, the value of **formId** must be updated in the **onAddForm** callback of the FormExtensionAbility.
  
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

- On the widget page, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the event to the UIAbility.
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('detail') detail: string = 'init';
    @LocalStorageProp('formId') formId: string = '0';
  
    build() {
      Column() {
        Button ('Start in Background')
          .margin('20%')
          .onClick(() => {
            console.info('postCardAction to EntryAbility');
            postCardAction(this, {
              'action': 'call',
              'abilityName': 'EntryAbility', // Only the UIAbility of the current application is allowed.
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
  
- Listen for the method required by the call event in the **onCreate** callback of the UIAbility, and then call the [updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform) API in the corresponding method to update the widget.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import formBindingData from '@ohos.app.form.formBindingData';
  import formProvider from '@ohos.app.form.formProvider';
  
  const MSG_SEND_METHOD: string = 'funA'
  
  // After the call event is received, the method listened for by the callee is triggered.
  function FunACall(data) {
    // Obtain all parameters transferred in the call event.
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
    // If the UIAbility is started for the first time, onCreate is triggered after the call event is received.
    onCreate(want, launchParam) {
      console.info('Want:' + JSON.stringify(want));
      try {
         // Listen for the method required by the call event.
        this.callee.on(MSG_SEND_METHOD, FunACall);
      } catch (error) {
        console.log(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`)
      }
    }
    ...
  }
  ```
