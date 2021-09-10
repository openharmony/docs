# 标准系统移植指南<a name="ZH-CN_TOPIC_0000001180064129"></a>

-   [定义开发板](#section132mcpsimp)
    -   [定义SOC](#section135mcpsimp)
    -   [定义产品](#section145mcpsimp)
    -   [移植验证](#section163mcpsimp)

-   [内核移植](#section171mcpsimp)
    -   [1.为SOC添加内核构建的子系统](#section174mcpsimp)
    -   [2. 编译内核](#section182mcpsimp)
    -   [3. 移植验证](#section207mcpsimp)

-   [HDF驱动移植](#section210mcpsimp)
    -   [1. LCD](#section212mcpsimp)
    -   [2. 触摸屏](#section229mcpsimp)
    -   [3. WLAN](#section274mcpsimp)
    -   [4. 开发移植示例](#section11253153018415)


本文描述了移植一块开发板的通用步骤，和具体芯片相关的详细移植过程无法在此一一列举。后续社区还会陆续发布开发板移植的实例供开发者参考。

## 定义开发板<a name="section132mcpsimp"></a>

本文以移植名为MyProduct的开发板为例讲解移植过程，假定MyProduct是MyProductVendor公司的开发板，使用MySoCVendor公司生产的MySOC芯片作为处理器。

### 定义SOC<a name="section135mcpsimp"></a>

在“//productdefine/common/device”目录下创建以SOC名字命名的json文件，并指定CPU的架构。

如要移植一个叫MySOC的SOC，这个SOC采用32位ARM内核。配置如下：

//productdefine/common/device/MySOC.json

```
{
    "target_os": "ohos",
    "target_cpu": "arm"
}
```

根据实际情况，这里的target\_cpu也可能是arm64 、riscv、 x86等。当前仅支持arm作为target\_cpu。

### 定义产品<a name="section145mcpsimp"></a>

在“//productdefine/common/products”目录下创建以产品名命名的json文件。该文件用于描述产品所使用的SOC 以及所需的子系统。配置如下

//productdefine/common/products/MyProduct.json

```
{
  "product_name": "MyProduct",
  "product_company" : "MyProductVendor",
  "product_device": "MySOC",
  "version": "2.0",
  "type": "standard",
  "parts":{
    "ace:ace_engine_standard":{},
    "ace:napi":{},
    ...
    "xts:phone_tests":{}
  }
}

```

主要的配置内容包括：

1.  product\_device：配置所使用的SOC
2.  type：配置系统的级别， 这里直接standard即可
3.  parts：系统需要启用的子系统。子系统可以简单理解位一块独立构建的功能块。

已定义的子系统可以在“//build/subsystem\_config.json”中找到。当然你也可以定制子系统。

这里建议先拷贝Hi3516DV300 开发板的配置文件，删除掉 hisilicon\_products 这个子系统。这个子系统为Hi3516DV300 SOC编译内核，显然不适合MySOC。

### 移植验证<a name="section163mcpsimp"></a>

至此，你可以使用如下命令，启动你产品的构建了：

```
./build.sh --product-name MyProduct 
```

构建完成后，可以在“//out/ohos-arm-release/packages/phone/images”目录下看到构建出来的OpenHarmony镜像文件。

## 内核移植<a name="section171mcpsimp"></a>

这一步需要移植Linux内核，让Linux内核可以成功运行起来。

### 1.为SOC添加内核构建的子系统<a name="section174mcpsimp"></a>

修改文件 //build/subsystem\_config.json增加一个子系统. 配置如下：

```
  "MySOCVendor_products": {
    "project": "hmf/MySOCVendor_products",
    "path": "device/MySOCVendor/MySOC/build",
    "name": "MySOCVendor_products",
    "dir": "device/MySOCVendor"
  },
```

接着需要修改定义产品的配置文件//productdefine/common/products/MyProduct.json，将刚刚定义的子系统加入到产品中。

### 2. 编译内核<a name="section182mcpsimp"></a>

OpenHarmony源码中提供了Linux 4.19的内核，归档在//kernel/linux-4.19。本节以该内核版本为例，讲解如何编译内核。

在子系统的定义中，描述了子系统构建的路径path，即\`//device/MySOCVendor/MySOC/build\`。这一节会在这个目录创建构建脚本，告诉构建系统如何构建内核。

建议的目录结构

```
├── build
│ ├── kernel
│ │     ├── linux
│ │           ├──standard_patch_for_4_19.patch // 基于4.19版本内核的补丁
│ ├── BUILD.gn
│ ├── ohos.build
```

BUILD.gn是subsystem构建的唯一入口。

期望的构建结果

<a name="table193mcpsimp"></a>
<table><tbody><tr id="row198mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry199mcpsimpp0"><a name="entry199mcpsimpp0"></a><a name="entry199mcpsimpp0"></a>文件</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry200mcpsimpp0"><a name="entry200mcpsimpp0"></a><a name="entry200mcpsimpp0"></a>文件说明</p>
</td>
</tr>
<tr id="row201mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry202mcpsimpp0"><a name="entry202mcpsimpp0"></a><a name="entry202mcpsimpp0"></a>$root_build_dir/packages/phone/images/uImage</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry203mcpsimpp0"><a name="entry203mcpsimpp0"></a><a name="entry203mcpsimpp0"></a>内核镜像</p>
</td>
</tr>
<tr id="row204mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry205mcpsimpp0"><a name="entry205mcpsimpp0"></a><a name="entry205mcpsimpp0"></a>$root_build_dir/packages/phone/images/uboot</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry206mcpsimpp0"><a name="entry206mcpsimpp0"></a><a name="entry206mcpsimpp0"></a>bootloader镜像</p>
</td>
</tr>
</tbody>
</table>

### 3. 移植验证<a name="section207mcpsimp"></a>

启动编译，验证预期的kernel镜像是否成功生成。

## HDF驱动移植<a name="section210mcpsimp"></a>

### 1. LCD<a name="section212mcpsimp"></a>

HDF为LCD设计了驱动模型。支持一块新的LCD，需要编写一个驱动，在驱动中生成模型的实例，并完成注册。

这些LCD的驱动被放置在//drivers/framework/model/display/driver/panel目录中。

-   创建Panel驱动

在驱动的Init方法中，需要调用RegisterPanel接口注册模型实例。如:

```
int32_t XXXInit(struct HdfDeviceObject *object)
{
    struct PanelData *panel = CreateYourPanel();

    // 注册
    if (RegisterPanel(panel) != HDF_SUCCESS) {
        HDF_LOGE("%s: RegisterPanel failed", __func__);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

struct HdfDriverEntry g_xxxxDevEntry = {
    .moduleVersion = 1,
    .moduleName = "LCD_XXXX",
    .Init = XXXInit,
};

HDF_INIT(g_xxxxDevEntry);
```

-   配置加载panel驱动产品的所有设备信息被定义在文件//vendor/MyProductVendor/MyProduct/config/device\_info/device\_info.hcs中。修改该文件，在display的host中，名为device\_lcd的device中增加配置。注意：moduleName 要与panel驱动中的moduleName相同。

```
root {
    ...
    display :: host {
        device_lcd :: device {
                deviceN :: deviceNode {
                    policy = 0;
                    priority = 100;
                    preload = 2;
                    moduleName = "LCD_XXXX";
                }
        }
    }
}
```

更详细的驱动开发指导，请参考  [LCD](../driver/driver-peripherals-lcd-des.md)。

### 2. 触摸屏<a name="section229mcpsimp"></a>

本节描述如何移植触摸屏驱动。触摸屏的驱动被放置在//drivers/framework/model/input/driver/touchscreen目录中。移植触摸屏驱动主要工作是向系统注册ChipDevice模型实例。

-   创建触摸屏器件驱动

在目录中创建名为touch\_ic\_name.c的文件。代码模板如下：注意：请替换ic\_name为你所适配芯片的名称。

```
#include "hdf_touch.h"

static int32_t HdfXXXXChipInit(struct HdfDeviceObject *device)
{
    ChipDevice *tpImpl = CreateXXXXTpImpl();
    if(RegisterChipDevice(tpImpl) != HDF_SUCCESS) {
        ReleaseXXXXTpImpl(tpImpl);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

struct HdfDriverEntry g_touchXXXXChipEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_TOUCH_XXXX",
    .Init = HdfXXXXChipInit,
};

HDF_INIT(g_touchXXXXChipEntry);
```

其中ChipDevice中要提供若干方法。

<a name="table240mcpsimp"></a>
<table><tbody><tr id="row245mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry246mcpsimpp0"><a name="entry246mcpsimpp0"></a><a name="entry246mcpsimpp0"></a>方法</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry247mcpsimpp0"><a name="entry247mcpsimpp0"></a><a name="entry247mcpsimpp0"></a>实现说明</p>
</td>
</tr>
<tr id="row248mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry249mcpsimpp0"><a name="entry249mcpsimpp0"></a><a name="entry249mcpsimpp0"></a>int32_t (*Init)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry250mcpsimpp0"><a name="entry250mcpsimpp0"></a><a name="entry250mcpsimpp0"></a>器件初始化</p>
</td>
</tr>
<tr id="row251mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry252mcpsimpp0"><a name="entry252mcpsimpp0"></a><a name="entry252mcpsimpp0"></a>int32_t (*Detect)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry253mcpsimpp0"><a name="entry253mcpsimpp0"></a><a name="entry253mcpsimpp0"></a>器件探测</p>
</td>
</tr>
<tr id="row254mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry255mcpsimpp0"><a name="entry255mcpsimpp0"></a><a name="entry255mcpsimpp0"></a>int32_t (*Suspend)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry256mcpsimpp0"><a name="entry256mcpsimpp0"></a><a name="entry256mcpsimpp0"></a>器件休眠</p>
</td>
</tr>
<tr id="row257mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry258mcpsimpp0"><a name="entry258mcpsimpp0"></a><a name="entry258mcpsimpp0"></a>int32_t (*Resume)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry259mcpsimpp0"><a name="entry259mcpsimpp0"></a><a name="entry259mcpsimpp0"></a>器件唤醒</p>
</td>
</tr>
<tr id="row260mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry261mcpsimpp0"><a name="entry261mcpsimpp0"></a><a name="entry261mcpsimpp0"></a>int32_t (*DataHandle)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry262mcpsimpp0"><a name="entry262mcpsimpp0"></a><a name="entry262mcpsimpp0"></a>从器件读取数据，将触摸点数据填写入device-&gt;driver-&gt;frameData中</p>
</td>
</tr>
<tr id="row263mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry264mcpsimpp0"><a name="entry264mcpsimpp0"></a><a name="entry264mcpsimpp0"></a>int32_t (*UpdateFirmware)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry265mcpsimpp0"><a name="entry265mcpsimpp0"></a><a name="entry265mcpsimpp0"></a>固件升级</p>
</td>
</tr>
</tbody>
</table>

-   配置产品，加载器件驱动

    产品的所有设备信息被定义在文件//vendor/MyProductVendor/MyProduct/config/device\_info/device\_info.hcs中。修改该文件，在名为input的host中，名为device\_touch\_chip的device中增加配置。注意：moduleName 要与触摸屏驱动中的moduleName相同。


```
                deviceN :: deviceNode {
                    policy = 0;
                    priority = 130;
                    preload = 0;
                    permission = 0660;
                    moduleName = "HDF_TOUCH_XXXX";
                    deviceMatchAttr = "touch_XXXX_configs";
                }
```

更详细的驱动开发指导，请参考  [TOUCHSCREEN](../driver/driver-peripherals-touch-des.md)。

### 3. WLAN<a name="section274mcpsimp"></a>

Wi-Fi驱动分为两部分，一部分负责管理WLAN设备，另一个部分负责处理WLAN流量。HDF WLAN分别为这两部分做了抽象。目前支持SDIO接口的WLAN芯片。

**图 1**  WLAN芯片<a name="fig16997123013494"></a>  
![](figure/WLAN芯片.png "WLAN芯片")

支持一款芯片的主要工作是实现一个ChipDriver驱动。实现HDF\_WLAN\_CORE和NetDevice提供的接口。主要需要实现的接口有:

<a name="table280mcpsimp"></a>
<table><tbody><tr id="row286mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry287mcpsimpp0"><a name="entry287mcpsimpp0"></a><a name="entry287mcpsimpp0"></a>接口</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry288mcpsimpp0"><a name="entry288mcpsimpp0"></a><a name="entry288mcpsimpp0"></a>定义头文件</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry289mcpsimpp0"><a name="entry289mcpsimpp0"></a><a name="entry289mcpsimpp0"></a>说明</p>
</td>
</tr>
<tr id="row290mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry291mcpsimpp0"><a name="entry291mcpsimpp0"></a><a name="entry291mcpsimpp0"></a>HdfChipDriverFactory</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="p136856366385"><a name="p136856366385"></a><a name="p136856366385"></a>//drivers/framework/include/wifi/hdf_wlan_chipdriver_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry294mcpsimpp0"><a name="entry294mcpsimpp0"></a><a name="entry294mcpsimpp0"></a>ChipDriver的Factory，用于支持一个芯片多个Wi-Fi端口</p>
</td>
</tr>
<tr id="row295mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry296mcpsimpp0"><a name="entry296mcpsimpp0"></a><a name="entry296mcpsimpp0"></a>HdfChipDriver</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="p714312457389"><a name="p714312457389"></a><a name="p714312457389"></a>//drivers/framework/include/wifi/wifi_module.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry299mcpsimpp0"><a name="entry299mcpsimpp0"></a><a name="entry299mcpsimpp0"></a>每个WLAN端口对应一个HdfChipDriver，用来管理一个特定的WLAN端口</p>
</td>
</tr>
<tr id="row300mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry301mcpsimpp0"><a name="entry301mcpsimpp0"></a><a name="entry301mcpsimpp0"></a>NetDeviceInterFace</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="p015815313819"><a name="p015815313819"></a><a name="p015815313819"></a>//drivers/framework/include/net/net_device.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry304mcpsimpp0"><a name="entry304mcpsimpp0"></a><a name="entry304mcpsimpp0"></a>与协议栈之间的接口，如发送数据、设置网络接口状态等</p>
</td>
</tr>
</tbody>
</table>

建议适配按如下步骤操作：

1.创建HDF驱动建议将代码放置在//device/MySoCVendor/peripheral/wifi/chip\_name/，文件模板如下：

```
static int32_t HdfWlanHisiChipDriverInit(struct HdfDeviceObject *device) {
    static struct HdfChipDriverFactory factory = CreateChipDriverFactory();
    struct HdfChipDriverManager *driverMgr = HdfWlanGetChipDriverMgr();
    if (driverMgr->RegChipDriver(&factory) != HDF_SUCCESS) {
        HDF_LOGE("%s fail: driverMgr is NULL!", __func__);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

struct HdfDriverEntry g_hdfXXXChipEntry = {
    .moduleVersion = 1,
    .Init = HdfWlanXXXChipDriverInit,
    .Release = HdfWlanXXXChipRelease,
    .moduleName = "HDF_WIFI_CHIP_XXX"
};

HDF_INIT(g_hdfXXXChipEntry);
```

在CreateChipDriverFactory中，需要创建一个HdfChipDriverFactory，接口如下：

<a name="table312mcpsimp"></a>
<table><tbody><tr id="row317mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry318mcpsimpp0"><a name="entry318mcpsimpp0"></a><a name="entry318mcpsimpp0"></a>接口</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry319mcpsimpp0"><a name="entry319mcpsimpp0"></a><a name="entry319mcpsimpp0"></a>说明</p>
</td>
</tr>
<tr id="row320mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry321mcpsimpp0"><a name="entry321mcpsimpp0"></a><a name="entry321mcpsimpp0"></a>const char *driverName</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry322mcpsimpp0"><a name="entry322mcpsimpp0"></a><a name="entry322mcpsimpp0"></a>当前driverName</p>
</td>
</tr>
<tr id="row323mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry324mcpsimpp0"><a name="entry324mcpsimpp0"></a><a name="entry324mcpsimpp0"></a>int32_t (*InitChip)(struct HdfWlanDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry325mcpsimpp0"><a name="entry325mcpsimpp0"></a><a name="entry325mcpsimpp0"></a>初始化芯片</p>
</td>
</tr>
<tr id="row326mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry327mcpsimpp0"><a name="entry327mcpsimpp0"></a><a name="entry327mcpsimpp0"></a>int32_t (*DeinitChip)(struct HdfWlanDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry328mcpsimpp0"><a name="entry328mcpsimpp0"></a><a name="entry328mcpsimpp0"></a>去初始化芯片</p>
</td>
</tr>
<tr id="row329mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry330mcpsimpp0"><a name="entry330mcpsimpp0"></a><a name="entry330mcpsimpp0"></a>void (_ReleaseFactory)(struct HdfChipDriverFactory _factory)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry331mcpsimpp0"><a name="entry331mcpsimpp0"></a><a name="entry331mcpsimpp0"></a>释放HdfChipDriverFactory对象</p>
</td>
</tr>
<tr id="row332mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry333mcpsimpp0"><a name="entry333mcpsimpp0"></a><a name="entry333mcpsimpp0"></a>struct HdfChipDriver _(_Build)(struct HdfWlanDevice *device, uint8_t ifIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry334mcpsimpp0"><a name="entry334mcpsimpp0"></a><a name="entry334mcpsimpp0"></a>创建一个HdfChipDriver；输入参数中，device是设备信息，ifIndex是当前创建的接口在这个芯片中的序号</p>
</td>
</tr>
<tr id="row335mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry336mcpsimpp0"><a name="entry336mcpsimpp0"></a><a name="entry336mcpsimpp0"></a>void (_Release)(struct HdfChipDriver _chipDriver)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry337mcpsimpp0"><a name="entry337mcpsimpp0"></a><a name="entry337mcpsimpp0"></a>释放chipDriver</p>
</td>
</tr>
<tr id="row338mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry339mcpsimpp0"><a name="entry339mcpsimpp0"></a><a name="entry339mcpsimpp0"></a>uint8_t (*GetMaxIFCount)(struct HdfChipDriverFactory *factory)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry340mcpsimpp0"><a name="entry340mcpsimpp0"></a><a name="entry340mcpsimpp0"></a>获取当前芯片支持的最大接口数</p>
</td>
</tr>
</tbody>
</table>

HdfChipDriver需要实现的接口有

<a name="table342mcpsimp"></a>
<table><tbody><tr id="row347mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry348mcpsimpp0"><a name="entry348mcpsimpp0"></a><a name="entry348mcpsimpp0"></a>接口</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry349mcpsimpp0"><a name="entry349mcpsimpp0"></a><a name="entry349mcpsimpp0"></a>说明</p>
</td>
</tr>
<tr id="row350mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry351mcpsimpp0"><a name="entry351mcpsimpp0"></a><a name="entry351mcpsimpp0"></a>int32_t (*init)(struct HdfChipDriver *chipDriver, NetDevice *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry352mcpsimpp0"><a name="entry352mcpsimpp0"></a><a name="entry352mcpsimpp0"></a>初始化当前网络接口，这里需要向netDev提供接口NetDeviceInterFace</p>
</td>
</tr>
<tr id="row353mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry354mcpsimpp0"><a name="entry354mcpsimpp0"></a><a name="entry354mcpsimpp0"></a>int32_t (*deinit)(struct HdfChipDriver *chipDriver, NetDevice *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry355mcpsimpp0"><a name="entry355mcpsimpp0"></a><a name="entry355mcpsimpp0"></a>去初始化当前网络接口</p>
</td>
</tr>
<tr id="row356mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry357mcpsimpp0"><a name="entry357mcpsimpp0"></a><a name="entry357mcpsimpp0"></a>struct HdfMac80211BaseOps *ops</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry358mcpsimpp0"><a name="entry358mcpsimpp0"></a><a name="entry358mcpsimpp0"></a>WLAN基础能力接口集</p>
</td>
</tr>
<tr id="row359mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry360mcpsimpp0"><a name="entry360mcpsimpp0"></a><a name="entry360mcpsimpp0"></a>struct HdfMac80211STAOps *staOps</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry361mcpsimpp0"><a name="entry361mcpsimpp0"></a><a name="entry361mcpsimpp0"></a>支持STA模式所需的接口集</p>
</td>
</tr>
<tr id="row362mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry363mcpsimpp0"><a name="entry363mcpsimpp0"></a><a name="entry363mcpsimpp0"></a>struct HdfMac80211APOps *apOps</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry364mcpsimpp0"><a name="entry364mcpsimpp0"></a><a name="entry364mcpsimpp0"></a>支持AP模式所需要的接口集</p>
</td>
</tr>
</tbody>
</table>

2.编写配置文件，描述驱动支持的设备

在产品配置目录下创建芯片的配置文件//vendor/MyProductVendor/MyProduct/config/wifi/wlan\_chip\_chip\_name.hcs。

注意： 路径中的vendor\_name、product\_name、chip\_name请替换成实际名称。

模板如下：

```
root {
    wlan_config {
        chip_name :& chipList {
            chip_name :: chipInst {
                match_attr = "hdf_wlan_chips_chip_name"; /* 这是配置匹配属性，用于提供驱动的配置根 */
                driverName = "driverName"; /* 需要与HdfChipDriverFactory中的driverName相同*/
                sdio {
                    vendorId = 0x0296;
                    deviceId = [0x5347];
                }
            }
        }
    }
}
```

3.编写配置文件，加载驱动

产品的所有设备信息被定义在文件//vendor/MyProductVendor/MyProduct/config/device\_info/device\_info.hcs中。修改该文件，在名为network的host中，名为device\_wlan\_chips的device中增加配置。注意：moduleName 要与触摸屏驱动中的moduleName相同。

```
                deviceN :: deviceNode {
                    policy = 0;
                    preload = 2;
                    moduleName = "HDF_WLAN_CHIPS";
                    deviceMatchAttr = "hdf_wlan_chips_chip_name";
                    serviceName = "driverName";
                }
```

4.构建驱动

-   创建内核菜单在//device/MySoCVendor/peripheral目录中创建Kconfig文件，内容模板如下：

```
config DRIVERS_WLAN_XXX
    bool "Enable XXX WLAN Host driver"
    default n
    depends on DRIVERS_HDF_WIFI
    help
      Answer Y to enable XXX Host driver. Support chip xxx
```

接着修改文件//drivers/adapter/khdf/linux/model/network/wifi/Kconfig,在文件末尾加入如下代码将配置菜单加入内核中，如：

```
source "../../../../../device/MySoCVendor/peripheral/Kconfig"
```

-   创建构建脚本

    在//drivers/adapter/khdf/linux/model/network/wifi/Makefile文件末尾增加配置，模板如下：


```
HDF_DEVICE_ROOT := $(HDF_DIR_PREFIX)/../device
obj-$(CONFIG_DRIVERS_WLAN_XXX) += $(HDF_DEVICE_ROOT)/MySoCVendor/peripheral/build/standard/
```

当在内核中开启DRIVERS\_WLAN\_XXX开关时，会调用//device/MySoCVendor/peripheral/build/standard/中的makefile。更多详细的开发手册，请参考[WLAN开发](../guide/oem_wifi_sdk_des.md)。

### 4. 开发移植示例<a name="section11253153018415"></a>

开发移植示例请参考[DAYU开发板](https://gitee.com/openharmony-sig/devboard_device_hihope_build/blob/master/DAYU%20%E5%B9%B3%E5%8F%B0OpenHarmony%20%E9%80%82%E9%85%8D%E6%8C%87%E5%AF%BC%20-202108.pdf)。

