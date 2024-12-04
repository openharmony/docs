# 基于Node-API加载模块

Node-API中的[napi_load_module](../napi/use-napi-load-module.md)接口的功能是在宿主线程中进行当前hap/hsp包工程内模块的加载，用法场景局限，但传参简单。[napi_load_module_with_info](../napi/use-napi-load-module-with-info.md)可支持宿主线程或子线程内加载har包、跨hsp包、native模块等多种文件类型，用法更加丰富，但使用时需要标记所加载包的信息。
