# \@Require Decorator: Validating Constructor Input Parameters


\@Require is a decorator for declaring that parameters – regular variables (those not decorated by any decorator) or variables decorated by \@Prop, \@State, \@Provide, or \@BuilderParam – must be passed in to the constructor.


> **NOTE**
>
> Validation for \@Prop and \@BuilderParam decorated variables is supported since API version 11.
>
> Validation for regular variables is supported since API version 12.

## Overview

When \@Require is used together with a regular variable or a variable decorated by \@Prop, \@State, \@Provide, or \@BuilderParam, the variable must be passed as the input parameter in to the constructor of a custom component.

## Constraints

The \@Require decorator can only decorate a regular variable or a variable decorated by \@Prop, \@State, \@Provide, or \@BuilderParam in a struct.

## Use Scenarios

When the \@Require decorator is used together with a regular variable or a variable decorated by \@Prop, \@State, \@Provide, or \@BuilderParam in the **Child** component, the parent component **Index** must pass in the variable for constructing the **Child** component. Otherwise, the compilation fails.

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  @Builder buildTest() {
    Row() {
      Text('Hello, world')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      Child({ regular_value: this.message, state_value: this.message, provide_value: this.message, initMessage: this.message, message: this.message,
        buildTest: this.buildTest, initbuildTest: this.buildTest })
    }
  }
}

@Component
struct Child {
  @Builder buildFuction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
  @Require @BuilderParam buildTest: () => void;
  @Require @BuilderParam initbuildTest: () => void = this.buildFuction;
  @Require @Prop initMessage: string = 'Hello';
  @Require @Prop message: string;

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      Text(this.message)
        .fontSize(30)
      this.initbuildTest();
      this.buildTest();
    }
    .width('100%')
    .height('100%')
  }
}
```

 ![img](figures/9e2d58bc-b0e1-4613-934b-8e4237bd5c05.png) 

## Incorrect Usage

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  @Builder buildTest() {
    Row() {
      Text('Hello, world')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      Child()
    }
  }
}

@Component
struct Child {
  @Builder buildFuction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  // As @Require is used here, parameters must be passed in to the constructor.
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
  @Require @BuilderParam initbuildTest: () => void = this.buildFuction;
  @Require @Prop initMessage: string = 'Hello';

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      this.initbuildTest();
    }
  }
}
```
