# OHOS::Camera::ICameraDevice


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.Device") | IPC通信token校验。 | 
| [GetStreamOperator](_camera.md#getstreamoperator)&nbsp;(const&nbsp;OHOS::sptr&lt;&nbsp;[IStreamOperatorCallback](_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md)&nbsp;&gt;&nbsp;&amp;callback,&nbsp;OHOS::sptr&lt;&nbsp;[IStreamOperator](_o_h_o_s_1_1_camera_1_1_i_stream_operator.md)&nbsp;&gt;&nbsp;&amp;streamOperator)=0 | 获取流操作句柄。&nbsp;[更多...](_camera.md#getstreamoperator) | 
| [UpdateSettings](_camera.md#updatesettings)&nbsp;(const&nbsp;std::shared_ptr&lt;&nbsp;CameraSetting&nbsp;&gt;&nbsp;&amp;settings)=0 | 更新设备控制参数。&nbsp;[更多...](_camera.md#updatesettings) | 
| [SetResultMode](_camera.md#setresultmode)&nbsp;(const&nbsp;[ResultCallbackMode](_camera.md#resultcallbackmode)&nbsp;&amp;mode)=0 | 设置metadata上报模式，逐帧上报还是设备状态变化时上报。&nbsp;[更多...](_camera.md#setresultmode) | 
| [GetEnabledResults](_camera.md#getenabledresults)&nbsp;(std::vector&lt;&nbsp;MetaType&nbsp;&gt;&nbsp;&amp;results)=0 | 查询使能的metadata。&nbsp;[更多...](_camera.md#getenabledresults) | 
| [EnableResult](_camera.md#enableresult)&nbsp;(const&nbsp;std::vector&lt;&nbsp;MetaType&nbsp;&gt;&nbsp;&amp;results)=0 | 打开metadata上报开关。&nbsp;[更多...](_camera.md#enableresult) | 
| [DisableResult](_camera.md#disableresult)&nbsp;(const&nbsp;std::vector&lt;&nbsp;MetaType&nbsp;&gt;&nbsp;&amp;results)=0 | 关闭metadata上报开关。&nbsp;[更多...](_camera.md#disableresult) | 
| [Close](_camera.md#close)&nbsp;()=0 | 关闭Camera设备。&nbsp;[更多...](_camera.md#close) | 


## **详细描述**

Camera设备操作。
