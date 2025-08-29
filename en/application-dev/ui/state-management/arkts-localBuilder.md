# \@LocalBuilder Decorator: Maintaining Component Relationships
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The @LocalBuilder decorator addresses a critical challenge in component composition. While local \@Builder functions enable reference data passing between components, they require careful management of parent-child relationships. Specifically, when you use **.bind(this)** to modify function call contexts, this often leads to misalignment between the visual component hierarchy and the underlying state management relationships. To address this issue, the @LocalBuilder decorator is introduced. @LocalBuilder provides the same functionality as the local @Builder but better ensures consistency between the visual component hierarchy and the underlying state management relationships.

Before proceeding, you are advised to review [\@Builder](./arkts-builder.md) to understand the base functionality that \@LocalBuilder enhances.

> **NOTE**
>
> This decorator is supported since API version 12.
>
> This decorator is supported in ArkTS widgets since API version 12.
>
> This decorator can be used in atomic services since API version 12.

## How to Use

### Component-Level Builder Declaration

Syntax definition:

```ts
@LocalBuilder myBuilderFunction() { ... }
```

Invocation pattern:

```ts
this.myBuilderFunction()
```
- One or more @LocalBuilder functions can be defined in a custom component. These functions are treated as private and special member functions of the owning component.

- Each \@LocalBuilder function is accessible only within the owning component's scope and can be called from the component's **build** method or other local builder functions.

- Inside the custom builder function body, **this** refers to the owning component. Component state variables are accessible from within the custom builder function implementation. Using **this** to access the custom components' state variables is recommended over parameter passing.

## Constraints

- @LocalBuilder declarations are component-bound. Global declarations are not allowed.

- \@LocalBuilder cannot be used in conjunction with other decorators, whether built-in or custom.

- \@LocalBuilder cannot be used to decorate static functions in custom components.

## Differences Between \@LocalBuilder and Local \@Builder

When local @Builder functions are passed between components, it is common to use **.bind(this)** to modify the function context. However, this approach may lead to inconsistencies between the visual component hierarchy and the underlying state management relationships. In contrast, @LocalBuilder maintains stable parent-child relationships regardless of **.bind(this)** usage. This means that the parent component of elements defined in @LocalBuilder remains fixed and immutable. For details, see [Comparison Between @LocalBuilder and @Builder](arkts-localBuilder.md#comparison-between-localbuilder-and-builder).

![en-us_image_compatible_localBuilder](figures/en-us_image_compatible_localBuilder.png)

> **NOTE**
>
> The **bind()** method creates a new bound function that sets the **this** value to the first parameter provided during creation.

## Parameter Passing Rules

@LocalBuilder functions support two parameter passing modes: [pass by value](#by-value-parameter-passing) and [pass by reference](#by-reference-parameter-passing). Both modes must comply with the following rules:

- Parameter types must exactly match their declared types. **undefined** and **null** values are prohibited.

- All parameters must be immutable inside the \@LocalBuilder function body.

- The \@LocalBuilder function body follows the same [syntax rules](arkts-create-custom-components.md#build) as the **build()** function.

- Object literals are passed by reference. All other types of parameters are passed by value.

### By-Reference Parameter Passing

In by-reference parameter passing, state variables can be passed, and the change of these state variables causes the UI re-rendering in the \@LocalBuilder function.

> **NOTE**
>
> If the \@LocalBuilder function is used together with the **$$** operator, when a child component calls the @LocalBuilder function of the parent component, parameter changes from the child component will not trigger UI re-rendering in the @LocalBuilder function.

In the example, the @LocalBuilder function in the **Parent** component is called in the **build** function using the key-value pair syntax for parameter passing. After **Click me** is clicked, the **Text** content in the @LocalBuilder changes with the state variable.

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

For passing parameters by reference in an \@LocalBuilder function that invokes custom components, ArkUI provides [$$](arkts-two-way-sync.md) as the standard paradigm.

In the following example, in the \@LocalBuilder function of the **Parent** component, a custom component is called with parameters passed by reference. When the value of the state variable in the **Parent** component changes, the **message** value of the custom component **HelloComponent** within the @LocalBuilder function will also change.

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

When a child component calls the @LocalBuilder function of its parent component with state variables, changes to the state variable do not trigger UI re-rendering within the @LocalBuilder function. This occurs because components created using the \@LocalBuilder function remain bound to the parent, and the state variable updates only affect the current component and its children, not the parent. In contrast, using \@Builder functions can trigger UI re-rendering. This is because \@Builder dynamically changes the function's **this** context to point to the calling child component, binding the created components to the child instead of the parent component.

The following example exhibits the distinct behaviors between @Builder and @LocalBuilder. When the **Child** component passes state variables to the **Parent** component's @Builder and @LocalBuilder functions: Inside \@Builder, **this** points to **Child**, and parameter changes trigger UI re-rendering. Inside \@LocalBuilder, **this** points to **Parent**, and parameter changes do not trigger UI re-rendering. Only changes to the Parent component's own state variables will cause the UI to re-render.

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
  }

  @LocalBuilder
  componentLocalBuilder($$: Data) {
    Text(`LocalBuilder + $$ data`)
    Text(`${'this -> ' + this.label}`)
    Text(`${'size : ' + $$.size}`)
  }

  @LocalBuilder
  contentLocalBuilderNoArgument() {
    Text(`LocalBuilder + local data`)
    Text(`${'this -> ' + this.label}`)
    Text(`${'size : ' + this.data.size}`)
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
      Button('add child size').onClick(() => {
        this.data.size += 1;
      })
    }
  }
}
```

### By-Value Parameter Passing

By default, parameters in the \@LocalBuilder functions are passed by value. In this case, when the passed parameter is a state variable, its change does not cause UI re-rendering in the \@LocalBuilder function. Therefore, for state variables, you are advised to use [by-reference parameter passing](#by-reference-parameter-passing) instead.

In the following example, the **Parent** component passes the \@State decorated **label** value to the @LocalBuilder function as a function parameter. In this case, the value obtained by the @LocalBuilder function is a regular variable value. As a result, when the **label** value changes, the value in the @LocalBuilder function remains unchanged.

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

## Comparison Between \@LocalBuilder and \@Builder

When the **componentBuilder** function is decorated by @Builder, the **Child** component is displayed. When the **componentBuilder** function is decorated by @LocalBuilder, the **Parent** component is displayed.
Key points:

For the \@Builder decorated function, when the parent component passes **this.componentBuilder** to the child component's **@BuilderParam customBuilderParam**, the **this** context points to the child component instance (**Child**).

For the \@LocalBuilder decorated function, when the parent component passes **this.componentBuilder** to the child component's **@BuilderParam customBuilderParam**, the **this** context points to the parent component instance (**Parent**).

```ts
@Component
struct Child {
  label: string = 'Child';
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
  label: string = 'Parent';

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

## Use Cases

### Using \@LocalBuilder in \@ComponentV2 Decorated Custom Components

When @LocalBuilder is used within @ComponentV2 decorated custom components, UI re-rendering is triggered upon variable changes.

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
      Text(`Custom component name: ${this.childInfo.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`Custom component age: ${this.childInfo.age}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Entry
@ComponentV2
struct ParentPage {
  info1: Info = { name: 'Tom', age: 25 };
  @Local info2: Info = { name: 'Tom', age: 25 };

  @LocalBuilder
  privateBuilder() {
    Column() {
      Text(`Local @LocalBuilder name: ${this.info1.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`Local @LocalBuilder age: ${this.info1.age}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }

  @LocalBuilder
  privateBuilderSecond() {
    Column() {
      Text(`Local @LocalBuilder name: ${this.info2.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`Local @LocalBuilder age: ${this.info2.age}`)
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
      ChildPage({ childInfo: this.info1 }) // Call the custom component.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info2 }) // Call the custom component.
      Line()
        .width('100%')
        .height(10)
        .backgroundColor('#000000').margin(10)
      Button('change info1&info2')
        .onClick(() => {
          this.info1 = { name: 'Cat', age: 18 }; // Text1 will not be re-rendered because no decorator is used to listen for changes to info1.
          this.info2 = { name: 'Cat', age: 18 }; // Text2 will be re-rendered because a decorator is used to listen for changes to info2.
        })
    }
  }
}
```
