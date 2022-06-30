# Counter


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Counter&gt;** component provides an operation to increase or decrease the number.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Counter()


## Events

Except the events listed below, other events, including universal events, are not supported. 

| Name | Description | 
| -------- | -------- |
| onInc(event: () =&gt; void) | Event indicating that the number of monitored objects is increased. | 
| onDec(event: () =&gt; void) | Event indicating that the number of monitored objects is decreased. | 


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
