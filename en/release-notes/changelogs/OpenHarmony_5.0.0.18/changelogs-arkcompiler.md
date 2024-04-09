# ArkCompiler Subsystem ChangeLog

## cl.arkcompiler.1 Add ArkTS linter check in incremental preview and hot-reload

**Access Level**

Other

**Reason for Change**

Before, the scenarios for the ArkTS linter tool include application full compilation, incremental compilation, first preview, first hot-reload, etc. In preview and hot-reload scenarios, when the real-time preview and hot-reload are triggered after saving the incrementally modified code, there is no ArkTS linter check. In this change, ArkTS linter is added to the compilation process in this scenario to keep the check results consistent with other scenarios.

**Change Impact**

In previewer and hot-reload scenarios, if the incremental modifications introduce problems that violate ArkTS syntax rules, before there is no ArkTS check and can continue to preview and hot-reload, but after there will be ArkTS check errors and it will block compilation and stop real-time preview and hot-reload.

**API Level**

ArkTS Linter check starts from 10

**Change Since**

OpenHarmony SDK 5.0.0.18

**Key API/Component Changes**

NA.

**Adaptation Guide**

Applications that can be fully compiled successfully require no additional adaptation.