# ArkTS Cross-Language Interaction
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

In addition to using ArkTS for development, you can also use Node-API to implement cross-language interaction between ArkTS and C/C++ (native).

OpenHarmony Node-API is an extended version of Node API in the Node.js community but does not fully align with it.

In the [Node-API development process](../napi/use-napi-process.md), you can use the [data types supported by Node-API](../napi/napi-data-types-interfaces.md#data-types) and [available APIs](../reference/native-lib/napi.md) to develop and encapsulate native capabilities. By importing the native module in ArkTS, cross-language interaction can be achieved.

[Node-API extension APIs](../napi/use-napi-about-extension.md) provide enhanced features for more flexible ArkTS interactions and custom object creation. You can also refer to [Node-API Development Specifications](../napi/napi-guidelines.md) and [Node-API FAQs](../napi/use-napi-faqs.md) when developing cross-language features using extended Node-API capabilities.
