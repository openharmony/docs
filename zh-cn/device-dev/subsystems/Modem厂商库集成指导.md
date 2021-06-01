# Modem厂商库集成指导<a name="ZH-CN_TOPIC_0000001148928023"></a>

-   [编译设置](#section142111565210)
-   [调测验证（可选）](#section114621643195220)

## 编译设置<a name="section142111565210"></a>

Modem厂商库可通过BUILD.gn编译为一个动态库，在RIL Adapter启动时用dlopen方式加载到系统中，然后执行厂商库的初始化操作（参见[Modem厂商库初始化开发指导](Modem厂商库初始化开发指导.md)），BUILD.gn编写示例如下：

```
import("//build/ohos.gni")
RIL_ADAPTER = "//base/telephony"

ohos_shared_library("vendor") { // Modem厂商库名称
sources = [ // 编译源文件
  "vendorlib.c",
  "xxx.c",
]
include_dirs = [ // 包含的头文件目录
  "$RIL_ADAPTER/ril_adapter/include",
  "$RIL_ADAPTER/ril_adapter/interfaces/innerkits",
  "include",
]
deps = [ // 内部依赖
  "//drivers/adapter/uhdf2/osal:libhdf_utils"
]
external_deps = [ // 外部依赖
  "hilog:libhilog"
]
part_name = "ril_adapter"
subsystem_name = "telephony"
```

## 调测验证（可选）<a name="section114621643195220"></a>

编译完成后，查看out/ohos-arm-release/packages/phone/system/lib 目录下是否生成libvendor.z.so，若生成了libvendor.z.so库文件说明系统集成成功。

