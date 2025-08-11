# inputmethod_types_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## Overview

Defines the types related to the input method.

**File to include**: <inputmethod/inputmethod_types_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) | InputMethod_KeyboardStatus | Keyboard status.|
| [InputMethod_EnterKeyType](#inputmethod_enterkeytype) | InputMethod_EnterKeyType | Enter key type.|
| [InputMethod_Direction](#inputmethod_direction) | InputMethod_Direction | Moving direction.|
| [InputMethod_ExtendAction](#inputmethod_extendaction) | InputMethod_ExtendAction | Type of the extended edit action on the text box.|
| [InputMethod_TextInputType](#inputmethod_textinputtype) | InputMethod_TextInputType | Text input type.|
| [InputMethod_CommandValueType](#inputmethod_commandvaluetype) | InputMethod_CommandValueType | Private data type.|
| [InputMethod_ErrorCode](#inputmethod_errorcode) | InputMethod_ErrorCode | Error code of the input method.|
| [InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason) | InputMethod_RequestKeyboardReason | Reason for requesting the keyboard.|

## Enum Description

### InputMethod_KeyboardStatus

```
enum InputMethod_KeyboardStatus
```

**Description**

Enumerates the keyboard status.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_KEYBOARD_STATUS_NONE = 0 | NONE.|
| IME_KEYBOARD_STATUS_HIDE = 1 | Invisible.|
| IME_KEYBOARD_STATUS_SHOW = 2 | Visible.|

### InputMethod_EnterKeyType

```
enum InputMethod_EnterKeyType
```

**Description**

Enumerates the Enter key types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_ENTER_KEY_UNSPECIFIED = 0 | Unspecified.|
| IME_ENTER_KEY_NONE = 1 | NONE.|
| IME_ENTER_KEY_GO = 2 | Go.|
| IME_ENTER_KEY_SEARCH = 3 | Search.|
| IME_ENTER_KEY_SEND = 4 | Send.|
| IME_ENTER_KEY_NEXT = 5 | Next.|
| IME_ENTER_KEY_DONE = 6 | Done.|
| IME_ENTER_KEY_PREVIOUS = 7 | Previous.|
| IME_ENTER_KEY_NEWLINE = 8 | Line break.|

### InputMethod_Direction

```
enum InputMethod_Direction
```

**Description**

Enumerates the moving directions.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_DIRECTION_NONE = 0 | NONE.|
| IME_DIRECTION_UP = 1 | Upward.|
| IME_DIRECTION_DOWN = 2 | Downward.|
| IME_DIRECTION_LEFT = 3 | Leftward.|
| IME_DIRECTION_RIGHT = 4 | Rightward.|

### InputMethod_ExtendAction

```
enum InputMethod_ExtendAction
```

**Description**

Enumerates the types of the extended edit action on the text box.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_EXTEND_ACTION_SELECT_ALL = 0 | Select all.|
| IME_EXTEND_ACTION_CUT = 3 | Cut.|
| IME_EXTEND_ACTION_COPY = 4 | Copy.|
| IME_EXTEND_ACTION_PASTE = 5 | Paste.|

### InputMethod_TextInputType

```
enum InputMethod_TextInputType
```

**Description**

Enumerates the text input types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_TEXT_INPUT_TYPE_NONE = -1 | NONE.|
| IME_TEXT_INPUT_TYPE_TEXT = 0 | Text.|
| IME_TEXT_INPUT_TYPE_MULTILINE = 1 | Multi-line.|
| IME_TEXT_INPUT_TYPE_NUMBER = 2 | Number.|
| IME_TEXT_INPUT_TYPE_PHONE = 3 | Phone number.|
| IME_TEXT_INPUT_TYPE_DATETIME = 4 | Date.|
| IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5 | Email address.|
| IME_TEXT_INPUT_TYPE_URL = 6 | URL.|
| IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7 | Password.|
| IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8 | Numeric password.|
| IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9 | Lock screen password.|
| IME_TEXT_INPUT_TYPE_USER_NAME = 10 | Username.|
| IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11 | New password.|
| IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12 | Decimal number.|
| IME_TEXT_INPUT_TYPE_ONE_TIME_CODE = 13 | Verification code. **Since**: 20|

### InputMethod_CommandValueType

```
enum InputMethod_CommandValueType
```

**Description**

Enumerates the private data types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_COMMAND_VALUE_TYPE_NONE = 0 | NONE.|
| IME_COMMAND_VALUE_TYPE_STRING = 1 | String.|
| IME_COMMAND_VALUE_TYPE_BOOL = 2 | Boolean.|
| IME_COMMAND_VALUE_TYPE_INT32 = 3 | 32-bit signed integer.|

### InputMethod_ErrorCode

```
enum InputMethod_ErrorCode
```

**Description**

Enumerates the input method error codes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IME_ERR_OK = 0 | Success.|
| IME_ERR_UNDEFINED = 1 | Query failed.|
| IME_ERR_PARAMCHECK = 401 | Parameter check failed.|
| IME_ERR_PACKAGEMANAGER = 12800001 | Package management error.|
| IME_ERR_IMENGINE = 12800002 | Input method application error.|
| IME_ERR_IMCLIENT = 12800003 | Text box client error.|
| IME_ERR_CONFIG_PERSIST = 12800005 | Configuration persistence failed. This error code is reported when the configuration fails to be saved.|
| IME_ERR_CONTROLLER = 12800006 | Input method controller error.|
| IME_ERR_SETTINGS = 12800007 | Input method setter error.|
| IME_ERR_IMMS = 12800008 | Input method manager service error.|
| IME_ERR_DETACHED = 12800009 | Text box unbound.|
| IME_ERR_NULL_POINTER = 12802000 | Null pointer.|
| IME_ERR_QUERY_FAILED = 12802001 | Query failed.|

### InputMethod_RequestKeyboardReason

```
enum InputMethod_RequestKeyboardReason
```

**Description**

Enumerates the reasons for requesting the keyboard.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| IME_REQUEST_REASON_NONE = 0 | No reason.|
| IME_REQUEST_REASON_MOUSE = 1 | Mouse operation.|
| IME_REQUEST_REASON_TOUCH = 2 | Touch operation.|
| IME_REQUEST_REASON_OTHER = 20 | Other reasons.|
