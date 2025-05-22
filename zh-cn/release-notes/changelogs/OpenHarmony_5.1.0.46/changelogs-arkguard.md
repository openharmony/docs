# 方舟运行时子系统变更说明

## cl.arkcompiler.1 默认不合并依赖混淆规则变更说明

**访问级别**

其他

**变更原因**

混淆默认合并依赖混淆规则，由于部分开发者不了解混淆机制，在发布的三方库中的obfuscation.txt文件中引入了混淆开关选项，其它应用依赖这些三方库后出现应用启动崩溃，且开发者无法直接感知这些三方库引入了混淆开关。

**变更影响**

此变更涉及应用适配。

变更前:  

编译一个模块时，生效的混淆规则为当前模块所有混淆配置与依赖模块及三方库**所有混淆配置**合并后的结果：

即如果当前模块、依赖的HAR模块、依赖的三方库中混淆配置如下：

```
// current-obfuscation-rules.txt
-enable-toplevel-obfuscation
-keep-global-name
currentVar

// dependencyHar-consumer-rule.txt
-enable-property-obfuscation
-keep-global-name
harVar
-keep-property-name
harProp

// dependencyThirdParty-obfuscation.txt
-compact
-keep-property-name
thirdPartyProp
```

那么编译当前模块时生效的混淆规则为：

```
-enable-toplevel-obfuscation
-enable-property-obfuscation
-compact
-keep-global-name
currentVar
harVar
-keep-property-name
harProp
thirdPartyProp
```

变更后:

编译一个模块时，生效的混淆规则为当前模块所有混淆配置与依赖模块及三方库的**混淆保留选项**合并后的结果：


即对于上面的例子，编译当前模块时生效的混淆规则为：
```
-enable-toplevel-obfuscation
-keep-global-name
currentVar
harVar
-keep-property-name
harProp
thirdPartyProp
```

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony 5.1.0.46 版本开始。

**变更的接口/组件**

不涉及。

**适配指导**

在当前编译模块的混淆配置文件`obfuscation-rules.txt`中配置混淆开关选项`-enable-lib-obfuscation-options`，可实现编译当前模块时合并依赖模块及三方库中所有的混淆配置，即规则合并功能与变更前一致。
