# Peripheral Management Module Changelog
## cl.usbddk.1 Change in the USB_DDK/HID_DDK Error Code Definition

**Access Level**

Public API

**Reason for Change**

The existing error codes of the peripheral management module may affect user experience in the following scenarios:

  1. Error codes are not defined. When an undefined error code is returned, no effective handling guide is available.

  2. There is no mapping error for an error code, and the error code needs to be deprecated.

Therefore, the involved error codes need to be rectified.

**Change Impact**

This change is a non-compatible change.

Possible impacts:
   
  1. After the definition of existing error codes is standardized, you need to verify the error codes again.

  2. For existing undefined error codes, you need to add error code verification and handling measures.

USB error codes

| Before Change| After Change|
| ------ | ------ |
| USB_DDK_SUCCESS = 0 | Unchanged|
| USB_DDK_FAILED = -1 | Deprecated|
| USB_DDK_INVALID_PARAMETER = -2 | USB_DDK_INVALID_PARAMETER = 401 |
| USB_DDK_MEMORY_ERROR = -3 | USB_DDK_MEMORY_ERROR = 27400001 |
| USB_DDK_INVALID_OPERATION = -4 | USB_DDK_INVALID_OPERATION = 27400002 |
| USB_DDK_NULL_PTR = -5 | Deprecated|
| USB_DDK_DEVICE_BUSY = -6 | Deprecated|
| USB_DDK_TIMEOUT = -7 | USB_DDK_TIMEOUT = 27400004 |
| USB_DDK_NO_PERM = 201 | Added|
| USB_DDK_IO_FAILED = 27400003 | Added|

HID error codes

| Before Change| After Change|
| ------ | ------ |
| HID_DDK_SUCCESS = 0 | Unchanged|
| HID_DDK_NO_PERM = -6 | HID_DDK_NO_PERM = 201 |
| HID_DDK_INVALID_PARAMETER = -2 | HID_DDK_INVALID_PARAMETER = 401 |
| HID_DDK_FAILURE = -1 | HID_DDK_FAILURE = 27300001 |
| HID_DDK_NULL_PTR = -4 | HID_DDK_NULL_PTR = 27300002 |
| HID_DDK_INVALID_OPERATION = -3 | HID_DDK_INVALID_OPERATION = 27300003 |
| HID_DDK_TIMEOUT = -5 | HID_DDK_TIMEOUT = 27300004 |

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.52

**Key API/Component Changes**

drivers/external_device_manager

**Adaptation Guide**

Developers do not need to perform additional adaptation. If specific error codes need to be verified, view the latest error code definition.

You are advised to verify the enum macros instead of the defined enum values when verifying the error codes.

The following is an example of verifying the error code for the HID permission error:

  ```C++
  //...
  int32_t ret;
  ret = OH_Hid_CreateDevice(hidDevice, hidEventProperties);
  if (ret == HID_DDK_NO_PERM) {
      // Handling for the permission error
  }
  ```
