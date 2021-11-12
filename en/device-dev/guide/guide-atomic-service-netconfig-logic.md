# Introduction to the Core Code<a name="EN-US_TOPIC_0000001111806146"></a>

The core code in the project is described as follows:

1.  After the  **MainAbility**  is started, the Java code uses  **nanSessionId**  read from the  **intent**  for network configuration and uses  **productId**  to determine the type of the device to connect. By default, a smart fan is used.

    For details about how to read device information, see  **onStart**  in  **MainAbility.java**.

    In addition, register  **abilityContext**  and  **sessionId**  with the network configuration SDK.

    ```
    String sessionId = intent.getStringParam("nanSessionId");
    if ("null".equals(sessionId) || "".equals(sessionId)) {
    	NetConfigAbility.register(this, null);
    } else {
    	NetConfigAbility.register(this, sessionId);
    }
    ```

2.  The Java code passes  **productId**,  **productName**, and  **sessionId**  read from the  **MainAbility**  to JS.

    For details on the code, see  **MainAbility.java**.

    ```
    IntentParams intentParams = intent.getParams();
    if (intentParams != null) {
    	intentParams.setParam("productId", productId);
    	intentParams.setParam("productName", productName);
            intentParams.setParam("sessionId", sessionId);
    	setPageParams(null, intentParams);
    }
    ```

3.  The JS code displays the device icon based on  **productName**. For details on the code, see  **device.js**.

    ```
    onInit() {
    	this.deviceName = this.$t('strings.device-name');
    	this.deviceImg = '/common/img/' + this.productName + ".png";
    	getApp(this).Product.productName = this.productName;
    	getApp(this).Product.productId = this.productId;
            getApp(this).ConfigParams.sessionId = this.sessionId;
    }
    ```

4.  After you click the  **Configure network**  button, the network configuration logic is executed. For details on the code, see  **netconfig.js**.
    1.  Discover the nearest device through Neighbor Awareness Networking \(NAN\) broadcast.

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

    2.  Connect to the device.

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

    3.  Obtain the Wi-Fi information used by the phone.

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

    4.  Configure the network for the device. After the configuration is successful, the device control page is displayed.

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

        >![](../public_sys-resources/icon-note.gif) **NOTE:** 
        >By default, the template project redirects to the device control page configured in the  **control**  module. You can modify the code for redirection to a custom device control page. Note that  **sessionId**  must be passed to subsequent pages for sending messages to the device.
        >The JS API for sending messages to devices is  **NetConfig.sendMessage\(commonInfo, message, callbackFunc\)**.
        >The Java API for sending messages to devices is  **NetConfigApi._getInstance_\(\).sendMessage\(CommonInfo, String, BaseCallback<String\>\)**.



