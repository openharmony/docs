# 主线程超时事件介绍

## 简介

当应用的主线程执行耗时任务时，开发者会感知到应用卡顿，但卡顿时间未达到系统设定的[应用冻屏](appfreeze-guidelines.md)时间限制，因此不会生成故障日志。为了更好地定位和分析问题，开发者可以利用[主线程超时事件检测原理](apptask-timeout-guidelines.md)，根据生成的采样[主线程超时事件日志规格](apptask-timeout-guidelines.md)，主动分析主线程任务的执行情况。

## 检测原理

详见[主线程超时检测原理](apptask-timeout-guidelines.md#检测原理)

## 接口说明

开发者可以通过HiAppEvent提供接口订阅主线程超时事件“hiAppEvent.event.MAIN_THREAD_JANK”，系统检测到主线程超时后，会抓取维测信息通过HiAppEvent将主线程超时回调给应用进程。

- [订阅主线程超时事件（ArkTS）](hiappevent-watcher-mainthreadjank-events-arkts.md)

- [订阅主线程超时事件（C/C++）](hiappevent-watcher-mainthreadjank-events-ndk.md)

## 自定义参数

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void> | 设置主线程采样栈参数接口。 **现阶段仅提供MAIN_THREAD_JANK事件参数自定义，因此name为MAIN_THREAD_JANK。** |

### 参数设置说明

开发者可以使用上述hiappevent提供的接口，在Record&lt;string, ParamType>中自定义配置采集MAIN_THREAD_JANK事件的参数。

> **注意：**
>
> log_type=0或2，无需设置其他参数。
>
> log_type=1时，必须配置以下参数：sample_interval、ignore_startup_time、sample_count和report_times_per_app。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| log_type | string | 是 | 采集MAIN_THREAD_JANK事件日志类型。<br/>log_type=0：默认值，主线程连续两次超时150ms~450ms，采集调用栈；主线程超时450ms，采集trace。<br/>log_type=1：仅采集调用栈，触发检测的阈值由用户自定义。<br/>log_type=2：仅采集trace。 |
| sample_interval | string | 否 | 主线程超时检测间隔和采样间隔。<br/>单位为ms，取值范围为[50, 500]。<br/>系统根据开发者设置的interval进行超时检测判断，并使用该interval作为周期性任务检测的间隔。 |
| ignore_startup_time | string | 否 | 忽略启动时间内的主线程超时检测。单位为s，最小值：3，默认值：10。<br/>线程启动一定时间内，不进行超时检测。一些进程启动时间较长，此时抓全的超时采样栈，分析意义不大。因此，在开发者定义启动时间间隔内，不进行超时检测。 |
| sample_count | string | 否 | 主线程超时采样次数。系统检测到当前主线程执行任务超过采样限制后，开始周期性采集堆栈，每个间隔采集一次堆栈，共采集sample_count次。<br/>最小值：1次，最大值需要结合自定义的sample_interval进行动态计算，计算公式：sample_count &lt;= (2500 / sample_interval - 4)。 |
| report_times_per_app | string | 否 | 同一个应用的PID一个生命周期内，主线程超时采样上报次数。一个生命周期内只能设置一次。<br/>默认值：1次，单位：次。<br/>开发者选项打开，每小时范围：[1, 3]。<br/>开发者选项关闭，每天上报次数范围：[1, 3]。 |

1. sample_count说明：
   （1）2500的含义：根据系统规定，主线程超时事件从检测到上报的时间不可以超过2.5s（即：2500ms）。因此sample_count的设置值不能超过系统按计算公式得出的最大值。

   （2）4的含义：第一次超时间隔检测时间 + 第二次超时间隔（系统提供两次再次发生超时事件的检测机会）时间 + 收集并上报堆栈信息的时间。

   （3）开发者要结合需求场景，进行合理的设置。

2. 参数设置示例
   以下示例用于模拟配置MAIN_THREAD_JANK事件的门限触发条件，以log_type的三种类型为例：

   (1)log_type=0，用于采样栈或采样trace。

   ```
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   let params: Record<string, hiAppEvent.ParamType> = {
   "log_type": "0"
   };
   hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
   hilog.info(0x0000, 'hiAppEvent', `Setting default value successfully.`);
   }).catch((err: BusinessError) => {
   hilog.error(0x0000, 'hiAppEvent', `Failed to set default value. Code: ${err.code}, message: ${err.message}`);
   });
   ```

   (2)log_type=1，仅用于采集调用栈。

   ```
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   let params: Record<string, hiAppEvent.ParamType> = {
     "log_type": "1",
     "sample_interval": "100",
     "ignore_startup_time": "11",
     "sample_count": "21",
     "report_times_per_app": "3"
   };
   hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
     hilog.info(0x0000, 'hiAppEvent', `Successfully set sampling stack parameters.`);
   }).catch((err: BusinessError) => {
   hilog.error(0x0000, 'hiAppEvent', `Failed to set sample stack value. Code: ${err.code}, message: ${err.message}`);
   });
   ```

   (3)log_type=2，仅用于采集trace。

   ```
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   let params: Record<string, hiAppEvent.ParamType> = {
     "log_type": "2"
   };
   hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
     hilog.info(0x0000, 'hiAppEvent', `Set to only collect trace successfully.`);
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'hiAppEvent', `Failed to set only collect trace. code: ${err.code}, message: ${err.message}`);
   });
   ```

## 事件字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| time | number | 事件触发时间，单位为ms。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。 |
| uid | number | 应用的用户id。 |
| begin_time | number | 主线程任务开始时间。 |
| end_time | number | 主线程任务结束时间。 |
| external_log | string[] | 主线程超时日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit | boolean | 生成的主线程超时日志文件与已存在的日志文件总大小是否超过10M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |
| app_start_jiffies_time | number | 开发者可以获取主线程超时事件时，任务执行的开始时间。**触发采样栈，打印开始时间信息。** |
| heaviest_stack | string | 生成的主线程超时日志文件中，打印多次的调用栈。**触发采样栈，打印多次的调用栈信息。** |
