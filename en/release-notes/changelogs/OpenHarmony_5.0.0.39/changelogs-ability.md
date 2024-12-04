# Ability Subsystem Changelog

## cl.ability.1 Added the Verification to Check Whether the Caller to Start a UIExtensionAbility Is Running in the Foreground

**Access Level**

Public API

**Reason for Change**

The UIExtensionAbility can be started only by an application running in the foreground. However, the system does not check whether the caller is a foreground application when the application attempts to start a UIExtensionAbility.

**Change Impact**

This change is a non-compatible change.

Before change: A background application can successfully start a UIExtensionAbility.

After change: A background application fails to start a UIExtensionAbility.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.39

**Key API/Component Changes**

1. **UIAbilityContext.startAbilityByType** and **UIExtensionContentSession.startAbilityByType**

2. APIs that have the capability to start a UIExtensionAbility

**Adaptation Guide**

No adaptation is required. After the change, background applications are not allowed to start a UIExtensionAbility.
