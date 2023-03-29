# Porting the File Subsystem


The utils component can be used by service subsystems and upper-layer applications and depends on the chip file system. The chip platform needs to provide functions such as opening, closing, reading, writing, and obtaining the file size.


## Procedure

The OpenHarmony file system needs to adapt to the following HAL APIs:

  **Table 1** Opening or closing a file

| API| Description| 
| -------- | -------- |
| HalFileOpen | Opens or creates a file.| 
| HalFileClose | Closes a file:| 

  **Table 2** File operations

| API| Description| 
| -------- | -------- |
| HalFileRead | Reads a file.| 
| HalFileWrite | Writes data to a file.| 
| HalFileDelete | Deletes a file.| 
| HalFileStat | Obtains file attributes.| 
| HalFileSeek | Searches for files.| 

  For details about the implementation of vendor adaptation interfaces, see the definitions of the file interface and HAL adaptation interface in OpenHarmony.
  
```
//utils/native/lite/file
├── BUILD.gn
└── src
     └── file_impl_hal
            └── file.c             # file interface
```

  
```
//utils/native/lite/hals
└── file
└── hal_file.h                   # HAL interface header file
```

The content of **BUILD.gn** is as follows:

  
```
import("//build/lite/config/component/lite_component.gni")
 
static_library("native_file") {
  sources = [
    "src/file_impl_hal/file.c",
  ]
  include_dirs = [
    "//utils/native/lite/include",
    "//utils/native/lite/hals/file",
  ]
  deps = ["$ohos_vendor_adapter_dir/hals/utils/file:hal_file_static"] # Vendor dependent adaptation.
}
 
lite_component("file") {
  features = [
    ":native_file",
  ]
}
```

As shown in the preceding example, the directory for storing vendor adaptation interfaces is **$ohos_vendor_adapter_dir/hals/utils/file**, where the target in the **BUILD.gn** file is **hal_file_static**.

Generally, vendors can use the following methods to adapt to HAL APIs:

1. Directly read and write the flash memory to simulate file operations.

2. Use the LittleFS or FatFs file system for adaptation. For the FatFs file system, you can refer to the **//thirdparty** directory of OpenHarmony.

3. Use the existing file system of the vendor for adaptation.


## Example

1. Add a file system to **config.json**.

   Path: **vendor/MyVendorCompany/MyProduct/config.json**

     The sample code is as follows:
     
   ```
   {
   "subsystem": "utils",
   "components": [
       { "component": "file", "features":[] }
     ]
   },
   ```

2. Add an adaptation file.
   In the **vendor/MyVendorCompany/MyProduct/config.json** file, set **vendor_adapter_dir** as follows:

   "vendor_adapter_dir": "//device/MyDeviceCompany/MyBoard/adapter".

   Perform **UtilsFile** interface adaptation in this directory.

     
   ```
   hals/utils/file
   ├── BUILD.gn
   └── src
       └── hal_file.c
   ```

     The content of **BUILD.gn** is as follows:
     
   ```
   import("//build/lite/config/component/lite_component.gni")
   static_library("hal_file_static") { # target name
     sources = [ "src/hal_file.c" ]        # Source file adapted by the vendor
     include_dirs = [
       "//utils/native/lite/hals/file",
     ]
   }
   ```
