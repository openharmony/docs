# ArkTS跨语言交互

除了支持使用ArkTS进行开发外，开发者还可以通过使用Node-API实现ArkTS和C/C++（Native）的跨语言交互。

其中，OpenHarmony的Node-API，是对Node.js社区的拓展版本，与Node.js社区的Node API并不完全兼容。

在[使用Node-API进行跨语言开发流程](../napi/use-napi-process.md)中，开发者可以根据[Node-API支持的数据类型](../napi/napi-data-types-interfaces.md#node-api的数据类型)和[接口](../reference/native-lib/napi.md#node-api)情况，进行Native能力的开发和封装，通过导入模块的方式在ArkTS侧导入Native模块后，即可实现跨语言交互。

[Node-API扩展能力接口](../napi/use-napi-about-extension.md)进一步扩展了NAPI的功能，提供了一些额外的接口，用于在NAPI模块中与ArkTS进行更灵活的交互和定制，这些接口可以用于创建自定义ArkTS对象等场景。同时，开发者还可参考[Node-API开发规范](../napi/napi-guidelines.md)和[Node-API常见问题](../napi/use-napi-faqs.md)高效地进行跨语言功能开发。
