# DFX开发常见问题

## 程序打开直接崩溃了，如何定位问题

使用于：OpenHarmony SDK 3.2.5.5版本

1. 通过业务日志打印，定位崩溃的代码位置。

2. 通过Crash文件查看报错信息，Crash文件路径是：/data/log/faultlog/faultlogger/。

## UiTest测试框架无法获取控件问题

使用于：OpenHarmony SDK 3.2.5.5版本

检查系统配置项 persist.ace.testmode.enabled 是开启。

通过hdc_std shell param get persist.ace.testmode.enabled 查看，若配置项为0，

可通过命令hdc_std shell param set persist.ace.testmode.enabled 1 开启配置。


## C++代码中hilog的格式参数类型为%d或者%s时，日志打印为何显示private

直接使用%d、%s等格式化参数时，标准系统默认使用private替换真实数据进行打印，防止数据泄露。如果需要打印出真实数据，需要使用%{public}d替换%d或者%{public}s替换%s。

## 如何解决hilog.debug日志无法打印

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过hdc_std命令 hdc_std shell hilog -b D开启调试开关

## 应用如何打印日志是使用hilog还是console，hilog接口参数domain的设置范围是什么

适用于：OpenHarmony SDK 3.2.2.5版本

推荐使用[hilog日志系统](../reference/apis/js-apis-hilog.md)进行日志打印，接口参数domain的设置范围可以参考[开发指南](../reference/apis/js-apis-hilog.md#hilogisloggable)。

## hilog日志打印长度限制是多少，是否可以配置 

适用于：OpenHarmony SDK 3.2.2.5版本

日志打印的长度限制为1024个字符，该长度不能配置。

## hilog接口的tag参数是否支持用空格隔开的多个字符串

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

不支持。

## hilog中没有使用{public}标识的数据，如何打印真实数据

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

使用命令：hdc_std shell hilog -p off
