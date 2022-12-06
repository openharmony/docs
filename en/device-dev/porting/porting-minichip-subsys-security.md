# Porting the Security Subsystem


The security subsystem provides functions such as network device connection, authentication, and authorization. It depends on mbedtls to implement hardware random numbers and network connection functions.


Because the chip hardware and the implementation for the hardware-based random number varies by vendor, the hardware-based random number interface needs to be adapted.


## Procedure

OpenHarmony provides an open-source library of Mbed TLS, which is stored in **//third_party/mbedtls**. This library provides several random number generation modes, such as **mbedtls_platform_entropy_poll**, **mbedtls_hardclock_poll**, **mbedtls_havege_poll**, and **mbedtls_hardware_poll**. For the hardware-based random number, adapt **mbedtls_hardware_poll** based on your chip.


## Example

1. Add a file system to the **config.json** file.

   Path: **vendor/MyVendorCompany/MyProduct/config.json**

     The sample code is as follows:
     
   ```
   {
     "subsystem": "security",
     "components": [
       { "component": "hichainsdk", "features":[] },
       { "component": "huks", "features":[]}
     ]
   },
   ```

2. Configure the macro to enable the code related to the hardware-based random number interface.

   According to the Mbed TLS compilation file, the macro is configured in the **MBEDTLS_CONFIG_FILE=\<../port/config/config_liteos_m.h>** file.

   Path: **third_party/mbedtls/BUILD.gn**

     
   ```
   if (ohos_kernel_type == "liteos_m") {
     defines += [
       "__unix__",
       "MBEDTLS_CONFIG_FILE=<../port/config/config_liteos_m.h>",
     ]
   }
   ```

   According to the code, configure the **MBEDTLS_NO_PLATFORM_ENTROPY** and **MBEDTLS_ENTROPY_HARDWARE_ALT** macros to build the related code.

   Path: **third_party/mbedtls/library/entropy.c**

     
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

3. Adapt the hardware-based random number interface.

   The API definition is as follows.

   Path: **third_party/mbedtls/include/mbedtls/entropy_poll.h**

     
   ```
   int mbedtls_hardware_poll( void *data,unsigned char *output, size_t len, size_t *olen );
   ```


  **Table 1** Configuration items of the security subsystem

| Configuration Item| Description| 
| -------- | -------- |
| disable_huks_binary | Whether to compile the HUKS source code.<br>(1) **false** (default): The HUKS source code is not compiled.<br>(2) **true**: The HUKS source code is not compiled.| 
| disable_authenticate | Whether tailoring is required for the HiChain authentication function.<br>(1) **true** (default): Tailoring is not required.<br>(2) **false**: Tailoring is required.| 
| huks_use_lite_storage | Whether the lightweight storage solution is used. The lightweight storage solution can be used for devices that come with flash storage and do not have file systems.<br>(1) **true** (default): The lightweight storage solution is used.<br>(2) **false**: The lightweight storage solution is not used.| 
| huks_use_hardware_root_key | Whether the hardware root key is used. If a device has the hardware root key capability, the hardware root key solution needs to be adapted based on the device capability. The RKC solution provided by HUKS is only for simulation implementation.<br>(1) **false** (default): The hardware root key is not used.<br>(2) **true**: The hardware root key is used. This requires adaptation.| 
| huks_config_file | Whether to use the default HUKS configuration file **hks_config.h**.<br>(1) **""**(default): The default HUKS configuration file is used.<br>(2) Other files: You can select the features to be supported from the HUKS support capability set.| 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> 
> When adding a security subsystem, you can directly select the features of the security subsystem by configuring features.
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
