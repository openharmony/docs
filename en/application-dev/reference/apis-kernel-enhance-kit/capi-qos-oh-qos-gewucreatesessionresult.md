# OH_QoS_GewuCreateSessionResult
<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @gatieme-->
<!--Designer: @tanyihua-->
<!--Tester: @panny060-->
<!--Adviser: @fang-jinxu-->

```c
typedef struct { ... } OH_QoS_GewuCreateSessionResult
```

## Overview
Return result of the **OH_QoS_GewuCreateSession()** API, used to encapsulate the execution status of the Gewu session creation operation. This struct supports unified handling of both success and failure scenarios. Upon success, the `session` field contains the handle to the created session. Upon failure, the `error` field stores the error code, helping you locate and handle exceptions.

**Since**: 20

**Related module**: [QoS](capi-qos.md)

**Header file**: [qos.h](capi-qos-h.md)

## Summary

### Member Variables

| Name | Description|
| -- | -- |
| [OH_QoS_GewuSession](capi-qos-h.md#oh_qos_gewusession) session | Session handle returned after a session is successfully created. This parameter is valid only when `error` is `OH_QOS_GEWU_OK`.|
| [OH_QoS_GewuErrorCode](capi-qos-h.md#oh_qos_gewuerrorcode) error | Error code.<br>- `OH_QOS_GEWU_OK`: The session is successfully created.<br>- `OH_QOS_GEWU_NOMEM`: Insufficient memory. There is not enough memory to create the session. You are advised to release system resources and retry the session creation.<br>- `OH_QOS_GEWU_INVAL`: Invalid parameter. The input parameter does not meet the API requirements. Verify the field types, formats, and values in `attributes`.<br>- `OH_QOS_GEWU_NOPERM`: Insufficient permission. The caller lacks the required permission for the API. Verify the application permission configuration.<br>- `OH_QOS_GEWU_EXIST`: The session already exists. An attempt was made to create a session that already exists. Verify the session creation process.<br>- `OH_QOS_GEWU_NOSYS`: Subsystem not found. The system does not support the related function or the dependent subsystems are unavailable. Check system version and the status of dependent libraries.<br>The mapping between the above enumerated values and their numeric codes is as follows: `OH_QOS_GEWU_OK` = **0**, `OH_QOS_GEWU_NOPERM` = **201**, `OH_QOS_GEWU_NOMEM` = **203**, `OH_QOS_GEWU_INVAL` = **401**, `OH_QOS_GEWU_EXIST` = **501**, and `OH_QOS_GEWU_NOSYS` = **801**.|
