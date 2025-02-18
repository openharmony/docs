# DRM解决方案开发指导

DRM 解决方案插件实现 DRM HDI 接口（链接），DRM Kit的DRM框架将通过HDI接口加载DRM解决方案插件。

插件由DRM解决方案集成方开发，放置在设备的 /vendor 分区中。

OpenHarmony HDI 插件驱动服务开发流程参考[HDF驱动开发流程](../../../device-dev/driver/driver-hdf-manage.md)，DRM HDI API 的 IDL 在 ohos/drivers/interface/drm/v1_0 目录中定义，其中 v1_0 对应不同版本的 HDI API 版本号，需根据实际调用的 HDI API 版本进行修改。

DRM HDI API 的 IDL 构建完成后，可以在`//ohos/out/产品型号/gen/drivers/interface/drm/v1_0/`中找到生成的相应版本的 .h 和 .cpp文件。
实现 DRM 解决方案插件的步骤如下（以clearplay为例）：

1. [开发插件](#开发插件)
    - 模块添加
    - 驱动入口实现
    - HDI接口实现
    - 编译配置
    - 部件配置
    - 部件编译入口配置
    - 服务代码编译

2. [DRM解决方案插件服务配置](#drm解决方案插件服务配置)
    - hcs配置
    - host用户与组配置
    - 动态加载

3. [添加SELinux权限](#添加selinux权限)

## 开发插件

### 模块添加

创建插件目录，参考如下：
```
//drivers/peripheral/clearplay
.
├── BUILD.gn     # 模块编译BUILD.gn
├── bundle.json  # 部件配置
├── hdi_service  # DRM解决方案HDI服务代码
│   ├── BUILD.gn # DRM解决方案HDI服务代码编译BUILD.gn
│   ├── common   # DRM解决方案HDI服务依赖的工具类代码，包含json解析、base64编解码
│   ├── include  # RM解决方案HDI服务实现头文件
│   └── src      # DRM解决方案HDI服务实现代码
├── interfaces   # DRM解决方案HDI服务能力接口
│   ├── BUILD.gn # DRM解决方案HDI服务能力接口编译BUILD.gn
│   ├── include  # DRM解决方案HDI服务能力接口文件
│   └── src      # DRM解决方案HDI服务能力接口实现
└── README_zh.md # DRM解决方案HDI服务组件说明
```

### 驱动入口实现

驱动入口实现可以参考`//ohos/out/产品型号/gen/drivers/interface/drm/v1_0/media_key_system_factory_driver.cpp`，需要驱动入口实现中修改以下几点，并手动配置编译：

```
using namespace OHOS::HDI::Drm::V1_0; // 1、本文中 V1_0 为 HDI API 版本号，需根据不同版本进行变更

struct HdfMediaKeySystemFactoryHost {
    struct IDeviceIoService ioService;
    OHOS::sptr<OHOS::IRemoteObject> stub;
};
static int HdfMediaKeySystemFactoryDriverBind(struct HdfDeviceObject *deviceObject)
{
    auto *hdfMediaKeySystemFactoryHost = new (std::nothrow) HdfMediaKeySystemFactoryHost;
    if (hdfMediaKeySystemFactoryHost == nullptr) {
        HDF_LOGE("%{public}s: failed to create create HdfMediaKeySystemFactoryHost object", __func__);
        return HDF_FAILURE;
    }
    int ret = HdfDeviceObjectSetInterfaceDesc(deviceObject, "ohos.hdi.drm.v1_0.IMediaKeySystemFactory"); // 2. 服务绑定接口描述符，便于DRM框架服务通过接口描述符获取到DRM解决方案HDI服务，根据不同的HDI API版本号调整
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: failed to HdfDeviceObjectSetInterfaceDesc", __func__);
    }

    hdfMediaKeySystemFactoryHost->ioService.Dispatch = MediaKeySystemFactoryDriverDispatch;
    hdfMediaKeySystemFactoryHost->ioService.Open = NULL;
    hdfMediaKeySystemFactoryHost->ioService.Release = NULL;

    auto serviceImpl = OHOS::HDI::Drm::V1_0::IMediaKeySystemFactory::Get("clearplay_service", true); // 3. 获取DRM解决方案HDI服务实例
    if (serviceImpl == nullptr) {
        HDF_LOGE("%{public}s: failed to get of implement service", __func__);
        delete hdfMediaKeySystemFactoryHost;
        return HDF_FAILURE;
    }

    hdfMediaKeySystemFactoryHost->stub = OHOS::HDI::ObjectCollector::GetInstance().GetOrNewObject(serviceImpl,
        OHOS::HDI::Drm::V1_0::IMediaKeySystemFactory::GetDescriptor()); // 4. 获取DRM解决方案HDI服务实现对应的Stub对象
    if (hdfMediaKeySystemFactoryHost->stub == nullptr) {
        HDF_LOGE("%{public}s: failed to get stub object", __func__);
        delete hdfMediaKeySystemFactoryHost;
        return HDF_FAILURE;
    }

    deviceObject->service = &hdfMediaKeySystemFactoryHost->ioService;
    return HDF_SUCCESS;
}

static int32_t MediaKeySystemFactoryDriverDispatch(struct HdfDeviceIoClient *client, int cmdId, struct HdfSBuf *data,
    struct HdfSBuf *reply)
{
    auto *hdfMediaKeySystemFactoryHost =
        CONTAINER_OF(client->device->service, struct HdfMediaKeySystemFactoryHost, ioService);

    OHOS::MessageParcel *dataParcel = nullptr;
    OHOS::MessageParcel *replyParcel = nullptr;
    OHOS::MessageOption option;

    if (SbufToParcel(data, &dataParcel) != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: invalid data sbuf object to dispatch", __func__);
        return HDF_ERR_INVALID_PARAM;
    }
    if (SbufToParcel(reply, &replyParcel) != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: invalid reply sbuf object to dispatch", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    return hdfMediaKeySystemFactoryHost->stub->SendRequest(cmdId, *dataParcel, *replyParcel, option);
}
```

### HDI接口实现

实现可以参考<!--RP2-->`//ohos/out/产品型号/gen/drivers/interface/drm/v1_0/`<!--RP2End-->中自动生成的.cpp文件，可以按照业务需要进行定制化修改或新增文件，如`media_key_system_factory_service.cpp`：

```
extern "C" IMediaKeySystemFactory *MediaKeySystemFactoryImplGetInstance(void)
{
    // 请新增实现
    return new (std::nothrow) MediaKeySystemFactoryService();
}

int32_t MediaKeySystemFactoryService::IsMediaKeySystemSupported(const std::string& name, const std::string& mimeType,
     OHOS::HDI::Drm::V1_0::ContentProtectionLevel level, bool& isSupported)
{
    // 请新增实现
    return HDF_SUCCESS;
}

int32_t MediaKeySystemFactoryService::CreateMediaKeySystem(sptr<OHOS::HDI::Drm::V1_0::IMediaKeySystem>& mediaKeySystem)
{
    // 请新增实现
    return HDF_SUCCESS;
}

int32_t MediaKeySystemFactoryService::GetMediaKeySystemDescription(std::string& name, std::string& uuid)
{
    // 请新增实现
    return HDF_SUCCESS;
}

```

### 编译配置
//drivers/peripheral/clearplay/BUILD.gn

```
if (defined(ohos_lite)) {
  group("clearplay_entry") {
    deps = []
  }
} else {
  group("clearplay_entry") {
    deps = [
      "./hdi_service:hdf_clearplay_service",
      "./interfaces:hdf_clearplay_interfaces",
    ]
  }
}
```

//drivers/peripheral/clearplay/hdi_service/BUILD.gn
```
import("//build/ohos.gni")

ohos_shared_library("libmedia_key_system_factory_clearplay_service_1.0") {
  include_dirs = [
    "./include",
    "./include/drm/v1_0",
    "./include/drm",
    "./../interfaces/include",
    "./../interfaces/include/drm/v1_0",
    "./../interfaces/include/drm",
    "./common",
  ]
  sources = [
    "./common/base64_utils.cpp",
    "./src/media_decrypt_module_service.cpp",
    "./src/media_key_session_callback_service.cpp",
    "./src/media_key_session_service.cpp",
    "./src/media_key_system_callback_service.cpp",
    "./src/media_key_system_factory_service.cpp",
    "./src/media_key_system_service.cpp",
    "./src/oem_certificate_service.cpp",
  ]

  deps = [ ]

  cflags = [
    "-Wall",
    "-Wextra",
    "-Werror",
    "-fsigned-char",
    "-fno-common",
    "-fno-strict-aliasing",
  ]

  external_deps = [
    "c_utils:utils",
    "hdf_core:libhdf_utils",
    "hilog:libhilog",
    "ipc:ipc_single",
  ]

  install_images = [ chipset_base_dir ]
  subsystem_name = "hdf"
  part_name = "drivers_peripheral_clearplay"
}

group("hdf_clearplay_service") {
  deps = [ ":libmedia_key_system_factory_clearplay_service_1.0" ]
}
```

//drivers/peripheral/clearplay/interfaces/BUILD.gn

```
import("//build/ohos.gni")

ohos_shared_library("libclearplay_driver") {
  include_dirs = [
    "./include",
    "./include/drm",
  ]

  public_configs = [ ":clearplay_imp_external_library_config" ]
  sources = [ "./src/media_key_system_factory_driver.cpp" ]

  external_deps = [
    "c_utils:utils",
    "drivers_interface_drm:libdrm_stub_1.0",
    "hdf_core:libhdf_host",
    "hdf_core:libhdf_ipc_adapter",
    "hdf_core:libhdf_utils",
    "hdf_core:libhdi",
    "hilog:libhilog",
    "ipc:ipc_single",
  ]
  cflags = [
    "-Wall",
    "-Wextra",
    "-Werror",
    "-fsigned-char",
    "-fno-common",
    "-fno-strict-aliasing",
  ]
  shlib_type = "hdi"
  install_images = [ chipset_base_dir ]
  subsystem_name = "hdf"
  part_name = "drivers_peripheral_clearplay"
}

config("clearplay_imp_external_library_config") {
  include_dirs =
      [ "//drivers/peripheral/clearplay/interfaces/include/drm/v1_0" ]
}
group("hdf_clearplay_interfaces") {
  deps = [ ":libclearplay_driver" ]
}
```

### 部件配置

新建drivers/peripheral/clearplay/build.json用于定义新增的drivers_peripheral_clearplay部件：

```
{
  "name": "@ohos/drivers_peripheral_clearplay",
  "description": "clearplay drm device driver",
  "version": "4.0",
  "license": "Apache License 2.0",
  "publishAs": "code-segment",
  "segment": {
    "destPath": "drivers/peripheral/clearplay"
  },
  "dirs": {},
  "scripts": {},
  "component": {
    "name": "drivers_peripheral_clearplay",
    "subsystem": "hdf",
    "syscap": [],
    "adapted_system_type": ["standard"],
    "rom": "",
    "ram": "",
    "deps": {
      "components": [
        "bounds_checking_function",
        "drivers_interface_drm",
        "c_utils",
        "hdf_core",
        "hilog",
        "ipc"
      ],
      "third_party": []
    },
    "build": {
      "sub_component": [
        "//drivers/peripheral/clearplay:clearplay_entry"
      ],
      "inner_kits": [
        {
          "type":"so",
          "name": "//drivers/peripheral/clearplay/hdi_service:libmedia_key_system_factory_clearplay_service_1.0",
            "header": {
              "header_files": [
                "imedia_decrypt_module.h",
                "imedia_key_session_callback.h",
                "imedia_key_session.h",
                "imedia_key_system_callback.h",
                "imedia_key_system_factory.h",
                "imedia_key_system.h",
                "ioem_certificate.h",
                "media_decrypt_module_proxy.h",
                "media_decrypt_module_stub.h",
                "media_key_session_callback_proxy.h",
                "media_key_session_callback_stub.h",
                "media_key_session_proxy.h",
                "media_key_session_stub.h",
                "media_key_system_callback_proxy.h",
                "media_key_system_callback_stub.h",
                "media_key_system_factory_proxy.h",
                "media_key_system_factory_stub.h",
                "media_key_system_proxy.h",
                "media_key_system_stub.h",
                "media_key_system_types.h",
                "oem_certificate_proxy.h",
                "oem_certificate_stub.h"
              ],
              "header_base": "//drivers/peripheral/clearplay/interfaces/include/drm/v1_0"
          }
        },
        {
          "type":"so",
          "name": "//drivers/peripheral/clearplay/interfaces:libclearplay_driver",
            "header": {
              "header_files": [],
              "header_base": "//drivers/peripheral/clearplay/interfaces/include/drm/v1_0"
          }
        }
      ]
    }
  }
}
```
### 部件编译入口配置

以rk3568产品为例：`//productdefine/common/inherit/chipset_common.json`

```
{
  "component": "drivers_peripheral_clearplay",
  "features": []
}
```

### 服务代码编译

与编译系统部件编译类似：
`./build.sh --product-name rk3568 --ccache --build-target drivers_peripheral_clearplay`
编译生成的二进制文件如下：
//ohos/out/rk3568/hdf/drivers_peripheral_clearplay/libclearplay_driver.z.so
//ohos/out/rk3568/hdf/drivers_peripheral_clearplay/libmedia_key_system_factory_clearplay_service_1.0.z.so

## DRM解决方案插件服务配置

### hcs配置

以rk3568产品为例，在`vendor/hihope/rk3568/hdf_config/uhdf/device_info.hcs`添加驱动服务配置

```
clearplay :: host {
    hostName = "clearplay_host";   // 进程名
    priority = 50;
    uid = ""; // 用户态进程uid，缺省为空，会被配置为hostName的定义值，即普通用户
    gid = ""; // 用户态进程gid，缺省为空，会被配置为hostName的定义值，即普通用户组
    caps = ["DAC_OVERRIDE", "DAC_READ_SEARCH"]; // 用户态进程Linux capabilities配置，缺省为空，需要业务模块按照业务需要进行配置
    clearplay_device :: device {
        device0 :: deviceNode {
            policy = 2;
            priority = 100;
            moduleName = "libclearplay_driver.z.so";  // 驱动加载入口
            serviceName = "clearplay_service";        // 服务名称
        }
    }
}
```

### host用户与组配置

对于在hcs中新增加的host节点，需要新增配置对应进程的uid（用户ID）和gid（组ID）
passwd文件为系统用户配置文件，存储了系统中所有用户的基本信息，这里以此为例：

```
//base/startup/init/services/etc/passwd
clearplay_host:x:1089:1089:::/bin/false
```

`//base/startup/init/services/etc/passwd`中每行用户信息使用“:”作为分隔符，划分为7个字段，每个字段所表示的含义如下：
用户名：密码：UID（用户ID）：GID（组ID）：描述信息：主目录：默认shell

group为用户组配置文件，存储了所有用户组的信息，以下为例：

```
base/startup/init/services/etc/group
clearplay_host:x:1089:
```

base/startup/init/services/etc/group中每行代表一个用户组，用户组中以“:”作为分隔符，分为4个字段，每个字段的含义如下：
组名：密码：GID(组ID):该用户组中的用户列表
注意：
- passwd中clearplay_host对应device_info.hcs中的uid，若device_info.hcs中uid缺省，则默认为hostName
- group中clearplay_host对应device_info.hcs中的gid，若device_info.hcs中gid缺省，则默认为hostName

### 动态加载

为节约 RAM 内存占用，DRM 框架服务支持动态加载 DRM 解决方案插件，DRM 框架服务调用完解决方案插件后，及时卸载 DRM 解决方案插件，释放 RAM 内存占用，插件需通过修改服务启动属性将自身服务配置成懒加载，并加入到设备上的 DRM 框架服务懒加载列表配置文件中;HDI服务提供动态加载能力，系统启动过程中默认不加载，支持动态加载，以下为示例：
`device_info.hcs`配置preload为2
```
clearplay :: host {
    hostName = "clearplay_host";
    priority = 50;
    clearplay_device :: device {
        device0 :: deviceNode {
            policy = 2;
            priority = 100;
            preload = 2; // 设置preload为2，则系统启动过程中默认不加载，后续可手动加载
            moduleName = "libclearplay_driver.z.so";
            serviceName = "clearplay_service";
        }
    }
}
```
设备上`/etc/drm/drm_plugin_lazyloding.cfg`为 DRM 框架服务懒加载列表配置文件，键值对形式，DRM 解决方案插件解决方案名为键，DRM解决方案服务名为值：
```
{
    "plugin_services": {
        "lazy_load_service": [
            "com.clearplay.drm:clearplay_service"
        ]
    }
}
```

## 添加SELinux权限

selinux用于限制服务进程可访问的资源，以下给定基础的selinux配置，在此基础上按业务添加所需规则。

注意：以下示例中，clearplay_host表示hcs中的hostName值，clearplay_service表示服务名称
//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/adapter/public/hdf_service_contexts
`clearplay_service                             u:object_r:hdf_clearplay_service:s0`

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/adapter/public/hdf_service.te
`type hdf_clearplay_service, hdf_service_attr;`

//base/security/selinux_adapter/sepolicy/ohos_policy/startup/init/public/chipset_init.te
`allow init clearplay_host:process { rlimitinh siginh transition };`

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/peripheral/clearplay/vendor/hdf_devmgr.te
```
allow hdf_devmgr clearplay_host:binder { call transfer };
allow hdf_devmgr clearplay_host:dir { search };
allow hdf_devmgr clearplay_host:file { open read };
allow hdf_devmgr clearplay_host:process { getattr };
```

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/adapter/public/type.te
`type clearplay_host, hdfdomain, domain;`

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/peripheral/clearplay/vendor/clearplay_host.te（新建此目录）
```
allow clearplay_host chip_prod_file:dir { search };
allow clearplay_host dev_console_file:chr_file { read write };
allow clearplay_host dev_hdf_kevent:chr_file { open read write ioctl getattr };
allow clearplay_host dev_unix_socket:dir { search };
allow clearplay_host hdf_device_manager:hdf_devmgr_class { get };
allow clearplay_host hdf_devmgr:binder { call transfer };
allow clearplay_host hdf_clearplay_service:hdf_devmgr_class { add };
allow clearplay_host hilog_param:file { open read map };
allow clearplay_host musl_param:file { open read map };
allow clearplay_host sa_device_service_manager:samgr_class { get };
allow clearplay_host samgr:binder { call };
allow clearplay_host sh:binder { call };
allow clearplay_host vendor_etc_file:dir { open read getattr search };
allow clearplay_host vendor_etc_file:file { open read getattr };
allowxperm clearplay_host dev_hdf_kevent:chr_file ioctl { 0x6202 0x6203 };
```