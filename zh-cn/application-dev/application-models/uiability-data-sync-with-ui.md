# UIAbility组件与UI的数据同步


基于当前的应用模型，可以通过以下几种方式来实现UIAbility组件与UI之间的数据同步。

- [使用EventHub进行数据通信](#使用eventhub进行数据通信)：在基类Context中提供了EventHub对象，可以通过发布订阅方式来实现事件的传递。在事件传递前，订阅者需要先进行订阅，当发布者发布事件时，订阅者将接收到事件并进行相应处理。
- [使用AppStorage/LocalStorage进行数据同步](#使用appstoragelocalstorage进行数据同步)：ArkUI提供了AppStorage和LocalStorage两种应用级别的状态管理方案，可用于实现应用级别和UIAbility级别的数据同步。


## 使用EventHub进行数据通信

[EventHub](../reference/apis/js-apis-inner-application-eventHub.md)为UIAbility组件提供了事件机制，使它们能够进行订阅、取消订阅和触发事件等数据通信能力。

在[基类Context](application-context-stage.md)中，提供了EventHub对象，可用于在UIAbility组件实例内通信。使用EventHub实现UIAbility与UI之间的数据通信需要先获取EventHub对象，本章节将以此为例进行说明。

1. 在UIAbility中调用[`eventHub.on()`](../reference/apis/js-apis-inner-application-eventHub.md#eventhubon)方法注册一个自定义事件“event1”，[`eventHub.on()`](../reference/apis/js-apis-inner-application-eventHub.md#eventhubon)有如下两种调用方式，使用其中一种即可。

   ```ts
   import hilog from '@ohos.hilog';
   import Logger from '../utils/Logger';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import type window from '@ohos.window';
   import type { Context } from '@ohos.abilityAccessCtrl';
   import Want from '@ohos.app.ability.Want'
   import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
   
   const DOMAIN_NUMBER: number = 0xFF00;
   const TAG: string = '[EventAbility]';
   
   export default class EntryAbility extends UIAbility {
   
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       // 获取UIAbility实例的上下文
       let context = this.context;
       // 获取eventHub
       let eventhub = this.context.eventHub;
       // 执行订阅操作
       eventhub.on('event1', this.eventFunc);
       eventhub.on('event1', (data: string) => {
         // 触发事件，完成相应的业务操作
       });
       hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');
     }
       
       // ...
       
     eventFunc(argOne: Context, argTwo: Context): void {
       Logger.info(TAG, '1. ' + `${argOne}, ${argTwo}`);
       return;
     }
   }
   ```

2. 在UI中通过[eventHub.emit()](../reference/apis/js-apis-inner-application-eventHub.md#eventhubemit)方法触发该事件，在触发事件的同时，根据需要传入参数信息。

   ```ts
   import common from '@ohos.app.ability.common';
   import promptAction from '@ohos.promptAction'
   
   @Entry
   @Component
   struct Page_EventHub {
   
     private context = getContext(this) as common.UIAbilityContext;
   
     eventHubFunc() : void {
       // 不带参数触发自定义“event1”事件
       this.context.eventHub.emit('event1');
       // 带1个参数触发自定义“event1”事件
       this.context.eventHub.emit('event1', 1);
       // 带2个参数触发自定义“event1”事件
       this.context.eventHub.emit('event1', 2, 'test');
       // 开发者可以根据实际的业务场景设计事件传递的参数
     }
   
     build() {
       Column() {
         Row() {
           Flex({ justifyContent: FlexAlign.Start, alignContent: FlexAlign.Center }) {
             Text($r('app.string.DataSynchronization'))
               .fontSize(24)
               .fontWeight(700)
               .textAlign(TextAlign.Start)
               .margin({ top: 12 , bottom: 11 , right: 24 , left: 24})
           }
         }
         .width('100%')
         .height(56)
         .justifyContent(FlexAlign.Start)
         .backgroundColor($r('app.color.backGrounding'))
   
         List({ initialIndex: 0 }) {
           ListItem() {
             Row() {
               Row(){
                 Text($r('app.string.EventHubFuncA'))
                   .textAlign(TextAlign.Start)
                   .fontWeight(500)
                   .margin({ top: 13, bottom: 13, left: 0, right: 8 })
                   .fontSize(16)
                   .width(232)
                   .height(22)
                   .fontColor($r('app.color.text_color'))
               }
               .height(48)
               .width('100%')
               .borderRadius(24)
               .margin({ top: 4, bottom: 4, left: 12, right: 12 })
             }
             .onClick(() => {
               this.eventHubFunc();
               promptAction.showToast({
                 message: $r('app.string.EventHubFuncA')
               });
             })
           }
           .height(56)
           .backgroundColor($r('app.color.start_window_background'))
           .borderRadius(24)
           .margin({ top: 8, right: 12, left: 12 })
   
           ListItem() {
             Row() {
               Row(){
                 Text($r('app.string.EventHubFuncB'))
                   .textAlign(TextAlign.Start)
                   .fontWeight(500)
                   .margin({ top: 13, bottom: 13, left: 0, right: 8 })
                   .fontSize(16)
                   .width(232)
                   .height(22)
                   .fontColor($r('app.color.text_color'))
               }
               .height(48)
               .width('100%')
               .borderRadius(24)
               .margin({ top: 4, bottom: 4, left: 12, right: 12 })
             }
             .onClick(() => {
               this.context.eventHub.off('event1');
               promptAction.showToast({
                 message: $r('app.string.EventHubFuncB')
               });
             })
           }
           .height(56)
           .backgroundColor($r('app.color.start_window_background'))
           .borderRadius(24)
           .margin({ top: 12, right: 12, left: 12 })
         }
         .height('100%')
         .backgroundColor($r('app.color.backGrounding'))
       }
       .width('100%')
       .margin({ top: 8 })
       .backgroundColor($r('app.color.backGrounding'))
     }
   }
   ```

3. 在UIAbility的注册事件回调中可以得到对应的触发事件结果，运行日志结果如下所示。

   ```json
   [Example].[Entry].[EntryAbility] 1. []
   [Example].[Entry].[EntryAbility] 1. [1]
   [Example].[Entry].[EntryAbility] 1. [2,"test"]
   ```
   
4. 在自定义事件“event1”使用完成后，可以根据需要调用[eventHub.off()](../reference/apis/js-apis-inner-application-eventHub.md#eventhuboff)方法取消该事件的订阅。

   ```ts
   // context为UIAbility实例的AbilityContext
   this.context.eventHub.off('event1');
   ```

## 使用AppStorage/LocalStorage进行数据同步

ArkUI提供了AppStorage和LocalStorage两种应用级别的状态管理方案，可用于实现应用级别和UIAbility级别的数据同步。使用这些方案可以方便地管理应用状态，提高应用性能和用户体验。其中，AppStorage是一个全局的状态管理器，适用于多个UIAbility共享同一状态数据的情况；而LocalStorage则是一个局部的状态管理器，适用于单个UIAbility内部使用的状态数据。通过这两种方案，开发者可以更加灵活地控制应用状态，提高应用的可维护性和可扩展性。详细请参见[应用级变量的状态管理](../quick-start/arkts-application-state-management-overview.md)。

<!--no_check-->