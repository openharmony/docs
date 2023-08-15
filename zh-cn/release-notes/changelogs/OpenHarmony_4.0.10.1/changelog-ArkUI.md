# ArkUI子系统changelog

## cl.arkui.1 状态变量支持undefined和null

**变更影响**

API version 9：状态变量不支持undefined和null，当开发者给状态变量设置undefined或者null时，设置失败，即状态变量还是上一次的值。

API version 10：状态变量支持undefined和null，当开发者给状态变量设置undefined和null时，ArkUI框架会接受该值，即下一次读状态变量的是undefined和null，开发者要注意做判空保护。

**适配指导**

API version 9，当开发者给状态变量设置undefined时，设置无效，会导致开发者忽略对undefined的校验。
```ts
@Entry
@Component
struct Page3 {
  @State messages: string[] = ['Hello World']

  aboutToAppear() {
    // AppStorage里没有对应的key，返回undefined
    // API version 9：赋值不生效，ArkUI框架会拒绝undefined，this.messages还为其初始值['Hello World']
    // API version 10: 赋值生效，ArkUI框架会接受undefined，this.messages为undefined
    this.messages = AppStorage.Get("aProp")
  }

  build() {
    Row() {
      Column() {
        // API version 9: 应用没有crash，length为1 
        // API version 10：应用crash, Error message: Cannot read property length of undefined
        Text(`the messages length: ${this.messages.length}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

对于上述情况，当每一次给状态变量赋值undefined和null时，需要对状态变量是否为undefined做校验。

```ts
Text(`the messages length: ${this.messages?.length}`)
```

API version 10，ArkUI框架增强对状态变量类型和初始化的校验，ArkUI框架会抛出运行时报错。具体有以下两种情况：
1. @Link必须被父组件初始化。

对于以下示例，当前会抛出运行时报错，提示开发者需要初始化@Link。
```ts
@Entry
@Component
struct Page3 {
  @State aProp: boolean = true

  build() {
    Row() {
      Column() {
        // crash: SynchedPropertyObjectTwoWayPU[9, 'linkProp']: constructor @Link/@Consume source variable in
        // parent/ancestor @Component must be defined. Application error!
        LinkChild()
        // 错误的用常规变量初始化linkProp，ArkUI框架无认为没有初始化，和上述一样的报错
        LinkChild({ aProp: false })
        // 正确，用状态变量this.aProp初始化@Link
        LinkChild({ aProp: this.aProp })
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
struct LinkChild {
  @Link aProp: boolean

  build() {
    Text(`linkProp: ${this.aProp}`)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

2. 校验状态变量不支持的类型。

状态变量对于不支持的类型，比如function，抛出运行时报错来提示开发者。
```ts
@Entry
@Component
struct Page3 {
  // API version 10：运行时报错：@Component 'Page3': Illegal variable value error with decorated variable @State/@Provide 'functionProp': failed
  // validation: 'undefined, null, number, boolean, string, or Object but not function, attempt to assign value type: 'function', 
  @State functionProp: () => void = () => {
    console.info("123")
  }

  aboutToAppear() {
    this.functionProp()
  }

  build() {
    Row() {
      Column() {
        Text("hello")
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## cl.arkui.2 @StorageLink在页面跳转和页签场景行为优化

**变更影响**

AppStorage是应用全局的UI状态存储，@StorageLink是对AppStorage中对应key的双向同步，即@StorageLink修饰的变量的改变会同步回AppStorage，AppStorage的修改也会同步给@StorageLink。
当AppStorage某一个key发生改变时，会通知所有绑定该key的@StorageLink，@StorageLink装饰的变量的改变，会触发组件的重新渲染，包括不可见页面或者TabContent组件，这就造成了不必要的更新和性能浪费。

本次优化针对两个场景做出了优化：
1. 不可见页面的@StorageLink不会被通知刷新。
2. 不可见TabContent的@StorageLink不会被通知刷新。
AppStorage的属性改变，将不立即通知这两个场景下的@StorageLink更新和其@Watch回调，而是当页面或TabContent重新回到激活状态时，即可见状态，再去触发UI更新和其@Watch回调。

可见切换不可见状态或不可见切换可见状态流程如下：
1. 页面或TabContent内的自定义组件从可见到不可见，即标记组件为inActive。
2. 当AppStorage的属性变化时，标记不可见节点的@StorageLink装饰的变量已经变化，但不通知UI刷新。
3. 当页面或TabContent重新可见，即从inActive回到Active状态，将@StorageLink的dependentElementIds添加到其所属自定义组件的脏节点，调用其@Watch方法，刷新UI。

这次优化带来的最重要的应用行为变更是：不可见的页面和TabContent的@StorageLink的watch方法将不被回调。当其回到可见状态时，才会触发@Watch方法回调和UI更新。

**适配指导**

不建议开发者通过借助@StorageLink和@Watch作为事件通知机制，因为@StorageLink是和UI强相关的装饰器，更新成本相较于一般的事件通知机制emit较高。

TapImage中的点击事件，会触发AppStorage中tapIndex对应属性的改变。因为@StorageLink是双向同步，修改会同步会AppStorage中，所以，所有绑定AppStorage的tapIndex可见自定义组件都会被通知UI刷新。UI刷新带来的成本是巨大的，因此不建议开发者使用此方式来实现基本的事件通知功能。

```ts
// xxx.ets
class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri
  }
}

@Entry
@Component
struct Gallery2 {
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))]
  scroller: Scroller = new Scroller()

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData, index?: number) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: index
            })
          }.aspectRatio(1)

        }, (item: ViewData, index?: number) => {
          return JSON.stringify(item) + index;
        })
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @StorageLink('tapIndex') @Watch('onTapIndexChange') tapIndex: number = -1;
  @State tapColor: Color = Color.Black;
  private index: number;
  private uri: Resource;

  // 判断是否被选中
  onTapIndexChange() {
    if (this.tapIndex >= 0 && this.index === this.tapIndex) {
      console.info(`tapindex: ${this.tapIndex}, index: ${this.index}, red`)
      this.tapColor = Color.Red;
    } else {
      console.info(`tapindex: ${this.tapIndex}, index: ${this.index}, black`)
      this.tapColor = Color.Black;
    }
  }

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .onClick(() => {
          this.tapIndex = this.index;
        })
        .border({ width: 5, style: BorderStyle.Dotted, color: this.tapColor })
    }

  }
}
```

开发者可以使用emit订阅某个事件并接收事件回调，可以减少开销，增强代码的可读性。


```ts
// xxx.ets
import emitter from '@ohos.events.emitter';

let NextID: number = 0;

class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;
  id: number;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri
    this.id = NextID++;
  }
}

@Entry
@Component
struct Gallery2 {
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))]
  scroller: Scroller = new Scroller()
  private preIndex: number = -1

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: item.id
            })
          }.aspectRatio(1)
          .onClick(() => {
            if (this.preIndex === item.id) {
              return
            }
            var innerEvent = { eventId: item.id }
            // 选中态：黑变红
            var eventData = {
              data: {
                "colorTag": 1
              }
            }
            emitter.emit(innerEvent, eventData)

            if (this.preIndex != -1) {
              console.info(`preIndex: ${this.preIndex}, index: ${item.id}, black`)
              var innerEvent = { eventId: this.preIndex }
              // 取消选中态：红变黑
              var eventData = {
                data: {
                  "colorTag": 0
                }
              }
              emitter.emit(innerEvent, eventData)
            }
            this.preIndex = item.id
          })

        }, (item: ViewData) => JSON.stringify(item))
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @State tapColor: Color = Color.Black;
  private index: number;
  private uri: Resource;

  onTapIndexChange(colorTag: emitter.EventData) {
    this.tapColor = colorTag.data.colorTag ? Color.Red : Color.Black
  }

  aboutToAppear() {
    //定义事件ID
    var innerEvent = { eventId: this.index }
    emitter.on(innerEvent, this.onTapIndexChange.bind(this))
  }

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .border({ width: 5, style: BorderStyle.Dotted, color: this.tapColor })
    }
  }
}
```

以上通知事件逻辑简单，也可以简化成三元表达式。

```
// xxx.ets
class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri
  }
}

@Entry
@Component
struct Gallery2 {
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))]
  scroller: Scroller = new Scroller()

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData, index?: number) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: index
            })
          }.aspectRatio(1)

        }, (item: ViewData, index?: number) => {
          return JSON.stringify(item) + index;
        })
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @StorageLink('tapIndex') tapIndex: number = -1;
  @State tapColor: Color = Color.Black;
  private index: number;
  private uri: Resource;

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .onClick(() => {
          this.tapIndex = this.index;
        })
        .border({
          width: 5,
          style: BorderStyle.Dotted,
          color: (this.tapIndex >= 0 && this.index === this.tapIndex) ? Color.Red : Color.Black
        })
    }
  }
}
```
