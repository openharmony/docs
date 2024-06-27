# \@BuilderParam Decorator: @Builder Function Reference


In certain circumstances, you may need to add a specific feature, such as a click-to-jump action, to a custom component. However, embedding an event method directly in a component will add the feature to all places where the component is imported. This is where the \@BuilderParam decorator comes into the picture. \@BuilderParam is used to decorate a custom component variable of type Reference to an \@Builder method (@BuilderParam is used to undertake the @Builder function). When initializing a custom component, you can add the specific feature to it by assigning a value to the variable. This decorator can be used to declare an element of any UI description, similar to a slot placeholder.


> **NOTE**
>
> This decorator can be used in ArkTS widgets since API version 9.
>
> This decorator can be used in atomic services since API version 11.

## Rules of Use


### Initializing \@BuilderParam Decorated Methods

An \@BuilderParam decorated method can be initialized only by an \@Builder function reference. If this decorator is used together with [\@Require](arkts-require.md) in API version 11, the parent component must construct input parameters.

- Local initialization with the owning component's custom \@Builder function reference or a global \@Builder function reference

  ```ts
  @Builder function overBuilder() {}

  @Component
  struct Child {
    @Builder doNothingBuilder() {};

    // Use the custom builder function of the custom component for @BuilderParam initialization.
    @BuilderParam customBuilderParam: () => void = this.doNothingBuilder;
    // Use the global custom builder function for @BuilderParam initialization.
    @BuilderParam customOverBuilderParam: () => void = overBuilder;
    build(){}
  }
  ```

- Initialization from the parent component

  ```ts
  @Component
  struct Child {
    @Builder customBuilder() {}
    // Use the @Builder decorated method in the parent component for @BuilderParam initialization.
    @BuilderParam customBuilderParam: () => void = this.customBuilder;

    build() {
      Column() {
        this.customBuilderParam()
      }
    }
  }

  @Entry
  @Component
  struct Parent {
    @Builder componentBuilder() {
      Text(`Parent builder `)
    }

    build() {
      Column() {
        Child({ customBuilderParam: this.componentBuilder })
      }
    }
  }
  ```
  **Figure 1** Example effect

  ![builderparam-demo1](figures/builderparam-demo1.png)


- **this** in the function body must point to the correct object.

  In the following example, when the **Parent** component calls **this.componentBuilder()**, **this** points to the owning component, that is, **Parent**. **@Builder componentBuilder()** is passed to **@BuilderParam customBuilderParam** in the **Child** component through **this.componentBuilder**. As such, **this** points to the label of **Child**, that is, **Child**. **@Builder componentBuilder()** is passed to **@BuilderParam customChangeThisBuilderParam** in the **Child** component through **():void=>{this.componentBuilder()}**. Because **this** of the arrow function points to the owner object, the value of **label** is **Parent**.


  ```ts
  @Component
  struct Child {
    label: string = `Child`
    @Builder customBuilder() {}
    @Builder customChangeThisBuilder() {}
    @BuilderParam customBuilderParam: () => void = this.customBuilder;
    @BuilderParam customChangeThisBuilderParam: () => void = this.customChangeThisBuilder;

    build() {
      Column() {
        this.customBuilderParam()
        this.customChangeThisBuilderParam()
      }
    }
  }

  @Entry
  @Component
  struct Parent {
    label: string = `Parent`

    @Builder componentBuilder() {
      Text(`${this.label}`)
    }

    build() {
      Column() {
        this.componentBuilder()
        Child({ customBuilderParam: this.componentBuilder, customChangeThisBuilderParam: ():void=>{this.componentBuilder()} })
      }
    }
  }
  ```
 **Figure 2** Example effect

 ![builderparam-demo2](figures/builderparam-demo2.png)


## Use Scenarios


### Component Initialization Through Parameters

An \@BuilderParam decorated method can be a method with or without parameters. Whether it contains parameters should match that of the assigned \@Builder method. The type of the \@BuilderParam decorated method must also match that of the assigned \@Builder method.


```ts
class Tmp{
  label:string = ''
}
@Builder function overBuilder($$ : Tmp) {
  Text($$.label)
    .width(400)
    .height(50)
    .backgroundColor(Color.Green)
}

@Component
struct Child {
  label: string = 'Child'
  @Builder customBuilder() {}
  // Without parameters. The pointed componentBuilder does not carry parameters either.
  @BuilderParam customBuilderParam: () => void = this.customBuilder;
  // With parameters. The pointed overBuilder also carries parameters.
  @BuilderParam customOverBuilderParam: ($$ : Tmp) => void = overBuilder;

  build() {
    Column() {
      this.customBuilderParam()
      this.customOverBuilderParam({label: 'global Builder label' } )
    }
  }
}

@Entry
@Component
struct Parent {
  label: string = 'Parent'

  @Builder componentBuilder() {
    Text(`${this.label}`)
  }

  build() {
    Column() {
      this.componentBuilder()
      Child({ customBuilderParam: this.componentBuilder, customOverBuilderParam: overBuilder })
    }
  }
}
```
**Figure 3** Example effect

![builderparam-demo3](figures/builderparam-demo3.png)


### Component Initialization Through Trailing Closure

In a custom component, the \@BuilderParam decorated attribute can be initialized using a trailing closure. During initialization, the component name is followed by a pair of braces ({}) to form a trailing closure.

> **NOTE**
>
>  - In this scenario, the custom component can have only one \@BuilderParam decorated attribute.
> 
>  - In this scenario, custom components do not support universal attributes.

You can pass the content in the trailing closure to \@BuilderParam as an \@Builder decorated method. Example:


```ts
@Component
struct CustomContainer {
  @Prop header: string = '';
  @Builder closerBuilder(){}
  // Use the trailing closure {} (@Builder decorated method) of the parent component for @BuilderParam initialization.
  @BuilderParam closer: () => void = this.closerBuilder

  build() {
    Column() {
      Text(this.header)
        .fontSize(30)
      this.closer()
    }
  }
}

@Builder function specificParam(label1: string, label2: string) {
  Column() {
    Text(label1)
      .fontSize(30)
    Text(label2)
      .fontSize(30)
  }
}

@Entry
@Component
struct CustomContainerUser {
  @State text: string = 'header';

  build() {
    Column() {
      // Create the CustomContainer component. During initialization, append a pair of braces ({}) to the component name to form a trailing closure.
      // Used as the parameter passed to CustomContainer @BuilderParam closer: () => void.
      CustomContainer({ header: this.text }) {
        Column() {
          specificParam('testA', 'testB')
        }.backgroundColor(Color.Yellow)
        .onClick(() => {
          this.text = 'changeHeader';
        })
      }
    }
  }
}
```
**Figure 4** Example effect

![builderparam-demo4](figures/builderparam-demo4.png)
