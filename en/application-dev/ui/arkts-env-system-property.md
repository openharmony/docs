# \@Env: Environment Variable

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @zhangwenhan-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=53ef9ec841b379d6df4370b0260f5d435c26f619 translatedAt=2026-07-30T11:37:01.713Z pushedAt=2026-07-31T01:47:38.305Z -->

In multi-device development scenarios, you can use the [@Env](../reference/apis-arkui/arkui-ts/ts-env-system-property.md) decorator to listen for changes in system environment variables and determine the corresponding scenario based on these variables, thereby reducing adaptation logic and repetitive development across different devices.

>**NOTE**
>
> Since API version 22, \@Env can be used in [\@Component](./state-management/arkts-create-custom-components.md#component) and [\@ComponentV2](./state-management/arkts-create-custom-components.md#componentv2).
>
> This decorator can be used in atomic services since API version 22.

## Overview

\@Env is a decorator for environment variables in the reactive system. It provides the following functionalities:

Reads the corresponding environment variable information based on the input parameter. For details, see [Supported Parameters](#supported-parameters). The following environment variables are currently supported:

  - [SystemProperties.BREAK_POINT](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): obtains the breakpoint value corresponding to different width and height thresholds of a window.

  - [SystemProperties.WINDOW_SIZE<sup>23+</sup>](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): obtains the size of a window, in vp.

  - [SystemProperties.WINDOW_SIZE_PX<sup>23+</sup>](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): obtains the size of a window, in px.

  - [SystemProperties.WINDOW_AVOID_AREA<sup>23+</sup>](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): obtains the avoid area of a window, in vp.

  - [SystemProperties.WINDOW_AVOID_AREA_PX<sup>23+</sup>](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): obtains the avoid area of a window, in px.

  - [SystemProperties.WINDOW_DISPLAY_ID](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): used to obtain the ID of the screen where the window is located. This parameter is supported since API version 26.0.0.

  - [SystemProperties.WINDOW_SYSTEM_DENSITY](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties): used to obtain the system display size scaling factor of the screen where the window is located. This parameter is supported since API version 26.0.0.

  - [WritableEnvKey.FONT_SCALE](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#properties-1): used to provide a local font scale for descendant components. This parameter is supported since API version 26.0.0.

  - [WritableEnvKey.DIRECTION](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#properties-1): used to obtain the layout direction of the screen where the window is located. This parameter is supported since API version 26.0.0.

  - When a system environment variable changes, the @Env-decorated variable is notified to update, and the component associated with @Env is triggered to refresh, thereby implementing synchronous update of the UI content. When the @Env parameters are WritableEnvKey.FONT_SCALE and WritableEnvKey.DIRECTION, the parent component can pass values to @Env in child components via the [.env](../reference/apis-arkui/arkui-ts/ts-container-with-env.md#env) method in [WithEnv](../reference/apis-arkui/arkui-ts/ts-container-with-env.md).

  - Variables decorated by @Env cannot be initialized by developers.

    - When the type decorated by @Env is a complex type, @Env returns an instance of an observable environment variable class (decorated by [@ObservedV2](./state-management/arkts-new-observedV2-and-trace.md), with its properties decorated by [@Trace](./state-management/arkts-new-observedV2-and-trace.md)). To listen for changes in environment variables, you can use [addMonitor](./state-management/arkts-new-addMonitor-clearMonitor.md). For a specific example, see [Using \@Env in \@ComponentV2](#using-env-in-componentv2).

    - When the type decorated by @Env is a simple type, you can use [@Watch](state-management/arkts-watch.md) in @Component and @Monitor in @ComponentV2 to listen for changes. For a specific example, see [@Watch and @Monitor Listening to @Env-Decorated Variables](#watch-and-monitor-listening-to-env-decorated-variables).

## Supported Parameters

For the parameters supported by @Env, see [SystemProperties Enum Type Description](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties) \| [SystemEnvKey\<T\> Type Description](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemenvkeyt).

## @Env and Environment Capability Comparison

@Env and [Environment](./state-management/arkts-environment.md) are related to system environment variables, but their capabilities are different. For details, see the following table.

| Capability| \@Env |Environment|
| ------------------ | ------------------ | ------------------ |
|Supported since|API version 22|API version 7|
|Supported parameters|[Enum values of SystemProperties](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties).<br/>Since API version 26.0.0, [SystemProperties](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties)\|[SystemEnvKey\<T\> type description](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemenvkeyt) is supported. | Supports parameters such as `languageCode`. For details, see [Environment Built-in Parameters](./state-management/arkts-environment.md#environment-built-in-parameters).|
|Usage|\@Env is a decorator that can be declared in \@Component or \@ComponentV2 to obtain the environment variable information of the corresponding parameter.<br/>After API version 26.0.0, you can set the system environment variable of the SystemEnvKey\<T\> type parameter via the env API of WithEnv.|Obtains the environment variable of the current app through APIs such as [envProp](../reference/apis-arkui/arkui-ts/ts-state-management.md#envprop10) and stores it in [AppStorage](./state-management/arkts-appstorage.md). You can access the value of the system environment variable through the AppStorage API. For a specific example, see [Accessing Environment Parameters from UI](./state-management/arkts-environment.md#accessing-environment-parameters-from-the-ui).|
|Responsive capability supported|Yes. When the system environment variable changes, the environment variable decorated by \@Env is notified of the change and the component associated with \@Env is notified to refresh.|No. When the system environment variable changes, **Environment** is not notified of the change.|

## Constraints

- \@Env can be used only in @Component and @ComponentV2. Otherwise, a compile-time error is reported. If you bypass the compilation check, a runtime error is thrown.

  ```ts
  import { uiObserver } from '@kit.ArkUI';

  class Info {
    @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage. Compile-time error occurs.
  }
  
  @Entry
  @Component
  struct Index {
    @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
  
    build() {
    }
  }
  ```

- The variable decorated by \@Env is read-only and cannot be initialized or assigned a value. Otherwise, a compile-time error is reported. If you bypass the compilation check, a runtime error is thrown.

  ```ts
  import { uiObserver } from '@kit.ArkUI';
  
  @Entry
  @Component
  struct Index {
    @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo =
      new uiObserver.WindowSizeLayoutBreakpointInfo(); // Incorrect usage. Compile-time error occurs.
  
    build() {
      Column() {
        Text(`breakpoint height ${this.breakpoint.heightBreakpoint}`).fontSize(20)
        Text(`breakpoint width ${this.breakpoint.widthBreakpoint}`).fontSize(20)
        Button('change breakpoint').onClick(() => {
          this.breakpoint = new uiObserver.WindowSizeLayoutBreakpointInfo(); // Incorrect usage. Compile-time error occurs.
        })
      }
    }
  }
  ```

- \@Env supports the enum values of [SystemProperties](../reference/apis-arkui/arkui-ts/ts-env-system-property.md#systemproperties). If an unsupported parameter is used, a compile-time error is reported.

    ```ts
    import { uiObserver } from '@kit.ArkUI';

    @Entry
    @Component
    struct Index {
      @Env(SystemProperties.BREAK_POINT) breakpoint1: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
      @Env('unsupported_key') breakpoint2: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage. @Env is an invalid input parameter, and a compile-time error is reported.
    
      build() {
        Text(`breakpoint2 width: ${this.breakpoint2.widthBreakpoint} height: ${this.breakpoint2.heightBreakpoint}`)
      }
    }
    ```

- When \@Env uses different key values, the decorated variable types must correspond to each other. Otherwise, a compile-time error is reported.

  - When \@Env uses **SystemProperties.BREAK_POINT**, the decorated variable type must be **uiObserver.WindowSizeLayoutBreakpointInfo**.

  - When \@Env uses **SystemProperties.WINDOW_SIZE**, the decorated variable type must be **window.SizeInVP**.

  - When \@Env uses **SystemProperties.WINDOW_SIZE_PX**, the decorated variable type must be **window.Size**.

  - When \@Env uses **SystemProperties.WINDOW_AVOID_AREA**, the decorated variable type must be **window.UIEnvWindowAvoidAreaInfoVP**.

  - When \@Env uses **SystemProperties.WINDOW_AVOID_AREA_PX**, the decorated variable type must be **window.UIEnvWindowAvoidAreaInfoPX**.

  - When \@Env uses `SystemProperties.WINDOW_DISPLAY_ID`, the decorated variable type must be `number`.

  - When \@Env uses `SystemProperties.WINDOW_SYSTEM_DENSITY`, the decorated variable type must be `number`.

  - When \@Env uses `WritableEnvKey.FONT_SCALE`, the decorated variable type must be `number`.

  - When \@Env uses `WritableEnvKey.DIRECTION`, the decorated variable type must be `Direction`.

  ```ts
  import { uiObserver } from '@kit.ArkUI';

  @Entry
  @Component
  struct Index {
    @Env(SystemProperties.BREAK_POINT) breakpoint1: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
    @Env(SystemProperties.BREAK_POINT) breakpoint2: string; // Incorrect usage. When @Env uses SystemProperties.BREAK_POINT, only the WindowSizeLayoutBreakpointInfo type can be decorated.

    build() {
    }
  }
  ```

- \@Env can only be used alone and cannot be combined with other V1 or V2 state variable decorators or @Require. Otherwise, a compile-time error is reported. Starting from API version 26.0.0, in \@Component, you can use [\@Watch](state-management/arkts-watch.md) to listen for changes in \@Env-decorated variables. For a specific example, see [\@Watch and \@Monitor Listening to \@Env-Decorated Variables](#watch-and-monitor-listening-to-env-decorated-variables).

  ```ts
  @Env(SystemProperties.BREAK_POINT) breakpoint1: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
  @State @Env(SystemProperties.BREAK_POINT) breakpoint2: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage. A compile-time error is reported.
  @Require @Env(SystemProperties.BREAK_POINT) breakpoint3: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage. A compile-time error is reported.
  @Local @Env(SystemProperties.BREAK_POINT) breakpoint4: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage. A compile-time error is reported.
  ```

- The rules for passing the \@Env decorated variables between \@Component and \@ComponentV2 are as follows:

  - The \@Env decorated variables can only be used to initialize the @Param decorated variable in \@ComponentV2. Otherwise, a compile-time error is reported.

  - The \@Env decorated variables can only be used to initialize common variables in \@Component. Otherwise, a compile-time error is reported. Note that switching the window through [BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md) will cause \@Env to update the environment variable instance based on the new window. In the window switching scenario, you are not advised to use the \@Env variable to initialize the common variables of the child component. Otherwise, \@Env cannot notify the common variables to trigger the associated UI component refresh. For details, see [Switching Windows Through BuilderNode](#switching-windows-through-buildernode).

  ```ts
  import { uiObserver } from '@kit.ArkUI';
  
  @Entry
  @Component
  struct Index {
    @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
  
    build() {
      Column() {
        CompV2({ breakpoint: this.breakpoint }) // Correct usage.
        Comp({ breakpoint: this.breakpoint }) // Correct usage.
  
        CompV2Invalid({ breakpoint: this.breakpoint }) // Incorrect usage. The variable decorated by @Env can only initialize the @Param variables of V2.
        CompInvalid({ breakpoint: this.breakpoint }) // Incorrect usage. The variable decorated by @Env can only initialize common variables of V1.
      }
    }
  }
  
  @ComponentV2
  struct CompV2 {
    @Require @Param breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
  
    build() {
    }
  }
  
  @ComponentV2
  struct CompV2Invalid {
    @Require breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage.
  
    build() {
    }
  }
  
  @Component
  struct Comp {
    @Require breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Correct usage.
  
    build() {
    }
  }
  
  @Component
  struct CompInvalid {
    @ObjectLink breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo; // Incorrect usage.
  
    build() {
    }
  }
  ```

## \@Env Initialization Process

\@Env variables cannot be initialized by developers. Their values are automatically provided by the framework based on the environment variables of the current window. When the \@Env variables are read for the first time, initialization is triggered. The initialization of \@Env variables complies with the following process:

1. Search for an existing instance in the parent component.

   - Recursively search for the parent component.

   - If the \@Env variable with the same key has been initialized by a parent component in the same window, reuse the instance.

   - If no instance is found, continue to search for the parent component until the parent component is empty. Note that the process of searching for the parent component will be interrupted by **BuilderNode**.

2. Search for the \@Env instance of the current window.

   - If the corresponding instance is not found in the parent component, check whether the current window has an \@Env variable instance with the same key.

   - If yes, reuse the \@Env instance in the window.

3. Create an environment variable instance for the first request.

   - If no instance is obtained in the preceding two steps, the environment variable is read for the first time in the current window.

   - The framework creates a new observable environment variable instance, binds it to the current window, and completes initialization.

The following figure shows the flowchart.

![image](./figures/env-flow.png)

Based on the preceding process, the following example uses **SystemProperties.BREAK_POINT** as an example to describe the use of @Env. The following figure shows the initialization of each component.

![image](./figures/env-flow2.png)

1. **Child1** initializes **@Env(SystemProperties.BREAK_POINT)**.

   - Recursively search until the parent component is empty. Search for the parent component **Index** upwards. There is no **SystemProperties.BREAK_POINT** instance corresponding to \@Env.

   - Search for the current window. No **SystemProperties.BREAK_POINT** instance corresponding to \@Env is found.

   - Create an observable environment variable instance corresponding to **SystemProperties.BREAK_POINT** and bind it to the current window.

2. Initialize **@Env(SystemProperties.BREAK_POINT)** for **GrandChild1**.

   - Recursively search for the parent component until it is empty. Search for the parent component **Child1** upwards. The **Child1** has a **SystemProperties.BREAK_POINT** instance corresponding to \@Env.

   - Reuse the **SystemProperties.BREAK_POINT** instance corresponding to \@Env in **Child1**.

3. Initialize **@Env(SystemProperties.BREAK_POINT)** for **GrandChild2**.

   - Recursively search for the parent component until it is empty. Search for the parent component **Child2** and ancestor node **Index** upwards. Neither of them has a **SystemProperties.BREAK_POINT** instance corresponding to \@Env.

   - Search for the current window. There is a **SystemProperties.BREAK_POINT** instance corresponding to \@Env.

   - Reuse the environment variable instance corresponding to **SystemProperties.BREAK_POINT** in the window.

```TypeScript
import { uiObserver } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Text(`Index`)
      Child1()
      Child2()
    }
    .height('100%')
    .width('100%')
  }
}

@Component
struct Child1 {
  // Read system environment variables via @Env.
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`Child1 breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`Child1 breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
      GrandChild1()
    }
  }
}

@Component
struct Child2 {
  build() {
    Column() {
      GrandChild2()
    }
  }
}

@Component
struct GrandChild1 {
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`GrandChild1 breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`GrandChild1 breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
    }
  }
}


@Component
struct GrandChild2 {
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`GrandChild2 breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`GrandChild2 breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
    }
  }
}
```

## When to Use

### Using \@Env in \@ComponentV2

In the following example:

- Declare \@Env in \@ComponentV2 to obtain the layout breakpoint of the window where the current \@ComponentV2 component is created, and use [addMonitor](./state-management/arkts-new-addMonitor-clearMonitor.md) to listen for the changes of the **this.breakpoint** attribute.

- Pass the \@Env decorated variables to the [\@Param](./state-management/arkts-new-param.md) decorated variables in **CompV2** and the common variables in **Comp**.

- Click **Button('Landscape')** and **Button('Portrait')** to switch between landscape and portrait modes. The **Index**, **CompV2**, and **Comp** associated components are refreshed, and the listener for **orientationChange** is triggered.

```ts
import { uiObserver, UIUtils, window } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

@Entry
@ComponentV2
struct Index {
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  private changeOrientation(isLandscape: boolean) {
    const context = this.getUIContext()?.getHostContext() as common.UIAbilityContext;
    window.getLastWindow(context).then((lastWindow) => {
      lastWindow.setPreferredOrientation(isLandscape ? window.Orientation.LANDSCAPE : window.Orientation.PORTRAIT);
    });
  }

  orientationChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`${path} changes from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    })
  }

  aboutToAppear(): void {
    // The object returned by @Env is actually an @ObservedV2 decorated object (whose properties are decorated by @Trace). Therefore, the change of its properties can be listened through addMonitor.
    UIUtils.addMonitor(this.breakpoint, ['widthBreakpoint', 'heightBreakpoint'], this.orientationChange);
  }

  build() {
    Column() {
      Text(`Index breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`Index breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)

      Button('Landscape').onClick(() => {
        this.changeOrientation(true);
      })

      Button('Portrait').onClick(() => {
        this.changeOrientation(false);
      })

      CompV2({ breakpoint: this.breakpoint })
      Comp({ breakpoint: this.breakpoint })
    }
  }
}

@ComponentV2
struct CompV2 {
  @Require @Param breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`CompV2 breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`CompV2 breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
    }
  }
}

@Component
struct Comp {
  @Require breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`Comp breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`Comp breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
    }
  }
}
```

### Using \@Env in \@Component

The usage of \@Env in \@Component is similar to that in \@ComponentV2. The following is an example:

```ts
import { uiObserver, UIUtils, window } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  private changeOrientation(isLandscape: boolean) {
    const context = this.getUIContext()?.getHostContext() as common.UIAbilityContext;
    window.getLastWindow(context).then((lastWindow) => {
      lastWindow.setPreferredOrientation(isLandscape ? window.Orientation.LANDSCAPE : window.Orientation.PORTRAIT);
    });
  }

  orientationChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`${path} changes from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    })
  }

  aboutToAppear(): void {
    // The object returned by @Env is actually an @ObservedV2 decorated object (whose properties are decorated by @Trace). Therefore, the change of its properties can be listened through addMonitor.
    UIUtils.addMonitor(this.breakpoint, ['widthBreakpoint', 'heightBreakpoint'], this.orientationChange);
  }

  build() {
    Column() {
      Text(`Index breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`Index breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)

      Button('Landscape').onClick(() => {
        this.changeOrientation(true);
      })

      Button('Portrait').onClick(() => {
        this.changeOrientation(false);
      })

      CompV2({ breakpoint: this.breakpoint })
      Comp({ breakpoint: this.breakpoint })
    }
  }
}

@ComponentV2
struct CompV2 {
  @Require @Param breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`CompV2 breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`CompV2 breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
    }
  }
}

@Component
struct Comp {
  @Require breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`Comp breakpoint width: ${this.breakpoint.widthBreakpoint}`).fontSize(20)
      Text(`Comp breakpoint height: ${this.breakpoint.heightBreakpoint}`).fontSize(20)
    }
  }
}
```

### Switching Windows Through BuilderNode

\@Env is used to display the environment variable information of the [window](../reference/apis-arkui/arkts-apis-window.md) where \@Component or \@ComponentV2 is located. When you switch the window instance of \@Component or \@ComponentV2 via BuilderNode, \@Env re-acquires the corresponding environment variable information based on the new window and triggers the associated UI component to refresh. The following uses `SystemProperties.BREAK_POINT` as an example.

In the following example:

1. Click **Button('add node to tree')** to create a **BuilderNode** and mount it to **NodeContainer**.

2. Click **Button('remove node from tree')** to remove the **BuilderNode** from **NodeContainer**.

3. Click **Button(`create sub window`)** to create a subwindow and display the **SubWindow** window.

4. Click **Button('add node to tree')** in **SubWindow** to mount the **BuilderNode** to the **NodeContainer** in the **SubWindow**.

   - When **ComponentUnderBuilderNode** is mounted to a new window, \@Env is triggered to obtain new environment variables.

   - After \@Env obtains new environment variables, the associated component is refreshed. **@Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo** in **ComponentUnderBuilderNode** notifies **@Param breakpoint** in **CompV2** of the refresh, but does not notify the common variable **breakpoint** in **Comp** of the refresh. Therefore, in the scenario where \@Env re-obtains environment variables after the window is switched, you are advised not to pass @Env to the common variable to avoid the problem that the common variable cannot be notified of UI refresh.

The following example includes the process of creating a subwindow. For details, see [Subwindow Development Guide](../windowmanager/subwindow-guide.md).

```Typescript
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
    })

    // Pass the window stage to the Index page.
    AppStorage.setOrCreate('windowStage', windowStage);
  }
}
```

```Typescript
// Index.ets
import { BuilderNode, FrameNode, NodeController, uiObserver, window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

let windowStage_: window.WindowStage | undefined = undefined;
let sub_windowClass: window.Window | undefined = undefined;
let globalBuilderNode: BuilderNode<[]> | undefined = undefined;

export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.uiContext = uiContext;
    return this.rootNode;
  }

  addBuilderNode(): void {
    if (!globalBuilderNode && this.uiContext) {
      globalBuilderNode = new BuilderNode(this.uiContext);
      globalBuilderNode.build(wrapBuilder<[]>(buildComponent), undefined);
    }
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.appendChild(globalBuilderNode.getFrameNode());
    }
  }

  removeBuilderNode(): void {
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.removeChild(globalBuilderNode.getFrameNode());
    }
  }

  disposeNode(): void {
    if (this.rootNode && globalBuilderNode) {
      globalBuilderNode.dispose();
      globalBuilderNode = undefined;
    }
  }
}

@Builder
function buildComponent() {
  Column() {
    ComponentUnderBuilderNode()
  }
}

@Entry
@ComponentV2
struct Index {
  private nodeController: MyNodeController = new MyNodeController();

  private createSubWindow() {
    windowStage_ = AppStorage.get('windowStage');
    if (windowStage_ == null) {
      hilog.error(DOMAIN, 'testTag', 'Failed to create the subwindow. Cause: windowStage_ is null');
    } else {
      // Create a subwindow.
      windowStage_.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, 'testTag', 'Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        sub_windowClass = data;
        if (!sub_windowClass) {
          hilog.error(DOMAIN, 'testTag', 'sub_windowClass is null');
          return;
        }
        hilog.info(DOMAIN, 'testTag', 'Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        // Set the position, size, and other properties of the subwindow.
        sub_windowClass.moveWindowTo(200, 1300, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, 'testTag', 'Failed to move the window. Cause:' + JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in moving the window.');
        });
        sub_windowClass.resize(900, 1800, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, 'testTag', 'Failed to change the window size. Cause:' + JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in changing the window size.');
        });
         // Load the target page to the subwindow.
        sub_windowClass.setUIContent('pages/SubWindow', (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
          if (!sub_windowClass) {
            hilog.error(DOMAIN, 'testTag', 'sub_windowClass is null');
            return;
          }
          sub_windowClass.showWindow((err: BusinessError) => {
            let errCode: number = err.code;
            if (errCode) {
              hilog.error(DOMAIN, 'testTag', 'Failed to show the window. Cause: ' + JSON.stringify(err));
              return;
            }
            hilog.info(DOMAIN, 'testTag', 'Succeeded in showing the window.');
          });
        });
      })
    }
  }

  private destroySubWindow() {
    if (!sub_windowClass) {
      console.error('sub_windowClass is null');
      return;
    }
    // Destroy the subwindow when it is no longer needed (depending on the service logic).
    sub_windowClass.destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the window.');
    });
  }

  build() {
    Column({ space: 10 }) {
      Text(`Index`)
      // Step 1: Create a globalBuilderNode and mount its nodes to the placeholder node of NodeContainer.
      Button('add node to tree').width(200).onClick(() => {
        this.nodeController.addBuilderNode();
      })
      // Step 2: Remove the nodes of globalBuilderNode from the placeholder node of NodeContainer.
      Button('remove node from tree').width(200).onClick(() => {
        this.nodeController.removeBuilderNode();
      })
      // Destroy nodes of globalBuilderNode.
      Button('dispose node').width(200).onClick(() => {
        this.nodeController.disposeNode();
      })
      // Step 3: Create a subwindow.
      Button(`create sub window`).width(200).onClick(() => {
        this.createSubWindow();
      })
      // Destroy the subwindow.
      Button(`destroy sub window`).width(200).onClick(() => {
        this.destroySubWindow();
      })
      NodeContainer(this.nodeController).backgroundColor('#FFEEF0')
    }
    .width('100%')
    .height('100%')
  }
}

@Component
struct ComponentUnderBuilderNode {
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`ComponentUnderBuilderNode breakpoint width: ${this.breakpoint.widthBreakpoint}`)
      Text(`ComponentUnderBuilderNode breakpoint height: ${this.breakpoint.heightBreakpoint}`)

      CompV2({ breakpoint: this.breakpoint })
      Comp({ breakpoint: this.breakpoint })
    }
  }
}

@ComponentV2
struct CompV2 {
  @Require @Param breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`CompV2 breakpoint width: ${this.breakpoint.widthBreakpoint}`)
      Text(`CompV2 breakpoint height: ${this.breakpoint.heightBreakpoint}`)
    }
  }
}

@Component
struct Comp {
  @Require breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`Comp breakpoint width: ${this.breakpoint.widthBreakpoint}`)
      Text(`Comp breakpoint height: ${this.breakpoint.heightBreakpoint}`)
    }
  }
}
```

```Typescript
// SubWindow.ets
import { MyNodeController } from './Index';

@Entry
@Component
struct SubWindow {
  private nodeController: MyNodeController = new MyNodeController();

  build() {
    Column({ space: 10 }) {
      Text(`SubWindow`)
      // Step 4: Mount the nodes of globalBuilderNode created in step 1 to the placeholder node under the NodeContainer of the subwindow.
      Button('add node to tree').width(200).onClick(() => {
        this.nodeController.addBuilderNode();
      })
      Button('remove node from tree').width(200).onClick(() => {
        this.nodeController.removeBuilderNode();
      })
      Button('dispose node').width(200).onClick(() => {
        this.nodeController.disposeNode();
      })
      NodeContainer(this.nodeController).backgroundColor('#FFEEF0')
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#0D9FFB')
  }
}
```

The following figure shows the running effect.

![gif](./figures/env_switch_instance1.gif)

You can use the Lambda closure function to pass \@Env in **ComponentUnderBuilderNode** downwards. In this way, \@Env in **ComponentUnderBuilderNode** can collect the internal dependencies of the child component **Comp**, and trigger the refresh of the components in **Comp** when the window instance is switched.

The following is an example:

```TypeScript
import { BuilderNode, FrameNode, NodeController, uiObserver, window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

let windowStage_: window.WindowStage | undefined = undefined;
let sub_windowClass: window.Window | undefined = undefined;
let globalBuilderNode: BuilderNode<[]> | undefined = undefined;

export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.uiContext = uiContext;
    return this.rootNode;
  }

  addBuilderNode(): void {
    if (!globalBuilderNode && this.uiContext) {
      globalBuilderNode = new BuilderNode(this.uiContext);
      globalBuilderNode.build(wrapBuilder<[]>(buildComponent), undefined);
    }
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.appendChild(globalBuilderNode.getFrameNode());
    }
  }

  removeBuilderNode(): void {
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.removeChild(globalBuilderNode.getFrameNode());
    }
  }

  disposeNode(): void {
    if (this.rootNode && globalBuilderNode) {
      globalBuilderNode.dispose();
      globalBuilderNode = undefined;
    }
  }
}

@Builder
function buildComponent() {
  Column() {
    ComponentUnderBuilderNode()
  }
}

@Entry
@ComponentV2
struct Index {
  private nodeController: MyNodeController = new MyNodeController();

  private createSubWindow() {
    windowStage_ = AppStorage.get('windowStage');
    if (windowStage_ == null) {
      hilog.error(DOMAIN, 'testTag', 'Failed to create the subwindow. Cause: windowStage_ is null');
    } else {
      // Create a subwindow.
      windowStage_.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, 'testTag', 'Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        sub_windowClass = data;
        if (!sub_windowClass) {
          hilog.error(DOMAIN, 'testTag', 'sub_windowClass is null');
          return;
        }
        hilog.info(DOMAIN, 'testTag', 'Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        // Set the position, size, and other properties of the subwindow.
        sub_windowClass.moveWindowTo(200, 1300, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, 'testTag', 'Failed to move the window. Cause:' + JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in moving the window.');
        });
        sub_windowClass.resize(900, 1800, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, 'testTag', 'Failed to change the window size. Cause:' + JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in changing the window size.');
        });
         // Load the target page to the subwindow.
        sub_windowClass.setUIContent('pages/SubWindow', (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
          if (!sub_windowClass) {
            hilog.error(DOMAIN, 'testTag', 'sub_windowClass is null');
            return;
          }
          sub_windowClass.showWindow((err: BusinessError) => {
            let errCode: number = err.code;
            if (errCode) {
              hilog.error(DOMAIN, 'testTag', 'Failed to show the window. Cause: ' + JSON.stringify(err));
              return;
            }
            hilog.info(DOMAIN, 'testTag', 'Succeeded in showing the window.');
          });
        });
      })
    }
  }

  private destroySubWindow() {
    if (!sub_windowClass) {
      console.error('sub_windowClass is null');
      return;
    }
    // Destroy the subwindow when it is no longer needed (depending on the service logic).
    sub_windowClass.destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the window.');
    });
  }

  build() {
    Column({ space: 10 }) {
      Text(`Index`)
      // Step 1: Create a globalBuilderNode and mount its nodes to the placeholder node of NodeContainer.
      Button('add node to tree').width(200).onClick(() => {
        this.nodeController.addBuilderNode();
      })
      // Step 2: Remove the nodes of globalBuilderNode from the placeholder node of NodeContainer.
      Button('remove node from tree').width(200).onClick(() => {
        this.nodeController.removeBuilderNode();
      })
      // Destroy nodes of globalBuilderNode.
      Button('dispose node').width(200).onClick(() => {
        this.nodeController.disposeNode();
      })
      // Step 3: Create a subwindow.
      Button(`create sub window`).width(200).onClick(() => {
        this.createSubWindow();
      })
      // Destroy the subwindow.
      Button(`destroy sub window`).width(200).onClick(() => {
        this.destroySubWindow();
      })
      NodeContainer(this.nodeController).backgroundColor('#FFEEF0')
    }
    .width('100%')
    .height('100%')
  }
}

@Component
struct ComponentUnderBuilderNode {
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`ComponentUnderBuilderNode breakpoint width: ${this.breakpoint.widthBreakpoint}`)
      Text(`ComponentUnderBuilderNode breakpoint height: ${this.breakpoint.heightBreakpoint}`)

      CompV2({ breakpoint: this.breakpoint })
      // Use the Lambda closure function to associate @Env with the components in Comp.
      Comp({ getEnv: () => this.breakpoint })
    }
  }
}

@ComponentV2
struct CompV2 {
  @Require @Param breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`CompV2 breakpoint width: ${this.breakpoint.widthBreakpoint}`)
      Text(`CompV2 breakpoint height: ${this.breakpoint.heightBreakpoint}`)
    }
  }
}

@Component
struct Comp {
  // Use the Lambda closure function to obtain the @Env instance of the parent component.
  @Require getEnv: () => uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
      Text(`Comp breakpoint width: ${this.getEnv().widthBreakpoint}`)
      Text(`Comp breakpoint height: ${this.getEnv().heightBreakpoint}`)
    }
  }
}
```

The following figure shows the running effect.

![gif](./figures/env_switch_instance2.gif)

### \@Watch and \@Monitor Listening to \@Env-Decorated Variables

Starting from API version 26.0.0, in \@Component, you can use [\@Watch](state-management/arkts-watch.md) to listen for changes in \@Env-decorated variables. Note that the \@Watch callback is triggered only when the \@Env-decorated variable is assigned as a whole; changes to its internal properties do not trigger the callback.

```ts
import { WithEnv } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  @State fontScaleNum: number = 1;

  build() {
    Column() {
      Button('update').onClick(() => {
        this.fontScaleNum++;
      })

      WithEnv() {
        ChildV1()
      }
      .env(WritableEnvKey.FONT_SCALE, this.fontScaleNum)
    }
    .height('100%')
    .width('100%')
  }
}

@Component
struct ChildV1 {
  @Env(WritableEnvKey.FONT_SCALE) @Watch('onEnvUpdate') fontScaleVal: number;

  onEnvUpdate(){
    hilog.info(0x0000, 'testTag',`Env value has changed Watched`);
  }

  build() {
    Column() {
      Text('FontScale val is:'  + this.fontScaleVal)
    }
    .height('100%')
    .width('100%')
  }
}
```

The following figure shows the runtime behavior.

![png](./figures/env-f.png)

In @ComponentV2, you can use @Monitor to listen for changes in @Env-decorated variables. Note that the @Monitor callback is triggered only when the @Env-decorated variable is assigned as a whole; changes to its internal properties do not trigger the callback.

```ts
import { WithEnv } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';


@Entry
@ComponentV2
struct MonitorTest {
  @Local message: number = 20;

  build() {
    Row() {
      Column() {
        Button('change message').onClick(() => {
          this.message++;
        })
        WithEnv() {
          Child()
        }.env(WritableEnvKey.FONT_SCALE, this.message)
      }
      .width('100%')
    }
    .height('100%')
  }
}

@ComponentV2
struct Child {
  @Env(WritableEnvKey.FONT_SCALE) message: number;

  @Monitor('message')
  onStrChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      hilog.info(0x0000, 'testTag',
        `${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }

  build() {
    Column() {
      Text('message' + `${this.message}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

The following figure shows the runtime behavior.

![image](./figures/env-m.png)

<!--no_check-->