# arkui子系统ChangeLog


## cl.arkui.1 编译拦截@Extend/@AnimatableExtend参数个数不符合预期

@Extend/@AnimatableExtend装饰器参数有且仅能有一个。

**变更影响**

当@Extend/@AnimatableExtend装饰器参数有多个时，编译报错。

**错误示例：**

```ts
// xxx.ets

@Extend(Text, Button)  // 编译报错： @Extend should have one and only one parameter
function fancy() {
  .width(100)
}

@AnimatableExtend(Text, Polyline)  // 编译报错： @AnimatableExtend should have one and only one parameter
function fancy2() {
  .height(100)
}

@Entry
@Component
struct Example {
  build() {
    Column() {
      Text('text')
        .fancy()
        .fancy2()
    }
  }
}
```

**关键接口/组件变更**

不涉及

**适配指导**

@Extend和AnimatableExtend装饰器仅能传一个参数。

参考代码如下：
```ts
// xxx.ets

@Extend(Text)
function fancy() {
  .width(100)
}

@AnimatableExtend(Text)
function fancy2() {
  .height(100)
}

@Entry
@Component
struct Example {
  build() {
    Column() {
      Text('text')
        .fancy()
        .fancy2()
    }
  }
}
```

## cl.arkui.2 编译拦截@Link/@ObjectLink成员变量未从父组件传值

子组件的@Link/@ObjectLink成员变量需要从父组件传值。

**变更影响**

子组件的@Link/@ObjectLink当没有从父组件传值时，编译报错。

**错误示例：**

```ts
// xxx.ets

@Observed
class Count {
  message: string = 'count'
}

@Entry
@Component
struct Parent {
  @State state1: string = 'state1';
  @State state2: Count = new Count();
  build() {
    Column() {
      Child()  // 编译报错：Property 'link' in the custom component 'Child' is missing (mandatory to specify).
               // 编译报错：Property 'objectLink' in the custom component 'Child' is missing (mandatory to specify).
    }
  }
}

@Component
struct Child {
  @Link link: string;
  @ObjectLink objectLink: Count;
  build() {
    Column() {
      Text(this.link)
        .fontSize(50)
      Text(this.objectLink.message)
        .fontSize(50)
    }
  }
}
```

**关键接口/组件变更**

不涉及

**适配指导**

子组件的@Link/@ObjectLink成员变量需要从父组件传值。

参考代码如下：
```ts
// xxx.ets

@Observed
class Count {
  message: string = 'count'
}

@Entry
@Component
struct Parent {
  @State state1: string = 'state1';
  @State state2: Count = new Count();
  build() {
    Column() {
      Child({link: $state1, objectLink: this.state2})
    }
  }
}

@Component
struct Child {
  @Link link: string;
  @ObjectLink objectLink: Count;
  build() {
    Column() {
      Text(this.link)
        .fontSize(50)
      Text(this.objectLink.message)
        .fontSize(50)
    }
  }
}
```
## cl.arkui.3 canvas组件onReady事件行为变更

**说明**
onReady事件在组件创建完成后或组件大小发生变化时触发，并清空画布。

**示例：**
```ts
@Entry
@Component
struct OnReadyDiff {
  @State message: string = 'init '
  @State isShow: boolean = false
  @State myHeight: number = 300
  private settings: RenderingContextSettings = new RenderingContextSettings(true);
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('ChangePosition')
          .onClick(()=>{
            this.isShow = !this.isShow
          })
        if (this.isShow) {
          Button('new button')
            .height(200)
        }
        Button('ChangeHeight')
          .onClick(()=>{
            this.myHeight = this.myHeight==300?500:300
          })

        Canvas(this.context)
          .width(300)
          .height(this.myHeight)
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillRect(0, 0, 100, 100)
            this.message += 'a '
          })
        Button('draw another')
          .onClick(()=>{
            this.context.fillRect(100, 100, 100, 100)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

API version 9：onReady在组件创建完成时触发，位置变化时会触发，组件大小变化时也会触发。

![stack](figures/api9onReady.gif)

API version 10及以后：onReady在组件创建完成时触发，在组件位置变化时不会触发，组件大小变化时会触发。

![stack](figures/api10onReady.gif)

**变更影响**

onReady事件在组件位置发生变化时行为变更，API version 9及以前会触发，API version 10及以后不会触发。

## cl.arkui.4 Margin属性百分比计算变更

当前margin会计算两次，margin的百分比参照在第一次margin计算之后会减去margin的大小，计算完之后百分比类型margin第二次计算时数值偏小。变更后margin第一次计算的结果为最终值，不进行第二次计算。

**变更影响**

所有设置百分比的margin大小。

**错误示例：**

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = ''
  controller: TextInputController = new TextInputController()

  build() {
    Column(){
      Row().margin({left:"50%"}).width(100).height(100)
    }.width("100%").height("100%")
  }
}
```

**关键接口/组件变更**

不涉及

**适配指导**

变更后margin的百分比参照固定为父组件的宽减去父组件的padding且不会减去第一次margin的计算结果，其百分比参照比变更前稍大，建议调整margin百分比的数值。

## cl.arkui.5 ListItem长距离划动接口修改

将ListItem长距离划动接口SwipeActionItem命名中的“Delete”替换为“Action”，同时删除useDefaultDeleteAnimation接口。

**变更影响**

使用OpenHarmony_4.0.9.3以后的SDK版本编译时，需使用变更后接口。

**关键接口/组件变更**

| 变更前接口     |  变更后接口     |
| ------ | ------------------------------ |
| deleteAreaDistance   | actionAreaDistance |
| onDelete   |  onAction |
| onEnterDeleteArea   | onEnterActionArea |
| onExitDeleteArea   | onExitActionArea |
| useDefaultDeleteAnimation | 删除 |

**适配指导**

在使用OpenHarmony_4.0.9.3及以后的SDK版本时，SwipeActionItem需使用变更后接口。OpenHarmony_4.0.9.2及之前版本，SwipeActionItem仍遵循变更前规则。

参考代码如下：

```ts
// xxx.ets
@Entry
@Component
struct ListItemExample2 {
  @State message: string = 'Hello World'
  @State arr: number[] = [0, 1, 2, 3, 4]
  @State enterEndDeleteAreaString: string = "not enterEndDeleteArea"
  @State exitEndDeleteAreaString: string = "not exitEndDeleteArea"

  @Builder itemEnd() {
    Row() {
      Button("Delete").margin("4vp")
      Button("Set").margin("4vp")
    }.padding("4vp").justifyContent(FlexAlign.SpaceEvenly)
  }

  build() {
    Column() {
      List({ space: 10 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text("item" + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          .transition({ type: TransitionType.Delete, opacity: 0 })
          .swipeAction({
            end: {
              builder: this.itemEnd.bind(this, item),
              onAction: () => {
                animateTo({ duration: 1000 }, () => {
                  let index = this.arr.indexOf(item)
                  this.arr.splice(index, 1)
                })
              },
              actionAreaDistance: 80,
              onEnterActionArea: () => {
                this.enterEndDeleteAreaString = "enterEndDeleteArea"
                this.exitEndDeleteAreaString = "not exitEndDeleteArea"
              },
              onExitActionArea: () => {
                this.enterEndDeleteAreaString = "not enterEndDeleteArea"
                this.exitEndDeleteAreaString = "exitEndDeleteArea"
              }
            }
          })
        }, item => item)
      }
      Text(this.enterEndDeleteAreaString).fontSize(20)
      Text(this.exitEndDeleteAreaString).fontSize(20)
    }
    .padding(10)
    .backgroundColor(0xDCDCDC)
    .width('100%')
    .height('100%')
  }
}
```