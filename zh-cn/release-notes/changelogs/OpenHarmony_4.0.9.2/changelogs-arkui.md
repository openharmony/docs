# arkui子系统ChangeLog

## cl.arkui.1 滚动事件上报滚动状态枚举值规则变更

ScrollState枚举值在API version 9及以下上报规则：

| 名称     | 描述                             |
| ------ | ------------------------------ |
| Idle   | 空闲状态。使用控制器提供的方法滚动、拖动滚动条滚动时触发。  |
| Scroll | 手指拖动状态。使用手指拖动List滚动时触发。        |
| Fling  | 惯性滚动状态。快速划动松手后惯性滚动和划动到边缘回弹时触发。 |

从API version 10开始，ScrollState上报规则变更为：

| 名称     | 描述                             |
| ------ | ------------------------------ |
| Idle   | 空闲状态。滚动状态回归空闲的时候触发，一个滚动流程的最后一帧回调。控制器提供的无动画的方法控制的滚动也会触发。  |
| Scroll | 滚动状态。手指拖动List滚动时触发，拖动滚动条滚动时触发，滚动鼠标滚轮触发。        |
| Fling  | 惯性滚动状态。由动画触发的滚动，包括快速划动松手后的惯性滚动，划动到边缘回弹的滚动，快速拖动内置滚动条松手后的惯性滚动，使用滚动控制器提供的带动画的方法控制的滚动。 |

ScrollState枚举变更如下。

| 场景     | API version 9及以下                         |API version 10开始                           |
| ------ | ------------------------------ |------------------------------ |
| 手指拖动滑动   | Scroll | Scroll |
| 惯性滚动   | Fling | Fling |
| 过界回弹   | Fling | Fling |
| 鼠标滚轮滚动   | Idle | Scroll |
| 拖动滚动条   | Idle | Scroll |
| 滚动控制器滚动（带动画）   | Idle | Fling |
| 滚动控制器滚动（不带动画）   | Idle | Idle |

**变更影响**

1、ScrollState枚举值从API version 7开始提供，在API version 10变更，不影响API version 9及以下版本使用。<br/>
2、API version 9及以下使用到这个枚举值的接口有List组件的onScroll事件、onScrollFrameBegin事件、Scroll组件的onScrollFrameBegin事件，API version 9及以下滚动状态上报规则不变，不会产生影响；从API version 10开始，List组件的onScroll事件在文章起始列出的部分场景中上报的枚举值会有变化。

**关键接口/组件变更**

List组件接口文档：
- [List组件事件](../../../application-dev/reference/arkui-ts/ts-container-list.md#事件)
- [List组件ScrollState枚举说明](../../../application-dev/reference/arkui-ts/ts-container-list.md#scrollstate枚举说明)

**适配指导**

List组件绑定onScroll事件，通过onScroll事件上报当前滚动状态。API version 9及以下上报的滚动状态仍遵循变更前规则，从API version 10开始，上报的滚动状态遵循变更后规则。

参考代码如下：
```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, item => item)
      }
      .listDirection(Axis.Vertical) // 排列方向
      .edgeEffect(EdgeEffect.Spring) // 边缘效果设置为Spring
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        console.log(`onScroll scrollState = ${ScrollState[scrollState]}, scrollOffset = ${[scrollOffset]}`)
      })
      .width('90%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }
}
```

## cl.arkui.2 ArkUI系统组件使用场景限制

对ArkUI系统组件的使用场景进行限制，仅允许在struct的build方法内， pageTransition方法内或@Builder修饰的函数内使用。

**示例：**

```
@Entry
@Component
struct Index {
  build() {
    Row() {
    }

  }
}
// ERROR:UI component 'Text' cannot be used in this place.
Text('Hello World')
```

**变更影响**

 如果ArkUI系统组件不在struct的build方法内，pageTransition方法内，@Builder修饰的函数内使用，编译报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

 ArkUI系统组件必须在struct的build方法内，pageTransition方法内，@Builder修饰的函数内使用。

## cl.arkui.3 RowSplit/ColumnSplit组件布局与行为变更

1、RowSplit/ColumnSplit交叉轴方向未设置大小时，由当前的适应父节点大小改为适应子节点大小。  
2、RowSplit/ColumnSplit分割线拖动后子节点行为变更，变更前拖动分割线时，子节点不压缩和拉伸，只进行平移；
变更后拖动分割线时，子节点拉伸和压缩。  
3、使用clip属性对子组件内容超出组件区域进行裁剪时，RowSplit裁剪区域由子组件区域的右侧改为子组件区域的左右两侧，
ColumnSplit裁剪区域由子组件区域的下侧改为子组件区域的上下两侧。

**变更影响**  
以上3点变更只影响API version 10及以后版本，API version 9及以前RowSplit/ColumnSplit组件布局与行为仍遵循变更前规则。

**关键接口/组件变更**

不涉及

## cl.arkui.4 Search组件/TextInput组件/TextArea组件布局与行为变更

1、Search/TextInput/TextArea中textRect中位置变更前仅相对padding偏移，变更后位置相对padding和border计算偏移。  
2、Search中textfield宽度变更前为search宽度减去search icon的宽度和icon左右space宽度，变更后需要再减去padding和border的宽度；

**变更影响**

以上变更只影响API version 10及以后版本，API version 9及以前仍遵循变更前规则。

**关键的接口/组件变更**

不涉及

**适配指导**

不涉及
