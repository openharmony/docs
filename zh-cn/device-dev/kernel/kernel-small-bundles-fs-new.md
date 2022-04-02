# 适配新的文件系统


## 基本概念

所谓对接VFS层，其实就是指实现VFS层定义的若干接口函数，可根据文件系统的特点和需要适配其中部分接口。一般情况下，支持文件读写，最小的文件系统适配看起来是这样的：

  
```
struct MountOps g_yourFsMountOps = {
    .Mount = YourMountMethod,
};

struct file_operations_vfs g_yourFsFileOps = {
  .read = YourReadMethod,
  .write = YourWriteMethod,
}

struct VnodeOps g_yourFsVnodeOps = {
    .Create = YourCreateMethod;
    .Lookup = YourLookupMethod;
    .Reclaim = YourReclaimMethod;
};

FSMAP_ENTRY(yourfs_fsmap, "your fs name", g_yourFsMountOps, TRUE, TRUE);  // 注册文件系统
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 1. open和close接口不是必须要实现的接口，因为这两个接口是对文件的操作，对下层的文件系统一般是不感知的，只有当要适配的文件系统需要在open和close时做一些特别的操作时，才需要实现。
> 
> 2. 适配文件系统，对基础知识的要求较高，适配者需要对要适配的文件系统的原理和实现具有深刻的理解，本节中不会事无巨细地介绍相关的基础知识，如果您在适配的过程中遇到疑问，建议参考kernel/liteos_a/fs目录下已经适配好的文件系统的代码，可能就会豁然开朗。


## 适配Mount接口

Mount是文件系统第一个被调用的接口，该接口一般会读取驱动的参数，根据配置对文件系统的进行初始化，最后生成文件系统的root节点。Mount接口的定义如下：

  
```
int (*Mount)(struct Mount *mount, struct Vnode *blkDriver, const void *data);
```

其中，第一个参数struct Mount \*mount是Mount点的信息，适配时需要填写的是下面的变量：

  
```
struct Mount {
    const struct MountOps *ops;        /* Mount相关的函数钩子 */
    struct Vnode *vnodeCovered;        /* Mount之后的文件系统root节点 */
    void *data;                        /* Mount点的私有数据 */
};
```

第二个参数struct Vnode \*blkDriver是驱动节点，可以通过这个节点访问驱动。

第三个参数const void \*data是mount命令传入的数据，可以根据文件系统的需要处理。

  下面以JFFS2为例，详细看一下mount接口是如何适配的：
  
```
int VfsJffs2Bind(struct Mount *mnt, struct Vnode *blkDriver, const void *data)
{
    int ret;
    int partNo;
    mtd_partition *p = NULL;
    struct MtdDev *mtd = NULL;
    struct Vnode *pv = NULL;
    struct jffs2_inode *rootNode = NULL;

    LOS_MuxLock(&g_jffs2FsLock, (uint32_t)JFFS2_WAITING_FOREVER);

    /* 首先是从驱动节点中获取文件系统需要的信息，例如jffs2读取的是分区的编号 */
    p = (mtd_partition *)((struct drv_data *)blkDriver->data)->priv;
    mtd = (struct MtdDev *)(p->mtd_info);

    if (mtd == NULL || mtd->type != MTD_NORFLASH) {
        LOS_MuxUnlock(&g_jffs2FsLock);
        return -EINVAL;
    }

    partNo = p->patitionnum;

    /* 然后生成一个文件系统的根Vnode，这里注意不要搞混rootNode和根Vnode，rootNode类型是inode，是jffs2内部维护的私有数据，而Vnode是VFS的概念，是通用的文件节点，
       这一步实际上就是把文件系统内部的私有信息保存到Vnode中，这样就可以通过Vnode直接找到文件系统中的对应文件。
     */
    ret = jffs2_mount(partNo, &rootNode);
    if (ret != 0) {
        LOS_MuxUnlock(&g_jffs2FsLock);
        return ret;
    }

    ret = VnodeAlloc(&g_jffs2Vops, &pv);
    if (ret != 0) {
        LOS_MuxUnlock(&g_jffs2FsLock);
        goto ERROR_WITH_VNODE;
    }

    /* 下面这段填写的是关于这个Vnode对应文件的相关信息，uid\gid\mode这部分信息，有的文件系统可能不支持，可以不填 */
    pv->type = VNODE_TYPE_DIR;
    pv->data = (void *)rootNode;
    pv->originMount = mnt;
    pv->fop = &g_jffs2Fops;
    mnt->data = p;
    mnt->vnodeCovered = pv;
    pv->uid = rootNode->i_uid;
    pv->gid = rootNode->i_gid;
    pv->mode = rootNode->i_mode;

    /* 这里的HashInsert是为了防止重复生成已经生成过的Vnode， 第二个参数一般会选择本文件系统内可以唯一确定某一个文件的信息，例如这里是jffs2内部inode的地址 */
    (void)VfsHashInsert(pv, rootNode->i_ino);

    g_jffs2PartList[partNo] = blkDriver;

    LOS_MuxUnlock(&g_jffs2FsLock);

    return 0;
ERROR_WITH_VNODE:
    return ret;
}
...
...
const struct MountOps jffs_operations = {
    .Mount = VfsJffs2Bind,
    ...
    ...
};
```

总结：

1. 首先从驱动节点中获取需要的私有信息。

2. 根据私有信息，生成文件系统的根节点。


## 适配Lookup接口

Lookup是查找文件的接口，它的函数原型是：

  
```
int (*Lookup)(struct Vnode *parent, const char *name, int len, struct Vnode **vnode);
```

很好理解，就是从父节点parent开始，根据文件名name和文件名长度len，查找到对应的vnode返回给上层。

这个接口适配起来思路很清晰，给了父节点的信息和文件名，实现从父目录中查询名字为name的文件这个功能，同样以JFFS2为例：

  
```
int VfsJffs2Lookup(struct Vnode *parentVnode, const char *path, int len, struct Vnode **ppVnode)
{
    int ret;
    struct Vnode *newVnode = NULL;
    struct jffs2_inode *node = NULL;
    struct jffs2_inode *parentNode = NULL;

    LOS_MuxLock(&g_jffs2FsLock, (uint32_t)JFFS2_WAITING_FOREVER);

    /* 首先从private data中提取父节点的信息 */
    parentNode = (struct jffs2_inode *)parentVnode->data;

    /* 然后查询得到目标节点的信息，注意这里调用的jffs2_lookup是jffs2本身的查询函数 */
    node = jffs2_lookup(parentNode, (const unsigned char *)path, len);
    if (!node) {
        LOS_MuxUnlock(&g_jffs2FsLock);
        return -ENOENT;
    }

    /* 接着先校验一下查找到的目标是否已经有现成的vnode了，这里对应之前提到的VfsHashInsert */
    (void)VfsHashGet(parentVnode->originMount, node->i_ino, &newVnode, NULL, NULL);
    LOS_MuxUnlock(&g_jffs2FsLock);
    if (newVnode) {
        newVnode->parent = parentVnode;
        *ppVnode = newVnode;
        return 0;
    }

    /* 如果vnode不存在，就新生成一个vnode，并填写相关信息 */
    ret = VnodeAlloc(&g_jffs2Vops, &newVnode);
    if (ret != 0) {
        PRINT_ERR("%s-%d, ret: %x\n", __FUNCTION__, __LINE__, ret);
        (void)jffs2_iput(node);
        LOS_MuxUnlock(&g_jffs2FsLock);
        return ret;
    }

    Jffs2SetVtype(node, newVnode);
    newVnode->fop = parentVnode->fop;
    newVnode->data = node;
    newVnode->parent = parentVnode;
    newVnode->originMount = parentVnode->originMount;
    newVnode->uid = node->i_uid;
    newVnode->gid = node->i_gid;
    newVnode->mode = node->i_mode;
    
    /* 同时不要忘记将新生成的vnode插入hashtable中 */
    (void)VfsHashInsert(newVnode, node->i_ino);

    *ppVnode = newVnode;

    LOS_MuxUnlock(&g_jffs2FsLock);
    return 0;
}
```

总结：

1. 从父节点获取私有数据；

2. 根据私有信息查询到目标文件的私有数据；

3. 通过目标文件的私有数据生成目标Vnode。


## 适配总结和注意事项

通过上面两个接口的适配，其实可以发现一个规律，不管是什么接口，基本都遵循下面的适配步骤：

1. 通过入参的vnode获取文件系统所需的私有数据。

2. 使用私有数据完成接口的功能。

3. 将结果包装成vnode或接口要求的其他返回格式，返回给上层。

核心的逻辑其实在使用私有数据完成接口的功能，这些接口都是些文件系统的通用功能，文件系统在移植前本身应该都有相应实现，所以关键是归纳总结出文件系统所需的私有数据是什么，将其存储在vnode中，供之后使用。一般情况下，私有数据的内容是可以唯一定位到文件在存储介质上位置的信息，大部分文件系统本身都会有类似数据结构可以直接使用，比如JFFS2的inode数据结构。

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 1. 访问文件时，不一定会调用文件系统中的Lookup接口，仅在上层的路径缓存失效时才会调用到。
> 
> 2. 通过VfsHashGet找到了已经存在的Vnode，不要直接将其作为结果返回，其储存的信息可能已经失效，请更新相应字段后再返回。
> 
> 3. Vnode会根据内存占用在后台自动释放，需要持久保存的信息，不要只保存在Vnode中。
> 
> 4. Reclaim接口在Vnode释放时会自动调用，请在这个接口中释放私有数据中的资源。
