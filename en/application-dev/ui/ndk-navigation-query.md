# Using Navigation Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @tsj_20201-->
<!--Designer: @fangzhiyuan1-->
<!--Tester: @Giacinta-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=d1e4d0c1349312557d4315ff2b1c5d57de74d862 translatedAt=2026-08-05T10:07:08.268Z pushedAt=2026-08-06T06:21:47.804Z -->

NDK provides a series of [Navigation](./arkts-navigation-architecture.md#overall-architecture) and [page routing](./arkts-routing.md) state query APIs. You can use [OH_ArkUI_GetNavDestinationName](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationname), [OH_ArkUI_GetNavDestinationParam](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationparam), [OH_ArkUI_GetNavDestinationState](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationstate), [OH_ArkUI_GetNavigationId](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavigationid), [OH_ArkUI_GetNavDestinationIndex](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationindex), and other APIs to query page state, index, name, and other information, and perform corresponding operations based on the query results, such as displaying different page information.

This document provides development guidance for page state query. Before querying, you need to access the ArkTS page first. For details, see [Integrating with ArkTS Pages](./ndk-access-the-arkts-page.md).

## Querying Page Information

To query page information, you must first ensure that the target node has been mounted as a child node to the page. If the node is not mounted, the operation will fail. For example, the corresponding information cannot be queried in the [aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear) lifecycle. For details about the page lifecycle and component mounting lifecycle, see [Page Lifecycle](./arkts-navigation-navdestination.md#page-lifecycle). You can load different page components based on the queried page information.

This example only shows the core functionality code. For the complete example, see <!--RP1-->[NDK Page Query API Usage Example](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKNavigation)<!--RP1End-->.

1. Query the current page name.

   Use [OH_ArkUI_GetNavDestinationName](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationname) to query the **NavDestination** page name. The router page name can be queried through the [OH_ArkUI_GetRouterPageName](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getrouterpagename) API.

   <!-- @[get_page_name](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKNavigation/entry/src/main/cpp/QueryNavigation.h) -->

   ``` C
   // Get the page name.
   char pageName[NUM_50];
   int32_t bufferLen = 0;
   OH_ArkUI_GetNavDestinationName(node, pageName, NUM_50, &bufferLen);
   ```

2. Query the page navigation parameters.

Use [OH_ArkUI_GetNavDestinationParam](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationparam) to query the [NavDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md) page navigation parameters.

   <!-- @[get_page_param](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKNavigation/entry/src/main/cpp/QueryNavigation.h) -->

   ``` C
   // Get page navigation parameters.
   napi_value param = OH_ArkUI_GetNavDestinationParam(node);
   napi_value nameVal = nullptr;
   napi_get_named_property(env, param, "name", &nameVal);
   size_t len = 0;
   napi_get_value_string_utf8(env, nameVal, nullptr, 0, &len);
   std::unique_ptr<char[]> viewName = std::make_unique<char[]>(len + 1);
   napi_get_value_string_utf8(env, nameVal, viewName.get(), len + 1, &len);
   ArkUI_NodeHandle targetNode = nullptr;
   std::string view = viewName.get();
   if (view == "QueryNavigation") {
       InitNavigationNode(column, pageName);
   } else if (view == "QueryRouter") {
       InitRouterNode(column);
   }
   nativeApi->addChild(node, column);
   ```

## Querying the Page State

Use [OH_ArkUI_GetNavDestinationState](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationstate) to query the state of the **NavDestination** page to which the current placeholder component belongs. Router pages can be queried through the [OH_ArkUI_GetRouterPageState](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getrouterpagestate) API, and corresponding adaptations can be made based on the query results, such as setting the component's visible attribute or video playback state.

This example only demonstrates the core function code. For the complete example, see <!--RP1-->[NDK page query API usage example](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKNavigation)<!--RP1End-->.

<!-- @[get_page_state](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKNavigation/entry/src/main/cpp/EntryModule.cpp) -->

``` C++
ArkUI_NodeHandle targetNode = nullptr;
OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("navDestinationState", &targetNode);
auto entry = NativeEntry::GetInstance();
entry->ReportError(targetNode, "event clicked");
ArkUI_NavDestinationState state;
OH_ArkUI_GetNavDestinationState(targetNode, &state);
if (state == NUM_8) {
    entry->SetColor(targetNode, 0x80808080);
} else if (state == NUM_9) {
    entry->SetColor(targetNode, 0xFF000000);
}
```

## Querying Page Stack Information

Use [OH_ArkUI_GetNavDestinationIndex](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnavdestinationindex) to query the position of the **NavDestination** to which the current placeholder component belongs in the stack. The router page index can be queried through the [OH_ArkUI_GetRouterPageIndex](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getrouterpageindex) API. Based on the returned page stack information, you can implement DFX features in app development, such as collecting parameters for performance monitoring and user behavior analysis, for data reporting and analysis.

This example only shows the core function code. For the complete example, see <!--RP1-->[NDK Page Query API Example](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKNavigation)<!--RP1End-->.

<!-- @[get_stack_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKNavigation/entry/src/main/cpp/EntryModule.cpp) -->

``` C++
char navigationId[NUM_50];
int32_t bufferLen = 0;
OH_ArkUI_GetNavigationId(handle, navigationId, NUM_50, &bufferLen);
    
char name[NUM_50];
int32_t nameLen = OH_ArkUI_GetNavDestinationName(handle, name, NUM_50, &nameLen);
    
int32_t index = -1;
OH_ArkUI_GetNavDestinationIndex(handle, &index);
OH_LOG_Print(LOG_APP, LOG_ERROR, 0xFF00, "NAPI",
             "navigation id: %{public}s, name: %{public}s, index: %{public}d, error: %{public}s",
             navigationId, name, index, info.c_str());
```