# 电话服务开发指导


## Modem厂商库初始化开发指导


### 场景介绍

Modem厂商库初始化是指在厂商库里实现const HRilOps \*RilInitOps(const struct HRilReport \*reportOps)函数，在该函数里处理三个重要的功能：

- 接收RIL Adapter事件回调的函数指针，当Modem有业务事件上报时，调用对应的函数指针，把事件上报给RIL Adapter。

- 创建读取Modem设备节点的线程，在该线程里会循环地读取Modem上报的事件，并把接收的Modem信息解析为具体业务相关的事件进行上报。

- 返回业务请求接口的函数指针给RIL Adapter。


### 接口说明

Modem厂商库初始化接口。

  **表1** Modem厂商库初始化接口功能介绍

| 接口名 | 描述 | 
| -------- | -------- |
| const&nbsp;HRilOps&nbsp;\*RilInitOps(const&nbsp;struct&nbsp;HRilReport&nbsp;\*&nbsp;reportOps) | 接口功能：Modem厂商库运行的入口。<br/>参数reportOps：RIL&nbsp;Adapter传入的事件回调函数指针。<br/>返回值：业务请求接口的函数指针。 | 


### 开发步骤


1. RilInitOps接口中设置RIL Adapter传入的事件回调函数指针。
     
   ```
   // 定义Modem厂商库回调函数指针
   static struct HRilReport g_reportOps = {
       OnCallReport,    // 通话相关业务回调函数
       OnDataReport,    // 蜂窝数据相关业务回调函数
       OnModemReport,   // Modem相关业务回调函数
       OnNetworkReport, // 搜网相关业务回调函数
       OnSimReport,     // SIM卡相关业务回调函数
       OnSmsReport      // 短信相关业务回调函数
   };
   ```


1. 创建主线程g_reader，开启消息循环。
     
   ```
   pthread_attr_t t;
   pthread_attr_init(&t);
   pthread_attr_setdetachstate(&t, PTHREAD_CREATE_DETACHED);
   ret = pthread_create(&g_reader, &t, ReaderLoop, &t); // 创建线程
   ```


1. 在g_eventListeners线程用open()打开Modem设备节点，并创建g_reader线程循环读取处理Modem上报的消息。
     
   ```
   g_fd = open(g_devicePath, O_RDWR); // 打开设备节点，入参g_devicePath是Modem设备节点
   pthread_attr_init(&attr);   
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);   
   ret = pthread_create(&g_eventListeners, &attr, EventListeners, NULL);
   ```


1. 返回业务请求接口的函数指针。
     
   ```
   // call模块业务请求接口结构体
   typedef struct {
       // 获取呼叫列表
       void (*GetCallList)(ReqDataInfo *requestInfo, const void *data, size_t dataLen);
       // 拨打电话
       void (*Dial)(ReqDataInfo *requestInfo, const void *data, size_t dataLen);
       // 挂断电话
       void (*Hangup)(ReqDataInfo *requestInfo, const void *data, size_t dataLen);
       // 拒接来电
       void (*Reject)(ReqDataInfo *requestInfo, const void *data, size_t dataLen);
       // 接听来电
       void (*Answer)(ReqDataInfo *requestInfo, const void *data, size_t dataLen)；
   } HRilCallReq;
   
   // call模块回调函数指针
   static const HRilCallReq g_callReqOps = { 
       .GetCallList = ReqGetCallList, // 获取呼叫列表接口
       .Dial = ReqDial,               // 拨打电话接口
       .Hangup = ReqHangup,           // 挂断电话接口
       .Reject = ReqReject,           // 拒接来电接口
       .Answer = ReqAnswer,           // 接听来电接口
   };
   
   // 业务请求结构体
   typedef struct { 
       const HRilCallReq *callOps;       // 通话相关业务请求结构体指针
       const HRilSimReq *simOps;         // SIM卡相关业务请求结构体指针
       const HRilSmsReq *smsOps;         // 短彩信相关业务请求结构体指针
       const HRilDataReq *dataOps;       // 蜂窝数据相关业务请求结构体指针
       const HRilNetworkReq *networkOps; // 搜网相关业务请求结构体指针
       const HRilModemReq *modemOps;     // Modem相关业务请求结构体指针
   } HRilOps;  
     
   // 业务请求接口定义
   HRilOps g_hrilOps = {
       .callOps = &g_callReqOps,       // 定义通话业务请求接口
       .simOps = &g_simReqOps,         // 定义SIM卡业务请求接口
       .smsOps = &g_smsReqOps,         // 定义短彩信业务请求接口
       .networkOps = &g_networkReqOps, // 定义蜂窝数据业务请求接口
       .dataOps = &g_dataReqOps,       // 定义搜网业务请求接口
       .modemOps = &g_modemReqOps,     // 定义Modem业务请求接口
   };
   ```


### 调测验证

1. 用[hdc_std工具](../subsystems/subsys-toolchain-hdc-guide.md#环境准备)连接调试设备，把编译生成的libril_vendor.z.so库文件（参见[Modem厂商库集成指导](#modem厂商库集成指导)）通过以下命令推到/system/lib/目录下。
     
   ```
   hdc_std file send libril_vendor.z.so /system/lib/
   ```

2. 执行hdc_std shell sync，hdc_std shell reboot重启设备。
     
   ```
   hdc_std shell sync
   hdc_std shell reboot
   ```

3. 执行hdc_std shell hilog，根据日志查看函数RilInitOps()是否正确执行完成。如下调测验证日志供参考：
     
   ```
   09-02 07:40:47.807   455   455 I 01f08/HrilHdf: [LoadVendor-(hril_hdf.c:148)] RilInit LoadVendor start with rilLibPath:libril_vendor.z.so
   09-02 07:40:47.830   455   455 I 01f08/HrilHdf: [LoadVendor-(hril_hdf.c:163)] HRilRegOps completed
   ```


## Modem业务请求及响应开发指导


### 场景介绍

Modem业务请求及响应是指RIL Adapter收到电话服务具体业务请求后，调用Modem厂商库初始化获得的函数指针，把具体业务请求发送给厂商库，厂商库根据业务请求ID做相应的业务处理。


### 接口说明

Modem业务请求及响应接口。

  **表2** Modem业务请求及响应接口功能介绍（以拨号功能模块为例）

| 接口名 | 描述 | 
| -------- | -------- |
| void&nbsp;ReqDial(ReqDataInfo&nbsp;\*requestInfo,&nbsp;const&nbsp;void&nbsp;\*data,&nbsp;size_t&nbsp;dataLen); | 接口功能：对拨号请求进行处理。<br/>参数requestInfo：请求类型信息。<br/>参数data：被叫号码信息。<br/>参数dataLen：数据长度。<br/>返回值：无。 | 
| void&nbsp;(\*OnCallReport)(struct&nbsp;ReportInfo&nbsp;reportInfo,&nbsp;const&nbsp;void&nbsp;\*data,&nbsp;size_t&nbsp;dataLen); | 接口功能：对通话业务执行结果进行响应，即当请求业务执行完成后，Modem将该请求执行的结果上报给RIL&nbsp;Adapter。<br/>参数reportInfo：返回类型信息。<br/>参数data：返回数据。<br/>参数dataLen：数据长度。<br/>返回值：无。 | 


### 开发步骤

1. 在ReqDial()接口中对拨号请求进行处理。
     
   ```
   // 拨号请求接口实现
   void ReqDial(ReqDataInfo *requestInfo, const void *data, size_t dataLen)
   {
       HRilDial *pDial = NULL;
       char cmd[MAX_BUFF_SIZE] = {0};
       const char *clir = NULL;
       int ret;
       int err = HRIL_ERR_SUCCESS;
       struct ReportInfo reportInfo = {};
       ResponseInfo *pResponse = NULL;
       if (data == NULL) {
           TELEPHONY_LOGE("data is null!!!");
           err = HRIL_ERR_INVALID_PARAMETER;
           reportInfo = CreateReportInfo(requestInfo, err, HRIL_RESPONSE, 0);
           OnCallReport(reportInfo, NULL, 0);
           return;
       }
       pDial = (HRilDial *)data;
       switch (pDial->clir) {
           case CALL_CLIR_INVOCATION:
               clir = "I";
               break; /* invocation */
           case CALL_CLIR_SUPPRESSION:
               clir = "i";
               break; /* suppression */
           case CALL_CLIR_SUBSCRIPTION_DEFUALT:
           default:
               clir = "";
               break; /* subscription default */
       }
       (void)sprintf_s(cmd, MAX_BUFF_SIZE, "ATD%s%s;", pDial->address, clir);
       ret = SendCommandLock(cmd, NULL, 0, &pResponse); // 发送AT指令
       ......
   }
   ```

2. 在Modem执行完拨号命令后，调用OnCallReport()回调函数，把该请求执行的结果上报给RIL Adapter。
     
   ```
   ret = SendCommandLock(cmd, NULL, 0, &pResponse);
   if (ret != 0 || (pResponse != NULL && pResponse->success == 0)) {
       TELEPHONY_LOGE("ATD send failed");
       err = HRIL_ERR_GENERIC_FAILURE;
   }
   reportInfo = CreateReportInfo(requestInfo, err, HRIL_RESPONSE, 0);
   OnCallReport(reportInfo, NULL, 0); // 调用通话相关回调函数
   ```


### 调测验证

1. 用[hdc_std工具](../subsystems/subsys-toolchain-hdc-guide.md#环境准备)工具连接调试设备，把编译生成的libril_vendor.z.so库文件通过以下命令推到/system/lib/目录下。
     
   ```
   hdc_std file send libril_vendor.z.so /system/lib/
   ```

2. 执行hdc_std shell sync，hdc_std shell reboot重启设备。
     
   ```
   hdc_std shell sync
   hdc_std shell reboot
   ```

3. hdc_std shell后执行./system/bin/ril_adapter_test，输入编号1，根据提示输入电话号码，测试拨打电话功能。
     
   ```
   hdc_std shell
   # ./system/bin/ril_adapter_test
   ----> Test Enter  --------->Call---------------------
    
   1----> RilUnitTest::OnRequestCallDialTest
   2----> RilUnitTest:: OnRequestCallHangupTest
   3----> RilUnitTest:: OnRequestCallAnswerTest
   4----> RilUnitTest::OnRequestCallGetCurrentCallsStatusTest
   5----> RilUnitTest::OnRequestRefusedCallTest
      
   1
   ```

4. 另开一个终端窗口，执行hdc_std shell hilog，通过日志查看函数ReqDial()是否正确执行完成。如下调测验证日志供参考：
     
   ```
   09-02 07:55:09.073   455  2059 I 01f08/RilVendor: [SendCommandLock-(at_support.c:226)] command ATD18675231804;, NeedATPause:0, atCmd:AT
   09-02 07:55:09.099   455  2053 I 01f08/Rilvendor: [ProcessResponse-(at_support.c:159)] processLine line = OK
   09-02 07:55:09.100   455  2053 E 01f08/RilVendor: [ReportStrWith-(vendor_util.c:63)] str or prefix parameter is null.
   09-02 07:55:09.100   455  2053 E 01f08/RilVendor: [ProcessLastResponse-(vendor_channel.c:77)] g_bufferCur endLine is null
   09-02 07:55:09.100   455  2059 I 01f08/RilVendor: [SendCommandLock-(at_support.c:243)] err = 0
   09-02 07:55:09.100   455  2053 I 01f08/RilVendor: [ProcessResponse-(at_support.c:159)] processLine line = ^ORIG:1,0
   ```


## Modem事件上报开发指导


### 场景介绍

Modem事件上报是指在厂商库的Modem设备节点读取线程，循环读取到Modem主动上报的消息后，对Modem上报事件进行解析，然后上报给RIL Adapter。


### 接口说明

Modem事件上报接口。

  **表3** Modem事件上报接口功能介绍

| 接口名 | 描述 | 
| -------- | -------- |
| void&nbsp;OnNotifyOps(const&nbsp;char&nbsp;\*s,&nbsp;const&nbsp;char&nbsp;\*smsPdu) | 接口功能：对Modem上报的事件进行分发处理。<br/>参数s：AT指令前缀。<br/>参数smsPdu：短信PDU信息。<br/>返回值：无。 | 


### 开发步骤

1. 在Modem设备节点读取线程g_reader里调用OnNotifyOps()解析具体的Modem上报事件，判断命令类型，并调用OnXxxReport()把解析得到的各模块事件上报给hril业务层。
     
   ```
   // 将Modem上报数据解析为对应模块的主动上报事件
   void OnNotifyOps(const char *s, const char *smsPdu)
   {
       int ret = 0;
       struct ReportInfo reportInfo = {0};
       reportInfo.error = HRIL_ERR_SUCCESS;
       reportInfo.type = HRIL_NOTIFICATION;
       if (GetRadioState() == HRIL_RADIO_POWER_STATE_UNAVAILABLE) {
           return;
       }
       TELEPHONY_LOGD("enter to [%{public}s]:%{public}s", s, smsPdu);
       // 通过AT指令判断主动上报命令类型
       if (ReportStrWith(s, "+CRING:") || ReportStrWith(s, "RING") || ReportStrWith(s, "IRING") ||
           ReportStrWith(s, "NO CARRIER") || ReportStrWith(s, "+CCWA") || ReportStrWith(s, "^CCALLSTATE") ||
           ReportStrWith(s, "^CEND") || ReportStrWith(s, "^CCWA")) {
           reportInfo.notifyId = HNOTI_CALL_STATE_UPDATED;
           OnCallReport(reportInfo, NULL, 0);
       } else if (ReportStrWith(s, "+CMT:")) {
           reportInfo.notifyId = HNOTI_SMS_NEW_SMS;
           OnSmsReport(reportInfo, (void *)smsPdu, strlen(smsPdu));
       }
       // 将各模块事件上报给hril业务层
       ......
   }
   ```

1. hril业务层将上报事件分发给Telephony Service。
     
   ```
   // 呼叫状态主动上报
   int32_t HRilCall::CallStateUpdated(
       int32_t slotId, int32_t notifyType, const HRilErrno e, const void *response, size_t responseLen)
   {
       struct HdfSBuf *dataSbuf = HdfSBufTypedObtain(SBUF_IPC);
       if (serviceCallbackNotify_ == nullptr) {
           TELEPHONY_LOGE("RilAdapter serviceCallbackNotify_ is null");
           HdfSBufRecycle(dataSbuf);
           return HDF_FAILURE;
       }
       // 分发处理
       int32_t ret = serviceCallbackNotify_->dispatcher->Dispatch(
           serviceCallbackNotify_, HNOTI_CALL_STATE_UPDATED, dataSbuf, nullptr);
       if (ret != HDF_SUCCESS) {
           HdfSBufRecycle(dataSbuf);
           return HDF_FAILURE;
       }
       HdfSBufRecycle(dataSbuf);
       return HDF_SUCCESS;
   }
   ```


### 调测验证

1. 用[hdc_std工具](../subsystems/subsys-toolchain-hdc-guide.md#环境准备)工具连接调试设备，把编译生成的libril_vendor.z.so库文件通过以下命令推到/system/lib/目录下。
     
   ```
   hdc_std file send libril_vendor.z.so /system/lib/
   ```

2. 执行hdc_std shell sync，hdc_std shell reboot重启设备。
     
   ```
   hdc_std shell sync
   hdc_std shell reboot
   ```

3. hdc_std shell后执行./system/bin/ril_adapter_test，输入编号1，根据提示输入电话号码，测试拨打电话功能。
     
   ```
   hdc_std shell
   # ./system/bin/ril_adapter_test
   ----> Test Enter  --------->Call---------------------
    
   1----> RilUnitTest::OnRequestCallDialTest
   2----> RilUnitTest:: OnRequestCallHangupTest
   3----> RilUnitTest:: OnRequestCallAnswerTest
   4----> RilUnitTest::OnRequestCallGetCurrentCallsStatusTest
   5----> RilUnitTest::OnRequestRefusedCallTest
      
   1
   ```

4. 另开一个终端窗口，执行hdc_std shell hilog，通过日志查看函数OnNotifyOps()是否正确执行完成。如下调测验证日志供参考：
     
   ```
   01-01 00:08:01.334   546   551 D 02b01/TelRilTest: [DialResponse-(tel_ril_call.cpp:280)] DialResponse --> radioResponseInfo->serial:2, radioResponseInfo->error:0
   01-01 00:08:01.334   546   557 D 02b01/TelRilTest: [ProcessEvent-(tel_ril_test.cpp:1262)] TelRilTest::DemoHandler::ProcessEvent --> eventId:101
   01-01 00:08:01.334   143   512 D 02b01/Rilvendor: [ReadResponse-(channel.c:93)] g_bufferCur : 
   01-01 00:08:01.334   143   512 D 02b01/Rilvendor: ^ORIG:1,0
   01-01 00:08:01.334   143   512 D 02b01/Rilvendor: [ReadResponse-(channel.c:108)] AT< ^ORIG:1,0
   01-01 00:08:01.334   143   512 D 02b01/Rilvendor: [ProcessResponse-(at_support.c:137)] processLine line = ^ORIG:1,0
   01-01 00:08:01.334   143   512 D 02b01/Rilvendor: [OnNotifyOps-(vendor_report.c:126)] enter to [^ORIG:1,0]:(null)
   01-01 00:08:01.335   143   512 W 02b01/Rilvendor: [OnNotifyOps-(vendor_report.c:167)] enter to  is unrecognized command: ^ORIG:1,0
   01-01 00:08:01.335   143   512 D 02b01/Rilvendor: [ProcessLastResponse-(channel.c:37)] last data more than one line , FindEndOfLine  g_bufferCur: 
   01-01 00:08:01.335   143   512 E 02b01/Rilvendor: [ProcessLastResponse-(channel.c:39)] g_bufferCur endLine is null
   01-01 00:08:01.336   143   512 D 02b01/Rilvendor: [ReadResponse-(channel.c:93)] g_bufferCur : 
   01-01 00:08:01.336   143   512 D 02b01/Rilvendor: ^CCALLSTATE: 1,0,1
   01-01 00:08:01.336   143   512 D 02b01/Rilvendor: [ReadResponse-(channel.c:108)] AT< ^CCALLSTATE: 1,0,1
   01-01 00:08:01.336   143   512 D 02b01/Rilvendor: [ProcessResponse-(at_support.c:137)] processLine line = ^CCALLSTATE: 1,0,1
   01-01 00:08:01.336   143   512 D 02b01/Rilvendor: [OnNotifyOps-(vendor_report.c:126)] enter to [^CCALLSTATE: 1,0,1]:(null)
   01-01 00:08:01.336   546   551 D 02b01/CoreService: [OnRemoteRequest-(tel_ril_manager.cpp:80)] RilManager OnRemoteRequest code:1001
   01-01 00:08:01.336   546   551 D 02b01/CoreService: [NotifyObserver-(observer_handler.cpp:76)] handler->SendEvent:8
   ```


### 开发实例

- **去电开发实例**
    去电的调用流程示例如下图所示：
    **图1** 去电调用时序图

  ![zh-cn_image_0000001171507146](figures/zh-cn_image_0000001171507146.png)

    当应用触发去电动作时，RIL Adapter会接收到拨打电话的请求，hril调用对应的拨打电话的接口ReqDial()。在该接口里会把电话服务传过来的数据封装为对应的AT指令发送到Modem，Modem执行完拨号命令后通过OnCallReport()接口把响应结果上报给RIL Adapter。
    
  ```
  // call模块回调函数指针
  static const HRilCallReq g_callReqOps = { 
      .GetCallList = ReqGetCallList, // 获取呼叫列表接口
      .Dial = ReqDial,               // 拨打电话接口
      .Hangup = ReqHangup,           // 挂断电话接口
      .Reject = ReqReject,           // 拒接来电接口
      .Answer = ReqAnswer,           // 接听来电接口
  }; 
  
  // 系统业务请求接口定义
  HRilOps g_hrilOps = {
      .callOps = &g_callReqOps,       // 定义通话业务请求接口
      .simOps = &g_simReqOps,         // 定义SIM卡业务请求接口
      .smsOps = &g_smsReqOps,         // 定义短彩信业务请求接口
      .networkOps = &g_networkReqOps, // 定义蜂窝数据业务请求接口
      .dataOps = &g_dataReqOps,       // 定义搜网业务请求接口
      .modemOps = &g_modemReqOps,     // 定义Modem业务请求接口
  };
  
  // 拨号请求接口实现
  void ReqDial(ReqDataInfo *requestInfo, const void *data, size_t dataLen)
  {
      HRilDial *pDial = NULL;
      char cmd[MAX_BUFF_SIZE] = {0};
      const char *clir = NULL;
      int ret;
      int err = HRIL_ERR_SUCCESS;
      struct ReportInfo reportInfo = {};
      ResponseInfo *pResponse = NULL;
      if (data == NULL) {
          TELEPHONY_LOGE("data is null!!!");
          err = HRIL_ERR_INVALID_PARAMETER;
          reportInfo = CreateReportInfo(requestInfo, err, HRIL_RESPONSE, 0);
          OnCallReport(reportInfo, NULL, 0);
          return;
      }
      pDial = (HRilDial *)data;
      switch (pDial->clir) {
          case CALL_CLIR_INVOCATION:
              clir = "I";
              break; /* invocation */
          case CALL_CLIR_SUPPRESSION:
              clir = "i";
              break; /* suppression */
          case CALL_CLIR_SUBSCRIPTION_DEFUALT:
          default:
              clir = "";
              break; /* subscription default */
      }
      (void)sprintf_s(cmd, MAX_BUFF_SIZE, "ATD%s%s;", pDial->address, clir);
      ret = SendCommandLock(cmd, NULL, 0, &pResponse); // 发送AT命令
      if (ret != 0) {
          err = HRIL_ERR_CMD_SEND_FAILURE;
          TELEPHONY_LOGE("ATD send failed");
      } else {
          if (pResponse != NULL && pResponse->success == 0) {
              TELEPHONY_LOGE("ReqDial return ERROR");
              err = HRIL_ERR_CMD_NO_CARRIER;
          }
      }
      reportInfo = CreateReportInfo(requestInfo, err, HRIL_RESPONSE, 0);
      OnCallReport(reportInfo, NULL, 0); // 调用通话相关业务回调函数
      FreeResponseInfo(pResponse);
  }
  ```


- **来电开发实例**
    来电的调用流程示例如下图所示：
    **图2** 来电调用时序图

  ![zh-cn_image_0000001214727595](figures/zh-cn_image_0000001214727595.png)

  Modem设备节点读取线程g_reader会循环读取Modem上报的消息，当Modem接收到来电时会主动上报来电相关的信息；

    当该线程通过调用OnNotifyOps()解析到Modem上报的数据是以"+CRING"、"RING"等字符开头时，表示有来电事件，然后通过OnCallReport(reportInfo, NULL, 0)上报给RIL Adapter完成来电事件上报。
    
  ```
  // 将Modem上报数据解析为对应模块的主动上报事件
  void OnNotifyOps(const char *s, const char *smsPdu)
  {
      int ret = 0;
      struct ReportInfo reportInfo = {0};
      reportInfo.error = HRIL_ERR_SUCCESS;
      reportInfo.type = HRIL_NOTIFICATION;
      if (GetRadioState() == HRIL_RADIO_POWER_STATE_UNAVAILABLE) {
          return;
      }
      TELEPHONY_LOGD("enter to [%{public}s]:%{public}s", s, smsPdu);
      // 通过AT指令判断主动上报命令类型
      if (ReportStrWith(s, "+CRING:") || ReportStrWith(s, "RING") || ReportStrWith(s, "IRING") ||
          ReportStrWith(s, "NO CARRIER") || ReportStrWith(s, "+CCWA") || ReportStrWith(s, "^CCALLSTATE") ||
          ReportStrWith(s, "^CEND") || ReportStrWith(s, "^CCWA")) {
          reportInfo.notifyId = HNOTI_CALL_STATE_UPDATED;
          OnCallReport(reportInfo, NULL, 0);  // 调用通话相关业务回调函数
      } else if (ReportStrWith(s, "+CMT:")) {
          reportInfo.notifyId = HNOTI_SMS_NEW_SMS;
          OnSmsReport(reportInfo, (void *)smsPdu, strlen(smsPdu));
      } 
      // add your codes
      ......
  }
  ```


## Modem厂商库集成指导


### 编译设置

Modem厂商库可通过BUILD.gn编译为一个动态库，在RIL Adapter启动时用dlopen方式加载到系统中，然后执行厂商库的初始化操作（参见[Modem厂商库初始化开发指导](#modem厂商库初始化开发指导)），BUILD.gn编写示例如下：

  
```
import("//build/ohos.gni")
RIL_ADAPTER = "//base/telephony"
ohos_shared_library("ril_vendor") { // Modem厂商库名称
    sources = [ // 编译源文件
        "at_call.c",
        "at_data.c",
        "xxx.c",
    ]
    include_dirs = [ // 包含的头文件目录
        "$RIL_ADAPTER/ril_adapter/vendor/include",
        "$RIL_ADAPTER/ril_adapter/interfaces/innerkits",
        "include",
    ]
    deps = [ // 内部依赖
        "//drivers/adapter/uhdf2/osal:libhdf_utils",
        "//base/telephony/core_service/utils:libtelephony_common",
    ]
    external_deps = [ "hilog:libhilog" ] // 外部依赖

    part_name = "ril_adapter"  // 部件名称
    subsystem_name = "telephony" // 子系统名称	
}
```


### 调测验证

1. 编译代码。

2. 查看/out/{device_name}/telephony/ril_adapter目录是否存在libril_vendor.z.so，存在证明集成成功。否则检查代码，重新编译验证。
