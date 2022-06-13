# Lifecycle Definition

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

We provide a range of lifecycle callbacks for custom components, including  **onInit**,  **onAttached**,  **onDetached**,  **onLayoutReady**,  **onDestroy**,  **onPageShow**, and  **onPageHide**. You can use these callbacks to manage the internal logic of your custom components. The following describes the times when the lifecycle callbacks are invoked.

| Attribute     | Type     | Description                        | Called When                                                  |
| ------------- | -------- | ---------------------------------- | ------------------------------------------------------------ |
| onInit        | Function | Custom component initialization    | Triggered once, when a custom component is created.          |
| onAttached    | Function | Custom component loading           | Triggered when a custom component is added to the **\<Page>** component tree. When this callback is triggered, related data can be displayed during the lifecycle in scenarios such as image loading and animation playback. |
| onLayoutReady | Function | Component layout completion        | Triggered when layout calculation, including content size and position adjustment, is complete for a custom component. |
| onDetached    | Function | Custom component removal           | Triggered when a custom component is removed. It is usually used to stop animation or asynchronous logic execution. |
| onDestroy     | Function | Custom component destruction       | Triggered when a custom component is destroyed. It is usually used to release resources. |
| onPageShow    | Function | Page display of a custom component | Triggered when the page where a custom component is located is displayed. |
| onPageHide    | Function | Page hiding of a custom component  | Triggered when the page where a custom component is located is hidden. |


## Example

```
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">{{value}}</text>  
</div>
```

```
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
  },
  onDetached() {
    this.value = ""
  },
  onPageShow() {
    console.log ("Page displayed.")
  },
  onPageHide() {
    console.log ("Page hidden.")
  }
}
```

