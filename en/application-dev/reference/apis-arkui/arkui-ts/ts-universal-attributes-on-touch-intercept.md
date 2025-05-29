# Custom Event Interception

The custom event interception capability provided for components allows you to dynamically determine the **HitTestMode** attribute of a component based on the position where the event is triggered on the component, as well as other event information such as the input source.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.


## onTouchIntercept

onTouchIntercept(callback: Callback<TouchEvent, HitTestMode>)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                   | Mandatory | Description                         |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | Callback<[TouchEvent](ts-universal-events-touch.md#touchevent), [HitTestMode](ts-universal-attributes-hit-test-behavior.md#HitTestMode)>| Yes    |  Custom event interception callback to bind to the component, which is called during hit testing.|


## Example

This example demonstrates how to modify the **HitTestMode** attribute of a component using **onTouchIntercept**.

```ts
// xxx.ets
@Entry
@Component
struct Index {
  isPolygon(event: TouchEvent) {
    return true;
  }

  build(){
    Row(){
      Column(){
        Text("hello world")
          .backgroundColor(Color.Blue)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            console.log("Text click");
          })
      }
      .width(400)
      .height(300)
      .backgroundColor(Color.Pink)
      .onClick(()=>{
        console.log("Column click");
      })
      // Call onTouchIntercept to modify the HitTestMode attribute of the component.
      .onTouchIntercept((event : TouchEvent) => {
        console.log("OnTouchIntercept + " + JSON.stringify(event));
        if (this.isPolygon(event)) {
          return HitTestMode.None
        }
        return HitTestMode.Default
      })
    }
    .width('100%')
  }
}
```
