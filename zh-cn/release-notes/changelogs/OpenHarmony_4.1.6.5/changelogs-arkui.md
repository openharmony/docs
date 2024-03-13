# ArkUI子系统Changelog

## cl.arkui.1 TextClock组件构造参数timeZoneOffset支持设置特定浮点数

**访问级别**

公开接口

**变更原因**

某些国家和地区时区偏移量为浮点数，因此需要支持设置浮点数。

**变更影响**

该变更为兼容性变更，变更后timeZoneOffset支持设置特定浮点数。

**API Level**

8 

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。

**变更的接口/组件**

API 11之前，TextClock组件构造参数timeZoneOffset设置浮点数会取对应的整数值。

API 11及之后，TextClock组件构造参数timeZoneOffset设置{ 9.5, 3.5, -3.5, -4.5, -5.5, -5.75, -6.5, -9.5, -10.5, -12.75 }里的值会取对应的浮点数。

**适配指导**

请查阅[TextClock组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textclock.md)文档进行适配。

## cl.arkui.2 Gauge组件的默认阴影模糊半径变更

**访问级别**

公开接口

**变更原因**

当前Gauge组件的默认阴影模糊半径为5vp、UX检视时发现模糊半径过小，因此依照UX规范增加阴影模糊半径到20vp。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的阴影模糊半径，提升了组件的默认显示效果。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

OpenHarmony SDK 4.1.6.5前，Gauge组件的默认阴影模糊半径为5vp。

![gauge](figures/oldGauge.png)

OpenHarmony SDK 4.1.6.5及以后，Gauge组件的默认阴影模糊半径为20vp。

![gauge](figures/newGauge.png)

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。

## cl.arkui.3 getItemRect, getItemRectInGroup接口返回值单位变更

**访问级别**

公开接口

**变更原因**

返回值类型为RectResult，位置和宽高以px为单位不合理，故变更返回值单位为vp。

**变更影响**

该变更为非兼容性变更。滚动组件getItemRect接口和List组件getItemRectInGroup接口的返回值单位从px变更为vp。具体受影响的场景如下：

a) 滚动组件通过getItemRect接口获取子组件大小位置

API version 11变更前：大小位置返回值都以px为单位。

API version 11变更后：大小位置返回值都以vp为单位。

b) List组件通过getItemRectInGroup接口获取子组件ListItemGroup内子组件ListItem的大小位置

API version 11变更前：大小位置返回值都以px为单位。

API version 11变更后：大小位置返回值都以vp为单位。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

滚动组件（List、Grid、WaterFlow、Scroll）getItemRect接口、List组件getItemRectInGroup接口

**适配指导**

滚动组件（List、Grid、WaterFlow、Scroll）getItemRect接口、List组件getItemRectInGroup接口的返回值单位由原来的px变更为vp。如果需要使用px单位类型，可用vp2px接口做单位转换。
## cl.arkui.4  自定义组件构造传参赋值中装饰器变量@Link/@ObjectLink校验日志级别变更 

**访问级别**

公开接口

**变更原因**

装饰器@Link/@ObjectLink父组件校验由WARN 变成ERROR。

**变更影响**

该变更为非兼容性变更，变更后@Link/@ObjectLink父组件校验报错。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。

**示例：**

```
let NextID: number = 1;

@Observed
class ClassA {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

@Entry
@Component
struct Parent {
  @State message: string = 'Hello';

  build() {
    Column() {
      // ERROR: Property 'message' in the custom component 'Child' is missing (mandatory to specify).
      // ERROR: Property 'message1' in the custom component 'Child' is missing (mandatory to specify).
      Child();
    }
  }
}

@Component
struct Child {
  @Link message: string;
  @ObjectLink message1: ClassA;

  build() {
    Row() {
    }
  }
}
```

**变更的接口/组件**

不涉及

**适配指导**

子组件使用了装饰器@Link/@ObjectLink，父组件使用带有装饰器@Link/@ObjectLink的自定义组件时，父组件必须给@Link/@ObjectLink修饰的变量传值。
## cl.arkui.5  bindmenu使用isShow时点击事件变更 

**访问级别**

公开接口

**变更原因**

在bindMenu使用isShow时，只允许isShow控制menu的开启。

**变更影响**

该变更为非兼容性变更，变更后在bindMenu使用isShow的情况下，点击父组件不会弹出menu。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。
**示例：**

```
@Entry
@Component
struct MenuExample {
  @State listData: number[] = [0, 0, 0]
  @State isShow: boolean = false

  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      ForEach(this.listData, (item:number, index) => {
        Column() {
          Row() {
            Image($r("app.media.icon")).width(20).height(20).margin({ right: 5 })
            Text(`Menu${index as number + 1}`).fontSize(20)
          }
          .width('100%')
          .height(30)
          .justifyContent(FlexAlign.Center)
          .align(Alignment.Center)
          .onClick(() => {
            console.info(`Menu${index as number + 1} Clicked!`)
          })

          if (index != this.listData.length - 1) {
            Divider().height(10).width('80%').color('#ccc')
          }
        }.padding(5).height(40)
      })
    }.width(100)
  }

  build() {
    Column() {
      Text('click for menu')
        .fontSize(20)
        .margin({ top: 20 })
        .onClick(()=>{
          this.isShow = true
        })
        .bindMenu(this.isShow, this.MenuBuilder,
          {
            onDisappear: ()=>{
              this.isShow = false
            }
          }
        )
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#f0f0f0')
  }
}
```

**变更的接口/组件**

bindMenu

**适配指导**

使用isShow后，需要在其他事件中将isShow从false改成true，menu才会弹出，例如点击事件、手势事件以及hover等，如果出现修改isShow的值后，菜单无法弹出，可以在isShow修改前后加上日志打印该值，判断isShow是否有变化, 如果没有变化，需要检查是不是在menu消失的时候没有在onDisappear里更新isShow的值为false，或者初始情况下将isShow设置为了true。

## cl.arkui.6 OffscreenCanvas类声明式继承错误删除

**访问级别**

公开接口

**变更原因**

OffscreenCanvas类声明时父类关系继承错误会导致DevEco Studio错误联想出非OffscreenCanvas本身的方法和属性。

**变更影响**

该变更为兼容性变更，变更后OffscreenCanvas类的方法和属性在DevEco studio中可正确联想，先前因OffscreenCanvas类声明时父类继承错误导致的非OffscreenCanvas本身的方法和属性不再被联想出来。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。

**变更的接口/组件**

OffscreenCanvas

**适配指导**

DevEco Studio中OffscreenCanvas代码编辑联想功能，不涉及适配。

## cl.arkui.7 layoutWeight支持float类型变更

**访问级别**

公开接口

**变更原因**

layoutWeight需要更精细的设置。

**变更影响**

该变更为兼容性变更，变更后layoutWeight参数支持float类型。

**API Level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

涉及到layoutWeight接口

API 12前，参数为float类型，小数点后不生效。

API 12及以后，参数为float类型，小数点后生效。

**适配指导**

接口参数类型变更，不涉及适配。

## cl.arkui.8 GridRow组件高度自适应变更

**访问级别**

公开接口

**变更原因**

原规格遗留问题，变更前用户设置了GridRow组件的height属性，而实际上GridRow组件的高度并不会按设置的height进行绘制，而是会自适应子组件高度。
现将规格确定为：若用户设置了GridRow组件的height属性，则GridRow组件的高度按设置的height进行绘制，若用户没有设置GridRow组件的height属性，则自适应子组件高度。

**变更影响**

该变更为非兼容性变更。改变了GridRow组件的高度设置，可按照用户设置的高度进行绘制。

**API Level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

涉及到GridRow组件

API 11前，GridRow组件无论是否设置height属性，其高度都会自适应子组件高度。

API 11及以后，GridRow组件设置了height属性后不再自适应子组件高度，而是按用户设置高度进行绘制；如果没有设置height属性，则仍会自适应子组件高度。

**适配指导**

组件高度自适应变更，不涉及适配。

## cl.arkui.9  surface类型XComponent组件backgroundColor属性行为变更

**访问级别**

公开接口

**变更原因**

surface类型的XComponent组件需支持设置背景色。

**变更影响**

该变更为非兼容性变更，场景为给surface类型的XComponent组件设置backgroundColor属性，具体行为如下：

API version 11变更前：无论设置何种属性，背景色均为默认黑色背景色。

API version 11变更后：组件背景色会生效所设置的颜色。

**API Level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。

**示例：**

```
@Entry
@Component
struct XComponentBKColor {
  private surfaceId: string = ''
  private xComponentContext: Record<string, () => void> = {}
  xComponentController: XComponentController = new XComponentController()

  build() {
    Row() {
      XComponent({
        id: 'xcomponentid',
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
        .onLoad(() => {
          this.xComponentController.setXComponentSurfaceSize({ surfaceWidth: 1920, surfaceHeight: 1080 })
          this.surfaceId = this.xComponentController.getXComponentSurfaceId()
          this.xComponentContext = this.xComponentController.getXComponentContext() as Record<string, () => void>
        })
        .width('640px')
        .height('480px')
        .backgroundColor(Color.White)
    }
  }
}
```

**变更的接口/组件**

XComponent

**适配指导**

给surface类型的XComponent组件设置backgroundColor属性后，确认是应用的场景所需要的背景色。

## cl.arkui.10 TextInput/TextArea组件光标超出圆角部分截断显示效果变更

**访问级别**

公开接口

**变更原因**

该变更为非兼容性变更，当设置TextInput组件padding为0时，光标会显示在输入框默认圆角外，不符合应用诉求。

**变更影响**

API version 11变更前：输入框使用默认圆角， 设置padding为0，光标超出输入框组件圆角的部分未被截断。

![Alt text](figures/textinputcursorexceednotclip.png)

API version 11变更后：输入框使用默认圆角， 设置padding为0，光标超出输入框组件圆角的部分会被截断。

![Alt text](figures/textinputcursorexceedclip.png)

**API Level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。 

**变更的接口/组件**

TextInput/TextArea

**适配指导**

默认行为变更，不涉及适配。

## cl.arkui.11 全局接口作用的UI实例跟踪匹配规则变更

**访问级别**

公开接口

**变更原因**

规范全局接口UI实例匹配行为，避免因实例不明确造成的非预期行为。

**变更影响**

多实例场景下，在未绑定UI实例的上下文中调用全局接口（如在异步回调中使用路由接口），接口的作用实例可能发生变化。

全局接口需要明确的UI实例上下文以确定作用的UI实例，建议通过绑定实例的接口进行调用。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。 

**变更的接口/组件**

不推荐开发者在多实例场景下使用如下接口，建议开发者使用适配指导中的替代接口。

|                  API                  |            说明            |
| :-----------------------------------: | :------------------------: |
|            @ohos.animator             |      自定义动画控制器      |
|     @ohos.arkui.componentSnapshot     |          组件截图          |
|      @ohos.arkui.componentUtils       |         组件工具类         |
|      @ohos.arkui.dragController       |         拖拽控制器         |
|         @ohos.arkui.inspector         |        组件布局回调        |
|         @ohos.arkui.observer          |          无感监听          |
|              @ohos.font               |         自定义字体         |
|             @ohos.measure             |          文本计算          |
|           @ohos.mediaquery            |          媒体查询          |
|          @ohos.promptAction           |            弹窗            |
|             @ohos.router              |          页面路由          |
|              AlertDialog              |          警告弹窗          |
|              ActionSheet              |        列表选择弹窗        |
|         CalendarPickerDialog          |       日历选择器弹窗       |
|           DatePickerDialog            |      日期滑动选择弹窗      |
|           TimePickerDialog            |     时间滑动选择器弹窗     |
|           TextPickerDialog            |     文本滑动选择器弹窗     |
|              ContextMenu              |          菜单控制          |
| vp2px/px2vp/fp2px/px2fp/lpx2px/px2lpx |        像素单位转换        |
|             focusControl              |          焦点控制          |
|             cursorControl             |          光标控制          |
|              getContext               | 获取当前的Ability的Context |
|        LocalStorage.getShared         |  获取Ability传递的Storage  |
|               animateTo               |          显式动画          |
|         animateToImmediately          |        显式立即动画        |

**适配指导**

使用组件内置方法[`getUIContext`](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-custom-component-api.md#getuicontext)，可直接获取当前组件所在的UIContext，并使用如下[UIContext](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext)中的API获取与实例绑定的对象。

| UIContext接口                    | 说明               |
| -------------------------------- | ------------------ |
| getRouter                        | 页面路由           |
| getComponentUtils                | 组件工具类         |
| getUIInspector                   | 组件布局回调       |
| getUIObserver                    | 无感监听           |
| getMediaQuery                    | 媒体查询           |
| getFont                          | 字体               |
| getPrompAction                   | 弹窗               |
| animateTo                        | 显示动画           |
| showAlerDialog                   | 警告弹窗           |
| showActionSheet                  | 列表选择弹窗       |
| showDatePickerDialog             | 日期滑动选择弹窗   |
| showTimePickerDialog             | 时间滑动选择器弹窗 |
| showTextPcikerDialog             | 文本滑动选择器弹窗 |
| createAnimator                   | 自定义动画控制器   |
| KeyboardAvoidMode                | 键盘避让           |
| getAtomicServiceBar              | 云服务             |
| getDragController/getDragPreview | 拖拽               |
| runScopedTask                    | 执行绑定实例的闭包 |

对于以下UIContext中尚不具备的API，可使用runScopedTask进行适配：

| 接口                                  | 说明                       |
| ------------------------------------- | -------------------------- |
| measure                               | 文本计算                   |
| getContext                            | 获取当前的Ability的Context |
| LocalStorage.getShared                | 获取Ability传递的Storage   |
| animateToImmediately                  | 显式立即动画               |
| ContextMenu                           | 菜单控制                   |
| vp2px/px2vp/fp2px/px2fp/lpx2px/px2lpx | 像素单位转换               |
| focusControl                          | 焦点控制                   |
| cursorControl                         | 光标控制                   |
| @ohos.arkui.componentSnapshot         | 组件截图                   |

示例1

```ets
// 使用绑定实例的路由对象进行页面路由
@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
        .onClick(() => {
          let uiContext = this.getUIContext();
          let uiRouter = uiContext.getRouter();
          uiRouter.pushUrl({
            url: 'pages/Page'
          })
        })
    }
  }
}
```

示例2

```ets
// 执行绑定实例的闭包
@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
        .onClick(() => {
          let uiContext = this.getUIContext();
          uiContext.runScopedTask(() => {
            let context = getContext();
            console.log('Get context: ' + JSON.stringify(context))
          })
        })
    }
  }
}
```

