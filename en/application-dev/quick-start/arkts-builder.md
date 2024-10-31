# \@Builder Decorator: Custom Builder Function

ArkUI provides the \@Builder decorator that is a lightweight UI element reuse mechanism. This custom component has a fixed internal UI structure and passes the data only to the user. You can abstract reused UI elements into a method and call the method in the **build** method.

For simplicity, here we refer to an \@Builder decorated function also as a custom builder function.


> **NOTE**
>
> This decorator can be used in ArkTS widgets since API version 9.
>
> This decorator can be used in atomic services since API version 11.

## Constraints

- The \@Builder triggers dynamic UI rendering for only when parameters are passed in by reference. Only one parameter can be passed.

- If the \@Builder passes in two or more parameters, dynamic UI rendering is not triggered.

- If the \@Builder passes in parameters by value and by reference, dynamic UI rendering is not triggered.

- \@Builder parameters must be passed in one by one in the form of object literals to trigger dynamic UI rendering.

## Rules of Use

### Private Custom Builder Function

Syntax:

```ts
@Builder MyBuilderFunction() {}
```

Usage:

```ts
this.MyBuilderFunction()
```

- You can define one or more @Builder decorated methods in a custom component. Such a method is considered as a private, special type of member function of the component.

- The custom builder function can be called from the **build** method or another custom builder function in the same component only.

- Inside the custom builder function body, **this** refers to the owning component. Component state variables are accessible from within the custom builder function implementation. Using **this** to access the custom components' state variables is recommended over parameter passing.


### Global Custom Builder Function

Syntax:

```ts
@Builder function MyGlobalBuilderFunction() { ... }
```

Usage:

```ts
MyGlobalBuilderFunction()
```

- Use of a global custom builder function is recommended if no own state is involved.


## Parameter Passing Rules

For custom builder functions, parameters can be passed [by value](#by-value-parameter-passing) and [by reference](#by-reference-parameter-passing). Both of them must comply with the following rules:

- The parameter type must be the same as the declared parameter type. The **undefined** or **null** constants as well as expressions evaluating to these values are not allowed.

- All parameters must be immutable inside the custom builder function.

- The custom builder function body follows the same [syntax rules](arkts-create-custom-components.md#build-function) as the **build()** function.

- Parameters are passed by value in all cases except when only one parameter is passed in and the parameter needs to be directly passed to the object literal.


### By-Reference Parameter Passing

In by-reference parameter passing, state variables can be passed, and the change of these state variables causes the UI re-rendering in the \@Builder decorated method.

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

When parameters are passed by reference, if a custom component is called within the \@Builder method, ArkUI provides [$$](arkts-two-way-sync.md) as the paradigm for passing parameters by reference.

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
            this.builder_value = 'builder_value clicked'
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
      overBuilder({str_value: this.objParam.str_value, num_value: this.objParam.num_value, tmp_value: this.objParam.tmp_value, arrayTmp_value: this.objParam.arrayTmp_value})
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

In this case, the decorator feature is used. The change of the listening value triggers UI re-rendering and parameters are not passed through the \@Builder.

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

Call the custom components or other methods within \@Builder method. ArkUI provides [$$](arkts-two-way-sync.md) as a paradigm for passing parameters by reference.

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

## FAQs

### Two or More Parameters Are Used in the \@Builder

When two or more parameters are used, the value change does not trigger the UI re-rendering even if the parameters are passed in the form of object literals.

[Incorrect Example]

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
      overBuilder({str_value: this.objParam.str_value}, this.num) // Two parameters are used.
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

[Incorrect Example]

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
      overBuilder({str_value: this.strParam.str_value}, {num_value: this.numParam.num_value}) // Two parameters are used.
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

[Correct Example]

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
