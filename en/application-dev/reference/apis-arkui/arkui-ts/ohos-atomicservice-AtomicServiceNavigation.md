# AtomicServiceNavigation

**AtomicServiceNavigation** is a component that serves as the root container of a page. By default, it includes a title bar, content area, and toolbar. The content area switches between the home page content (child components of [NavDestination](ts-basic-components-navdestination.md)) and non-home page content through routing.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import { AtomicServiceNavigation } from '@kit.ArkUI';
```

## Child Components

Supported
Since API version 10, you are advised to use [NavPathStack](ts-basic-components-navigation.md#navpathstack10) for page routing.
## AtomicServiceNavigation

```
AtomicServiceNavigation({
    navPathStack?: NavPathStack,
    navigationContent: Callback<void>,
    title?: ResourceStr,
    titleOptions?: TitleOptions,
    gradientBackground?: GradientBackground,
    hideTitleBar?: boolean,
    navBarWidth?: Length,
    mode?: NavigationMode,
    navDestinationBuilder?: NavDestinationBuilder,
    navBarWidthRange?: [Dimension, Dimension],
    minContentWidth?: Dimension,
    sideBarOptions?: sideBarOptions,
    sideBarContent?: Callback<void>,
    menus?:	CustomBuilder | Array<NavigationMenuItem>,
    stateChangeCallback?: Callback<boolean>,
    modeChangeCallback?: Callback<NavigationMode>
})
```

**Atomic service API**: This API can be used in atomic services since API version 12.

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Decorator|Description|
| --------------- | ------ | ---- | ----|----------|
| navPathStack | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | No| @State | Information about the navigation stack.|
| navigationContent | Callback\<void\> | No| @BuilderParam | Content of the navigation container.|
| title | [ResourceStr](ts-types.md#resourcestr) | No|@Prop | Page title.|
| titleOptions | [TitleOptions](#titleoptions) | No| @Prop | Title bar options.|
| gradientBackground<sup>18+</sup> | [GradientBackground](#gradientbackground18) | No| @Prop | Background color options.|
| hideTitleBar | boolean | No| @Prop | Whether to hide the title bar.|
| navBarWidth | [Length](ts-types.md#length)| No| @Prop | Width of the navigation bar.<br>This attribute takes effect only when the component is split.|
| mode| [NavigationMode](ts-basic-components-navigation.md#navigationmode9)| No| @Prop |Display mode of the navigation bar.<br>Available options are **Stack**, **Split**, and **Auto**.|
| navDestinationBuilder | [NavDestinationBuilder](#navdestinationbuilder) | No| @BuilderParam | Builder data required for creating the [NavDestination](ts-basic-components-navdestination.md) component.|
| navBarWidthRange | [[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)] | No| @Prop |Minimum and maximum widths of the navigation bar (effective in dual-column mode).|
| minContentWidth | [Dimension](ts-types.md#dimension10) | No| @Prop | Minimum width of the navigation bar content area (effective in dual-column mode).|
| sideBarOptions<sup>18+</sup> | [SideBarOptions](#sidebaroptions18) | No| @Prop | Sidebar options.|
| sideBarContent<sup>18+</sup> | Callback\<void\> | No| @BuilderParam | Content of the sidebar.|
| menus<sup>18+</sup> | [CustomBuilder](ts-types.md#custombuilder8) \| Array\<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)\> | No| @BuilderParam | Custom layouts for wide-screen scenarios. The default value is empty, with no styles displayed.|
| stateChangeCallback | Callback\<boolean\> | No| - | Callback invoked when the navigation bar visibility status changes.|
| modeChangeCallback | Callback\<[NavigationMode](ts-basic-components-navigation.md#navigationmode9)\>| No| - | Callback invoked when the component is displayed for the first time or its display mode switches between single-column and dual-column.|

## TitleOptions
Title bar options.
**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| --------------- | ------ | ---- | ---------- |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | No| Background color of the title bar.|
| isBlurEnabled | boolean | No| Whether the title bar is blurred.<br>Default value: **true**|
| barStyle | [BarStyle](ts-basic-components-navigation.md#barstyle12)  | No| Style options of the title bar.|
| titleBarType<sup>18+</sup> | [TitleBarType](#titlebartype18) | No| Type of the title bar. <br>Default value: **TitleBarType.ROUND_ICON**|
| titleIcon<sup>18+</sup> | [Resource](ts-types.md#resource) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No| Icon of the title bar. Default value: **$r('sys.color.ohos_id_color_titlebar_icon')**|

## GradientBackground<sup>18+</sup>
Provides options for setting gradient colors for branding.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| --------------- | ------ | ---- | ---------- |
| primaryColor | [ResourceColor](ts-types.md#resourcecolor)  | Yes| Color value for single-color gradients and the first color in dual-color gradients.<br> No default value.|
| secondaryColor |[ResourceColor](ts-types.md#resourcecolor)  | No|Second color in dual-color gradients.<br> No default value.|
| backgroundTheme |[BackgroundTheme<sup>18+</sup>](#backgroundtheme18)  | No|Background theme of the navigation bar. <br>Default value: **DEFAULT**|
| mixMode | [MixMode<sup>18+</sup>](#mixmode18)  | No|How the two colors blend in dual-color gradients. It is effective only when both **primaryColor** and **secondaryColor** are set. <br>Default value: **TOWARDS**|
| alpha | [GradientAlpha<sup>18+</sup>](#gradientalpha18)  | No|Transparency level for the gradient display area. <br>Default value: **OPACITY_20**|

## NavDestinationBuilder

type NavDestinationBuilder = (name: string, param?: Object) => void

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
    
| Name| Type| Mandatory| Description|
| --------------- | ------ | ---- | ---------- |
| name | string | Yes| Name of the [NavDestination](ts-basic-components-navdestination.md) page.|
| param | Object | Yes| Settings of the [NavDestination](ts-basic-components-navdestination.md) page.|

## MixMode<sup>18+</sup>
Provides options for background color blending modes.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| --------------- | ------ |-----|
| AVERAGE  | 1 | Both colors are evenly mixed. |
| CROSS  | 2 | One color passes through the other.|
| TOWARDS  | 3 | One color gradually blends into the other.|

## TitleBarType<sup>18+</sup>
Enumerates the title bar types. The default type is **ROUND_ICON**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| --------------- | ------ |-----|
| SQUARED_ICON  | 1 | Square icon style.|
| ROUND_ICON | 2 | Round icon style.|
| DRAWER | 3 | Drawer style.|

## GradientAlpha<sup>18+</sup>
Enumerates the transparency levels of the navigation bar background.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| --------------- | ------ |-----|
| OPACITY_20| 1 | Transparency level of 0.2.|
| OPACITY_60| 2 | Transparency level of 0.6.|
| OPACITY_80| 3 | Transparency level of 0.8.|
| OPACITY_100| 4 | Transparency level of 1.0.|

## BackgroundTheme<sup>18+</sup>
Enumerates the navigation bar background themes.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| --------------- | ------ |-----|
| DARK  | 1 | Dark theme.|
| LIGHT  | 2 | Light theme.|
| DEFAULT  | 3 | Light gray theme, with the color value of #F1F3F5.|

## SideBarOptions<sup>18+</sup>
Provides sidebar options.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| --------------- | ------ | ---- | ---------- |
| sideBarBackground | [ResourceColor](ts-types.md#resourcecolor) | No| Background color of the sidebar. <br>Default value: **$r('sys.color.ohos_id_color_sub_background')**|
| onChange | Callback\<boolean\> | No| Callback triggered when the sidebar is shown or hidden.|
| sideBarIcon | [Resource](ts-types.md#resource) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No| Icon of the sidebar. Default value: **$r('sys.symbol.open_sidebar')**|

## Example

### Example 1: Setting the Layout and Gradient Background
This example demonstrates how to set the basic style of the **AtomicServiceNavigation** component with a gradient background.

```ts
import { AtomicServiceNavigation, NavDestinationBuilder, AtomicServiceTabs, TabBarOptions, TabBarPosition } from '@kit.ArkUI';
import { MixMode, GradientAlpha, BackgroundTheme} from '@ohos.atomicservice.AtomicServiceNavigation'
@Entry
@Component
struct Index {
  @State message: string = 'Title';
  childNavStack: NavPathStack = new NavPathStack();
  @Builder
  tabContent1() {
    Text('first page')
      .onClick(() => {
        this.childNavStack.pushPath({ name: 'page one' })
      })
  }

  @Builder
  tabContent2() {
    Text('second page')
  }

  @Builder
  tabContent3() {
    Text('third page')
  }

  @Builder
  navigationContent() {
    AtomicServiceTabs({
      tabContents: [
        () => {
          this.tabContent1()
        },
        () => {
          this.tabContent2()
        },
        () => {
          this.tabContent3()
        }
      ],
      tabBarOptionsArray: [
        new TabBarOptions($r('sys.media.ohos_ic_public_phone'), 'Feature 1'),
        new TabBarOptions($r('sys.media.ohos_ic_public_location'), 'Feature 2', Color.Green, Color.Red),
        new TabBarOptions($r('sys.media.ohos_ic_public_more'), 'Feature 3')
      ],
      tabBarPosition: TabBarPosition.BOTTOM,
      barBackgroundColor: $r('sys.color.ohos_id_color_bottom_tab_bg'),
      onTabBarClick: (index: Number) => {
        if (index == 0) {
          this.message = 'Feature 1';
        } else if (index == 1) {
          this.message = 'Feature 2';
        } else {
          this.message = 'Feature 3';
        }
      }
    })
  }

  @Builder
  pageMap(name: string) {
    if (name === 'page one') {
      PageOne()
    } else if (name === 'page two') {
      PageTwo()
    }
  }

  build() {
    Row() {
      Column() {
        AtomicServiceNavigation({
          navigationContent: () => {
            this.navigationContent()
          },
          title: this.message,
          titleOptions: {
            isBlurEnabled: false
          },
          gradientBackground: {
            primaryColor: 'red',
            secondaryColor: 'green',
            backgroundTheme: BackgroundTheme.LIGHT,
            mixMode: MixMode.AVERAGE,
            alpha: GradientAlpha.OPACITY_100
          },
          navDestinationBuilder: this.pageMap,
          navPathStack: this.childNavStack,
          mode: NavigationMode.Stack
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
export struct PageOne {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('Next')
        .onClick(() => {
          this.pageInfo.pushPath({ name: 'page two'})
        })
    }
    .title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@Component
export struct PageTwo {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('End')
    }
    .title('PageTwo')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}
```

![](figures/AtomicServiceNavigationDemo02.jpg)

### Example 2: Implementing the Drawer Style with Custom Layouts for Wide-Screen Scenarios

This example demonstrates how to implement the drawer style and insert custom layouts into the title bar in wide-screen scenarios (width > 600 vp).

```ts
import { AtomicServiceNavigation, TitleBarType } from '@kit.ArkUI';
import { AtomicServiceTabs, TabBarOptions, TabBarPosition } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  childNavStack: NavPathStack = new NavPathStack();

  @Builder
  tabContent1() {
    Text('First page')
      .onClick(() => {
        this.childNavStack.pushPath({ name: 'page one' })
      })
  }

  @Builder
  tabContent2() {
    Text('Second page')
  }

  @Builder
  tabContent3() {
    Text('Third page')
  }

  @Builder
  navigationContent() {
    AtomicServiceTabs({
      tabContents: [
        () => {
          this.tabContent1()
        },
        () => {
          this.tabContent2()
        },
        () => {
          this.tabContent3()
        }
      ],
      tabBarOptionsArray: [
        new TabBarOptions($r('sys.media.ohos_ic_public_phone'), 'Feature 1'),
        new TabBarOptions($r('sys.media.ohos_ic_public_location'), 'Feature 2', Color.Green, Color.Red),
        new TabBarOptions($r('sys.media.ohos_ic_public_more'), 'Feature 3')
      ],
      tabBarPosition: TabBarPosition.BOTTOM,
      barBackgroundColor: $r('sys.color.ohos_id_color_bottom_tab_bg'),
      onTabBarClick: (index: Number) => {
        if (index == 0) {
          this.message = 'Feature 1';
        } else if (index == 1) {
          this.message = 'Feature 2';
        } else {
          this.message = 'Feature 3';
        }
      }
    })
  }

  @Builder
  pageMap(name: string) {
    if (name === 'page one') {
      PageOne()
    } else if (name === 'page two') {
      PageTwo()
    }
  }

  @State showText: string = 'time: ';
  @State time: number = 0;

  @Builder
  insertComp() {
    Text('This is the menu area')
      .fontColor(Color.Red)
      .width(200)
      .height('100%')
  }

  build() {
    Column() {
      AtomicServiceNavigation({
        navigationContent: () => {
          this.navigationContent()
        },
        navDestinationBuilder: this.pageMap,
        navPathStack: this.childNavStack,
        title: this.message,
        titleOptions: {
          titleIcon: $r('app.media.startIcon'),
          backgroundColor: 'rgb(61, 157, 180)',
          titleBarType: TitleBarType.DRAWER
        },
        menus: () => { this.insertComp() },
        mode: NavigationMode.Stack
      })
    }
    .width('100%')
  }
}

@Component
export struct PageOne {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('Next')
        .onClick(() => {
          this.pageInfo.pushPath({ name: 'page two'})
        })
    }
    .title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@Component
export struct PageTwo {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('End')
    }
    .title('PageTwo')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}
```
![](figures/AtomicServiceNavigationDemo03.png)

### Example 3: Configuring the Sidebar

This example demonstrates how to set the sidebar background color and content style.

```ts
import { AtomicServiceNavigation, TitleBarType } from '@kit.ArkUI';
import { AtomicServiceTabs, TabBarOptions, TabBarPosition } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  childNavStack: NavPathStack = new NavPathStack();

  @Builder
  tabContent1() {
    Text('first page')
      .onClick(() => {
        this.childNavStack.pushPath({ name: 'page one' })
      })
  }

  @Builder
  tabContent2() {
    Text('second page')
  }

  @Builder
  tabContent3() {
    Text('third page')
  }

  @Builder
  navigationContent() {
    AtomicServiceTabs({
      tabContents: [
        () => {
          this.tabContent1()
        },
        () => {
          this.tabContent2()
        },
        () => {
          this.tabContent3()
        }
      ],
      tabBarOptionsArray: [
        new TabBarOptions($r('sys.media.ohos_ic_public_phone'), 'Feature 1'),
        new TabBarOptions($r('sys.media.ohos_ic_public_location'), 'Feature 2', Color.Green, Color.Red),
        new TabBarOptions($r('sys.media.ohos_ic_public_more'), 'Feature 3')
      ],
      tabBarPosition: TabBarPosition.BOTTOM,
      barBackgroundColor: $r('sys.color.ohos_id_color_bottom_tab_bg'),
      onTabBarClick: (index: Number) => {
        if (index == 0) {
          this.message = 'Feature 1';
        } else if (index == 1) {
          this.message = 'Feature 2';
        } else {
          this.message = 'Feature 3';
        }
      }
    })
  }

  @Builder
  pageMap(name: string) {
    if (name === 'page one') {
      PageOne()
    } else if (name === 'page two') {
      PageTwo()
    }
  }

  @State showText: string = 'time: ';
  @State time: number = 0;

  @Builder
  insertComp() {
    Text('This is menus area')
      .fontColor(Color.Red)
      .width(200)
      .height('100%')
  }

  @Builder
  sideBarContentBuilder() {
    Text('This is sideBar content area')
      .fontSize(20)
  }

  build() {
    Column() {
      AtomicServiceNavigation({
        navigationContent: () => {
          this.navigationContent()
        },
        navDestinationBuilder: this.pageMap,
        navPathStack: this.childNavStack,
        title: this.message,
        titleOptions: {
          titleIcon: $r('app.media.startIcon'),
          backgroundColor: 'rgb(61, 157, 180)',
          titleBarType: TitleBarType.DRAWER
        },
        sideBarOptions: {
          sideBarBackground: '#409EFF'
        },
        sideBarContent: () => { this.sideBarContentBuilder() },
        mode: NavigationMode.Stack
      })
    }
    .width('100%')
  }
}

@Component
export struct PageOne {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('Next')
        .onClick(() => {
          this.pageInfo.pushPath({ name: 'page two'})
        })
    }
    .title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@Component
export struct PageTwo {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('End')
    }
    .title('PageTwo')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}
```
![](figures/AtomicServiceNavigationDemo04.png)
