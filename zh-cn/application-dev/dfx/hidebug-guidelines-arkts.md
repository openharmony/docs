# 使用HiDebug获取调试信息（ArkTS）

HiDebug对外提供系统调试相关功能的接口，包括应用进程的静态堆内存（native heap）信息、应用进程内存占用PSS（Proportional Set Size）信息的获取等，也可完成虚拟机内存切片导出，虚拟机CPU Profiling采集等操作。

## 接口说明

| 接口名                             | 描述                                                         |
| ---------------------------------- | ------------------------------------------------------------ |
| hidebug.getNativeHeapSize          | 获取内存分配器统计的进程持有的堆内存大小（含分配器元数据）。 |
| hidebug.getNativeHeapAllocatedSize | 获取内存分配器统计的进程业务分配的堆内存大小。               |
| hidebug.getNativeHeapFreeSize      | 获取内存分配器持有的缓存内存大小。                           |
| hidebug.getPss                     | 获取应用进程实际使用的物理内存大小。                         |
| hidebug.getVss                     | 获取应用进程虚拟耗用内存大小。                               |
| hidebug.getSharedDirty             | 获取进程的共享脏内存大小。                                   |
| hidebug.getPrivateDirty            | 获取进程的私有脏内存大小。                                   |
| hidebug.getCpuUsage                | 获取进程的CPU使用率。                                        |
| hidebug.dumpJsHeapData             | 虚拟机堆导出。                                               |
| hidebug.startJsCpuProfiling        | 启动虚拟机Profiling方法跟踪。                                |
| hidebug.stopJsCpuProfiling         | 停止虚拟机Profiling方法跟踪。                                |
| hidebug.getAppVMMemoryInfo         | 获取VM内存相关信息。                                         |
| hidebug.getAppThreadCpuUsage       | 获取应用线程CPU使用情况。                                    |
| hidebug.startAppTraceCapture       | 启动应用trace采集。                                          |
| hidebug.stopAppTraceCapture        | 停止应用trace采集。                                          |
| hidebug.getAppMemoryLimit          | 获取应用程序进程内存限制。                                   |
| hidebug.getSystemCpuUsage          | 获取系统的CPU资源占用情况。                                  |
| hidebug.setAppResourceLimit        | 设置应用的fd数量、线程数量、js内存或者native内存资源限制。   |
| hidebug.getAppNativeMemInfo        | 获取应用进程内存信息。                                       |
| hidebug.getSystemMemInfo           | 获取系统内存信息。                                           |
| hidebug.getVMRuntimeStats          | 获取系统gc全部统计信息。                                     |
| hidebug.getVMRuntimeStat           | 根据参数获取指定的系统gc统计信息。                           |
| hidebug.getGraphicsMemory          | 使用异步方式获取应用显存大小。                    |
| hidebug.getGraphicsMemorySync      | 使用同步方式获取应用显存大小。                    |

HiDebug的具体用法可查看API参考[API参考文档](../reference/apis-performance-analysis-kit/js-apis-hidebug.md)。

## 开发示例

下文将展示如何在应用内增加一个按钮，并单击该按钮以调用hidebug接口。

1. 新建一个工程，选择“Empty Ability”。

2. 工程配置界面中，**Model**选择“Stage”。

3. 在**Project**窗口单击entry &gt; src &gt; main &gt; ets &gt; pages，打开工程中的Index.ets文件，

   新增一个方法调用hidebug接口，本文以hidebug.getSystemCpuUsage()为例，其他接口可参考[API参考文档](../reference/apis-performance-analysis-kit/js-apis-hidebug.md)。

   ```ts
   import { hidebug } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   function testHidebug(event?: ClickEvent) {
     try {
       console.info(`getSystemCpuUsage: ${hidebug.getSystemCpuUsage()}`)
     } catch (error) {
       console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
     }
   }
   ```

   给文本Text组件添加一个点击事件，示例代码如下：

   ```ts
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'

     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testHidebug);//添加点击事件
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

4. 在真机上运行该工程，单击应用/服务界面上的“Hello World”文本。

5. 在DevEco Studio的底部，切换到“Log”窗口，设置日志的过滤条件为“testTag”。
   此时窗口将显示通过hidebug.getSystemCpuUsage()接口获取的CPU使用率的相关日志。
   ```Text
	08-20 11:06:01.891   1948-1948     A03d00/JSAPP                    com.examp...lication  I     getSystemCpuUsage: 0.4722222222222222
   ```

<!--RP1-->
<!--RP1End-->