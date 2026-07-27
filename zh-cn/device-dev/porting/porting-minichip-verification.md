# 移植验证


OpenHarmony芯片移植完成后，需要开展OpenHarmony兼容性测试以及芯片SDK功能性测试。除可获得测试认证之外，还可以在开发阶段提前发现缺陷，大幅提高代码质量。


## OpenHarmony兼容性测试

OpenHarmony兼容性测试是XTS（OpenHarmony生态认证测试套件）之一，详见[OpenHarmony兼容性测试](https://gitcode.com/openharmony/docs/blob/master/zh-cn/readme/XTS%E5%AD%90%E7%B3%BB%E7%BB%9F.md)。

1. 添加test子系统以及xts_acts部件。 在“vendor/xxx/xxx/config.json”文件中，添加如下代码：

     
   ```json
   {
     "subsystem": "xts",
     "components": [
       { "component": "acts", "features":[] },
       { "component": "tools", "features":[] }, 
       { "component": "device_attest_lite", "features":[] }
     ]
   }
   ```

2. 链接XTS生成的.a库。 在链接选项中，需要链接生成于“out/MyBoard/MyProduct/libs”目录下的XTS的.a库，其库的名称格式为libmodule_ActsXxxTest.a，链接方式为"-lmodule_ActsXxxTest"，示例代码如下：

     
   ```text
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

3. 根据测试报告调整代码。 将编译生成的文件烧录到开发板上，使用串口工具查看xts测试报告。如果出现"failed"的测试项，则需要整改代码。

   定位问题时，可在“test/xts/acts/build_lite/BUILD.gn”中，将不需要的测试项注释，以便调试。

     
   ```gn
   if (ohos_kernel_type == "liteos_m") {
     all_features += [
       "//test/xts/acts/ability_lite/ability_hal:ActsAbilityMgrTest",
       "//test/xts/acts/communication_lite/lwip_hal:ActsLwipTest",
       "//test/xts/acts/communication_lite/dsoftbus_hal:ActsDsoftbusMgrTest",
       #"//test/xts/acts/communication_lite/wifiservice_hal:ActsWifiServiceTest",
       "//test/xts/acts/commonlibrary_lite/file_hal:ActsUtilsFileTest",
       "//test/xts/acts/startup_lite/syspara_hal:ActsParameterTest",
       "//test/xts/acts/iothardware_lite/peripheral_hal:ActsWifiIotTest",
       "//test/xts/acts/kernel_lite/kernelcmsis_hal:ActsCMSISTest",
       "//test/xts/acts/distributeddatamgr_lite/kv_store_hal:ActsKvStoreTest",
       "//test/xts/acts/security_lite/huks/liteos_m_adapter:ActsHuksHalFunctionTest",
       "//test/xts/acts/hiviewdfx_lite/hilog_hal:ActsDfxFuncTest",
       "//test/xts/acts/hiviewdfx_lite/hievent_hal:ActsHieventLiteTest",
       "//test/xts/acts/distributed_schedule_lite/system_ability_manager_hal:ActsSamgrTest",
       "//test/xts/acts/update_lite/dupdate_hal:ActsUpdaterFuncTest",
       "//test/xts/acts/startup_lite/bootstrap_hal:ActsBootstrapTest",
       "//test/xts/acts/xts_lite/device_attest_lite/device_attestStart_hal:ActsDeviceAttestTest",
     ]
     if (bundle_framework_lite_enable_ohos_bundle_manager_service == true) {
       all_features += [
         "//test/xts/acts/appexecfwk_lite/appexecfwk_hal:ActsBundleMgrTest",
       ]
     }
   }
   ```

> <img src="public_sys-resources/icon-caution.gif" alt="说明"/> <b>说明：</b>
> 1. XTS会在OHOS_SystemInit()调用之后，自行运行测试。
> 
> 2. 需要在"-Wl,--whole-archive"和"-Wl,--no-whole-archive"中间添加，否则链接不到。
> 
> 进行XTS测试时，必须链接以下静态库。
> 
>   
>```text
> "-lhctest",
> "-lbootstrap",
> "-lbroadcast",
>```


## 厂商SDK功能性测试

芯片移植完成后需要客户验证SDK自身功能，例如Wi-Fi，蓝牙，OTA等基础能力是否正常。
