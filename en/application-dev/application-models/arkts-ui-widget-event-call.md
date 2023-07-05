# Launching a UIAbility in the Background Through the call Event


There may be cases you want to provide in a widget access to features available in your application running in the foreground, for example, the play, pause, and stop buttons in a music application widget. This is where the **call** capability of the **postCardAction** API comes in handy. This capability, when used in a widget, can start the specified UIAbility of the widget provider in the background. It also allows the widget to call the specified method of the application and transfer data so that the application, while in the background, can behave accordingly in response to touching of the buttons on the widget.


Typically, the call event is triggered for touching of buttons. Below is an example.


- In this example, two buttons are laid out on the widget page. When one button is clicked, the **postCardAction** API is called to send a call event to the target UIAbility. Note that the **method** parameter in the API indicates the method to call in the target UIAbility. It is mandatory and of the string type.
  
  ```ts
  @Entry
  @Component
  struct WidgetCard {
    build() {
      Column() {
        Button ('Feature A')
          .margin('20%')
          .onClick(() => {
            console.info('call EntryAbility funA');
            postCardAction(this, {
              'action': 'call',
              'abilityName': 'EntryAbility', // Only the UIAbility of the current application is allowed.
              'params': {
                'method': 'funA' // Set the name of the method to call in the EntryAbility.
              }
            });
          })
  
        Button ('Feature B')
          .margin('20%')
          .onClick(() => {
            console.info('call EntryAbility funB');
            postCardAction(this, {
              'action': 'call',
              'abilityName': 'EntryAbility', // Only the UIAbility of the current application is allowed.
              'params': {
                'method': 'funB', // Set the name of the method to call in the EntryAbility.
                'num': 1 // Set other parameters to be passed in.
              }
            });
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

- The UIAbility receives the call event and obtains the transferred parameters. It then executes the target method specified by the **method** parameter. Other data can be obtained in readString mode. Listen for the method required by the call event in the **onCreate** callback of the UIAbility.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  function FunACall(data) {
    // Obtain all parameters passed in the call event.
    console.log('FunACall param:' + JSON.stringify(data.readString()));
    return null;
  }
  
  function FunBCall(data) {
    console.log('FunBCall param:' + JSON.stringify(data.readString()));
    return null;
  }
  
  export default class CameraAbility extends UIAbility {
    // If the UIAbility is started for the first time, onCreate is triggered afte the call event is received.
    onCreate(want, launchParam) {
        try {
            // Listen for the method required by the call event.
            this.callee.on('funA', FunACall);
            this.callee.on('funB', FunBCall);
        } catch (error) {
            console.log('register failed with error. Cause: ' + JSON.stringify(error));
        }
    }
  
    ...
  
    // Deregister the listener when the process exits.
    onDestroy() {
        try {
            this.callee.off('funA');
            this.callee.off('funB');
        } catch (error) {
            console.log('register failed with error. Cause: ' + JSON.stringify(error));
        }
    }
  };
  ```
