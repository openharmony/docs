# ArkUI框架开发常见问题

## 如何动态替换掉资源文件中的“%s”占位符

适用于OpenHarmony 3.2 Beta5  API 9

**问题现象**

引用String资源，如何动态替换资源文件中的“%s”占位符。

**解决措施**

在应用中，通过`$r('app.string.xx')`的形式引用应用资源，\$r的第二个参数可用于替换%s占位符。

**代码示例**

```
build() {
  //do something
  //引用的string资源,$r的第二个参数用于替换%s
  Text($r('app.string.entry_desc','aaa')) 
    .fontSize(100)
    .fontColor(Color.Black)
  //do something
}
```

## 自定义弹窗能否在ts文件中定义和使用

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

自定义弹窗的定义和初始化需要用到属于ArkTS语法内容，必须在ets后缀文件中定义使用，不能在ts后缀文件中定义使用。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## 自定义弹窗中的变量如何传递给页面

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

在自定义弹窗内定义的变量内容，在关闭弹窗或变量变化时需要及时传递给页面，可以通过何种方式传递？

**解决措施**

-   方式一：使用组件的状态变量传递。
-   方式二：在初始化弹窗时，传递一个方法给自定义弹窗，在自定义弹窗中触发该方法，弹窗中变量作为方法的参数。
-   方式三：使用AppStorage或LocalStorage方式管理页面状态，实现自定义弹窗和页面之间状态的共享。

**代码示例**

-   方式一：

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

-   方式二：

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

-   方式三：

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


## 如何获取组件的宽高

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

组件的宽高信息用于计算布局区域大小以及偏移量等内容，如何获取宽高信息？

**解决措施**

-   方式一：使用组件区域变化事件onAreaChange，在组件初始化或组件尺寸发生变化时触发。
-   方式二：在点击或触摸事件中，事件的回调信息中存在目标元素的区域信息。

**参考链接**

[组件区域变化事件](../reference/arkui-ts/ts-universal-component-area-change-event.md)，[点击事件](../reference/arkui-ts/ts-universal-events-click.md)，[触摸事件](../reference/arkui-ts/ts-universal-events-touch.md)

## 如何一键清空TextInput、TextArea组件内容

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

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

## 如何设置自定义弹窗位置

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

自定义弹窗当前默认在窗口居中显示，当自定义弹窗需要与窗口边框对齐是需要设置自定义弹窗的对齐方式。

**解决措施**

初始化自定义弹窗时，通过alignment参数设置对齐方式，通过offset设置弹窗偏移量。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## 如何隐藏容器组件的溢出内容

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

当容器组件内容溢出时，表现为子组件边缘超出容器组件，需要进行隐藏设置。

**解决措施**

将通用属性-形状裁剪clip属性设置为true，表示按照容器边缘轮廓进行裁剪。此属性默认为false，表示不进行裁剪隐藏。

**参考链接**

[形状裁剪](../reference/arkui-ts/ts-universal-attributes-sharp-clipping.md)


## 自定义弹窗大小如何自适应内容

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

当自定义弹窗中存在可变化区域大小的子组件时，弹窗大小需要跟随自适应。

**解决措施**

-   方式一：采用弹窗容器默认样式。在默认样式中，弹窗容器高度自适应子节点，最大可为窗口高度的90%；弹窗容器的宽度根据栅格系统自适应，不跟随子节点变化。
-   方式二：当显示设置customStyle为true时，弹窗宽高跟随子节点内容适应。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## 如何理解自定义弹窗中的gridCount参数

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

gridCount参数是指弹窗宽度占栅格列数的个数。系统把窗口宽等分，等分的份数即为栅格列数，不同设备栅格列数不同。假设设备屏幕密度值在320vp<=水平宽度<600vp，所以栅格列数是4，则gridCount的有效值在\[1, 4\]。

注意：仅采用弹窗默认样式时设置有效。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## 如何去除自定义弹窗的白色背景

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

使用自定义弹窗时，默认样式中存在白色背景。

**解决措施**

需要采用自定义样式来消除自定义弹窗的白色背景：

1.  在初始化自定义弹窗时设置customStyle为true。
2.  在定义弹窗时设置组件背景色backgroundColor。

**参考链接**

[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## TextInput组件密码模式下，右边的眼睛图标能否支持自定义

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

TextInput组件设置type为InputType.Password时，右侧出现眼睛图标，不能修改图标样式。

**解决措施**

当前图标不支持自定义，可使用TextInput的showPasswordIcon属性隐藏图标，使用Image组件替代控制TextInput组件的type。

**参考链接**

[TextInput组件](../reference/arkui-ts/ts-basic-components-textinput.md)

## TextInput的onSubmit事件如何使用

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

TextInput的onSubmit事件怎么触发，以及事件回调的参数类型代表的含义。

**解决措施**

onSubmit事件在外接键盘或软键盘回车时触发该回调，回调的参数为当前软键盘回车键类型。通过TextInput的enterKeyType属性可以设置输入法回车键类型，软键盘回车键样式需要输入法的支持。

**参考链接**

[TextInput组件](../reference/arkui-ts/ts-basic-components-textinput.md)

## TextInput在聚焦时如何使光标回到起点

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

TextInput组件在聚焦时，光标位置会自动根据触摸点位置变化，如何使得聚焦时光标固定显示在起点位置？

**解决措施**

1.  TextInput组件绑定onEditChange事件，该事件TextInput可进行输入时触发。
2.  在事件回调用TextInputController.caretPosition方法设置光标位置，不过需要用到setTimeout延迟方法。

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

## 如何获取组件的属性信息

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**解决措施**

组件所有属性信息可通过通用属性-组件标识内getInspectorByKey获取。

**参考链接**

[组件标识](../reference/arkui-ts/ts-universal-attributes-component-id.md)

## 如何获取可滚动组件的当前滚动偏移量

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

可滚动组件包含List，Grid，Scroll等，在发生滚动时如何获取滚动偏移量？

**解决措施**

1.  可滚动组件在初始化时可设置scroller参数，绑定滚动控制器。
2.  通过控制器的currentOffset方法可获取水平和竖直方向的滚动偏移量。

**参考链接**

[Scroll](../reference/arkui-ts/ts-container-scroll.md#currentoffset)

## 如何实现文本竖向排列

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

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

## 如何创建Toast窗口

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

应用做弱提示时，需要采用Toast窗口。

**解决措施**

可使用系统提供的@ohos.promptAction接口创建Toast窗口。

**参考链接**

[@ohos.promptAction \(弹窗\)](../reference/apis/js-apis-promptAction.md)

## Toast弹窗是否支持自定义背景或者字体颜色

适用于 OpenHarmony 3.2 Beta5 API 9 Stage模型

当前版本不支持Toast弹窗自定义背景和字体颜色。

**参考链接**

[@ohos.promptAction \(弹窗\)](../reference/apis/js-apis-promptAction.md)

## 如何将Ability的UI界面设置成透明 

适用于：OpenHarmony SDK 3.2，API9

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

## constraintSize尺寸设置不生效

适用于：Openharmony 3.2 Beta5 API 9 stage模型

**问题现象**

constraintSize约束组件尺寸时，子组件内设置百分比宽度，例如width\('100%'\)会采用constraintSize约束中的最大宽乘百分比，导致撑开组件，看起来constraintSize设置没生效。

**解决措施**

可以在外层使用Scroll组件，设置constraintSize，当子组件占用空间超过设置的约束值时，会显示滚动条。

## 如何将背景颜色设置为透明

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

将backgroundColor设置为 '\#00000000'。

## Scroll组件滚动到达不了最底部

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

Scroll组件在未设置高度情况下，默认为窗口高度，当滚动区域外存在其他组件时，滚动底部区域会出现遮挡。

**解决措施**

Scroll组件需要设置Scroll高度，或者使用Flex布局限制Scroll高度。

## backgroundImage如何设置CenterCrop

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

CenterCrop是android中imageView,scaletype的设置，主要保证图片等比缩放裁剪，位置保持居中，要达到相同效果，应该怎么处理？

**解决措施**

可以使用通用属性backgroundImageSize\(ImageSize.cover\)和backgroundImagePosition\(Alignment.Center\)达到相同效果。

## 如何自定义Video组件控制栏样式

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

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

## 如何设置组件不同状态下的样式

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

## Scroll内Flex加宽高与滑动冲突

适用于：OpenHarmony 3.2 Beta5 API 9 Stage模型

**问题现象**

当在Scroll组件中添加容器组件，并设置该容器组件的尺寸时，会破坏滚动布局。

**解决措施**

Scroll组件中的容器组件不设置尺寸，大小由内容撑开。

## ArkTS使用position之后height不生效

适用于 OpenHarmony 3.2 Beta5  API 9

**问题现象**

ArkTS使用position之后height不生效

**解决措施**

容器组件在使用position之后会脱离文本流，导致容器脱离外层容器束缚，导致height不生效，可以将外层容器换成Stack可以解决这个问题。

## 焦点事件onBlur/onFocus回调无法触发

适用于 OpenHarmony 3.2 Beta5  API 9

**问题现象**

焦点事件onBlur/onFocus回调无法触发

**解决措施**

焦点事件默认情况下需要外接键盘的Tab键，或方向键触发，点击触发焦点事件需要添加焦点控制属性focusOnTouch。

**参考链接**

[焦点控制](../reference/arkui-ts/ts-universal-attributes-focus.md)

## scroll里面套一个grid，怎么禁用grid的滑动事件

适用于 OpenHarmony 3.2 Beta5 API 9

可以通过onScrollFrameBegin事件和scrollBy方法实现容器嵌套滚动。

可参考：[容器嵌套滚动样例](../reference/arkui-ts/ts-container-scroll.md#示例2)

## 如何实现一个组件不停地旋转

适用于 OpenHarmony 3.2 Beta5  API 9

可以通过[属性动画](../reference/arkui-ts/ts-animatorproperty.md)的方式实现。

## 列表目前无法键盘上下滑动，是否能力不支持

适用于 OpenHarmony 3.2 Beta5  API 9

**问题现象**

列表目前无法键盘上下滑动，是否能力不支持

**解决措施**

有以下两种方案：

1.  需要在列表子项中添加focusable\(true\)进行获焦。
2.  在每个item的外层嵌套一个可获焦组件，例如Button。

## 键盘移动焦点对象按下enter，为什么不会触发点击事件？

适用于 OpenHarmony 3.2 Beta5  API 9

组件的内置的点击事件和开发者自定义的onClick点击事件默认会和空格键绑定，并非与enter键绑定（UX规格）

## 多层组件嵌套button，如何阻止事件传递

适用于 OpenHarmony 3.2 Beta5  API 9

可以通过将button组件绑定参数stopPropagation来控制冒泡传递。

## ArkUI如何通过代码动态创建组件

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

ArkUI使用ArkTS声明式开发范式，开发者无法持有组件实例，在声明时通过渲染控制语法以及动态构建UI元素的方式，控制组件的创建。

**代码示例**

```
// 条件渲染语句创建组件
if(this.isTrue) {
  Text("创建文本组件").fontSize(30)
}
// 循环渲染语句创建组件
ForEach(this.nums,(item) => {
  Text(item + '').fontSize(30)
},item => JSON.stringify(item))
```

**参考链接**

[渲染控制语法](../quick-start/arkts-rendering-control-overview.md)

## 使用@Builder装饰器包含自定义组件的方法与普通方法的区别是什么

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

@Builder装饰的方法中使用了自定义组件，那么该方法每次被调用时，对应的自定义组件均会重新创建，普通方法中不使用@builder装饰，无法容纳自定义组件。

**参考链接**

[@BuilderParam](../quick-start/arkts-builderparam.md)

## 如何使用@BuilderParam装饰器进行组件传参

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

-   不带参数

    对@BuilderParam修饰的属性进行赋值时不带参数（如：content: this.specificParam），则此属性的类型需定义成无返回值的函数（如：@BuilderParam content: \(\) =\> void）。

-   带参数

    对@BuilderParam修饰的属性进行赋值时带参数（如：callContent: this.specificParam1\("111"\)），则此属性的类型需定义成any（如：@BuilderParam callContent: any）。


**参考链接**

[@BuilderParam](../quick-start/arkts-builderparam.md)

## 如何监听数组内对象属性变化

适用于：OpenHarmony 3.2 Beta5 API9 

**问题现象**

数组内存储对象示例，需要对对象的属性变化进行监听。

**解决措施**

通过@Observed配合@ObjectLink装饰符实现。@Observed用于类，@ObjectLink用于变量。

**代码示例**

1.  在类上使用@Observed。

    ```
    @Observed
    class ClassA {
      public name: string
      public c: number
      public id: number
    
      constructor(c: number, name: string = 'OK') {
        this.name = name
        this.c = c
      }
    }
    ```

2.  在组件变量使用@ObjectLink。

    ```
    @Component
    struct ViewA {
      label: string = 'ViewA1'
      @ObjectLink a: ClassA
    
      build() {
        Row() {
          Button(`ViewA [${this.label}] this.a.c= ${this.a.c} +1`)
            .onClick(() => {
              this.a.c += 1
            })
        }.margin({ top: 10 })
      }
    }
    ```


**参考链接**

[Observed和ObjectLink数据管理](../quick-start/arkts-observed-and-objectlink.md)

## 子组件使用@Link修饰成员变量时，如何通过父组件传值

适用于：OpenHarmony 3.2 Beta5 API 9 

**解决措施**

子组件使用@Link接受父组件的值时，需要使用'\$'建立变量之间的引用关系。才能实现同步。

**代码示例**

@Link语义是从`$`操作符引出，即\$isPlaying是this.isPlaying内部状态的双向数据绑定。当单击子组件PlayButton中的按钮时，@Link变量更改，PlayButton与父组件中的Text和Button将同时进行刷新，同样地，当点击父组件中的Button修改this.isPlaying时，子组件PlayButton与父组件中的Text和Button也将同时刷新。

1.  在父组件使用@State装饰器，传递数据使用\$符创建引用。

    ```
    @Entry
    @Component
    struct Player {
      @State isPlaying: boolean = false
      build() {
        Column() {
          PlayButton({ buttonPlaying: $isPlaying })
          Text(`Player is ${this.isPlaying ? '' : 'not'} playing`).fontSize(18)
          Button('Parent:' + this.isPlaying)
            .margin(15)
            .onClick(() => {
              this.isPlaying = !this.isPlaying
            })
        }
      }
    }
    
    
    ```

2.  在子组件使用@Link接受数据。

    ```
    @Component
    struct PlayButton {
      @Link buttonPlaying: boolean
    
      build() {
        Column() {
          Button(this.buttonPlaying ? 'pause' : 'play')
            .margin(20)
            .onClick(() => {
              this.buttonPlaying = !this.buttonPlaying
            })
        }
      }
    }
    ```


**参考链接**

[@Link](../quick-start/arkts-link.md)

## 父组件如何与孙子组件进行状态同步

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

-   方式一（推荐）：使用@Provide和@Consume装饰器。在父组件使用@Provide，在孙子组件使用@Consume，可以实现父组件和孙子组件进行双向数据绑定。

-   方式二：使用@State和@Link装饰器。在父组件使用@State，在每一层子组件（子组件和孙子组件）都使用@Link。

**代码示例一**

1.  父组件中使用子组件，通过Provide提供reviewVote参数，供跨级传递给孙子组件。

    ```
    @Entry
    @Component
    struct Father{
      @Provide("reviewVote") reviewVotes: number = 0;
    
      build() {
        Column() {
          Son()
          Button(`Father: ${this.reviewVotes}`)
            ...
        }
      }
    }
    ```

2.  子组件中使用孙组件。

    ```
    @Component
    struct Son{
      build() {
        Column() {
          GrandSon()
        }
      }
    }
    ```

3.  孙子组件中使用Consume来接受reviewVote的参数。

    ```
    @Component
    struct GrandSon{
      @Consume("reviewVote") reviewVotes: number
    
      build() {
        Column() {
          Button(`GrandSon: ${this.reviewVotes}`)
            ...
        }.width('100%')
      }
    }
    ```


**代码示例二**

1.  父组件Father使用@State绑定数据reviewVote。

    ```
    @Entry
    @Component
    struct Father {
      @State reviewVotes: number = 0;
    
      build() {
        Column() {
          Son({reviewVotes:$reviewVotes})
          Button(`Father: ${this.reviewVotes}`)
            ...
        }
      }
    }
    ```

2.  子组件Son中使用@Link接受由父组件Father传递的参数reviewVote。

    ```
    @Component
    struct Son{
      @Link reviewVotes: number;
      build() {
        Column() {
          Grandson({reviewVotes:$reviewVotes})
        }
      }
    }
    
    
    ```

3.  孙子组件GrandSon使用@Link接受由Son组件传递的参数reviewVote。

    ```
    @Component
    struct Grandson{
      @Link reviewVotes: number;
    
      build() {
        Column() {
          Button(`Grandson: ${this.reviewVotes}`)
            ...
        }.width('100%')
      }
    }
    ```


## Js如何定义callback函数

适用于：OpenHarmony 3.2 Beta5 API 9 

**解决措施**

定义个callback函数的样例，**示例如下：**

1.  定义回调函数

    ```
    // 页面中定义个2个参数,空返回的callback函数
    myCallback: (a:number,b:string) => void
    ```

2.  在使用时进行初始化赋值

    ```
    aboutToAppear() {
      // callback函数初始化
      this.myCallback= (a,b)=>{
        console.info(`handle myCallback a=${a},b=${b}`)
      }}
    ```


## 组件需要多次更新时如何优化性能

适用于：OpenHarmony 3.2 Beta5 API 9 

**解决措施**

使用状态管理模块，目前已经支持最小化更新，当数据依赖变化时，不再是重新刷新整个自定义组件，而是只更新依赖数据的视图内容。

## 对象中函数的this如何指向外层

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过箭头函数实现。

**代码示例**

```
const obj = {
  start:() => {
    return this.num
  }
}
```

## 如何实现页面加载前从接口获取数据

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

页面生命周期相关问题，在页面渲染前从接口获取数据，渲染时将数据渲染到页面上。

**解决措施**

在声明周期函数aboutToAppear中使用异步接口获取页面数据，数据变量使用@State修饰，数据获取完成后根据变量自动刷新页面。

**代码示例**

```
@Entry
@Component
struct Test6Page {
  // 数据获取成功，会自动刷新页面
  @State message: string = 'loading.....'
  aboutToAppear(){
    // 模拟异步接口获取数据
    setTimeout(()=>{
      this.message = 'new msg'
    },3000)
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Stage模型资源配置文件string.json是否支持配置占位符

适用于：Openharmony 3.2 Beta5 API 9

资源配置文件string.json文件本身不支持配置占位符，可以在对应的页面中通过定义变量，在实际组件使用Resources和变量拼接的方式达到实现占位符的同等效果。

## eTS文件和ts文件的区别

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

ArkTS基于兼容了TS语法，继承了TS的所有特性，当前，ArkTS在TS的基础上主要扩展了声明式UI能力，让开发者能够以更简洁、更自然的方式开发高性能应用。推荐用ArtTS开发UI相关内容，TS可以用来开发业务逻辑相关内容。

**参考链接**

[初识ArkTS](../quick-start/arkts-get-started.md)

## ArkTS如何发送邮箱验证码

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

ArkTS语言如何给邮箱发送邮箱验证码？用哪个接口？

**解决措施**

发送验证码需要请求服务端，然后服务端调用对应的短信验证码接口来实现该功能。可以通过短信服务实现相关功能。

## 如何将传感器的数据实时显示在UI的Text中

适用于：Openharmony 3.2 Beta5 API9

**问题现象**

ArkUI（ets）如何将传感器的数据实时显示在UI的Text中。

**解决措施**

传感器返回数据类型为double，可将double转为string，再显示在text中。

## 如何监听屏幕旋转

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

应用想监听屏幕是否进行旋转操作。

**解决措施**

屏幕旋转可使用媒体查询接口进行监听。

```
import mediaquery from '@ohos.mediaquery'
let listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件
function onPortrait(mediaQueryResult) {
  if (mediaQueryResult.matches) {
   // do something here
  } else {
   // do something here
  }
}
listener.on('change', onPortrait) // 注册回调
listener.off('change', onPortrait) // 去注册回调
```

**参考链接**

[媒体查询](../reference/apis/js-apis-mediaquery.md)

## DevEco Studio 升级到最新后ForEach不能遍历全部数据

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

升级DevEco Studio后，ForEach无法遍历全部数据。

**解决措施**

forEach\(\)功能进行了增强，其第三个参数keyGenerator如果传入参数时，需要确保数据源array中的每个元素生成的key不同，才能正常遍历。如果生成的key相同，则只能生成一个。

该第三个参数也可以不传，系统采用默认生成方式，也可以正常遍历出全部元素。

## 创建的单例换了页面后不生效问题

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

单例只有在同一个流程中才有效，换了页面后之前的实例都全是undefined。

**解决措施**

对于每个Page都会生成一个js文件，定义的单例会在每个js中都生成一份，所以单例的作用范围只是Page的范围。

如果想共享一个实例，创建范围需要提升至UIAbility或者App级别。

## 如何将时间格式的字符串string转换为Date对象

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

如果字符string满足格式“yyyy-MM-dd”格式，则可直接使用函数new Date\("yyyy-MM-dd"\)来获取对应的Date对象。

```
new Date("2021-05-23");
new Date("2020/2/29");
new Date("2020-14-03");
new Date("14-02-2021");
```

其他格式字符串可使用new Date\(year:number,month:number,day?:number,hour?:number,mintue?:number,second?:number,ms?:number\)方法来获取Date对象。

```
根据参数创建日期的语法：
new Date(yearValue, IndexOfMonth, dayValue, hours, minutes, seconds)
```

其中每一个参数换算为对应时间参数传入即可。

-   yearValue：应符合 ISO 8061 YYYY 格式。例如 2021。如果我们以 YY 格式指定一个值，它将会被错误地接受。例如，仅将 2021 提到 21 会被认为是 1921 年而不是 2021 年。
-   IndexOfMonth：从索引 0 开始。因此，从 Month 值中减去 1。例如，对于 3 月，该值为 3，但 monthIndex 将为 2（即 3-1 = 2）。本月指数通常应在 0-11 范围内
-   dayValue：表示一个月中的某天。它应在 1-31 范围内，具体取决于一个月中的天数。例如：对于 21-05-2021，日期值为 21
-   hours：一天中的小时。例如 10 点。
-   minutes：过去一个小时的分钟数
-   seconds：保留超过一分钟的秒数。

## ArkTS如何把string转为byte数组

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

参考如下代码实现，示例：

```
stringToArray(str:string) {
  var arr = [];
  for(var i = 0,j = str.length;i<j;++i) {
 arr.push(str.charCodeAt(i))
  }
  return arr;
}
```

## ArkTS如何实现字符串编解码

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过util工具函数模块中的TextEncoder和TextDecoder进行解码。

**参考链接**

[TextEncoder](../reference/apis/js-apis-util.md#textencoder)、[TextDecoder](../reference/apis/js-apis-util.md#textdecoder)

## 如何导入和导出namespace命名空间

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过export和import导入导出

-   namespace导数据库出

    ```
    namespace Util{
        export function getTime(){
            return Date.now()
        }
    }
    export default Util
    ```

-   namespace导入

    ```
    import Util from './util'
    Util.getTime()
    ```


## worker线程中能否进行关系型数据库的操作

适用于：Openharmony 3.2 Beta5 API 9

当前不支持将UI主线程中的rdb数据库对象发送给Worker线程后进行操作。Worker线程中使用rdb数据库，需要重新获取rdb数据库的对象。

## 如何获取应用resource目录下的文件

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

-   方式一：使用\$r或者\$rawfile访问。适合静态访问，程序运行时不改变资源路径。
-   方式二：使用ResourceManage访问。适合动态访问，程序运行时可动态改变资源路径。

**参考链接**

[资源访问](../quick-start/resource-categories-and-access.md)与[资源管理](../reference/apis/js-apis-resource-manager.md#getstring)


## XML格式如何转为JSON格式

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

服务端返回的数据是通过base64编码后XML格式，需要转为JSON格式进行后续的处理。

**解决措施**

使用util工具中的base64相关接口进行解码操作，然后使用convertxml组件解析XML格式数据。

**代码示例**

```
import convertxml from '@ohos.convertxml';
import util from '@ohos.util';

@Entry
@Component
struct Faq_4_31 {
  @State message: string = 'base64转json'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            /* 原数据，GBK编码
            <?xml version="1.0" encoding="GBK"?>
            <data>
            <asset_no>xxxxx</asset_no>
            <machine_sn>xxxx</machine_sn>
            <bios_id>xxxx</bios_id>
            <responsible_emp_name><![CDATA[xxxx]]></responsible_emp_name>
            <responsible_account><![CDATA[xxxx xxxx]]></responsible_account>
            <responsible_emp_no>xxxx</responsible_emp_no>
            <responsible_dept><![CDATA[xxxx]]></responsible_dept>
            <user_dept><![CDATA[xxxx]]></user_dept>
            <user_name><![CDATA[xxx]]></user_name>
            <cur_domain_account>xxxx</cur_domain_account>
            <asset_loc><![CDATA[--]]></asset_loc>
            <asset_loc_cur><![CDATA[]]></asset_loc_cur>
            <asset_type>1</asset_type>
            <asset_use>For Outsourcing Staff/xxxx</asset_use>
            <overdue_date></overdue_date>
            <asset_status>xxxx</asset_status>
            <asset_period>xxxx</asset_period>
            <license></license>
            </data>
             */
            let src = 'PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iR0JLIj8+CjxkYXRhPgo8YXNzZXRfbm8+eHh4eHg8L2Fzc2V0X25vPgo8bWFjaGluZV9zbj54eHh4PC9tYWNoaW5lX3NuPgo8Ymlvc19pZD54eHh4PC9iaW9zX2lkPgo8cmVzcG9uc2libGVfZW1wX25hbWU+PCFbQ0RBVEFbeHh4eF1dPjwvcmVzcG9uc2libGVfZW1wX25hbWU+CjxyZXNwb25zaWJsZV9hY2NvdW50PjwhW0NEQVRBW3h4eHggeHh4eF1dPjwvcmVzcG9uc2libGVfYWNjb3VudD4KPHJlc3BvbnNpYmxlX2VtcF9ubz54eHh4PC9yZXNwb25zaWJsZV9lbXBfbm8+CjxyZXNwb25zaWJsZV9kZXB0PjwhW0NEQVRBW3h4eHhdXT48L3Jlc3BvbnNpYmxlX2RlcHQ+Cjx1c2VyX2RlcHQ+PCFbQ0RBVEFbeHh4eF1dPjwvdXNlcl9kZXB0Pgo8dXNlcl9uYW1lPjwhW0NEQVRBW3h4eF1dPjwvdXNlcl9uYW1lPgo8Y3VyX2RvbWFpbl9hY2NvdW50Pnh4eHg8L2N1cl9kb21haW5fYWNjb3VudD4KPGFzc2V0X2xvYz48IVtDREFUQVstLV1dPjwvYXNzZXRfbG9jPgo8YXNzZXRfbG9jX2N1cj48IVtDREFUQVtdXT48L2Fzc2V0X2xvY19jdXI+Cjxhc3NldF90eXBlPjE8L2Fzc2V0X3R5cGU+Cjxhc3NldF91c2U+Rm9yIE91dHNvdXJjaW5nIFN0YWZmL3h4eHg8L2Fzc2V0X3VzZT4KPG92ZXJkdWVfZGF0ZT48L292ZXJkdWVfZGF0ZT4KPGFzc2V0X3N0YXR1cz54eHh4PC9hc3NldF9zdGF0dXM+Cjxhc3NldF9wZXJpb2Q+eHh4eDwvYXNzZXRfcGVyaW9kPgo8bGljZW5zZT48L2xpY2Vuc2U+CjwvZGF0YT4='
            let base64 = new util.Base64Helper();
            // base解码
            let src_uint8Array = base64.decodeSync(src);
            // 解码为utf-8的字符串
            let textDecoder = util.TextDecoder.create("utf-8",{ignoreBOM: true})
            let src_str = textDecoder.decodeWithStream(src_uint8Array)
            //替换encoding字段
            src_str = src_str.replace("GBK","utf-8")
            console.log('Test src_str: ' + JSON.stringify(src_str));
            // 转换 xml-> json
            let conv = new convertxml.ConvertXML();
            let options = {trim : false, declarationKey:"_declaration",
              instructionKey : "_instruction", attributesKey : "_attributes",
              textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
              commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
              nameKey : "_name", elementsKey : "_elements"}
            let src_json = JSON.stringify(conv.convertToJSObject(src_str, options));
            console.log('Test json: ' + JSON.stringify(src_json));
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 通过try/catch语句获取到错误码401是什么意思

适用于：Openharmony 3.2 Beta5 API 9

**问题原因**

1. 必选参数没有传入。

2. 参数类型错误。

3. 参数为undefined。

**参考链接**

[通用错误码](../reference/errorcodes/errorcode-universal.md)
