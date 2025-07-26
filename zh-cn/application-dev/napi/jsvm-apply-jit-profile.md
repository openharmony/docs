# JSVM-API 申请JIT权限指导

JIT(Just In Time) 即时编译功能会引入任意代码注入的安全风险，为保护应用安全、维护鸿蒙纯净生态，系统默认关闭JSVM的JIT功能，若开发者期望使用该功能， 需要向应用市场（AppGallery Connect，简称为AGC）提交ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY受限ACL权限的申请， 并在附带材料中说明使用JSVM引擎JIT功能的具体场景。在权限审批通过后， 开发者可从AGC网站上更新profile证书， 并对应用重打包上架。权限申请及适配流程可参考《[申请使用受限权限](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/declare-permissions-in-acl-V5)》指导完成。


## 适配注意事项
1. 如果应用未申请相应的权限证书，却试图在配置文件中声明此权限，将会导致应用安装失败。
2. 若在编译时报以下错误日志`The ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission under requestPermissions must be a value that is predefined within the SDK or a custom one that you have included under definePermissions.`， 请将OpenHarmony SDK更新到最新版本(>=5.0.2.125版本)。
3. 在坚盾守护模式开启期间，操作系统将在全局范围内禁用JIT（即时编译）功能，此限制适用于所有应用程序，包括已获得ACL权限的特权应用，具体技术实现细节请参阅[JSVM 坚盾守护模式](jsvm-secure-shield-mode.md)。