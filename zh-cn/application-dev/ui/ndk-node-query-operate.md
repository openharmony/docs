# 查询和操作自定义节点

NDK提供一系列节点查询、遍历、操作能力，通过使用以下接口，开发者可以高效地访问和操控节点。

## 查询节点uniqueId及通过uniqueId获取节点信息

uniqueId是系统分配的唯一标识的节点Id。

从API version 20开始，使用[OH_ArkUI_NodeUtils_GetNodeUniqueId](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_getnodeuniqueid)接口，可以获取目标节点的uniqueId。

从API version 20开始，使用[OH_ArkUI_NodeUtils_GetNodeHandleByUniqueId](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_getnodehandlebyuniqueid)接口，可以通过uniqueId获取目标节点的指针。

## 通过用户id获取节点信息

使用[OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_getattachednodehandlebyid)接口，可以通过用户设置的id获取目标节点的指针。

1. ArkTS侧接入Native组件。
    ```ts
    // GetNodeById.ets
    import nativeNode from 'libentry.so';
    import { NodeContent } from '@kit.ArkUI';

    @Entry
    @Component
    struct GetNodeById {
      private rootSlot = new NodeContent();

      aboutToAppear(): void {
        nativeNode.createNativeRoot(this.rootSlot);
      }

      build() {
        Scroll() {
          Column({ space: 15 }) {
            Column() {
              ContentSlot(this.rootSlot)
            }
          }
          .width('100%')
        }.scrollBarColor(Color.Transparent)
      }
    }
    ```

2. 新建`GetNodeByIdExample.h`文件，在其中创建Text节点并设置id属性，通过OH_ArkUI_NodeUtils_GetAttachedNodeHandleById接口拿到节点。
    ```c
    // GetNodeByIdExample.h
    #ifndef MYAPPLICATION_GETNODEBYID_H
    #define MYAPPLICATION_GETNODEBYID_H

    #include "ArkUINode.h"
    #include <hilog/log.h>

    namespace NativeModule {

    std::shared_ptr<ArkUIBaseNode> CreateGetNodeByIdExample() {
        auto nodeAPI = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
        
        // 创建传入事件节点结构体
        struct A {
            ArkUI_NodeHandle node;
        };
        A* a = new A;
        
        // 创建根节点Scroll
        ArkUI_NodeHandle scroll = nodeAPI->createNode(ARKUI_NODE_SCROLL);
        ArkUI_NumberValue length_value[] = {{.f32 = 480}};
        ArkUI_AttributeItem length_item = {length_value, sizeof(length_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(scroll, NODE_WIDTH, &length_item);
        ArkUI_NumberValue length_value1[] = {{.f32 = 650}};
        ArkUI_AttributeItem length_item1 = {length_value1, sizeof(length_value1) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(scroll, NODE_HEIGHT, &length_item1);
        ArkUI_AttributeItem scroll_id = {.string = "Scroll_CAPI"};
        nodeAPI->setAttribute(scroll, NODE_ID, &scroll_id);
        
        // 创建Column
        ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
        ArkUI_NumberValue value[] = {480};
        ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(column, NODE_WIDTH, &item);
        ArkUI_NumberValue column_bc[] = {{.u32 = 0xFFF00BB}};
        ArkUI_AttributeItem column_item = {column_bc, 1};
        nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &column_item);
        ArkUI_AttributeItem column_id = {.string = "Column_CAPI"};
        nodeAPI->setAttribute(column, NODE_ID, &column_id);
        
        // 创建Text
        ArkUI_NodeHandle text0 = nodeAPI->createNode(ARKUI_NODE_TEXT);
        ArkUI_NumberValue text_width[] = {300};
        ArkUI_AttributeItem text_item0 = {text_width, sizeof(text_width) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(text0, NODE_WIDTH, &text_item0);
        ArkUI_NumberValue text_height[] = {50};
        ArkUI_AttributeItem text_item1 = {text_height, sizeof(text_height) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(text0, NODE_HEIGHT, &text_item1);
        ArkUI_AttributeItem text_item = {.string = "示例Text节点"};
        nodeAPI->setAttribute(text0, NODE_TEXT_CONTENT, &text_item);
        ArkUI_NumberValue margin[] = {10};
        ArkUI_AttributeItem item_margin = {margin, sizeof(margin) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(text0, NODE_MARGIN, &item_margin);
        ArkUI_AttributeItem text0_id = {.string = "Text0_CAPI"};
        nodeAPI->setAttribute(text0, NODE_ID, &text0_id);
        a->node = text0;
        
        // 创建Row
        ArkUI_NodeHandle row0 = nodeAPI->createNode(ARKUI_NODE_ROW);
        ArkUI_NumberValue width_value[] = {{.f32=330}};
        ArkUI_AttributeItem width_item = {width_value, sizeof(width_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(row0, NODE_WIDTH, &width_item);
        nodeAPI->setAttribute(row0, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(row0, NODE_MARGIN, &item_margin);
        
        // 创建Button
        ArkUI_NodeHandle bt0 = nodeAPI->createNode(ARKUI_NODE_BUTTON);
        ArkUI_NumberValue btn_width[] = {150};
        ArkUI_AttributeItem btn_item0 = {btn_width, sizeof(btn_width) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(bt0, NODE_WIDTH, &btn_item0);
        nodeAPI->setAttribute(bt0, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(bt0, NODE_MARGIN, &item_margin);
        ArkUI_AttributeItem bt0_item = {.string = "GetAttachedNodeHandleById"};
        nodeAPI->setAttribute(bt0, NODE_BUTTON_LABEL, &bt0_item);
        nodeAPI->registerNodeEvent(bt0, NODE_ON_CLICK, 0, a);
        
        // 注册事件
        auto onClick = [](ArkUI_NodeEvent *event) {
            ArkUI_NodeHandle node = OH_ArkUI_NodeEvent_GetNodeHandle(event);
            auto nodeAPI = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
            
            if (OH_ArkUI_NodeEvent_GetTargetId(event) == 0) {  // GetAttachedNodeHandleById
                A* a = (A*)OH_ArkUI_NodeEvent_GetUserData(event);
                ArkUI_NodeHandle node = nullptr;
                auto res = OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("Text0_CAPI", &node);
                if (node == a->node) {
                    OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "GetNodeByIdExample", "get Text0_CAPI success");
                } else {
                    OH_LOG_Print(LOG_APP, LOG_ERROR, 0xFF00, "GetNodeByIdExample", "get Text0_CAPI failed");
                }
            }
        };
        nodeAPI->registerNodeEventReceiver(onClick);
        
        // 节点添加
        nodeAPI->addChild(scroll, column);
        nodeAPI->addChild(column, text0);
        nodeAPI->addChild(column, row0);
        nodeAPI->addChild(row0, bt0);
        
        return std::make_shared<ArkUINode>(scroll);
    }
    } // namespace NativeModule

    #endif //MYAPPLICATION_GETNODEBYID_H
    ```

3. 在`NativeEntry.cpp`中，挂载Native节点。
    ```c
    // NativeEntry.cpp


    #include <arkui/native_node_napi.h>
    #include <hilog/log.h>
    #include <js_native_api.h>
    #include "NativeEntry.h"
    #include "GetNodeByIdExample.h"


    namespace NativeModule {


    napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
        size_t argc = 1;
        napi_value args[1] = {nullptr};


        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);


        // 获取NodeContent
        ArkUI_NodeContentHandle contentHandle;
        OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
        NativeEntry::GetInstance()->SetContentHandle(contentHandle);


        // 创建节点
        auto node = CreateGetNodeByIdExample();


        // 保持Native侧对象到管理类中，维护生命周期。
        NativeEntry::GetInstance()->SetRootNode(node);
        return nullptr;
    }


    napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
        // 从管理类中释放Native侧对象。
        NativeEntry::GetInstance()->DisposeRootNode();
        return nullptr;
    }


    } // namespace NativeModule
    ```

4. 运行程序，点击按钮，打印节点获取成功信息。

## 移动节点

使用[OH_ArkUI_NodeUtils_MoveTo](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_moveto)接口，可以将Native节点移动到新的父节点下，从而按需改变节点树结构。

> **说明：**
>
> 当前仅支持以下类型的[ArkUI_NodeType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodetype)进行移动操作：ARKUI_NODE_STACK、ARKUI_NODE_XCOMPONENT、ARKUI_NODE_EMBEDDED_COMPONENT。对于其他类型的节点，移动操作不会生效。

1. ArkTS侧接入Native组件。
    ```ts
    // MoveTo.ets
    import nativeNode from 'libentry.so';
    import { NodeContent } from '@kit.ArkUI';

    @Entry
    @Component
    struct MoveTo {
      private rootSlot = new NodeContent();

      aboutToAppear(): void {
        nativeNode.createNativeRoot(this.rootSlot);
      }

      build() {
        Scroll() {
          Column({ space: 15 }) {
            Column() {
              ContentSlot(this.rootSlot)
            }
          }
          .width('100%')
        }.scrollBarColor(Color.Transparent)
      }
    }
    ```

2. 新建`MoveTo.h`文件，在其中创建Stack节点，通过OH_ArkUI_NodeUtils_MoveTo接口移动Stack节点。
    ```c
    // MoveToExample.h
    #ifndef MYAPPLICATION_MOVETO_H
    #define MYAPPLICATION_MOVETO_H

    #include "ArkUINode.h"
    #include <hilog/log.h>

    namespace NativeModule {

    std::shared_ptr<ArkUIBaseNode> CreateMoveToExample() {
        auto nodeAPI = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
        
        // 创建传入事件节点结构体
        struct A {
            ArkUI_NodeHandle node;
            ArkUI_NodeHandle targetParent;
        };
        A* a = new A;
        
        // 创建根节点Scroll
        ArkUI_NodeHandle scroll = nodeAPI->createNode(ARKUI_NODE_SCROLL);
        ArkUI_NumberValue length_value[] = {{.f32 = 480}};
        ArkUI_AttributeItem length_item = {length_value, sizeof(length_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(scroll, NODE_WIDTH, &length_item);
        ArkUI_NumberValue length_value1[] = {{.f32 = 650}};
        ArkUI_AttributeItem length_item1 = {length_value1, sizeof(length_value1) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(scroll, NODE_HEIGHT, &length_item1);
        ArkUI_AttributeItem scroll_id = {.string = "Scroll_CAPI"};
        nodeAPI->setAttribute(scroll, NODE_ID, &scroll_id);
        
        // 创建Column
        ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
        ArkUI_NumberValue value[] = {480};
        ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(column, NODE_WIDTH, &item);
        ArkUI_AttributeItem column_id = {.string = "Column_CAPI"};
        nodeAPI->setAttribute(column, NODE_ID, &column_id);
        
        // 创建Row
        ArkUI_NodeHandle row0 = nodeAPI->createNode(ARKUI_NODE_ROW);
        ArkUI_NumberValue width_value[] = {{.f32=330}};
        ArkUI_AttributeItem width_item = {width_value, sizeof(width_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(row0, NODE_WIDTH, &width_item);
        nodeAPI->setAttribute(row0, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(row0, NODE_MARGIN, &item_margin);
        
        ArkUI_NodeHandle row1 = nodeAPI->createNode(ARKUI_NODE_ROW);
        nodeAPI->setAttribute(row1, NODE_WIDTH, &width_item);
        nodeAPI->setAttribute(row1, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(row1, NODE_MARGIN, &item_margin);
        a->targetParent = row1;
        
        ArkUI_NodeHandle row2 = nodeAPI->createNode(ARKUI_NODE_ROW);
        nodeAPI->setAttribute(row2, NODE_WIDTH, &width_item);
        nodeAPI->setAttribute(row2, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(row2, NODE_MARGIN, &item_margin);
        
        // 创建Stack
        ArkUI_NodeHandle stack0 = nodeAPI->createNode(ARKUI_NODE_STACK);
        ArkUI_NumberValue stack_value[] = {{.f32=50}};
        ArkUI_AttributeItem stack_item1 = {stack_value, sizeof(width_value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(stack0, NODE_WIDTH, &stack_item1);
        nodeAPI->setAttribute(stack0, NODE_HEIGHT, &stack_item1);
        ArkUI_NumberValue stack_bc[] = {{.u32 = 0xFFFFB6C1}};
        ArkUI_AttributeItem stack_item2 = {stack_bc, 1};
        nodeAPI->setAttribute(stack0, NODE_BACKGROUND_COLOR, &stack_item2);
        a->node = stack0;
        
        ArkUI_NodeHandle stack1 = nodeAPI->createNode(ARKUI_NODE_STACK);
        nodeAPI->setAttribute(stack1, NODE_WIDTH, &stack_item1);
        nodeAPI->setAttribute(stack1, NODE_HEIGHT, &stack_item1);
        ArkUI_NumberValue stack_bc1[] = {{.u32 = 0xFF6495ED}};
        ArkUI_AttributeItem stack_item3 = {stack_bc1, 1};
        nodeAPI->setAttribute(stack1, NODE_BACKGROUND_COLOR, &stack_item3);
        
        ArkUI_NodeHandle stack2 = nodeAPI->createNode(ARKUI_NODE_STACK);
        nodeAPI->setAttribute(stack2, NODE_WIDTH, &stack_item1);
        nodeAPI->setAttribute(stack2, NODE_HEIGHT, &stack_item1);
        ArkUI_NumberValue stack_bc2[] = {{.u32 = 0xFF90EE90}};
        ArkUI_AttributeItem stack_item4 = {stack_bc2, 1};
        nodeAPI->setAttribute(stack2, NODE_BACKGROUND_COLOR, &stack_item4);
        
        ArkUI_NodeHandle stack3 = nodeAPI->createNode(ARKUI_NODE_STACK);
        nodeAPI->setAttribute(stack3, NODE_WIDTH, &stack_item1);
        nodeAPI->setAttribute(stack3, NODE_HEIGHT, &stack_item1);
        nodeAPI->setAttribute(stack3, NODE_BACKGROUND_COLOR, &stack_item2);
        
        ArkUI_NodeHandle stack4 = nodeAPI->createNode(ARKUI_NODE_STACK);
        nodeAPI->setAttribute(stack4, NODE_WIDTH, &stack_item1);
        nodeAPI->setAttribute(stack4, NODE_HEIGHT, &stack_item1);
        nodeAPI->setAttribute(stack4, NODE_BACKGROUND_COLOR, &stack_item3);
        
        ArkUI_NodeHandle stack5 = nodeAPI->createNode(ARKUI_NODE_STACK);
        nodeAPI->setAttribute(stack5, NODE_WIDTH, &stack_item1);
        nodeAPI->setAttribute(stack5, NODE_HEIGHT, &stack_item1);
        nodeAPI->setAttribute(stack5, NODE_BACKGROUND_COLOR, &stack_item4);
        
        // 创建Button
        ArkUI_NodeHandle bt0 = nodeAPI->createNode(ARKUI_NODE_BUTTON);
        ArkUI_NumberValue btn_width[] = {150};
        ArkUI_AttributeItem btn_item0 = {btn_width, sizeof(btn_width) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(bt0, NODE_WIDTH, &btn_item0);
        nodeAPI->setAttribute(bt0, NODE_HEIGHT, &text_item1);
        nodeAPI->setAttribute(bt0, NODE_MARGIN, &item_margin);
        ArkUI_AttributeItem bt0_item = {.string = "MoveTo"};
        nodeAPI->setAttribute(bt0, NODE_BUTTON_LABEL, &bt0_item);
        nodeAPI->registerNodeEvent(bt0, NODE_ON_CLICK, 0, a);
        
        // 注册事件
        auto onClick = [](ArkUI_NodeEvent *event) {
            ArkUI_NodeHandle node = OH_ArkUI_NodeEvent_GetNodeHandle(event);
            auto nodeAPI = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
            
            if (OH_ArkUI_NodeEvent_GetTargetId(event) == 0) {  // MoveTo
                A* a = (A*)OH_ArkUI_NodeEvent_GetUserData(event);
                auto res = OH_ArkUI_NodeUtils_MoveTo(a->node, a->targetParent, 2);
            }
        };
        nodeAPI->registerNodeEventReceiver(onClick);
        
        // 节点添加
        nodeAPI->addChild(scroll, column);
        nodeAPI->addChild(column, row0);
        nodeAPI->addChild(column, row1);
        nodeAPI->addChild(column, row2);
        nodeAPI->addChild(row0, stack0);
        nodeAPI->addChild(row0, stack1);
        nodeAPI->addChild(row0, stack2);
        nodeAPI->addChild(row1, stack3);
        nodeAPI->addChild(row1, stack4);
        nodeAPI->addChild(row1, stack5);
        nodeAPI->addChild(row2, bt0);
        
        return std::make_shared<ArkUINode>(scroll);
    }
    } // namespace NativeModule

    #endif //MYAPPLICATION_MOVETO_H
    ```

3. 在`NativeEntry.cpp`中，挂载Native节点。
    ```c
    // NativeEntry.cpp


    #include <arkui/native_node_napi.h>
    #include <hilog/log.h>
    #include <js_native_api.h>
    #include "NativeEntry.h"
    #include "MoveToExample.h"


    namespace NativeModule {


    napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
        size_t argc = 1;
        napi_value args[1] = {nullptr};


        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);


        // 获取NodeContent
        ArkUI_NodeContentHandle contentHandle;
        OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
        NativeEntry::GetInstance()->SetContentHandle(contentHandle);


        // 创建节点
        auto node = CreateMoveToExample();


        // 保持Native侧对象到管理类中，维护生命周期。
        NativeEntry::GetInstance()->SetRootNode(node);
        return nullptr;
    }


    napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
        // 从管理类中释放Native侧对象。
        NativeEntry::GetInstance()->DisposeRootNode();
        return nullptr;
    }


    } // namespace NativeModule
    ```

4. 运行程序，点击按钮，Stack节点会移动到目标位置。

![moveToNativeDemo](figures/moveToNativeDemo.gif)