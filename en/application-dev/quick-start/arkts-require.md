# \@Require Decorator: Validating Constructor Input Parameters


\@Require is a decorator for declaring that parameters must be passed in to the constructor. This decorator must be used with \@Prop or \@BuilderParam.


> **NOTE**
>
> This decorator is supported since API version 11.

## Overview

When \@Require is used together with \@Prop or \@BuilderParam, parameters must be passed in to the constructor of a custom component.

## Constraints

The \@Require decorator can only decorate an \@Prop or \@BuilderParam decorated member variable in a struct.

## Use Scenarios

When the \@Require decorator is used together with \@Prop or \@BuilderParam in the **Child** component, the parent component **Index** must pass in parameters for constructing the **Child** component. Otherwise, the compilation fails.

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
      Child({ initMessage: this.message, message: this.message,
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

## Nonexample

```
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
