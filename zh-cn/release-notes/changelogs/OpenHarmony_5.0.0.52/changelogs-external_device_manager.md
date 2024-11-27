# 驱动子系统扩展外设管理模块Changelog
## cl.usbddk.1 USB_DDK/HID_DDK错误码定义变更

**访问级别**

公开接口。

**变更原因**

扩展外设管理模块已有的错误码可能有如下两种情况导致开发者体验不佳：

  1.存在错误码未定义的现象，当返回未定义的错误码时，无有效处理指导；

  2.存在定义了错误码，但没有返回该错误码的场景，需要废除；

因此需要对涉及到的错误码进行整改。

**变更影响**

该变更为不兼容变更。

可能的影响:
   
  1.对于存量错误码的定义进行了规范化调整，需要对错误码重新校验。

  2.已经存在但未定义的错误码，可以新增相关错误码校验，以及处理措施。

USB错误码

| 变更前 | 变更后 |
| ------ | ------ |
| USB_DDK_SUCCESS = 0 | 未变更 |
| USB_DDK_FAILED = -1 | 废弃 |
| USB_DDK_INVALID_PARAMETER = -2 | USB_DDK_INVALID_PARAMETER = 401 |
| USB_DDK_MEMORY_ERROR = -3 | USB_DDK_MEMORY_ERROR = 27400001 |
| USB_DDK_INVALID_OPERATION = -4 | USB_DDK_INVALID_OPERATION = 27400002 |
| USB_DDK_NULL_PTR = -5 | 废弃 |
| USB_DDK_DEVICE_BUSY = -6 | 废弃 |
| USB_DDK_TIMEOUT = -7 | USB_DDK_TIMEOUT = 27400004 |
| USB_DDK_NO_PERM = 201 | 新增 |
| USB_DDK_IO_FAILED = 27400003 | 新增 |

HID错误码

| 变更前 | 变更后 |
| ------ | ------ |
| HID_DDK_SUCCESS = 0 | 未变更 |
| HID_DDK_NO_PERM = -6 | HID_DDK_NO_PERM = 201 |
| HID_DDK_INVALID_PARAMETER = -2 | HID_DDK_INVALID_PARAMETER = 401 |
| HID_DDK_FAILURE = -1 | HID_DDK_FAILURE = 27300001 |
| HID_DDK_NULL_PTR = -4 | HID_DDK_NULL_PTR = 27300002 |
| HID_DDK_INVALID_OPERATION = -3 | HID_DDK_INVALID_OPERATION = 27300003 |
| HID_DDK_TIMEOUT = -5 | HID_DDK_TIMEOUT = 27300004 |

**起始 API Level**

10

**变更发生的版本**

从OpenHarmonySDK 5.0.0.52开始。

**变更的接口/组件**

drivers/external_device_manager。

**适配指导**

开发人员无需做额外适配，如果有对特定错误码进行校验的话，请查看最新的错误码定义；

推荐校验错误码时对枚举的宏定义进行校验，而不是对定义的枚举值校验；

例如校验HID的权限错误码：

  ```C++
  ...
  int32_t ret;
  ret = OH_Hid_CreateDevice(hidDevice, hidEventProperties);
  if (ret == HID_DDK_NO_PERM) {
      //权限配置错误的处理措施
  }
  ```
