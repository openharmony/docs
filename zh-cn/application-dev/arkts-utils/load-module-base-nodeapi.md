# 基于Node-API加载模块

Node-API中的[napi_load_module](../napi/use-napi-load-module.md)接口的功能是在宿主线程中进行当前hap/hsp包工程内模块的加载，使用场景有限，但参数传递简便。[napi_load_module_with_info](../napi/use-napi-load-module-with-info.md)可支持宿主线程或子线程内加载har包、hsp包、native模块等多种文件类型，用法更加多样，但使用时必须标记所加载的包的信息。
