# sensor_type.h


## **概述**

**所属模块:**

[Sensor](_sensor.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [SensorInformation](_sensor_information.md) | 定义传感器基本信息。&nbsp;[更多...](_sensor_information.md) | 
| [SensorEvents](_sensor_events.md) | 上报传感器数据结构。&nbsp;[更多...](_sensor_events.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [SENSOR_NAME_MAX_LEN](_sensor.md#sensornamemaxlen)&nbsp;&nbsp;&nbsp;32 | Sensor名称的最大长度 | 
| [SENSOR_VERSION_MAX_LEN](_sensor.md#sensorversionmaxlen)&nbsp;&nbsp;&nbsp;16 | Sensor版本号的最大长度 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([RecordDataCallback](_sensor.md#recorddatacallback))&nbsp;(const&nbsp;struct&nbsp;[SensorEvents](_sensor_events.md)&nbsp;\*) | 传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时，&nbsp;需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。&nbsp;[更多...](_sensor.md#recorddatacallback) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [SensorStatus](_sensor.md#sensorstatus)&nbsp;{&nbsp;&nbsp;&nbsp;[SENSOR_SUCCESS](_sensor.md#ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827)&nbsp;=&nbsp;0,&nbsp;[SENSOR_FAILURE](_sensor.md#ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71)&nbsp;=&nbsp;-1,&nbsp;[SENSOR_NOT_SUPPORT](_sensor.md#ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5)&nbsp;=&nbsp;-2,&nbsp;[SENSOR_INVALID_PARAM](_sensor.md#ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7)&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;[SENSOR_INVALID_SERVICE](_sensor.md#ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c)&nbsp;=&nbsp;-4,&nbsp;[SENSOR_NULL_PTR](_sensor.md#p431372085818)&nbsp;=&nbsp;-5&nbsp;} | 定义传感器模块返回值类型。&nbsp;[更多...](_sensor.md#sensorstatus) | 
| [SensorTypeTag](_sensor.md#sensortypetag)&nbsp;{&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_NONE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee)&nbsp;=&nbsp;0,&nbsp;[SENSOR_TYPE_ACCELEROMETER](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c)&nbsp;=&nbsp;1,&nbsp;[SENSOR_TYPE_GYROSCOPE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28)&nbsp;=&nbsp;2,&nbsp;[SENSOR_TYPE_PHOTOPLETHYSMOGRAPH](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_ELECTROCARDIOGRAPH](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607)&nbsp;=&nbsp;4,&nbsp;[SENSOR_TYPE_AMBIENT_LIGHT](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325)&nbsp;=&nbsp;5,&nbsp;[SENSOR_TYPE_MAGNETIC_FIELD](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8)&nbsp;=&nbsp;6,&nbsp;[SENSOR_TYPE_CAPACITIVE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b)&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_BAROMETER](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8)&nbsp;=&nbsp;8,&nbsp;[SENSOR_TYPE_TEMPERATURE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6)&nbsp;=&nbsp;9,&nbsp;[SENSOR_TYPE_HALL](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665)&nbsp;=&nbsp;10,&nbsp;[SENSOR_TYPE_GESTURE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe)&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_PROXIMITY](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c)&nbsp;=&nbsp;12,&nbsp;[SENSOR_TYPE_HUMIDITY](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5)&nbsp;=&nbsp;13,&nbsp;[SENSOR_TYPE_MEDICAL_BEGIN](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943)&nbsp;=&nbsp;128,&nbsp;[SENSOR_TYPE_MEDICAL_END](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e)&nbsp;=&nbsp;160,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_PHYSICAL_MAX](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53)&nbsp;=&nbsp;255,&nbsp;[SENSOR_TYPE_ORIENTATION](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596)&nbsp;=&nbsp;256,&nbsp;[SENSOR_TYPE_GRAVITY](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e)&nbsp;=&nbsp;257,&nbsp;[SENSOR_TYPE_LINEAR_ACCELERATION](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384)&nbsp;=&nbsp;258,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_ROTATION_VECTOR](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b)&nbsp;=&nbsp;259,&nbsp;[SENSOR_TYPE_AMBIENT_TEMPERATURE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a)&nbsp;=&nbsp;260,&nbsp;[SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af)&nbsp;=&nbsp;261,&nbsp;[SENSOR_TYPE_GAME_ROTATION_VECTOR](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b)&nbsp;=&nbsp;262,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_GYROSCOPE_UNCALIBRATED](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638)&nbsp;=&nbsp;263,&nbsp;[SENSOR_TYPE_SIGNIFICANT_MOTION](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80)&nbsp;=&nbsp;264,&nbsp;[SENSOR_TYPE_PEDOMETER_DETECTION](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58)&nbsp;=&nbsp;265,&nbsp;[SENSOR_TYPE_PEDOMETER](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8)&nbsp;=&nbsp;266,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0)&nbsp;=&nbsp;277,&nbsp;[SENSOR_TYPE_HEART_RATE](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91)&nbsp;=&nbsp;278,&nbsp;[SENSOR_TYPE_DEVICE_ORIENTATION](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac)&nbsp;=&nbsp;279,&nbsp;[SENSOR_TYPE_WEAR_DETECTION](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718)&nbsp;=&nbsp;280,&nbsp;&nbsp;&nbsp;[SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED](_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129)&nbsp;=&nbsp;281,&nbsp;[SENSOR_TYPE_MAX](_sensor.md#p876144152111)&nbsp;} | 定义传感器类型标识。&nbsp;[更多...](_sensor.md#sensortypetag) | 
| [SensorAccuracyType](_sensor.md#sensoraccuracytype)&nbsp;{&nbsp;&nbsp;&nbsp;[SENSOR_NO_ACCURACY](_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7)&nbsp;=&nbsp;0,&nbsp;[SENSOR_LOW_ACCURACY](_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed)&nbsp;=&nbsp;1,&nbsp;[SENSOR_MEDIUM_ACCURACY](_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd)&nbsp;=&nbsp;2,&nbsp;[SENSOR_HIGH_ACCURACY](_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[SENSOR_MAX_ACCURACY](_sensor.md#p945419536162)&nbsp;} | 传感器的精度类型。&nbsp;[更多...](_sensor.md#sensoraccuracytype) | 
| [SensorRangeType](_sensor.md#sensorrangetype)&nbsp;{&nbsp;[SENSOR_RANGE_LEVEL1](_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986)&nbsp;=&nbsp;0,&nbsp;[SENSOR_RANGE_LEVEL2](_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1)&nbsp;=&nbsp;1,&nbsp;[SENSOR_RANGE_LEVEL3](_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e)&nbsp;=&nbsp;2,&nbsp;[SENSOR_RANGE_LEVEL_MAX](_sensor.md#p165901247205)&nbsp;} | 传感器的量程级别。&nbsp;[更多...](_sensor.md#sensorrangetype) | 
| [SensorModeType](_sensor.md#sensormodetype)&nbsp;{&nbsp;&nbsp;&nbsp;[SENSOR_MODE_DEFAULT](_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d)&nbsp;=&nbsp;0,&nbsp;[SENSOR_MODE_REALTIME](_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d)&nbsp;=&nbsp;1,&nbsp;[SENSOR_MODE_ON_CHANGE](_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322)&nbsp;=&nbsp;2,&nbsp;[SENSOR_MODE_ONE_SHOT](_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[SENSOR_MODE_FIFO_MODE](_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f)&nbsp;=&nbsp;4,&nbsp;[SENSOR_MODE_MAX](_sensor.md#p4932820101810)&nbsp;} | 传感器的工作模式。&nbsp;[更多...](_sensor.md#sensormodetype) | 
| [SensorGroupType](_sensor.md#sensorgrouptype)&nbsp;{&nbsp;[TRADITIONAL_SENSOR_TYPE](_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64)&nbsp;=&nbsp;0,&nbsp;[MEDICAL_SENSOR_TYPE](_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47)&nbsp;=&nbsp;1,&nbsp;[SENSOR_GROUP_TYPE_MAX](_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94)&nbsp;} | 枚举传感器的硬件服务组。&nbsp;[更多...](_sensor.md#sensorgrouptype) | 


## **详细描述**

定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。

**Since：**

2.2

**Version：**

1.0
