# 复用标识

reuseId用于标记自定义组件复用组，当组件回收复用时，复用框架将根据组件的reuseId来划分组件的复用组。

>  **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## reuseId

reuseId(id: string)

复用标识，用于划分自定义组件的复用组。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| id     | string | 是   | 复用标识，用于划分自定义组件的复用组。 |

## 示例

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
