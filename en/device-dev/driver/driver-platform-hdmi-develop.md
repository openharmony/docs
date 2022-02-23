# HDMI 

## Overview<a name="1"></a>

The High-Definition Multimedia Interface (HDMI) is an audio/video transmission protocol released by Hitachi, Panasonic, Philips, SiliconImage, Sony, Thomson and Toshiba. It is used to transmit audio or video data from an audio or video source device, such as a DVD player or STB, to a sink device, such as a TV or monitor. The transmission process complies with the Transition Minimized Differential Signaling (TMDS) protocol.

In the HDF, the HDMI module uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to process external access requests. After receiving an access request, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDFDeviceManager can be directly used. However, you need to configure a node for each device, which increases the memory usage.

 **Figure 1** Independent service mode<a name="fig1"></a>

![image1](figures/independent-service-mode.png)

## How to Develop<a name="2"></a>

The HDMI module adaptation involves the following steps:

1. Instantiate the driver entry.
    - Instantiate the **HdfDriverEntry** structure.
    - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
    - Add the **deviceNode** information to the **device_info.hcs** file.
    - (Optional) Add the **hdmi_config.hcs** file.

3. Instantiate the HDMI controller object.
    - Initialize **HdmiCntlr**.
    - Instantiate **HdmiCntlrOps** in **HdmiCntlr**. For details, see the following description of **HdmiCntlrOps**.

    HdmiCntlrOps:
    ```c
    struct HdmiCntlrOps {
        void (*hardWareInit)(struct HdmiCntlr *cntlr);
        void (*hardWareStatusGet)(struct HdmiCntlr *cntlr, struct HdmiHardwareStatus *status);
        void (*controllerReset)(struct HdmiCntlr *cntlr);
        bool (*hotPlugStateGet)(struct HdmiCntlr *cntlr);
        bool (*hotPlugInterruptStateGet)(struct HdmiCntlr *cntlr);
        void (*lowPowerSet)(struct HdmiCntlr *cntlr, bool enable);
        void (*tmdsModeSet)(struct HdmiCntlr *cntlr, enum HdmiTmdsModeType mode);
        int32_t (*tmdsConfigSet)(struct HdmiCntlr *cntlr, struct HdmiTmdsConfig mode);
        void (*infoFrameEnable)(struct HdmiCntlr *cntlr, enum HdmiPacketType infoFrameType, bool enable);
        int32_t (*infoFrameSend)(struct HdmiCntlr *cntlr, enum HdmiPacketType infoFrameType, uint8_t *data, uint32_t len);
        int32_t (*infoFrameDataSet)(struct HdmiCntlr *cntlr, uint32_t type, uint8_t *data, uint32_t len);
        int32_t (*cecMsgSend)(struct HdmiCntlr *cntlr, struct HdmiCecMsg *msg);
        void (*audioPathEnable)(struct HdmiCntlr *cntlr, bool enable);
        void (*audioPathSet)(struct HdmiCntlr *cntlr, struct HdmiAudioConfigInfo *config);
        void (*phyOutputEnable)(struct HdmiCntlr *cntlr, bool enable);
        void (*phyOutputSet)(struct HdmiCntlr *cntlr, struct HdmiPhyCfg *cfg);
        void (*blackDataSet)(struct HdmiCntlr *cntlr, bool enable);
        void (*videoMuteEnable)(struct HdmiCntlr *cntlr, bool enable);
        void (*videoPathSet)(struct HdmiCntlr *cntlr, struct HdmiVideoAttr *attr);
        void (*audioMuteEnable)(struct HdmiCntlr *cntlr, bool enable);
        void (*avmuteSet)(struct HdmiCntlr *cntlr, bool enable);
        int32_t (*ddcTransfer)(struct HdmiCntlr *cntlr, struct HdmiDdcCfg *ddcCfg);
        bool (*scdcSourceScrambleGet)(struct HdmiCntlr *cntlr);
        int32_t (*scdcSourceScrambleSet)(struct HdmiCntlr *cntlr, bool enable);
        void (*frlSet)(struct HdmiCntlr *cntlr);
        int32_t (*frlEnable)(struct HdmiCntlr *cntlr, bool enable);
        int32_t (*audioNctsSet)(struct HdmiCntlr *cntlr, struct HdmiFrlAudioNctsConfig *cfg);
        void (*frlTrainingConfigSet)(struct HdmiCntlr *cntlr, struct HdmiFrlTrainConfig *cfg);
        void (*frlTrainingStart)(struct HdmiCntlr *cntlr);
        void (*frlGetTriningRslt)(struct HdmiCntlr *cntlr, struct HdmiFrlTrainRslt *rslt);
        void (*hdcpRegInit)(struct HdmiCntlr *cntlr);
        int32_t (*hdcpGenerateAksvAndAn)(struct HdmiCntlr *cntlr);
        int32_t (*hdcpOptReg)(struct HdmiCntlr *cntlr, enum HdmiHdcpRegOptType type, uint8_t *data, uint32_t len);
        void (*hdrTimerSet)(struct HdmiCntlr *cntlr, struct HdmiHdrTimerConfig *config);
    };
    ```

    **Table 1** Callbacks for the members in the HdmiCntlrOps structure

   | Function Member| Input Parameter| Output Parameter| Return Value| Description|
   | ------------------------ | ------------------------------------------------------------ | -------------------------------------- | ------------------ | -------------------------------------------------- |
   | hardWareInit             | **cntlr**: structure pointer to an HDMI controller at the core layer.| –| –| Initializes HDMI hardware.|
   | hardWareStatusGet        | **cntlr**: structure pointer to an HDMI controller at the core layer. <br />| **status**: HDMI hardware status.| –| Obtains the HDMI hardware status.|
   | controllerReset          | **cntlr**: structure pointer to an HDMI controller at the core layer.| –| –| Resets an HDMI controller.|
   | hotPlugStateGet          | **cntlr**: structure pointer to an HDMI controller at the core layer.| -| **bool**: HDMI hot-plug status.| Obtains the HDMI hot-plug status.|
   | hotPlugInterruptStateGet | **cntlr**: structure pointer to an HDMI controller at the core layer.| –| **bool**: HDMI hot-plug interrupt status.| Obtains the HDMI hot-plug interrupt status.|
   | lowPowerSet              | **cntlr**: structure pointer to an HDMI controller at the core layer.<br /> **enable**: whether low power consumption is enabled.| –| –| Enables or disables low power consumption.|
   | tmdsModeSet              | **cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **mode**: TMDS mode.| –| –| Set the TMDS mode.|
   |tmdsConfigSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **mode**: TMDS mode parameters.|–|HDF_STATUS|Sets TMDS parameters.|
   |infoFrameEnable|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **infoFrameType**: packet type.  <br /> **enable**: whether infoFrame is enabled.|–|–|Enables or disables infoFrame.|
   |infoFrameSend|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **infoFrameType**: packet type. <br /> **data**: infoFrame data. <br /> **len**: data length.|–|HDF_STATUS|Sends an infoFrame.|
   |cecMsgSend|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **msg**: Consumer Electronics Control (CEC) message.|–|HDF_STATUS|Sends a CEC message.|
   |audioPathEnable|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether the audio path is enabled.|–|–|Enables or disables the audio path.|
   |audioPathSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **config**: audio path configuration.|–|–|Sets the audio path.|
   |phyOutputEnable|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether the physical layer output is enabled.|–|–|Enables or disables the physical layer output.|
   |phyOutputSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **cfg**: physical layer configuration.|–|–|Sets the physical layer information.|
   |blackDataSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether the black screen is enabled.|–|–|Sets the black screen.|
   |videoMuteEnable|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether the video mute feature is enabled.|–|–|Enables or disables the video mute feature.|
   |videoPathSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **attr**: configuration.|–|–|Sets the video path.|
   |audioMuteEnable|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether the audio mute feature is enabled.|–|–|Enables or disables the audio mute feature.|
   |avmuteSet|**cntlr**: structure pointer to an HDMI controller at the core layer.<br /> **enable**: whether the AV mute feature is enabled.|–|–|Enables or disables the AV mute feature.|
   |ddcTransfer|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **ddcCfg**: DDC configuration.|**ddcCfg**: DDC configuration.|HDF_STATUS|Reads and writes data through the display data channel (DDC).|
   |scdcSourceScrambleGet|**cntlr**: structure pointer to an HDMI controller at the core layer.|–|Scrambling status of the source.|Obtains the scrambling status of the source.|
   |scdcSourceScrambleSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether scrambling is enabled for the source.|–|HDF_STATUS|Enables or disable scrambling for the source.|
   |frlEnable|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **enable**: whether fixed rate link (FRL) is enabled.|–|HDF_STATUS|Enables or disables the FRL.|
   |audioNctsSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **cfg**: N/CTS configuration.|–|HDF_STATUS|Sets the audio N/CTS information.|
   |frlTrainingConfigSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **cfg**: FRL training configuration.|–|–|Sets FRL training information.|
   |frlTrainingStart|**cntlr**: structure pointer to an HDMI controller at the core layer.|–|–|Starts FRL training.|
   |frlGetTriningRslt|**cntlr**: structure pointer to an HDMI controller at the core layer.|**rslt**: FRL training result.|–|Obtains the FRL training result.|
   |hdcpRegInit|**cntlr**: structure pointer to an HDMI controller at the core layer.|–|–|Initializes registers related to the High-bandwidth Digital Content Protection (HDCP) process.|
   |hdcpGenerateAksvAndAn|**cntlr**: structure pointer to an HDMI controller at the core layer.|–|HDF_STATUS|Generates the **Aksv** and **An** in the HDCP process.|
   |hdcpOptReg|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **type**: operation type. <br /> **data**: register data. <br /> **len**: data length.|**data**: register data.|HDF_STATUS|Reads or writes the registers in the HDCP process.|
   |hdrTimerSet|**cntlr**: structure pointer to an HDMI controller at the core layer. <br /> **config**: timer configuration.|–|–|Sets the HDR-related timer.|

## Development Example<a name="3"></a>

1. Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers are collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

    HDMI driver entry reference:

    ```c
    struct HdfDriverEntry g_hdmiDriverEntry = {
        .moduleVersion = 1,
        .Bind = HdmiAdapterBind,
        .Init = HdmiAdapterInit,
        .Release = HdmiAdapterRelease,
        .moduleName = "adapter_hdmi_driver",// (mandatory) The value must be the same as that in the .hcs file.
    };
    HDF_INIT(g_hdmiDriverEntry);            // Call HDF_INIT to register the driver entry with the HDF.
    ```

2. Add **deviceNode** to the **device_info.hcs** file, and configure the device attributes in the **hdmi_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the driver implementation and the default values or restriction ranges of the **HdmiCntlr** members at the core layer.

    Configure HDMI controller information from the second node. This node specifies a type of HDMI controllers rather than a specific HDMI controller. In this example, there is only one HDMI controller. If there are multiple HDMI controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **hdmi_config** file.

    - **device_info.hcs** configuration reference

        ```c
        root {
            platform :: host {
                 device_hdmi :: device {
                    device0 :: deviceNode {
                        policy = 2;         // The value 2 means to publish a service.
                        priority = 20;     // Driver startup priority.
                        permission = 0644; // Permission to create device nodes for the driver.
                        serviceName = "HDF_PLATFORM_HDMI_0"; // (Mandatory) Unique name of the service published by the driver.
                        moduleName = "hdmi_driver";         // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                        deviceMatchAttr = "adapter_hdmi_driver"; // (Mandatory) Controller private data, which must be same as that of the corresponding controller in hdmi_config.hcs.
                    }                                             // The specific controller information is in hdmi_config.hcs.
                 }
            }
        }
        ```

    - **hdmi_config.hcs** configuration reference

        ```c
         root {
             platform {
                hdmi_config {
                    template hdmi_controller {    // Template configuration. In the template, you can configure the common parameters shared by service nodes.
                        match_attr = "";            // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                        index = 0;                 // (Mandatory) HDMI controller number.
                        regBasePhy = 0x10100000; // (Mandatory) Physical base address of the register.
                        regSize = 0xd1;            // (Mandatory) Register bit width.
                        irqNum = 100;            //(Mandatory) Interrupt request (IRQ) number.
                        maxTmdsClock = 300;
                        videoTiming = 10;
                        quantization = 1;
                        colorSpace = 0;
                        colorimetry = 0;
                        audioIfType = 0;
                        audioBitDepth = 1;
                        audioSampleRate = 2;
                        audioChannels = 1;
                        hdrColorimetry = 4;
                        hdrUserMode = 1;
                        cap = 0xd001e045;
                    }
                    controller_0x10100000 :: hdmi_controller {
                        match_attr = "adapter_hdmi_driver";
                        index = 0;
                        regBasePhy = 0x10100000;
                        irqNum = 100;
                        maxTmdsClock = 400;
                        defTmdsClock = 300;
                        maxFrlRate = 600;
                        videoTiming = 10;
                        quantization = 1;
                        colorSpace = 0;
                        colorimetry = 0;
                        audioIfType = 0;
                        audioSampleRate = 2;
                        audioChannels = 1;
                        hdrColorimetry = 4;
                        hdrUserMode = 1;
                        cap = 0xd001e045;
                    }
                }
            }
        }
        ```

3. Initialize the **HdmiCntlr** object at the core layer, including initializing the vendor custom structure (transferring parameters and data) and instantiating the **HdmiCntlrOps** (used to call the underlying functions of the driver). The **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) must be implemented in this step.
   
    - Custom structure reference
    
        > ![](../public_sys-resources/icon-note.gif) **NOTE:**
        > To the driver, the custom structure carries parameters and data. The values in the **hdmi_config.hcs** file are read by the HDF, and structure members are initialized by **DeviceResourceIface**. Some important values (such as the device number and bus number) are also passed to the **HdmiCntlr** object of the core layer.

        ```c
        struct HdmiAdapterHost {
            struct HdmiCntlr *cntlr;        // (Mandatory) Control object of the core layer. The details are as follows:
            volatile unsigned char *regBase;// (Mandatory) Register base address.
            uint32_t regBasePhy            // (Mandatory) Physical base address of the register.
            uint32_t regSize;               // (Mandatory) Register bit width.
            uint32_t irqNum;                // (Mandatory) IRQ number.
        };
    
        /* HdmiCntlr is the controller structure at the core layer. Its members are assigned with values by using the Init function. */
        struct HdmiCntlr {
            struct IDeviceIoService service;
            struct HdfDeviceObject *hdfDevObj;
            struct PlatformDevice device;
            struct OsalMutex mutex;
            struct PlatformQueue *msgQueue;
            struct HdmiCntlrCap cap;
            struct HdmiAttr attr;
            struct HdmiCntlrOps *ops;
            uint32_t deviceIndex;
            uint32_t state;                 // Controller status.
            enum HdmiTmdsModeType tmdsMode;
            struct HdmiDevice *hdmi;
            struct HdmiInfoframe infoframe;
            struct HdmiScdc *scdc;
            struct HdmiDdc ddc;
            struct HdmiFrl *frl;
            struct HdmiHdcp *hdcp;
            struct HdmiCec *cec;
            struct HdmiEvent event;
            struct HdmiHdr *hdr;
            void *priv;
        };
        ```

    - **(Important)** Instantiate the callback structure **HdmiCntlrOps** in **HdmiCntlr**. 

        ```c 
        static struct HdmiCntlrOps g_hdmiAdapterHostOps = {
            .hardWareInit = HdmiAdapterHardWareInit,
            .hardWareStatusGet = HdmiAdapterHardWareStatusGet,
            .controllerReset = HdmiAdapterControllerReset,
            .hotPlugStateGet = HdmiAdapterHotPlugStateGet,
            .hotPlugInterruptStateGet = HdmiAdapterHotPlugInterruptStateGet,
            .lowPowerSet = HdmiAdapterLowPowerSet,
            .tmdsModeSet = HdmiAdapterTmdsModeSet,
            .tmdsConfigSet = HdmiAdapterTmdsConfigSet,
            .infoframeEnable = HdmiAdapterInfoframeEnable,
            .infoframeSend = HdmiAdapterInfoframeSend,
            .infoframeDataSet = HdmiAdapterInfoframeDataSet,
            .cecMsgSend = HdmiAdapterCecMsgSend,
            .audioPathEnable = HdmiAdapterAudioPathEnable,
            .audioPathSet = HdmiAdapterAudioPathSet,
            .phyOutputEnable = HdmiAdapterPhyOutputEnable,
            .phyOutputSet = HdmiAdapterPhyOutputSet,
            .blackDataSet = HdmiAdapterBlackDataSet,
            .videoMuteEnable = HdmiAdapterVideoMuteEnable,
            .videoPathSet = HdmiAdapterVideoPathSet,
            .audioMuteEnable = HdmiAdapterAudioMuteEnable,
            .avmuteSet = HdmiAdapterAvmuteSet,
            .ddcTransfer = HdmiAdapterDdcTransfer,
            .scdcSourceScrambleGet = HdmiAdapterScdcSourceScrambleGet,
            .scdcSourceScrambleSet = HdmiAdapterScdcSourceScrambleSet,
            .frlSet = HdmiAdapterFrlSet,
            .frlEnable = HdmiAdapterFrlEnable,
            .audioNctsSet = HdmiAdapterAudioNctsSet,
            .frlTrainingConfigSet = HdmiAdapterFrlTrainingConfigSet,
            .frlTrainingStart = HdmiAdapterFrlTrainingStart,
            .frlGetTriningRslt = HdmiAdapterFrlGetTriningRslt,
            .hdcpRegInit = HdmiAdapterHdcpRegInit,
            .hdcpGenerateAksvAndAn = HdmiAdapterHdcpGenerateAksvAndAn,
            .hdcpOptReg = HdmiAdapterHdcpOptReg,
            .hdrTimerSet = HdmiAdapterHdrTimerSet,
        };
        ```
    
    - **Bind function**
    
        > **Input parameter**:
        >  **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.
        > 
        > **Return value**
        > **HDF_STATUS** (The following table lists some states. For more details, see **HDF_STATUS** definition in the **/drivers/framework/include/utils/hdf_base.h file**.)
    
        |State (Value)|Status|
        |:-|:-|
        |HDF_ERR_INVALID_OBJECT|Invalid controller object.|
        |HDF_ERR_INVALID_PARAM |Invalid parameter.|
        |HDF_ERR_MALLOC_FAIL   |Failed to allocate memory.|
        |HDF_ERR_IO            |I/O error.|
        |HDF_SUCCESS           |Transmission successful.|
        |HDF_FAILURE           |Transmission failed.|
    
        > **Function description:**
        > Initializes the custom structure object **HdmiAdapterHost** and **HdmiCntlr**, and calls the **HdmiCntlrAdd** function to add the HDMI controller to the core layer.
        >
        > The **HdmiCntlr**, **HdmiAdapterHost**, and **HdfDeviceObject** assign values with each other so that other functions can be converted successfully.
    
        ```c
        static int32_t HdmiAdapterBind(struct HdfDeviceObject *obj)
        {
            struct HdmiCntlr *cntlr = NULL;
            struct HimciAdapterHost *host = NULL;
            int32_t ret;
            cntlr = (struct HdmiCntlr *)OsalMemCalloc(sizeof(struct HdmiCntlr));
            if (cntlr == NULL) {
                HDF_LOGE("%s: malloc cntlr failed!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            host = (struct HimciAdapterHost *)OsalMemCalloc(sizeof(struct HimciAdapterHost));
            if (host == NULL) {
                HDF_LOGE("%s: malloc host failed!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            cntlr->priv = (void *)host;     // (Mandatory) Store host to the private data of cntlr.
            cntlr->ops = &g_hdmiHostOps;     // (Mandatory) Connect to the HdmiCntlrOps instance.
            cntlr->hdfDevObj = obj;          // (Mandatory) Prerequisites for conversion between HdfDeviceObject and HdmiCntlr.
            obj->service = &cntlr->service; // (Mandatory) Prerequisites for conversion between HdfDeviceObject and HdmiCntlr.
            ret = HdmiAdapterCntlrParse(cntlr, obj); // (Mandatory) Initialize cntlr. If the operation fails, execute goto__ERR.
            ... 
            ret = HdmiAdapterHostParse(host, obj); // (Mandatory) Initialize the attributes of the host object. If the initialization fails, execute goto__ERR.
            ...
            ret = HdmiAdapterHostInit(host, cntlr);  // Perform vendor custom initialization. If the initialization fails, execute goto __ERR.
            ...
            ret = HdmiCntlrAdd(cntlr);              // Call the function at the core layer. If the operation fails, execute goto__ERR.
            ...
            HDF_LOGD("HdmiAdapterBind: success.");
            return HDF_SUCCESS;
        __ERR:
            HdmiAdapterDeleteHost(host);
            HDF_LOGD("HdmiAdapterBind: fail, err = %d.", ret);
            return ret;
        }
        ```
    
    - **Init function**
    
        >**Input parameter**:
        >**HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.
        >
        >**Return value**
        >HDF_STATUS
        >
        >Function description:
        >
        >Implements the **HdmiAdapterInit** function.
    
        ```c
        static int32_t HdmiAdapterInit(struct HdfDeviceObject *obj)
        {
            return HDF_SUCCESS;
        }
        ```
    
    - **Release function**
    
        > **Input parameter**:
        > **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.
        >
        > **Return value**
        > –
        > 
        > **Function description:**
        > Releases the memory and deletes the controller. This function assigns a value to the **Release** API in the driver entry structure. When the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.
    
        ```c
        static void HdmiAdapterRelease(struct HdfDeviceObject *obj)
        {
            struct HdmiCntlr *cntlr = NULL;
            ...
            cntlr = (struct MmcCntlr *)obj->service;// Forcibly convert HdfDeviceObject to HdmiCntlr by using service. For details about the value assignment, see the Bind function.
            ...
            HimciDeleteHost((struct HimciAdapterHost *)cntlr->priv);// Memory release function customized by the vendor. A forced conversion from HdmiCntlr to HimciAdapterHost is involved in the process.
        }
        ```
        > All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the corresponding value assignment operations.
