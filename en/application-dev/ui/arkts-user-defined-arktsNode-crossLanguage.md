# Setting Custom Node Cross-Language Attributes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=4cd6ff07550739998f1b5508c7b8a32b6b4ff448 translatedAt=2026-08-05T01:24:22.786Z pushedAt=2026-08-05T01:42:39.644Z -->

## Overview

ArkUI supports creating imperative nodes using the ArkTS language on the frontend, that is, [FrameNodes](../reference/apis-arkui/js-apis-arkui-frameNode.md). It also allows creating imperative nodes using the C language on the native side, and both types of nodes can be used together to build pages.

For this scenario, ArkUI provides cross-language attribute setting for imperative nodes, meaning nodes created with ArkTS can have their attributes set on the native side, and nodes created in C can have their attributes set in ArkTS.

> **NOTE**
>
> In the examples below, native-side configuration must be completed first. For details, see [Integrating with ArkTS Pages](./ndk-access-the-arkts-page.md).

## Setting and Obtaining Cross-Language Options

Cross-language refers to operations between ArkTS and C languages. Cross-language options refer to permission settings for cross-language operations on imperative nodes.

You can set a node's cross-language options using [setCrossLanguageOptions](../reference/apis-arkui/js-apis-arkui-frameNode.md#setcrosslanguageoptions15) and [OH_ArkUI_NodeUtils_SetCrossLanguageOption](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_setcrosslanguageoption). If the node cannot modify or set cross-language options, an exception will be thrown.

You can obtain the current cross-language options using [getCrossLanguageOptions](../reference/apis-arkui/js-apis-arkui-frameNode.md#getcrosslanguageoptions15) and [OH_ArkUI_NodeUtils_GetCrossLanguageOption](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getcrosslanguageoption).

The following example demonstrates how to set and obtain cross-language options for ArkTS imperative nodes.

```ts
// Index.ets
import { NodeController, UIContext, FrameNode, typeNode, BuilderNode } from '@kit.ArkUI';

@Builder
function insideScroll() {
  Column() {
    ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], (item: number) => {
      Text(item.toString())
        .width("75%")
        .height(50)
        .backgroundColor(0xFFFFFF)
        .borderRadius(15)
        .fontSize(30)
        .textAlign(TextAlign.Center)
        .margin({ top: 10 })
    }, (item: number) => item.toString())
  }
  .width("100%")
}

class MyNodeController extends NodeController {
  uiContext: UIContext | null = null;
  rootNode: FrameNode | null = null;
  scrollNode: FrameNode | null = null;
  scroller: Scroller = new Scroller();

  makeNode(uiContext: UIContext): FrameNode | null {
    this.uiContext = uiContext;
    this.rootNode = new FrameNode(uiContext);
    this.rootNode.commonAttribute.width("80%").height("50%").borderWidth(2).margin(15);
    const scroll = typeNode.createNode(uiContext, 'Scroll');
    scroll.initialize(this.scroller).id("scroll");
    this.scrollNode = scroll;
    this.rootNode.appendChild(this.scrollNode);
    const builderNode = new BuilderNode(uiContext);
    builderNode.build(wrapBuilder(insideScroll));
    this.scrollNode?.appendChild(builderNode.getFrameNode());
    return this.rootNode;
  }
}

@Entry
@Component
struct CrossLanguage {
  myNodeController: MyNodeController = new MyNodeController()
  @State attributeSetting: boolean = false;
  @State getCrossLanguageOptions: string = '{"attributeSetting": false}';

  build() {
    Scroll() {
      Column({ space: 15 }) {
        Column() {
          Scroll() {
            Column() {
              NodeContainer(this.myNodeController)
              Button("setCrossLanguageOptions").margin({ bottom: 15})
                .onClick(() => {
                  this.attributeSetting = !this.attributeSetting;
                  this.myNodeController.scrollNode?.setCrossLanguageOptions({
                    attributeSetting: this.attributeSetting
                  });
                  // If attributeSetting is true, scrollNode supports attribute modification via non-ArkTS languages; otherwise, it does not.
                  this.getCrossLanguageOptions = JSON.stringify(this.myNodeController.scrollNode?.getCrossLanguageOptions());
                })
              Text("CrossLanguageOptions: " + this.getCrossLanguageOptions)
            }
          }.scrollBarColor(Color.Transparent)
        }
        .width('100%')
        .height(350)
        .backgroundColor(0xeeeeee)
        .id('Part_TS')
      }
      .width('100%')
    }.scrollBarColor(Color.Transparent)
  }
}
```

## Setting Cross-Language Node Attributes

After obtaining a node, if its cross-language configuration allows attribute setting, ArkTS can use the **getAttribute** API to access objects for modifying native node attributes, while the native side can use [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute) to modify ArkTS node attributes.

The following example creates an ArkTS [Scroll](../reference/apis-arkui/js-apis-arkui-frameNode.md#scroll12) node and modifies its properties on the native side.

1. Create an imperative node of type Scroll on the ArkTS side.

    ```ts
    // Index.ets
    import nativeNode from 'libentry.so';
    import { NodeController, UIContext, FrameNode, typeNode, BuilderNode, NodeContent } from '@kit.ArkUI';

    @Builder
    function insideScroll() {
      Column() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], (item: number) => {
          Text(item.toString())
            .width("75%")
            .height(50)
            .backgroundColor(0xFFFFFF)
            .borderRadius(15)
            .fontSize(30)
            .textAlign(TextAlign.Center)
            .margin({ top: 10 })
        }, (item: number) => item.toString())
      }
      .width("100%")
    }

    class MyNodeController extends NodeController {
      uiContext: UIContext | null = null;
      rootNode: FrameNode | null = null;
      scrollNode: FrameNode | null = null;
      scroller: Scroller = new Scroller();

      makeNode(uiContext: UIContext): FrameNode | null {
        this.uiContext = uiContext;
        this.rootNode = new FrameNode(uiContext);
        this.rootNode.commonAttribute.width("80%").height("50%").borderWidth(2).margin(15);
        const scroll = typeNode.createNode(uiContext, 'Scroll');
        scroll.initialize(this.scroller).id("scroll");
        this.scrollNode = scroll;
        this.rootNode.appendChild(this.scrollNode);
        const builderNode = new BuilderNode(uiContext);
        builderNode.build(wrapBuilder(insideScroll));
        this.scrollNode?.appendChild(builderNode.getFrameNode());
        return this.rootNode;
      }
    }

    @Entry
    @Component
    struct CrossLanguage {
      private myNodeController: MyNodeController = new MyNodeController();
      @State attributeSetting: boolean = false;
      @State getCrossLanguageOptions: string = '{"attributeSetting": false}';
      private rootSlot = new NodeContent();

      aboutToAppear(): void {
        nativeNode.createNativeRoot(this.rootSlot);
      }

      build() {
        Scroll() {
          Column({ space: 15 }) {
            Column() {
              Scroll() {
                Column() {
                  NodeContainer(this.myNodeController)
                  Button("setCrossLanguageOptions").margin({ bottom: 15})
                    .onClick(() => {
                      this.attributeSetting = !this.attributeSetting;
                      this.myNodeController.scrollNode?.setCrossLanguageOptions({
                        attributeSetting: this.attributeSetting
                      });
                      // If attributeSetting is true, scrollNode supports attribute modification via non-ArkTS languages; otherwise, it does not.
                      this.getCrossLanguageOptions = JSON.stringify(this.myNodeController.scrollNode?.getCrossLanguageOptions());
                    })
                  Text("CrossLanguageOptions: " + this.getCrossLanguageOptions)
                }
              }.scrollBarColor(Color.Transparent)
            }
            .width('100%')
            .height(350)
            .backgroundColor(0xeeeeee)
            .id('Part_TS')

            Column() {
              ContentSlot(this.rootSlot)
            }
            .width(500)
            .height(400)
            .id('Part_C')
          }
          .width('100%')
        }.scrollBarColor(Color.Transparent)
      }
    }
    ```

2. Create **CrossLanguageExample.h** to obtain the target node (created in ArkTS) and set its properties.

    ```c
    // CrossLanguageExample.h
    #ifndef MYAPPLICATION_CROSSLANGUAGEEXAMPLE_H
    #define MYAPPLICATION_CROSSLANGUAGEEXAMPLE_H

    #include "ArkUINode.h"
    #include <hilog/log.h>

    namespace NativeModule {

    std::shared_ptr<ArkUIBaseNode> CreateCrossLanguageExample() {
        auto nodeAPI = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
        
        // Create the root Scroll node.
        ArkUI_NodeHandle scroll = nodeAPI->createNode(ARKUI_NODE_SCROLL);
        ArkUI_NumberValue length_value[] = {{.f32 = 480}};
        ArkUI_AttributeItem length_item = {length_value, sizeof(length_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(scroll, NODE_WIDTH, &length_item);
        ArkUI_NumberValue length_value1[] = {{.f32 = 650}};
        ArkUI_AttributeItem length_item1 = {length_value1, sizeof(length_value1) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(scroll, NODE_HEIGHT, &length_item1);
        ArkUI_AttributeItem scroll_id = {.string = "Scroll_CAPI"};
        nodeAPI->setAttribute(scroll, NODE_ID, &scroll_id);
        
        // Create a Column node.
        ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
        ArkUI_NumberValue value[] = {480};
        ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(column, NODE_WIDTH, &item);
        ArkUI_NumberValue column_bc[] = {{.u32 = 0xFFF00BB}};
        ArkUI_AttributeItem column_item = {column_bc, 1};
        nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &column_item);
        ArkUI_AttributeItem column_id = {.string = "Column_CAPI"};
        nodeAPI->setAttribute(column, NODE_ID, &column_id);
        
        // Create a Text node.
        ArkUI_NodeHandle text0 = nodeAPI->createNode(ARKUI_NODE_TEXT);
        ArkUI_NumberValue text_width[] = {300};
        ArkUI_AttributeItem text_item0 = {text_width, sizeof(text_width) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(text0, NODE_WIDTH, &text_item0);
        ArkUI_NumberValue text_height[] = {50};
        ArkUI_AttributeItem text_item1 = {text_height, sizeof(text_height) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(text0, NODE_HEIGHT, &text_item1);
        ArkUI_AttributeItem text_item = {.string = "C sets attributes of TypeScript-created node"};
        nodeAPI->setAttribute(text0, NODE_TEXT_CONTENT, &text_item);
        ArkUI_NumberValue margin[] = {10};
        ArkUI_AttributeItem item_margin = {margin, sizeof(margin) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(text0, NODE_MARGIN, &item_margin);
        
        // Create a Row node.
        ArkUI_NodeHandle row0 = nodeAPI->createNode(ARKUI_NODE_ROW);
        ArkUI_NumberValue width_value[] = {{.f32=330}};
        ArkUI_AttributeItem width_item = {width_value, sizeof(width_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(row0, NODE_WIDTH, &width_item);
        nodeAPI->setAttribute(row0, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(row0, NODE_MARGIN, &item_margin);
        
        // Create a Button node.
        ArkUI_NodeHandle bt0 = nodeAPI->createNode(ARKUI_NODE_BUTTON);
        ArkUI_NumberValue btn_width[] = {150};
        ArkUI_AttributeItem btn_item0 = {btn_width, sizeof(btn_width) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(bt0, NODE_WIDTH, &btn_item0);
        nodeAPI->setAttribute(bt0, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(bt0, NODE_MARGIN, &item_margin);
        ArkUI_AttributeItem bt0_item = {.string = "scrollBarColor"};
        nodeAPI->setAttribute(bt0, NODE_BUTTON_LABEL, &bt0_item);
        nodeAPI->registerNodeEvent(bt0, NODE_ON_CLICK, 0, nullptr);
        
        ArkUI_NodeHandle bt1 = nodeAPI->createNode(ARKUI_NODE_BUTTON);
        nodeAPI->setAttribute(bt1, NODE_WIDTH, &btn_item0);
        nodeAPI->setAttribute(bt1, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(bt1, NODE_MARGIN, &item_margin);
        ArkUI_AttributeItem bt1_item = {.string = "scrollBarWidth"};
        nodeAPI->setAttribute(bt1, NODE_BUTTON_LABEL, &bt1_item);
        nodeAPI->registerNodeEvent(bt1, NODE_ON_CLICK, 1, nullptr);
        
        // Register events.
        auto onClick = [](ArkUI_NodeEvent *event) {
            ArkUI_NodeHandle node = OH_ArkUI_NodeEvent_GetNodeHandle(event);
            auto nodeAPI = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
            
            if (OH_ArkUI_NodeEvent_GetTargetId(event) == 0) {  // scrollBarColor
                ArkUI_NodeHandle node_ptr = nullptr;
                OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("scroll", &node_ptr);
                try {
                    ArkUI_NumberValue scroll_color_value[] = {{.u32 = 0xff00ff00}};
                    ArkUI_AttributeItem scroll_color_item = {scroll_color_value, sizeof(scroll_color_value) / sizeof(ArkUI_NumberValue)};
                    nodeAPI->setAttribute(node_ptr, NODE_SCROLL_BAR_COLOR, &scroll_color_item);
                } catch (...) {
                    OH_LOG_Print(LOG_APP, LOG_ERROR, 0xFF00, "CrossLanguageExample", "crossLanguage setAttribute error");
                }
            }
            
            if (OH_ArkUI_NodeEvent_GetTargetId(event) == 1) {  // scrollBarWidth
                ArkUI_NodeHandle node_ptr = nullptr;
                OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("scroll", &node_ptr);
                try {
                    ArkUI_NumberValue scroll_width_value[] = {{20}};
                    ArkUI_AttributeItem scroll_width_item = {scroll_width_value, sizeof(scroll_width_value) / sizeof(ArkUI_NumberValue)};
                    nodeAPI->setAttribute(node_ptr, NODE_SCROLL_BAR_WIDTH, &scroll_width_item);
                } catch (...) {
                    OH_LOG_Print(LOG_APP, LOG_ERROR, 0xFF00, "CrossLanguageExample", "crossLanguage setAttribute error");
                }
            }
        };
        nodeAPI->registerNodeEventReceiver(onClick);
        
        // Add nodes.
        nodeAPI->addChild(scroll, column);
        nodeAPI->addChild(column, text0);
        nodeAPI->addChild(column, row0);
        nodeAPI->addChild(row0, bt0);
        nodeAPI->addChild(row0, bt1);
        
        return std::make_shared<ArkUINode>(scroll);
    }
    } // namespace NativeModule

    #endif // MYAPPLICATION_CROSSLANGUAGEEXAMPLE_H
    ```

3. Mount the native node in **NativeEntry.cpp**.

    ```c
    // NativeEntry.cpp


    #include <arkui/native_node_napi.h>
    #include <js_native_api.h>
    #include "NativeEntry.h"
    #include "CrossLanguageExample.h"


    namespace NativeModule {


    napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
        size_t argc = 1;
        napi_value args[1] = {nullptr};


        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);


        // Obtain NodeContent.
        ArkUI_NodeContentHandle contentHandle;
        OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
        NativeEntry::GetInstance()->SetContentHandle(contentHandle);


        // Create a node.
        auto node = CreateCrossLanguageExample();


        // Keep the native-side object in the management class to maintain its lifecycle.
        NativeEntry::GetInstance()->SetRootNode(node);
        return nullptr;
    }


    napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
        // Release the native-side object from the management class.
        NativeEntry::GetInstance()->DisposeRootNode();
        return nullptr;
    }


    } // namespace NativeModule
    ```

4. Update the **CMakeLists.txt** file and add the required link libraries.

   ```c
   // CMakeLists.txt
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.5.0)
   project(CAPI_DEMO)
 
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
 
   if(DEFINED PACKAGE_FIND_FILE)
       include(${PACKAGE_FIND_FILE})
   endif()
 
   include_directories(${NATIVERENDER_ROOT_PATH}
                     ${NATIVERENDER_ROOT_PATH}/include)
 
   add_library(entry SHARED napi_init.cpp NativeEntry.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so hilog_ndk.z.so)
   ```

5. Run the program. On the ArkTS side, click the button to set **attributeSetting** to **true**. On the native side, click the buttons to set the **Scroll** component's scrollbar color and width.

![crossLanguageDemo](figures/crossLanguageDemo.gif)

## Node Types Supporting Cross-Language Attribute Setting

Only the following node types support cross-language attribute setting. The native side must use [OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getattachednodehandlebyid) to obtain the node whose attributes are to be modified. Cross-language attribute setting is not supported for target nodes obtained via [OH_ArkUI_GetNodeHandleFromNapiValue](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnodehandlefromnapivalue).

| ArkTS [TypedFrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#typedframenode12) type| Native [ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype) type| ArkTS Attribute Getter| ArkTS Controller Getter/Binding|
| -------- | -------- | -------- | -------- |
| [Button](../reference/apis-arkui/js-apis-arkui-frameNode.md#button12) | ARKUI_NODE_BUTTON | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributebutton20) | NA |
| [Checkbox](../reference/apis-arkui/js-apis-arkui-frameNode.md#checkbox18) | ARKUI_NODE_CHECKBOX | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributecheckbox20) | NA |
| [Radio](../reference/apis-arkui/js-apis-arkui-frameNode.md#radio18) | ARKUI_NODE_RADIO | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeradio20) | NA |
| [Slider](../reference/apis-arkui/js-apis-arkui-frameNode.md#slider18) | ARKUI_NODE_SLIDER | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeslider20) | NA |
| [Toggle](../reference/apis-arkui/js-apis-arkui-frameNode.md#toggle18) | ARKUI_NODE_TOGGLE | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributetoggle20) | NA |
| [Progress](../reference/apis-arkui/js-apis-arkui-frameNode.md#progress12) | ARKUI_NODE_PROGRESS | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeprogress20) | NA |
| [LoadingProgress](../reference/apis-arkui/js-apis-arkui-frameNode.md#loadingprogress12) | ARKUI_NODE_LOADING_PROGRESS | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeloadingprogress20) | NA |
| [Image](../reference/apis-arkui/js-apis-arkui-frameNode.md#image12) | ARKUI_NODE_IMAGE | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeimage20) | NA |
| [XComponent](../reference/apis-arkui/js-apis-arkui-frameNode.md#xcomponent12) | ARKUI_NODE_XCOMPONENT | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributexcomponent20) | getController |
| [Column](../reference/apis-arkui/js-apis-arkui-frameNode.md#column12) | ARKUI_NODE_COLUMN | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributecolumn20) | NA |
| [Row](../reference/apis-arkui/js-apis-arkui-frameNode.md#row12) | ARKUI_NODE_ROW | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributerow20) | NA |
| [Stack](../reference/apis-arkui/js-apis-arkui-frameNode.md#stack12) | ARKUI_NODE_STACK | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributestack20) | NA |
| [Flex](../reference/apis-arkui/js-apis-arkui-frameNode.md#flex12) | ARKUI_NODE_FLEX | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeflex20) | NA |
| [RelativeContainer](../reference/apis-arkui/js-apis-arkui-frameNode.md#relativecontainer12) | ARKUI_NODE_RELATIVE_CONTAINER | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributerelativecontainer20) | NA |
| [Swiper](../reference/apis-arkui/js-apis-arkui-frameNode.md#swiper12) | ARKUI_NODE_SWIPER | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeswiper20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollerswiper20) |
| [Scroll](../reference/apis-arkui/js-apis-arkui-frameNode.md#scroll12) | ARKUI_NODE_SCROLL | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributescroll15) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollerscroll15) |
| [List](../reference/apis-arkui/js-apis-arkui-frameNode.md#list12) | ARKUI_NODE_LIST | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributelist20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollerlist20) |
| [ListItem](../reference/apis-arkui/js-apis-arkui-frameNode.md#listitem12) | ARKUI_NODE_LIST_ITEM | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributelistitem20) | NA |
| [ListItemGroup](../reference/apis-arkui/js-apis-arkui-frameNode.md#listitemgroup12) | ARKUI_NODE_LIST_ITEM_GROUP | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributelistitemgroup20) | NA |
| [WaterFlow](../reference/apis-arkui/js-apis-arkui-frameNode.md#waterflow12) | ARKUI_NODE_WATER_FLOW | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributewaterflow20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollerwaterflow20) |
| [FlowItem](../reference/apis-arkui/js-apis-arkui-frameNode.md#flowitem12) | ARKUI_NODE_FLOW_ITEM | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributeflowitem20) | NA |
| [Grid](../reference/apis-arkui/js-apis-arkui-frameNode.md#grid14) | ARKUI_NODE_GRID | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributegrid20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollergrid20) |
| [GridItem](../reference/apis-arkui/js-apis-arkui-frameNode.md#griditem14) | ARKUI_NODE_GRID_ITEM | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributegriditem20) | NA |
| [Text](../reference/apis-arkui/js-apis-arkui-frameNode.md#text12) | ARKUI_NODE_TEXT | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributetext20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollertext20) |
| [TextInput](../reference/apis-arkui/js-apis-arkui-frameNode.md#textinput12) | ARKUI_NODE_TEXT_INPUT | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributetextinput20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollertextinput20) |
| [TextArea](../reference/apis-arkui/js-apis-arkui-frameNode.md#textarea14) | ARKUI_NODE_TEXT_AREA | [getAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#getattributetextarea20) | [bindController](../reference/apis-arkui/js-apis-arkui-frameNode.md#bindcontrollertextarea20) |