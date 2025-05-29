# 移植文件子系统


utils部件可被各业务子系统及上层应用使用，依赖芯片文件系统实现，需要芯片平台提供文件打开、关闭、读写、获取大小等功能。


## 移植指导

OpenHarmony文件系统需要适配如下HAL层接口：

  **表1** 文件打开或关闭

| **接口名** | **描述** | 
| -------- | -------- |
| HalFileOpen | 文件打开或创建新文件。 | 
| HalFileClose | 文件关闭。 | 

  **表2** 文件操作

| **接口名** | **描述** | 
| -------- | -------- |
| HalFileRead | 读文件。 | 
| HalFileWrite | 写文件。 | 
| HalFileDelete | 删除文件。 | 
| HalFileStat | 获取文件属性。 | 
| HalFileSeek | 文件查找。 | 

  厂商适配相关接口的实现，请参考OpenHarmony中file的接口和hal层适配接口的定义：
  
```
//utils/native/lite/file
├── BUILD.gn
└── src
     └── file_impl_hal
            └── file.c             #file接口。
```

  
```
//utils/native/lite/hals
└── file
└── hal_file.h                   #hal层接口头文件。
```

其中BUILD.gn的内容如下：

  
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
  deps = ["$ohos_vendor_adapter_dir/hals/utils/file:hal_file_static"]  #依赖厂商的适配。
}
 
lite_component("file") {
  features = [
    ":native_file",
  ]
}
```

从中可以看到厂商适配相关接口的存放目录应为“$ohos_vendor_adapter_dir/hals/utils/file”，且该目录下BUILD.gn文件中的目标应为hal_file_static。

通常厂商可以采用下面三种方式适配hal层接口：

1. 直接flash读写，模拟文件的操作。

2. 使用littlefs或者fatfs文件系统进行适配，littlefs或者fatfs都是轻量级文件系统适配简单，其中OpenHarmony的“//thirdparty”目录下已有fatfs可供参考。

3. 使用厂商已有的文件系统进行适配。


## 移植实例

1. “config.json”添加文件系统。
   路径：“vendor/MyVendorCompany/MyProduct/config.json”

     修改如下：
     
   ```
   {
   "subsystem": "utils",
   "components": [
       { "component": "file", "features":[] }
     ]
   },
   ```

2. 添加适配文件。
   在“vendor/MyVendorCompany/MyProduct/config.json”文件中，vendor_adapter_dir配置项通常进行如下配置：

   "vendor_adapter_dir": "//device/MyDeviceCompany/MyBoard/adapter"。

   在该目录下进行UtilsFile接口适配：

     
   ```
   hals/utils/file
   ├── BUILD.gn
   └── src
       └── hal_file.c
   ```

     其中BUILD.gn内容如下：
     
   ```
   import("//build/lite/config/component/lite_component.gni")
   static_library("hal_file_static") {     #目标名。
     sources = [ "src/hal_file.c" ]        #厂商适配的源文件。
     include_dirs = [
       "//utils/native/lite/hals/file",
     ]
   }
   ```
