# lwIP组件适配


lwIP是一个小型开源的TCP/IP协议栈，LiteOS-M已对开源lwIP做了适配和功能增强，lwIP代码分为两部分：


- third_party/lwip目录下是lwIP开源代码，里面只做了少量的侵入式修改，为了适配增强功能。

- kernel/liteos_m/components/net/lwip-2.1目录下是lwIP适配和功能增强代码，里面提供了lwIP的默认配置文件。


如果需要使用lwIP组件，请按如下步骤适配：


1. 在产品目录下新建一个目录用来存放产品的适配文件，如lwip_adapter。

2. 在lwip_adapter目录下新建一个目录include，用来存放适配的头文件。

3. 在include目录下新建目录lwip，并在lwip目录下新建头文件lwipopts.h，代码如下所示，如果默认配置不能满足产品使用，可自行根据产品使用情况修改配置，如关闭DHCP功能。
     
   ```
   #ifndef _LWIP_ADAPTER_LWIPOPTS_H_
   #define _LWIP_ADAPTER_LWIPOPTS_H_
   
   #include_next "lwip/lwipopts.h"
   
   #undef LWIP_DHCP#define LWIP_DHCP                       0 // 关闭DHCP功能
   
   #endif /* _LWIP_ADAPTER_LWIPOPTS_H_ */
   ```

4. 将kernel/liteos_m/components/net/lwip-2.1目录下的BUILD.gn复制到lwip_adapter目录下，并按如下修改。
     
   ```
   import("//kernel/liteos_m/liteos.gni")
   import("$LITEOSTHIRDPARTY/lwip/lwip.gni")
   import("$LITEOSTOPDIR/components/net/lwip-2.1/lwip_porting.gni")
   module_switch = defined(LOSCFG_NET_LWIP_SACK)
   module_name = "lwip"kernel_module(module_name) {
     sources = LWIP_PORTING_FILES + LWIPNOAPPSFILES - [ "$LWIPDIR/api/sockets.c" ]
     include_dirs = [ "//utils/native/lite/include" ]
   }
   #添加新增加的适配头文件路径include
   config("public") {
     include_dirs = [ "include" ] + LWIP_PORTING_INCLUDE_DIRS + LWIP_INCLUDE_DIRS
   }
   ```

5. 在产品的配置文件(如config.json)中设置lwIP的编译路径，即步骤4中BUILD.gn的路径。
     
   ```
   {
     "subsystem": "kernel",
     "components": [
       { "component": "liteos_m", "features":["ohos_kernel_liteos_m_lwip_path = \"//xxx/lwip_adapter\"" ] }
     ]
   },
   ```

6. 在产品的内核编译配置文件中，如kernel_config/debug.config，打开编译lwIP的开关。
     
   ```
   LOSCFG_NET_LWIP=y
   ```
