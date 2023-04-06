# ServiceAbility组件配置


与PageAbility类似，ServiceAbility的相关配置在config.json配置文件的"module"对象的"abilities"对象中，与PageAbility的区别在于"type"属性及"backgroundModes"属性。


  **表1** ServiceAbility部分配置项说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| type | 表示Ability的类型。取值为"service"时表示该Ability是基于Service模板开发的Ability。 | 字符串 | 否 |
| backgroundModes | 表示后台服务的类型，可以为一个服务配置多个后台服务类型。该标签仅适用于service类型的Ability。取值范围如下：<br/>dataTransfer：通过网络/对端设备进行数据下载、备份、分享、传输等业务。<br/>audioPlayback：音频输出业务。<br/>audioRecording：音频输入业务。<br/>pictureInPicture：画中画、小窗口播放视频业务。<br/>voip：音视频电话、VOIP业务。<br/>location：定位、导航业务。<br/>bluetoothInteraction：蓝牙扫描、连接、传输业务。<br/>wifiInteraction：WLAN扫描、连接、传输业务。<br/>screenFetch：录屏、截屏业务。<br/>multiDeviceConnection：多设备互联业务。 | 字符串数组 | 可缺省，缺省值为空。 |


ServiceAbility支持的配置项及详细说明详见[module对象内部结构](../quick-start/module-structure.md)。
