# 应用内状态变量迁移
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

本文档主要介绍应用内状态变量迁移，包含以下场景。


| V1装饰器名称/场景 | 迁移方案 |
| -------- | -------- |
| [LocalStorage](./arkts-localstorage.md) | [@ObservedV2](./arkts-new-observedV2-and-trace.md) [@Trace](./arkts-new-observedV2-and-trace.md) |
| [AppStorage](./arkts-appstorage.md) | [AppStorageV2](./arkts-new-appstoragev2.md) |
| [Environment](./arkts-environment.md) | 通过[UIAbilityContext](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext-1)的config属性获取系统环境变量 |
| [PersistentStorage](./arkts-persiststorage.md) | [PersistenceV2](./arkts-new-persistencev2.md) |
| 存量迁移场景 | \@ObservedV2、\@Trace、[@Monitor](./arkts-new-monitor.md) |


## LocalStorage->\@ObservedV2/\@Trace

**迁移规则**

LocalStorage的目的是实现页面间的状态变量共享。由于V1状态变量和View层耦合，开发者难以自主实现页面间状态变量的共享，因此框架提供了该能力。

状态管理V2将状态变量的观察能力内嵌到数据本身，不再和View层耦合。因此，不再需要类似LocalStorage的能力，可以使用创建\@ObservedV2和\@Trace装饰类的实例，开发者需自行import和export，实现状态变量的页面间共享。


### 基本场景

V1:

通过windowStage.[loadContent](../../reference/apis-arkui/arkts-apis-window-Window.md#loadcontent9)和this.getUIContext().[getSharedLocalStorage](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getsharedlocalstorage12)接口实现页面间的状态变量共享。

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

在下面的示例中，使用\@LocalStorageLink，可以将开发者本地的修改同步回LocalStorage中。

<!-- @[Internal_@ObservedV2_@Trace_V1_pag1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV1/pages/Page1.ets) -->

``` TypeScript
// Page1.ets
// 预览器上不支持获取页面共享的LocalStorage实例。
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

// Page2组件获得了父亲Page1组件的LocalStorage实例
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

使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page2页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。

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

- 声明\@ObservedV2装饰的MyStorage类，并import到需要使用的页面中。
- 声明被\@Trace的属性作为页面间共享的可观察的数据。

<!-- @[Internal_@ObservedV2_@Trace_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/Internal@ObservedV2@TraceV2/storage.ets) --> 

``` TypeScript
// 声明@ObservedV2装饰的MyStorage类
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

使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page2页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。

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

如果开发者需要实现类似于\@LocalStorageProp的效果，但希望本地的修改不同步回LocalStorage中，可参考以下示例：

- 在`Page1`中改变`count`值，由于count被\@LocalStorageProp装饰的，因此其更改仅在本地生效，不会同步到LocalStorage。
- 点击`push to Page2`按钮，跳转到`Page2`。由于在`Page1`中改变`count`值不会同步到LocalStorage，因此`Page2`中的Text组件仍显示初始值47。
- 点击`change Storage Count`按钮，调用LocalStorage的setOrCreate，改变`count`对应的值，并通知所有绑定该key的变量。

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

// Page2组件获得了父亲Page1组件的LocalStorage实例
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

在V2中，可以借助\@Local和\@Monitor实现类似的效果。

- \@Local装饰的`count`变量为组件本地的值，其改变不会同步回`storage`。
- \@Monitor监听`storage.count`的变化，当`storage.count`改变时，在\@Monitor的回调里改变本地\@Local的值。

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


### 自定义组件接收LocalStorage实例场景

为了配合Navigation的场景，LocalStorage支持作为自定义组件的入参，传递给以当前自定义组件为根节点的所有子自定义组件。

对于该场景，V2可以使用创建多个全局\@ObservedV2和\@Trace装饰类的实例进行替代。

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
      // 传递不同的LocalStorage实例
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
              this.pageInfo.pushPath({ name: 'pageOne' }); // 将name指定的NavDestination页面信息入栈
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
        // 显示'propA'
        NavigationContentMsgStack()
        // 显示'propA'
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
        // 显示'Hello'，当前LocalStorage实例localStorageB没有propA对应的值，使用本地默认值'Hello'
        NavigationContentMsgStack()
        // 显示'propB'
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
        // 显示'Hello'，当前LocalStorage实例localStorageC没有propA对应的值，使用本地默认值'Hello'
        NavigationContentMsgStack()
        // 显示'propC'
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

V2：

声明\@ObservedV2装饰的class代替LocalStorage。其中LocalStorage的key可以用\@Trace装饰的属性代替。

<!-- @[Internal_Trace_customize_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalTraceCustomize/storage.ets) --> 

``` TypeScript
// @ObservedV2装饰的class代替LocalStorage
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

在PageOneStack、PageTwoStack和PageThreeStack组件内分别创建MyStorageA、MyStorageB、MyStorageC的实例，并通过\@Param传递给其子组件NavigationContentMsgStack，从而实现类似LocalStorage实例在子组件树上共享的能力。

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
              this.pageInfo.pushPath({ name: 'pageOne' }); // 将name指定的NavDestination页面信息入栈
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
        // 显示'PropA'
        NavigationContentMsgStack({ storage: this.storageA })
        // 显示'PropA'
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
        // 显示'Hello'
        NavigationContentMsgStack({ storage: this.storageB })
        // 显示'PropB'
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
        // 显示'Hello'
        NavigationContentMsgStack({ storage: this.storageC })
        // 显示'PropC'
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


### 多实例场景LocalStorage的迁移

LocalStorage支持单个UIAbility内的页面间状态共享。对于该场景，V2可结合@ObservedV2与@Trace创建可观测的全局单例对象，定义Map类型存储不同Ability页面的数据，通过不同的key值访问对应数据，从而实现UIAbility内的数据共享。启动Ability可以参考[specified启动模式](../../application-models/uiability-launch-type.md#specified启动模式)。

**主页面**

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
      Text('使用文件管理器，使用本应用打开多个PDF')
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

使用\@ObservedV2+\@Trace定义全局可观测单例，通过全局的map对象进行数据关联，这种方式需要开发者自行建立唯一的key和value关系。注意单例单独封装存放。

<!-- @[Internal_localStorage_multi_instance_2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/LocalStorageMultiInstance/model/PDFData.ets) -->

``` TypeScript
// model/PDFData.ets
@ObservedV2
export default class PDFData {
  // 单例实例
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
    // 用单例存储数据
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
    // 此处只做简略显示uri，实际功能为打开渲染PDF文件
    const key: string = PDFData.getInstance().getFlag();
    // 根据唯一标识，从单例中获取页面对应数据
    this.message = PDFData.getInstance().getData().get(key) || '';
  }
}
```


## AppStorage->AppStorageV2

上一小节中，虽然可以通过创建全局@ObservedV2和@Trace装饰的单例对象实现跨Ability的数据共享，但AppStorageV2提供了更标准、便捷的跨Ability共享方案，推荐使用AppStorageV2替代。

V1:

AppStorage与应用进程绑定，支持跨[Ability](../../reference/apis-ability-kit/js-apis-app-ability-ability.md)数据共享。

在下面的示例中，使用\@StorageLink，可以使得开发者本地的修改同步回AppStorage中。

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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

V2:

可以使用AppStorageV2实现跨Ability共享。

如下面示例：

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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

如果开发者需要实现类似于\@StorageProp的效果，希望本地的修改不同步回AppStorage，而AppStorage的变化能够通知到使用\@StorageProp装饰器的组件，可以参考以下示例对比。

V1：

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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

V2:

开发者可以使用\@Monitor和\@Local实现类似效果，示例如下。

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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
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
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```


## Environment->调用Ability接口直接获取系统环境变量

V1中，开发者可以通过Environment来获取环境变量，但Environment获取的结果无法直接使用，需要配合AppStorage才能得到对应环境变量的值。

在切换V2的过程中，开发者无需再通过Environment来获取环境变量，可以直接通过[UIAbilityContext的config属性](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext-1)获取系统环境变量。

V1:

以`languageCode`为例。

<!-- @[Internal_Environment_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalEnvironmentV1.ets) -->

``` TypeScript
// 将设备languageCode存入AppStorage中
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';

  build() {
    Row() {
      Column() {
        // 输出当前设备的languageCode
        Text(this.languageCode)
      }
    }
  }
}
```

V2:

封装Env类型来传递多个系统环境变量。

<!-- @[Internal_Environment_V2_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/pages/Env.ets) -->

``` TypeScript
// Env.ets
import { ConfigurationConstant } from '@kit.AbilityKit';

export class Env {
  public language: string | undefined;
  public colorMode: ConfigurationConstant.ColorMode | undefined;
  // 字体大小缩放的倍数
  public fontSizeScale: number | undefined;
  // 字体粗细缩放的倍数
  public fontWeightScale: number | undefined;
}

export let env: Env = new Env();
```

在`onCreate`里获取需要的系统环境变量。

<!-- @[Internal_Environment_V2_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalEnvironmentV2/EntryAbility.ets) --> 

``` TypeScript
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { env } from '../pages/Env';

export default class EntryAbility extends UIAbility {
  // 在onCreate里获取需要的系统环境变量
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

在页面中获取当前Env的值。

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
        // 输出当前设备的环境变量
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

V1中PersistentStorage提供了持久化UI数据的能力，而V2则提供了更加方便使用的PersistenceV2接口来替代它。

- PersistentStorage持久化的触发时机依赖AppStorage的观察能力，且与AppStorage耦合，开发者无法自主选择写入或读取持久化数据的时机。

- PersistentStorage使用序列化和反序列化，并没有传入类型，所以在持久化后，会丢失其类型，且对象的属性方法不能持久化。

对于PersistenceV2：

- 与PersistenceV2关联的\@ObservedV2对象，其\@Trace属性的变化，会触发整个关联对象的自动持久化。

- 开发者也可以调用[PersistenceV2.save()](../../reference/apis-arkui/js-apis-stateManagement.md#save)和[PersistenceV2.globalConnect()](./arkts-new-persistencev2.md#使用globalconnect存储数据)来手动触发持久化写入和读取。

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
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`numProp: ${this.numProp}`)
        .onClick(() => {
          this.numProp += 1;
        })
        .fontSize(30)

      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`dataProp.name: ${this.dataProp.name}`)
        .onClick(() => {
          this.dataProp.name += 'a';
        })
        .fontSize(30)
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
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

下面的案例展示了：

- 将PersistentStorage的持久化数据迁移到V2的PersistenceV2中。V2对被\@Trace标记的数据可以自动持久化，对于非\@Trace数据，需要手动调用save进行持久化。
- 示例中的move函数和需要显示的组件放在了一个ets中，开发者可以定义自己的move函数，并放入合适的位置进行统一迁移操作。

<!-- @[Internal_Persistent_Storage_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalPersistentStorageV2.ets) -->

``` TypeScript
// 迁移到globalConnect
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;
// 接受序列化失败的回调
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
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(V2Data)
  @Trace public V2: V2Data = new V2Data();
}

// 用于判断是否完成数据迁移的辅助数据
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

    // V2创建对应数据
    let migrate = PersistenceV2.globalConnect({
      type: Sample,
      key: 'connect2',
      defaultCreator: () => new Sample()
    })!; // 使用默认构造函数也可以
    // 赋值数据，@Trace修饰的会自动保存，对于非@Trace对象，也可以调用save保存，如：PersistenceV2.save('connect2');
    migrate.num = num;
    migrate.V2.name = v1Data.name;
    migrate.V2.id = v1Data.id;

    // 将迁移标志设置为true
    movingState.isCompleteMoving = true;
  }
}

move();

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:connect2存入数据
  @Local p: Sample =
    PersistenceV2.globalConnect({ type: Sample, key: 'connect2', defaultCreator: () => new Sample() })!;

  build() {
    Column({ space: 5 }) {
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`numProp: ${this.p.num}`)
        .onClick(() => {
          this.p.num += 1;
        })
        .fontSize(30)

      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`dataProp.name: ${this.p.V2.name}`)
        .onClick(() => {
          this.p.V2.name += 'a';
        })
        .fontSize(30)
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
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
