# 公共驱动层初始化及注册驱动至HDF框架<a name="ZH-CN_TOPIC_0000001158361885"></a>

示例代码路径：./drivers/framework/model/input/driver/hdf\_touch.c

```
static int32_t HdfTouchDriverProbe(struct HdfDeviceObject *device)
{
    ...
    /* 板级信息结构体内存申请及hcs配置信息解析 */
    boardCfg = BoardConfigInstance(device);
    ...
    /* 公共驱动结构体内存申请 */
    touchDriver = TouchDriverInstance();
    ...
    /* 依据解析出的板级信息进行公共资源初始化，如IIC初始化 */
    ret = TouchDriverInit(touchDriver, boardCfg);
    if (ret == HDF_SUCCESS) {
        ...
        /* 添加驱动至公共驱动层驱动管理链表，当设备与驱动进行绑定时使用该链表进行查询 */
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
                               
HDF_INIT(g_hdfTouchEntry);                                              //驱动注册入口
```

