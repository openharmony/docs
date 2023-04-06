# 移植验证


OpenHarmony芯片移植完成后，需要开展OpenHarmony兼容性测试以及芯片SDK功能性测试。除可获得测试认证之外，还可以在开发阶段提前发现缺陷，大幅提高代码质量。


## OpenHarmony兼容性测试

OpenHarmony兼容性测试是XTS（OpenHarmony生态认证测试套件）之一，详见[OpenHarmony兼容性测试](https://gitee.com/openharmony/docs/blob/master/zh-cn/readme/XTS%E5%AD%90%E7%B3%BB%E7%BB%9F.md)。

1. 添加test子系统以及xts_acts部件。
   在“vendor/xxx/xxx/config.json”文件中，添加如下代码：

     
   ```
   {
     "subsystem": "test",
     "components": [
       { "component": "xts_acts", "features":[] },
       { "component": "xts_tools", "features":[] }
     ]
   }
   ```

2. 链接XTS生成的.a库。
   在链接选项中，需要链接生成于“out/MyBoard/MyProduct/libs”目录下的XTS的.a库，其库的名称格式为libmodule_ActsXxxTest.a，链接方式为"-lmodule_ActsXxxTest",示例代码如下：

     
   ```
   "-Wl,--whole-archive",
   ......
   "-lhctest",
   "-lbootstrap",
   "-lbroadcast",
   "-lmodule_ActsBootstrapTest",
   "-lmodule_ActsCMSISTest",
   "-lmodule_ActsDfxFuncTest",
   "-lmodule_ActsParameterTest",
   "-lmodule_ActsSamgrTest",
   "-lmodule_ActsSecurityDataTest",
   ......
   "-Wl,--no-whole-archive",
   ```

3. 根据测试报告调整代码。
   将编译生成的文件烧录到开发板上，使用串口工具查看xts测试报告。如果出现"failed"的测试项，则需要整改代码。

   定位问题时，可在“test/xts/acts/build_lite/BUILD.gn”中，将不需要的测试项注释，以便调试。

     
   ```
   if (ohos_kernel_type == "liteos_m") {
     all_features += [
       "//test/xts/acts/communication_lite/lwip_hal:ActsLwipTest",
       "//test/xts/acts/communication_lite/softbus_hal:ActsSoftBusTest",
       "//test/xts/acts/communication_lite/wifiservice_hal:ActsWifiServiceTest",
       "//test/xts/acts/utils_lite/file_hal:ActsUtilsFileTest",
       "//test/xts/acts/startup_lite/syspara_hal:ActsParameterTest",
       "//test/xts/acts/iot_hardware_lite/iot_controller_hal:ActsWifiIotTest",
       "//test/xts/acts/kernel_lite/kernelcmsis_hal:ActsCMSISTest",
       "//test/xts/acts/utils_lite/kv_store_hal:ActsKvStoreTest",
       "//test/xts/acts/security_lite/datahuks_hal:ActsSecurityDataTest",
       "//test/xts/acts/hiviewdfx_lite/hilog_hal:ActsDfxFuncTest",
       "//test/xts/acts/distributed_schedule_lite/samgr_hal:ActsSamgrTest",
       "//test/xts/acts/update_lite/updater_hal:ActsUpdaterFuncTest",
       "//test/xts/acts/startup_lite/bootstrap_hal:ActsBootstrapTest",
     ]
   }
   ```

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 1. XTS会在OHOS_SystemInit()调用之后，自行运行测试。
> 
> 2. 需要在"-Wl,--whole-archive"和"-Wl,--no-whole-archive"中间添加，否则链接不到。
> 
> 进行XTS测试时，必须链接以下静态库
> 
>   
> ```
> "-lhctest",
> "-lbootstrap",
> "-lbroadcast",
> ```


## 厂商SDK功能性测试

芯片移植完成后需要客户验证SDK自身功能，例如Wi-Fi，蓝牙，OTA等基础能力是否正常。
