# ArkTS Cross-language Interaction

In addition to using ArkTS for development, you can also use Node-APIs to implement cross-language interaction between ArkTS and C/C++ (Native).

The Node-APIs of OpenHarmony are extended versions of the Node.js community and are not fully compatible with the Node APIs of the Node.js community.

In the [Node-API Development Process](../napi/use-napi-process.md), you can use [Node-API data types](../napi/napi-data-types-interfaces.md#data-types) and [APIs](../reference/native-lib/napi.md#node-api) Develop and encapsulate native capabilities. After the native module is imported to ArkTS, cross-language interaction can be implemented.

[Node-API extension APIs](../napi/use-napi-about-extension.md) further extends the functions of NAPI and provides some additional interfaces for more flexible interaction and customization with ArkTS in the NAPI module. These interfaces can be used in scenarios such as creating custom ArkTS objects. For details, see [Node-API Development Specifications](../napi/napi-guidelines.md) and [Node-API FAQs](../napi/use-napi-faqs.md). Efficiently develop cross-language functions.
