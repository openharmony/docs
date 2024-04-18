# oh_input_manager.h


## Overview

Provides functions such as event injection and key status query.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Library**: liboh_input.so

**Since**: 12

**Related module**: [Input](input.md)


## Summary


### Enums

| Name| Description| 
| -------- | -------- |
| [Input_KeyStateAction](input.md#input_keystateaction) {<br>[KEY_DEFAULT](input.md) = -1, [KEY_PRESSED](input.md) = 0, [KEY_RELEASED](input.md) = 1, [KEY_SWITCH_ON](input.md) = 2,<br>[KEY_SWITCH_OFF](input.md) = 3<br>} | Provides the enum values of the key status.| 
| [Input_Result](input.md#input_result) { [INPUT_SUCCESS](input.md) = 0, [INPUT_PERMISSION_DENIED](input.md) = 201, [INPUT_NOT_SYSTEM_APPLICATION](input.md) = 202, [INPUT_PARAMETER_ERROR](input.md) = 401 } | Provides error codes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Input_Result](input.md#input_result)[OH_Input_GetKeyState](input.md#oh_input_getkeystate) (struct Input_KeyState \*keyState) | Queries an enum object of the key status.| 
| Input_KeyState \* [OH_Input_CreateKeyState](input.md#oh_input_createkeystate) () | Creates an enum object of the key status.| 
| [OH_Input_DestroyKeyState](input.md#oh_input_destroykeystate) (struct Input_KeyState \*keyState) | Destroys an enum object of the key status.| 
| [OH_Input_SetKeyCode](input.md#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | Sets the key value of a key status enum object.| 
| [OH_Input_GetKeyCode](input.md#oh_input_getkeycode) (struct Input_KeyState \*keyState) | Obtains the key value of a key status enum object.| 
| [OH_Input_SetKeyPressed](input.md#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | Sets whether the key specific to a key status enum object is pressed.| 
| [OH_Input_GetKeyPressed](input.md#oh_input_getkeypressed) (struct Input_KeyState \*keyState) | Checks whether the key specific to a key status enum object is pressed.| 
| [OH_Input_SetKeySwitch](input.md#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | Sets the key switch of the key status enum object.| 
| [OH_Input_GetKeySwitch](input.md#oh_input_getkeyswitch) (struct Input_KeyState \*keyState) | Obtains the key switch of the key status enum object.| 
