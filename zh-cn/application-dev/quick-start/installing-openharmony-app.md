# 安装运行OpenHarmony应用

安装OpenHarmony应用需要使用hdc工具，通过手动执行命令行完成应用的安装。


hdc工具本身需要手动从开源仓中获取。然后通过工具命令将应用安装到设备上。


相关命令如下：


- 安装命令。支持直接将本地应用的hap包安装到终端设备上。
  **install [-r/-d/-g]  *package***

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


完整的hdc工具使用指导及命令格式请参见[hdc_std使用指导](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)。

