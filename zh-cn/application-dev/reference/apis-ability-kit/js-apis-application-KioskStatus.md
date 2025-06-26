# KioskStatus（Kiosk状态信息）

表示Kiosk状态信息，包括系统是否处于Kiosk模式以及该模式下的应用信息。

> **说明：**
>
> 本模块接口从 API Version 20 开始支持。
>

## KioskStatus

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 名称                  | 类型                    | 只读 | 可选 | 说明                                                  |
| --------------------- | ---------------------- | ---- | ---- | ---------------------------------------------------- |
| isKioskMode           | boolean                | 否   | 否   | 当前系统是否处于Kiosk模式。true表示处于Kiosk模式，false表示不处于。|
| kioskBundleName       | string                 | 否   | 否   | 进入Kiosk模式的应用的名称。                          |
| kioskBundleUid        | number                 | 否   | 否   | 进入Kiosk模式的应用的UID。                           |
