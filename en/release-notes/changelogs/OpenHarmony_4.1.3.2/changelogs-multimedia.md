# Multimedia Changelog

## cl.multimedia.1 Change of PhotoAccessHelper.getAlbums, UserFileManager.getAlbums, and UserFileManager.getPhotoAlbums

**Access Level**

System API

**Change Reason**

For privacy protection purposes, the capability of obtaining hidden albums is restricted since API version 11. To obtain hidden albums, use **getHiddenAlbums** with the required permissions. The APIs for obtaining albums cannot be used to obtain hidden albums.

**Change Impact**

This change is a non-compatible change. **PhotoAccessHelper.getAlbums**, **UserFileManager.getAlbums**, and **UserFileManager.getPhotoAlbums** can no longer be used to obtain hidden albums. Only the system APIs are affected. Adaptation is required for Gallery. Third-party apps are not affected.

**Start API Level**

API version 11

**Change Since**

OpenHarmony SDK <4.1.6.7>
