# ArkTS Cross-Language Interaction

In addition to supporting development with ArkTS, you can use Node-API to implement cross-language interaction between ArkTS and C/C++ (native).

OpenHarmony Node-API is an extended version of Node API in the Node.js community but does not fully align with it.

In the [Node-API development process](../napi/use-napi-process.md), you can use the [data types supported by Node-API](../napi/napi-data-types-interfaces.md#data-types) and [available APIs](../reference/native-lib/napi.md#node-api) to develop and encapsulate native capabilities. By importing the native module in ArkTS, cross-language interaction can be achieved.

[Node-API extension APIs](../napi/use-napi-about-extension.md) further extends the functionalities of Node-API by providing additional interfaces for more flexible interactions and customizations with ArkTS within the Node-API module. These interfaces can be used in scenarios such as creating custom ArkTS objects. You can also refer to [Node-API Development Specifications](../napi/napi-guidelines.md) and [Node-API FAQs](../napi/use-napi-faqs.md) to efficiently develop cross-language features.
