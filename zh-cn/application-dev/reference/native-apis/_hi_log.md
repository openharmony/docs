# HiLog


## **Overview**

**Description:**

HiLog模块实现日志打印功能。

开发者可以通过使用这些接口实现日志相关功能，输出日志时可以指定日志类型、所属业务领域、日志TAG标识、日志级别等。

\@syscap SystemCapability.HiviewDFX.HiLog

**Since:**

8


## **Summary**


### Files

  | File&nbsp;Name | Description | 
| -------- | -------- |
| [log.h](log_8h.md) | HiLog模块日志接口定义，通过这些接口实现日志打印相关功能。 | 


### Macros

  | Macro&nbsp;Name&nbsp;and&nbsp;Value | Description | 
| -------- | -------- |
| LOG_DOMAIN&nbsp;&nbsp;&nbsp;0 | 日志所对应的业务领域，用于标识业务的子系统、模块。 | 
| LOG_TAG&nbsp;&nbsp;&nbsp;NULL | 字符串常量，标识调用所在的类或者业务。 | 
| OH_LOG_DEBUG(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)OH_LOG_Print((type),&nbsp;LOG_DEBUG,&nbsp;LOG_DOMAIN,&nbsp;LOG_TAG,&nbsp;__VA_ARGS__)) | DEBUG级别写日志，宏封装接口。 | 
| OH_LOG_INFO(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)OH_LOG_Print((type),&nbsp;LOG_INFO,&nbsp;LOG_DOMAIN,&nbsp;LOG_TAG,&nbsp;__VA_ARGS__)) | INFO级别写日志，宏封装接口。 | 
| OH_LOG_WARN(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)OH_LOG_Print((type),&nbsp;LOG_WARN,&nbsp;LOG_DOMAIN,&nbsp;LOG_TAG,&nbsp;__VA_ARGS__)) | WARN级别写日志，宏封装接口。 | 
| OH_LOG_ERROR(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)OH_LOG_Print((type),&nbsp;LOG_ERROR,&nbsp;LOG_DOMAIN,&nbsp;LOG_TAG,&nbsp;__VA_ARGS__)) | ERROR级别写日志，宏封装接口。 | 
| OH_LOG_FATAL(type,&nbsp;...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type),&nbsp;LOG_FATAL,&nbsp;LOG_DOMAIN,&nbsp;LOG_TAG,&nbsp;__VA_ARGS__)) | FATAL级别写日志，宏封装接口。 | 


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| LogType&nbsp;{&nbsp;LOG_APP&nbsp;=&nbsp;0&nbsp;} | 日志类型。 | 
| LogLevel&nbsp;{&nbsp;&nbsp;&nbsp;LOG_DEBUG&nbsp;=&nbsp;3,&nbsp;LOG_INFO&nbsp;=&nbsp;4,&nbsp;LOG_WARN&nbsp;=&nbsp;5,&nbsp;LOG_ERROR&nbsp;=&nbsp;6,&nbsp;&nbsp;&nbsp;LOG_FATAL&nbsp;=&nbsp;7&nbsp;} | 日志级别。 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| OH_LOG_Print&nbsp;(LogType&nbsp;type,&nbsp;LogLevel&nbsp;level,&nbsp;unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;const&nbsp;char&nbsp;\*fmt,...)&nbsp;__attribute__((__format__(os_log | int<br/>写日志接口。 | 
| OH_LOG_IsLoggable&nbsp;(unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;LogLevel&nbsp;level) | int&nbsp;bool<br/>检查指定业务领域、TAG、级别的日志是否可以打印。 | 


## **Details**


## **Macro Definition**


### LOG_DOMAIN

  
```
#define LOG_DOMAIN   0
```

**Description:**

日志所对应的业务领域，用于标识业务的子系统、模块。

16进制整数，有效范围0x0~0xFFFF，超过自动截掉高位。


### LOG_TAG

  
```
#define LOG_TAG   NULL
```

**Description:**

字符串常量，标识调用所在的类或者业务。


### OH_LOG_DEBUG

  
```
#define OH_LOG_DEBUG( type,  ... )   ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description:**

DEBUG级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 | 
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 | 
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 | 

**See also:**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_ERROR

  
```
#define OH_LOG_ERROR( type,  ... )   ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description:**

ERROR级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 | 
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 | 
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 | 

**See also:**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_FATAL

  
```
#define OH_LOG_FATAL( type,  ... )   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description:**

FATAL级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 | 
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 | 
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 | 

**See also:**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_INFO

  
```
#define OH_LOG_INFO( type,  ... )   ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description:**

INFO级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 | 
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 | 
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 | 

**See also:**

[OH_LOG_Print](#oh_log_print)

### OH_LOG_WARN

  
```
#define OH_LOG_WARN( type,  ... )   ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description:**

WARN级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 | 
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 | 
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 | 

**See also:**

[OH_LOG_Print](#oh_log_print)


## **Enumeration Type**


### LogLevel

  
```
enum LogLevel
```

**Description:**

日志级别。

该枚举类型用于定义日志级别。

各级别建议使用方式： 

DEBUG：比INFO级别更详细的流程记录，通过该级别的日志可以更详细地分析业务流程和定位分析问题。DEBUG级别的日志在正式发布版本中默认不会被打印，只有在调试版本或打开调试开关的情况下才会打印。 

INFO：用来记录业务关键流程节点，可以还原业务的主要运行过程；用来记录非正常情况信息，但这些情况都是可以预期的(如无网络信号、登录失败等)。这些日志都应该由该业务内处于支配地位的模块来记录，避免在多个被调用的模块或低级函数中重复记录。 

WARN：发生了较为严重的非预期情况，但是对用户影响不大，程序可以自动恢复或通过简单的操作就可以恢复的问题。

ERROR：程序或功能发生了错误，该错误会影响功能的正常运行或用户的正常使用，可以恢复但恢复代价较高，如重置数据等。 

FATAL：重大致命异常，表明程序或功能即将崩溃，故障无法恢复。

  | Enumerator | Description | 
| -------- | -------- |
| LOG_DEBUG | DEBUG日志级别，使用OH_LOG_DEBUG接口打印 | 
| LOG_INFO | INFO日志级别，使用OH_LOG_INFO接口打印 | 
| LOG_WARN | WARN日志级别，使用OH_LOG_WARN接口打印 | 
| LOG_ERROR | ERROR日志级别，使用OH_LOG_ERROR接口打印 | 
| LOG_FATAL | FATAL日志级别，使用OH_LOG_FATAL接口打印 | 


### LogType

  
```
enum LogType
```

**Description:**

日志类型。

该枚举类型用于定义应用开发者可以使用的日志类型。当前有应用日志LOG_APP。

  | Enumerator | Description | 
| -------- | -------- |
| LOG_APP | 应用日志 | 


## **Function**


### OH_LOG_IsLoggable()

  
```
int bool OH_LOG_IsLoggable (unsigned int domain, const char * tag, LogLevel level )
```

**Description:**

检查指定业务领域、TAG、级别的日志是否可以打印。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| domain | 指定日志业务领域。 | 
| tag | 指定日志TAG。 | 
| level | 指定日志level。 | 

**Returns:**

如果指定domain、tag、level日志可以打印则返回true；否则返回false。


### OH_LOG_Print()

  
```
int OH_LOG_Print (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * fmt,  ... )
```

**Description:**

写日志接口。

指定日志类型、日志级别、业务领域、TAG，按照类printf格式类型和隐私指示确定需要输出的变参。

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 | 
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。 | 
| domain | 日志业务领域，16进制整数，范围0x0~0xFFFF。 | 
| tag | 日志TAG，字符串，标识调用所在的类或者业务。 | 
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 | 
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 | 

**Returns:**

大于等于0表示成功；小于0表示失败。
