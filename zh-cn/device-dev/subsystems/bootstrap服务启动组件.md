# bootstrap服务启动组件<a name="ZH-CN_TOPIC_0000001063402356"></a>

-   [接口说明](#section1633115419401)
-   [开发实例](#section2055311316228)

bootstrap服务启动组件实现了服务的自动初始化，即服务的初始化函数无需显式调用，而是将其使用宏定义的方式申明，就会在系统启动时自动被执行。实现原理是将服务启动的函数通过宏申明之后，放在预定义好的zInit代码段中，系统启动的时候调用OHOS\_SystemInit接口，遍历该代码段并调用其中的函数。因此，需要在链接脚本中添加zInit段，并且在main函数里调用OHOS\_SystemInit接口。

zInit段的添加可参考已有的Hi3861平台的链接脚本，文件路径为vendor/hisi/hi3861/hi3861/build/link/link.ld.S。

用于实现服务的自动初始化的宏定义接口请参见启动恢复子系统的[API接口文档](https://gitee.com/openharmony/docs/blob/master/api/api-SmartVision-Devices/OHOS-Init.md)。

## 接口说明<a name="section1633115419401"></a>

bootstrap服务启动：

**表 1**  主要的服务自动初始化宏

<a name="table12281332101910"></a>
<table><thead align="left"><tr id="row102914328199"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p229113221917"><a name="p229113221917"></a><a name="p229113221917"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p429132161912"><a name="p429132161912"></a><a name="p429132161912"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row13291532141919"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14292032181919"><a name="p14292032181919"></a><a name="p14292032181919"></a>SYS_SERVICE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10291732181911"><a name="p10291732181911"></a><a name="p10291732181911"></a>标识核心系统服务的初始化启动入口。</p>
</td>
</tr>
<tr id="row1329133214197"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p15291332161915"><a name="p15291332161915"></a><a name="p15291332161915"></a>SYS_FEATURE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p12292324198"><a name="p12292324198"></a><a name="p12292324198"></a>标识核心系统功能的初始化启动入口。</p>
</td>
</tr>
<tr id="row1529133231911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9291332131915"><a name="p9291332131915"></a><a name="p9291332131915"></a>APP_SERVICE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1229432181920"><a name="p1229432181920"></a><a name="p1229432181920"></a>标识应用层服务的初始化启动入口。</p>
</td>
</tr>
<tr id="row1229173214194"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12923218193"><a name="p12923218193"></a><a name="p12923218193"></a>APP_FEATURE_INIT(func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17291332121913"><a name="p17291332121913"></a><a name="p17291332121913"></a>标识应用层功能的初始化启动入口。</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section2055311316228"></a>

服务自动初始化宏使用实例：

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

// 日志的打印顺序为：
// Init System Service
// Init System Feature
// Init App Service
// Init App Feature
```

