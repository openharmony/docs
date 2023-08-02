# ArkUI Changelog

## cl.arkui.1 状态变量数据类型声明使用限制

所有的状态装饰器变量需要显式声明变量类型，不允许声明any。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct DatePickerExample {
  // 错误写法: @State isLunar: any = false
  @State isLunar: boolean = false

  build() {
   ...
  }
}
```

**变更影响**

如果状态装饰器变量没有显式声明变量类型，声明any，编译拦截等级由WARN变成ERROR。

```ts
// ArkTS:ERROR Please define an explicit type, not any.
@State isLunar: any = false
```

**关键的接口/组件变更**

不涉及。

**适配指导**

状态装饰器变量声明具体的变量类型替代any。


## cl.arkui.2 自定义组件成员变量初始化的规则与约束

不允许从父组件初始化\@LocalStorageLink, \@LocalStorageProp修饰的变量。

**示例：**

```ts
let NextID: number = 0;

@Observed
class ClassA {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

@Entry
@Component
struct LocalStorageComponent {
  build() {
    Column() {
      Child({
        /* ArkTS:ERROR Property 'simpleVarName' in the custom component 'Child' cannot
          initialize here (forbidden to specify). */
        simpleVarName: 1,
        /* ArkTS:ERROR Property 'objectName' in the custom component 'Child' cannot
          initialize here (forbidden to specify). */
        objectName: new ClassA(1)
      })
    }
  }
}

@Component
struct Child {
  @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
  @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA(1);

  build() {
  }
}
```

**变更影响**

如果父组件初始化\@LocalStorageLink, \@LocalStorageProp修饰的变量，编译拦截等级由WARN变成ERROR。

**关键的接口/组件变更**

不涉及。

**适配指导**

构造子组件时，不对子组件的\@LocalStorageLink, \@LocalStorageProp修饰的变量进行赋值。

如果需要在父组件中修改子组件的\@LocalStorageLink, \@LocalStorageProp修饰的变量，则使用LocalStorage提供的API接口方法(比如set方法)赋值。



## cl.arkui.3 通用事件参数支持undefined

通用事件（点击事件、触摸事件、挂载卸载事件、按键事件、焦点事件、鼠标事件、组件区域变化事件）参数支持undefined。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Example {
  build() {
    Button("test")
    .onClick(()=>{
      console.log("click");
    })
    .onClick(undefined)
  }
}
```

**变更影响**

如果事件回调参数为undefined，那么将不再响应已经设置的事件回调。

**关键的接口/组件变更**

不涉及。

**适配指导**

当事件参数设置为undefined，将会禁用该事件，依据实际应用开发场景进行参数设置即可。


## cl.arkui.4 \@Prop/\@BuilderParam 状态变量需要初始化或从父组件传值

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Parent {
  @State message: string = 'Parent'
  build() {
    Column() {
      Child()   // 编译报错
    }
  }
}

@Component
struct Child {
  @Prop message: string
  build() {
    Column() {
      
    }
  }
}
```

**变更影响**

当\@Prop/\@BuilderParam 状态变量未初始化且未从父组件传值时，编译无法通过。

**关键的接口/组件变更**

不涉及。

**适配指导**

对\@Prop/\@BuilderParam 状态变量做初始化赋值或从父组件调用子组件时传入。


## cl.arkui.5 \@BuilderParam 状态变量初始化赋值必须为\@Builder函数/方法

**示例：**

```ts
// xxx.ets
@Builder
function builderFunction() {
  Text('Hello Builder')
}

function normal () {

}

@Component
struct Index {
  @BuilderParam builderParam: ()=>void = builderFunction
  @BuilderParam builderParam2: ()=>void = normal   // 编译报错
  build() {
    Column() {

    }
  }
}
```

**变更影响**

\@BuilderParam 状态变量初始化赋值非\@Builder方法时，编译无法通过。

**关键的接口/组件变更**

不涉及。

**适配指导**

\@BuilderParam 状态变量初始化赋值传入\@Builder方法。


## cl.arkui.6 Search组件的searchButton属性中SearchButtonOption修改为SearchButtonOptions

**变更影响**

如果显式地使用了SearchButtonOption类型，编译无法通过。

**关键的接口/组件变更**

searchButton属性中类型SearchButtonOption修改为SearchButtonOptions。

**适配指导**

SearchButtonOption修改为SearchButtonOptions。


## cl.arkui.7 滚动事件上报滚动状态枚举值规则变更

ScrollState枚举值在API version 9及以下上报规则：

| 名称 | 描述 | 
| -------- | -------- |
| Idle | 空闲状态。使用控制器提供的方法滚动、拖动滚动条滚动时触发。 | 
| Scroll | 手指拖动状态。使用手指拖动List滚动时触发。 | 
| Fling | 惯性滚动状态。快速划动松手后惯性滚动和划动到边缘回弹时触发。 | 

从API version 10开始，ScrollState上报规则变更为：

| 名称 | 描述 | 
| -------- | -------- |
| Idle | 空闲状态。滚动状态回归空闲的时候触发，一个滚动流程的最后一帧回调。控制器提供的无动画的方法控制的滚动也会触发。 | 
| Scroll | 滚动状态。手指拖动List滚动时触发，拖动滚动条滚动时触发，滚动鼠标滚轮触发。 | 
| Fling | 惯性滚动状态。由动画触发的滚动，包括快速划动松手后的惯性滚动，划动到边缘回弹的滚动，快速拖动内置滚动条松手后的惯性滚动，使用滚动控制器提供的带动画的方法控制的滚动。 | 

ScrollState枚举变更如下。

| 场景 | API&nbsp;version&nbsp;9及以下 | API&nbsp;version&nbsp;10开始 | 
| -------- | -------- | -------- |
| 手指拖动滑动 | Scroll | Scroll | 
| 惯性滚动 | Fling | Fling | 
| 过界回弹 | Fling | Fling | 
| 鼠标滚轮滚动 | Idle | Scroll | 
| 拖动滚动条 | Idle | Scroll | 
| 滚动控制器滚动（带动画） | Idle | Fling | 
| 滚动控制器滚动（不带动画） | Idle | Idle | 

**变更影响**

1、ScrollState枚举值从API version 7开始提供，在API version 10变更，不影响API version 9及以下版本使用。

2、API version 9及以下使用到这个枚举值的接口有List组件的onScroll事件、onScrollFrameBegin事件、Scroll组件的onScrollFrameBegin事件，API version 9及以下滚动状态上报规则不变，不会产生影响；从API version 10开始，List组件的onScroll事件在文章起始列出的部分场景中上报的枚举值会有变化。

**关键接口/组件变更**

List组件接口文档：

- [List组件事件](https://harmonyosdevelopertest.devccsrnd.hwcloudtest.cn:3087/cn/docs/documentation/doc-references/ts-container-list-0000001580185770#ZH-CN_TOPIC_0000001656797053__%E4%BA%8B%E4%BB%B6)

- [List组件ScrollState枚举说明](https://harmonyosdevelopertest.devccsrnd.hwcloudtest.cn:3087/cn/docs/documentation/doc-references/ts-container-list-0000001580185770#ZH-CN_TOPIC_0000001656797053__scrollstate%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E)

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


## cl.arkui.8 ArkUI系统组件使用限制

对ArkUI系统组件的使用场景进行限制，仅允许在struct的build方法内、pageTransition方法内或\@Builder修饰的函数内使用。

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

如果ArkUI系统组件在限制（struct的build方法内，pageTransition方法内，\@Builder修饰的函数内）以外的地方使用，会导致编译报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

将ArkUI系统组件的调用修改到struct的build方法内、pageTransition方法内或\@Builder修饰的函数内。


## cl.ArkUI.9 \@Prop在API 9支持Object浅拷贝，API 10变更为深拷贝

**变更影响**

\@Prop支持Object在API 9为浅拷贝，具体行为表现为：

- Object类型：浅拷贝Object.keys(propObj) 返回的所有属性。即只拷贝最外层的Object，Object中property还是指向原来的父组件的数据源。

- 数组类型：浅拷贝所有的数组项，即只拷贝最外层的array，其他行为和Object一致。

- 拷贝Object和数组的prototype。

\@Prop支持Object在API 10变更为深拷贝，具体行为表现为：

- Object类型：完全拷贝Object.keys(propObj) 返回的所有属性。

- 数组类型：完全拷贝所有的数组项；

- 拷贝Object和数组的prototype。

**适配指导**

\@Prop深浅拷贝的变更在UI渲染上的影响主要在\@ObjectLink相关的场景，因为\@ObjectLink会代理其修饰对象属性。

例子如下：

api9：PropClassAArray组件中\@Prop objArray改变ClassA的属性，或者设置新的数组项，都会引起父组件StateClassAArray创建的ObjectLinkClassA中的\@ObjectLink obj的改变。

这个更新是因为父组件StateClassAArray中\@State stateClassAArray到子组件PropClassAArray中\@Prop objArray是浅拷贝引起的，因为浅拷贝只拷贝了数组项的引用，所以数据源也被改变，而\@ObjectLink代理了数据源的属性，所以引发了ObjectLinkClassA组件中的\@ObjectLink obj的更新（从StateClassAArray组件中构造的）。

api10：在上述场景中，因为父组件StateClassAArray中\@State stateClassAArray到子组件PropClassAArray中\@Prop objArray是深拷贝，完整拷贝了ClassA的对象，所以不会改变数据源，从而不会引发ObjectLinkClassA组件中的\@ObjectLink obj的更新（从StateClassAArray组件中构造的）。

![zh-cn_image_0000001621772152](figures/zh-cn_image_0000001621772152.png)

```ts
let nextId = 0;

@Observed
class ClassA  {
  id : number;
  a : number;
  constructor(a : number = 0) {
    this.id = nextId++;
    this.a = a;
  }
}

@Component
struct ObjectLinkClassA {
  @ObjectLink obj : ClassA;

  build() {
    Row() {
      Text(`ObjectLink: obj: ${this.obj.a}`)
        .height(100)
        .onClick(() => {
          this.obj.a += 1;
          console.info(`ObjectLink onClick ClassA property changed to  ${this.obj.a}`)
        })
    }.border({width: 3, color: Color.Red})
  }
}

@Component
struct PropClassAArray {
  @Prop objArray : Array<ClassA> = [];

  build() {
    Column() {
      Text(`green box: @Prop : Array<ObjectClassA> item [0] + [1]`)
      Row() {
        ObjectLinkClassA({ obj:  this.objArray[0] })
        Text("[0] Assign new ClassA")
          .height(100)
          .onClick(() => {
            this.objArray[0] = new ClassA();
            console.info(`PropClassAArray[0] onClick ClassA object assign ${this.objArray[0].a}`)
          })
        Text("Change ClassA property")
          .height(100)
          .onClick(() => {
            this.objArray[0].a += 1;
            console.info(`PropClassAArray[1] onClick ClassA property change  ${this.objArray[1].a}`)
          })
      }
    }.border({width: 3, color: Color.Green})
  }
}

@Entry
@Component
struct StateClassAArray {
  @State stateClassAArray : Array<ClassA> = [ new ClassA(), new ClassA() ];

  build() {
    Column() {
      Column() {
        Text("Red box: @ObjectLink from @State array item[0]")
        Row() {
          ObjectLinkClassA({obj : this.stateClassAArray[0] })
          Text("Assign new ClassA")
            .height(100)
            .onClick(() => {
              this.stateClassAArray[0] = new ClassA();
              console.info(`StateClassAArray[0] onClick ClassA object assign ${this.stateClassAArray[0].a}`)
            })
          Text("Change ClassA property")
            .height(100)
            .onClick(() => {
              this.stateClassAArray[0].a += 1;
              console.info(`StateClassAArray onClick stateClassAArray[0] changed to  ${this.stateClassAArray[0].a}`)
            })
        }

      }.border({width: 3, color: Color.Blue})

      Divider().height(5)

      // api9浅拷贝：只拷贝指向源数组项的引用，不拷贝数组项ClassA实例自身
      // api10深拷贝：完整拷贝this.stateClassAArray，包括其数组项。
      PropClassAArray({ objArray: this.stateClassAArray })
    }
  }
}
```


## cl.arkui.10 编译拦截\@Extend/\@AnimatableExtend参数个数不符合预期

\@Extend/\@AnimatableExtend装饰器参数有且仅能有一个。

**变更影响**

当\@Extend/\@AnimatableExtend装饰器参数有多个时，编译报错。

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

\@Extend和AnimatableExtend装饰器仅能传一个参数。

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


## cl.arkui.11 编译拦截\@Link/\@ObjectLink成员变量未从父组件传值

子组件的\@Link/\@ObjectLink成员变量需要从父组件传值。

**变更影响**

子组件的\@Link/\@ObjectLink当没有从父组件传值时，编译报错。

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

子组件的\@Link/\@ObjectLink成员变量需要从父组件传值。

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


## cl.arkui.12 canvas组件onReady事件行为变更

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

![zh-cn_image_0000001669812181](figures/zh-cn_image_0000001669812181.gif)

API version 10及以后：onReady在组件创建完成时触发，在组件位置变化时不会触发，组件大小变化时会触发。

![zh-cn_image_0000001621452400](figures/zh-cn_image_0000001621452400.gif)

**变更影响**

onReady事件在组件位置发生变化时行为变更，API version 9及以前会触发，API version 10及以后不会触发。


## cl.arkui.13 Navigation menus属性显示变更

**变更影响**

menus的value属性值不做显示，如果需要显示，可以使用自定义Builder显示。

**示例：**

```ts
@Entry
@Component
struct Index {
  build() {
    Column() {
      Navigation() {
        Text('Navigation')
      }.title("Navigation Menu")
      .menus([
        {icon: 'common/image/icon.png', value: 'menu1'},
        {icon: 'common/image/icon.png', value: 'menu2'},
        {icon: 'common/image/icon.png', value: 'menu3'}
      ])
    }
  }
}
```

API Version 9：menus的value属性会显示

![zh-cn_image_0000001670132021](figures/zh-cn_image_0000001670132021.png)

API Version 10: menus中的value属性不显示

![zh-cn_image_0000001621612228](figures/zh-cn_image_0000001621612228.png)


## cl.arkui.14 Navigation的titleMode属性Free模式默认显示位置变更

**变更影响**

1. Navigation组件自定义标题并titleMode设置为Full模式或Free模式显示位置相同

2. 使用自定义title结合Free模式的标签会出现标签位置向右偏移

**示例：**

```ts
@Entry
@Component
struct Index {
  @Builder NavigationTile() {
    Column() {
      Text('title').fontColor('#182431').fontSize(30).lineHeight(41)
      Text('subTitle').fontColor('#182431').fontSize(14).lineHeight(19).margin(top:2, bottom: 20)
    }
  }

  build() {
    Column() {
      Navigation() {
        Text('Navigation')
      }.title(this.NavigationTitle)
       .titleMode(NavigationTitleMode.Free)
       .menus([
        {icon: 'common/image/icon.png', value: 'menu1'}
       ])
    }
  }
}
```

API Version 9: Free模式显示位置

![zh-cn_image_0000001621932120](figures/zh-cn_image_0000001621932120.png)

API Version 10: Free模式显示位置与Full模式显示位置相同

![zh-cn_image_0000001670212013](figures/zh-cn_image_0000001670212013.png)
