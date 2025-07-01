# 形状裁剪（clipShape）

可利用[clipShape](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clipshape12)接口将组件裁剪为所需的形状。调用该接口后，可以保留该形状覆盖的组件部分，同时移除组件的其余部分。裁剪形状本身是不可见的。

> **说明：**  
>
> 不同的形状支持的属性范围不同，路径是一种形状，除此之外还有椭圆、矩形等形状。
>
> 路径的形状不支持设置宽度和高度，具体形状支持的属性参考具体[形状](../reference/apis-arkui/js-apis-arkui-shape.md)的文档。
>
> 形状中的[fill](../reference/apis-arkui/js-apis-arkui-shape.md#fill)属性对clipShape接口不生效。

## 裁剪圆形

通过设置CircleShape，将图片裁剪为圆形。

```ts
// xxx.ets
import { CircleShape } from '@kit.ArkUI';

@Entry
@Component
struct ClipShapeExample {
  build() {
    Column({ space: 15 }) {
      // 用一个280px直径的圆对图片进行裁剪
      Image($r('app.media.background'))
        .clipShape(new CircleShape({ width: '280px', height: '280px' }))
        .width('500px').height('280px')

      // 用一个350px直径的圆对图片进行裁剪
      Image($r('app.media.background'))
        .clipShape(new CircleShape({ width: '350px', height: '350px' }))
        .width('500px').height('370px')
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![zh-cn_image_clip_rotundity](figures/zh-cn_image_clip_rotundity.png)

## 裁剪椭圆形

通过设置EllipseShape，将图片裁剪为椭圆形。

```ts
// xxx.ets
import { EllipseShape } from '@kit.ArkUI';

@Entry
@Component
struct ClipShapeExample {
  build() {
    Column({ space: 15 }) {
      Image($r('app.media.background'))
        .clipShape(new EllipseShape({ width: '280px', height: '200px' }))
        .width('500px').height('400px')

      Image($r('app.media.background'))
        .clipShape(new EllipseShape({ width: '380px', height: '280px' }))
        .width('500px').height('400px')
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![zh-cn_image_clipl_elliptical](figures/zh-cn_image_clipl_elliptical.png)

## 裁剪矩形

通过设置RectShape，将图片裁剪为矩形。

```ts
// xxx.ets
import { RectShape } from '@kit.ArkUI';

@Entry
@Component
struct ClipShapeExample {
  build() {
    Column({ space: 15 }) {
      Image($r('app.media.background'))
        .clipShape(new RectShape({ width: '200px', height: '200px' }))
        .width('500px').height('400px')

      Image($r('app.media.background'))
        .clipShape(new RectShape({ width: '380px', height: '280px' }))
        .width('500px').height('400px')
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![zh-cn_image_clipl_rectangle](figures/zh-cn_image_clipl_rectangle.png)

## 裁剪不规则形状

通过设置PathShape，将图片裁剪为不规则形状。

```ts
// xxx.ets
import { PathShape } from '@kit.ArkUI';

@Entry
@Component
struct ClipShapeExample {
  build() {
    Column({ space: 15 }) {
      Row() {
        Image($r('app.media.background'))
          .clipShape(new PathShape({ commands: 'M0 0 H400 V200 H0 Z' }))
          .width('500px').height('300px')
      }
      .clip(true)
      .borderRadius(20)
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![zh-cn_image_clip_Irregular_shapes](figures/zh-cn_image_clip_Irregular_shapes.png)
