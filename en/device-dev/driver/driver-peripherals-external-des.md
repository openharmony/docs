# WLAN


## Overview

### WLAN

The Wireless Local Area Network (WLAN) Driver module in OpenHarmony is developed based on the Hardware Driver Foundation (HDF). It features cross-OS porting, self-adaptation to component differences, and modular assembly and build.

### Working Principles

You can adapt your driver code based on the unified interfaces provided by the WLAN module. The WLAN module provides:

- A unified underlying interface to implement capabilities, such as setting up or closing a WLAN hotspot, scanning hotspots, and connecting to or disconnecting from a hotspot.
- A unified interface to the Hardware Device Interface (HDI) layer to implement capabilities, such as setting or obtaining the device Media Access Control (MAC) address and setting the transmit power.

The figure below shows the WLAN architecture. The WLAN Driver module implements startup loading, parses configuration files, and provides bus abstraction APIs. The WLAN Chip Driver module provides the MAC Sublayer Management Entity (MLME).

  **Figure 1** WLAN architecture

  ![image](figures/WLAN_architecture.png "WLAN architecture")

  The figure below shows the WLAN driver architecture.

  **Figure 2** WLAN driver architecture

  ![image](figures/WLAN_driver_architecture.png "WLAN driver architecture")

The WLAN driver consists of the following modules:

1. WLAN Message: provides an independent interface for each service or a composite service interface for multiple dependent services. It can run in the user mode, kernel mode, and MCU to implement complete decoupling between components.

2. WLAN Configuration Core: parses WLAN configuration files.

3. Access point (AP): provides a WLAN access interface for devices.

4. Station (STA): a terminal that accesses the WLAN system.

5. mac80211: defines MAC-layer interfaces for underlying drivers.

6. Bus: provides a unified bus abstract interface for the upper layer. It shields the differences between different kernels by calling the Secure Digital Input Output (SDIO) interfaces provided by the platform layer and encapsulating the adapted USB and PCIe interfaces. It also encapsulates different types of bus operations in a unified manner to shield differences between different chipsets. The complete bus driving capabilities provided by the bus module help simplify and streamline the development of different chip vendors.

7. NetDevice: creates dedicated network devices to shield differences between OSs, provides unified interfaces for Wi-Fi drivers, unified HDF NetDevice data structure, and unified management, registration, and deregistration capabilities, and connects to the Linux network device layer on mini-, small-, standard, and large-system devices.

8. NetBuf: encapsulates the unified data structure of the Linux or LiteOS native network data buffer and the operation interfaces for network data.

9. FlowCtl: performs flow control.

10. HCC-CFG: configures WLAN parameters, including the board configuration, driver configuration, and module configuration.

The relationships between the main modules are as follows:

1. The WLAN driver works with HCC-CFG and WLAN Configuration Core to parse and load configuration files.

2. The WLAN Message module distributes user-mode messages to the AP and STA by component.

3. Commands are delivered to mac80211, and then forwarded by the Bus module to the WLAN chip firmware.

4. The protocol stack works with the NetDevice, NetBuf, and FlowCtl modules to exchange data flows.

## Development Guidelines

### Available APIs

The WLAN module provides the following types of APIs:

- WLAN APIs that can be directly called by drivers

- APIs for vendors

- APIs for the HDI layer


  **Figure 3** WLAN driver APIs

  ![image](figures/WLAN_driver_APIs.png "WLAN Driver APIs")

- The WLAN Driver module provides APIs that you can directly use to create or release a **WifiModule**, connect to or disconnect from a WLAN hotspot, request or release a **NetBuf**, and convert between the **pbuf** structure of Lightweight IP (lwIP) and a **NetBuf**.

  Tables 1 to 3 describe these APIs.

    **Table 1** wifi_module.h (HDF-based WLAN driver development)

  | API| Description|
  | -------- | -------- |
  | struct WifiModule \*WifiModuleCreate(const struct HdfConfigWifiModuleConfig \*config) | Creates a **WifiModule**.|
  | void WifiModuleDelete(struct WifiModule \*module) | Deletes a **WifiModule** and releases its data.|
  | int32_t DelFeature(struct WifiModule \*module, uint16_t featureType) | Deletes a feature from a **WifiModule**.|
  | int32_t AddFeature(struct WifiModule \*module, uint16_t featureType, struct WifiFeature \*featureData) | Adds a feature to a **WifiModule**.|

    **Table 2** wifi_mac80211_ops.h

  | API| Description|
  | -------- | -------- |
  | int32_t (\*startAp)(NetDevice \*netDev) | Starts an AP.|
  | int32_t (\*stopAp)(NetDevice \*netDev) | Stops an AP.|
  | int32_t (\*connect)(NetDevice \*netDev, WifiConnectParams \*param) | Connects to a hotspot.|
  | int32_t (\*disconnect)(NetDevice \*netDev, uint16_t reasonCode) | Disconnects from a hotspot.|

    **Table 3** hdf_netbuf.h

  | API| Description|
  | -------- | -------- |
  | static inline void NetBufQueueInit(struct NetBufQueue \*q) | Initializes a **NetBuf** queue.|
  | struct NetBuf \*NetBufAlloc(uint32_t size) | Allocates a **NetBuf**.|
  | void NetBufFree(struct NetBuf \*nb) | Releases a **NetBuf**.|
  | struct NetBuf \*Pbuf2NetBuf(const struct NetDevice \*netdev, struct pbuf \*lwipBuf) | Converts the **pbuf** structure of lwIP to a **NetBuf**.|
  | struct pbuf \*NetBuf2Pbuf(const struct NetBuf \*nb) | Converts a **NetBuf** to the **pbuf** structure of lwIP.|

- The WLAN Driver module also provides APIs that you need to fill in the implementation. This type of APIs can be used to initialize/deinitialize a **NetDevice**, opening/stopping a **NetDevice**, and obtaining the **NetDevice** status. Table 4 describes some of these APIs.

    **Table 4** net_device.h

  | API| Description|
  | -------- | -------- |
  | int32_t (\*init)(struct NetDevice \*netDev) | Initializes a **NetDevice**.|
  | struct NetDevStats \*(\*getStats)(struct NetDevice \*netDev) | Obtains the state of a **NetDevice**.|
  | int32_t (\*setMacAddr)(struct NetDevice \*netDev, void \*addr) | Sets the MAC address.|
  | void (\*deInit)(struct NetDevice \*netDev) | Deinitializes a **NetDevice**.|
  | int32_t (\*open)(struct NetDevice \*netDev) | Opens a **NetDevice**.|
  | int32_t (\*stop)(struct NetDevice \*netDev) | Stops a **NetDevice**.|

- The WLAN Driver module also provides APIs to the HDI layer for creating and destroying an **IWiFi** object and setting the MAC address. Tables 5 and 6 describe some of the APIs.

    **Table 5** wifi_hal.h

  | API| Description|
  | -------- | -------- |
  | int32_t WifiConstruct(struct IWiFi \*\*wifiInstance) | Creates an **IWiFi** object with basic capabilities.|
  | int32_t WifiDestruct(struct IWiFi \*\*wifiInstance) | Destroys an **IWiFi** object.|
  | int32_t (\*start)(struct IWiFi \*) | Creates a channel between the HAL and the driver and obtains the NICs supported by the driver.|
  | int32_t (\*stop)(struct IWiFi \*) | Stops the channel between the HAL and the driver.|

    **Table 6** wifi_hal_base_feature.h

  | API| Description|
  | -------- | -------- |
  | int32_t (\*getFeatureType)(const struct IWiFiBaseFeature \*) | Obtains the feature type.|
  | int32_t (\*setMacAddress)(const struct IWiFiBaseFeature \*, unsigned char \*, uint8_t) | Sets the MAC address.|
  | int32_t (\*getDeviceMacAddress)(const struct IWiFiBaseFeature \*, unsigned char \*, uint8_t) | Obtains the device MAC address.|
  | int32_t (\*setTxPower)(const struct IWiFiBaseFeature \*, int32_t) | Sets the transmit power.|


### How to Develop

The WLAN driver module developed based on the HDF and Platform frameworks provides a unified driver model for WLAN modules of different vendors regardless of the OS and system on a chip (SoC).


1. Configure hardware (such as modules and chips) parameters in the **wifi_config.hcs** file. This configuration file is parsed by the corresponding API in the HDF to generate a structure object for full configuration.

2. Initialize and create a module.

3. Attach and initialize the chip.

4. Implement the upper-layer Wi-Fi Protected Access (WPA) service.

### Development Example

This example describes how to initialize a WLAN module. The following uses the Hi3881 WLAN chip as an example:

  1. Set parameters for the WLAN module based on hardware attributes.

```
/* Set parameters in the wlan_platform.hcs file based on hardware attributes. The following is an example of the WLAN platform configuration. */
hisi :& deviceList {
    device0 :: deviceInst {
        deviceInstId = 0;
        powers {
            power0 {
                powerSeqDelay = 0;  /* Power sequence delay. */
                powerType = 1;      /* Power supply type. The value 0 indicates that the device is always powered on, and 1 indicates power supply through general-purpose input/output (GPIO). */
                gpioId = 1;         /* GPIO pin number. */
                activeLevel=1;      /* Active level. The value 0 indicates low level, and 1 indicates high level. */
            }
            power1 {
                powerSeqDelay = 0;  /* Power sequence delay. */
                powerType = 0;      /* The value 0 indicates that the device is always powered on, and 1 indicates power supply through GPIO. */
            }
        }
        reset {
            resetType = 0;         /* Reset type. The value 0 indicates that reset is dynamically determined, and value 1 indicates reset through GPIO. */
            gpioId = 2;           /* GPIO pin number. */
            activeLevel=1;         /* Active level. The value 0 indicates low level, and 1 indicates high level. */
            resetHoldTime = 30;    /* Hold time (ms) after a reset. */
        }
        bootUpTimeout = 30;  /* Boot timeout duration (ms). */
        bus {
            busType = 0;     /* Bus type. The value 0 indicates SDIO. */
            busId = 2;      /* Bus number. */
            funcNum = [1];   /* SDIO function number. */
            timeout = 1000;  /* Timeout duration for data read/write. */
            blockSize = 512; /* Size of the data block to read or write. */
        }
    }
}
/* Add the configuration file wlan_chip_<Chip name>.hcs (for example, wlan_chip_hi3881.hcs) for each chip and set parameters. The following uses the Hi3881 chip as an example. */
root {
    wlan_config {
        hi3881 :& chipList {
            chipHi3881 :: chipInst {
                match_attr = "hdf_wlan_chips_hi3881"; /* Attribute used to match the chip. */
                chipName = "hi3881";                   /* WLAN chip name. */
                sdio {
                    vendorId = 0x0296;    /* Vendor ID. */
                    deviceId = [0x5347];  /* Device ID. */
                }
            }
        }
    }
}
```

  2. Hook the **init** and **deinit** functions of the WLAN chip and WLAN chip driver.

```
/* Process of implementing WLAN module initialization. */
#include "hdf_device_desc.h"
#include "hdf_wifi_product.h"
#include "hdf_log.h"
#include "osal_mem.h"
#include "hdf_wlan_chipdriver_manager.h"
#include "securec.h"
#include "wifi_module.h"
#include "hi_wifi_api.h"
#include "hi_types_base.h"

#define HDF_LOG_TAG Hi3881Driver

/* Functions for initializing and deinitializing a WLAN chip. */
int32_t InitHi3881Chip(struct HdfWlanDevice *device);
int32_t DeinitHi3881Chip(struct HdfWlanDevice *device);
/* Functions for initializing and deinitializing a WLAN chip driver. */
int32_t Hi3881Deinit(struct HdfChipDriver* chipDriver, struct NetDevice *netDevice);
int32_t Hi3881Init(struct HdfChipDriver* chipDriver, struct NetDevice *netDevice);

/* Initialize mac80211 by hooking the functions of the chip. */
hi_void HiMac80211Init(struct HdfChipDriver *chipDriver);

static const char* const HI3881_DRIVER_NAME = "hisi";

/* Hook the functions of the WLAN chip driver, mac80211, and chip. */
static struct HdfChipDriver *BuildHi3881Driver(struct HdfWlanDevice *device, uint8_t ifIndex)
{
    struct HdfChipDriver *specificDriver = NULL;
    if (device == NULL) {
        HDF_LOGE("%s fail : channel is NULL", __func__);
        return NULL;
    }
    (void)device;
    (void)ifIndex;
    specificDriver = (struct HdfChipDriver *)OsalMemCalloc(sizeof(struct HdfChipDriver));
    if (specificDriver == NULL) {
        HDF_LOGE("%s fail: OsalMemCalloc fail!", __func__);
        return NULL;
    }
    if (memset_s(specificDriver, sizeof(struct HdfChipDriver), 0, sizeof(struct HdfChipDriver)) != EOK) {
        HDF_LOGE("%s fail: memset_s fail!", __func__);
        OsalMemFree(specificDriver);
        return NULL;
    }

    if (strcpy_s(specificDriver->name, MAX_WIFI_COMPONENT_NAME_LEN, HI3881_DRIVER_NAME) != EOK) {
        HDF_LOGE("%s fail : strcpy_s fail", __func__);
        OsalMemFree(specificDriver);
        return NULL;
    }
    specificDriver->init = Hi3881Init;
    specificDriver->deinit = Hi3881Deinit;

    HiMac80211Init(specificDriver);

    return specificDriver;
}

/* Release the WLAN chip driver. */
static void ReleaseHi3881Driver(struct HdfChipDriver *chipDriver)
{
    if (chipDriver == NULL) {
        return;
    }
    if (strcmp(chipDriver->name, HI3881_DRIVER_NAME) != 0) {
        HDF_LOGE("%s:Not my driver!", __func__);
        return;
    }
    OsalMemFree(chipDriver);
}

static uint8_t GetHi3881GetMaxIFCount(struct HdfChipDriverFactory *factory) {
    (void)factory;
    return 1;
}

/* Register WLAN chip functions. */
static int32_t HDFWlanRegHisiDriverFactory(void)
{
    static struct HdfChipDriverFactory tmpFactory = { 0 };
    struct HdfChipDriverManager *driverMgr = NULL;
    driverMgr = HdfWlanGetChipDriverMgr();
    if (driverMgr == NULL && driverMgr->RegChipDriver != NULL) {
        HDF_LOGE("%s fail: driverMgr is NULL!", __func__);
        return HDF_FAILURE;
    }
    tmpFactory.driverName = HI3881_DRIVER_NAME;
    tmpFactory.GetMaxIFCount = GetHi3881GetMaxIFCount;
    tmpFactory.InitChip = InitHi3881Chip;
    tmpFactory.DeinitChip = DeinitHi3881Chip;
    tmpFactory.Build = BuildHi3881Driver;
    tmpFactory.Release = ReleaseHi3881Driver;
    tmpFactory.ReleaseFactory = NULL;
    if (driverMgr->RegChipDriver(&tmpFactory) != HDF_SUCCESS) {
        HDF_LOGE("%s fail: driverMgr is NULL!", __func__);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}

static int32_t HdfWlanHisiChipDriverInit(struct HdfDeviceObject *device)
{
    (void)device;
    return HDFWlanRegHisiDriverFactory();
}

struct HdfDriverEntry g_hdfHisiChipEntry = {
    .moduleVersion = 1,
    .Init = HdfWlanHisiChipDriverInit,
    .moduleName = "HDF_WLAN_CHIPS"
};

HDF_INIT(g_hdfHisiChipEntry);
```


```
#include "hdf_wifi_product.h"
#include "hi_wifi_api.h"
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include "oal_thread.h"
#include "osal_time.h"
#endif
#include "wifi_mac80211_ops.h"
#include "wal_cfg80211.h"
#include "net_adapter.h"
#include "hdf_wlan_utils.h"

#define HDF_LOG_TAG Hi3881Driver

/* Function for initializing the WLAN chip. */
int32_t InitHi3881Chip(struct HdfWlanDevice *device)
{
    uint8_t maxPortCount = 1;
    int32_t ret = HI_SUCCESS;
    uint8_t maxRetryCount = 2;
    if (device == NULL) {
        HDF_LOGE("%s:NULL ptr!", __func__);
        return HI_FAIL;
    }

    do {
        if (ret != HI_SUCCESS) {
            if (device->reset != NULL && device->reset->Reset != NULL) {
                device->reset->Reset(device->reset);
            }
            HDF_LOGE("%s:Retry init hi3881!last ret=%d", __func__, ret);
        }
        ret = hi_wifi_init(maxPortCount);
    } while (ret != 0 && --maxRetryCount > 0);

    if (ret != 0) {
        HDF_LOGE("%s:Init hi3881 driver failed!", __func__);
        return ret;
    }
    return HI_SUCCESS;
}

/* Function for deinitializing the WLAN chip. */
int32_t DeinitHi3881Chip(struct HdfWlanDevice *device)
{
    (void)device;
    int32_t ret = hi_wifi_deinit();
    if (ret != 0) {
        HDF_LOGE("%s:Deinit failed!ret=%d", __func__, ret);
    }
    return ret;
}

/* Function for initializing the WLAN chip driver. */
int32_t Hi3881Init(struct HdfChipDriver *chipDriver, struct NetDevice *netDevice)
{
    HDF_LOGI("%s: start...", __func__);
    hi_u16 mode = wal_get_vap_mode();
    int32_t ret;
    nl80211_iftype_uint8 type;
    (void)chipDriver;

    if (mode >= WAL_WIFI_MODE_BUTT) {
        oam_error_log1(0, 0, "wal_init_drv_netdev:: invalid mode[%d]", mode);
        return HI_FAIL;
    }

    if (mode == WAL_WIFI_MODE_STA) {
        type = NL80211_IFTYPE_STATION;
    } else if (mode == WAL_WIFI_MODE_AP) {
        type = NL80211_IFTYPE_AP;
    } else {
        oam_error_log1(0, 0, "wal_init_drv_netdev:: invalid mode[%d]", mode);
        return HI_FAIL;
    }

    ret = wal_init_drv_wlan_netdev(type, WAL_PHY_MODE_11N, netDevice);
    if (ret != HI_SUCCESS) {
        oam_error_log2(0, OAM_SF_ANY, "wal_init_drv_netdev %s failed.l_return:%d\n", netDevice->name, ret);
    }
    return ret;
}

/* Function for deinitializing the WLAN chip driver. */
int32_t Hi3881Deinit(struct HdfChipDriver *chipDriver, struct NetDevice *netDevice)
{
    (void)chipDriver;
    int32_t ret = wal_deinit_drv_wlan_netdev(netDevice);
    if (ret != HDF_SUCCESS) {
        return ret;
    }
    return ReleasePlatformNetDevice(netDevice);
}
```

  3. During the chip initialization process, call **NetDeviceInit()**  to initialize a network device, call **NetDeviceAdd()** to add the network device to a protocol stack, and hook function pointers of **netdev**.

```
hi_s32 wal_init_drv_wlan_netdev(nl80211_iftype_uint8 type, wal_phy_mode mode, hi_char* ifname, hi_u32* len)
{
    oal_net_device_stru *netdev          = HI_NULL;

    ......
    /* Initialize the network device and obtain the initialized instance. */
    netdev = NetDeviceInit(ifname, *len, LITE_OS);
    oal_wireless_dev *wdev = (oal_wireless_dev *)oal_mem_alloc(OAL_MEM_POOL_ID_LOCAL, sizeof(oal_wireless_dev));
    ret = wal_init_netif(type, netdev, wdev);

    ......

    return HI_SUCCESS;
}
/* Hook pointers of NetDeviceInterFace(). */
oal_net_device_ops_stru g_wal_net_dev_ops =
{
    .getStats          = wal_netdev_get_stats,
    .open               = wal_netdev_open,
    .stop               = wal_netdev_stop,
    .xmit         = hmac_bridge_vap_xmit,
    .ioctl           = wal_net_device_ioctl,
    .changeMtu         = oal_net_device_change_mtu,
    .init              = oal_net_device_init,
    .deInit            = oal_net_free_netdev,
#if (defined(_PRE_WLAN_FEATURE_FLOWCTL) || defined(_PRE_WLAN_FEATURE_OFFLOAD_FLOWCTL))
    .selectQueue       = wal_netdev_select_queue,
#endif
    .setMacAddr    = wal_netdev_set_mac_addr,
#if (_PRE_OS_VERSION_LITEOS == _PRE_OS_VERSION)
    .netifNotify       = HI_NULL,
#endif
    .specialEtherTypeProcess = SpecialEtherTypeProcess,
};

hi_s32 wal_init_netif(nl80211_iftype_uint8 type, oal_net_device_stru *netdev, const oal_wireless_dev *wdev)
{
    /* Add the network device to a protocol stack. */
    hi_u32 ret = NetDeviceAdd(netdev, (Protocol80211IfType)type);

    ......

    return HI_SUCCESS;
}
```

4. Hook functions of **WifiMac80211Ops**.


```
/* Hook function pointers of mac80211. */

/* Define the functions for implementing the basic capabilities in the MAC layer for the driver. */
static struct HdfMac80211BaseOps g_baseOps = {
    .SetMode = WalSetMode,
    .AddKey = WalAddKey,
    .DelKey = WalDelKey,
    .SetDefaultKey = WalSetDefaultKey,
    .GetDeviceMacAddr = WalGetDeviceMacAddr,
    .SetMacAddr = WalSetMacAddr,
    .SetTxPower = WalSetTxPower,
    .GetValidFreqsWithBand = WalGetValidFreqsWithBand,
    .GetHwCapability = WalGetHwCapability
};

/* Define the functions for implementing the STA capabilities in the MAC layer for the driver. */
static struct HdfMac80211STAOps g_staOps = {
    .Connect = WalConnect,
    .Disconnect = WalDisconnect,
    .StartScan = WalStartScan,
    .AbortScan = WalAbortScan,
    .SetScanningMacAddress = WalSetScanningMacAddress,
};

/* Define the functions for implementing the AP capabilities in the MAC layer for the driver. */
static struct HdfMac80211APOps g_apOps = {
    .ConfigAp = WalConfigAp,
    .StartAp = WalStartAp,
    .StopAp = WalStopAp,
    .ConfigBeacon = WalChangeBeacon,
    .DelStation = WalDelStation,
    .SetCountryCode = WalSetCountryCode,
    .GetAssociatedStasCount = WalGetAssociatedStasCount,
    .GetAssociatedStasInfo = WalGetAssociatedStasInfo
};

/* Initialize mac80211 and hook functions of the chip. */
hi_void HiMac80211Init(struct HdfChipDriver *chipDriver)
{
    if (chipDriver == NULL) {
        oam_error_log(0, OAM_SF_ANY, "%s:input is NULL!", __func__);
        return;
    }
    chipDriver->ops = &g_baseOps;
    chipDriver->staOps = &g_staOps;
    chipDriver->apOps = &g_apOps;
}
```
## Reference

- Code repositories:

  [drivers\_hdf\_core](https://gitee.com/openharmony/drivers_hdf_core)

  [drivers\_peripheral](https://gitee.com/openharmony/drivers_peripheral)

- Code paths:

  Adaptation of WLAN FlowCtl component on LiteOS: **//drivers/hdf_core/adapter/khdf/liteos/model/network/wifi**

  Adaptation of HDF network model on LiteOS: **//drivers/hdf_core/adapter/khdf/liteos/model/network**

  Adaptation of WLAN FlowCtl component on Linux, build of the HDF WLAN model, and build of the vendor's WLAN driver:

  **//drivers/hdf_core/adapter/khdf/linux/model/network/wifi**

  Core code for implementing the WLAN module: **//drivers/hdf_core/framework/model/network/wifi**

  External APIs of the WLAN module: **//drivers/hdf_core/framework/include/wifi**

  HDF network model APIs: **//drivers/hdf_core/framework/include/net**

  WLAN HDI APIs and implementation: **//drivers/peripheral/wlan**
