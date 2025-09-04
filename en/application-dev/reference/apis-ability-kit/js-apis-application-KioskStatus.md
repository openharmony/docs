# KioskStatus (Kiosk Status Information)

The module provides the kiosk status information, including whether the system is in kiosk mode and the information about the application in kiosk mode.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## KioskStatus

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                 | Type                   | Read-Only| Optional| Description                                                 |
| --------------------- | ---------------------- | ---- | ---- | ---------------------------------------------------- |
| isKioskMode           | boolean                | No  | No  | Whether the system is in kiosk mode. **true** if in kiosk mode, **false** otherwise.|
| kioskBundleName       | string                 | No  | No  | Bundle name of the application in kiosk mode.                         |
| kioskBundleUid        | number                 | No  | No  | UID of the application in kiosk mode.                          |
