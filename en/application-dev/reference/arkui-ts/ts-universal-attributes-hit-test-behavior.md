# Hit Test Control

Hit test control allows you to configure hit testing for components. When processing a touch event, ArkUI performs hit testing on the touch points and component area before the touch event is triggered, in order to determine the component that needs to respond to the touch event, and then distributes the touch event based on the hit test result. The **hitTestBehavior** attribute sets how the component behaves during hit testing. The settings will affect the hit test result and thereby the subsequent touch event distribution. For details, see **[HitTestMode](#hittestmode)**.

>  **NOTE**
>
>  - The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>  - When the touch areas of nodes, for example, two nodes, in the **\<Stack>** component overlap, hit testing is performed only on the node displayed at the top layer by default. To perform hit testing on the node at the lower layer, set **hitTestBehavior** to **HitTestMode.Transparent** for the upper-layer node.


## Attributes

| Name              | Type    | Description                                 |
| -------------------- | -------- | ---------------------------------------- |
| hitTestBehavior      | [HitTestMode](#hittestmode) | How the component behaves during hit testing.<br>Default value: **HitTestMode.Default**|

## HitTestMode

| Name         | Description                                      |
| ------------| ----------------------------------------- |
| Default     | Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from the hit test.|
| Block       | The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test.|
| Transparent | Both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test.|
| None        | The node does not respond to the hit test of a touch event, but its child node and sibling node are considered during the hit test.|


## Example

Set **hitTestBehavior** to **HitTestMode.Transparent** for the **\<Text>** component, which means that the inner-layer **\<Stack>** component is also considered during hit testing. Therefore, both the **\<Text>** and **\<Stack>** components respond to the **onTouch** event. 
Set **hitTestBehavior** to **HitTestMode.Block** for the inner-layer **\<Stack>** component, which means that its child nodes and sibling node **\<Button>** are blocked from hit testing. Therefore, neither the inner-layer or out-layer **\<Button>** components respond to the **onTouch** event.

```ts
// xxx.ets
@Entry
@Component
struct HitTestBehaviorExample {
  build() {
    // outer stack
    Stack() {
      Button('outer button')
        .onTouch((event) => {
          console.info('outer button touched type: ' + event.type)
        })
      // inner stack
      Stack() {
        Button('inner button')
          .onTouch((event) => {
            console.info('inner button touched type: ' + event.type)
          })
      }
      .width("100%").height("100%")
      .hitTestBehavior(HitTestMode.Block)
      .onTouch((event) => {
        console.info('stack touched type: ' + event.type)
      })

      Text('Transparent')
        .hitTestBehavior(HitTestMode.Transparent)
        .width("100%").height("100%")
        .onTouch((event) => {
          console.info('text touched type: ' + event.type)
        })
    }.width(300).height(300)
  }
}
```
