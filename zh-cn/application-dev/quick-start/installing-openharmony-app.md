# 安装运行OpenHarmony应用



安装OpenHarmony应用可以通过DevEco Studio安装，也可以通过使用hdc工具进行手动安装。


- 通过DevEco Studio安装：将设备连接上DevEco Studio后，点击![zh-cn_image_0000001239855207](figures/zh-cn_image_0000001239855207.png)按钮即可安装。

- 通过hdc工具安装：手动执行命令行完成应用的安装。
  hdc工具本身需要手动从开源仓中获取。然后使用工具将编译后的本地hap包发送至设备侧并完成安装。

  相关命令如下：

  - 安装命令
     **install [-r/-d/-g] _package_**

     命令示例：

     ```
     hdc_std install E:\hwadmin.hap
     ```
  - 日志抓取命令
     **hilog**

     命令示例：

     ```
     hdc_std hilog
     ```

  完整的hdc工具使用指导及命令格式请参见[hdc_std使用指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-toolchain-hdc-guide.md)。
