# Custom Component Lifecycle Callbacks


The lifecycle callbacks of a custom component are used to notify users of the lifecycle of the component. These callbacks are private and are invoked by the development framework at a specified time at runtime. They cannot be manually invoked from applications.


## Lifecycle Callback Definition

| Function | Description |
| -------- | -------- |
| aboutToAppear | Invoked after a new instance of the custom component is created and before its build function is executed. You can change state variables in the **aboutToAppear** function. The change will take effect when you execute the **build** function next time. |
| aboutToDisappear | Invoked before the destructor of the custom component is consumed. Do not change state variables in the **aboutToDisappear** function as doing this can cause unexpected errors. For example, the modification of the **@Link** decorated variable may cause unstable application running. |
| onPageShow | Invoked when a page is displayed. This callback is used in the routing process or scenarios where the application is switched to the foreground or background. Only the custom components decorated by **@Entry** take effect. |
| onPageHide | Invoked when a page is hidden. This callback is used in the routing process or scenarios where the application is switched to the foreground or background. Only the custom components decorated by **@Entry** take effect. |
| onBackPress | Invoked when a user clicks the back button. Only the custom components decorated by **@Entry** take effect.<br/>- The value **true** is returned if the page processes the return logic instead of performing page routing.<br/>- The value **false** is returned if the default return logic is used.<br/>- If no value is returned, the default return logic is used. |


## Example


```
@Entry
@Component
struct CountDownTimerComponent {
    @State countDownFrom: number = 10
    private timerId: number = -1

    aboutToAppear(): void  {
        this.timerId = setInterval(() => {
            if (this.countDownFrom <= 1) {
                clearTimeout(this.timerId)
            }
            this.countDownFrom -= 1
        }, 1000) // decr counter by 1 every second
    }

    aboutToDisappear(): void {
        if (this.timerId > 0) {
            clearTimeout(this.timerId)
            this.timerId = -1
        }
    }

    build() {
        Text(`${this.countDownFrom} sec left`)
    }
}
```

The example above shows that lifecycle functions are critical for CountDownTimerComponent to manage its timer resources. Similar functions include loading resources asynchronously from the network.


> **NOTE**
>
> - Promise and asynchronous callback functions can be used in lifecycle functions, for example, network resource getters and timer setters.
>
> - Do not use **async await** in lifecycle functions.
