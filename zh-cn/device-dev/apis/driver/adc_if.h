/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 *
 * HDF is dual licensed: you can use it either under the terms of
 * the GPL, or the BSD license, at your option.
 * See the LICENSE file in the root of this repository for complete details.
 */

/**
 * @addtogroup ADC
 * @{
 *
 * @brief 定义用于模/数转换器驱动程序开发的标准ADC API。
 * 此ADC模块抽象了不同系统平台的ADC功能，以提供稳定的API，用于模/数转换器驱动程序开发。您可以使用此模块获取/释放ADC设备句柄。
 *
 * @since 1.0
 */

/**
 * @file adc_if.h
 *
 * @brief 声明标准ADC接口函数。
 *
 * @since 1.0
 */

#ifndef ADC_IF_H
#define ADC_IF_H

#include "hdf_platform.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

struct AdcIoMsg {
    /** ADC设备号 */
    uint32_t number;
    /** ADC设备通道号 */
    uint32_t channel;
};

/**
 * @brief 获取ADC设备的句柄。
 * 在访问ADC设备之前，必须调用此函数。
 *
 * @param number ADC设备ID。
 *
 * @return 如果操作成功，则返回指向ADC设备的DevHandle的指针；否则返回NULL。
 *
 * @since 1.0
 */
DevHandle AdcOpen(uint32_t number);

 /**
 * @brief 释放ADC设备的句柄。
 * 如果不再需要访问ADC设备，则应调用此函数关闭其句柄，以便释放未使用的内存资源。
 *
 * @param handle 指向通过{@link AdcOpen}获得的ADC设备的设备句柄的指针。
 *
 * @since 1.0
 */
void AdcClose(DevHandle handle);

/**
 * @brief 从ADC设备读取指定大小的数据。
 *
 * @param handle 指向通过{@link AdcOpen}获得的ADC设备的设备句柄的指针。
 * @param channel ADC设备通道。
 * @param val 指向存储读出数据指针。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 * @since 1.0
 */
int32_t AdcRead(DevHandle handle, uint32_t channel, uint32_t *val);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* ADC_IF_H */
