# Glossary

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda; @yixiaoff-->
<!--Designer: @guxinggang; @liweilu1-->
<!--Tester: @wangbeibei; @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=fea077926b0978d03b1b37767b2d1723ff105d6c translatedAt=2026-08-11T01:56:18.257Z pushedAt=2026-08-12T03:36:35.259Z -->

## D

### DataSharePredicates

  A utility class for building data query conditions. In media library queries, it retrieves specific media assets or album objects by setting query conditions (such as `equalTo` and `between`), supporting flexible data filtering.

## F

### FetchOptions

  An object used to configure query parameters for media assets or albums. It includes fetch columns (`fetchColumns`) and query conditions (`predicates`), which specify the asset properties to return and filter criteria for queries, improving query efficiency and accuracy.

### FetchResult

  A result set object returned by a media asset or album query operation. It provides the ability to traverse and access query results. You can use methods such as `getFirstObject` and `getAllObjects` to obtain the queried media asset or album objects. After the query is complete, call the `close` method to release resources.

## M

### Media Library Kit

Provides capabilities for managing albums and media files, including photos and videos, helping apps quickly build photo and video display and playback capabilities.

### MediaAlbumChangeRequest

  A request object used to create and modify album attributes. It supports change operations such as creating user albums, renaming albums, and adding or removing media assets in albums. The change request must be submitted through the `PhotoAccessHelper.applyChanges` API to take effect.

### MediaAssetChangeRequest

  A request object used to create and modify media asset properties. It supports change operations such as creating image or video assets, renaming media assets, setting the favorite status, and deleting assets. You can add resource content through the `addResource` API, and the change request must be submitted through the `PhotoAccessHelper.applyChanges` API to take effect.

### MediaAssetManager

  A core component for requesting and managing media asset data. It supports requesting image data, requesting moving photo objects, and loading moving photos from the app sandbox. It provides two resource delivery strategies — high-quality mode and fast mode — for efficiently obtaining media asset content.

### MovingPhoto

  A special photo format that combines a static image and a short video. It contains both image and video content, capable of displaying dynamic visuals and sound for a brief period. It is used to capture exciting dynamic moments, expand creative possibilities, and improve photo-taking fault tolerance.

### MovingPhotoView

  A UI component for playing and displaying moving photos. It supports features such as long-press to trigger playback, mute settings, and video display mode configuration. The playback state is controlled through the `MovingPhotoViewController`. It is suitable for moving photo playback and display in social and gallery apps.

### MovingPhotoViewController

  A controller object used to control the playback state of the `MovingPhotoView` component. It provides the `startPlayback` and `stopPlayback` methods to control the playback and stopping of moving photos, and works with the `MovingPhotoView` component to implement interactive playback of moving photos.

## P

### PhotoAccessHelper

  A core API module that provides core APIs for accessing and managing albums and media assets. You can obtain an instance through the `getPhotoAccessHelper` API. It supports obtaining media assets, obtaining albums, creating and modifying assets, listening for asset changes, and other operations. It is the primary development interface of Media Library Kit.

### PhotoAsset

  An object for a single image or video media asset. It contains basic information about the media asset (such as URI, display name, title, and other properties), supports operations such as obtaining thumbnails, reading resource data, and modifying properties, and serves as the basic operation unit for media assets in the media library.

### PhotoViewPicker

  A system component used to launch the system gallery for users to select media assets. It supports configuring parameters such as the selectable media file types, maximum number of selections, and whether to support taking photos. After the user makes a selection, it returns a `PhotoSelectResult` result set. It provides a secure way to select media assets without requiring permissions.

### Picker

  A system-provided component for users to interactively select assets. It includes `PhotoViewPicker` (photo picker), `AudioViewPicker` (audio picker), and other pickers. By launching a system UI, it allows users to select assets to be shared or operated on, enabling secure asset access without requiring sensitive permissions.

## T

### Thumbnail

  A reduced-size version of a media asset. It is used to quickly display preview content of images or videos in scenarios such as album browsing and editing previews. Thumbnails can be obtained with the `PhotoAsset.getThumbnail` API by specifying the desired size, and are commonly used for UI display to improve performance and responsiveness.