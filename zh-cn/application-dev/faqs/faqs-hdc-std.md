# hdc_std命令使用常见问题



## 日志的常用命令 

适用于：OpenHarmony SDK 3.2.2.5版本

清理日志：hdc_std shell hilog -r

调大缓存到20M：hdc_std shell hilog -G 20M

抓取日志：hdc_std shell hilog &gt; log.txt

## 日志限流怎么规避 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

- 关闭日志限流 hdc_std shell hilog -Q pidoff

- 关闭隐私标志  hdc_std shell hilog -p off

- 增加日志buffer  hdc_std shell hilog -G 200M

- 关闭全局日志，只打开自己领域的日志 hdc_std shell hilog –b D –D  0xd0xxxxx

执行完命令后重启DevEco Studio。

## 应用如何打印日志是使用hilog还是console，hilog接口参数domain的设置范围是什么？

适用于：OpenHarmony SDK 3.2.2.5版本

推荐使用[hilog日志系统](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-hilog.md)进行日志打印，接口参数domain的设置范围可以参考[开发指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-hilog.md#hilogisloggable)。

## hilog日志打印长度限制是多少，是否可以配置 

适用于：OpenHarmony SDK 3.2.2.5版本

日志打印的长度限制为1024个字符，该长度不能配置。

## 为什么有时候直接用IDE安装HAP包到开发板上无法打开？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

请检查sdk和开发板烧录的系统版本是否一致，推荐取同一天的sdk和系统版本。

## 如何通过hdc命令上传文件 

适用于：OpenHarmony SDK 3.2.2.5版本

可以使用hdc_std file send上传文件。

## 如何让RK3568开发板不熄屏？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

输入命令hdc_std shell "power-shell setmode 602"

## 如何通过命令启动Ability？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

输入命令hdc_std shell aa start -a AbilityName -b bundleName -m moduleName
