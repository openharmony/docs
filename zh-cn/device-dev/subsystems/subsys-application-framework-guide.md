# 开发指导


## 场景介绍

- 带界面的Ability的应用，比如：新闻类的应用、视频类的应用、导航类的应用、支付类的应用等等，目前我们看到的大部分应用都是带有界面的用于人机交互的应用。

- 不带界面的Ability应用，比如：音乐播放器能在后台播放音乐、后台提供计算服务、导航服务的各类应用等。

不管是带界面的Ability应用还是不带界面的Ability应用，都要打包成Hap包，最终发布到应用市场，用户通过应用市场下载安装相应的应用。


## 接口说明

  **表1** Ability子系统的对外接口

| 接口名称 | 接口描述 | 
| -------- | -------- |
| Want&nbsp;\*WantParseUri(const&nbsp;char&nbsp;\*uri) | 反序列化接口，由字符串生成Want对象。 | 
| const&nbsp;char&nbsp;\*WantToUri(Want&nbsp;want) | 序列化接口，把Want对象生成字符串。 | 
| void&nbsp;SetWantElement(Want&nbsp;\*want,&nbsp;ElementName&nbsp;element); | 设置ElementName对象。 | 
| void&nbsp;SetWantData(Want&nbsp;\*want,&nbsp;const&nbsp;void&nbsp;\*data,&nbsp;uint16_t&nbsp;dataLength) | 设置数据。 | 
| bool&nbsp;SetWantSvcIdentity(Want&nbsp;\*want,&nbsp;SvcIdentity&nbsp;sid) | 设置SvcIdentity。 | 
| void&nbsp;ClearWant(Want&nbsp;\*want) | 清除Want的内部内存数据。 | 
| void&nbsp;SetMainRoute(const&nbsp;std::string&nbsp;&amp;entry) | 设置AbilitySlice主路由。 | 
| void&nbsp;SetUIContent(RootView&nbsp;\*rootView) | 设置布局资源。 | 
| void&nbsp;OnStart(const&nbsp;Want&amp;&nbsp;intent) | Ability生命周期状态回调，Ability启动时被回调。 | 
| void&nbsp;OnStop() | Ability生命周期状态回调，Ability销毁时被回调。 | 
| void&nbsp;OnActive(const&nbsp;Want&amp;&nbsp;intent) | Ability生命周期状态回调，Ability显示时被回调。 | 
| void&nbsp;OnInactive() | Ability生命周期状态回调，Ability隐藏时被回调。 | 
| void&nbsp;OnBackground() | Ability生命周期状态回调，Ability退到后台时被回调。 | 
| const&nbsp;SvcIdentity&nbsp;\*OnConnect(const&nbsp;Want&nbsp;&amp;want) | Service类型Ability第一次连接时被回调。 | 
| void&nbsp;OnDisconnect(const&nbsp;Want&nbsp;&amp;want); | Service类型Ability断开连接被回调。 | 
| void&nbsp;MsgHandle(uint32_t&nbsp;funcId,&nbsp;IpcIo&nbsp;\*request,&nbsp;IpcIo&nbsp;\*reply); | Service类型Ability接收消息处理。 | 
| void&nbsp;Dump(const&nbsp;std::string&nbsp;&amp;extra) | dump&nbsp;Ability信息。 | 
| void&nbsp;Present(AbilitySlice&nbsp;\*abilitySlice,&nbsp;const&nbsp;Want&nbsp;&amp;want) | 发起AbilitySlice跳转。 | 
| void&nbsp;Terminate() | 退出当前AbilitySlice。 | 
| void&nbsp;SetUIContent(RootView&nbsp;\*rootView) | 设置当前AbilitySlice所在Ability的布局资源。 | 
| void&nbsp;OnStart(const&nbsp;Want&amp;&nbsp;want) | AbilitySlice生命周期状态回调，AbilitySlice启动时被回调。 | 
| void&nbsp;OnStop() | AbilitySlice生命周期状态回调，AbilitySlice销毁时被回调。 | 
| void&nbsp;OnActive(const&nbsp;Want&amp;&nbsp;want) | AbilitySlice生命周期状态回调，AbilitySlice显示时被回调。 | 
| void&nbsp;OnInactive() | AbilitySlice生命周期状态回调，AbilitySlice隐藏时被回调。 | 
| void&nbsp;OnBackground() | AbilitySlice生命周期状态回调，AbilitySlice退到后台时被回调。 | 
| int&nbsp;StartAbility(const&nbsp;Want&nbsp;&amp;want) | 启动Ability。 | 
| int&nbsp;StopAbility(const&nbsp;Want&nbsp;&amp;want) | 停止Service类型的Ability。 | 
| int&nbsp;TerminateAbility() | 销毁当前的Ability。 | 
| int&nbsp;ConnectAbility(const&nbsp;Want&nbsp;&amp;want,&nbsp;const&nbsp;IAbilityConnection&nbsp;&amp;conn,&nbsp;void&nbsp;\*data); | 绑定Service类型的Ability。 | 
| int&nbsp;DisconnectAbility(const&nbsp;IAbilityConnection&nbsp;&amp;conn) | 解绑Service类型的Ability。 | 
| const&nbsp;char&nbsp;\*GetBundleName() | 获取当前ability的对应应用的包名。 | 
| const&nbsp;char&nbsp;\*GetSrcPath() | 获取当前ability的对应应用的安装路径。 | 
| const&nbsp;char&nbsp;\*GetDataPath() | 获取当前ability的对应应用的数据路径。 | 
| int&nbsp;StartAbility(const&nbsp;Want&nbsp;\*want) | 启动Ability，该接口可以不需要在基于Ability开发的应用中使用。 | 
| int&nbsp;ConnectAbility(const&nbsp;Want&nbsp;\*want,&nbsp;const&nbsp;IAbilityConnection&nbsp;\*conn,&nbsp;void&nbsp;\*data); | 绑定Service类型的Ability，该接口可以不需要在基于Ability开发的应用中使用。 | 
| int&nbsp;DisconnectAbility(const&nbsp;IAbilityConnection&nbsp;\*conn); | 解绑Service类型的Ability，该接口可以不需要在基于Ability开发的应用中使用。 | 
| int&nbsp;StopAbility(const&nbsp;Want&nbsp;\*want) | 停止Service类型的Ability，该接口可以不需要在基于Ability开发的应用中使用。 | 
| void&nbsp;(\*OnAbilityConnectDone)(ElementName&nbsp;\*elementName,&nbsp;SvcIdentity&nbsp;\*serviceSid,&nbsp;int&nbsp;resultCode,&nbsp;void&nbsp;\*data) | 绑定Service&nbsp;Ability的回调。 | 
| void&nbsp;(\*OnAbilityDisconnectDone)(ElementName&nbsp;\*elementName,&nbsp;int&nbsp;resultCode,&nbsp;void&nbsp;\*data) | 解绑Service&nbsp;Ability的回调。 | 
| void&nbsp;PostTask(const&nbsp;Task&amp;&nbsp;task) | 投递任务到异步线程进行处理。 | 
| void&nbsp;PostQuit() | 退出当前线程的消息循环。 | 
| static&nbsp;AbilityEventHandler\*&nbsp;GetCurrentHandler() | 获取当前线程的事件处理器。 | 
| void&nbsp;Run() | 执行当前线程的消息循环。 | 
| \#define&nbsp;REGISTER_AA(className) | 注册开发者的Ability到框架中。 | 
| \#define&nbsp;REGISTER_AS(className) | 注册开发者的AbilitySlice到框架中。 | 


## 开发步骤


### 创建Service类型的Ability


1. 在my_service_ability.h中创建Ability的子类MyServiceAbility。
     
   ```
   class MyServiceAbility: public Ability {
   protected:
       void OnStart(const Want& want);
       const SvcIdentity *OnConnect(const Want &want) override;
       void MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply) override;
   };
   ```

2. 调用REGISTER_AA宏将ServiceAbility注册到应用框架中，以便应用框架实例化MyServiceAbility。
     
   ```
   #include "my_service_ability.h"
   
   REGISTER_AA(ServiceAbility)
   
   void MyServiceAbility::OnStart(const Want& want)
   {
       printf("ServiceAbility::OnStart\n");
       Ability::OnStart(want);
   }
   
   const SvcIdentity *MyServiceAbility::OnConnect(const Want &want)
   {
       printf("ServiceAbility::OnConnect\n");
       return Ability::OnConnect(want);
   }
   
   void MyServiceAbility::MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply)
   {
       printf("ServiceAbility::MsgHandle, funcId is %u\n", funcId);
       int result = 0;
       if (funcId == 0) {
           result = IpcIoPopInt32(request) + IpcIoPopInt32(request);
       }
       // push data
       IpcIoPushInt32(reply, result);
   }
   ```

3. 实现Service相关的生命周期方法。

   Service也是一种Ability，Ability为服务提供了以下生命周期方法，用户可以重写这些方法来添加自己的处理。用户在重写的方法里，需要调用父类对应的方法。

   - OnStart()
     
     该方法在创建Service的时候调用，用于做一些Service初始化且耗时较短的工作，在Service的整个生命周期只会调用一次。
   
      ```
      void MyServiceAbility::OnStart(const Want& want)
      {
          printf("ServiceAbility::OnStart\n");
          Ability::OnStart(want);
      }
      ```
   - OnConnect​()
      
     在组件和服务连接时调用，该方法返回SvcIdentity，组件可以通过它与服务交互。
        
      ```
      const SvcIdentity *MyServiceAbility::OnConnect(const Want &want)
      {
          printf("ServiceAbility::OnConnect\n");
          return Ability::OnConnect(want);
      }
      ```
   - OnDisconnect​()
      
     在组件与绑定的Service断开连接时调用。

   - OnStop()
     
     在Service销毁时调用。Service应通过实现此方法来清理任何资源，如关闭线程、注册的侦听器等。

4. 重写消息处理方法。

   MsgHandle是Service用来处理客户端消息的方法。其中funcId是客户端传过来的消息类型，request是客户端传过来的序列化请求参数。如果用户在处理完成之后想要把结果传回去，需要把结果序列化后写入reply中。
 
   ```
   void ServiceAbility::MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply)
   {
       printf("ServiceAbility::MsgHandle, funcId is %d\n", funcId);
       int result = 0;
       if (funcId == PLUS) {
           result = IpcIoPopInt32(request) + IpcIoPopInt32(request);
       }
       // push data
       IpcIoPushInt32(reply, result);
   }
   ```

5. 注册Service。
  
   Service也需要在应用清单文件config.json中进行注册，注册类型type需要设置为service。

     
   ```
   "abilities": [{
       "name": "ServiceAbility",
       "icon": "res/drawable/phone.png",
       "label": "test app 2", 
       "launchType": "standard",
       "type": "service",
       "visible": true
   }
   ]
   ```

6. 启动Service。

   - Ability为用户提供了StartAbility()方法来启动另外一个Ability，因为Service也是Ability的一种，开发者同样可以通过将Want传递给该方法来启动Service。
        
     开发者可以通过Want的SetWantElement ()来设置目标服务信息。ElementName结构体的两个主要参数：第一个参数为包名称；第二个参数为目标Ability。
        
      ```
      {
          Want want = { nullptr };
          ElementName element = { nullptr };
          SetElementBundleName(&element, "com.company.appname");
          SetElementAbilityName(&element, "ServiceAbility");
          SetWantElement(&want, element);
          StartAbility(want);
          ClearElement(&element);
          ClearWant(&want);
      }
      ```

      StartAbility() 方法会立即执行，如果Service尚未运行，则系统首先会调用OnStart()。
   - 停止Service。
     
     Service一旦创建就会一直保持在后台运行，开发者可以通过调用StopAbility()来停止Service。

7. 连接Service。

   - 如果Service需要与Page Ability或其他应用组件中的Service进行交互，则应创建用于连接的Service。

     Service支持其他Ability通过ConnectAbility()与其进行连接，ConnectAbility()需要传入目标Service的Want，以及IAbilityConnection的实例来处理回调。IAbilityConnection提供了两个方法供用户实现，OnAbilityConnectDone()用来处理连接的回调，OnAbilityDisconnectDone()用来处理断开连接的回调。
        
      ```
      {
          // ability创建IAbilityConnection对象和定义IAbilityConnection的两个方法实现
          IAbilityConnection abilityConnection = new IAbilityConnection();
          abilityConnection->OnAbilityConnectDone = OnAbilityConnectDone;
          abilityConnection->OnAbilityDisconnectDone = OnAbilityDisconnectDone;
       
          void OnAbilityConnectDone(ElementName *elementName, SvcIdentity *serviceSid, 
              int resultCode, void *data)
          {
              if (resultCode != 0) {
                  return;
              }
              // push data
              IpcIo request;
              char dataBuffer[IPC_IO_DATA_MAX];
              IpcIoInit(&request, dataBuffer, IPC_IO_DATA_MAX, 0);
              IpcIoPushInt32(&request, 10);
              IpcIoPushInt32(&request, 6);
       
              // send and getReply
              IpcIo reply;
              uintptr_t ptr = 0;
              if (Transact(nullptr, *serviceSid, 0, &request, &reply, 
                  LITEIPC_FLAG_DEFAULT, &ptr) != LITEIPC_OK) {
                  printf("transact error\n");
                  return;
              }
              int result = IpcIoPopInt32(&reply);
              printf("execute add method, result is %d\n", result);
              if (ptr != 0) {
                  FreeBuffer(nullptr, reinterpret_cast<void *>(ptr));
              }
          }
       
          void OnAbilityDisconnectDone(ElementName *elementName, 
              int resultCode, void *data)
          {
              printf("elementName is %s, %s\n", 
                  elementName->bundleName, elementName->abilityName);
          }
      }
      ```
   - 发起connect和disconnect。
        
      ```
      {
          // ability发起connect
          Want want = { nullptr };
          ElementName element = { nullptr };
          SetElementBundleName(&element, "com.company.appname");
          SetElementAbilityName(&element, "ServiceAbility");
          SetWantElement(&want, element);
          ConnectAbility(want, *abilityConnection, this);
       
          // ability发起disconnect
          DisconnectAbility(*abilityConnection);
      }
      ```


### 包管理接口使用指导


**安装应用**


  安装接口只能给内置的系统应用使用。根据应用的安装路径，可以在安装应用时进行选择：

- 将应用安装到系统默认的文件目录/storage/app/。

- 将应用安装到系统外挂的存储介质中，例如micro sdcard。


这两种选择可以在创建InstallParam实例的时候指定，

- 当InstallParam的成员变量installLocation为 INSTALL_LOCATION_INTERNAL_ONLY时，意味着应用将会被安装到/storage/app/目录下。
- 当InstallParam的成员变量installLocation为INSTALL_LOCATION_PREFER_EXTERNAL时，意味着应用将被安装到存储介质，其安装目录是/sdcard/app/。

由于安装应用的过程是异步的，所以需要使用类似信号量的机制来确保安装的回调可以被执行。


  安装应用的步骤如下（示例代码以安装到系统目录为例）：
1. 将经过安全签名的应用放置于指定的目录下。

2. 创建InstallParam实例和信号量。
     
   ```
   InstallParam installParam = { 
   .installLocation = INSTALL_LOCATION_INTERNAL_ONLY, // 安装到系统目录
   .keepData = false
   };
   static sem_t g_sem;
   ```

3. 定义回调函数。
     
   ```
   static void InstallCallback(const uint8_t resultCode, const void *resultMessage)
   {
        std::string strMessage = reinterpret_cast<const char *>(resultMessage);
        if (!strMessage.empty()) {
           printf("install resultMessage is %s, %d\n", strMessage.c_str(),resultCode);
        }
        sem_post(&g_sem);
   }
   ```

4. 调用Install接口。
     
   ```
   const uint32_t WAIT_TIMEOUT = 30;
   sem_init(&g_sem, 0, 0);
   std::string installPath = “/storage/bundle/demo.hap”; // Hap包的存储路径
   bool result = Install(installPath.c_str(), &installParam, InstallCallback);
   struct timespec ts = {};
   clock_gettime(CLOCK_REALTIME, &ts);
   ts.tv_sec += WAIT_TIMEOUT; // 超时即释放信号量
   sem_timedwait(&g_sem, &ts);
   ```


**卸载应用**


  卸载应用的时候可以选择是否保留应用的数据，开发者可以通过创建的InstallParam实例的成员变量keepData来确定。当keepData为true, 卸载应用之后将保留应用的数据，当keepData为false时，卸载应用之后将不会保留应用的数据。
1. 创建InstallParam实例和信号量。
     
   ```
   static sem_t g_sem;
   InstallParam installParam = {
   .installLocation = 1,
        .keepData = false // 不保留应用数据
   };
   ```

2. 定义回调函数。
     
   ```
   static void UninstallCallback(const uint8_t resultCode, const void *resultMessage)
   {
       std::string strMessage = reinterpret_cast<const char *>(resultMessage);
       if (!strMessage.empty()) {
           printf("uninstall resultMessage is %s\n", strMessage.c_str());
           g_resultMessage = strMessage;
       }
       g_resultCode = resultCode;
       sem_post(&g_sem);
   }
   ```

3. 调用Uninstall接口。
     
   ```
   sem_init(&g_sem, 0, 0);
   const uint32_t WAIT_TIMEOUT = 30;
   std::string BUNDLE_NAME = “com.example.demo”; // 卸载应用的包名
   Uninstall(BUNDLE_NAME.c_str(), &installParam, UninstallCallback);
   struct timespec ts = {};
   clock_gettime(CLOCK_REALTIME, &ts);
   ts.tv_sec += WAIT_TIMEOUT;
   sem_timedwait(&g_sem, &ts);
   ```


**查询已安装应用的包信息**


  开发者可以利用BundleManager提供的接口GetBundleInfo来查询系统内已安装应用的包信息。
1. 创建以及初始化BundleInfo。
     
   ```
   BundleInfo bundleInfo;
   (void) memset_s(&bundleInfo, sizeof(BundleInfo), 0, sizeof(BundleInfo));
   ```

2. 调用GetBundleInfo接口，指定查询应用的包名，同时指定flag来确定获取的BundleInfo中是否含有元能力信息（实例代码以含有元能力信息为例）。
     
   ```
   std::string BUNDLE_NAME = "com.example.demo";
   uint8_t ret = GetBundleInfo(BUNDLE_NAME.c_str(), 1, &bundleInfo); // flags = 1，获取包信息中含有元能力信息
   ```

3. 使用完获取的BundleInfo之后，要及时清理掉其内部所占用的内存空间避免内存泄漏。
     
   ```
   ClearBundleInfo(&bundleInfo);
   ```


### Hap包打包


  打包工具一般集成到开发工具或者IDE中，开发者一般不涉及直接使用该工具，下面的介绍开发者可以作为了解。打包工具的jar包在开源代码中的位置：developtools/packing_tool/jar。

- 打包命令行参数
    
   **表2** 打包所需要的资源文件描述
  
  | 命令参数 | 对应的资源文件 | 说明 | 是否可缺省 | 
  | -------- | -------- | -------- | -------- |
  | --mode | - | 为“hap”字段，打包生成Hap | 否 | 
  | --json-path | 清单文件config.json | - | 否 | 
  | --resources-path | 资源文件resources | - | 是 | 
  | --assets-path | 资源文件assets | - | 是 | 
  | --lib-path | 依赖库TONGGUO&nbsp;文件 | - | 是 | 
  | --shared-libs-path | 共享库文件 | 针对系统应用的共享库，特殊情况下使用 | 是 | 
  | --ability-so-path | 主功能so文件 | - | 是 | 
  | --index-path | 资源索引 | 资源索引文件由资源生成工具生成，由资源流水线会集成该工具 | 是 | 
  | --out-path | - | 生成的Hap包输出路径，默认为当前目录 | 是 | 
  | --force | - | 是否覆盖原有同名文件，默认为false | 是 | 

- 打包示例
    
    **图1** 开发视图

    ![zh-cn_image_0000001154005784](figures/zh-cn_image_0000001154005784.png)

    
    **图2** 编译视图

    ![zh-cn_image_0000001154167492](figures/zh-cn_image_0000001154167492.png)

    
    **图3** 使用打包工具执行以下命令打包：

    ![zh-cn_image_0000001200127655](figures/zh-cn_image_0000001200127655.png)
  
    
  ```
  $ java -jar hmos_app_packing_tool.jar --mode hap --json-path ./config.json --assets-path ./assets/ --ability-so-path ./libentry.so --index-path ./resources.index --out-path out/entry.hap --force true
  ```
