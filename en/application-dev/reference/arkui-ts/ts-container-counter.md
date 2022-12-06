# Counter

The **\<Counter>** component provides an operation to increase or decrease the number.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Supported


## APIs

Counter()


## Events

The universal events and gestures are not supported. Only the following events are supported.

| Name| Description|
| -------- | -------- |
| onInc(event: () =&gt; void) | Invoked when the number of monitored objects is increased.|
| onDec(event: () =&gt; void) | Invoked when the number of monitored objects is decreased.|


## Example

```ts
// xxx.ets
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
