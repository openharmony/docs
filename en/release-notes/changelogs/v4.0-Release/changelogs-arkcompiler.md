# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 Addition of ArkTS Syntax Validation

Added ArkTS syntax validation to the compilation process. Syntax issues are classified as warning or error, depending on the mode specified by **compatibleSdkVersion**, which are generally configured in the **build-profile.json5** file.

For details, see [TypeScript to ArkTS Cookbook](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md).

  - In compatible mode, where the value of **compatibleSdkVersion** is smaller than 10, syntax issues are reported as warnings and will not block the compilation process.
  - In compatible mode, where the value of **compatibleSdkVersion** is greater than or equal to 10, syntax issues are reported as errors and will block the compilation process.

**Change Impact**

 

  - In OpenHarmony SDK 4.0.10.3 and later versions, syntax validation is enabled. During project compilation, a warning is generated for code that does not comply with the ArkTS syntax rules. These warnings will not block the compilation process. Yet, you are advised to adapt the code based on the warnings.
  - In the release edition of API version 10, the OpenHarmony SDK is expected to report an error for an ArkTS syntax issue. In this case, the compilation process can continue only after the issue has been rectified.

**Key API/Component Changes**

ArkTS syntax validation is added to the compilation process.

**Adaptation Guide**

Modify code that does not comply with the ArkTS syntax rules. For details about the error reporting rules and modification, see [TypeScript to ArkTS Cookbook](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md).

For details about the ArkTS language, see [Introduction to ArkTS](../../../application-dev/quick-start/introduction-to-arkts.md).
