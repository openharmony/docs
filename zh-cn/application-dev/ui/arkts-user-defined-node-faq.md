# 自定义节点常见问题
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

本文档将简单介绍自定义节点常见问题，并提供参考帮助。

## 自定义节点的子节点在页面退出后未立即回调自定义组件的aboutToDisappear方法

**问题现象**

自定义组件的[aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md)在其销毁的时候触发，页面销毁后未立即回调或者一直未触发相关回调则说明改自定义组件在页面销毁后未立即销毁。

**可能原因**

- 自定义组件存在父节点且其父节点未销毁。
- 自定义组件由[BuilderNode](./arkts-user-defined-arktsNode-builderNode.md)创建，且该前端对象既未销毁也未解除对后端自定义组件的引用。BuilderNode创建的时候默认持有后端节点的强引用。
- 使用了[OH_ArkUI_GetNodeHandleFromNapiValue](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnodehandlefromnapivalue)获取了BuilderNode或者ComponentContent对象中的root节点，该方法会导致后端节点的引用计数增加1。

**解决措施**

- 将需要释放的自定义组件从父节点上移除，排除父节点对自定义组件生命周期的影响。
- 自定义组件由[BuilderNode](./arkts-user-defined-arktsNode-builderNode.md)创建的场景下，调用[dispose](../reference/apis-arkui/js-apis-arkui-builderNode.md#dispose12)接口，立即释放前端BuilderNode对象对于后端节点的强引用。
- 对于使用了OH_ArkUI_GetNodeHandleFromNapiValue获取了BuilderNode或者ComponentContent对象中的root节点，
调用[OH_ArkUI_NodeAdapter_Dispose](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_dispose)将OH_ArkUI_GetNodeHandleFromNapiValue时候后增加的引用计数减去。

**代码示例**
