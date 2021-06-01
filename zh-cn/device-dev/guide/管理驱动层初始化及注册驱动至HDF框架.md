# 管理驱动层初始化及注册驱动至HDF框架<a name="ZH-CN_TOPIC_0000001111841930"></a>

示例代码路径：./drivers/framework/model/input/driver/hdf\_input\_device\_manager.c

```
static int32_t HdfInputManagerInit(struct HdfDeviceObject *device)
{ 
    /* 分配内存给manager，manager中将存放所有input设备 */
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

HDF_INIT(g_hdfInputEntry);                                               //驱动注册入口
```

