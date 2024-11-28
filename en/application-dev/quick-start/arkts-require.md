# \@Require Decorator: Validating Constructor Input Parameters


\@Require is a decorator for declaring that parameters – regular variables (those not decorated by any decorator) or variables decorated by \@Prop, \@State, \@Provide, or \@BuilderParam – must be passed in to the constructor.


> **NOTE**
>
> Validation for \@Prop and \@BuilderParam decorated variables is supported since API version 11.
>
> Validation for regular variables and \@State or \@Provide decorated variables is supported since API version 12.
> This decorator can be used in atomic services since API version 11.


## Overview

When \@Require is used together with a regular variable or a variable decorated by \@Prop, \@State, \@Provide, or \@BuilderParam in a custom component, the variable must be passed from the parent component during construction of the custom component.

## Constraints

The \@Require decorator can only decorate a regular variable or a variable decorated by \@Prop, \@State, \@Provide, or \@BuilderParam in a struct.

For details about the usage in DevEco Studio Previewer, see [PreviewChecker Inspection Rules](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-previewer-previewchecker-V5).

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
        buildTest: this.buildTest, initBuildTest: this.buildTest })
    }
  }
}

@Component
struct Child {
  @Builder buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
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

 ![img](figures/9e2d58bc-b0e1-4613-934b-8e4237bd5c05.png) 

@ComponentV2 decorated custom component **ChildPage** is initialized through the parent component **ParentPage**. Because the parent component is decorated by @Require, it must be constructed and assigned a value.

```ts
@ObservedV2
class Info {
  @Trace name: string = '';
  @Trace age: number = 0;
}

@ComponentV2
struct ChildPage {
  @Require @Param childInfo: Info = new Info();
  @Require @Param state_value: string = "Hello";
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
  info1: Info = { name: "Tom", age: 25 };
  label1: string = "Hello World";
  @Local info2: Info = { name: "Tom", age: 25 };
  @Local label2: string = "Hello World";

  build() {
    Column() {
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info1, state_value: this.label1}) // Calling a custom component.
      Line()
        .width('100%')
        .height(5)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info2, state_value: this.label2}) // Calling a custom component.
      Line()
        .width('100%')
        .height(5)
        .backgroundColor('#000000').margin(10)
      Button("change info1&info2")
        .onClick(() => {
          this.info1 = { name: "Cat", age: 18} // Text1 is not re-rendered because no decorator is used to listen for value changes.
          this.info2 = { name: "Cat", age: 18} // Text2 is re-rendered because a decorator is used to listen for value changes.
          this.label1 = "Luck"; // ChildPage is not re-rendered because no decorator is used to listen for value changes.
          this.label2 = "Luck"; // ChildPage is re-rendered because a decorator is used to listen for value changes.
        })
    }
  }
}
```

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
  @Builder buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  // As @Require is used here, parameters must be passed in to the constructor.
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
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
```
