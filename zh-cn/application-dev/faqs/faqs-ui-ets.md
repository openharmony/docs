# UI框架（ArkTS）开发常见问题



## TS语言在生成器函数中编译失败，有哪些使用限制？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

TS语言的使用在生成器函数中存在以下限制：

- 表达式仅允许在字符串(${expression})、if条件、ForEach的参数和组件的参数中使用；

- 这些表达式中的任何一个都不能导致任何应用程序状态变量（\@State、\@Link、\@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为；

- 生成器函数内部不能有局部变量。

上述限制都不适用于事件处理函数（例如onClick）的匿名函数实现。

错误示例：


```
build() {
  let a: number = 1 // invalid: variable declaration not allowed
  Column() {
    Text('Hello ${this.myName.toUpperCase()}') // ok.
    ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array variable in place
  }
  buildSpecial()  // invalid: no function calls
  Text(this.calcTextValue()) // this function call is ok.
}
```

## 在Stage模型下，如何通过router实现页面跳转 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 对于通过页面路由router实现页面跳转，首先要在main_pages.json配置文件中将所有跳转的页面加入pages列表；

2. 页面路由需要在页面渲染完成之后才能调用，在onInit和onReady生命周期中页面还处于渲染阶段，禁止调用页面路由方法。

## router通过调用push方法进堆栈的page是否会被回收

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

调用push进入堆栈的page不回收，调用back方法出栈后可以被回收。

## 如何动态替换掉资源文件中的“%s”占位符

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

在应用中，通过"$r('app.string.xx')"的形式引用应用资源，$r的第二个参数可用于替换%s占位符。

  示例：

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

## 如何读取Resource中的xml文件并转化为String类型

适用于：OpenHarmony SDK 3.2.2.5版本， API9 Stage模型

1. 通过resourceManager的RawFile接口获取Uint8Array格式数据。

2. 通过String.fromCharCode将Uint8Array格式数据转化为String类型。

参考文档：[资源管理](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md)

示例：


```
resourceManager.getRawFile(path, (error, value) => {
  if (error != null) {
    console.log("error is " + error);
  } else {
    let rawFile = value;
    let xml = String.fromCharCode.apply(null, rawFile)
  }
});
```

## 如何将Resource资源对象转成string类型

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

通过\@ohos.resourceManager模块 resourceManager.getString()方法获取字符串。

参考文档：[资源管理](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#getstring)

## class全局静态变量无法使用的问题

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

Page和Ability打包后会对import的对象分别形成两个不同的闭包，即打包出两个Global对象。因此，所引用的静态变量并不是同一对象，所以无法通过class静态变量方式定义全局变量。建议使用AppStorage进行全局变量管理。

参考文档：[应用程序的数据存储](https://docs.openharmony.cn/pages/v3.2Beta/zh-cn/application-dev/ui/ts-application-states-appstorage.md/)

## Stage模型下如何获取资源

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

Stage模型支持了通过context获取resourceManager对象的方式，再调用其内部获取资源的接口，无需再导入包，此方式FA模型不适用。

示例：


```
const context = getContext(this) as any
context 
  .resourceManager
  .getString($r('app.string.entry_desc').id)
  .then(value => {
    this.message = value.toString()
})
```

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

## CustomDialog是否支持在TS文件中使用？

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

不支持，CustomDialog当前只支持在eTS的Page中使用。

参考文档：[自定义弹窗](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-methods-custom-dialog-box.md)

## 如何将CustomDialog中的变量传递给Page页面中的变量？

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

利用自定义的回调函数，当点击弹窗的confirm按钮时，将data数据从自定义弹窗组件中传递给当前的page的页面。

示例：


```
// CustomDialog 组件
@CustomDialog
struct MyDialog {
  controller: CustomDialogController
  title: string
  data: string
  cancel: () => void
  confirm: (data: string) => void
  Button('confirm')
    .onClick(() => {
      this.controller.close()
      this.data = 'test'
      this.confirm(this.data)
    }).backgroundColor(0xffffff).fontColor(Color.Red)
// Page页面
@Entry
@Component
struct DialogTest {
  dialogController: CustomDialogController = new CustomDialogController({
    builder: MyDialog({ title:'标题自定义',cancel: this.onCancel,
    confirm: this.onAccept.bind(this) }), // 绑定自定义的回调函数
    cancel: this.existApp,
    autoCancel: true
  })
  onAccept(data:string) {
    console.info('Callback when the second button is clicked ' + data)
  }
}
```

## List组件上添加了Text组件后，List组件无法拖动到底部 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

在List的父容器加上代码layoutWeight(1)。原理：List属于可滚动容器组件，默认高度是占满全屏幕高度，当出现其他固定高度的组件占领了屏幕的部分高度时，需要开发人员显性的指定List组件占满剩余高度，而不是全屏幕高度。

## 栅格布局子组件如何居中？ 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

GridContainer内子组件默认水平左对齐，居中显示可以参考以下处理方式：

内部嵌套布局组件Row，设置Row属性justifyContent(FlexAlign.Center)，内部嵌套子组件可保持居中显示，参考[栅格布局](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ui/ui-ts-layout-grid-container.md)文档。

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
  await mainWindow.setSystemBarProperties({
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

## 如何在eTS代码中执行Web组件内的JS函数？

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

通过WebController中runJavaScript方法异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。注意：runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

参考文档：[Web](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-basic-components-web.md)

## 在容器组件嵌套的场景下，如何解决手势拖拽事件出现错乱的问题？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

gesture的属性distance默认值是5，把gesture的属性distance设成1就可以解决。
