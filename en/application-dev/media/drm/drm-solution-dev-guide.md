# DRM Solution Development
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->
DRM plugins implement the DRM HDI, and the DRM framework of DRM Kit loads the DRM plugins through the HDI.

Plugins are developed by DRM solution integrators and placed in the /vendor partition of devices.

For details about the development process of the OpenHarmony HDI plugin driver service, see [HDF Driver Development Process](../../../device-dev/driver/driver-hdf-manage.md). The IDL of the DRM HDI API is defined in the **ohos/drivers/interface/drm/v1_0** directory, where **v1_0** is the HDI API version number and should be changed to the actual version number.

After the IDL of the DRM HDI API is built, you can find the generated .h and .cpp files of the corresponding version in **//ohos/out/*productModel*/gen/drivers/interface/drm/v1_0/**.

To implement a DRM plugin (clearplay used as an example), perform the following steps:

1. [Plugin Development](#plugin-development)
    - Module addition
    - Driver entry implementation
    - HDI API implementation
    - Compilation configuration
    - Component configuration
    - Component compilation entry configuration
    - Service code compilation

2. [DRM Plugin Service Configuration](#drm-plugin-service-configuration)
    - hcs configuration
    - Host user and group configuration
    - Dynamic loading

3. [Adding SELinux Permissions](#adding-selinux-permissions)

## Plugin Development

### Module Addition

Create a plugin directory. The following is an example:
```
//drivers/peripheral/clearplay
.
├── BUILD.gn     # Module compilation file.
├── bundle.json  # Component configuration file.
├── hdi_service  # HDI service code of the DRM solution.
│   ├── BUILD.gn # Configuration file for the HDI service code of the DRM solution.
│   ├── common   # Utility code for the HDI service of the DRM solution, including JSON parsing and Base64 encoding/decoding.
│   ├── include  # Header file for the HDI service of the DRM solution.
│   └── src      # Implementation code for the HDI service of DRM solution.
├── interfaces   # Capability interfaces for the HDI service of the DRM solution.
│   ├── BUILD.gn # Configuration file for the capability interfaces of the HDI service code of the DRM solution.
│   ├── include  # Capability interface file for the HDI service of the DRM solution.
│   └── src      # Implementation of the capability interfaces of the HDI service of the DRM solution.
└── README.md # Description of the HDI service component in the DRM solution.
```

### Driver Entry Implementation

Refer to **//ohos/out/productModel/gen/drivers/interface/drm/v1_0/media_key_system_factory_driver.cpp** for the driver entry implementation. Make the following modifications in the driver entry and configure the compilation manually:

```
using namespace OHOS::HDI::Drm::V1_0; // 1. V1_0 indicates the HDI API version number. Replace it with the actual version number.

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

Refer to the .cpp file automatically generated in **//ohos/out/*productModel*/gen/drivers/interface/drm/v1_0/** for the HDI API implementation. You can modify or add files based on service requirements. The following uses **media_key_system_factory_service.cpp** as an example.

```
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

### Component Configuration

Create the **drivers/peripheral/clearplay/build.json** file to define the new drivers_peripheral_clearplay component.

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
### Component Compilation Entry Configuration

The following uses RK3568 as an example. The entry configuration file is **//productdefine/common/inherit/chipset_common.json**.

```
{
  "component": "drivers_peripheral_clearplay",
  "features": []
}
```

### Service Code Compilation

This process is similar to the compilation of system components.
`./build.sh --product-name rk3568 --ccache --build-target drivers_peripheral_clearplay`
The binary files generated after compilation are as follows:
//ohos/out/rk3568/hdf/drivers_peripheral_clearplay/libclearplay_driver.z.so
//ohos/out/rk3568/hdf/drivers_peripheral_clearplay/libmedia_key_system_factory_clearplay_service_1.0.z.so

## DRM Plugin Service Configuration

### hcs Configuration

The following uses RK3568 as an example. Add the driver service configuration to **vendor/hihope/rk3568/hdf_config/uhdf/device_info.hcs**.

```
clearplay :: host {
    hostName = "clearplay_host";   // Process name.
    priority = 50;
    uid = ""; // uid of the user-mode process. It is left empty by default. If you do not set the value, this parameter will be set to the value of hostName, which indicates a common user.
    gid = ""; // gid of the user-mode process. It is left empty by default. If you do not set the value, this parameter will be set to the value of hostName, which indicates a common user group.
    caps = ["DAC_OVERRIDE", "DAC_READ_SEARCH"]; // Linux capabilities of the user-mode process. It is left empty by default. Set this parameter based on service requirements.
    clearplay_device :: device {
        device0 :: deviceNode {
            policy = 2;
            priority = 100;
            moduleName = "libclearplay_driver.z.so";  // Driver loading entry.
            serviceName = "clearplay_service";        // Service name.
        }
    }
}
```

### Host User and Group Configuration

For the new host node in hcs, you must configure the uid and gid of the corresponding process.

The **passwd** file is a system user configuration file that stores basic information about all users in the system. The following is an example:

```
//base/startup/init/services/etc/passwd
clearplay_host:x:1089:1089::/bin/false
```

In **//base/startup/init/services/etc/passwd**, each line of user information is divided into 7 fields, separated by colons (:). The meaning of each field is as follows:

Username: Password: uid: gid: Description: Home directory: Default shell

The **group** file is the user group configuration file that stores information about all user groups. The following is an example:

```
base/startup/init/services/etc/group
clearplay_host:x:1089:
```

In **base/startup/init/services/etc/group**, each line indicates a user group. The user group is divided into four fields, separated by colons (:). The meaning of each field is as follows:

Group name: Password: gid: List of users in the user group

**NOTE**

- **clearplay_host** in **passwd** corresponds to **uid** in **device_info.hcs**. If **uid** in **device_info.hcs** is not specified, the default value **hostName** is used.
- **clearplay_host** in **group** corresponds to **gid** in **device_info.hcs**. If **gid** in **device_info.hcs** is not specified, the default value **hostName** is used.

### Dynamic Loading

To reduce RAM memory usage, the DRM framework supports dynamic loading of DRM plugins. After the DRM framework calls the plugin, it should promptly unload the plugin to release the occupied RAM memory. The plugin must modify its service startup properties to configure itself as a lazy loading service and add itself to the lazy loading list configuration file for the DRM framework on the device. The HDI service provides dynamic loading capabilities, which are not loaded by default during system startup but can be loaded dynamically. Here is an example:

Set **preload** to **2** in **device_info.hcs**.

```
clearplay :: host {
    hostName = "clearplay_host";
    priority = 50;
    clearplay_device :: device {
        device0 :: deviceNode {
            policy = 2;
            priority = 100;
            preload = 2; // If preload is set to 2, the system does not load the file during startup by default. You can manually load the file later.
            moduleName = "libclearplay_driver.z.so";
            serviceName = "clearplay_service";
        }
    }
}
```
The **/etc/drm/drm_plugin_lazyloding.cfg** file on the device is the lazy loading list configuration file of the DRM framework. The file is in the format of key-value pairs, where the solution name of the DRM plugin is the key and the service name of the DRM solution is the value.
```
{
    "plugin_services": {
        "lazy_load_service": [
            "com.clearplay.drm:clearplay_service"
        ]
    }
}
```

## Adding SELinux Permissions

SELinux is used to restrict resources that can be accessed by service processes. The following provides the basic SELinux configuration. Add required rules based on services.

In the following example, **clearplay_host** indicates the value of **hostName** in hcs, and **clearplay_service** indicates the service name.

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

//base/security/selinux_adapter/sepolicy/ohos_policy/drivers/peripheral/clearplay/vendor/clearplay_host.te (Create this directory.)
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
