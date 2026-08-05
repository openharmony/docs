# Component Navigation and Page Routing Overview
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @tsj_20201-->
<!--Designer: @fangzhiyuan1-->
<!--Tester: @gouyuanyuan-->
<!--Adviser: @Brilliantry_Rui-->

A page serves as a visual interaction unit composed of layouts, components, and interaction logic. It encapsulates specific functional logic and information presentation, forming the core interface medium for user-application interaction. A complete application typically consists of multiple pages. Both [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) and [@ohos.router](../reference/apis-arkui/arkts-apis-uicontext-router.md) provide the ability to navigate between pages within the application.

- In the [NavDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md) framework, a page is carried by the **NavDestination** component and refers to the content contained in a **NavDestination** component.
- In the @ohos.router framework, a page refers to a custom component decorated with the @Entry decorator.

Compared with@ohos.router, the **Navigation** framework embeds pages within **Navigation** components for navigation, offering enhanced multi-device adaptation capabilities, more flexible page stack management, and richer animation effects and lifecycle support. Therefore, to deliver a better user experience, prioritize the **Navigation** component for implementing both page navigation and intra-component navigation whenever possible.

## Architecture Differences

In the ArkUI component tree hierarchy, pages that were originally managed by the **Router** module are located beneath the stage management node of the page stack. **Navigation**, as a navigation container component, can be mounted under a single page node and can also be stacked and nested. **Navigation** manages the title bar, toolbar, and content area, an area designed to display the content of custom pages and allowing for page routing. The design of **Navigation** has the following advantages:

![image](figures/navigation-and-router-architecture.png)

1. Explicitly distinguishes the title bar, content area, and toolbar in the API for enhanced management and UX animation flexibility.

2. Explicitly provides a routing container, allowing you to decide its location, which can be in a modal, sheet, or dialog box.

3. Integrates UX design and one-time development for multi-device deployment capabilities, with default capabilities for unified title display, page switching, and single or double column adaptation.

4. Enables flexible page configuration by allowing you to determine the relationship between page aliases and UI through [UIBuilder](../ui/state-management/arkts-builder.md).

5. Transforms page transition animations into component property animations, offering a wider and more flexible range of transition effects.

6. Opens the page stack object to allow developers to inherit it for better management of the page display.

## Capability Comparison 

| Scenario                                     | Navigation                            | Router                                 |
| --------------------------------------------- | ------------------------------------- | -------------------------------------- |
| One-time development for multi-device deployment                                     | Supported (The Auto mode is provided to automatically adapt to single- or double-column layout.)   | Not supported                                |
| Navigation to a specific page                                 | [pushPath](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#pushpath10) & [pushDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#pushdestination11)            | [pushUrl](../reference/apis-arkui/arkts-apis-uicontext-router.md#pushurl) & [pushNamedRoute](../reference/apis-arkui/arkts-apis-uicontext-router.md#pushnamedroute)               |
| Navigation to a page within an HSP                                | Supported                                 | Supported                                  |
| Navigation to a page within a HAR                                | Supported                                 | Supported                                  |
| Passing parameters during navigation                                     | Supported                                 | Supported                                 |
| Obtaining parameters of a specific page                             | Supported                                 | Not supported                                |
| Type of parameters passed                                     | Passed as an object                       | Passed as an object, method variables not supported within the object|
| Navigation result callback                                 | Supported                                 | Supported                                  |
| Navigation to a singleton page                                 | Supported                                 | Supported                                  |
| Return to a previous page                                     | Supported                                 | Supported                                  |
| Passing parameters on returning to a previous page                                 | Supported                                 | Supported                                  |
| Returning to a specific route                                 | Supported                                 | Supported                                  |
| Dialog box for returning to a previous page                                 | Supported, implemented through route interception               | [showAlertBeforeBackPage](../reference/apis-arkui/arkts-apis-uicontext-router.md#showalertbeforebackpage)             |
| Route replacement                                     | [replacePath](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#replacepath11) & [replacePathByName](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#replacepathbyname11)        | [replaceUrl](../reference/apis-arkui/arkts-apis-uicontext-router.md#replaceurl) & [replaceNamedRoute](../reference/apis-arkui/arkts-apis-uicontext-router.md#replacenamedroute)          |
| Clearing the navigation stack                                   | [clear](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#clear10)                                 | [clear](../reference/apis-arkui/arkts-apis-uicontext-router.md#clear)                                  |
| Removing specific routes from the navigation stack                                 | [removeByIndexes](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#removebyindexes11) & [removeByName](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#removebyname11)        | Not supported                                |
| Transition animation                                     | Supported                                 | Supported                                  |
| Custom transition animation                               | Supported                                 | Supported, with limited animation types                    |
| Disabling transition animation                                 | Supported, with global or one-time settings                       | Supported, with the duration of the [pageTransition](../reference/apis-arkui/arkui-ts/ts-page-transition-animation.md) method set to **0**.|
| Shared element animation with **geometryTransition**               | Supported through sharing between **NavDestination** components       | Not supported                                |
| Listening for page lifecycle                             | [UIObserver.on('navDestinationUpdate')](../reference/apis-arkui/arkts-apis-uicontext-uiobserver.md#onnavdestinationupdate11) | [UIObserver.on('routerPageUpdate')](../reference/apis-arkui/arkts-apis-uicontext-uiobserver.md#onrouterpageupdate11)     |
| Obtaining a page stack object                               | Supported                                 | Not supported                                |
| Route interception                                     | Supported through [setInterception](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#setinterception12).     | Not supported                                |
| Route stack information query                               | Supported                                 | [getState()](../reference/apis-arkui/arkts-apis-uicontext-router.md#getstate)|
| Move operations within the navigation stack                               | [moveToTop](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#movetotop10) & [moveIndexToTop](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#moveindextotop10)             | Not supported                                |
| Immersive pages                                   | Supported                                 | Not supported; requires window configuration              |
| Setting the title bar and toolbar| Supported                                 | Not supported                                |
| Modal nested routing                                 | Supported                                 | Not supported                                |
