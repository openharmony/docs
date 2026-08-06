# Transition from Router to Navigation

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @huangxiaolinabc-->
<!--Designer: @fangzhiyuan1-->
<!--Tester: @Giacinta-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=39f66a31c4cd77f8015af575d95ace022de7992b translatedAt=2026-08-04T06:37:52.962Z pushedAt=2026-08-04T08:22:30.953Z -->

The [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) component stands out for its wider range of animations, higher flexibility in one-time development for multi-device deployment, and more adaptable stack operations. This topic guides you through the transition from using APIs in the Router module to using the **Navigation** component in terms of page navigation, animation, and lifecycle.

## Page Structure

Pages managed by **Router** are @Entry decorated components, each of which must be declared in **main_page.json**.

```json5
// main_page.json
{
  "src": [
    "pages/Index",
    "pages/pageOne",
    "pages/pageTwo"
  ]
}
```

The following is an example of a page managed by **Router**.

<!-- @[router_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Index.ets) -->   

``` TypeScript
// Index.ets
import { router } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
const DOMAIN = 0xF811;
const TAG = '[Sample_ArkTSRouter]';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  @State router: string = 'Examples of Router, Navigation, and NavPathStack';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('router to pageOne', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.getUIContext().getRouter().pushUrl({
              url: 'pages/routerToNavigation/router/PageOne' // Target URL.
            }, router.RouterMode.Standard, (err) => {
              if (err) {
                hilog.error(DOMAIN, TAG, 'page ON_SHOWN:' + `Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
                return;
              }
              hilog.info( DOMAIN, TAG, 'Invoke pushUrl succeeded.');
            });
          })
        // ...
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

<!-- @[router_page_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/PageOne.ets) -->

``` TypeScript
@Entry
@Component
struct pageOne {
  @State message: string = 'This is pageOne';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('router back to Index', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.getUIContext().getRouter().back();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

Pages using **Navigation** are divided into navigation pages and subpages. The navigation page, also known as a [Navbar](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navbar12), is a child component of **Navigation**, while subpages are child components of [NavDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md).

The following is an example of the navigation page using **Navigation**.

<!-- @[nav_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/navigation/Index.ets) -->

``` TypeScript
// Index.ets
@Entry
@Component
struct Index1 {
  pathStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pathStack) {
      Column() {
        Button('Push PageOne', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.pushPathByName('navigation_pageOne', null);
          })
      }.width('100%').height('100%')
    }
    .title('Navigation')
    .mode(NavigationMode.Stack)
  }
}
```

The following is an example of a subpage using **Navigation**.

<!-- @[nav_page_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/navigation/PageOne.ets) -->

``` TypeScript
@Builder
export function PageOneBuilder() {
  PageOne();
}

@Entry
@Component
export struct PageOne {
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        // Replace $r('app.string.routerToNavigation_nav_text1_backHome') with the actual resource file. In this example, the value in the resource file is "Back to Home Page."
        Button($r('app.string.routerToNavigation_nav_text1_backHome'), { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.clear();
          })
      }.width('100%').height('100%')
    }.title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

Each sub-page must also be configured in the system configuration file `router_map.json` (see [System Routing Table](./arkts-navigation-cross-package.md#system-routing-table)).

```json5
// Configure {"routerMap": "$profile:router_map"} in the project configuration file module.json5.
// router_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    }
  ]
}
```

## Route Operations

The **Router** module leverages APIs from the @ohos.router module to perform page operations. It is recommended that you obtain the [Router](../reference/apis-arkui/arkts-apis-uicontext-router.md) object using [getRouter](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getrouter) in [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md).

<!-- @[get_router](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/navPathStack/GetRouter.ets) -->

``` TypeScript
// push page
this.getUIContext().getRouter().pushUrl({ url:'pages/pageOne', params: null });

// pop page
this.getUIContext().getRouter().back({ url: 'pages/pageOne' });

// replace page
this.getUIContext().getRouter().replaceUrl({ url: 'pages/pageOne' });

// clear all page
this.getUIContext().getRouter().clear();

// Obtain the size of the page stack.
let size = this.getUIContext().getRouter().getLength();

// Obtain the page state.
let pageState = this.getUIContext().getRouter().getState();
```

To use the **Navigation** component for page operations, call APIs of the [NavPathStack](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navpathstack10) navigation controller object. You need to first create a **NavPathStack** object and pass it into **Navigation**.

<!-- @[nav_stack_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/navPathStack/Index.ets) -->

``` TypeScript
@Entry
@Component
struct Index {
  pathStack: NavPathStack = new NavPathStack();

  build() {
    // Set NavPathStack and pass it to Navigation.
    Navigation(this.pathStack) {
      // ...
    }.width('100%').height('100%')
    .title('Navigation, Navigation')
    .mode(NavigationMode.Stack)
  }
}
```

<!-- @[nav_stack_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/navPathStack/PathStack.ets) -->

``` TypeScript
this.pathStack.pop();
// push page
this.pathStack.pushPath({ name: 'pageOne' });

// pop page
this.pathStack.pop();
this.pathStack.popToIndex(1);
this.pathStack.popToName('pageOne');

// replace page
this.pathStack.replacePath({ name: 'pageOne' });

// clear all page
this.pathStack.clear();

//Obtain the size of the navigation stack.
let size: number = this.pathStack.size();

// Remove all pages with the name pageOne from the stack.
this.pathStack.removeByName('pageOne');

// Remove the page with the specified index.
this.pathStack.removeByIndexes([1, 3, 5]);

// Obtain all page names in the stack.
this.pathStack.getAllPathName();

// Obtain the parameters of the page whose index is 1.
this.pathStack.getParamByIndex(1);

// Obtain the parameters of the pageOne page.
this.pathStack.getParamByName('pageOne');

// Obtain the index collection of the pageOne page.
this.pathStack.getIndexByName('pageOne');
// ...
```

**Router** serves as a global module that can be used across any page, whereas **Navigation** operates as a component. If subpages within a **Navigation** component need to perform routing operations, they must access the **NavPathStack** object held by **Navigation**. The following are several methods to obtain the **NavPathStack** object:

**Method 1**: Use @Provide and @Consume (this method creates coupling and is not recommended).

<!-- @[router_1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Router1.ets) -->

``` TypeScript
// Navigation root container
@Entry
@Component
struct Index {
  // Navigation creates a NavPathStack object decorated by @Provide.
  @Provide('pathStack') pathStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pathStack) {
      // ...
    }
    .title('Method 1: Navigation')
    .mode(NavigationMode.Stack)
  }
}

// Navigation subpage
@Component
export struct PageOne {
  // NavDestination obtains the NavPathStack object through @Consume.
  @Consume('pathStack') pathStack: NavPathStack;

  build() {
    NavDestination() {
      // ...
    }
    .title('PageOne')
  }
}
```

**Method 2**: Use the [OnReady](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#onready11) callback.

<!-- @[router_2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Router2.ets) -->

``` TypeScript
@Entry
@Component
export struct PageOne {
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      // ...
    }.title('Method 2: PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

**Method 3**: Call the global AppStorage API.

<!-- @[router_3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Router3.ets) -->

``` TypeScript
@Entry
@Component
struct Index {
  pathStack: NavPathStack = new NavPathStack();

  // Set a NavPathStack object globally.
  aboutToAppear(): void {
    AppStorage.setOrCreate('PathStack', this.pathStack);
  }

  build() {
    Navigation(this.pathStack) {
      // ...
    }.title('Method 3: AppStorage')
    .mode(NavigationMode.Stack)
  }
}

// Navigation subpage
@Component
export struct PageOne {
  // The subpage obtains the global NavPathStack object.
  pathStack: NavPathStack = AppStorage.get('PathStack') as NavPathStack;

  build() {
    NavDestination() {
      // ...
    }
    .title('PageOne')
  }
}
```

**Method 4**: Call the custom component query API. For details, see [queryNavigationInfo](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#querynavigationinfo12).

<!-- @[router_4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Router4.ets) -->

``` TypeScript
// Custom component on the subpage
@Entry
@Component
struct CustomNode {
  pathStack: NavPathStack = new NavPathStack();

  aboutToAppear() {
    // query navigation info
    let navigationInfo: NavigationInfo = this.queryNavigationInfo() as NavigationInfo;
    if (navigationInfo !== undefined) {
      this.pathStack = navigationInfo.pathStack ;
    }
  }

  build() {
    Row() {
      Button('Method 4: queryNavigationInfo')
        .onClick(() => {
          this.pathStack.pushPath({ name: 'pageTwo' });
        })
    }
  }
}
```

## Lifecycle

> **NOTE**
>
> The relationship between the **Router** page lifecycle and the **Navigation** page lifecycle is as follows:
>
> 1. Navigating inside a **Router** page affects the lifecycle of the **Navigation** page contained within it.
>
> 2. Navigating inside a **Navigation** page does not affect the lifecycle of the enclosing **Router** page.
>
> 3. Foreground or background switching of the application triggers both the **Router** page lifecycle and the **Navigation** page lifecycle.

The [lifecycle](arkts-routing.md#lifecycle) of a **Router** page is managed by universal methods within the @Entry page, which mainly includes the following lifecycle events:

<!-- @[life_comm](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/lifeCycle/Comm.ets) -->

``` TypeScript
// Callback after the page is created and mounted to the tree
aboutToAppear(): void {
}

// Callback before the page is destroyed and unmounted
aboutToDisappear(): void {
}

// Callback when the page is displayed
onPageShow(): void {
}

// Callback when the page is hidden
onPageHide(): void {
}
```

The sequence of these lifecycle events is illustrated in the figure below.

![image](figures/router_page_lifecycle.png)

**Navigation**, as a routing container, hosts its lifecycle within the **NavDestination** component and exposes lifecycle events as component events.

For details about the lifecycle, see [Page Lifecycle](./arkts-navigation-navdestination.md#page-lifecycle).

<!-- @[life_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/lifeCycle/Index.ets) -->

``` TypeScript
@Entry
@Component
struct PageOne {
  aboutToDisappear() {
  }

  aboutToAppear() {
  }

  build() {
    NavDestination() {
      // ...
    }
    .onWillAppear(() => {
    })
    .onAppear(() => {
    })
    .onWillShow(() => {
    })
    .onShown(() => {
    })
    .onWillHide(() => {
    })
    .onHidden(() => {
    })
    .onWillDisappear(() => {
    })
    .onDisAppear(() => {
    })
  }
}
```

## Transition Animation

Both **Router** and **Navigation** offer built-in system transition animations as well as the capability to customize these animations.

For **Router**, custom page transition animations are implemented through the universal method **pageTransition()**. For details, see [Page Transition Animation](arkts-page-transition-animation.md).

For **Navigation**, a routing container component, page transition animations are essentially property animations between components. You can custom page transition animations through the [customNavContentTransition](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#customnavcontenttransition11) event in **Navigation**. For details, see [Defining a Custom Transition](./arkts-navigation-animation.md#defining-a-custom-transition). (Note that for Dialog-type pages, the default transition animations are available only since API version 13.)

## Shared Element Transition

To animate shared elements during page transitions with **Router**, use the **sharedTransition** API. For details, see

[Shared Element Transition](../reference/apis-arkui/arkui-ts/ts-transition-animation-shared-elements.md).

To animate shared elements during page transitions with **Navigation**, use the **geometryTransition** API. For details, see [Shared Element Transition](./arkts-navigation-animation.md#defining-a-shared-element-transition).

## Cross-Package Routing

To implement cross-package routing, with **Router**, use named routes.

1. In the [HAR](../quick-start/har-package.md) or [HSP](../quick-start/in-app-hsp.md) you want to navigate to, name the @Entry decorated custom component in [EntryOptions](../ui/state-management/arkts-create-custom-components.md#entry).

   <!-- @[router_hsp11](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Hsp11.ets) -->

   ``` TypeScript
   // library/src/main/ets/pages/Index.ets
   // library is the new custom name of the shared package.
   @Entry({ routeName: 'myPage' })
   @Component
   export struct MyComponent {
     build() {
       Row() {
         Column() {
           Text('Library Page')
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

2. To use the named route for redirection, you must configure dependencies in the **oh-package.json5** file of the application package. For example:

   ```ts
   "dependencies": {
       "library": "file:../library",
       // ...
   }
   ```

3. When the configuration is successful, import the named route page to the page from which you want to navigate and perform the navigation.

   <!-- @[router_hsp12](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Hsp12.ets) -->

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import('library/src/main/ets/pages/routerToNavigation/router/Index'); // Import the named route page from the library of the shared package.
   const DOMAIN = 0xF811;
   const TAG = '[Sample_ArkTSRouter]';
   
   @Entry
   @Component
   struct Index {
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         Text('Hello World')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .margin({ top: 20 })
           .backgroundColor('#ccc')
           .onClick(() => { // Click to go to a page in another shared package.
             this.getUIContext().getRouter().pushNamedRoute({
                 name: 'myPage',
                 params: {
                   data1: 'message',
                   data2: {
                     data3: [123, 456, 789]
                   }
                 }
               })
               .then(() => {
                 hilog.info(DOMAIN, TAG, 'pushNamedRoute succeeded.');
               })
               .catch((err: BusinessError) => {
                 let code = err.code;
                 let message = err.message;
                 hilog.error(DOMAIN, TAG,`pushNamedRoute failed, code is ${code}, message is ${message}`);
               });
           })
       }
       .width('100%')
       .height('100%')
     }
   }
   ```

As a routing component, **Navigation** natively supports cross-package navigation.

1. Develop the custom component (the target page to navigate to) in the HSP (HAR) and declare the custom component as export.

   <!-- @[router_hsp21](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Hsp21.ets) -->

   ``` TypeScript
   @Component
   export struct PageInHSP {
     build() {
       NavDestination() {
         // ...
       }
     }
   }
   ```

2. Export the component in the **Index.ets** file of the HSP (HAR).

   <!-- @[router_hsp22](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Hsp22.ets) -->

   ``` TypeScript
   export { PageInHSP } from './src/main/ets/pages/PageInHSP';
   ```

3. To use cross-package routing for redirection, you must configure dependencies in the **oh-package.json5** file of the application package. For example:

   ```ts
   "dependencies": {
       "library": "file:../library",
       // ...
   }
   ```

4. After configuring the project dependencies for the HSP (HAR), import the custom component into **mainPage** and add it to **pageMap** for normal use.

   <!-- @[router_hsp23](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/router/Hsp23.ets) -->

   ``` TypeScript
   // 1. Import the cross-package route page.
   import { PageInHSP } from 'library';
   
   @Entry
   @Component
   struct mainPage {
     pageStack: NavPathStack = new NavPathStack();
   
     @Builder pageMap(name: string) {
       if (name === 'PageInHSP') {
         // 2. Define the route mapping table.
         PageInHSP();
       }
     }
   
     build() {
       Navigation(this.pageStack) {
         Button('Push HSP Page')
           .onClick(() => {
             // 3. Navigate to the page in the HSP.
             this.pageStack.pushPath({ name: 'PageInHSP' });
           })
       }
       .mode(NavigationMode.Stack)
       .navDestination(this.pageMap)
     }
   }
   ```

In the above approaches, static dependencies are used for cross-package routing. In large-scale projects, inter-module development generally requires decoupling, which relies on the capability of dynamic routing.

## Dynamic Routing

Dynamic routing facilitates the reuse of service modules across different products (HAPs) and ensures module decoupling by using a routing table for transitions without interdependencies. It also streamlines the expansion and integration of routing features.

Business modules expose a set of pages for various scenarios, which are managed through a unified routing table. Products can register the routing tables of the required modules.

**Key Benefits of Dynamic Routing**

1. Route definitions can include not only the URL for navigation but also a variety of extended configurations, such as default orientation (landscape or portrait) and authentication requirements, for unified handling during routing.

2. Each route is assigned a name, allowing navigation by name rather than by file path, which simplifies the routing process.

3. Pages can be loaded using dynamic import (lazy loading), preventing the initial page from loading a large amount of code that could cause lag.

**Implementing Dynamic Routing with Router**

1. Definition: Add new routes to the routing table -> Bind page files to route names (decorators) -> Associate loading functions with page files (dynamic import functions).<br>

2. Registration: Register routes (inject the routing table of dependent modules as needed in the entry ability).<br>

3. Navigation: Check the routing table (for registered route names) -> Pre-routing hooks (dynamic import for page loading) -> Perform routing -> Post-routing hooks (common processing, such as tracking).

**Implementing Dynamic Routing with Navigation**

**Solution 1: Custom Routing Table**

The basic implementation is similar to the aforementioned dynamic routing with **Router**.

1. Create a custom routing management module, which is depended on by all modules providing routing pages.

2. When constructing the **Navigation** component, inject **NavPathStack** into the routing management module, which then encapsulates **NavPathStack** and provides routing capabilities.

3. Instead of providing components directly, each routing page offers a build function wrapped with [@Builder](../reference/apis-arkui/arkui-ts/ts-universal-builder-dynamic.md#builder), which is then further encapsulated with [WrappedBuilder](../reference/apis-arkui/arkui-ts/ts-universal-wrapBuilder.md#wrappedbuilder) for global encapsulation.

4. Each routing page registers its module name, route name, and the **WrappedBuilder**-encapsulated build function with the routing management module.

5. The routing management module completes dynamic imports and route transitions as needed.

<!--RP1--><!--RP1End-->

**Solution 2: System Routing Table**

Starting from API version 12, **Navigation** supports a system-level cross-module routing table solution. The overall design delegates route table management to the system: each business module (HSP/HAR) that requires routing independently configures a `router_map.json` file. When a route navigation is triggered, the app only needs to call **NavPathStack** to perform the navigation. The system then automatically completes dynamic loading of the routing module, component construction, and route navigation, thereby achieving module decoupling at the development level.

For details, see [System Routing Table](./arkts-navigation-cross-package.md#system-routing-table).

## Lifecycle Listening

You can use the observer to register a listening for the lifecycle events with the **Router**. For details about the APIs, see [uiObserver.on('routerPageUpdate')](../reference/apis-arkui/js-apis-arkui-observer.md#uiobserveronrouterpageupdate11).

<!-- @[observer_comm](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/observer/Comm.ets) -->

``` TypeScript
import { UIContext, uiObserver } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
const DOMAIN = 0xF811;
const TAG = '[Sample_ArkTSRouter]';

function callbackFunc(info: uiObserver.RouterPageInfo) {
  hilog.info(DOMAIN, TAG,'RouterPageInfo is : ' + JSON.stringify(info));
}

// used in ability context.
uiObserver.on('routerPageUpdate', this.context, callbackFunc);

// used in UIContext.
uiObserver.on('routerPageUpdate', this.getUIContext(), callbackFunc);
```

A registered callback is invoked when there is a change in the page state. You can obtain relevant page information such as the page name, index, path, and lifecycle status through the parameters passed to the callback.

**Navigation** also allows you to register for lifecycle events through the observer.

<!-- @[observer_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/observer/Index.ets) -->

``` TypeScript
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { UIObserver, window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
const DOMAIN = 0xF811;
const TAG = '[Sample_ArkTSRouter]';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // ...
    windowStage.getMainWindow((err: BusinessError, data) => {
      // ...
      let windowClass = data;
      // Obtain the UIContext instance.
      let uiContext: UIContext = windowClass.getUIContext();
      // Obtain the UIObserver instance.
      let uiObserver : UIObserver = uiContext.getUIObserver();
      // Register the status listener for NavDestination.
      uiObserver.on('navDestinationUpdate',(info) => {
        // NavDestinationState.ON_SHOWN = 0, NavDestinationState.ON_HIDE = 1
        if (info.state === 0) {
          // Actions to perform when the NavDestination component is shown.
          hilog.info(DOMAIN, TAG, 'page ON_SHOWN:' + info.name.toString());
        }
      });
    });
  }
}
```

## Page Information Query

To achieve decoupling between custom components and their containing pages, a global API for querying page information is provided within custom components.

With **Router**, you can use the [queryRouterPageInfo](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#queryrouterpageinfo12) API to query information about the current page where the custom component resides. The return value includes the following properties, with **pageId** being the unique ID for the page.

| Name                | Type                       | Mandatory| Description                          |
| -------------------- | --------------------------- | ---- | ------------------------------ |
| context              | UIAbilityContext/ UIContext | Yes  | Context information of the page.|
| index                | number                      | Yes  | Position of the page in the stack.      |
| name                 | string                      | Yes  | Name of the page.        |
| path                 | string                      | Yes  | Path of the page.        |
| state                | RouterPageState             | Yes  | Status of the page.          |
| pageId<sup>12+</sup> | string                      | Yes  | Unique ID of the routerPage page.      |

<!-- @[observer_pageinfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/observer/PageInfo.ets) -->

``` TypeScript
import { uiObserver } from '@kit.ArkUI';

// Custom component on the page
@Component
struct MyComponent {
  aboutToAppear() {
    let info: uiObserver.RouterPageInfo | undefined = this.queryRouterPageInfo();
  }

  build() {
    // ...
  }
}
```

With **Navigation**, you can use the [queryNavDestinationInfo](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#querynavdestinationinfo) API to query information about the current page where the custom component resides. The return value includes the following properties, with **navDestinationId** being the unique ID for the page.

| Name                         | Type               | Mandatory| Description                                        |
| ----------------------------- | ------------------- | ---- | -------------------------------------------- |
| navigationId                  | ResourceStr         | Yes  | ID of the **Navigation** component that contains the target **NavDestination** component.|
| name                          | ResourceStr         | Yes  | Name of the **NavDestination** component.                  |
| state                         | NavDestinationState | Yes  | State of the **NavDestination** component.                  |
| index<sup>12+</sup>            | number              | Yes   | Index of NavDestination in the route stack.             |
| param<sup>12+</sup>            | Object              | No   | Parameter of the NavDestination component.                   |
| navDestinationId<sup>12+</sup> | string              | Yes   | Unique ID of the NavDestination component.             |

<!-- @[observer_query](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Navigation/entry/src/main/ets/pages/routerToNavigation/observer/QueryNav.ets) -->

``` TypeScript
import { uiObserver } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
const DOMAIN = 0xF811;
const TAG = '[Sample_ArkTSRouter]';

@Component
export struct NavDestinationExample {
  build() {
    NavDestination() {
      MyComponent();
    }
  }
}

@Component
struct MyComponent {
  navDesInfo: uiObserver.NavDestinationInfo | undefined;

  aboutToAppear() {
    this.navDesInfo = this.queryNavDestinationInfo();
    hilog.info(DOMAIN, TAG, 'get navDestinationInfo: ' + JSON.stringify(this.navDesInfo));
  }

  build() {
    // ...
  }
}
```

## Route Interception

**Router** does not provide route interception, so you must implement it by creating custom routing APIs for redirection and interception logic.

**Navigation** provides the [setInterception](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#setinterception12) API for setting callbacks to intercept page navigation. For details, see [Route Interception](./arkts-navigation-jump.md#route-interception).

<!--no_check-->