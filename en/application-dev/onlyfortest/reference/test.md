# api-info--This requirement can be implemented only in the reference folder.

Use the value of H1 for api-info. The value is 9.

**Topic results are 9**
The ExtensionAbility module provides the capability of managing the extensionAbility life cycle and context environment, including creating, destroying, and dumping client information.

> **NOTE:**
>
> The initial APIs of this module are supported since API version 9.
> This module interface can be used only in the stage model.


## WindowType<sup>7+</sup>
**Directly use the value of h2, and the result is 7**

Window type enumeration.
<!-- gdsgsdg-->

**System capability:** SystemCapability.WindowManager.WindowManager.Core

| Name| value|Description|
| -------- | -------- | -------- | 
| launchReason | string| Ability launch reason, which is an enumerated type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastExitReason | string | Reason for the last exit, which is an enumerated type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastExitMessage<sup>12+</sup> | string | Reason for the last exit.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

### showWindow
**Level 3 title not available, found 7 from h2, result is 7**

showWindow(callback: AsyncCallback&lt;void&gt;): void

Displays the current window and uses the callback asynchronous callback function.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

**Parameters:**

| Parameter name | Type | Mandatory | Description |
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | is a |callback function.|

**Error code:**

## Configuration

**The level-2 title does not have sup. Find 9**Parameters for creating a sub-window or system window from the topic. The result is 9.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

### window.create<sup>(deprecated)</sup>
**Level-3 title is discarded and found in boock. The result is 7**

create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Create a system window and use callback asynchronous callback.**Level 3 Title Abandoned Search 7**

> **NOTE:**
>
> This API is supported since API version 7 and deprecated since API version 9.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

**Example:**

```js
let windowClass = null;
window.create(this.context, 'alertWindow', window.WindowType.TYPE_SYSTEM_ALERT, (err, data) = > {
    if (err.code) {
        console.error  ('Failed to create the window. Cause:'+ JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info  ('Succeeded in creating the window. Data:'+ JSON.stringify(data));
    windowClass.resetSize(500, 1000);
});
```

### window.getTopWindow<sup>(deprecated)</sup>

**This block does not exist, and h2 does not. The value of topic is 9.**


getTopWindow(): Promise&lt;Window&gt;

Obtains the last window displayed in the current application and uses Promise asynchronous callback.

> **NOTE:**
>
> 1235 hot.

**Model constraints:** This interface can be used only in the FA model.

**System capability:** SystemCapability.WindowManager.WindowManager.Core


### window.getTopWindow111<sup>(deprecated)</sup><sup>6+</sup>

**If there are multiple sups, the result is 6**.

getTopWindow(): Promise&lt;Window&gt;

Obtains the last window displayed in the current application and uses Promise asynchronous callback.**Find 6 from the title**

> **NOTE:**
>
> This API is supported since API version 6 and deprecated since API version 9.

**Model constraints:** This interface can be used only in the FA model.

**System capability:** SystemCapability.WindowManager.WindowManager.Core


### hide

hide(): Promise&lt;void&gt;

Hide the current window and use Promise asynchronous callback.**Search from the parent title until topic 9, and the result is 9**

**System Interface:** This interface is a system interface.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

**Return value:**

| Type | Description |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise object with no return result.|
| Promise\<void\> | Promise object with no return result.|
| Promise\<void> | Promise object with no return result.|
|` Promise<void> `| Promise object with no return result.|

## test Angle brackets

* one

    Executing Commands `ps -s <pid> -T`

* two

    <strong>Blod</strong>
    <b>bold</b>
    <p>Pp</p>
    <text>text</text>
    

    |name|age|
    |---|---|
    |Louis|7<sup>+</sup>|
    |Albee|2024:35  <br>2025:36  <br/>2025:37  |

* three
```ts
async function getCurrentAudioRendererInfoArray(): Promise<void> {
    ...
}
```

* four
    ```ts
    async function getCurrentAudioRendererInfoArray(): Promise<void> {
        ...
    }
    ```

* five

```ts
async function getCurrentAudioRendererInfoArray(): Promise<void> {
    ...
}
```

* six

    ```ts
    async function getCurrentAudioRendererInfoArray(): Promise<void> {
        ...
    }
    ```

* seven
    1. name 1
    ```
    sdgfdhgdfhfgjfgj
    ```

    2. name 2
        ```
        sdgfdhgdfhfgjfgj
        ```

    3. name 3

    ```
    sdgfdhgdfhfgjfgj
    ```
    4. name 4

        ```
        sdgfdhgdfhfgjfgj
        ```

## Atomic service API-apiUse the value of H1 for api-info. The value is 9.

**atomic API exit in H2(only)**
<!--ArkUI-->

<!--etgeryrt-->
**Topic results are 9**
The ExtensionAbility module provides the capability of managing the extensionAbility life cycle and context environment, including creating, destroying, and dumping client information.

> **NOTE:**
>
> The initial APIs of this module are supported since API version 9.
> This module interface can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

## Atomic service API-WindowType<sup>7+</sup>
**Directly use the value of h2, and the result is 7**

**atomic API exit in H2,not H3**

Window type enumeration.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

### Atomic service API-showWindow
**Level 3 title not available, found 7 from h2, result is 7**

showWindow(callback: AsyncCallback&lt;void&gt;): void

Displays the current window and uses the callback asynchronous callback function.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

**Parameters:**

| Parameter name | Type | Mandatory | Description |
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | is a |callback function.|

**Error code:**

## Atomic service API-Configuration

**The level-2 title does not have sup. Find 9**Parameters for creating a sub-window or system window from the topic. The result is 9.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

### Atomic service API-window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void
**atomic API exit in H3(only),not H2**

**Atomic service API**: This API can be used in atomic services since API version 12.

Create a system window and use callback asynchronous callback.**Level 3 Title Abandoned Search 7**

> **NOTE:**
>
> This API is supported since API version 7 and deprecated since API version 9.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

**Example:**

```js
let windowClass = null;
window.create(this.context, 'alertWindow', window.WindowType.TYPE_SYSTEM_ALERT, (err, data) = > {
    if (err.code) {
        console.error  ('Failed to create the window. Cause:'+ JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info  ('Succeeded in creating the window. Data:'+ JSON.stringify(data));
    windowClass.resetSize(500, 1000);
});
```

### Atomic service API-window.getTopWindow<sup>(deprecated)</sup>

**This block does not exist, and h2 does not. The value of topic is 9.**


getTopWindow(): Promise&lt;Window&gt;

Obtains the last window displayed in the current application and uses Promise asynchronous callback.

> **NOTE:**
>
> 1235 hot.

**Model constraints:** This interface can be used only in the FA model.

**System capability:** SystemCapability.WindowManager.WindowManager.Core


### Atomic service API-window.getTopWindow111<sup>(deprecated)</sup><sup>6+</sup>

**If there are multiple sups, the result is 6**.

getTopWindow(): Promise&lt;Window&gt;

Obtains the last window displayed in the current application and uses Promise asynchronous callback.**Find 6 from the title**

> **NOTE:**
>
> This API is supported since API version 6 and deprecated since API version 9.

**Model constraints:** This interface can be used only in the FA model.

**System capability:** SystemCapability.WindowManager.WindowManager.Core


### Atomic service API-hide

hide(): Promise&lt;void&gt;

Hide the current window and use Promise asynchronous callback.**Search from the parent title until topic 9, and the result is 9**

**System Interface:** This interface is a system interface.

**System capability:** SystemCapability.WindowManager.WindowManager.Core

| Name| value|Description|
| -------- | -------- | -------- | 
| launchReason | string| Ability launch reason, which is an enumerated type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastExitReason | string | Reason for the last exit, which is an enumerated type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastExitMessage<sup>12+</sup> | string | Reason for the last exit.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
