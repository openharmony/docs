# ArkUI Subsystem Changelog

## cl.arkui.1 Display Effect Change for the showTips Method of the \<Slider> Component

**Access Level**

Public

**Reason for Change**

This change is a compatible change, which involves how the tooltip is displayed for the **\<Slider>** component.

**Change Impact**

The **showTips** method of the **\<Slider>** component is affected. This method has two parameters: The first parameter of the Boolean type indicates whether to display a tooltip; the second parameter of the ResourceStr type indicates the text content of the tooltip.
Specifically, the affected scenarios are as follows:

- Style of the tooltip when the first parameter of **showTips** is set to **true**

Before change

![Alt text](figures/oldVertical.png)![Alt text](figures/oldHorizontal.png)

After change

![Alt text](figures/newVertical.png)![Alt text](figures/newHorizontal.png)

- Width of the text content specified by the second parameter of **showTips**

Before change: The text can be displayed in multiple lines in full based on the grid width.

After change: The text is displayed in a single line, with the maximum width of 36 vp. That is, a maximum of four digits can be displayed.

**API Level**

7

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

\<Slider>

**Adaptation Guide**

N/A

## cl.Arkui.2 Change in the Default Colors of the \<Progress> Component

**Access Level**

Public

**Reason for Change**

The original default colors of the **\<Progress>** component do not comply with the UX specifications.

**Change Impact**

This change is a compatible change. It delivers a more visually appealing component.

**API Level**

8

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

>  **NOTE**
>
> The color values listed below refer to the resource IDs in the system.

In versions earlier than API version 11:

- The default colors of the capsule-style progress indicator are as follows: foreground color: **ohos_id_color_emphasize_contrary**; border: **ohos_id_color_emphasize_contrary**.
- The default background color of the ring-style progress indicator is **ohos_id_color_component_normal**.

![progress](figures/oldProgress.png)

Since API version 11:

- The default colors of the capsule-style progress indicator are as follows: foreground color: **ohos_id_color_emphasize**; foreground color opacity: **ohos_id_alpha_highlight_bg**; border: **ohos_id_color_emphasize**; border opacity: **ohos_id_alpha_highlight_bg**.
- The default background color of the ring-style progress indicator is **ohos_id_color_button_normal**.

![progress](figures/newProgress.png)

**Adaptation Guide**

N/A

## cl.Arkui.3 Change in the Default Colors of the \<LoadingProgress> Component

**Access Level**

Public

**Reason for Change**

The original default foreground color of the **\<LoadingProgress>** component does not comply with the UX specifications.

**Change Impact**

This change is a compatible change. It delivers a more visually appealing component.

**API Level**

8

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

In versions earlier than API version 11: The default foreground color opacity is **0.6**, and the default foreground color is **#99666666**.

![loadingProgress](figures/oldLoadingProgress.png)

Since API version 11: The default foreground color opacity is **1.0**, and the default foreground color is **#ff666666**.

![loadingProgress](figures/newLoadingProgress.png)

**Adaptation Guide**

N/A

## cl.arkui.4 Change in the Default Behavior for the colorFilter Attribute of the \<Image> Component

**Access Level**

Public

**Reason for Change**

The change is made to meet user expectations.

**Change Impact**

This change is a non-compatible change.

Before change: When the **colorFilter** attribute of the **\<Image>** component is set to an invalid value, no operation is performed.

After change: When the **colorFilter** attribute of the **\<Image>** component is set to an invalid value, the system uses a value that represents a $4 \times 5$ matrix with entries of $1$ on the diagonal and entries of $0$ in other places.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

\<Image>

**Adaptation Guide**

N/A

## cl.arkui.5 Change in the Default Behavior for the fillColor Attribute of the \<Image> Component

**Access Level**

Public

**Reason for Change**

The change is made to meet user expectations.

**Change Impact**

This change is a non-compatible change.

Before change: When the **fillColor** attribute of the **\<Image>** component is set to an invalid value, no operation is performed.

After change: When the **fillColor** attribute of the **\<Image>** component is set to an invalid value, the system uses the default value.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

\<Image>

**Adaptation Guide**

N/A


## cl.Arkui.6 Change in the Default Shadow Blur Radius of the \<Datapanel> Component

**Access Level**

Public

**Reason for Change**

The original default shadow blur radius, 5 vp, is too small to meet the UX specifications.

**Change Impact**

This change is a compatible change. It delivers a more visually appealing component.

**API Level**

10

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

In versions earlier than API version 11: The default shadow blur radius of the **\<Datapanel>** component is 5 vp.

![dataPanel](figures/oldDataPanel.png)

Since API version 11: The default shadow blur radius of the **\<Datapanel>** component is 20 vp.

![dataPanel](figures/newDataPanel.png)

**Adaptation Guide**

N/A

## cl.Arkui.7 Change in the Default Alignment Mode for Dialog Box Content

**Access Level**

Public

**Reason for Change**

The change is made to maintain consistency with UX specifications.

**Change Impact**

This change is a compatible change. It delivers a more visually appealing dialog box when there are multiple lines but no title in the dialog box.

**API Level**

7

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

In versions earlier than API version 11: By default, content in the dialog box is center aligned when there is no title.

Since API version 11: By default, content in the dialog box is center aligned when there is no title and the content contains only one line, and is left aligned when there is no title and the content contains multiple lines.

**Adaptation Guide**

N/A

## cl.Arkui.8 Change in the Default Background Effect of Dialog Boxes

**Access Level**

Public

**Reason for Change**

The change is made to enhance visual effects.

**Change Impact**

This change is a compatible change. In unified rendering mode, the default background of the dialog box is changed to a blur material.

To change the blur material and background color, you can use the **backgroundColor** and **backgroundBlurStyle** parameters.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

Components: **\<AlertDialog>**, **\<ActionSheet>**, **\<CalendarPickerDialog>**, **\<DatePickerDialog>**, **\<TimePickerDialog>**, **\<TextPickerDialog>**<br>API: **showDialog** in the **promptAction** module

In versions earlier than API version 11: The default background of the dialog box is in the theme color.

Since API version 11: The default background of the dialog box is a blur material.

**Adaptation Guide**

Example of removing the blur material:
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
Before change:
```ts
AlertDialog.show({
  message:"alertDialog",
})
```
After change:
```ts
AlertDialog.show({
  message:"alertDialog",
  backgroundColor:Color.White,
  backgroundBlurStyle:BlurStyle.NONE
})
```
As shown in the preceding example, you can manually set the enumerated values of the background color and background blur material.

## cl.Arkui.9 Change in the Default Line Break Rule for Dialog Boxes

**Access Level**

Public

**Reason for Change**

The change is made to maintain consistency with UX specifications.

**Change Impact**

This change is a compatible change. It delivers a more visually appealing component.

**API Level**

7

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

In versions earlier than API version 11: The default line break rule of the dialog box is **BREAK_WORD**.

Since API version 11: The default line break rule of the dialog box is **BREAK_ALL**.

For details about the differences between **BREAK_WORD** and **BREAK_ALL**, see [WordBreak](../../../application-dev/reference/apis-arkui/arkui-ts/ts-appendix-enums.md#wordbreak11).

**Adaptation Guide**

N/A

## cl.arkui.10 Change in Handling of Invalid Opacity Values

**Access Level**

Public

**Reason for Change**

If the **opacity** attribute is set to a value less than 0, the opacity should be treated as completely transparent.

**Change Impact**

This change is a non-compatible change.

Before change: The **opacity** attribute is treated as completely opaque when set to a value less than 0.

After change: The **opacity** attribute is treated as completely transparent when set to a value less than 0.

**API Level**

7

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

opacity

**Adaptation Guide**

N/A

## cl.Arkui.11 Change in Handling of Invalid selectable Values for the \<ListItem> and \<GridItem> Components

**Access Level**

Public

**Reason for Change**

The change is made to meet user expectations.

**Change Impact**

This change is a non-compatible change.

Before change: Any invalid value of the **selectable** attribute is regarded as **false** for the **\<ListItem>** and **\<GridItem>** components.

After change: Any invalid value of the **selectable** attribute is regarded as **true** for the **\<ListItem>** and **\<GridItem>** components.

**API Level**

8

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

**selectable** attribute of the **\<ListItem>** and **\<GridItem>** components

 

 

**Adaptation Guide**

N/A

## cl.arkui.12 Change in Handling of Certain Invalid Values of the fontSize attribute of the \<Text> Component

**Access Level**

Public

**Reason for Change**

The previous handling mode for invalid strings that contain digits, such as **"5abc"**, is incorrect.

**Change Impact**

This change is a non-compatible change.

Before change: If an invalid value set for the **fontSize** attribute contains a number, the number is regarded as the entire value. For example, **"5abc"** is regarded as 5 fp.

After change: If an invalid value is set for the **fontSize** attribute, regardless of whether it contains a number, the default value 16 fp is used.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

**fontSize** attribute of the **\<Text>** component

**Adaptation Guide**

N/A

## cl.arkui.13 Click Event Specification Change

**Access Level**

Public

**Reason for Change**

A tap gesture should detect all fingers touching the screen within the touch target. The temporary specification that the finger movement must not exceed 20 px during the recognition process is removed.

**Change Impact**

This change is a non-compatible change.

Before change: For a tap gesture to be recognized successfully, the fingers involved must not move more than 20 px from the initial touch points.

After change: The tap gesture recognizer collects and caches the touch targets when fingers touch the screen. If any of the fingers moves outside the cached touch targets, the tap gesture cannot be recognized.

**API Level**

7

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

TapGesture

**Adaptation Guide**

If the tap gesture and pan gesture are placed in a parallel gesture group, they may be recognized at the same time.

As such, consider the following measures:
1. If the tap gesture and pan gesture are placed in a parallel gesture group, upgroup them when possible to avoid possible recognition conflicts.
Before modification:
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
After modification:
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
2. If the tap gesture and pan gesture must be placed in the same parallel gesture group, you can use the custom gesture judgment APIs to specify that the finger involved in the tap gesture must not move a certain distance from the initial touch point.
The sample code is as follows:
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
3. If the tap gesture and pan gesture must be placed in the same parallel gesture group, you can also use the custom gesture judgment APIs to set the component flag to avoid recognition conflicts.
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
      // If a pan gesture is recognized, set the flag to true.
      if (gestureInfo.tag === "Single-Finger-Pan") {
        this.hasPanActive = true
      }
      // If a tap gesture is recognized and the flag is true, the component resets the flag and does not respond to the tap gesture.
      if (gestureInfo.tag === "Single-Finger-Click" && this.hasPanActive) {
        this.hasPanActive = false;
        return GestureJudgeResult.REJECT
      }
      return GestureJudgeResult.CONTINUE
    })
  }
}
```
## cl.arkui.14 Change in the Default Menu Item Height

**Access Level**

Other

**Reason for Change**

The change is made to maintain consistency with UX specifications.

**Change Impact**

This change is a compatible change.

Before change: If a menu item does not have its height specified, its height is 0, even when an icon is passed in.

Before change: If a menu item does not have its height specified, its height is the same as the height of the icon passed in.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

\<MenuItem>, \<Menu>, \<MenuItemGroup>

**Adaptation Guide**

If the default height is inconsistent with the application UX specification, you can customize the height.

## cl.arkui.15 Change in the Logic for Setting the indicator Attribute of the \<Swiper> Component

**Access Level**

Other

**Reason for Change**

The previous logic for handling invalid values of the **left**, **top**, **right**, and **bottom** parameters of the **indicator** attribute is incorrect.

**Change Impact**

This change is a non-compatible change.

Before change: If any of the **left**, **top**, **right**, and **bottom** parameters of the **indicator** attribute is set to **0** or an invalid value, the navigation point indicator is located in the center of the bottom of the **\<Swiper>** component.

After change: If any of the **left**, **top**, **right**, and **bottom** parameters of the **indicator** attribute is set to **0** or an invalid value, the navigation point indicator is located at the edge of the **\<Swiper>** component. That is, the default value 0 vp is used.

**API Level**

10

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

\<Tabs>

**Adaptation Guide**

N/A
