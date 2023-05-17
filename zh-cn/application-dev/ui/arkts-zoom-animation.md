# 放大缩小视图


在不同页面间，有使用相同的元素（例如同一幅图）的场景，可以使用[共享元素转场](../reference/arkui-ts/ts-transition-animation-shared-elements.md)动画衔接。为了突出不同页面间相同元素的关联性，可为它们添加共享元素转场动画。如果相同元素在不同页面间的大小有明显差异，即可达到放大缩小视图的效果。


共享元素转场的接口为：



```ts
sharedTransition(id: string, options?: sharedTransitionOptions)
```


其中根据sharedTransitionOptions中的type参数，共享元素转场分为Exchange类型的共享元素转场和Static类型的共享元素转场。


## Exchange类型的共享元素转场

交换型的共享元素转场，需要两个页面中，存在通过sharedTransition函数配置为相同id的组件，它们称为共享元素。这种类型的共享元素转场适用于两个页面间相同元素的衔接，会从起始页共享元素的位置、大小过渡到目标页的共享元素的位置、大小。如果不指定type，默认为Exchange类型的共享元素转场，这也是最常见的共享元素转场的方式。使用Exchange类型的共享元素转场时，共享元素转场的动画参数由目标页options中的动画参数决定。


## Static类型的共享元素转场

静态型的共享元素转场通常用于页面跳转时，标题逐渐出现或隐藏的场景，只需要在一个页面中有Static的共享元素，不能在两个页面中出现相同id的Static类型的共享元素。在跳转到该页面（即目标页）时，配置Static类型sharedTransition的组件做透明度从0到该组件设定的透明度的动画，位置保持不变。在该页面（即起始页）消失时，做透明度逐渐变为0的动画，位置保持不变。

共享元素转场的动画参数由该组件sharedTransition属性中的动画参数决定。


## 场景示例

下面介绍使用共享元素转场进行放大缩小图片的示例。


```ts
// src page
import router from '@ohos.router';

@Entry
@Component
struct SharedTransitionSrc {
  build() {
    Column() {
      // 配置Exchange类型的共享元素转场，共享元素id为"sharedImage1"
      Image($r('app.media.mountain')).width(50).height(50)
        .sharedTransition('sharedImage1', { duration: 1000, curve: Curve.Linear })
        .onClick(() => {
          // 点击小图时路由跳转至下一页面
          router.pushUrl({ url: 'pages/myTest/sharedTransitionDst' });
        })
    }
    .padding(10)
    .width("100%")
    .alignItems(HorizontalAlign.Start)
  }
}
```




```ts
// dest page
import router from '@ohos.router';
@Entry
@Component
struct SharedTransitionDest {
  build() {
    Column() {
      // 配置Static类型的共享元素转场
      Text("SharedTransition dest page")
        .fontSize(16)
        .sharedTransition('text', { duration: 500, curve: Curve.Linear, type: SharedTransitionEffectType.Static })
        .margin({ top: 10 })

      // 配置Exchange类型的共享元素转场，共享元素id为"sharedImage1"
      Image($r('app.media.mountain'))
        .width(150)
        .height(150)
        .sharedTransition('sharedImage1', { duration: 500, curve: Curve.Linear })
        .onClick(() => {
          // 点击图片时路由返回至上一页面
          router.back();
        })
    }
    .width("100%")
    .alignItems(HorizontalAlign.Center)
  }
}
```


上述示例中，第一个页面（src page)和第二个页面（dest page）都配置了id为"sharedImage1"的共享元素转场，使两个页面能匹配到这一组共享元素。从第一个页面跳转到第二个页面时，第一个页面为起始页，第二个页面为目标页。配置id为"sharedImage1"的组件按照目标页中500ms的时长进行共享元素转场，达到放大视图的效果，id为"text"的组件按照配置的Static类型sharedTransition参数中的500ms的时长进行共享元素转场，标题逐渐出现。从第二个页面返回到第一个页面时，第二个页面为起始页，第一个页面为目标页。配置id为"sharedImage1"的组件按照目标页中1000ms的时长进行共享元素转场，缩小为原始视图，id为"text"的组件按照配置的Static类型sharedTransition参数中的500ms的时长进行共享元素转场，标题逐渐隐藏。



![sharedTransition](figures/sharedTransition.gif)
