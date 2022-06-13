# Universal Events

## Event Description

- Events are bound to components. When a component meets the event triggering condition, the corresponding event callback in the JS is executed to implement the interaction between the UI and the JS logic layer of the page.
- The event callback can carry additional information through parameters, such as the dataset on the component and event-specific callback parameters.

Different from private events, universal events can be bound to most components.



| Name          | Parameter                                                    | Description                                                  | Support Bubbling |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------- |
| touchstart    | [TouchEvent](js-components-common-events.md) | Triggered when the tapping starts.                           | Yes<sup>5+</sup>            |
| touchmove     | [TouchEvent](js-components-common-events.md) | Triggered when the tapping moves.                            | Yes<sup>5+</sup>            |
| touchcancel   | [TouchEvent](js-components-common-events.md) | Triggered when the tapping is interrupted.                   | Yes<sup>5+</sup>            |
| touchend      | [TouchEvent](js-components-common-events.md) | Triggered when the tapping ends.                             | Yes<sup>5+</sup>            |
| click         | -                                                            | Triggered when a component is clicked.                       | Yes<sup>6+</sup>            |
| doubleclick<sup>7+</sup> |                                                              | Triggered when a component is double-clicked.                | No               |
| longpress     | -                                                            | Triggered when a component is long pressed.                  | No               |
| swipe<sup>5+</sup>       | [SwipeEvent](js-components-common-events.md#table111811577714) | Triggered when a user quickly swipes on a component.         | No               |
| attached<sup>6+</sup>    | -                                                            | Triggered after the current component node is mounted to the render tree. | No               |
| detached<sup>6+</sup>    | -                                                            | Triggered when the current component node is removed from the render tree. | No               |
| pinchstart<sup>7+</sup>  | [PinchEvent](js-components-common-events.md) | Triggered when a pinch operation is started.                 | No               |
| pinchupdate<sup>7+</sup> | [PinchEvent](js-components-common-events.md) | Triggered when a pinch operation is in progress.             | No               |
| pinchend<sup>7+</sup>    | [PinchEvent](js-components-common-events.md) | Triggered when a pinch operation is ended.                   | No               |
| pinchcancel<sup>7+</sup> | [PinchEvent](js-components-common-events.md) | Triggered when the pinch operation is interrupted.           | No               |
| dragstart<sup>7+</sup>   | [DragEvent](js-components-common-events.md) | Triggered when dragging starts.                              | No               |
| drag<sup>7+</sup>        | [DragEvent](js-components-common-events.md) | Triggered when dragging is in progress.                      | No               |
| dragend<sup>7+</sup>     | [DragEvent](js-components-common-events.md) | Triggered when dragging is ended.                            | No               |
| dragenter<sup>7+</sup>   | [DragEvent](js-components-common-events.md) | Triggered when the dragged component enters a drop target.   | No               |
| dragover<sup>7+</sup>    | [DragEvent](js-components-common-events.md) | Triggered when the dragged component is being dragged over a drop target. | No               |
| dragleave<sup>7+</sup>   | [DragEvent](js-components-common-events.md) | Triggered when the dragged component leaves a drop target.   | No               |
| drop<sup>7+</sup>        | [DragEvent](js-components-common-events.md) | Triggered when a component is dropped on a drop target.      | No               |

> ![img](public_sys-resources/icon-note.gif) **NOTE:** Events not listed in the preceding table are non-bubbling events, such as the [change event](js-components-basic-input.md). For details, see the specific component.

**Table 1** Attributes of the BaseEvent object



| Attribute | Type   | Description                                     |
| --------- | ------ | ----------------------------------------------- |
| type      | string | Event type, such as **click** and **longpress** |
| timestamp | number | Timestamp when the event is triggered           |

**Table 2** Attributes of the TouchEvent object (inherited from BaseEvent)



| Attribute      | Type              | Description                                                  |
| -------------- | ----------------- | ------------------------------------------------------------ |
| touches        | Array\<TouchInfo> | Attribute set of the touch event, including the information array of the touch points on the screen. |
| changedTouches | Array\<TouchInfo> | Attribute set when a touch event occurs, including the information array of changed touch points on the screen. **changedTouches** has the same data format as **touches** and indicates touch point changes, such as from no touch point to newly generated touch points, from some touch points to no touch point, and location changes. For example, when the user's finger leaves the touchscreen, no data exists in the **touches** array, but **changedTouches** will save the generated data. |

**Table 3** TouchInfo



| Attribute | Type   | Description                                                  |
| --------- | ------ | ------------------------------------------------------------ |
| globalX   | number | Horizontal distance from the upper left corner of the screen (excluding the status bar). The upper left corner of the screen acts as the coordinate origin. |
| globalY   | number | Vertical distance from the upper left corner of the screen (excluding the status bar). The upper left corner of the screen acts as the coordinate origin. |
| localX    | number | Horizontal distance from the upper left corner of the touched component. The upper left corner of the component acts as the coordinate origin. |
| localY    | number | Vertical distance from the upper left corner of the touched component. The upper left corner of the component acts as the coordinate origin. |
| size      | number | Touch area.                                                  |
| force<sup>6+</sup>   | number | Touch force.                                                 |

**Table 4** Attributes of the SwipeEvent object (inherited from BaseEvent)



| Attribute  | Type   | Description                                                  |
| ---------- | ------ | ------------------------------------------------------------ |
| direction  | string | Swiping direction. The value can be one of the following:   <br>- **left**: Swipe from right to left  <br>- **right**: Swipe from left to right  <br>- **up**: Swipe upwards  <br>- **down**: Swipe downwards |
| distance<sup>6+</sup> | number | Swiping distance in the swiping direction.                   |

**Table 5** Attributes of the PinchEvent object<sup>7+</sup>



| Attribute    | Type   | Description                              |
| ------------ | ------ | ---------------------------------------- |
| scale        | number | Scale factor.                            |
| pinchCenterX | number | X-coordinate of the pinch center, in px. |
| pinchCenterY | number | Y-coordinate of the pinch center, in px. |

**Table 6** Attributes of the DragEvent object (inherited from BaseEvent)<sup>7+</sup>



| Attribute | Type   | Description                                                  |
| --------- | ------ | ------------------------------------------------------------ |
| type      | string | Event name.                                                  |
| globalX   | number | Horizontal distance from the origin of the coordinates in the upper left corner of the screen. |
| globalY   | number | Vertical distance from the origin of the coordinates in the upper left corner of the screen. |
| timestamp | number | Timestamp.                                                   |

## Event Object

When a component triggers an event, the event callback receives an event object by default. You can obtain the corresponding information through the event object.

**target object:**



| Attribute | Type   | Description                                                  |
| --------- | ------ | ------------------------------------------------------------ |
| dataSet<sup>6+</sup> | Object | Custom attribute set defined through [data-*](js-components-common-attributes.md). |

**Example:**

```
<!-- xxx.hml -->
<div>
  <div data-a="dataA" data-b="dataB" 
    style="width: 100%; height: 50%; background-color: saddlebrown;"@touchstart='touchstartfunc'></div>
</div>
```

```
// xxx.js
export default {
  touchstartfunc(msg) {
    console.info(`on touch start, point is: ${msg.touches[0].globalX}`);
    console.info(`on touch start, data is: ${msg.target.dataSet.a}`);
  }
}
```

