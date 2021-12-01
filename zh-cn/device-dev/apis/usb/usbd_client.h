/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup USB
 * @{
 *
 * @brief Declares USB-related APIs, including the custom data types and functions
 * used to obtain descriptors, interface objects, and request objects, and to submit requests.
 *
 * @since 3.0
 * @version 1.0
 */

/**
 * @file usbd_client.h
 *
 * @brief Defines the usbd Interface.
 *
 * @since 3.0
 * @version 1.0
 */

#ifndef USBD_CLIENT_H
#define USBD_CLIENT_H

#include "usb_param.h"
#include "usbd_subscriber.h"

namespace OHOS {
namespace USB {
class UsbdClient {
public:
    /* *
     * @brief 打开设备，建立连接
     *
     * @param dev usb设备地址信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t OpenDevice(const UsbDev &dev);

    /* *
     * @brief 关闭设备，释放与设备相关的所有系统资源
     *
     * @param dev usb设备地址信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t CloseDevice(const UsbDev &dev);

    /* *
     * @brief 获取设备描述符device
     *
     * @param dev usb设备地址信息
     * @param decriptor usb设备描述符信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t GetDeviceDescriptor(const UsbDev &dev, std::vector<uint8_t> &decriptor);

    /* *
     * @brief 根据String ID获取设备的字符串描述符string
     *
     * @param dev usb设备地址信息
     * @param descId usb的string ID
     * @param decriptor 获取usb设备config信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t GetStringDescriptor(const UsbDev &dev, uint8_t descId, std::vector<uint8_t> &decriptor);

    /* *
     * @brief 根据config ID获取设备的配置描述符config
     *
     * @param dev usb设备地址信息
     * @param descId usb的config ID
     * @param decriptor 获取usb设备config信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t GetConfigDescriptor(const UsbDev &dev, uint8_t descId, std::vector<uint8_t> &decriptor);

    /* *
     * @brief 获取原始描述符
     *
     * @param dev usb设备地址信息
     * @param decriptor usb设备原始描述符
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t GetRawDescriptor(const UsbDev &dev, std::vector<uint8_t> &decriptor);

    /* *
     * @brief 设置当前的config信息
     *
     * @param dev usb设备地址信息
     * @param configIndex usb设备config信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t SetConfig(const UsbDev &dev, uint8_t configIndex);

    /* *
     * @brief 获取当前的config信息
     *
     * @param dev usb设备地址信息
     * @param configIndex usb设备config信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t GetConfig(const UsbDev &dev, uint8_t &configIndex);

    /* *
     * @brief 打开接口，并申明独占接口，必须在数据传输前执行
     *
     * @param dev usb设备地址信息
     * @param interfaceid usb设备interface ID
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t ClaimInterface(const UsbDev &dev, uint8_t interfaceid);

    /* *
     * @brief 关闭接口，释放接口的占用，在停止数据传输后执行
     *
     * @param dev usb设备地址信息
     * @param interfaceid usb设备interface ID
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t ReleaseInterface(const UsbDev &dev, uint8_t interfaceid);

    /* *
     * @brief 设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择
     *
     * @param dev usb设备地址信息
     * @param interfaceid usb设备interface ID
     * @param altIndex interface 的 AlternateSetting 信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t SetInterface(const UsbDev &dev, uint8_t interfaceid, uint8_t altIndex);

    /* *
     * @brief 在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取可以设置超时时间
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param timeout 超时时间
     * @param data 获取写入的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t
        BulkTransferRead(const UsbDev &dev, const UsbPipe &pipe, int32_t timeout, std::vector<uint8_t> &data);

    /* *
     * @brief 在给定端点上执行批量数据写入， 返回读取的数据和长度，端点方向必须为数据写入
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param timeout 超时时间
     * @param data 写入的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t
        BulkTransferWrite(const UsbDev &dev, const UsbPipe &pipe, int32_t timeout, const std::vector<uint8_t> &data);

    /* *
     * @brief 对此设备执行端点零的控制事务，传输方向由请求类型决定。 如果requestType＆
     * USB_ENDPOINT_DIR_MASK是USB_DIR_OUT ，则传输是写入，如果是USB_DIR_IN ，则传输是读取。
     *
     * @param dev usb设备地址信息
     * @param ctrl usb设备控制数据包结构
     * @param data 读取/写入 的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t ControlTransfer(const UsbDev &dev, const UsbCtrlTransfer &ctrl, std::vector<uint8_t> &data);

    /* *
     * @brief 在给定端点上执行中断数据读取， 返回读取的数据和长度，端点方向必须为数据读取
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param timeout 超时时间
     * @param data 读取的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t
        InterruptTransferRead(const UsbDev &dev, const UsbPipe &pipe, int32_t timeout, std::vector<uint8_t> &data);

    /* *
     * @brief 在给定端点上执行中断数据写入， 返回读取的数据和长度，端点方向必须为数据写入
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param timeout 超时时间
     * @param data 读取的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t
        InterruptTransferWrite(const UsbDev &dev, const UsbPipe &pipe, int32_t timeout, std::vector<uint8_t> &data);

    /* *
     * @brief 在给定端点上执行等时数据读取， 返回读取的数据和长度，端点方向必须为数据读取
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param timeout 超时时间
     * @param data 读取的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t IsoTransferRead(const UsbDev &dev, const UsbPipe &pipe, int32_t timeout, std::vector<uint8_t> &data);

    /* *
     * @brief 在给定端点上执行等时数据写入， 返回读取的数据和长度，端点方向必须为数据写入
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param timeout 超时时间
     * @param data 读取的数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t
        IsoTransferWrite(const UsbDev &dev, const UsbPipe &pipe, int32_t timeout, std::vector<uint8_t> &data);

    /* *
     * @brief 将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     * @param clientData 用户数据
     * @param buffer 传输数据
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t RequestQueue(const UsbDev &dev,
                                const UsbPipe &pipe,
                                const std::vector<uint8_t> &clientData,
                                const std::vector<uint8_t> &buffer);

    /* *
     * @brief 等待RequestQueue异步请求的操作结果
     *
     * @param dev usb设备地址信息
     * @param clientData 用户数据
     * @param buffer 传输数据
     * @param timeout 超时时间
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t
        RequestWait(const UsbDev &dev, std::vector<uint8_t> &clientData, std::vector<uint8_t> &buffer, int32_t timeout);

    /* *
     * @brief 取消待处理的数据请求
     *
     * @param dev usb设备地址信息
     * @param pipe usb设备pipe信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t RequestCancel(const UsbDev &dev, const UsbPipe &pipe);

    /* *
     * @brief 获取从设备支持的功能列表（按位域表示）（从设备）
     *
     * @param funcs 获取当前设备的function的值
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t GetCurrentFunctions(int32_t &funcs);

    /* *
     * @brief 设置从设备支持的功能列表（按位域表示）（从设备）
     *
     * @param funcs 传入设备支持的function的值
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t SetCurrentFunctions(int32_t funcs);

    /* *
     * @brief 关闭设备，释放与设备相关的所有系统资源
     *
     * @param portId port接口 ID
     * @param powerRole 电源角色的值
     * @param dataRole 数据角色的值
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t SetPortRole(int32_t portId, int32_t powerRole, int32_t dataRole);

    /* *
     * @brief 查询port端口的当前设置
     *
     * @param portId port接口 ID
     * @param powerRole 电源角色的值
     * @param dataRole 数据角色的值
     * @param mode 模式的值
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static int32_t QueryPort(int32_t &portId, int32_t &powerRole, int32_t &dataRole, int32_t &mode);

    /* *
     * @brief 绑定订阅者
     *
     * @param subscriber 订阅者信息
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static ErrCode BindUsbdSubscriber(const sptr<UsbdSubscriber> &subscriber);

    /* *
     * @brief 解绑订阅者
     *
     * @return 0 表示成功，其他返回值表示失败
     * @since 3.0
     */
    static ErrCode UnbindUsbdSubscriber();

private:
    static void PrintBuffer(const char *title, const uint8_t *buffer, uint32_t length);
    static int32_t SetDeviceMessage(MessageParcel &data, const UsbDev &dev);
    static int32_t SetBufferMessage(MessageParcel &data, const std::vector<uint8_t> &tdata);
    static int32_t GetBufferMessage(MessageParcel &data, std::vector<uint8_t> &tdata);
    static sptr<IRemoteObject> GetUsbdService();
    static ErrCode DoDispatch(uint32_t cmd, MessageParcel &data, MessageParcel &reply);
};
} // namespace USB
} // namespace OHOS
#endif // USBD_CLIENT_H
