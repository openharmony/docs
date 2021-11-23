/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 *
 * HDF is dual licensed: you can use it either under the terms of
 * the GPL, or the BSD license, at your option.
 * See the LICENSE file in the root of this repository for complete details.
 */

/**
 * @addtogroup MIPI CSI
 * @{
 *
 * @brief 定义用于外设接收端驱动程序开发的标准MIPI CSI API。
 * 此MIPI CSI模块抽象了不同系统平台的MIPI CSI功能，以提供稳定的API。
 * 用于外设接收端驱动程序开发。您可以使用此模块获取/释放MIPI CSI设备句柄。
 *
 * @since 1.0
 */

/**
 * @file mipi_csi_if.h
 *
 * @brief 声明用于显示驱动程序开发的标准MIPI CSI API。
 *
 *
 *
 * @since 1.0
 */

#ifndef MIPI_CSI_IF_H
#define MIPI_CSI_IF_H

#include "hdf_platform.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/**
 * @brief MIPI RX的MIPI设备支持的最大通道数。
 *
 * @since 1.0
 */
#define MIPI_LANE_NUM                4

/**
 * @brief Mipi Rx的LVDS设备支持的最大通道数。
 *
 * @since 1.0
 */
#define LVDS_LANE_NUM                4

/**
 * @brief 定义支持的最大虚拟通道数。
 *
 * @since 1.0
 */
#define WDR_VC_NUM                   4

/**
 * @brief 为LVDS的每个虚拟通道定义同步代码的数量。
 *
 * @since 1.0
 */
#define SYNC_CODE_NUM                4

/**
 * @brief 最多3组扩展数据类型。
 *
 * @since 1.0
 */
#define MAX_EXT_DATA_TYPE_NUM        3

/**
 * @brief Mipi-Rx的通道分布。
 *
 * @since 1.0
 */
typedef enum {
    LANE_DIVIDE_MODE_0 = 0,
    LANE_DIVIDE_MODE_1 = 1,
    LANE_DIVIDE_MODE_BUTT
} LaneDivideMode;

/**
 * @brief MIPI接收输入接口类型。
 *
 * @since 1.0
 */
typedef enum {
    /** mipi */
    INPUT_MODE_MIPI    = 0x0,
    /** SUB_LVDS */
    INPUT_MODE_SUBLVDS = 0x1,
    /** LVDS */
    INPUT_MODE_LVDS    = 0x2,
    /* HISPI */
    INPUT_MODE_HISPI   = 0x3,
    /** CMOS */
    INPUT_MODE_CMOS    = 0x4,
    /** BT601 */
    INPUT_MODE_BT601   = 0x5,
    /** BT656 */
    INPUT_MODE_BT656   = 0x6,
    /** BT1120 */
    INPUT_MODE_BT1120  = 0x7,
    /** MIPI Bypass */
    INPUT_MODE_BYPASS  = 0x8,
    INPUT_MODE_BUTT
} InputMode;

/**
 * @brief MIPI接收速率。
 *
 * @since 1.0
 */
typedef enum {
    /** output 1 pixel per clock */
    MIPI_DATA_RATE_X1 = 0,
    /** output 2 pixel per clock */
    MIPI_DATA_RATE_X2 = 1,
    MIPI_DATA_RATE_BUTT
} MipiDataRate;

/**
 * @brief Mipi图像区域。
 *
 * @since 1.0
 */
typedef struct {
    int x;
    int y;
    unsigned int width;
    unsigned int height;
} ImgRect;

/**
 * @brief 传输的数据类型。
 *
 * @since 1.0
 */
typedef enum {
    DATA_TYPE_RAW_8BIT = 0,
    DATA_TYPE_RAW_10BIT,
    DATA_TYPE_RAW_12BIT,
    DATA_TYPE_RAW_14BIT,
    DATA_TYPE_RAW_16BIT,
    DATA_TYPE_YUV420_8BIT_NORMAL,
    DATA_TYPE_YUV420_8BIT_LEGACY,
    DATA_TYPE_YUV422_8BIT,
    /** YUV422 8位转换用户定义16位原始数据 */
    DATA_TYPE_YUV422_PACKED, 
    DATA_TYPE_BUTT
} DataType;

/**
 * @brief 定义YUV和原始数据格式以及位深度。
 *
 * @since 1.0
 */
typedef struct {
    uint8_t devno;
    unsigned int num;
    unsigned int extDataBitWidth[MAX_EXT_DATA_TYPE_NUM];
    unsigned int extDataType[MAX_EXT_DATA_TYPE_NUM];
} ExtDataType;

/**
 * @brief MIPI D-PHY WDR模式定义。
 *
 * @since 1.0
 */
typedef enum {
    HI_MIPI_WDR_MODE_NONE = 0x0,
    /** Virtual Channel */
    HI_MIPI_WDR_MODE_VC   = 0x1,
    /** Data Type */
    HI_MIPI_WDR_MODE_DT   = 0x2,
    /** DOL Mode */
    HI_MIPI_WDR_MODE_DOL  = 0x3, 
    HI_MIPI_WDR_MODE_BUTT
} MipiWdrMode;

/**
 * @brief Mipi设备属性。
 *
 * @since 1.0
 */
typedef struct {
    /** 数据类型：8/10/12/14/16位 */
    DataType inputDataType;
    /** MIPI WDR模式定义 */
    MipiWdrMode wdrMode;
    /** 通道id: -1 - 禁用 */
    short laneId[MIPI_LANE_NUM];

    union {
        /** 由HI_MIPI_WDR_MODE_DT使用 */
        short dataType[WDR_VC_NUM];
    };
} MipiDevAttr;

/**
 * @brief LVDS WDR模式定义。
 *
 * @since 1.0
 */
typedef enum {
    HI_WDR_MODE_NONE = 0x0,
    HI_WDR_MODE_2F = 0x1,
    HI_WDR_MODE_3F = 0x2,
    HI_WDR_MODE_4F = 0x3,
    HI_WDR_MODE_DOL_2F = 0x4,
    HI_WDR_MODE_DOL_3F = 0x5,
    HI_WDR_MODE_DOL_4F = 0x6,
    HI_WDR_MODE_BUTT
} WdrMode;

/**
 * @brief LVDS同步模式。
 *
 * @since 1.0
 */
typedef enum {
    /** 传感器SOL、EOL、SOF、EOF */
    LVDS_SYNC_MODE_SOF = 0,
    /** SAV, EAV */
    LVDS_SYNC_MODE_SAV,
    LVDS_SYNC_MODE_BUTT
} LvdsSyncMode;

/**
 * @brief LVDS 列同步类型。
 *
 * @since 1.0
 */
typedef enum {
    LVDS_VSYNC_NORMAL   = 0x00,
    LVDS_VSYNC_SHARE    = 0x01,
    LVDS_VSYNC_HCONNECT = 0x02,
    LVDS_VSYNC_BUTT
} LvdsVsyncType;

/**
 * @brief LVDS-Vsync列同步参数。
 *
 * @since 1.0
 */
typedef struct {
    LvdsVsyncType syncType;

    /* 当 sync_type 为 LVDS_VSYNC_HCONNECT 时，需要配置 hblank1 和 hblank2，表示 Hconnect 的消隐区长度 */
    unsigned short hblank1;
    unsigned short hblank2;
} LvdsVsyncAttr;

/**
 * @brief 帧ID类型。
 *
 * @since 1.0
 */
typedef enum {
    LVDS_FID_NONE    = 0x00,
    /** SAV 4th中的帧标识id */
    LVDS_FID_IN_SAV  = 0x01,
    /** 第一个数据中的帧标识id */
    LVDS_FID_IN_DATA = 0x02,
    LVDS_FID_BUTT
} LvdsFidType;

/**
 * @brief 帧ID配置信息。
 *
 * @since 1.0
 */
typedef struct {
    LvdsFidType fidType;

    /** 索尼DOL有帧信息线，在DOL H连接模式下,
        应将此标志配置为false以禁用输出帧信息行。 */
    unsigned char outputFil;
} LvdsFidAttr;

/**
 * @brief 位大小端模式。
 *
 * @since 1.0
 */
typedef enum {
    LVDS_ENDIAN_LITTLE = 0x0,
    LVDS_ENDIAN_BIG = 0x1,
    LVDS_ENDIAN_BUTT
} LvdsBitEndian;

/**
 * @brief LVDS/SUBSLVDS/HiSPi设备属性。
 *
 * @since 1.0
 */
typedef struct {
    /** 数据类型：8/10/12/14位 */
    DataType inputDataType;
    /** 波分复用模式 */
    WdrMode wdrMode;

    /** 同步模式：SOF，SAV */
    LvdsSyncMode syncMode;
    /** 正常、共享、连接 */
    LvdsVsyncAttr vsyncAttr;
    /** 帧识别码 */
    LvdsFidAttr fidAttr;

    /** 数据端：小/大 */
    LvdsBitEndian dataEndian;
    /** 同步代码endian:小/大 */
    LvdsBitEndian syncCodeEndian;
    /** 通道id: -1 - 禁用 */
    short laneId[LVDS_LANE_NUM];

    /** 每个vc有4个参数，syncCode[i]:
        同步模式是SYNC_MODE_SOF:SOF、EOF、SOL、EOL
        同步模式是SYNC_MODE_SAV：无效SAV、无效eav、有效SAV、有效eav */
    unsigned short syncCode[LVDS_LANE_NUM][WDR_VC_NUM][SYNC_CODE_NUM];
} LvdsDevAttr;

/**
 * @brief 组合设备的属性。
 * 组合设备属性，由于 MIPI Rx 能够对接 CSI-2、LVDS、HiSPi 等时序，所以将 MIPI Rx 称为组合设备。
 *
 * @since 1.0
 */
typedef struct {
    /** 设备号 */
    uint8_t devno;
    /** 输入模式：MIPI/LVDS/SUBSLVDS/HISPI/DC */
    InputMode inputMode;
    MipiDataRate dataRate;
    /** MIPI Rx设备裁剪区域（与原始传感器输入图像大小相对应） */
    ImgRect imgRect;

    union {
        MipiDevAttr mipiAttr;
        LvdsDevAttr lvdsAttr;
    };
} ComboDevAttr;

/**
 * @brief 共模电压模式。
 *
 * @since 1.0
 */
typedef enum {
    PHY_CMV_GE1200MV = 0x00,
    PHY_CMV_LT1200MV = 0x01,
    PHY_CMV_BUTT
} PhyCmvMode;

/**
 * @brief 获取具有指定通道ID的MIPI CSI设备句柄。
 *
 * @param id 表示 MIPI CSI通道id。
 *
 * @return 如果操作成功，则返回MIPI CSI设备句柄；否则返回NULL。
 *
 * @since 1.0
 */
DevHandle MipiCsiOpen(uint8_t id);

/**
 * @brief 释放MIPI CSI设备句柄。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 *
 * @since 1.0
 */
void MipiCsiClose(DevHandle handle);

/**
 * @brief 将Mipi、CMOS或LVDS摄像机的参数设置到控制器。
 * 参数包括工作模式、图像面积、图像深度、数据速率和物理通道。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param pAttr 指向属性的指针。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiSetComboDevAttr(DevHandle handle, ComboDevAttr *pAttr);

/**
 * @brief 设置共模电压模式。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param devno 总共有2个设备编号，指向0或1。
 * @param cmvMode 共模电压模式参数。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiSetPhyCmvmode(DevHandle handle, uint8_t devno, PhyCmvMode cmvMode);

/**
 * @brief 复位传感器。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param snsResetSource 传感器的复位信号线号在软件中称为传感器的复位源。
 * sns是传感器的缩写。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiResetSensor(DevHandle handle, uint8_t snsResetSource);

/**
 * @brief 撤销复位传感器。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param snsResetSource 传感器的复位信号线号在软件中称为传感器的复位源。
 * sns是传感器的缩写。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiUnresetSensor(DevHandle handle, uint8_t snsResetSource);

/**
 * @brief 复位 MIPI RX。
 * 不同的s32WorkingViNum有不同的enSnsType。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param comboDev MIPI Rx或者SLVS 设备类型。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiResetRx(DevHandle handle, uint8_t comboDev);

/**
 * @brief 未设置的MIPI RX.
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param comboDev MIPI Rx或者SLVS 设备类型。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiUnresetRx(DevHandle handle, uint8_t comboDev);

/**
 * @brief 设置Mipi Rx的通道分布。
 * 根据硬件连接形式选择具体模式。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param laneDivideMode 通道划分模式参数。
 *
 * @since 1.0
 */
int32_t MipiCsiSetHsMode(DevHandle handle, LaneDivideMode laneDivideMode);

/**
 * @brief 使能mipi的时钟。
 * 根据上层函数电泳传递的enSnsType参数决定是用 MIPI 还是LVDS。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param comboDev MIPI接收或LVDS设备类型。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiEnableClock(DevHandle handle, uint8_t comboDev);

/**
 * @brief 关闭Mipi的时钟。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param comboDev MIPI接收或LVDS设备类型。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiDisableClock(DevHandle handle, uint8_t comboDev);

/**
 * @brief 启用Mipi上的传感器时钟。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param snsClkSource 传感器的时钟信号线号，在软件中称为传感器的时钟源。
 * sns是传感器的缩写。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiEnableSensorClock(DevHandle handle, uint8_t snsClkSource);

/**
 * @brief 关闭传感器时钟。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param snsClkSource 传感器的时钟信号线号，在软件中称为传感器的时钟源。
 * sns是传感器的缩写。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiDisableSensorClock(DevHandle handle, uint8_t snsClkSource);

/**
 * @brief 设置YUV和原始数据格式以及位深度。
 *
 * @param handle 通过{@link MipiCsiOpen}获得的MIPI CSI设备句柄。
 * @param dataType 指向图像数据格式的指针。
 *
 * @return 如果操作成功，则返回0；否则返回负值。
 *
 * @since 1.0
 */
int32_t MipiCsiSetExtDataType(DevHandle handle, ExtDataType* dataType);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* MIPI_CSI_IF_H */
