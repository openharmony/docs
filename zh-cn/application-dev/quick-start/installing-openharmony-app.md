# 安装运行OpenHarmony应用

安装OpenHarmony应用需要使用hdc工具，通过手动执行命令行完成应用的安装。


hdc工具本身需要手动从开源仓中获取。然后使用工具将编译后的hap包发送至设备侧，然后通过hdc命令完成app的安装。


相关命令如下：


- 文件发送命令
  **file send  *localpath remotepath***

  命令示例：

  ```
  hdc_std file send E:\hwadmin.hap /data/local/tmp/hwadmin.hap
  ```

- 安装命令
  **install [-r/-d/-g]  *package***

  命令示例：

  ```
  hdc_std install hwadmin.hap
  ```

- 日志抓取命令
  **hilog**

  命令示例：

  ```
  hdc_std hilog
  ```


完整的hdc工具使用指导及命令格式请参见开源仓”docs/zh-cn/device-dev/subsystems/hdc使用指导.md“。

