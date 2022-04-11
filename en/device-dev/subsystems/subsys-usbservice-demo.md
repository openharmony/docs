# USB Usage Demo<a name="EN-US_TOPIC_0000001092792986"></a>


```
#include <cstdio>
#include <iostream>
#include <map>
#include <mutex>
#include <sstream>
#include <sys/time.h>
#include "if_system_ability_manager.h"
#include "ipc_skeleton.h"
#include "iremote_object.h"
#include "iservice_registry.h"
#include "iusb_srv.h"
#include "string_ex.h"
#include "system_ability_definition.h"
#include "usb_common.h"
#include "usb_device.h"
#include "usb_errors.h"
#include "usb_request.h"
#include "usb_server_proxy.h"
#include "usb_srv_client.h"

const int32_t REQUESTYPE = ((1 << 7) | (0 << 5) | (0 & 0x1f));
const int32_t REQUESTCMD = 6;
const int32_t VALUE = (2 << 8) + 0;
const int32_t TIMEOUT = 5000;
const int32_t ITFCLASS = 10;
const int32_t PRAMATYPE = 2;
const int32_t BUFFERLENGTH = 21;

void GetType(OHOS::USB::USBEndpoint &tep, OHOS::USB::USBEndpoint &outEp, bool &outEpFlg)
{
    if ((tep.GetType() == PRAMATYPE)) {
        if (tep.GetDirection() == 0) {
            outEp = tep;
            outEpFlg = true;
        }
    }
}

bool SelectEndpoint(OHOS::USB::USBConfig config,
                    std::vector<OHOS::USB::UsbInterface> interfaces,
                    OHOS::USB::UsbInterface &interface,
                    OHOS::USB::USBEndpoint &outEp,
                    bool &outEpFlg)
{
    for (int32_t i = 0; i < config.GetInterfaceCount(); ++i) {
        OHOS::USB::UsbInterface tif = interfaces[i];
        std::vector<OHOS::USB::USBEndpoint> mEndpoints = tif.GetEndpoints();
        for (int32_t j = 0; j < tif.GetEndpointCount(); ++j) {
            OHOS::USB::USBEndpoint tep = mEndpoints[j];
            if ((tif.GetClass() == ITFCLASS) && (tif.GetSubClass() == 0) && (tif.GetProtocol() == PRAMATYPE)) {
                GetType(tep, outEp, outEpFlg);
            }
        }
        if (outEpFlg) {
            interface = interfaces[i];
            return true;
        }
        std::cout << std::endl;
    }
    return false;
}

int OpenDeviceTest(OHOS::USB::UsbSrvClient &Instran, OHOS::USB::UsbDevice device, OHOS::USB::USBDevicePipe &pip)
{
    int ret = Instran.RequestRight(device.GetName());
    std::cout << "device RequestRight ret = " << ret << std::endl;
    if (0 != ret) {
        std::cout << "device RequestRight failed = " << ret << std::endl;
    }
    ret = Instran.OpenDevice(device, pip);
    return ret;
}

int CtrTransferTest(OHOS::USB::UsbSrvClient &Instran, OHOS::USB::USBDevicePipe &pip)
{
    std::cout << "usb_device_test : << Control Transfer >> " << std::endl;
    std::vector<uint8_t> vData;
    const OHOS::USB::UsbCtrlTransfer tctrl = {REQUESTYPE, REQUESTCMD, VALUE, 0, TIMEOUT};
    int ret = Instran.ControlTransfer(pip, tctrl, vData);
    if (ret != 0) {
        std::cout << "control message read failed width ret = " << ret << std::endl;
    } else {
    }
        std::cout << "control message read success" << std::endl;

    return ret;
}

int ClaimTest(OHOS::USB::UsbSrvClient &Instran,
              OHOS::USB::USBDevicePipe &pip,
              OHOS::USB::UsbInterface &interface,
              bool interfaceFlg)
{
    if (interfaceFlg) {
        std::cout << "ClaimInterface InterfaceInfo:" << interface.ToString() << std::endl;
        int ret = Instran.ClaimInterface(pip, interface, true);
        if (ret != 0) {
            std::cout << "ClaimInterface failed width ret = " << ret << std::endl;
        } else {
            std::cout << "ClaimInterface success" << std::endl;
        }
    }
    return 0;
}

int BulkTransferTest(OHOS::USB::UsbSrvClient &Instran,
                     OHOS::USB::USBDevicePipe &pip,
                     OHOS::USB::USBEndpoint &outEp,
                     bool interfaceFlg,
                     bool outEpFlg)
{
    if (interfaceFlg) {
        std::cout << "usb_device_test : << Bulk transfer start >> " << std::endl;
        if (outEpFlg) {
            uint8_t buffer[50] = "hello world 123456789";
            std::vector<uint8_t> vData(buffer, buffer + BUFFERLENGTH);
            int ret = Instran.BulkTransfer(pip, outEp, vData, TIMEOUT);
            if (ret != 0) {
                std::cout << "Bulk transfer write failed width ret = " << ret << std::endl;
            } else {
                std::cout << "Bulk transfer write success" << std::endl;
            }
            return ret;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << "usb_device_test " << std::endl;
    static OHOS::USB::UsbSrvClient &Instran = OHOS::USB::UsbSrvClient::GetInstance();
    // GetDevices
    std::vector<OHOS::USB::UsbDevice> deviceList;
    int32_t ret = Instran.GetDevices(deviceList);
    if (ret != 0) {
        return OHOS::USB::UEC_SERVICE_INVALID_VALUE;
    }
    if (deviceList.empty()) {
        return OHOS::USB::UEC_SERVICE_INVALID_VALUE;
    }

    OHOS::USB::UsbDevice device = deviceList[0];
    std::vector<OHOS::USB::USBConfig> configs = device.GetConfigs();
    OHOS::USB::USBConfig config = configs[0];
    std::vector<OHOS::USB::UsbInterface> interfaces = config.GetInterfaces();
    OHOS::USB::UsbInterface interface;
    OHOS::USB::USBEndpoint outEp;
    bool interfaceFlg = false;
    bool outEpFlg = false;
    interfaceFlg = SelectEndpoint(config, interfaces, interface, outEp, outEpFlg);

    // OpenDevice
    std::cout << "usb_device_test : << OpenDevice >> test begin -> " << std::endl;
    OHOS::USB::USBDevicePipe pip;
    ret = OpenDeviceTest(Instran, device, pip);
    if (ret != 0) {
        return OHOS::USB::UEC_SERVICE_INVALID_VALUE;
    }

    // ControlTransfer
    CtrTransferTest(Instran, pip);

    // ClaimInterface
    ClaimTest(Instran, pip, interface, interfaceFlg);

    // BulkTransferWrite
    BulkTransferTest(Instran, pip, outEp, interfaceFlg, outEpFlg);

    // CloseDevice
    std::cout << "usb_device_test : << Close Device >> " << std::endl;
    ret = Instran.Close(pip);
    if (ret == 0) {
        std::cout << "Close device failed width ret = " << ret << std::endl;
        return OHOS::USB::UEC_SERVICE_INVALID_VALUE;
    } else {
        std::cout << "Close Device success" << std::endl;
    }
    return 0;
}
```
