# Monitoring Rotating Crown Events

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:26:10.311Z pushedAt=2026-07-27T09:23:36.717Z -->

This module provides APIs to monitor rotating crown events for the current page, supporting the registration of page-level rotating crown event monitors. This module is applicable to scenarios where perception of rotating crown operations and page-level interactions are required. Only devices equipped with a rotating crown are supported.

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## setMonitorForCrownEvents

setMonitorForCrownEvents(handler: Function): void

Sets a rotary crown event monitor for the page. When a rotating crown event is triggered, the monitor triggers a callback.

This monitor is automatically removed when [page routing](../js-apis-router.md) occurs. It can be manually removed using the [clearMonitorForCrownEvents()](#clearmonitorforcrownevents) API.

> **NOTE**
>
> - The monitor is automatically removed when page routing occurs. Therefore, it is recommended that this API be called in the **onShow** [lifecycle](./js-lite-framework-lifecycle.md) callback of the page.
> - Only one monitor is supported per page. A newly registered monitor overwrites the previous one, and the system uses the monitor passed in the last call to this API.
> - Do not use this function in [app.js](../../../ui/js-framework-js-file.md), as its behavior is undefined.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Model restriction:** This API can be used only in the FA model.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| handler | Function | Mandatory | Callback executed after a rotating crown event occurs. The callback format is **(event)=>{ return false/true; }**.<br>If **true** is returned, the rotating crown event is no longer distributed to the focused component.<br>If **false** is returned,  the rotating crown event continues to be distributed to the focused component. If the callback returns an abnormal value, such as **undefined** or no return value, the default value **false** is used.<br>The rotating crown event information can be obtained through the input parameter. For event information, see **Table 1 Attributes of the CrownEvent object**. |

**Table 1** Attributes of the CrownEvent object

| Name                  | Type      | Read-Only   |  Optional  |  Description                                |
| --------------------- | -------- | ------- |--------- |-------------------------------------- |
| timestamp             | number   | No     | No    | Timestamp, in ns.                                  |
| angularVelocity       | number   | No     | No    | Rotation angular velocity, indicating the angle rotated per second.<br>The value is a positive number when the crown is rotated counterclockwise and a negative number when the crown is rotated clockwise.<br>Unit: deg/s      |
| degree                | number   | No     | No    | Relative rotation angle.<br>The value is a positive number when the crown is rotated counterclockwise and a negative number when the crown is rotated clockwise.<br>Unit: deg.<br>Value range: [-360, 360]     |

## clearMonitorForCrownEvents

clearMonitorForCrownEvents(): void

Clears the rotating crown event monitor for the page.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Model restriction:** This API can be used only in the FA model.

## Example

### Example 1 (Setting a Rotating Crown Event Monitor)

This example shows how to set a rotating crown event monitor for a page using [setMonitorForCrownEvents](#setmonitorforcrownevents) and control whether the **Slider** component responds to rotating crown events  based on the return value of the monitor using a callback.

Since API version 24, [setMonitorForCrownEvents](#setmonitorforcrownevents) and [clearMonitorForCrownEvents](#clearmonitorforcrownevents) are added.

```css
/* xxx.css */
.container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
    width: 100%;
    height: 100%;
}
.title {
    width: 80%;
    font-size: 30px;
    text-align: center;
    border-width: 2px;
    border-color: aliceblue;
    margin: 5px;
}
```

```html
<!-- xxx.hml -->
<div class="container">
    <text class="title" onclick="flagChange">flagChange</text>
    <text class="title" onclick="clearMonitor">clearMonitor</text>
    <text>slider start value is {{startValue}}</text>
    <text>slider current value is {{currentValue}}</text>
    <text>slider end value is {{endValue}}</text>
    <slider min="0" max="100" value="{{value}}" ref="sliderObj"
            onchange="setValue" style="margin-top: 10%; width: 80%;height: 1%"></slider>
</div>
```

```js
// xxx.js
export default {
    data: {
        value: 0,
        startValue: 0,
        currentValue: 0,
        endValue: 100,
        flag: false
    },
    onShow() {
        this.$refs.sliderObj.rotation({ focus: true });
        setMonitorForCrownEvents((event) => {
            console.error('event.timestamp: ' + event.timestamp + '\n' + 'event.angularVelocity: ' +
            event.angularVelocity + '\n' + 'event.degree:' + event.degree);
            return this.flag;
        });
    },
    setValue(e) {
        this.currentValue = e.value;
    },
    clearMonitor() {
        clearMonitorForCrownEvents();
    },
    flagChange() {
        this.flag = !this.flag;
    }
}

```