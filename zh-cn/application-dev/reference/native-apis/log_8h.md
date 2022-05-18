# log.h


## **Overview**

**Related Modules:**

[HiLog](_hi_log.md)

**Description:**

HiLog模块日志接口定义，通过这些接口实现日志打印相关功能。

用户输出日志时，先定义日志所属业务领域、日志TAG，然后按照类型、级别选择对应API，指定参数隐私标识输出日志内容。 业务领域：指定日志所对应的业务领域，用户自定义使用，用于标识业务的子系统、模块。16进制整数，范围0x0~0xFFFF。 日志TAG：字符串常量，用于标识调用所在的类或者业务。 日志级别：DEBUG、INFO、WARN、ERROR、FATAL。 参数格式：类printf的方式，包括格式字符串（包括参数类型标识）和变参。 隐私参数标识：在格式字符串每个参数中符号后类型前增加{public}、{private}标识。注意：每个参数未指定隐私标识时，缺省为隐私。 使用示例： 定义业务领域、TAG： \#define LOG_DOMAIN 0x0201 \#define LOG_TAG "MY_TAG" 日志打印： HILOG_WARN([LOG_APP](_hi_log.md#ggaf67907baa897e9fb84df0cb89795b87ca84f0546432a39b6f5e8a777d5cf667b5), "Failed to visit %{private}s, reason:%{public}d.", url, errno); 结果输出： 05-06 15:01:06.870 1051 1051 W 0201/MY_TAG: Failed to visit &lt;private&gt;, reason:503.

**Since:**
8

## **Summary**


### Macros

  | Macro&nbsp;Name&nbsp;and&nbsp;Value | Description | 
| -------- | -------- |
| [LOG_DOMAIN](_hi_log.md#ga95a1d08c807e0aada863b5298a61d08d)&nbsp;&nbsp;&nbsp;0 | 日志所对应的业务领域，用于标识业务的子系统、模块。 | 
| [LOG_TAG](_hi_log.md#ga7ce0df38eb467e59f209470c8f5ac4e6)&nbsp;&nbsp;&nbsp;NULL | 字符串常量，标识调用所在的类或者业务。 | 
| [OH_LOG_DEBUG](_hi_log.md#gac9b9319de06bce0df57ef440ccaa25fc)(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](_hi_log.md#gaed4b343058326b7f5dbcac6799025946)((type),&nbsp;[LOG_DEBUG](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e),&nbsp;[LOG_DOMAIN](_hi_log.md#ga95a1d08c807e0aada863b5298a61d08d),&nbsp;[LOG_TAG](_hi_log.md#ga7ce0df38eb467e59f209470c8f5ac4e6),&nbsp;__VA_ARGS__)) | DEBUG级别写日志，宏封装接口。 | 
| [OH_LOG_INFO](_hi_log.md#gadf3fd661bccb575348c5109a0f24f252)(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](_hi_log.md#gaed4b343058326b7f5dbcac6799025946)((type),&nbsp;[LOG_INFO](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837),&nbsp;[LOG_DOMAIN](_hi_log.md#ga95a1d08c807e0aada863b5298a61d08d),&nbsp;[LOG_TAG](_hi_log.md#ga7ce0df38eb467e59f209470c8f5ac4e6),&nbsp;__VA_ARGS__)) | INFO级别写日志，宏封装接口。 | 
| [OH_LOG_WARN](_hi_log.md#ga1beaeee414c2e0238db4c57212809737)(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](_hi_log.md#gaed4b343058326b7f5dbcac6799025946)((type),&nbsp;[LOG_WARN](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13),&nbsp;[LOG_DOMAIN](_hi_log.md#ga95a1d08c807e0aada863b5298a61d08d),&nbsp;[LOG_TAG](_hi_log.md#ga7ce0df38eb467e59f209470c8f5ac4e6),&nbsp;__VA_ARGS__)) | WARN级别写日志，宏封装接口。 | 
| [OH_LOG_ERROR](_hi_log.md#gab7e62682d195ee81093e7e08673c4941)(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](_hi_log.md#gaed4b343058326b7f5dbcac6799025946)((type),&nbsp;[LOG_ERROR](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473),&nbsp;[LOG_DOMAIN](_hi_log.md#ga95a1d08c807e0aada863b5298a61d08d),&nbsp;[LOG_TAG](_hi_log.md#ga7ce0df38eb467e59f209470c8f5ac4e6),&nbsp;__VA_ARGS__)) | ERROR级别写日志，宏封装接口。 | 
| [OH_LOG_FATAL](_hi_log.md#ga17370605a946403e37024ea898d27f55)(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type),&nbsp;[LOG_FATAL](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b),&nbsp;[LOG_DOMAIN](_hi_log.md#ga95a1d08c807e0aada863b5298a61d08d),&nbsp;[LOG_TAG](_hi_log.md#ga7ce0df38eb467e59f209470c8f5ac4e6),&nbsp;__VA_ARGS__)) | FATAL级别写日志，宏封装接口。 | 


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| [LogType](_hi_log.md#gaf67907baa897e9fb84df0cb89795b87c)&nbsp;{&nbsp;[LOG_APP](_hi_log.md#ggaf67907baa897e9fb84df0cb89795b87ca84f0546432a39b6f5e8a777d5cf667b5)&nbsp;=&nbsp;0&nbsp;} | 日志类型。 | 
| [LogLevel](_hi_log.md#gaca1fd1d8935433e6ba2e3918214e07f9)&nbsp;{&nbsp;&nbsp;&nbsp;[LOG_DEBUG](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e)&nbsp;=&nbsp;3,&nbsp;[LOG_INFO](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837)&nbsp;=&nbsp;4,&nbsp;[LOG_WARN](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13)&nbsp;=&nbsp;5,&nbsp;[LOG_ERROR](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473)&nbsp;=&nbsp;6,&nbsp;&nbsp;&nbsp;[LOG_FATAL](_hi_log.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b)&nbsp;=&nbsp;7&nbsp;} | 日志级别。 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_LOG_Print](_hi_log.md#gaed4b343058326b7f5dbcac6799025946)&nbsp;([LogType](_hi_log.md#gaf67907baa897e9fb84df0cb89795b87c)&nbsp;type,&nbsp;[LogLevel](_hi_log.md#gaca1fd1d8935433e6ba2e3918214e07f9)&nbsp;level,&nbsp;unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;const&nbsp;char&nbsp;\*fmt,...)&nbsp;__attribute__((__format__(os_log | int<br/>写日志接口。 | 
| [OH_LOG_IsLoggable](_hi_log.md#gabba82e8c08cf8941e4af54941eeda257)&nbsp;(unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;[LogLevel](_hi_log.md#gaca1fd1d8935433e6ba2e3918214e07f9)&nbsp;level) | int&nbsp;bool<br/>检查指定业务领域、TAG、级别的日志是否可以打印。 | 
