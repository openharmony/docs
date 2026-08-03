# \@Reusable V2 Decorator: Reusing V2 Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:08:39.741Z pushedAt=2026-07-23T10:40:37.005Z -->

To reduce the performance overhead caused by repeatedly creating and destroying custom components, you can use [\@ReusableV2](../../reference/apis-arkui/arkui-ts/ts-custom-component-decorator-reusablev2.md#reusablev2) to decorate custom components decorated by [\@ComponentV2](./arkts-create-custom-components.md#componentv2), thereby achieving component reuse.

Before reading this topic, you are advised to read [\@Reusable Decorator: Reusing V1 Components](./arkts-reusable.md).

>**NOTE**
>
> The \@ReusableV2 decorator is supported since API version 18.
>
> This decorator can be used in atomic services since API version 18.

## Overview

Using \@ReusableV2 to decorate the custom components of V2 indicates that these components are reusable.

- \@ReusableV2 can decorate only custom components of V2, that is, custom components decorated by \@ComponentV2. In addition, only \@ReusableV2 decorated custom components can be used as child components of custom components of V2.

- \@ReusableV2 also provides the lifecycle methods [aboutToRecycle](../../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttorecycle10) and [aboutToReuse](../../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoreuse18). **aboutToRecycle** is called when the component is recycled, and **aboutToReuse** is called when the component is reused. However, unlike \@Reusable, **aboutToReuse** has no input parameters.

- In the recycling phase, **aboutToRecycle** of all child components is recursively called (even if the child components are not reusable). In the reuse phase, so does **aboutToReuse** of all child components.

- The custom component decorated with \@ReusableV2 remains frozen during recycling. That is, the UI re-render and the [\@Monitor](./arkts-new-monitor.md) callback cannot be triggered. Different from the [freezeWhenInactive](./arkts-custom-components-freezeV2.md) flag, the delayed re-render is not triggered after the \@ReusableV2 decorated custom component is unfrozen.

- When an \@ReusableV2 decorated custom component is reused, its state variables are automatically reset, and the [@Computed](./arkts-new-computed.md) properties and related @Monitor callbacks within the component are recalculated. You are not advised to change the state variable of a component in **aboutToRecycle**. For details, see [Resetting State Variables in Components Before Reuse](#resetting-state-variables-in-components-before-reuse).

- The reusable components of V1 and V2 can be used together under certain rules. For details, see the second point in [Constraints](#constraints).

- Do not overuse the \@ReusableV2 decorator. Otherwise, the reuse efficiency may be undermined and the memory overhead may increase.

## Decorator Description

| \@ReusableV2 Decorator| Description                         |
| ------------------ | ----------------------------- |
| Decorator parameters        | None                           |
| Decoratable components      | \@ComponentV2 decorated custom components|
| Function        | Indicates that a component is reusable.           |

<!-- @[ReusableV2Component1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/common/ReusableV2Component1.ets) -->  

``` TypeScript
@ReusableV2 // Decorates @ComponentV2 decorated custom components.
@ComponentV2
struct ReusableV2Component {
  @Local message: string = 'Hello World';
  build () {
    Column() {
      Text(this.message)
    }
  }
}
```

## Description

For details about the **reuse**, **ReuseOptions**, and **ReuseIdCallback** APIs, see [Reuse Options](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-reuse.md).

<!-- @[ExamplePage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/ExamplePage.ets) -->

``` TypeScript
@Entry
@ComponentV2
struct Index {
  build() {
    Column() {
      ReusableV2Component()
        .reuse({ reuseId: () => 'reuseComponent' }) // Use 'reuseComponent' as reuseId.
      ReusableV2Component()
        .reuse({ reuseId: () => '' }) // If an empty string is used, the component name 'ReusableV2Component' is used as reuseId.
      ReusableV2Component() // If reuseId is not specified, the component name 'ReusableV2Component' is used as reuseId.
    }
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  build() {
  }
}
```

## Constraints

- Only \@ReusableV2 decorated custom components can be used as child components of custom components of V2. If a reusable component of V2 is used in the custom components of V1, an error is reported during compilation. In complex scenarios where verification cannot be performed during compilation, an error is reported during runtime.

  <!-- @[UsageRestrictionsPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/UsageRestrictionsPage.ets) -->

  ``` TypeScript
  @Entry
  @ComponentV2
  struct Index {
    build() {
      Column() {
        ReusableV2Component() // Correct usage.
      }
    }
  }
  
  @ReusableV2
  @ComponentV2
  struct ReusableV2Component {
    build() {
    }
  }
  
  @Builder
  function V2ReusableBuilder() {
    ReusableV2Component()
  }
  ```

- The following describes some mixed use cases of V1 and V2.

  The mapping between a component and its type is listed in the table below.

  | Description      | Type                        |
  | ---------- | ------------------------------------ |
  | Common component of V1| [\@Component](./arkts-create-custom-components.md#component) decorated struct.              |
  | Common component of V2| @ComponentV2 decorated struct            |
  | Reusable component of V1| @Reusable and @Component decorated struct    |
  | Reusable component of V2| @ReusableV2 and @ComponentV2 decorated struct|

  The following table shows the mixed use support between V1 and V2, indicating whether components in the second to fifth columns can be used as child components of the parent components in the first column.

  For example, the common component of V1, common component of V2, and reusable component of V1 can be used as child components of the common component of V1 except the reusable component of V2.

  | Mixed use support| Common component of V1| Common component of V2|               Reusable component of V1              |    Reusable component of V2   |
  | ------------ | :--------: | :--------: | :------------------------------------: | :--------------: |
  | Common component of V1  |    Yes   |    Yes   |                  Yes                 | No. An error is reported during compilation.|
  | Common component of V2  |    Yes   |    Yes   | No. An error is reported during compilation. The actual used child component is not created.|       Yes      |
  | Reusable component of V1  |    Yes   |    Yes. The SDK of API version 18 or later is required. Otherwise, a runtime error is reported. Since API version 23, the error code[140113](../../reference/apis-arkui/errorcode-stateManagement.md#140113-toolchain-version-is-too-early-when-componentv2-custom-components-are-reused) will be returned.    |                  Yes                 | No. An error is reported during compilation.|
  | Reusable component of V2  |    Yes   |    Yes   |            No. An error is reported during compilation.           |       Yes      |

  According to the preceding table, only 12 possible parent-child relationships are supported. You are advised not to highly nest reusable components, because it will reduce the reuse efficiency.

- The reusable components of V2 cannot be directly used in the **template** of [Repeat](../../reference/apis-arkui/arkui-ts/ts-rendering-control-repeat.md), but can be used in the custom component of V2 in **template**.

  <!-- @[RepeatTemplatePage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/RepeatTemplatePage.ets) -->

  ``` TypeScript
  @Entry
  @ComponentV2
  struct Index {
    @Local arr: number[] = [1, 2, 3, 4, 5];
  
    build() {
      Column() {
        List() {
          Repeat(this.arr)
            .each(() => {
            })
            .virtualScroll()
            .templateId(() => 'a')
            .template('a', (ri) => {
              ListItem() {
                Column() {
                  NormalV2Component({ val: ri.item }) // Reusable components of V2 can be used in common custom components of V2.
                }
              }
            })
        }
      }
    }
  }
  
  @ComponentV2
  struct NormalV2Component {
    @Require @Param val: number;
  
    build() {
      ReusableV2Component({ val: this.val })
    }
  }
  
  @Builder
  function ReusableV2Builder(param: number) {
    ReusableV2Component({ val: param })
  }
  
  @ReusableV2
  @ComponentV2
  struct ReusableV2Component {
    @Require @Param val: number;
  
    build() {
      Column() {
        Text(`val: ${this.val}`)
      }
    }
  }
  ```

## Lifecycle of Recycling and Reuse

\@ReusableV2 provides the **aboutToRecycle** and **aboutToReuse** callbacks, which are called respectively when a component is recycled and reused.

The following uses the **if** statement as an example:

<!-- @[AboutToRecyclePage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/AboutToRecyclePage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@Entry
@ComponentV2
struct Index {
  @Local condition1: boolean = false;
  @Local condition2: boolean = true;

  build() {
    Column({ space: 10 }) {
      Button('step1. appear')
        .width('60%')
        .onClick(() => {
          this.condition1 = true;
        })
      Button('step2. recycle')
        .width('60%')
        .onClick(() => {
          this.condition2 = false;
        })
      Button('step3. reuse')
        .width('60%')
        .onClick(() => {
          this.condition2 = true;
        })
      Button('step4. disappear')
        .width('60%')
        .onClick(() => {
          this.condition1 = false;
        })
      if (this.condition1) {
        NormalV2Component({ condition: this.condition2 })
      }
    }
    .width('100%')
  }
}

@ComponentV2
struct NormalV2Component {
  @Require @Param condition: boolean;

  build() {
    if (this.condition) {
      ReusableV2Component()
    }
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  aboutToAppear() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToAppear called'); // Called when a component is created.
  }

  aboutToDisappear() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToDisappear called'); // Called when a component is destroyed.
  }

  aboutToRecycle() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToRecycle called'); // Called when a component is recycled.
  }

  aboutToReuse() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToReuse called'); // Called when a component is reused.
  }

  build() {
    Column() {
      Text('ReusableV2Component')
    }
  }
}
```

You are advised to follow the steps below:

1. Click **step1. appear** to change the value of **condition1** to **true**. The **if** component in **Index** switches the branch and creates a **NormalV2Component**. Due to the initial value **true** of **condition2**, the **if** condition in **NormalV2Component** is met and the system attempts to create a **ReusableV2Component**. In this case, there is no element in the reuse pool. Therefore, **ReusableV2Component** is created, the **aboutToAppear** method is called back, and the log **ReusableV2Component aboutToAppear called** is output.

2. Click **step2. recycle** to change the value of **condition2** to **false** and synchronize this change to **NormalV2Component** through \@Param. The **if** condition is switched. Because **ReusableV2Component** uses \@ReusableV2, the component is recycled to the reuse pool instead of being destroyed. The **aboutToRecycle** method is called back and the log **ReusableV2Component aboutToRecycle called** is output.

3. Click **step3. reuse** to change the value of **condition2** to **true** and synchronize this change to **NormalV2Component** through \@Param. The **if** condition is switched. Because **ReusableV2Component** uses \@ReusableV2, the system attempts to search for the component in the reuse pool when creating the component. In this case, the component recycled in step 2 is reused from the reuse pool, the **aboutToReuse** method is called back, and the log **ReusableV2Component aboutToReuse called** is output.

4. Click **step4. disappear** to change the value of **condition1** to **false**. The **if** component in **Index** switches the branch and destroys **NormalV2Component**. In this case, **ReusableV2Component** is destroyed due to the destroyed parent component, the **aboutToDisappear** method is called back, and the log **ReusableV2Component aboutToDisappear called** is output.

If the reusable component has child components, **aboutToRecycle** and **aboutToReuse** of the child components are recursively called during recycling and reuse (irrelevant to whether the child components are marked for reuse) until all child components are traversed.

![lifecycle](./figures/reusablev2-lifecycle.gif)

## Component Freezing in the Reuse Phase

In the previous reuse, components of V1 can still respond to updates in the reuse pool, which has a negative impact on performance. Therefore, you need to use the component freezing capability to resolve this issue. For this, V2 components are automatically frozen when reused and do not respond to changes that occur during recycling. For example, changes in **aboutToRecycle** are not updated to the UI, and \@Computed and \@Monitor are not triggered. The frozen state lasts until **aboutToReuse** and subsequent variables change. In this case, the UI re-render, \@Computed recalculation, and \@Monitor are triggered.

The following uses the **if** statement as an example:

<!-- @[ConditionPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/ConditionPage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@ObservedV2
class Info {
  @Trace public age: number = 25;
}

const info: Info = new Info();

@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;

  build() {
    Column({ space: 10 }) {
      Button('Reuse/Recycle')
        .width('60%')
        .onClick(() => {
          this.condition = !this.condition;
        })
      Button('Change value')
        .width('60%')
        .onClick(() => {
          info.age++;
        })
      if (this.condition) {
        ReusableV2Component()
      }
    }
    .width('100%')
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local info: Info = info; // This is used only for demonstration. You are not advised to assign a value to the global variable using @Local.

  @Monitor('info.age')
  onValChange() {
    hilog.info(DOMAIN, TAG, 'info.age change');
  }

  aboutToRecycle() {
    hilog.info(DOMAIN, TAG, 'aboutToRecycle');
    this.info.age++;
  }

  aboutToReuse() {
    hilog.info(DOMAIN, TAG, 'aboutToReuse');
    this.info.age++;
  }

  onRender(): string {
    hilog.info(DOMAIN, TAG, 'info.age onRender');
    return this.info.age.toString();
  }

  build() {
    Column() {
      Text(this.onRender())
    }
  }
}
```

You are advised to follow the steps below:

1. Click the **Change value** button to listen for the UI change. \@Monitor is triggered to output the logs **info.age change** and **info.age onRender**, indicating that the change can be listened for and the UI re-render can be triggered.

2. Click the **Reuse/Recycle** button to call the **aboutToRecycle** method and output the log of **aboutToRecycle**. However, \@Monitor is not triggered and the **onRender** method is not called back.

3. Click the **Change value** button. The UI is not re-rendered, \@Monitor is not triggered, and the **onRender** method is not called back.

4. Click the **Reuse/Recycle** button to call the **aboutToReuse** method and output the **aboutToReuse** log. \@Monitor is triggered, the **info.age change** log is output, and the **info.age onRender** log is output by the **onRender** method. The UI changes.

![freeze](./figures/reusablev2-freeze.gif)

If the auto-increment operation is removed from the **aboutToReuse** method, the \@Monitor callback is not triggered in step 4.

In complex mixed use scenarios, the rules for component freezing can be summarized as follows:

1. For Components of V1, component freezing is determined by **freezeWhenInactive**.

2. V2 components are automatically frozen.

## Resetting State Variables in Components Before Reuse

Different from \@Reusable, \@ReusableV2 resets the state variables and related \@Computed and \@Monitor content in components before reuse. During reuse, all V2 custom components, regardless of whether they are marked with \@ReusableV2, will go through this reset process.

The reset is performed based on the sequence of variables defined in the component according to the following rules.

| Decorator    | Method for Resetting                                                    |
| ---------- | ------------------------------------------------------------ |
| [\@Local](./arkts-new-local.md)    | Use the initial value for reassignment.                            |
| [\@Param](./arkts-new-param.md)    | Use external input value for reassignment. If there is no external input value, use the local initial value. Note that variables decorated by \@Once are also reset and initialized.|
| [\@Event](./arkts-new-event.md)    | Use external input value for reassignment. If there is no external input value, use the local initial value. If there is no local initial value, the default empty implementation is generated.|
| [\@Provider](./arkts-new-provider-and-consumer.md) | Use the initial value for reassignment.                            |
| [\@Consumer](./arkts-new-provider-and-consumer.md) | If the corresponding \@Provider exists, use the value of \@Provider. Otherwise, use the local initial value for reassignment.|
| \@Computed | The latest value is used for recalculation. If the used variable is not reset, the value before the reset is used. Therefore, you are advised to define \@Computed after the used variable.|
| \@Monitor  | Triggered after all the preceding variables are reset. The variable change generated during the reset does not trigger the \@Monitor callback. Only the **before** value in **IMonitorValue** is updated. Values that do not change during the reset do not trigger the reset of \@Monitor.|
| Constant      | Read-only constants are included and are not reset.                                |

The following example shows some of the effects:

<!-- @[ComputedPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/ComputedPage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@ObservedV2
class Info {
  @Trace public age: number;

  constructor(age: number) {
    this.age = age;
  }
}

@Entry
@ComponentV2
struct Index {
  @Local local: number = 0;
  @Provider('inherit') inheritProvider: number = 100;
  @Local condition: boolean = true;

  build() {
    Column({ space: 10 }) {
      Button('Recycle/Reuse')
        .onClick(() => {
          this.condition = !this.condition;
        })
      Column({ space: 10 }) {
        Text('Variables of parent component')
        Text(`local: ${this.local}`)
          .onClick(() => {
            this.local++;
          })
        Text(`inheritProvider: ${this.inheritProvider}`)
          .onClick(() => {
            this.inheritProvider++;
          })
      }
      .width('80%')
      .borderWidth(2)

      if (this.condition) {
        ReusableV2Component({
          paramOut: this.local,
          paramOnce: this.local,
          changeParam: () => {
            this.local++;
          }
        })
      }
    }
    .width('100%')
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local val: number = 0;
  @Local info: Info = new Info(25);
  @Param paramLocal: number = 1;
  @Require @Param paramOut: number;
  @Require @Param @Once paramOnce: number;
  @Event changeParam: () => void;
  @Provider('selfProvider') selfProvider: number = 0;
  @Consumer('inherit') inheritConsumer: number = 0;
  @Consumer('selfConsumer') selfConsumer: number = 0;
  noDecoVariable: number = 0; // No decorator is used. It is used as a constant.
  noDecoInfo: Info = new Info(30); // No decorator is used. It is used as a constant.
  readonly readOnlyVariable: number = 0; // Read-only constant.

  @Computed
  get plusParam() {
    return this.paramLocal + this.paramOut + this.paramOnce;
  }

  @Monitor('val')
  onValChange(monitor: IMonitor) {
    hilog.info(DOMAIN, TAG, `val change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  @Monitor('plusParam')
  onPlusParamChange(monitor: IMonitor) {
    hilog.info(DOMAIN, TAG, `plusParam change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column({ space: 10 }) {
      Column({ space: 10 }) {
        Text('Variables reset to local initial values')
        Text(`val: ${this.val}`)
          .onClick(() => {
            this.val++;
          })
        Text(`info.age: ${this.info.age}`)
          .onClick(() => {
            this.info.age++;
          })
        Text(`paramLocal: ${this.paramLocal}`)
          .onClick(() => {
            /* Local without external input value fails to be changed locally. */
          })
        Text(`selfProvider: ${this.selfProvider}`)
          .onClick(() => {
            this.selfProvider++;
          })
        Text(`selfConsumer: ${this.selfConsumer}`)
          .onClick(() => {
            this.selfConsumer++;
          })
      }
      .width('80%')
      .borderWidth(2)

      Column({ space: 10 }) {
        Text('Reset to an external variable')
        Text(`paramOut: ${this.paramOut}`)
          .onClick(() => {
            this.changeParam();
          })
        Text(`paramOnce: ${this.paramOnce}`)
          .onClick(() => {
            this.paramOnce++;
          })
      }
      .width('80%')
      .borderWidth(2)

      Column({ space: 10 }) {
        Text('Depending on the parent component')
        Text(`inheritConsumer: ${this.inheritConsumer}`)
          .onClick(() => {
            this.inheritConsumer++;
          })
        Text(`plusParam: ${this.plusParam}`)
      }
      .width('80%')
      .borderWidth(2)

      Column({ space: 10 }) {
        Text('Not reset')
        Text(`noDecoVariable: ${this.noDecoVariable}`)
        Text(`noDecoInfo.age: ${this.noDecoInfo.age}`)
          .onClick(() => {
            this.noDecoInfo.age++;
          }) // Update can be triggered but the variable is not reset.
        Text(`readOnlyVariable: ${this.readOnlyVariable}`)
      }
      .width('80%')
      .borderWidth(2)
    }
    .width('100%')
  }
}
```

You can click each variable and click **Recycle/Reuse** to view the reset state after reuse.

![reset](./figures/reusablev2-reset.gif)

In the preceding example, **noDecoInfo** is not reset. If a \@Monitor is used to listen for **noDecoInfo.age**, it will not be reset because **noDecoInfo** does not change. Therefore, when **noDecoInfo.age** is changed for the first time, the **before** value of **IMonitorValue** will not be reset, which is still the value before reuse.

The simplified example is as follows:

<!-- @[IMonitorValuePage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/IMonitorValuePage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@ObservedV2
class Info {
  @Trace public age: number;

  constructor(age: number) {
    this.age = age;
  }
}

@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;

  build() {
    Column({ space: 10 }) {
      Button('Recycle/Reuse')
        .width('60%')
        .onClick(() => {
          this.condition = !this.condition;
        })
      if (this.condition) {
        ReusableV2Component()
      }
    }
    .width('100%')
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  noDecoInfo: Info = new Info(30); // No decorator is used. It is used as a constant.

  @Monitor('noDecoInfo.age')
  onAgeChange(monitor: IMonitor) {
    hilog.info(DOMAIN, TAG, `age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  aboutToRecycle() {
    this.noDecoInfo.age = 25;
  }

  aboutToReuse() {
    this.noDecoInfo.age = 35;
  }

  build() {
    Column() {
      Column() {
        Text(`noDecoInfo.age: ${this.noDecoInfo.age}`)
          .onClick(() => {
            this.noDecoInfo.age++;
          }) // Update can be triggered but the variable is not reset.
      }
    }
  }
}
```

You are advised to follow the steps below:

1. Click **noDecoInfo.age: 30**. The UI is re-rendered to **noDecoInfo.age: 31** and \@Monitor is triggered to output the log **age change from 30 to 31**.

2. Click **Recycle/Reuse** twice. The UI is re-rendered to **noDecoInfo.age: 35** and \@Monitor is triggered to output the log **age change from 31 to 35**.

3. Click **noDecoInfo.age: 35**. The UI is re-rendered to **noDecoInfo.age: 36** and \@Monitor is triggered to output the log **age change from 35 to 36**.

![resetmonitor](./figures/reusablev2-resetmonitor.gif)

Due to the freezing mechanism, the value change in **aboutToRecycle** is not listened by \@Monitor. After the variable is reset, a new value is assigned to the variable. Therefore, for the state variable in the component, the value assignment in **aboutToRecycle** does not have obvious effect. For the constant (such as **noDecoInfo**), due to the freezing mechanism, the change of **age** in **aboutToRecycle** is not observable and cannot be reset, therefore, the \@Monitor bound to **age** will not be reset. Finally, in \@Monitor called back in step 2, the value of **monitor.value()?.before** is **31** instead of the initial value **30** of **age**.

As such, you are advised to reduce the use of constant objects that contain the [\@Trace](./arkts-new-observedV2-and-trace.md) attribute in reuse scenarios to ensure that the reuse meets expectations.

## Use Cases

### Using in the if Component

Change the conditions of the **if** component to control component recycling or reuse.

<!-- @[ComponentIfPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/ComponentIfPage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;

  build() {
    Column({ space: 10 }) {
      Button('Recycle/Reuse')
        .width('60%')
        .onClick(() => {
          this.condition = !this.condition;
        }) // Switch the recycling or reuse status.
      if (this.condition) {
        ReusableV2Component()
      }
    }
    .width('100%')
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local message: string = 'Hello World';

  aboutToRecycle() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToRecycle'); // Called when a component is recycled.
  }

  aboutToReuse() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToReuse'); // Called when a component is reused.
  }

  build() {
    Column() {
      Text(this.message)
    }
  }
}
```

![if](./figures/reusablev2-if.gif)

### Using in the Repeat Component

In the lazy loading scenario of the [Repeat](../rendering-control/arkts-new-rendering-control-repeat.md) component, the cache pool of the **Repeat** component is preferentially used. Normal scrolling and update scenarios do not involve component recycling or reuse. When the cache pool needs to be expanded, new child components are required from the custom components. In this case, if there are reusable nodes in the reuse pool, the nodes will be reused.

You can disable the reuse capability of the **Repeat** component by setting the **reusable** attribute of the **[VirtualScrollOptions](../../reference/apis-arkui/arkui-ts/ts-rendering-control-repeat.md#virtualscrolloptions)** property of this component to **false**. In this case, both scrolling and update scenarios will trigger the recycling and reuse of @ReusableV2.

In the following example, click **Change condition** to add three nodes to the reuse pool. When you slide down the **List** component, you can see the log output **ReusableV2Component aboutToReuse**, indicating that **Repeat** can use the reuse pool of the custom component to fill its cache pool.

<!-- @[RepeatPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/RepeatPage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;
  @Local simpleList: number[] = [];

  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.simpleList.push(i);
    }
  }

  build() {
    Column() {
      Button('Change condition')
        .onClick(() => {
          this.condition = !this.condition;
        })
      if (this.condition) {
        // This is only for demonstration. Fill three components in the reuse pool.
        ReusableV2Component({ num: 0 })
        ReusableV2Component({ num: 0 })
        ReusableV2Component({ num: 0 })
      }
      List({ space: 10 }) {
        Repeat(this.simpleList)
          .virtualScroll()
          .each((obj: RepeatItem<number>) => {
            ListItem() {
              Column() {
                ReusableV2Component({ num: obj.item })
              }
            }
            .width('100%')
          })
      }.height('50%')
      .cachedCount(2)
    }
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;

  aboutToAppear() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToAppear');
  }

  aboutToRecycle() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToRecycle');
  }

  aboutToReuse() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToReuse');
  }

  build() {
    Column() {
      Text(`${this.num}`).fontSize(50)
    }
  }
}
```

![repeat](./figures/reusablev2-repeat.gif)

### Using in the each Attribute of Repeat in the Non-Lazy Loading Scenarios

In the non-lazy loading scenarios of the **Repeat** component, recycling or reuse is triggered when a subtree is deleted or created.

<!-- @[ComponentEachPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/ComponentEachPage.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@Entry
@ComponentV2
struct Index {
  @Local simpleList: number[] = [1, 2, 3, 4, 5];
  @Local condition: boolean = true;

  build() {
    Column({ space: 10 }) {
      // Click the button to switch the condition and delete/create the ReusableV2Component.
      Button('Delete/Create Repeat')
        .width('60%')
        .onClick(() => {
          this.condition = !this.condition;
        })
      Button('Add element')
        .width('60%')
        .onClick(() => {
          this.simpleList.push(this.simpleList.length + 1);
        })
      Button('Delete element')
        .width('60%')
        .onClick(() => {
          this.simpleList.pop();
        })
      Button('Change element')
        .width('60%')
        .onClick(() => {
          this.simpleList[0]++;
        })
      if (this.condition) {
        List({ space: 10 }) {
          Repeat(this.simpleList)
            .each((obj: RepeatItem<number>) => {
              ListItem() {
                Column() {
                  ReusableV2Component({ num: obj.item })
                }
                .width('100%')
              }
            })
        }
      }
    }
    .width('100%')
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;

  aboutToAppear() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToAppear');
  }

  aboutToRecycle() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToRecycle');
  }

  aboutToReuse() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToReuse');
  }

  build() {
    Column() {
      Text(`${this.num}`)
    }
  }
}
```

![repeat-nonvirtual](./figures/reusablev2-repeat-nonvirtual.gif)

### Using in ForEach

>**NOTE**
>
>You are advised to use the non-lazy loading scenarios of **Repeat** to replace [ForEach](../../reference/apis-arkui/arkui-ts/ts-rendering-control-foreach.md).

In the following example, ForEach is used to render multiple reusable components. Each time the **Click to change** button is clicked, the key value changes. Therefore, recycling and reuse are triggered from the second click. (When ForEach determines whether there is reusable nodes, the reuse pool is not initialized. Therefore, when ForEach is clicked for the first time, a new node is created. Then, the reuse pool is initialized from the second click and the node is recycled at the same time.)

<!-- @[ComponentForEachPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/ComponentForEachPage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

@Entry
@ComponentV2
struct Index {
  @Local simpleList: number[] = [0, 1, 2, 3, 4, 5];

  build() {
    Column() {
      ForEach(this.simpleList, (num: number, index: number) => {
        Row() {
          Button('Click to change')
            .margin({ right: 10 })
            .onClick(() => {
              this.simpleList[index]++;
            })
          ReusableV2Component({ num: num })
        }
        .margin({ bottom: 10 })
      }) // The key changes from each click.
    }
  }
}

@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;

  aboutToAppear() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToAppear', this.num); // Triggered when the component is created.
  }

  aboutToRecycle() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToRecycle', this.num); // Triggered when the component is recycled.
  }

  aboutToReuse() {
    hilog.info(DOMAIN, TAG, 'ReusableV2Component aboutToReuse', this.num); // Triggered when the component is reused.
  }

  build() {
    Column() {
      Text(`child: ${this.num}`)
    }
  }
}
```

![foreach](./figures/reusablev2-foreach.gif)

### Using in LazyForEach

>**NOTE**
>
>You are advised to use the lazy loading scenarios of **Repeat** to replace [LazyForEach](../../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md).

In the following example, **LazyForEach** is used to render several reusable components. During sliding, component creation can be observed first. After all pre-loaded nodes are created, sliding triggers reuse and recycling.

<!-- @[LazyForEachPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ReusableV2/entry/src/main/ets/view/LazyForEachPage.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[Sample_Reusablev2]';
const DOMAIN = 0xF811;

class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: StringData[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): StringData {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      hilog.info(DOMAIN, TAG, 'add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      hilog.info(DOMAIN, TAG, 'remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    });
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    });
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    });
  }

  notifyDatasetChange(operations: DataOperation[]): void {
    this.listeners.forEach(listener => {
      listener.onDatasetChange(operations);
    });
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: StringData[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): StringData {
    return this.dataArray[index];
  }

  public addData(index: number, data: StringData): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: StringData): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@ObservedV2
class StringData {
  @Trace message: string;

  constructor(message: string) {
    this.message = message;
  }
}

@Entry
@ComponentV2
struct Index {
  data: MyDataSource = new MyDataSource(); // Data source.

  aboutToAppear() {
    for (let i = 0; i <= 200; i++) {
      this.data.pushData(new StringData('Hello' + i));
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: StringData, index: number) => {
        ListItem() {
          Column() {
            Text(item.message)
            ChildComponent({ data: item.message })
              .onClick(() => {
                item.message += '!'; // message is a variable decorated by @Trace and its change is observable.
              })
          }
        }
      })
    }.cachedCount(5)
  }
}

@ReusableV2
@ComponentV2
struct ChildComponent {
  @Require @Param data: string;

  aboutToAppear(): void {
    hilog.info(DOMAIN, TAG, 'ChildComponent aboutToAppear', this.data);
  }

  aboutToDisappear(): void {
    hilog.info(DOMAIN, TAG, 'ChildComponent aboutToDisappear', this.data);
  }

  aboutToReuse(): void {
    hilog.info(DOMAIN, TAG, 'ChildComponent aboutToReuse', this.data); // Triggered when the component is reused.
  }

  aboutToRecycle(): void {
    hilog.info(DOMAIN, TAG, 'ChildComponent aboutToRecycle', this.data); // Triggered when the component is reclaimed.
  }

  build() {
    Row() {
      Text(this.data).fontSize(50)
    }
  }
}
```

![lazyforeach](./figures/reusablev2-lazyforeach.gif)

<!--no_check-->