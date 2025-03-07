## cl.arkui.1 RichEditor菜单弹出时滚动组件后菜单显隐规格变更

**访问级别**

公开接口

**变更原因**

RichEditor菜单弹出后，滚动停止时菜单是否显示的UX默认行为改变

**变更影响**

变更前：RichEditor菜单弹出后，滚动组件时菜单隐藏，停止滚动时菜单不自动重新显示。

变更后：RichEditor菜单弹出后，滚动组件时菜单隐藏，停止滚动时会自动重新显示。
| 变更前 | 变更后 |
|---------|---------|
| ![alt text](menu_disappear_onScrollEnd.gif)| ![alt text](menu_appear_onScrollEnd.gif)|
**起始API Level**

该特性变更起始支持版本为 API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**适配指导**

UX默认行为变更，无需适配。不影响功能逻辑，请关注当前富文本菜单在停止滚动时的UX表现。

## cl.arkui.2 bindMenu、bindContextMenu菜单允许自定义圆角

**访问级别**

公开接口

**变更原因**

功能增强

**变更影响**

该变更为兼容性变更。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24 版本开始。

**变更的接口/组件**

bindMenu、bindContextMenu

**适配指导**

该变更为兼容性变更，无需适配。如需使用该功能，请查阅[菜单控制](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md)文档。

## cl.arkui.3 在UI上下文不明确的地方，promptAction.showToast使用方式规格变更

**访问级别**

公开接口

**变更原因**

本模块功能依赖UI的执行上下文，不可在UI上下文不明确的地方使用，若在非UI页面中或者一些异步回调中调用此接口，可能无法跟踪到当前UI的上下文，导致toast位置计算错误。

**变更影响**

变更前：在UI上下文不明确的地方，可以直接弹出toast，但是位置可能错误。

变更后：在UI上下文不明确的地方，需要用户指定相应的UIContext来获取promptAction对象，来弹出toast。

**起始API Level**

该特性变更起始支持版本为 API 9。

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**适配指导**

在http、延时或者子窗口中弹toast，可能不会显示toast，并且日志中能看到窗口返回11的错误码，此时就需要用户自行指定上下文，代码如下
```ts
import promptAction from '@ohos.promptAction';
import http from '@ohos.net.http';

@Entry
@Component
struct Index {
  @State message: string = '点这里会弹个toast';

  build() {
    Row() {
      Button() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
      .onClick(()=>{
        let httpRequest = http.createHttp()
        let uiContext = this.getUIContext()
        httpRequest.request('https://xxx.com', { method: http.RequestMethod.GET }).then((res: http.HttpResponse) => {
          let promptAction1 = uiContext.getPromptAction()
          promptAction1.showToast({
            message:"ok，我是toast",
            duration:1000,
            showMode: promptAction.ToastShowMode.TOP_MOST
          })
        }).catch((err: Error)=>{
          let promptAction1 = uiContext.getPromptAction()
          promptAction1.showToast({
            message:"error，我是toast",
            duration:1000,
            showMode: promptAction.ToastShowMode.TOP_MOST
          })
          httpRequest.destroy()
        })
      })
    }
    .height('100%')
  }
}
```

## cl.arkui.4 backgroundImagePosition传入参数默认单位规格变更

**访问级别**

公开接口

**变更原因**

接口默认单位值与文档描述不符。

**变更影响**

变更前：position类型传入的数字值，默认单位当作px。

变更后：position类型传入的数字值，默认单位当作vp。

**起始API Level**

该特性版本为API 7,变更版本为API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如需设置px单位的值，可拼接成数字加px的字符串，或者px2vp后设置。

## cl.arkui.5 RicEditor组件RichEditorTextStyle通用属性默认值变更

**访问级别**

公开接口

**变更原因**

UX规格增强

**变更影响**

该变更为非兼容性变更。

1. 修改RichEditorTextStyle通用属性中设置字体大小为0时的字体显示大小

变更前，设置字体大小为0时內容不显示；

变更后，设置字体大小为0时，显示为默认字体大小16fp。

2. 修改RichEditorTextStyle通用属性中默认字体颜色

变更前，默认字体颜色是Color.Black；

变更后，默认字体颜色是是系统资源中的`font_primary`。

3. 修改RichEditorTextStyle通用属性中默认字体颜色

变更前，默认装饰线颜色是Color.Black；

变更后，默认装饰线颜色为跟随字体颜色。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改效果控制变量以达到预期。


## cl.arkui.6 @Builder函数中使用自定义组件关于父子关系的变更

**访问级别**

公开接口

**变更原因**

在子组件中传入Builder函数时，子组件的this会指向Builder函数所在的父组件，在某种场景下会导致运行报错，所以进行变更。

**变更影响**

示例如下1：

```ts
@Entry
@Component
struct Index {
  @Builder thirdBuilder() {
    Third()
  }
  build() {
    Column() {
      Second({secondBuilder: this.thirdBuilder.bind(this)})
    }
  }
}

@Component
struct Second {
  @Provide message: string = 'Hello';
  @BuilderParam secondBuilder: ()=>void;
  build() {
    Column() {
      this.secondBuilder()
    }
  }
}

@Component
struct Third {
  @Consume message: string;
  build() {
    Column() {
      Text(this.message).fontSize(30)
    }
  }
}
```

变更前：

执行以上代码会报运行时错误

![ScreenShot](ScreenShot_20240429152341.png)

变更后：

无报错

**涉及场景示例**

弹窗嵌套

```ts
@Builder
function customDialogBuilderFunc(){}

@CustomDialog
struct CustomDialogExampleTwo {
  @BuilderParam grandsonBuilderFunc: ()=>void;
  grandsonFunc: ()=>void = ()=>{};
  controllerTwo?: CustomDialogController;
  @State message: string = "I'm the second dialog box.";
  @State showIf: boolean = false;
  build() {
    Column() {
      this.grandsonBuilderFunc()
      Button("show/hide Text")
        .onClick(()=>{
          this.grandsonFunc()
        })
      Button ('Close Second Dialog Box')
        .onClick(() => {
          if (this.controllerTwo != undefined) {
            this.controllerTwo.close()
          }
        })
        .margin(20)
    }
  }
}

@CustomDialog
struct CustomDialogExample {
  @BuilderParam childBuilderFunc: ()=>void = customDialogBuilderFunc;
  childFunc: null | (()=>void) = null;
  dialogControllerTwo: CustomDialogController | null = new CustomDialogController({
    builder: CustomDialogExampleTwo({grandsonBuilderFunc: this.childBuilderFunc, grandsonFunc: this.childFunc!}),
    alignment: DialogAlignment.Bottom,
    offset: { dx: 0, dy: -25 } })
  controller?: CustomDialogController;

  build() {
    Column() {
      Button ('Open Second Dialog Box and close this box')
        .onClick(() => {
          this.controller!.close();
          this.dialogControllerTwo!.open();
        })
        .margin(20)
    }.borderRadius(10)
  }
}

@Entry
@Component
struct CustomDialogUser {
  @State inputValue: string = 'Click Me';
  @State styleFlag: boolean = false;
  @Builder parentBuilderFunc() {
    if (this.styleFlag) {
      Text(this.inputValue).fontSize(35)
    }
  }
  parentFunc() {
    this.styleFlag = !this.styleFlag;
  }
  dialogController: CustomDialogController | null = new CustomDialogController({
    builder: CustomDialogExample({childBuilderFunc: this.parentBuilderFunc.bind(this), childFunc: this.parentFunc.bind(this),}),
    cancel: this.exitApp,
    autoCancel: true,
    alignment: DialogAlignment.Bottom,
    offset: { dx: 0, dy: -20 },
    gridCount: 4,
    customStyle: false
  })


  aboutToDisappear() {
    this.dialogController = null;
  }

  onCancel() {
    console.info('Callback when the first button is clicked');
  }

  onAccept() {
    console.info('Callback when the second button is clicked');
  }

  exitApp() {
    console.info('Click the callback in the blank area');
  }
  build() {
    Column() {
      Button(this.inputValue)
        .onClick(() => {
          if (this.dialogController != null) {
            this.dialogController.open()
          }
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

组件冻结

```ts
@Entry
@Component
struct Index {
  @Builder
  parentComponent() {
    Third()
  }
  build() {
    Column() {
      Second({childBuilderParam: this.parentComponent.bind(this)})
    }.width('100%').margin({ top: 5 })
  }
}

@Component({freezeWhenInactive: true})
struct Second {
  @BuilderParam childBuilderParam: ()=>void;
  build() {
    Column() {
      this.childBuilderParam();
    }.width('100%').margin({ top: 5 })
  }
}

@Component
struct Third {
  @State message: string = '111';
  build() {
    Column() {
      Text(this.message)
    }.width('100%').margin({ top: 5 })
  }
}
```

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.24 版本开始。

**变更的接口/组件**

@Builder

**适配指导**

该变更为兼容性变更，无需适配。

## cl.arkui.7 Menu组件radius接口边界值处理规则变更

**访问级别**

公开接口

**变更原因**

UX规格增强

**变更影响**

该变更为非兼容性变更。

变更前：当水平方向两个圆角半径之和的最大值大于等于菜单宽度时，菜单四个圆角均采用菜单默认圆角半径值；

变更后：当水平方向两个圆角半径之和的最大值大于菜单宽度，或垂直方向两个圆角半径之和的最大值大于菜单高度时，菜单四个圆角均采用菜单默认圆角半径值。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24 版本开始。

**变更的接口/组件**

Menu组件中的radius接口

**适配指导**

若预期是使用菜单默认圆角，则无需给Menu组件设置radius属性；
若预期使用自定义圆角，可通过radius接口设置为自定义值，且自定义值不超出边界值。

## cl.arkui.8 RichEditor的onWillChange、onDidChange接口规格变更

**访问级别**

公开接口

**变更原因**

接口能力增强

**变更影响**

该变更为非兼容性变更。

变更前：

OnWillChange回调函数的参数RichEditorChangeValue，是被替换的Span与新Span的信息。
OnDidChange回调函数的返回值是新Span的信息。

变更后：

OnWillChange回调函数的参数RichEditorChangeValue，是被替换内容的索引范围与新Span的信息。
OnDidChange回调函数的返回值，是被替换内容的索引范围与新内容的索引范围。


**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24 版本开始。

**变更的接口/组件**

RichEditor的OnWillChange、OnDidChange接口。

**适配指导**

增强后的接口使用见[接口文档](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#示例17)
