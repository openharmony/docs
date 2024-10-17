# Media Library Kit子系统Changelog

## cl.medialibrary.1 @ohos.file.photoAccessHelper相册添加资产、移除资产等操作转变为复制添加资产、删除资产到回收站

**访问级别**

公开接口

**变更原因**

为了使资产的保存逻辑更清晰，修改了媒体库对于“资产-相册”的对应关系。修改前一个图片/视频资源可以通过关系映射存在于多个逻辑相册中，修改后一张照片仅能归属一个实体相册。

**变更影响**

该变更为不兼容变更。

1. 向相册中添加资产addAssets：

    变更前：添加的是查询得到的资产

    变更后：添加该资产的复制体

2. 从相册中移除资产removeAssets：

    变更前：删除相册与资产的映射关系

    变更后：删除对应资产到回收站

3. 设置相册名称setAlbumName&commitModify：

    变更前：直接修改该相册的album_name。
  
    变更后：删除该相册，并新建一条元数据相同的相册，命名为新名称。

4. 注册对指定uri的监听，使用callback方式返回异步结果registerChange：

    变更前：注册查询出来的Asset uri监听，添加删除修改等行为通知查询出来的Asset Uri。

    变更后：由于Add和Remove等操作变更，操作的对象均为复制体，故通知时通知复制体uri变更。


**起始API Level**

API 10和API 11

**变更发生版本**

从OpenHarmony 5.0.0.43开始

**变更的接口/组件**

1. 向相册中添加资产：addAssets(assets: Array\<PhotoAsset>): void
2. 从相册中移除资产：removeAssets(assets: Array\<PhotoAsset>): void
3. 设置相册名称：

   setAlbumName(name: string):void，
   commitModify(callback: AsyncCallback\<void>): void

4. 注册对指定uri的监听：registerChange(uri: string, forChildUris: boolean, callback: Callback\<ChangeData>): void

**适配指导**

接口使用方式没有变化，开发者在调用接口过程中无需额外适配，但接口行为发生变化，开发者应当注意其关联变化并适当调整。

1. addAssets相册添加照片后，并非将原照片加入到当前相册，而是将复制体添加到相册内。后续若想操作资产，应操作当前相册内的复制体资产。

2. removeAssets需注意移除资产会将其删除到回收站。

3. deleteAlbums需注意删除相册会将相册内资产一并删除到回收站。

4. 调用setAlbumName和commitModify修改相册名称，会将原相册删除再新建一个新的改名相册。
后续若想继续操作相册，应操作新建的相册。接口行为变更后，在调用setAlbumName和commitModify修改相册名后，需使用[getAlbums](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2)获取新命名的相册进行后续操作。

5. registerChange需注意，在调用addAssets接口时会收到复制体资产添加的新增通知，在调用removeAssets和deleteAlbums时会收到
相册内资产的删除通知，在调用setAlbumName和commitModify时，会收到相册更新通知。