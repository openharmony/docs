# Faceauth

## 概述

### 功能简介

人脸识别功能是端侧设备不可或缺的一部分。提供用户认证能力，可应用于设备解锁、支付、应用登录等身份认证场景。它是基于人的脸部特征信息进行身份识别的一种生物特征识别技术，用摄像机或摄像头采集含有人脸的图像或视频流，并自动在图像中检测和跟踪人脸，进而对检测到的人脸进行脸部识别，通常也叫做人像识别、面部识别、人脸认证。

Faceauth驱动模型屏蔽硬件器件差异，为上层用户认证框架和人脸识别服务提供稳定的人脸识别基础能力接口，包括人脸识别执行器列表查询、执行器信息查询、指定template ID查询模板信息、用户认证框架和执行器间的模板信息对账、人脸的录入，删除，认证和识别等。

本文主要介绍基于HDF(Hardware Driver Foundation)驱动框架开发的Faceauth驱动，包括Faceauth驱动的架构组成和功能接口。芯片厂商可以根据此说明，进行各自驱动的开发及IDL层接口的调用。

### 框架介绍

Faceauth驱动框架基于[HDF驱动框架](https://device.harmonyos.com/cn/docs/documentation/guide/driver-hdf-overview-0000001051715456)实现，图1显示了简化的人脸识别服务和Faceauth驱动接口交互。人脸SA通过接口获取人脸认证执行器列表及执行器信息并向用户认证框架注册。人脸认证执行器实现人脸提供的功能接口，用于与人脸识别服务做交互。

**图1** 人脸识别服务和Faceauth驱动接口：

![image-20220429165815860](C:\Users\wang\AppData\Roaming\Typora\typora-user-images\image-20220429165815860.png)

## 开发指导

### 接口说明

**表1** 接口功能介绍

| 接口名                                                       | 功能介绍                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| GetExecutorList(std::vector<sptr<IExecutor>>& executorList)  | 获取执行器列表。                                             |
| GetExecutorInfo(ExecutorInfo& info)                          | 获取执行器信息。                                             |
| GetTemplateInfo(uint64_t templateId, TemplateInfo& info)     | 获取指定templateId的模板信息。                               |
| OnRegisterFinish(const std::vector<uint64_t>& templateIdList,<br/>        const std::vector<uint8_t>& frameworkPublicKey, const std::vector<uint8_t>& extraInfo) | 执行器注册成功后，获取用户认证框架的公钥信息；获取用户认证框架的template 列表用于对账。 |
| Enroll(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,<br/>        const sptr<IExecutorCallback>& callbackObj) | 人脸录入操作。                                               |
| Authenticate(uint64_t scheduleId, const std::vector<uint64_t>& templateIdList,<br/>        const std::vector<uint8_t>& extraInfo, const sptr<IExecutorCallback>& callbackObj) | 人脸认证操作。                                               |
| Identify(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,<br/>        const sptr<IExecutorCallback>& callbackObj) | 人脸识别操作。                                               |
| Delete(const std::vector<uint64_t>& templateIdList)          | 删除人脸模板。                                               |
| Cancel(uint64_t scheduleId)                                  | 通过scheduleId取消指定操作。                                 |
| SendCommand(int32_t commandId, const std::vector<uint8_t>& extraInfo,<br/>        const sptr<IExecutorCallback>& callbackObj) | 人脸认证服务向Faceauth驱动传递参数的通用接口。               |

**表2** 回调函数介绍

| 接口名                                                       | 功能介绍                 |
| ------------------------------------------------------------ | ------------------------ |
| IExecutorCallback::OnResult(int32_t code, const std::vector<uint8_t>& extraInfo) | 返回操作的最终结果。     |
| IExecutorCallback::OnAcquireInfo(int32_t code, const std::vector<uint8_t>& extraInfo) | 返回操作的过程交互信息。 |
| IExecutorCallback::GetVersion(uint32_t& majorVer, uint32_t& minorVer) | 返回版本信息。           |

### 开发步骤

以下将基于Faceauth驱动框架，并以Hi3516DV300平台为例，介绍相关驱动开发的具体步骤。

1.基于HDF驱动框架，按照驱动Driver Entry程序，完成Faceauth驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

```c++
// 通过自定义的HdfFaceAuthInterfaceHost对象包含IoService对象和真正的HDI Service实现FaceAuthInterfaceService对象
struct HdfFaceAuthInterfaceHost {
    struct IDeviceIoService ioservice;
    FaceAuthInterfaceService *service;
};

// 服务接口调用响应接口
static int32_t FaceAuthInterfaceDriverDispatch(struct HdfDeviceIoClient *client, int cmdId, struct HdfSBuf *data,
    struct HdfSBuf *reply)
{
    FACEAUTH_HILOGI(MODULE_DRIVER, "start");
    struct HdfFaceAuthInterfaceHost *hdfFaceAuthInterfaceHost = CONTAINER_OF(client->device->service,
        struct HdfFaceAuthInterfaceHost, ioservice);

    OHOS::MessageParcel *dataParcel = nullptr;
    OHOS::MessageParcel *replyParcel = nullptr;
    OHOS::MessageOption option;

    (void)SbufToParcel(reply, &replyParcel);
    if (SbufToParcel(data, &dataParcel) != HDF_SUCCESS) {
        FACEAUTH_HILOGE(MODULE_DRIVER, "%{public}s:invalid data sbuf object to dispatch", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    return hdfFaceAuthInterfaceHost->service->OnRemoteRequest(cmdId, *dataParcel, *replyParcel, option);
}

// 初始化接口
int HdfFaceAuthInterfaceDriverInit(struct HdfDeviceObject *deviceObject)
{
    FACEAUTH_HILOGI(MODULE_DRIVER, "start");
    return HDF_SUCCESS;
}

// Faceauth驱动对外提供的服务绑定到HDF框架
int HdfFaceAuthInterfaceDriverBind(struct HdfDeviceObject *deviceObject)
{
    FACEAUTH_HILOGI(MODULE_DRIVER, "start");

    struct HdfFaceAuthInterfaceHost *hdfFaceAuthInterfaceHost = (struct HdfFaceAuthInterfaceHost *)OsalMemAlloc(
        sizeof(struct HdfFaceAuthInterfaceHost));
    if (hdfFaceAuthInterfaceHost == nullptr) {
        FACEAUTH_HILOGE(MODULE_DRIVER, "OsalMemAlloc HdfFaceAuthInterfaceHost failed!");
        return HDF_FAILURE;
    }

    hdfFaceAuthInterfaceHost->ioservice.Dispatch = FaceAuthInterfaceDriverDispatch;
    hdfFaceAuthInterfaceHost->ioservice.Open = NULL;
    hdfFaceAuthInterfaceHost->ioservice.Release = NULL;
    hdfFaceAuthInterfaceHost->service = new FaceAuthInterfaceService();

    deviceObject->service = &hdfFaceAuthInterfaceHost->ioservice;
    FACEAUTH_HILOGI(MODULE_DRIVER, "success");
    return HDF_SUCCESS;
}

// 释放Faceauth驱动中的资源
void HdfFaceAuthInterfaceDriverRelease(struct HdfDeviceObject *deviceObject)
{
    FACEAUTH_HILOGI(MODULE_DRIVER, "start");
    struct HdfFaceAuthInterfaceHost *hdfFaceAuthInterfaceHost = CONTAINER_OF(deviceObject->service,
        struct HdfFaceAuthInterfaceHost, ioservice);
    delete hdfFaceAuthInterfaceHost->service;
    OsalMemFree(hdfFaceAuthInterfaceHost);
    FACEAUTH_HILOGI(MODULE_DRIVER, "success");
}

// 注册Faceauth驱动入口数据结构体对象
struct HdfDriverEntry g_faceauthinterfaceDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "faceauth_interface_service",
    .Bind = HdfFaceAuthInterfaceDriverBind,
    .Init = HdfFaceAuthInterfaceDriverInit,
    .Release = HdfFaceAuthInterfaceDriverRelease,
};

// 调用HDF_INIT将驱动入口注册到HDF框架中，在加载驱动时HDF框架会先调用Bind函数,再调用Init函数加载该驱动，当Init调用异常时，HDF框架会调用Release释放驱动资源并退出
HDF_INIT(g_faceauthinterfaceDriverEntry);
```

2.完成获取执行器列表接口实现，向框架注册执行器。

```c++
// 执行器实现类
class ExecutorImpl : public ExecutorStub {
public:
    ExecutorImpl(struct ExecutorInfo executorInfo);

    virtual ~ExecutorImpl() {}

private:
    struct ExecutorInfo executorInfo_; // 执行器信息
};

static constexpr unsigned short EXAMPLE1_SENSOR_ID = 123; // 执行器sensorID

// 获取执行器列表实现，创建执行器
int32_t GetExecutorList(std::vector<sptr<IExecutor>>& executorList)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    executorList.clear();
    struct ExecutorInfo executorInfoExample1 = {
        .sensorId = EXAMPLE1_SENSOR_ID,
        .executorType = static_cast<uint32_t>(ExecutorType::FACE_2D),
        .executorRole = ExecutorRole::COLLECTOR,
        .authType = AuthType::FACE,
        .esl = ExecutorSecureLevel::ESL0,
        .publicKey = std::vector<uint8_t>(PUBLIC_KEY_LEN, 1), // 执行器32位公钥
        .extraInfo = {},
    };
    executorList.push_back(sptr<IExecutor>(new ExecutorImpl(executorInfoExample1)));
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock success");
    return HDF_SUCCESS;
}
```

3.完成执行器每个功能接口实现。

```c++
// 实现获取执行器信息接口
int32_t GetExecutorInfo(ExecutorInfo& info)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    info = executorInfo_;
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "get executor information success");
    return HDF_SUCCESS;
}

// 实现获取指定templateId的模板信息接口
int32_t GetTemplateInfo(uint64_t templateId, TemplateInfo& info)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(templateId);
    info = {0};
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "get template information success");
    return HDF_SUCCESS;
}

// 实现执行器注册成功后，获取用户认证框架的公钥信息、获取用户认证框架的template 列表接口,将公钥信息保持，template 列表用于和本地的template做对账
int32_t OnRegisterFinish(const std::vector<uint64_t>& templateIdList,
    const std::vector<uint8_t>& frameworkPublicKey, const std::vector<uint8_t>& extraInfo)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(templateIdList);
    static_cast<void>(extraInfo);
    static_cast<void>(frameworkPublicKey);
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "register finish");
    return HDF_SUCCESS;
}

// 实现人脸录入接口
int32_t Enroll(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,
    const sptr<IExecutorCallback>& callbackObj)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(scheduleId);
    static_cast<void>(extraInfo);
    callbackObj->OnResult(ResultCode::OPERATION_NOT_SUPPORT, {});
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "enroll, result is %{public}d",
        static_cast<int32_t>(ResultCode::OPERATION_NOT_SUPPORT));
    return HDF_SUCCESS;
}

// 实现人脸认证接口
int32_t Authenticate(uint64_t scheduleId, const std::vector<uint64_t>& templateIdList,
    const std::vector<uint8_t>& extraInfo, const sptr<IExecutorCallback>& callbackObj)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(scheduleId);
    static_cast<void>(templateIdList);
    static_cast<void>(extraInfo);
    callbackObj->OnResult(ResultCode::NOT_ENROLLED, {});
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "authenticate, result is %{public}d",
        static_cast<int32_t>(ResultCode::NOT_ENROLLED));
    return HDF_SUCCESS;
}

// 实现人脸识别接口
int32_t Identify(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,
    const sptr<IExecutorCallback>& callbackObj)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(scheduleId);
    static_cast<void>(extraInfo);
    callbackObj->OnResult(ResultCode::OPERATION_NOT_SUPPORT, {});
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "identify, result is %{public}d",
        static_cast<int32_t>(ResultCode::OPERATION_NOT_SUPPORT));
    return HDF_SUCCESS;
}

// 实现删除人脸模板接口
int32_t Delete(const std::vector<uint64_t>& templateIdList)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(templateIdList);
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "delete success");
    return HDF_SUCCESS;
}

// 实现通过scheduleId取消指定操作接口
int32_t Cancel(uint64_t scheduleId)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(scheduleId);
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "cancel success");
    return HDF_SUCCESS;
}

// 实现人脸认证服务向Faceauth驱动传递参数的通用接口，当前需要实现冻结与解锁模板命令
int32_t SendCommand(int32_t commandId, const std::vector<uint8_t>& extraInfo,
    const sptr<IExecutorCallback>& callbackObj)
{
    FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "interface mock start");
    static_cast<void>(extraInfo);
    switch (commandId) {
        case LOCK_TEMPLATE:
            callbackObj->OnResult(ResultCode::SUCCESS, {});
            FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "unlock template, result is %{public}d",
                static_cast<int32_t>(ResultCode::SUCCESS));
            break;
        case UNLOCK_TEMPLATE:
            callbackObj->OnResult(ResultCode::SUCCESS, {});
            FACEAUTH_HILOGI(MODULE_DEFAULT_SERVICE, "unlock template, result is %{public}d",
                static_cast<int32_t>(ResultCode::SUCCESS));
            break;
        default:
            callbackObj->OnResult(ResultCode::GENERAL_ERROR, {});
            FACEAUTH_HILOGD(MODULE_DEFAULT_SERVICE, "not support CommandId : %{public}d", commandId);
    }
    return HDF_SUCCESS;
}
```

### 调测验证
驱动开发完成后，通过[用户认证 API接口](../../application-dev/reference/apis/js-apis-useriam-userauth.md)开发JS应用，基于Hi3516DV300平台验证认证和取消流程。

```js
// API version 8
import userIAM_userAuth from '@ohos.userIAM.userAuth';
let auth = new userIAM_userAuth.UserAuth();

export default {
    getVersion() {
        console.info("start get version");
        let version = this.auth.getVersion();
        console.info("auth version = " + version);
    },

    startAuth() {
        console.info("start auth");
        this.auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                try {
                    console.info("auth onResult result = " + result);
                    console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
                    if (result == 'SUCCESS') {
                        // 此处添加认证成功逻辑
                    }  else {
                        // 此处添加认证失败逻辑
                    }
                } catch (e) {
                    console.info("auth onResult error = " + e);
                }
            },

            onAcquireInfo: (module, acquire, extraInfo) => {
                try {
                    console.info("auth onAcquireInfo module = " + module);
                    console.info("auth onAcquireInfo acquire = " + acquire);
                    console.info("auth onAcquireInfo extraInfo = " + JSON.stringify(extraInfo));
                } catch (e) {
                    console.info("auth onAcquireInfo error = " + e);
                }
            }
        });
    },

    cancelAuth() {
        console.info("start cancel auth");
        // contextId通过auth接口获取
        let contextId = auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                console.info("auth onResult result = " + result);
            },

            onAcquireInfo: (module, acquire, extraInfo) => {
                console.info("auth onAcquireInfo module = " + module);
            }
        });
        let cancelCode = this.auth.cancel(contextId);
        if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
            console.info("cancel auth success");
        } else {
            console.error("cancel auth fail");
        }
    }
}
```

## 总结

以上就是基于Faceauth驱动框架进行移植开发过程中，所涉及的所有关键适配点。重点介绍了驱动适配方法、HDI层接口功能。开发者可以根据不同执行器进行适配。希望通过本次的文档，您能初步掌握基于HDF框架的Faceauth驱动开发。