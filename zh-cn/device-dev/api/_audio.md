# Audio


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [audio_adapter.h](audio__adapter_8h.md) | Audio适配器的接口定义文件 | 
| [audio_attribute.h](audio__attribute_8h.md) | Audio属性的接口定义文件 | 
| [audio_capture.h](audio__capture_8h.md) | Audio录音的接口定义文件 | 
| [audio_control.h](audio__control_8h.md) | Audio控制的接口定义文件 | 
| [audio_manager.h](audio__manager_8h.md) | Audio适配器管理及加载的接口定义文件 | 
| [audio_render.h](audio__render_8h.md) | Audio播放的接口定义文件 | 
| [audio_scene.h](audio__scene_8h.md) | Audio场景的接口定义文件 | 
| [audio_types.h](audio__types_8h.md) | Audio模块接口定义中使用的自定义数据类型 | 
| [audio_volume.h](audio__volume_8h.md) | Audio音量的接口定义文件 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [AudioAdapter](_audio_adapter.md) | AudioAdapter音频适配器接口&nbsp;[更多...](_audio_adapter.md) | 
| [AudioAttribute](_audio_attribute.md) | AudioAttribute音频属性接口&nbsp;[更多...](_audio_attribute.md) | 
| [AudioCapture](_audio_capture.md) | AudioCapture音频录音接口&nbsp;[更多...](_audio_capture.md) | 
| [AudioControl](_audio_control.md) | AudioControl音频控制接口&nbsp;[更多...](_audio_control.md) | 
| [AudioManager](_audio_manager.md) | AudioManager音频适配器管理接口&nbsp;[更多...](_audio_manager.md) | 
| [AudioRender](_audio_render.md) | AudioRender音频播放接口&nbsp;[更多...](_audio_render.md) | 
| [AudioScene](_audio_scene.md) | AudioScene音频场景接口&nbsp;[更多...](_audio_scene.md) | 
| [AudioPort](_audio_port.md) | 音频端口&nbsp;[更多...](_audio_port.md) | 
| [AudioAdapterDescriptor](_audio_adapter_descriptor.md) | 音频适配器描述符&nbsp;[更多...](_audio_adapter_descriptor.md) | 
| [AudioDeviceDescriptor](_audio_device_descriptor.md) | 音频设备描述符&nbsp;[更多...](_audio_device_descriptor.md) | 
| [AudioSceneDescriptor](_audio_scene_descriptor.md) | 音频场景描述符&nbsp;[更多...](_audio_scene_descriptor.md) | 
| [AudioSceneDescriptor::SceneDesc](union_audio_scene_descriptor_1_1_scene_desc.md) | 音频场景描述&nbsp;[更多...](union_audio_scene_descriptor_1_1_scene_desc.md) | 
| [AudioSampleAttributes](_audio_sample_attributes.md) | 音频采样属性&nbsp;[更多...](_audio_sample_attributes.md) | 
| [AudioTimeStamp](_audio_time_stamp.md) | 音频时间戳&nbsp;[更多...](_audio_time_stamp.md) | 
| [AudioSubPortCapability](_audio_sub_port_capability.md) | 音频子端口的支持能力&nbsp;[更多...](_audio_sub_port_capability.md) | 
| [AudioPortCapability](_audio_port_capability.md) | 音频端口的支持能力&nbsp;[更多...](_audio_port_capability.md) | 
| [AudioMmapBufferDescripter](_audio_mmap_buffer_descripter.md) | mmap缓冲区描述符&nbsp;[更多...](_audio_mmap_buffer_descripter.md) | 
| [AudioDevExtInfo](_audio_dev_ext_info.md) | 音频设备拓展信息&nbsp;[更多...](_audio_dev_ext_info.md) | 
| [AudioMixExtInfo](_audio_mix_ext_info.md) | 音轨拓展信息&nbsp;[更多...](_audio_mix_ext_info.md) | 
| [AudioSessionExtInfo](_audio_session_ext_info.md) | 会话拓展信息&nbsp;[更多...](_audio_session_ext_info.md) | 
| [AudioRouteNode](_audio_route_node.md) | 音频路由节点&nbsp;[更多...](_audio_route_node.md) | 
| [AudioRoute](_audio_route.md) | 音频路由信息&nbsp;[更多...](_audio_route.md) | 
| [AudioVolume](_audio_volume.md) | AudioVolume音频音量接口&nbsp;[更多...](_audio_volume.md) | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| AudioHandle | 音频句柄 | 
| ([RenderCallback](#rendercallback))&nbsp;(enum&nbsp;[AudioCallbackType](#audiocallbacktype),&nbsp;void&nbsp;\*reserved,&nbsp;void&nbsp;\*cookie) | 回调函数指针&nbsp;[更多...](#rendercallback) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](#audioportdirection)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1872427638083931,link:zh-cn_topic_0000001295254272.xml#gga68ff7140b15790debbac4bbc62f8e9f8af54f110a0f64337d474989fbac06bc22](#gga68ff7140b15790debbac4bbc62f8e9f8af54f110a0f64337d474989fbac06bc22)&nbsp;=&nbsp;0x1u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1956179113083931,link:zh-cn_topic_0000001295254272.xml#gga68ff7140b15790debbac4bbc62f8e9f8a154a6db110515b7afde52d3a36d57846](#gga68ff7140b15790debbac4bbc62f8e9f8a154a6db110515b7afde52d3a36d57846)&nbsp;=&nbsp;0x2u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1870613635083931,link:zh-cn_topic_0000001295254272.xml#gga68ff7140b15790debbac4bbc62f8e9f8a87e14fe9da9c332ba29185b9213d7bbf](#gga68ff7140b15790debbac4bbc62f8e9f8a87e14fe9da9c332ba29185b9213d7bbf)&nbsp;=&nbsp;0x3u&nbsp;} | 音频端口的类型&nbsp;[更多...](#audioportdirection) | 
| [AudioPortPin](#audioportpin)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1493981061083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad2f867652c04c17517db7731af03bf20](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad2f867652c04c17517db7731af03bf20)&nbsp;=&nbsp;0x0u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref685216793083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab1070439bab93e06446c21157771dd6f](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab1070439bab93e06446c21157771dd6f)&nbsp;=&nbsp;0x1u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1812227293083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a271013721c8840cc2700c19b3ff8d0a6](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a271013721c8840cc2700c19b3ff8d0a6)&nbsp;=&nbsp;0x2u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref44597532083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a411e9037214c75d22c9080505cf9cae6](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a411e9037214c75d22c9080505cf9cae6)&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1840039063083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab4aaa2ec71ec77480f60743cd79340b9](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab4aaa2ec71ec77480f60743cd79340b9)&nbsp;=&nbsp;0x8u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1181985818083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a4fdca959c8b32bc9a30a36882bd3bdaa](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a4fdca959c8b32bc9a30a36882bd3bdaa)&nbsp;=&nbsp;0x10u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1740611064083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a933d2d5aadef8b45038be8be69b56b27](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a933d2d5aadef8b45038be8be69b56b27)&nbsp;=&nbsp;0x20u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1483273702083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a336001f5685d9c206b1251714553b485](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a336001f5685d9c206b1251714553b485)&nbsp;=&nbsp;0x8000001u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref2052340513083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835aaeca21ac0a7b249905d1cea5b683f574](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835aaeca21ac0a7b249905d1cea5b683f574)&nbsp;=&nbsp;0x8000002u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1541442973083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a5146add03ff98f06648567bb0e02a477](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a5146add03ff98f06648567bb0e02a477)&nbsp;=&nbsp;0x8000004u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1972742366083931,link:zh-cn_topic_0000001295254272.xml#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad6b81dc30e45f9f79801bf1e8ee0caef](#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad6b81dc30e45f9f79801bf1e8ee0caef)&nbsp;=&nbsp;0x8000008u&nbsp;} | 音频适配器端口的PIN脚&nbsp;[更多...](#audioportpin) | 
| [AudioCategory](#audiocategory)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref297140569083931,link:zh-cn_topic_0000001295254272.xml#ggaf210d41d152890f3aaf2aaac99bd28d5a6ac6cfd90dcc34de100c1cecb3df44c3](#ggaf210d41d152890f3aaf2aaac99bd28d5a6ac6cfd90dcc34de100c1cecb3df44c3)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1959787488083931,link:zh-cn_topic_0000001295254272.xml#ggaf210d41d152890f3aaf2aaac99bd28d5a474576c773934a0df994bad4cf781b41](#ggaf210d41d152890f3aaf2aaac99bd28d5a474576c773934a0df994bad4cf781b41),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1760094621083931,link:zh-cn_topic_0000001295254272.xml#ggaf210d41d152890f3aaf2aaac99bd28d5aa5361a2d3ed6703c130417ec243d0a69](#ggaf210d41d152890f3aaf2aaac99bd28d5aa5361a2d3ed6703c130417ec243d0a69),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref871250563083931,link:zh-cn_topic_0000001295254272.xml#ggaf210d41d152890f3aaf2aaac99bd28d5a7a6ef7c82e9a5eb63d004056eb13c894](#ggaf210d41d152890f3aaf2aaac99bd28d5a7a6ef7c82e9a5eb63d004056eb13c894)&nbsp;} | 音频类型（category）&nbsp;[更多...](#audiocategory) | 
| [AudioFormat](#audioformat)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1847971465083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a321cc2160af35aa86b8ee55f231ef1e6](#gga98d5d077cca088ddf77314871474fe59a321cc2160af35aa86b8ee55f231ef1e6)&nbsp;=&nbsp;0x1u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1261428183083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59ae188cf87c8f2e6218c74b3b2385068e6](#gga98d5d077cca088ddf77314871474fe59ae188cf87c8f2e6218c74b3b2385068e6)&nbsp;=&nbsp;0x2u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1801870868083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a21eb864e2117df577dcd90ad81da3b14](#gga98d5d077cca088ddf77314871474fe59a21eb864e2117df577dcd90ad81da3b14)&nbsp;=&nbsp;0x3u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref620562518083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59adf7a0bf1f3dd15c9c43fac07c0c6ea26](#gga98d5d077cca088ddf77314871474fe59adf7a0bf1f3dd15c9c43fac07c0c6ea26)&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1087097448083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a5a781e6f8b145066ae7fb2c310804bab](#gga98d5d077cca088ddf77314871474fe59a5a781e6f8b145066ae7fb2c310804bab)&nbsp;=&nbsp;0x1000001u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1830475719083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a3d4bc5d534d0452635455ed8d2cade57](#gga98d5d077cca088ddf77314871474fe59a3d4bc5d534d0452635455ed8d2cade57)&nbsp;=&nbsp;0x1000002u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1989338155083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59ad4baf87ff9f4684c03483c572052b700](#gga98d5d077cca088ddf77314871474fe59ad4baf87ff9f4684c03483c572052b700)&nbsp;=&nbsp;0x1000003u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1985412102083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a4b8d42988fecf03e2bf73c4395501852](#gga98d5d077cca088ddf77314871474fe59a4b8d42988fecf03e2bf73c4395501852)&nbsp;=&nbsp;0x1000004u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1803238353083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59abaddb86f122d3185de9407dbc673bf0e](#gga98d5d077cca088ddf77314871474fe59abaddb86f122d3185de9407dbc673bf0e)&nbsp;=&nbsp;0x1000005u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref391270671083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59ab610e0121e0b5076b3f78831e3c237fd](#gga98d5d077cca088ddf77314871474fe59ab610e0121e0b5076b3f78831e3c237fd)&nbsp;=&nbsp;0x1000006u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1730725146083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a625f7a608bd66462e532762af64c5393](#gga98d5d077cca088ddf77314871474fe59a625f7a608bd66462e532762af64c5393)&nbsp;=&nbsp;0x2000001u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref379396610083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a6284a1ee0d6034eab8836f5d6352b3da](#gga98d5d077cca088ddf77314871474fe59a6284a1ee0d6034eab8836f5d6352b3da)&nbsp;=&nbsp;0x2000002u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref203695405083931,link:zh-cn_topic_0000001295254272.xml#gga98d5d077cca088ddf77314871474fe59a46432573957951a919c84b00504b46b0](#gga98d5d077cca088ddf77314871474fe59a46432573957951a919c84b00504b46b0)&nbsp;=&nbsp;0x2000003u&nbsp;} | 音频格式&nbsp;[更多...](#audioformat) | 
| [AudioChannelMask](#audiochannelmask)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref469505431083931,link:zh-cn_topic_0000001295254272.xml#gga137eb03027d5947ea294b32f5095b83ca0419483310bfc5abe46a0c586070ed18](#gga137eb03027d5947ea294b32f5095b83ca0419483310bfc5abe46a0c586070ed18)&nbsp;=&nbsp;0x1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1505633910083931,link:zh-cn_topic_0000001295254272.xml#gga137eb03027d5947ea294b32f5095b83ca05525a25c5912eda05e9a8786a743a75](#gga137eb03027d5947ea294b32f5095b83ca05525a25c5912eda05e9a8786a743a75)&nbsp;=&nbsp;0x2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1774752327083931,link:zh-cn_topic_0000001295254272.xml#gga137eb03027d5947ea294b32f5095b83ca0479e1cd2137cbbad68efae1d2b2c9a9](#gga137eb03027d5947ea294b32f5095b83ca0479e1cd2137cbbad68efae1d2b2c9a9)&nbsp;=&nbsp;0x1u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref81777348083931,link:zh-cn_topic_0000001295254272.xml#gga137eb03027d5947ea294b32f5095b83ca70f2212ea5439c13f7fcba3e30b15c1a](#gga137eb03027d5947ea294b32f5095b83ca70f2212ea5439c13f7fcba3e30b15c1a)&nbsp;=&nbsp;0x3u&nbsp;} | 音频通道掩码（mask）&nbsp;[更多...](#audiochannelmask) | 
| [AudioSampleRatesMask](#audiosampleratesmask)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1216525371083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4ca046a26906a4df81bfc38c583ba3606e9](#gga7053fcaa56d1dc47d2fcd83ee131fe4ca046a26906a4df81bfc38c583ba3606e9)&nbsp;=&nbsp;0x1u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1589795186083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4caf1f34aa763f2bf6d5f43178f2d335d10](#gga7053fcaa56d1dc47d2fcd83ee131fe4caf1f34aa763f2bf6d5f43178f2d335d10)&nbsp;=&nbsp;0x2u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref201634848083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4ca5f13b000ef455b858506fc90d17e2dd7](#gga7053fcaa56d1dc47d2fcd83ee131fe4ca5f13b000ef455b858506fc90d17e2dd7)&nbsp;=&nbsp;0x4u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1523021230083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4ca3102248493467e00d16c2cf1971635a7](#gga7053fcaa56d1dc47d2fcd83ee131fe4ca3102248493467e00d16c2cf1971635a7)&nbsp;=&nbsp;0x8u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref292096040083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4cae7cfb2244a15cd133373cfa5e96ec82e](#gga7053fcaa56d1dc47d2fcd83ee131fe4cae7cfb2244a15cd133373cfa5e96ec82e)&nbsp;=&nbsp;0x10u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref701474512083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4cacce4defc0cf23abfe52d399b4aa68fdf](#gga7053fcaa56d1dc47d2fcd83ee131fe4cacce4defc0cf23abfe52d399b4aa68fdf)&nbsp;=&nbsp;0x20u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref440698404083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4ca5594285d8ef3897e9f29a15e0795b814](#gga7053fcaa56d1dc47d2fcd83ee131fe4ca5594285d8ef3897e9f29a15e0795b814)&nbsp;=&nbsp;0x40u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1331816390083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4ca52345265822f55a62b2e038438daf37e](#gga7053fcaa56d1dc47d2fcd83ee131fe4ca52345265822f55a62b2e038438daf37e)&nbsp;=&nbsp;0x80u,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1378568104083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4caa52c49624fecf6d9f1d075d0d3ad0bbf](#gga7053fcaa56d1dc47d2fcd83ee131fe4caa52c49624fecf6d9f1d075d0d3ad0bbf)&nbsp;=&nbsp;0x100u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1527587012083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4caf111a8b9762ec169361a106ba7efdb0f](#gga7053fcaa56d1dc47d2fcd83ee131fe4caf111a8b9762ec169361a106ba7efdb0f)&nbsp;=&nbsp;0x200u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1311588140083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4caa9e4deb07b2a7c32e5a19b8c81d9fd0d](#gga7053fcaa56d1dc47d2fcd83ee131fe4caa9e4deb07b2a7c32e5a19b8c81d9fd0d)&nbsp;=&nbsp;0x400u,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref835932715083931,link:zh-cn_topic_0000001295254272.xml#gga7053fcaa56d1dc47d2fcd83ee131fe4ca41f8d22ab95c84d0acb3d0c78679274c](#gga7053fcaa56d1dc47d2fcd83ee131fe4ca41f8d22ab95c84d0acb3d0c78679274c)&nbsp;=&nbsp;0xFFFFFFFFu&nbsp;} | 音频采样频率MASK&nbsp;[更多...](#audiosampleratesmask) | 
| [AudioPortPassthroughMode](#audioportpassthroughmode)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref2003128552083931,link:zh-cn_topic_0000001295254272.xml#gga186d2d4f9a2ecacb80cd2cce2bd26f0ea48da60ec7958d35e8884e67cc32cb465](#gga186d2d4f9a2ecacb80cd2cce2bd26f0ea48da60ec7958d35e8884e67cc32cb465)&nbsp;=&nbsp;0x1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1340675146083931,link:zh-cn_topic_0000001295254272.xml#gga186d2d4f9a2ecacb80cd2cce2bd26f0eaf44936c424fbadafda9e1a12829b291f](#gga186d2d4f9a2ecacb80cd2cce2bd26f0eaf44936c424fbadafda9e1a12829b291f)&nbsp;=&nbsp;0x2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref431072076083931,link:zh-cn_topic_0000001295254272.xml#gga186d2d4f9a2ecacb80cd2cce2bd26f0eada09d902428d269446b94c2b7e9eb95e](#gga186d2d4f9a2ecacb80cd2cce2bd26f0eada09d902428d269446b94c2b7e9eb95e)&nbsp;=&nbsp;0x4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref731183987083931,link:zh-cn_topic_0000001295254272.xml#gga186d2d4f9a2ecacb80cd2cce2bd26f0ea6fd7a77031d807247e159c3deec07e11](#gga186d2d4f9a2ecacb80cd2cce2bd26f0ea6fd7a77031d807247e159c3deec07e11)&nbsp;=&nbsp;0x8&nbsp;} | 音频端口的数据透传模式&nbsp;[更多...](#audioportpassthroughmode) | 
| [AudioSampleFormat](#audiosampleformat)&nbsp;{&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S8](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a2d8a330d2cb71268562e1c4da0c4eabc),&nbsp;[AUDIO_SAMPLE_FORMAT_S8P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a4eb79a5d6d99244902cfb5c65f225c80),&nbsp;[AUDIO_SAMPLE_FORMAT_U8](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ab6d04d1d87a9a243b195ab6be183600e),&nbsp;[AUDIO_SAMPLE_FORMAT_U8P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757aeffb8620959b836e01622c7dc82ebc6d),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S16](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a4422a2a04509e492ef823189d454d5a3),&nbsp;[AUDIO_SAMPLE_FORMAT_S16P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a11a1fb37c21f722383a37fc5e6075dfe),&nbsp;[AUDIO_SAMPLE_FORMAT_U16](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757af961944b4c8e77ee56defc30e6e61eb5),&nbsp;[AUDIO_SAMPLE_FORMAT_U16P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a08ba605e3e58479ebb7432ff5d6d0972),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S24](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a102520af7c50d1ee4951e472f5f921e4),&nbsp;[AUDIO_SAMPLE_FORMAT_S24P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ae245cf6bd637c1f1304b38746f8940d6),&nbsp;[AUDIO_SAMPLE_FORMAT_U24](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a0d5fc3d14030aad7bc17d894bf4fc5c9),&nbsp;[AUDIO_SAMPLE_FORMAT_U24P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a0e8b7681ec3461988cb7fdd0f3616b2e),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a46819088770f843230d2b094fd8d14ba),&nbsp;[AUDIO_SAMPLE_FORMAT_S32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a7883f8a4bede55eb4ffaf6ecb47f6841),&nbsp;[AUDIO_SAMPLE_FORMAT_U32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757afae09ccb9fdae65e73e5584a4c3a6d16),&nbsp;[AUDIO_SAMPLE_FORMAT_U32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a915025bfdcf9491a21b2d38dec7998cc),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S64](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a2e5477f7cc05dcc271b50e570dfd0452),&nbsp;[AUDIO_SAMPLE_FORMAT_S64P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ab07b4d40994980a8012a79dc4a69a794),&nbsp;[AUDIO_SAMPLE_FORMAT_U64](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a959950ea0f2b6c0e17d752640238c23b),&nbsp;[AUDIO_SAMPLE_FORMAT_U64P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757aad2c58522f7d16111756c1731bf52044),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_F32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ac3cb5729241a7f73210d97d4fe0002fe),&nbsp;[AUDIO_SAMPLE_FORMAT_F32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a1121b8995d1083f61b2fa0afcc45143f),&nbsp;[AUDIO_SAMPLE_FORMAT_F64](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a72f064169d0282fa8a152aea546056c3),&nbsp;[AUDIO_SAMPLE_FORMAT_F64P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a1f0e407cd152b27f7b0ff761d26bb300),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FMT_U8](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757aad65a5b895b3dba000167dbb6c19b9ab),&nbsp;[AUDIO_SAMPLE_FMT_S16](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a40335eaa7ca378540941909ed02b51a0),&nbsp;[AUDIO_SAMPLE_FMT_S32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ab98feafb8396c0190a4fb719a15ab7c5),&nbsp;[AUDIO_SAMPLE_FMT_FLOAT](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ac2fb27a42b3f79e51dd71ce05b42f9db),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FMT_DOUBLE](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757afb8b12c44b4799f59a533609b4c360b5),&nbsp;[AUDIO_SAMPLE_FMT_U8P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a8eb00238e7aa21d69f056d9292eb64d9),&nbsp;[AUDIO_SAMPLE_FMT_S16P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a93008db1a966fee4a91b515fedc78cec),&nbsp;[AUDIO_SAMPLE_FMT_S32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a6bb874f2726bb94d08914b366ae947d6),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FMT_FLOATP](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a8a635bbd6c5df1a8a0fadb1d9602ea74),&nbsp;[AUDIO_SAMPLE_FMT_DOUBLEP](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a467bd88ce7f736a433425695ed0a0dbc),&nbsp;[AUDIO_SAMPLE_FMT_INVALID](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a5c8f7c2c0f84e70f609f8fd4ffd2c910)&nbsp;} | 原始音频样本格式&nbsp;[更多...](#audiosampleformat) | 
| [AudioChannelMode](#audiochannelmode)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1444525694083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123aa97ec21f6627e1dfd4854b5b470cdfba](#gga78aab1fafb9657451804e42b42897123aa97ec21f6627e1dfd4854b5b470cdfba)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1758738400083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a47fd61e4531acb6b5cc058ac26af5d51](#gga78aab1fafb9657451804e42b42897123a47fd61e4531acb6b5cc058ac26af5d51),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref92277550083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a3341b11cad1d47bda2b4a2be60dda023](#gga78aab1fafb9657451804e42b42897123a3341b11cad1d47bda2b4a2be60dda023),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref2092924788083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a3f2e41939cc24c51213d8730c32e74e9](#gga78aab1fafb9657451804e42b42897123a3f2e41939cc24c51213d8730c32e74e9),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1344286562083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a2c1537bccd5c2a05d1c515e58ec4481e](#gga78aab1fafb9657451804e42b42897123a2c1537bccd5c2a05d1c515e58ec4481e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref965246877083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a485c0423ce07fbb7f844a387ed9bb546](#gga78aab1fafb9657451804e42b42897123a485c0423ce07fbb7f844a387ed9bb546),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref118340556083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a0878cdf6f3e0d9ae9ae1f61b7f74257e](#gga78aab1fafb9657451804e42b42897123a0878cdf6f3e0d9ae9ae1f61b7f74257e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1234763433083931,link:zh-cn_topic_0000001295254272.xml#gga78aab1fafb9657451804e42b42897123a22540143eb96abf8176e73c19fc0d8e5](#gga78aab1fafb9657451804e42b42897123a22540143eb96abf8176e73c19fc0d8e5)&nbsp;} | 音频播放的通道模式&nbsp;[更多...](#audiochannelmode) | 
| [AudioDrainNotifyType](#audiodrainnotifytype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref775607707083931,link:zh-cn_topic_0000001295254272.xml#gga6359642a80d38bd309683186d904306da4963b68236fd3314ffee8bc02c1b5d9f](#gga6359642a80d38bd309683186d904306da4963b68236fd3314ffee8bc02c1b5d9f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1047403888083931,link:zh-cn_topic_0000001295254272.xml#gga6359642a80d38bd309683186d904306da6502b8f1bc5e947ef45638a2155b5dff](#gga6359642a80d38bd309683186d904306da6502b8f1bc5e947ef45638a2155b5dff)&nbsp;} | DrainBuffer函数结束类型&nbsp;[更多...](#audiodrainnotifytype) | 
| [AudioCallbackType](#audiocallbacktype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1832461030083931,link:zh-cn_topic_0000001295254272.xml#ggae6a108ed6d40bf9adc9124f59501e1a8ae5f3f33b8d4de2b6ae2004e46db16b4f](#ggae6a108ed6d40bf9adc9124f59501e1a8ae5f3f33b8d4de2b6ae2004e46db16b4f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1794398377083931,link:zh-cn_topic_0000001295254272.xml#ggae6a108ed6d40bf9adc9124f59501e1a8a88770682790de22125afbee7fd0da618](#ggae6a108ed6d40bf9adc9124f59501e1a8a88770682790de22125afbee7fd0da618),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1867274954083931,link:zh-cn_topic_0000001295254272.xml#ggae6a108ed6d40bf9adc9124f59501e1a8a67b1cc122ca5bf96b68cb28bfbdfe9a8](#ggae6a108ed6d40bf9adc9124f59501e1a8a67b1cc122ca5bf96b68cb28bfbdfe9a8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref483828898083931,link:zh-cn_topic_0000001295254272.xml#ggae6a108ed6d40bf9adc9124f59501e1a8a569f62b68b379f66e63bd8f0f8500421](#ggae6a108ed6d40bf9adc9124f59501e1a8a569f62b68b379f66e63bd8f0f8500421),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1991332510083931,link:zh-cn_topic_0000001295254272.xml#ggae6a108ed6d40bf9adc9124f59501e1a8a5372856fbf3214e0c54c4d4d4046bfe8](#ggae6a108ed6d40bf9adc9124f59501e1a8a5372856fbf3214e0c54c4d4d4046bfe8)&nbsp;} | 回调函数通知事件类型&nbsp;[更多...](#audiocallbacktype) | 
| [AudioPortRole](#audioportrole)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref2141548492083931,link:zh-cn_topic_0000001295254272.xml#gga9262d2f01824bf765fd79c2e78c9a62da87fb7ced5a0e447f2bbd1b7730d2eb7b](#gga9262d2f01824bf765fd79c2e78c9a62da87fb7ced5a0e447f2bbd1b7730d2eb7b)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref450998328083931,link:zh-cn_topic_0000001295254272.xml#gga9262d2f01824bf765fd79c2e78c9a62da22faadd2246a6ca5995c14560a9b9332](#gga9262d2f01824bf765fd79c2e78c9a62da22faadd2246a6ca5995c14560a9b9332)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1555569095083931,link:zh-cn_topic_0000001295254272.xml#gga9262d2f01824bf765fd79c2e78c9a62da6f2b666591eb7bb9106d1d998ca18ab7](#gga9262d2f01824bf765fd79c2e78c9a62da6f2b666591eb7bb9106d1d998ca18ab7)&nbsp;=&nbsp;2&nbsp;} | 音频端口角色&nbsp;[更多...](#audioportrole) | 
| [AudioPortType](#audioporttype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1968248538083931,link:zh-cn_topic_0000001295254272.xml#ggaad9bcf12b3ab430a2f96a2af7505173bae8d72365ca8cd78b9245c874fbe06227](#ggaad9bcf12b3ab430a2f96a2af7505173bae8d72365ca8cd78b9245c874fbe06227)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref124855075083931,link:zh-cn_topic_0000001295254272.xml#ggaad9bcf12b3ab430a2f96a2af7505173ba52c6725d10840f7524b001ff71452439](#ggaad9bcf12b3ab430a2f96a2af7505173ba52c6725d10840f7524b001ff71452439)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref644032916083931,link:zh-cn_topic_0000001295254272.xml#ggaad9bcf12b3ab430a2f96a2af7505173baee29a064c72da8740173cd9e618681c1](#ggaad9bcf12b3ab430a2f96a2af7505173baee29a064c72da8740173cd9e618681c1)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1440590184083931,link:zh-cn_topic_0000001295254272.xml#ggaad9bcf12b3ab430a2f96a2af7505173ba1e16adb8496d8a0e28f0794334c425ec](#ggaad9bcf12b3ab430a2f96a2af7505173ba1e16adb8496d8a0e28f0794334c425ec)&nbsp;=&nbsp;3&nbsp;} | 音频端口类型&nbsp;[更多...](#audioporttype) | 
| [AudioSessionType](#audiosessiontype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref250576326083931,link:zh-cn_topic_0000001295254272.xml#ggab242c41d88b46812f204052ba8509ccea0b887608f198d74497a4eb44c51f9fce](#ggab242c41d88b46812f204052ba8509ccea0b887608f198d74497a4eb44c51f9fce)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1097777551083931,link:zh-cn_topic_0000001295254272.xml#ggab242c41d88b46812f204052ba8509ccea5cd6f49112fc8a0f97fd83b0fd48b25a](#ggab242c41d88b46812f204052ba8509ccea5cd6f49112fc8a0f97fd83b0fd48b25a),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1048520415083931,link:zh-cn_topic_0000001295254272.xml#ggab242c41d88b46812f204052ba8509ccead78430579e471af7153917fbcc5aa6b4](#ggab242c41d88b46812f204052ba8509ccead78430579e471af7153917fbcc5aa6b4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254272.xml#xref1887504163083931,link:zh-cn_topic_0000001295254272.xml#ggab242c41d88b46812f204052ba8509ccea8721a5a0498b144056551b41030afbb7](#ggab242c41d88b46812f204052ba8509ccea8721a5a0498b144056551b41030afbb7)&nbsp;} | 端口会话类型&nbsp;[更多...](#audiosessiontype) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [GetAudioManagerFuncs](#getaudiomanagerfuncs)&nbsp;(void) | 获取音频适配器管理接口的操作函数列表，详情参考[AudioManager](_audio_manager.md)[更多...](#getaudiomanagerfuncs) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| [AudioPort::dir](#dir) | 音频端口的类型。 | 
| [AudioPort::portId](#portid-14) | 音频端口的ID。 | 
| [AudioPort::portName](#portname) | 音频端口的名称。 | 
| [AudioAdapterDescriptor::adapterName](#adaptername) | 音频适配器的名称。 | 
| [AudioAdapterDescriptor::portNum](#portnum) | 一个音频适配器支持的端口数目。 | 
| [AudioAdapterDescriptor::ports](#ports) | 一个音频适配器支持的端口列表。 | 
| [AudioDeviceDescriptor::portId](#portid-24) | 音频端口ID。 | 
| [AudioDeviceDescriptor::pins](#pins) | 音频端口上的PIN脚（输出、输入）。 | 
| [AudioDeviceDescriptor::desc](#desc-15) | 以字符串命名的音频设备。 | 
| [AudioSceneDescriptor::SceneDesc::id](#id) | 音频场景的ID。 | 
| [AudioSceneDescriptor::SceneDesc::desc](#desc-35) | 以字符串命名的音频场景。 | 
| [AudioSceneDescriptor::scene](#scene) | 音频场景的名称。 | 
| [AudioSceneDescriptor::desc](#desc-25) | 音频设备描述符。 | 
| [AudioSampleAttributes::type](#type-13) | 音频类型。 | 
| [AudioSampleAttributes::interleaved](#interleaved) | 音频数据交织的标记。 | 
| [AudioSampleAttributes::format](#format) | 音频数据格式。 | 
| [AudioSampleAttributes::sampleRate](#samplerate) | 音频采样频率。 | 
| [AudioSampleAttributes::channelCount](#channelcount-12) | 音频通道数目，如单通道（mono）为1、立体声（stereo）为2。 | 
| [AudioSampleAttributes::period](#period) | 音频采样周期。 | 
| [AudioSampleAttributes::frameSize](#framesize) | 音频数据的帧大小。 | 
| [AudioSampleAttributes::isBigEndian](#isbigendian) | 音频数据的大端标志。 | 
| [AudioSampleAttributes::isSignedData](#issigneddata) | 音频数据的有符号或无符号标志。 | 
| [AudioSampleAttributes::startThreshold](#startthreshold) | 音频渲染开始阈值。 | 
| [AudioSampleAttributes::stopThreshold](#stopthreshold) | 音频渲染停止阈值。 | 
| [AudioSampleAttributes::silenceThreshold](#silencethreshold) | 音频捕获缓冲区阈值。 | 
| [AudioSampleAttributes::streamId](#streamid-12) | 渲染或捕获的音频标识符。 | 
| [AudioTimeStamp::tvSec](#tvsec) | tvSec时间，单位：秒。 | 
| [AudioTimeStamp::tvNSec](#tvnsec) | tvNSec时间，单位：纳秒。 | 
| [AudioSubPortCapability::portId](#portid-34) | 子端口ID。 | 
| [AudioSubPortCapability::desc](#desc-45) | 以字符串命名的子端口。 | 
| [AudioSubPortCapability::mask](#mask) | 数据透传模式。 | 
| [AudioPortCapability::deviceType](#devicetype) | 设备输出、输入类型。 | 
| [AudioPortCapability::deviceId](#deviceid) | 绑定（bind）设备ID，唯一的设备识别符。 | 
| [AudioPortCapability::hardwareMode](#hardwaremode) | 是否支持设备绑定处理。 | 
| [AudioPortCapability::formatNum](#formatnum) | 支持的音频格式数目。 | 
| [AudioPortCapability::formats](#formats) | 支持的音频格式。 | 
| [AudioPortCapability::sampleRateMasks](#sampleratemasks) | 支持的音频采样频率（8k、16k、32k、48k）。 | 
| [AudioPortCapability::channelMasks](#channelmasks) | 设备的声道布局掩码（mask）。 | 
| [AudioPortCapability::channelCount](#channelcount-22) | 支持的最大声道总数。 | 
| [AudioPortCapability::subPortsNum](#subportsnum) | 支持的子端口数目（仅用于输出设备）。 | 
| [AudioPortCapability::subPorts](#subports) | 支持的子端口列表。 | 
| [AudioPortCapability::supportSampleFormatNum](#supportsampleformatnum) | 支持的音频样本格式数量。 | 
| [AudioPortCapability::supportSampleFormats](#supportsampleformats) | 支持的音频样本格式。 | 
| [AudioMmapBufferDescripter::memoryAddress](#memoryaddress) | 指向mmap缓冲区的指针。 | 
| [AudioMmapBufferDescripter::memoryFd](#memoryfd) | mmap缓冲区的文件描述符。 | 
| [AudioMmapBufferDescripter::totalBufferFrames](#totalbufferframes) | 缓冲区总大小，单位：帧。 | 
| [AudioMmapBufferDescripter::transferFrameSize](#transferframesize) | 传输大小，单位：帧。 | 
| [AudioMmapBufferDescripter::isShareable](#isshareable) | mmap缓冲区是否可以在进程间共享。 | 
| [AudioDevExtInfo::moduleId](#moduleid-12) | 音频流绑定的模块ID。 | 
| [AudioDevExtInfo::type](#type-23) | 音频端口上的PIN脚（输出、输入）。 | 
| [AudioDevExtInfo::desc](#desc-55) | 地址描述。 | 
| [AudioMixExtInfo::moduleId](#moduleid-22) | 流所属模块标识符。 | 
| [AudioMixExtInfo::streamId](#streamid-22) | 由调用者传递的Render或Capture标识符。 | 
| [AudioSessionExtInfo::sessionType](#sessiontype) | 音频会话类型。 | 
| [AudioRouteNode::portId](#portid-44) | 音频端口ID。 | 
| [AudioRouteNode::role](#role) | 指定端口角色为sink或source。 | 
| [AudioRouteNode::type](#type-33) | 指定端口类型。 | 
| [AudioRouteNode::device](#device) | 设备特定信息。 | 
| [AudioRouteNode::mix](#mix) | 音轨特定信息。 | 
| [AudioRouteNode::session](#session) | 会话特定信息。 | 
| [AudioRoute::sourcesNum](#sourcesnum) | 发送端节点数量。 | 
| [AudioRoute::sources](#sources) | 发送端列表。 | 
| [AudioRoute::sinksNum](#sinksnum) | 接受端节点数量。 | 
| [AudioRoute::sinks](#sinks) | 接受端列表。 | 


## **详细描述**

Audio模块接口定义。

音频接口涉及自定义类型、驱动加载接口、驱动适配器接口、音频播放（render）接口、音频录音（capture）接口等。

**Since：**

1.0

**Version：**

1.0


## **类型定义说明**


### RenderCallback

  
```
typedef int32_t(* RenderCallback) (enum AudioCallbackType, void *reserved, void *cookie)
```

**描述：**

回调函数指针

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| AudioCallbackType | 回调函数响应类型 | 
| reserved | 保留字段 | 
| cookie | 用于传递数据 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

RegCallback


## **枚举类型说明**


### AudioCallbackType

  
```
enum AudioCallbackType
```

**描述：**

回调函数通知事件类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_NONBLOCK_WRITE_COMPELETED | 非阻塞式写完成 | 
| AUDIO_DRAIN_COMPELETED | DrainBuffer完成 | 
| AUDIO_FLUSH_COMPLETED | Flush完成 | 
| AUDIO_RENDER_FULL | Render缓冲区已满 | 
| AUDIO_ERROR_OCCUR | 发生了错误 | 


### AudioCategory

  
```
enum AudioCategory
```

**描述：**

音频类型（category）

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_IN_MEDIA | 媒体 | 
| AUDIO_IN_COMMUNICATION | 通信 | 
| AUDIO_IN_RINGTONE | 铃声 | 
| AUDIO_IN_CALL | 呼叫 | 


### AudioChannelMask

  
```
enum AudioChannelMask
```

**描述：**

音频通道掩码（mask）

定义音频声道的位置

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_FRONT_LEFT | 声道布局前左 | 
| AUDIO_CHANNEL_FRONT_RIGHT | 声道布局前右 | 
| AUDIO_CHANNEL_MONO | 单声道 | 
| AUDIO_CHANNEL_STEREO | 立体声，由左右声道组成（FRONT_LEFT&nbsp;\|&nbsp;FRONT_RIGHT） | 


### AudioChannelMode

  
```
enum AudioChannelMode
```

**描述：**

音频播放的通道模式

> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
> 下面的模式是针对双通道立体声的音频播放而设置，其他不支持。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_NORMAL | 正常模式，不做处理 | 
| AUDIO_CHANNEL_BOTH_LEFT | 两个声道全部为左声道声音 | 
| AUDIO_CHANNEL_BOTH_RIGHT | 两个声道全部为右声道声音 | 
| AUDIO_CHANNEL_EXCHANGE | 左右声道数据互换，左声道为右声道声音，右声道为左声道声音 | 
| AUDIO_CHANNEL_MIX | 左右两个声道输出为左右声道相加（混音） | 
| AUDIO_CHANNEL_LEFT_MUTE | 左声道静音，右声道播放原右声道声音 | 
| AUDIO_CHANNEL_RIGHT_MUTE | 右声道静音，左声道播放原左声道声音 | 
| AUDIO_CHANNEL_BOTH_MUTE | 左右声道均静音 | 


### AudioDrainNotifyType

  
```
enum AudioDrainNotifyType
```

**描述：**

DrainBuffer函数结束类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DRAIN_NORMAL_MODE | DrainBuffer在所有数据播放结束后返回 | 
| AUDIO_DRAIN_EARLY_MODE | DrainBuffer()在当前曲目的所有数据播放完之前返回，以便留出时间给音频服务做连续性曲目切换 | 


### AudioFormat

  
```
enum AudioFormat
```

**描述：**

音频格式

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_FORMAT_PCM_8_BIT | 8bit位宽pcm格式 | 
| AUDIO_FORMAT_PCM_16_BIT | 16bit位宽pcm格式 | 
| AUDIO_FORMAT_PCM_24_BIT | 24bit位宽pcm格式 | 
| AUDIO_FORMAT_PCM_32_BIT | 32bit位宽pcm格式 | 
| AUDIO_FORMAT_AAC_MAIN | AAC&nbsp;MAIN格式 | 
| AUDIO_FORMAT_AAC_LC | AAC&nbsp;LC格式 | 
| AUDIO_FORMAT_AAC_LD | AAC&nbsp;LD格式 | 
| AUDIO_FORMAT_AAC_ELD | AAC&nbsp;ELD格式 | 
| AUDIO_FORMAT_AAC_HE_V1 | AAC&nbsp;HE_V1格式 | 
| AUDIO_FORMAT_AAC_HE_V2 | AAC&nbsp;HE_V2格式 | 
| AUDIO_FORMAT_G711A | G711A格式 | 
| AUDIO_FORMAT_G711U | G711u格式 | 
| AUDIO_FORMAT_G726 | G726格式 | 


### AudioPortDirection

  
```
enum AudioPortDirection
```

**描述：**

音频端口的类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| PORT_OUT | 音频输出端口。 | 
| PORT_IN | 音频输入端口。 | 
| PORT_OUT_IN | 音频输出/入端口，同时支持输出和输入能力（OUT&nbsp;\|&nbsp;IN）。 | 


### AudioPortPassthroughMode

  
```
enum AudioPortPassthroughMode
```

**描述：**

音频端口的数据透传模式

  | 枚举值 | 描述 | 
| -------- | -------- |
| PORT_PASSTHROUGH_LPCM | 立体声pcm | 
| PORT_PASSTHROUGH_RAW | HDMI透传 | 
| PORT_PASSTHROUGH_HBR2LBR | 蓝光次世代音频降规格输出 | 
| PORT_PASSTHROUGH_AUTO | 根据HDMI&nbsp;EDID能力自动匹配 | 


### AudioPortPin

  
```
enum AudioPortPin
```

**描述：**

音频适配器端口的PIN脚

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIN_NONE | 无效PIN | 
| PIN_OUT_SPEAKER | 喇叭输出 | 
| PIN_OUT_HEADSET | 有线耳机输出 | 
| PIN_OUT_LINEOUT | Lineout输出 | 
| PIN_OUT_HDMI | HDMI输出 | 
| PIN_OUT_USB | USB设备输出 | 
| PIN_OUT_USB_EXT | 扩展&nbsp;USB&nbsp;设备输出 | 
| PIN_IN_MIC | Mic输入 | 
| PIN_IN_HS_MIC | 有线耳机Mic输入 | 
| PIN_IN_LINEIN | Linein输入 | 
| PIN_IN_USB_EXT | 扩展&nbsp;USB&nbsp;设备输入 | 


### AudioPortRole

  
```
enum AudioPortRole
```

**描述：**

音频端口角色

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_ROLE | 未指定端口角色 | 
| AUDIO_PORT_SOURCE_ROLE | 指定端口为发送端角色 | 
| AUDIO_PORT_SINK_ROLE | 指定端口为接受端角色 | 


### AudioPortType

  
```
enum AudioPortType
```

**描述：**

音频端口类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_TYPE | 未指定端口类型 | 
| AUDIO_PORT_DEVICE_TYPE | 指定端口为设备类型 | 
| AUDIO_PORT_MIX_TYPE | 指定端口类型为复合类型 | 
| AUDIO_PORT_SESSION_TYPE | 指定端口为会话类型 | 


### AudioSampleFormat

  
```
enum AudioSampleFormat
```

**描述：**

原始音频样本格式

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_FORMAT_S8 | 8bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S8P | 8bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U8 | 8bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U8P | 8bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S16 | 16bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S16P | 16bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U16 | 16bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U16P | 16bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S24 | 24bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S24P | 24bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U24 | 24bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U24P | 24bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S32 | 32bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S32P | 32bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U32 | 32bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U32P | 32bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S64 | 64bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S64P | 64bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U64 | 64bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U64P | 64bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_F32 | 32bit位宽浮点型交织样本 | 
| AUDIO_SAMPLE_FORMAT_F32P | 64bit位宽浮点型非交织样本 | 
| AUDIO_SAMPLE_FORMAT_F64 | 64bit位宽双精度浮点型交织样本 | 
| AUDIO_SAMPLE_FORMAT_F64P | 64bit位宽双精度浮点型非交织样本 | 
| AUDIO_SAMPLE_FMT_U8 | 无符号8位整型，打包格式 | 
| AUDIO_SAMPLE_FMT_S16 | 带符号16位整型，打包格式 | 
| AUDIO_SAMPLE_FMT_S32 | 带符号32位整型，打包格式 | 
| AUDIO_SAMPLE_FMT_FLOAT | 浮点型，打包格式 | 
| AUDIO_SAMPLE_FMT_DOUBLE | 双精度浮点型，打包格式 | 
| AUDIO_SAMPLE_FMT_U8P | 无符号8位整型，平面格式 | 
| AUDIO_SAMPLE_FMT_S16P | 带符号16位整型，平面格式 | 
| AUDIO_SAMPLE_FMT_S32P | 带符号32位整型，平面格式 | 
| AUDIO_SAMPLE_FMT_FLOATP | 浮点型，平面格式 | 
| AUDIO_SAMPLE_FMT_DOUBLEP | 双精度浮点型，平面格式 | 
| AUDIO_SAMPLE_FMT_INVALID | 无效采样格式 | 


### AudioSampleRatesMask

  
```
enum AudioSampleRatesMask
```

**描述：**

音频采样频率MASK

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_RATE_MASK_8000 | 8K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_12000 | 12K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_11025 | 11.025K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_16000 | 16K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_22050 | 22.050K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_24000 | 24K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_32000 | 32K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_44100 | 44.1K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_48000 | 48K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_64000 | 64K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_96000 | 96K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_INVALID | 无效的采样频率 | 


### AudioSessionType

  
```
enum AudioSessionType
```

**描述：**

端口会话类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_OUTPUT_STAGE_SESSION | 会话绑定到指定输出流 | 
| AUDIO_OUTPUT_MIX_SESSION | 会话绑定到特定音轨 | 
| AUDIO_ALLOCATE_SESSION | 会话ID需重新申请 | 
| AUDIO_INVALID_SESSION | 无效会话类型 | 


## **函数说明**


### GetAudioManagerFuncs()

  
```
struct AudioManager* GetAudioManagerFuncs (void )
```

**描述：**

获取音频适配器管理接口的操作函数列表，详情参考[AudioManager](_audio_manager.md)。

**返回：**

成功返回一个音频适配器管理接口的对象，失败返回NULL。


## **变量说明**


### adapterName

  
```
const char* AudioAdapterDescriptor::adapterName
```

**描述：**

音频适配器的名称。


### channelCount [1/2]

  
```
uint32_t AudioSampleAttributes::channelCount
```

**描述：**

音频通道数目，如单通道（mono）为1、立体声（stereo）为2。


### channelCount [2/2]

  
```
unsigned int AudioPortCapability::channelCount
```

**描述：**

支持的最大声道总数。


### channelMasks

  
```
enum AudioChannelMask AudioPortCapability::channelMasks
```

**描述：**

设备的声道布局掩码（mask），详情参考[AudioChannelMask](#audiochannelmask)。


### desc [1/5]

  
```
const char* AudioDeviceDescriptor::desc
```

**描述：**

以字符串命名的音频设备。


### desc [2/5]

  
```
struct AudioDeviceDescriptor AudioSceneDescriptor::desc
```

**描述：**

音频设备描述符。


### desc [3/5]

  
```
const char* AudioSceneDescriptor::SceneDesc::desc
```

**描述：**

以字符串命名的音频场景。


### desc [4/5]

  
```
const char* AudioSubPortCapability::desc
```

**描述：**

以字符串命名的子端口。


### desc [5/5]

  
```
const char* AudioDevExtInfo::desc
```

**描述：**

地址描述。


### deviceId

  
```
unsigned int AudioPortCapability::deviceId
```

**描述：**

绑定（bind）设备ID，唯一的设备识别符。


### deviceType

  
```
unsigned int AudioPortCapability::deviceType
```

**描述：**

设备输出、输入类型。


### dir

  
```
enum AudioPortDirection AudioPort::dir
```

**描述：**

音频端口的类型，详情参考[AudioPortDirection](#audioportdirection)。


### format

  
```
enum AudioFormat AudioSampleAttributes::format
```

**描述：**

音频数据格式，详情参考[AudioFormat](#audioformat)。


### formatNum

  
```
unsigned int AudioPortCapability::formatNum
```

**描述：**

支持的音频格式数目。


### formats

  
```
enum AudioFormat* AudioPortCapability::formats
```

**描述：**

支持的音频格式，详情参考[AudioFormat](#audioformat)。


### frameSize

  
```
uint32_t AudioSampleAttributes::frameSize
```

**描述：**

音频数据的帧大小。


### hardwareMode

  
```
bool AudioPortCapability::hardwareMode
```

**描述：**

是否支持设备绑定处理。


### id

  
```
unsigned int AudioSceneDescriptor::SceneDesc::id
```

**描述：**

音频场景的ID。


### interleaved

  
```
bool AudioSampleAttributes::interleaved
```

**描述：**

音频数据交织的标记。


### isBigEndian

  
```
bool AudioSampleAttributes::isBigEndian
```

**描述：**

音频数据的大端标志。


### isShareable

  
```
int32_t AudioMmapBufferDescripter::isShareable
```

**描述：**

mmap缓冲区是否可以在进程间共享。


### isSignedData

  
```
bool AudioSampleAttributes::isSignedData
```

**描述：**

音频数据的有符号或无符号标志


### mask

  
```
enum AudioPortPassthroughMode AudioSubPortCapability::mask
```

**描述：**

数据透传模式，详情参考[AudioPortPassthroughMode](#audioportpassthroughmode)。


### memoryAddress

  
```
void* AudioMmapBufferDescripter::memoryAddress
```

**描述：**

指向mmap缓冲区的指针。


### memoryFd

  
```
int32_t AudioMmapBufferDescripter::memoryFd
```

**描述：**

mmap缓冲区的文件描述符。


### moduleId [1/2]

  
```
int32_t AudioDevExtInfo::moduleId
```

**描述：**

音频流绑定的模块ID。


### moduleId [2/2]

  
```
int32_t AudioMixExtInfo::moduleId
```

**描述：**

流所属模块标识符。


### period

  
```
uint32_t AudioSampleAttributes::period
```

**描述：**

音频采样周期。


### pins

  
```
enum AudioPortPin AudioDeviceDescriptor::pins
```

**描述：**

音频端口上的PIN脚（输出、输入），详情参考[AudioPortPin](#audioportpin)。


### portId [1/4]

  
```
unsigned int AudioPort::portId
```

**描述：**

音频端口的ID。


### portId [2/4]

  
```
unsigned int AudioDeviceDescriptor::portId
```

**描述：**

音频端口ID。


### portId [3/4]

  
```
unsigned int AudioSubPortCapability::portId
```

**描述：**

子端口ID。


### portId [4/4]

  
```
int32_t AudioRouteNode::portId
```

**描述：**

音频端口ID。


### portName

  
```
const char* AudioPort::portName
```

**描述：**

音频端口的名称。


### portNum

  
```
unsigned int AudioAdapterDescriptor::portNum
```

**描述：**

一个音频适配器支持的端口数目。


### ports

  
```
struct AudioPort* AudioAdapterDescriptor::ports
```

**描述：**

一个音频适配器支持的端口列表。


### role

  
```
enum AudioPortRole AudioRouteNode::role
```

**描述：**

指定端口角色为sink或source。


### sampleRate

  
```
unsigned int AudioSampleAttributes::sampleRate
```

**描述：**

音频采样频率。


### sampleRateMasks

  
```
unsigned int AudioPortCapability::sampleRateMasks
```

**描述：**

支持的音频采样频率（8k、16k、32k、48k）。


### scene

  
```
union AudioSceneDescriptor::SceneDesc AudioSceneDescriptor::scene
```

**描述：**

音频场景的名称。


### sessionType

  
```
enum AudioSessionType AudioSessionExtInfo::sessionType
```

**描述：**

音频会话类型。


### silenceThreshold

  
```
uint32_t AudioSampleAttributes::silenceThreshold
```

**描述：**

音频捕获缓冲区阈值。


### sinks

  
```
const struct AudioRouteNode* AudioRoute::sinks
```

**描述：**

接受端列表。


### sinksNum

  
```
uint32_t AudioRoute::sinksNum
```

**描述：**

接受端节点数量。


### sources

  
```
const struct AudioRouteNode* AudioRoute::sources
```

**描述：**

发送端列表。


### sourcesNum

  
```
uint32_t AudioRoute::sourcesNum
```

**描述：**

发送端节点数量。


### startThreshold

  
```
uint32_t AudioSampleAttributes::startThreshold
```

**描述：**

音频渲染开始阈值。


### stopThreshold

  
```
uint32_t AudioSampleAttributes::stopThreshold
```

**描述：**

音频渲染停止阈值。


### streamId [1/2]

  
```
int32_t AudioSampleAttributes::streamId
```

**描述：**

渲染或捕获的音频标识符。


### streamId [2/2]

  
```
int32_t AudioMixExtInfo::streamId
```

**描述：**

由调用者传递的Render或Capture标识符。


### subPorts

  
```
struct AudioSubPortCapability* AudioPortCapability::subPorts
```

**描述：**

支持的子端口列表。


### subPortsNum

  
```
unsigned int AudioPortCapability::subPortsNum
```

**描述：**

支持的子端口数目（仅用于输出设备）。


### supportSampleFormatNum

  
```
uint32_t AudioPortCapability::supportSampleFormatNum
```

**描述：**

支持的音频样本格式数量。


### supportSampleFormats

  
```
enum AudioSampleFormat* AudioPortCapability::supportSampleFormats
```

**描述：**

支持的音频样本格式，详请参考[AudioSampleFormat](_codec.md#audiosampleformat)。


### totalBufferFrames

  
```
int32_t AudioMmapBufferDescripter::totalBufferFrames
```

**描述：**

缓冲区总大小，单位：帧。


### transferFrameSize

  
```
int32_t AudioMmapBufferDescripter::transferFrameSize
```

**描述：**

传输大小，单位：帧。


### tvNSec

  
```
int64_t AudioTimeStamp::tvNSec
```

**描述：**

tvNSec时间，单位：纳秒。


### tvSec

  
```
int64_t AudioTimeStamp::tvSec
```

**描述：**

tvSec时间，单位：秒。


### type [1/3]

  
```
enum AudioCategory AudioSampleAttributes::type
```

**描述：**

音频类型，详情参考[AudioCategory](#audiocategory)。


### type [2/3]

  
```
enum AudioPortPin AudioDevExtInfo::type
```

**描述：**

音频端口上的PIN脚（输出、输入），详情参考[AudioPortPin](#audioportpin)。


### type [3/3]

  
```
enum AudioPortType AudioRouteNode::type
```

**描述：**

指定端口类型。


### device

  
```
 struct AudioDevExtInfo AudioRouteNode::device
```

**描述：**

设备特定信息。


### mix

  
```
 struct AudioMixExtInfo AudioRouteNode::mix
```

**描述：**

音轨特定信息。


### session

  
```
 struct AudioSessionExtInfo AudioRouteNode::session
```

**描述：**

会话特定信息。
