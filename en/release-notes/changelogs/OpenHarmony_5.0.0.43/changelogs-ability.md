# Ability Framework Changelog

## cl.ability.1 Ability Assistant No Longer Supports Debugging of Applications in Release Mode

**Access Level**

Public API

**Reason for Change**

The Ability Assistant tool is the bottom-layer dependency for debugging capabilities of DevEco Studio. Normally, DevEco Studio restricts debugging of applications in release mode. However, there is a risk of bypassing DevEco Studio and directly using the debugging commands of Ability Assistant for debugging. Therefore, this behavior must be fundamentally restricted.

**Change Impact**

This change is a non-compatible change.

Before change:
There is a risk of bypassing DevEco Studio and directly running the commands of Ability Assistant to debug applications in release mode.

After change:
The Ability Assistant tool does not support debugging of applications in release mode.

**Start API Level**

N/A

**Change Since**

OpenHarmony SDK 5.0.0.43

**Key API/Component Changes**

Ability Assistant

**Adaptation Guide**

No adaptation is required.


## cl.ability.2. It Is Forbidden to Start an ExtensionAbility using wantAgent

**Access Level**

Public API

**Reason for Change**

A third-party application creates a wantAgent for an ExtensionAbility and sends a notification containing the wantAgent. After a user touches the notification on the home screen, the ExtensionAbility starts. When the user exits the application, the ExtensionAbility process does not exit, affecting power consumption.

**Change Impact**

This change is a non-compatible change.

Before change:
A third-party application creates a wantAgent for an ExtensionAbility and sends a notification containing the wantAgent. When users can touch the notification on the home screen, the ExtensionAbility starts.

After change:
A third-party application creates a wantAgent for an ExtensionAbility and sends a notification containing the wantAgent. When users touch the notification on the home screen, the ExtensionAbility does not start.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.43

**Key API/Component Changes**

wantAgent.trigger

**Adaptation Guide**

You are advised not to create a wantAgent for starting an ExtensionAbility. Otherwise, the ExtensionAbility fails to start through **wantAgent.trigger**.
