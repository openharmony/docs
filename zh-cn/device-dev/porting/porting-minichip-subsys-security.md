# 移植安全子系统


安全子系统提供网络设备连接、认证鉴权等功能，依赖mbedtls实现硬件随机数以及联网功能。


由于每个厂商芯片硬件与实现硬件随机数的方式不同，需要适配硬件随机数接口。


## 移植指导

OpenHarmony提供了mbedtls的开源三方库，路径为“//third_party/mbedtls”。此库中提供了“mbedtls_platform_entropy_poll”、“mbedtls_hardclock_poll”、“mbedtls_havege_poll”、“mbedtls_hardware_poll”等几种产生随机数的方式。厂商需要根据芯片适配“mbedtls_hardware_poll”方式。


## 移植实例

1. “config.json”添加文件系统。
   路径：“vendor/MyVendorCompany/MyProduct/config.json”

     修改如下：
     
   ```
   {
     "subsystem": "security",
     "components": [
       { "component": "hichainsdk", "features":[] },
       { "component": "huks", "features":[]}
     ]
   },
   ```

2. 配置宏，打开硬件随机数接口相关代码。
   根据mbedtls的编译文件可以看出，配置宏的位置在"MBEDTLS_CONFIG_FILE=&lt;../port/config/config_liteos_m.h&gt;"文件中。

   路径：“third_party/mbedtls/BUILD.gn”

     
   ```
   if (ohos_kernel_type == "liteos_m") {
     defines += [
       "__unix__",
       "MBEDTLS_CONFIG_FILE=<../port/config/config_liteos_m.h>",
     ]
   }
   ```

   根据代码我们可以看出需要配置“MBEDTLS_NO_PLATFORM_ENTROPY”、“MBEDTLS_ENTROPY_HARDWARE_ALT”两个宏，才能编译硬件随机数的相关代码。

   路径：“third_party/mbedtls/library/entropy.c”

     
   ```
   #if !defined(MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES)
   #if !defined(MBEDTLS_NO_PLATFORM_ENTROPY)
       mbedtls_entropy_add_source( ctx, mbedtls_platform_entropy_poll, NULL,
                                   MBEDTLS_ENTROPY_MIN_PLATFORM,
                                   MBEDTLS_ENTROPY_SOURCE_STRONG );
   #endif
   ......
   #if defined(MBEDTLS_ENTROPY_HARDWARE_ALT)
       mbedtls_entropy_add_source( ctx, mbedtls_hardware_poll, NULL,
                                   MBEDTLS_ENTROPY_MIN_HARDWARE,
                                   MBEDTLS_ENTROPY_SOURCE_STRONG );
   #endif
   ......
   #endif /* MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES */
   }
   ```

3. 适配硬件随机数接口。
   接口定义如下：

   路径：“third_party/mbedtls/include/mbedtls/entropy_poll.h”

     
   ```
   int mbedtls_hardware_poll( void *data,unsigned char *output, size_t len, size_t *olen );
   ```


  **表1** 安全子系统配置项

| 配置项 | 意义 | 
| -------- | -------- |
| disable_huks_binary | 是否编译HUKS源码。<br/>(1)&nbsp;默认值：&nbsp;false，不编译HUKS源码。<br/>(2)&nbsp;其他值：&nbsp;true，编译HUKS源码。 | 
| disable_authenticate | 是否需要裁剪hichain认证功能。<br/>(1)&nbsp;默认值：&nbsp;true，不裁剪。<br/>(2)&nbsp;其他值：&nbsp;false，裁剪hichain认证功能。 | 
| huks_use_lite_storage | 是否采用轻量化存储方案。无文件系统、仅有flash存储的设备，可采用轻量化存储方案。<br/>(1)&nbsp;默认值：&nbsp;true，使用轻量化存储。<br/>(2)&nbsp;其他值：&nbsp;false，不使用轻量化存储。 | 
| huks_use_hardware_root_key | 是否使用硬件根密钥。设备存在硬件根密钥能力时，需要根据自身能力适配硬件根密钥方案；HUKS提供的RKC方案仅为模拟实现。<br/>(1)&nbsp;默认值：false，默认值，默认无硬件根密钥。<br/>(2)&nbsp;其他值：true，设备具有硬件根密钥相关能力时，应自行适配。 | 
| huks_config_file | 是否使用HUKS默认配置文件。<br/>(1)&nbsp;默认值：""：使用HUKS默认配置文件hks_config.h。<br/>(2)&nbsp;其他文件：产品可在HUKS支持能力集合中自行选择所要支持的特性。 | 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 在添加安全子系统时，可直接通过配置feature来选择安全子系统特性。
> 
>   
> ```
> {
>   "subsystem": "security",
>   "components": [
>     { "component": "hichainsdk", "features":[] },
>     { "component": "huks", "features":
>       [
>         "disable_huks_binary = false",
>         "disable_authenticate = false"
>       ]
>     }
>   ]
> },
> ```
