# Migration for In-Application State Variables

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=5cbda8a742fe4c75db3800c28ccfc8ffcd9cebc0 translatedAt=2026-06-30T03:37:57.348Z pushedAt=2026-06-30T04:36:46.447Z -->

This guide provides migration instructions for in-application state variables.

| V1 Decorator Name/Scenario| Migration Solution|
| -------- | -------- |
| [LocalStorage](./arkts-localstorage.md) | [@ObservedV2](./arkts-new-observedV2-and-trace.md) [@Trace](./arkts-new-observedV2-and-trace.md) |
| [AppStorage](./arkts-appstorage.md) | [AppStorageV2](./arkts-new-appstoragev2.md) |
| [Environment](./arkts-environment.md) | Obtain system environment variables using the **config** property of [UIAbilityContext](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext-1).|
| [PersistentStorage](./arkts-persiststorage.md) | [PersistenceV2](./arkts-new-persistencev2.md) |
| Legacy migration scenarios| \@ObservedV2, \@Trace, [\@Monitor](./arkts-new-monitor.md)|

## LocalStorage->\@ObservedV2/\@Trace

**Migration Rules**

LocalStorage is used to share state variables across pages. However, these variables are tightly coupled with the view layer in state management V1, requiring framework-level support for sharing.

In state management V2, observation capabilities are embedded directly into the data itself, decoupling state from the view layer. As a result, LocalStorage-style functionality is no longer needed. Instead, you can create state instances using the \@ObservedV2 and \@Trace decorators, and then import or export these instances to enable cross-page state sharing.

### Basic Scenarios

V1:

Use the windowStage.[loadContent](../../reference/apis-arkui/arkts-apis-window-Window.md#loadcontent9) and this.getUIContext().[getSharedLocalStorage](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getsharedlocalstorage12) APIs to share state variables between pages.

<!-- @[Internal_@ObservedV2_@Trace_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV1/EntryAbility.ets) -->

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  public para: Record<string, number> = { 'count': 47 };
  public storage: LocalStorage = new LocalStorage(this.para);

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Page1', this.storage);
  }
}
```

In this example, \@LocalStorageLink is used to synchronize local changes to LocalStorage.

<!-- @[Internal_@ObservedV2_@Trace_V1_pag1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV1/pages/Page1.ets) -->

``` TypeScript
// Page1.ets
// The Previewer does not support accessing LocalStorage instances shared across pages.
@Entry({ useSharedStorage: true })
@Component
struct Page1 {
  @LocalStorageLink('count') count: number = 0;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

<!-- @[Internal_@ObservedV2_@Trace_V1_pag2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV1/pages/Page2.ets) -->

``` TypeScript
// Page2.ets
@Builder
export function Page2Builder() {
  Page2()
}

// The Page2 component obtains the LocalStorage instance of the parent component Page1.
@Component
struct Page2 {
  @LocalStorageLink('count') count: number = 0;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change')
          .fontSize(50)
          .onClick(() => {
            const storage = this.getUIContext().getSharedLocalStorage();
            if (storage) {
              storage.set('count', 20);
            }
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

When using **Navigation**, create a **src/main/resources/base/profile/route_map.json** with **pageSourceFile** set to the actual path to **Page2**. Then, add **"routerMap": "$profile: route_map"** to the **module.json5** file.

```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description": "LocalStorage example"
      }
    }
  ]
}
```

V2:

- Declare the \@ObservedV2 decorated **MyStorage** class and import it to the page to use.

- Declare the \@Trace decorated properties as observable data shared between pages.

<!-- @[Internal_@ObservedV2_@Trace_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV2/storage.ets) --> 

``` TypeScript
// Declare the MyStorage class decorated with @ObservedV2.
@ObservedV2
export class MyStorage {
  public static singleton_: MyStorage;

  static instance() {
    if (!MyStorage.singleton_) {
      MyStorage.singleton_ = new MyStorage();
    }
    return MyStorage.singleton_;
  }
  @Trace public count: number = 47;
}
```

<!-- @[Internal_@ObservedV2_@Trace_V2_pag1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV2/Page1.ets) -->

``` TypeScript
// Page1.ets
import { MyStorage } from './storage';

@Entry
@ComponentV2
struct Page1 {
  storage: MyStorage = MyStorage.instance();
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.storage.count}`)
          .fontSize(50)
          .onClick(() => {
            this.storage.count++;
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

<!-- @[Internal_@ObservedV2_@Trace_V2_pag2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV2/Page2.ets) -->

``` TypeScript
// Page2.ets
import { MyStorage } from './storage';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  storage: MyStorage = MyStorage.instance();
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Text(`${this.storage.count}`)
          .fontSize(50)
          .onClick(() => {
            this.storage.count++;
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

When using **Navigation**, create a **src/main/resources/base/profile/route_map.json** with **pageSourceFile** set to the actual path to **Page2**. Then, add **"routerMap": "$profile: route_map"** to the **module.json5** file.

```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "LocalStorage example"
      }
    }
  ]
}
```

The following example demonstrates \@LocalStorageProp behavior, where local modifications do not synchronize back to LocalStorage:

- In **Page1**, changes to the **count** variable decorated with \@LocalStorageProp remain local to the component and do not synchronize back to LocalStorage.

- Clicking **push to Page2** navigates to **Page2**, where the **Text** component displays the original value **47** from LocalStorage. This is because **count** modified on **Page1** is not synced to LocalStorage.

- Clicking **change Storage Count** updates the value of **count** via **setOrCreate** of LocalStorage and triggers notifications to all bound variables.

<!-- @[Internal_@Trace_setOrCreate_V1_pag1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@TracesetOrCreateV1/Page1.ets) -->

``` TypeScript
// Page1.ets
export let storage: LocalStorage = new LocalStorage();

storage.setOrCreate('count', 47);

@Entry(storage)
@Component
struct Page1 {
  @LocalStorageProp('count') count: number = 0;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            storage.setOrCreate('count', storage.get<number>('count') as number + 100);
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

<!-- @[Internal_@Trace_setOrCreate_V1_pag2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@TracesetOrCreateV1/Page2.ets) -->

``` TypeScript
// Page2.ets
import { storage } from './Page1'

@Builder
export function Page2Builder() {
  Page2()
}

// The Page2 component obtains the LocalStorage instance of the parent component Page1.
@Component
struct Page2 {
  @LocalStorageProp('count') count: number = 0;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            storage.setOrCreate('count', storage.get<number>('count') as number + 100);
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

In V2, you can use \@Local and \@Monitor to achieve the similar effect.

- The **count** variable decorated with \@Local is local to the component. Changes to it will not synchronize back to **storage**.

- \@Monitor listens for changes of **storage.count**. When **storage.count** changes, the \@Local value is updated in the callback of \@Monitor.

<!-- @[Internal_@ObservedV2_@Trace_V2_pag1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@TracesetOrCreateV2/Page1.ets) -->

``` TypeScript
// Page1.ets
import { MyStorage } from './storage';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

@Entry
@ComponentV2
struct Page1 {
  storage: MyStorage = MyStorage.instance();
  pageStack: NavPathStack = new NavPathStack();
  @Local count: number = this.storage.count;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    hilog.info(DOMAIN, 'testTag', '%{public}s', `Page1 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }

  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            this.storage.count += 100;
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

<!-- @[Internal_@ObservedV2_@Trace_V2_pag2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@TracesetOrCreateV2/Page2.ets) -->

``` TypeScript
// Page2.ets
import { MyStorage } from './storage';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  storage: MyStorage = MyStorage.instance();
  pathStack: NavPathStack = new NavPathStack();
  @Local count: number = this.storage.count;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    hilog.info(DOMAIN, 'testTag', '%{public}s', `Page2 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }

  build() {
    NavDestination() {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            this.storage.count += 100;
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

### Scenario Where a Custom Component Receives a LocalStorage Instance

To support scenarios where **Navigation** is used, LocalStorage instances can be passed as parameters to custom components and shared with all child components using the current custom component as the root.

In V2, this scenario can be implemented by creating multiple global instances of \@ObservedV2 and \@Trace decorated classes.

V1:

<!-- @[Internal_Trace_customize_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalTraceCustomize/InternalTraceCustomizeV1.ets) -->

``` TypeScript
let localStorageA: LocalStorage = new LocalStorage();
localStorageA.setOrCreate('propA', 'propA');

let localStorageB: LocalStorage = new LocalStorage();
localStorageB.setOrCreate('propB', 'propB');

let localStorageC: LocalStorage = new LocalStorage();
localStorageC.setOrCreate('propC', 'propC');

@Entry
@Component
struct MyNavigationTestStack {
  @Provide('pageInfo') pageInfo: NavPathStack = new NavPathStack();

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      // Pass multiple LocalStorage instances.
      PageOneStack({}, localStorageA)
    } else if (name === 'pageTwo') {
      PageTwoStack({}, localStorageB)
    } else if (name === 'pageThree') {
      PageThreeStack({}, localStorageC)
    }
  }

  build() {
    Column({ space: 5 }) {
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
      .borderWidth(1)
    }
  }
}

@Component
struct PageOneStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('propA') propA: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        // Display 'propA'.
        NavigationContentMsgStack()
        // Display 'propA'.
        Text(`${this.propA}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct PageTwoStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('propB') propB: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        // Display 'Hello'. The current LocalStorage instance localStorageB has no value corresponding to propA. Therefore, the local default value 'Hello' is used.
        NavigationContentMsgStack()
        //Display 'propB'.
        Text(`${this.propB}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })

      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct PageThreeStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('propC') propC: string = 'pageThreeStack';

  build() {
    NavDestination() {
      Column() {
        // Display 'Hello'. The current LocalStorage instance localStorageC has no value corresponding to propA. Therefore, the local default value 'Hello' is used.
        NavigationContentMsgStack()
        // Display 'propC'.
        Text(`${this.propC}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })

      }.width('100%').height('100%')
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct NavigationContentMsgStack {
  @LocalStorageLink('propA') propA: string = 'Hello';

  build() {
    Column() {
      Text(`${this.propA}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

V2:

Declare the \@ObservedV2 decorated class to replace LocalStorage functionality. LocalStorage keys can be replaced with \@Trace decorated properties.

<!-- @[Internal_Trace_customize_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalTraceCustomize/storage.ets) --> 

``` TypeScript
// @ObservedV2 decorated class replaces LocalStorage.
@ObservedV2
export class MyStorageA {
  @Trace public propA: string = 'Hello';

  constructor(propA?: string) {
    this.propA = propA ? propA : this.propA;
  }
}

@ObservedV2
export class MyStorageB extends MyStorageA {
  @Trace public propB: string = 'Hello';

  constructor(propB: string) {
    super();
    this.propB = propB;
  }
}

@ObservedV2
export class MyStorageC extends MyStorageA {
  @Trace public propC: string = 'Hello';

  constructor(propC: string) {
    super();
    this.propC = propC;
  }
}
```

In the **PageOneStack**, **PageTwoStack**, and **PageThreeStack** components, create instances of **MyStorageA**, **MyStorageB**, and **MyStorageC**, respectively. Pass these instances to the child component **NavigationContentMsgStack** using \@Param. This way, the same cross-component state sharing capability as LocalStorage is achieved.

<!-- @[Internal_Trace_Customize_Param](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalTraceCustomize/Index.ets) -->

``` TypeScript
// Index.ets
import { MyStorageA, MyStorageB, MyStorageC } from './storage';

@Entry
@ComponentV2
struct MyNavigationTestStack {
  pageInfo: NavPathStack = new NavPathStack();

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      PageOneStack()
    } else if (name === 'pageTwo') {
      PageTwoStack()
    } else if (name === 'pageThree') {
      PageThreeStack()
    }
  }

  build() {
    Column({ space: 5 }) {
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
      .borderWidth(1)
    }
  }
}

@ComponentV2
struct PageOneStack {
  pageInfo: NavPathStack = new NavPathStack();
  @Local storageA: MyStorageA = new MyStorageA('PropA');

  build() {
    NavDestination() {
      Column() {
        // Display 'PropA'.
        NavigationContentMsgStack({ storage: this.storageA })
        // Display 'PropA'.
        Text(`${this.storageA.propA}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@ComponentV2
struct PageTwoStack {
  pageInfo: NavPathStack = new NavPathStack();
  @Local storageB: MyStorageB = new MyStorageB('PropB');

  build() {
    NavDestination() {
      Column() {
        // Display "Hello".
        NavigationContentMsgStack({ storage: this.storageB })
        // Display "PropB".
        Text(`${this.storageB.propB}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })

      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@ComponentV2
struct PageThreeStack {
  pageInfo: NavPathStack = new NavPathStack();
  @Local storageC: MyStorageC = new MyStorageC('PropC');

  build() {
    NavDestination() {
      Column() {
        // Display "Hello".
        NavigationContentMsgStack({ storage: this.storageC })
        // Display "PropC".
        Text(`${this.storageC.propC}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })

      }.width('100%').height('100%')
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@ComponentV2
struct NavigationContentMsgStack {
  @Require @Param storage: MyStorageA;

  build() {
    Column() {
      Text(`${this.storage.propA}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

### LocalStorage Migration in Multi-instance Scenarios

To share data between different abilities, LocalStorage supports data access across abilities.

For this scenario, V2 can combine \@ObservedV2 and \@Trace to create an observable global singleton object, which defines a Map type to store data from different ability pages, achieving data sharing between different abilities. For details about how to start an ability, see [Specified](../../application-models/uiability-launch-type.md#specified).

**Home screen**

<!-- @[Internal_localStorage_multi_instance_1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/LocalStorageMultiInstance/Index.ets) -->

``` TypeScript
// Index.ets
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text ('Use the file manager to open multiple PDF files in this application')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
      Button('Jump to PDF_A').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.samples.paradigmstatemanagement',
          abilityName: 'PdfEntryAbility',
          uri: 'PDF_A',
          parameters: {
            key: 'PDF_A',
            value: 'PDF_A-1111111111',
          }
        };
        this.context.startAbility(wantInfo);
      })
      Button('Jump to PDF_B').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.samples.paradigmstatemanagement',
          abilityName: 'PdfEntryAbility',
          uri: 'PDF_B',
          parameters: {
            key: 'PDF_B',
            value: 'PDF_B-22222222222',
          }
        };
        this.context.startAbility(wantInfo);
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

V2:

Defines a global observable singleton using \@ObservedV2 and \@Trace. The global **map** object is used to associate data. This approach requires you to establish a unique key-value relationship. Note that the singleton instance is encapsulated and stored separately.

<!-- @[Internal_localStorage_multi_instance_2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/LocalStorageMultiInstance/model/PDFData.ets) -->

``` TypeScript
// model/PDFData.ets
@ObservedV2
export default class PDFData {
  // Singleton instance.
  private static instance_: PDFData | null = null;
  @Trace private data: Map<string, string> = new Map();
  @Trace private flag: string = '';

  private constructor() {
  }

  static getInstance(): PDFData {
    if (!PDFData.instance_) {
      PDFData.instance_ = new PDFData();
    }
    return PDFData.instance_;
  }

  setData(key: string, value: string) {
    this.data.set(key, value);
  }

  getData() {
    return this.data;
  }

  setFlag(value: string) {
    this.flag = value;
  }

  getFlag() {
    return this.flag;
  }
}
```

<!-- @[Internal_localStorage_multi_instance_3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/LocalStorageMultiInstance/PdfEntryAbility.ets) -->

``` TypeScript
import { UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import PDFData from './model/PDFData';

export default class PDFAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Use the singleton to store data.
    const data = this.launchWant.parameters as Record<string, string>;
    PDFData.getInstance().setData(data.key, data.value);
    PDFData.getInstance().setFlag(this.launchWant.uri || '');
    windowStage.loadContent('pages/internalmigrate/LocalStorageMultiInstance/PDF').catch();
  }
}
```

<!-- @[Internal_localStorage_multi_instance_4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/LocalStorageMultiInstance/PDF.ets) -->

``` TypeScript
// PDF.ets
import PDFData from './model/PDFData';

@Entry
@ComponentV2
struct PDF {
  @Local message: string = 'uri';

  build() {
    Column() {
      Text(this.message)
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
    }
    .backgroundColor(Color.Pink)
    .height('100%')
    .width('100%')
  }

  aboutToAppear(): void {
    // The URI here is only displayed briefly. The actual function is to open and render the PDF file.
    const key: string = PDFData.getInstance().getFlag();
    // Obtain the page data from the singleton based on the unique ID.
    this.message = PDFData.getInstance().getData().get(key) || '';
  }
}
```

## AppStorage->AppStorageV2

The modification of creating global \@ObservedV2 and \@Trace decorated instances in the previous section is not suitable for cross-Ability data sharing. AppStorageV2 can be used instead.

V1:

AppStorage is bound to the application process and enables data sharing across [abilities](../../reference/apis-ability-kit/js-apis-app-ability-ability.md).

Using \@StorageLink allows local modifications to synchronize back to AppStorage.

<!-- @[Internal_AppStorage_V1_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalAppStorageV1one.ets) -->

``` TypeScript
// EntryAbility Index.ets
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @StorageLink('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

<!-- @[Internal_AppStorage_V1_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalAppStorageV1two.ets) -->

``` TypeScript
// EntryAbility1 Index1.ets
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index1 {
  @StorageLink('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

V2:

AppStorageV2 can be used to achieve cross-ability data sharing.

Example:

<!-- @[Internal_AppStorage_V2_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalAppStorageV2one.ets) -->

``` TypeScript
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
export class MyStorage {
  @Trace public count: number = 0;
}

@Entry
@ComponentV2
struct Index {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility count: ${this.storage.count}`)
        .fontSize(50)
        .onClick(() => {
          this.storage.count++;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

<!-- @[Internal_AppStorage_V2_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalAppStorageV2two.ets) -->

``` TypeScript
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
export class MyStorage {
  @Trace public count: number = 0;
}

@Entry
@ComponentV2
struct Index1 {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.storage.count}`)
        .fontSize(50)
        .onClick(() => {
          this.storage.count++;
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

For scenarios that require @StorageProp-like behavior, where local variables can be modified without synchronizing back to AppStorage, while the component still receives updates from AppStorage:

V1:

<!-- @[Internal_StorageProp_V1_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalStoragePropV1one.ets) -->

``` TypeScript
// EntryAbility Index.ets
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @StorageProp('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility count: ${this.count}`)
        .fontSize(25)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          AppStorage.setOrCreate('count', AppStorage.get<number>('count') as number + 100);
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

<!-- @[Internal_StorageProp_V1_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalStoragePropV1two.ets) -->

``` TypeScript
// EntryAbility1 Index1.ets
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index1 {
  @StorageProp('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          AppStorage.setOrCreate('count', AppStorage.get<number>('count') as number + 100);
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

V2:

Use \@Monitor and \@Local to achieve the similar behavior:

<!-- @[Internal_StorageProp_V2_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalStoragePropV2one.ets) -->

``` TypeScript
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

@ObservedV2
export class MyStorage {
  @Trace public count: number = 0;
}

@Entry
@ComponentV2
struct Index {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  @Local count: number = this.storage.count;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    hilog.info(DOMAIN, 'testTag', '%{public}s', `Index ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }

  build() {
    Column() {
      Text(`EntryAbility count: ${this.count}`)
        .fontSize(25)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          this.storage.count += 100;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

<!-- @[Internal_StorageProp_V2_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalStoragePropV2two.ets) -->

``` TypeScript
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

@ObservedV2
export class MyStorage {
  @Trace public count: number = 0;
}

@Entry
@ComponentV2
struct Index1 {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  @Local count: number = this.storage.count;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    hilog.info(DOMAIN, 'testTag', '%{public}s', `Index1 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(25)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          this.storage.count += 100;
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // Replace it with the bundle name in AppScope/app.json5.
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

## Environment -> Direct API Calls to Obtain System Environment Variables

In V1, you can obtain environment variables through **Environment**. However, the result obtained by **Environment** cannot be directly used. It must be combined with AppStorage to obtain the corresponding environment variable values.

After migration to V2, you can directly obtain the system environment variables through the [config](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext-1) property of **UIAbilityContext**, eliminating the need for the **Environment** API.

V1:

The following uses **languageCode** as an example.

<!-- @[Internal_Environment_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalEnvironmentV1.ets) -->

``` TypeScript
// Store languageCode to AppStorage.
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';

  build() {
    Row() {
      Column() {
        // Obtain the current device's language code.
        Text(this.languageCode)
      }
    }
  }
}
```

V2:

Encapsulate an **Env** class to manage multiple system environment variables.

<!-- @[Internal_Environment_V2_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/pages/Env.ets) -->

``` TypeScript
// Env.ets
import { ConfigurationConstant } from '@kit.AbilityKit';

export class Env {
  public language: string | undefined;
  public colorMode: ConfigurationConstant.ColorMode | undefined;
  // Font size scaling multiplier.
  public fontSizeScale: number | undefined;
  // Font width scaling multiplier.
  public fontWeightScale: number | undefined;
}

export let env: Env = new Env();
```

Obtain the required system environment variables from **onCreate**.

<!-- @[Internal_Environment_V2_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalEnvironmentV2/EntryAbility.ets) --> 

``` TypeScript
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { env } from '../pages/Env';

export default class EntryAbility extends UIAbility {
  // Obtain the required system environment variables in onCreate.
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    env.language = this.context.config.language;
    env.colorMode = this.context.config.colorMode;
    env.fontSizeScale = this.context.config.fontSizeScale;
    env.fontWeightScale = this.context.config.fontWeightScale;
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index');
  }
}
```

Obtain the current value of **Env** on the page.

<!-- @[Internal_Environment_V2_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalEnvironmentV2/Index.ets) -->

``` TypeScript
// Index.ets
import { env } from '../pages/Env';

@Entry
@ComponentV2
struct Index {
  build() {
    Row() {
      Column() {
        // Output the environment variables of the current device.
        Text(`languageCode: ${env.language}`).fontSize(20)
        Text(`colorMode: ${env.colorMode}`).fontSize(20)
        Text(`fontSizeScale: ${env.fontSizeScale}`).fontSize(20)
        Text(`fontWeightScale: ${env.fontWeightScale}`).fontSize(20)
      }
    }
  }
}
```

## PersistentStorage->PersistenceV2

In V1, **PersistentStorage** provides UI data persistence. In V2, this functionality is replaced by the more convenient **PersistenceV2** API.

- Persistence trigger timing of **PersistentStorage** relies on AppStorage's observation capability and is coupled with AppStorage. As a result, you cannot control when to read or write persistent data.

- **PersistentStorage** uses serialization and deserialization without explicit type information, resulting in type loss after persistence, and object methods cannot be persisted.

For **PersistenceV2**:

- When an \@ObservedV2 object is associated with **PersistenceV2**, changes to its \@Trace properties automatically trigger persistence of the entire object.

- You can manually trigger persistence operations by calling [PersistenceV2.save()](../../reference/apis-arkui/js-apis-stateManagement.md#save) and [PersistenceV2.globalConnect()](./arkts-new-persistencev2.md#using-globalconnect-to-store-data).

V1:

<!-- @[Internal_Persistent_Storage_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalPersistentStorageV1.ets) -->

``` TypeScript
class Data {
  public name: string = 'ZhangSan';
  public id: number = 0;
}

PersistentStorage.persistProp('numProp', 47);
PersistentStorage.persistProp('dataProp', new Data());

@Entry
@Component
struct Index {
  @StorageLink('numProp') numProp: number = 48;
  @StorageLink('dataProp') dataProp: Data = new Data();

  build() {
    Column() {
      // The current result is saved when the application exits. After the restart, the last saved result is displayed.
      Text(`numProp: ${this.numProp}`)
        .onClick(() => {
          this.numProp += 1;
        })
        .fontSize(30)

      // The current result is saved when the application exits. After the restart, the last saved result is displayed.
      Text(`dataProp.name: ${this.dataProp.name}`)
        .onClick(() => {
          this.dataProp.name += 'a';
        })
        .fontSize(30)
      // The current result is saved when the application exits. After the restart, the last saved result is displayed.
      Text(`dataProp.id: ${this.dataProp.id}`)
        .onClick(() => {
          this.dataProp.id += 1;
        })
        .fontSize(30)

    }
    .width('100%')
  }
}
```

V2:

In this example:

- Persisted data is migrated from PersistentStorage to PersistenceV2 (V2). In V2, properties decorated with \@Trace are automatically persisted, while non-\@Trace decorated properties require manual **save** calls for persistence.

- The **move** function and the components to display are placed in the same .ets file in this example. You can define your own **move** functions and place them in appropriate locations for unified migration operations.

<!-- @[Internal_Persistent_Storage_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalPersistentStorageV2.ets) -->

``` TypeScript
// Migrate to globalConnect.
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;
// Callback used to receive persistence errors.
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

class Data {
  public name: string = 'ZhangSan';
  public id: number = 0;
}

@ObservedV2
class V2Data {
  @Trace public name: string = '';
  @Trace public id: number = 1;
}

@ObservedV2
export class Sample {
  @Trace public num: number = 1;
  // For complex objects, use the @Type decorator to ensure successful serialization.
  @Type(V2Data)
  @Trace public V2: V2Data = new V2Data();
}

// Auxiliary data used to determine whether data migration is complete.
@ObservedV2
class StorageState {
  @Trace public isCompleteMoving: boolean = false;
}

function move() {
  let movingState = PersistenceV2.globalConnect({ type: StorageState, defaultCreator: () => new StorageState() })!;
  if (!movingState.isCompleteMoving) {
    PersistentStorage.persistProp('numProp', 47);
    PersistentStorage.persistProp('dataProp', new Data());
    let num = AppStorage.get<number>('numProp')!;
    let v1Data = AppStorage.get<Data>('dataProp')!;
    PersistentStorage.deleteProp('numProp');
    PersistentStorage.deleteProp('dataProp');

    // Create the corresponding V2 data.
    let migrate = PersistenceV2.globalConnect({
      type: Sample,
      key: 'connect2',
      defaultCreator: () => new Sample()
    })!; // You can also use the default constructor.
    // Assign values. Properties decorated with @Trace are automatically saved. For non-@Trace objects, you can call save(), for example, PersistenceV2.save('connect2'), to save the data.
    migrate.num = num;
    migrate.V2.name = v1Data.name;
    migrate.V2.id = v1Data.id;

    // Set the migration flag to true.
    movingState.isCompleteMoving = true;
  }
}

move();

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // Store data with key: connect2.
  @Local p: Sample =
    PersistenceV2.globalConnect({ type: Sample, key: 'connect2', defaultCreator: () => new Sample() })!;

  build() {
    Column({ space: 5 }) {
      // The current result is saved when the application exits. After the restart, the last saved result is displayed.
      Text(`numProp: ${this.p.num}`)
        .onClick(() => {
          this.p.num += 1;
        })
        .fontSize(30)

      // The current result is saved when the application exits. After the restart, the last saved result is displayed.
      Text(`dataProp.name: ${this.p.V2.name}`)
        .onClick(() => {
          this.p.V2.name += 'a';
        })
        .fontSize(30)
      // The current result is saved when the application exits. After the restart, the last saved result is displayed.
      Text(`dataProp.id: ${this.p.V2.id}`)
        .onClick(() => {
          this.p.V2.id += 1;
        })
        .fontSize(30)
    }
    .width('100%')
  }
}
```