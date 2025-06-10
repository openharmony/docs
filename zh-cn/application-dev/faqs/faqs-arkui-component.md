# ArkUI组件开发常见问题(ArkTS)


## 自定义弹窗能否在ts文件中定义和使用(API 9)

自定义弹窗的定义和初始化需要用到属于ArkTS语法内容，必须在ets后缀文件中定义使用，不能在ts后缀文件中定义使用。

**参考链接**

[自定义弹窗](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## 自定义弹窗中的变量如何传递给页面(API 9)

**问题现象**

在自定义弹窗内定义的变量内容，在关闭弹窗或变量变化时需要及时传递给页面，可以通过何种方式传递？

**解决措施**

- 方式一：使用组件的状态变量传递。

- 方式二：在初始化弹窗时，传递一个方法给自定义弹窗，在自定义弹窗中触发该方法，弹窗中变量作为方法的参数。

- 方式三：使用AppStorage或LocalStorage方式管理页面状态，实现自定义弹窗和页面之间状态的共享。

**代码示例**

- 方式一：

  ```
  @CustomDialog
  struct CustomDialog01 {
    @Link inputValue: string
    controller: CustomDialogController
    build() {
      Column() {
        Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
        TextInput({ placeholder: '', text: this.inputValue }).height(60).width('90%')
          .onChange((value: string) => {
            this.inputValue = value
          })
      }
    }
  }
  
  @Entry
  @Component
  struct DialogDemo01 {
    @State inputValue: string = 'click me'
    dialogController: CustomDialogController = new CustomDialogController({
      builder: CustomDialog01({
        inputValue: $inputValue
      })
    })
  
    build() {
      Column() {
        Button(this.inputValue)
          .onClick(() => {
            this.dialogController.open()
          }).backgroundColor(0x317aff)
      }.width('100%').margin({ top: 5 })
    }
  }
  ```

- 方式二：

  ```
  @CustomDialog
  struct CustomDialog02 {
    private inputValue: string
    changeInputValue: (val: string) => void
    controller: CustomDialogController
    build() {
      Column() {
        Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
        TextInput({ placeholder: '', text: this.inputValue }).height(60).width('90%')
          .onChange((value: string) => {
            this.changeInputValue(value)
          })
      }
    }
  }
  
  @Entry
  @Component
  struct DialogDemo02 {
    @State inputValue: string = 'click me'
    dialogController: CustomDialogController = new CustomDialogController({
      builder: CustomDialog02({
        inputValue: this.inputValue,
        changeInputValue: (val: string) => {
          this.inputValue = val
        }
      })
    })
  
    build() {
      Column() {
        Button(this.inputValue)
          .onClick(() => {
            this.dialogController.open()
          }).backgroundColor(0x317aff)
      }.width('100%').margin({ top: 5 })
    }
  }
  ```

- 方式三：

  ```
  let storage = LocalStorage.GetShared()
  @CustomDialog
  struct CustomDialog03 {
    @LocalStorageLink('inputVal')  inputValue: string = ''
    controller: CustomDialogController
    build() {
      Column() {
        Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
        TextInput({ placeholder: '', text: this.inputValue }).height(60).width('90%')
          .onChange((value: string) => {
            this.inputValue = value;
          })
      }
    }
  }
  
  @Entry(storage)
  @Component
  struct DialogDemo03 {
    @LocalStorageLink('inputVal') inputValue: string = ''
    dialogController: CustomDialogController = new CustomDialogController({
      builder: CustomDialog03()
    })
  
    build() {
      Column() {
        Button(this.inputValue)
          .onClick(() => {
            this.dialogController.open()
          }).backgroundColor(0x317aff)
      }.width('100%').margin({ top: 5 })
    }
  }
  ```


## 如何获取组件的宽高(API 9)

**问题现象**

组件的宽高信息用于计算布局区域大小以及偏移量等内容，如何获取宽高信息？

**解决措施**

- 方式一：使用组件区域变化事件onAreaChange，在组件初始化或组件尺寸发生变化时触发。

- 方式二：在点击或触摸事件中，事件的回调信息中存在目标元素的区域信息。

**参考链接**

[组件区域变化事件](../reference/apis-arkui/arkui-ts/ts-universal-component-area-change-event.md)，[点击事件](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md)，[触摸事件](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md)


## 如何一键清空TextInput、TextArea组件内容(API 9)

**问题现象**

TextInput，TextArea组件输入多字符后，需要实现点击清空。

**解决措施**

将状态变量赋值给TextInput或TextArea组件的text属性，在做点击清空事件时为状态变量赋值空字符串。

**代码示例**

```
struct Index {
@State text: string = 'Hello World'
controller: TextInputController = new TextInputController()
  build() {
    Row() {
      Column() {
        TextInput({ placeholder: 'Please input your words.', text: this.text,
          controller:this.controller}).onChange((value) => {
            this.text = value
          })
        Button("Clear TextInput").onClick(() => {
          this.text = "";
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## 如何设置自定义弹窗位置(API 9)

**问题现象**

自定义弹窗当前默认在窗口居中显示，当自定义弹窗需要与窗口边框对齐是需要设置自定义弹窗的对齐方式。

**解决措施**

初始化自定义弹窗时，通过alignment参数设置对齐方式，通过offset设置弹窗偏移量。

**参考链接**

[自定义弹窗](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## 如何隐藏容器组件的溢出内容(API 9)

**问题现象**

当容器组件内容溢出时，表现为子组件边缘超出容器组件，需要进行隐藏设置。

**解决措施**

将通用属性-形状裁剪clip属性设置为true，表示按照容器边缘轮廓进行裁剪。此属性默认为false，表示不进行裁剪隐藏。

**参考链接**

[形状裁剪](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md)


## 自定义弹窗大小如何自适应内容(API 9)

**问题现象**

当自定义弹窗中存在可变化区域大小的子组件时，弹窗大小需要跟随自适应。

**解决措施**

- 方式一：采用弹窗容器默认样式。在默认样式中，弹窗容器高度自适应子节点，最大可为窗口高度的90%；弹窗容器的宽度根据栅格系统自适应，不跟随子节点变化。

- 方式二：当显示设置customStyle为true时，弹窗宽高跟随子节点内容适应。

**参考链接**

[自定义弹窗](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## 如何理解自定义弹窗中的gridCount参数(API 9)

gridCount参数是指弹窗宽度占栅格列数的个数。系统把窗口宽等分，等分的份数即为栅格列数，不同设备栅格列数不同。假设设备屏幕密度值在320vp&lt;=水平宽度&lt;600vp，所以栅格列数是4，则gridCount的有效值在[1, 4]。

注意：仅采用弹窗默认样式时设置有效。

**参考链接**

[自定义弹窗](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## 如何去除自定义弹窗的白色背景(API 9)

**问题现象**

使用自定义弹窗时，默认样式中存在白色背景。

**解决措施**

需要采用自定义样式来消除自定义弹窗的白色背景：

1. 在初始化自定义弹窗时设置customStyle为true。

2. 在定义弹窗时设置组件背景色backgroundColor。

**参考链接**

[自定义弹窗](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## TextInput组件密码模式下，右边的眼睛图标能否支持自定义(API 9)

**问题现象**

TextInput组件设置type为InputType.Password时，右侧出现眼睛图标，不能修改图标样式。

**解决措施**

当前图标不支持自定义，可使用TextInput的showPasswordIcon属性隐藏图标，使用Image组件替代控制TextInput组件的type。

**参考链接**

[TextInput组件](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)


## TextInput的onSubmit事件如何使用(API 9)

**问题现象**

TextInput的onSubmit事件怎么触发，以及事件回调的参数类型代表的含义。

**解决措施**

onSubmit事件在外接键盘或软键盘回车时触发该回调，回调的参数为当前软键盘回车键类型。通过TextInput的enterKeyType属性可以设置输入法回车键类型，软键盘回车键样式需要输入法的支持。

**参考链接**

[TextInput组件](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)


## TextInput在聚焦时如何使光标回到起点(API 9)

**问题现象**

TextInput组件在聚焦时，光标位置会自动根据触摸点位置变化，如何使得聚焦时光标固定显示在起点位置？

**解决措施**

1. TextInput组件绑定onEditChange事件，该事件TextInput可进行输入时触发。

2. 在事件回调用TextInputController.caretPosition方法设置光标位置，不过需要用到setTimeout延迟方法。

**代码示例**

```
@Entry
@Component
struct TextInputDemo {
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      TextInput({ controller: this.controller })
        .onEditChange((isEditing: boolean) => {
          if (isEditing) {
            setTimeout(() => {
              this.controller.caretPosition(0)
            }, 100)
          }
        })
    }
  }
}
```

**参考链接**

[TextInput组件](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)


## 如何获取可滚动组件的当前滚动偏移量(API 9)

**问题现象**

可滚动组件包含List，Grid，Scroll等，在发生滚动时如何获取滚动偏移量？

**解决措施**

1. 可滚动组件在初始化时可设置scroller参数，绑定滚动控制器。

2. 通过控制器的currentOffset方法可获取水平和竖直方向的滚动偏移量。

**参考链接**

[Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#currentoffset)


## 如何实现文本竖向排列(API 9)

**问题现象**

使用Text组件时，无法将文本排列方向设置为竖向排列。

**解决措施**

Text组件当前文本排列方向固定为横向排列，要设置为竖向排列，可将文件拆分，使用Flex容器组件装填，设置主轴方向为竖向。

**代码示例**

```
@Entry
@Component
struct Index15 {
  private message: string = '本文档适用于应用开发的初学者。通过构建一个简单的具有页面跳转/返回功能的应用，快速了解工程目录的主要文件，熟悉应用开发流程。';
  build() {
    Flex({ direction: FlexDirection.Column, wrap: FlexWrap.Wrap }) {
      ForEach(this.message.split(''), (item, index) => {
        Text(item)
          .fontSize(30)
          .flexShrink(0)
      })
    }
  }
}
```


## 如何将Ability的UI界面设置成透明(API 9)

**问题现象**

如何设置Ability的UI界面为透明

**解决措施**

将最上层容器组件背景色设置为透明，然后通过设置XComponent组件的opacity属性值为0.01来实现。

示例：

```
build() {
  Stack() {
    XComponent({
    id: 'componentId',
    type: 'surface',
    })
    .width('100%')
    .height('100%')
    .opacity(0.01)
    // 页面内容
  }
  .width('100%')
  .height('100%')
  .backgroundColor('rgba(255,255,255, 0)')
}
```


## constraintSize尺寸设置不生效(API 9)

适用于Stage模型。

**问题现象**

constraintSize约束组件尺寸时，子组件内设置百分比宽度，例如width('100%')会采用constraintSize约束中的最大宽乘百分比，导致撑开组件，看起来constraintSize设置没生效。

**解决措施**

可以在外层使用Scroll组件，设置constraintSize，当子组件占用空间超过设置的约束值时，会显示滚动条。


## 如何将背景颜色设置为透明(API 9)

**解决措施**

将backgroundColor设置为 '\#00000000'。


## Scroll组件滚动到达不了最底部(API 9)

适用于Stage模型。

**问题现象**

Scroll组件在未设置高度情况下，默认为窗口高度，当滚动区域外存在其他组件时，滚动底部区域会出现遮挡。

**解决措施**

Scroll组件需要设置Scroll高度，或者使用Flex布局限制Scroll高度。


## 如何自定义Video组件控制栏样式(API 9)

适用于Stage模型。

**解决措施**

1. 通过设置属性controls为false关闭默认控制栏。

2. 设置Video组件的controller。

3. 通过ArkTS实现自定义的控制栏，并通过VideoController控制视频播放。

**代码示例**

```
// xxx.ets
@Entry@Componentstruct VideoCreateComponent {
  @State videoSrc: Resource = $rawfile('video1.mp4')
  @State previewUri: Resource = $r('app.media.poster1')
  @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X
  @State isAutoPlay: boolean = false
  @State showControls: boolean = true
  controller: VideoController = new VideoController()
   build() {
    Column() {
      Video({
        src: this.videoSrc,
        previewUri: this.previewUri,
        currentProgressRate: this.curRate,
        controller: this.controller
      }).width('100%').height(600)
        .autoPlay(this.isAutoPlay)
        .controls(this.showControls)
        .onStart(() => {
          console.info('onStart')
        })
        .onPause(() => {
          console.info('onPause')
        })
        .onFinish(() => {
          console.info('onFinish')
        })
        .onError(() => {
          console.info('onError')
        })
        .onPrepared((e) => {
          console.info('onPrepared is ' + e.duration)
        })
        .onSeeking((e) => {
          console.info('onSeeking is ' + e.time)
        })
        .onSeeked((e) => {
          console.info('onSeeked is ' + e.time)
        })
        .onUpdate((e) => {
          console.info('onUpdate is ' + e.time)
        })
             Row() {
        Button('src').onClick(() => {
          this.videoSrc = $rawfile('video2.mp4') // 切换视频源
        }).margin(5)
        Button('previewUri').onClick(() => {
          this.previewUri = $r('app.media.poster2') // 切换视频预览海报
        }).margin(5)

        Button('controls').onClick(() => {
          this.showControls = !this.showControls // 切换是否显示视频控制栏
        }).margin(5)
      }
       Row() {
        Button('start').onClick(() => {
          this.controller.start() // 开始播放
        }).margin(5)
        Button('pause').onClick(() => {
          this.controller.pause() // 暂停播放
        }).margin(5)
        Button('stop').onClick(() => {
          this.controller.stop() // 结束播放
        }).margin(5)
        Button('setTime').onClick(() => {
          this.controller.setCurrentTime(10, SeekMode.Accurate) // 精准跳转到视频的10s位置
        }).margin(5)
      }
       Row() {
        Button('rate 0.75').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_0_75_X // 0.75倍速播放
        }).margin(5)
        Button('rate 1').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_1_00_X // 原倍速播放
        }).margin(5)
        Button('rate 2').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_2_00_X // 2倍速播放
        }).margin(5)
      }
    }
  }}
```

**参考链接**

[Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#start)

## 如何设置组件不同状态下的样式(API 9)

**问题现象**

对应组件的不同状态（如无状态、按下、禁用、聚焦、点击），显示不同的样式。

**解决措施**

使用多态样式，在组件的StateStyles接口中，定义组件不同状态下的样式。

**代码示例**

```
//xxx.ts
@Entry
@Component
struct StyleExample {
  @State isEnable: boolean = true;

  @Styles pressedStyles() {
    .backgroundColor("#ED6F21")
    .borderRadius(10)
    .borderStyle(BorderStyle.Dashed)
    .borderWidth(2)
    .borderColor('#33000000')
    .width(120)
    .height(30)
    .opacity(1)
  }
  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center}) {
      Text("pressed")
        .backgroundColor('#0A59F7')
        .borderRadius(20)
        .borderStyle(BorderStyle.Dotted)
        .borderWidth(2)
        .borderColor(Color.Red)
        .width(100)
        .height(25)
        .opacity(1)
        .fontSize(14)
        .fontColor(Color.White)
        .stateStyles({
          pressed: this.pressedStyles
        })
        .margin({
          bottom: 20
        })
        .textAlign(TextAlign.Center)
    }
    .width(350)
    .height(300)
  }
}
```

**参考链接**

[多态样式](../reference/apis-arkui/arkui-ts/ts-universal-attributes-polymorphic-style.md)

## Scroll内Flex加宽高与滑动冲突(API 9)

适用于Stage模型。

**问题现象**

当在Scroll组件中添加容器组件，并设置该容器组件的尺寸时，会破坏滚动布局。

**解决措施**

Scroll组件中的容器组件不设置尺寸，大小由内容撑开。


## 父组件中如何处理子组件内点击事件(API 9)

适用于Stage模型。

在父组件中初始化子组件时，将父组件中定义的方法，传递给子组件，在子组件中调用该方法，类似于变量传递。

**代码示例**

```
class Model {
  value: string
}
@Entry
@Component
struct EntryComponent {
  test() {
    console.log('testTag test in my component');
  }
  build() {
    Column() {
      MyComponent({ title: { value: 'Hello World 2' }, count: 7, onClick: this.test }) //初始化时传递定义的方法
    }
  }
}

@Component
struct MyComponent {
  @State title: Model = { value: 'Hello World' }
  @State count: number = 0
  onClick: any;
  private toggle: string = 'Hello World'
  private increaseBy: number = 1

  build() {
    Column() {
      Text(`${this.title.value}`).fontSize(30)
      Button(`Click to increase count=${this.count}`)
        .margin(20)
        .onClick(() => {
          // 修改内部状态变量count
          this.count += this.increaseBy
          this.onClick.call();
        })
    }
  }
}
```


## 如何主动拉起软键盘(API 9)

**解决措施**

可以通过focusControl.requestFocus控制输入框获焦，组件获焦后会自动弹起软键盘

**参考链接**

焦点控制：[焦点控制](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md)


## SideBarContainer如何设置controlButton属性(API 9)

**解决措施**

示例代码：

```
@Entry
@Component
struct SideBarContainerExample {
  normalIcon : Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer(SideBarContainerType.Embed)
    {
      Column() {
        ForEach(this.arr, (item, index) => {
          Column({ space: 5 }) {
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)
            Text("Index0" + item)
              .fontSize(25)
              .fontColor(this.current === item ? '#0A59F7' : '#999')
              .fontFamily('source-sans-pro,cursive,sans-serif')
          }
          .onClick(() => {
            this.current = item
          })
        }, item => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor('#19000000')


      Column() {
        Text('SideBarContainer content text1').fontSize(25)
        Text('SideBarContainer content text2').fontSize(25)
      }
      .margin({ top: 50, left: 20, right: 30 })
    }
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .controlButton({left:32,
      top:32,
      width:32,
      height:32, 
      icons:{shown: $r("app.media.icon"),
        hidden: $r("app.media.icon"),
        switching: $r("app.media.icon")}})
    .maxSideBarWidth(300)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
  }
}
```

## 如何实现主动控制组件刷新(API 10)

**解决措施**

Canvas组件最终的显示内容分两种，一种是组件通用属性的绘制内容，比如背景色，boarder等这类组件属性方法设置的渲染属性，这类属性是可以通过状态变量驱动更新的。
另一种是通过CanvasRenderingContext2D绘制接口由应用自行绘制的内容。该类命令时绘制接口不响应状态变量，该类接口内置表脏功能，只要调用就会在下一帧刷新绘制内容，不需要开发者显式刷新。

**参考链接**

[CanvasRenderingContext2D](../reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md)

## 怎么解决列表组件List在不设置高度的情况下，会出现滑动不到底的问题(API 10)

**原因分析**

List没有设置高度时，如果子组件总高度大于List父组件的高度时，List会取List父组件高度。如果List有其他兄弟节点，可能会吧List部分顶出父组件显示区域外，看起来像是划不到底部。

**解决措施**

List组件设置layoutWeight(1)属性，将剩余空间全部分配给List组件。

**参考链接**

[尺寸设置](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md)

## 如何实现瀑布流滑动时，数据的无限加载和显示(API 10)

**解决措施**

1.使用LazyForEach做瀑布流子节点。

2.参考WaterFlow高性能开发指导在FlowItem的onAppear中判断是否即将触底，提前在LazyForEach数据源尾部新增数据；或在onScrollIndex11+事件中根据当前index进行判断。

**参考链接**

[WaterFlow高性能开发指导](../performance/waterflow_optimization.md)

## customDialog中调用router.push启动新页面，会把customDialog关闭，怎么实现在不关闭弹窗的前提下启动新页面(API 10)

**解决措施**

开发者在路由跳转时，需要获取到主窗口的uiContext，再调用路由跳转。

**参考链接**

[自定义弹窗](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)

## 当前ArkUI-X的支持进展如何，有无明确路线图(API 10)

**解决措施**

1.进展：ArkUI-X当前已经开源，首版本已于2023-12-15正式发布，当前支持Android、iOS跨平台；另外，也在探索和试验桌面平台与Web平台的支持。

2.[路线图](https://gitee.com/arkui-x/docs/blob/master/zh-cn/roadmap/ArkUI-X-roadmap-2023.md)。

**参考链接**

[ArkUI-X](https://gitee.com/arkui-x)

## 应用如何在自定义组件的构建流程里跟踪组件数据或者状态(API 10)

**问题现象**

UI的构建build方法内无法插入日志，导致应用无法感知UI绘制流程，不利于调试UI，定位UI问题。  

**解决措施**

使用@Watch回调来监测状态变量的变化，如果执行回调函数，说明在下一次vysnc信号发送时，使用该状态变量的UI会刷新绘制。

示例代码如下：

```ts
@Prop @Watch('onCountUpdated') count: number = 0; 
@State total: number = 0; 
// @Watch 回调 
onCountUpdated(propName: string): void {
  this.total += this.count; 
}
```

**参考链接**

[@Watch装饰器：状态变量更改通知](../ui/state-management/arkts-watch.md)

## 自定义component不支持继承语法，针对其他框架支持的自定义组件继承及封装能力，ArkUI的解决方案是什么(API 10)

**解决措施**

对于声明式的自定义组件场景，不会提供继承的能力，需要使用组合的方式进行扩展，并结合后续提供的Modifier机制进行对现有组件属性的继承、复用和传递。

## 组件支持的参数类型及参数单位类型区别是什么，使用场景是什么(API 10)

**解决措施**

屏幕像素单位px(pixel)，表示屏幕上的实际像素，1px代表设备屏幕上的一个像素点。视窗逻辑像素单位lpx，lpx单位为实际屏幕宽度与逻辑宽度（通过designWidth配置）的比值，标识页面设计基准宽度。以此为基准，根据实际设备宽度来缩放元素大小。距离使用vp(virtual pixel)，字体大小使用fp(font pixel)，虚拟像素单位vp(virtual pixel)，vp具体计算公式为：vp= px/（DPI/160）。  
以屏幕相对像素为单位, 是一台设备针对应用而言所具有的虚拟尺寸（区别于屏幕硬件本身的像素单位）。它提供了一种灵活的方式来适应不同屏幕密度的显示效果,使用虚拟像素，使元素在不同密度的设备上具有一致的视觉体量。字体像素单位fp(font pixel)，字体像素(font pixel)大小默认情况下与vp相同，即默认情况下1fp=1vp。如果用户在设置中选择了更大的字体，字体的实际显示大小就会在vp的基础上乘以scale系数，即1fp=1vp*scale。Percentage - 需要指定以%像素单位，如'10%'。  
Resource - 资源引用类型，引入系统资源或者应用资源中的尺寸。 

## Surface模式下的XComponent组件在设置RenderFit后如果出现显示异常，该如何调整获取正确的显示效果(API 10)

**背景介绍**

系统芯片平台侧除通用的CPU/GPU计算单元外，还提供了Hardware Composer（简称HWC）专用硬件合成器用于图形合成送显。与通用计算单元相比，HWC在图层叠加场景中具有更高的处理效率和更低的能耗。Surface模式下的XComponent组件所产生的图形数据是否能进入HWC硬件合成通道处理，受芯片平台能力、产品形态以及应用绘制行为等多个因素影响。

**解决措施**

当Surface模式下的XComponent组件其内容与组件尺寸不一致时，可通过设置[renderFit](../reference/apis-arkui/arkui-ts/ts-universal-attributes-renderfit.md#renderfit18)属性，以调整绘制内容在组件尺寸范围内的布局方式，例如拉伸、居中、等比缩放等。
在API version 18之前，若要使用HWC硬件合成通道（当XComponent组件的背景色设置为纯黑不透明时，可能会进入HWC硬件合成通道，实际走进与否取决于前述因素），组件的[renderFit](../reference/apis-arkui/arkui-ts/ts-universal-attributes-renderfit.md#renderfit18)属性仅能支持设置为RenderFit.RESIZE_FILL，如果设置为其他属性值可能会导致显示异常。如果确实需要设置为RenderFit.RESIZE_FILL外的属性值，可以通过升级至API version 18或在XComponent组件的id字段中包含"RenderFitSurface"来修正显示效果(在API version 18前)。

示例代码如下：

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State xc_width: number = 500;
  @State xc_height: number = 700;
  myXComponentController: XComponentController = new XComponentController();

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Start }) {
      XComponent({
        id: 'myXComponent_RenderFitSurface', // 当id的字符串中包含"RenderFitSurface"时，可以使RenderFit显示正确。
        type: XComponentType.SURFACE,
        controller: this.myXComponentController
      })
        .width(this.xc_width)
        .height(this.xc_height)
        .renderFit(RenderFit.CENTER)
    }
    .width('100%')
    .height('100%')
  }
}

```