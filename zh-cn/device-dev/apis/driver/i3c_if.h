/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 *
 * HDF is dual licensed: you can use it either under the terms of
 * the GPL, or the BSD license, at your option.
 * See the LICENSE file in the root of this repository for complete details.
 */

/**
 * @addtogroup I3C
 * @{
 *
 * @brief 提供改进的Improved Inter-Integrated Circuit (I3C)接口。
 * 该模块允许驱动程序在I3C控制器上执行操作，以访问I3C总线上的设备。
 * 包括创建和销毁I3C控制器句柄以及读取和写入数据。
 *
 * @since 1.0
 */

/**
 * @file i3c_if.h
 *
 * @brief 声明标准I3C接口函数。
 *
 * @since 1.0
 */

#ifndef I3C_IF_H
#define I3C_IF_H

#include "hdf_platform.h"
#include "i3c_ccc.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

enum TransMode {
    /** I2C传输模式 */
    I2C_MODE = 0,
    /** I3C传输模式 */
    I3C_MODE,
    /** CCC（通用命令代码）模式 */
    CCC_CMD_MODE,
};

enum I3cBusMode {
    /** 单数据速率模式 */
    I3C_BUS_SDR_MODE = 0,
    /** 高数据速率模式 */
    I3C_BUS_HDR_MODE,
};

/**
 * @brief 定义I3C控制器的配置。
 *
 * @since 1.0
 */
struct I3cConfig {
    /** I3C总线模式 */
    enum I3cBusMode busMode;
    /** 当前主设备，当控制器是主设备时，其为NULL  */
    struct I3cDevice *curMaster;  
};

/**
 * @brief 定义I3C传输、I2C传输或发送CCC（通用命令代码）期间使用的I3C传输消息。
 *
 * @attention 此结构不限制len指定的数据传输长度，允许的最大长度由特定控制器确定。
 * 设备地址addr表示原始设备地址，不需要包含读/写标志位。
 * @since 1.0
 */
struct I3cMsg {
    /** 目标设备的地址 */
    uint16_t addr;
    /** 用于存储传输数据的缓冲区地址 */
    uint8_t *buf;
    /** 传输数据的长度 */
    uint16_t len;
    /**
     * 传输模式标志 | 说明
     * ------------| -----------------------
     * I2C_FLAG_READ | 读标志
     * I2C_FLAG_READ_NO_ACK | 无确认读取标志
     * I2C_FLAG_IGNORE_NO_ACK | 忽略无确认标志
     * I2C_FLAG_NO_START | 无启动条件标志
     * I2C_FLAG_STOP | 停止条件标志
     */
    uint16_t flags;
    /** 传输模式选择，默认为I2C_MODE */
    enum TransMode mode;
    /** CCC（通用命令代码）结构，用于CCC_CMD_MODE传输模式 */
    struct I3cCccCmd *ccc;
    /** I3C错误代码，由驱动程序更新 */
    uint16_t err;
};

/**
 * @brief 定义I3C IBI（带内中断）的数据。
 *
 * @attention 生成IBI时，IBI函数中的有效载荷和buf可获得IBI数据。
 *
 * @since 1.0
 */
struct I3cIbiData {
    /** 有效载荷数据长度。IBI有效负载数据的长度。当IBI已生成，读取时请勿修改。 */
    uint32_t payload;
    /** 数据缓冲区。有效负载数据的指针。 */
    uint8_t *buf;
};

enum I3cFlag {
    /** 读标志。值1表示读取操作，0表示写入操作。 */
    I3C_FLAG_READ           = (0x1 << 0),
    /** 无ACK读标志。值1表示在读取过程中没有发送ACK信号。 */
    I3C_FLAG_READ_NO_ACK    = (0x1 << 11),
    /** 忽略ACK标志。值1表示忽略非ACK信号。 */
    I3C_FLAG_IGNORE_NO_ACK  = (0x1 << 12),
    
    /** 无启动条件标志。值1表示消息没有启动条件转移。 */
    I3C_FLAG_NO_START       = (0x1 << 14),
    /** 停止条件标志。值1表示当前传输以停止条件结束。 */
    I3C_FLAG_STOP           = (0x1 << 15),
};

/**
 * @brief IBI（带内中断）回调函数。
 * 使用{@link I3cRequestIbi}将其连接到I3C设备。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 * @param addr 重新设置IBI（带内中断）的设备地址。
 * @param data IBI的数据结构。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 * @since 1.0
 */
typedef int32_t (*I3cIbiFunc)(DevHandle handle, uint16_t addr, struct I3cIbiData data);

/**
 * @brief 获取I3C控制器的句柄。
 * 在访问I3C总线之前，必须调用此函数。
 *
 * @param number I3C控制器ID。
 *
 * @return 如果操作成功，则返回指向I3C控制器的DevHandle的指针；否则返回NULL。
 *
 * @since 1.0
 */
DevHandle I3cOpen(int16_t number);

 /**
 * @brief 释放I3C控制器的句柄。
 * 如果不再需要访问I3C控制器，则应调用此函数关闭其句柄，以便释放未使用的内存资源。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 *
 * @since 1.0
 */
void I3cClose(DevHandle handle);

 /**
 * @brief 启动到I3C设备或兼容的I2C设备的传输,或者向支持的I3C设备发送CCC（通用命令代码）。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 * @param msg 指向I3C传输消息结构数组的指针。
 * @param count 消息结构数组的长度。
 * @param mode 传输模式。
 *
 * @return 如果操作成功，返回传输的消息结构数；
 * @see I3cMsg
 * @attention 此结构不限制len指定的数据传输长度。 特定的 I3C 控制器决定了允许的最大长度。 设备地址addr表示原始设备地址，不需要包含读/写标志位。
 *
 * @since 1.0
 */
int32_t I3cTransfer(DevHandle handle, struct I3cMsg *msg, int16_t count, enum TransMode mode);

 /**
 * @brief 重新设置受支持的I3C设备的IBI（带内中断）。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 * @param addr 重新设置IBI（带内中断）的设备地址。
 * @param func IBI回调函数。
 * @param payload 有效负载数据的长度，以字节为单位。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t I3cRequestIbi(DevHandle handle, uint16_t addr, I3cIbiFunc func, uint32_t payload);

 /**
 * @brief 释放{@link I3cRequestIbi}重新设置的IBI（带内中断）。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 * @param addr 要释放IBI的设备的地址。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t I3cFreeIbi(DevHandle handle, uint16_t addr);

 /**
 * @brief 设置I3C控制器的配置。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 * @param config 要设置的配置结构的指针。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t I3cSetConfig(DevHandle handle, struct I3cConfig *config);

 /**
 * @brief 获取I3C控制器的配置。
 *
 * @param handle 指向通过{@link I3cOpen}获得的I3C控制器句柄的指针。
 * @param config 用于存储配置的结构体。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t I3cGetConfig(DevHandle handle, struct I3cConfig *config);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* I3C_IF_H */
/** @} */
