# arkcompiler子系统Changelog

## cl.arkcompiler.1 JIT功能默认关闭，需申请权限证书并通过审核后启用

**访问级别**

公开接口

**变更原因**

JIT（Just In Time）即时编译功能可能带来任意代码注入的风险。为了保护应用安全并维护鸿蒙系统的纯净生态，系统默认关闭JSVM的JIT功能，采用解释执行方式执行JS代码。

**变更影响**

此变更涉及应用适配。

变更前：
默认开启JIT。

变更后：
默认关闭JIT，需申请权限证书后启用。关闭后，依赖JIT的wasm接口将无法执行，且JIT与解释执行在特定场景下存在性能差异。

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.1.0.51开始。

**变更的接口/组件**

| 接口                          | 影响                                                          |
| ------------------------------- | --------------------------------------------------------------- |
| OH\_JSVM\_CompileWasmModule   | 无 JIT 权限会返回 JIT\_MODE\_EXPECTED 状态码                      |
| OH\_JSVM\_CompileWasmFunction | 无 JIT 权限会返回 JIT\_MODE\_EXPECTED 状态码                      |
| OH\_JSVM\_CreateWasmCache     | 无 JIT 权限会返回 JIT\_MODE\_EXPECTED 状态码                      |
| OH\_JSVM\_RunScript           | 无 JIT 权限执行含wasm的脚本会失败，在特定场景下存在性能差异 |

**适配指导**

新上架应用若期望使用JIT权限，需向应用市场（AppGallery Connect，简称AGC）提交ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY受限ACL权限的申请， 并在附带材料中说明使用JSVM引擎JIT功能的具体场景。在权限审批通过后， 开发者可从AGC网站上更新profile证书， 并对应用重打包上架。权限申请及适配流程可参考《[申请使用受限权限](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/declare-permissions-in-acl-V5)》指导完成。

适配注意事项
1. 如果应用未申请相应的权限证书，却试图在配置文件中声明此权限，将会导致应用安装失败。
2. 若在编译时报以下错误日志`The ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission under requestPermissions must be a value that is predefined within the SDK or a custom one that you have included under definePermissions.`， 请将OpenHarmony SDK更新到最新版本(>=5.0.2.125版本)。