# ArkUI动画/交互事件开发常见问题(ArkTS)


## 焦点事件onBlur/onFocus回调无法触发(API 9)

**问题现象**

焦点事件onBlur/onFocus回调无法触发

**解决措施**

焦点事件默认情况下需要外接键盘的Tab键，或方向键触发，点击触发焦点事件需要添加焦点控制属性focusOnTouch。

**参考链接**

[焦点控制](../reference/arkui-ts/ts-universal-attributes-focus.md)


## scroll里面套一个grid，如何禁用grid的滑动事件(API 9)

可以通过onScrollFrameBegin事件和scrollBy方法实现容器嵌套滚动。

**参考链接**

[容器嵌套滚动样例](../reference/arkui-ts/ts-container-scroll.md#示例2)


## 如何实现一个组件不停地旋转(API 9)

可以通过[属性动画](../reference/arkui-ts/ts-animatorproperty.md)的方式实现。


## 列表目前无法键盘上下滑动，是否能力不支持(API 9)

**解决措施**

有以下两种方案：

1. 需要在列表子项中添加focusable(true)进行获焦。

2. 在每个item的外层嵌套一个可获焦组件，例如Button。


## 键盘移动焦点对象按下enter，为什么不会触发点击事件(API 9)

组件的内置的点击事件和开发者自定义的onClick点击事件默认会和空格键绑定，并非与enter键绑定（UX规格）。


## 多层组件嵌套button，如何阻止事件传递(API 9)

可以通过将button组件绑定参数stopPropagation来控制冒泡传递。


## 使用router或Navigator实现页面跳转时，如何关闭页面间转场动效(API 9)

1. 参考[页面间转场示例](../reference/arkui-ts/ts-page-transition-animation.md#示例)在当前页面和目标页面中定义pageTransition方法。

2. 将页面入场组件PageTransitionEnter和页面退场组件PageTransitionExit的动效参数duration都设置为0。


## 在容器组件嵌套的场景下，如何解决手势拖拽事件出现错乱的问题(API 9)

PanGesture用于触发拖动手势事件，滑动的最小距离distance默认为5vp时拖动手势识别成功。可以将distance值设为1，使拖动更灵敏，避免造成事件错乱。

**参考链接**

[PanGesture](../reference/arkui-ts/ts-basic-gestures-pangesture.md)


## 是否支持使用fontFamily属性设置不同的字体(API 9)

默认字体'HarmonyOS Sans'，且当前只支持这种字体。


## 点击输入框时会拉起软键盘，点击button时软键盘关闭要如何实现(API 9)

TextInput获取焦点会弹出输入法，失去焦点就会关闭软键盘，使用focusControl控制焦点即可关闭软键盘。

**代码示例**

```
build() {
  Column() {
    TextInput()
    Button(`hide`)
      .key('button')
      .onClick(()=>{
        focusControl.requestFocus('button')
      })
  }
}
```


## 当父组件绑定了onTouch，其子组件Button绑定了onClick，如何做到点击Button只响应Button的onClick，而不用响应父组件的onTouch(API 9)

可以在Button组件中绑定onTouch，并在onTouch中使用stopPropagation()阻止onTouch冒泡传递到父组件阻止冒泡传递。

**代码示例**

```
build() {
  Row() {
    Button("点击我")
      .width(100)
      .width(100)
      .backgroundColor('#f00')
      .onClick(()=>{
        console.log("Button onClick")
      })
      .onTouch((e) => {
        console.log("Button onTouch")
        e.stopPropagation()
      })
  }
  .onTouch(() => {
    console.log("Row onTouch")
  })
}
```


## 绑定菜单后无法使用右键触发菜单(API 9)

**解决措施**

目前菜单仅支持点击、长按触发方式，没有右键方式。


## 点击文本输入框，如何屏蔽系统默认键盘弹起行为(API 9)

设置TextInput组件的focusable属性为false，此组件则不可获焦，就不会拉起系统默认的键盘。


## 如何实现上下切换的页面间跳转动画(API 9)

**问题现象**

页面切换时如何实现上下切换动画

**解决措施**

可以使用pageTransition函数来实现页面转场效果，通过PageTransitionEnter和PageTransitionExit指定页面进入和退出的动画效果，将其slide属性设置为SlideEffect.Bottom，则页面入场时从下边划入，出场时滑出到下边，即可实现上下切换效果。

**代码示例**

```
// Index.ets
@Entry
@Component
struct PageTransition1 {
  build() {
    Stack({alignContent: Alignment.Bottom}) {
      Navigator({ target: 'pages/Page1'}) {
        Image($r('app.media.ic_banner01')).width('100%').height(200) // 图片存放在media文件夹下
      }
    }.height('100%').width('100%')
  }
  pageTransition() {
    PageTransitionEnter({ duration: 500, curve: Curve.Linear }).slide(SlideEffect.Bottom)
    PageTransitionExit({ duration: 500, curve: Curve.Ease }).slide(SlideEffect.Bottom)
  }
}
```

```
// Page1.ets
@Entry
@Component
struct PageTransition2 {
  build() {
    Stack({alignContent: Alignment.Bottom}) {
      Navigator({ target: 'pages/Index'}) {
        Image($r('app.media.ic_banner02')).width('100%').height(200) // 图片存放在media文件夹下
      }
    }.height('100%').width('100%')
  }
  pageTransition() {
    PageTransitionEnter({ duration: 500, curve: Curve.Linear }).slide(SlideEffect.Bottom)
    PageTransitionExit({ duration: 500, curve: Curve.Ease }).slide(SlideEffect.Bottom)
  }
}
```

**参考链接**

[页面间转场](../reference/arkui-ts/ts-page-transition-animation.md)

## 自定义组件间如何实现从底部滑入滑出的效果(API 9)

**问题现象**

一个页面底部默认显示自定义组件A，点击自定义组件A，则A消失，自定义组件B从底部出现；点击自定义组件B，则组件B消失，A从底部出现。这个效果要如何实现？

**解决措施**

可以使用transition产生组件转场动画，其参数type用来设置组件变化场景，包括新增和删除；参数translate用来设置转场时的平移效果。注意transition需要配合animateTo才能生效，动效时长、曲线、延时跟随animateTo中的配置。

**代码示例**

```
@Entry
@Component
struct ComponentTransition {
  @State flag: boolean = true;

  build() {
    Stack({alignContent: Alignment.Bottom}) {
        if (this.flag) {
          ComponentChild1({ flag: $flag })
            .transition({ type: TransitionType.Insert,translate: { x: 0, y: 200 } })
        }
        if (!this.flag) {
          ComponentChild2({ flag: $flag })
            .transition({ type: TransitionType.Insert, translate: { x: 0, y: 200 } })
        }
    }.height('100%').width('100%')
  }
}

@Component
struct ComponentChild1 {
  @Link flag: boolean

  build() {
    Column() {
      Image($r('app.media.ic_banner01'))
        .width('100%')
        .height(200)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.flag = !this.flag;
          })
        })
    }
  }
}

@Component
struct ComponentChild2 {
  @Link flag: boolean

  build() {
    Column() {
      Image($r('app.media.ic_banner02'))
        .width('100%')
        .height(200)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.flag = !this.flag;
          })
        })
    }
  }
}
```

**参考链接**

[出现/消失转场](../ui/arkts-enter-exit-transition.md)


## 文件管理器短按不响应(API 10)

**问题现象**

短按文件夹图标，如点击时长在200-500ms松手会触发文件管理器点击不响应。

**原因分析**

拖拽手势识别逻辑存在异常分支未处理，短按特定时间段松手会导致手势识别器处于pending状态，不再响应用户输入导致文件管理器出现卡死现象。

**解决措施**

长按文件图标或者空白区域即可恢复。


