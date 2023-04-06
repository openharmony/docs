# 图像球面效果

设置组件的图像球面效果。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。此接口为系统接口。

## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| sphericalEffect | [number]&nbsp;| 设置组件的图像球面化程度。<br>取值范围：[0,1]。<br>**说明：**<br>1、如果value等于0则图像保持原样，如果value等于1则图像为完全球面化效果。在0和1之间，数值越大，则球面化程度越高。<br>`value < 0 `或者` value > 1`为异常情况，`value < 0`按0处理，`value > 1`按1处理。<br> 2、如果组件的图像使用异步加载，则不支持球面效果。例如Image组件默认使用异步加载，如果要使用球面效果，就要设置`syncLoad`为`true`，但是这种做法不推荐。`backgroundImage`也是使用异步加载，所以如果设置了`backgroundImage`，不支持球面效果。<br>3、如果组件设置了阴影，不支持球面效果。|

## 示例

### 示例1
```ts
// xxx.ets
@Entry
@Component
struct SphericalEffectExample {
  build() {
    Stack() {
      TextInput({ placeholder: "请输入变化范围百分比（[0%,100%]）"})
        .width('50%')
        .height(35)
        .type(InputType.Number)
        .enterKeyType(EnterKeyType.Done)
        .caretColor(Color.Red)
        .placeholderColor(Color.Blue)
        .placeholderFont({
          size: 20,
          style: FontStyle.Italic,
          weight: FontWeight.Bold
        })
        .sphericalEffect(0.5)
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```
效果图如下：

![textInputSpherical1](figures/textInputSpherical1.png)

去掉sphericalEffect的设置，效果如下：

![textInputSpherical2](figures/textInputSpherical2.png)