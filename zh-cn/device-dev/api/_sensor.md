# Sensor


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [sensor_if.h](sensor__if_8h.md) | Sensor模块对外通用的接口声明文件，提供获取传感器设备信息、订阅/去订阅传感器数据、&nbsp;使能/去使能传感器、设置传感器模式、设置传感器精度，量程等可选配置接口定义。 | 
| [sensor_type.h](sensor__type_8h.md) | 定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [SensorInterface](_sensor_interface.md) | 提供sensor设备基本控制操作接口。&nbsp;[更多...](_sensor_interface.md) | 
| [SensorInformation](_sensor_information.md) | 定义传感器基本信息。&nbsp;[更多...](_sensor_information.md) | 
| [SensorEvents](_sensor_events.md) | 上报传感器数据结构。&nbsp;[更多...](_sensor_events.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [SENSOR_NAME_MAX_LEN](#sensornamemaxlen)&nbsp;&nbsp;&nbsp;32 | Sensor名称的最大长度。 | 
| [SENSOR_VERSION_MAX_LEN](#sensorversionmaxlen)&nbsp;&nbsp;&nbsp;16 | Sensor版本号的最大长度。 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([RecordDataCallback](#recorddatacallback))&nbsp;(const&nbsp;struct&nbsp;[SensorEvents](_sensor_events.md)&nbsp;\*) | 传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时，&nbsp;需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。&nbsp;[更多...](#recorddatacallback) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [SensorStatus](#sensorstatus)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1744368128083931,link:zh-cn_topic_0000001348293929.xml#ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827](#ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1335251836083931,link:zh-cn_topic_0000001348293929.xml#ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71](#ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1233191896083931,link:zh-cn_topic_0000001348293929.xml#ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5](#ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5)&nbsp;=&nbsp;-2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1060174146083931,link:zh-cn_topic_0000001348293929.xml#ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7](#ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7)&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1078641707083931,link:zh-cn_topic_0000001348293929.xml#ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c](#ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c)&nbsp;=&nbsp;-4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref199916655214,link:#p431372085818](#p431372085818)&nbsp;=&nbsp;-5&nbsp;} | 定义传感器模块返回值类型。&nbsp;[更多...](#sensorstatus) | 
| [SensorTypeTag](#sensortypetag)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref276196875083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee](#ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1251682907083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c](#ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref952930154083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28](#ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref472145700083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e](#ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref760459074083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607](#ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref982677450083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325](#ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref14169199083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8](#ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8)&nbsp;=&nbsp;6,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref154702882083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b](#ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b)&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1984772313083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8](#ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8)&nbsp;=&nbsp;8,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1908999646083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6](#ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref2060890795083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665](#ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665)&nbsp;=&nbsp;10,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1014929795083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe](#ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe)&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1246330281083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c](#ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c)&nbsp;=&nbsp;12,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref927809977083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5](#ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5)&nbsp;=&nbsp;13,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref80376381083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943](#ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943)&nbsp;=&nbsp;128,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1670563828083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e](#ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e)&nbsp;=&nbsp;160,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref925483407083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53](#ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53)&nbsp;=&nbsp;255,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1588739202083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596](#ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596)&nbsp;=&nbsp;256,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1037316072083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e](#ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e)&nbsp;=&nbsp;257,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref504051126083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384](#ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384)&nbsp;=&nbsp;258,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1823576696083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b](#ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b)&nbsp;=&nbsp;259,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref542704221083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a](#ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a)&nbsp;=&nbsp;260,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1403111115083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af](#ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af)&nbsp;=&nbsp;261,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1386678478083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b](#ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b)&nbsp;=&nbsp;262,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref219154468083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638](#ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638)&nbsp;=&nbsp;263,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1498541716083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80](#ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80)&nbsp;=&nbsp;264,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref293505469083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58](#ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58)&nbsp;=&nbsp;265,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1947880315083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8](#ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8)&nbsp;=&nbsp;266,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref717567083083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0](#ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0)&nbsp;=&nbsp;277,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref494571919083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91](#ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91)&nbsp;=&nbsp;278,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1305798719083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac](#ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac)&nbsp;=&nbsp;279,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref592082955083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718](#ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718)&nbsp;=&nbsp;280,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1215860865083931,link:zh-cn_topic_0000001348293929.xml#ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129](#ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129)&nbsp;=&nbsp;281,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref4210134214532,link:#p876144152111](#p876144152111)&nbsp;} | 定义传感器类型标识。&nbsp;[更多...](#sensortypetag) | 
| [SensorAccuracyType](#sensoraccuracytype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref885806585083931,link:zh-cn_topic_0000001348293929.xml#gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7](#gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref687798640083931,link:zh-cn_topic_0000001348293929.xml#gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed](#gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1802973734083931,link:zh-cn_topic_0000001348293929.xml#gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd](#gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1858007843083931,link:zh-cn_topic_0000001348293929.xml#gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574](#gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref91811716205513,link:#p945419536162](#p945419536162)} | 传感器的精度类型。&nbsp;[更多...](#sensoraccuracytype) | 
| [SensorRangeType](#sensorrangetype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref948776572083931,link:zh-cn_topic_0000001348293929.xml#gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986](#gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref399481110083931,link:zh-cn_topic_0000001348293929.xml#gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1](#gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref811186551083931,link:zh-cn_topic_0000001348293929.xml#gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e](#gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref66771827105514,link:#p165901247205](#p165901247205)&nbsp;} | 传感器的量程级别。&nbsp;[更多...](#sensorrangetype) | 
| [SensorModeType](#sensormodetype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref357904618083931,link:zh-cn_topic_0000001348293929.xml#gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d](#gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref858811297083931,link:zh-cn_topic_0000001348293929.xml#gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d](#gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1003544038083931,link:zh-cn_topic_0000001348293929.xml#gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322](#gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1343791083931,link:zh-cn_topic_0000001348293929.xml#gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee](#gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref751754462083931,link:zh-cn_topic_0000001348293929.xml#gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f](#gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref14351915611,link:#p4932820101810](#p4932820101810)&nbsp;} | 传感器的工作模式。&nbsp;[更多...](#sensormodetype) | 
| [SensorGroupType](#sensorgrouptype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1746000080083931,link:zh-cn_topic_0000001348293929.xml#gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64](#gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref2030071987083931,link:zh-cn_topic_0000001348293929.xml#gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47](#gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293929.xml#xref1096312121083931,link:zh-cn_topic_0000001348293929.xml#gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94](#gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94)&nbsp;} | 枚举传感器的硬件服务组。&nbsp;[更多...](#sensorgrouptype) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [NewSensorInterfaceInstance](#newsensorinterfaceinstance)&nbsp;(void) | 创建传感器接口实例。&nbsp;[更多...](#newsensorinterfaceinstance) | 
| [FreeSensorInterfaceInstance](#freesensorinterfaceinstance)&nbsp;(void) | 释放传感器接口实例。&nbsp;[更多...](#freesensorinterfaceinstance) | 


## **详细描述**

传感器设备驱动对传感器服务提供通用的接口能力。

模块提供传感器服务对传感器驱动访问统一接口，服务获取驱动对象或者代理后， 通过其提供的各类方法，以传感器id区分访问不同类型传感器设备，实现获取传感器设备信息、订阅/去订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置等。

**Since：**

2.2

**Version：**

1.0


## **宏定义说明**


### SENSOR_NAME_MAX_LEN

  
```
#define SENSOR_NAME_MAX_LEN   32
```

**描述：**

Sensor名称的最大长度。


### SENSOR_VERSION_MAX_LEN

  
```
#define SENSOR_VERSION_MAX_LEN  16
```

**描述：**

Sensor版本号的最大长度。


## **类型定义说明**


### RecordDataCallback

  
```
typedef int32_t(* RecordDataCallback) (const struct SensorEvents *)
```

**描述：**

传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时， 需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。


## **枚举类型说明**


### SensorAccuracyType

  
```
enum SensorAccuracyType
```

**描述：**

传感器的精度类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_NO_ACCURACY | 无精度类型。 | 
| SENSOR_LOW_ACCURACY | 低精度类型。 | 
| SENSOR_MEDIUM_ACCURACY | 中等精度类型。 | 
| SENSOR_HIGH_ACCURACY | 高精度类型。 | 
| SENSOR_MAX_ACCURACY | 最大精度类型。 | 


### SensorGroupType

  
```
enum SensorGroupType
```

**描述：**

枚举传感器的硬件服务组。

  | 枚举值 | 描述 | 
| -------- | -------- |
| TRADITIONAL_SENSOR_TYPE | 传统传感器类型，传感器ID枚举值范围为128-160。 | 
| MEDICAL_SENSOR_TYPE | 医疗传感器类型，传感器ID枚举值范围不在128-160之间。 | 
| SENSOR_GROUP_TYPE_MAX | 最大传感器类型。 | 


### SensorModeType

  
```
enum SensorModeType
```

**描述：**

传感器的工作模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_MODE_DEFAULT | 传感器默认工作模式状态。 | 
| SENSOR_MODE_REALTIME | 传感器实时工作模式状态，一组数据上报一次。 | 
| SENSOR_MODE_ON_CHANGE | 传感器实时工作模式状态，状态变更上报一次。 | 
| SENSOR_MODE_ONE_SHOT | 传感器实时工作模式状态，只上报一次。 | 
| SENSOR_MODE_FIFO_MODE | 传感器缓存工作模式状态，根据配置的缓存大小上报。 | 
| SENSOR_MODE_MAX | 传感器最大类型标识。 | 


### SensorRangeType

  
```
enum SensorRangeType
```

**描述：**

传感器的量程级别。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_RANGE_LEVEL1 | 量程级别1。 | 
| SENSOR_RANGE_LEVEL2 | 量程级别2。 | 
| SENSOR_RANGE_LEVEL3 | 量程级别3。 | 
| SENSOR_RANGE_LEVEL_MAX | 量程最大级别。 | 


### SensorStatus

  
```
enum SensorStatus
```

**描述：**

定义传感器模块返回值类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_SUCCESS | 传感器执行成功。 | 
| SENSOR_FAILURE | 传感器执行失败。 | 
| SENSOR_NOT_SUPPORT | 传感器不支持。 | 
| SENSOR_INVALID_PARAM | 传感器无效参数。 | 
| SENSOR_INVALID_SERVICE | 传感器无效服务。 | 
| SENSOR_NULL_PTR | 传感器空指针。 | 


### SensorTypeTag

  
```
enum SensorTypeTag
```

**描述：**

定义传感器类型标识。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_TYPE_NONE | 空传感器类型，用于测试。 | 
| SENSOR_TYPE_ACCELEROMETER | 加速度传感器。 | 
| SENSOR_TYPE_GYROSCOPE | 陀螺仪传感器。 | 
| SENSOR_TYPE_PHOTOPLETHYSMOGRAPH | 心率传感器。 | 
| SENSOR_TYPE_ELECTROCARDIOGRAPH | 心电传感器。 | 
| SENSOR_TYPE_AMBIENT_LIGHT | 环境光传感器。 | 
| SENSOR_TYPE_MAGNETIC_FIELD | 地磁传感器。 | 
| SENSOR_TYPE_CAPACITIVE | 电容传感器。 | 
| SENSOR_TYPE_BAROMETER | 气压计传感器。 | 
| SENSOR_TYPE_TEMPERATURE | 温度传感器。 | 
| SENSOR_TYPE_HALL | 霍尔传感器。 | 
| SENSOR_TYPE_GESTURE | 手势传感器。 | 
| SENSOR_TYPE_PROXIMITY | 接近光传感器。 | 
| SENSOR_TYPE_HUMIDITY | 湿度传感器。 | 
| SENSOR_TYPE_MEDICAL_BEGIN | 医疗传感器ID枚举值范围的开始。 | 
| SENSOR_TYPE_MEDICAL_END | 医疗传感器ID枚举值范围的结束。 | 
| SENSOR_TYPE_PHYSICAL_MAX | 物理传感器最大类型。 | 
| SENSOR_TYPE_ORIENTATION | 方向传感器。 | 
| SENSOR_TYPE_GRAVITY | 重力传感器。 | 
| SENSOR_TYPE_LINEAR_ACCELERATION | 线性加速度传感器。 | 
| SENSOR_TYPE_ROTATION_VECTOR | 旋转矢量传感器。 | 
| SENSOR_TYPE_AMBIENT_TEMPERATURE | 环境温度传感器 | 
| SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED | 未校准磁场传感器。 | 
| SENSOR_TYPE_GAME_ROTATION_VECTOR | 游戏旋转矢量传感器。 | 
| SENSOR_TYPE_GYROSCOPE_UNCALIBRATED | 未校准陀螺仪传感器。 | 
| SENSOR_TYPE_SIGNIFICANT_MOTION | 大幅度动作传感器。 | 
| SENSOR_TYPE_PEDOMETER_DETECTION | 计步器检测传感器。 | 
| SENSOR_TYPE_PEDOMETER | 计步器传感器。 | 
| SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR | 地磁旋转矢量传感器。 | 
| SENSOR_TYPE_HEART_RATE | 心率传感器。 | 
| SENSOR_TYPE_DEVICE_ORIENTATION | 设备方向传感器。 | 
| SENSOR_TYPE_WEAR_DETECTION | 佩戴检测传感器。 | 
| SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED | 未校准加速度传感器。 | 
| SENSOR_TYPE_MAX | 传感器类型最大个数标识。 | 


## **函数说明**


### FreeSensorInterfaceInstance()

  
```
int32_t FreeSensorInterfaceInstance (void )
```

**描述：**

释放传感器接口实例。

**返回：**

如果释放实例成功，则返回0。

如果释放实例失败，则返回负值。

**Since：**

2.2

**Version：**

1.0


### NewSensorInterfaceInstance()

  
```
const struct SensorInterface* NewSensorInterfaceInstance (void )
```

**描述：**

创建传感器接口实例。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorId | 表示传感器ID。有关详细信息，详见[SensorTypeTag](#sensortypetag)。 | 
| cb | 表示要注册的回调函数。有关详细信息，详见[RecordDataCallback](#recorddatacallback)。 | 

**返回：**

如果创建实例成功，则返回非零值。

如果创建实例失败，则返回负值。

**Since：**

2.2

**Version：**

1.0
