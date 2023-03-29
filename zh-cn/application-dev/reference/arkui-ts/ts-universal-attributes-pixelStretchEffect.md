# 图像边缘像素扩展效果

设置组件的图像边缘像素扩展效果。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。此接口为系统接口。

## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| pixelStretchEffect | [PixelStretchEffectOptions](ts-types.md#PixelStretchEffectOptions)&nbsp;| 设置组件的图像边缘像素扩展距离。<br>参数`options`包括上下左右四个方向的边缘像素扩展距离。<br>**说明：**<br>1、如果距离为正值，表示向外扩展，放大原来图像大小。上下左右四个方向分别用边缘像素填充，填充的距离即为设置的边缘扩展的距离。<br>2、如果距离为负值，表示内缩，但是最终图像大小不变。内缩方式：1、图像根据`options`的设置缩小，缩小大小为四个方向边缘扩展距离的绝对值。2、图像用边缘像素扩展到原来大小。<br>3、对`options`的输入约束：1、上下左右四个方向的扩展统一为非正值或者非负值。即四个边同时向外扩或者内缩，方向一致。2、所有方向的输入均为百分比或者具体值，不支持百分比和具体值混用。3、所有异常情况下，显示为{0，0，0，0}效果，即跟原图保持一致。|

## 示例

### 示例1

```ts
// xxx.ets
@Entry
@Component
struct PixelStretchExample {
  build() {
    Stack() {
      Text('This is the text content with letterSpacing 0.')
        .letterSpacing(0)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('50%')
        .pixelStretchEffect({top:10,left:10,right:10,bottom:10 })
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```
效果图如下：

![textPixelStretch1](figures/textPixelStretch1.png)

去掉pixelStretchEffect的设置，原图效果如下：

![textPixelStretch2](figures/textPixelStretch2.png)

对比发现，如果边缘扩展距离设置为正值，图像向外扩展了边缘距离。

### 示例2

基于示例1，现在把边缘扩展距离改为非正值。

```ts
// xxx.ets
@Entry
@Component
struct PixelStretchExample {
  build() {
    Stack() {
      Text('This is the text content with letterSpacing 0.')
        .letterSpacing(0)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('50%')
        .pixelStretchEffect({top:-10,left:-10,right:-10,bottom:-10 })
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}
```
效果图如下:

![textPixelStretch3](figures/textPixelStretch3.png)

跟原图对比发现，效果图分两步实现：<br>1、原图大小缩小，缩小后的大小为原图大小减去像素
收缩的距离。例如，原图大小为`100*100`，设置了`pixelStretchEffect({top:-10,left:-10,
right:-10,bottom:-10 })`，则缩小后的大小为`(100-10-10)*(100-10-10)`，即`80*80`。<br>2、使用边缘像素扩展，将图像扩展为原图大小。
