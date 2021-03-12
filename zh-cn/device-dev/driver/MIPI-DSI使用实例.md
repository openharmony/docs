# MIPI DSI使用实例<a name="ZH-CN_TOPIC_0000001062724697"></a>

MIPI-DSI完整的使用示例如下所示：

```
#include "hdf.h"
#include "mipi_dsi_if.h"

void PalMipiDsiTestSample(void)
{
    uint8_t chnId;
    int32_t ret;  
    DevHandle handle = NULL;
    
    /* 设备通道编号 */
    chnId = 0; 
    /* 获取操作句柄 */
    handle = MipiDsiOpen(chnId);
    if (handle == NULL) {
        HDF_LOGE("MipiDsiOpen: failed!\n");
        return;
    }
    /* 配置相应参数 */
    struct MipiCfg cfg = {0};
    cfg.lane = DSI_4_LANES;
    cfg.mode = DSI_CMD_MODE;
    cfg.burstMode = VIDEO_NON_BURST_MODE_SYNC_EVENTS;
    cfg.format = FORMAT_RGB_24_BIT;
    cfg.pixelClk = 174;                      
    cfg.phyDataRate = 384;                 
    cfg.timingInfo.hsaPixels = 50;
    cfg.timingInfo.hbpPixels = 55;
    cfg.timingInfo.hlinePixels = 1200;
    cfg.timingInfo.yResLines = 1800;
    cfg.timingInfo.vbpLines = 33;
    cfg.timingInfo.vsaLines = 76;
    cfg.timingInfo.vfpLines = 120;
    cfg.timingInfo.xResPixels = 1342;
    /* 写入配置数据 */
    ret = MipiDsiSetCfg(g_handle, &cfg);
    if (ret != 0) {
        HDF_LOGE("%s: SetMipiCfg fail! ret=%d\n", __func__, ret);
        return;
    }
    /* 发送PANEL初始化指令 */
    struct DsiCmdDesc *cmd = OsalMemCalloc(sizeof(struct DsiCmdDesc));
    if (cmd == NULL) {
        return;
    }
    cmd->dtype = DTYPE_DCS_WRITE;
    cmd->dlen = 1;
    cmd->payload = OsalMemCalloc(sizeof(uint8_t));
    if (cmd->payload == NULL) {
        HdfFree(cmd);
        return;
    }
    *(cmd->payload) = DTYPE_GEN_LWRITE;
    MipiDsiSetLpMode(mipiHandle);
    ret = MipiDsiTx(mipiHandle, cmd);
    MipiDsiSetHsMode(mipiHandle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: MipiDsiTx fail! ret=%d\n", __func__, ret);
        HdfFree(cmd->payload);
        HdfFree(cmd);
        return;
    }
    HdfFree(cmd->payload);
    HdfFree(cmd);
    /* 回读panel状态寄存器 */
    uint8_t readVal = 0;
    struct DsiCmdDesc *cmdRead = OsalMemCalloc(sizeof(struct DsiCmdDesc));
    if (cmdRead == NULL) {
        return;
    }
    cmdRead->dtype = DTYPE_DCS_READ;
    cmdRead->dlen = 1;
    cmdRead->payload = OsalMemCalloc(sizeof(uint8_t));
    if (cmdRead->payload == NULL) {
        HdfFree(cmdRead);
        return;
    }
    *(cmdRead->payload) = DDIC_REG_STATUS;
    MipiDsiSetLpMode(g_handle);
    ret = MipiDsiRx(g_handle, cmdRead, sizeof(readVal), &readVal);
    MipiDsiSetHsMode(g_handle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: MipiDsiRx fail! ret=%d\n", __func__, ret);
        HdfFree(cmdRead->payload);
        HdfFree(cmdRead);
        return;
    }
    HdfFree(cmdRead->payload);
    HdfFree(cmdRead);
    /* 释放MIPI DSI设备句柄 */
    MipiDsiClose(handle); 
}
```

