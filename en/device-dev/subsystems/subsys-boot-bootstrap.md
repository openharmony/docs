# bootstrap Module<a name="EN-US_TOPIC_0000001063402356"></a>

This module implements automatic service initialization. That is, the initialization function does not need to be explicitly called. Instead, it is declared using the macro definition and is automatically executed when the system is started. Specifically, after the function for starting a service is declared using a macro, it is placed in the predefined  **zInit**  code segment. During system startup, the  **OHOS\_SystemInit**  API is called to traverse the code segment and call the functions in the code segment. Therefore, you need to include the  **zInit**  code segment in the linker script and call the  **OHOS\_SystemInit**  API in the  **main**  function.

For details about how to include the  **zInit**  code segment, see the Hi3861 linker script in  **vendor/hisi/hi3861/hi3861/build/link/link.ld.S**.

For details about the macros used by the bootstrap module to implement automatic service initialization, see  [API document](https://device.harmonyos.com/en/docs/develop/apiref/init-0000001054598113)  the Startup subsystem.

## Available APIs<a name="section1633115419401"></a>

The following table describes the major macros used by the bootstrap module to implement automatic service initialization.

**Table  1**  Major macros for the bootstrap module

<a name="table12281332101910"></a>
<table><thead align="left"><tr id="row102914328199"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p229113221917"><a name="p229113221917"></a><a name="p229113221917"></a>Macro Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p429132161912"><a name="p429132161912"></a><a name="p429132161912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13291532141919"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14292032181919"><a name="p14292032181919"></a><a name="p14292032181919"></a>SYS_SERVICE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10291732181911"><a name="p10291732181911"></a><a name="p10291732181911"></a>Entry for initializing and starting a core system service</p>
</td>
</tr>
<tr id="row1329133214197"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p15291332161915"><a name="p15291332161915"></a><a name="p15291332161915"></a>SYS_FEATURE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p12292324198"><a name="p12292324198"></a><a name="p12292324198"></a>Entry for initializing and starting a core system feature</p>
</td>
</tr>
<tr id="row1529133231911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9291332131915"><a name="p9291332131915"></a><a name="p9291332131915"></a>APP_SERVICE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1229432181920"><a name="p1229432181920"></a><a name="p1229432181920"></a>Entry for initializing and starting an application-layer service</p>
</td>
</tr>
<tr id="row1229173214194"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12923218193"><a name="p12923218193"></a><a name="p12923218193"></a>APP_FEATURE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17291332121913"><a name="p17291332121913"></a><a name="p17291332121913"></a>Entry for initializing and starting an application-layer feature</p>
</td>
</tr>
</tbody>
</table>

## How to Use<a name="section2055311316228"></a>

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

