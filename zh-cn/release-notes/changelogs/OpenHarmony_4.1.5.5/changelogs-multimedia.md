## c1.multimedia.1 ohos.multimedia.audio AudioManager接口setAudioParameter/getAudioParameter废弃

**访问级别**

公开接口

**废弃原因**

不再开放三方应用与音频芯片通过定制参数直接修改配置的通道，收归系统内部管控，通用功能由专有接口替代

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**废弃的接口**

接口属于AudioManager

setAudioParameter(key: string, value: string, callback: AsyncCallback<void>): void;

setAudioParameter(key: string, value: string): Promise<void>;

getAudioParameter(key: string, callback: AsyncCallback<string>): void;

getAudioParameter(key: string): Promise<string>;

**适配指导**

对于系统应用，根据废弃接口提示，使用替代接口：

setExtraParameters(mainKey: string, kvpairs: Record<string, string>): Promise<void>;

getExtraParameters(mainKey: string, subKeys?: Array<string>): Promise<Record<string, string>>;

mainKey与原接口参数key保持一致，kvpairs是原有value字符串内多个key-value配对的拆分写法。

对于三方应用，本接口提供的功能本身不对三方开放，请按需使用系统在AudioManager模块中提供的公开音频管理接口。

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划。