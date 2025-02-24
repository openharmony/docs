# Reuse ID

**reuseId** is an ID that identifies the reuse group of a custom component. The reuse framework identifies and groups reusable custom components based on their reuse IDs.

>  **NOTE**
>
> This attribute is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## reuseId

reuseId(id: string)

Sets the ID that identifies the reuse group of the component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| id     | string | Yes  | ID that identifies the reuse group of the component.|

## Example

This example demonstrates how to use **reused** to identify the reuse group of a custom component.

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
  @State switch: boolean = true;
  private type: string = "type1";

  build() {
    Column() {
      Button("ChangeType")
        .onClick(() => {
          this.type = "type2"
        })
      Button("Switch")
        .onClick(() => {
          this.switch = !this.switch
        })
      if (this.switch) {
        ReusableChildComponent({ type: this.type })
          .reuseId(this.type)
      }
    }
    .width('100%')
    .height('100%')
  }
}

@Reusable
@Component
struct ReusableChildComponent {
  @State type: string = ''

  aboutToAppear() {
    console.log(`ReusableChildComponent Appear ${this.type}`)
  }

  aboutToReuse(params: ESObject) {
    console.log(`ReusableChildComponent Reuse ${this.type}`)
    this.type = params.type;
  }

  build() {
    Row() {
      Text(this.type)
        .fontSize(20)
        .margin({ left: 10 })
    }.margin({ left: 10, right: 10 })
  }
}
```
