# \@Require Decorator: Validating Constructor Input Parameters

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @VictorS67-->
<!--Designer: @VictorS67-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:11:33.065Z pushedAt=2026-07-23T02:27:02.040Z -->

[\@Require](../../reference/apis-arkui/arkui-ts/ts-universal-require-dynamic.md#require) is a decorator that validates whether \@Prop, \@State, \@Provide, \@BuilderParam, \@Param, and regular variables (variables without stateless decorator modification) require constructor parameter passing.

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

## Use Cases

When the \@Require decorator is used together with a regular variable or a variable decorated with \@Prop, \@State, \@Provide, \@BuilderParam, or \@Param in a child component, the parent component (for example, **SceneRequire**) must pass in the variable for constructing the child component. Failure to do so will result in a compilation error.

<!-- @[scene_require_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RequireDemo/entry/src/main/ets/pages/SceneRequire.ets) -->

``` TypeScript
@Entry
@Component
struct SceneRequire {
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
        regularValue: this.message,
        stateValue: this.message,
        provideValue: this.message,
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
  @Require regularValue: string;
  @Require @State stateValue: string;
  @Require @Provide provideValue: string;
  @Require @BuilderParam buildTest: () => void;
  @Require @BuilderParam initBuildTest: () => void;
  @Require @Prop initMessage: string;
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

The **ChildPage** component customized using [\@ComponentV2](./arkts-create-custom-components.md#componentv2) is initialized using the **ParentPage** component. Because \@Require is used to decorate \@Param, the parent component must assign a value to it during construction.

<!-- @[parent_require_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RequireDemo/entry/src/main/ets/pages/ParentPage.ets) -->

``` TypeScript
@ObservedV2
class Info {
  @Trace public name: string = '';
  @Trace public age: number = 0;
}

@ComponentV2
struct ChildPage {
  @Require @Param childInfo: Info;
  @Require @Param stateValue: string;

  build() {
    Column() {
      Text(`ChildPage childInfo name :${this.childInfo.name}`)
        .fontSize(15)
        .height(30)
      Text(`ChildPage childInfo age :${this.childInfo.age}`)
        .fontSize(15)
        .height(30)
      Text(`ChildPage stateValue age :${this.stateValue}`)
        .fontSize(15)
        .height(30)
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
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1.
        .fontSize(25)
        .height(30)
      // The parent component ParentPage performs construction assignment when initializing the child component ChildPage.
      // Values are passed to the childInfo and stateValue properties in ChildPage, which are decorated with @Require and @Param.
      ChildPage({ childInfo: this.info1, stateValue: this.label1 }) // Create a custom component.
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2.
        .fontSize(25)
        .height(30)
      // Similarly, construction assignment is performed when the parent component creates the child component.
      ChildPage({ childInfo: this.info2, stateValue: this.label2 }) // Create a custom component.
      Button('change info1&info2')
        .onClick(() => {
          this.info1 = { name: 'Cat', age: 18 }; // Text1 is not re-rendered because info1 is not decorated with a decorator and cannot listen for value changes.
          this.info2 = { name: 'Cat', age: 18 }; // Text2 will be re-rendered because info2 is decorated with a decorator and can listen for value changes.
          this.label1 = 'Luck'; // No re-rendering occurs because label1 is not decorated with a decorator and cannot listen for value changes.
          this.label2 = 'Luck'; // Re-rendering occurs because label2 is decorated with a decorator and can listen for value changes.
        })
    }
    .width('100%')
  }
}
```

![](figures/arkts-require-1.gif)

Since API version 18, \@Require can decorate state variables decorated with \@State, \@Prop, or \@Provide without requiring a local initial value. These variables can be used directly in the component without compilation errors.

<!-- @[page_one_require_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RequireDemo/entry/src/main/ets/pages/PageOne.ets) -->

``` TypeScript
@Entry
@Component
struct PageOne {
  message: string = 'Hello World';

  build() {
    Column() {
      ChildIndex({ message: this.message })
    }
  }
}

@Component
struct ChildIndex {
  @Require @State message: string;

  build() {
    Column() {
      Text(this.message) // No local initial value needed (since API version 18).
    }
  }
}
```

## FAQs

When the \@Require decorator is used with \@Prop, \@State, \@Provide, \@BuilderParam, and common variables (variables not decorated with state decorators) in a state management V1 component, if the parent component **Index** does not pass the corresponding parameters when constructing **Child**, the compilation fails. When the \@Require decorator is used with \@Param in a state management V2 component, if the parent component **Index** does not pass the corresponding parameters when constructing **ChildV2**, the compilation fails.

**Incorrect Usage**

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World!';

  @Builder
  buildTest() {
    Row() {
      Text('Hello, world!!')
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
  // @Require decorated parameters that are not passed by the parent component
  @Require regularValue: string;
  @Require @State stateValue: string;
  @Require @Provide provideValue: string;
  @Require @BuilderParam initBuildTest: () => void;
  @Require @Prop initMessage: string;

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

If the parent component **Example** passes corresponding parameters when constructing **ChildV1** and **ChildV2**, the compilation is successful.

**Correct Usage**

<!-- @[example_require_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RequireDemo/entry/src/main/ets/pages/Example.ets) -->

``` TypeScript
@Entry
@Component
struct Example {
  @State message: string = 'Hello World!';

  @Builder
  buildTest() {
    Row() {
      Text('Hello, world!!')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      // Pass parameters during ChildV1 and ChildV2 construction. The compilation is successful.
      ChildV1({
        regularValue: 'Hello',
        stateValue: 'Hello',
        provideValue: 'Hello',
        initBuildTest: this.buildTest,
        initMessage: 'Hello'
      })
      ChildV2({ message: this.message })
    }
  }
}

@Component
struct ChildV1 {
  // @Require decorated parameters that are not passed by the parent component
  @Require regularValue: string;
  @Require @State stateValue: string;
  @Require @Provide provideValue: string;
  @Require @BuilderParam initBuildTest: () => void;
  @Require @Prop initMessage: string;

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

<!--no_check-->