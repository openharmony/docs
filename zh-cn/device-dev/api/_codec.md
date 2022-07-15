# Codec


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [codec_callback_if.h](codec__callback__if_8h.md) | 主要包括回调函数接口定义。 | 
| [codec_common_type.h](codec__common__type_8h.md) | Codec模块接口定义中使用的自定义数据类型。 | 
| [codec_component_if.h](codec__component__if_8h.md) | 主要包括Codec组件接口定义。 | 
| [codec_component_manager.h](codec__component__manager_8h.md) | 主要包括Codec组件管理类接口。 | 
| [codec_component_type.h](codec__component__type_8h.md) | Codec模块接口定义中使用的自定义数据类型。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [CodecCallbackType](_codec_callback_type.md) | Codec回调接口定义。&nbsp;[更多...](_codec_callback_type.md) | 
| [Alignment](_alignment.md) | 对齐结构定义，包含宽高的对齐值。&nbsp;[更多...](_alignment.md) | 
| [Rect](_rect.md) | 矩形的定义。&nbsp;[更多...](_rect.md) | 
| [RangeValue](_range_value.md) | 取值范围的定义。&nbsp;[更多...](_range_value.md) | 
| [CodecComponentType](_codec_component_type.md) | Codec组件接口定义。&nbsp;[更多...](_codec_component_type.md) | 
| [CodecComponentManager](_codec_component_manager.md) | Codec组件管理类接口定义。&nbsp;[更多...](_codec_component_manager.md) | 
| [VideoPortCap](_video_port_cap.md) | 定义视频编解码能力。&nbsp;[更多...](_video_port_cap.md) | 
| [AudioPortCap](_audio_port_cap.md) | 定义音频编解码能力。&nbsp;[更多...](_audio_port_cap.md) | 
| [PortCap](union_port_cap.md) | 定义音视频编解码能力。&nbsp;[更多...](union_port_cap.md) | 
| [CodecCompCapability](_codec_comp_capability.md) | 定义Codec编解码能力。&nbsp;[更多...](_codec_comp_capability.md) | 
| [OmxCodecBuffer](_omx_codec_buffer.md) | Codec&nbsp;buffer信息的定义。&nbsp;[更多...](_omx_codec_buffer.md) | 
| [CompVerInfo](_comp_ver_info.md) | 定义组件版本信息。&nbsp;[更多...](_comp_ver_info.md) | 
| [EventInfo](_event_info.md) | 定义事件上报信息。&nbsp;[更多...](_event_info.md) | 
| [SupportBufferType](_support_buffer_type.md) | SupportBuffer类型定义。&nbsp;[更多...](_support_buffer_type.md) | 
| [UseBufferType](_use_buffer_type.md) | UseBuffer类型定义。&nbsp;[更多...](_use_buffer_type.md) | 
| [GetBufferHandleUsageParams](_get_buffer_handle_usage_params.md) | BufferHandleUsage类型定义。&nbsp;[更多...](_get_buffer_handle_usage_params.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| SAMPLE_FMT_NUM&nbsp;&nbsp;&nbsp;&nbsp;32 | 采样格式最大值。 | 
| UUID_LENGTH&nbsp;&nbsp;&nbsp;&nbsp;128 | 定义UUID长度。 | 
| PIX_FORMAT_NUM&nbsp;&nbsp;&nbsp;&nbsp;16 | 支持的像素格式数组大小。 | 
| SAMPLE_FORMAT_NUM&nbsp;&nbsp;&nbsp;&nbsp;12 | 支持的音频采样格式数组大小。 | 
| SAMPLE_RATE_NUM&nbsp;&nbsp;&nbsp;&nbsp;16 | 支持的音频采样率数组大小。 | 
| CHANNEL_NUM&nbsp;&nbsp;&nbsp;&nbsp;16 | 支持的音频通道数组大小。 | 
| NAME_LENGTH&nbsp;&nbsp;&nbsp;&nbsp;32 | 组件名称大小。 | 
| PROFILE_NUM&nbsp;&nbsp;&nbsp;&nbsp;256 | 支持的profile数组大小。 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [CodecType](#codectype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1226574869083931,link:zh-cn_topic_0000001348174217.xml#gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261](#gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1400049721083931,link:zh-cn_topic_0000001348174217.xml#gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992](#gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1868464496083931,link:zh-cn_topic_0000001348174217.xml#gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4](#gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref351084008083931,link:zh-cn_topic_0000001348174217.xml#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54](#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref700718642083931,link:zh-cn_topic_0000001348174217.xml#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546](#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546)&nbsp;} | 枚举编解码的类型。&nbsp;[更多...](#codectype) | 
| [Profile](#profile)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1657963075083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f](#gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2118494792083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44](#gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44)&nbsp;=&nbsp;0x1000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref558204117083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b](#gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref719764591083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e](#gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1592491779083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8](#gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2093958921083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a](#gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1758087689083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc](#gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1928953065083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a](#gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a)&nbsp;=&nbsp;0x2000,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref166414379083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646](#gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref27655933083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246](#gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref231585948083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22](#gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22)&nbsp;=&nbsp;0x3000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2079710423083931,link:zh-cn_topic_0000001348174217.xml#gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6](#gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6)&nbsp;} | 枚举Codec规格。&nbsp;[更多...](#profile) | 
| [AudioSampleRate](#audiosamplerate)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1918023658083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd](#ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd)&nbsp;=&nbsp;8000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref864113223083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9](#ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9)&nbsp;=&nbsp;12000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1504523782083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81](#ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81)&nbsp;=&nbsp;11025,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref215148463083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee](#ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee)&nbsp;=&nbsp;16000,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref291741590083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54](#ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54)&nbsp;=&nbsp;22050,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref955843961083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d](#ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d)&nbsp;=&nbsp;24000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1548100102083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66](#ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66)&nbsp;=&nbsp;32000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1810460978083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2](#ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2)&nbsp;=&nbsp;44100,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1133692547083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c](#ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c)&nbsp;=&nbsp;48000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref735747655083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3](#ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3)&nbsp;=&nbsp;64000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1390737663083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd](#ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd)&nbsp;=&nbsp;96000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref261510881083931,link:zh-cn_topic_0000001348174217.xml#ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2](#ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2)&nbsp;} | 枚举音频采样率。&nbsp;[更多...](#audiosamplerate) | 
| [CodecCapsMask](#codeccapsmask)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1008129247083931,link:zh-cn_topic_0000001348174217.xml#gga9e2fbfb8a5881de2f495933f90f23b3fa30c688a80d3e64a3f5c2a13da89eef3c](#gga9e2fbfb8a5881de2f495933f90f23b3fa30c688a80d3e64a3f5c2a13da89eef3c)&nbsp;=&nbsp;0x1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1068884083931,link:zh-cn_topic_0000001348174217.xml#gga9e2fbfb8a5881de2f495933f90f23b3fa33911c21f51bcd1980645cac6d0729ca](#gga9e2fbfb8a5881de2f495933f90f23b3fa33911c21f51bcd1980645cac6d0729ca)&nbsp;=&nbsp;0x2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1215364952083931,link:zh-cn_topic_0000001348174217.xml#gga9e2fbfb8a5881de2f495933f90f23b3fa423e1b0d0a7dc9e4abeeded920aafb5b](#gga9e2fbfb8a5881de2f495933f90f23b3fa423e1b0d0a7dc9e4abeeded920aafb5b)&nbsp;=&nbsp;0x4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref825851473083931,link:zh-cn_topic_0000001348174217.xml#gga9e2fbfb8a5881de2f495933f90f23b3fa0da8339e6a216573d7dc3b8d4380d96d](#gga9e2fbfb8a5881de2f495933f90f23b3fa0da8339e6a216573d7dc3b8d4380d96d)&nbsp;=&nbsp;0x10000&nbsp;} | 枚举播放能力。&nbsp;[更多...](#codeccapsmask) | 
| [CodecProcessMode](#codecprocessmode)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref611947245083931,link:zh-cn_topic_0000001348174217.xml#gga5bec468886b760c542669b1615613dc4a0324b4efc6d2095c788806bf387955fe](#gga5bec468886b760c542669b1615613dc4a0324b4efc6d2095c788806bf387955fe)&nbsp;=&nbsp;0X1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref177076729083931,link:zh-cn_topic_0000001348174217.xml#gga5bec468886b760c542669b1615613dc4acba39cb03563db7f38634009575fdc21](#gga5bec468886b760c542669b1615613dc4acba39cb03563db7f38634009575fdc21)&nbsp;=&nbsp;0X2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1743979161083931,link:zh-cn_topic_0000001348174217.xml#gga5bec468886b760c542669b1615613dc4a2ebd571bd15c86c289b04617e78584ec](#gga5bec468886b760c542669b1615613dc4a2ebd571bd15c86c289b04617e78584ec)&nbsp;=&nbsp;0X4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1013858360083931,link:zh-cn_topic_0000001348174217.xml#gga5bec468886b760c542669b1615613dc4a73009c59abb2943e3363ad0aeefa81c1](#gga5bec468886b760c542669b1615613dc4a73009c59abb2943e3363ad0aeefa81c1)&nbsp;=&nbsp;0X100,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1641056342083931,link:zh-cn_topic_0000001348174217.xml#gga5bec468886b760c542669b1615613dc4ab943f6f6a762a47e663b74f42941fe9e](#gga5bec468886b760c542669b1615613dc4ab943f6f6a762a47e663b74f42941fe9e)&nbsp;=&nbsp;0X200,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1328533278083931,link:zh-cn_topic_0000001348174217.xml#gga5bec468886b760c542669b1615613dc4a5421710be01e8656530fb22f39e766ea](#gga5bec468886b760c542669b1615613dc4a5421710be01e8656530fb22f39e766ea)&nbsp;=&nbsp;0X400&nbsp;} | 枚举编解码处理模式。&nbsp;[更多...](#codecprocessmode) | 
| [AvCodecRole](#avcodecrole)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref173493394083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5ac261edd4c0d6eed15f6317024810dee2](#gga7c1ff03fc0cd5a8f738afae873b5d5d5ac261edd4c0d6eed15f6317024810dee2)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref688238919083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5adebef2ce1107d74e5d4f91d3452c823d](#gga7c1ff03fc0cd5a8f738afae873b5d5d5adebef2ce1107d74e5d4f91d3452c823d),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1904733606083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5af84180255d50e9ae94cedfc35ad19056](#gga7c1ff03fc0cd5a8f738afae873b5d5d5af84180255d50e9ae94cedfc35ad19056),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref978692029083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5a9e653abe452b248670825bd468f59d20](#gga7c1ff03fc0cd5a8f738afae873b5d5d5a9e653abe452b248670825bd468f59d20)&nbsp;=&nbsp;0x10000,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2040328027083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5ac9627d3deaca6bbf69f03c0dee1b6c05](#gga7c1ff03fc0cd5a8f738afae873b5d5d5ac9627d3deaca6bbf69f03c0dee1b6c05)&nbsp;=&nbsp;0x10000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1552553578083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5a033c0faacbd270fa2c539686e6d60551](#gga7c1ff03fc0cd5a8f738afae873b5d5d5a033c0faacbd270fa2c539686e6d60551),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref389010746083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5ae0170e900d835de44884f483b28b10f8](#gga7c1ff03fc0cd5a8f738afae873b5d5d5ae0170e900d835de44884f483b28b10f8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref297358192083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5a1bd136ced64ce1ab7b9e45fb0f5d75b6](#gga7c1ff03fc0cd5a8f738afae873b5d5d5a1bd136ced64ce1ab7b9e45fb0f5d75b6),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1063220299083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5a30e0f43909d411eb0f4c4fd8f9216dd8](#gga7c1ff03fc0cd5a8f738afae873b5d5d5a30e0f43909d411eb0f4c4fd8f9216dd8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref829862961083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5aec847c178f28118703297fb600907338](#gga7c1ff03fc0cd5a8f738afae873b5d5d5aec847c178f28118703297fb600907338),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1628407345083931,link:zh-cn_topic_0000001348174217.xml#gga7c1ff03fc0cd5a8f738afae873b5d5d5aee058a8e8a635efc2ed3328440a58e45](#gga7c1ff03fc0cd5a8f738afae873b5d5d5aee058a8e8a635efc2ed3328440a58e45)&nbsp;} | 枚举音视频编解码组件类型。&nbsp;[更多...](#avcodecrole) | 
| [AudioSampleFormat](#audiosampleformat)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2003574848083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a2d8a330d2cb71268562e1c4da0c4eabc](#gga97cfd5633b2133e7ebe42dbb9b03e757a2d8a330d2cb71268562e1c4da0c4eabc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref620047795083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a4eb79a5d6d99244902cfb5c65f225c80](#gga97cfd5633b2133e7ebe42dbb9b03e757a4eb79a5d6d99244902cfb5c65f225c80),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref142894648083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757ab6d04d1d87a9a243b195ab6be183600e](#gga97cfd5633b2133e7ebe42dbb9b03e757ab6d04d1d87a9a243b195ab6be183600e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref6705514083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757aeffb8620959b836e01622c7dc82ebc6d](#gga97cfd5633b2133e7ebe42dbb9b03e757aeffb8620959b836e01622c7dc82ebc6d),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref66699849083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a4422a2a04509e492ef823189d454d5a3](#gga97cfd5633b2133e7ebe42dbb9b03e757a4422a2a04509e492ef823189d454d5a3),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1172713521083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a11a1fb37c21f722383a37fc5e6075dfe](#gga97cfd5633b2133e7ebe42dbb9b03e757a11a1fb37c21f722383a37fc5e6075dfe),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1455558145083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757af961944b4c8e77ee56defc30e6e61eb5](#gga97cfd5633b2133e7ebe42dbb9b03e757af961944b4c8e77ee56defc30e6e61eb5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref104700168083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a08ba605e3e58479ebb7432ff5d6d0972](#gga97cfd5633b2133e7ebe42dbb9b03e757a08ba605e3e58479ebb7432ff5d6d0972),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1333780014083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a102520af7c50d1ee4951e472f5f921e4](#gga97cfd5633b2133e7ebe42dbb9b03e757a102520af7c50d1ee4951e472f5f921e4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref924177791083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757ae245cf6bd637c1f1304b38746f8940d6](#gga97cfd5633b2133e7ebe42dbb9b03e757ae245cf6bd637c1f1304b38746f8940d6),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2030780353083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a0d5fc3d14030aad7bc17d894bf4fc5c9](#gga97cfd5633b2133e7ebe42dbb9b03e757a0d5fc3d14030aad7bc17d894bf4fc5c9),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref350166403083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a0e8b7681ec3461988cb7fdd0f3616b2e](#gga97cfd5633b2133e7ebe42dbb9b03e757a0e8b7681ec3461988cb7fdd0f3616b2e),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2089368438083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a46819088770f843230d2b094fd8d14ba](#gga97cfd5633b2133e7ebe42dbb9b03e757a46819088770f843230d2b094fd8d14ba),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref828579509083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a7883f8a4bede55eb4ffaf6ecb47f6841](#gga97cfd5633b2133e7ebe42dbb9b03e757a7883f8a4bede55eb4ffaf6ecb47f6841),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1544127027083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757afae09ccb9fdae65e73e5584a4c3a6d16](#gga97cfd5633b2133e7ebe42dbb9b03e757afae09ccb9fdae65e73e5584a4c3a6d16),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2141626376083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a915025bfdcf9491a21b2d38dec7998cc](#gga97cfd5633b2133e7ebe42dbb9b03e757a915025bfdcf9491a21b2d38dec7998cc),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref584049049083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a2e5477f7cc05dcc271b50e570dfd0452](#gga97cfd5633b2133e7ebe42dbb9b03e757a2e5477f7cc05dcc271b50e570dfd0452),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1992155113083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757ab07b4d40994980a8012a79dc4a69a794](#gga97cfd5633b2133e7ebe42dbb9b03e757ab07b4d40994980a8012a79dc4a69a794),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1735639451083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a959950ea0f2b6c0e17d752640238c23b](#gga97cfd5633b2133e7ebe42dbb9b03e757a959950ea0f2b6c0e17d752640238c23b),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1946681433083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757aad2c58522f7d16111756c1731bf52044](#gga97cfd5633b2133e7ebe42dbb9b03e757aad2c58522f7d16111756c1731bf52044),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1380270506083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757ac3cb5729241a7f73210d97d4fe0002fe](#gga97cfd5633b2133e7ebe42dbb9b03e757ac3cb5729241a7f73210d97d4fe0002fe),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref614528807083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a1121b8995d1083f61b2fa0afcc45143f](#gga97cfd5633b2133e7ebe42dbb9b03e757a1121b8995d1083f61b2fa0afcc45143f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref898289380083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a72f064169d0282fa8a152aea546056c3](#gga97cfd5633b2133e7ebe42dbb9b03e757a72f064169d0282fa8a152aea546056c3),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2105995988083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a1f0e407cd152b27f7b0ff761d26bb300](#gga97cfd5633b2133e7ebe42dbb9b03e757a1f0e407cd152b27f7b0ff761d26bb300),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref181714056083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757aad65a5b895b3dba000167dbb6c19b9ab](#gga97cfd5633b2133e7ebe42dbb9b03e757aad65a5b895b3dba000167dbb6c19b9ab),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1331090330083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a40335eaa7ca378540941909ed02b51a0](#gga97cfd5633b2133e7ebe42dbb9b03e757a40335eaa7ca378540941909ed02b51a0),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref786053352083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757ab98feafb8396c0190a4fb719a15ab7c5](#gga97cfd5633b2133e7ebe42dbb9b03e757ab98feafb8396c0190a4fb719a15ab7c5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2109222277083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757ac2fb27a42b3f79e51dd71ce05b42f9db](#gga97cfd5633b2133e7ebe42dbb9b03e757ac2fb27a42b3f79e51dd71ce05b42f9db),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref612599514083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757afb8b12c44b4799f59a533609b4c360b5](#gga97cfd5633b2133e7ebe42dbb9b03e757afb8b12c44b4799f59a533609b4c360b5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref667066201083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a8eb00238e7aa21d69f056d9292eb64d9](#gga97cfd5633b2133e7ebe42dbb9b03e757a8eb00238e7aa21d69f056d9292eb64d9),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1989032944083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a93008db1a966fee4a91b515fedc78cec](#gga97cfd5633b2133e7ebe42dbb9b03e757a93008db1a966fee4a91b515fedc78cec),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1021492727083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a6bb874f2726bb94d08914b366ae947d6](#gga97cfd5633b2133e7ebe42dbb9b03e757a6bb874f2726bb94d08914b366ae947d6),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref257850676083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a8a635bbd6c5df1a8a0fadb1d9602ea74](#gga97cfd5633b2133e7ebe42dbb9b03e757a8a635bbd6c5df1a8a0fadb1d9602ea74),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref385515098083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a467bd88ce7f736a433425695ed0a0dbc](#gga97cfd5633b2133e7ebe42dbb9b03e757a467bd88ce7f736a433425695ed0a0dbc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref342798447083931,link:zh-cn_topic_0000001348174217.xml#gga97cfd5633b2133e7ebe42dbb9b03e757a5c8f7c2c0f84e70f609f8fd4ffd2c910](#gga97cfd5633b2133e7ebe42dbb9b03e757a5c8f7c2c0f84e70f609f8fd4ffd2c910)&nbsp;} | 枚举音频采样格式。&nbsp;[更多...](#audiosampleformat) | 
| [CodecBufferType](#codecbuffertype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1110288353083931,link:zh-cn_topic_0000001348174217.xml#ggaf63c168decbe7dc156ad3b4d575a0d46aba35b6e9b3ca08afcb012f723c07baee](#ggaf63c168decbe7dc156ad3b4d575a0d46aba35b6e9b3ca08afcb012f723c07baee)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2088381045083931,link:zh-cn_topic_0000001348174217.xml#ggaf63c168decbe7dc156ad3b4d575a0d46a4df6de0078bcf908fdb12d0ec1486899](#ggaf63c168decbe7dc156ad3b4d575a0d46a4df6de0078bcf908fdb12d0ec1486899)&nbsp;=&nbsp;0x1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref858706672083931,link:zh-cn_topic_0000001348174217.xml#ggaf63c168decbe7dc156ad3b4d575a0d46aaba95e9bf8ffbd7fe7512bc842d70ca5](#ggaf63c168decbe7dc156ad3b4d575a0d46aaba95e9bf8ffbd7fe7512bc842d70ca5)&nbsp;=&nbsp;0x2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref995851734083931,link:zh-cn_topic_0000001348174217.xml#ggaf63c168decbe7dc156ad3b4d575a0d46a90db1a10a238c832937c7a0e02287a79](#ggaf63c168decbe7dc156ad3b4d575a0d46a90db1a10a238c832937c7a0e02287a79)&nbsp;=&nbsp;0x4,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2022100500083931,link:zh-cn_topic_0000001348174217.xml#ggaf63c168decbe7dc156ad3b4d575a0d46a931ecc36727f5eb3baba00e0d2b8771e](#ggaf63c168decbe7dc156ad3b4d575a0d46a931ecc36727f5eb3baba00e0d2b8771e)&nbsp;=&nbsp;0x8&nbsp;} | 定义buffer类型。&nbsp;[更多...](#codecbuffertype) | 
| [ShareMemTypes](#sharememtypes)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref2102640873083931,link:zh-cn_topic_0000001348174217.xml#ggae84516e039a3963772dfeebd4937cb8daa268821c7f672c1b968aeed0ad745dd0](#ggae84516e039a3963772dfeebd4937cb8daa268821c7f672c1b968aeed0ad745dd0)&nbsp;=&nbsp;0x1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1705786981083931,link:zh-cn_topic_0000001348174217.xml#ggae84516e039a3963772dfeebd4937cb8daa5af6f1eec0b9f19c72a1085cef7c0ff](#ggae84516e039a3963772dfeebd4937cb8daa5af6f1eec0b9f19c72a1085cef7c0ff)&nbsp;=&nbsp;0x2&nbsp;} | 枚举共享内存类型。&nbsp;[更多...](#sharememtypes) | 
| [OmxIndexCodecExType](#omxindexcodecextype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1239243344083931,link:zh-cn_topic_0000001348174217.xml#gga0ab3a4efe29745d2b49944c4014e0c28a228f8b3c93f68da516a76db3f594625d](#gga0ab3a4efe29745d2b49944c4014e0c28a228f8b3c93f68da516a76db3f594625d)&nbsp;=&nbsp;OMX_IndexKhronosExtensions&nbsp;+&nbsp;0x00a00000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref234312713083931,link:zh-cn_topic_0000001348174217.xml#gga0ab3a4efe29745d2b49944c4014e0c28aaab75f888d711f3168327535312117fa](#gga0ab3a4efe29745d2b49944c4014e0c28aaab75f888d711f3168327535312117fa),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref1353327798083931,link:zh-cn_topic_0000001348174217.xml#gga0ab3a4efe29745d2b49944c4014e0c28a353c3ccfb9985619526c0c7a28c9cce8](#gga0ab3a4efe29745d2b49944c4014e0c28a353c3ccfb9985619526c0c7a28c9cce8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref663473178083931,link:zh-cn_topic_0000001348174217.xml#gga0ab3a4efe29745d2b49944c4014e0c28a3dea5e61dc211290d54d79d35679199d](#gga0ab3a4efe29745d2b49944c4014e0c28a3dea5e61dc211290d54d79d35679199d)&nbsp;} | 枚举Codec扩展index。&nbsp;[更多...](#omxindexcodecextype) | 
| [OmxVideoExType](#omxvideoextype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348174217.xml#xref979218263083931,link:zh-cn_topic_0000001348174217.xml#ggab1cbacdf16bc8912e69547b37022a9c1acf4ea0b624499e3a53c3b36f6217f6fe](#ggab1cbacdf16bc8912e69547b37022a9c1acf4ea0b624499e3a53c3b36f6217f6fe)&nbsp;=&nbsp;11&nbsp;} | 枚举Codec扩展编码类型。&nbsp;[更多...](#omxvideoextype) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [CodecCallbackTypeGet](#codeccallbacktypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecCallbackType对象。&nbsp;[更多...](#codeccallbacktypeget) | 
| [CodecCallbackTypeRelease](#codeccallbacktyperelease)&nbsp;(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*instance) | 释放CodecCallbackType对象。&nbsp;[更多...](#codeccallbacktyperelease) | 
| [CodecComponentTypeGet](#codeccomponenttypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecComponentType对象。&nbsp;[更多...](#codeccomponenttypeget) | 
| [CodecComponentTypeRelease](#codeccomponenttyperelease)&nbsp;(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*instance) | 释放CodecComponentType对象。&nbsp;[更多...](#codeccomponenttyperelease) | 
| [GetCodecComponentManager](#getcodeccomponentmanager)&nbsp;(void) | 实例化CodecComponentManager对象。&nbsp;[更多...](#getcodeccomponentmanager) | 
| [CodecComponentManagerRelease](#codeccomponentmanagerrelease)&nbsp;(void) | 释放CodecComponentManager对象。&nbsp;[更多...](#codeccomponentmanagerrelease) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackType::remote](#remote) | 指向HdfRemoteService的指针。&nbsp;[更多...](#remote) | 
| (&nbsp;[CodecCallbackType::EventHandler](#eventhandler)&nbsp;)(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*self,&nbsp;enum&nbsp;OMX_EVENTTYPE&nbsp;event,&nbsp;struct&nbsp;[EventInfo](_event_info.md)&nbsp;\*info) | 事件上报。&nbsp;[更多...](#eventhandler) | 
| (&nbsp;[CodecCallbackType::EmptyBufferDone](#emptybufferdone)&nbsp;)(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*self,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 上报输入buffer编码或者解码处理完毕。&nbsp;[更多...](#emptybufferdone) | 
| (&nbsp;[CodecCallbackType::FillBufferDone](#fillbufferdone)&nbsp;)(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*self,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 上报输出buffer填充完毕。&nbsp;[更多...](#fillbufferdone) | 
| (&nbsp;[CodecComponentType::GetComponentVersion](#getcomponentversion)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;struct&nbsp;[CompVerInfo](_comp_ver_info.md)&nbsp;\*verInfo) | 获取Codec组件版本号。&nbsp;[更多...](#getcomponentversion) | 
| (&nbsp;[CodecComponentType::SendCommand](#sendcommand)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;enum&nbsp;OMX_COMMANDTYPE&nbsp;cmd,&nbsp;uint32_t&nbsp;param,&nbsp;int8_t&nbsp;\*cmdData,&nbsp;uint32_t&nbsp;cmdDataLen) | 发送命令给组件。&nbsp;[更多...](#sendcommand) | 
| (&nbsp;[CodecComponentType::GetParameter](#getparameter)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;paramIndex,&nbsp;int8_t&nbsp;\*paramStruct,&nbsp;uint32_t&nbsp;paramStructLen) | 获取组件参数设置。&nbsp;[更多...](#getparameter) | 
| (&nbsp;[CodecComponentType::SetParameter](#setparameter)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*paramStruct,&nbsp;uint32_t&nbsp;paramStructLen) | 设置组件需要的参数。&nbsp;[更多...](#setparameter) | 
| (&nbsp;[CodecComponentType::GetConfig](#getconfig)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*cfgStruct,&nbsp;uint32_t&nbsp;cfgStructLen) | 获取组件的配置结构。&nbsp;[更多...](#getconfig) | 
| (&nbsp;[CodecComponentType::SetConfig](#setconfig)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*cfgStruct,&nbsp;uint32_t&nbsp;cfgStructLen) | 设置组件的配置。&nbsp;[更多...](#setconfig) | 
| (&nbsp;[CodecComponentType::GetExtensionIndex](#getextensionindex)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;const&nbsp;char&nbsp;\*paramName,&nbsp;uint32_t&nbsp;\*indexType) | 根据字符串获取组件的扩展索引。&nbsp;[更多...](#getextensionindex) | 
| (&nbsp;[CodecComponentType::GetState](#getstate)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;enum&nbsp;OMX_STATETYPE&nbsp;\*state) | 获取组件的当前状态。&nbsp;[更多...](#getstate) | 
| (&nbsp;[CodecComponentType::ComponentTunnelRequest](#componenttunnelrequest)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;port,&nbsp;int32_t&nbsp;tunneledComp,&nbsp;uint32_t&nbsp;tunneledPort,&nbsp;struct&nbsp;OMX_TUNNELSETUPTYPE&nbsp;\*tunnelSetup) | 设置组件采用Tunnel方式通信。&nbsp;[更多...](#componenttunnelrequest) | 
| (&nbsp;[CodecComponentType::UseBuffer](#usebuffer)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 指定组件端口的buffer。&nbsp;[更多...](#usebuffer) | 
| (&nbsp;[CodecComponentType::AllocateBuffer](#allocatebuffer)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 向组件申请端口buffer。&nbsp;[更多...](#allocatebuffer) | 
| (&nbsp;[CodecComponentType::FreeBuffer](#freebuffer)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 释放buffer。&nbsp;[更多...](#freebuffer) | 
| (&nbsp;[CodecComponentType::EmptyThisBuffer](#emptythisbuffer)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 编解码输入待处理buffer。&nbsp;[更多...](#emptythisbuffer) | 
| (&nbsp;[CodecComponentType::FillThisBuffer](#fillthisbuffer)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 编解码输出填充buffer。&nbsp;[更多...](#fillthisbuffer) | 
| (&nbsp;[CodecComponentType::SetCallbacks](#setcallbacks)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*callback,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen) | 设置Codec组件的回调函数。&nbsp;[更多...](#setcallbacks) | 
| (&nbsp;[CodecComponentType::ComponentDeInit](#componentdeinit)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self) | 组件去初始化。&nbsp;[更多...](#componentdeinit) | 
| (&nbsp;[CodecComponentType::UseEglImage](#useeglimage)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer,&nbsp;uint32_t&nbsp;portIndex,&nbsp;int8_t&nbsp;\*eglImage,&nbsp;uint32_t&nbsp;eglImageLen) | 使用已在EGL中申请的空间。&nbsp;[更多...](#useeglimage) | 
| (&nbsp;[CodecComponentType::ComponentRoleEnum](#componentroleenum)&nbsp;)(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*self,&nbsp;uint8_t&nbsp;\*role,&nbsp;uint32_t&nbsp;roleLen,&nbsp;uint32_t&nbsp;index) | 获取组件角色。&nbsp;[更多...](#componentroleenum) | 


## **详细描述**

Codec模块接口定义。

Codec模块涉及自定义类型、音视频编解码组件初始化、参数设置、数据的轮转和控制等。

**Since：**

3.1

**Version：**

2.0


## **枚举类型说明**


### AudioSampleFormat

  
```
enum AudioSampleFormat
```

**描述：**

枚举音频采样格式。

- 对于planar的采样格式，每个声道的数据是独立存储在data中。

- 对于packed的采样格式，只使用第一个data，每个声道的数据是交错存储的。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_FORMAT_S8 | 8bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S8P | 8bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U8 | 8bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U8P | 8bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S16 | 16bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S16P | 16bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U16 | 16bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U16P | 16bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S24 | 24bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S24P | 24bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U24 | 24bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U24P | 24bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S32 | 32bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S32P | 32bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U32 | 32bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U32P | 32bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S64 | 64bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S64P | 64bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U64 | 64bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U64P | 64bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F32 | 32bit位宽浮点型交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F32P | 64bit位宽浮点型非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F64 | 64bit位宽双精度浮点型交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F64P | 64bit位宽双精度浮点型非交织样本。 | 
| AUDIO_SAMPLE_FMT_U8 | 无符号8位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_S16 | 带符号16位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_S32 | 带符号32位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_FLOAT | 浮点型，打包格式。 | 
| AUDIO_SAMPLE_FMT_DOUBLE | 双精度浮点型，打包格式。 | 
| AUDIO_SAMPLE_FMT_U8P | 无符号8位整型，平面格式。 | 
| AUDIO_SAMPLE_FMT_S16P | 带符号16位整型，平面格式。 | 
| AUDIO_SAMPLE_FMT_S32P | 带符号32位整型，平面格式。 | 
| AUDIO_SAMPLE_FMT_FLOATP | 浮点型，平面格式。 | 
| AUDIO_SAMPLE_FMT_DOUBLEP | 双精度浮点型，平面格式。 | 
| AUDIO_SAMPLE_FMT_INVALID | 无效采样格式。 | 


### AudioSampleRate

  
```
enum AudioSampleRate
```

**描述：**

枚举音频采样率

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUD_SAMPLE_RATE_8000 | 8K采样率 | 
| AUD_SAMPLE_RATE_12000 | 12K采样率 | 
| AUD_SAMPLE_RATE_11025 | 11.025K采样率 | 
| AUD_SAMPLE_RATE_16000 | 16K采样率 | 
| AUD_SAMPLE_RATE_22050 | 22.050K采样率 | 
| AUD_SAMPLE_RATE_24000 | 24K采样率 | 
| AUD_SAMPLE_RATE_32000 | 32K采样率 | 
| AUD_SAMPLE_RATE_44100 | 44.1K采样率 | 
| AUD_SAMPLE_RATE_48000 | 48K采样率 | 
| AUD_SAMPLE_RATE_64000 | 64K采样率 | 
| AUD_SAMPLE_RATE_96000 | 96K采样率 | 
| AUD_SAMPLE_RATE_INVALID | 无效采样率 | 


### AvCodecRole

  
```
enum AvCodecRole
```

**描述：**

枚举音视频编解码组件类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_ROLETYPE_IMAGE_JPEG | 图像JPEG媒体类型 | 
| MEDIA_ROLETYPE_VIDEO_AVC | 视频H.264媒体类型 | 
| MEDIA_ROLETYPE_VIDEO_HEVC | 视频H.265媒体类型 | 
| MEDIA_ROLETYPE_AUDIO_FIRST | 音频编解码器类型 | 
| MEDIA_ROLETYPE_AUDIO_AAC | 音频AAC媒体类型 | 
| MEDIA_ROLETYPE_AUDIO_G711A | 音频G711A媒体类型 | 
| MEDIA_ROLETYPE_AUDIO_G711U | 音频G711U媒体类型 | 
| MEDIA_ROLETYPE_AUDIO_G726 | 音频G726媒体类型 | 
| MEDIA_ROLETYPE_AUDIO_PCM | 音频PCM媒体类型 | 
| MEDIA_ROLETYPE_AUDIO_MP3 | 音频MP3媒体类型 | 
| MEDIA_ROLETYPE_INVALID | 无效媒体类型 | 


### CodecBufferType

  
```
enum CodecBufferType
```

**描述：**

定义buffer类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_BUFFER_TYPE_INVALID | 无效buffer类型 | 
| CODEC_BUFFER_TYPE_VIRTUAL_ADDR | 虚拟地址类型 | 
| CODEC_BUFFER_TYPE_AVSHARE_MEM_FD | 共享内存类型 | 
| CODEC_BUFFER_TYPE_HANDLE | handle类型 | 
| CODEC_BUFFER_TYPE_DYNAMIC_HANDLE | 动态handle类型 | 


### CodecCapsMask

  
```
enum CodecCapsMask
```

**描述：**

枚举播放能力。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_CAP_ADAPTIVE_PLAYBACK | 自适应播放能力 | 
| CODEC_CAP_SECURE_PLAYBACK | 安全播放能力 | 
| CODEC_CAP_TUNNEL_PLAYBACK | 通道播放能力 | 
| CODEC_CAP_MULTI_PLANE | 视频图像平面/音频通道平面能力 | 


### CodecProcessMode

  
```
enum CodecProcessMode
```

**描述：**

枚举编解码处理模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PROCESS_BLOCKING_INPUT_BUFFER | 同步模式输入buffer | 
| PROCESS_BLOCKING_OUTPUT_BUFFER | 同步模式输出buffer | 
| PROCESS_BLOCKING_CONTROL_FLOW | 同步模式控制流 | 
| PROCESS_NONBLOCKING_INPUT_BUFFER | 异步模式输入buffer | 
| PROCESS_NONBLOCKING_OUTPUT_BUFFER | 异步模式输出buffer | 
| PROCESS_NONBLOCKING_CONTROL_FLOW | 异步模式控制流 | 


### CodecType

  
```
enum CodecType
```

**描述：**

枚举编解码的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_DECODER | 视频解码类型 | 
| VIDEO_ENCODER | 视频编码类型 | 
| AUDIO_DECODER | 音频解码类型 | 
| AUDIO_ENCODER | 音频编码类型 | 
| INVALID_TYPE | 无效类型 | 


### OmxIndexCodecExType

  
```
enum OmxIndexCodecExType
```

**描述：**

枚举Codec扩展index。

  | 枚举值 | 描述 | 
| -------- | -------- |
| OMX_IndexExtBufferTypeStartUnused | BufferType&nbsp;扩展index | 
| OMX_IndexParamSupportBufferType | SupportBuffer类型 | 
| OMX_IndexParamUseBufferType | UseBuffer类型 | 
| OMX_IndexParamGetBufferHandleUsage | GetBufferHandleUsage类型 | 


### OmxVideoExType

  
```
enum OmxVideoExType
```

**描述：**

枚举Codec扩展编码类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| OMX_VIDEO_CodingHEVC | HEVC编码类型 | 


### Profile

  
```
enum Profile
```

**描述：**

枚举Codec规格。

  | 枚举值 | 描述 | 
| -------- | -------- |
| INVALID_PROFILE | 无效的规格。 | 
| AAC_LC_PROFILE | AAC低复杂度规格。 | 
| AAC_MAIN_PROFILE | AAC主规格。 | 
| AAC_HE_V1_PROFILE | AAC高效率和频带重现规格，又称为HEAAC，AAC+，或者AACPlusV1。 | 
| AAC_HE_V2_PROFILE | AAC高效率和频带重现以及变量立体声规格，又称为AAC++或者AACPlusV2。 | 
| AAC_LD_PROFILE | AAC低延迟规格。 | 
| AAC_ELD_PROFILE | AAC增强型低延迟规格。 | 
| AVC_BASELINE_PROFILE | H.264低规格。 | 
| AVC_MAIN_PROFILE | H.264主规格。 | 
| AVC_HIGH_PROFILE | H.264高规格。 | 
| HEVC_MAIN_PROFILE | H.265主规格。 | 
| HEVC_MAIN_10_PROFILE | H.265&nbsp;10比特主规格。 | 


### ShareMemTypes

  
```
enum ShareMemTypes
```

**描述：**

枚举共享内存类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| READ_WRITE_TYPE | 可读可写的共享内存类型 | 
| READ_ONLY_TYPE | 可读的共享内存类型 | 


## **函数说明**


### CodecCallbackTypeGet()

  
```
struct CodecCallbackType* CodecCallbackTypeGet (struct HdfRemoteService * remote)
```

**描述：**

实例化CodecCallbackType对象。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| remote | 输入参数，指向HdfRemoteService的指针。 | 

**返回：**

实例化CodecCallbackType对象。

**Since：**

3.1


### CodecCallbackTypeRelease()

  
```
void CodecCallbackTypeRelease (struct CodecCallbackType * instance)
```

**描述：**

释放CodecCallbackType对象。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| instance | 输入参数，指向CodecCallbackType实例的指针。 | 

**Since：**

3.1


### CodecComponentManagerRelease()

  
```
void CodecComponentManagerRelease (void )
```

**描述：**

释放CodecComponentManager对象。

**Since：**

3.1


### CodecComponentTypeGet()

  
```
struct CodecComponentType* CodecComponentTypeGet (struct HdfRemoteService * remote)
```

**描述：**

实例化CodecComponentType对象。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| remote | 输入参数，指向RemoteService的指针。 | 

**返回：**

实例化的CodecComponentType对象。

**Since：**

3.1


### CodecComponentTypeRelease()

  
```
void CodecComponentTypeRelease (struct CodecComponentType * instance)
```

**描述：**

释放CodecComponentType对象。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| instance | 输入参数，指向CodecComponentType实例的指针。 | 

**Since：**

3.1


### GetCodecComponentManager()

  
```
struct CodecComponentManager* GetCodecComponentManager (void )
```

**描述：**

实例化CodecComponentManager对象。

**返回：**

实例化的CodecComponentManager对象。

**Since：**

3.1


## **变量说明**


### AllocateBuffer

  
```
int32_t(* CodecComponentType::AllocateBuffer) (struct CodecComponentType *self, uint32_t portIndex, struct OmxCodecBuffer *buffer)
```

**描述：**

向组件申请端口buffer。

向组件申请分配新的buffer，此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且用户已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| buffer | 输入输出参数，指向要申请的buffer结构体[OmxCodecBuffer](_omx_codec_buffer.md)指针。 | 

**返回：**

HDF_SUCCESS 表示申请buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，申请buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，申请buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，申请buffer失败。

**Since：**

3.1


### ComponentDeInit

  
```
int32_t(* CodecComponentType::ComponentDeInit) (struct CodecComponentType *self)
```

**描述：**

组件去初始化。

调用此接口使组件去初始化，当组件处于OMX_StateLoaded状态时，将直接关闭组件。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 

**返回：**

HDF_SUCCESS 表示去初始化成功。

HDF_ERR_INVALID_PARAM 表示参数无效，去初始化失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，去初始化失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，去初始化失败。

**Since：**

3.1


### ComponentRoleEnum

  
```
int32_t(* CodecComponentType::ComponentRoleEnum) (struct CodecComponentType *self, uint8_t *role, uint32_t roleLen, uint32_t index)
```

**描述：**

获取组件角色。

根据组件角色索引获取对应组件角色。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| role | 输出参数，角色名称。 | 
| roleLen | 输入参数，role字节数。 | 
| index | 输入参数，角色的索引，一个组件可能支持多种角色。 | 

**返回：**

HDF_SUCCESS 表示获取角色成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取角色失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取角色失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取角色失败。

**Since：**

3.1


### ComponentTunnelRequest

  
```
int32_t(* CodecComponentType::ComponentTunnelRequest) (struct CodecComponentType *self, uint32_t port, int32_t tunneledComp, uint32_t tunneledPort, struct OMX_TUNNELSETUPTYPE *tunnelSetup)
```

**描述：**

设置组件采用Tunnel方式通信。

当组件处于OMX_StateLoaded 状态时，用户通过调用此接口确定组件是否可以进行Tunnel传输，如果可以则设置组件的Tunnel传输。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| port | 输入参数，组件设置的端口。 | 
| tunneledComp | 输入参数，组件的tunnel&nbsp;handle。 | 
| tunneledPort | 输入参数，组件用来Tunnel通信的端口。 | 
| tunnelSetup | 输入输出参数，指向Tunnel设置的结构体**OMX_TUNNELSETUPTYPE**指针。 | 

**返回：**

HDF_SUCCESS 表示设置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置失败。

**Since：**

3.1


### EmptyBufferDone

  
```
int32_t(* CodecCallbackType::EmptyBufferDone) (struct CodecCallbackType *self, int8_t *appData, uint32_t appDataLen, const struct OmxCodecBuffer *buffer)
```

**描述：**

上报输入buffer编码或者解码处理完毕。

组件运行过程中向上报告输入buffer已经使用完毕。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的callback指针。 | 
| appData | 输入参数，上层数据，通常是设置回调时给入的上层实例。 | 
| appDataLen | 输入参数，appData字节数。 | 
| buffer | 输入参数，已经处理完毕的输入buffer信息[OmxCodecBuffer](_omx_codec_buffer.md)。 | 

**返回：**

HDF_SUCCESS 表示上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，上报失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，上报失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，上报失败。

**Since：**

3.1


### EmptyThisBuffer

  
```
int32_t(* CodecComponentType::EmptyThisBuffer) (struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)
```

**描述：**

编解码输入待处理buffer。

此接口在组件处于OMX_StateExecuting或者OMX_StatePause状态时调用。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| buffer | 输入参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 

**返回：**

HDF_SUCCESS 表示输入buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，输入buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，输入buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，输入buffer失败。

**Since：**

3.1


### EventHandler

  
```
int32_t(* CodecCallbackType::EventHandler) (struct CodecCallbackType *self, enum OMX_EVENTTYPE event, struct EventInfo *info)
```

**描述：**

事件上报。

组件运行过程中向上报告错误事件、命令完成事件、端口设置更改事件等。

- 当eEvent为OMX_EventCmdComplete，eventData为NULL，data1数据为OMX_COMMANDTYPE，此时，当data1为OMX_CommandStateSet，data2表示状态，其它情况下，data2表示端口。

- 当event为OMX_EventError时，data1表示错误码，data2和eventData都为0。

- 当event为OMX_EventMark时，data1和data2都为0，eventData指向mark指针。

- 当event为OMX_EventPortSettingsChanged时，data1表示端口，data2和eventData为0。

- 当event为OMX_EventBufferFlag时，data1表示端口，data2表示flag，eventData为0。

- 当event为OMX_EventResourcesAcquired或OMX_EventDynamicResourcesAvailable时，data1、data2和eventData都为0。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的callback指针。 | 
| event | 输入参数，要通知的事件类型，详见**OMX_EVENTTYPE**。 | 
| info | 输入参数，指向事件上报携带的信息指针，详见[EventInfo](_event_info.md)。 | 

**返回：**

HDF_SUCCESS 表示事件上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，事件上报失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，事件上报失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，事件上报失败。

**Since：**

3.1


### FillBufferDone

  
```
int32_t(* CodecCallbackType::FillBufferDone) (struct CodecCallbackType *self, int8_t *appData, uint32_t appDataLen, struct OmxCodecBuffer *buffer)
```

**描述：**

上报输出buffer填充完毕。

组件运行过程中向上报告输出buffer已经填充完毕。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的callback指针。 | 
| appData | 输入参数，上层数据，通常是设置回调时给入的上层实例。 | 
| appDataLen | 输入参数，appData字节数。 | 
| buffer | 输入参数，已经填充完毕的buffer信息[OmxCodecBuffer](_omx_codec_buffer.md)。 | 

**返回：**

HDF_SUCCESS 表示上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，上报失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，上报失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，上报失败。

**Since：**

3.1


### FillThisBuffer

  
```
int32_t(* CodecComponentType::FillThisBuffer) (struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)
```

**描述：**

编解码输出填充buffer。

此接口在组件处于OMX_StateExecuting或者OMX_StatePause状态时调用。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| buffer | 输入参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 

**返回：**

HDF_SUCCESS 表示填充buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，填充buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，填充buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，填充buffer失败。

**Since：**

3.1


### FreeBuffer

  
```
int32_t(* CodecComponentType::FreeBuffer) (struct CodecComponentType *self, uint32_t portIndex, const struct OmxCodecBuffer *buffer)
```

**描述：**

释放buffer。

此接口在以下情况下使用：

- 当组件处于OMX_StateIdle状态，并且已经向组件发送OMX_StateLoaded状态转换请求。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle时调用。

- 此接口调用可随时进行，但是如果未在上述情况下执行，可能会导致组件上报OMX_ErrorPortUnpopulated事件。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| buffer | 输入参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 

**返回：**

HDF_SUCCESS 表示释放buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，释放buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，释放buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，释放buffer失败。

**Since：**

3.1


### GetComponentVersion

  
```
int32_t(* CodecComponentType::GetComponentVersion) (struct CodecComponentType *self, struct CompVerInfo *verInfo)
```

**描述：**

获取Codec组件版本号。

通过查询组件，返回组件版本信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| verInfo | 输出参数，指向组件版本信息的指针，详见[CompVerInfo](_comp_ver_info.md)。 | 

**返回：**

HDF_SUCCESS 表示获取版本号成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取版本号失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取版本号失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取版本号失败。

**Since：**

3.1


### GetConfig

  
```
int32_t(* CodecComponentType::GetConfig) (struct CodecComponentType *self, uint32_t index, int8_t *cfgStruct, uint32_t cfgStructLen)
```

**描述：**

获取组件的配置结构。

加载组件后可以随时调用此接口获取组件的配置。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| index | 输入参数，待填充结构的索引，详见**OMX_INDEXTYPE**。 | 
| cfgStruct | 输入输出参数，指向由组件填充的应用程序分配的结构体指针。 | 
| cfgStructLen | 输入参数，上层传入的cfgStruct字节数。 | 

**返回：**

HDF_SUCCESS 表示获取配置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取配置失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取配置失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取配置失败。

**Since：**

3.1


### GetExtensionIndex

  
```
int32_t(* CodecComponentType::GetExtensionIndex) (struct CodecComponentType *self, const char *paramName, uint32_t *indexType)
```

**描述：**

根据字符串获取组件的扩展索引。

将扩展字符串转换为Openmax IL结构索引。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| paramName | 输入参数，组件用来转换为配置索引的字符串。 | 
| indexType | 输出参数，由paramName转换的配置索引，详见**OMX_INDEXTYPE**。 | 

**返回：**

HDF_SUCCESS 表示获取扩展索引成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取扩展索引失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取扩展索引失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取扩展索引失败。

**Since：**

3.1


### GetParameter

  
```
int32_t(* CodecComponentType::GetParameter) (struct CodecComponentType *self, uint32_t paramIndex, int8_t *paramStruct, uint32_t paramStructLen)
```

**描述：**

获取组件参数设置。

当组件处于除了OMX_StateInvalid（组件状态异常）之外的其他状态，用户可通过此接口获取组件参数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| paramIndex | 输入参数，待填充结构的索引，详见**OMX_INDEXTYPE**。 | 
| paramStruct | 输入输出参数，指向由组件填充的应用程序分配的结构体指针。 | 
| paramStructLen | 输入参数，paramStruct字节数。 | 

**返回：**

HDF_SUCCESS 表示获取参数成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取参数失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取参数失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取参数失败。

**Since：**

3.1


### GetState

  
```
int32_t(* CodecComponentType::GetState) (struct CodecComponentType *self, enum OMX_STATETYPE *state)
```

**描述：**

获取组件的当前状态。

用户可调用此接口获取组件的当前状态，组件状态详见**OMX_STATETYPE**。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| state | 输出参数，指向获取到的状态指针，组件状态详见**OMX_STATETYPE**。 | 

**返回：**

HDF_SUCCESS 表示获取状态成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取状态失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取状态失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取状态失败。

**Since：**

3.1


### remote

  
```
struct HdfRemoteService* CodecCallbackType::remote
```

**描述：**

指向HdfRemoteService的指针。

**Since：**

3.1


### SendCommand

  
```
int32_t(* CodecComponentType::SendCommand) (struct CodecComponentType *self, enum OMX_COMMANDTYPE cmd, uint32_t param, int8_t *cmdData, uint32_t cmdDataLen)
```

**描述：**

发送命令给组件。

发送命令给组件，当命令为设置状态时，会有事件回调通知结果给上层，其他命令则没有事件上报。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| cmd | 输入参数，组件要执行的命令，详见**OMX_COMMANDTYPE**。 | 
| param | 输入参数，组件要执行的命令携带的参数。<br/>-&nbsp;当cmd为OMX_CommandStateSet时，param的值详见**OMX_STATETYPE**。<br/>-&nbsp;当cmd为OMX_CommandFlush、OMX_CommandPortDisable、OMX_CommandPortEnable、OMX_CommandMarkBuffer时，param为目标端口。 | 
| cmdData | 输入参数，当cmd为OMX_CommandMarkBuffer时，指向OMX_MARKTYPE结构体指针。 | 
| cmdDataLen | 输入参数，上层传递的cmdData字节数。 | 

**返回：**

HDF_SUCCESS 表示发送命令成功。

HDF_ERR_INVALID_PARAM 表示参数无效，发送命令失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，发送命令失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，发送命令失败。

**Since：**

3.1


### SetCallbacks

  
```
int32_t(* CodecComponentType::SetCallbacks) (struct CodecComponentType *self, struct CodecCallbackType *callback, int8_t *appData, uint32_t appDataLen)
```

**描述：**

设置Codec组件的回调函数。

当组件处于OMX_StateLoaded状态时，使用此回调函数向上通知事件以及上报可用的输入输出信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| callback | 输入参数，指向回调函数[CodecCallbackType](_codec_callback_type.md)对象指针。 | 
| appData | 输入参数，指向应用程序定义的值的指针，该值将在回调期间返回。 | 
| appDataLen | 输入参数，上层传递的appData字节数。 | 

**返回：**

HDF_SUCCESS 表示设置回调成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置回调失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置回调失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置回调失败。

**Since：**

3.1


### SetConfig

  
```
int32_t(* CodecComponentType::SetConfig) (struct CodecComponentType *self, uint32_t index, int8_t *cfgStruct, uint32_t cfgStructLen)
```

**描述：**

设置组件的配置。

加载组件后可以随时调用此接口设置组件的配置。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| index | 输入参数，要设置的结构索引，详见**OMX_INDEXTYPE**。 | 
| cfgStruct | 输入参数，指向组件用于初始化的应用程序分配结构的指针。 | 
| cfgStructLen | 输入参数，cfgStruct字节数。 | 

**返回：**

HDF_SUCCESS 表示设置配置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置失败。

**Since：**

3.1


### SetParameter

  
```
int32_t(* CodecComponentType::SetParameter) (struct CodecComponentType *self, uint32_t index, int8_t *paramStruct, uint32_t paramStructLen)
```

**描述：**

设置组件需要的参数。

当组件处于OMX_StateLoaded、OMX_StateWaitForResources状态或者端口是去使能状态，用户可通过此接口设置组件参数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| index | 输入参数，要设置的结构索引，详见**OMX_INDEXTYPE**。 | 
| paramStruct | 输入参数，指向组件用于初始化的应用程序分配结构的指针。 | 
| paramStructLen | 输入参数，paramStruct字节数。 | 

**返回：**

HDF_SUCCESS 表示设置参数成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置参数失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置参数失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置参数失败。

**Since：**

3.1


### UseBuffer

  
```
int32_t(* CodecComponentType::UseBuffer) (struct CodecComponentType *self, uint32_t portIndex, struct OmxCodecBuffer *buffer)
```

**描述：**

指定组件端口的buffer。

此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且用户已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| buffer | 输入输出参数，指向要使用的buffer结构体[OmxCodecBuffer](_omx_codec_buffer.md)指针。 | 

**返回：**

HDF_SUCCESS 表示指定成功。

HDF_ERR_INVALID_PARAM 表示参数无效，指定失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，指定失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，指定失败。

**Since：**

3.1


### UseEglImage

  
```
int32_t(* CodecComponentType::UseEglImage) (struct CodecComponentType *self, struct OmxCodecBuffer *buffer, uint32_t portIndex, int8_t *eglImage, uint32_t eglImageLen)
```

**描述：**

使用已在EGL中申请的空间。

此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| buffer | 输入输出参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| eglImage | 输入参数，EGL申请的图像指针。 | 
| eglImageLen | 输入参数，eglImage字节数。 | 

**返回：**

HDF_SUCCESS 表示使用成功。

HDF_ERR_INVALID_PARAM 表示参数无效，使用失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，使用失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，使用失败。

**Since：**

3.1
