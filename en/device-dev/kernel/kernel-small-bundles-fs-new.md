# File System Adaptation


## Basic Concepts<a name="section19480121811422"></a>

The purpose of interconnecting with the VFS layer is to implement API functions defined by the VFS layer. You can adapt some APIs based on the file system features and service requirements. Basically, file read and write must be supported. The minimum file system adaptation is as follows:

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

FSMAP_ENTRY(yourfs_fsmap, "your fs name", g_yourFsMountOps, TRUE, TRUE); // Register the file system.
```

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>1.  The  **open**  and  **close**  APIs are not necessarily implemented because they are used to operate files and are imperceptible to the underlying file system. You need to implement them only when special operations need to be performed during the open and close operations on the file system.
>2.  Basic file system knowledge is required for file system adaptation. You need to have a deep understanding of the principles and implementation of the target file system. This section does not include the file system basics in detail. If you have any questions during the adaptation process, refer to the code in the  **kernel/liteos\_a/fs**  directory.

## Adapting the Mount API<a name="section147051940104212"></a>

**Mount**  is the first API called by the file system. This API reads the driver parameters, initializes the file system based on the configuration, and generates the root node of the file system. The  **Mount**  API is defined as follows:

```
int (*Mount)(struct Mount *mount, struct Vnode *blkDriver, const void *data);
```

The parameter  **struct Mount \*mount**  specifies information about the mount point. The following variables need to be set during adaptation:

```
struct Mount {
    const struct MountOps *ops;        /* Mount-related function hooks */
    struct Vnode *vnodeCovered;        /* root node of the file system generated after the mount*/
    void *data;                        /* Private data of the mount point*/
};
```

The parameter  **struct Vnode \*blkDriver**  specifies the driver node, which can be used to access the driver.

The parameter  **const void \*data**  specifies the data passed by the  **mount**  command and can be processed according to the requirements of the file system.

The following uses JFFS2 as an example to describe how to adapt the  **mount**  API:

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

    /* Obtain information required by the file system from the driver node, for example, the partition ID for JFFS2. */
    p = (mtd_partition *)((struct drv_data *)blkDriver->data)->priv;
    mtd = (struct MtdDev *)(p->mtd_info);

    if (mtd == NULL || mtd->type != MTD_NORFLASH) {
        LOS_MuxUnlock(&g_jffs2FsLock);
        return -EINVAL;
    }

    partNo = p->patitionnum;

    /* Generate a root Vnode for the file system. Do not mix rootNode and root Vnode. The rootNode type is inode, which is the private data maintained in JFFS2. Vnode is a common file node of VFS.
       This step saves the private information in the file system to the Vnode. As a result, you can directly find the corresponding file in the file system through the Vnode.
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

    /* The following enters information about the file corresponding to the Vnode. Some file systems may not support uid, gid, and mode, which can be skipped.*/
    pv->type = VNODE_TYPE_DIR;
    pv->data = (void *)rootNode;
    pv->originMount = mnt;
    pv->fop = &g_jffs2Fops;
    mnt->data = p;
    mnt->vnodeCovered = pv;
    pv->uid = rootNode->i_uid;
    pv->gid = rootNode->i_gid;
    pv->mode = rootNode->i_mode;

    /* HashInsert is used to prevent repeated generation of Vnodes. The second parameter is generally set to the unique file identifier in the file system, for example, the inode address in JFFS2. */
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

Summary:

1.  Obtain the required private information from the driver node.
2.  Generate the root node of the file system based on the private information.

## Adapting the  **Lookup**  API<a name="section11930181394317"></a>

**Lookup**  is used to search for files. The function prototype of  **Lookup**  is as follows:

```
int (*Lookup)(struct Vnode *parent, const char *name, int len, struct Vnode **vnode);
```

This function searches for the Vnode from the parent node based on the file name \(**name**\) and file name length \(**len**\) and returns the Vnode to the upper layer.

You need to specify the parent node information and file name to implement search for the file of the specified name under the parent directory. The following uses JFFS2 as an example:

```
int VfsJffs2Lookup(struct Vnode *parentVnode, const char *path, int len, struct Vnode **ppVnode)
{
    int ret;
    struct Vnode *newVnode = NULL;
    struct jffs2_inode *node = NULL;
    struct jffs2_inode *parentNode = NULL;

    LOS_MuxLock(&g_jffs2FsLock, (uint32_t)JFFS2_WAITING_FOREVER);

    /* Obtain information about the parent node from the private data.*/
    parentNode = (struct jffs2_inode *)parentVnode->data;

    /* Obtain information about the target node. Note that the jffs2_lookup function called is a function of JFFS2. */
    node = jffs2_lookup(parentNode, (const unsigned char *)path, len);
    if (!node) {
        LOS_MuxUnlock(&g_jffs2FsLock);
        return -ENOENT;
    }

    /* Check whether the located target has an existing Vnode, which corresponds to VfsHashInsert mentioned earlier. */
    (void)VfsHashGet(parentVnode->originMount, node->i_ino, &newVnode, NULL, NULL);
    LOS_MuxUnlock(&g_jffs2FsLock);
    if (newVnode) {
        newVnode->parent = parentVnode;
        *ppVnode = newVnode;
        return 0;
    }

    /* If the Vnode does not exist, create a Vnode and enter related information. */
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
    
    /* Insert the newly created Vnode into the hashtable.*/
    (void)VfsHashInsert(newVnode, node->i_ino);

    *ppVnode = newVnode;

    LOS_MuxUnlock(&g_jffs2FsLock);
    return 0;
}
```

Summary:

1.  Obtain private data from the parent node.
2.  Obtain the private data of the target file based on the private data.
3.  Create the target Vnode based on the private data of the target file.

## Summary and Precautions<a name="section5617183014319"></a>

The general adaptation procedure is as follows:

1.  Obtain the private data required by the file system based on the Vnode input parameters.
2.  Implement the API based on the private data.
3.  Encapsulate the result in the format required by the Vnode or other APIs and return the result to the upper layer.

The core logic is how to use the private data to implement API functions. These APIs implement common functions of the file systems and are generally implemented before the files systems are ported. Therefore, the key is to determine the private data required by the file system and store the data in the Vnode for later use. Generally, the private data is information that can uniquely locate a file on a storage medium. Most file systems have similar data structures, for example, the inode data structure in JFFS2.

>![](../public_sys-resources/icon-caution.gif) **CAUTION:**<br/> 
>1.  When a file is accessed, the  **Lookup**  API of the file system is not necessarily called. The  **Lookup**  API is called only when the PathCache is invalid.
>2.  Do not directly return the Vnode located by using  **VfsHashGet**  as the result. The information stored in the Vnode may be invalid. Update the fields and return it.
>3.  Vnodes are automatically released in the background based on memory usage. If data needs to be stored persistently, do not save it only in Vnodes.
>4.  The  **Reclaim**  API is automatically called when a Vnode is released. Release the resources used by the private data in this API.

