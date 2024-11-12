# Multimodal Subsystem Changelog

## cl.multimodalinput.1 Permission Change of the OH_Input_GetKeyState API in the oh_input_manager.h File

**Access Level**

Public API

**Reason for Change**

According to the security requirements, the keys that can be queried by the **OH_Input_GetKeyState** API are restricted to the range of keys that cannot be entered.

**Change Impact**

This change is a non-compatible change.
Before change: The API can query keys that can or cannot be entered.
After change: The API can query only the keys that cannot be entered. When the keys that can be entered are queried, error code 401 is returned.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

| API| Before Change| After Change|
| ------------------------------------------------------------ | --------- | ------ |
| Input_Result OH_Input_GetKeyState(struct Input_KeyState* keyState); | All keys can be queried.| Only keys that cannot be entered can be queried.|

**Adaptation Guide**

Use the API to query only the keys that cannot be entered.
