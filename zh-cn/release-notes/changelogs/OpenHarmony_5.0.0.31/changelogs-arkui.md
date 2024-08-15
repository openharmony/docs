# ArkUI子系统Changelog

## cl.arkui.1 @Component和@ComponentV2修饰的自定义组件使用@Observed或者@ObservedV2修饰的类增加相关校验

**访问级别**

公开接口

**变更原因**

该变更为不兼容变更。

1.在@Component修饰的自定义组件中通过@State、@Prop、@Link、@Provide、@Consume、@StorageLink、@StorageProp、LocalStorageLink、@LocalStorageProp修饰并使用@ObservedV2修饰的变量类型时，进行校验并输出错误信息。

简化示例如下：

```ts
@ObservedV2
class TmpA{}

@Entry
@Component
struct testTmp {
  @State value_string: TmpA = new TmpA()
  build() {
    Column(){

    }
  }
}
```

2.在@ComponentV2修饰的自定义组件中通过@Param、@Local、@Event、@Provider()、@Consumer()修饰并使用@Observed修饰的类时，进行校验并输出错误信息。

简化示例如下：

```ts
@Observed
class TmpA{}

@Entry
@ComponentV2
struct testTmp {
  @Param value_string: TmpA = new TmpA()
  build() {
    Column(){

    }
  }
}
```

3.以上的变量类型联合使用时，也会进行校验并输出错误信息。

示例如下：

```ts
@ObservedV2
class TmpA{}

@Observed
class TmpB{}

@Entry
@Component
struct testTmp {
  @State value_string: TmpA | TmpB = new TmpA()
  build() {
    Column(){

    }
  }
}
```

**变更影响**

变更前无报错。

变更后报错：

1.The type of the @State property can not be a class decorated with @ObservedV2.

2.The type of the @Param property can not be a class decorated with @Observed.

3.The type of the @State property can not be a class decorated with @ObservedV2.

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**适配指导**

如果开发者不按规范使用对应范式，则需按日志提示信息进行修改。

## cl.arkui.2 bindContentCover动效参数变更

**访问级别**

公开接口

**变更原因**

为满足应用述求和UX规格，全模态动效参数改为与半模态一致。

**变更影响**

该变更为不兼容变更。

变更前，全模态动效参数为interpolatingSpring(velocity:n, mass:1, stiffness:100, damping:20)，动效时长约为1200ms。

变更后，全模态动效参数为interpolatingSpring(velocity:n, mass:1, stiffness:328, damping:36)，动效时长约为800ms。

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

bindContentCover组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改效果控制变量以达到预期，可通过[transition](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#contentcoveroptions)接口自定义动效。

## cl.arkui.3 @ohos.arkui.advanced.SubHeader删除SymbolRenderingStrategy和SymbolEffectStrategy。

**访问级别**

公开接口

**变更原因**

SymbolGlyph中已定义SymbolRenderingStrategy和SymbolEffectStrategy，避免重复枚举定义。减少开发者引用工作量。

**变更影响**

该变更为不兼容变更。

变更前，引用@ohos.arkui.advanced.SubHeader中SymbolRenderingStrategy和SymbolEffectStrategy，运行时报错：

1.Eerror message:the requested module '@ohos.arkui.advanced.SubHeader' does not provide an export name 'SymbolRenderingStrategy' and 'SymbolEffectStrategy'.

变更后，引用@ohos.arkui.advanced.SubHeader中SymbolRenderingStrategy和SymbolEffectStrategy，编译期报错：

1.Module '@ohos.arkui.advanced.SubHeader' has no exported member 'SymbolRenderingStrategy' and 'SymbolEffectStrategy'.

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**适配指导**

如果开发者不按规范使用对应范式，则需按编译提示信息进行修改。参考API文档，删除引用SubHeader中SymbolRenderingStrategy和SymbolEffectStrategy，自动引用SymbolGlyph中SymbolRenderingStrategy和SymbolEffectStrategy。
适配示例：

```ts
import { promptAction, OperationType, SubHeader } from '@kit.ArkUI'

@Entry
@Component
struct SubHeaderExample {
  build() {
    Column() {
      SubHeader({
        icon: $r('sys.symbol.ohos_wifi'),
        iconSymbolOptions: {
          effectStrategy: SymbolEffectStrategy.HIERARCHICAL,
          renderingStrategy: SymbolRenderingStrategy.MULTIPLE_COLOR,
          fontColor: [Color.Blue, Color.Grey, Color.Green],
        },
        secondaryTitle: '标题',
        operationType: OperationType.BUTTON,
        operationItem: [{ value: '操作',
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        }]
      })
    }
  }
}
```

## cl.arkui.4 bindSheet支持嵌套滚动

**访问级别**

公开接口

**变更原因**

为满足应用诉求，半模态面板嵌套滚动组件，且在滚动组件上设置嵌套模式时，需要实现联动效果。

**变更影响**

该变更为不兼容变更。

单挡位模式下半模态仅可设置一档高度。多挡位模式下半模态可以设置三档高度，内容位于半模态面板顶部时，通过上下滑动可以自由切换挡位。

API version 12之前，半模态面板嵌套滚动组件，且在滚动组件上设置嵌套模式时，无法实现联动。内容位于顶部，多档位时上下滑动无法切换挡位，单挡位时下滑无法关闭半模态。

API version 12及以后，半模态面板嵌套滚动组件，且在滚动组件上设置嵌套模式时，可以实现联动。内容位于顶部，多档位时上下滑动可以切换挡位；单挡位时下滑可以关闭半模态。

在滚动组件上设置嵌套的情况下：
| 多挡位变更前 | 多挡位变更后 |
|---------|---------|
| 无法通过上下滑动切换挡位，在最低档下滑无法关闭半模态<br>![Alt text](figures/NestedScroll_detents_Before.gif) |可以通过上下滑动切换挡位，在最低档下滑可以关闭半模态<br>![Alt text](figures/NestedScroll_detents_After.gif)|

| 单挡位变更前 | 单挡位变更后 |
|---------|---------|
| 无法通过下滑关闭半模态<br>![Alt text](figures/NestedScroll_Before.gif) |可以通过下滑关闭半模态<br>![Alt text](figures/NestedScroll_After.gif) |

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

bindSheet组件

**适配指导**

需要开发者主动适配。例如，在半模态面板中嵌套List组件场景，@Builder内容可以参考如下示例。

```ts
private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
@Builder
myBuilder() {
  Column() {
    List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }
      .listDirection(Axis.Vertical) // 排列方向
      .edgeEffect(EdgeEffect.None)
      .nestedScroll({
        scrollForward: NestedScrollMode.PARENT_FIRST,
        scrollBackward: NestedScrollMode.SELF_FIRST
      }) // 嵌套模式
      .backgroundColor(Color.Gray)
      .width('90%')
      .height('100%')
  }
}
```

## cl.arkui.5 RichEditor长按交互调整

**访问级别**

公开接口

**变更原因**

为满足应用述求和UX规格，RichEditor组件长按交互效果需要进行调整。

**变更影响**

该变更为不兼容性变更。

变更前，长按文本内容，直接触发选词，展示选中背板、手柄以及文本选择菜单。

变更后，长按文本内容不松手，触发选词并展示选中背板，继续拖动变更选中区域，松手后展示手柄及文本选择菜单。如果不继续拖动，则松手时直接展示手柄和文本选择菜单。
| 变更前                                 | 变更后                               |
| -------------------------------------- | ------------------------------------ |
| ![alt text](RichEditor_LongPress_Before.gif) | ![alt text](RichEditor_LongPress_After.gif) |

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

RichEditor组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改事件效果以达到预期。

## cl.arkui.6 TextTimer的onTimer回调频率与参数单位调整

**访问级别**

公开接口

**变更原因**

调整onTimer回调频率与参数的单位，使其符合文档描述。

**变更影响**

该变更为不兼容性变更。

TextTimer的format属性用于自定义时间格式。其中，毫秒可使用S、SS和SSS关键字表示，分别代表100ms、10ms和1ms。

变更前，当TextTimer的format属性包含毫秒时，TextTimer的文本发生变化，便会几毫秒触发一次onTimer事件，且回调参数utc和elapsedTime的单位为毫秒。

变更后，TextTimer的文本发生变化时，onTimer事件的触发时间与回调参数utc和elapsedTime的单位随format属性的自定义时间格式变化。format为mm:ss.S时，100ms回调一次onTimer事件，回调参数的单位为100ms。format为mm:ss.SS时，10ms回调一次onTimer事件，回调参数的单位为10ms。format为mm:ss.SSS时，与变更前保持一致。

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

textTimer组件的onTimer接口

**适配指导**

需要开发者主动适配，调整回调参数的数量级。

```ts
@Entry
@Component
struct TextTimerExample {
  textTimerController: TextTimerController = new TextTimerController();
  build() {
    Column(){
      TextTimer({isCountDown: true, count: 30000, controller: this.textTimerController})
        .format('mm:ss.SS')
        .fontSize(50)
        .onTimer((utc: number, elapsedTime: number) => {
          // 如果开发者需改回变更前的效果，可以将utc、elapsedTime乘10
          console.info('textTimer countDown utc is:' + utc * 10 + ',elapsedTime is:' + elapsedTime * 10)
        })

      TextTimer({isCountDown: true, count: 30000, controller: this.textTimerController})
        .format('mm:ss.S')
        .fontSize(50)
        .onTimer((utc: number, elapsedTime: number) => {
          // 如果开发者需改回变更前的效果，可以将utc、elapsedTime乘100
          console.info('textTimer countDown utc is:' + utc * 100 + ',elapsedTime is:' + elapsedTime * 100)
        })
    }
  }
}
```

## cl.arkui.7 滚动类组件（List、Grid、WaterFlow、Scroll）Friction接口默认值变更

**访问级别**

公开接口

**变更原因**

为了优化功耗，将滚动类组件（List、Grid、WaterFlow、Scroll）friction接口默认值改为0.75。

**变更影响**

该变更为不兼容变更。

变更前，滚动类组件（List、Grid、WaterFlow、Scroll）的friction接口默认值为0.7。

变更后，滚动类组件（List、Grid、WaterFlow、Scroll）的friction接口默认值为0.75。相较变更之前，用同样力度抛滑，抛滑时间更短、抛滑距离更近。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

滚动类组件（List、Grid、WaterFlow、Scroll）的friction接口。

**适配指导**

开发者如果需要使用变更之前的抛滑效果，可以将friction接口的参数设置为0.7。

```ts
@Entry
@Component
struct FrictionExample {
  build() {
    List() {
      ForEach([1, 2, 3, 4, 5], (item: number) => {
        ListItem() {
          Text('' + item)
            .width('100%').height(200).fontSize(16)
            .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
        }
      }, (item: string) => item)
    }
    .height(500)
    .friction(0.7)
  }
}
```
## cl.arkui.8 ListItem卡片样式行为变更

**访问级别**

公开接口

**变更原因**

原本ListItem在LazyForEach下使用时，ListItem设置卡片样式不生效，需要整该为能够生效。

**变更影响**

该变更为不兼容变更。

变更前：ListItem在LazyForEach下使用时，卡片样式设置不生效。<br>变更后：ListItem在LazyForEach下使用时，卡片样式设置可以生效。

```ts
// Basic implementation of IDataSource to handle data listener
abstract class BasicDataSource<T> implements IDataSource {
  private listeners: DataChangeListener[] = []

  public totalCount(): number {
    return 0
  }
  abstract getData(index: number): T;

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener)
    }
  }
  unregisterDataChangeListener(listener: DataChangeListener): void {
   const pos = this.listeners.indexOf(listener);
   if (pos >= 0) {
     this.listeners.splice(pos, 1)
   }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index)
    })
  }
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index)
    })
  }
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index)
    })
  }
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to)
    })
  }
}

class MyDataSource<T> extends BasicDataSource<T> {
  public dataArray: T[] = [];

  public totalCount(): number {
    return this.dataArray.length
  }
  public getData(index: number): T {
    return this.dataArray[index]
  }

  public addData(index: number, data: T): void {
    this.dataArray.splice(index, 0, data)
    this.notifyDataAdd(index)
  }
  public popFirstData(): void {
    this.dataArray.shift()
    this.notifyDataDelete(0)
  }
  public pushData(data: T): void {
    this.dataArray.push(data)
    this.notifyDataAdd(this.dataArray.length - 1)
  }
  public popData(): void {
    this.dataArray.pop()
    this.notifyDataDelete(this.dataArray.length)
  }
}

@Entry
@Component
struct Index {
  arr:MyDataSource<number> = new MyDataSource<number>();
  aboutToAppear(): void {
    for (let i = 0; i < 10; i++) {
      this.arr.pushData(i)
    }
  }

  build() {
    List() {
      ListItemGroup({ style: ListItemGroupStyle.CARD }) {
        LazyForEach(this.arr, (item: number) => {
          ListItem({ style: ListItemStyle.CARD }) {
            Text("item" + item.toString())
          }
        })
      }
    }.backgroundColor("#DCDCDC")
    .height("100%")
  }
}
```
| 变更前效果 | 变更后效果 |
| ---- | ---- |
| ![](./figures/list_item_card_style_before.png) | ![](./figures/list_item_card_style_after.png) |

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.31 版本开始。

**变更的接口/组件**

涉及的组件：ListItem组件ListItemStyle接口。

**适配指导**

如果ListItem在LazyForEach下使用，设置了卡片样式没有生效，变更后生效卡片样式导致显示界面变化，可以删除卡片样式的设置。

如下代码变更前设置卡片样式不生效，变更后生效卡片样式导致显示界面变化。
```ts
build() {
  List() {
    ListItemGroup({ style: ListItemGroupStyle.CARD }) {
      LazyForEach(this.arr, (item: number) => {
        ListItem({ style: ListItemStyle.CARD }) {
          Text("item" + item.toString())
            .height(64)
        }
      })
    }
  }.backgroundColor("#DCDCDC")
  .height("100%")
}
```
删除ListItem卡片样式可以恢复变更前效果。
```ts
build() {
  List() {
    ListItemGroup({ style: ListItemGroupStyle.CARD }) {
      LazyForEach(this.arr, (item: number) => {
        ListItem() {
          Text("item" + item.toString())
            .height(64)
        }
      })
    }
  }.backgroundColor("#DCDCDC")
  .height("100%")
}
```