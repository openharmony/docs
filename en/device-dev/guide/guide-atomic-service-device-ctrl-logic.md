# Introduction to the Core Code Logic<a name="EN-US_TOPIC_0000001111964324"></a>

-   [Core Code Description](#section17354153553419)

## Core Code Description<a name="section17354153553419"></a>

The core logic is described in  **DataHandlerAbility.java**. The code process is as follows:

1.  After the JS page is started, the JS code requests the template configuration from Java.

    JS code:

    ```
    async requestTemplate() {
    	// This function requests the JSON configuration used for display from Java.
    	let action = utils.makeAction(ACTION_MESSAGE_CODE_GET_TEMPLATE, {});
    	let result = await FeatureAbility.callAbility(action);
    	let resultJson = JSON.parse(result);
    	if (resultJson.code == 0) {
    		let template = JSON.parse(resultJson.data);
    		this.parseJson(template.template);
    	}
    }
    ```

    Java code:

    ```
    private boolean onRemoteRequest(int code, MessageParcel data, MessageParcel reply) {
    	switch (code) {
    		case ACTION_MESSAGE_CODE_GET_TEMPLATE: {
    			reply.writeString(getWriteTemplateString());
    			break;
    		}
    		default: {
    			reply.writeString("service not defined");
    			return false;
    		}
    	}
    	return true;
    }
    ```

2.  The Java code reads the template configuration file. The configuration file path is specified by  **getTemplate**  in  **DataHandlerAbility**. The path can be a local path or a URL.

    ```
    private ZSONObject getTemplate() {
    	// source indicates whether the JSON configuration file is from a local file or an online file.
    	final String source = "local";
    	// configDir indicates the directory.
    	final String configDir = SampleDeviceDataHandler.EXAMPLE_TEMPLATE_FILE_DIR + "/" + productName;
    	// configPath indicates the URL of the JSON configuration file. You can change it corresponding 
    	// to your product name or device ID.
    	final String configPath = configDir + "/" + productName + "_" + language + ".json";
    	ZSONObject result = null;
    	if (LOCAL.equals(source)) {
    		try {
    			Resource resource = abilityContext.getResourceManager().getRawFileEntry(configPath).openRawFile();
    			byte[] tmp = new byte[1024 * 1024];
    			int reads = resource.read(tmp);
    			if (reads != -1) {
    				String jsonString = new String(tmp, 0, reads, StandardCharsets.UTF_8);
    				result = ZSONObject.stringToZSON(jsonString);
    			}
    		} catch (IOException e) {
    			HiLog.error(LABEL_LOG, "Failed to open the template from the local file.");
    		}
    	} else {
    		try {
    			URL url = new URL(configPath);
    			URLConnection urlc = url.openConnection();
    			urlc.connect();
    			try (InputStream is = urlc.getInputStream();
    				 InputStreamReader isReader = new InputStreamReader(is, StandardCharsets.UTF_8);
    				 BufferedReader reader = new BufferedReader(isReader)) {
    				StringBuilder sb = new StringBuilder();
    				String str;
    				while ((str = reader.readLine()) != null) {
    					sb.append(str);
    				}
    				result = ZSONObject.stringToZSON(sb.toString());
    			}
    		} catch (IOException e) {
    			HiLog.error(LABEL_LOG, "Failed to open the template from the URL.");
    		}
    	}
    	if (result != null) {
    		// iconUrl is the icon's prefix path. Here we use /common/productName in the js module. You can change it into your
    		// cloud url. All icon files must be under iconUrl.
    		result.put("iconUrl", SampleDeviceDataHandler.EXAMPLE_RESOURCE_DIR + "/" + productName);
    		// deviceIcon is the product icon's file name. It must be under iconUrl.
    		result.put("deviceIcon", "/" + productName + ".png");
    		// logoIcon is the product logo's file name. It must be under iconUrl.
    		result.put("logoIcon", "/logo.png");
    	}
    	return result;
    }
    ```

3.  After obtaining the configuration, the JS code requests device data from Java.

    JS code:

    ```
    async getData() {
    	let action = utils.makeAction(ACTION_MESSAGE_CODE_GET_DATA, {});
    	await FeatureAbility.callAbility(action);
    }
    ```

    Java code:

    ```
    private boolean onRemoteRequest(int code, MessageParcel data, MessageParcel reply) {
    	switch (code) {
    		case ACTION_MESSAGE_CODE_GET_DATA: {
    			deviceDataHandler.getData();
    			break;
    		}
    		default: {
    			reply.writeString("service not defined");
    			return false;
    		}
    	}
    	return true;
    }
    ```

4.  The Java code initializes the device data and calls  **BaseDeviceDataHandler\#initProfileData**  to return all profile data of the device.

    ```
    NetworkDeviceDataHandler(String deviceId, DeviceDataCallback deviceDataCallback) {
    	super(deviceId, deviceDataCallback);
    	dataModel = fanDataModel;
    	mainHandler = new EventHandler(EventRunner.getMainEventRunner());
    	mainHandler.postTask(() -> initProfileData(0, "", dataModel.recoverData()));
    }
    ```

    For example, the initial data of the intelligent fan in the template is as follows:

    ```
    private final DeviceDataModel fanDataModel = new DeviceDataModel() {
    	@Override
    	public Map<String, Object> recoverData() {
    		dataMap.put("switch/on", 0);
    		dataMap.put("windMode/mode", 0);
    		dataMap.put("windGear/gear", 0);
    		dataMap.put("shutdown/mode", 0);
    		return dataMap;
    	}
    }
    ```

5.  When a click event occurs on the JS page that has data loaded,  **BaseDeviceDataHandler\#modifyDeviceProperty**  is called and sent to the device. In this case, the UI does not change. After the device responds,  **BaseDeviceDataHandler\#onDeviceDataChange**  is called back to return the changed data to the UI layer. Now the UI is automatically refreshed.

    In the template, the logic for the intelligent fan to send messages to the device is as follows:

    ```
    private void sendMessage(String message, HashMap<String, Object> tmpMap) {
    	CommonInfo commonInfo = new CommonInfo();
    	commonInfo.setSessionId(sessionId);
    	HiLog.error(LABEL_LOG, "sessionId " + sessionId);
    	NetConfigApi.getInstance().sendMessage(commonInfo, message, (code, controlMessage, str) -> {
    		if (code == 0) {
    			HiLog.info(LABEL_LOG, "Message sent successfully " + message);
    			dataMap.putAll(tmpMap);
    			mainHandler.postTask(() -> onDeviceDataChange(dataMap));
    		} else {
    			HiLog.error(LABEL_LOG, "Failed to send message, code = " +
    					code + " control message = " + controlMessage);
    		}
    	});
    }
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >The template supports only message delivery from the mobile phone to the device. The function of sending messages from the device to the mobile phone will be supported in the future.


