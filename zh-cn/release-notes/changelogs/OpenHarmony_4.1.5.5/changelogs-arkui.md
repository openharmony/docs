# ArkUI子系统变更说明

## cl.arkui.1 Slider设置showTips方法显示效果变更

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更，约束了Silder气泡的使用，优化了slider气泡的样式。

**变更影响**

Slider通过设置showTips方法，显示气泡。该方法有两个参数，参数1:boolean类型，表示是否显示气泡；参数2:ResourceStr类型，表示气泡中的文本内容。
具体受影响的场景见下文：

a) showTips 第一个参数设置为true显示气泡，气泡样式变化

变更前气泡样式：

![Alt text](figures/oldVertical.png)![Alt text](figures/oldHorizontal.png)

变更后气泡样式：

![Alt text](figures/newVertical.png)![Alt text](figures/newHorizontal.png)

b) showTips 第二个参数设置文本内容时，文本内容可能产生变化

变更前：根据栅格化宽度，可多行显示文本，全量显示文本。

变更后：单行显示文本，文本最大宽度36vp，即最大显示2个中文字符或4个数字。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

滑动条（Slider）

**适配指导**

默认行为变更，不涉及适配。

## cl.Arkui.2 Progress组件的默认颜色变更

**访问级别**

公开接口

**变更原因**

当前Progress组件的默认进度条前景色、默认进度条底色和默认内描边颜色不符合UX规范，因此依照UX规范对相关默认颜色做出变更。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的显示颜色，提升了组件的默认显示效果。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

API 11前，胶囊样式进度条默认前景色是系统资源中的`ohos_id_color_emphasize_contrary`，默认内描边颜色是系统资源中的`ohos_id_color_emphasize_contrary`，环形样式进度条默认进度条底色是系统资源中的`ohos_id_color_component_normal`。

![progress](figures/oldProgress.png)

API 11及以后，胶囊样式进度条默认前景色是系统资源中的`ohos_id_color_emphasize`，前景色不透明度为系统资源中的`ohos_id_alpha_highlight_bg`，默认内描边颜色是系统资源中的`ohos_id_color_emphasize`，内描边颜色不透明度为系统资源中的`ohos_id_alpha_highlight_bg`，环形样式进度条默认进度条底是系统资源中的`ohos_id_color_button_normal`。

![progress](figures/newProgress.png)

**适配指导**

默认颜色变更，不涉及适配。

## cl.Arkui.3 LoadingProgress组件的默认颜色变更

**访问级别**

公开接口

**变更原因**

当前LoadingProgress组件的默认前景色不符合UX规范，因此依照UX规范对相关默认前景色做出变更。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的显示颜色，提升了组件的默认显示效果。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

API 11前，默认前景色不透明度为0.6，默认前景色是“#99666666”。

![loadingProgress](figures/oldLoadingProgress.png)

API 11及以后，默认前景色不透明度为1.0，默认前景色是“#ff666666”。

![loadingProgress](figures/newLoadingProgress.png)

**适配指导**

默认颜色变更，不涉及适配。

## cl.arkui.4 Image组件colorFilter属性默认行为变更

**访问级别**

公开接口

**变更原因**

用户对于Image组件colorFilter属性设置异常值时，使用默认值

**变更影响**

该变更为非兼容性变更。

变更前，当开发者对Image组件的colorFilter属性设置为异常值时，采用不操作处理。

变更后，当开发者对Image组件的colorFilter属性设置为异常值时，采用对角线为 $1$ 其余值为 $0$ 的 $4 \times 5$ 的矩阵来处理。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

受影响的组件有：Image。

**适配指导**

默认行为变更，不涉及适配。

## cl.arkui.5 Image组件fillColor属性默认行为变更

**访问级别**

公开接口

**变更原因**

用户对于Image组件fillColor属性设置异常值时，使用默认值

**变更影响**

该变更为非兼容性变更。

变更前，当开发者对Image组件的fillColor属性设置为异常值时，采用不操作处理。

变更后，当开发者对Image组件的fillColor属性设置为异常值时，采用系统默认颜色来处理。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

受影响的组件有：Image。

**适配指导**

默认行为变更，不涉及适配。


## cl.Arkui.6 Datapanel组件的默认阴影模糊半径变更

**访问级别**

公开接口

**变更原因**

当前Datapanel组件的默认阴影模糊半径为5vp、UX检视时发现模糊半径过小，因此依照UX规范增加阴影模糊半径到20vp。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的阴影模糊半径，提升了组件的默认显示效果。

**API Level**

10

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

API 11前，Datapanel组件的默认阴影模糊半径为5vp。

![dataPanel](figures/oldDataPanel.png)

API 11及以后，Datapanel组件的默认阴影模糊半径为20vp。

![dataPanel](figures/newDataPanel.png)

**适配指导**

默认阴影效果变更，不涉及适配。

## cl.Arkui.7 Dialog组件内容的默认对齐方式变更

**访问级别**

公开接口

**变更原因**

当前Dialog组件内容的默认对齐方式不符合UX规范，因此依照UX规范对对齐方式做出变更。

**变更影响**

该变更为兼容性变更，改变了Dialog无标题且内容多行情况下的对齐方式，提升了组件的默认显示效果。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

API 11前，默认Dialog的内容区对齐方式在无标题情况下为居中对齐。

API 11及以后，默认Dialog的内容区对齐方式在无标题且内容只有一行的情况下为居中对齐，默认Dialog的内容区对齐方式在无标题且内容有多行的情况下为左对齐。

**适配指导**

默认对齐方式变更，不涉及适配。

## cl.Arkui.8 弹窗类组件背板的默认视觉效果变更为模糊材质

**访问级别**

公开接口

**变更原因**

增强视觉效果。

**变更影响**

该变更为兼容性变更。在统一渲染模式下，弹窗类组件背板的默认视觉效果变更为模糊材质。

如果开发者需要更换模糊材质及背景色，可以通过添加backgroundColor及backgroundBlurStyle参数修改。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

涉及到警告弹窗（AlertDialog）、列表选择弹窗（ActionSheet）、日历选择器弹窗（CalendarPickerDialog）、日期滑动选择器弹窗（DatePickerDialog）、时间滑动选择器弹窗（TimePickerDialog）、文本滑动选择器弹窗（TextPickerDialog）、promptAction中showDialog方法

API 11前，弹窗类组件背板显示为主题色。

API 11及以后，弹窗类组件背板显示为模糊材质。

**适配指导**

去除模糊材质示例代码：
```ts
@Entry
@Component
struct AlertDialogExample {
  build() {
    Column({ space: 5 }) {
      Button('one button dialog')
        .onClick(() => {
          AlertDialog.show({
            message:"alertDialog",
          })
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```
将
```ts
AlertDialog.show({
  message:"alertDialog",
})
```
替换为
```ts
AlertDialog.show({
  message:"alertDialog",
  backgroundColor:Color.White,
  backgroundBlurStyle:BlurStyle.NONE
})
```
即手动设置背景色与背景模糊材质枚举值。

## cl.Arkui.9 Dialog组件内容区Text默认分词方式变更

**访问级别**

公开接口

**变更原因**

当前Dialog组件内容的默认分词方式不符合UX规范，因此依照UX规范对分词方式做出变更。

**变更影响**

该变更为兼容性变更，改变了Dialog内容区Text默认分词方式，提升了组件的默认显示效果。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

API 11前，默认Dialog的内容区分词方式为BREAK_WORD。

API 11及以后，默认Dialog的内容区分词方式为BREAK_ALL。

关于BREAK_WORD和BREAK_ALL的区别，详见[WordBreak](../../../application-dev/reference/arkui-ts/ts-appendix-enums.md#wordbreak11)

**适配指导**

默认分词方式变更，不涉及适配。

## cl.arkui.10  opacity属性非法值设置变更

**访问级别**

公开接口

**变更原因**

opacity属性设置小于0的非法值需要按照完全透明来处理。

**变更影响**

该变更为非兼容性变更。

变更前，opacity属性设置小于0的非法值时效果完全不透明。

变更后，opacity属性设置小于0的非法值时效果完全透明。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

受影响的属性：opacity。

**适配指导**

默认行为变更，不涉及适配。

## cl.Arkui.11 ListItem、GridItem的selectable属性异常值处理逻辑变更

**访问级别**

公开接口

**变更原因**

用户对于ListItem和GridItem组件selectable属性设置异常值时，使用默认值。

**变更影响**

该变更为非兼容性变更。

变更前，当开发者对ListItem和GridItem组件selectable属性设置异常值时，采用false值处理。

变更后，当开发者对ListItem和GridItem组件selectable属性设置异常值时，采用默认值true处理。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

涉及到ListItem和GridItem组件的selectable属性。

API 11前，当开发者对ListItem和GridItem组件selectable属性设置异常值时，采用false值处理。

API 11及以后，当开发者对ListItem和GridItem组件selectable属性设置异常值时，采用默认值true处理。

**适配指导**

默认行为变更，不涉及适配。

## cl.arkui.12  Text组件fontSize属性非法值设置变更

**访问级别**

公开接口

**变更原因**

"5abc"这类数字拼接字符串被定义为非法值，不可以解析使用数字部分处理为5fp字号。

**变更影响**

该变更为非兼容性变更。

变更前，fontSize属性设置"5abc"非法值时显示字号为5fp。

变更后，fontSize属性设置"5abc"非法值时显示默认字号16fp。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

受影响的组件和接口：Text组件fontSize属性。

**适配指导**

默认行为变更，不涉及适配。

## cl.arkui.13  点击事件规格变更

**访问级别**

公开接口

**变更原因**

点击手势需响应在手指落下时，组件热区范围内的所有点击事件。去掉之前点击过程中手指移动不能超过20px的临时规格。

**变更影响**

该变更为非兼容性变更。

变更前，点击过程中手指移动不能超过20px，若手指移动超过20px，则点击手势识别失败。

变更后，点击手势识别器在手指落下时收集响应热区并缓存，若手指移动/抬起过程中超出缓存热区，则点击手势识别失败。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

点击手势：TapGesture

**适配指导**

该变更会导致若点击手势和拖动手势放入同一个并行手势组，会出现拖动手势和点击手势同时响应的情况

适配措施：
1.应用业务审视是否必须将点击手势和拖动手势放入同一个并行手势组内（大部分之前没有冲突的情况，是因为点击事件的20px的移动限制，自动消减了冲突），如果不是必须则可以不挂到同一个手势组
修改前：
```ts
  .parallelGesture(GestureGroup(GestureMode.Parallel,
    TapGesture({count: 1})
      .onAction((event?: GestureEvent)=> {
        if (event) {
          console.info("Tapgesture")
        }
      }),
    PanGesture({fingers: 1})
      .onActionStart((event?: GestureEvent)=>{
        console.info("Pan start")
      })
      .onActionUpdate((event?: GestureEvent)=>{
        console.info("Pan update")
      })
      .onActionEnd((event?: GestureEvent)=>{
        console.info("Pan end")
      })
  ))
```
修改后：
```ts
  .parallelGesture(GestureGroup(GestureMode.Parallel,
    PanGesture({fingers: 1})
      .onActionStart((event?: GestureEvent)=>{
        console.info("Pan start")
      })
      .onActionUpdate((event?: GestureEvent)=>{
        console.info("Pan update")
      })
      .onActionEnd((event?: GestureEvent)=>{
        console.info("Pan end")
      })
  ))
  .gesture(
    TapGesture({count: 1})
      .onAction((event?: GestureEvent)=> {
        if (event) {
          console.info("Tapgesture")
        }
    })
  )
```
2.若点击必须与滑动放到同一个平行手势组下，则可以通过手势自定义判定能力，通过自行设置的手指移动距离判定点击手势失败：
示例代码：
```ts
  .gesture(
    TapGesture({count: 1})
      .onAction((event?: GestureEvent)=> {
        if (event) {
          console.log("Tapgesture")
        }
      })
  )
  .onTouch((event?: TouchEvent)=> {
    if (event) {
      if (event.type === TouchType.Down) {
        this.downX = event.touches[0].windowX
        this.downY = event.touches[0].windowY
      }
    }
  })
  .onGestureJudgeBegin((gestureInfo: GestureInfo, event: BaseGestureEvent)=> {
    if (gestureInfo.type == GestureControl.GestureType.TAP_GESTURE) {
      let xGap = event.fingerList[0].globalX - this.downX
      if (xGap > 5) {
        return GestureJudgeResult.REJECT
      }
      let yGap = event.fingerList[0].globalY - this.downY
      if (yGap > 5) {
        return GestureJudgeResult.REJECT
      }
      return GestureJudgeResult.CONTINUE
    } else {
      return GestureJudgeResult.CONTINUE
    }
  })
```
3.若点击必须与滑动放到同一个平行手势组下，则可以通过手势自定义判定能力，通过设置组件flag进行手势互斥判断：
```ts
@Entry
@Component
struct Index {
  @State message: string = '';
  private hasPanActive = false;
  build() {
    Column() {
      Row({ space: 20 }) {
        Text(this.message).width(100).height(40).backgroundColor(Color.Pink)
      }.margin(20)
    }
    .width('100%')
    .height(200)
    .borderWidth(2)
    .parallelGesture(GestureGroup(GestureMode.Parallel,
      TapGesture({count: 1})
        .onAction((event?: GestureEvent)=> {
          if (event) {
            console.info("Tapgesture")
          }
        }).tag("Single-Finger-Click"),
      PanGesture({fingers: 1})
        .onActionStart((event?: GestureEvent)=>{
          console.info("Pan start")
        })
        .onActionUpdate((event?: GestureEvent)=>{
          console.info("Pan update")
        })
        .onActionEnd((event?: GestureEvent)=>{
          console.info("Pan end")
        }).tag("Single-Finger-Pan")
    ))
    .onGestureJudgeBegin((gestureInfo: GestureInfo, event: BaseGestureEvent) => {
      // 若滑动手势被触发，则将flag置为true
      if (gestureInfo.tag === "Single-Finger-Pan") {
        this.hasPanActive = true
      }
      // 若点击手势被触发，且flag为true，则说明再此之前滑动手势已被触发，组件重置flag并拒绝点击手势。
      if (gestureInfo.tag === "Single-Finger-Click" && this.hasPanActive) {
        this.hasPanActive = false;
        return GestureJudgeResult.REJECT
      }
      return GestureJudgeResult.CONTINUE
    })
  }
}
```
## cl.arkui.14  menuItem默认高度规格变更

**访问级别**

其他

**变更原因**

UX默认规格变更

**变更影响**

该变更为兼容性变更。

变更前，menuItem只传入图标高度为24vp，menuItem传入为空时高度为0。

变更后，menuItem只传入图标高度为48vp，menuItem传入为空时高度也为48vp。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

受影响的组件：MenuItem、Menu、MenuItemGroup。

**适配指导**

默认高度规格变更，如果与应用UX高度规格不符，可以自定义设置menuItem的height。

## cl.arkui.15  Swiper组件的Indicator属性参数设置逻辑变更

**访问级别**

其他

**变更原因**

Indicator属性的left、top、right、bottom等参数设置为0时不生效，设置成异常值时未按默认值0vp处理。

**变更影响**

该变更为非兼容性变更。

变更前，Indicator属性的left、top、right、bottom等参数设置为0或异常值时，导航点位于Swiper组件底部居中。

变更后，Indicator属性的left、top、right、bottom等参数设置为0或异常值时，导航点位于Swiper组件对应边界的位置，即按默认值0vp处理。

**API Level**

10

**变更发生版本**

从OpenHarmony SDK 4.1.5.5 开始。

**变更的接口/组件**

受影响的组件：Tabs。

**适配指导**

变更后，Indicator属性的left、top、right、bottom等参数设置为正常值（包含0）时按设置的值处理，设置成异常值按默认值0vp处理，不涉及适配。