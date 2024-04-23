| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：sourcefile;<br>方法or属性：export declare function markModuleCollectable(namespace: Object): void;|global.d.ts|
|函数有变化|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|类名：URLSearchParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: URLSearchParams) => void, thisArg?: Object): void;|@ohos.url.d.ts|
|函数有变化|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void;|类名：URLParams;<br>方法or属性：forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void;|@ohos.url.d.ts|
