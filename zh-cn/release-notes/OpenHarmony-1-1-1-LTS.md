# OpenHarmony 1.1.1 LTS（2021-06-22）(停止维护)

## 版本概述

更新发布LTS（long-term support）长期支持版本OpenHarmony 1.1.1，本版本在1.1.0版本的基础上新增了部分功能和修复了部分缺陷。

## 源码获取

### 通过镜像站点获取

**表 1**  源码获取路径

| 版本源码                 | 版本信息 | 下载站点                                                     | SHA256校验码                                                 |
| ------------------------ | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码                 | 1.1.1    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.1/code-v1.1.1-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.1/code-v1.1.1-LTS.tar.gz.sha256) |
| Hi3861解决方案（二进制） | 1.1.1    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.1/wifiiot-1.1.0.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.1/wifiiot-1.1.0.tar.gz.sha256) |
| Hi3518解决方案（二进制） | 1.1.1    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3518ev300-1.1.1.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3518ev300-1.1.1.tar.gz.sha256) |
| Hi3516解决方案（二进制） | 1.1.1    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3516dv300-1.1.1.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3516dv300-1.1.1.tar.gz.sha256) |
| Release Notes            | 1.1.1    | [站点](https://repo.huaweicloud.com/harmonyos/os/1.1.1/OpenHarmony_Release_Notes_1.1.1_LTS.md) | -                                                            |


### 通过repo下载

下载命令如下：

repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v1.1.1-LTS  --no-repo-verify

## 更新说明

本版本完全继承了OpenHarmony 1.1.0的所有特性，并在OpenHarmony 1.1.0版本的基础上，对各模块进行了缺陷修复和性能优化，详情请参考下表。

**表 2**  版本更新说明

| 类别    | 更新内容                                                     |
| ------- | ------------------------------------------------------------ |
| 通信    | - 更新了部分STA相关功能的数据类以及新增了几个AP相关功能的innerkits接口<br/>- 新增了蓝牙相关功能的innerkits接口，包括BLE设备gatt相关的操作，以及BLE广播、扫描等功能 |
| 安全    | - 支持调用方仅使用绑定的能力，裁剪设备认证能力<br/>- 支持了huks裁剪设备认证 |
| 内核    | - 修复clang编译的系统镜像内核栈回溯功能失效<br/>- 解决调度中存在有符号数与无符号数比较<br/>- 修复setitimer中定时给进程发信号时未持有调度锁，导致踩内存等问题<br/>- lwip适配内核posix接口<br/>- 修复sigaction中sigsuspend的后执行信号顺序与预期不符，信号注册时未屏蔽用户传入信号屏蔽字段 |
| 驱动    | - liteos_m上的编译错误修复<br/>- 合入解决mmc crash的问题     |
| AI      | - AI添加共享内存机制<br/>- AI添加linux内核适配<br/>- 同步算法禁用异步调用<br/>- 添加gitignore和Cmakelist |
| 图形    | - 修复circle progress开启端点样式情况下，进度为0，圆形端点需要绘制问题<br/>- 修改旋转表冠灵敏度及方向相关问题<br/>- 增加 UIList 自动对齐动画时间设置功能<br/>- 修复当LineBreakMode为LINE_BRAK_ELLIPSIS时UILabel GetText宽度值错误<br/>- slider组件新增样式属性<br/>- UITimePicker增加设置循环接口<br/>- 修复定点数优化导致的NEON旋转缩放变换显示异常的BUG<br/>- 修复换行算法在字符串中有多个换行符时存在的换行错误<br/>- 修复表盘指针显示花屏问题 |
| 全球化  | - 添加日期时间模板Ed和MEd                                    |
| ACE框架 | - 修复checkbox/radio点击事件异常<br/>- 修复list和if指令场景JS应用crash问题<br/>- slider样式归一处理<br/>- pickerview组件支持循环滑动<br/>- 修改align-item设置值为stretch情况下，子项居中显示的问题 |


