# \@Require Decorator: Validating Constructor Input Parameters
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @VictorS67-->
<!--Designer: @lixingchi1-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The \@Require decorator is used to declare that specific parameters – either regular variables (not decorated by any other decorator) or variables decorated with \@Prop, \@State, \@Provide, \@BuilderParam, or \@Param – must be passed in to the constructor.

> **NOTE**
>
> Validation for \@Prop and \@BuilderParam decorated variables is supported since API version 11.
>
> This decorator is supported in ArkTS widgets since API version 11.
>
> This decorator can be used in atomic services since API version 11.
>
> Validation for regular variables and \@State, \@Provide, or \@Param decorated variables is supported since API version 12.

## Overview

When \@Require is applied to a regular variable or a variable decorated with [\@Prop](./arkts-prop.md), [\@State](./arkts-state.md), [\@Provide](./arkts-provide-and-consume.md), [\@Param](./arkts-new-param.md), or [\@BuilderParam](./arkts-builderparam.md) within a custom component, that variable must be provided during the construction of the custom component.

## Constraints

The \@Require decorator can only decorate a regular variable or a variable decorated with \@Prop, \@State, \@Provide, \@BuilderParam, or \@Param in a struct.

For details about the usage in DevEco Studio Previewer, see [PreviewChecker Inspection Rules](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-previewer-previewchecker-V5).

## Use Scenarios

When the \@Require decorator is used together with a regular variable or a variable decorated with \@Prop, \@State, \@Provide, \@BuilderParam, or \@Param in a child component, the parent component (for example, **Index**) must pass in the variable for constructing the child component. Failure to do so will result in a compilation error.

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  @Builder
  buildTest() {
    Row() {
      Text('Hello, world')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      // All @Require decorated parameters in Child must be passed here.
      Child({
        regular_value: this.message,
        state_value: this.message,
        provide_value: this.message,
        initMessage: this.message,
        message: this.message,
        buildTest: this.buildTest,
        initBuildTest: this.buildTest
      })
    }
  }
}

@Component
struct Child {
  @Builder
  buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }

  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = 'Hello';
  @Require @Provide provide_value: string = 'Hello';
  @Require @BuilderParam buildTest: () => void;
  @Require @BuilderParam initBuildTest: () => void = this.buildFunction;
  @Require @Prop initMessage: string = 'Hello';
  @Require @Prop message: string;

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      Text(this.message)
        .fontSize(30)
      this.initBuildTest();
      this.buildTest();
    }
    .width('100%')
    .height('100%')
  }
}
```


A custom component **ChildPage** decorated with \@ComponentV2 is initialized by its parent component **ParentPage**. Since \@Param decorated variables are also decorated with \@Require, **ParentPage** must pass these variables with assigned values during construction.

```ts
@ObservedV2
class Info {
  @Trace name: string = '';
  @Trace age: number = 0;
}

@ComponentV2
struct ChildPage {
  @Require @Param childInfo: Info = new Info();
  @Require @Param state_value: string = 'Hello';

  build() {
    Column() {
      Text(`ChildPage childInfo name :${this.childInfo.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`ChildPage childInfo age :${this.childInfo.age}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`ChildPage state_value age :${this.state_value}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Entry
@ComponentV2
struct ParentPage {
  info1: Info = { name: 'Tom', age: 25 };
  label1: string = 'Hello World';
  @Local info2: Info = { name: 'Tom', age: 25 };
  @Local label2: string = 'Hello World';

  build() {
    Column() {
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      // The parent component ParentPage performs construction assignment when initializing the child component ChildPage.
      // Values are passed to the childInfo and state_value properties in ChildPage, which are decorated with @Require and @Param.
      ChildPage({ childInfo: this.info1, state_value: this.label1 }) // Create a custom component.
      Line()
        .width('100%')
        .height(5)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      // Similarly, construction assignment is performed when the parent component creates the child component.
      ChildPage({ childInfo: this.info2, state_value: this.label2 }) // Create a custom component.
      Line()
        .width('100%')
        .height(5)
        .backgroundColor('#000000').margin(10)
      Button('change info1&info2')
        .onClick(() => {
          this.info1 = { name: 'Cat', age: 18 }; // Text1 is not re-rendered because info1 is not decorated with a decorator and cannot listen for value changes.
          this.info2 = { name: 'Cat', age: 18 }; // Text2 will be re-rendered because info2 is decorated with a decorator and can listen for value changes.
          this.label1 = 'Luck'; // No re-rendering occurs because label1 is not decorated with a decorator and cannot listen for value changes.
          this.label2 = 'Luck'; // Re-rendering occurs because label2 is decorated with a decorator and can listen for value changes.
        })
    }
  }
}
```

Since API version 18, \@Require can decorate state variables decorated with \@State, \@Prop, or \@Provide) without requiring a local initial value. These variables can be used directly in the component without compilation errors.

```ts
@Entry
@Component
struct Index {
  message: string = 'Hello World';

  build() {
    Column() {
      Child({ message: this.message })
    }
  }
}

@Component
struct Child {
  @Require @State message: string;

  build() {
    Column() {
      Text(this.message) // No local initial value needed (since API version 18).
    }
  }
}
```

## Common Issues

If a parent component fails to pass a parameter required by \@Require in the child component, compilation will fail.

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  @Builder
  buildTest() {
    Row() {
      Text('Hello, world')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      // Error: The @Require decorated parameters are not passed during Child and ChildV2 construction.
      Child()
      ChildV2()
    }
  }
}

@Component
struct Child {
  @Builder
  buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }

  // @Require decorated parameters that are not passed by the parent component
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = 'Hello';
  @Require @Provide provide_value: string = 'Hello';
  @Require @BuilderParam initBuildTest: () => void = this.buildFunction;
  @Require @Prop initMessage: string = 'Hello';

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      this.initBuildTest();
    }
  }
}

@ComponentV2
struct ChildV2 {
  // @Require decorated parameters that are not passed by the parent component
  @Require @Param message: string;

  build() {
    Column() {
      Text(this.message)
    }
  }
}
```
