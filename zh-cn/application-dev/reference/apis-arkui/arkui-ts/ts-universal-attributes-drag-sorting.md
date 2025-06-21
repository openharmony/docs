# 拖拽排序

在List组件下使用ForEach/LazyForEach/Repeat，并设置onMove事件，每次迭代生成一个ListItem时，可以使能拖拽排序。拖拽排序离手后，如果数据位置发生变化，将触发onMove事件，上报数据移动原始索引号和目标索引号。在onMove事件中，需要根据上报的起始索引号和目标索引号修改数据源。确保数据仅顺序发生变化，才能正常执行落位动画。

> **说明：**
> 
> 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## onMove

onMove(handler: Optional\<OnMoveHandler\>)

拖拽排序数据移动回调。当父容器组件为[List](./ts-container-list.md#list)，并且ForEach/LazyForEach/Repeat每次迭代都生成一个ListItem组件时才生效。设置拖拽排序时可以定义不同的拖拽操作，并在响应事件发生时响应。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | 是   | 拖拽动作。 |

## OnMoveHandler

type OnMoveHandler = (from: number, to: number) => void;

定义数据源拖拽回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| from  | number | 是   | 数据源拖拽起始索引号。取值范围是[0, 数据源长度-1]。 |
| to  | number | 是   | 数据源拖拽目标索引号。取值范围是[0, 数据源长度-1]。 |

## 示例

下面的示例展示了ForEach在List组件内使用时的拖拽效果。

```ts
@Entry
@Component
struct ForEachSort {
  @State arr: Array<string> = [];

  build() {
    Row() {
      List() {
        ForEach(this.arr, (item: string) => {
          ListItem() {
            Text(item.toString())
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .size({height: 100, width: "100%"})
          }.margin(10)
          .borderRadius(10)
          .backgroundColor('#FFFFFFFF')
        }, (item: string) => item)
          .onMove((from:number, to:number) => {
            let tmp = this.arr.splice(from, 1);
            this.arr.splice(to, 0, tmp[0]);
          })
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#FFDCDCDC')
    }
  }
  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.arr.push(i.toString());
    }
  }
}
```
