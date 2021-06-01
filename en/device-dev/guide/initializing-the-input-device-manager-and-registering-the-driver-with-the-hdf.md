# Initializing the Input Device Manager and Registering the Driver with the HDF<a name="EN-US_TOPIC_0000001111841930"></a>

You can obtain the sample code at  **./drivers/framework/model/input/driver/hdf\_input\_device\_manager.c**.

```
static int32_t HdfInputManagerInit(struct HdfDeviceObject *device)
{ 
    /* Allocate memory to the device manager, which will store all input devices. */
    g_inputManager = InputManagerInstance();
    ...
}
struct HdfDriverEntry g_hdfInputEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_INPUT_MANAGER",
    .Bind = HdfInputManagerBind,
    .Init = HdfInputManagerInit,
    .Release = HdfInputManagerRelease,
};

HDF_INIT(g_hdfInputEntry);                                               // Driver registration entry
```

