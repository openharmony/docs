# AbilityComponent

>  **说明：**
>
>  该组件从API&nbsp;Version&nbsp;9开始支持。
>
>  本组件均为系统接口，三方应用不支持调用。


独立显示Ability的容器。

## 使用约束

使用AbilityComponent必须是平台签名使用，并申请权限。

AbilityComponent为独立层次渲染，不能再之上叠加其他显示内容。

AbilityComponent不支持处理输入事件，事件不经过当前Ability，直接分发给内部的Ability处理。

AbilityComponent需设置且只能设置width、height，且width、height不支持动态更新。

被启动的Ability必须是resizeable。

被启动的Ability需要设置为多任务栏不显示。

## 权限列表

ohos.permission.INFUSE_EVENTS

ohos.permission.CONTROL_ABILITY_STACKS

ohos.permission.INTEGRATED_ABILITY

ohos.permission.INTEGRATED_INTERIOR_WINDOW


## 子组件

无


## 接口

AbilityComponent(value: {want : Want, controller? : AbilityController})

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | want | [Want](../../reference/apis/js-apis-application-Want.md) | 是 | - | 默认加载的Ability描述。 |
  | controller | [AbilityController](#abilityController) | 否 | - | Ability控制器。 |


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onReady()&nbsp;=&gt;&nbsp;void | AbilityComponent环境启动完成时的回调，之后可使用AbilityComponent的方法。 |
| onDestroy()&nbsp;=&gt;&nbsp;void | AbilityComponent环境销毁时的回调。 |
| onAbilityCreated(name:&nbsp;string)&nbsp;=&gt;&nbsp;void | 加载Ability时触发，name为Ability名。 |
| onAbilityMoveToFont()&nbsp;=&gt;&nbsp;void               | 当Ability移动到前台时触发。 |
| onAbilityWillRemove()&nbsp;=&gt;&nbsp;void | Ability移除之前触发。 |

## AbilityController

Ability控制器，提供AbilityComponent的控制接口。

| 名称                                    | 功能描述                                                     |
| --------------------------------------- | ------------------------------------------------------------ |
| startAbility()&nbsp;=&gt;&nbsp;want     | 在AbilityComponent内部加载Ability。<br>want：要加载的Ability描述信息。 |
| preformBackPress()&nbsp;=&gt;&nbsp;void | 在AbilityComponent内部执行返回操作。                         |
| getStackCount()&nbsp;=&gt;&nbsp;void    | 获取AbilityComponent内部任务栈中任务的个数。                 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
 @State controller: AbilityController = new AbilityController()

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
              controller: this.controller
          })
          .onReady(() => {
              console.log('AbilityComponent ready');
          })
          .onDestory(() => {
              console.log('AbilityComponent destory');
          })
          Button("Start New")
          .onClick(() => {
              this.controller.startAbility({
                  bundleName: '',
                  abilityName: ''
              });
          })
          Button("Back")
          .onClick(() => {
              if (this.controller.getStacjCount() > 1) {
                  this.controller.preformBackPress();
              }
          })
      }
  }
}
```
