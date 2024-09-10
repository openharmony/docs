# Media Library Kit子系统Changelog

## cl.medialibrary.1 @ohos.file.photoAccessHelper相册资产操作行为相关接口变更

**访问级别**

公开接口&系统接口

**变更原因**

媒体库支持基于资产-相册一对一管理的方案，因修改相册资产对应关系为1对1，导致相册相关接口行为发生变更。

**变更影响**

该变更为不兼容变更。
无对外接口参数或返回值变更，仅因一对一方案部分接口内部实现差异导致XTS fail。

1、向相册中添加资产addAssets：
差异点：原行为添加的是查询得到的资产，新行为添加该资产的复制体，对外调用无变更，因复制资产与原资产内容和元数据一致，相册表现无差异。

2、从相册中移除资产removeAssets：
差异点：原行为删除相册与资产的映射关系，新行为删除对应资产到回收站。

3、设置相册名称setAlbumName&commitModify
原行为：直接修改该相册的album_name。
新行为：删除该相册，并新建一条元数据相同的相册，命名为新名称。

4、注册对指定uri的监听，使用callback方式返回异步结果registerChange：
原行为：注册查询出来的Asset uri监听，添加删除修改等行为通知查询出来的Asset Uri。
新行为：由于Add和Remove等操作变更，操作的对象均为复制体，故通知时通知复制体uri变更。

SystemAPI：

1、删除相册，使用Promise方式返回结果。删除相册前需先确保相册存在，只能删除用户相册deleteAlbums：
原行为：删除相册不删除相册内资产。
新行为：由于资产相册关系一对一，仅删除相册不处理资产的话会产生无归属资产导致不同版本同步异常。因此需要联通相册下的资产一并删除。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.43开始

**变更的接口/组件**

1、 向相册中添加资产：
```
addAssets(assets: Array<PhotoAsset>): void
```

2、 从相册中移除资产：
```
removeAssets(assets: Array<PhotoAsset>): void
```

3、 设置相册名称：
```
setAlbumName(name: string):void
commitModify(callback: AsyncCallback<void>): void
```

4、 注册对指定uri的监听，使用callback方式返回异步结果：
```
registerChange(uri: string, forChildUris: boolean, callback: Callback<ChangeData>): void
```

SystemAPI:

1、 删除相册，使用Promise方式返回结果。删除相册前需先确保相册存在，只能删除用户相册。
```
static deleteAlbums(context: Context, albums: Array<Album>): Promise<void>
```


**适配指导**

无对外接口参数或返回值变更，仅因一对一方案部分接口内部实现差异导致XTS fail。