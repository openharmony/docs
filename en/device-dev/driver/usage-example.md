# Usage Example<a name="EN-US_TOPIC_0000001062724697"></a>

The following is an example of using a MIPI DSI device:

```
#include "hdf.h"
#include "mipi_dsi_if.h"

void PalMipiDsiTestSample(void)
{
    uint8_t chnId;
    int32_t ret;  
    DevHandle handle = NULL;
    
    /* Device channel ID */
    chnId = 0; 
    /* Obtain the MIPI DSI device handle based on a specified channel ID. */
    handle = MipiDsiOpen(chnId);
    if (handle == NULL) {
        HDF_LOGE("MipiDsiOpen: failed!\n");
        return;
    }
    /* MIPI DSI configuration parameters */
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
    /* Set MIPI DSI configuration parameters. */
    ret = MipiDsiSetCfg(g_handle, &cfg);
    if (ret != 0) {
        HDF_LOGE("%s: SetMipiCfg fail! ret=%d\n", __func__, ret);
        return;
    }
    /* Send the command for initializing the PANEL register. */
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
    /* Pointer to the register that reads the PANEL status */
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
    /* Release the MIPI DSI device handle. */
    MipiDsiClose(handle); 
}
```

