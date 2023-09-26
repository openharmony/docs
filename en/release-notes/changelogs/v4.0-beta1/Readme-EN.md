# Readme

| Subsystem        | Change Type    | Change Description                                                    |
| :------------- | ------------ | ------------------------------------------------------------ |
| Common          | Verification enhanced    | [Permission verification enhanced for system APIs. Now only system applications are allowed to use system APIs. If third-party applications use a system API, error 202 is returned.](changelogs-common.md)|
| Ability framework        | Behavior changed    | [In the **appRecovery** API, the enum names of **RestartFlag** are changed from **NO_RESTART** upon a specific fault to **RESTART** upon a specific fault.](changelogs-ability.md)|
| Multi-language runtime subsystem| Parsing rule changed| [LLVM parsing format changed. When your code depends on the **version-script** or **-gcc-toolchain** option, parsing may fail if you continue to use the original LLVM 12 configuration file or options.](changelogs-arkcompiler.md)|
| Multi-language runtime subsystem| Verification enhanced    | [New alarms are added and existing alarms are enhanced along with the upgrade from LLVM 12 to LLVM 15](changelogs-arkcompiler.md)|
| Multi-language runtime subsystem| Verification enhanced    | [LLVM emu-tls is changed. If you use both LLVM 12 and LLVM 15, the emu-tls symbol cannot be found in libc++.so.](changelogs-arkcompiler.md)|
| Multi-language runtime subsystem| Verification enhanced    | [New features and internal interface changes in the official release of LLVM 15 are inherited.](changelogs-arkcompiler.md)|
| ArkUI          | Behavior changed    | [The stack layout issue is fixed.](changelogs-arkui.md)                    |
| ArkUI          | Default value changed  | [The default state of the scrollbar in the \<List> and \<Gird> components is changed.](changelogs-arkui.md) |
| ArkUI          | UX changed      | [The hover effect of the \<Button> component is changed from scale-up by 100% to 105% to overlay of 0% to 5% opacity.](changelogs-arkui.md)|
| ArkUI          | UX changed      | [The alignment mode of multi-line text in toasts is changed from center-aligned to left-aligned.](changelogs-arkui.md)|
| Bundle management subsystem        | Mechanism changed    | [The HAP is no longer decompressed during HAP installation.](changelogs-bundlemanager.md)|
| Globalization        | API added    | [The getStringSync and getStringByNameSync APIs are added.](changelogs-global.md)|
| Globalization        | Behavior changed    | [The meaning of the return value for the API used to obtain the rawfile descriptor is changed.](changelogs-global.md)|
| Security-HUKS | Behavior changed | [HuksKeyStorageType must be passed in for key derivation or key agreement.](changelogs-huks.md) |
| Security-HUKS | Behavior changed | [Permission is required for Using attestKeyItem.](changelogs-huks.md) |
| Web            | Input parameter added | [The input parameter type Resource is added for the setResponseData API.](changelogs-web.md) |
| Resource scheduler subsystem      | Behavior changed    | [The reminder agent allows you to customize buttons for system applications. Clicking a custom button will redirect you to the specified application page.](changelogs-resourceschedule.md)|
