# 驱动开发


## 驱动模型介绍

HDF（Hardware Driver Foundation）框架以组件化的驱动模型作为核心设计思路，为开发者提供更精细化的驱动管理，让驱动开发和部署更加规范。HDF框架将一类设备驱动放在同一个Host（设备容器）里面，用于管理一组设备的启动加载等过程。在划分Host时，驱动程序是部署在一个Host还是部署在不同的Host，主要考虑驱动程序之间是否存在耦合性，如果两个驱动程序之间存在依赖，可以考虑将这部分驱动程序部署在一个Host里面，否则部署到独立的Host中是更好的选择。Device对应一个真实的物理设备。DeviceNode是设备的一个部件，Device至少有一个DeviceNode。每个DeviceNode可以发布一个设备服务。驱动即驱动程序，每个DevicdNode唯一对应一个驱动，实现和硬件的功能交互。HDF驱动模型如下图所示：

  **图1** HDF驱动模型

  ![HDF驱动模型](figures/HDF驱动模型.png)


## 驱动开发步骤

基于HDF框架的驱动开发主要分为三个部分：驱动实现、驱动编译脚本编写和驱动配置。详细开发流程如下所示：

1. 驱动实现

   驱动实现包含驱动业务代码实现和驱动入口注册，具体写法如下：

   - 驱动业务代码
        
      ```c
      #include "hdf_device_desc.h"          // HDF框架对驱动开发相关能力接口的头文件
      #include "hdf_log.h"                  // HDF框架提供的日志接口头文件
      
      #define HDF_LOG_TAG sample_driver     // 打印日志所包含的标签，如果不定义则用默认定义的HDF_TAG标签。
      
      // 将驱动对外提供的服务能力接口绑定到HDF框架。
      int32_t HdfSampleDriverBind(struct HdfDeviceObject *deviceObject)
      {
          HDF_LOGD("Sample driver bind success");
          return HDF_SUCCESS;
      }
      
      // 驱动自身业务初始化的接口
      int32_t HdfSampleDriverInit(struct HdfDeviceObject *deviceObject)
      {
          HDF_LOGD("Sample driver Init success");
          return HDF_SUCCESS;
      }
      
      // 驱动资源释放的接口
      void HdfSampleDriverRelease(struct HdfDeviceObject *deviceObject)
      {
          HDF_LOGD("Sample driver release success");
          return;
      }
      ```
   - 驱动入口注册到HDF框架
        
      ```c
      // 定义驱动入口的对象，必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量。
      struct HdfDriverEntry g_sampleDriverEntry = {
          .moduleVersion = 1,
          .moduleName = "sample_driver",
          .Bind = HdfSampleDriverBind,
          .Init = HdfSampleDriverInit,
          .Release = HdfSampleDriverRelease,
      };
      
      // 调用HDF_INIT将驱动入口注册到HDF框架中。在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动；当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。
      HDF_INIT(g_sampleDriverEntry);
      ```

2. 驱动编译脚本编写

   - LiteOS

     涉及Makefile和BUILD.gn修改：

     - Makefile部分：

       驱动代码的编译必须要使用HDF框架提供的Makefile模板进行编译。

         
       ```c
       include $(LITEOSTOPDIR)/../../drivers/hdf_core/adapter/khdf/liteos/lite.mk # 【必需】导入hdf预定义内容
       MODULE_NAME :=        #生成的结果文件
       LOCAL_INCLUDE :=      #本驱动的头文件目录
       LOCAL_SRCS :=         #本驱动的源代码文件
       LOCAL_CFLAGS ：=      #自定义的编译选项
       include $(HDF_DRIVER) #导入Makefile模板完成编译
       ```

       编译结果文件链接到内核镜像，添加到**drivers/hdf_core/adapter/khdf/liteos**目录下的**hdf_lite.mk**里面，示例如下：

           
       ```c
       LITEOS_BASELIB +=  -lxxx  #链接生成的静态库
       LIB_SUBDIRS    +=         #驱动代码Makefile的目录
       ```

     - BUILD.gn部分：

       添加模块BUILD.gn，可参考如下示例：

           
       ```c
       import("//build/lite/config/component/lite_component.gni")
       import("//drivers/hdf_core/adapter/khdf/liteos/hdf.gni")
       module_switch = defined(LOSCFG_DRIVERS_HDF_xxx)
       module_name = "xxx"
       hdf_driver(module_name) {
           sources = [
               "xxx/xxx/xxx.c",           #模块要编译的源码文件
           ]
           public_configs = [ ":public" ] #使用依赖的头文件配置
       }
       config("public") {                 #定义依赖的头文件配置
           include_dirs = [
               "xxx/xxx/xxx",             #依赖的头文件目录
           ]
       }
        ```

       把新增模块的BUILD.gn所在的目录添加到**/drivers/hdf_core/adapter/khdf/liteos/BUILD.gn**里面：

           
       ```c
       group("liteos") {
           public_deps = [ ":$module_name" ]
               deps = [
                   "xxx/xxx",   #新增模块BUILD.gn所在的目录，目录结构相对于/drivers/hdf_core/adapter/khdf/liteos
               ]
       }
       ```
   - Linux

     如果需要定义模块控制宏，需要在模块目录xxx里面添加Kconfig文件，并把Kconfig文件路径添加到**drivers/hdf_core/adapter/khdf/linux/Kconfig**里面：

        
     ```c
     source "drivers/hdf/khdf/xxx/Kconfig" #目录为hdf模块软链接到kernel里面的目录
     ```

     添加模块目录到**drivers/hdf_core/adapter/khdf/linux/Makefile**：

        
     ```c
     obj-$(CONFIG_DRIVERS_HDF)  += xxx/
     ```

     在模块目录xxx里面添加Makefile文件，在Makefile文件里面添加模块代码编译规则：

        
     ```c
     obj-y  += xxx.o
     ```

3. 驱动配置

   HDF使用HCS作为配置描述源码，HCS详细介绍参考[配置管理](../driver/driver-hdf-manage.md)介绍。

   驱动配置包含两部分，HDF框架定义的驱动设备描述和驱动的私有配置信息，具体写法如下：

   - 驱动设备描述（必选）

     HDF框架加载驱动所需要的信息来源于HDF框架定义的驱动设备描述，因此基于HDF框架开发的驱动必须要在HDF框架定义的device_info.hcs配置文件中添加对应的设备描述。驱动的设备描述填写如下所示：

        
      ```
      root {
          device_info {
              match_attr = "hdf_manager";
              template host {       // host模板，继承该模板的节点（如下sample_host）如果使用模板中的默认值，则节点字段可以缺省。
                  hostName = "";
                  priority = 100;
                  uid = "";         // 用户态进程uid，缺省为空，会被配置为hostName的定义值，即普通用户。
                  gid = "";         // 用户态进程gid，缺省为空，会被配置为hostName的定义值，即普通用户组。
                  caps = [""];      // 用户态进程Linux capabilities配置，缺省为空，需要业务模块按照业务需要进行配置。
                  template device {
                      template deviceNode {
                          policy = 0;
                          priority = 100;
                          preload = 0;
                          permission = 0664;
                          moduleName = "";
                          serviceName = "";
                          deviceMatchAttr = "";
                      }
                  }
              }
              sample_host :: host{
                  hostName = "host0";    // host名称，host节点是用来存放某一类驱动的容器。
                  priority = 100;        // host启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证host的加载顺序。
                  caps = ["DAC_OVERRIDE", "DAC_READ_SEARCH"];   // 用户态进程Linux capabilities配置。
                  device_sample :: device {        // sample设备节点
                      device0 :: deviceNode {      // sample驱动的DeviceNode节点
                          policy = 1;              // policy字段是驱动服务发布的策略，在驱动服务管理章节有详细介绍。
                          priority = 100;          // 驱动启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证device的加载顺序。
                          preload = 0;             // 驱动按需加载字段。
                          permission = 0664;       // 驱动创建设备节点权限
                          moduleName = "sample_driver";      // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致。
                          serviceName = "sample_service";    // 驱动对外发布服务的名称，必须唯一。
                          deviceMatchAttr = "sample_config"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等。
                      }
                  }
              }
          }
      }
      ```
             
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
      >
      > - uid、gid、caps等配置项是用户态驱动的启动配置，内核态不用配置。
      >
      > - 根据进程权限最小化设计原则，业务模块uid、gid不用配置，如上面的sample_host，使用普通用户权限，即uid和gid被定义为hostName的定义值。
      >
      > - 如果普通用户权限不能满足业务要求，需要把uid、gid定义为system或者root权限时，请找安全专家进行评审。
      >
      > - 进程的uid在文件**base/startup/init_lite/services/etc/passwd**中配置，进程的gid在文件**base/startup/init_lite/services/etc/group**中配置，进程uid和gid配置参考：[系统服务用户组添加方法](https://gitee.com/openharmony/startup_init_lite/wikis)。
      >
      > - caps值：格式为caps = ["xxx"]，如果要配置CAP_DAC_OVERRIDE，此处需要填写caps = ["DAC_OVERRIDE"]，不能填写为caps = ["CAP_DAC_OVERRIDE"]。
      >
      > - preload：驱动按需加载字段，参考[驱动加载](../driver/driver-hdf-load.md)。


   - 驱动私有配置信息（可选）

     如果驱动有私有配置，则可以添加一个驱动的配置文件，用来填写一些驱动的默认配置信息。HDF框架在加载驱动的时候，会将对应的配置信息获取并保存在HdfDeviceObject中的property里面，通过Bind和Init（参考步骤1）传递给驱动。驱动的配置信息示例如下：

        
      ```
      root {
          SampleDriverConfig {
              sample_version = 1;
              sample_bus = "I2C_0";
              match_attr = "sample_config";   // 该字段的值必须和device_info.hcs中的deviceMatchAttr值一致
          }
      }
      ```

      配置信息定义之后，需要将该配置文件添加到板级配置入口文件hdf.hcs，示例如下：

        
      ```
      #include "device_info/device_info.hcs"
      #include "sample/sample_config.hcs"
      ```

