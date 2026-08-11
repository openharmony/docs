# 共享元素转场 (sharedTransition)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

共享元素转场（sharedTransition）用于在页面跳转时实现共享元素位置、大小等的平滑过渡动画，使同一元素在不同页面间保持视觉连续性，提升用户体验和转场流畅度。可以通过设置组件的sharedTransition属性将该元素标记为共享元素并设置对应的共享元素转场动效。sharedTransition仅发生在[@ohos.router (页面路由)](../js-apis-router.md)跳转时。

> **说明：**
>
> 从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## sharedTransition

sharedTransition(id: string, options?: sharedTransitionOptions): T

设置共享元素转场动效。该转场仅发生在@ohos.router页面路由跳转时。

> **说明：**
>
> - sharedTransition需与[PageTransitionEnter](./ts-page-transition-animation.md#pagetransitionenter)和[PageTransitionExit](./ts-page-transition-animation.md#pagetransitionexit)配合使用，共同控制页面转场动画效果。
> - 当PageTransitionEnter/PageTransitionExit设置type为RouteType.None、duration为0时，页面整体无转场动画，仅显示共享元素转场动效。
> - 当未配置PageTransition时，页面默认转场动画与共享元素转场动效同时播放，可能出现视觉叠加效果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| id | string | 是 | 两个页面中id值相同且不为空字符串的组件即为共享元素，在页面转场时可显示共享元素转场动效。传入空字符串时不产生共享元素转场动效。|
|     options          |  [sharedTransitionOptions](#sharedtransitionoptions)       | 否     |  共享元素转场动效参数。未设置时使用默认转场动画参数。各参数具体默认值参考[sharedTransitionOptions](#sharedtransitionoptions)。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件，用于链式调用。 |

## sharedTransitionOptions

共享元素转场动效参数。

> **说明：**
>
> type为SharedTransitionEffectType.Exchange时motionPath才会生效。
>
> type为SharedTransitionEffectType.Exchange时，效果为对匹配的共享元素产生位置、大小的过渡（可通过配置组件的border观察），不支持组件绘制内容的过渡效果（可通过为共享元素组件配置border属性来观察位置和大小变化的过渡范围）。例如，Text组件在两个页面上使用不同的fontSize属性值，即绘制内容有大小差异，在sharedTransition动画结束后的最后一帧，Text的fontSize效果会突变为跳转目标页fontSize的效果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型      | 只读 |  可选     | 说明                                                     |
| ----------------- | -------------|------- | ------- | --------------------------------------------------------------|
| duration          |     number   |  否  |    是          | 描述共享元素转场动效播放时长。<br>默认值：1000 <br>单位：毫秒<br>取值范围：[0, +∞) |
| curve             |      [Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[ICurve](../js-apis-curve.md#icurve9)  | 否 | 是 | 动画曲线。<br>推荐以Curve或ICurve形式指定。<br>当类型为string时，为动画插值曲线，取值参考[AnimateParam](./ts-explicit-animation.md#animateparam对象说明)的curve参数。<br>默认值：Curve.Linear |
| delay          |     number   |  否  |  是         | 延迟播放时间。<br>取值范围：[0, +∞)<br>默认值：0 <br>单位：毫秒 |
| motionPath          | [MotionPathOptions](./ts-motion-path-animation.md#motionpathoptions)  |  否   |  是        | 运动路径信息，用于定义共享元素转场时的运动轨迹。不设置时不启用运动路径效果。仅在type为SharedTransitionEffectType.Exchange时生效。 |
| zIndex          |     number   |  否   |   是           | 设置共享元素在转场动画期间的Z轴堆叠顺序。<br>取值范围：(-∞, +∞)<br>默认值：0<br>数值越大，该共享元素在转场过程中越靠前（显示在上层），越不容易被其他共享元素遮挡。此zIndex仅在共享元素转场动画期间生效，控制共享元素相对于其他同时参与转场的共享元素在Z轴上的堆叠顺序，不参与页面内普通组件的静态布局层级控制（页面内组件的静态布局层级由组件通用属性[zIndex](ts-universal-attributes-z-order.md#zindex)控制）。 |
| type           |     [SharedTransitionEffectType](ts-appendix-enums.md#sharedtransitioneffecttype)   |  否  |  是 | 动画类型，决定共享元素转场时的过渡方式。Exchange类型产生位置、大小的过渡动画（不支持内容过渡效果），其他类型详见[SharedTransitionEffectType](ts-appendix-enums.md#sharedtransitioneffecttype)。<br>默认值：SharedTransitionEffectType.Exchange |


## 示例

示例代码为点击图片所在区域跳转页面时，显示共享元素图片的自定义转场动效。 

```ts
// xxx.ets
@Entry
@Component
struct SharedTransitionExample {

  build() {
    Column() {
      // $r('app.media.ic_health_heart')需要替换为开发者所需的图像资源文件。
      Image($r('app.media.ic_health_heart')).width(50).height(50).margin({ left: 20, top: 20 })
        .sharedTransition('sharedImage', { duration: 800, curve: Curve.Linear, delay: 100 }) 
    }.width('100%').height('100%').alignItems(HorizontalAlign.Start)
    .onClick(() => {
      this.getUIContext().getRouter().pushUrl({ url: 'pages/PageB' });
    })
  }

  pageTransition() {
    PageTransitionEnter({ type: RouteType.None, duration: 0 })
    PageTransitionExit({ type: RouteType.None, duration: 0 })
  }
}
```

```ts
// PageB.ets
@Entry
@Component
struct PageBExample {
  build() {
    Stack() {
      // $r('app.media.ic_health_heart')需要替换为开发者所需的图像资源文件。
      Image($r('app.media.ic_health_heart')).width(150).height(150)
        .sharedTransition('sharedImage', { duration: 800, curve: Curve.Linear, delay: 100 })
    }.width('100%').height('100%')
  }

  pageTransition() {
    PageTransitionEnter({ type: RouteType.None, duration: 0 })
    PageTransitionExit({ type: RouteType.None, duration: 0 })
  }
}
```

![shared](figures/shared.gif)

