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

## 概述
OH_QoS_GewuCreateSession()接口的返回结果，用于封装格物会话创建操作的执行状态。该结构体支持统一处理会话创建成功和失败两种场景：创建会话成功时，`session`字段包含创建的会话句柄；失败时，`error`字段保存错误码，便于开发者定位和处理异常。

**起始版本：** 20

**相关模块：** [QoS](capi-qos.md)

**所在头文件：** [qos.h](capi-qos-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_QoS_GewuSession](capi-qos-h.md#oh_qos_gewusession) session | 创建会话成功后返回的会话句柄。仅在`error`为`OH_QOS_GEWU_OK`时有效。 |
| [OH_QoS_GewuErrorCode](capi-qos-h.md#oh_qos_gewuerrorcode) error | 错误码。<br>- `OH_QOS_GEWU_OK`：创建会话成功。<br>- `OH_QOS_GEWU_NOMEM`：内存不足，表示没有足够的内存创建会话，建议释放系统资源后重新创建会话。<br>- `OH_QOS_GEWU_INVAL`：参数错误，表示输入参数不符合接口要求，请检查`attributes`中的字段类型、格式和取值。<br>- `OH_QOS_GEWU_NOPERM`：权限不足，表示调用者缺少接口所需权限，请检查应用权限配置。<br>- `OH_QOS_GEWU_EXIST`：会话已存在，表示重复创建已存在的会话，请确认会话创建流程。<br>- `OH_QOS_GEWU_NOSYS`：找不到子系统，表示系统不支持相关功能或依赖子系统不可用，请确认系统版本和依赖库状态。<br>上述枚举值与数字的对应关系：`OH_QOS_GEWU_OK`=0、`OH_QOS_GEWU_NOPERM`=201、`OH_QOS_GEWU_NOMEM`=203、`OH_QOS_GEWU_INVAL`=401、`OH_QOS_GEWU_EXIST`=501、`OH_QOS_GEWU_NOSYS`=801。 |


