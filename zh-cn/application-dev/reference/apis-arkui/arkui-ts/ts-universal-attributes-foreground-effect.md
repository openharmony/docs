# 前景属性设置

设置组件的前景属性。

>  **说明：**
>
>  从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## foregroundEffect

foregroundEffect(options: ForegroundEffectOptions)

设置组件的前景属性。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| options | [ForegroundEffectOptions](ts-appendix-enums.md#foregroundeffectoptions12) | 是   | 设置组件前景属性包括：模糊半径。 |

## 示例

通过foregroundEffect接口设置前景属性

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      Image($r('app.media.icon'))
          .width(100)
          .height(100)
          .foregroundEffect({ radius: 20 })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

效果图如下：
radius表示模糊半径，数值越大越模糊

![foregroundColor_circle](figures/foregroundEffect.jpg)
