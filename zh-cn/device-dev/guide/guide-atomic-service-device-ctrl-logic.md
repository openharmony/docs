# 核心代码逻辑介绍<a name="ZH-CN_TOPIC_0000001111964324"></a>

-   [核心代码说明](#section17354153553419)

## 核心代码说明<a name="section17354153553419"></a>

核心逻辑都在DataHandlerAbility.java中, 代码流程如下：

1.  JS页面拉起后，会向Java侧请求模板配置数据。

    JS代码：

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

    JAVA代码：

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

2.  Java侧读取模板配置文件：配置文件的路径在DataHandlerAbility的getTemplate中指定，文件来源可以是本地资源，也可以从网络路径读取。

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
    		// iconUrl is icon's prefix path. Here we use /common/productName in js module. You can change it into your
    		// cloud url. All icons file must be under iconUrl.
    		result.put("iconUrl", SampleDeviceDataHandler.EXAMPLE_RESOURCE_DIR + "/" + productName);
    		// deviceIcon is the product icon's file name. It must be under iconUrl.
    		result.put("deviceIcon", "/" + productName + ".png");
    		// logoIcon is the product logo's file name. It must exist under iconUrl.
    		result.put("logoIcon", "/logo.png");
    	}
    	return result;
    }
    ```

3.  JS读取到页面配置后，会向Java侧请求设备数据。

    JS代码：

    ```
    async getData() {
    	let action = utils.makeAction(ACTION_MESSAGE_CODE_GET_DATA, {});
    	await FeatureAbility.callAbility(action);
    }
    ```

    JAVA代码：

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

4.  Java侧进行初始化设备数据，调用BaseDeviceDataHandler\#initProfileData返回设备所有profile数据。

    ```
    NetworkDeviceDataHandler(String deviceId, DeviceDataCallback deviceDataCallback) {
    	super(deviceId, deviceDataCallback);
    	dataModel = fanDataModel;
    	mainHandler = new EventHandler(EventRunner.getMainEventRunner());
    	mainHandler.postTask(() -> initProfileData(0, "", dataModel.recoverData()));
    }
    ```

    例如：模板样例智能电风扇的数据初始化如下。

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

5.  JS界面加载完毕后，事件响应如下：页面点击事件触发后会调用到BaseDeviceDataHandler\#modifyDeviceProperty，发送到设备端，此时UI不会有任何变化。等设备产生响应后，再触发BaseDeviceDataHandler\#onDeviceDataChange回调变化后的数据到UI层，界面会自动刷新。

    例如：模板样例智能电风扇发送消息给设备端的逻辑如下。

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

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >当前模板只提供了从手机发送消息到设备侧的功能，暂不支持从设备侧发送消息到手机，相关能力后续将逐步更新。


