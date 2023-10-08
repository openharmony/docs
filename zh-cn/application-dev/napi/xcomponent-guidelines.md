# XComponent开发指导

## 场景介绍

Native XComponent是XComponent组件提供在Native层的实例，可作为JS层和Native层XComponent绑定的桥梁。XComponent所提供的的NDK接口都依赖于该实例。接口能力包括获取Native Window实例、获取XComponent的布局/事件信息、注册XComponent的生命周期回调、注册XComponent的触摸、鼠标、按键等事件回调。针对Native XComponent，主要的开发场景如下：

- 利用Native XComponent提供的接口注册XComponent的生命周期和事件回调。
- 在这些回调中进行初始化环境、获取当前状态、响应各类事件的开发。
- 利用Native Window和EGL接口开发自定义绘制内容以及申请和提交Buffer到图形队列。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
|OH_NativeXComponent_GetXComponentId(OH_NativeXComponent* component, char* id, uint64_t* size)|获取XComponent的id。|
|OH_NativeXComponent_GetXComponentSize(OH_NativeXComponent* component, const void* window, uint64_t* width, uint64_t* height)|获取XComponent持有的surface的大小。|
|OH_NativeXComponent_GetXComponentOffset(OH_NativeXComponent* component, const void* window, double* x, double* y)|获取XComponent持有的surface相对窗口左上角的偏移量。|
|OH_NativeXComponent_GetTouchEvent(OH_NativeXComponent* component, const void* window, OH_NativeXComponent_TouchEvent* touchEvent)|获取由XComponent触发的触摸事件。touchEvent内的具体属性值可参考[OH_NativeXComponent_TouchEvent](../reference/native-apis/_o_h___native_x_component___touch_event.md)。|
|OH_NativeXComponent_GetTouchPointToolType(OH_NativeXComponent* component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType* toolType)|获取XComponent触摸点的工具类型。|
|OH_NativeXComponent_GetTouchPointTiltX(OH_NativeXComponent* component, uint32_t pointIndex, float* tiltX)|获取XComponent触摸点处相对X轴的倾斜角度。|
|OH_NativeXComponent_GetTouchPointTiltY(OH_NativeXComponent* component, uint32_t pointIndex, float* tiltY)|获取XComponent触摸点处相对Y轴的倾斜角度。|
|OH_NativeXComponent_GetMouseEvent(OH_NativeXComponent* component, const void* window, OH_NativeXComponent_MouseEvent* mouseEvent)|获取由XComponent触发的鼠标事件。|
|OH_NativeXComponent_RegisterCallback(OH_NativeXComponent* component, OH_NativeXComponent_Callback* callback)|为此OH_NativeXComponent实例注册生命周期和触摸事件回调。|
|OH_NativeXComponent_RegisterMouseEventCallback(OH_NativeXComponent* component, OH_NativeXComponent_MouseEvent_Callback* callback)|为此OH_NativeXComponent实例注册鼠标事件回调。|
|OH_NativeXComponent_RegisterFocusEventCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))|为此OH_NativeXComponent实例注册获得焦点事件回调。|
|OH_NativeXComponent_RegisterKeyEventCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))|为此OH_NativeXComponent实例注册按键事件回调。|
|OH_NativeXComponent_RegisterBlurEventCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))|为此OH_NativeXComponent实例注册失去焦点事件回调。|
|OH_NativeXComponent_GetKeyEvent(OH_NativeXComponent* component, OH_NativeXComponent_KeyEvent\** keyEvent)|获取由XComponent触发的按键事件。|
|OH_NativeXComponent_GetKeyEventAction(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_KeyAction* action)|获取按键事件的动作。|
|OH_NativeXComponent_GetKeyEventCode(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_KeyCode* code)|获取按键事件的键码值。|
|OH_NativeXComponent_GetKeyEventSourceType(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_EventSourceType* sourceType)|获取按键事件的输入源类型。|
|OH_NativeXComponent_GetKeyEventDeviceId(OH_NativeXComponent_KeyEvent* keyEvent, int64_t* deviceId)|获取按键事件的设备ID。|
|OH_NativeXComponent_GetKeyEventTimestamp(OH_NativeXComponent_KeyEvent* keyEvent, int64_t* timestamp)|获取按键事件的时间戳。|

## 生命周期说明

开发者在ArkTS侧使用如下代码即可用XComponent组件进行利用EGL/OpenGLES渲染的开发。

```typescript
@Builder
function myComponent() {
  XComponent({ id: 'xcomponentId1', type: 'surface', libraryname: 'nativerender' })
    .onLoad((context) => {})
    .onDestroy(() => {})
}
```

### onLoad事件

触发时刻：XComponent准备好surface后触发。

参数context：其上面挂载了暴露在模块上的Native方法，使用方法类似于利用 import context from "libnativerender.so" 直接加载模块后获得的context实例。

时序：onLoad事件的触发和surface相关，其和Native侧的OnSurfaceCreated的时序如下图：

![onLoad](./figures/onLoad.png)

### onDestroy事件

触发时刻：XComponent组件被销毁时触发与一般ArkUI的组件销毁时机一致，其和Native侧的OnSurfaceDestroyed的时序如下图：

![onDestroy](./figures/onDestroy.png)

## 开发步骤
以下步骤描述了在**OpenHarmony**中如何使用`XComponent组件`调用`NAPI`接口来创建`EGL/GLES`环境，实现在主页面绘制图形，并可以改变图形的颜色。

1. **在界面中定义XComponent**。

    ```typescript
    @Entry
    @Component
    struct Index {
        @State message: string = 'Hello World'
        xComponentContext: object | undefined = undefined;
        xComponentAttrs: XComponentAttrs = {
            id: 'xcomponentId',
            type: XComponentType.SURFACE,
            libraryname: 'nativerender'
        }

        build() {
            Row() {
            // ...
            // 在xxx.ets 中定义 XComponent
            XComponent(this.xComponentAttrs)
                .focusable(true) // 可响应键盘事件
                .onLoad((xComponentContext) => {
                this.xComponentContext = xComponentContext;
                })
                .onDestroy(() => {
                console.log("onDestroy");
                })
            // ...
            }
            .height('100%')
        }
    }

    interface XComponentAttrs {
        id: string;
        type: number;
        libraryname: string;
    }
    ```

2. **Napi模块注册**，具体使用请参考[Native API在应用工程中的使用指导](napi-guidelines.md)。

    ```c++
    // 在napi_init.cpp文件中，Init方法注册接口函数，从而将封装的C++方法传递出来，供JS侧调用
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        // ...
        // 向JS侧暴露接口getContext()
        napi_property_descriptor desc[] = {
            { "getContext", nullptr, PluginManager::GetContext, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
        if (napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc) != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Init", "napi_define_properties failed");
            return nullptr;
        }
        // 方法内检查环境变量是否包含XComponent组件实例，若实例存在注册绘制相关接口
        PluginManager::GetInstance()->Export(env, exports);
        return exports;
    }
    EXTERN_C_END

    // 编写接口的描述信息，根据实际需要可以修改对应参数
    static napi_module nativerenderModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        // 入口函数
        .nm_register_func = Init,
        // 模块名称
        .nm_modname = "nativerender",
        .nm_priv = ((void *)0),
        .reserved = { 0 }
    };

    // __attribute__((constructor))修饰的方法由系统自动调用，使用NAPI接口napi_module_register()传入模块描述信息进行模块注册
    extern "C" __attribute__((constructor)) void RegisterModule(void)
    {
        napi_module_register(&nativerenderModule);
    }

    // 使用NAPI中的napi_define_properties方法，向JS侧暴露drawPattern()方法，在JS侧调用drawPattern()来绘制内容。
    void PluginRender::Export(napi_env env, napi_value exports)
    {
        // ...
        // 将接口函数注册为JS侧接口drawPattern
        napi_property_descriptor desc[] = {
            { "drawPattern", nullptr, PluginRender::NapiDrawPattern, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
        if (napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc) != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender", "Export: napi_define_properties failed");
        }
    }
    ```

3. **注册XComponent事件回调**，使用NAPI实现XComponent事件回调函数。

   (1) 定义surface创建成功，发生改变，销毁和XComponent的touch事件回调接口。

   ```c++
   // 定义一个函数OnSurfaceCreatedCB()，封装初始化环境与绘制背景
   void OnSurfaceCreatedCB(OH_NativeXComponent *component, void *window)
   {
   	// ...
   	// 获取XComponent的id，即JS侧XComponent组件构造中的id参数
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { '\0' };
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	if (OH_NativeXComponent_GetXComponentId(component, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
   			"OnSurfaceCreatedCB: Unable to get XComponent id");
   		return;
   	}
   
   	// 初始化环境与绘制背景
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	uint64_t width;
   	uint64_t height;
   	// 获取XComponent拥有的surface的大小
   	int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
   	if ((xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) && (render != nullptr)) {
   		if (render->eglCore_->EglContextInit(window, width, height)) {
   			render->eglCore_->Background();
   		}
   	}
   }
   
   // 定义一个函数OnSurfaceChangedCB()
   void OnSurfaceChangedCB(OH_NativeXComponent *component, void *window)
   {
   	// ...
   	// 获取XComponent的id
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { '\0' };
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	if (OH_NativeXComponent_GetXComponentId(component, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
   			"OnSurfaceChangedCB: Unable to get XComponent id");
   		return;
   	}
   
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	if (render != nullptr) {
   		// 封装OnSurfaceChanged方法
   		render->OnSurfaceChanged(component, window);
   	}
   }
   
   // 定义一个函数OnSurfaceDestroyedCB()，将PluginRender类内释放资源的方法Release()封装在其中
   void OnSurfaceDestroyedCB(OH_NativeXComponent *component, void *window)
   {
   	// ...
   	// 获取XComponent的id
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { '\0' };
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	if (OH_NativeXComponent_GetXComponentId(component, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
   			"OnSurfaceDestroyedCB: Unable to get XComponent id");
   		return;
   	}
   
   	std::string id(idStr);
   	// 释放资源
   	PluginRender::Release(id);
   }
   
   // 定义一个函数DispatchTouchEventCB()，响应触摸事件时触发该回调
   void DispatchTouchEventCB(OH_NativeXComponent *component, void *window)
   {
   	// ...
   	// 获取XComponent的id
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { '\0' };
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	if (OH_NativeXComponent_GetXComponentId(component, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
   			"DispatchTouchEventCB: Unable to get XComponent id");
   		return;
   	}
   
   	std::string id(idStr);
   	PluginRender *render = PluginRender::GetInstance(id);
   	if (render != nullptr) {
   		// 封装OnTouchEvent方法
   		render->OnTouchEvent(component, window);
   	}
   }
   
   // 定义一个函数DispatchMouseEventCB()，响应鼠标事件时触发该回调
   void DispatchMouseEventCB(OH_NativeXComponent *component, void *window) {
   	OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "DispatchMouseEventCB");
   	int32_t ret;
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	ret = OH_NativeXComponent_GetXComponentId(component, idStr, &idSize);
   	if (ret != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		return;
   	}
   
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	if (render) {
   		// 封装OnMouseEvent方法
   		render->OnMouseEvent(component, window);
   	}
   }
   
   // 定义一个函数DispatchHoverEventCB()，响应鼠标悬停事件时触发该回调
   void DispatchHoverEventCB(OH_NativeXComponent *component, bool isHover) {
   	OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "DispatchHoverEventCB");
   	int32_t ret;
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	ret = OH_NativeXComponent_GetXComponentId(component, idStr, &idSize);
   	if (ret != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		return;
   	}
   
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	if (render) {
   		// 封装OnHoverEvent方法
   		render->OnHoverEvent(component, isHover);
   	}
   }
   
   // 定义一个函数OnFocusEventCB()，响应获焦事件时触发该回调
   void OnFocusEventCB(OH_NativeXComponent *component, void *window) {
   	OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "OnFocusEventCB");
   	int32_t ret;
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	ret = OH_NativeXComponent_GetXComponentId(component, idStr, &idSize);
   	if (ret != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		return;
   	}
   
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	if (render) {
   		// 封装OnFocusEvent方法
   		render->OnFocusEvent(component, window);
   	}
   }
   
   // 定义一个函数OnBlurEventCB()，响应失去焦点事件时触发该回调
   void OnBlurEventCB(OH_NativeXComponent *component, void *window) {
   	OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "OnBlurEventCB");
   	int32_t ret;
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	ret = OH_NativeXComponent_GetXComponentId(component, idStr, &idSize);
   	if (ret != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		return;
   	}
   
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	if (render) {
   		// 封装OnBlurEvent方法
   		render->OnBlurEvent(component, window);
   	}
   }
   
   // 定义一个函数OnKeyEventCB()，响应按键事件时触发该回调
   void OnKeyEventCB(OH_NativeXComponent *component, void *window) {
   	OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "OnKeyEventCB");
   	int32_t ret;
   	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
   	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
   	ret = OH_NativeXComponent_GetXComponentId(component, idStr, &idSize);
   	if (ret != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   		return;
   	}
   	std::string id(idStr);
   	auto render = PluginRender::GetInstance(id);
   	if (render) {
   		// 封装OnKeyEvent方法
   		render->OnKeyEvent(component, window);
   	}
   }
   
   // 定义一个OnSurfaceChanged()方法
   void PluginRender::OnSurfaceChanged(OH_NativeXComponent* component, void* window)
   {
   	// ...
       std::string id(idStr);
       PluginRender* render = PluginRender::GetInstance(id);
       double offsetX;
       double offsetY;
       // 获取XComponent持有的surface相对窗口左上角的偏移量
       OH_NativeXComponent_GetXComponentOffset(component, window, &offsetX, &offsetY);
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "OH_NativeXComponent_GetXComponentOffset",
           "offsetX = %{public}lf, offsetY = %{public}lf", offsetX, offsetY);
       uint64_t width;
       uint64_t height;
       OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
       if (render != nullptr) {
           render->eglCore_->UpdateSize(width, height);
       }
   }
   
   // 定义一个OnTouchEvent()方法
   void PluginRender::OnTouchEvent(OH_NativeXComponent* component, void* window)
   {
       // ...
       OH_NativeXComponent_TouchEvent touchEvent;
       // 获取由XComponent触发的触摸事件
       OH_NativeXComponent_GetTouchEvent(component, window, &touchEvent);
       // 获取XComponent触摸点相对于XComponent组件左边缘的坐标x和相对于XComponent组件上边缘的坐标y
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "OnTouchEvent",
           "touch info: x = %{public}lf, y = %{public}lf", touchEvent.x, touchEvent.y);
       // 获取XComponent触摸点相对于XComponent所在应用窗口左上角的x坐标和相对于XComponent所在应用窗口左上角的y坐标
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "OnTouchEvent",
           "touch info: screenX = %{public}lf, screenY = %{public}lf", touchEvent.screenX, touchEvent.screenY);
       std::string id(idStr);
       PluginRender* render = PluginRender::GetInstance(id);
       if (render != nullptr && touchEvent.type == OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UP) {
           render->eglCore_->ChangeColor();
           hasChangeColor_ = 1;
       }
       float tiltX = 0.0f;
       float tiltY = 0.0f;
       OH_NativeXComponent_TouchPointToolType toolType =
           OH_NativeXComponent_TouchPointToolType::OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN;
       // 获取XComponent触摸点的工具类型
       OH_NativeXComponent_GetTouchPointToolType(component, 0, &toolType);
       // 获取XComponent触摸点处相对X轴的倾斜角度
       OH_NativeXComponent_GetTouchPointTiltX(component, 0, &tiltX);
       // 获取XComponent触摸点处相对Y轴的倾斜角度
       OH_NativeXComponent_GetTouchPointTiltY(component, 0, &tiltY);
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "OnTouchEvent",
           "touch info: toolType = %{public}d, tiltX = %{public}lf, tiltY = %{public}lf", toolType, tiltX, tiltY);
   }
   
   // 定义一个OnMouseEvent()方法
   void PluginRender::OnMouseEvent(OH_NativeXComponent *component, void *window) {
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "PluginRender", "OnMouseEvent");
      OH_NativeXComponent_MouseEvent mouseEvent;
      // 获取由XComponent触发的鼠标事件
      int32_t ret = OH_NativeXComponent_GetMouseEvent(component, window, &mouseEvent);
      if (ret == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
   	   OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "PluginRender", "MouseEvent Info: x = %{public}f, y = %{public}f, action = %{public}d, button = %{public}d", mouseEvent.x, mouseEvent.y, mouseEvent.action, mouseEvent.button);
      } else {
   	   OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender", "GetMouseEvent error");
      }
   }
   
   // 定义一个OnMouseEvent()方法
   void PluginRender::OnKeyEvent(OH_NativeXComponent *component, void *window) {
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "PluginRender", "OnKeyEvent");
   
      OH_NativeXComponent_KeyEvent *keyEvent = nullptr;
      // 获取由XComponent触发的按键事件。
      if (OH_NativeXComponent_GetKeyEvent(component, &keyEvent) >= 0) {
   	   OH_NativeXComponent_KeyAction action;
          // 获取按键事件的动作
   	   OH_NativeXComponent_GetKeyEventAction(keyEvent, &action);
   	   OH_NativeXComponent_KeyCode code;
          // 获取按键事件的键码值
   	   OH_NativeXComponent_GetKeyEventCode(keyEvent, &code);
   	   OH_NativeXComponent_EventSourceType sourceType;
          // 获取按键事件的输入源类型
   	   OH_NativeXComponent_GetKeyEventSourceType(keyEvent, &sourceType);
   	   int64_t deviceId;
          // 获取按键事件的设备ID
   	   OH_NativeXComponent_GetKeyEventDeviceId(keyEvent, &deviceId);
   	   int64_t timeStamp;
          // 获取按键事件的时间戳
   	   OH_NativeXComponent_GetKeyEventTimestamp(keyEvent, &timeStamp);
   	   OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "PluginRender", "KeyEvent Info: action=%{public}d, code=%{public}d, sourceType=%{public}d, deviceId=%{public}ld, timeStamp=%{public}ld", action, code, sourceType, deviceId, timeStamp);
      } else {
   	   OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender", "GetKeyEvent error");
      }
   }
   ```

   (2) 注册XComponent事件回调函数，在XComponent事件触发时调用3.1步骤中定义的方法。

    ```c++
    void PluginRender::RegisterCallback(OH_NativeXComponent *nativeXComponent) {
        // 设置组件创建事件的回调函数，组件创建时触发相关操作，初始化环境与绘制背景
        renderCallback_.OnSurfaceCreated = OnSurfaceCreatedCB;
        // 设置组件改变事件的回调函数，组件改变时触发相关操作
        renderCallback_.OnSurfaceChanged = OnSurfaceChangedCB;
        // 设置组件销毁事件的回调函数，组件销毁时触发相关操作，释放申请的资源
        renderCallback_.OnSurfaceDestroyed = OnSurfaceDestroyedCB;
        // 设置触摸事件的回调函数，在触摸事件触发时调用NAPI接口函数，从而调用原C++方法
        renderCallback_.DispatchTouchEvent = DispatchTouchEventCB;
        // 将OH_NativeXComponent_Callback注册给NativeXComponent
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &renderCallback_);
        
        // 设置鼠标事件的回调函数，在触摸事件触发时调用NAPI接口函数，从而调用原C++方法
        mouseCallback_.DispatchMouseEvent = DispatchMouseEventCB;
        // 设置鼠标悬停事件的回调函数，在触摸事件触发时调用NAPI接口函数，从而调用原C++方法
        mouseCallback_.DispatchHoverEvent = DispatchHoverEventCB;
        // 将OH_NativeXComponent_MouseEvent_Callback注册给NativeXComponent
        OH_NativeXComponent_RegisterMouseEventCallback(nativeXComponent, &mouseCallback_);
        
        // 将OnFocusEventCB方法注册给NativeXComponent
        OH_NativeXComponent_RegisterFocusEventCallback(nativeXComponent, OnFocusEventCB);
        // 将OnKeyEventCB方法注册给NativeXComponent
        OH_NativeXComponent_RegisterKeyEventCallback(nativeXComponent, OnKeyEventCB);
        // 将OnBlurEventCB方法注册给 NativeXComponent
        OH_NativeXComponent_RegisterBlurEventCallback(nativeXComponent, OnBlurEventCB);
    }
    ```

   (3) 定义NapiDrawPattern方法，暴露到JS侧的drawPattern()方法会执行该方法。

    ```c++
    napi_value PluginRender::NapiDrawPattern(napi_env env, napi_callback_info info)
    {
        // ...
        // 获取环境变量参数
        napi_value thisArg;
        if (napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr) != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender", "NapiDrawPattern: napi_get_cb_info fail");
            return nullptr;
        }
       
        // 获取环境变量中XComponent实例
        napi_value exportInstance;
        if (napi_get_named_property(env, thisArg, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance) != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender",
                "NapiDrawPattern: napi_get_named_property fail");
            return nullptr;
        }
       
        // 通过napi_unwrap接口，获取XComponent的实例指针
        OH_NativeXComponent *nativeXComponent = nullptr;
        if (napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&nativeXComponent)) != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender", "NapiDrawPattern: napi_unwrap fail");
            return nullptr;
        }
       
        // 获取XComponent实例的id
        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { '\0' };
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
        if (OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "PluginRender",
                "NapiDrawPattern: Unable to get XComponent id");
            return nullptr;
        }
       
        std::string id(idStr);
        PluginRender *render = PluginRender::GetInstance(id);
        if (render) {
            // 调用绘制方法
            render->eglCore_->Draw();
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "PluginRender", "render->eglCore_->Draw() executed");
        }
        return nullptr;
    }
    ```

4. **初始化环境**，包括初始化可用的EGLDisplay、确定可用的surface配置、创建渲染区域surface、创建并关联上下文等。

    ```c++
    void EGLCore::UpdateSize(int width, int height) 
    {
        width_ = width;
        height_ = height;
        if (width_ > 0) {
            // 计算绘制矩形宽度百分比
            width_Percent_ = FIFTY_PERCENT * height_ / width_;
        }
    }

    bool EGLCore::EglContextInit(void *window, int width, int height)
    {
        // ...
        UpdateSize(width, height);
        eglWindow_ = static_cast<EGLNativeWindowType>(window);

        // 初始化display
        eglDisplay_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (eglDisplay_ == EGL_NO_DISPLAY) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "eglGetDisplay: unable to get EGL display");
            return false;
        }

        // 初始化EGL
        EGLint majorVersion;
        EGLint minorVersion;
        if (!eglInitialize(eglDisplay_, &majorVersion, &minorVersion)) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore",
                "eglInitialize: unable to get initialize EGL display");
            return false;
        }

        // 选择配置
        const EGLint maxConfigSize = 1;
        EGLint numConfigs;
        if (!eglChooseConfig(eglDisplay_, ATTRIB_LIST, &eglConfig_, maxConfigSize, &numConfigs)) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "eglChooseConfig: unable to choose configs");
            return false;
        }

        // 创建环境
        return CreateEnvironment();
    }
    ```

    ```c++
    bool EGLCore::CreateEnvironment()
    {
        // ...
        // 创建surface
        eglSurface_ = eglCreateWindowSurface(eglDisplay_, eglConfig_, eglWindow_, NULL);

        // ...
        // 创建context
        eglContext_ = eglCreateContext(eglDisplay_, eglConfig_, EGL_NO_CONTEXT, CONTEXT_ATTRIBS);
        if (!eglMakeCurrent(eglDisplay_, eglSurface_, eglSurface_, eglContext_)) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "eglMakeCurrent failed");
            return false;
        }

        // 创建program
        program_ = CreateProgram(VERTEX_SHADER, FRAGMENT_SHADER);
        if (program_ == PROGRAM_ERROR) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "CreateProgram: unable to create program");
            return false;
        }
        return true;
    }
    ```

5. **渲染功能实现**。

   (1) 绘制背景。

    ```c++
    // 绘制背景颜色 #f4f4f4
    const GLfloat BACKGROUND_COLOR[] = { 244.0f / 255, 244.0f / 255, 244.0f / 255, 1.0f };

    // 绘制背景顶点
    const GLfloat BACKGROUND_RECTANGLE_VERTICES[] = {
        -1.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, -1.0f,
        -1.0f, -1.0f
    };
    ```

    ```c++
    // 绘制背景颜色
    void EGLCore::Background()
    {
        GLint position = PrepareDraw();
        if (position == POSITION_ERROR) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Background get position failed");
            return;
        }

        if (!ExecuteDraw(position, BACKGROUND_COLOR, BACKGROUND_RECTANGLE_VERTICES,
            sizeof(BACKGROUND_RECTANGLE_VERTICES))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Background execute draw failed");
            return;
        }

        if (!FinishDraw()) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Background FinishDraw failed");
            return;
        }
    }

    // 绘前准备，获取position，创建成功时position值从0开始
    GLint EGLCore::PrepareDraw()
    {
        if ((eglDisplay_ == nullptr) || (eglSurface_ == nullptr) || (eglContext_ == nullptr) ||
            (!eglMakeCurrent(eglDisplay_, eglSurface_, eglSurface_, eglContext_))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "PrepareDraw: param error");
            return POSITION_ERROR;
        }

        glViewport(DEFAULT_X_POSITION, DEFAULT_Y_POSITION, width_, height_);
        glClearColor(GL_RED_DEFAULT, GL_GREEN_DEFAULT, GL_BLUE_DEFAULT, GL_ALPHA_DEFAULT);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program_);

        return glGetAttribLocation(program_, POSITION_NAME);
    }

    // 依据传入参数在指定区域绘制指定颜色
    bool EGLCore::ExecuteDraw(GLint position, const GLfloat *color, const GLfloat shapeVertices[],
        unsigned long vertSize)
    {
        if ((position > 0) || (color == nullptr) || (vertSize / sizeof(shapeVertices[0]) != SHAPE_VERTICES_SIZE)) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "ExecuteDraw: param error");
            return false;
        }

        glVertexAttribPointer(position, POINTER_SIZE, GL_FLOAT, GL_FALSE, 0, shapeVertices);
        glEnableVertexAttribArray(position);
        glVertexAttrib4fv(1, color);
        glDrawArrays(GL_TRIANGLE_FAN, 0, TRIANGLE_FAN_SIZE);
        glDisableVertexAttribArray(position);

        return true;
    }

    // 结束绘制操作
    bool EGLCore::FinishDraw()
    {
        // 强制刷新缓冲
        glFlush();
        glFinish();
        return eglSwapBuffers(eglDisplay_, eglSurface_);
    }
    ```

   (2) 绘制图形。

    ```c++
    void EGLCore::Draw()
    {
        flag_ = false;
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "EGLCore", "Draw");
        GLint position = PrepareDraw();
        if (position == POSITION_ERROR) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw get position failed");
            return;
        }

        // 绘制背景
        if (!ExecuteDraw(position, BACKGROUND_COLOR, BACKGROUND_RECTANGLE_VERTICES,
            sizeof(BACKGROUND_RECTANGLE_VERTICES))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw execute draw background failed");
            return;
        }
        
        // 将五角星分为五个四边形，计算其中一个四边形的四个顶点
        GLfloat rotateX = 0;
        GLfloat rotateY = FIFTY_PERCENT * height_;
        GLfloat centerX = 0;
        GLfloat centerY = -rotateY * (M_PI / 180 * 54) * (M_PI / 180 * 18);
        GLfloat leftX = -rotateY * (M_PI / 180 * 18);
        GLfloat leftY = 0;
        GLfloat rightX = rotateY * (M_PI / 180 * 18);
        GLfloat rightY = 0;

        // 确定绘制四边形的顶点，使用绘制区域的百分比表示
        const GLfloat shapeVertices[] = {
            centerX / width_, centerY / height_,
            leftX / width_, leftY / height_,
            rotateX / width_, rotateY / height_,
            rightX / width_, rightY / height_
        };
        
        if (!ExecuteDrawStar(position, DRAW_COLOR, shapeVertices, sizeof(shapeVertices))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw execute draw star failed");
            return;
        }
        
        GLfloat rad = M_PI / 180 * 72;
        for (int i = 0; i < 4; ++i) 
        {
            // 旋转得其他四个四边形的顶点
            rotate2d(centerX, centerY, &rotateX, &rotateY,rad);
            rotate2d(centerX, centerY, &leftX, &leftY,rad);
            rotate2d(centerX, centerY, &rightX, &rightY,rad);
            
            // 确定绘制四边形的顶点，使用绘制区域的百分比表示
            const GLfloat shapeVertices[] = {
                    centerX / width_, centerY / height_,
                    leftX / width_, leftY / height_,
                    rotateX / width_, rotateY / height_,
                    rightX / width_, rightY / height_
                };
            
            // 绘制图形
            if (!ExecuteDrawStar(position, DRAW_COLOR, shapeVertices, sizeof(shapeVertices))) {
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw execute draw star failed");
                return;
            }
        }

        // 结束绘制
        if (!FinishDraw()) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw FinishDraw failed");
            return;
        }

        flag_ = true;
    }
    ```

   (3) 改变颜色，重新画一个大小相同颜色不同的图形，与原图形替换，达到改变颜色的效果。

    ```c++
    void EGLCore::ChangeColor()
    {
        if (!flag_) {
            return;
        }
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "EGLCore", "ChangeColor");
        GLint position = PrepareDraw();
        if (position == POSITION_ERROR) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "ChangeColor get position failed");
            return;
        }
    
        // 绘制背景
        if (!ExecuteDraw(position, BACKGROUND_COLOR, BACKGROUND_RECTANGLE_VERTICES,
            sizeof(BACKGROUND_RECTANGLE_VERTICES))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "ChangeColor execute draw background failed");
            return;
        }
    
        // 确定绘制四边形的顶点，使用绘制区域的百分比表示
        GLfloat rotateX = 0;
        GLfloat rotateY = FIFTY_PERCENT * height_;
        GLfloat centerX = 0;
        GLfloat centerY = -rotateY * (M_PI / 180 * 54) * (M_PI / 180 * 18);
        GLfloat leftX = -rotateY * (M_PI / 180 * 18);
        GLfloat leftY = 0;
        GLfloat rightX = rotateY * (M_PI / 180 * 18);
        GLfloat rightY = 0;
    
        // 确定绘制四边形的顶点，使用绘制区域的百分比表示
        const GLfloat shapeVertices[] = {
            centerX / width_, centerY / height_,
            leftX / width_, leftY / height_,
            rotateX / width_, rotateY / height_,
            rightX / width_, rightY / height_
        };
        
        // 使用新的颜色绘制
        if (!ExecuteDrawStar2(position, CHANGE_COLOR, shapeVertices, sizeof(shapeVertices))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw execute draw star failed");
            return;
        }
    
        GLfloat rad = M_PI / 180 * 72;
        for (int i = 0; i < 4; ++i)
        {
            // 旋转得其他四个四边形的顶点
            rotate2d(centerX, centerY, &rotateX, &rotateY,rad);
            rotate2d(centerX, centerY, &leftX, &leftY,rad);
            rotate2d(centerX, centerY, &rightX, &rightY,rad);
            
            // 确定绘制四边形的顶点，使用绘制区域的百分比表示
            const GLfloat shapeVertices[] = {
                    centerX / width_, centerY / height_,
                    leftX / width_, leftY / height_,
                    rotateX / width_, rotateY / height_,
                    rightX / width_, rightY / height_
                };
    
            // 使用新的颜色绘制
            if (!ExecuteDrawStar2(position, CHANGE_COLOR, shapeVertices, sizeof(shapeVertices))) {
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Draw execute draw star failed");
                return;
            }
        }
    
        // 结束绘制
        if (!FinishDraw()) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "ChangeColor FinishDraw failed");
        }
    }
    ```

6. **释放相关资源**。

   (1) EGLCore类下创建Release()方法，释放初始化环境时申请的资源，包含窗口display、渲染区域surface、环境上下文context等。

    ```c++
    void EGLCore::Release()
    {
        // 释放surface
        if ((eglDisplay_ == nullptr) || (eglSurface_ == nullptr) || (!eglDestroySurface(eglDisplay_, eglSurface_))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Release eglDestroySurface failed");
        }
        //     释放context
        if ((eglDisplay_ == nullptr) || (eglContext_ == nullptr) || (!eglDestroyContext(eglDisplay_, eglContext_))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Release eglDestroyContext failed");
        }
        //     释放display
        if ((eglDisplay_ == nullptr) || (!eglTerminate(eglDisplay_))) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "EGLCore", "Release eglTerminate failed");
        }
    }
    ```

   (2) PluginRender类添加Release()方法，释放EGLCore实例及PluginRender实例。

    ```c++
    void PluginRender::Release(std::string &id)
    {
        PluginRender *render = PluginRender::GetInstance(id);
        if (render != nullptr) {
            render->eglCore_->Release();
            delete render->eglCore_;
            render->eglCore_ = nullptr;
            delete render;
            render = nullptr;
            instance_.erase(instance_.find(id));
        }
    }
    ```

7. **CMakeLists**，使用CMake工具链将C++源代码编译成动态链接库文件。

    ```CMake
    # 设置CMake最小版本
    cmake_minimum_required(VERSION 3.4.1)
    # 项目名称
    project(XComponent)
    
    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    add_definitions(-DOHOS_PLATFORM)
    # 设置头文件搜索目录
    include_directories(
        ${NATIVERENDER_ROOT_PATH}
        ${NATIVERENDER_ROOT_PATH}/include
    )
    # 添加名为nativerender的动态库，库文件名为libnativerender.so，添加cpp文件
    add_library(nativerender SHARED
        render/egl_core.cpp
        render/plugin_render.cpp
        manager/plugin_manager.cpp
        napi_init.cpp
    )
    
    find_library(
        EGL-lib
        EGL
    )
    
    find_library(
        GLES-lib
        GLESv3
    )
    
    find_library(
        hilog-lib
        hilog_ndk.z
    )
    
    find_library(
        libace-lib
        ace_ndk.z
    )
    
    find_library(
        libnapi-lib
        ace_napi.z
    )
    
    find_library(
        libuv-lib
        uv
    )
    # 添加构建需要链接的库
    target_link_libraries(nativerender PUBLIC
        ${EGL-lib} ${GLES-lib} ${hilog-lib} ${libace-lib} ${libnapi-lib} ${libuv-lib})
    ```

##  相关实例

针对Native XComponent的使用，有以下相关实例可供参考：

- [Native XComponent（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkXComponent)

- [OpenGL三棱椎（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkOpenGL)
