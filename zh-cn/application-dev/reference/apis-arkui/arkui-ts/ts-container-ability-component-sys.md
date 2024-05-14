# AbilityComponent (系统接口)

独立显示Ability的容器。

>  **说明：**
>
>  从API Version 10开始，该组件不再维护，推荐使用[UIExtensionComponent](ts-container-ui-extension-component-sys.md)。
>
>  该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  本模块为系统接口。

## 使用约束

AbilityComponent为独立层次渲染，不能再之上叠加其他显示内容。

AbilityComponent不支持处理输入事件，事件不经过当前Ability，直接分发给内部的Ability处理。

AbilityComponent需设置且只能设置width、height，且width、height不支持动态更新。

被拉起的Ability必须继承[WindowExtension](../js-apis-application-windowExtensionAbility-sys.md)。

## 子组件

无


## 接口

AbilityComponent(want: Want)

**参数：**

| 参数名 | 参数类型                                                   | 必填 | 参数描述                |
| ------ | ---------------------------------------------------------- | ---- | ----------------------- |
| want   | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 默认加载的Ability描述。 |


## 事件

### onConnect

onConnect(callback:()&nbsp;=&gt;&nbsp;void)

AbilityComponent环境启动完成时的回调，之后可使用AbilityComponent的方法。

### onDisconnect

onDisconnect(callback:()&nbsp;=&gt;&nbsp;void)

AbilityComponent环境销毁时的回调。

## 示例

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
          })
          .onConnect(() => {
              console.log('AbilityComponent connect')
          })
          .onDisconnect(() => {
              console.log('AbilityComponent disconnect')
          })
      }
  }
}
```
