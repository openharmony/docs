| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFdSync(path: string): RawFileDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：closeRawFdSync(path: string): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileListSync(path: string): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileContentSync(path: string): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentSync(resId: number, density?: number): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentSync(resource: Resource, density?: number): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64Sync(resId: number, density?: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64Sync(resource: Resource, density?: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValueSync(resId: number, num: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValueSync(resource: Resource, num: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValueSync(resId: number): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValueSync(resource: Resource): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringByNameSync(resName: string, num: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaByNameSync(resName: string, density?: number): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaBase64ByNameSync(resName: string, density?: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayByNameSync(resName: string): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getConfigurationSync(): Configuration;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getDeviceCapabilitySync(): DeviceCapability;|@ohos.resourceManager.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：params?: any[];|resource.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：type?: number;|resource.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource, ...args: Array\<string \| number>): string;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource, ...args: Array\<string \| number>): string;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getDrawableDescriptor(resource: Resource, density?: number): DrawableDescriptor;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getDrawableDescriptor(resource: Resource, density?: number): DrawableDescriptor;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|type有变化|类名：Resource;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：Resource;<br>方法or属性：bundleName: string;<br>新版本信息：string|resource.d.ts|
|type有变化|类名：Resource;<br>方法or属性：moduleName: string;<br>旧版本信息：|类名：Resource;<br>方法or属性：moduleName: string;<br>新版本信息：string|resource.d.ts|
|type有变化|类名：Resource;<br>方法or属性：id: number;<br>旧版本信息：|类名：Resource;<br>方法or属性：id: number;<br>新版本信息：number|resource.d.ts|
