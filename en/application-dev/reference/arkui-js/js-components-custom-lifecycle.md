# Lifecycle Definition

>  **NOTE**
>
>  This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.


A range of lifecycle callbacks are provided for custom components, including **onInit**, **onAttached**, **onDetached**, **onLayoutReady**, **onDestroy**, **onShow**, and **onHide**. You can use these callbacks to manage the internal logic of your custom components. The following describes the times when the lifecycle callbacks are invoked.


| Attribute         | Type    | Description              | Invoked When                                                    |
| ------------- | -------- | ------------------ | ------------------------------------------------------------ |
| onInit        | Function | Custom component initialization  | The custom component is created. This callback is invoked once.|
| onAttached    | Function | Custom component loading    | The custom component is added to the **\<Page>** component tree. When this callback is invoked, related data can be displayed during the lifecycle in scenarios such as image loading and animation playback.|
| onLayoutReady | Function | Component layout completion| Layout calculation, including content size and position adjustment, is complete for the custom component.|
| onDetached    | Function | Custom component detachment    | The custom component is detached. It is usually used to stop animation or asynchronous logic execution. |
| onDestroy     | Function | Custom component destruction    | The custom component is destroyed. It is usually used to release resources.              |
| onShow        | Function | Page display of a custom component| The page where the custom component is located is displayed.                      |
| onHide        | Function | Page hiding of a custom component| The page where the custom component is located is hidden.                      |


## Example

```html
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">{{ value }}</text>  
</div>
```

```js
//comp.js
export default {
  data: {
    value: "Create a component."
  },
  onInit() {
    console.log("Component created.")
  },
  onAttached() {
    this.value = "Load the component."
    console.log ("Component loaded.")
  },
  onShow() {
    console.log ("Page displayed.")
  },
  onHide() {
    console.log ("Page hidden.")
  }
}
```
