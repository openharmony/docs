# Initializing the Input Common Driver and Registering the Driver with the HDF<a name="EN-US_TOPIC_0000001158361885"></a>

You can obtain the sample code at  **./drivers/framework/model/input/driver/hdf\_touch.c**.

```
static int32_t HdfTouchDriverProbe(struct HdfDeviceObject *device)
{
    ...
    /* Use the boardCfg structure to allocate memory and parse the configuration information obtained from the HCS. */
    boardCfg = BoardConfigInstance(device);
    ...
    /* Allocate memory in the touchDriver structure. */
    touchDriver = TouchDriverInstance();
    ...
    /* Initialize common resources based on the parsed board-level information, such as IIC initialization. */
    ret = TouchDriverInit(touchDriver, boardCfg);
    if (ret == HDF_SUCCESS) {
        ...
        /* Add the driver to the common driver management linked list, which is used to query the driver after it is bound to the device. */
        AddTouchDriver(touchDriver);
        ...
    }
    ...
}
struct HdfDriverEntry g_hdfTouchEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_TOUCH",
    .Bind = HdfTouchDriverBind,
    .Init = HdfTouchDriverProbe,
    .Release = HdfTouchDriverRelease,
};
                               
 HDF_INIT(g_hdfTouchEntry);                                              // Driver registration entry
```

