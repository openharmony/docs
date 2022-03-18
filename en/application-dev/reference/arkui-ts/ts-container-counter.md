# Counter


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Counter&gt;** component provides an operation to increase or decrease the number.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Counter()


## Events

Universal events and gestures are not supported. Only the events listed below are supported.

  | Name | Description | 
| -------- | -------- |
| onInc(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Event&nbsp;indicating&nbsp;that&nbsp;the&nbsp;number&nbsp;of&nbsp;monitored&nbsp;objects&nbsp;is&nbsp;increased. | 
| onDec(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Event&nbsp;indicating&nbsp;that&nbsp;the&nbsp;number&nbsp;of&nbsp;monitored&nbsp;objects&nbsp;is&nbsp;decreased. | 


## Example


```
@Entry
@Component
struct CounterExample {
  @State value: number = 0

  build() {
    Column() {
      Counter() {
        Text(this.value.toString())
      }.margin(100)
      .onInc(() => {
        this.value++
      })
      .onDec(() => {
        this.value--
      })
    }.width("100%")
  }
}
```

![en-us_image_0000001212378424](figures/en-us_image_0000001212378424.gif)
