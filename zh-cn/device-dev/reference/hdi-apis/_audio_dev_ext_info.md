# AudioDevExtInfo


## 概述

音频设备拓展信息。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [moduleId](#moduleid) | unsigned&nbsp;int<br/>音频流绑定的模块ID。 | 
| [type](#type) | enum&nbsp;[AudioPortPin](_audio.md#audioportpin)<br/>音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_audio.md#audioportpin)。 | 
| [desc](#desc) | String<br/>地址描述。 | 


## 类成员变量说明


### desc

  
```
String AudioDevExtInfo::desc
```

**描述:**

地址描述。


### moduleId

  
```
unsigned int AudioDevExtInfo::moduleId
```

**描述:**

音频流绑定的模块ID。


### type

  
```
enum AudioPortPin AudioDevExtInfo::type
```

**描述:**

音频端口上的Pin脚（输出、输入），详情参考[AudioPortPin](_audio.md#audioportpin)。
