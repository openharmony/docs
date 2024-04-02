| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：agent;<br>方法or属性：function search(callback: AsyncCallback\<Array\<string>>): void;|@ohos.request.d.ts|
|type有变化|类名：Config;<br>方法or属性：data?: string \| Array\<FormItem>;<br>旧版本信息：?string \| Array\<FormItem>|类名：Config;<br>方法or属性：data?: string \| Array\<FormItem>;<br>新版本信息：?(string \| Array\<FormItem>)|@ohos.request.d.ts|
|type有变化|类名：TaskInfo;<br>方法or属性：readonly data?: string \| Array\<FormItem>;<br>旧版本信息：?string \| Array\<FormItem>|类名：TaskInfo;<br>方法or属性：readonly data?: string \| Array\<FormItem>;<br>新版本信息：?(string \| Array\<FormItem>)|@ohos.request.d.ts|
|函数有变化|类名：agent;<br>方法or属性：function search(filter: Filter): Promise\<Array\<string>>;|类名：agent;<br>方法or属性：function search(filter?: Filter): Promise\<Array\<string>>;|@ohos.request.d.ts|
