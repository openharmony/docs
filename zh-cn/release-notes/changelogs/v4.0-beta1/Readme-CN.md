# Readme

| 子系统         | 变更类型     | 变更说明                                                     |
| :------------- | ------------ | ------------------------------------------------------------ |
| 通用           | 校验增强     | [System API校验权限增强，只有系统应用允许使用system-api,三方应用使用system-api将返回202错误](changelogs-common.md) |
| 元能力         | 行为变更     | [apprecovery接口中RestartFlag枚举命名从特定故障发生后不重启改成了特定故障发生后重启](changelogs-ability.md) |
| 语言编译运行时 | 解析规则变更 | [LLVM解析格式变更,对于业务依赖version-script或gcc-toolchain选项的开发者,在沿用LLVM12配置文件或选项时,部分规则发生变化,可能会解析失败](changelogs-arkcompiler.md) |
| 语言编译运行时 | 校验增强     | [LLVM新增告警及已有告警增强,LLVM从12升级15,新增告警/对已有的告警校验增强](changelogs-arkcompiler.md) |
| 语言编译运行时 | 校验增强     | [LLVM emu-tls变更,对于LLVM12/LLVM15工具链混用的开发者,会产生libc++.so emu-tls符号无法找到的问题](changelogs-arkcompiler.md) |
| 语言编译运行时 | 校验增强     | [LLVM12~15官方变更差异继承新增特性及内部接口变更](changelogs-arkcompiler.md) |
| ArkUI          | 行为变更     | [修复Stack布局问题](changelogs-arkui.md)                     |
| ArkUI          | 默认值变更   | [List组件和Gird组件滚动条默认状态变更](changelogs-arkui.md)  |
| ArkUI          | UX变更       | [Button组件hover状态效果变更,由100-105%放大效果变更为0-5%](changelogs-arkui.md) |
| ArkUI          | UX变更       | [toast组件多行文本对齐方式由居中对齐变更为左对齐](changelogs-arkui.md) |
| 包管理         | 机制变更     | [安装hap时,hap中的文件不在解压到安装目录](changelogs-bundlemanager.md) |
| 全球化         | 接口扩展     | [getStringSync、getStringByNameSync接口能力扩展](changelogs-global.md) |
| 全球化         | 行为变更     | [资源获取rawfile文件描述符接口含义变更相较于之前的版本返回值发生了变化](changelogs-global.md) |
| 安全-huks      | 行为变更     | [解决在派生密钥/协商密钥时需传入HuksKeyStorageType中定义的类型](changelogs-huks.md) |
| 安全-huks      | 权限变更     | [attestKeyitem是基于设备证书链封装业务公钥对用户指定的密钥进行证明](changelogs-huks.md) |
| Web            | 新增入参     | [setResponseData接口支持Resource类型](changelogs-web.md)     |
| 资源调度       | 行为变更     | [提醒代理支持系统应用设置自定义按钮，并且自定义按钮可跳转指定应用界面](changelogs-resourceschedule.md) |
