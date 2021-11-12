# 核心代码逻辑介绍<a name="ZH-CN_TOPIC_0000001111806146"></a>

关于工程中的核心代码说明如下：

1.  碰一碰拉起MainAbility后， 从intent中读取的nanSessionId用于配网，productId用于确定需要连接的设备类型，默认为智能电风扇。

    参考MainAbility.java的onStart函数中如何读取设备信息。

    同时需要将abilityContext和sessionId注册到配网SDK中。

    ```
    String sessionId = intent.getStringParam("nanSessionId");
    if ("null".equals(sessionId) || "".equals(sessionId)) {
    	NetConfigAbility.register(this, null);
    } else {
    	NetConfigAbility.register(this, sessionId);
    }
    ```

2.  MainAbility读取到的productId、productName和sessionId会作为参数会传递到JS。

    代码参考MainAbility.java

    ```
    IntentParams intentParams = intent.getParams();
    if (intentParams != null) {
    	intentParams.setParam("productId", productId);
    	intentParams.setParam("productName", productName);
            intentParams.setParam("sessionId", sessionId);
    	setPageParams(null, intentParams);
    }
    ```

3.  JS根据productName显示对应的设备图标， 代码参考device.js

    ```
    onInit() {
    	this.deviceName = this.$t('strings.device-name');
    	this.deviceImg = '/common/img/' + this.productName + ".png";
    	getApp(this).Product.productName = this.productName;
    	getApp(this).Product.productId = this.productId;
            getApp(this).ConfigParams.sessionId = this.sessionId;
    }
    ```

4.  点击配网后会执行配网逻辑，代码参考netconfig.js
    1.  通过NAN广播发现最近的一个设备。

        ```
        discoverDevice() {
        	let scanInfo = {
        		duration: 30,
        		lockTime: 60,
        		sessionId: getApp(this).ConfigParams.sessionId
        	};
        	// Step 1 Discover the device through NAN broadcast.
        	getApp(this).NetConfig.discoveryByNAN(scanInfo, (result) => {
        		if (result.code == 0) {
        			this.progress = this.progressStatus[1];
        			this.desc = this.descStatus[1];
        			getApp(this).ConfigParams.deviceInfo = result.data;
        			this.registerDisconnectCallback(result.data.sessionId);
        			this.connectDevice();
        		} else {
        			this.progress = this.progressStatus[4];
        			this.desc = this.failDescStatus[1];
        			this.disconnectDevice();
        		}
        	});
        }
        ```

    2.  连接设备。

        ```
        connectDevice() {
        	let connectInfo = {
        		targetDeviceId: getApp(this).ConfigParams.deviceInfo.productId,
        		type: 0,
        		pin: '0123456789012345',
        		password: getApp(this).ConfigParams.deviceInfo.sn,
        		sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
        	};
        	// Step 2 Connect the device.
        	getApp(this).NetConfig.connectDevice(connectInfo, (result) => {
        		if (result.code === 0) {
        			this.progress = this.progressStatus[2];
        			this.desc = this.descStatus[2];
        			this.getWifiInfo();
        		} else {
        			this.progress = this.progressStatus[4];
        			this.desc = this.failDescStatus[2];
        			this.disconnectDevice();
        		}
        	});
        }
        ```

    3.  获取手机连接的wifi信息。

        ```
        getWifiInfo() {
        	// Step 3 Obtain the Wi-Fi information used by the phone for connection.
        	getApp(this).NetConfig.getWifiList((result) => {
        		if (result.code == 0 && result.data && result.data.length > 0) {
        			this.progress = this.progressStatus[3];
        			this.desc = this.descStatus[3];
        			this.configDevice(result.data[0]);
        		} else {
        			this.progress = this.progressStatus[4];
        			this.desc = this.descStatus[3];
        			this.disconnectDevice();
        		}
        	});
        }
        ```

    4.  与设备进行配网， 配网成功后跳转到设备控制页面。

        ```
        async configDevice(wifiApInfo) {
        	let netConfigInfo = {
        		ssid: wifiApInfo.ssid,
        		ssidPassword: '',
        		isDefaultPassword: true,
        		channel: wifiApInfo.channel,
        		sessionId: getApp(this).ConfigParams.deviceInfo.sessionId,
        		type: 0,
        		wifiApId: wifiApInfo.wifiApId,
        		vendorData: '',
        		timeout: 30,
        		paramValid: true
        	};
        	// Step 4 Configure the device network.
        	getApp(this).NetConfig.configDeviceNet('deviceInfo', 'accountInfo', netConfigInfo, (result) => {
        		if (result.code == 0) {
        			this.progress = this.progressStatus[4];
        			this.desc = this.descStatus[4];
        			this.registerMsgReceive()
        			// Step 5 Display the device control page after a successful network configuration.
        			this.goToControl();
        		} else {
        			this.progress = this.progressStatus[4];
        			this.desc = this.failDescStatus[4];
        			this.disconnectDevice();
        		}
        	});
        }
        ```

        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >模板工程默认跳转到control设备控制模块，你也可以修改代码跳转到自定义的设备控制页，注意必须将sessionId传递到后续页面，用于给设备发送消息。
        >给设备发送消息的JS接口为：NetConfig.sendMessage\(commonInfo, message, callbackFunc\)
        >给设备发送消息的JAVA接口为：NetConfigApi._getInstance_\(\).sendMessage\(CommonInfo, String, BaseCallback<String\>\)



