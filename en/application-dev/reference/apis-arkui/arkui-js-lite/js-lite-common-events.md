# Universal Events


Different from private events, universal events can be bound to most components.


| Name| Parameter| Description|
| -------- | -------- | -------- |
| click | - | Triggered when the component is clicked. |
| longpress | - | Triggered when the component is long pressed. |
| swipe<sup>5+</sup> | SwipeEvent | Triggered when a user quickly swipes on the component. |


SwipeEvent (inherited from BaseEvent)

| Attribute| Type| Description |
| -------- | -------- | -------- |
| direction | string | Swiping direction. The value can be one of the following:<br>- **left**: Swipe left.<br>- **right**: Swipe right.<br>- **up**: Swipe up.<br>- **down**: Swipe down. |

