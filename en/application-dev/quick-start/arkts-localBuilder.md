# \@LocalBuilder Decorator: Maintaining the Parent-Child Relationship Between Component and State Management

When use @Builder to pass data, the parent-child relationship of components is considered. After **bind(this)** is used, the parent-child relationship of components is inconsistent with that of state management. As a result, the @LocalBuilder decorator is used to fix the inconsistency. @LocalBuilder has the same features as local @Builder and provides a better determination of the parent-child relationship of components and state management.

Before reading this topic, you are advised to read [\@Builder](./arkts-builder.md).

> **NOTE**
>
> This decorator is supported since API version 12.
>

## How to Use


### Local Custom Builder Function

Syntax:


```ts
@LocalBuilder MyBuilderFunction() { ... }
```

Usage:


```ts
this.MyBuilderFunction()
```

- One or more @LocalBuilder methods can be defined in a custom component. The methods are considered as private and special member functions of the component.
- The custom builder function can be called from the **build** method or another custom builder function in the same component only.
- Inside the custom builder function body, **this** refers to the owning component. Component state variables are accessible from within the custom builder function implementation. Using **this** to access the custom components' state variables is recommended over parameter passing.

## Constraints

- @LocalBuilder can be declared only within the component to which it belongs. Global declaration is not allowed.

- @LocalBuilder cannot be used by built-in decorators and custom decorators.

- Static methods in a custom component cannot be used together with @LocalBuilder.

## Differences Between @LocalBuilder and Local @Builder

To change the pointed object of **this**, **bind(this)** used in the local @Builder will cause inconsistent parent-child relationship between the component and the state management. However, this problem does not exist in the @LocalBuilder. For details, see [Differences between @LocalBuilder and @Builder](arkts-localBuilder.md#differences-between-localbuilder-and-builder).

## Parameter Passing Rules

For @LocalBuilder functions, parameters can be passed [by value](#by-value-parameter-passing) and [by reference](#by-reference-parameter-passing). Both of them must comply with the following rules:

- The parameter type must be the same as the declared parameter type. The **undefined** or **null** constants as well as expressions evaluating to these values are not allowed.

- All parameters must be immutable inside the @LocalBuilder function.

- The \@LocalBuilder function body follows the same [syntax rules](arkts-create-custom-components.md#build-function) as the **build()** function.

- Parameters are passed by value in all cases except when only one parameter is passed in and the parameter needs to be directly passed to the object literal.


### By-Reference Parameter Passing

In by-reference parameter passing, state variables can be passed, and the change of these state variables causes the UI re-rendering in the \@LocalBuilder decorated method.

Note that if the \@LocalBuilder function is used together with the **$$** parameter, the passed parameters change when the child component calls the @LocalBuilder function of the parent component and the UI in \@LocalBuilder is not re-rendered.

Use scenario:

The @LocalBuilder method in the **Parent** component is called in the **build** function to pass the parameters by keys. When you click **Click me**, the **Text** content in the @LocalBuilder changes with the state variable.

```ts
class ReferenceType {
  paramString: string = '';
}

@Entry
@Component
struct Parent {
  @State variableValue: string = 'Hello World';

  @LocalBuilder
  citeLocalBuilder(params: ReferenceType) {
    Row() {
      Text(`UseStateVarByReference: ${params.paramString}`)
    }
  };

  build() {
    Column() {
      this.citeLocalBuilder({ paramString: this.variableValue })
      Button('Click me').onClick(() => {
        this.variableValue = 'Hi World';
      })
    }
  }
}
```

When parameters are passed by reference, if a custom component is called within the\@LocalBuilder method, ArkUI provides [$$](arkts-two-way-sync.md) as the paradigm for passing parameters by reference.

Use scenario:

The @LocalBuilder method in the **Parent** component is called in the custom component to pass the parameters by reference. When the value of a state variable in the **Parent** component changes, the **message** of the custom component **HelloComponent** in the @LocalBuilder method also changes.

```ts
class ReferenceType {
  paramString: string = '';
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
  @State variableValue: string = 'Hello World';

  @LocalBuilder
  citeLocalBuilder($$: ReferenceType) {
    Row() {
      Column() {
        Text(`citeLocalBuilder===${$$.paramString}`)
        HelloComponent({ message: $$.paramString })
      }
    }
  }

  build() {
    Column() {
      this.citeLocalBuilder({ paramString: this.variableValue })
      Button('Click me').onClick(() => {
        this.variableValue = 'Hi World';
      })
    }
  }
}
```

The child component references the @LocalBuilder function of the parent component with a state variable as the parameter. The change of the state variable does not trigger the UI re-render in the @LocalBuilder method because the function decorated by @Localbuilder is bound to the parent component and only the current component and its child components are re-rendered. Therefore, the re-render of the parent component cannot be triggered. If @Builder is used, the UI can be re-rendered. The reason is that @Builder has the pointer of the **this** keyword changed. In this case, the function is bound to the child component, and the UI can be re-rendered.


Use scenario:

The **Child** component passes the state variable to the @Builder and @LocalBuilder functions of the **Parent** component. In the @Builder function, **this** points to the **Child** component and parameter changes can trigger a UI re-rendering. In the @LocalBuilder function, **this** points to the **Parent** component and parameter changes cannot trigger the UI re-rendering. If the state variable of **Parent** referenced in the @LocalBuilder function changes, the UI can be re-rendered properly.

```ts
class Data {
  size: number = 0;
}

@Entry
@Component
struct Parent {
  label: string = 'parent';
  @State data: Data = new Data();

  @Builder
  componentBuilder($$: Data) {
    Text(`builder + $$`)
    Text(`${'this -> ' + this.label}`)
    Text(`${'size : ' + $$.size}`)
    Text(`------------------------`)
  }

  @LocalBuilder
  componentLocalBuilder($$: Data) {
    Text(`LocalBuilder + $$ data`)
    Text(`${'this -> ' + this.label}`)
    Text(`${'size : ' + $$.size}`)
    Text(`------------------------`)
  }

  @LocalBuilder
  contentLocalBuilderNoArgument() {
    Text(`LocalBuilder + local data`)
    Text(`${'this -> ' + this.label}`)
    Text(`${'size : ' + this.data.size}`)
    Text(`------------------------`)
  }

  build() {
    Column() {
      Child({
        contentBuilder: this.componentBuilder,
        contentLocalBuilder: this.componentLocalBuilder,
        contentLocalBuilderNoArgument: this.contentLocalBuilderNoArgument,
        data: this.data
      })
    }
  }
}

@Component
struct Child {
  label: string = 'child';
  @Builder customBuilder() {};
  @BuilderParam contentBuilder: ((data: Data) => void) = this.customBuilder;
  @BuilderParam contentLocalBuilder: ((data: Data) => void) = this.customBuilder;
  @BuilderParam contentLocalBuilderNoArgument: (() => void) = this.customBuilder;
  @Link data: Data;

  build() {
    Column() {
      this.contentBuilder({ size: this.data.size })
      this.contentLocalBuilder({ size: this.data.size })
      this.contentLocalBuilderNoArgument()
      Button("add child size").onClick(() => {
        this.data.size += 1;
      })
    }
  }
}
```

### By-Value Parameter Passing

By default, parameters in the \@LocalBuilder decorated functions are passed by value. In this case, when the passed parameter is a state variable, the change of the state variable does not cause UI re-rendering in the \@LocalBuilder decorated function. Therefore, when passing state variables, you are advised to use [by-reference parameter passing](#by-reference-parameter-passing).

Use scenario:

The **Parent** component passes the @State decorated **label** value to the @LocalBuilder function as a function parameter. In this case, the value obtained by the @LocalBuilder function is a common variable value. Therefore, when the @State decorated **label** value is changed, the value in the @LocalBuilder function does not change.


```ts
@Entry
@Component
struct Parent {
  @State label: string = 'Hello';

  @LocalBuilder
  citeLocalBuilder(paramA1: string) {
    Row() {
      Text(`UseStateVarByValue: ${paramA1}`)
    }
  }

  build() {
    Column() {
      this.citeLocalBuilder(this.label)
    }
  }
}
```

## Differences Between @LocalBuilder and @Builder

When the **componentBuilder** function is decorated by @Builder, the **Child** component is displayed. When the **componentBuilder** function is decorated by @LocalBuilder, the **Parent** component is displayed.

**NOTE**

**@Builder componentBuilder()** is passed to the child component **@BuilderParam customBuilderParam** in the form of **this.componentBuilder**. **this** points to the label of **Child**, that is, **Child** is displayed.

**@LocalBuilder componentBuilder()** is passed to the child component **@BuilderParam customBuilderParam** in the form of **this.componentBuilder**. **this** points to the label of **Parent**, that is, **Parent** is displayed.

```ts
@Component
struct Child {
  label: string = `Child`;
  @BuilderParam customBuilderParam: () => void;

  build() {
    Column() {
      this.customBuilderParam()
    }
  }
}

@Entry
@Component
struct Parent {
  label: string = `Parent`;

  @Builder componentBuilder() {
    Text(`${this.label}`)
  }

  // @LocalBuilder componentBuilder() {
  //   Text(`${this.label}`)
  // }

  build() {
    Column() {
      Child({ customBuilderParam: this.componentBuilder })
    }
  }
}
```

## Use Scenarios

### Using @LocalBuilder in @ComponentV2 Decorated Custom Components

Call the @LocalBuilder in the custom component decorated by @ComponentV2 to change the variables, triggering the UI re-renders.

```ts
@ObservedV2
class Info {
  @Trace name: string = '';
  @Trace age: number = 0;
}

@ComponentV2
struct ChildPage {
  @Require @Param childInfo: Info;
  build() {
    Column() {
      Text(`Custom component name :${this.childInfo.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`Custom component age :${this.childInfo.age}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Entry
@ComponentV2
struct ParentPage {
  info1: Info = { name: "Tom", age: 25 };
  @Local info2: Info = { name: "Tom", age: 25 };

  @LocalBuilder
  privateBuilder() {
    Column() {
      Text(`LocalBuilder@Builder name :${this.info1.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`LocalBuilder@Builder age :${this.info1.age}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }

  @LocalBuilder
  privateBuilderSecond() {
    Column() {
      Text(`LocalBuilder@Builder name :${this.info2.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`LocalBuilder@Builder age :${this.info2.age}`)
        .fontSize(20)
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
      this.privateBuilderSecond() // Call the local @Builder.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({childInfo: this.info1}) // Call the custom component.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({childInfo: this.info2}) // Call the custom component.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button("change info1&info2")
        .onClick(() => {
          this.info1 = { name: "Cat", age: 18} // Text1 is not re-rendered because no decorator is used to listen for value changes.
          this.info2 = { name: "Cat", age: 18} // Text2 is re-rendered because a decorator is used to listen for value changes.
        })
    }
  }
}
```
