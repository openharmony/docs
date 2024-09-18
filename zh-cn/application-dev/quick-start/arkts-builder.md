# \@Builder装饰器：自定义构建函数

ArkUI提供了一种轻量的UI元素复用机制\@Builder，该自定义组件内部UI结构固定，仅与使用方进行数据传递，开发者可以将重复使用的UI元素抽象成一个方法，在build方法里调用。

为了简化语言，我们将\@Builder装饰的函数也称为“自定义构建函数”。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

## 限制条件

- \@Builder通过按引用传递的方式传入参数，才会触发动态渲染UI，并且参数只能是一个。

- \@Builder如果传入的参数是两个或两个以上，不会触发动态渲染UI。

- \@Builder传入的参数中同时包含按值传递和按引用传递两种方式，不会触发动态渲染UI。

- \@Builder的参数必须按照对象字面量的形式，把所需要的属性一一传入，才会触发动态渲染UI。

## 装饰器使用说明

### 私有自定义构建函数

定义的语法：

```ts
@Builder MyBuilderFunction() {}
```

使用方法：

```ts
this.MyBuilderFunction()
```

- 允许在自定义组件内定义一个或多个@Builder方法，该方法被认为是该组件的私有、特殊类型的成员函数。

- 自定义构建函数可以在所属组件的build方法和其他自定义构建函数中调用，但不允许在组件外调用。

- 在自定义函数体中，this指代当前所属组件，组件的状态变量可以在自定义构建函数内访问。建议通过this访问自定义组件的状态变量而不是参数传递。


### 全局自定义构建函数

定义的语法：

```ts
@Builder function MyGlobalBuilderFunction() { ... }
```

使用方法：

```ts
MyGlobalBuilderFunction()
```

- 如果不涉及组件状态变化，建议使用全局的自定义构建方法。


## 参数传递规则

自定义构建函数的参数传递有[按值传递](#按值传递参数)和[按引用传递](#按引用传递参数)两种，均需遵守以下规则：

- 参数的类型必须与参数声明的类型一致，不允许undefined、null和返回undefined、null的表达式。

- 在@Builder修饰的函数内部，不允许改变参数值。

- \@Builder内UI语法遵循[UI语法规则](arkts-create-custom-components.md#build函数)。

- 只有传入一个参数，且参数需要直接传入对象字面量才会按引用传递该参数，其余传递方式均为按值传递。


### 按引用传递参数

按引用传递参数时，传递的参数可为状态变量，且状态变量的改变会引起\@Builder方法内的UI刷新。

```ts
class Tmp {
  paramA1: string = ''
}

@Builder function overBuilder(params: Tmp) {
  Row() {
    Text(`UseStateVarByReference: ${params.paramA1} `)
  }
}
@Entry
@Component
struct Parent {
  @State label: string = 'Hello';
  build() {
    Column() {
      // Pass the this.label reference to the overBuilder component when the overBuilder component is called in the Parent component.
      overBuilder({ paramA1: this.label })
      Button('Click me').onClick(() => {
        // After Click me is clicked, the UI text changes from Hello to ArkUI.
        this.label = 'ArkUI';
      })
    }
  }
}
```

按引用传递参数时，如果在\@Builder方法内调用自定义组件，ArkUI提供[$$](arkts-two-way-sync.md)作为按引用传递参数的范式。

```ts
class Tmp {
  paramA1: string = ''
}

@Builder function overBuilder($$: Tmp) {
  Row() {
    Column() {
      Text(`overBuilder===${$$.paramA1}`)
      HelloComponent({message: $$.paramA1})
    }
  }
}

@Component
struct HelloComponent {
  @Prop message: string;

  build() {
    Row() {
      Text(`HelloComponent===${this.message}`)
    }
  }
}

@Entry
@Component
struct Parent {
  @State label: string = 'Hello';
  build() {
    Column() {
      // Pass the this.label reference to the overBuilder component when the overBuilder component is called in the Parent component.
      overBuilder({paramA1: this.label})
      Button('Click me').onClick(() => {
        // After Click me is clicked, the UI text changes from Hello to ArkUI.
        this.label = 'ArkUI';
      })
    }
  }
}
```

### 按值传递参数

调用\@Builder装饰的函数默认按值传递。当传递的参数为状态变量时，状态变量的改变不会引起\@Builder方法内的UI刷新。所以当使用状态变量的时候，推荐使用[按引用传递](#按引用传递参数)。

```ts
@Builder function overBuilder(paramA1: string) {
  Row() {
    Text(`UseStateVarByValue: ${paramA1} `)
  }
}
@Entry
@Component
struct Parent {
  @State label: string = 'Hello';
  build() {
    Column() {
      overBuilder(this.label)
    }
  }
}
```

使用按值传递的方式，在@ComponentV2装饰器修饰的自定义组件里配合使用@ObservedV2和@Trace装饰器可以实现刷新UI功能。

【正例】

在@ComponentV2装饰中，只有使用@ObservedV2修饰的ParamTmp类和@Trace修饰的count属性才可以触发UI的刷新。

```ts
@ObservedV2
class ParamTmp {
  @Trace count : number = 0;
}

@Builder
function renderText(param: ParamTmp) {
  Column() {
    Text(`param : ${param.count}`)
      .fontSize(20)
      .fontWeight(FontWeight.Bold)
  }
}

@Builder
function renderMap(paramMap: Map<string,number>) {
  Text(`paramMap : ${paramMap.get('name')}`)
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
}

@Builder
function renderSet(paramSet: Set<number>) {
  Text(`paramSet : ${paramSet.size}`)
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
}

@Builder
function renderNumberArr(paramNumArr: number[]) {
  Text(`paramNumArr : ${paramNumArr[0]}`)
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
}

@Entry
@ComponentV2
struct PageBuilder {
  @Local builderParams: ParamTmp = new ParamTmp();
  @Local map_value: Map<string,number> = new Map();
  @Local set_value: Set<number> = new Set([0]);
  @Local numArr_value: number[] = [0];
  private progressTimer: number = -1;

  aboutToAppear(): void {
    this.progressTimer = setInterval(() => {
      if (this.builderParams.count < 100) {
        this.builderParams.count += 5;
        this.map_value.set('name', this.builderParams.count);
        this.set_value.add(this.builderParams.count);
        this.numArr_value[0] = this.builderParams.count;
      } else {
        clearInterval(this.progressTimer)
      }
    }, 500);
  }

  @Builder
  localBuilder() {
    Column() {
      Text(`localBuilder : ${this.builderParams.count}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }

  build() {
    Column() {
      this.localBuilder()
      Text(`builderParams :${this.builderParams.count}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      renderText(this.builderParams)
      renderText({ count: this.builderParams.count })
      renderMap(this.map_value)
      renderSet(this.set_value)
      renderNumberArr(this.numArr_value)
    }
    .width('100%')
    .height('100%')
  }
}
```

【反例】

在@ComponentV2装饰的自定义组件中，使用简单数据类型不可以触发UI的刷新。

```ts
@ObservedV2
class ParamTmp {
  @Trace count : number = 0;
}

@Builder
function renderNumber(paramNum: number) {
  Text(`paramNum : ${paramNum}`)
    .fontSize(30)
    .fontWeight(FontWeight.Bold)
}

@Entry
@ComponentV2
struct PageBuilder {
  @Local class_value: ParamTmp = new ParamTmp();
  // 此处使用简单数据类型不支持刷新UI的能力。
  @Local num_value: number = 0;
  private progressTimer: number = -1;

  aboutToAppear(): void {
    this.progressTimer = setInterval(() => {
      if (this.class_value.count < 100) {
        this.class_value.count += 5;
        this.num_value += 5;
      } else {
        clearInterval(this.progressTimer)
      }
    }, 500);
  }

  build() {
    Column() {
      renderNumber(this.num_value)
    }
    .width('100%')
    .height('100%')
    .padding(50)
  }
}
```

## 使用场景

### 自定义组件内使用自定义构建函数

创建私有的\@Builder方法，在Column里面使用this.builder()方式调用，通过aboutToAppear生命周期函数和按钮的点击事件改变builder_value的内容，实现动态渲染UI。

```ts
@Entry
@Component
struct PrivateBuilder {
  @State builder_value: string = 'Hello';

  @Builder builder() {
    Column(){
      Text(this.builder_value)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }

  aboutToAppear(): void {
    setTimeout(() => {
      this.builder_value = 'Hello World';
    },3000)
  }

  build() {
    Row() {
      Column() {
        Text(this.builder_value)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
        this.builder()
        Button('点击改变builder_value内容')
          .onClick(() => {
            this.builder_value ='builder_value被点击了'
          })
      }
    }
  }
}
```

### 使用全局自定义构建函数

创建全局的\@Builder方法，在Column里面使用overBuilder()方式调用，通过以对象字面量的形式传递参数，无论是简单类型还是复杂类型，值的改变都会引起UI界面的刷新。

```ts
class ChildTmp {
  val: number = 1;
}

class Tmp {
  str_value: string = 'Hello';
  num_value: number = 0;
  tmp_value: ChildTmp = new ChildTmp();
  arrayTmp_value: Array<ChildTmp> = [];
}

@Builder function overBuilder(param: Tmp) {
  Column() {
    Text(`str_value: ${param.str_value}`)
    Text(`num_value: ${param.num_value}`)
    Text(`tmp_value: ${param.tmp_value.val}`)
    ForEach(param.arrayTmp_value, (item: ChildTmp) => {
      Text(`arrayTmp_value: ${item.val}`)
    }, (item: ChildTmp) => JSON.stringify(item))
  }
}

@Entry
@Component
struct Parent {
  @State objParam: Tmp = new Tmp();
  build() {
    Column() {
      Text('通过调用@Builder渲染UI界面')
        .fontSize(20)
      overBuilder({str_value: this.objParam.str_value, num_value: this.objParam.num_value, tmp_value: this.objParam.tmp_value, arrayTmp_value: this.objParam.arrayTmp_value})
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('点击改变参数值').onClick(() => {
        this.objParam.str_value = 'Hello World';
        this.objParam.num_value = 1;
        this.objParam.tmp_value.val = 8;
        const child_value: ChildTmp = {
          val: 2
        }
        this.objParam.arrayTmp_value.push(child_value)
      })
    }
  }
}
```

### 修改装饰器修饰的变量触发UI刷新

此种方式是使用了装饰器的特性，监听值的改变触发UI刷新，不通过\@Builder传递参数。

```ts
class Tmp {
  str_value: string = 'Hello';
}

@Entry
@Component
struct Parent {
  @State objParam: Tmp = new Tmp();
  @State label: string = 'World';

  @Builder privateBuilder() {
    Column() {
      Text(`wrapBuilder str_value: ${this.objParam.str_value}`)
      Text(`wrapBuilder num: ${this.label}`)
    }
  }

  build() {
    Column() {
      Text('通过调用@Builder渲染UI界面')
        .fontSize(20)
      this.privateBuilder()
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('点击改变参数值').onClick(() => {
        this.objParam.str_value = 'str_value Hello World';
        this.label = 'label Hello World'
      })
    }
  }
}
```

### 使用全局和局部的@Builder传入customBuilder类型

```ts
@Builder
function overBuilder() {
  Row() {
    Text('全局 Builder')
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
}

@Entry
@Component
struct customBuilderDemo {
  @State arr: number[] = [0, 1, 2, 3, 4];

  @Builder privateBuilder() {
    Row() {
      Text('局部 Builder')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }

  build() {
    Column() {
      List({ space: 10 }) {
        ForEach(this.arr, (item: number) => {
          ListItem(){
            Text(`${item}`)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
            .swipeAction({
              start: {
                builder: overBuilder()
              },
              end: {
                builder: () => { this.privateBuilder() }
              }
            })
        }, (item: string) => JSON.stringify(item))
      }
    }
  }
}
```

### 多层\@Builder方法嵌套使用

在\@Builder方法内调用自定义组件或者其他\@Builder方法，ArkUI提供[$$](arkts-two-way-sync.md)作为按引用传递参数的范式。

```ts
class Tmp {
  paramA1: string = '';
}

@Builder function parentBuilder($$: Tmp) {
  Row() {
    Column() {
      Text(`parentBuilder===${$$.paramA1}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      HelloComponent({message: $$.paramA1})
      childBuilder({paramA1: $$.paramA1})
    }
  }
}

@Component
struct HelloComponent {
  @Prop message: string = '';

  build() {
    Row() {
      Text(`HelloComponent===${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Builder
function childBuilder($$: Tmp) {
  Row() {
    Column() {
      Text(`childBuilder===${$$.paramA1}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      HelloChildComponent({message: $$.paramA1})
      grandsonBuilder({paramA1: $$.paramA1})
    }
  }
}

@Component
struct HelloChildComponent {
  @State message: string = '';
  build() {
    Row() {
      Text(`HelloChildComponent===${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Builder function grandsonBuilder($$: Tmp) {
  Row() {
    Column() {
      Text(`grandsonBuilder===${$$.paramA1}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      HelloGrandsonComponent({message: $$.paramA1})
    }
  }
}

@Component
struct HelloGrandsonComponent {
  @Prop message: string;
  build() {
    Row() {
      Text(`HelloGrandsonComponent===${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Entry
@Component
struct Parent {
  @State label: string = 'Hello';
  build() {
    Column() {
      parentBuilder({paramA1: this.label})
      Button('Click me').onClick(() => {
        this.label = 'ArkUI';
      })
    }
  }
}
```

### \@Builder函数联合V2装饰器使用

使用全局@Builder和局部@Builder在@ComponentV2修饰的自定义组件中调用，修改相关变量触发UI刷新。

```ts
@ObservedV2
class Info {
  @Trace name: string = '';
  @Trace age: number = 0;
}

@Builder
function overBuilder(param: Info) {
  Column() {
    Text(`全局@Builder name :${param.name}`)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
    Text(`全局@Builder age :${param.age}`)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
}

@ComponentV2
struct ChildPage {
  @Require @Param childInfo: Info;
  build() {
    overBuilder({name: this.childInfo.name, age: this.childInfo.age})
  }
}

@Entry
@ComponentV2
struct ParentPage {
  info1: Info = { name: "Tom", age: 25 };
  @Local info2: Info = { name: "Tom", age: 25 };

  @Builder
  privateBuilder() {
    Column() {
      Text(`局部@Builder name :${this.info1.name}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      Text(`局部@Builder age :${this.info1.age}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }

  build() {
    Column() {
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      this.privateBuilder() // 调用局部@Builder
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      overBuilder({ name: this.info2.name, age: this.info2.age}) // 调用全局@Builder
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info1}) // 调用自定义组件
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info2}) // 调用自定义组件
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button("change info1&info2")
        .onClick(() => {
          this.info1 = { name: "Cat", age: 18} // Text1不会刷新，原因是没有装饰器修饰监听不到值的改变。
          this.info2 = { name: "Cat", age: 18} // Text2会刷新，原因是有装饰器修饰，可以监听到值的改变。
        })
    }
  }
}
```

## 常见问题

### \@Builder存在两个或者两个以上参数

当参数存在两个或者两个以上的时候，就算通过对象字面量的形式传递，值的改变也不会引起UI刷新。

【反例】

```ts
class GlobalTmp {
  str_value: string = 'Hello';
}

@Builder function overBuilder(param: GlobalTmp, num: number) {
  Column() {
    Text(`str_value: ${param.str_value}`)
    Text(`num: ${num}`)
  }
}

@Entry
@Component
struct Parent {
  @State objParam: GlobalTmp = new GlobalTmp();
  @State num: number = 0;
  build() {
    Column() {
      Text('通过调用@Builder渲染UI界面')
        .fontSize(20)
      overBuilder({str_value: this.objParam.str_value}, this.num) // 此处出现问题，使用了两个参数。
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('点击改变参数值').onClick(() => {
        this.objParam.str_value = 'Hello World';
        this.num = 1;
      })
    }
  }
}
```

【反例】

```ts
class GlobalTmp {
  str_value: string = 'Hello';
}
class SecondTmp {
  num_value: number = 0;
}
@Builder function overBuilder(param: GlobalTmp, num: SecondTmp) {
  Column() {
    Text(`str_value: ${param.str_value}`)
    Text(`num: ${num.num_value}`)
  }
}

@Entry
@Component
struct Parent {
  @State strParam: GlobalTmp = new GlobalTmp();
  @State numParam: SecondTmp = new SecondTmp();
  build() {
    Column() {
      Text('通过调用@Builder渲染UI界面')
        .fontSize(20)
      overBuilder({str_value: this.strParam.str_value}, {num_value: this.numParam.num_value}) // 此处出现问题，使用了两个参数。
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('点击改变参数值').onClick(() => {
        this.strParam.str_value = 'Hello World';
        this.numParam.num_value = 1;
      })
    }
  }
}
```

\@Builder只接受一个参数，当传入一个参数的时候，通过对象字面量的形式传递，值的改变会引起UI的刷新。

【正例】

```ts
class GlobalTmp {
  str_value: string = 'Hello';
  num_value: number = 0;
}
@Builder function overBuilder(param: GlobalTmp) {
  Column() {
    Text(`str_value: ${param.str_value}`)
    Text(`num: ${param.num_value}`)
  }
}

@Entry
@Component
struct Parent {
  @State objParam: GlobalTmp = new GlobalTmp();
  build() {
    Column() {
      Text('通过调用@Builder渲染UI界面')
        .fontSize(20)
      overBuilder({str_value: this.objParam.str_value, num_value: this.objParam.num_value})
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('点击改变参数值').onClick(() => {
        this.objParam.str_value = 'Hello World';
        this.objParam.num_value = 1;
      })
    }
  }
}
```

### \@Builder函数里面使用的组件没有根节点包裹

在\@Builder函数里使用if判断语句时，创建的组件没有被Column/Row(根节点)包裹，会出现组件创建不出来的情况。

【反例】

```ts
const showComponent: boolean = true;
@Builder function OverlayNode() {
  // 没有Column或者Row根节点导致Text组件没有创建
  if (showComponent) {
      Text("This is overlayNode Blue page")
        .fontSize(20)
        .fontColor(Color.Blue)
        .height(100)
        .textAlign(TextAlign.End)
    } else {
      Text("This is overlayNode Red page")
        .fontSize(20)
        .fontColor(Color.Red)
    }
}

@Entry
@Component
struct OverlayExample {

  build() {
    RelativeContainer() {
      Text('Hello World')
        .overlay(OverlayNode(), { align: Alignment.Center})
    }
    .height('100%')
    .width('100%')
  }
}
```

【正例】

```ts
const showComponent: boolean = true;
@Builder function OverlayNode() {
  Column() {
    if (showComponent) {
      Text("This is overlayNode Blue page")
        .fontSize(20)
        .fontColor(Color.Blue)
        .height(100)
        .textAlign(TextAlign.End)
    } else {
      Text("This is overlayNode Red page")
        .fontSize(20)
        .fontColor(Color.Red)
    }
  }
}

@Entry
@Component
struct OverlayExample {

  build() {
    RelativeContainer() {
      Text('Hello World')
        .overlay(OverlayNode(), { align: Alignment.Center})
    }
    .height('100%')
    .width('100%')
  }
}
```