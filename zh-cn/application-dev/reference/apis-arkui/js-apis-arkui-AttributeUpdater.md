# AttributeUpdater

将属性直接设置给组件，无需标记为状态变量即可直接触发UI更新。

>  **说明：**
>
>  从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>


## 导入模块

```ts
import { AttributeUpdater } from '@ohos.arkui.modifier'
```

>  **使用说明：**
>  
>  1. 由于与属性方法同时设置或者在AttributeUpdater中实现applyNormalAttribute等方法时，涉及到与状态管理更新机制同时使用，易出现混淆，因此不建议在同一组件上同时用两种方法设置相同属性。
>  
>  2. 当与属性方法同时设置时，属性生效的原则为：后设置的生效。
>  若先进行属性直通更新，后通过状态管理机制更新属性方法，则后更新的属性方法生效；
>  若先通过状态管理机制更新属性方法，后进行属性直通更新，则属性直通更新生效。
>  
>  3. 一个AttributeUpdater对象只能同时关联一个组件，否则将出现设置的属性只在一个组件上生效的现象。
>  

## AttributeUpdater
AttributeUpdater\<T>

为[AttributeModifier](arkui-ts/ts-universal-attributes-attribute-modifier.md#AttributeModifier)的实现类，开发者需要自定义class继承AttributeUpdater。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### applyNormalAttribute
applyNormalAttribute?(instance: T): void

定义正常态更新属性函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| instance | T | 是 | 组件的属性类，用来标识进行属性设置的组件的类型，比如Button组件的ButtonAttribute，Text组件的TextAttribute等。|

### initializeModifier
initializeModifier(instance: T): void

AttributeUpdater首次设置给组件时提供的样式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| instance | T | 是 | 组件的属性类，用来标识进行属性设置的组件的类型，比如Button组件的ButtonAttribute，Text组件的TextAttribute等。|

**示例：** 

通过initializeModifier方法初始化设置属性值。

```ts
// xxx.ets
import { AttributeUpdater } from '@ohos.arkui.modifier'

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  initializeModifier(instance: ButtonAttribute): void {
    instance.backgroundColor('#ff2787d9')
      .width('50%')
      .height(30)
  }
}

@Entry
@Component
struct updaterDemo1 {
  modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeUpdater1](figures/attribute-updater1.PNG)


### attribute
get attribute(): T | undefined

获取AttributeUpdater中组件对应的属性类实例，通过该实例实现属性直通更新的功能。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 描述                                                         |
| -------------------- | ------------------------------------------------------------ |
| T \| undefined |如果AttributeUpdater中组件的属性类实例存在，则返回对应组件的属性类实例，否则返回undefined。|

**示例：** 

通过属性直通设置方式更新属性值。

```ts
// xxx.ets
import { AttributeUpdater } from '@ohos.arkui.modifier'

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  initializeModifier(instance: ButtonAttribute): void {
    instance.backgroundColor('#ffd5d5d5')
      .width('50%')
      .height(30)
  }
}

@Entry
@Component
struct updaterDemo2 {
  modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
          .onClick(() => {
            this.modifier.attribute?.backgroundColor('#ff2787d9').width('30%')
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeUpdater2](figures/attribute-updater2.gif)