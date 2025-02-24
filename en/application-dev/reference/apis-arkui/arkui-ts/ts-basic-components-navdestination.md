# NavDestination

**NavDestination** is the root container of a destination page and represents the content area of the [Navigation](ts-basic-components-navigation.md) component.

> **NOTE**
>
> - This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - Since API version 11, this component supports the safe area attribute by default, with the default attribute value being **expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])**. You can override this attribute to change the default behavior. In earlier versions, you need to use the [expandSafeArea](ts-universal-attributes-expand-safe-area.md) attribute to implement the safe area feature.
>
> - The **NavDestination** component must be used in conjunction with the **Navigation** component to act as the root node for the navigation destination page. When used alone, it can only function as a standard container component and does not possess any routing-related attributes or capabilities.
>
> - If the lifecycle of a page in the middle of the navigation stack changes, the lifecycle of the destination page at the top of the stack before the transition (**onWillShow**, **onShown**, **onHidden**, **onWillDisappear**) and the lifecycle of the destination page after the transition (**onWillShow**, **onShown**, **onHidden**, **onWillDisappear**) are both triggered at the end.
>
> - If no main title or subtitle is set for **NavDestination** and there is no back button, the title bar is not displayed.

## Child Components

Built-in components and custom components are allowed, with support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.

Number of child components: multiple.


## APIs

NavDestination()

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

Avoid setting layout-related attributes such as the position and size. They may result in display issues on the page.

### title

title(value: string | CustomBuilder | NavDestinationCommonTitle | NavDestinationCustomTitle | Resource, options?: NavigationTitleOptions)

Sets the page title. When the NavigationCustomTitle type is used to set the height, the [titleMode](ts-basic-components-navigation.md#titlemode) attribute does not take effect. When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description      |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| value  | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavDestinationCommonTitle](#navdestinationcommontitle) \| [NavDestinationCustomTitle](#navdestinationcustomtitle) \| [Resource<sup>14+</sup>](ts-types.md#resource)  | Yes  | Page title.|
| options<sup>12+</sup> | [NavigationTitleOptions](ts-basic-components-navigation.md#navigationtitleoptions11) | No  | Title bar options.|

### hideTitleBar

hideTitleBar(value: boolean)

Specifies whether to hide the title bar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|

### hideTitleBar<sup>13+</sup>

hideTitleBar(hide: boolean, animated: boolean)

Sets whether to hide the title bar and whether to animate the visibility change.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| hide  | boolean | Yes  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Show the title bar.|
| animated  | boolean | Yes  | Whether to animate the visibility change.<br>Default value: **false**<br>**true**: Animate the visibility change.<br>**false**: Do not animate the visibility change.|

### toolbarConfiguration<sup>13+</sup>

toolbarConfiguration(toolbarParam: Array&lt;ToolbarItem&gt; | CustomBuilder, options?: NavigationToolbarOptions)

Sets the content of the toolbar. If this API is not called, the toolbar remains hidden.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| toolbarParam |  Array&lt;[ToolbarItem](ts-basic-components-navigation.md#toolbaritem10)&gt;  \| [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Content of the toolbar.<br>When configured with Array&lt;[ToolbarItem](ts-basic-components-navigation.md#toolbaritem10)&gt;, the toolbar follows the rules below:<br>- Toolbar items are evenly distributed on the bottom toolbar, with text and icons evenly spaced in each content area.<br>- If any item contains overlong text and there are fewer than five items, the toolbar will: 1. Increase the item width to accommodate the text until the toolbar spans the screen width; 2. Reduce the text size progressively; 3. Wrap the text over two lines; 4. Clip the text with an ellipsis (...).<br>- In portrait mode, the toolbar shows a maximum of five icons, with any additional icons placed under an automatically generated **More** icon. In landscape mode, the behavior of the toolbar is determined by the display mode: (1) If the display mode is [Split](ts-basic-components-navigation.md#navigationmode9), the toolbar follows the same rules as in portrait mode. (2) If the display mode is [Stack](ts-basic-components-navigation.md#navigationmode9), the toolbar must be used together with Array&lt;[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt; of the **menus** attribute; in this configuration, the bottom toolbar is automatically hidden, and all items on the toolbar are relocated to the menu in the upper right corner of the screen.<br>When configured with [CustomBuilder](ts-types.md#custombuilder8), the toolbar does not follow the above rules, except for evenly distributing items at the bottom of the toolbar.|
| options      | [NavigationToolbarOptions](ts-basic-components-navigation.md#navigationtoolbaroptions11) | No  | Toolbar options.                                                |

> **NOTE**
>
> The following are not allowed: modify the icon size through the **fontSize** attribute of the **SymbolGlyphModifier** object, change the animation effects through the **effectStrategy** attribute, or change the type of animation effects through the **symbolEffect** attribute.

### hideToolBar<sup>13+</sup>

hideToolBar(hide: boolean, animated?: boolean)

Sets whether to hide the toolbar and whether to animate the visibility change.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| hide  | boolean | Yes  | Whether to hide the toolbar.<br>Default value: **false**<br>**true**: Hide the toolbar.<br>**false**: Show the toolbar.|
| animated  | boolean | No  | Whether to animate the visibility change.<br>Default value: **false**<br>**true**: Animate the visibility change.<br>**false**: Do not animate the visibility change.|

### mode <sup>11+</sup>

mode(value: NavDestinationMode)

Sets the mode of the **NavDestination** component. Dynamic modification is not supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [NavDestinationMode](#navdestinationmode11) | Yes  | Mode of the **NavDestination** component.<br>Default value: **NavDestinationMode.STANDARD**|

### backButtonIcon<sup>11+</sup>

backButtonIcon(value: ResourceStr | PixelMap | SymbolGlyphModifier)

> **NOTE**
>
> The following are not allowed: modify the icon size through the **fontSize** attribute of the **SymbolGlyphModifier** object, change the animation effects through the **effectStrategy** attribute, or change the type of animation effects through the **symbolEffect** attribute.


Sets the icon of the back button on the title bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr) \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [SymbolGlyphModifier<sup>12+</sup>](ts-universal-attributes-attribute-modifier.md)  | Yes  | Icon of the back button on the title bar.|

### menus<sup>12+</sup>

menus(value: Array&lt;NavigationMenuItem&gt; | CustomBuilder)

> **NOTE**
>
> The following are not allowed: modify the icon size through the **fontSize** attribute of the **SymbolGlyphModifier** object, change the animation effects through the **effectStrategy** attribute, or change the type of animation effects through the **symbolEffect** attribute.


Sets the menu items in the upper right corner of the page. If this attribute is not set, no menu item is displayed. When the value type is Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt;, the menu shows a maximum of three icons in portrait mode and a maximum of five icons in landscape mode, with excess icons (if any) placed under the automatically generated **More** icon.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Menu items in the upper right corner of the page.|

### ignoreLayoutSafeArea<sup>12+</sup>

ignoreLayoutSafeArea(types?: Array&lt;LayoutSafeAreaType&gt;, edges?: Array&lt;LayoutSafeAreaEdge&gt;)

Ignores the layout safe area by allowing the component to extend into the non-safe areas of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                              | Mandatory| Description                                                        |
| ------ | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| types  | Array <[LayoutSafeAreaType](ts-types.md#layoutsafeareatype12)> | No  | Types of non-safe areas to extend into.<br>Default value:<br>[LayoutSafeAreaType.SYSTEM] |
| edges  | Array <[LayoutSafeAreaEdge](ts-types.md#layoutsafeareaedge12)> | No  | Edges for expanding the safe area.<br> Default value:<br>[LayoutSafeAreaEdge.TOP, LayoutSafeAreaEdge.BOTTOM]|

>  **NOTE**
>   
>  After **LayoutSafeArea** is set:  
>  When **LayoutSafeAreaType.SYSTEM** is set, the component can extend into the non-safe area if its boundaries overlap with it. For example, if the device's status bar is 100 high, the component must have an absolute vertical offset between 0 and 100 to extend into the non-safe area. 
>   
>  If the component extends into the non-safe area, events triggered within that area (such as click events) might be intercepted by the system. This allows the system to prioritize responses to system components such as the status bar.

### systemBarStyle<sup>12+</sup>

systemBarStyle(style: Optional&lt;SystemBarStyle&gt;)

Sets the style of the system status bar when this **NavDestination** page is displayed in the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type        | Mandatory| Description              |
| ------ | -------------- | ---- | ------------------ |
| style  | Optional&lt;[SystemBarStyle](../js-apis-window.md#systembarstyle12)&gt; | Yes  | Style of the system status bar.|

> **NOTE**
>
> 1. The setting takes effect only when the **NavDestination** component is used in conjunction with the **Navigation** component.
> 2. For other usage restrictions, see the description of [systemBarStyle](ts-basic-components-navigation.md#systembarstyle12) for the **Navigation** component.

### systemTransition<sup>14+</sup>
systemTransition(type: NavigationSystemTransitionType)

Sets the system transition animation of the **NavDestination** component. System transition animations for the title bar and content area can be configured separately.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type  | [NavigationSystemTransitionType](#navigationsystemtransitiontype14) | Yes  | Type of the system transition animation.<br>Default value: **NavigationSystemTransitionType.DEFAULT**|

### recoverable<sup>14+</sup>

recoverable(recoverable: Optional&lt;boolean&gt;)

Sets whether the **NavDestination** component is recoverable. If set to recoverable, when the application process exits unexpectedly and restarts, the **NavDestination** component will be automatically recreated. To use this feature, ensure that the **recoverable** attribute is set for the **Navigation** component associated with the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type        | Mandatory| Description              |
| ------ | -------------- | ---- | ------------------ |
| recoverable  | Optional&lt;boolean&gt; | Yes  | Whether the **NavDestination** component is recoverable. By default, it is not recoverable.<br>Default value: **false**<br>**true**: The **NavDestination** component is recoverable.<br>**false**: The **NavDestination** component is not recoverable.|

>  **NOTE**
>
> This API must be used together with the [recoverable](./ts-basic-components-navigation.md#recoverable14) API of **Navigation**.

### bindToScrollable<sup>14+</sup>
bindToScrollable(scrollers: Array&lt;Scroller&gt;)

Binds the **NavDestination** component to a scrollable container, which can be [List](./ts-container-list.md), [Scroll](./ts-container-scroll.md), [Grid](./ts-container-grid.md), or [WaterFlow](./ts-container-waterflow.md). After the binding, scrolling in the scrollable container will trigger the animations for showing or hiding the title bar and toolbar of all bound **NavDestination** components. A single **NavDestination** component can be bound to multiple scrollable containers, and a single scrollable container can be bound to multiple **NavDestination** components. For details, see [Example 1](#example-1).

> **NOTE**
>
> - The connection between the scrolling actions and the animations for showing or hiding the title bar and toolbar of the **NavDestination** component takes effect only when the title bar or toolbar is visible.
> - If a **NavDestination** component is bound to multiple scrollable containers, scrolling in any of these containers triggers the display or hiding animations of the title bar and toolbar. Specifically, when any scrollable container reaches either the bottom or the top, the display animation for the title bar and toolbar is triggered without delay. As such, to ensure the optimal user experience, avoid triggering scroll events of multiple scrollable containers simultaneously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| scrollers | Array<[Scroller](./ts-container-scroll.md#scroller)> | Yes  | Controller of the target scrollable container.|

### bindToNestedScrollable<sup>14+</sup>
bindToNestedScrollable(scrollers: Array&lt;NestedScrollInfo&gt;)

Binds the **NavDestination** component to nested scrollable containers, which can be [List](./ts-container-list.md), [Scroll](./ts-container-scroll.md), [Grid](./ts-container-grid.md), or [WaterFlow](./ts-container-waterflow.md). After the binding, scrolling in any of these scrollable containers will trigger the animations for showing or hiding the title bar and toolbar of all bound **NavDestination** components. A single **NavDestination** component can be bound to multiple nested scrollable containers, and a single nested scrollable container can be bound to multiple **NavDestination** components. For details, see [Example 1](#example-1).

> **NOTE**
>
> - The connection between the scrolling actions and the animations for showing or hiding the title bar and toolbar of the **NavDestination** component takes effect only when the title bar or toolbar is visible.
> - If a **NavDestination** component is bound to multiple scrollable containers, scrolling in any of these containers triggers the display or hiding animations of the title bar and toolbar. Specifically, when any scrollable container reaches either the bottom or the top, the display animation for the title bar and toolbar is triggered without delay. As such, to ensure the optimal user experience, avoid triggering scroll events of multiple scrollable containers simultaneously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| scrollInfos | Array<[NestedScrollInfo](#nestedscrollinfo14)> | Yes  | Controller of the target nested scrollable containers.|

### hideBackButton<sup>16+</sup>

hideBackButton(hide: Optional&lt;boolean&gt;)

Sets whether to hide the back button in the title bar.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| hide  | Optional&lt;boolean&gt; | Yes  | Whether to hide the back button in the title bar.<br>Default value: **false**<br>**true**: Hide the back button.<br>**false**: Show the back button.|

## NavDestinationMode<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Description                                    |
| ---- | ---------------------------------------- |
| STANDARD | Standard mode.                      |
| DIALOG | Dialog mode, where the navigation destination is transparent by default, and adding or removing the navigation destination from the navigation stack does not affect the lifecycle of the lower-layer navigation destinations.<br>System transition animations are supported since API version 13. |

## NavigationSystemTransitionType<sup>14+</sup>

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Value  | Description|
| ----  | ---   | ----- |
| DEFAULT  | 0 | Default system transition animation.|
| NONE| 1 | No system transition animation.|
| TITLE | 2 | System transition animation of the title bar.|
| CONTENT | 3 | System transition animation of the content area.|

**NOTE**
>
> System transition animations for the title bar and content area can be configured separately.
> 
> The system transition animation of the title bar is only available for the push and pop animations of navigation destination pages in STANDARD mode, with the following constraints:
> 1. When **NavigationSystemTransitionType** is set to **TITLE**, only the system transition animation of the title bar is displayed.
> 2. When **NavigationSystemTransitionType** is set to **CONTENT**, only the system transition animation of the content area is displayed.
>
> When **NONE** or **TITLE** is set, no system transition animation is displayed. When **CONTENT** or **DEFAULT** is set, the system transition animation is displayed by default.

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onShown<sup>10+</sup>

onShown(callback: () =&gt; void)

Called when the navigation destination page is displayed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onHidden<sup>10+</sup>

onHidden(callback: () =&gt; void)

Called when the navigation destination page is hidden.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillAppear<sup>12+</sup>

onWillAppear(callback: Callback\<void>)

Called when the navigation destination is about to be mounted. You can change the navigation stack in this callback function, and the change takes effect in the current frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillShow<sup>12+</sup>

onWillShow(callback: Callback\<void>)

Called when the navigation destination is about to be displayed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillHide<sup>12+</sup>

onWillHide(callback: Callback\<void>)

Called when the navigation destination is about to be hidden.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillDisappear<sup>12+</sup>

onWillDisappear(callback: Callback\<void>)

Called when the navigation destination is about to be unmounted (or when the transition animation, if any, is about to start).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onBackPressed<sup>10+</sup>

onBackPressed(callback: () =&gt; boolean)

This callback takes effect when there is one or more entries in the navigation stack bound to the **Navigation** component. Called when the back button is pressed.

The value **true** means that the back button logic is overridden, and **false** means that the previous page is displayed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onReady<sup>11+</sup>

onReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11)>)

Called when the **NavDestination** component is about to build a child component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## NavDestinationCommonTitle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type    | Mandatory  | Description    |
| ---- | ------ | ---- | ------ |
| main | string \| [Resource<sup>14+<sup>](ts-types.md#resource) | Yes   | Main title.|
| sub  | string \| [Resource<sup>14+<sup>](ts-types.md#resource) | Yes   | Subtitle.|

## NavDestinationCustomTitle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                      | Mandatory  | Description      |
| ------- | ---------------------------------------- | ---- | -------- |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | Yes   | Content of the title bar.|
| height  | [TitleHeight](ts-appendix-enums.md#titleheight9) \| [Length](ts-types.md#length) | Yes   | Height of the title bar.|

## NavDestinationContext<sup>11+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type    | Mandatory  |  Description    |
| ---- | ------ | ----- | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | Yes| Path information of the navigation destination page.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | Yes| Page stack where the current navigation destination page is located.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| navDestinationId<sup>12+</sup> | string | No| Unique ID of the current navigation destination page, which is automatically generated by the system and is irrelevant to the universal attribute **id** of the component.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

### getConfigInRouteMap<sup>12+</sup>

getConfigInRouteMap(): RouteMapConfig |undefined

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type| Description|
| --- | --- |
| [RouteMapConfig](#routemapconfig12) | Route map configuration of the current page.|
| undefined | **undefined**, returned when the page is not configured through the route table.|

## RouteMapConfig<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  |Mandatory| Description|
| ----  | ---   | ---- |----- |
| name  | string | Yes| Page name.|
| pageSourceFile| string | Yes| Path of the page in the current package.|
| data | Object | Yes| Custom data of the page.|

## NestedScrollInfo<sup>14+</sup>

Provides the information about the nested scrollable containers.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  |Mandatory| Description|
| ----  | ---   | ---- |----- |
| parent | [Scroller](./ts-container-scroll.md#scroller) | Yes| Controller of the target scrollable container.|
| child | [Scroller](./ts-container-scroll.md#scroller) | Yes| Controller of the scrollable container nested within the target scrollable container. This scrollable container is a child component of the target scrollable container.|

## Example

### Example 1

This example shows how to bind a **NavDestination** component to scrollable containers so that scrolling in the scrollable containers triggers the animations for showing or hiding the title bar and toolbar of the **NavDestination** component.

```ts
import { SymbolGlyphModifier } from '@kit.ArkUI';

@Component
struct MyPageOne {
  private listScroller: Scroller = new Scroller();
  private scrollScroller: Scroller = new Scroller();
  private arr: number[] = [];

  aboutToAppear(): void {
    for (let i = 0; i < 30; i++) {
      this.arr.push(i);
    }
  }

  build() {
    NavDestination() {
      Scroll(this.scrollScroller) {
        Column() {
          List({space: 0, initialIndex: 0, scroller: this.listScroller}) {
            ForEach(this.arr, (item: number, index: number) => {
              ListItem() {
                Text('' + item)
                  .height(100)
                  .fontSize(16)
                  .textAlign(TextAlign.Center)
                  .width('90%')
                  .margin({left: '5%'})
                  .borderRadius(10)
                  .backgroundColor(Color.Gray)
              }
            }, (item: string) => item);
          }.width('100%').height('80%').scrollBar(BarState.Off)
          .nestedScroll({scrollForward: NestedScrollMode.SELF_FIRST, scrollBackward: NestedScrollMode.SELF_FIRST})
          ForEach(this.arr, (item: number, index: number) => {
            ListItem() {
              Text('' + item)
                .height(100)
                .fontSize(16)
                .textAlign(TextAlign.Center)
                .width('90%')
                .margin({top: '5%'})
                .borderRadius(10)
                .backgroundColor(Color.Pink)
            }
          }, (item: string) => item);
        }
      }
      .width('100%')
      .scrollBar(BarState.Off)
      .scrollable(ScrollDirection.Vertical)
      .edgeEffect(EdgeEffect.Spring)
    }
    .title('PageOne', {backgroundColor: Color.Yellow, barStyle: BarStyle.STACK})
    .toolbarConfiguration([
      {
        value: 'item1',
        symbolIcon: new SymbolGlyphModifier($r('sys.symbol.phone_badge_star'))
      }
    ], {backgroundColor: Color.Orange, barStyle: BarStyle.STACK})
    // Bind the NavDestination component to nested scrollable containers.
    .bindToNestedScrollable([{parent: this.scrollScroller, child: this.listScroller}])
  }
}

@Component
struct MyPageTwo {
  private listScroller: Scroller = new Scroller();
  private arr: number[] = [];

  aboutToAppear(): void {
    for (let i = 0; i < 30; i++) {
      this.arr.push(i);
    }
  }

  build() {
    NavDestination() {
      List({scroller: this.listScroller}) {
        ForEach(this.arr, (item: number, index: number) => {
          ListItem() {
            Text('' + item)
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .width('90%')
              .margin({left: '5%'})
              .borderRadius(10)
              .backgroundColor(Color.Gray)
          }
        }, (item: string) => item);
      }.width('100%')
    }
    .title('PageTwo', {backgroundColor: Color.Yellow, barStyle: BarStyle.STACK})
    .toolbarConfiguration([
      {
        value: 'item1',
        symbolIcon: new SymbolGlyphModifier($r('sys.symbol.phone_badge_star'))
      }
    ], {backgroundColor: Color.Orange, barStyle: BarStyle.STACK})
    // Bind the NavDestination component to a scrollable container.
    .bindToScrollable([this.listScroller])
  }
}

@Entry
@Component
struct Index {
  private stack: NavPathStack = new NavPathStack();

  @Builder
  MyPageMap(name: string) {
    if (name === 'myPageOne') {
      MyPageOne()
    } else {
      MyPageTwo()
    }
  }

  build() {
    Navigation(this.stack) {
      Column() {
        Button('push PageOne').onClick(() => {
          this.stack.pushPath({name: 'myPageOne'})
        })
        Button('push PageTwo').onClick(() => {
          this.stack.pushPath({name: 'myPageTwo'})
        })
      }.height('40%').justifyContent(FlexAlign.SpaceAround)
    }.width('100%')
    .height('100%')
    .title({main: 'MainTitle', sub: 'subTitle'})
    .navDestination(this.MyPageMap)
  }
}
```
![navdestination_bind_scrollable](figures/navdestination_bind_scrollable.gif)

For more examples, see [Example in Navigation](ts-basic-components-navigation.md#example-1-implementing-a-navigation-page-layout).
