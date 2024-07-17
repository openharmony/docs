# Transition from Router to Navigation

## Architectural Differences

From the perspective of the ArkUI component tree hierarchy, pages that were originally managed by Router are located under the stage management node of the page stack. Navigation, as a navigation container component, can be mounted under a single page node and can also be stacked and nested. Navigation manages the title bar, content area, and toolbar, with the content area used to display the content of user-defined pages and supports page routing capabilities. The design of Navigation has the following advantages:

![image](figures/navigation-and-router-architecture.png)

1. The interface explicitly distinguishes the title bar, content area, and toolbar, enabling more flexible management and UX animation capabilities.

2. It provides the concept of a routing container, allowing developers to decide the location of the routing container, supporting display in full modal, semi-modal, and pop-up windows.

3. It integrates UX design and multi-view capabilities, providing unified title display, page switching, and single-column and dual-column adaptation capabilities by default.

4. Based on the general UIBuilder capability, developers decide the page alias and page UI correspondence, offering more flexible page configuration capabilities.

5. Based on component attribute animations and shared element animation capabilities, page switching animations are implemented as component attribute animations, providing richer and more flexible transition effects.

6. The page stack object is exposed, allowing developers to inherit it for better management of page display.

## Capability Comparison

| Service Scenario | Navigation | Router |
| --- | --- | --- |
| One-to-many capability | Supported. Auto mode adapts to single-column and double-column display | Not supported |
| Navigate to a specific page | pushPath & pushDestination | pushUrl & pushNameRoute |
| Navigate to a page in HSP | Supported | Supported |
| Navigate to a page in HAR | Supported | Supported |
| Pass parameters during navigation | Supported | Supported |
| Obtain parameters of specified pages | Supported | Not supported |
| Parameter passing type | Parameters passed as an object | Parameters passed as an object, methods in the object are not supported temporarily |
| Callback for navigation result | Supported | Supported |
| Navigate to a singleton page | Not supported | Supported |
| Page return | Supported | Supported |
| Pass parameters on page return | Supported | Supported |
| Return to a specific route | Supported | Supported |
| Page return pop-up | Supported, implemented through route interception | showAlertBeforeBackPage |
| Route replacement | replacePath & replacePathByName | replaceUrl & replaceNameRoute |
| Clear route stack | clear | clear |
| Clear a specific route | removeByIndexes & removeByName | Not supported |
| Transition animation | Supported | Supported |
| Custom transition animation | Supported | Supported, limited animation types |
| Disable transition animation | Support global and single | Support setting pageTransition method duration to 0 |
| geometryTransition shared element animation | Supported (shared between NavDestinations) | Not supported |
| Page lifecycle listener | UIObserver.on('navDestinationUpdate') | UIObserver.on('routerPageUpdate') |
| Get page stack object | Supported | Not supported |
| Route interception | Supported through setInterception | Not supported |
| Query route stack information | Supported | getState() & getLength() |
| Route stack move operation | moveToTop & moveIndexToTop | Not supported |
| Immersive pages | Supported | Not supported, need to be configured through window |
| Set page title bar (titlebar) and toolbar (toolbar) | Supported | Not supported |
| Modal embedded routing | Supported | Not supported |

## Switching Guidance

### Page Structure

Pages of Router routing are Components decorated with `@Entry`, and each page needs to be declared in `main_page.json`.

```json
// main_page.json
{
  "src": [
    "pages/Index",
    "pages/pageOne",
    "pages/pageTwo"
  ]
}
```

The following is an example of a Router page:

```ts
// index.ets
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

In contrast, routing pages based on Navigation are divided into navigation pages and child pages. Navigation pages, also known as Navbars, are child components contained in Navigation, and child pages are child components contained in NavDestination.

The following is an example of a Navigation navigation page:

```ts
// index.ets
@Entry
@Component
struct Index {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    Navigation(this.pathStack) {
      Column() {
        Button('Push PageOne', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.pushPathByName('pageOne', null)
          })
      }.width('100%').height('100%')
    }
    .title("Navigation")
  }
}
```

The following is an example of a Navigation child page:

```ts
// PageOne.ets

@Builder
export function PageOneBuilder() {
  PageOne()
}

@Component
export struct PageOne {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    NavDestination() {
      Column() {
        Button('Go Back to Home', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.clear()
          })
      }.width('100%').height('100%')
    }.title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack
    })
  }
}
```

Each child page also needs to be configured in the system configuration file `route_map.json` (see [System Routing Table](arkts-navigation-navigation.md#system-routing-table)):

```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5
// route_map.json
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

### Router Operations

Router operates pages through methods provided by the `@ohos.router` module, which need to be imported first:

```ts
import router from '@ohos.router';

// push page
router.pushUrl({ url:"pages/pageOne", params: null })

// pop page
router.back({ url: "pages/pageOne" })

// replace page
router.replaceUrl({ url: "pages/pageOne" })

// clear all page
router.clear()

// Get the size of the page stack
let size = router.getLength()

// Get the state of the page stack
let pageState = router.getState()
```

Navigation operates pages through methods provided by the page stack object [NavPathStack](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navpathstack10). You need to create a stack object and pass it to Navigation:

```ts
@Entry
@Component
struct Index {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    // Set NavPathStack and pass it to Navigation
    Navigation(this.pathStack) {
        ...
    }.width('100%').height('100%')
  }
  .title("Navigation")
}


// push page
this.pathStack.pushPath({ name: 'pageOne' })

// pop page
this.pathStack.pop()
this.pathStack.popToIndex(1)
this.pathStack.popToName('pageOne')

// replace page
this.pathStack.replacePath({ name: 'pageOne' })

// clear all page
this.pathStack.clear()

// Get the size of the page stack
let size = this.pathStack.size()

// Remove all pages with the name 'PageOne' from the stack
this.pathStack.removeByName("pageOne")

// Remove the page at the specified index
this.pathStack.removeByIndexes([1,3,5])

// Get a collection of all page names in the stack
this.pathStack.getAllPathName()

// Get the parameters of the page at index 1
this.pathStack.getParamByIndex(1)

// Get the parameters of the 'PageOne' page
this.pathStack.getParamByName("pageOne")

// Get the index collection of the 'PageOne' page
this.pathStack.getIndexByName("pageOne")
...
```

Router, as a global common module, can be called in any page. In contrast, Navigation, as a component, requires child pages to obtain the page stack object NavPathStack held by Navigation to perform routing. This can be done in several ways:

**Method One**: Passing to child pages through `@Provide` and `@Consume` (coupling, not recommended);

```ts
// Navigation root container
@Entry
@Component
struct Index {
  // Navigation creates a NavPathStack with @Provide
 @Provide('pathStack') pathStack: NavPathStack

  build() {
    Navigation(this.pathStack) {
        ...
      }.width('100%').height('100%')
    }
    .title("Navigation")
  }
}

// Navigation child page
@Component
export struct PageOne {
  // NavDestination gets it through @Consume
  @Consume('pathStack') pathStack: NavPathStack;

  build() {
    NavDestination() {
      ...
    }
    .title("PageOne")
  }
}
```

**Method Two**: Child page obtains it through the `OnReady` callback;

```ts
@Component
export struct PageOne {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    NavDestination() {
      ...
    }.title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack
    })
  }
}
```

**Method Three**: Obtained through the global `AppStorage` interface;

```ts
@Entry
@Component
struct Index {
  pathStack: NavPathStack = new NavPathStack()

  // Globally set a NavPathStack
  aboutToAppear(): void {
     AppStorage.setOrCreate("PathStack", this.pathStack)
   }

  build() {
    Navigation(this.pathStack) {
        ...
      }.width('100%').height('100%')
    }
    .title("Navigation")
  }
}

// Navigation child page
@Component
export struct PageOne {
  // Child page gets the global NavPathStack
  pathStack: NavPathStack = AppStorage.get("PathStack") as NavPathStack

  build() {
    NavDestination() {
      ...
    }
    .title("PageOne")
  }
}
```

**Method Four**: Obtained through the custom component query interface (refer to [Custom Component Method](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#querynavigationinfo12));

```ts
import observer from '@ohos.arkui.observer';

// Custom component in the child page
@Component
struct CustomNode {
  pathStack : NavPathStack = new NavPathStack()

  aboutToAppear() {
    // query navigation info
    let  navigationInfo : NavigationInfo = this.queryNavigationInfo() as NavigationInfo
    this.pathStack = navigationInfo.pathStack;
  }

  build() {
    Row() {
      Button('Go to PageTwo')
        .onClick(()=>{
          this.pathStack.pushPath({ name: 'pageTwo' })
        })
    }
  }
}
```

### Lifecycle

The lifecycle of Router pages is a general method in the `@Entry` page, mainly including the following four lifecycles:

```ts
// Callback after the page is created and mounted
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

The lifecycle sequence is shown in the following figure:

![image](figures/router_page_lifecycle.png)

Navigation, as a routing container, carries its lifecycle on the NavDestination component, which is opened in the form of component events.
For a detailed description of the lifecycle, see [Navigation Lifecycle](arkts-navigation-navigation.md#page-lifecycle).

```ts
@Component
struct PageOne {

  aboutToDisappear() {
  }

  aboutToAppear() {
  }

  build() {
    NavDestination() {
      ...
    }
    .onWillAppear(()=>{
    })
    .onAppear(()=>{
    })
    .onWillShow(()=>{
    })
    .onShown(()=>{
    })
    .onWillHide(()=>{
    })
    .onHidden(()=>{
    })
    .onWillDisappear(()=>{
    })
    .onDisAppear(()=>{
    })
  }
}
```

### Transition Animation

Both Router and Navigation provide system transition animations and also provide the ability to customize transitions.

The custom page transition of Router is implemented through the general method `pageTransition()`, which can be referred to:
[Router Custom Transition Animation](arkts-page-transition-animation.md)

Navigation, as a routing container component, essentially belongs to the property animation between components for the page switching animation inside. It can provide the ability to customize the transition animation through the [customNavContentTransition](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#customnavcontenttransition11) event in Navigation. The specific implementation can refer to the following guidance:
[Navigation Custom Transition Animation](arkts-navigation-navigation.md#custom-transition) (Note: The pages of the Dialog type currently do not have transition animations)

### Shared Element Transition

When pages transition between each other, shared element transition animations are required. Router can achieve shared element transitions through the general property `sharedTransition`, which can be referred to as follows:
[Router Shared Element Transition Animation](../reference/apis-arkui/arkui-ts/ts-transition-animation-shared-elements.md)

Navigation also provides the ability to transition with shared elements in one shot, which needs to be coordinated with the `geometryTransition` property. When switching between child pages (NavDestination), shared element transitions can be achieved, which can be referred to as follows: [Navigation Shared Element Transition Animation](arkts-navigation-navigation.md#shared-element-transition)

### Cross-Package Routing

Router can achieve cross-package jumping through the way of naming routes.

1. Name the custom component in the shared package [HAR](../quick-start/har-package.md) or [HSP](../quick-start/in-app-hsp.md) page you want to jump to:

```typescript
// library/src/main/ets/pages/Index.ets
// library is the custom name of the newly created shared package
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

2. After the configuration is successful, you need to import the named route page in the page you want to jump to and jump:

```ts
import router from '@ohos.router';
import { BusinessError } from '@ohos.base';
import('library/src/main/ets/pages/Index');  // Import the named route page in the shared package

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
        .onClick(() => { // Click to jump to the page in another shared package
          try {
            router.pushNamedRoute({
              name: 'myPage',
              params: {
                data1: 'message',
                data2: {
                  data3: [123, 456, 789]
                }
              }
            })
          } catch (err) {
            let message = (err as BusinessError).message
            let code = (err as BusinessError).code
            console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

Navigation, as a routing component, supports cross-package jumping by default.

1. Complete the development of the custom component (the target page to be jumped to) from HSP (HAR) and declare the custom component as export;

```ts
@Component
export struct PageInHSP {
  build() {
    NavDestination() {
        ...
    }
  }
}
```

2. Export the component in the index.ets of HSP (HAR)

```ts
export { PageInHSP } from "./src/main/ets/pages/PageInHSP"
```

3. After configuring the project dependencies of HSP (HAR), import the custom component in the mainPage and add it to the pageMap to call it normally.

```ts
// 1. Import the cross-package routing page
import { PageInHSP } from 'library/src/main/ets/pages/PageInHSP'

@Entry
@Component
struct mainPage {
 pageStack: NavPathStack = new NavPathStack()

 @Builder pageMap(name: string) {
   if (name === 'PageInHSP') {
	 // 2. Define the route mapping table
	 PageInHSP()
   }
 }
 build() {
   Navigation(this.pageStack) {
	 Button("Push HSP Page")
	   .onClick(() => {
		  // 3. Navigate to a page in the HSP.
		  this.pageStack.pushPath({ name: "PageInHSP"});
	 })
   }
   .navDestination(this.pageMap)
 }
}

```

The above was accomplished through the form of **static dependency** for cross-package routing. In large-scale projects, inter-module development generally requires decoupling, which necessitates the capability of **dynamic routing**.

### Dynamic Routing

The purpose of dynamic routing design is to address the reusability of the same business modules between multiple products (Hap), decoupling between various business modules (navigation between modules is achieved through a routing table without mutual dependency), and the integration and expansion of routing functions.

The business feature module exposes a collection of multiple pages that support the completion of specific business scenarios; routing management is about managing each module's supported pages with a unified routing table structure. When a product needs a certain business module, it will register the corresponding module's routing table.

**Advantages of Dynamic Routing:**

1. In addition to the URL for navigation, the routing definition can be enriched with any extended information, such as default landscape or portrait mode, whether authentication is required, etc., for unified processing during route navigation.
2. Assign a name to each route, and navigate by name rather than file paths.
3. Page loading can use dynamic Import (load on demand) to prevent the initial page from loading a large amount of code, which could cause lag.

**The implementation of dynamic routing by Router mainly involves the following three processes:**

1. Definition Process: Define new routes in the routing table -> Bind page files to route names (decorators) -> Bind loading functions and page files (dynamic import functions)
2. Definition Registration Process: Route registration (can be injected with the routing table of dependent modules in the entry ability as needed).
3. Navigation Process: Routing table check (whether the corresponding route name has been registered) -> Pre-route hook (dynamic Import for route page loading) -> Route navigation -> Post-route hook (common processing, such as logging).

**Navigation implements dynamic routing in the following two ways:**

**Plan One:** Custom Routing Table

The basic implementation is similar to the aforementioned Router dynamic routing.
1. Developers customize a routing management module, and all modules that provide routing pages depend on this module.
2. When building the Navigation component, inject the NavPathStack into the routing management module, which encapsulates the NavPathStack and provides routing capabilities externally.
3. Each routing page no longer provides components but instead provides a construction function wrapped with @build, and then encapsulates it again through WrappedBuilder to achieve global encapsulation.
4. Each routing page registers the module name, route name, and WrappedBuilder-wrapped construction function in the routing module.
5. When routing needs to navigate to a specified route, the routing module completes the dynamic import of the specified routing module and completes the route navigation.

For the specific construction process, you can refer to the [Navigation Dynamic Routing Example](https://gitee.com/harmonyos-cases/cases/blob/master/CommonAppDevelopment/common/routermodule/README_AUTO_GENERATE.md).

**Plan Two:** System Routing Table

Starting from API version 12, Navigation supports a system-wide cross-module routing table solution. The overall design is to manage the routing table scheme within the system, i.e., independently configure the `router_map.json` file in each business module (HSP/HAR) that requires routing. When triggering route navigation, the application only needs to perform route navigation through `NavPathStack`, at which point the system will automatically complete the dynamic loading of the routing module, component construction, and complete the route navigation function, thus achieving module decoupling at the development level.
For more details, see [Navigation System Routing](arkts-navigation-navigation.md#system-routing-table).

### Lifecycle Listening

Router can implement registration listening through observer, and the interface definition can be referred to: [Router Seamless Listening](../reference/apis-arkui/js-apis-arkui-observer.md#observeronrouterpageupdate11).

```ts
import observer from '@ohos.arkui.observer';

function callBackFunc(info: observer.RouterPageInfo) {
    console.info("RouterPageInfo is : " + JSON.stringify(RouterPageInfo))
}

// used in ability context.
observer.on('routerPageUpdate', this.context, callBackFunc);

// used in UIContext.
observer.on('routerPageUpdate', this.getUIContext(), callBackFunc);
```
When the state of a page changes, the registered callback will be triggered, allowing developers to obtain information about the page through the parameters passed in the callback, such as the page's name, index, path, lifecycle state, etc.

Navigation can also implement registration and listening within an observer.

```ts
export default class EntryAbility extends UIAbility {
  ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    ...
    windowStage.getMainWindow((err: BusinessError, data) => {
      ...
      windowClass = data;
      // Obtain the UIContext instance.
      let uiContext: UIContext = windowClass.getUIContext();
      // Obtain the UIObserver instance.
      let uiObserver : UIObserver = uiContext.getUIObserver();
      // Register the state listening for DevNavigation.
      uiObserver.on("navDestinationUpdate",(info) => {
        // NavDestinationState.ON_SHOWN = 0, NavDestinationState.ON_HIDE = 1
        if (info.state == 0) {
          // Operations when the NavDestination component is shown
          console.info('page ON_SHOWN:' + info.name.toString());
        }
      })
    })
  }
}
```


### Page Information Query

To achieve decoupling between custom components and the page itself, a global interface for querying page information is provided within the custom components.

The Router can query information about the current Page page where the custom component resides through the [queryRouterPageInfo](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#queryrouterpageinfo12) interface. The returned value includes the following properties, where pageId is the unique identifier of the page:

| Name          | Type                                                                                                                                                                                                                                                                 | Required | Description                                   |
| -------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------- | --------------------------------------------- |
| context       | UIAbilityContext / UIContext                                                                                                                                                                                                                                                     | Yes      | The context information corresponding to the routerPage page. |
| index         | number                                                                                                                                                                                                                                                                                           | Yes      | The position of the routerPage in the stack. |
| name          | string                                                                                                                                                                                                                                                                                           | Yes      | The name of the routerPage page.            |
| path          | string                                                                                                                                                                                                                                                                                           | Yes      | The path of the routerPage page.            |
| state         | RouterPageState                                                                                                                                                                                                                                                                        | Yes      | The state of the routerPage page.          |
| pageId<sup>12+</sup> | string                                                                                                                                                                                                                                                                                           | Yes      | The unique identifier of the routerPage page. |

```ts
import observer from '@ohos.arkui.observer';

// Custom component within the page
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

Navigation can also query information about the current NavDestination where the custom component resides through the [queryNavDestinationInfo](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#querynavdestinationinfo) interface. The returned value includes the following properties, where navDestinationId is the unique identifier of the page:

| Name                    | Type                                                                                                                                                      | Required | Description                                                                                                                |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------- | -------------------------------------------------------------------------------------------------------------------------- |
| navigationId            | ResourceStr                                                                                                                                                | Yes      | The id of the Navigation component containing the NavDestination component. |
| name                    | ResourceStr                                                                                                                                                | Yes      | The name of the NavDestination component.          |
| state                   | NavDestinationState                                                                                                                                        | Yes      | The state of the NavDestination component.              |
| index<sup>12+<sup>            | number                                                                                                                                                      | Yes      | The index of NavDestination in the page stack.                                                                                    |
| param<sup>12+<sup>            | Object                                                                                                                                                      | No       | The parameters of the NavDestination component.                                                                                         |
| navDestinationId<sup>12+<sup> | string                                                                                                                                                      | Yes      | The unique identifier ID of the NavDestination component.                                                                                    |

```ts
import observer from '@ohos.arkui.observer';

@Component
export struct NavDestinationExample {
  build() {
    NavDestination() {
      MyComponent()
    }
  }
}

@Component
struct MyComponent {
  navDesInfo: observer.NavDestinationInfo | undefined

  aboutToAppear() {
    this.navDesInfo = this.queryNavDestinationInfo();
    console.log('get navDestinationInfo: ' + JSON.stringify(this.navDesInfo))
  }

  build() {
    // ...
  }
}
```

### Routing Interception

Router does not natively provide the capability for routing interception, developers need to encapsulate the routing interface themselves, and within their encapsulated interface, they should make judgments for routing interception and redirect the routing.

Navigation provides the [setInterception](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#setinterception12) method, which is used to set the callback for intercepting page navigation transitions. For more details, you can refer to the document: [Navigation Routing Interception](arkts-navigation-navigation.md#routing-interception).
<!--no_check-->