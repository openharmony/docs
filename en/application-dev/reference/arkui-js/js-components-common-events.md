# Universal Events

>  **NOTE**<br>
>  Universal events are supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

## Event Description

- Events are bound to components. When a component meets the event triggering condition, the corresponding event callback in the JS is executed to implement the interaction between the UI and the JS logic layer of the page.

- The event callback can carry additional information through parameters, such as the dataset on the component and event-specific callback parameters.


Different from private events, universal events can be bound to most components.


| Name                      | Parameter        | Description                            | Support Bubbling                                  |
| ------------------------ | ---------- | ---------------------------------------- | ---------------------------------------- |
| touchstart               | TouchEvent | Triggered when the tapping starts. For details about **TouchEvent**, see Table 2.       | Yes<sup>5+</sup>                          |
| touchmove                | TouchEvent | Triggered when the tapping moves.                        | Yes<sup>5+</sup>                          |
| touchcancel              | TouchEvent | Triggered when the tapping is interrupted.                     | Yes<sup>5+</sup>                          |
| touchend                 | TouchEvent | Triggered when the tapping ends.                       | Yes<sup>5+</sup>                          |
| click                    | -          | Triggered when a component is clicked.                              | Yes<sup>6+</sup>                          |
| doubleclick<sup>7+</sup> | -          | Triggered when a component is double-clicked.                               | No<br>Bubbling is supported since API version 9. |
| longpress                | -          | Triggered when a component is long pressed.                              | No<br>Bubbling is supported since API version 9.|
| swipe<sup>5+</sup>       | SwipeEvent | Triggered when a user quickly swipes on a component.<br/>For details about **SwipeEvent**, see Table 4. | No<br>Bubbling is supported since API version 9.|
| attached<sup>6+</sup>    | -          | Triggered after the current component node is mounted to the render tree.                        | No                                       |
| detached<sup>6+</sup>    | -          | Triggered when the current component node is removed from the render tree.                       | No                                       |
| pinchstart<sup>7+</sup>  | PinchEvent | Triggered when a pinch operation is started.<br>For details about **PinchEvent**, see Table 5.| No                                       |
| pinchupdate<sup>7+</sup> | PinchEvent | Triggered when a pinch operation is in progress.                       | No                                       |
| pinchend<sup>7+</sup>    | PinchEvent | Triggered when a pinch operation is ended.                     | No                                       |
| pinchcancel<sup>7+</sup> | PinchEvent | Triggered when a pinch operation is interrupted.                        | No                                       |
| dragstart<sup>7+</sup>   | DragEvent  | Triggered when dragging starts.<br>For details about **DragEvent**, see Table 6.     | No                                       |
| drag<sup>7+</sup>        | DragEvent  | Triggered when dragging is in progress.                             | No                                       |
| dragend<sup>7+</sup>     | DragEvent  | Triggered when dragging is ended.                              | No                                       |
| dragenter<sup>7+</sup>   | DragEvent  | Triggered when the dragged component enters a drop target.                           | No                                       |
| dragover<sup>7+</sup>    | DragEvent  | Triggered when the dragged component is being dragged over a drop target.                            | No                                       |
| dragleave<sup>7+</sup>   | DragEvent  | Triggered when the dragged component leaves a drop target.                            | No                                       |
| drop<sup>7+</sup>        | DragEvent  | Triggered when the dragged component is dropped on a drop target.                         | No                                       |


>  **NOTE**<br>
>  Events not listed in the preceding table do not support bubbling, such as the [change event](../arkui-js/js-components-basic-input.md#events) of the **<input\>** component. For details, see the description of the specific component.

**Table 1** BaseEvent

| Attribute                   | Type                  | Description                          |
| --------------------- | -------------------- | --------------------------- |
| type                  | string               | Event type, such as **click** and **longpress**.|
| timestamp             | number               | Timestamp when the event is triggered.                |
| deviceId<sup>6+</sup> | number               | ID of the device that triggers the event.              |
| target<sup>6+</sup>   | [Target](#target6)| Target object that triggers the event.                |

**Table 2** TouchEvent (inherited from BaseEvent)

| Attribute            | Type                    | Description                                       |
| -------------- | ---------------------- | ---------------------------------------- |
| touches        | Array&lt;TouchInfo&gt; | Attribute set of the touch event, including the information array of the touch points on the screen.                |
| changedTouches | Array&lt;TouchInfo&gt; | Attribute set when a touch event occurs, including the information array of changed touch points on the screen. **changedTouches** has the same data format as **touches** and indicates touch point changes, including changes in the number and location of touch points. For example, when the user's finger leaves the screen, which means that the number of touch points changes from 1 to 0, **changedTouches** has the relevant data generated, but not **touches**.|

**Table 3** TouchInfo

| Attribute                | Type    | Description                            |
| ------------------ | ------ | ------------------------------ |
| globalX            | number | Horizontal distance from the upper left corner of the screen (excluding the status bar), which acts as the origin of coordinates.|
| globalY            | number | Vertical distance from the upper left corner of the screen (excluding the status bar), which acts as the origin of coordinates.|
| localX             | number | Horizontal distance from the upper left corner of the touched component, which acts as the origin of coordinates.     |
| localY             | number | Vertical distance from the upper left corner of the touched component, which acts as the origin of coordinates.     |
| size               | number | Touch area.                       |
| force<sup>6+</sup> | number | Touch force.                        |

**Table 4** SwipeEvent (inherited from BaseEvent)

| Attribute                   | Type    | Description                                      |
| --------------------- | ------ | ---------------------------------------- |
| direction             | string | Swiping direction. The value can be one of the following:<br>- **left**: Swipe left.<br>- **right**: Swipe right.<br>- **up**: Swipe up.<br>- **down**: Swipe down.|
| distance<sup>6+</sup> | number | Swiping distance in the swiping direction.                            |

**Table 5** PinchEvent<sup>7+</sup>

| Attribute          | Type    | Description            |
| ------------ | ------ | -------------- |
| scale        | number | Scale factor.          |
| pinchCenterX | number | X-coordinate of the pinch center, in px.|
| pinchCenterY | number | Y-coordinate of the pinch center, in px.|

**Table 6** DragEvent<sup>7+</sup> (inherited from BaseEvent)

| Attribute                       | Type                              | Description               |
| ------------------------- | -------------------------------- | ---------------- |
| type                      | string                           | Event name.           |
| globalX                   | number                           | Horizontal distance from the upper left corner of the screen, which acts as the origin of coordinates.|
| globalY                   | number                           | Vertical distance from the upper left corner of the screen, which acts as the origin of coordinates.|
| timestamp                 | number                           | Timestamp.            |

## Target<sup>6+</sup>

When a component triggers an event, the event callback receives an event object by default. You can obtain the corresponding information through the event object.

| Attribute                  | Type    | Description                                      |
| -------------------- | ------ | ---------------------------------------- |
| dataSet<sup>6+</sup> | Object | Custom attribute set defined through [data-*](../arkui-js/js-components-common-attributes.md).|

**Example**

```html
<!-- xxx.hml -->
<div>
  <div data-a="dataA" data-b="dataB" 
    style="width: 100%; height: 50%; background-color: saddlebrown;"@touchstart='touchstartfunc'></div>
</div>
```

```js
// xxx.js
export default {
  touchstartfunc(msg) {
    console.info(`on touch start, point is: ${msg.touches[0].globalX}`);
    console.info(`on touch start, data is: ${msg.target.dataSet.a}`);
  }
}
```



