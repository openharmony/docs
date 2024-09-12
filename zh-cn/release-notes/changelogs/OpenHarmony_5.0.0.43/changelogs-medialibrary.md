# Media Library Kit子系统Changelog

## cl.medialibrary.1 @ohos.file.photoAccessHelper相册资产操作行为相关接口变更

**访问级别**

公开接口

**变更原因**

1、媒体库支持基于资产-相册一对一管理的方案，需求目标是实现单双框架相册显示一致，双框架每条媒体资产均存放在公共路径文件夹下，文件夹就是资产的相册，一张图片对应一个相册。
变更前单框架相册资产关系采用映射表维护，一张图片可以对应多个相册。单双框架维护关系不一致，无法直接端云互通。

2、方案变更后，需要修改相册和资产的对应关系，将数据库中添加映射关系转为每条数据添加所属相册值。原本一张照片可以通过关系映射存在于多个逻辑相册，变更后一张照片仅能归属一个实体相册。

**变更影响**

该变更为不兼容变更。

无对外接口参数或返回值变更，仅因一对一方案部分接口内部实现差异导致XTS fail。

1、向相册中添加资产addAssets：

差异点：原行为添加的是查询得到的资产，新行为添加该资产的复制体，对外调用无变更，因复制资产与原资产内容和元数据一致，相册表现无差异。

2、从相册中移除资产removeAssets：

差异点：原行为删除相册与资产的映射关系，新行为删除对应资产到回收站。

3、设置相册名称setAlbumName&commitModify：

差异点：

原行为：直接修改该相册的album_name。

新行为：删除该相册，并新建一条元数据相同的相册，命名为新名称。

4、注册对指定uri的监听，使用callback方式返回异步结果registerChange：

差异点：

原行为：注册查询出来的Asset uri监听，添加删除修改等行为通知查询出来的Asset Uri。

新行为：由于Add和Remove等操作变更，操作的对象均为复制体，故通知时通知复制体uri变更。


**起始API Level**

API 10和API 11

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

**适配指导**

1、addAssets接口使用方式无变更，开发者使用无需额外适配，但接口行为上需注意相册添加照片后，并非将原照片加入到当前相册，而是将复制体添加到相册内。
后续若想操作资产，应操作当前相册内的复制体资产。

2、removeAssets接口使用方式无变更，开发者使用无需额外适配，但接口行为上需注意移除资产会将其删除到回收站。

3、deleteAlbums接口使用方式无变更，开发者使用无需额外适配，但接口行为上需注意删除相册会将相册内资产一并删除到回收站。

4、setAlbumName和commitModify接口使用方式无变更，需要注意相册改名是将原相册删除再新建一个新的改名相册。后续若想继续操作相册，应操作新建的相册。
接口行为变更后，在调用setAlbumName和commitModify修改相册名后，需使用getAlbums()获取新命名的相册进行后续操作。
具体参考https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2

5、registerChange接口使用无变更，开发者使用无需额外适配，但接口行为上需注意，在调用addAssets接口时会收到复制体资产添加的新增通知，在调用removeAssets和deleteAlbums时会收到
相册内资产的删除通知，在调用setAlbumName和commitModify时，会收到相册更新通知。