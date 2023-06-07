# 使用call事件拉起指定UIAbility到后台


许多应用希望借助卡片的能力，实现和应用在前台时相同的功能。例如音乐卡片，卡片上提供播放、暂停等按钮，点击不同按钮将触发音乐应用的不同功能，进而提高用户的体验。在卡片中使用**postCardAction**接口的call能力，能够将卡片提供方应用的指定的UIAbility拉到后台。同时，call能力提供了调用应用指定方法、传递数据的功能，使应用在后台运行时可以通过卡片上的按钮执行不同的功能。


通常使用按钮控件来触发call事件，示例代码如下：


- 在卡片页面中布局两个按钮，点击其中一个按钮时调用postCardAction向指定UIAbility发送call事件，并在事件内定义需要调用的方法和传递的数据。需要注意的是，method参数为必选参数，且类型需要为string类型，用于触发UIAbility中对应的方法。
  
  ```ts
  @Entry
  @Component
  struct WidgetCard {
    build() {
      Column() {
        Button('功能A')
          .margin('20%')
          .onClick(() => {
            console.info('call EntryAbility funA');
            postCardAction(this, {
              'action': 'call',
              'abilityName': 'EntryAbility', // 只能跳转到当前应用下的UIAbility
              'params': {
                'method': 'funA' // 在EntryAbility中调用的方法名
              }
            });
          })
  
        Button('功能B')
          .margin('20%')
          .onClick(() => {
            console.info('call EntryAbility funB');
            postCardAction(this, {
              'action': 'call',
              'abilityName': 'EntryAbility', // 只能跳转到当前应用下的UIAbility
              'params': {
                'method': 'funB', // 在EntryAbility中调用的方法名
                'num': 1 // 需要传递的其他参数
              }
            });
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

- 在UIAbility中接收call事件并获取参数，根据传递的method不同，执行不同的方法。其余数据可以通过readString的方式获取。需要注意的是，UIAbility需要onCreate生命周期中监听所需的方法。
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  function FunACall(data) {
    // 获取call事件中传递的所有参数
    console.log('FunACall param:' + JSON.stringify(data.readString()));
    return null;
  }

  function FunBCall(data) {
    console.log('FunBCall param:' + JSON.stringify(data.readString()));
    return null;
  }
  
  export default class CameraAbility extends UIAbility {
    // 如果UIAbility第一次启动，在收到call事件后会触发onCreate生命周期回调
    onCreate(want, launchParam) {
        try {
            // 监听call事件所需的方法
            this.callee.on('funA', FunACall);
            this.callee.on('funB', FunBCall);
        } catch (error) {
            console.log('register failed with error. Cause: ' + JSON.stringify(error));
        }
    }

    ...
  
    // 进程退出时，解除监听
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
