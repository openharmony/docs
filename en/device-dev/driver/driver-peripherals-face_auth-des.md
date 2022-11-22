# Facial Authentication

## Overview

### Function

Facial authentication provides user authentication capabilities in identity authentication scenarios, such as device unlocking, payment, and app logins. It uses biometric recognition technologies to identify individuals based on facial characteristics. A camera is used to collect images or video streams that contain human faces, and automatically detect, track, and recognize human faces. Facial authentication is also called facial recognition. The figure below shows the architecture of facial authentication.

The face authentication (Face_auth) driver is developed based on the Hardware Driver Foundation (HDF). It shields hardware differences and provides stable facial authentication capabilities for the user authentication framework (User_auth) and Face_auth service. The facial authentication capabilities include obtaining facial recognition executor list, executor information, and template information by template ID, comparing face image template information of the executor and that of User_auth, enrolling or deleting face image templates, and performing facial authentication.

**Figure 1** Facial authentication architecture

![image](figures/face_auth_architecture.png "Facial authentication architecture")

### Basic Concepts

The identity authentication consists of User_auth and basic authentication services (including PIN authentication and facial authentication). It supports basic functions such as setting and deleting user credentials and performing authentication. The system supports user identity authentication and data collection, processing, storage, and comparison.
- Executor

  The executor collects, processes, stores, and compares data for authentication. Each authentication service provides the executor capabilities, which are scheduled by User_auth to implement basic capabilities.

- Executor security level

  Security level required for the execution environment of an executor.

- Executor role

  - Executor: independently completes the entire process of credential registration and identity authentication. The executor can collect, process, store, and compare data to complete the authentication.

  - Collector: only collects data during user authentication. It needs to work with the authenticator to complete user authentication.

  - Authenticator: only processes data, obtains the stored credential template, and compares it with the authentication information generated.

- Executor type

  The authentication algorithm varies depending on the authentication mode and device used. Different executor types are defined based on the supported algorithm type or the device in use.

- User_auth public key & executor public key

  To ensure user data security and authentication result accuracy, measures must be taken to protect the integrity of the key information exchanged between User_auth and basic authentication services. Public keys must be exchanged when the executor provided by a basic authentication service interworks with User_auth.

    The executor uses the User_auth public key to verify scheduling instructions.

    User_auth uses the executor public key to verify the authentication result accuracy and the integrity of the information exchanged with the executor.

- Authentication credential template

  Authentication credentials are generated and stored by the authentication service when users set authentication credentials. Each template has an ID to index a set of template information files. The template information needs to be compared with the authentication data generated during authentication to complete identity authentication.

- Data verification by the executor

  User_auth manages the mappings between user identities and credential IDs in a unified manner. When connecting to User_auth, the executor obtains the template ID list from User_auth and updates its template ID list based on the template ID list obtained.

### Working Principles

The Face_auth driver provides basic facial authentication capabilities for the User_auth and Face_auth service to ensure successful facial authentication.
You can develop drivers to call Hardware Device Interface (HDI) APIs based on the HDF and the chip you use.

**Figure 2** Face_auth service and Face_auth driver interaction

![image](figures/face_auth_service_and_driver_interaction.png "Face_auth service and Face_auth driver interaction")

### Constraints

- To implement facial authentication, the device must have a camera and the face image must be greater than 100 x 100 pixels.
- A Trusted Execution Environment (TEE) must be available, and facial feature information must be encrypted and stored in a TEE.
- The face matching accuracy varies with people with similar looks and children whose facial features keep changing. If you are concerned about this, consider using other authentication modes.

## Development Guidelines

### When to Use

The Face_auth driver provides basic facial authentication capabilities for the User_auth and Face_auth service to ensure successful facial authentication.

### Available APIs

**Table 1** Available APIs

| API                                                      | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| GetExecutorList(std::vector<sptr<IExecutor>>& executorList)  | Obtains the executor list.                                            |
| GetExecutorInfo(ExecutorInfo& info)                          | Obtains the executor information, including the executor type, executor role, authentication type, security level, and executor public key.|
| GetTemplateInfo(uint64_t templateId, TemplateInfo& info)     | Obtains information about a face image template based on the specified template ID.                              |
| OnRegisterFinish(const std::vector<uint64_t>& templateIdList,<br>        const std::vector<uint8_t>& frameworkPublicKey, const std::vector<uint8_t>& extraInfo) | Obtains the public key and template ID list from User_auth after the executor is registered successfully.|
| Enroll(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,<br>        const sptr<IExecutorCallback>& callbackObj) | Enrolls a face image template.                                              |
| Authenticate(uint64_t scheduleId, const std::vector<uint64_t>& templateIdList,<br>        const std::vector<uint8_t>& extraInfo, const sptr<IExecutorCallback>& callbackObj) | Performs facial authentication.                                              |
| Identify(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,<br>        const sptr<IExecutorCallback>& callbackObj) | Performs facial identification.                                              |
| Delete(const std::vector<uint64_t>& templateIdList)          | Deletes a face image template.                                              |
| Cancel(uint64_t scheduleId)                                  | Cancels a face enrolling, authentication, or identification operation based on the **scheduleId**.                |
| SendCommand(int32_t commandId, const std::vector<uint8_t>& extraInfo,<br>        const sptr<IExecutorCallback>& callbackObj) | Sends commands to the Face_auth service.             |

**Table 2** Callbacks

| API                                                      | Description                |
| ------------------------------------------------------------ | ------------------------ |
| IExecutorCallback::OnResult(int32_t code, const std::vector<uint8_t>& extraInfo) | Called to return the operation result.    |
| IExecutorCallback::OnTip(int32_t code, const std::vector<uint8_t>& extraInfo) | Called to return the interaction information about the operation process.|

### How to Develop

The following uses the Hi3516D V300 development board as an example to demonstrate how to develop the Face_auth driver. <br/>The directory structure is as follows:

```undefined
// drivers/peripheral/face_auth
├── BUILD.gn # Build script
├── bundle.json # Module description file
└── hdi_service # Face_auth driver implementation
    ├── BUILD.gn # Build script
    ├── include # Header files
    └── src
        ├── executor_impl.cpp # Implementation of authentication and enrollment APIs
        ├── face_auth_interface_driver.cpp # Face_auth driver entry
        └── face_auth_interface_service.cpp # Implementation of the APIs for obtaining the executor list
```

The development procedure is as follows:

1. Develop the Face_auth driver based on the HDF. The **Bind()**, **Init()**, **Release()**, and **Dispatch()** functions are used. For details about the code, see [face_auth_interface_driver.cpp](https://gitee.com/openharmony/drivers_peripheral/blob/master/face_auth/hdi_service/src/face_auth_interface_driver.cpp).

   ```c++
   // Create an IRemoteObject object by using the custom HdfFaceAuthInterfaceHost object, which consists of the IoService object and HDI service.
   struct HdfFaceAuthInterfaceHost {
       struct IDeviceIoService ioService;
       OHOS::sptr<OHOS::IRemoteObject> stub;
   };
   
   // Enable the IPC service to call the response API.
   static int32_t FaceAuthInterfaceDriverDispatch(struct HdfDeviceIoClient *client, int cmdId, struct HdfSBuf *data,
       struct HdfSBuf *reply)
   {
       IAM_LOGI("start");
       auto *hdfFaceAuthInterfaceHost = CONTAINER_OF(client->device->service,
           struct HdfFaceAuthInterfaceHost, ioService);
   
       OHOS::MessageParcel *dataParcel = nullptr;
       OHOS::MessageParcel *replyParcel = nullptr;
       OHOS::MessageOption option;
   
       if (SbufToParcel(data, &dataParcel) != HDF_SUCCESS) {
           IAM_LOGE("%{public}s:invalid data sbuf object to dispatch", __func__);
           return HDF_ERR_INVALID_PARAM;
       }
       if (SbufToParcel(reply, &replyParcel) != HDF_SUCCESS) {
           IAM_LOGE("%{public}s:invalid reply sbuf object to dispatch", __func__);
           return HDF_ERR_INVALID_PARAM;
       }
   
       return hdfFaceAuthInterfaceHost->stub->SendRequest(cmdId, *dataParcel, *replyParcel, option);
   }
   
   // Initialize the HdfFaceAuthInterfaceDriver object.
   int HdfFaceAuthInterfaceDriverInit(struct HdfDeviceObject *deviceObject)
   {
       IAM_LOGI("start");
       if (!HdfDeviceSetClass(deviceObject, DEVICE_CLASS_USERAUTH)) {
           IAM_LOGE("set face auth hdf class failed");
           return HDF_FAILURE;
       }
       return HDF_SUCCESS;
   }
   
   // Bind the service provided by the Face_auth driver to the HDF. 
   int HdfFaceAuthInterfaceDriverBind(struct HdfDeviceObject *deviceObject)
   {
       IAM_LOGI("start");
       auto *hdfFaceAuthInterfaceHost = new (std::nothrow) HdfFaceAuthInterfaceHost;
       if (hdfFaceAuthInterfaceHost == nullptr) {
           IAM_LOGE("%{public}s: Failed to create HdfFaceAuthInterfaceHost object", __func__);
           return HDF_FAILURE;
       }
   
       hdfFaceAuthInterfaceHost->ioService.Dispatch = FaceAuthInterfaceDriverDispatch;
       hdfFaceAuthInterfaceHost->ioService.Open = NULL;
       hdfFaceAuthInterfaceHost->ioService.Release = NULL;
   
       auto serviceImpl = IFaceAuthInterface::Get(true);
       if (serviceImpl == nullptr) {
           IAM_LOGE("%{public}s: Failed to implement service", __func__);
           return HDF_FAILURE;
       }
   
       hdfFaceAuthInterfaceHost->stub = OHOS::HDI::ObjectCollector::GetInstance().GetOrNewObject(serviceImpl,
           IFaceAuthInterface::GetDescriptor());
       if (hdfFaceAuthInterfaceHost->stub == nullptr) {
           IAM_LOGE("%{public}s: Failed to get stub object", __func__);
           return HDF_FAILURE;
       }
   
       deviceObject->service = &hdfFaceAuthInterfaceHost->ioService;
       IAM_LOGI("success");
       return HDF_SUCCESS;
   }
   
   // Release resources of the Face_auth driver.
   void HdfFaceAuthInterfaceDriverRelease(struct HdfDeviceObject *deviceObject)
   {
       IAM_LOGI("start");
       auto *hdfFaceAuthInterfaceHost = CONTAINER_OF(deviceObject->service,
           struct HdfFaceAuthInterfaceHost, ioService);
       delete hdfFaceAuthInterfaceHost;
       IAM_LOGI("success");
   }
   
   // Register the entry data structure object of the Face_auth driver.
   struct HdfDriverEntry g_faceAuthInterfaceDriverEntry = {
       .moduleVersion = 1,
       .moduleName = "faceauth_interface_service",
       .Bind = HdfFaceAuthInterfaceDriverBind,
       .Init = HdfFaceAuthInterfaceDriverInit,
       .Release = HdfFaceAuthInterfaceDriverRelease,
   };
   
   // Call HDF_INIT to register the driver entry with the HDF. When loading the driver, the HDF calls the Bind() function and then the Init() function. If the Init() function fails to be called, the HDF will call Release() to release driver resources and exit the driver model.
   HDF_INIT(g_faceAuthInterfaceDriverEntry);
   ```

2. Implement the API for obtaining the executor list. For details about the code, see [face_auth_interface_service.cpp](https://gitee.com/openharmony/drivers_peripheral/blob/master/face_auth/hdi_service/src/face_auth_interface_service.cpp).

   ```c++
   // Executor implementation class
   class ExecutorImpl : public IExecutor {
   public:
       ExecutorImpl(struct ExecutorInfo executorInfo);
       virtual ~ExecutorImpl() {}
   
   private:
       struct ExecutorInfo executorInfo_; // Executor information
   };
   
   static constexpr uint16_t SENSOR_ID = 123; // Executor sensor ID
   static constexpr uint32_t EXECUTOR_TYPE = 123; // Executor type
   static constexpr size_t PUBLIC_KEY_LEN = 32; //32-byte public key of the executor
   
   // Create an HDI service object.
   extern "C" IFaceAuthInterface *FaceAuthInterfaceImplGetInstance(void)
   {
       auto faceAuthInterfaceService = new (std::nothrow) FaceAuthInterfaceService();
       if (faceAuthInterfaceService == nullptr) {
           IAM_LOGE("faceAuthInterfaceService is nullptr");
           return nullptr;
       }
       return faceAuthInterfaceService;
   }
   
   // Obtain the executor list and create an executor.
   int32_t GetExecutorList(std::vector<sptr<IExecutor>>& executorList)
   {
       IAM_LOGI("interface mock start");
       executorList.clear();
       struct ExecutorInfo executorInfoExample = {
           .sensorId = SENSOR_ID,
           .executorType = EXECUTOR_TYPE,
           .executorRole = ExecutorRole::ALL_IN_ONE,
           .authType = AuthType::FACE,
           .esl = ExecutorSecureLevel::ESL0, // Executor security level, which ranges from ESL0 to ESL3 (highest).
           .publicKey = std::vector<uint8_t>(PUBLIC_KEY_LEN, 0), // 32-byte public key, using the Ed25519 algorithm.
           .extraInfo = {},
       };
       auto executor = new (std::nothrow) ExecutorImpl(executorInfoExample);
       if (executor == nullptr) {
           IAM_LOGE("executor is nullptr");
           return HDF_FAILURE;
       }
       executorList.push_back(sptr<IExecutor>(executor));
       IAM_LOGI("interface mock success");
       return HDF_SUCCESS;
   }
   ```

3. Implement each function of the executor. For details about the code, see [executor_impl.cpp](https://gitee.com/openharmony/drivers_peripheral/blob/master/face_auth/hdi_service/src/executor_impl.cpp).

   ```c++
   // Obtain the executor information.
   int32_t GetExecutorInfo(ExecutorInfo& info)
   {
       IAM_LOGI("interface mock start");
       info = executorInfo_;
       IAM_LOGI("Executor information got successfully");
       return HDF_SUCCESS;
   }
   
   // Obtain template information based on templateId.
   int32_t GetTemplateInfo(uint64_t templateId, TemplateInfo& info)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(templateId);
       info = {0};
       IAM_LOGI("Template information got successfully");
       return HDF_SUCCESS;
   }
   
   // After the executor is successfully registered, obtain the public key and template ID list from User_auth and save the public key. The executor compares its template ID list with the template ID list obtained and updates its template ID list.
   int32_t OnRegisterFinish(const std::vector<uint64_t>& templateIdList,
       const std::vector<uint8_t>& frameworkPublicKey, const std::vector<uint8_t>& extraInfo)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(templateIdList);
       static_cast<void>(extraInfo);
       static_cast<void>(frameworkPublicKey);
       IAM_LOGI("Registration finished");
       return HDF_SUCCESS;
   }
   
   // Enroll a face image.
   int32_t Enroll(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,
       const sptr<IExecutorCallback>& callbackObj)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(scheduleId);
       static_cast<void>(extraInfo);
       IAM_LOGI("enroll, result is %{public}d", ResultCode::OPERATION_NOT_SUPPORT);
       int32_t ret = callbackObj->OnResult(ResultCode::OPERATION_NOT_SUPPORT, {});
       if (ret != ResultCode::SUCCESS) {
           IAM_LOGE("callback result is %{public}d", ret);
           return HDF_FAILURE;
       }
       return HDF_SUCCESS;
   }
   
   // Start facial authentication.
   int32_t Authenticate(uint64_t scheduleId, const std::vector<uint64_t>& templateIdList,
       const std::vector<uint8_t>& extraInfo, const sptr<IExecutorCallback>& callbackObj)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(scheduleId);
       static_cast<void>(templateIdList);
       static_cast<void>(extraInfo);
       IAM_LOGI("authenticate, result is %{public}d", ResultCode::NOT_ENROLLED);
       int32_t ret = callbackObj->OnResult(ResultCode::NOT_ENROLLED, {});
       if (ret != ResultCode::SUCCESS) {
           IAM_LOGE("callback result is %{public}d", ret);
           return HDF_FAILURE;
       }
       return HDF_SUCCESS;
   }
   
   // Perform facial recognition.
   int32_t Identify(uint64_t scheduleId, const std::vector<uint8_t>& extraInfo,
       const sptr<IExecutorCallback>& callbackObj)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(scheduleId);
       static_cast<void>(extraInfo);
       IAM_LOGI("identify, result is %{public}d", ResultCode::OPERATION_NOT_SUPPORT);
       int32_t ret = callbackObj->OnResult(ResultCode::OPERATION_NOT_SUPPORT, {});
       if (ret != ResultCode::SUCCESS) {
           IAM_LOGE("callback result is %{public}d", ret);
           return HDF_FAILURE;
       }
       return HDF_SUCCESS;
   }
   
   // Delete the face image template.
   int32_t Delete(const std::vector<uint64_t>& templateIdList)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(templateIdList);
       IAM_LOGI("delete success");
       return HDF_SUCCESS;
   }
   
   // Cancel the operation based on the specified scheduleId.
   int32_t Cancel(uint64_t scheduleId)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(scheduleId);
       IAM_LOGI("cancel success");
       return HDF_SUCCESS;
   }
   
   // Send template locking or unlocking command from the Face_auth service to the Face_auth driver.
   int32_t SendCommand(int32_t commandId, const std::vector<uint8_t>& extraInfo,
       const sptr<IExecutorCallback>& callbackObj)
   {
       IAM_LOGI("interface mock start");
       static_cast<void>(extraInfo);
       int32_t ret;
       switch (commandId) {
           case LOCK_TEMPLATE:
               IAM_LOGI("unlock template, result is %{public}d", ResultCode::SUCCESS);
               ret = callbackObj->OnResult(ResultCode::SUCCESS, {});
               if (ret != ResultCode::SUCCESS) {
                   IAM_LOGE("callback result is %{public}d", ret);
                   return HDF_FAILURE;
               }
               break;
           case UNLOCK_TEMPLATE:
               IAM_LOGI("unlock template, result is %{public}d", ResultCode::SUCCESS);
               ret = callbackObj->OnResult(ResultCode::SUCCESS, {});
               if (ret != ResultCode::SUCCESS) {
                   IAM_LOGE("callback result is %{public}d", ret);
                   return HDF_FAILURE;
               }
               break;
           default:
               IAM_LOGD("not support CommandId : %{public}d", commandId);
               ret = callbackObj->OnResult(ResultCode::GENERAL_ERROR, {});
               if (ret != ResultCode::SUCCESS) {
                   IAM_LOGE("callback result is %{public}d", ret);
                   return HDF_FAILURE;
               }
       }
       return HDF_SUCCESS;
   }
   ```
   
4. Modify **serviceName2Config** in the **face_auth_service.cpp** file if you need to add a driver or modify driver information.

   ```c++
   // base/user_iam/face_auth/services/src/face_auth_service.cpp
   void FaceAuthService::StartDriverManager()
   {
       IAM_LOGI("start");
       // Service name and ID of the driver to add or modify. The driver service name and ID must be globally unique.
       const std::map<std::string, UserAuth::ServiceConfig> serviceName2Config = {
           {"face_auth_interface_service", {1, std::make_shared<FaceAuthDriverHdi>()}},
       };
       UserIAM::UserAuth::IDriverManager::GetInstance().Start(serviceName2Config);
   }
   ```

### Verification

Use the [User Authentication APIs](../../application-dev/reference/apis/js-apis-useriam-userauth.md) to develop a JavaScript application and verify the application on the Hi3516D V300 development board. The sample code for verifying and canceling the authentication is as follows:

```js
// API version 8
import userIAM_userAuth from '@ohos.userIAM.userAuth';
let auth = new userIAM_userAuth.UserAuth();

export default {
    getVersion() {
        console.info("start to get version");
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
                    if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                        // Add the logic to be executed when the authentication is successful.
                    }  else {
                        // Add the logic to be executed when the authentication fails.
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
        // Obtain contextId using auth().
        let contextId = auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                console.info("auth onResult result = " + result);
            },

            onAcquireInfo: (module, acquire, extraInfo) => {
                console.info("auth onAcquireInfo module = " + module);
            }
        });
        let cancelCode = this.auth.cancel(contextId);
        if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
            console.info("Authentication canceled successfully");
        } else {
            console.error("failed to cancel authentication");
        }
    }
}
```
