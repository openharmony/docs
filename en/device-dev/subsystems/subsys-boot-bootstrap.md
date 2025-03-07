# bootstrap Module


This module implements automatic service initialization. That is, the initialization function does not need to be explicitly called. Instead, it is declared using the macro definition and is automatically executed when the system is started. Specifically, after the function for starting a service is declared through macro definition, it is placed in the predefined **zInit** code segment. During system startup, the **OHOS_SystemInit** API is called to traverse the code segment and call the functions in the code segment. Therefore, you need to include the **zInit** code segment in the linker script and call the **OHOS_SystemInit** API in the **main** function.


For details about how to include the **zInit** code segment, see the Hi3861 linker script in **vendor/hisi/hi3861/hi3861/build/link/link.ld.S**.


For details about the macros used by the bootstrap module to implement automatic service initialization, see [API Reference](https://device.harmonyos.com/cn/docs/develop/apiref/init-0000001054598113) of the Startup subsystem.


## Available APIs

The following table lists the automatic initialization macros of main services.

  Table 1 Major macros for the bootstrap module

| Name| Description| 
| -------- | -------- |
| SYS_SERVICE_INIT(func) | Entry for initializing and starting a core system service.| 
| SYS_FEATURE_INIT(func) | Entry for initializing and starting a core system feature.| 
| APP_SERVICE_INIT(func) | Entry for initializing and starting an application-layer service.| 
| APP_FEATURE_INIT(func) | Entry for initializing and starting an application-layer feature.| 


## Development Example

  The following is an example of using macros to automatically initialize services.
  
```
void SystemServiceInit(void) {
    printf("Init System Service\n");
}
SYS_SERVICE_INIT(SystemServiceInit);

void SystemFeatureInit(void) {
    printf("Init System Feature\n");
}
SYS_FEATURE_INIT(SystemFeatureInit);

void AppServiceInit(void) {
    printf("Init App Service\n");
}
APP_SERVICE_INIT(AppServiceInit);

void AppFeatureInit(void) {
    printf("Init App Feature\n");
}
APP_FEATURE_INIT(AppFeatureInit);

// Logs are printed in the following sequence:
// Init System Service
// Init System Feature
// Init App Service
// Init App Feature
```
