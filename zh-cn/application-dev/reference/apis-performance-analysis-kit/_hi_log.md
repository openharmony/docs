# HiLog

## 概述

HiLog模块实现日志打印功能。

开发者可以通过使用这些接口实现日志相关功能，输出日志时可以指定日志类型、所属业务领域、日志TAG标识、日志级别等。

**系统能力：** SystemCapability.HiviewDFX.HiLog

**起始版本：** 8

## 汇总

### 文件

| 名称 | 描述 |
| -------- | -------- |
| [log.h](log_8h.md) | HiLog模块日志接口定义，通过这些接口实现日志打印相关功能。<br>**引用文件**：<hilog/log.h> <br>**库**：libhilog_ndk.z.so |

### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [LOG_DOMAIN](#log_domain)&nbsp;&nbsp;&nbsp;0 | 日志所对应的业务领域，用于标识业务的子系统、模块。 |
| [LOG_TAG](#log_tag)&nbsp;&nbsp;&nbsp;NULL | 字符串常量，标识调用所在的类或者业务。 |
| [OH_LOG_DEBUG](#oh_log_debug)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_DEBUG, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | DEBUG级别写日志，宏封装接口。 |
| [OH_LOG_INFO](#oh_log_info)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_INFO, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | INFO级别写日志，宏封装接口。 |
| [OH_LOG_WARN](#oh_log_warn)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_WARN, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | WARN级别写日志，宏封装接口。 |
| [OH_LOG_ERROR](#oh_log_error)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_ERROR, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | ERROR级别写日志，宏封装接口。 |
| [OH_LOG_FATAL](#oh_log_fatal)(type, ...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type), LOG_FATAL, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | FATAL级别写日志，宏封装接口。 |

### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef void(\* [LogCallback](#logcallback)) (const [LogType](#logtype) type, const [LogLevel](#loglevel) level, const unsigned int domain, const char \*tag, const char \*msg) | 函数指针，开发者自定义回调函数内容，在回调函数中，可自行对hilog日志进行处理。  |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [LogType](#logtype) { LOG_APP = 0 } | 日志类型。 |
| [LogLevel](#loglevel) {<br/>LOG_DEBUG = 3,<br/>LOG_INFO = 4,<br/>LOG_WARN = 5,<br/>LOG_ERROR = 6,<br/>LOG_FATAL = 7<br/>} | 日志级别。 |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| int [OH_LOG_Print](#oh_log_print) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) \_\_attribute\_\_((\_\_format\_\_(os_log  | 写日志接口。  |
| int bool [OH_LOG_IsLoggable](#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](#loglevel) level) | 检查指定业务领域、TAG、级别的日志是否可以打印。  |
| void [OH_LOG_SetCallback](#oh_log_setcallback) ([LogCallback](#logcallback) callback) | 注册函数。  |
| void [OH_LOG_SetMinLogLevel](#oh_log_setminloglevel) ([LogLevel](#loglevel) level) | 设置当前应用进程的最低日志级别。  |
| int [OH_LOG_PrintMsg](#oh_log_printmsg) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char \*tag, const char \*message) int OH_LOG_PrintMsgByLen([LogType](#logtype) type | 输出指定type、level、domain、tag的常量日志字符串。  |

## 宏定义说明

### LOG_DOMAIN

```
#define LOG_DOMAIN   0
```

**描述**
日志所对应的业务领域，用于标识业务的子系统、模块。

16进制整数，有效范围0x0~0xFFFF，超过自动截掉高位。

**起始版本：** 8

### LOG_TAG

```
#define LOG_TAG   NULL
```

**描述**

字符串常量，标识调用所在的类或者业务。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。

**起始版本：** 8

### OH_LOG_DEBUG

```
#define OH_LOG_DEBUG( type,  ... )   ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**描述**
DEBUG级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。  |
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。  |

**参见：**

[OH_LOG_Print](#oh_log_print)

### OH_LOG_ERROR

```
#define OH_LOG_ERROR( type,  ... )   ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**描述**
ERROR级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。  |
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。  |

**参见：**

[OH_LOG_Print](#oh_log_print)

### OH_LOG_FATAL

```
#define OH_LOG_FATAL( type,  ... )   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**描述**
FATAL级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。  |
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。  |

**参见：**

[OH_LOG_Print](#oh_log_print)

### OH_LOG_INFO

```
#define OH_LOG_INFO( type,  ... )   ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**描述**
INFO级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。  |
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。  |

**参见：**

[OH_LOG_Print](#oh_log_print)

### OH_LOG_WARN

```
#define OH_LOG_WARN( type,  ... )   ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**描述**
WARN级别写日志，宏封装接口。

使用时需要先定义日志业务领域、日志TAG，一般在源文件起始处统一定义一次。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。  |
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。  |

**参见：**

[OH_LOG_Print](#oh_log_print)

## 类型定义说明

### LogCallback

```
typedef void(* LogCallback) (const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
```

**描述**
函数指针，开发者自定义回调函数内容，在回调函数中，可自行对hilog日志进行处理。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 |
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。 |
| domain | 日志业务领域，16进制整数，范围为0x0~0xFFFF。 |
| tag | 日志TAG，字符串，标识调用所在的类或者业务。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| msg | 日志内容，格式化之后的日志字符串。 |

## 枚举类型说明

### LogLevel

```
enum LogLevel
```

**描述**
日志级别。

该枚举类型用于定义日志级别。各级别建议使用方式：

DEBUG：比INFO级别更详细的流程记录，通过该级别的日志可以更详细地分析业务流程和定位分析问题。DEBUG级别的日志在正式发布版本中默认不会被打印，只有在调试版本或打开调试开关的情况下才会打印。

INFO：用来记录业务关键流程节点，可以还原业务的主要运行过程；用来记录非正常情况信息，但这些情况都是可以预期的(如无网络信号、登录失败等)。这些日志都应该由该业务内处于支配地位的模块来记录，避免在多个被调用的模块或低级函数中重复记录。

WARN：发生了较为严重的非预期情况，但是对用户影响不大，程序可以自动恢复或通过简单的操作就可以恢复的问题。

ERROR：程序或功能发生了错误，该错误会影响功能的正常运行或用户的正常使用，可以恢复但恢复代价较高，如重置数据等。

FATAL：重大致命异常，表明程序或功能即将崩溃，故障无法恢复。

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| LOG_DEBUG  | DEBUG日志级别，使用OH_LOG_DEBUG接口打印。&nbsp;&nbsp; |
| LOG_INFO  | INFO日志级别，使用OH_LOG_INFO接口打印。&nbsp;&nbsp; |
| LOG_WARN  | WARN日志级别，使用OH_LOG_WARN接口打印。&nbsp;&nbsp; |
| LOG_ERROR  | ERROR日志级别，使用OH_LOG_ERROR接口打印。&nbsp;&nbsp; |
| LOG_FATAL  | FATAL日志级别，使用OH_LOG_FATAL接口打印。&nbsp;&nbsp; |

### LogType

```
enum LogType
```

**描述**
日志类型。

该枚举类型用于定义应用开发者可以使用的日志类型。当前有应用日志LOG_APP。

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| LOG_APP  | 应用日志&nbsp;&nbsp; |

## 函数说明

### OH_LOG_IsLoggable()

```
int bool OH_LOG_IsLoggable (unsigned int domain, const char * tag, LogLevel level )
```

**描述**
检查指定业务领域、TAG、级别的日志是否可以打印。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| domain | 指定日志业务领域。  |
| tag | 指定日志TAG。  |
| level | 指定日志level。  |

**返回：**

如果指定domain、tag、level日志可以打印则返回true；否则返回false。

### OH_LOG_Print()

```
int OH_LOG_Print (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * fmt,  ... )
```

**描述**
写日志接口。

指定日志类型、日志级别、业务领域、TAG，按照类printf格式类型和隐私指示确定需要输出的变参。

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。  |
| domain | 日志业务领域，16进制整数，范围为0x0~0xFFFF。  |
| tag | 日志TAG，字符串，标识调用所在的类或者业务。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。 |
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。  |
| ... | 与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。  |

**返回：**

大于等于0表示成功；小于0表示失败。

**返回：**

大于等于0表示成功；小于0表示失败。

### OH_LOG_SetCallback()

```
void OH_LOG_SetCallback (LogCallback callback)
```

**描述**
注册函数。

调用此函数后，用户实现的回调函数可以接收当前进程的所有hilog日志。 请注意，无论是否调用该接口，它都不会更改当前进程的hilog日志的默认行为。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| callback | 用户实现的回调函数。如果不需要处理hilog日志，可以传输空指针。  |

### OH_LOG_SetMinLogLevel()

```
void OH_LOG_SetMinLogLevel(LogLevel level)
```

**描述**

设置应用日志打印的最低日志级别，进程在打印日志时，需要同时校验该日志级别和全局日志级别，所以设置的日志级别不能低于全局日志级别，[全局日志级别](../../dfx/hilog.md#查看和设置日志级别)默认为Info。

**起始版本** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| level | 日志级别。  |

### OH_LOG_PrintMsg()

```
int OH_LOG_PrintMsg (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * message )
```

**描述**
输出指定type、level、domain、tag的常量日志字符串。

输出指定type、level、domain、tag的常量日志字符串，需要指定tag及字符串长度。

**起始版本：** 16

**起始版本：** 16

**参数参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。  |
| domain | 日志业务领域，16进制整数，范围为0x0~0xFFFF。  |
| tag | 日志TAG，字符串，标识调用所在的类或者业务。  |
| message | 常量日志字符串。  |
| type | 日志类型，三方应用日志类型为LOG_APP。  |
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。  |
| domain | 日志业务领域，16进制整数，范围为0x0~0xFFFF。  |
| tag | 日志TAG，字符串，标识调用所在的类或者业务。  |
| tagLen | tag长度。  |
| message | 常量日志字符串。  |
| messageLen | 常量字符串长度。  |

**返回：**

大于等于0表示成功；小于0表示失败。

### OH_LOG_PrintMsgByLen()

```
int OH_LOG_PrintMsgByLen(LogType type, LogLevel level, unsigned int domain, const char *tag, size_t tagLen, const char *message, size_t messageLen)
```

**描述**

写日志接口。

输出指定domain、tag和日志级别的常量日志字符串，需要指定tag及字符串长度，和OH_LOG_PrintMsg区别是可以接受不带结束符的字符串。

**起始版本：** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 |
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。 |
| domain | 日志业务领域，16进制整数，范围为0x0~0xFFFF。 |
| tag | 日志TAG，字符串，标识调用所在的类或者业务。 tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。|
| tagLen | tag长度，小于32。 |
| message | 日志字符串。 |
| messageLen | 日志字符串长度，小于3500。 |

**返回：**

大于等于0表示成功；小于0表示失败。

### OH_LOG_VPrint()

```
int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap)
```

**描述**

写日志接口。

指定日志类型、日志级别、业务领域、TAG，按照类printf格式类型和隐私指示确定需要输出的变参，变参为va_list类型。

**起始版本：** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | 日志类型，三方应用日志类型为LOG_APP。 |
| level | 日志级别，日志级别包括LOG_DEBUG、LOG_INFO、LOG_WARN、LOG_ERROR、LOG_FATAL。 |
| domain | 日志业务领域，16进制整数，范围为0x0~0xFFFF。 |
| tag | 日志TAG，字符串，标识调用所在的类或者业务。 tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。|
| fmt | 格式化字符串，基于类printf格式的增强，支持隐私参数标识，即在格式字符串每个参数中符号后类型前增加{public}、{private}标识。 |
| ap | va_list类型，与格式字符串里参数类型对应的参数列表，参数数目、参数类型必须与格式字符串中的标识一一对应。 |

**返回：**

大于等于0表示成功；小于0表示失败。
