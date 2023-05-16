# Updating Widget Content Through UIAbility


On the widget page, the **postCardAction** API can be used to trigger a router or call event to start the UIAbility, which then updates the widget content. The following is an example of this widget update mode.


- On the widget page, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the event to the FormExtensionAbility.
  
  ```ts
  let storage = new LocalStorage();
  @Entry(storage)
  @Component
  struct WidgetCard {
    @LocalStorageProp('detail') detail: string = 'init';
  
    build() {
      Column() {
        Button ('Jump')
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
    // If the UIAbility is started for the first time, the onCreate lifecycle callback is triggered after the router event is received.
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
    // If the UIAbility is running in the background, the onNewWant lifecycle callback is triggered after the router event is received.
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
