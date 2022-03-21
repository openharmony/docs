# Input Monitor


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import


```
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```


## Required Permissions

ohos.permission.INPUT_MONITORING


## inputMonitor.on

on(type: "touch", receiver: TouchEventReceiver): void

Starts listening for global input events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

  **Parameters**
  | Parameter | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;input&nbsp;event.&nbsp;Currently,&nbsp;only&nbsp;**touch**&nbsp;events&nbsp;are&nbsp;supported. | 
| receiver | [TouchEventReceiver](#toucheventreceiver) | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;touch&nbsp;event. | 

  **Example**

```
callback: function (value) {
    if (checkEvent(value)) {
            // The event meets the service requirement and is consumed.
        return true;
    } else {
            // The event does not meet the service requirement and is not consumed.
        return false;
    }
},
testOn: function () {
    console.info("InputMonitorJsTest---start---testOn");
    inputMonitor.on(
        "touch",
        this.callback
    );
    console.info("InputMonitorJsTest---end---testOn");
}
```


## inputMonitor.off

off(type: "touch", receiver: TouchEventReceiver): void

Stops listening for global input events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

  **Parameters**
  | Parameter | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;input&nbsp;event.&nbsp;Currently,&nbsp;only&nbsp;**touch**&nbsp;events&nbsp;are&nbsp;supported. | 
| receiver | [TouchEventReceiver](#toucheventreceiver) | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;touch&nbsp;event. | 

  **Example**

```
callback: function (value) {
    if (checkEvent(value)) {
            // The event meets the service requirement and is consumed.
        return true;
    } else {
            // The event does not meet the service requirement and is not consumed.
        return false;
    }
},
testOff: function () {
    console.info("InputMonitorJsTest---start---testOff");
    inputMonitor.off(
        "touch",
        this.callback
    );
    console.info("InputMonitorJsTest---end---testOff");
}
```


## TouchEventReceiver

Represents the class of the callback used to return the touch event. The value **true** indicates that the touch event has been consumed, and the value **false** indicates the opposite.


### (touchEvent: TouchEvent): Boolean

Represents the callback used to return the touch event. You need to define the name of the callback function in the correct format. Ensure that the input parameter is of the **TouchEvent** type, and the return value is of the **Boolean** type.

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

  **Parameters**
| Parameter | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;touch&nbsp;event. |

  **Return value**
  | Type | Description | 
| -------- | -------- |
| Boolean | Result&nbsp;indicating&nbsp;whether&nbsp;the&nbsp;touch&nbsp;event&nbsp;has&nbsp;been&nbsp;consumed&nbsp;by&nbsp;the&nbsp;input&nbsp;monitor.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;touch&nbsp;event&nbsp;has&nbsp;been&nbsp;consumed,&nbsp;and&nbsp;the&nbsp;value&nbsp;**false**&nbsp;indicates&nbsp;the&nbsp;opposite. | 

  **Example**

```
callback: function (value) {// Implementation of the (touchEvent:TouchEvent): Boolean API.
    if (checkEvent(value)) {
            // The event meets the service requirement and is consumed.
        return true;
    } else {
            // The event does not meet the service requirement and is not consumed.
        return false;
    }
},
testOff: function () {
    console.info("InputMonitorJsTest---start---testOff");
    inputMonitor.off(
        "touch",
        this.callback
    );
    console.info("InputMonitorJsTest---end---testOff");
}
```
