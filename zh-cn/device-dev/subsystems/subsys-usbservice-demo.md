# USB服务子系使用实例<a name="ZH-CN_TOPIC_0000001092792986"></a>


```
#include "usb_device_pipe_test.h"
#include <iostream>
#include <vector>
#include "delayed_sp_singleton.h"
#include "hilog_wrapper.h"
#include "if_system_ability_manager.h"
#include "system_ability_definition.h"
#include "usb_srv_client.h"

void UsbDevicePipeTest::SetUpTestCase(void)
{
    auto &srvClient = UsbSrvClient::GetInstance();
    auto ret = srvClient.SetPortRole(1, 1, 1);
    sleep(SLEEP_TIME);
    USB_HILOGI(MODULE_USB_SERVICE, "UsbDevicePipeTest:: [Device] SetPortRole=%{public}d", ret);
    ASSERT_TRUE(ret == 0);
    if (ret != 0) {
        exit(0);
    }

    std::cout << "请连接设备，连接完后按回车键继续" << std::endl;
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

/* 测试用例函数 */
HWTEST_F(UsbDevicePipeTest, UsbBulkTransfer001, TestSize.Level1)
{
    vector<UsbDevice> devi;
    // 获取usb service实例
    auto &UsbSrvClient = UsbSrvClient::GetInstance();
    // 获取usb设备列表
    auto ret = UsbSrvClient.GetDevices(devi);
    EXPECT_TRUE(ret == 0);
    EXPECT_TRUE(!(devi.empty())) << "delist NULL";
    USBDevicePipe pipe;
    UsbDevice device = devi.front();
    // 申请设备权限
    UsbSrvClient.RequestRight(device.GetName());
    // 打开设备
    ret = UsbSrvClient.OpenDevice(device, pipe);
    EXPECT_TRUE(ret == 0);
    UsbInterface interface = device.GetConfigs().front().GetInterfaces().at(1);
    USBEndpoint point = interface.GetEndpoints().front();
    // 配置设备接口
    ret = UsbSrvClient.ClaimInterface(pipe, interface, true);
    EXPECT_TRUE(ret == 0);
    uint8_t buffer[255] = "bulk read";
    uint32_t len = 255;
    std::vector<uint8_t> bulkbuffer = {buffer, buffer + len};
    // 数据传输
    ret = UsbSrvClient.BulkTransfer(pipe, point, bulkbuffer, 500);
    EXPECT_TRUE(ret == 0);
    // 关闭设备
    bool close = UsbSrvClient.Close(pipe);
    EXPECT_TRUE(close);
}
```


