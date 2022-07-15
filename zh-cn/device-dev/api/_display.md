# Display


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [display_device.h](display__device_8h.md) | 显示设备控制接口声明。 | 
| [display_gfx.h](display__gfx_8h.md) | 显示硬件加速驱动接口声明。 | 
| [display_gralloc.h](display__gralloc_8h.md) | 显示内存驱动接口声明。 | 
| [display_layer.h](display__layer_8h.md) | 显示图层驱动接口声明。 | 
| [display_type.h](display__type_8h.md) | 显示类型定义，定义显示驱动接口所使用的数据类型。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [DeviceFuncs](_device_funcs.md) | 显示设备控制接口结构体，定义显示设备控制接口函数指针。&nbsp;[更多...](_device_funcs.md) | 
| [GfxFuncs](_gfx_funcs.md) | 显示硬件加速驱动接口结构体，定义硬件加速驱动接口函数指针。&nbsp;[更多...](_gfx_funcs.md) | 
| [GrallocFuncs](_gralloc_funcs.md) | 显示内存驱动接口结构体，定义显示内存驱动接口函数指针。&nbsp;[更多...](_gralloc_funcs.md) | 
| [LayerFuncs](_layer_funcs.md) | 显示图层驱动接口结构体，定义显示图层驱动接口函数指针。&nbsp;[更多...](_layer_funcs.md) | 
| [DisplayInfo](_display_info.md) | 定义显示信息结构体&nbsp;[更多...](_display_info.md) | 
| [LayerInfo](_layer_info.md) | 定义图层信息结构体&nbsp;[更多...](_layer_info.md) | 
| [LayerAlpha](_layer_alpha.md) | 定义图层Alpha信息的结构体&nbsp;[更多...](_layer_alpha.md) | 
| [BufferData](_buffer_data.md) | 定义一层的缓冲区数据，包括虚拟和物理内存地址。&nbsp;[更多...](_buffer_data.md) | 
| [LayerBuffer](_layer_buffer.md) | 图层Buffer，用于存放图层数据。&nbsp;[更多...](_layer_buffer.md) | 
| [IRect](_i_rect.md) | 定义矩形信息&nbsp;[更多...](_i_rect.md) | 
| [ISurface](_i_surface.md) | 用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。&nbsp;[更多...](_i_surface.md) | 
| [ILine](_i_line.md) | 线条描述结构体定义，用于硬件加速绘制直线。&nbsp;[更多...](_i_line.md) | 
| [ICircle](_i_circle.md) | 圆形描述结构体定义，用于硬件加速绘制圆形。&nbsp;[更多...](_i_circle.md) | 
| [Rectangle](_rectangle.md) | 矩形描述结构体定义，用于硬件加速绘制矩形，&nbsp;[更多...](_rectangle.md) | 
| [GfxOpt](_gfx_opt.md) | 图像硬件加速相关的操作选项结构体定义，用于图像硬件加速时的操作选项。&nbsp;[更多...](_gfx_opt.md) | 
| [PropertyObject](_property_object.md) | 定义包含名称、属性ID和值的属性对象。&nbsp;[更多...](_property_object.md) | 
| [DisplayCapability](_display_capability.md) | 定义输出性能。&nbsp;[更多...](_display_capability.md) | 
| [DisplayModeInfo](_display_mode_info.md) | 定义输出模式信息。&nbsp;[更多...](_display_mode_info.md) | 
| [AllocInfo](_alloc_info.md) | 定义关于要分配的内存的信息。&nbsp;[更多...](_alloc_info.md) | 
| [HDRCapability](_h_d_r_capability.md) | HDR属性结构体定义&nbsp;[更多...](_h_d_r_capability.md) | 
| [HDRMetaData](_h_d_r_meta_data.md) | HDR元数据结构体定义&nbsp;[更多...](_h_d_r_meta_data.md) | 
| [VerifyAllocInfo](_verify_alloc_info.md) | 用于验证内存分配信息的结构体定义&nbsp;[更多...](_verify_alloc_info.md) | 
| [PresentTimestamp](_present_timestamp.md) | 上屏时间戳结构体定义&nbsp;[更多...](_present_timestamp.md) | 
| [__attribute__](____attribute____.md) | 扩展数据句柄结构体定义&nbsp;[更多...](____attribute____.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| **PROPERTY_NAME_LEN**&nbsp;&nbsp;&nbsp;50 | 属性名字长度。 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([HotPlugCallback](#hotplugcallback))&nbsp;(uint32_t&nbsp;devId,&nbsp;bool&nbsp;connected,&nbsp;void&nbsp;\*data) | 热插拔事件回调。[更多...](#hotplugcallback) | 
| ([VBlankCallback](#vblankcallback))&nbsp;(unsigned&nbsp;int&nbsp;sequence,&nbsp;uint64_t&nbsp;ns,&nbsp;void&nbsp;\*data) | VBlank&nbsp;事件回调。&nbsp;[更多...](#vblankcallback) | 
| ([RefreshCallback](#refreshcallback))&nbsp;(uint32_t&nbsp;devId,&nbsp;void&nbsp;\*data) | 刷新请求回调。[更多...](#refreshcallback) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [DispErrCode](#disperrcode)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref467931723083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0a188daac95e787159d50ff9546536035b](#gga12a925dadef7573cd74d63d06824f9b0a188daac95e787159d50ff9546536035b)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref461318324083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0afdffc20c71fb142c3e7f01323a31d742](#gga12a925dadef7573cd74d63d06824f9b0afdffc20c71fb142c3e7f01323a31d742)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1573229612083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0a5bdb0a826a652f51e6c82685ae08ede8](#gga12a925dadef7573cd74d63d06824f9b0a5bdb0a826a652f51e6c82685ae08ede8)&nbsp;=&nbsp;-2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref628139164083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0a330e09be303bc7056f6115830bbd2370](#gga12a925dadef7573cd74d63d06824f9b0a330e09be303bc7056f6115830bbd2370)&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref116149628083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0a82fbcdba6c699059bc04b491c92424ac](#gga12a925dadef7573cd74d63d06824f9b0a82fbcdba6c699059bc04b491c92424ac)&nbsp;=&nbsp;-4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1147568460083931,link:#entry1871899482083931p0](#entry1871899482083931p0)&nbsp;=&nbsp;-5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref632114308083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0af186ab511133fa3280c54d2c44358882](#gga12a925dadef7573cd74d63d06824f9b0af186ab511133fa3280c54d2c44358882)&nbsp;=&nbsp;-6,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref183420496083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0ac11b678fc04745ff4d91f4398b83c427](#gga12a925dadef7573cd74d63d06824f9b0ac11b678fc04745ff4d91f4398b83c427)&nbsp;=&nbsp;-7,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1225838925083931,link:zh-cn_topic_0000001295414172.xml#gga12a925dadef7573cd74d63d06824f9b0ad133674b9f3b857a12791479aaf58cf8](#gga12a925dadef7573cd74d63d06824f9b0ad133674b9f3b857a12791479aaf58cf8)&nbsp;=&nbsp;-8&nbsp;} | 返回值类型定义。&nbsp;[更多...](#disperrcode) | 
| [LayerType](#layertype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref33455598083931,link:zh-cn_topic_0000001295414172.xml#gga56943a0946e5f15e5e58054b8e7a04a4a6ef157ea82a5d4c1715b3cddcca38d6f](#gga56943a0946e5f15e5e58054b8e7a04a4a6ef157ea82a5d4c1715b3cddcca38d6f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1928108280083931,link:zh-cn_topic_0000001295414172.xml#gga56943a0946e5f15e5e58054b8e7a04a4ac33e449941bc0e4d039b4b5bed853a78](#gga56943a0946e5f15e5e58054b8e7a04a4ac33e449941bc0e4d039b4b5bed853a78),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1214480178083931,link:zh-cn_topic_0000001295414172.xml#gga56943a0946e5f15e5e58054b8e7a04a4a0aef2c460a206fa00c742219d65be477](#gga56943a0946e5f15e5e58054b8e7a04a4a0aef2c460a206fa00c742219d65be477),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1743879312083931,link:zh-cn_topic_0000001295414172.xml#gga56943a0946e5f15e5e58054b8e7a04a4a44b3a657e6bf4f1f5709c03a94a11019](#gga56943a0946e5f15e5e58054b8e7a04a4a44b3a657e6bf4f1f5709c03a94a11019),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1133479067083931,link:zh-cn_topic_0000001295414172.xml#gga56943a0946e5f15e5e58054b8e7a04a4acd813c5ad9a2be97c85a97d4bdf1cb57](#gga56943a0946e5f15e5e58054b8e7a04a4acd813c5ad9a2be97c85a97d4bdf1cb57)&nbsp;} | 图层类型定义。&nbsp;[更多...](#layertype) | 
| {&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref146139778083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a9bb139ab93fcaceac48e52bac1be53dc](#ggadf764cbdea00d65edcd07bb9953ad2b7a9bb139ab93fcaceac48e52bac1be53dc)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1607643731083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a29217cbafbb6666fe1e8d96f3c368a4d](#ggadf764cbdea00d65edcd07bb9953ad2b7a29217cbafbb6666fe1e8d96f3c368a4d)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1226143925083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a9126b10e53b48304a5d9c351b1ace6d4](#ggadf764cbdea00d65edcd07bb9953ad2b7a9126b10e53b48304a5d9c351b1ace6d4)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1354412377083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7af7d33fd75c60375bef211629ff02d8c4](#ggadf764cbdea00d65edcd07bb9953ad2b7af7d33fd75c60375bef211629ff02d8c4)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1235654974083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a16042b501b66017d663c3f5bcd24a20f](#ggadf764cbdea00d65edcd07bb9953ad2b7a16042b501b66017d663c3f5bcd24a20f)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1166165519083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a553664654199ebde6733a830cbe0a369](#ggadf764cbdea00d65edcd07bb9953ad2b7a553664654199ebde6733a830cbe0a369)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref867019725083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a110b955655861ef11167e907be5f18fc](#ggadf764cbdea00d65edcd07bb9953ad2b7a110b955655861ef11167e907be5f18fc)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;6),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref475703695083931,link:zh-cn_topic_0000001295414172.xml#ggadf764cbdea00d65edcd07bb9953ad2b7a44d0fd6e88dbbe9e78c44cc8e5bddc22](#ggadf764cbdea00d65edcd07bb9953ad2b7a44d0fd6e88dbbe9e78c44cc8e5bddc22)&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;7)&nbsp;} | 缓冲区定义。[更多...](#anonymous-enum) | 
| [PixelFormat](#pixelformat)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1732209840083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aabdea255b6e5f2920977f11d21445b34a](#gga60883d4958a60b91661e97027a85072aabdea255b6e5f2920977f11d21445b34a)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2042431780083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa5740c66a546552c0c5a4bc06850af584](#gga60883d4958a60b91661e97027a85072aa5740c66a546552c0c5a4bc06850af584),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1240468655083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aabde13e8f357e39981973929309bb0e0e](#gga60883d4958a60b91661e97027a85072aabde13e8f357e39981973929309bb0e0e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2130788661083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa5fae320872be3ffdda0d371cec048ec6](#gga60883d4958a60b91661e97027a85072aa5fae320872be3ffdda0d371cec048ec6),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref58537565083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa4c16147153b63d7ba71b257111afdd62](#gga60883d4958a60b91661e97027a85072aa4c16147153b63d7ba71b257111afdd62),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref999360489083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aaa479ac0d983fde9b4f7f0e1a3b3e230f](#gga60883d4958a60b91661e97027a85072aaa479ac0d983fde9b4f7f0e1a3b3e230f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2110176620083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aacbb91256e8c45a51410a9f6caae2d04c](#gga60883d4958a60b91661e97027a85072aacbb91256e8c45a51410a9f6caae2d04c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1175419870083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa7d18a83da06902c104208031ed487942](#gga60883d4958a60b91661e97027a85072aa7d18a83da06902c104208031ed487942),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref278468690083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa85e5dd1a0e547c0031baffd02abb31a0](#gga60883d4958a60b91661e97027a85072aa85e5dd1a0e547c0031baffd02abb31a0),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref495124063083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aadc1387526a271d8c6db7729de06474b1](#gga60883d4958a60b91661e97027a85072aadc1387526a271d8c6db7729de06474b1),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2005992881083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa720a429fa57133f6e27ef8c8fa1c404a](#gga60883d4958a60b91661e97027a85072aa720a429fa57133f6e27ef8c8fa1c404a),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1851802084083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa24a7181b7fb4019e7c19739bd9b65ff0](#gga60883d4958a60b91661e97027a85072aa24a7181b7fb4019e7c19739bd9b65ff0),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref981238871083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa90b462672221691ed66cacb07dd2e05f](#gga60883d4958a60b91661e97027a85072aa90b462672221691ed66cacb07dd2e05f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1496414706083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa7ff77397bf2cf52b4614a46264f8ce01](#gga60883d4958a60b91661e97027a85072aa7ff77397bf2cf52b4614a46264f8ce01),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref18225218083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aaec581b908c291e2bd0155e25169f9629](#gga60883d4958a60b91661e97027a85072aaec581b908c291e2bd0155e25169f9629),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref911606020083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa6b5a7b35e00fc25146de0c9bf88b0230](#gga60883d4958a60b91661e97027a85072aa6b5a7b35e00fc25146de0c9bf88b0230),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1458046858083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa2f3d4ada099b2e8d84ec4501fbc8bed9](#gga60883d4958a60b91661e97027a85072aa2f3d4ada099b2e8d84ec4501fbc8bed9),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1137952576083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aaaf1a20dc0a597258cfe6aca806a8e0de](#gga60883d4958a60b91661e97027a85072aaaf1a20dc0a597258cfe6aca806a8e0de),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref562635814083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa2319d4a75dae0b56776fa63d525e308b](#gga60883d4958a60b91661e97027a85072aa2319d4a75dae0b56776fa63d525e308b),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1618305575083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa1b19279f89c8cfb60e7d77ce23cd5f43](#gga60883d4958a60b91661e97027a85072aa1b19279f89c8cfb60e7d77ce23cd5f43),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref758967891083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aaeb31c670120a1fbc96a0e0887997fe16](#gga60883d4958a60b91661e97027a85072aaeb31c670120a1fbc96a0e0887997fe16),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1617335806083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aac73c2a84907a53ed95a329007b5c8992](#gga60883d4958a60b91661e97027a85072aac73c2a84907a53ed95a329007b5c8992),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref298059959083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aabdf1224848278508479ce97f637dd711](#gga60883d4958a60b91661e97027a85072aabdf1224848278508479ce97f637dd711),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref73739201083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa8bf97d66e26b3aad7c83dfa70e2bc451](#gga60883d4958a60b91661e97027a85072aa8bf97d66e26b3aad7c83dfa70e2bc451),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref357426934083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa0d1db50eb492f9073abdd2d662c56396](#gga60883d4958a60b91661e97027a85072aa0d1db50eb492f9073abdd2d662c56396),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1072753167083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa1fa43c8a197d5c974a35b8bf02ab386e](#gga60883d4958a60b91661e97027a85072aa1fa43c8a197d5c974a35b8bf02ab386e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref250680627083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aaa2fe085e63428ea76e1d975175001dc6](#gga60883d4958a60b91661e97027a85072aaa2fe085e63428ea76e1d975175001dc6),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref403598730083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aab04eb6e1d940e42f3b4cc20c0a44c4ee](#gga60883d4958a60b91661e97027a85072aab04eb6e1d940e42f3b4cc20c0a44c4ee),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref281652873083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa3d80e785bed28e2b3f5c7df563500962](#gga60883d4958a60b91661e97027a85072aa3d80e785bed28e2b3f5c7df563500962),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref793358918083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa3dc5a0a5ad2f21218b446c477277210a](#gga60883d4958a60b91661e97027a85072aa3dc5a0a5ad2f21218b446c477277210a),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2099129983083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa3980def5b133584bdb2982a71f07798e](#gga60883d4958a60b91661e97027a85072aa3980def5b133584bdb2982a71f07798e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1329036123083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aadfd69bd5b421aad5bdd39d5f33317197](#gga60883d4958a60b91661e97027a85072aadfd69bd5b421aad5bdd39d5f33317197),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1795868980083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aaf851031c336e8d9f57c940c5f52381f4](#gga60883d4958a60b91661e97027a85072aaf851031c336e8d9f57c940c5f52381f4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref626327261083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa317a761939335025379d382074a1541c](#gga60883d4958a60b91661e97027a85072aa317a761939335025379d382074a1541c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref910922561083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa67668ea067a31a8479aece94094bc547](#gga60883d4958a60b91661e97027a85072aa67668ea067a31a8479aece94094bc547)&nbsp;=&nbsp;0X7FFF0000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref440016946083931,link:zh-cn_topic_0000001295414172.xml#gga60883d4958a60b91661e97027a85072aa07086bb3356c9c88959eee00c0982684](#gga60883d4958a60b91661e97027a85072aa07086bb3356c9c88959eee00c0982684)&nbsp;=&nbsp;0X7FFFFFFF&nbsp;} | 像素格式类型定义。&nbsp;[更多...](#pixelformat) | 
| [TransformType](#transformtype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref775310058083931,link:zh-cn_topic_0000001295414172.xml#ggaa65f3b21a9a92ff022e435a7304126d2a68e349e9d45a8eba440e2a7a3ba31ec9](#ggaa65f3b21a9a92ff022e435a7304126d2a68e349e9d45a8eba440e2a7a3ba31ec9)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref436596700083931,link:zh-cn_topic_0000001295414172.xml#ggaa65f3b21a9a92ff022e435a7304126d2a685062467b0c1a3164556335b467c886](#ggaa65f3b21a9a92ff022e435a7304126d2a685062467b0c1a3164556335b467c886),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1295314303083931,link:zh-cn_topic_0000001295414172.xml#ggaa65f3b21a9a92ff022e435a7304126d2a186263164422bb8f0eb5f7b7d195a3d1](#ggaa65f3b21a9a92ff022e435a7304126d2a186263164422bb8f0eb5f7b7d195a3d1),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1082872368083931,link:zh-cn_topic_0000001295414172.xml#ggaa65f3b21a9a92ff022e435a7304126d2a554e734d2a23790b248c5ce39816c18f](#ggaa65f3b21a9a92ff022e435a7304126d2a554e734d2a23790b248c5ce39816c18f),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1630028750083931,link:zh-cn_topic_0000001295414172.xml#ggaa65f3b21a9a92ff022e435a7304126d2a9b6ff871536aeef2a8e3ce4a753988ed](#ggaa65f3b21a9a92ff022e435a7304126d2a9b6ff871536aeef2a8e3ce4a753988ed)&nbsp;} | 图层变换类型定义。&nbsp;[更多...](#transformtype) | 
| [BlendType](#blendtype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1630535161083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817ae410edb34509ca21425fe5872bbc7e2f](#ggaab1839ed4aab1030dfda801a51e68817ae410edb34509ca21425fe5872bbc7e2f)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1293460839083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a6330cee419fbdafc0b25f0aa068814e5](#ggaab1839ed4aab1030dfda801a51e68817a6330cee419fbdafc0b25f0aa068814e5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1180798558083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817af01da0c255cdbf67d0774a67c2d221b5](#ggaab1839ed4aab1030dfda801a51e68817af01da0c255cdbf67d0774a67c2d221b5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1762594512083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817ad4c0cd02aa4b5f4849e2b29a26481dde](#ggaab1839ed4aab1030dfda801a51e68817ad4c0cd02aa4b5f4849e2b29a26481dde),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref978725557083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a21f03e8d04a58ed0684b39eb84bdb89f](#ggaab1839ed4aab1030dfda801a51e68817a21f03e8d04a58ed0684b39eb84bdb89f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref54214776083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a74e681f6c9027bb2cf0bda3b72d2dd9e](#ggaab1839ed4aab1030dfda801a51e68817a74e681f6c9027bb2cf0bda3b72d2dd9e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref504312733083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a19f528828d75c34e18375219f113d9bb](#ggaab1839ed4aab1030dfda801a51e68817a19f528828d75c34e18375219f113d9bb),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref737668884083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a404e05a118462520e878c23f89808199](#ggaab1839ed4aab1030dfda801a51e68817a404e05a118462520e878c23f89808199),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1002570120083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817ac0dc902b4928413d367376e4c842d909](#ggaab1839ed4aab1030dfda801a51e68817ac0dc902b4928413d367376e4c842d909),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1482844901083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817ada473c7e3bf2b1102349489416aefefc](#ggaab1839ed4aab1030dfda801a51e68817ada473c7e3bf2b1102349489416aefefc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref942142713083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a0129b4506a06b1a6df297bcf685f5f89](#ggaab1839ed4aab1030dfda801a51e68817a0129b4506a06b1a6df297bcf685f5f89),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2109257292083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817adbdb329830e5b4d9fa2b17d5d6d7894f](#ggaab1839ed4aab1030dfda801a51e68817adbdb329830e5b4d9fa2b17d5d6d7894f),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1722590029083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a167c3b256e051244066d8e53cdd5529d](#ggaab1839ed4aab1030dfda801a51e68817a167c3b256e051244066d8e53cdd5529d),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1078349153083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a4686a5f30c73982d625a05db021e9b15](#ggaab1839ed4aab1030dfda801a51e68817a4686a5f30c73982d625a05db021e9b15),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1719812602083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817ae549aa3794365df8965a2c3853c8da99](#ggaab1839ed4aab1030dfda801a51e68817ae549aa3794365df8965a2c3853c8da99),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1718413401083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817a3cc39f12fa8bceba626a33c2d82a8bf7](#ggaab1839ed4aab1030dfda801a51e68817a3cc39f12fa8bceba626a33c2d82a8bf7),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1072135724083931,link:zh-cn_topic_0000001295414172.xml#ggaab1839ed4aab1030dfda801a51e68817ad0650812ac2aa9eee228f48ac514b44a](#ggaab1839ed4aab1030dfda801a51e68817ad0650812ac2aa9eee228f48ac514b44a)&nbsp;} | 显示内存类型定义。&nbsp;[更多...](#blendtype) | 
| [RopType](#roptype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref742002375083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a6358a786ec3b81000a07b343424cee0d](#gga24265f7618fbdba53d3da4806d3097c4a6358a786ec3b81000a07b343424cee0d)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref17811207083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a96c89f7b89a9048d355b4dc467224f4c](#gga24265f7618fbdba53d3da4806d3097c4a96c89f7b89a9048d355b4dc467224f4c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2043334490083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a54d054ea6920cb88f374f70e8d41f934](#gga24265f7618fbdba53d3da4806d3097c4a54d054ea6920cb88f374f70e8d41f934),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2053741826083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4af4a5d5dc0f15249001cff7ef32fadef1](#gga24265f7618fbdba53d3da4806d3097c4af4a5d5dc0f15249001cff7ef32fadef1),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1527355910083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4ad777eea18ba9f4e071b00aa060db00e3](#gga24265f7618fbdba53d3da4806d3097c4ad777eea18ba9f4e071b00aa060db00e3),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2065629750083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4afa63c8e2a6a39d50954cb6316576b4e9](#gga24265f7618fbdba53d3da4806d3097c4afa63c8e2a6a39d50954cb6316576b4e9),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1601085310083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a79433776e85bb80ad0306ced0b82947c](#gga24265f7618fbdba53d3da4806d3097c4a79433776e85bb80ad0306ced0b82947c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref92248121083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4ad6c4d2458a9caaa079a3e5907d636e8a](#gga24265f7618fbdba53d3da4806d3097c4ad6c4d2458a9caaa079a3e5907d636e8a),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1093756523083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a2a069e2105c5b8d4dac5d174c76eb9d4](#gga24265f7618fbdba53d3da4806d3097c4a2a069e2105c5b8d4dac5d174c76eb9d4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1280708123083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a33c37c5ce718e876f43141dc5a028375](#gga24265f7618fbdba53d3da4806d3097c4a33c37c5ce718e876f43141dc5a028375),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref596450312083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a2acacab882af44bba09878bd58e18695](#gga24265f7618fbdba53d3da4806d3097c4a2acacab882af44bba09878bd58e18695),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref231000186083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4afaea3c47612082914332b78ca8c331b3](#gga24265f7618fbdba53d3da4806d3097c4afaea3c47612082914332b78ca8c331b3),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref261991109083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a91bae697f9dea25ac4d7be011958a45d](#gga24265f7618fbdba53d3da4806d3097c4a91bae697f9dea25ac4d7be011958a45d),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1444974344083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a3580b77320e4829da046b8739c61d6b8](#gga24265f7618fbdba53d3da4806d3097c4a3580b77320e4829da046b8739c61d6b8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1590052574083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a8195ac0d37e0d69b2cd71dd7362d3fd3](#gga24265f7618fbdba53d3da4806d3097c4a8195ac0d37e0d69b2cd71dd7362d3fd3),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1361443035083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4a533a614b27da8a81b67ada085b018618](#gga24265f7618fbdba53d3da4806d3097c4a533a614b27da8a81b67ada085b018618),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2083205639083931,link:zh-cn_topic_0000001295414172.xml#gga24265f7618fbdba53d3da4806d3097c4aa858b07e214a7f62625e24776806c74b](#gga24265f7618fbdba53d3da4806d3097c4aa858b07e214a7f62625e24776806c74b)&nbsp;} | 硬件加速支持的ROP操作类型。&nbsp;[更多...](#roptype) | 
| [ColorKey](#colorkey)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1866201489083931,link:zh-cn_topic_0000001295414172.xml#gga4fe6fb05c7ba0048b1739d88f4d4878ea629b31de258db2ce01cb757b85bd5273](#gga4fe6fb05c7ba0048b1739d88f4d4878ea629b31de258db2ce01cb757b85bd5273)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1057243463083931,link:zh-cn_topic_0000001295414172.xml#gga4fe6fb05c7ba0048b1739d88f4d4878ea5e3271e73dce39d0806ff8e9cba011bc](#gga4fe6fb05c7ba0048b1739d88f4d4878ea5e3271e73dce39d0806ff8e9cba011bc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref278164484083931,link:zh-cn_topic_0000001295414172.xml#gga4fe6fb05c7ba0048b1739d88f4d4878ea6921c2c202aa69293467baa6c33fae05](#gga4fe6fb05c7ba0048b1739d88f4d4878ea6921c2c202aa69293467baa6c33fae05),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref297021214083931,link:zh-cn_topic_0000001295414172.xml#gga4fe6fb05c7ba0048b1739d88f4d4878ea32cedc8986de2c290bf2ec193d88cabf](#gga4fe6fb05c7ba0048b1739d88f4d4878ea32cedc8986de2c290bf2ec193d88cabf)&nbsp;} | Color&nbsp;key操作类型定义，即硬件加速支持的Color&nbsp;key操作类型。&nbsp;[更多...](#colorkey) | 
| [MirrorType](#mirrortype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1622625061083931,link:zh-cn_topic_0000001295414172.xml#gga08d32376574b541d162d8534adb78fd0a5ad82fcc8af04f92571e185b61eeb309](#gga08d32376574b541d162d8534adb78fd0a5ad82fcc8af04f92571e185b61eeb309)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1262697891083931,link:zh-cn_topic_0000001295414172.xml#gga08d32376574b541d162d8534adb78fd0ae35099d9fd28c2974661bcce36a9ea5c](#gga08d32376574b541d162d8534adb78fd0ae35099d9fd28c2974661bcce36a9ea5c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1443537263083931,link:zh-cn_topic_0000001295414172.xml#gga08d32376574b541d162d8534adb78fd0afd82e59546a645fd29bc779c50bfa733](#gga08d32376574b541d162d8534adb78fd0afd82e59546a645fd29bc779c50bfa733),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref579554716083931,link:zh-cn_topic_0000001295414172.xml#gga08d32376574b541d162d8534adb78fd0ad9e357a2c2f7dc0e3ca5a351ec457410](#gga08d32376574b541d162d8534adb78fd0ad9e357a2c2f7dc0e3ca5a351ec457410)&nbsp;} | 硬件加速支持的镜像操作类型定义&nbsp;[更多...](#mirrortype) | 
| [Connection](#connection)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1976252805083931,link:zh-cn_topic_0000001295414172.xml#ggab0845c0c8d309ee865c78b095b00e671ab5c8a92e6af2e63e769dd8f711564760](#ggab0845c0c8d309ee865c78b095b00e671ab5c8a92e6af2e63e769dd8f711564760)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref137781331083931,link:zh-cn_topic_0000001295414172.xml#ggab0845c0c8d309ee865c78b095b00e671a7a691a2430ec26878897b5fbc9c22a4c](#ggab0845c0c8d309ee865c78b095b00e671a7a691a2430ec26878897b5fbc9c22a4c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref302409363083931,link:zh-cn_topic_0000001295414172.xml#ggab0845c0c8d309ee865c78b095b00e671acdaad1112073e3e2ea032424c38c34e1](#ggab0845c0c8d309ee865c78b095b00e671acdaad1112073e3e2ea032424c38c34e1)&nbsp;} | 热插拔连接类型定义&nbsp;[更多...](#connection) | 
| [InterfaceType](#interfacetype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1452208663083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da717f9ae7960ba280c6c6b8822c6d8b66](#ggaf1ef2c97e255bd7f21d3b7614b283d9da717f9ae7960ba280c6c6b8822c6d8b66)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1121895311083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da210dbbea7e5c30b693515bba570474d4](#ggaf1ef2c97e255bd7f21d3b7614b283d9da210dbbea7e5c30b693515bba570474d4),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref632913210083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da89a4e456ceffa55cb93b2c6f4792c96b](#ggaf1ef2c97e255bd7f21d3b7614b283d9da89a4e456ceffa55cb93b2c6f4792c96b),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2037575674083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9daf23a0b7607d3fdc7eac791d62c5f9cd5](#ggaf1ef2c97e255bd7f21d3b7614b283d9daf23a0b7607d3fdc7eac791d62c5f9cd5),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1854194160083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da54a83297ab61376574854e804a6158e1](#ggaf1ef2c97e255bd7f21d3b7614b283d9da54a83297ab61376574854e804a6158e1),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1974798167083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da83ef625db890ee1ddb4e874d6155405f](#ggaf1ef2c97e255bd7f21d3b7614b283d9da83ef625db890ee1ddb4e874d6155405f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1128524956083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9dabf3991ede75cb3bb454372174d63ec29](#ggaf1ef2c97e255bd7f21d3b7614b283d9dabf3991ede75cb3bb454372174d63ec29),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1601425364083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9daad740e6f901f40965d2824415fcb9041](#ggaf1ef2c97e255bd7f21d3b7614b283d9daad740e6f901f40965d2824415fcb9041),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref834357467083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da5db1f365e675d992f47ce797339beff5](#ggaf1ef2c97e255bd7f21d3b7614b283d9da5db1f365e675d992f47ce797339beff5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1826677317083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da5b9c7382dfdcc029e467c6339bf90915](#ggaf1ef2c97e255bd7f21d3b7614b283d9da5b9c7382dfdcc029e467c6339bf90915),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1227458094083931,link:zh-cn_topic_0000001295414172.xml#ggaf1ef2c97e255bd7f21d3b7614b283d9da4d64c32b687840c7e08e28a2892ac222](#ggaf1ef2c97e255bd7f21d3b7614b283d9da4d64c32b687840c7e08e28a2892ac222),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref65502257333,link:#p106611424171011](#p106611424171011)&nbsp;} | 枚举接口类型。&nbsp;[更多...](#interfacetype) | 
| [DispPowerStatus](#disppowerstatus)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref378646307083931,link:zh-cn_topic_0000001295414172.xml#gga0f3c8af6e9d40730b0d2e0fbbf8e627da89e258c21283c662af2145bd3f9fc9a0](#gga0f3c8af6e9d40730b0d2e0fbbf8e627da89e258c21283c662af2145bd3f9fc9a0),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1015948368083931,link:zh-cn_topic_0000001295414172.xml#gga0f3c8af6e9d40730b0d2e0fbbf8e627da604748a7de21aa992c1f72c252fc77a7](#gga0f3c8af6e9d40730b0d2e0fbbf8e627da604748a7de21aa992c1f72c252fc77a7),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref821302934083931,link:zh-cn_topic_0000001295414172.xml#gga0f3c8af6e9d40730b0d2e0fbbf8e627da5605db047fd50c64fa0a13d8e558d479](#gga0f3c8af6e9d40730b0d2e0fbbf8e627da5605db047fd50c64fa0a13d8e558d479),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref21224644083931,link:zh-cn_topic_0000001295414172.xml#gga0f3c8af6e9d40730b0d2e0fbbf8e627daddd660122faa920f2adcd81e83d22c85](#gga0f3c8af6e9d40730b0d2e0fbbf8e627daddd660122faa920f2adcd81e83d22c85),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1203211795083931,link:zh-cn_topic_0000001295414172.xml#gga0f3c8af6e9d40730b0d2e0fbbf8e627dad1f590a00c02d7335bfc24edbea92037](#gga0f3c8af6e9d40730b0d2e0fbbf8e627dad1f590a00c02d7335bfc24edbea92037)&nbsp;} | 枚举显示状态&nbsp;[更多...](#disppowerstatus) | 
| [CompositionType](#compositiontype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1830977517083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5afc7ab4757f19ed87ea6d1603478edbe8](#ggae5d7b642670cf3dc6654131dfa115fe5afc7ab4757f19ed87ea6d1603478edbe8),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1161941610083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5aa51390e0da602171f2d042a94c6b75bf](#ggae5d7b642670cf3dc6654131dfa115fe5aa51390e0da602171f2d042a94c6b75bf),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1097843950083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5a663feec453d4509980f3bb34f641303b](#ggae5d7b642670cf3dc6654131dfa115fe5a663feec453d4509980f3bb34f641303b),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref700721638083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5a89ea30239d366a6968c7dff429a99aa9](#ggae5d7b642670cf3dc6654131dfa115fe5a89ea30239d366a6968c7dff429a99aa9),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2089060453083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5a05f5ab2a5da295c0fdc7e19e9a121f3e](#ggae5d7b642670cf3dc6654131dfa115fe5a05f5ab2a5da295c0fdc7e19e9a121f3e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref81247533083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5a7c1535ef8d388f878fae7c722d69855e](#ggae5d7b642670cf3dc6654131dfa115fe5a7c1535ef8d388f878fae7c722d69855e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref776657651083931,link:zh-cn_topic_0000001295414172.xml#ggae5d7b642670cf3dc6654131dfa115fe5a400576aea4b15e011ddd21748d16f9ca](#ggae5d7b642670cf3dc6654131dfa115fe5a400576aea4b15e011ddd21748d16f9ca),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1598485913356,link:#p488974221219](#p488974221219)&nbsp;} | 枚举特殊层的组合类型。&nbsp;[更多...](#compositiontype) | 
| [ColorGamut](#colorgamut)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1320572072083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a7d7d95bebc0ddb4d10da05b449bab1bf](#gga7e865f6dbae09a004be2949b473fd7c3a7d7d95bebc0ddb4d10da05b449bab1bf)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref680538601083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3af0e1dba48215d4d19bd9a3536a736cdb](#gga7e865f6dbae09a004be2949b473fd7c3af0e1dba48215d4d19bd9a3536a736cdb)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2112483204083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3affa91ab208128bec9b981e7020bcbfa9](#gga7e865f6dbae09a004be2949b473fd7c3affa91ab208128bec9b981e7020bcbfa9)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref977909621083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a248480b6ae7ad6c5327dd7cb5cfd0a85](#gga7e865f6dbae09a004be2949b473fd7c3a248480b6ae7ad6c5327dd7cb5cfd0a85)&nbsp;=&nbsp;2,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1659526516083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a98eb540d5a93ab3ad4256907eec89c4e](#gga7e865f6dbae09a004be2949b473fd7c3a98eb540d5a93ab3ad4256907eec89c4e)&nbsp;=&nbsp;3,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref750726964083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a8327e3fc0a79c9935dd9279c10c841c5](#gga7e865f6dbae09a004be2949b473fd7c3a8327e3fc0a79c9935dd9279c10c841c5)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1950926867083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a3377a7df82b495c65f3f7ab2b1655100](#gga7e865f6dbae09a004be2949b473fd7c3a3377a7df82b495c65f3f7ab2b1655100)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1621900951083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3ad79cdc9f86f3b581453c523a03a876d3](#gga7e865f6dbae09a004be2949b473fd7c3ad79cdc9f86f3b581453c523a03a876d3)&nbsp;=&nbsp;6,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref300730856083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a79ff774719c5b83287b298d39ee274f3](#gga7e865f6dbae09a004be2949b473fd7c3a79ff774719c5b83287b298d39ee274f3)&nbsp;=&nbsp;7,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref269858315083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3aa8191f5fca2ad767fa56767b41f4dec5](#gga7e865f6dbae09a004be2949b473fd7c3aa8191f5fca2ad767fa56767b41f4dec5)&nbsp;=&nbsp;8,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref185185729083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3ad4f624c7b578dacaa732cd9556724797](#gga7e865f6dbae09a004be2949b473fd7c3ad4f624c7b578dacaa732cd9556724797)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref327662541083931,link:zh-cn_topic_0000001295414172.xml#gga7e865f6dbae09a004be2949b473fd7c3a5d07e2f0d8e570c5e16ccff05e12cb29](#gga7e865f6dbae09a004be2949b473fd7c3a5d07e2f0d8e570c5e16ccff05e12cb29)&nbsp;=&nbsp;10&nbsp;} | 色域类型枚举值&nbsp;[更多...](#colorgamut) | 
| [GamutMap](#gamutmap)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1218064531083931,link:zh-cn_topic_0000001295414172.xml#gga5700b58f1bc340e309a0962101ad7fa4acdf75e246ac2f53f37ef9e11b5561535](#gga5700b58f1bc340e309a0962101ad7fa4acdf75e246ac2f53f37ef9e11b5561535)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref121550703083931,link:zh-cn_topic_0000001295414172.xml#gga5700b58f1bc340e309a0962101ad7fa4af3824abcccbd8d85d28e34149e9aaa33](#gga5700b58f1bc340e309a0962101ad7fa4af3824abcccbd8d85d28e34149e9aaa33)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref874892009083931,link:zh-cn_topic_0000001295414172.xml#gga5700b58f1bc340e309a0962101ad7fa4afd4e1cb10b8032108ab070925b73e270](#gga5700b58f1bc340e309a0962101ad7fa4afd4e1cb10b8032108ab070925b73e270)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref340489629083931,link:zh-cn_topic_0000001295414172.xml#gga5700b58f1bc340e309a0962101ad7fa4ad0f9722a0efd51910ac5f2f63fd86a10](#gga5700b58f1bc340e309a0962101ad7fa4ad0f9722a0efd51910ac5f2f63fd86a10)&nbsp;=&nbsp;3&nbsp;} | 枚举色域的映射类型&nbsp;[更多...](#gamutmap) | 
| [ColorDataSpace](#colordataspace)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref878538396083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca5a0aa62f13715cbdf2b5ec1e26e76225](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca5a0aa62f13715cbdf2b5ec1e26e76225)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref213046039083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad778a31f4c8e3431f5240f98c70f577d](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad778a31f4c8e3431f5240f98c70f577d)&nbsp;=&nbsp;0x00000001,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1054907918083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca7d346fa865c56c76f62c7f6ab92511ec](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca7d346fa865c56c76f62c7f6ab92511ec)&nbsp;=&nbsp;0x00000002,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1479012727083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccae29ccb674444c3f81f0a46361d7ce63c](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccae29ccb674444c3f81f0a46361d7ce63c)&nbsp;=&nbsp;0x00000003,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1386886784083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca16c4c57e66f86b20269db0d5d6382ded](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca16c4c57e66f86b20269db0d5d6382ded)&nbsp;=&nbsp;0x00000004,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref784825585083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca0a0a0c633a41a5f30596a5168a3267ca](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca0a0a0c633a41a5f30596a5168a3267ca)&nbsp;=&nbsp;0x00000005,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1056392053083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca3d4a0608dd5c682fc020bfc68a425e15](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca3d4a0608dd5c682fc020bfc68a425e15)&nbsp;=&nbsp;0x00000006,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref965963320083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa6dc448a5d0d16a7d2610edb29fff407](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa6dc448a5d0d16a7d2610edb29fff407)&nbsp;=&nbsp;0x00000007,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref221255855083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca6b100b6876c7e77106df92b9c8cf7d2b](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca6b100b6876c7e77106df92b9c8cf7d2b)&nbsp;=&nbsp;0x00000008,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1433734811083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca53a60a5ed93129597841bde263e9a798](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca53a60a5ed93129597841bde263e9a798)&nbsp;=&nbsp;0x00000009,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1953311748083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa66ffaf12ec59488cccbd2170cc3d2c8](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa66ffaf12ec59488cccbd2170cc3d2c8)&nbsp;=&nbsp;0x0000000a,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref722710803083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca0fe652843eafbf7a93b645a71342dce0](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca0fe652843eafbf7a93b645a71342dce0)&nbsp;=&nbsp;0x00000100,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref807869741083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa2e1f70b023dd5ae3a31771217d958cc](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa2e1f70b023dd5ae3a31771217d958cc)&nbsp;=&nbsp;0x00000200,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1259865942083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca47dd20703e8d8135aedfb687b75ef66c](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca47dd20703e8d8135aedfb687b75ef66c)&nbsp;=&nbsp;0x00000300,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1984327463083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccab031ec808cc46bee79d2c96460615206](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccab031ec808cc46bee79d2c96460615206)&nbsp;=&nbsp;0x00000400,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref561552060083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca078b8dad4e1eb6720c81c841b3f417d9](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca078b8dad4e1eb6720c81c841b3f417d9)&nbsp;=&nbsp;0x00000500,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1263948536083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad6abe514be2fa6c57b2aec5a5eb6fc7d](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad6abe514be2fa6c57b2aec5a5eb6fc7d)&nbsp;=&nbsp;0x00000600,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1183051809083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca850b419cb0075b5bd44df5708fc9c87f](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca850b419cb0075b5bd44df5708fc9c87f)&nbsp;=&nbsp;0x00000700,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2118794799083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca24a6d830fca211b067260df9583a1b2b](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca24a6d830fca211b067260df9583a1b2b)&nbsp;=&nbsp;0x00000800,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1273459295083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca4a6d68c7a2219cada2edf0e9d7bc46f8](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca4a6d68c7a2219cada2edf0e9d7bc46f8)&nbsp;=&nbsp;0x00000900,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref708368044083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca77342396f1154be94079d0d76fc5e829](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca77342396f1154be94079d0d76fc5e829)&nbsp;=&nbsp;0x00010000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2084997452083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca200541efc2ee0d21e37a7200e7a08a54](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca200541efc2ee0d21e37a7200e7a08a54)&nbsp;=&nbsp;0x00020000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref550019244083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccab51307e81936be84b6504a98197fb1ee](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccab51307e81936be84b6504a98197fb1ee)&nbsp;=&nbsp;0x00030000,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref599760488083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccafd6ac339ebbdbbdd7fee540a6fad5ec2](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccafd6ac339ebbdbbdd7fee540a6fad5ec2)&nbsp;=&nbsp;0x00040000,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1337337657083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccab640f36320dafb19066dfcaccc836999](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccab640f36320dafb19066dfcaccc836999)&nbsp;=&nbsp;GAMUT_BT601&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1816105061083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca6cd475c6421764e5d71d71f1de75d638](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca6cd475c6421764e5d71d71f1de75d638)&nbsp;=&nbsp;GAMUT_BT601&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRESION_LIMITED,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1498990098083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad2bc96da52c18ef9bb26320507747176](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad2bc96da52c18ef9bb26320507747176)&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref770259992083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca03631fd75bc6ec7280ce2c68a129e4fd](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca03631fd75bc6ec7280ce2c68a129e4fd)&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRESION_EXTENDED,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1144035591083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaaffba49d9c1c335387cd8153becad65a](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaaffba49d9c1c335387cd8153becad65a)&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1776467667083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca049878481c3ed46dbd6cfea995e2f0d5](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca049878481c3ed46dbd6cfea995e2f0d5)&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRESION_EXTENDED,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1982944600083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca14381e6d202b6bda3c90264b05d31838](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca14381e6d202b6bda3c90264b05d31838)&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRESION_LIMITED,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1756810240083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad03af85a7ff4c1069a97bfb603f7d694](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad03af85a7ff4c1069a97bfb603f7d694)&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1597065210083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca9de9b32e0e7c172c77922af8904ba3a2](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca9de9b32e0e7c172c77922af8904ba3a2)&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_GM2_6&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1497114999083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca8bcb3a4ed6039d158b9c32ba99fceaff](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca8bcb3a4ed6039d158b9c32ba99fceaff)&nbsp;=&nbsp;GAMUT_DISPLAY_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1059463390083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca2fac97f61868100034eb40fdba9a9d3f](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca2fac97f61868100034eb40fdba9a9d3f)&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1845514239083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca1f855c7b4bd5f8a9cc29f3e335a9f2f4](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca1f855c7b4bd5f8a9cc29f3e335a9f2f4)&nbsp;=&nbsp;GAMUT_ADOBE_RGB&nbsp;\|&nbsp;TRANSFORM_FUNC_GM2_2&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1108373610083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca27315309a3b866eda00f17825ee9532d](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca27315309a3b866eda00f17825ee9532d)&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1250807752083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa63d6a3a8bb1c6c5b383cb7010f61d72](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaa63d6a3a8bb1c6c5b383cb7010f61d72)&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1723753803083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33cca6de02e882e01743ce5ca07a17d481930](#gga00fa6ca1bcfe5949dceaa3a77f8d33cca6de02e882e01743ce5ca07a17d481930)&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1603971625083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccac2e37c91fc9bd29641cf95d74aa7862c](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccac2e37c91fc9bd29641cf95d74aa7862c)&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_ST2084&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref910505882083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad5b0a069ac80df8d045265e88f9b5e71](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccad5b0a069ac80df8d045265e88f9b5e71)&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_HLG&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1521841710083931,link:zh-cn_topic_0000001295414172.xml#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaeab2d55af8e3568130cf69fa614b3c9d](#gga00fa6ca1bcfe5949dceaa3a77f8d33ccaeab2d55af8e3568130cf69fa614b3c9d)&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_ST2084&nbsp;\|&nbsp;PRESION_LIMITED&nbsp;} | 枚举颜色空间的类型&nbsp;[更多...](#colordataspace) | 
| [HDRFormat](#hdrformat)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref665428812083931,link:zh-cn_topic_0000001295414172.xml#ggabdc446aa6fa47c5dd8d1b7d87bed2566a0799ce04a1873f60ed59c3d30dcda69a](#ggabdc446aa6fa47c5dd8d1b7d87bed2566a0799ce04a1873f60ed59c3d30dcda69a)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref638522815083931,link:zh-cn_topic_0000001295414172.xml#ggabdc446aa6fa47c5dd8d1b7d87bed2566ac43f1175d92c85033e0a85c7a14266a7](#ggabdc446aa6fa47c5dd8d1b7d87bed2566ac43f1175d92c85033e0a85c7a14266a7)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2122250653083931,link:zh-cn_topic_0000001295414172.xml#ggabdc446aa6fa47c5dd8d1b7d87bed2566ada5b15b3c4b4cc64593452113ac1d4dc](#ggabdc446aa6fa47c5dd8d1b7d87bed2566ada5b15b3c4b4cc64593452113ac1d4dc)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref6932435083931,link:zh-cn_topic_0000001295414172.xml#ggabdc446aa6fa47c5dd8d1b7d87bed2566a2c6e7224778e782cbbd478e4c11282e2](#ggabdc446aa6fa47c5dd8d1b7d87bed2566a2c6e7224778e782cbbd478e4c11282e2)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1192919169083931,link:zh-cn_topic_0000001295414172.xml#ggabdc446aa6fa47c5dd8d1b7d87bed2566abc6f25afdafdebb03fd137de1917389d](#ggabdc446aa6fa47c5dd8d1b7d87bed2566abc6f25afdafdebb03fd137de1917389d)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1193677514083931,link:zh-cn_topic_0000001295414172.xml#ggabdc446aa6fa47c5dd8d1b7d87bed2566a84318c5a162e5b9b822e38e675117e42](#ggabdc446aa6fa47c5dd8d1b7d87bed2566a84318c5a162e5b9b822e38e675117e42)&nbsp;=&nbsp;5&nbsp;} | 枚举HDR格式&nbsp;[更多...](#hdrformat) | 
| [HDRMetadataKey](#hdrmetadatakey)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1884505899083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a92c0f5eaba344bee22c657040b606fd3](#gga5d7d90acb5c568e62a02b18446f37789a92c0f5eaba344bee22c657040b606fd3)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref651614535083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a405841a4999556bd36281870d579dc7e](#gga5d7d90acb5c568e62a02b18446f37789a405841a4999556bd36281870d579dc7e)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref2104996214083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a08f31a74e8df3253c6326879818dfe1b](#gga5d7d90acb5c568e62a02b18446f37789a08f31a74e8df3253c6326879818dfe1b)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1726732454083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a19db3eede73e96c6a25dc4d31e5846e1](#gga5d7d90acb5c568e62a02b18446f37789a19db3eede73e96c6a25dc4d31e5846e1)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref149187678083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a23e7112a9c4aaf15bc2a529344a61939](#gga5d7d90acb5c568e62a02b18446f37789a23e7112a9c4aaf15bc2a529344a61939)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref957659268083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a5a34485b5884d8bd86273750b9d47b0b](#gga5d7d90acb5c568e62a02b18446f37789a5a34485b5884d8bd86273750b9d47b0b)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref254163734083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789ac12237b3de1eee6176c690e7f14ab339](#gga5d7d90acb5c568e62a02b18446f37789ac12237b3de1eee6176c690e7f14ab339)&nbsp;=&nbsp;6,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1227069924083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a331c8b69a7d9484c9eaea70e78a34921](#gga5d7d90acb5c568e62a02b18446f37789a331c8b69a7d9484c9eaea70e78a34921)&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1152477491083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789ac27053151e1fa76e58dc3281d843ad74](#gga5d7d90acb5c568e62a02b18446f37789ac27053151e1fa76e58dc3281d843ad74)&nbsp;=&nbsp;8,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref974552333083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a345f5cea142c7357e0b9de5ccfc86bed](#gga5d7d90acb5c568e62a02b18446f37789a345f5cea142c7357e0b9de5ccfc86bed)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref332772781083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a9897f53fcb179afc9c90f8c7ca0ac254](#gga5d7d90acb5c568e62a02b18446f37789a9897f53fcb179afc9c90f8c7ca0ac254)&nbsp;=&nbsp;10,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref819598522083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a8d285ea7b6246f62b7e7a65e5a870bfe](#gga5d7d90acb5c568e62a02b18446f37789a8d285ea7b6246f62b7e7a65e5a870bfe)&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1771466287083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789a89ef9c02321a94080f185c7fea3f6d1d](#gga5d7d90acb5c568e62a02b18446f37789a89ef9c02321a94080f185c7fea3f6d1d)&nbsp;=&nbsp;12,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1713611155083931,link:zh-cn_topic_0000001295414172.xml#gga5d7d90acb5c568e62a02b18446f37789ac99c4612b3aee2bfede23070fe32ac7e](#gga5d7d90acb5c568e62a02b18446f37789ac99c4612b3aee2bfede23070fe32ac7e)&nbsp;=&nbsp;13&nbsp;} | 枚举HDR元数据关键字&nbsp;[更多...](#hdrmetadatakey) | 
| [PresentTimestampType](#presenttimestamptype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref660661019083931,link:zh-cn_topic_0000001295414172.xml#ggabdba71665ea5ba4004ac1a9fbeb505f3ad6e47ab1a80ab94cccb5e465610ff45d](#ggabdba71665ea5ba4004ac1a9fbeb505f3ad6e47ab1a80ab94cccb5e465610ff45d)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1774566629083931,link:zh-cn_topic_0000001295414172.xml#ggabdba71665ea5ba4004ac1a9fbeb505f3a5c06391b9583b69d37c7a0518dd10f09](#ggabdba71665ea5ba4004ac1a9fbeb505f3a5c06391b9583b69d37c7a0518dd10f09)&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref1494486451083931,link:zh-cn_topic_0000001295414172.xml#ggabdba71665ea5ba4004ac1a9fbeb505f3afd872c457c9dade672aaaec5de622ff7](#ggabdba71665ea5ba4004ac1a9fbeb505f3afd872c457c9dade672aaaec5de622ff7)&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;} | 上屏时间戳类型枚举值&nbsp;[更多...](#presenttimestamptype) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [DeviceInitialize](#deviceinitialize)&nbsp;([DeviceFuncs](_device_funcs.md)&nbsp;\*\*funcs) | 实现显示设备控制接口的初始化，申请操作显示设备控制接口的资源，并获取对应的操作接口。&nbsp;[更多...](#deviceinitialize) | 
| [DeviceUninitialize](#deviceuninitialize)&nbsp;([DeviceFuncs](_device_funcs.md)&nbsp;\*funcs) | 取消显示设备控制接口的初始化，释放控制接口使用到的资源。&nbsp;[更多...](#deviceuninitialize) | 
| [GfxInitialize](#gfxinitialize)&nbsp;([GfxFuncs](_gfx_funcs.md)&nbsp;\*\*funcs) | 获取硬件加速相关的操作接口指针。&nbsp;[更多...](#gfxinitialize) | 
| [GfxUninitialize](#gfxuninitialize)&nbsp;([GfxFuncs](_gfx_funcs.md)&nbsp;\*funcs) | 释放硬件加速相关的操作接口指针。&nbsp;[更多...](#gfxuninitialize) | 
| [GrallocInitialize](#grallocinitialize)&nbsp;([GrallocFuncs](_gralloc_funcs.md)&nbsp;\*\*funcs) | 初始化内存模块，并获取内存提供的操作接口。&nbsp;[更多...](#grallocinitialize) | 
| [GrallocUninitialize](#grallocuninitialize)&nbsp;([GrallocFuncs](_gralloc_funcs.md)&nbsp;\*funcs) | 取消初始化内存模块，并释放内存操作接口指针。&nbsp;[更多...](#grallocuninitialize) | 
| [LayerInitialize](#layerinitialize)&nbsp;([LayerFuncs](_layer_funcs.md)&nbsp;\*\*funcs) | 实现图层初始化功能，申请图层使用的资源，并获取图层提供的操作接口。&nbsp;[更多...](#layerinitialize) | 
| [LayerUninitialize](#layeruninitialize)&nbsp;([LayerFuncs](_layer_funcs.md)&nbsp;\*funcs) | 取消图层初始化功能，释放图层使用到的资源，并释放图层操作接口指针。&nbsp;[更多...](#layeruninitialize) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| (&nbsp;[DeviceFuncs::RegHotPlugCallback](#reghotplugcallback)&nbsp;)([HotPlugCallback](#hotplugcallback)&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册热插拔事件回调。&nbsp;[更多...](#reghotplugcallback) | 
| (&nbsp;[DeviceFuncs::RegDisplayVBlankCallback](#regdisplayvblankcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[VBlankCallback](#vblankcallback)&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册VBlank事件回调。&nbsp;[更多...](#regdisplayvblankcallback) | 
| (&nbsp;[DeviceFuncs::RegDisplayRefreshCallback](#regdisplayrefreshcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[RefreshCallback](#refreshcallback)&nbsp;callback,&nbsp;void&nbsp;\*data) | 刷新请求回调。&nbsp;[更多...](#regdisplayrefreshcallback) | 
| (&nbsp;[DeviceFuncs::GetDisplayCapability](#getdisplaycapability)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DisplayCapability](_display_capability.md)&nbsp;\*info) | 获取显示设备能力集。&nbsp;[更多...](#getdisplaycapability) | 
| (&nbsp;[DeviceFuncs::GetDisplaySupportedModes](#getdisplaysupportedmodes)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[DisplayModeInfo](_display_mode_info.md)&nbsp;\*modes) | 获取显示设备支持的显示模式信息。&nbsp;[更多...](#getdisplaysupportedmodes) | 
| (&nbsp;[DeviceFuncs::GetDisplayMode](#getdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*modeId) | 获取显示设备当前的显示模式。&nbsp;[更多...](#getdisplaymode) | 
| (&nbsp;[DeviceFuncs::SetDisplayMode](#setdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;modeId) | 设置显示设备的显示模式。&nbsp;[更多...](#setdisplaymode) | 
| (&nbsp;[DeviceFuncs::GetDisplayPowerStatus](#getdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DispPowerStatus](#disppowerstatus)&nbsp;\*status) | 获取显示设备当前的电源状态。&nbsp;[更多...](#getdisplaypowerstatus) | 
| ([&nbsp;DeviceFuncs::SetDisplayPowerStatus](#setdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DispPowerStatus](#disppowerstatus)&nbsp;status) | 设置显示设备当前的电源状态。&nbsp;[更多...](#setdisplaypowerstatus) | 
| (&nbsp;[DeviceFuncs::GetDisplayBacklight](#getdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*level) | 获取显示设备当前的背光值。&nbsp;[更多...](#getdisplaybacklight) | 
| (&nbsp;[DeviceFuncs::SetDisplayBacklight](#setdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;level) | 设置显示设备当前的背光值。&nbsp;[更多...](#setdisplaybacklight) | 
| (&nbsp;[DeviceFuncs::GetDisplayProperty](#getdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;\*value) | 获得显示设备属性值。&nbsp;[更多...](#getdisplayproperty) | 
| (&nbsp;[DeviceFuncs::SetDisplayProperty](#setdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;value) | 设置显示设备属性值。&nbsp;[更多...](#setdisplayproperty) | 
| (&nbsp;[DeviceFuncs::PrepareDisplayLayers](#preparedisplaylayers)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;\*needFlushFb) | 显示设备合成前准备。&nbsp;[更多...](#preparedisplaylayers) | 
| (&nbsp;[DeviceFuncs::GetDisplayCompChange](#getdisplaycompchange)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*Layers,&nbsp;int32_t&nbsp;\*type) | 获取显示设备合成类型有变化的layer。&nbsp;[更多...](#getdisplaycompchange) | 
| (&nbsp;[DeviceFuncs::SetDisplayClientCrop](#setdisplayclientcrop)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | 设置显示设备的裁剪区域。&nbsp;[更多...](#setdisplayclientcrop) | 
| (&nbsp;[DeviceFuncs::SetDisplayClientDestRect](#setdisplayclientdestrect)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | 设置显示设备的显示区域。&nbsp;[更多...](#setdisplayclientdestrect) | 
| (&nbsp;[DeviceFuncs::SetDisplayClientBuffer](#setdisplayclientbuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置显示设备的显示缓存。&nbsp;[更多...](#setdisplayclientbuffer) | 
| (&nbsp;[DeviceFuncs::SetDisplayClientDamage](#setdisplayclientdamage)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;num,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | 设置显示设备的显示脏区。&nbsp;[更多...](#setdisplayclientdamage) | 
| (&nbsp;[DeviceFuncs::SetDisplayVsyncEnabled](#setdisplayvsyncenabled)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;enabled) | 使能垂直同步信号。&nbsp;[更多...](#setdisplayvsyncenabled) | 
| (&nbsp;[DeviceFuncs::GetDisplayReleaseFence](#getdisplayreleasefence)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*layers,&nbsp;int32_t&nbsp;\*fences) | 获取显示图层fence。&nbsp;[更多...](#getdisplayreleasefence) | 
| (&nbsp;[DeviceFuncs::GetDisplaySupportedColorGamuts](#getdisplaysupportedcolorgamuts)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[ColorGamut](#colorgamut)&nbsp;\*gamuts) | 获取显示设备支持的色域信息。&nbsp;[更多...](#getdisplaysupportedcolorgamuts) | 
| (&nbsp;[DeviceFuncs::GetDisplayColorGamut](#getdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](#colorgamut)&nbsp;\*gamut) | 获取显示设备当前的色域模式。&nbsp;[更多...](#getdisplaycolorgamut) | 
| (&nbsp;[DeviceFuncs::SetDisplayColorGamut](#setdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](#colorgamut)&nbsp;gamut) | 设置显示设备当前的色域模式。&nbsp;[更多...](#setdisplaycolorgamut) | 
| (&nbsp;[DeviceFuncs::GetDisplayGamutMap](#getdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](#colorgamut)&nbsp;\*gamutMap) | 获取显示设备当前的色域映射模式。&nbsp;[更多...](#getdisplaygamutmap) | 
| (&nbsp;[DeviceFuncs::SetDisplayGamutMap](#setdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](#colorgamut)&nbsp;gamutMap) | 设置显示设备当前的色域映射模式。&nbsp;[更多...](#setdisplaygamutmap) | 
| (&nbsp;[DeviceFuncs::SetDisplayColorTransform](#setdisplaycolortransform)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;float&nbsp;\*matrix) | 设置显示设备当前的4x4的颜色转换矩阵。&nbsp;[更多...](#setdisplaycolortransform) | 
| (&nbsp;[DeviceFuncs::GetHDRCapabilityInfos](#gethdrcapabilityinfos)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[HDRCapability](_h_d_r_capability.md)&nbsp;\*info) | 获取显示设备支持的HDR属性信息。&nbsp;[更多...](#gethdrcapabilityinfos) | 
| (&nbsp;[DeviceFuncs::GetSupportedMetadataKey](#getsupportedmetadatakey)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[HDRMetadataKey](#hdrmetadatakey)&nbsp;\*keys) | 获取显示设备支持的&nbsp;HDRMetadataKey。&nbsp;[更多...](#getsupportedmetadatakey) | 
| (&nbsp;[DeviceFuncs::Commit](#commit)&nbsp;)(uint32_t&nbsp;devId,&nbsp;int32_t&nbsp;\*fence) | 提交合成送显请求。&nbsp;[更多...](#commit) | 
| (&nbsp;[DeviceFuncs::InvokeDisplayCmd](#invokedisplaycmd)&nbsp;)(uint32_t&nbsp;devId,...) | 调用显示设备命令。&nbsp;[更多...](#invokedisplaycmd) | 
| ([&nbsp;DeviceFuncs::CreateVirtualDisplay](#createvirtualdisplay)&nbsp;)(uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format,&nbsp;uint32_t&nbsp;\*devId) | 创建虚拟显示设备。&nbsp;[更多...](#createvirtualdisplay) | 
| (&nbsp;[DeviceFuncs::DestroyVirtualDisplay](#destroyvirtualdisplay)&nbsp;)(uint32_t&nbsp;devId) | 销毁虚拟显示设备。&nbsp;[更多...](#destroyvirtualdisplay) | 
| (&nbsp;[DeviceFuncs::SetVirtualDisplayBuffer](#setvirtualdisplaybuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置虚拟屏的输出缓存。&nbsp;[更多...](#setvirtualdisplaybuffer) | 
| (&nbsp;[DeviceFuncs::GetWriteBackFrame](#getwritebackframe)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;\*fence) | 获取显示设备的回写帧。&nbsp;[更多...](#getwritebackframe) | 
| (&nbsp;[DeviceFuncs::CreateWriteBack](#createwriteback)&nbsp;)(uint32_t&nbsp;\*devId,&nbsp;uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format) | 对指定显示设备创建回写点。&nbsp;[更多...](#createwriteback) | 
| (&nbsp;[DeviceFuncs::DestroyWriteBack](#destroywriteback)&nbsp;)(uint32_t&nbsp;devId) | 销毁指定显示设备的回写点。&nbsp;[更多...](#destroywriteback) | 
| [DisplayInfo::width](#width-17) | 显示屏宽度 | 
| [DisplayInfo::height](#height-17) | 显示屏高度 | 
| [DisplayInfo::rotAngle](#rotangle) | 显示屏旋转角度 | 
| [LayerInfo::width](#width-27) | 图层宽度 | 
| [LayerInfo::height](#height-27) | 图层高度 | 
| [LayerInfo::type](#type-13) | 图层类型，包括图形层、视频层和媒体播放模式 | 
| [LayerInfo::bpp](#bpp) | 每像素所占bit数 | 
| [LayerInfo::pixFormat](#pixformat-12) | 图层像素格式 | 
| [LayerAlpha::enGlobalAlpha](#englobalalpha-12) | 全局alpha使能标志 | 
| [LayerAlpha::enPixelAlpha](#enpixelalpha-12) | 像素alpha使能标志 | 
| [LayerAlpha::alpha0](#alpha0-12) | alpha0值，取值范围：[0,&nbsp;255] | 
| [LayerAlpha::alpha1](#alpha1-12) | alpha1值，取值范围：[0,&nbsp;255] | 
| [LayerAlpha::gAlpha](#galpha) | 全局alpha值，取值范围：[0,&nbsp;255] | 
| [BufferData::phyAddr](#phyaddr-12) | 物理内存地址 | 
| [BufferData::virAddr](#viraddr) | 虚拟内存地址 | 
| [LayerBuffer::fenceId](#fenceid) | buffer&nbsp;的fence号r | 
| [LayerBuffer::width](#width-37) | buffer宽度 | 
| [LayerBuffer::height](#height-37) | buffer高度 | 
| [LayerBuffer::pitch](#pitch) | 一行数据所占字节数 | 
| [LayerBuffer::pixFormat](#pixformat-22) | buffer像素格式r | 
| [LayerBuffer::data](#data) | 图层buffer数据 | 
| [LayerBuffer::hdl](#hdl) | 图层buffer句柄 | 
| [IRect::x](#x-12) | 矩形框起始x坐标 | 
| [IRect::y](#y-12) | 矩形框起始y坐标 | 
| [IRect::w](#w) | 矩形框宽度 | 
| [IRect::h](#h) | 矩形框高度 | 
| [ISurface::phyAddr](#phyaddr-22) | 图像首地址 | 
| [ISurface::height](#height-47) | 图像高度 | 
| [ISurface::width](#width-47) | 图像宽度 | 
| [ISurface::stride](#stride) | 图像跨度 | 
| [ISurface::enColorFmt](#encolorfmt) | 图像格式 | 
| [ISurface::bYCbCrClut](#bycbcrclut) | CLUT表是否位于&nbsp;YCbCr&nbsp;空间 | 
| [ISurface::bAlphaMax255](#balphamax255) | 图像alpha最大值为255还是128 | 
| [ISurface::bAlphaExt1555](#balphaext1555) | 是否使能1555的Alpha扩展 | 
| [ISurface::alpha0](#alpha0-22) | Alpha0值，取值范围：[0,255] | 
| [ISurface::alpha1](#alpha1-22) | Alpha1值，取值范围：[0,255] | 
| [ISurface::cbcrPhyAddr](#cbcrphyaddr) | CbCr分量地址 | 
| [ISurface::cbcrStride](#cbcrstride) | CbCr分量跨度 | 
| [ISurface::clutPhyAddr](#clutphyaddr) | Clut表首地址，用作颜色扩展或颜色校正 | 
| [ILine::x0](#x0) | 线条起点的x坐标 | 
| [ILine::y0](#y0) | 线条起点的y坐标 | 
| [ILine::x1](#x1) | 线条终点的x坐标 | 
| [ILine::y1](#y1) | 线条终点的y坐标 | 
| [ILine::color](#color-13) | 线条颜色 | 
| [ICircle::x](#x-22) | 圆心x坐标 | 
| [ICircle::y](#y-22) | 圆心y坐标r | 
| [ICircle::r](#r) | 圆的半径 | 
| [ICircle::color](#color-23) | 圆的颜色 | 
| [Rectangle::rect](#rect) | 矩形区域 | 
| [Rectangle::color](#color-33) | 矩形颜色 | 
| [GfxOpt::enGlobalAlpha](#englobalalpha-22) | 全局alpha使能位 | 
| [GfxOpt::globalAlpha](#globalalpha) | 全局alpha的值 | 
| [GfxOpt::enPixelAlpha](#enpixelalpha-22) | 像素alpha使能位 | 
| [GfxOpt::blendType](#blendtype) | 混合方式 | 
| [GfxOpt::colorKeyFrom](#colorkeyfrom) | 色键模式 | 
| [GfxOpt::enableRop](#enablerop) | Rop功能使能位 | 
| [GfxOpt::colorRopType](#colorroptype) | 颜色的Rop类型 | 
| [GfxOpt::alphaRopType](#alpharoptype) | Alpha的Rop类型 | 
| [GfxOpt::enableScale](#enablescale) | 缩放功能使能位 | 
| [GfxOpt::rotateType](#rotatetype) | 旋转类型 | 
| [GfxOpt::mirrorType](#mirrortype) | 镜像类型 | 
| [PropertyObject::name](#name-12)&nbsp;[PROPERTY_NAME_LEN] | 属性名称 | 
| [PropertyObject::propId](#propid) | 属性ID | 
| [PropertyObject::value](#value-12) | 属性值 | 
| [DisplayCapability::name](#name-22)&nbsp;[PROPERTY_NAME_LEN] | 显示设备名称 | 
| [DisplayCapability::type](#type-23) | 显示屏接口类型 | 
| [DisplayCapability::phyWidth](#phywidth) | 物理宽度 | 
| [DisplayCapability::phyHeight](#phyheight) | 物理高度 | 
| [DisplayCapability::supportLayers](#supportlayers) | 支持的图层数 | 
| [DisplayCapability::virtualDispCount](#virtualdispcount) | 支持的虚拟屏数 | 
| [DisplayCapability::supportWriteBack](#supportwriteback) | 是否支持回写 | 
| [DisplayCapability::propertyCount](#propertycount) | 属性数组大小 | 
| [DisplayCapability::props](#props) | 属性数组 | 
| [DisplayModeInfo::width](#width-57) | 像素宽度 | 
| [DisplayModeInfo::height](#height-57) | 像素高度 | 
| [DisplayModeInfo::freshRate](#freshrate) | 刷新速率 | 
| [DisplayModeInfo::id](#id) | 模式ID | 
| [AllocInfo::width](#width-67) | 申请内存宽度 | 
| [AllocInfo::height](#height-67) | 申请内存高度 | 
| [AllocInfo::usage](#usage-12) | 申请内存的使用场景 | 
| [AllocInfo::format](#format-12) | 申请内存格式 | 
| [AllocInfo::expectedSize](#expectedsize) | 申请内存大小 | 
| [HDRCapability::formatCount](#formatcount) | 支持的HDR格式的数量 | 
| [HDRCapability::formats](#formats) | 支持的HDR格式的数组首地址 | 
| [HDRCapability::maxLum](#maxlum) | 最大的光亮度luminance值 | 
| [HDRCapability::maxAverageLum](#maxaveragelum) | 最大的平均光亮度luminance值 | 
| [HDRCapability::minLum](#minlum) | 最小的光亮度luminance值 | 
| [HDRMetaData::key](#key) | HDR元数据关键字 | 
| [HDRMetaData::value](#value-22) | 关键字对应的值 | 
| [VerifyAllocInfo::width](#width-77) | 分配内存的宽度 | 
| [VerifyAllocInfo::height](#height-77) | 分配内存的高度 | 
| [VerifyAllocInfo::usage](#usage-22) | 内存的用处 | 
| [VerifyAllocInfo::format](#format-22) | 分配内存的像素格式 | 
| [PresentTimestamp::type](#type-33) | 上屏时间戳类型 | 
| [PresentTimestamp::time](#time) | 类型对应的值 | 
| [__attribute__::fd](#fd) | 句柄&nbsp;fd，-1代表不支持 | 
| [__attribute__::reserveInts](#reserveints) | reserve数组的个数 | 
| [__attribute__::reserve](#reserve)&nbsp;[0] | reserve数组 | 
| [__attribute__::baseAddr](#baseaddr) | 内存的初始地址 | 
| [__attribute__::yOffset](#yoffset) | Y的偏移量 | 
| [__attribute__::uOffset](#uoffset) | U的偏移量 | 
| [__attribute__::vOffset](#voffset) | V的偏移量 | 
| [__attribute__::yStride](#ystride) | Y的stride信息 | 
| [__attribute__::uvStride](#uvstride) | UV的stride信息 | 
| [__attribute__::uvStep](#uvstep) | UV的step信息 | 


## **详细描述**

显示模块驱动接口定义。

提供给图形系统使用的驱动接口，包括图层管理、设备控制、图形硬件加速、显示内存管理和回调接口等。

**Since：**

1.0

**Version：**

2.0


## **类型定义说明**


### HotPlugCallback

  
```
typedef void(* HotPlugCallback) (uint32_t devId, bool connected, void *data)
```

**描述：**

热插拔事件回调。

当有热插拔事件发生时，会回调该接口，需要通过RegHotPlugCallback注册该回调接口。

\@paramdevId 输入参数，显示设备ID，此ID由HDI实现层生成，并通过当前回调接口传递给图形服务使用，用以标记当前连接的显示设备。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| connected | 输入参数，指明设备的连接状态，ture代表连接，false代表断开。 | 
| data | 输出参数，图形服务携带的私有数据，该参数携带的是RegHotPlugCallback接口注册时传递的私有数据地址，详情参考&nbsp;RegHotPlugCallback&nbsp;接口注册时传递的地址。 | 


### RefreshCallback

  
```
typedef void(* RefreshCallback) (uint32_t devId, void *data)
```

**描述：**

刷新请求回调。

刷新请求回调，当接口实现层需要图形服务刷新数据帧时会回调该接口，需要通过RegDisplayRefreshCallback注册该回调接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID。 | 
| data | 输出参数，图形服务携带的私有数据，该参数携带的是RegDisplayRefreshCallback接口注册时传递的地址。 | 


### VBlankCallback

  
```
typedef void(* VBlankCallback) (unsigned int sequence, uint64_t ns, void *data)
```

**描述：**

VBlank 事件回调。

垂直同步事件回调接口，需要通过RegDisplayVBlankCallback注册该回调接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sequence | 输入参数，指明VBlank序列，是一个累加值。 | 
| ns | 输入参数，该次VBlank事件的时间戳，以纳秒为单位。 | 
| data | 输出参数，图形服务携带的私有数据，该参数携带的是RegDisplayVBlankCallback接口注册时传递的地址。 | 


## **枚举类型说明**


### anonymous enum

  
```
anonymous enum
```

**描述：**

缓冲区定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| HBM_USE_CPU_READ | CPU&nbsp;读缓冲 | 
| HBM_USE_CPU_WRITE | CPU&nbsp;写内存 | 
| HBM_USE_MEM_MMZ | MMZ | 
| HBM_USE_MEM_DMA | DMA缓冲区 | 
| HBM_USE_MEM_SHARE | 共享内存缓冲区 | 
| HBM_USE_MEM_MMZ_CACHE | MMZ缓存 | 
| HBM_USE_MEM_FB | 帧缓存 | 
| HBM_USE_ASSIGN_SIZE | 内存分配 | 


### BlendType

  
```
enum BlendType
```

**描述：**

显示内存类型定义。

根据图形系统指定的类型进行分配，包括带cache或者不带cache的内存。

  | 枚举值 | 描述 | 
| -------- | -------- |
| BLEND_NONE | No&nbsp;混合操作 | 
| BLEND_CLEAR | CLEAR&nbsp;混合操作 | 
| BLEND_SRC | SRC&nbsp;混合操作 | 
| BLEND_SRCOVER | SRC_OVER&nbsp;混合操作 | 
| BLEND_DSTOVER | DST_OVER&nbsp;混合操作 | 
| BLEND_SRCIN | SRC_IN&nbsp;混合操作 | 
| BLEND_DSTIN | DST_IN&nbsp;混合操作 | 
| BLEND_SRCOUT | SRC_OUT&nbsp;混合操作 | 
| BLEND_DSTOUT | DST_OUT&nbsp;混合操作 | 
| BLEND_SRCATOP | SRC_ATOP&nbsp;混合操作 | 
| BLEND_DSTATOP | DST_ATOP&nbsp;混合操作 | 
| BLEND_ADD | ADD&nbsp;混合操作 | 
| BLEND_XOR | XOR&nbsp;混合操作 | 
| BLEND_DST | DST&nbsp;混合操作 | 
| BLEND_AKS | AKS&nbsp;混合操作 | 
| BLEND_AKD | AKD&nbsp;混合操作 | 
| BLEND_BUTT | 空操作 | 


### ColorDataSpace

  
```
enum ColorDataSpace
```

**描述：**

枚举颜色空间的类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_DATA_SPACE_UNKNOWN | 未知的 | 
| GAMUT_BT601 | BT601色域 | 
| GAMUT_BT709 | BT709色域 | 
| GAMUT_DCI_P3 | DCI_P3色域 | 
| GAMUT_SRGB | SRGB色域 | 
| GAMUT_ADOBE_RGB | ADOBE_RGB色域 | 
| GAMUT_DISPLAY_P3 | DISPLAY_P3色域 | 
| GAMUT_BT2020 | BT2020色域 | 
| GAMUT_BT2100_PQ | BT2100_PQ色域 | 
| GAMUT_BT2100_HLG | BT2100_HLG色域 | 
| GAMUT_DISPLAY_BT2020 | DISPLAY_BT2020色域 | 
| TRANSFORM_FUNC_UNSPECIFIED | UNSPECIFIED转换函数 | 
| TRANSFORM_FUNC_LINEAR | LINEAR转换函数 | 
| TRANSFORM_FUNC_SRGB | SRGB转换函数 | 
| TRANSFORM_FUNC_SMPTE_170M | SMPTE_170M转换函数 | 
| TRANSFORM_FUNC_GM2_2 | GM2_2转换函数 | 
| TRANSFORM_FUNC_GM2_6 | GM2_6转换函数 | 
| TRANSFORM_FUNC_GM2_8 | GM2_8转换函数 | 
| TRANSFORM_FUNC_ST2084 | ST2084转换函数 | 
| TRANSFORM_FUNC_HLG | HLG转换函数 | 
| PRECISION_UNSPECIFIED | UNSPECIFIED精度 | 
| PRECISION_FULL | FULL精度 | 
| PRESION_LIMITED | LIMITED精度 | 
| PRESION_EXTENDED | EXTENDED精度 | 
| BT601_SMPTE170M_FULL | BT601色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT601_SMPTE170M_LIMITED | BT601色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;LIMITED精度 | 
| BT709_LINEAR_FULL | BT709色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT709_LINEAR_EXTENDED | BT709色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;EXTENDED精度 | 
| BT709_SRGB_FULL | BT709色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT709_SRGB_EXTENDED | BT709色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;EXTENDED精度 | 
| BT709_SMPTE170M_LIMITED | BT709色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;LIMITED精度 | 
| DCI_P3_LINEAR_FULL | DCI_P3色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| DCI_P3_GAMMA26_FULL | DCI_P3色域&nbsp;\|&nbsp;GM2_6转换函数&nbsp;\|&nbsp;FULL精度 | 
| DISPLAY_P3_LINEAR_FULL | DISPLAY_P3色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| DCI_P3_SRGB_FULL | DCI_P3色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;FULL精度 | 
| ADOBE_RGB_GAMMA22_FULL | ADOBE_RGB色域&nbsp;\|&nbsp;GM2_2转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_LINEAR_FULL | BT2020色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_SRGB_FULL | BT2020色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_SMPTE170M_FULL | BT2020色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_ST2084_FULL | BT2020色域&nbsp;\|&nbsp;ST2084转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_HLG_FULL | BT2020色域&nbsp;\|&nbsp;HLG转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_ST2084_LIMITED | BT2020色域&nbsp;\|&nbsp;ST2084转换函数&nbsp;\|&nbsp;LIMITED精度 | 


### ColorGamut

  
```
enum ColorGamut
```

**描述：**

色域类型枚举值。

  | 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_GAMUT_INVALID | 无效值 | 
| COLOR_GAMUT_NATIVE | 默认值 | 
| COLOR_GAMUT_SATNDARD_BT601 | Standard&nbsp;BT601类型 | 
| COLOR_GAMUT_STANDARD_BT709 | Standard&nbsp;BT709类型 | 
| COLOR_GAMUT_DCI_P3 | DCI&nbsp;P3类型 | 
| COLOR_GAMUT_SRGB | SRGB类型 | 
| COLOR_GAMUT_ADOBE_RGB | Adobe&nbsp;RGB类型 | 
| COLOR_GAMUT_DISPLAY_P3 | display&nbsp;P3类型 | 
| COLOR_GAMUT_BT2020 | BT2020类型 | 
| COLOR_GAMUT_BT2100_PQ | BT2100&nbsp;PQ类型 | 
| COLOR_GAMUT_BT2100_HLG | BT2100&nbsp;HLG类型 | 
| COLOR_GAMUT_DISPLAY_BT2020 | Display&nbsp;BT2020类型 | 


### ColorKey

  
```
enum ColorKey
```

**描述：**

Color key操作类型定义，即硬件加速支持的Color key操作类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CKEY_NONE | 不使用colorkey | 
| CKEY_SRC | 使用源colorkey | 
| CKEY_DST | 使用目标colorkey | 
| CKEY_BUTT | 空操作 | 


### CompositionType

  
```
enum CompositionType
```

**描述：**

枚举特殊层的组合类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| COMPOSITION_CLIENT | Client&nbsp;合成类型，使用CPU或者GPU合成。 | 
| COMPOSITION_DEVICE | Device&nbsp;合成类型，使用Device合成。 | 
| COMPOSITION_CURSOR | Cursor合成类型，用于光标合成。 | 
| COMPOSITION_VIDEO | Video合成类型，用于视频层合成。 | 
| COMPOSITION_DEVICE_CLEAR | Device&nbsp;clear&nbsp;合成类型，device会清除目标区域。 | 
| COMPOSITION_CLIENT_CLEAR | Client&nbsp;clear&nbsp;合成类型，service会清除目标区域。 | 
| COMPOSITION_TUNNEL | Tunnel&nbsp;合成类型，用于tunnel。 | 
| COMPOSITION_BUTT | 合成类型，一个不可用类型，用于默认初始化。 | 


### Connection

  
```
enum Connection
```

**描述：**

热插拔连接类型定义

  | 枚举值 | 描述 | 
| -------- | -------- |
| CON_INVALID | 无效类型 | 
| CONNECTED | 已连接 | 
| DISCONNECTED | 断开连接 | 


### DispErrCode

  
```
enum DispErrCode
```

**描述：**

返回值类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_SUCCESS | 成功 | 
| DISPLAY_FAILURE | 失败 | 
| DISPLAY_FD_ERR | fd错误 | 
| DISPLAY_PARAM_ERR | 参数错误 | 
| DISPLAY_NULL_PTR | 空指针 | 
| DISPLAY_NOT_SUPPORT | 不支持的特性 | 
| DISPLAY_NOMEM | 内存不足 | 
| DISPLAY_SYS_BUSY | 系统繁忙 | 
| DISPLAY_NOT_PERM | 操作不允许 | 


### DispPowerStatus

  
```
enum DispPowerStatus
```

**描述：**

枚举显示状态

  | 枚举值 | 描述 | 
| -------- | -------- |
| POWER_STATUS_ON | 上电模式 | 
| POWER_STATUS_STANDBY | 待机模式 | 
| POWER_STATUS_SUSPEND | 休眠模式 | 
| POWER_STATUS_OFF | 下电模式 | 
| POWER_STATUS_BUTT | 默认模式 | 


### GamutMap

  
```
enum GamutMap
```

**描述：**

枚举色域的映射类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| GAMUT_MAP_CONSTANT | 不变 | 
| GAMUT_MAP_EXPANSION | 映射增强 | 
| GAMUT_MAP_HDR_CONSTANT | 不变，用于HDR | 
| GAMUT_MAP_HDR_EXPANSION | 映射增强，用于HDR | 


### HDRFormat

  
```
enum HDRFormat
```

**描述：**

枚举HDR格式

  | 枚举值 | 描述 | 
| -------- | -------- |
| NOT_SUPPORT_HDR | 不支持HDR | 
| DOLBY_VISION | Dolby&nbsp;Vision格式 | 
| HDR10 | HDR10格式 | 
| HLG | HLG格式 | 
| HDR10_PLUS | HDR10&nbsp;Plus格式 | 
| HDR_VIVID | Vivid格式 | 


### HDRMetadataKey

  
```
enum HDRMetadataKey
```

**描述：**

枚举HDR元数据关键字

  | 枚举值 | 描述 | 
| -------- | -------- |
| MATAKEY_RED_PRIMARY_X | 红基色X坐标 | 
| MATAKEY_RED_PRIMARY_Y | 红基色Y坐标 | 
| MATAKEY_GREEN_PRIMARY_X | 绿基色X坐标 | 
| MATAKEY_GREEN_PRIMARY_Y | 绿基色Y坐标 | 
| MATAKEY_BLUE_PRIMARY_X | 蓝基色X坐标 | 
| MATAKEY_BLUE_PRIMARY_Y | 蓝基色Y坐标 | 
| MATAKEY_WHITE_PRIMARY_X | 白点X坐标 | 
| MATAKEY_WHITE_PRIMARY_Y | 白点Y坐标 | 
| MATAKEY_MAX_LUMINANCE | 最大的光亮度 | 
| MATAKEY_MIN_LUMINANCE | 最小的光亮度 | 
| MATAKEY_MAX_CONTENT_LIGHT_LEVEL | 最大的内容亮度水平 | 
| MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL | 最大的帧平均亮度水平 | 
| MATAKEY_HDR10_PLUS | HDR10&nbsp;Plus | 
| MATAKEY_HDR_VIVID | Vivid | 


### InterfaceType

  
```
enum InterfaceType
```

**描述：**

枚举接口类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DISP_INTF_HDMI | HDMI&nbsp;接口 | 
| DISP_INTF_LCD | LCD&nbsp;接口 | 
| DISP_INTF_BT1120 | BT1120&nbsp;接口 | 
| DISP_INTF_BT656 | BT656&nbsp;接口 | 
| DISP_INTF_YPBPR | YPBPR&nbsp;接口 | 
| DISP_INTF_RGB | RGB&nbsp;接口 | 
| DISP_INTF_CVBS | CVBS&nbsp;接口 | 
| DISP_INTF_SVIDEO | SVIDEO&nbsp;接口 | 
| DISP_INTF_VGA | VGA&nbsp;接口 | 
| DISP_INTF_MIPI | MIPI&nbsp;接口 | 
| DISP_INTF_PANEL | PANEL&nbsp;接口 | 
| DISP_INTF_BUTT | BUTT接口，一个不可用类型，用于默认初始化。 | 


### LayerType

  
```
enum LayerType
```

**描述：**

图层类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| LAYER_TYPE_GRAPHIC | 图形层 | 
| LAYER_TYPE_OVERLAY | 视频层 | 
| LAYER_TYPE_SDIEBAND | 媒体播放 | 
| LAYER_TYPE_CURSOR | 光标层 | 
| LAYER_TYPE_BUTT | 空图层 | 


### MirrorType

  
```
enum MirrorType
```

**描述：**

硬件加速支持的镜像操作类型定义

  | 枚举值 | 描述 | 
| -------- | -------- |
| MIRROR_NONE | 不使用镜像 | 
| MIRROR_LR | 左右镜像 | 
| MIRROR_TB | 上下镜像 | 
| MIRROR_BUTT | 空操作 | 


### PixelFormat

  
```
enum PixelFormat
```

**描述：**

像素格式类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIXEL_FMT_CLUT8 | CLUT8&nbsp;格式 | 
| PIXEL_FMT_CLUT1 | CLUT1&nbsp;格式 | 
| PIXEL_FMT_CLUT4 | CLUT4&nbsp;格式 | 
| PIXEL_FMT_RGB_565 | RGB565&nbsp;格式 | 
| PIXEL_FMT_RGBA_5658 | RGBA5658&nbsp;格式 | 
| PIXEL_FMT_RGBX_4444 | RGBX4444&nbsp;格式 | 
| PIXEL_FMT_RGBA_4444 | RGBA4444&nbsp;格式 | 
| PIXEL_FMT_RGB_444 | RGB444&nbsp;格式 | 
| PIXEL_FMT_RGBX_5551 | RGBX5551&nbsp;格式 | 
| PIXEL_FMT_RGBA_5551 | RGBA5551&nbsp;格式 | 
| PIXEL_FMT_RGB_555 | RGB555&nbsp;格式 | 
| PIXEL_FMT_RGBX_8888 | RGBX8888&nbsp;格式 | 
| PIXEL_FMT_RGBA_8888 | RGBA8888&nbsp;格式 | 
| PIXEL_FMT_RGB_888 | RGB888&nbsp;格式 | 
| PIXEL_FMT_BGR_565 | BGR565&nbsp;格式 | 
| PIXEL_FMT_BGRX_4444 | BGRX4444&nbsp;格式 | 
| PIXEL_FMT_BGRA_4444 | BGRA4444&nbsp;格式 | 
| PIXEL_FMT_BGRX_5551 | BGRX5551&nbsp;格式 | 
| PIXEL_FMT_BGRA_5551 | BGRA5551&nbsp;格式 | 
| PIXEL_FMT_BGRX_8888 | BGRX8888&nbsp;格式 | 
| PIXEL_FMT_BGRA_8888 | BGRA8888&nbsp;格式 | 
| PIXEL_FMT_YUV_422_I | YUV422&nbsp;交错格式 | 
| PIXEL_FMT_YCBCR_422_SP | YCBCR422&nbsp;半平面格式 | 
| PIXEL_FMT_YCRCB_422_SP | YCRCB422&nbsp;半平面格式 | 
| PIXEL_FMT_YCBCR_420_SP | YCBCR420&nbsp;半平面格式 | 
| PIXEL_FMT_YCRCB_420_SP | YCRCB420&nbsp;半平面格式 | 
| PIXEL_FMT_YCBCR_422_P | YCBCR422&nbsp;平面格式 | 
| PIXEL_FMT_YCRCB_422_P | YCRCB422&nbsp;平面格式 | 
| PIXEL_FMT_YCBCR_420_P | YCBCR420&nbsp;平面格式 | 
| PIXEL_FMT_YCRCB_420_P | YCRCB420&nbsp;平面格式 | 
| PIXEL_FMT_YUYV_422_PKG | YUYV422&nbsp;打包格式 | 
| PIXEL_FMT_UYVY_422_PKG | UYVY422&nbsp;打包格式t | 
| PIXEL_FMT_YVYU_422_PKG | YVYU422&nbsp;打包格式 | 
| PIXEL_FMT_VYUY_422_PKG | VYUY422&nbsp;打包格式 | 
| PIXEL_FMT_VENDER_MASK | vendor&nbsp;mask&nbsp;格式 | 
| PIXEL_FMT_BUTT | Invalid&nbsp;像素格式 | 


### PresentTimestampType

  
```
enum PresentTimestampType
```

**描述：**

上屏时间戳类型枚举值。

  | 枚举值 | 描述 | 
| -------- | -------- |
| HARDWARE_DISPLAY_PTS_UNSUPPORTED | 不支持 | 
| HARDWARE_DISPLAY_PTS_DELAY | Delay&nbsp;时延类型 | 
| HARDWARE_DISPLAY_PTS_TIMESTAMP | 时间戳类型 | 


### RopType

  
```
enum RopType
```

**描述：**

硬件加速支持的ROP操作类型。

硬件加速支持的ROP操作类型，在将前景位图的RGB颜色分量和Alpha分量值与背景位图的RGB颜色 分量值和Alpha分量值进行按位的布尔运算（包括按位与，按位或等），将结果输出。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ROP_BLACK | 黑色 | 
| ROP_NOTMERGEPEN | ~(S2+S1) | 
| ROP_MASKNOTPEN | ~S2&amp;S1 | 
| ROP_NOTCOPYPEN | ~S2 | 
| ROP_MASKPENNOT | S2&amp;~S1 | 
| ROP_NOT | ~S1 | 
| ROP_XORPEN | S2^S1 | 
| ROP_NOTMASKPEN | ~(S2&amp;S1) | 
| ROP_MASKPEN | S2&amp;S1 | 
| ROP_NOTXORPEN | ~(S2^S1) | 
| ROP_NOP | S1 | 
| ROP_MERGENOTPEN | ~S2+S1 | 
| ROP_COPYPE | S2 | 
| ROP_MERGEPENNOT | S2+~S1 | 
| ROP_MERGEPEN | S2+S1 | 
| ROP_WHITE | 白色 | 
| ROP_BUTT | 无效值 | 


### TransformType

  
```
enum TransformType
```

**描述：**

图层变换类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ROTATE_NONE | 不旋转 | 
| ROTATE_90 | 旋转90度 | 
| ROTATE_180 | 旋转180度 | 
| ROTATE_270 | 旋转270度 | 
| ROTATE_BUTT | 无效操作 | 


## **函数说明**


### DeviceInitialize()

  
```
int32_t DeviceInitialize (DeviceFuncs **funcs)
```

**描述：**

实现显示设备控制接口的初始化，申请操作显示设备控制接口的资源，并获取对应的操作接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，显示设备控制接口指针，初始化时分配内存，调用者不需要分配内存，调用者获取该指针用于操作显示设备。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**Since：**

1.0

**Version：**

1.0


### DeviceUninitialize()

  
```
int32_t DeviceUninitialize (DeviceFuncs * funcs)
```

**描述：**

取消显示设备控制接口的初始化，释放控制接口使用到的资源。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，显示设备控制接口指针，用于释放初始化函数中分配的操作指针内存。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**Since：**

1.0

**Version：**

1.0


### GfxInitialize()

  
```
int32_t GfxInitialize (GfxFuncs **funcs)
```

**描述：**

获取硬件加速相关的操作接口指针。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，硬件加速模块操作接口指针，调用者不需要分配内存，调用者获取该指针操作硬件加速。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**Since：**

1.0

**Version：**

1.0


### GfxUninitialize()

  
```
int32_t GfxUninitialize (GfxFuncs * funcs)
```

**描述：**

释放硬件加速相关的操作接口指针。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，硬件加速操作接口指针。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**Since：**

1.0

**Version：**

1.0


### GrallocInitialize()

  
```
int32_t GrallocInitialize (GrallocFuncs **funcs)
```

**描述：**

初始化内存模块，并获取内存提供的操作接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，内存模块操作接口指针，初始化内存模块时分配内存，调用者不需要分配内存，调用者获取该指针操作内存。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**Since：**

1.0

**Version：**

1.0


### GrallocUninitialize()

  
```
int32_t GrallocUninitialize (GrallocFuncs * funcs)
```

**描述：**

取消初始化内存模块，并释放内存操作接口指针。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，内存操作接口指针，用于释放内存初始化函数中分配的操作指针内存。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**Since：**

1.0

**Version：**

1.0


### LayerInitialize()

  
```
int32_t LayerInitialize (LayerFuncs **funcs)
```

**描述：**

实现图层初始化功能，申请图层使用的资源，并获取图层提供的操作接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，图层操作接口指针，初始化图层时分配内存，调用者不需要分配内存，调用者获取该指针操作图层。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**参见：**

[LayerUninitialize](#layeruninitialize)


### LayerUninitialize()

  
```
int32_t LayerUninitialize (LayerFuncs * funcs)
```

**描述：**

取消图层初始化功能，释放图层使用到的资源，并释放图层操作接口指针。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，图层操作接口指针，用于释放图层初始化函数中分配的操作指针内存。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**参见：**

[LayerInitialize](#layerinitialize)

**Since：**

1.0

**Version：**

1.0


## **变量说明**


### alpha0 [1/2]

  
```
uint8_t LayerAlpha::alpha0
```

**描述：**

alpha0值，取值范围：[0, 255]


### alpha0 [2/2]

  
```
uint8_t ISurface::alpha0
```

**描述：**

Alpha0值，取值范围：[0,255]


### alpha1 [1/2]

  
```
uint8_t LayerAlpha::alpha1
```

**描述：**

alpha1值，取值范围：[0, 255]


### alpha1 [2/2]

  
```
uint8_t ISurface::alpha1
```

**描述：**

Alpha1值，取值范围：[0,255]


### alphaRopType

  
```
RopType GfxOpt::alphaRopType
```

**描述：**

Alpha的Rop类型


### bAlphaExt1555

  
```
bool ISurface::bAlphaExt1555
```

**描述：**

是否使能1555的Alpha扩展


### bAlphaMax255

  
```
bool ISurface::bAlphaMax255
```

**描述：**

图像alpha最大值为255还是128


### baseAddr

  
```
void* __attribute__::baseAddr
```

**描述：**

内存的初始地址


### blendType

  
```
BlendType GfxOpt::blendType
```

**描述：**

混合方式


### bpp

  
```
int32_t LayerInfo::bpp
```

**描述：**

每像素所占bit数


### bYCbCrClut

  
```
bool ISurface::bYCbCrClut
```

**描述：**

CLUT表是否位于 YCbCr 空间


### cbcrPhyAddr

  
```
uint64_t ISurface::cbcrPhyAddr
```

**描述：**

CbCr分量地址


### cbcrStride

  
```
int32_t ISurface::cbcrStride
```

**描述：**

CbCr分量跨度


### clutPhyAddr

  
```
uint64_t ISurface::clutPhyAddr
```

**描述：**

Clut表首地址，用作颜色扩展或颜色校正


### color [1/3]

  
```
uint32_t ILine::color
```

**描述：**

线条颜色


### color [2/3]

  
```
uint32_t ICircle::color
```

**描述：**

圆的颜色


### color [3/3]

  
```
uint32_t Rectangle::color
```

**描述：**

矩形颜色


### colorKeyFrom

  
```
ColorKey GfxOpt::colorKeyFrom
```

**描述：**

色键模式


### colorRopType

  
```
RopType GfxOpt::colorRopType
```

**描述：**

颜色的Rop类型


### Commit

  
```
int32_t(* DeviceFuncs::Commit) (uint32_t devId, int32_t *fence)
```

**描述：**

提交合成送显请求。

图形服务通过该接口向接口实现层提交合成送显请求，如果有硬件合成层，接口实现层需要在这时进行合成，并且把最终合成的数据送到硬件进行显示。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| fences | 输出参数，fence首地址，指向fence数组的首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### CreateVirtualDisplay

  
```
int32_t(* DeviceFuncs::CreateVirtualDisplay) (uint32_t width, uint32_t height, int32_t *format, uint32_t *devId)
```

**描述：**

创建虚拟显示设备。

该接口用于创建一个虚拟显示设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| width | 输入参数，指定显示设备的像素宽度。 | 
| height | 输入参数，指定显示设备的像素高度。 | 
| format | 输出参数，指定显示设备的像素格式。&nbsp;详情参考[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414172.xml#xref738382043153217,link:zh-cn_topic_0000001347985105.xml#ga60883d4958a60b91661e97027a85072a](zh-cn_topic_0000001347985105.xml#ga60883d4958a60b91661e97027a85072a)，接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 
| devId | 输出参数，用于接口层返回创建的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### CreateWriteBack

  
```
int32_t(* DeviceFuncs::CreateWriteBack) (uint32_t *devId, uint32_t width, uint32_t height, int32_t *format)
```

**描述：**

对指定显示设备创建回写点。

该接口用来对指定的设备创建一个回写点，如果回写点数量超过了限制，接口实现层将会返回失败。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID，接口实现层在创建完回写点后将回写点设备ID存放在该参数中返回给图形服务。 | 
| width | 输入参数，回写像素宽度。 | 
| height | 输入参数，回写像素高度。 | 
| format | 输入参数，回写点数据格式，详情参考[PixelFormat](#pixelformat)，接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### data

  
```
BufferData LayerBuffer::data
```

**描述：**

图层buffer数据


### DestroyVirtualDisplay

  
```
int32_t(* DeviceFuncs::DestroyVirtualDisplay) (uint32_t devId)
```

**描述：**

销毁虚拟显示设备。

该接口用于销毁指定的虚拟显示设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### DestroyWriteBack

  
```
int32_t(* DeviceFuncs::DestroyWriteBack) (uint32_t devId)
```

**描述：**

销毁指定显示设备的回写点。

该接口用來销毁指定的回写点。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### enableRop

  
```
bool GfxOpt::enableRop
```

**描述：**

Rop功能使能位


### enableScale

  
```
bool GfxOpt::enableScale
```

**描述：**

缩放功能使能位


### enColorFmt

  
```
PixelFormat ISurface::enColorFmt
```

**描述：**

图像格式


### enGlobalAlpha [1/2]

  
```
bool LayerAlpha::enGlobalAlpha
```

**描述：**

全局alpha使能标志


### enGlobalAlpha [2/2]

  
```
bool GfxOpt::enGlobalAlpha
```

**描述：**

全局alpha使能位


### enPixelAlpha [1/2]

  
```
bool LayerAlpha::enPixelAlpha
```

**描述：**

像素alpha使能标志


### enPixelAlpha [2/2]

  
```
bool GfxOpt::enPixelAlpha
```

**描述：**

像素alpha使能位


### expectedSize

  
```
uint32_t AllocInfo::expectedSize
```

**描述：**

申请内存大小


### fd

  
```
int32_t __attribute__::fd
```

**描述：**

句柄 fd，-1代表不支持。


### fenceId

  
```
int32_t LayerBuffer::fenceId
```

**描述：**

buffer 的fence号


### format [1/2]

  
```
PixelFormat AllocInfo::format
```

**描述：**

申请内存格式


### format [2/2]

  
```
PixelFormat VerifyAllocInfo::format
```

**描述：**

分配内存的像素格式


### formatCount

  
```
uint32_t HDRCapability::formatCount
```

**描述：**

支持的HDR格式的数量


### formats

  
```
HDRFormat* HDRCapability::formats
```

**描述：**

支持的HDR格式的数组首地址


### freshRate

  
```
uint32_t DisplayModeInfo::freshRate
```

**描述：**

刷新速率


### gAlpha

  
```
uint8_t LayerAlpha::gAlpha
```

**描述：**

全局alpha值，取值范围：[0, 255]


### GetDisplayBacklight

  
```
int32_t(* DeviceFuncs::GetDisplayBacklight) (uint32_t devId, uint32_t *level)
```

**描述：**

获取显示设备当前的背光值。

图形服务可以通过该接口获取设置显示设备的背光值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| level | 输出参数，保存对应设备的背光值，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayCapability

  
```
int32_t(* DeviceFuncs::GetDisplayCapability) (uint32_t devId, DisplayCapability *info)
```

**描述：**

获取显示设备能力集。

图形服务可以通过该接口获取显示设备具备哪些显示能力。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| info | 输出参数，设备支持的能力级信息，详情参考&nbsp;{\@DisplayCapability}。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayColorGamut

  
```
int32_t(* DeviceFuncs::GetDisplayColorGamut) (uint32_t devId, ColorGamut *gamut)
```

**描述：**

获取显示设备当前的色域模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamut | 输出参数，保存对应设备的色域模式，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayCompChange

  
```
int32_t(* DeviceFuncs::GetDisplayCompChange) (uint32_t devId, uint32_t *num, uint32_t *Layers, int32_t *type)
```

**描述：**

获取显示设备合成类型有变化的layer。

在合成准备阶段，显示设备会根据设备的合成能力修改图层的合成类型，该接口会返回哪些图层合成类型发生了变化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，表示合成类型发生了变化的图层数量。 | 
| Layers | 输出参数，指向图层数组首地址。 | 
| type | 输出参数，指向合成类型数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayGamutMap

  
```
int32_t(* DeviceFuncs::GetDisplayGamutMap) (uint32_t devId, GamutMap *gamutMap)
```

**描述：**

获取显示设备当前的色域映射模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamutMap | 输出参数，保存对应设备的色域映射模式，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayMode

  
```
int32_t(* DeviceFuncs::GetDisplayMode) (uint32_t devId, uint32_t *modeId)
```

**描述：**

获取显示设备当前的显示模式。

图形服务可以通过该接口获取显示设备当前的显示模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| modeId | 输出参数，存放当前设备的显示模式ID，&nbsp;由接口实现层进行数据的写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayPowerStatus

  
```
int32_t(* DeviceFuncs::GetDisplayPowerStatus) (uint32_t devId, DispPowerStatus *status)
```

**描述：**

获取显示设备当前的电源状态。

图形服务可以通过该接口获设置显示设备的电源状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| status | 输出参数，保存对应设备的电源状态，由接口实现层进行状态的写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayProperty

  
```
int32_t(* DeviceFuncs::GetDisplayProperty) (uint32_t devId, uint32_t id, uint64_t *value)
```

**描述：**

获得显示设备属性值。

图形服务可以通过该接口获取显示设备具体的属性值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| id | 输入参数，由接口GetDisplayCapability返回属性ID。 | 
| level | 输出参数，属性ID对应的属性值，由接口实现层写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayReleaseFence

  
```
int32_t(* DeviceFuncs::GetDisplayReleaseFence) (uint32_t devId, uint32_t *num, uint32_t *layers, int32_t *fences)
```

**描述：**

获取显示图层fence。

图形服务在调用接口Commit后，需要通过该接口获取图层的fence信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，图层个数。 | 
| layers | 输出参数，图层首地址，指向图层数组的首地址。 | 
| fences | 输出参数，fence首地址，指向fence数组的首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplaySupportedColorGamuts

  
```
int32_t(* DeviceFuncs::GetDisplaySupportedColorGamuts) (uint32_t devId, uint32_t *num, ColorGamut *gamuts)
```

**描述：**

获取显示设备支持的色域信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，设备支持的色域数组个数。 | 
| gamuts | 输出参数，色域首地址，指向色域数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplaySupportedModes

  
```
int32_t(* DeviceFuncs::GetDisplaySupportedModes) (uint32_t devId, uint32_t *num, DisplayModeInfo *modes)
```

**描述：**

获取显示设备支持的显示模式信息。

图形服务可以通过该接口获取到显示设备支持哪些显示模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，设备支持的模式数量。 | 
| modes | 输出参数，设备支持的所有模式信息，包括所有能支持的分辨率和刷新率，每一个模式实现层都有一个Id与之对应，在获取当前模式&nbsp;和设置当前模式时都会使用到，详情参考&nbsp;{\@DisplayModeInfo}。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetHDRCapabilityInfos

  
```
int32_t(* DeviceFuncs::GetHDRCapabilityInfos) (uint32_t devId, HDRCapability *info)
```

**描述：**

获取显示设备支持的HDR属性信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| info | 输出参数，保存对应设备的HDR属性信息，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetSupportedMetadataKey

  
```
int32_t(* DeviceFuncs::GetSupportedMetadataKey) (uint32_t devId, uint32_t *num, HDRMetadataKey *keys)
```

**描述：**

获取显示设备支持的 HDRMetadataKey。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，设备支持的HDRMetadataKey数组个数。 | 
| keys | 输出参数，HDRMetadataKey首地址，指向HDRMetadataKey数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetWriteBackFrame

  
```
int32_t(* DeviceFuncs::GetWriteBackFrame) (uint32_t devId, BufferHandle *buffer, int32_t *fence)
```

**描述：**

获取显示设备的回写帧。

该接口用来获取devId指定的回写点数据，接口实现层将显示设备回写点的数据写入到设置的缓存中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| buffer | 输出参数，回写点数据缓存。 | 
| fence | 输出参数，同步栅栏，图形服务在调用该接口时，需要将Buffer的release&nbsp;fence&nbsp;传入，标记该缓存是否可以被写入，接口实现层在接口返回前需要将buffer的acquirce&nbsp;fence&nbsp;写入回传给图形服务，用来标记回写数据是否已经写入缓存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### globalAlpha

  
```
uint32_t GfxOpt::globalAlpha
```

**描述：**

全局alpha的值


### h

  
```
int32_t IRect::h
```

**描述：**

矩形框高度


### hdl

  
```
BufferHandle* LayerBuffer::hdl
```

**描述：**

图层buffer句柄


### height [1/7]

  
```
uint32_t DisplayInfo::height
```

**描述：**

显示屏高度


### height [2/7]

  
```
int32_t LayerInfo::height
```

**描述：**

图层高度


### height [3/7]

  
```
int32_t LayerBuffer::height
```

**描述：**

buffer高度


### height [4/7]

  
```
int32_t ISurface::height
```

**描述：**

图像高度


### height [5/7]

  
```
int32_t DisplayModeInfo::height
```

**描述：**

像素高度


### height [6/7]

  
```
uint32_t AllocInfo::height
```

**描述：**

申请内存高度


### height [7/7]

  
```
uint32_t VerifyAllocInfo::height
```

**描述：**

分配内存的高度


### id

  
```
int32_t DisplayModeInfo::id
```

**描述：**

模式ID


### InvokeDisplayCmd

  
```
int32_t(* DeviceFuncs::InvokeDisplayCmd) (uint32_t devId,...)
```

**描述：**

调用显示设备命令。

该接口用于图形服务和接口实现层之间的接口扩展，如果由临时接口新增可以通过该接口进行扩展，不用增加新的接口定义。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### key

  
```
HDRMetadataKey HDRMetaData::key
```

**描述：**

HDR元数据关键字


### maxAverageLum

  
```
float HDRCapability::maxAverageLum
```

**描述：**

最大的平均光亮度luminance值


### maxLum

  
```
float HDRCapability::maxLum
```

**描述：**

最大的光亮度luminance值


### minLum

  
```
float HDRCapability::minLum
```

**描述：**

最小的光亮度luminance值


### mirrorType

  
```
MirrorType GfxOpt::mirrorType
```

**描述：**

镜像类型


### name [1/2]

  
```
char PropertyObject::名称[PROPERTY_NAME_LEN]
```

**描述：**

属性名称


### name [2/2]

  
```
char DisplayCapability::名称[PROPERTY_NAME_LEN]
```

**描述：**

显示设备名称


### phyAddr [1/2]

  
```
uint64_t BufferData::phyAddr
```

**描述：**

物理内存地址


### phyAddr [2/2]

  
```
uint64_t ISurface::phyAddr
```

**描述：**

图像首地址


### phyHeight

  
```
uint32_t DisplayCapability::phyHeight
```

**描述：**

物理高度


### phyWidth

  
```
uint32_t DisplayCapability::phyWidth
```

**描述：**

物理宽度


### pitch

  
```
int32_t LayerBuffer::pitch
```

**描述：**

一行数据所占字节数


### pixFormat [1/2]

  
```
PixelFormat LayerInfo::pixFormat
```

**描述：**

图层像素格式


### pixFormat [2/2]

  
```
PixelFormat LayerBuffer::pixFormat
```

**描述：**

buffer像素格式


### PrepareDisplayLayers

  
```
int32_t(* DeviceFuncs::PrepareDisplayLayers) (uint32_t devId, bool *needFlushFb)
```

**描述：**

显示设备合成前准备。

图形服务在合成前需要通过该接口通知显示设备进行合成前的准备工作。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| needFlushFb | 输出参数，接口实现层通过该参数指示图形服务在commit前是否需要通过SetDisplayClientBuffer重新设置显示帧存。&nbsp;true表示需要设置显示帧存，false表示不需要。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### propertyCount

  
```
uint32_t DisplayCapability::propertyCount
```

**描述：**

属性数组大小


### propId

  
```
uint32_t PropertyObject::propId
```

**描述：**

属性ID


### props

  
```
PropertyObject* DisplayCapability::props
```

**描述：**

属性数组


### r

  
```
int32_t ICircle::r
```

**描述：**

圆的半径


### rect

  
```
IRect Rectangle::rect
```

**描述：**

矩形区域


### RegDisplayRefreshCallback

  
```
int32_t(* DeviceFuncs::RegDisplayRefreshCallback) (uint32_t devId, RefreshCallback callback, void *data)
```

**描述：**

刷新请求回调。

注册刷新请求事件回调，当实现层有刷新需求时，实现层通过回调注册的接口通知图形服务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| callback | 输入参数，刷新请求事件回调实例，当有接口实现层有刷新请求时，需要通过该实例通知图形服务。 | 
| data | 输出参数，图形服务携带的私有数据，在事件回调接口中需要返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### RegDisplayVBlankCallback

  
```
int32_t(* DeviceFuncs::RegDisplayVBlankCallback) (uint32_t devId, VBlankCallback callback, void *data)
```

**描述：**

注册VBlank事件回调。

注册VBlank事件回调，当有VBlank事件发生时接口实现层需要回调注册的接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| callback | 输入参数，VBlank事件回调实例，当有VBlank事件发生时并且DisplayVsync处于Enable状态，接口实现层需要通过该实例通知图形服务。 | 
| data | 输出参数，图形服务携带的私有数据，在事件回调接口中需要返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### RegHotPlugCallback

  
```
int32_t(* DeviceFuncs::RegHotPlugCallback) ((HotPlugCallback callback, void *data)
```

**描述：**

注册热插拔事件回调。

注册热插拔事件回调，当有热插拔事件发生时接口实现层需要回调注册的接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callback | 输入参数，热插拔事件回调实例，当有热插拔事件发生时，接口实现层需要通过该实例通知图形服务。 | 
| data | 输出参数，图形服务携带的私有数据，在事件回调接口中需要返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### reserve

  
```
int32_t __attribute__::reserve[0]
```

**描述：**

reserve数组


### reserveInts

  
```
uint32_t __attribute__::reserveInts
```

**描述：**

reserve数组的个数


### rotAngle

  
```
int32_t DisplayInfo::rotAngle
```

**描述：**

显示屏旋转角度


### rotateType

  
```
TransformType GfxOpt::rotateType
```

**描述：**

旋转类型


### SetDisplayBacklight

  
```
int32_t(* DeviceFuncs::SetDisplayBacklight) (uint32_t devId, uint32_t level)
```

**描述：**

设置显示设备当前的背光值。

图形服务可以通过该接口获设置显示设备的背光值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| level | 输入参数，表示需要设置的背光值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientBuffer

  
```
int32_t(* DeviceFuncs::SetDisplayClientBuffer) (uint32_t devId, const BufferHandle *buffer, int32_t fence)
```

**描述：**

设置显示设备的显示缓存。

图形服务可以通过该接口将显示缓存设置给显示设备，显示设备硬件合成结果将会存放在该显示缓存中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| buffer | 输入参数，显示缓存。 | 
| fence | 输入参数，同步栅栏，标识显示缓存是否可以访问，有图形服务创建和释放，接口实现层需要等待同步栅栏发送信号后才能使用显示缓存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientCrop

  
```
int32_t(* DeviceFuncs::SetDisplayClientCrop) (uint32_t devId, IRect *rect)
```

**描述：**

设置显示设备的裁剪区域。

图形服务可以通过该接口设置显示设备的ClientBuffer的裁剪区域，裁剪区域不能超过ClientBuffer的大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| rect | 输入参数，ClientBuffer的裁剪区域。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientDamage

  
```
int32_t(* DeviceFuncs::SetDisplayClientDamage) (uint32_t devId, uint32_t num, IRect *rect)
```

**描述：**

设置显示设备的显示脏区。

图形服务可以通过该接口设置显示设备脏区，接口实现层可以根据该区域进行区域刷新，脏区是由多个矩形区域组合起来的。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输入参数，矩形个数。 | 
| rect | 输入参数，区域矩形指针，指向矩形数组的首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientDestRect

  
```
int32_t(* DeviceFuncs::SetDisplayClientDestRect) (uint32_t devId, IRect *rect)
```

**描述：**

设置显示设备的显示区域。

图形服务可以通过该接口设置显示设备的显示区域。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| rect | 输入参数，显示区域。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayColorGamut

  
```
int32_t(* DeviceFuncs::SetDisplayColorGamut) (uint32_t devId, ColorGamut gamut)
```

**描述：**

设置显示设备当前的色域模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamut | 输入参数，表示需要设置的色域模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayColorTransform

  
```
int32_t(* DeviceFuncs::SetDisplayColorTransform) (uint32_t devId, const float *matrix)
```

**描述：**

设置显示设备当前的4x4的颜色转换矩阵。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| matrix | 输入参数，表示需要设置的颜色转换模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayGamutMap

  
```
int32_t(* DeviceFuncs::SetDisplayGamutMap) (uint32_t devId, GamutMap gamutMap)
```

**描述：**

设置显示设备当前的色域映射模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamutMap | 输入参数，表示需要设置的色域映射模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayMode

  
```
int32_t(* DeviceFuncs::SetDisplayMode) (uint32_t devId, uint32_t modeId)
```

**描述：**

设置显示设备的显示模式。

图形服务可以通过该接口获设置显示设备的显示模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| modeId | 输入参数，指明需要设置的模式ID，接口实现层将设备切换到该参数对应的显示模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayPowerStatus

  
```
int32_t(* DeviceFuncs::SetDisplayPowerStatus) (uint32_t devId, DispPowerStatus status)
```

**描述：**

设置显示设备当前的电源状态。

图形服务可以通过该接口获设置显示设备的电源状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| status | 输入参数，表示需要设置的电源状态。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayProperty

  
```
int32_t(* DeviceFuncs::SetDisplayProperty) (uint32_t devId, uint32_t id, uint64_t value)
```

**描述：**

设置显示设备属性值。

图形服务可以通过该接口设置显示设备具体的属性值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| id | 输入参数，由接口GetDisplayCapability返回属性ID。 | 
| value | 输入参数，需要设置的属性值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayVsyncEnabled

  
```
int32_t(* DeviceFuncs::SetDisplayVsyncEnabled) (uint32_t devId, bool enabled)
```

**描述：**

使能垂直同步信号。

图形服务可以通过该接口使能或取消垂直同步信号，当有垂直同步信号产生时，接口实现层需要回调图形服务通过RegDisplayVBlankCallback注册的 VBlankCallback 回调。 图形服务在需要刷新显示时需要使能垂直同步信号，在收到VBlankCallback事件回调时再进行合成送显，不需要刷新显示时需要取消垂直同步信号。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| enabled | 输入参数，使能状态，true表示能，false表示不能。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetVirtualDisplayBuffer

  
```
int32_t(* DeviceFuncs::SetVirtualDisplayBuffer) (uint32_t devId, BufferHandle *buffer, int32_t fence)
```

**描述：**

设置虚拟屏的输出缓存。

该接口用于设置虚拟屏输出缓存，接口实现层需要将虚拟屏的输出放入到该缓存中，接口实现层需要等待同步栅栏发送信号后才能使用缓存。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| buffer | 输出参数，输出缓存。 | 
| fence | 输出参数，同步栅栏。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### stride

  
```
int32_t ISurface::stride
```

**描述：**

图像跨度


### supportLayers

  
```
uint32_t DisplayCapability::supportLayers
```

**描述：**

支持的图层数


### supportWriteBack

  
```
bool DisplayCapability::supportWriteBack
```

**描述：**

是否支持回写


### time

  
```
int64_t PresentTimestamp::time
```

**描述：**

类型对应的值


### type [1/3]

  
```
LayerType LayerInfo::type
```

**描述：**

图层类型，包括图形层、视频层和媒体播放模式


### type [2/3]

  
```
InterfaceType DisplayCapability::type
```

**描述：**

显示屏接口类型


### type [3/3]

  
```
PresentTimestampType PresentTimestamp::type
```

**描述：**

上屏时间戳类型


### uOffset

  
```
size_t __attribute__::uOffset
```

**描述：**

U的偏移量


### usage [1/2]

  
```
uint64_t AllocInfo::usage
```

**描述：**

申请内存的使用场景


### usage [2/2]

  
```
uint64_t VerifyAllocInfo::usage
```

**描述：**

内存的用处


### uvStep

  
```
size_t __attribute__::uvStep
```

**描述：**

UV的step信息


### uvStride

  
```
size_t __attribute__::uvStride
```

**描述：**

UV的stride信息


### value [1/2]

  
```
uint64_t PropertyObject::value
```

**描述：**

属性值


### value [2/2]

  
```
float HDRMetaData::value
```

**描述：**

关键字对应的值


### virAddr

  
```
void* BufferData::virAddr
```

**描述：**

虚拟内存地址


### virtualDispCount

  
```
uint32_t DisplayCapability::virtualDispCount
```

**描述：**

支持的虚拟屏数


### vOffset

  
```
size_t __attribute__::vOffset
```

**描述：**

V的偏移量


### w

  
```
int32_t IRect::w
```

**描述：**

矩形框宽度


### width [1/7]

  
```
uint32_t DisplayInfo::width
```

**描述：**

显示屏宽度


### width [2/7]

  
```
int32_t LayerInfo::width
```

**描述：**

图层宽度


### width [3/7]

  
```
int32_t LayerBuffer::width
```

**描述：**

buffer宽度


### width [4/7]

  
```
int32_t ISurface::width
```

**描述：**

图像宽度


### width [5/7]

  
```
int32_t DisplayModeInfo::width
```

**描述：**

像素宽度


### width [6/7]

  
```
uint32_t AllocInfo::width
```

**描述：**

申请内存宽度


### width [7/7]

  
```
uint32_t VerifyAllocInfo::width
```

**描述：**

分配内存的宽度


### x [1/2]

  
```
int32_t IRect::x
```

**描述：**

矩形框起始x坐标


### x [2/2]

  
```
int32_t ICircle::x
```

**描述：**

圆心x坐标


### x0

  
```
int32_t ILine::x0
```

**描述：**

线条起点的x坐标


### x1

  
```
int32_t ILine::x1
```

**描述：**

线条终点的x坐标


### y [1/2]

  
```
int32_t IRect::y
```

**描述：**

矩形框起始y坐标


### y [2/2]

  
```
int32_t ICircle::y
```

**描述：**

圆心y坐标r


### y0

  
```
int32_t ILine::y0
```

**描述：**

线条起点的y坐标


### y1

  
```
int32_t ILine::y1
```

**描述：**

线条终点的y坐标


### yOffset

  
```
size_t __attribute__::yOffset
```

**描述：**

Y的偏移量


### yStride

  
```
size_t __attribute__::yStride
```

**描述：**

Y的stride信息
