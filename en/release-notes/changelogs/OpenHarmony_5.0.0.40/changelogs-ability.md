# Ability Subsystem Changelog

## cl.ability.1 Applications Running a Continuous Task in the Background Are Not Allowed to Call startAbility

**Access Level**

Public API

**Reason for Change**

It is prohibited for an application to call **startAbility** to start itself or other applications from the background. However, by leveraging a continuous task, the application can still successfully call **startAbility** in the background, potentially leading to the display of malicious dialog boxes. To resolve this vulnerability, a new limitation is implemented to block applications from calling **startAbility** when running a continuous task in the background.

**Change Impact**

This change is a non-compatible change.

Before change: An application running a continuous task in the background can successfully call **startAbility**.

After change: An application running a continuous task in the background fails to call **startAbility**.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.40

**Key API/Component Changes**

**startAbility** in each context

**Adaptation Guide**

No adaptation is required. After the change, applications running a continuous task in the background fail to call **startAbility**. If such a behavior exists, you are advised to delete the related code.
