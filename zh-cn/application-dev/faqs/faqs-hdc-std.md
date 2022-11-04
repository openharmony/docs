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

## 用IDE安装HAP包到开发板上无法打开

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

请检查sdk和开发板烧录的系统版本是否一致，推荐取同一天的sdk和系统版本。

## 如何通过hdc命令上传文件 

适用于：OpenHarmony SDK 3.2.2.5版本

可以使用hdc_std file send上传文件。

## 如何让RK3568开发板不熄屏

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

输入命令hdc_std shell "power-shell setmode 602"

## 如何通过命令启动Ability

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

输入命令hdc_std shell aa start -a AbilityName -b bundleName -m moduleName

## 如何修改开发板中文件目录为可读写权限

适用于：OpenHarmony SDK 3.2.5.6版本，API9 Stage模型

输入命令 hdc_std shell mount -o remount,rw /

## 如何解决hdc_std file recv 使用报错：Unkonw file option -r

适用于：OpenHarmony SDK 3.2.5.6版本，API9 Stage模型

1. 使用设备镜像或者同版本SDK中配套的hdc工具进行使用。

2. hdc工具指定的路径不要包含中文和空格。

## 如何使用命令卸载应用

适用于：OpenHarmony SDK 3.2.2.5版本

输入命令hdc_std uninstall [-k] [package_name]

## 如何查看系统是32位还是64位

适用于：OpenHarmony SDK 3.2.5.5版本

使用命令：hdc_std shell getconf LONG_BIT

若返回64则为64位系统，否则为32位系统。

## 如何查看组件树结构

适用于：OpenHarmony SDK 3.2.5.5版本

1. 使用命令hdc_std shell 进入命令行界面。

2. 输入 aa dump -a 找到abilityID。

3. aa dump -i [abilityID] -c -render 查看组件树。
<!--no_check-->