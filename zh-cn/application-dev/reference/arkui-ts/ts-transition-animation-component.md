# 组件内转场

组件内转场主要通过transition属性配置转场参数，在组件插入和删除时显示过渡动效，主要用于容器组件中的子组件插入和删除时，提升用户体验。 

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称 | 参数类型 | 参数描述 |
| -------- | -------- | -------- |
| transition | TransitionOptions<sup>(deprecated)</sup> \| TransitionEffect<sup>10+</sup>  | 设置组件插入显示和删除隐藏的过渡效果。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>详细描述见TransitionOptions和TransitionEffect对象说明。 |


## TransitionEffect<sup>10+</sup>对象说明
TransitionEffect以函数的形式指定转场效果。提供了以下接口：
| 接口名称 | 参数类型 | 是否静态函数 | 参数描述 |
| -------- | ---------- | -------- | -------- |
| opacity | number | 是 | 设置组件转场时的透明度效果，为插入时起点和删除时终点的值。<br/>取值范围： [0, 1]<br/>**说明：** <br/>设置小于0或大于1的非法值时，按1处理。 |
| translate | {<br/>x?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>y?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>z?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 是 | 设置组件转场时的平移效果，为插入时起点和删除时终点的值。<br/>-x：横向的平移距离。<br/>-y：纵向的平移距离。<br/>-z：竖向的平移距离。 |
| scale | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number,<br/>centerX?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerY?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 是 | 设置组件转场时的缩放效果，为插入时起点和删除时终点的值。<br/>-x：横向放大倍数（或缩小比例）。<br/>-y：纵向放大倍数（或缩小比例）。<br/>-z：竖向放大倍数（或缩小比例）。<br/>-&nbsp;centerX、centerY指缩放中心点，centerX和centerY默认值是"50%"，即默认以组件的中心点为缩放中心点。<br/>-&nbsp;中心点为(0, 0)代表组件的左上角。 |
| rotate | {<br/>x?:&nbsp;number,<br/>y?:&nbsp;number,<br/>z?:&nbsp;number,<br/>angle:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerX?:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerY?:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 是 | 设置组件转场时的旋转效果，为插入时起点和删除时终点的值。<br/>-x：横向的旋转向量分量。<br/>-y：纵向的旋转向量分量。<br/>-z：竖向的旋转向量分量。<br/>-&nbsp;centerX、centerY指旋转中心点，centerX和centerY默认值是"50%"，即默认以组件的中心点为旋转中心点。<br/>-&nbsp;中心点为(0, 0)代表组件的左上角。 |
| move | [TransitionEdge](ts-appendix-enums.md#transitionedge10) | 是 | 指定组件转场时从屏幕边缘滑入和滑出的效果，本质为平移效果，为插入时起点和删除时终点的值。 |
| asymmetric | appear: TransitionEffect,<br/>disappear: TransitionEffect<br/> | 是 | 指定非对称的转场效果。<br/>第一个参数指定出现的转场效果，第二个参数指定消失的转场效果。<br/>如不通过asymmetric函数构造TransitionEffect，则表明该效果在组件出现和消失时均生效。 |
| combine | TransitionEffect | 否 | 对TransitionEffect进行链式组合，以形成包含多种转场效果的TransitionEffect。 |
| animation | [AnimateParam](ts-explicit-animation.md#animateparam对象说明) | 否 | 指定该TransitionEffect的动画参数。</br>该参数只用来指定动画参数，其入参AnimateParam的onFinish回调不生效。</br>如果通过combine进行TransitionEffect的组合，前一TransitionEffect的动画参数也可用于后一TransitionEffect。 |

上表提供的静态函数用于构造TransitionEffect对象，而非静态函数作用于构造好的TransitionEffect对象，以指定多种转场效果的组合效果和动画参数。
此外TransitionEffect提供了一些转场效果的静态成员变量：
| 静态成员名称 | 参数描述 |
| -------- | -------- |
| IDENTITY | 禁用转场效果。 |
| OPACITY | 指定透明度为0的转场效果。即相当于TransitionEffect.opacity(0) |
| SLIDE | 指定出现时从左侧滑入、消失时从右侧滑出的转场效果。即相当于TransitionEffect.asymmetric(TransitionEffect.move(TransitionEdge.START), TransitionEffect.move(TransitionEdge.END)) |

>  **说明：**
>
>  1. TransitionEffect可通过combine函数实现多个转场效果的组合，可以为每个效果分别指定animation参数，且前一效果的animation的参数也可适用于后一效果。例如，TransitionEffect.OPACITY.animation({duration: 1000}).combine(TransitionEffect.translate({x: 100}))，则时长为1000ms的动画参数对OPACITY和translate均生效。
>  2. 动画参数的生效顺序为：本TransitionEffect指定的animation参数 > 前面的TransitionEffect指定的animation参数 > 触发该组件出现消失的animateTo中的动画参数。
>  3. 如果未使用animateTo触发转场动画且TransitionEffect中也无animation参数，则该组件直接出现或者消失。
>  4. TransitionEffect中指定的属性值如与默认值相同，则该属性不会产生转场动画。如TransitionEffect.opacity(1).animation({duration:1000})，由于opacity默认值也为1，未产生透明度动画，该组件直接出现或者消失。
>  5. 更详细的关于scale、rotate效果的介绍可参考[图形变换](ts-universal-attributes-transformation.md)。

## TransitionOptions<sup>(deprecated)</sup>
TransitionOptions通过指定结构体内的参数来指定转场效果。

从API version 10开始不再维护，建议使用[TransitionEffect](#transitioneffect10对象说明)代替。
| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| type | [TransitionType](ts-appendix-enums.md#transitiontype)  | 否 | 指定该转场样式生效的场景。<br/>默认值：TransitionType.All<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>不指定type时默认为TransitionType.All，即插入删除都生效。 |
| opacity | number | 否 | 设置组件转场时的透明度效果，为插入时起点和删除时终点的值。<br/>取值范围： [0, 1]<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>设置小于0或大于1的非法值时，按1处理。 |
| translate | {<br/>x?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>y?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>z?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 否 | 设置组件转场时的平移效果，为插入时起点和删除时终点的值。<br/>-x：横向的平移距离。<br/>-y：纵向的平移距离。<br/>-z：竖向的平移距离。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| scale | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number,<br/>centerX?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerY?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 否 | 设置组件转场时的缩放效果，为插入时起点和删除时终点的值。<br/>-x：横向放大倍数（或缩小比例）。<br/>-y：纵向放大倍数（或缩小比例）。<br/>-z：竖向放大倍数（或缩小比例）。<br/>-&nbsp;centerX、centerY指缩放中心点，centerX和centerY默认值是"50%"，即默认以组件的中心点为缩放中心点。<br/>-&nbsp;中心点为(0, 0)代表组件的左上角。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| rotate | {<br/>x?:&nbsp;number,<br/>y?:&nbsp;number,<br/>z?:&nbsp;number,<br/>angle:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerX?:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerY?:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 否 | 设置组件转场时的旋转效果，为插入时起点和删除时终点的值。<br/>-x：横向的旋转向量分量。<br/>-y：纵向的旋转向量分量。<br/>-z：竖向的旋转向量分量。<br/>-&nbsp;centerX、centerY指旋转中心点，centerX和centerY默认值是"50%"，即默认以组件的中心点为旋转中心点。<br/>-&nbsp;中心点为(0, 0)代表组件的左上角。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

>  **说明：**
>
>  1. 当使用TransitionOptions类型的入参指定转场效果时，**必须**配合[animateTo](ts-explicit-animation.md)使用才有动画效果，动效时长、曲线、延时跟随animateTo中的配置。
>  2. 当使用TransitionOptions作为入参，且不指定除type外的任何参数时，此时相当于指定了透明度的转场效果。例如，指定{type: TransitionType.Insert}相当于指定了{type: TransitionType.Insert, opacity: 0}的转场效果。而指定了具体效果时，则不会添加默认的透明度转场效果。

## 示例

下面是一个出现消失使用同一TransitionEffect（出现和消失互为逆过程）的示例。
```ts
// xxx.ets
@Entry
@Component
struct TransitionEffectExample1 {
  @State flag: boolean = true;
  @State show: string = 'show';

  build() {
    Column() {
      Button(this.show).width(80).height(30).margin(30)
        .onClick(() => {
          // 点击Button控制Image的显示和消失
          if (this.flag) {
            this.show = 'hide';
          } else {
            this.show = 'show';
          }
          this.flag = !this.flag;
        })
      if (this.flag) {
        // Image的显示和消失配置为相同的过渡效果（出现和消失互为逆过程）
        // 出现时从指定的透明度为0、绕z轴旋转180°的状态，变为默认的透明度为1、旋转角为0的状态，透明度与旋转动画时长都为2000ms
        // 消失时从默认的透明度为1、旋转角为0的状态，变为指定的透明度为0、绕z轴旋转180°的状态，透明度与旋转动画时长都为2000ms
        Image($r('app.media.testImg')).width(200).height(200)
          .transition(TransitionEffect.OPACITY.animation({ duration: 2000, curve: Curve.Ease }).combine(
            TransitionEffect.rotate({ z: 1, angle: 180 })
          ))
      }
    }.width('100%')
  }
}
```
示意图：<br/>
![transitionComponent2](figures/transitionComponent2.gif)

下面是一个出现和消失使用不同TransitionEffect的示例。
```ts
// xxx.ets
@Entry
@Component
struct TransitionEffectExample2 {
  @State flag: boolean = true;
  @State show: string = 'show';

  build() {
    Column() {
      Button(this.show).width(80).height(30).margin(30)
        .onClick(() => {
          // 点击Button控制Image的显示和消失
          if (this.flag) {
            this.show = 'hide';
          } else {
            this.show = 'show';
          }
          animateTo({ duration: 2000 }, () => {
            // 第一张图的TransitionEffect包含了animation，transition的动画参数由TransitionEffect指定
            // 第二张图的TransitionEffect不包含animation，transition的动画参数由animateTo指定
            this.flag = !this.flag;
          });
        })
      if (this.flag) {
        // Image的显示和消失配置为不同的过渡效果
        // 出现时做从指定的透明度为0变为默认的透明度1的动画，该动画时长为1000ms，以及做从指定的绕z轴旋转180°变为默认的旋转角为0的动画，该动画1000ms后播放，时长为1000ms
        // 消失时做从默认的透明度为1变为指定的透明度0的动画，该动画1000ms后播放，时长为1000ms，以及做从默认的旋转角0变为指定的绕z轴旋转180°的动画，该动画时长为1000ms
        Image($r('app.media.testImg')).width(200).height(200)
          .transition(
            TransitionEffect.asymmetric(
              TransitionEffect.OPACITY.animation({ duration: 1000 }).combine(
              TransitionEffect.rotate({ z: 1, angle: 180 }).animation({ delay: 1000, duration: 1000 }))
              ,
              TransitionEffect.OPACITY.animation({ delay: 1000, duration: 1000 }).combine(
              TransitionEffect.rotate({ z: 1, angle: 180 }).animation({ duration: 1000 }))
            )
          )
        // 出现时做从x方向和y方向scale都为0变为默认的x方向和y方向scale都为1的动画，该动画时长为animateTo中指定的2000ms
        // 消失时无转场效果
        Image($r('app.media.testImg')).width(200).height(200).margin({ top: 100 })
          .transition(
            TransitionEffect.asymmetric(
              TransitionEffect.scale({ x: 0, y: 0 }),
              TransitionEffect.IDENTITY
            )
          )
      }
    }.width('100%')
  }
}
```
示意图：<br/>
![transitionComponent3](figures/transitionComponent3.gif)
