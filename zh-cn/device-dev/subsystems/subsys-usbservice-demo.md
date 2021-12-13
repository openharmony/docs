# USB服务子系使用实例<a name="ZH-CN_TOPIC_0000001092792986"></a>


```
#include <cstdio>
#include <iostream>
#include <map>
#include <mutex>
#include <sstream>
#include "if_system_ability_manager.h"
#include "ipc_skeleton.h"
#include "iremote_object.h"
#include "iservice_registry.h"
#include "iusb_srv.h"
#include "string_ex.h"
#include "system_ability_definition.h"
#include "usb_common.h"
#include "usb_device.h"
#include "usb_request.h"
#include "usb_server_proxy.h"
#include "usb_srv_client.h"
#include "usb_errors.h"
#include <sys/time.h>

//需要修改/base/usb/usb_manager/service/BUILD.gn和/base/usb/usb_manager/ohos.build文件
//usb_manager/servrice/BUILD.gn是因为.cpp文件在service目录下，可根据实际情况来调整gn的指定路径

int main(int argc, char **argv)
{
    int32_t ret;
    static OHOS::USB::UsbSrvClient &g_usbClient = OHOS::USB::UsbSrvClient::GetInstance();
    // GetDevices
    std::vector<OHOS::USB::UsbDevice> deviceList;
    ret = g_usbClient.GetDevices(deviceList);
    if (ret != 0) {
        std::cout << "GetDevices failed width ret = " << ret << std::endl;
        return -5;
    }
    if (deviceList.empty()) {
        std::cout << "device list is empty." << std::endl;
        return -5;
    }
    for (auto it = deviceList.begin(); it != deviceList.end(); ++it) {
        std::cout << "device info :" << it->ToString() << "\n" << std::endl;
    }
    std::cout << "usb_device_test : << GetDevices >> test end ok <-" << std::endl;
    OHOS::USB::UsbDevice device = deviceList[0];
    std::vector<OHOS::USB::USBConfig> configs = device.GetConfigs();
    OHOS::USB::USBConfig config = configs[0];
    std::vector<OHOS::USB::UsbInterface> interfaces = config.GetInterfaces();
    OHOS::USB::UsbInterface interface;
    OHOS::USB::USBEndpoint inEp;
    OHOS::USB::USBEndpoint outEp;
    bool interfaceFlg = false;
    bool inEpFlg = false;
    bool outEpFlg = false;
    std::string hstr = "\t";
    std::cout << "test device Info:" << device.ToString() << std::endl;
    std::cout << hstr << "config Info:" << config.ToString() << std::endl;
    hstr += "\t";
    for (int32_t i = 0; i < config.GetInterfaceCount(); ++i) {
        OHOS::USB::UsbInterface tif = interfaces[i];
        std::cout << hstr << "Interfaces[" << i << "]:" << std::endl;
        std::cout << hstr << tif.ToString() << std::endl;
        std::string hestr = hstr + "\t";
        std::vector<OHOS::USB::USBEndpoint> mEndpoints = tif.GetEndpoints();
        for (int32_t j = 0; j < tif.GetEndpointCount(); ++j) {
            OHOS::USB::USBEndpoint tep = mEndpoints[j];
            std::cout << hestr << "mEndpoints[" << j << "]:" << std::endl;
            std::cout << hestr << tep.ToString() << std::endl;
            if ((tif.GetClass() == 10) && (tif.GetSubClass() == 0) && (tif.GetProtocol() == 2)) {
                if ((!interfaceFlg) && (tep.GetType() == 2)) {
                    if (tep.GetDirection()) {
                        inEp = tep;
                        inEpFlg = true;
                    } else {
                        outEp = tep;
                        outEpFlg = true;
                    }
                }
            }
        }
        if (!interfaceFlg) {
            if ((outEpFlg) && (inEpFlg)) {
                interface = interfaces[i];
                interfaceFlg = true;
            } else {
                inEpFlg = false;
                outEpFlg = false;
            }
        }
        std::cout << std::endl;
    }
// OpenDevice
    std::cout << "usb_device_test : << OpenDevice >> test begin -> " << std::endl;
    OHOS::USB::USBDevicePipe pip;
    ret = g_usbClient.RequestRight(device.GetName());
    std::cout << "设备请求权限结果 ret = " << ret << std::endl;
    if (0 != ret) {
        std::cout << "设备请求权限失败 ret = " << ret << std::endl;
    }
    ret = g_usbClient.OpenDevice(device, pip);
    if (ret != 0) {
        std::cout << "OpenDevice failed width ret = " << ret << std::endl;
        return -5;
    }
    std::cout << "usb_device_test : << Control Transfer >> " << std::endl;
    int32_t requestCmd = 6;
    int32_t requestType = ((1 << 7) | (0 << 5) | (0 & 0x1f));
    int32_t value = (2 << 8) + 0; // descriptor type << 8 + descriptor index
    int32_t index = 0;
    int32_t timeout = 5000;
    std::vector<uint8_t> vData;
    const OHOS::USB::UsbCtrlTransfer tctrl = {requestType, requestCmd, value, index, timeout};
    ret = g_usbClient.ControlTransfer(pip, tctrl, vData);
    if (ret != 0) {
        std::cout << "control message read failed width ret = " << ret << std::endl;
    } else {
        std::cout << "control message read success" << std::endl;
    }
    if (interfaceFlg) {
        std::cout << "ClaimInterface InterfaceInfo:" << interface.ToString() << std::endl;
        ret = g_usbClient.ClaimInterface(pip, interface, true);
        if (ret != 0) {
            std::cout << "ClaimInterface failed width ret = " << ret << std::endl;
        } else {
            std::cout << "ClaimInterface success" << std::endl;
        }
    }
    // BulkTransfer
    if (interfaceFlg) {
        std::cout << "usb_device_test : << Bulk transfer start >> " << std::endl;
        if (outEpFlg) {
            std::cout << "usb_device_test : << Bulk transfer write >> " << std::endl;
            uint8_t buffer[50] = "hello world 123456789";
            std::vector<uint8_t> vData(buffer, buffer + 21);
            ret = g_usbClient.BulkTransfer(pip, outEp, vData, 5000);
            if (ret != 0) {
                std::cout << "Bulk transfer write failed width ret = " << ret << std::endl;
            } else {
                std::cout << "Bulk transfer write success" << std::endl;
            }
        }
    }
    // CloseDevice
    std::cout << "usb_device_test : << Close Device >> " << std::endl;
    ret = g_usbClient.Close(pip);
    if (ret == 0) {
        std::cout << "Close device failed width ret = " << ret << std::endl;
        return -5;
    } else {
        std::cout << "Close device success" << std::endl;
    }
    return 0;
}
```


