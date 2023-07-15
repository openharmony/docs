# \@Builder Decorator: Custom Builder Function


As previously described, you can reuse UI elements by creating a custom component, which comes with a fixed internal UI structure and allows for data transfer only with its caller. ArkUI also provides a more lightweight mechanism for reusing UI elements: \@Builder. An \@Builder decorated function is a special function that serves similar purpose as the build function. The \@Builder function body follows the same syntax rules as the **build** function. You can abstract reusable UI elements into a method and call the method in **build**.


To simplify language, here we refer to an \@Builder decorated function also as a custom builder function.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Rules of Use


### Custom Builder Function

Syntax:


```ts
@Builder myBuilderFunction({ ... })
```

Usage:


```ts
this.myBuilderFunction({ ... })
```

- Defining one or more custom builder (\@Builder decorated) functions inside a custom component is allowed. Such a custom builder function can be considered as a private, special type of member functions of that component.

- The custom builder function can be called from the owning component's **build** or another custom builder (within that custom component) function only.

- Inside the custom builder function body, **this** refers to the owning component. Component state variables are accessible from within the custom builder function implementation. Using the custom components' state variables is recommended over parameter passing.


### Global Custom Builder Function

Syntax:


```ts
@Builder function MyGlobalBuilderFunction({ ... })
```

Usage:


```ts
MyGlobalBuilderFunction()
```


- A global custom builder function is accessible from the entire application. **this** and the **bind** method are not allowed.

- Use of a global custom builder function is recommended if no own state is required.


## Parameter Passing Rules

There are two types of parameter passing for custom builder functions: [by-value parameter passing](#by-value-parameter-passing) and [by-reference parameter passing](#by-reference-parameter-passing). Both of them must comply with the following rules:

- The parameter type must be the same as the declared parameter type. The **undefined** or **null** constants as well as expressions evaluating to these values are not allowed.

- All parameters are immutable inside the custom builder function. If mutability and synchronization of the mutation is required, the custom builder should be replaced by a custom component with a [@Link](arkts-link.md) decorated variable.

- The \@Builder function body follows the same [syntax rules](arkts-create-custom-components.md#build-function) as the **build** function.


### By-Reference Parameter Passing

In by-reference parameter passing, the passed parameters can be state variables, and the change of these state variables causes the UI re-rendering in the \@Builder method. ArkUI provides $$ as a paradigm for by-reference parameter passing.


```ts
ABuilder( $$ : { paramA1: string, paramB1 : string } );
```



```ts
@Builder function ABuilder($$: { paramA1: string }) {
  Row() {
    Text(`UseStateVarByReference: ${$$.paramA1} `)
  }
}
@Entry
@Component
struct Parent {
  @State label: string = 'Hello';
  build() {
    Column() {
      // Pass the this.label reference to the ABuilder component when the ABuilder component is called in the Parent component.
      ABuilder({ paramA1: this.label })
      Button('Click me').onClick(() => {
        // After Click me is clicked, the UI text changes from Hello to ArkUI.
        this.label = 'ArkUI';
      })
    }
  }
}
```


### By-Value Parameter Passing

By default, parameters in the \@Builder decorated functions are passed by value. When the passed parameter is a state variable, the change of the state variable does not cause the UI re-rendering in the \@Builder method. Therefore, when using state variables, you are advised to use [by-reference parameter passing](#by-reference-parameter-passing).


```ts
@Builder function ABuilder(paramA1: string) {
  Row() {
    Text(`UseStateVarByValue: ${paramA1} `)
  }
}
@Entry
@Component
struct Parent {
  label: string = 'Hello';
  build() {
    Column() {
      ABuilder(this.label)
    }
  }
}
```
