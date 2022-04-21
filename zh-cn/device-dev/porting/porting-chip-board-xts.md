# XTS认证


## XTS简介

XTS是OpenHarmony生态认证测试套件的集合，当前包括acts（application compatibility test suite）应用兼容性测试套。test/xts仓当前包括acts与tools软件包：

- acts，存放acts相关测试用例源码与配置文件，其目的是帮助终端设备厂商尽早发现软件与OpenHarmony的不兼容性，确保软件在整个开发过程中满足OpenHarmony的兼容性要求。

- tools，存放acts相关测试用例开发框架。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> XTS的启动依赖SAMGR系统服务。


适配分为两步，包括：


1. 将XTS认证子系统加入编译组件中。

2. 执行联接类模组acts测试用例。


### 将XTS认证子系统加入编译组件中

举例：将XTS认证子系统加入hispark_aries产品编译组件中为例。

1. 在vendor/hisilicon/hispark_aries/config.json中加入XTS认证子系统定义：
     
   ```
   {
       "subsystem": "test",
       "components": [
          { "component": "xts_acts", "features":[] },
          { "component": "xts_tools", "features":[] }
        ]
   },
   ```

2. Debug版本才会触发XTS认证子系统编译；


### 执行联接类模组acts测试用例

举例：以hispark_aries产品执行联接类模组acts测试用例为例。


1. 获取编译镜像。
   请在如下目录获取版本镜像：out/hispark_pegasus/wifiiot_hispark_pegasus/。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 判断当前版本镜像是否集成acts测试套件方法：在map文件中查看对应.a是否被编译即可。

2. 版本镜像烧录进开发板。

3. 测试步骤。

   （1）使用串口工具登录开发板，并保存串口打印信息。

   （2）重启设备，查看串口日志。

4. 测试结果分析指导。

   （1）基于串口打印日志进行分析；

   （2）每个测试套件执行以“Start to run test suite”开始，以“xx Tests xx Failures xx Ignored”结束。
