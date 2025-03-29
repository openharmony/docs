# Crown Event (Recommended for Circular Screens)

The crown event, supported since API version 18, is triggered by the rotation of the watch crown and reports changes in the rotation angle based on the hardware sampling frequency.

The distribution of crown events depends on the application focus. Only the component that currently has focus can receive the event. Therefore, the component that receives the event must manage its focus status. You can customize focus events. Some built-in components already support interaction with the watch crown. For example, rotating the crown scrolls the scrollbar. In addition, applications can be notified of crown events through a specific API. Currently, the following components support crown events by default: [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md), [DatePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-datepicker.md), [TextPicker](../reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md), [TimePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md), [Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md), [List](../reference/apis-arkui/arkui-ts/ts-container-list.md), [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md), [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md), [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md), [Refresh](../reference/apis-arkui/arkui-ts/ts-container-refresh.md), and [Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md).

>  **NOTE**
>
>  - Only circular screens support crown events.

When a crown event occurs, the **onDigitalCrown** callback is invoked.

```ts
onDigitalCrown(event: (event?: CrownEvent) => void)
```

The **event** parameter provides the following information: timestamp, rotation angular velocity, rotation angle, and [crown action](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#crownaction18).

To enable a component to obtain information such as the rotation angle, use the **onDigitalCrown** API for receiving the crown event. The following example uses the **Text** component to illustrate how to develop a crown event and the precautions to take during development.

1. Ensure the component focus.

    Use APIs such as [focusable](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusable), [defaultFocus](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#defaultfocus9), and [focusOnTouch](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusontouch9) to ensure that the target component can receive focus. For details about focus control, see [Focus Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md).
    
    ```ts
    Text(this.message)
      .fontSize(20)
      .fontColor(Color.White)
      .backgroundColor("#262626")
      .textAlign(TextAlign.Center)
      .focusable(true)
      .focusOnTouch(true)
      .defaultFocus(true)
    ```
2. Register the crown event callback.

    To receive a crown event, you need to register a crown event callback. When a crown event is triggered, the callback function is executed.

    ```ts
    .onDigitalCrown((event: CrownEvent) => {})
    ```
3. Understand event fields.

    The crown event provides the timestamp, rotation angular velocity, rotation angle, and crown action. To prevent the event from bubbling up, use [stopPropagation](../reference/apis-arkui/arkui-ts/ts-universal-events-crown.md#crownevent).

    ```ts
    event.stopPropagation();
    this.message = "CrownEvent\n\n" + JSON.stringify(event);
    console.debug("action:%d, angularVelocity:%f, degree:%f, timestamp:%f",
    event.action, event.angularVelocity, event.degree, event.timestamp);
    ```

**Example**

```ts
// xxx.ets
@Entry
@Component
struct CityList {
  @State message: string = "onDigitalCrown";

  build() {
    Column() {
      Row(){
        Stack() {
          Text(this.message)
            .fontSize(20)
            .fontColor(Color.White)
            .backgroundColor("#262626")
            .textAlign(TextAlign.Center)
            .focusable(true)
            .focusOnTouch(true)
            .defaultFocus(true)
            .borderWidth(2)
            .width(223).height(223)
            .borderRadius(110)
            .onDigitalCrown((event: CrownEvent) => {
              event.stopPropagation();
              this.message = "CrownEvent\n\n" + JSON.stringify(event);
              console.debug("action:%d, angularVelocity:%f, degree:%f, timestamp:%f",
                event.action, event.angularVelocity, event.degree, event.timestamp);
            })
        }.width("100%").height("100%")
      }.width("100%").height("100%")
    }
  }
}
```

![crown.gif](../reference/apis-arkui/arkui-ts/figures/crown.gif)
