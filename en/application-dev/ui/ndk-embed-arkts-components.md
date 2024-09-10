# Embedding ArkTS Components


ArkUI on the native side offers a subset of ArkTS features, excluding certain capabilities such as declarative UI syntax, custom struct components, and advanced UI components.


For scenarios requiring ArkTS-specific features, ArkUI provides a mechanism to embed ArkTS components using [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md). This involves encapsulating ArkTS components and passing them to the native side, where they are converted into **ArkUI_NodeHandle** objects through the [OH_ArkUI_GetNodeHandleFromNapiValue](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getnodehandlefromnapivalue) API for component mounting.


> **NOTE**
>
> - **ArkUI_NodeHandle** objects obtained from **OH_ArkUI_GetNodeHandleFromNapiValue** are for child component parameters only, such as the second parameter of the [addChild](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addchild) API. Using such objects in other scenarios, such as setting attributes with [setAttribute](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#setattribute), will not take effect and will return an error code.
> 
> - To modify ArkTS components on the native side, construct update data using Node-APIs, and then call the [update](../reference/apis-arkui/js-apis-arkui-ComponentContent.md#update) API of **ComponentContent**.

