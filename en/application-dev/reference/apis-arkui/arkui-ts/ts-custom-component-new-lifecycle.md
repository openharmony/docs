# Lifecycle of a Custom Component (Recommended)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xin11112-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=5b34f41bf116f7d72d70b6a8dcf29a936c5dc473 translatedAt=2026-08-18T03:08:53.590Z pushedAt=2026-08-18T09:34:20.385Z -->

The lifecycle callbacks of a custom component are used to notify developers of the lifecycle of the custom component. These callbacks are private and are invoked by the development framework at specific times during runtime. They cannot be manually called from an app. This lifecycle mechanism covers the initialization, appearance, building, recycling and reuse, activation and deactivation, and destruction phases of a custom component. You can perform operations such as state modification, data event reporting, and listener registration in the callbacks of the corresponding phases. In addition, you can use **CustomComponentLifecycle** to monitor and observe the lifecycle state, which is suitable for scenarios that require fine-grained management of the component lifecycle, such as component reuse and recycling, state event reporting, and activation control.

For details about the development guide, see [Lifecycle of a Custom Component (Recommended)](../../../ui/state-management/arkts-custom-components-new-lifecycle.md).

>**NOTE**
>
> - The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## \@ComponentInit

ComponentInit: MethodDecorator

The function decorated by **\@ComponentInit** is executed when the initialization of a custom component is about to complete, and is triggered before **\@ComponentAppear**. You can register lifecycle listeners and modify state variables at this time. The difference from **\@ComponentAppear** is that **\@ComponentInit** focuses on preparation operations in the initialization phase (such as listener registration), while **\@ComponentAppear** focuses on state changes before the component is about to be displayed. The two can be used together to respectively assume the responsibilities of initialization and pre-display.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

For details, see [Lifecycle Example](#lifecycle-example).

## \@ComponentAppear

ComponentAppear: MethodDecorator

Decorates a function that is called after a new instance of the custom component is created and before the **build()** function is executed. This callback is similar to **aboutToAppear**. The difference is that the **\@ComponentAppear** callback is triggered only when the custom component is in the **[CustomComponentLifecycleState](#customcomponentlifecyclestate).INIT** state. The state variable can be changed in **\@ComponentAppear**. The change will take effect in the subsequent **build()** function execution.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

For details, see [Lifecycle Example](#lifecycle-example).

## \@ComponentBuilt

ComponentBuilt: MethodDecorator

The function decorated by **\@ComponentBuilt** is called after the build() function of a custom component is executed for the first time, that is, it is triggered in the stage from **CustomComponentLifecycleState.APPEARED** to **CustomComponentLifecycleState.BUILT**. You can implement functions that do not affect the actual UI, such as event data reporting, in this phase.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

For details, see [Lifecycle Example](#lifecycle-example).

## \@ComponentDisappear

ComponentDisappear: MethodDecorator

The function decorated by **@ComponentDisappear** is executed before a custom component is destroyed, that is, it is triggered when the component transitions to the **CustomComponentLifecycleState.DISAPPEARED** state. It is not recommended to change state variables in this function. In particular, modifying **\@Link** variables may cause unstable app behavior.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

For details, see [Lifecycle Example](#lifecycle-example).

## \@ComponentReuse

ComponentReuse: MethodDecorator

The function decorated by **\@ComponentReuse** is called when a reusable custom component is re-added to the node tree from the cache, that is, it is triggered in the stage from **CustomComponentLifecycleState.RECYCLED** to **CustomComponentLifecycleState.BUILT**, to receive the construction parameters of the component. Finally, reuse recursively traverses all child components, and for each child component that completes reuse, the function decorated by **\@ComponentReuse** in the child component is called.

> **NOTE**
>
> - In a state management V1 component, the function decorated by **\@ComponentReuse** can have one input parameter or no parameter. The input parameter **params** is recommended to be of the **Record\<string, Object \| undefined \| null\>** type.
>
> - In a state management V2 component, the function decorated by **\@ComponentReuse** has no input parameter.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type     | Mandatory   | Description                                       |
| ---- | ------ | ---- | ------- |
| params   | Record\<string, Object \| undefined \| null\> | No    | Construction parameters received when the component is reused. Only the reuse callback of a V1 component supports this parameter. If this parameter is not passed, the reuse callback function has no input parameter. |

**Example**

For details, see [Lifecycle Example](#lifecycle-example).

## \@ComponentRecycle

ComponentRecycle: MethodDecorator

After a component is recycled, the recycling operations such as resource release defined in the app are performed first. After the recycling is complete, the function decorated by **\@ComponentRecycle** is called, that is, it is triggered in the stage from **CustomComponentLifecycleState.BUILT** to **CustomComponentLifecycleState.RECYCLED**. Then the component is frozen to avoid UI updates while the component is in the reuse pool. Finally, recycling recursively traverses all child components, and for each child component that completes recycling, the function decorated by **\@ComponentRecycle** in the child component is called.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

For details, see [Lifecycle Example](#lifecycle-example).

## \@ComponentActive

ComponentActive: MethodDecorator

After a custom component transitions from the inactive state to the active state, the function decorated by **@ComponentActive** is called. In the component reuse and recycling scenario, when a cached component is reused (that is, re-added to the node tree from the reuse pool), the component transitions from the inactive state to the active state, triggering this callback.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

See [Active and Inactive Lifecycle Example](#active-and-inactive-lifecycle-example).

## \@ComponentInactive

ComponentInactive: MethodDecorator

After a custom component transitions from the active state to the inactive state, the function decorated by **@ComponentInactive** is called. In the component reuse and recycling scenario, when a component is recycled to the reuse pool, the component transitions from the active state to the inactive state, triggering this callback.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

See [Active and Inactive Lifecycle Example](#active-and-inactive-lifecycle-example).

## CustomComponentLifecycle

**CustomComponentLifecycle** is used to monitor changes in the lifecycle of a custom component. You can obtain a **CustomComponentLifecycle** instance through [UIUtils.getLifecycle](../js-apis-stateManagement.md#getlifecycle23).

### getCurrentState

getCurrentState(): CustomComponentLifecycleState

The **getCurrentState** function is used to obtain the current lifecycle state of a custom component. Before calling this method, you need to obtain a CustomComponentLifecycle instance through [UIUtils.getLifecycle](../js-apis-stateManagement.md#getlifecycle23).

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Return value**

| Type                           | Description      |
| -------- | -------- |
| [CustomComponentLifecycleState](#customcomponentlifecyclestate) | Current lifecycle status of a custom component.|

**Example**

```ts
import { UIUtils, ComponentBuilt } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
@Entry
@Component
struct Index {
  @ComponentBuilt
  myBuilt() {
    // CustomComponentLifecycle.getCurrentState is used to obtain the current lifecycle state of a custom component.
    hilog.info(0x0000, 'testTag', 'Index Lifecycle is %{public}d', UIUtils.getLifecycle(this).getCurrentState());
  }
  build() {
    Column() {
      Text(`HelloWorld`)
    }
    .height('100%')
    .width('100%')
  }
}
```

### addObserver

addObserver(observer: CustomComponentLifecycleObserver): void

Registers a custom component lifecycle listener. Before calling this method, you need to obtain a CustomComponentLifecycle instance through [UIUtils.getLifecycle](../js-apis-stateManagement.md#getlifecycle23). When the lifecycle of the custom component changes, the corresponding lifecycle callback function in the listener is triggered.

After calling addObserver to register a listener, you must call [removeObserver](#removeobserver) to remove the listener when the component is destroyed or when the listener is no longer needed. The two must be used in pairs. If removeObserver is not called to remove the listener, the listener may keep triggering callbacks and cause memory leaks.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Parameter | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ------- |
| observer   | [CustomComponentLifecycleObserver](#customcomponentlifecycleobserver) | Yes  | Listener for the custom component lifecycle. |

### removeObserver

removeObserver(observer: CustomComponentLifecycleObserver): void

Removes a custom component lifecycle listener. Before calling this method, you need to obtain a **CustomComponentLifecycle** instance through [UIUtils.getLifecycle](../js-apis-stateManagement.md#getlifecycle23). After unregistration, even if the lifecycle state of the custom component changes, the corresponding lifecycle callback function in the listener will not be triggered.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Parameter | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ------- |
| observer   | [CustomComponentLifecycleObserver](#customcomponentlifecycleobserver) | Yes  | Listener for the custom component lifecycle. |

## CustomComponentLifecycleObserver

After developers register a custom component lifecycle callback, when the lifecycle of the custom component changes, the corresponding lifecycle callback in the listener is triggered. The difference from the lifecycle decorators is that the lifecycle decorators respond to lifecycle events by the component itself, while **CustomComponentLifecycleObserver** observes component lifecycle events from the outside. If only the component itself needs to respond to lifecycle changes, use the lifecycle decorators. If you need to centrally monitor the lifecycles of multiple components, use **CustomComponentLifecycleObserver**.

### aboutToAppear

aboutToAppear?(): void

Called after a new instance of a custom component is created and before its **build()** function is executed. Developers can modify state variables in this phase, and the changes will take effect in the subsequent execution of the build() function. Its function is similar to [aboutToAppear](./ts-custom-component-lifecycle.md#abouttoappear). It is subject to the custom component state machine and triggers the callback when the monitored custom component transitions to **CustomComponentLifecycleState.APPEARED**.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

### onDidBuild

onDidBuild?(): void

Called after the **build()** function of a custom component is executed. It is subject to the custom component state machine and triggers the callback when the state of the monitored custom component transitions to **CustomComponentLifecycleState.BUILT**. Developers can implement functions that do not affect the actual UI in this phase, such as event data reporting.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

### aboutToDisappear

aboutToDisappear?(): void

Executed before a custom component is destroyed. It is not recommended to modify state variables in the **aboutToDisappear** function. In particular, modifying **\@Link** variables may cause unstable app behavior. Its function is similar to [aboutToDisappear](./ts-custom-component-lifecycle.md#abouttodisappear). The difference is that the **aboutToDisappear** function in **CustomComponentLifecycleObserver** is subject to the state machine and triggers the callback only before the state of the monitored custom component transitions to **CustomComponentLifecycleState.DISAPPEARED**.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

### aboutToReuse

aboutToReuse?(params?: Record\<string, Object \| undefined \| null\>): void

Called when a reusable custom component is re-added to the node tree from the cache. It is subject to the custom component state machine, that is, it triggers the callback in the stage from **CustomComponentLifecycleState.RECYCLED** to **CustomComponentLifecycleState.BUILT**. Finally, reuse recursively traverses all child components, and for each child component that completes reuse, the **aboutToReuse** function registered in the child component is called. In a state management V1 component, this function can have one input parameter or no parameter. When **params** exists, it indicates the reuse callback of a V1 component. In a state management V2 component, this function has no input parameter.

> **NOTE**
>
> - In a state management V1 component, the **aboutToReuse** function can have one input parameter or no parameter. The input parameter **params** is recommended to be of the Record\<string, Object \| undefined \| null\> type.
>
> - In a state management V2 component, the **aboutToReuse** function has no input parameter.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Parameter | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ------- |
| params   | Record\<string, Object \| undefined \| null\> | No    | Construction parameter received during component reuse. Only the reuse callback of V1 components supports this parameter. If this parameter is not passed, the reuse callback function has no input parameter. |

### aboutToRecycle

aboutToRecycle?(): void

After a component is recycled, the recycling operations such as resource release defined in the app are performed first. After the recycling is complete, the **aboutToRecycle** function is called. It is subject to the custom component state machine, that is, it triggers the callback in the stage from **CustomComponentLifecycleState.BUILT** to **CustomComponentLifecycleState.RECYCLED**. Then the component is frozen to avoid UI updates while the component is in the reuse pool. Finally, recycling recursively traverses all child components, and for each child component that completes recycling, the **aboutToRecycle** function registered in the child component is called.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Example**

```ts
import { ComponentInit, ComponentDisappear, UIUtils, CustomComponentLifecycleObserver, CustomComponentLifecycle } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export class Message {
  value: string | undefined;
  constructor(value: string) {
    this.value = value;
  }
}

@Entry
@Component
struct Index {
  @State isChildVisible: boolean = true;

  build() {
    Column() {
      Button('Hello')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.isChildVisible = !this.isChildVisible;
        })
      if (this.isChildVisible) {
        // If only one reusable component is used, reuseId is optional.
        Child({ message: new Message('Child') })
          .reuseId('Child')
      }
    }
    .height('100%')
    .width('100%')
  }
}

@Reusable
@Component
struct Child {
  @State message: Message = new Message('AboutToReuse');
  @ComponentInit
  myInit(): void {
    registerObserver(UIUtils.getLifecycle(this));
  }
  @ComponentDisappear
  myDisappear(): void {
    unRegisterObserver(UIUtils.getLifecycle(this));
  }
  build() {
    Column() {
      Text(this.message.value)
        .fontSize(30)
    }
  }
}

export class MyObserver implements CustomComponentLifecycleObserver {
  // Override the lifecycle events in CustomComponentLifecycleObserver.
  aboutToAppear() {
    hilog.info(0x0000, 'testTag', 'MyObserver aboutToAppear');
  }
  onDidBuild() {
    hilog.info(0x0000, 'testTag', 'MyObserver onDidBuild');
  }
  aboutToReuse(params?: Record<string, Object | undefined | null>) {
    // If params exists, it is V1 reuse.
    hilog.info(0x0000, 'testTag', 'MyObserver aboutToReuse');
  }
  aboutToRecycle() {
    hilog.info(0x0000, 'testTag', 'MyObserver aboutToRecycle');
  }
  aboutToDisappear() {
    hilog.info(0x0000, 'testTag', 'MyObserver aboutToDisappear');
  }
}

// Create the Observer object.
const observer = new MyObserver();

export function registerObserver(lifeCycle: CustomComponentLifecycle) {
  // Register the listener with lifeCycle.
  lifeCycle.addObserver(observer);
}

export function unRegisterObserver(lifeCycle: CustomComponentLifecycle) {
  // Unregister the listener from lifeCycle.
  lifeCycle.removeObserver(observer);
}
```

## CustomComponentLifecycleState

Defines the current lifecycle status of a custom component.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name| Value| Description|
| -- | -- | -- |
| INIT | 0 | Initial.|
| APPEARED | 1 | Appeared.|
| BUILT | 2 | Built.|
| RECYCLED | 3 | Recycled. |
| DISAPPEARED | 4 | Disappeared. |

**Example**

```ts
import { CustomComponentLifecycleState, ComponentBuilt } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  @ComponentBuilt
  myBuilt() {
    // CustomComponentLifecycleState.BUILT indicates that the custom component is in the expanded state.
    hilog.info(0x0000, 'testTag', 'Index Lifecycle is %{public}d', CustomComponentLifecycleState.BUILT);
  }
  build() {
    Column() {
      Text(`HelloWorld`)
    }
    .height('100%')
    .width('100%')
  }
}
```

## Lifecycle Example

This example demonstrates some use cases of the lifecycle callback functions.

1. When the app is started and the custom component **Child** is created, **\@ComponentInit** and **\@ComponentAppear** are triggered. After **build()** is executed for **Child**, **\@ComponentBuilt** is triggered.

2. Set **this.switchChild** to **false** to recycle the **Child** child component and trigger **\@ComponentRecycle**.

3. Set **this.switchChild** to **true** to reuse the **Child** child component and trigger **\@ComponentReuse**.

4. Exit the app to trigger **\@ComponentDisappear** before the custom component **Child** is destroyed.

```ts
import { ComponentInit, ComponentAppear, ComponentBuilt, ComponentDisappear, ComponentReuse, ComponentRecycle } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export class Message {
  value: string | undefined;
  constructor(value: string) {
    this.value = value;
  }
}
@Entry
@Component
struct Index {
  @State switchChild: boolean = true;
  build() {
    Column() {
      Button('Hello')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.switchChild = !this.switchChild;
        })
      if (this.switchChild) {
        // If only one reusable component is used, reuseId is optional.
        Child({ message: new Message('Child') })
          .reuseId('Child')
      }
    }
    .height('100%')
    .width('100%')
  }
}

@Reusable
@Component
struct Child {
  @State message: Message = new Message('Child');
  @State label: string = 'HelloWorld';
  @ComponentInit
  myInit() {
    // After the custom component is created, trigger the myInit method.
    hilog.info(0x0000, 'testTag', 'Child myInit');
  }
  @ComponentAppear
  myAppear() {
    this.label = 'myAppear';
    hilog.info(0x0000, 'testTag', `Child ${this.label}`);
  }
  @ComponentBuilt
  myBuilt() {
    this.label = 'myBuilt';
    hilog.info(0x0000, 'testTag', `Child ${this.label}`);
  }
  @ComponentRecycle
  myRecycle() {
    this.label = 'myRecycle';
    hilog.info(0x0000, 'testTag', `Child ${this.label}`);
  }
  @ComponentDisappear
  myDisappear() {
    hilog.info(0x0000, 'testTag', 'Child myDisappear');
  }
  @ComponentReuse
  myReuse() {
    this.label = 'myReuse';
    hilog.info(0x0000, 'testTag', `Child ${this.label}`);
  }
  build() {
    Column() {
      Text(this.message.value)
        .fontSize(30)
    }
    .height(100)
  }
}
```

## Active and Inactive Lifecycle Example

This example demonstrates how the active and inactive lifecycle callback functions of a custom component are triggered in the component reuse and recycling scenario. It is recommended to perform the following steps:

1. Click **change** to create the **Child** component for the first time.

2. Click **change** to trigger the recycling event of the **Child** component and the function decorated by **\@ComponentInactive**.

3. Click **change** to trigger the reuse event of the **Child** component and the function decorated by **\@ComponentActive**.

```ts
import { ComponentActive, ComponentInactive } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State changeChild: boolean = false;

  build() {
    Column() {
      Button('change').onClick(() => {
        // Switch the display state of the Child component to trigger component recycling or reuse.
        this.changeChild = !this.changeChild;
      })
      if (this.changeChild) {
        Child()
      }
    }
    .width('100%')
  }
}

@Reusable
@Component
struct Child {
  @ComponentActive
  myActive() {
    // Triggered when the component changes from the inactive state to the active state.
    console.info(`Child myActive`);
  }

  @ComponentInactive
  myInactive() {
    // Triggered when the component changes from the active state to the inactive state.
    console.info(`Child myInactive`);
  }

  build() {
    Text('Child')
  }
}
```