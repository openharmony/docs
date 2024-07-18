# Custom Event Interception

Provides the customized event interception capability for components. Developers can determine the HitTestMode attribute of a component based on the event information such as the position where the event occurs when the event is pressed on the component and the input source.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.


## onTouchIntercept

onTouchIntercept(callback: Callback<TouchEvent, HitTestMode>)

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                   | Mandatory | Description                         |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | Callback<[TouchEvent](ts-universal-events-touch.md#touchevent), [HitTestMode](ts-universal-attributes-hit-test-behavior.md#HitTestMode)> | Yes    |  Bind the customized event interception callback to the component and enable the callback function during the touch test. |


## Example

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
      //Invoke onTouchIntercept to modify the HitTestMode attribute of the component.
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
