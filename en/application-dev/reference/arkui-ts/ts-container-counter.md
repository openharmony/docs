# Counter

The **\<Counter>** component provides an operation to increase or decrease the number.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported


## APIs

Counter()

Since API version 9, this API is supported in ArkTS widgets.

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                         | Type                              | Description                                      |
| --------------------------- | ---------------------------------------- | ---------------------------------------- |
| enableInc<sup>10+</sup>              | boolean                            | Whether the plus button is enabled.<br>Default value: **true**  |
| enableDec<sup>10+</sup>           | boolean                                  | Whether the minus button is enabled.<br>Default value: **true**|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name| Description|
| -------- | -------- |
| onInc(event: () =&gt; void) | Invoked when the number of monitored objects is increased.<br>Since API version 9, this API is supported in ArkTS widgets.|
| onDec(event: () =&gt; void) | Invoked when the number of monitored objects is decreased.<br>Since API version 9, this API is supported in ArkTS widgets.|


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
