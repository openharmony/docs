# \@Builder Decorator: Custom Builder Function


As previously described, you can reuse UI elements by creating a custom component, which comes with a fixed internal UI structure and allows for data transfer only with its caller. ArkUI also provides a more lightweight mechanism for reusing UI elements: \@Builder. An \@Builder decorated function is a special function that serves similar purposes as the **build** function. The \@Builder decorated function follows the same syntax rules as the **build()** function. You can abstract reusable UI elements into a method and call the method in **build**.


For simplicity, here we refer to an \@Builder decorated function also as a custom builder function.


> **NOTE**
>
> This decorator can be used in ArkTS widgets since API version 9.


## Rules of Use


### Local Custom Builder Function

Syntax:


```ts
@Builder MyBuilderFunction() { ... }
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
  @Link message: string;

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

When parameters are passed by reference, if a custom component or another \@Builder method is called within the \@Builder method, ArkUI provides [$$](arkts-two-way-sync.md) as the paradigm for passing parameters by reference.

The following is an example of a multi-level, nested \@Builder method:

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
  @Link message: string;
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
