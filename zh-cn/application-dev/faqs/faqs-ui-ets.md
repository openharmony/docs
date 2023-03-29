# ArkUI组件（ArkTS）开发常见问题

## 在Stage模型下，如何通过router实现页面跳转 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 对于通过页面路由router实现页面跳转，首先要在main_pages.json配置文件中将所有跳转的页面加入pages列表；

2. 页面路由需要在页面渲染完成之后才能调用，在onInit和onReady生命周期中页面还处于渲染阶段，禁止调用页面路由方法。

参考文档：[页面路由](../reference/apis/js-apis-router.md)

## router通过调用push方法进堆栈的page是否会被回收

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

调用push进入堆栈的page不回收，调用back方法出栈后可以被回收。

## 如何将容器定位到屏幕的最底部？

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

可以使用Stack堆叠容器，设置子组件在容器内的最底部。

  示例：
  
```
build() {
  Stack({alignContent : Alignment.Bottom}) {
    //容器位于最底部
    Stack() {
      Column()
      .width('100%')
      .height('100%')
      .backgroundColor(Color.Yellow)
    }
    .width('100%')
    .height('10%')
  }
  .width('100%')
  .height('100%')
  .backgroundColor('rgba(255,255,255, 0)')
}
```

## CustomDialog是否支持在TS文件中使用

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

不支持，CustomDialog当前只支持在ArkTS的Page中使用。

参考文档：[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## 如何将CustomDialog中的变量传递给Page页面中的变量

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

利用自定义的回调函数，当点击弹窗的confirm按钮时，将data数据从自定义弹窗组件中传递给当前的page的页面。

示例：

  
```
// 弹窗组件
@CustomDialog
struct MyDialog {
  controller: CustomDialogController
  title: string
  confirm: (data: string) => void
  data: string = ''

  build() {
    Row() {
      Column({ space: 10 }) {
        Text(this.title)
          .fontSize(30)
          .fontColor(Color.Blue)
        TextInput({ placeholder: "输入内容", text: this.data })
          .onChange((data) => {
            this.data = data // 获取输入框数据
          })
        Button('confirm')
          .onClick(() => {
            this.confirm(this.data) // 将输入框数据通过回调函数传给主页面
            this.controller.close()
          }).backgroundColor(0xffffff).fontColor(Color.Red)
      }.width("50%")
    }.height("50%")
  }
}

// main页面
@Entry
@Component
struct DialogTest {
  @State dialogTitle: string = ''
  @State dialogData: string = ''
  dialogController: CustomDialogController = new CustomDialogController({
    builder: MyDialog({
      title: this.dialogTitle, // 绑定数据
      data: this.dialogData,
      confirm: this.confirm.bind(this) // 绑定自定义的回调函数,这里要修改this的指向
    })
  })

  confirm(data: string) {
    this.dialogData = data
    console.info(`recv dialog data: ${data}`) // 获取弹窗输入的信息
  }

  build() {
    Row() {
      Column({ space: 10 }) {
        Button('点击打开弹窗')
          .onClick(() => {
            this.dialogTitle = '弹窗'
            this.dialogController.open()
          })
        Text(`接受弹窗的数据：`)
          .fontSize(20)
        TextInput({ placeholder: "输入内容", text: this.dialogData })
          .width("50%")
          .onChange((data) => {
            this.dialogData = data // 获取输入框数据
          })
      }.width("100%")
    }.height("100%")
  }
}
```

## List组件上添加了Text组件后，List组件无法拖动到底部 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

在List的父容器加上代码layoutWeight(1)。原理：List属于可滚动容器组件，默认高度是占满全屏幕高度，当出现其他固定高度的组件占领了屏幕的部分高度时，需要开发人员显性的指定List组件占满剩余高度，而不是全屏幕高度。

## 栅格布局子组件如何居中？ 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

GridContainer内子组件默认水平左对齐，居中显示可以参考以下处理方式：

内部嵌套布局组件Row，设置Row属性justifyContent(FlexAlign.Center)，内部嵌套子组件可保持居中显示，参考[栅格布局](../reference/arkui-ts/ts-container-gridcontainer.md)文档。

  示例：
  
```
GridContainer({ sizeType: SizeType.SM, columns: 12 }) {
  Row() {
    Text('1')
    .useSizeType({
      sm: { span: 4, offset: 0 },
    })
    .backgroundColor(0x46F2B4)
  }.justifyContent(FlexAlign.Center) // 该属性设置使子组件居中显示
}
```

## 如何获取状态栏和导航栏高度？ 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

在加载窗口内容之前，采用systemAvoidAreaChange事件监听。

  示例：
  
```
// MainAbility.ts
import window from '@ohos.window';

/**
 * 设置沉浸式窗口，并获取状态栏和导航栏高度
 * @param mainWindow 主窗口对象
 */
async function enterImmersion(mainWindow: window.Window) {
  mainWindow.on("systemAvoidAreaChange", (area: window.AvoidArea) => {
    AppStorage.SetOrCreate<number>("topHeight", area.topRect.height);
    AppStorage.SetOrCreate<number>("bottomHeight", area.bottomRect.height);
  })
  await mainWindow.setFullScreen(true)
  await mainWindow.setSystemBarEnable(["status", "navigation"])
  await mainWindow.sArkTSystemBarProperties({
    navigationBarColor: "#00000000",
    statusBarColor: "#00000000",
    navigationBarContentColor: "#FF0000",
    statusBarContentColor: "#FF0000"
  })
}
export default class MainAbility extends Ability {
  // do something
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let mainWindow = await windowStage.getMainWindow()
    await enterImmersion(mainWindow)
    windowStage.loadContent('pages/index')
  }
  // do something
}
```

## 在容器组件嵌套的场景下，如何解决手势拖拽事件出现错乱的问题

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

gesture的属性distance默认值是5，把gesture的属性distance设成1就可以解决。

## 如何获取组件的高度

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

组件宽高变化可通过onAreaChange组件区域变化事件获取。

示例：

  
```
Column() {
  Text(this.value)
    .backgroundColor(Color.Green).margin(30).fontSize(20)
    .onClick(() => {
      this.value = this.value + 'Text'
    })
    .onAreaChange((oldValue: Area, newValue: Area) => {
      console.info(`Ace: on area change, oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
      this.size = JSON.stringify(newValue)
    })
```

## 如何获取List组件的偏移量

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

List组件绑定Scoller控制器，通过currentOffset方式获取当前的滚动偏移量。

示例：

  
```
Column() {
  List({ space: 20, initialIndex: 0,scroller: this.scroller}) {
    ForEach(this.arr, (item) => {
      ListItem() {
        Text('' + item)
          .width('100%').height(100).fontSize(16)
          .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
      }.editable(true)
    }, item => item)
  }
  .listDirection(Axis.Vertical) // 排列方向
  .editMode(this.editFlag)
  .onScroll((xOffset: number, yOffset: number) => {        
      console.info("yOffset======="+this.scroller.currentOffset().yOffset)
  })
}.width('100%')
```

## 页面使用router携带param跳转后，下一个页面如何获取param

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

  
```
// 3.1.5.5版本之前，取值方式为：router.getParams().key 
private value: string = router.getParams().value;  
// 从3.1.6.5版本起，取值方式为：router.getParams()['key'] 
private value: string = router.getParams()['value'];
```

## RichText组件是否支持跳转到本地page页面

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

不支持。

## 使用router或Navigator实现页面跳转时，如何关闭页面间转场动效

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

1. 参考[页面间转场示例](../reference/arkui-ts/ts-page-transition-animation.md#示例)在当前页面和目标页面中定义pageTransition方法。

2. 将页面入场组件PageTransitionEnter和页面退场组件PageTransitionExit的动效参数duration都设置为0。

## UI开发中，像素单位如何选择

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

Vp保证了不同分辨率下 视觉效果的等价性，比如一个图标，在不同分辨率下都是视觉效果是等价。

lpx相当于百分比视图，按比例扩大或者缩小。

如果关注Item等效性的，比如按钮、文字、列表基本上都是VP；比如关注布局，比如1/2之类的网格，lpx更好。

## ArkTS中颜色的格式说明

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

颜色可以使用两种格式，例如 0x7F000000 或者 '\#7F000000' ，其中前两位是透明度，后六位是RGB。

  
```
fontColor(0x7F000000)
fontColor( '#7F000000' )
```

## 如何在Page页面中监听返回操作

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

在Page页面返回时，系统会调用\@Entry修饰的自定义组件的onBackPress()回调，可以在回调函数中实现相关业务诉求。参考[自定义组件生命周期回调函数](../ui/ui-ts-custom-component-lifecycle-callbacks.md)

## TextInput组件密码模式下，右边的眼睛图标是否支持自定义？

适用于：OpenHarmony SDK3.0, API9 Stage模型

TextInput组件设置type为InputType.Password时，右侧出现眼睛图标，showPasswordIcon控制图标显示隐藏，不支持自定义。更多信息可参考文档：[TextInput组件](../reference/arkui-ts/ts-basic-components-textinput.md)

## Image图片加载目前只能加载https的，不能加载http的

适用于：OpenHarmony SDK3.2.5.5, API9 Stage模型

http是不安全的，会被白名单过滤掉，建议使用https。

## TextView布局设置间距与显示界面不符合

适用于：OpenHarmony SDK3.2.5.5, API9 Stage模型

TextView默认设置align属性为居中，文本从左到右显示，需要设置align属性为Start。

## constraintSize尺寸设置不生效

适用于：OpenHarmony SDK3.0, API9 Stage模型

constraintSize约束组件尺寸时，子组件内设置百分比宽度，例如width('100%')会采用constraintSize约束中的最大宽乘百分比，导致撑开组件，看起来constraintSize设置没生效

## 如何将背景颜色设置为透明

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

将backgroundColor设置为 '\#00000000' 。

## Scroll组件滚动到达不了最底部

适用于：OpenHarmony SDK3.0, API9 Stage模型

Scroll组件在未设置高度情况下，默认为窗口高度，当滚动区域外存在其他组件时，滚动底部区域会出现遮挡，需要设置Scroll高度，或者使用Flex布局限制Scroll高度

## 输入框组件TextInput回车事件onSubmit使用

适用于：OpenHarmony SDK3.0, API9 Stage模型

onSubmit事件在回车键或软键盘回车触发该回调，参数为当前软键盘回车键类型，通过enterKeyType属性可以设置输入法回车键类型，软键盘回车键样式需要输入法的支持，具体文档参考[Textinput组件](../reference/arkui-ts/ts-basic-components-textinput.md)

## 页面路由时，页面栈内的数量限制是多少

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

页面路由栈支持的最大页面数量是32，当超出此限制时，使用router.push接口页面无法完成跳转 。

## ArkUI是否支持通过代码动态创建组件

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

支持使用[条件渲染](../quick-start/arkts-rendering-control.md#条件渲染)和[循环渲染](../quick-start/arkts-rendering-control.md#循环渲染)等方式进行动态创建组件。

## 页面路由携带PixelMap对象参数，跳转页面无法获取

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

页面路由只支持普通对象类型，普通JSON数据结构，可以采用localStorage存储PixelMap对象，在跳转页面获取

## TextInput组件在onEditChange激活的时候通过.caretPosition(0)让光标回到起点

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

onEditChange事件在输入框聚焦时触发，这时光标位置和手势触发位置有关，在使用caretPosition同步处理无法改变光标位置，需要使用异步处理，在setTimeout中执行可以进行

## TextInput是否有方法设置内容为全部选中

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

TextInput组件暂不支持设置内容全选。

## input的输入框的type属性是date，但无法选择时间 

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

input 组件的 type 设置为 date，只是会有相关格式提示，本质上还是输入控件，如果需要实现日期选择效果，需要使用 picker 组件。

## ArkTS TextInput输入时，弹出的输入法框把页面布局挤压变形 

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

用Flex布局就会有挤压变形情况，改成Column布局就不会产生挤压

## 子组件使用\@Link修饰成员变量时，父组件传值如何传值 

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

子组件使用\@Link修饰时，父组件传值需要添加"$"

示例：

  
```
@Component
struct FoodImageDisplay {
  @Link imageSrc: Resource

  build() {
    Stack({ alignContent: Alignment.BottomStart }) {
      Image(this.imageSrc)
        .objectFit(ImageFit.Contain)
      Text('Tomato')
        .fontSize(26)
        .fontWeight(500)
        .margin({ left: 26, bottom: 17.4 })
    }
    .backgroundColor('#FFedf2f5')
    .height(357)
  }
}

@Entry
@Component
struct FoodDetail {

  @State imageSrc: Resource = $r('app.media.Tomato')

  build() {
    Column() {
      FoodImageDisplay({imageSrc:$imageSrc})
    }
    .alignItems(HorizontalAlign.Center)
  }
}
```

## 如何多个pageAbility之间共享变量

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

1. 可以使用轻量级数据库

2. 可以使用持久化数据管理

3. 可以使用emitter事件通信


## 如何自定义Video组件控制栏样式

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

1. 通过设置属性controls为false关闭默认控制栏

2. 设置Video组件的controller

3. 通过ArkTS实现自定义的控制栏，并通过VideoController控制视频播放

## 对ArkTS组件多次更新时如何优化性能

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过将需要更新的ArkTS组件抽离成自定义组件，并更新该自定义组件内\@State绑定的变量，以此实现组件的局部刷新。

## 如何优化Tab组件性能

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

Tab组件处于某一页签时。其他页签并不会被系统卸载，所以会占用部分内存。可以通过if渲染控制判断当前页签是否是需要显示的页签，若不是则不加载，以此来实现卸载其他不显示的页签并释放这部分内存。

## 如何设置组件不同状态下的样式

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过设置组件的多态样式，实现组件不同状态（无状态、按下、禁用、聚焦、点击）的样式

参考文档：[多态样式](../reference/arkui-ts/ts-universal-attributes-polymorphic-style.md)

## 焦点事件onBlur/onFocus回调无法触发

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

焦点事件默认情况下需要外接键盘的Tab键，或方向键触发，点击触发焦点事件需要添加焦点控制属性focusOnTouch

参考文档：[焦点控制](../reference/arkui-ts/ts-universal-attributes-focus.md)

## Scroll内Flex加宽高与滑动冲突

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

Scroll支持单个子组件，子组件高度应由内容高度决定，当内容中存在异步加载的图片组件导致滚动布局异常时，可约束子组件最小高度constraintSize({ minHeight: '100%' })

## 页面路由跳转后如何阻止其返回原页面

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过router.clear()接口清空页面栈中的所有历史页面，保留当前页面作为栈顶页面。

参考文档：[页面路由](../reference/apis/js-apis-router.md)

## 如何实现将TextInput组件内容进行一次性清空

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

可以参考如下实现：

  
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

## Tabs组件在点击Tab项时是否支持禁止切换

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

不支持。

## 使用 \@state修饰成员变量“id”会报错,报错原因：TypeError: cannot read property 'get' of undefined

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

id添加为唯一值，成为关键字。

## 基于OpenHarmony开发的应用，是否支持使用fontFamily属性设置不同的字体

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

基于OpenHarmony开发的应用，默认字体'HarmonyOS Sans'，且当前只支持这种字体。

## Ability与UI页面推荐的数据交互方式是什么

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

推荐使用[LocalStorage](../quick-start/arkts-state-mgmt-application-level.md#localstorage)。

## 父组件如何与其孙子组件进行状态同步

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

- 方式一（推荐）：使用\@Provide和\@Consume装饰器。在父组件使用\@Provide，在孙子组件使用\@Consume，可以实现父组件和孙子组件进行双向数据绑定。

- 方式二：使用\@State和\@Link装饰器。在父组件使用\@State，在每一层子组件（子组件和孙子组件）都使用\@Link。

## 字符超长中间显示省略号

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

代码示例

  
```
beautySub(str,len) {
	var reg = /[\u4e00-\u9fa5]/g;
	//减少字符，达到优化
	var slice = str.substring(0,len)
	var charNum = (~~(slice.match(reg) && slice.match(reg).length))
	//减1是为了处理万一超过字符串，不显示多一个不是汉字的字符，
	var realen = slice.length*2 - charNum-1
	return str.substr(0,realen) + (realen < str.length ? "..." : "") +str.substr(str.length-realen,str.length)
}
```

## richText 组件怎么加上滚动条

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

RichText底层是web，可以参考html的语法，在div上加上的overflow：auto的滚动样式。

## scroll里面套一个grid，怎么禁用grid的滑动事件？

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

可以通过onScrollBegin事件和scrollBy方法实现容器嵌套滚动。

参考：[容器嵌套滚动样例](../reference/arkui-ts/ts-container-scroll.md#示例2)

## 能否去除自定义弹窗组件的白色背景

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

当前不支持。原因是当前的UI样式在框架后端写死了，无法更改。

## 组件背景图片设置backgroundImage方法是否支持svg图片格式

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

当前不支持。

## 自定义弹窗组件如何设置弹窗位置

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

自定义弹窗组件中参数alignment可以指定弹窗的位置。比如设置弹窗在底部：alignment : DialogAlignment.Bottom。

参考文档：[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## scroller如何判断回弹动画的结束误差

适用于：OpenHarmony SDK 3.2.5.3版本，API8 FA模型

目前可以在触摸结束之后，计算同方向的变化，如果变化方向相反，说明出现回弹了，就规避不处理了。


## 如何实现应用数据持久化存储

通过PersistentStorage类实现管理应用持久化数据，可以将特定标记的持久化数据链接到AppStorage中，并由AppStorage接口访问对应持久化数据。

参考文档：[持久化数据管理](../quick-start/arkts-state-mgmt-application-level.md#persistentstorage)

示例：

  
```
AppStorage.Link('varA')
PersistentStorage.PersistProp("varA", "111");
@Entry
@Componentstruct Index {
  @StorageLink('varA') varA: string = ''
  build() {
    Column() {
      Text('varA: ' + this.varA).fontSize(20)
      Button('Set').width(100).height(100).onClick(() => {
        this.varA += '333'
      })
    }
    .width('100%')
    .height('100%')
  }
}
```
