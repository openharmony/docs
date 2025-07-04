# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Change in Default Behavior of Merging Dependency Obfuscation Rules

**Access Level**

Others

**Reason for Change**

The default behavior of merging dependency obfuscation rules during obfuscation causes issues for some developers who were not familiar with the obfuscation mechanism. Some third-party libraries include obfuscation switch options in their **obfuscation.txt** files. When other applications depended on these libraries, it causes application crashes at startup, and developers cannot directly detect that these third-party libraries have introduced obfuscation switches.

**Impact of the Change**

This change requires application adaptation.

Before change:  

When compiling a module, the effective obfuscation rules are the result of merging all obfuscation configurations from the current module, dependent modules, and third-party libraries.

For example, if the obfuscation configurations for the current module, a dependent HAR module, and a third-party library are as follows:

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

Then the effective obfuscation rules when compiling the current module are as follows:

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

After change:

When compiling a module, the effective obfuscation rules are the result of merging the current module's obfuscation configurations with the obfuscation retention options from dependent modules and third-party libraries.


For the same example, the effective obfuscation rules when compiling the current module are as follows:
```
-enable-toplevel-obfuscation
-keep-global-name
currentVar
harVar
-keep-property-name
harProp
thirdPartyProp
```

**Start API Level**

API 10

**Change Since**

OpenHarmony 5.1.0.46

**Key API/Component Changes**

N/A

**Adaptation Guide**

To achieve the pre-change behavior of merging all obfuscation configurations from dependent modules and third-party libraries when compiling the current module, you can configure the obfuscation switch option **-enable-lib-obfuscation-options** in the current module's obfuscation configuration file **obfuscation-rules.txt**.
