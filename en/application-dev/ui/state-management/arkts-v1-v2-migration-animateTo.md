# Migration for AnimateTo Usage
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=5cbda8a742fe4c75db3800c28ccfc8ffcd9cebc0 translatedAt=2026-06-30T03:38:00.757Z pushedAt=2026-06-30T03:38:22.226Z -->

During the migration of state management from V1 to V2, if you need to modify state variables before executing an animation with [animateTo](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#animateto), you can refer to the adaptation solution in this document.

## Redefining the Initial State Before Executing an Animation

**V1 implementation code**:

<!-- @[Local_Question_V1_animateTo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalQuestionV1animateTo.ets) -->   

``` TypeScript
@Entry
@Component
struct Index {
  @State w: number = 50; // Width.
  @State h: number = 50; // Height.
  @State message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // Values are changed additionally before the animation is executed.
          this.w = 100;
          this.h = 100;
          this.message = 'Hello World';
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            this.w = 200;
            this.h = 200;
            this.message = 'Hello ArkUI';
          })
        })
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.w)
      .height(this.h)
    }
  }
}
```

Expected animation effect: The green rectangle changes from 100 x 100 to 200 x 200, and the string changes from **Hello World** to **Hello ArkUI**.

![arkts-new-local-animateTo-2](./figures/arkts-new-local-animateTo-2.gif)

**Migration from V1 to V2**

<!-- @[Local_Question_V2_animateTo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalQuestionV2animateTo.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct Index {
  @Local w: number = 50; // Width.
  @Local h: number = 50; // Height.
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // Values are changed additionally before the animation is executed.
          this.w = 100;
          this.h = 100;
          this.message = 'Hello World';
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            this.w = 200;
            this.h = 200;
            this.message = 'Hello ArkUI';
          })
        })
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.w)
      .height(this.h)
    }
  }
}
```

However, due to the current incompatibility between **animateTo** and state management V2's update mechanism, the additional modifications before the animation do not take effect. The actual animation effect is as follows: The green rectangle transitions from 50 x 50 to 200 x 200, and the text changes from **Hello** to **Hello ArkUI**, as shown in the following figure.

![arkts-new-local-animateTo-1](./figures/arkts-new-local-animateTo-1.gif)


## Migration Solution


### Migration Solution Before API Version 22

Before API version 22, you can use [animateToImmediately](../../reference/apis-arkui/arkui-ts/ts-explicit-animatetoimmediately.md#animatetoimmediately) with **duration** set to **0** to apply the additional modifications and then execute the original animation to achieve the expected effect.

The complete code is as follows:

<!-- @[Local_Question_animateToImmediately](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalQuestionAnimateToImmediately.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct Index {
  @Local w: number = 50; // Width.
  @Local h: number = 50; // Height.
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // Values are changed additionally before the animation is executed.
          this.w = 100;
          this.h = 100;
          this.message = 'Hello World';
          animateToImmediately({
            duration: 0
          }, () => {
          })
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            this.w = 200;
            this.h = 200;
            this.message = 'Hello ArkUI';
          })
        })
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.w)
      .height(this.h)
    }
  }
}
```


### Migration Solution Since API Version 22

Since API version 22, you can use the [applySync API](./arkts-new-applySync-flushUpdates-flushUIUpdates.md) to achieve the expected display effect.

The principle is as follows: Use the **applySync** API to synchronously update the state variables changes in the closure function, and then execute the original animation to achieve the expected effect.

<!-- @[Local_Question_Expected_Effect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/local/LocalQuestionExpectedEffect.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local w: number = 50; // Width.
  @Local h: number = 50; // Height.
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // Values are changed additionally before the animation is executed.
          UIUtils.applySync(() => {
            this.w = 100;
            this.h = 100;
            this.message = 'Hello World';
          })
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            this.w = 200;
            this.h = 200;
            this.message = 'Hello ArkUI';
          })
        })
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.w)
      .height(this.h)
    }
  }
}
```