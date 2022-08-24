# Mouse Pointer

The mouse pointer module provides APIs related to pointer attribute management.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import pointer from '@ohos.multimodalInput.pointer';
```

## pointer.setPointerVisibele

setPointerVisible(visible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the visible status of the mouse pointer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name    | Type                     | Mandatory| Description                                                               |
| -------- | ------------------------- | ---- | ------------------------------------------------------------------- |
| visible  | boolean                   | Yes  | Whether the mouse pointer is visible. The value **true** indicates that the mouse pointer is visible, and the value **false** indicates the opposite.|
| callback | AysncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                       |

**Example**

```js
pointer.setPointerVisible(true, (err, data) => {
    if (err) {
        console.log(`set pointer visible failed. err=${JSON.stringify(err)}`);
        return;
    }
    console.log(`set pointer visible success.`);
);
```

## pointer.setPointerVisible

setPointerVisible(visible: boolean): Promise&lt;void&gt;

Sets the visible status of the mouse pointer. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name   | Type   | Mandatory| Description                                                               |
| ------- | ------- | ---- | ------------------------------------------------------------------- |
| visible | boolean | Yes  | Whether the mouse pointer is visible. The value **true** indicates that the mouse pointer is visible, and the value **false** indicates the opposite.|

**Return value**

| Parameter               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
pointer.setPointerVisible(false).then( data => {
        console.log(`set mouse pointer visible success`);
    }, data => {
    console.log(`set mouse pointer visible failed err=${JSON.stringify(data)}`);
});
```

## pointer.isPointerVisible

isPointerVisible(callback: AsyncCallback&lt;boolean&gt;): void

Checks the visible status of the mouse pointer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name    | Type                        | Mandatory| Description                        |
| -------- | ---------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

**Example**

```js
pointer.isPointerVisible((visible)=>{
    console.log("The mouse pointer visible attributes is " + visible);
});
```

## pointer.isPointerVisible

isPointerVisible(): Promise&lt;boolean&gt;

Checks the visible status of the mouse pointer. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Return value**

| Parameter                  | Description                           |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
pointer.isPointerVisible().then( data => {
    console.log(`isPointerThen success data=${JSON.stringify(data)}`);
});
```
