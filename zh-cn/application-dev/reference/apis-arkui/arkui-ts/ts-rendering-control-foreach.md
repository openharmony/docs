# ForEach

ForEach接口基于数组类型数据来进行循环渲染。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[ForEach开发者指南](../../../ui/state-management/arkts-rendering-control-foreach.md)。

## 接口

ForEach(arr: Array\<any\>,itemGenerator: (item: any, index: number) => void,keyGenerator?: (item: any, index: number) => string,)

ForEach接口基于数组类型数据来进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在ForEach父容器组件中的子组件。例如，ListItem组件要求ForEach的父容器组件必须为[List组件](../../../reference/apis-arkui/arkui-ts/ts-container-list.md)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                                                         |
| ------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| arr           | Array\<Object\>                         | 是   | 数据源，为`Array`类型的数组。<br/>**说明：**<br/>- 可以设置为空数组，此时不会创建子组件。<br/>- 可以设置返回值为数组类型的函数，例如`arr.slice(1, 3)`，但设置的函数不应改变包括数组本身在内的任何状态变量，例如不应使用`Array.splice()`,`Array.sort()`或`Array.reverse()`这些会改变原数组的函数。 |
| itemGenerator | (item: Object, index: number) => void   | 是   | 组件生成函数。<br/>- 为数组中的每个元素创建对应的组件。<br/>- `item`参数：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 组件的类型必须是`ForEach`的父容器所允许的。例如，`ListItem`组件要求`ForEach`的父容器组件必须为`List`组件。 |
| keyGenerator  | (item: Object, index: number) => string | 否   | 键值生成函数。<br/>- 为数据源`arr`的每个数组项生成唯一且持久的键值。函数返回值为开发者自定义的键值生成规则。<br/>- `item`参数：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 如果函数缺省，框架默认的键值生成函数为`(item: T, index: number) => { return index + '__' + JSON.stringify(item); }`<br/>- 键值生成函数不应改变任何组件状态。 |

> **说明：**
>
> - `ForEach`的`itemGenerator`函数可以包含`if/else`条件渲染逻辑。另外，也可以在`if/else`条件渲染语句中使用`ForEach`组件。
> - 在初始化渲染时，`ForEach`会加载数据源的所有数据，并为每个数据项创建对应的组件，然后将其挂载到渲染树上。如果数据源非常大或有特定的性能需求，建议使用`LazyForEach`组件。

## 属性

继承自[DynamicNode](#dynamicnode12)。

## DynamicNode<sup>12+</sup>

定义节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onMove<sup>12+</sup>

onMove(handler: Optional\<OnMoveHandler\>): T

拖拽排序数据移动回调。只有在List组件中使用，并且ForEach每次迭代都生成一个ListItem组件时才生效拖拽排序。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | 是   | 拖拽动作。 |

### onMove<sup>20+</sup>

onMove(handler: Optional\<OnMoveHandler\>, eventHandler: ItemDragEventHandler): T

拖拽排序数据移动回调。拖拽排序只有在List组件中使用，并且ForEach每次迭代都生成一个ListItem组件时才生效。设置拖拽排序时可以定义不同的拖拽操作，并在响应事件发生时响应。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | 是   | 拖拽动作。 |
| eventHandler  | [ItemDragEventHandler](#itemdrageventhandler20) | 是   | 拖拽发生时产生的回调。 |

### ItemDragEventHandler<sup>20+</sup>

定义数据源拖拽事件回调。用于响应不同的拖拽操作。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| onLongPress  |  [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | 是   | 长按时触发的回调。<br>- Index：长按时当前目标的索引号。 |
| onDragStart  | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | 是   | 在页面跟手滑动开始时触发的回调。<br>- Index：拖拽开始时当前目标的索引号。 |
| onMoveThrough  | [OnMoveHandler](#onmovehandler) | 是   | 在页面跟手滑动过程中经过其他组件时触发的回调。 |
| onDrop  | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | 是   | 在页面跟手滑动结束时触发的回调。<br>- Index：拖拽结束时当前目标的索引号。 |

### OnMoveHandler

type OnMoveHandler = (from: number, to: number) => void

定义数据源拖拽回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| from  | number | 是   | 数据源拖拽起始索引号。取值范围是[0, 数据源长度-1]。 |
| to  | number | 是   | 数据源拖拽目标索引号。取值范围是[0, 数据源长度-1]。 |

## 示例

### 示例1（使用OnMove进行拖拽）

以下示例展示了ForEach在List组件内使用时的拖拽效果。

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
          .backgroundColor("#FFFFFFFF")
        }, (item: string) => item)
          .onMove((from:number, to:number) => {
            let tmp = this.arr.splice(from, 1);
            this.arr.splice(to, 0, tmp[0]);
          })
      }
      .width('100%')
      .height('100%')
      .backgroundColor("#FFDCDCDC")
    }
  }
  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.arr.push(i.toString());
    }
  }
}
```

### 示例2（使用OnMove进行拖拽，并设置拖拽事件回调）

以下示例展示了ForEach在List组件设置拖拽效果后触发的回调事件。

```ts
// xxx.ets
@Entry
@Component
struct ListOnMoveExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6];

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text('第一个List' + item)
              .width('100%')
              .height(80)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
          .onMove((from: number, to: number) => {
            let tmp = this.arr.splice(from, 1);
            this.arr.splice(to, 0, tmp[0]);
            console.log('List onMove From: ' + from);
            console.log('List onMove To: ' + to);
          },
            {
              onLongPress: (index: number) => {
                console.log('List onLongPress: ' + index);
              },
              onDrop: (index: number) => {
                console.log('List onDrop: ' + index);
              },
              onDragStart: (index: number) => {
                console.log('List onDragStart: ' + index);
              },
              onMoveThrough: (from: number, Through: number) => {
                console.log('List onMoveThrough From: ' + from);
                console.log('List onMoveThrough To: ' + Through);
              }
            }
          )
      }.width('90%')
        .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```
