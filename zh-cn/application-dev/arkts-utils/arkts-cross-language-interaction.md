# ArkTS跨语言交互
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

除了支持使用ArkTS开发外，开发者还可以通过Node-API实现ArkTS与C/C++(Native)的跨语言交互能力。

OpenHarmony的Node-API是基于Node.js社区版本的扩展实现，但与原生Node-API并不完全兼容。

开发者可参考[使用Node-API进行跨语言开发流程](../napi/use-napi-process.md)，基于[Node-API支持的数据类型](../napi/napi-data-types-interfaces.md#node-api的数据类型)和[接口](../reference/native-lib/napi.md)进行Native能力的开发和封装，并通过在ArkTS侧导入Native模块的方式实现跨语言调用。

[Node-API扩展能力接口](../napi/use-napi-about-extension.md)提供了增强功能，支持更灵活的ArkTS交互和自定义对象创建。开发者可结合Node-API的扩展能力进行功能扩展，并参考[Node-API开发规范](../napi/napi-guidelines.md)和[Node-API常见问题](../napi/use-napi-faqs.md)进行跨语言功能开发。
