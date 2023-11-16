# ArkUI组件开发常见问题(ArkTS)


## 自定义弹窗能否在ts文件中定义和使用(API 9)

自定义弹窗的定义和初始化需要用到属于ArkTS语法内容，必须在ets后缀文件中定义使用，不能在ts后缀文件中定义使用。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)


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

[组件区域变化事件](../reference/arkui-ts/ts-universal-component-area-change-event.md)，[点击事件](../reference/arkui-ts/ts-universal-events-click.md)，[触摸事件](../reference/arkui-ts/ts-universal-events-touch.md)


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

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)


## 如何隐藏容器组件的溢出内容(API 9)

**问题现象**

当容器组件内容溢出时，表现为子组件边缘超出容器组件，需要进行隐藏设置。

**解决措施**

将通用属性-形状裁剪clip属性设置为true，表示按照容器边缘轮廓进行裁剪。此属性默认为false，表示不进行裁剪隐藏。

**参考链接**

[形状裁剪](../reference/arkui-ts/ts-universal-attributes-sharp-clipping.md)


## 自定义弹窗大小如何自适应内容(API 9)

**问题现象**

当自定义弹窗中存在可变化区域大小的子组件时，弹窗大小需要跟随自适应。

**解决措施**

- 方式一：采用弹窗容器默认样式。在默认样式中，弹窗容器高度自适应子节点，最大可为窗口高度的90%；弹窗容器的宽度根据栅格系统自适应，不跟随子节点变化。

- 方式二：当显示设置customStyle为true时，弹窗宽高跟随子节点内容适应。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)


## 如何理解自定义弹窗中的gridCount参数(API 9)

gridCount参数是指弹窗宽度占栅格列数的个数。系统把窗口宽等分，等分的份数即为栅格列数，不同设备栅格列数不同。假设设备屏幕密度值在320vp&lt;=水平宽度&lt;600vp，所以栅格列数是4，则gridCount的有效值在[1, 4]。

注意：仅采用弹窗默认样式时设置有效。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)


## 如何去除自定义弹窗的白色背景(API 9)

**问题现象**

使用自定义弹窗时，默认样式中存在白色背景。

**解决措施**

需要采用自定义样式来消除自定义弹窗的白色背景：

1. 在初始化自定义弹窗时设置customStyle为true。

2. 在定义弹窗时设置组件背景色backgroundColor。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)


## TextInput组件密码模式下，右边的眼睛图标能否支持自定义(API 9)

**问题现象**

TextInput组件设置type为InputType.Password时，右侧出现眼睛图标，不能修改图标样式。

**解决措施**

当前图标不支持自定义，可使用TextInput的showPasswordIcon属性隐藏图标，使用Image组件替代控制TextInput组件的type。

**参考链接**

[TextInput组件](../reference/arkui-ts/ts-basic-components-textinput.md)


## TextInput的onSubmit事件如何使用(API 9)

**问题现象**

TextInput的onSubmit事件怎么触发，以及事件回调的参数类型代表的含义。

**解决措施**

onSubmit事件在外接键盘或软键盘回车时触发该回调，回调的参数为当前软键盘回车键类型。通过TextInput的enterKeyType属性可以设置输入法回车键类型，软键盘回车键样式需要输入法的支持。

**参考链接**

[TextInput组件](../reference/arkui-ts/ts-basic-components-textinput.md)


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

[TextInput组件](../reference/arkui-ts/ts-basic-components-textinput.md)


## 如何获取可滚动组件的当前滚动偏移量(API 9)

**问题现象**

可滚动组件包含List，Grid，Scroll等，在发生滚动时如何获取滚动偏移量？

**解决措施**

1. 可滚动组件在初始化时可设置scroller参数，绑定滚动控制器。

2. 通过控制器的currentOffset方法可获取水平和竖直方向的滚动偏移量。

**参考链接**

[Scroll](../reference/arkui-ts/ts-container-scroll.md#currentoffset)


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

[Video](../reference/arkui-ts/ts-media-components-video.md#start)

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

[多态样式](../reference/arkui-ts/ts-universal-attributes-polymorphic-style.md)

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

焦点控制：[焦点控制](../reference/arkui-ts/ts-universal-attributes-focus.md)


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
