# \@Builder Decorator: Custom Builder Function

ArkUI provides the \@Builder decorator that is a lightweight UI element reuse mechanism. This decorator has a fixed internal UI structure and passes the data only to the user. You can abstract reused UI elements into a method and call the method in the **build** method.

For simplicity, here we refer to an \@Builder decorated function also as a custom builder function.

Before reading this topic, you are advised to read [Basic Syntax Overview](./arkts-basic-syntax-overview.md), [Declarative UI Description](./arkts-declarative-ui-description.md), and [Creating a Custom Component](./arkts-create-custom-components.md).

> **NOTE**
>
> This decorator can be used in ArkTS widgets since API version 9.
>
> This decorator can be used in atomic services since API version 11.


## Rules of Use

The \@Builder decorator can be used for the private custom build function defined in the custom component and global custom build function defined globally.

### Private Custom Build Function

Syntax:

```ts
@Entry
@Component
struct BuilderDemo {
  @Builder
  showTextBuilder() {
    Text('Hello World')
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
  @Builder
  showTextValueBuilder(param: string) {
    Text(param)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
  build() {
    Column() {
      // Without parameter.
      this.showTextBuilder()
      // With a parameter.
      this.showTextValueBuilder('Hello @Builder')
    }
  }
}
```

Usage:

```ts
this.showTextBuilder()
```

- You can define one or more @Builder decorated methods in a custom component. Such a method is considered as a private, special type of member function of the component.

- Private custom builder functions can be called in custom components, **build()**, and other custom builder functions.

- Inside the custom builder function body, **this** refers to the owning component. Component state variables are accessible from within the custom builder function implementation. Using **this** to access the custom components' state variables is recommended over parameter passing.


### Global Custom Builder Function

Syntax:

```ts
@Builder
function showTextBuilder() {
  Text('Hello World')
    .fontSize(30)
    .fontWeight(FontWeight.Bold)
}
@Entry
@Component
struct BuilderDemo {
  build() {
    Column() {
      showTextBuilder()
    }
  }
}
```

Usage:

```ts
showTextBuilder()
```

- Use of a global custom builder function is recommended if no own state is involved.

- Global custom builder functions can be called in **build()** and other custom builder functions.


## Parameter Passing Rules

For custom builder functions, parameters can be passed [by value](#by-value-parameter-passing) and [by reference](#by-reference-parameter-passing). Both of them must comply with the following rules:

- The parameter type must be the same as the declared parameter type. The **undefined** or **null** constants as well as expressions evaluating to these values are not allowed.

- All parameters must be immutable inside the custom builder function.

- The custom builder function body follows the same [syntax rules](arkts-create-custom-components.md#build-function) as **build()**.

- Parameters are passed by value in all cases except when only one parameter is passed in and the parameter needs to be directly passed to the object literal.

### By-Value Parameter Passing

By default, parameters in the \@Builder decorated functions are passed by value. In this case, when the passed parameter is a state variable, the change of the state variable does not cause UI re-rendering in the \@Builder decorated function. Therefore, when passing state variables, you are advised to use [by-reference parameter passing](#by-reference-parameter-passing).

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

### By-Reference Parameter Passing

In by-reference parameter passing, state variables can be passed, and the change of these state variables causes the UI re-rendering in the \@Builder decorated method.

```ts
class Tmp {
  paramA1: string = '';
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
      // When the overBuilder component is called in the parent component,
      // pass this.label to the overBuilder component by reference.
      overBuilder({ paramA1: this.label })
      Button('Click me').onClick(() => {
        // After you click "Click me", the UI text changes from "Hello" to "ArkUI".
        this.label = 'ArkUI';
      })
    }
  }
}
```

## Constraints

1. Parameter values cannot be changed in \@Builder decorated functions. Otherwise, the framework throws a runtime error. You can change the parameters in the \@Builder decorated custom components. For details, see [Changing the Input Parameters in the \@Builder Decorated Function](#changing-the-input-parameters-in-the-builder-decorated-function).

2. The \@Builder triggers dynamic UI rendering for only when parameters are passed in by reference. Only one parameter can be passed. For details, see [By-Reference Parameter Passing](#by-reference-parameter-passing).

3. If the \@Builder passes in two or more parameters, dynamic UI rendering is not triggered. For details, see [Two or More Parameters Are Used in \@Builder](#two-or-more-parameters-are-used-in-builder).

4. If the \@Builder passes in parameters by value and by reference, dynamic UI rendering is not triggered. For details, see [Two or More Parameters Are Used in \@Builder](#two-or-more-parameters-are-used-in-builder).

5. \@Builder parameters must be passed in one by one in the form of object literals to trigger dynamic UI rendering. For details, see [Two or More Parameters Are Used in \@Builder](#two-or-more-parameters-are-used-in-builder).


## Use Scenarios

### Using Custom Builder Function in Custom Component

Create a private \@Builder method, call this method by using **this.builder()** in **Column**, and change the content of **builder_value** through the **aboutToAppear** lifecycle function and Button click event to dynamically render the UI.

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
        Button('Click to change builder_value')
          .onClick(() => {
            this.builder_value = 'builder_value is clicked'
          })
      }
    }
  }
}
```

### Using Global Custom Builder Function

Create a global \@Builder method and call this method by using **overBuilder()** in **Column**. Pass the simple type or complex type parameters in the form of object literals, value changes will trigger UI re-rendering.

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
      Text('Render the UI by calling the @Builder')
        .fontSize(20)
      overBuilder({str_value: this.objParam.str_value, num_value: this.objParam.num_value,
       tmp_value: this.objParam.tmp_value, arrayTmp_value: this.objParam.arrayTmp_value})
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('Click to change parameter').onClick(() => {
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

### Changing the Variables Decorated by the Decorator Triggers UI Re-rendering

In this scenario, @Builder is used only to display the **Text** component instead of directly triggering dynamic UI re-rendering. UI re-rendering is triggered by the value change of the **Text** component listened by the decorator.

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
      Text('Render the UI by calling the @Builder')
        .fontSize(20)
      this.privateBuilder()
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('Click to change parameter').onClick(() => {
        this.objParam.str_value = 'str_value Hello World';
        this.label = 'label Hello World'
      })
    }
  }
}
```

### Using the Global and Local @Builder to Pass in Parameters of the customBuilder Type

When a parameter is of the **customBuilder** type, the defined \@Builder function can be passed in because **customBuilder** is a **Function(() => any)** or **void** type and \@Builder is also a function type. In this case, \@Builder is passed to implement a specific effect.

```ts
@Builder
function overBuilder() {
  Row() {
    Text('Global Builder')
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
      Text('Local Builder')
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

### Nesting of Multi-layer \@Builder Method

Call the custom component or other \@Builder methods in the \@Builder method to implement a nesting of multiple \@Builder methods. To trigger the dynamic UI re-rendering in the innermost \@Builder, you should ensure that \@Builder is called by reference at each layer. [\$$](./arkts-two-way-sync.md) can be replaced with another name, which is not a mandatory parameter.

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
  @Prop message: string = '';
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

### Using \@Builder Functions Together with the Decorators in V2

Use the global @Builder and local @Builder in the @ComponentV2 decorated custom components and use the @ObservedV2 and @Trace decorators to listen for specific value changes to trigger UI re-rendering.

```ts
@ObservedV2
class Info {
  @Trace name: string = '';
  @Trace age: number = 0;
}

@Builder
function overBuilder(param: Info) {
  Column() {
    Text('Global @Builder name :${param.name}`)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
    Text('Global @Builder age :${param.age}`)
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
      Text('Local @Builder name :${this.info1.name}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      Text('Local @Builder age :${this.info1.age}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }

  build() {
    Column() {
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      this.privateBuilder() // Call the local @Builder.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      overBuilder({ name: this.info2.name, age: this.info2.age}) // Call the global @Builder.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage ({childInfo: this.info1}) // Call the custom component.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage ({childInfo: this.info2}) // Call the custom component.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button("change info1&info2")
        .onClick(() => {
          this.info1 = { name: "Cat", age: 18}; // Text1 is not re-rendered because no decorator is used to listen for value changes.
          this.info2 = { name: "Cat", age: 18}; // Text2 is re-rendered because a decorator is used to listen for value changes.
        })
    }
  }
}
```

## FAQs

### Two or More Parameters Are Used in \@Builder

When two or more parameters are used, the value change does not trigger the UI re-rendering even if the parameters are passed in the form of object literals.

[Negative Example]

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
      Text('Render the UI by calling the @Builder')
        .fontSize(20)
      // Two parameters are used, which is incorrect.
      overBuilder({str_value: this.objParam.str_value}, this.num)
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('Click to change parameter').onClick(() => {
        this.objParam.str_value = 'Hello World';
        this.num = 1;
      })
    }
  }
}
```

[Negative Example]

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
      Text('Render the UI by calling the @Builder')
        .fontSize(20)
      // Two parameters are used, which is incorrect.
      overBuilder({str_value: this.strParam.str_value}, {num_value: this.numParam.num_value})
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('Click to change parameter').onClick(() => {
        this.strParam.str_value = 'Hello World';
        this.numParam.num_value = 1;
      })
    }
  }
}
```

Only one parameter can be used in the \@Builder. When one parameter is passed in the form of object literals, the value change triggers the UI re-rendering.

[Positive Example]

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
      Text('Render the UI by calling the @Builder')
        .fontSize(20)
      overBuilder({str_value: this.objParam.str_value, num_value: this.objParam.num_value})
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('Click to change parameter').onClick(() => {
        this.objParam.str_value = 'Hello World';
        this.objParam.num_value = 1;
      })
    }
  }
}
```

### Using the @ComponentV2 Decorator to Trigger Dynamic Re-render

In the way of passing parameters by value, the @ObservedV2 and @Trace decorators can be used together in the @ComponentV2 decorated custom component to re-render the UI.

[Negative Example]

In the @ComponentV2 decorated custom component, the use of simple data types cannot trigger UI re-render.

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
  // Using simple data type cannot trigger UI re-render
  @Local num_value: number = 0;
  private progressTimer: number = -1;

  aboutToAppear(): void {
    this.progressTimer = setInterval(() => {
      if (this.class_value.count < 100) {
        this.class_value.count += 5;
        this.num_value += 5;
      } else {
        clearInterval(this.progressTimer);
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

[Positive Example]

In @ComponentV2, only the @ObservedV2 decorated **ParamTmp** class and the @Trace decorated **count** property can trigger the UI re-render.

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
        clearInterval(this.progressTimer);
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

### Changing the Input Parameters in the \@Builder Decorated Function

[Negative Example]

```ts
interface Temp {
  paramA: string;
}

@Builder function overBuilder(param: Temp) {
  Row() {
    Column() {
      Button(`overBuilder === ${param.paramA}`)
        .onClick(() => {
          // Incorrect format. Parameter values cannot be changed in the function decorated by @Builder.
          param.paramA = 'Yes';
      })
    }
  }
}

@Entry
@Component
struct Parent {
  @State label: string = 'Hello';

  build() {
    Column() {
      overBuilder({paramA: this.label})
      Button('click me')
        .onClick(() => {
          this.label = 'ArkUI';
        })
    }
  }
}
```

[Positive Example]

```ts
interface Temp {
  paramA: string;
}

@Builder function overBuilder(param: Temp) {
  Row() {
    Column() {
      Button(`overBuilder === ${param.paramA}`)
    }
  }
}

@Entry
@Component
struct Parent {
  @State label: string = 'Hello';

  build() {
    Column() {
      overBuilder({paramA: this.label})
      Button('click me')
        .onClick(() => {
          this.label = 'ArkUI';
        })
    }
  }
}
```
