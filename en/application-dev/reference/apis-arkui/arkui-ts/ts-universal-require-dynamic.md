# \@Require Decorator: Validating Constructor Input Parameters

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4b4c3fae8bb5dd3f2fd16533483d2b6e26cbc14a translatedAt=2026-08-11T01:49:04.952Z pushedAt=2026-08-13T11:30:48.936Z -->

The **\@Require** decorator validates whether [\@Prop](../../../ui/state-management/arkts-prop.md), [\@State](../../../ui/state-management/arkts-state.md), [\@Provide](../../../ui/state-management/arkts-provide-and-consume.md), [\@BuilderParam](../../../ui/state-management/arkts-builderparam.md), [\@Param](../../../ui/state-management/arkts-new-param.md), and regular variables (variables not decorated by any state decorator) require constructor input parameters. When a variable is decorated with **\@Require**, the parent component must pass the corresponding parameter when constructing the child component. Otherwise, a compile-time error is reported, thereby preventing runtime exceptions caused by missing parameters. This decorator is suitable for scenarios where mandatory parameters of a custom component must be properly initialized.

See the development guide: [\@Require Decorator: Validating Constructor Input Parameters](../../../ui/state-management/arkts-require.md).

> **NOTE**
>
> - This decorator is supported since API version 11.
>
> - Validation for **\@Prop** and **\@BuilderParam** is supported since API version 11.
>
> - Validation for **\@State**, **\@Provide**, **\@Param**, and regular variables (variables not decorated by any state decorator) is supported since API version 12.

## @Require

const Require: PropertyDecorator

**Model restriction:** This API can be used only in the stage model.

**Widget capability**: This API can be used in ArkTS widgets since API version 11.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example**

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
      // Pass in all @Require parameters when constructing Child. Otherwise, compilation fails.
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
  @Builder
  buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }

  @Require regularValue: string = 'Hello';
  @Require @State stateValue: string = 'Hello';
  @Require @Provide provideValue: string = 'Hello';
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
      this.initBuildTest()
      this.buildTest()
    }
    .width('100%')
    .height('100%')
  }
}
```