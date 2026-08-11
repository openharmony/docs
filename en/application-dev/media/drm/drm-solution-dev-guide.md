# DRM Solution Development
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
DRM plugins provide implementations of the DRM HDI APIs. The DRM framework of DRM Kit loads DRM plugins through the HDI APIs.

Plugins are developed by DRM solution integrators and placed in the `/vendor` partition of devices.

For details about the development process of the OpenHarmony HDI plugin driver service, see [HDF Driver Development Process](../../../device-dev/driver/driver-hdf-manage.md). The IDL for the DRM HDI APIs is defined in the `ohos/drivers/interface/drm/v1_0` directory. Note that `v1_0` corresponds to the HDI API version number and should be adjusted based on the actual HDI API version.

After the IDL of the DRM HDI API is built, the generated `.h` and `.cpp` files are located in `//ohos/out/*productModel*/gen/drivers/interface/drm/v1_0/`.

To implement a DRM plugin (using clearplay as an example), perform the following steps:

1. [Plugin Development](#plugin-development)
    - Module addition
    - Driver entry implementation
    - HDI API implementation
    - Compilation configuration
    - Component configuration
    - Component build entry configuration
    - Service code build

2. [DRM Plugin Service Configuration](#drm-plugin-service-configuration)
    - hcs configuration
    - Host user and group configuration
    - Dynamic loading

3. [Adding SELinux Permissions](#adding-selinux-permissions)

## Plugin Development

### Module Addition

Create a plugin directory. The following is an example:
```txt
//drivers/peripheral/clearplay
.
├── BUILD.gn     # Module build configuration.
├── bundle.json  # Component configuration
├── hdi_service  # HDI service implementation of the DRM solution
│   ├── BUILD.gn # HDI service build configuration
│   ├── common   # Common utilities (JSON parsing, Base64 encoding/decoding)
│   ├── include  # HDI service header files
│   └── src      # HDI service source code
├── interfaces   # HDI service capability interfaces
│   ├── BUILD.gn # Interface build configuration
│   ├── include  # Interface definitions
│   └── src      # Interface implementations
└── README.md # Component documentation
```

### Driver Entry Implementation

For the driver entry implementation, refer to **//ohos/out/productModel/gen/drivers/interface/drm/v1_0/media_key_system_factory_driver.cpp**. In your implementation, make the following modifications and configure the build manually:

```cpp
using namespace OHOS::HDI::Drm::V1_0; // 1. V1_0 indicates the HDI API version number. Replace it with the actual version number.

struct HdfMediaKeySystemFactoryHost {
    struct IDeviceIoService ioService;
    OHOS::sptr<OHOS::IRemoteObject> stub;
};
static int HdfMediaKeySystemFactoryDriverBind(struct HdfDeviceObject *deviceObject)
{
    auto *hdfMediaKeySystemFactoryHost = new (std::nothrow) HdfMediaKeySystemFactoryHost;
    if (hdfMediaKeySystemFactoryHost == nullptr) {
        HDF_LOGE("%{public}s: failed to create HdfMediaKeySystemFactoryHost object", __func__);
        return HDF_FAILURE;
    }
    int ret = HdfDeviceObjectSetInterfaceDesc(deviceObject, "ohos.hdi.drm.v1_0.IMediaKeySystemFactory"); // 2. Bind the service interface descriptor. This allows the DRM framework to access the HDI service of the DRM solution via the descriptor. Adjust according to the specific HDI API version number.
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: failed to HdfDeviceObjectSetInterfaceDesc", __func__);
    }

    hdfMediaKeySystemFactoryHost->ioService.Dispatch = MediaKeySystemFactoryDriverDispatch;
    hdfMediaKeySystemFactoryHost->ioService.Open = NULL;
    hdfMediaKeySystemFactoryHost->ioService.Release = NULL;

    auto serviceImpl = OHOS::HDI::Drm::V1_0::IMediaKeySystemFactory::Get("clearplay_service", true); // 3. Obtain the HDI service instance of the DRM solution.
    if (serviceImpl == nullptr) {
        HDF_LOGE("%{public}s: failed to get of implement service", __func__);
        delete hdfMediaKeySystemFactoryHost;
        return HDF_FAILURE;
    }

    hdfMediaKeySystemFactoryHost->stub = OHOS::HDI::ObjectCollector::GetInstance().GetOrNewObject(serviceImpl,
        OHOS::HDI::Drm::V1_0::IMediaKeySystemFactory::GetDescriptor()); // 4. Obtain the stub object corresponding to the HDI service implementation of the DRM solution.
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

### HDI API Implementation

For the HDI API implementation, refer to the .cpp file automatically generated in **//ohos/out/*productModel*/gen/drivers/interface/drm/v1_0/**. You can modify or add files based on service requirements. The following uses **media_key_system_factory_service.cpp** as an example.

```cpp
extern "C" IMediaKeySystemFactory *MediaKeySystemFactoryImplGetInstance(void)
{
    // Add implementation here.
    return new (std::nothrow) MediaKeySystemFactoryService();
}

int32_t MediaKeySystemFactoryService::IsMediaKeySystemSupported(const std::string& name, const std::string& mimeType,
     OHOS::HDI::Drm::V1_0::ContentProtectionLevel level, bool& isSupported)
{
    // Add implementation here.
    return HDF_SUCCESS;
}

int32_t MediaKeySystemFactoryService::CreateMediaKeySystem(sptr<OHOS::HDI::Drm::V1_0::IMediaKeySystem>& mediaKeySystem)
{
    // Add implementation here.
    return HDF_SUCCESS;
}

int32_t MediaKeySystemFactoryService::GetMediaKeySystemDescription(std::string& name, std::string& uuid)
{
    // Add implementation here.
    return HDF_SUCCESS;
}

```

### Compilation Configuration
//drivers/peripheral/clearplay/BUILD.gn

```txt
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
```txt
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

```txt
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

### Component Configuration

Create the **drivers/peripheral/clearplay/build.json** file to define the drivers_peripheral_clearplay component.

```json
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
### Component Build Entry Configuration

The following uses RK3568 as an example. The entry configuration file is **//productdefine/common/inherit/chipset_common.json**.

```json
{
  "component": "drivers_peripheral_clearplay",
  "features": []
}
```

### Service Code Build

This process is similar to building system components.
`./build.sh --product-name rk3568 --ccache --build-target drivers_peripheral_clearplay`
The build generates the following binary files:
//ohos/out/rk3568/hdf/drivers_peripheral_clearplay/libclearplay_driver.z.so
//ohos/out/rk3568/hdf/drivers_peripheral_clearplay/libmedia_key_system_factory_clearplay_service_1.0.z.so

## DRM Plugin Service Configuration

### hcs Configuration

The following uses RK3568 as an example. Add the driver service configuration to **vendor/hihope/rk3568/hdf_config/uhdf/device_info.hcs**.

```txt
clearplay :: host {
    hostName = "clearplay_host";   // Process name.
    priority = 50;
    uid = ""; // User ID of the user-space process. It is left empty by default. If you do not set the value, this parameter will be set to the value of hostName (regular user).
    gid = ""; // Group ID of the user-space process. It is left empty by default. If you do not set the value, this parameter will be set to the value of hostName (regular user group).
    caps = ["DAC_OVERRIDE", "DAC_READ_SEARCH"]; // Linux capabilities of the user-space process. It is left empty by default. Set this parameter based on service requirements.
    clearplay_device :: device {
        device0 :: deviceNode {
            policy = 2;
            priority = 100;
            moduleName = "libclearplay_driver.z.so";  // Driver entry point.
            serviceName = "clearplay_service";        // Service name.
        }
    }
}
```

### Host User and Group Configuration

For any newly added host node in hcs, you must configure the uid and gid for the corresponding process.

The **passwd** file is a system user configuration file that stores basic information about all users. The following is an example:

```txt
//base/startup/init/services/etc/passwd
clearplay_host:x:1089:1089::/bin/false
```

Each line in the **//base/startup/init/services/etc/passwd** file represents a user, using the colon (:) as a delimiter, divided into seven fields. The meaning of each field is as follows:

Username: Password: uid: gid: Description: Home directory: Default shell

The **group** file is the user group configuration file that stores information about all user groups. The following is an example:

```txt
base/startup/init/services/etc/group
clearplay_host:x:1089:
```

Each line in the **base/startup/init/services/etc/group** file indicates a user group, using the colon (:) as a delimiter, divided into four fields. The meaning of each field is as follows:

Group name: Password: gid: List of users in the user group

> **NOTE**
>
> - **clearplay_host** in **passwd** corresponds to **uid** in **device_info.hcs**. If **uid** in **device_info.hcs** is not specified, the default value **hostName** is used.
> - **clearplay_host** in **group** corresponds to **gid** in **device_info.hcs**. If **gid** in **device_info.hcs** is not specified, the default value **hostName** is used.

### Dynamic Loading

To reduce Random Access Memory (RAM) usage, the DRM framework supports dynamic loading of DRM plugins. After calling a plugin, the framework promptly unloads it to free memory. The plugin must modify its service startup properties to configure itself as lazy-loaded and add itself to the lazy loading list configuration file of the DRM framework on the device. HDI services provide dynamic loading capabilities. By default, they are not loaded during system startup but can be loaded dynamically. Here is an example:

Set **preload** to **2** in **device_info.hcs**.

```txt
clearplay :: host {
    hostName = "clearplay_host";
    priority = 50;
    clearplay_device :: device {
        device0 :: deviceNode {
            policy = 2;
            priority = 100;
            preload = 2; // If preload is set to 2, the system does not load the file during startup by default. It can be loaded manually later.
            moduleName = "libclearplay_driver.z.so";
            serviceName = "clearplay_service";
        }
    }
}
```
The **/etc/drm/drm_plugin_lazyloding.cfg** file on the device is the lazy loading list configuration file of the DRM framework. The file is in the format of key-value pairs, where the DRM solution name is the key and the DRM service name is the value.
```json
{
    "plugin_services": {
        "lazy_load_service": [
            "com.clearplay.drm:clearplay_service"
        ]
    }
}
```

## Adding SELinux Permissions

SELinux is used to restrict resources that can be accessed by service processes. The following provides the basic SELinux configuration. Add required rules based on service requirements.

In the following example, **clearplay_host** indicates the value of **hostName** in hcs, and **clearplay_service** indicates the service name.

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/adapter/public/hdf_service_contexts
`clearplay_service                             u:object_r:hdf_clearplay_service:s0`

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/adapter/public/hdf_service.te
`type hdf_clearplay_service, hdf_service_attr;`

//base/security/selinux_adapter/sepolicy/ohos_policy/startup/init/public/chipset_init.te
`allow init clearplay_host:process { rlimitinh siginh transition };`

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/peripheral/clearplay/vendor/hdf_devmgr.te
```txt
allow hdf_devmgr clearplay_host:binder { call transfer };
allow hdf_devmgr clearplay_host:dir { search };
allow hdf_devmgr clearplay_host:file { open read };
allow hdf_devmgr clearplay_host:process { getattr };
```

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/adapter/public/type.te
`type clearplay_host, hdfdomain, domain;`

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/peripheral/clearplay/vendor/clearplay_host.te (Create this directory.)
```txt
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
