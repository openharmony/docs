# Ability Subsystem Changelog

## cl.ability.1 Behavior Change in startAbility for Full-screen and Split Window Modes

**Access Level**

Public API

**Reason for Change**

On 2-in-1 devices, when [supportWindowModes](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md) is configured with the values **fullscreen** and **split**, the window starts in a freeform window state, which is not as expected.

**Impact of the Change**

This change requires application adaptation.

Before the change, when **supportWindowModes** is configured with the values **fullscreen** and **split** on a 2-in-1 devices, windows are launched in freeform window mode.

After the change, when **supportWindowModes** is configured with the values **fullscreen** and **split** on a 2-in-1 devices, windows are launched in full-screen mode.


**Start API Level**

API 14

**Change Since**

OpenHarmony SDK 5.1.0.52

**Key API/Component Changes**

@ohos.app.ability.StartOptions.d.ts

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

API: **supportWindowModes**

**Adaptation Guide**

In API version 15 or later, configure windows to launch in full-screen mode when **supportWindowModes** is configured with the values **fullscreen** and **split** on 2-in-1 devices.
If the intention is to start in a freeform window state, add the **floating** configuration item to the existing **supportWindowModes** configuration.
