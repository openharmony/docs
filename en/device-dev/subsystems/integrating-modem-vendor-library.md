# Integrating Modem Vendor Library<a name="EN-US_TOPIC_0000001148928023"></a>

-   [Compilation Information Configuration](#section142111565210)
-   [\(Optional\) Commissioning and Verification](#section114621643195220)

## Compilation Information Configuration<a name="section142111565210"></a>

The modem vendor library can be compiled into a dynamic library by using  **BUILD.gn**. When the RIL Adapter is started, the dynamic library is loaded to the system in dlopen mode, and then the modem vendor library is initialized \(for details, see  [Initializing a Modem Vendor Library](initializing-a-modem-vendor-library.md)\). The following is a compilation example of  **BUILD.gn**:

```
import("//build/ohos.gni")
RIL_ADAPTER = "//base/telephony"

ohos_shared_library("vendor") {// Name of the modem vendor library
sources = [// Source files to be compiled
  "vendorlib.c",
  "xxx.c",
]
include_dirs = [// Header files
  "$RIL_ADAPTER/ril_adapter/include",
  "$RIL_ADAPTER/ril_adapter/interfaces/innerkits",
  "include",
]
deps = [// Internal dependencies
  "//drivers/adapter/uhdf2/osal:libhdf_utils"
]
external_deps = [// External dependencies
  "hilog:libhilog"
]
part_name = "ril_adapter"
subsystem_name = "telephony"
```

## \(Optional\) Commissioning and Verification<a name="section114621643195220"></a>

After the compilation is complete, check whether the  **libvendor.z.so**  file is generated in the  **out/ohos-arm-release/packages/phone/system/lib**  directory. If this file is generated, the library integration is successful.

