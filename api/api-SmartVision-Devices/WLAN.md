# WLAN<a name="ZH-CN_TOPIC_0000001055198080"></a>

-   [Overview](#section219415277165623)
-   [Summary](#section674220326165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section88215858165623)
-   [Macro Definition](#section128768446165623)
-   [MAX\_NETBUF\_RESEVER\_SIZE](#ga794c035a19a38acc000146a8f9a4ec80)
-   [MAX\_WIFI\_COMPONENT\_NAME\_LEN](#gaf460a45a5e365279ca6bc5b3e8750542)
-   [Typedef](#section1022416497165623)
-   [Mac80211SetMacParam](#ga85f7d8a3795887f090e0a6439b1df6e1)
-   [NetDevice](#gac26e4b0cda623f27420f9ce77befbb1f)
-   [WifiConnectParams](#ga3e8945c521d2392cb775494570c560b3)
-   [Enumeration Type](#section1302951935165623)
-   [anonymous enum](#gafa231099d07583c3ed0981e0bb665f55)
-   [Ieee80211Band](#ga9882f415202cf9acb0f4cdfbc456a88d)
-   [MacSetType](#ga75cba3dc6ab4c5dc5653b037433b3abf)
-   [NetdeviceError](#ga9023c5dc1cc43758cbb468d78af41c2d)
-   [NetDevTxResult](#ga9fb4e578a15db1b0087d7b3831591ced)
-   [NetIfCategory](#ga530241881cd17e03f8ae254ef1d9755e)
-   [NetIfLinkStatus](#ga7b1187d116fb065d7927ad9f77edd842)
-   [NetIfStatus](#ga0fb482694e5eac3f48c75de1749c8baf)
-   [NetLinkType](#gad3175955d2e6ef3c4f52da9b509d5b4a)
-   [ProcessingResult](#ga9c1d6e7df4468671742cb76f72b67af1)
-   [Protocol80211IfType](#gac69954f56fcc99fc8aac68aa157831c7)
-   [WifiBusType](#ga1c5537e64f05b5e91b951ddeb66d4261)
-   [WifiChannelType](#ga9d902b330de99c24b2a8c3ba7120af21)
-   [WifiHmacMgmtStatus](#gaf3e873b51f0cfa077aca9d33ed7a0960)
-   [WifiMainFeatureType](#gaec03ba36d71cc2d5f3209bc24aa6ee10)
-   [Function](#section2116187334165623)
-   [AddFeature\(\)](#gae928a69366143780650b73c6b030c3a7)
-   [DelFeature\(\)](#ga395848b77fc10f2213d5b12793861292)
-   [HdfWifiEventConnectResult\(\)](#gaf9e61f36e11d7d2e94e7969a8ecf22f1)
-   [HdfWifiEventCsaChannelSwitch\(\)](#ga2aa62f7e8e72e8f9df0b2101c08a9d44)
-   [HdfWifiEventDelSta\(\)](#ga208ef54b2a601f416a472bb1e21fae7e)
-   [HdfWifiEventDisconnected\(\)](#ga58b1a613d784233a1e84027079e1ea57)
-   [HdfWifiEventEapolRecv\(\)](#ga3e60f4568723471226107848ddbe582f)
-   [HdfWifiEventInformBssFrame\(\)](#ga941675fb683212e6e0d8e1529b300482)
-   [HdfWifiEventMgmtTxStatus\(\)](#ga1721c7e1b5af0240a663ea9f0fe12854)
-   [HdfWifiEventNewSta\(\)](#ga31edc1e9de8835e0e8a9c1e89fad3bd9)
-   [HdfWifiEventRxMgmt\(\)](#gad47d56e4332ccd14116368444a4b330f)
-   [HdfWifiEventScanDone\(\)](#ga41efbd6788a80604b81ae117a363b657)
-   [HdfWifiEventTimeoutDisconnected\(\)](#gafda13471995c91e65326a9aa374ae1c9)
-   [HdfWifiGetProduct\(\)](#ga77f15efb80095134d08cc63b62229f21)
-   [Mac80211GetOps\(\)](#gad7c34413d81d55ba090c90404d340c8a)
-   [Mac80211RegisterOps\(\)](#ga6542a735af0fe7496789c3c55380adfa)
-   [NetBuf2Pbuf\(\)](#ga88e4943fc1b1f4e31f388bf8eec57476)
-   [NetBufAlloc\(\)](#ga5ced2af63a9064b0e33d0aa4e86b3fc1)
-   [NetBufConcat\(\)](#ga89ee14a3da1b7b83325045af9c488ef8)
-   [NetBufDevAlloc\(\)](#ga74198f03268aadc025f6b76056b09604)
-   [NetBufFree\(\)](#ga9320642699593dfecd79dc30132dd4eb)
-   [NetBufGetAddress\(\)](#gacd40d5004291b4aaa5c27703d9379c9c)
-   [NetBufGetDataLen\(\)](#ga67eeb57ebe467b9caa4f31734955727b)
-   [NetBufGetRoom\(\)](#ga09245834fe9f55fe475a0dc226a6a709)
-   [NetBufPop\(\)](#ga81f298aebc5b7772f173e2f6fadc004f)
-   [NetBufPush\(\)](#gac4ec1cedef616e61038dcb6dbf67d204)
-   [NetBufQueueAtHead\(\)](#ga082b7a173ca09288c3b418ce4e4faa7d)
-   [NetBufQueueAtTail\(\)](#ga9de36bf1db57bd4eb042e87cb63dae69)
-   [NetBufQueueClear\(\)](#ga79045ebd1636c27bee454e9541498f33)
-   [NetBufQueueConcat\(\)](#ga2331e6b8c8f1ac4f00f8a1206fb1a3d8)
-   [NetBufQueueDequeue\(\)](#ga4ad66d7ca7aabda3aef08fa541dc9ee4)
-   [NetBufQueueDequeueTail\(\)](#ga390319a0419c26c73552bcee6b8d5c32)
-   [NetBufQueueEnqueue\(\)](#ga25bf5d56e8afec1bc80080b20c3b7daa)
-   [NetBufQueueEnqueueHead\(\)](#ga5ebe7aff6d5187645869f067b0a8f659)
-   [NetBufQueueInit\(\)](#ga6e754d5529b23b413d1fe00102a95db9)
-   [NetBufQueueIsEmpty\(\)](#ga36297284c60746f2b6895d94ea5e2dc3)
-   [NetBufQueueSize\(\)](#gaaa5c00efd1dedecf846af4dd108b6701)
-   [NetBufResizeRoom\(\)](#ga623e0b15e65f317f746b53b9a4530bdd)
-   [NetDevGetRegisterCount\(\)](#ga8c8d400a6b4eb64445a2b4ea12102c9a)
-   [NetDeviceAdd\(\)](#ga64be10f09b180d3098e9550163131dbd)
-   [NetDeviceDeInit\(\)](#gaf4a2fa8b1a35d4cadd8247ee8fed60a4)
-   [NetDeviceDelete\(\)](#ga6c93cb701cf2523eaa7bbeabd4acf3ab)
-   [NetDeviceGetCap\(\)](#ga5d2a4fd370e2115b4c1fc8ecc46d64ab)
-   [NetDeviceGetInstByIndex\(\)](#gab45261476e710c30335975726af3a834)
-   [NetDeviceGetInstByName\(\)](#ga6d90d1bf783a83db1d838d03f8c1d93a)
-   [NetDeviceInit\(\)](#ga8d2bff6673ec21ba317d596a84df7ca8)
-   [NetDeviceIsAnyInstRunning\(\)](#ga20fcbcc248e99917c17223a97fe5d70e)
-   [NetDeviceIsInstRunning\(\)](#ga05b08c890c69f3e633447f14e16d30f7)
-   [NetIfDhcpIsBound\(\)](#ga389ec95a3c8170c4ca74487f8bc1d8ac)
-   [NetIfDhcpsStart\(\)](#gae97c7abcf556be34798622a85162c35e)
-   [NetIfDhcpsStop\(\)](#gaadfeb819b4cb623870823fa5c9793b4c)
-   [NetIfDhcpStart\(\)](#ga5fdd93c820b994adf1b76eb8d50e4f88)
-   [NetIfDhcpStop\(\)](#ga22f97a3fc45841e874ab2072c14e0f3e)
-   [NetIfRx\(\)](#ga44006f6e066aff9f6a3310559e781582)
-   [NetIfRxNi\(\)](#gad252107cdd20e9d3d0ab33fbfc2161e9)
-   [NetIfSetAddr\(\)](#gadd5c08aa8e65a12db062b1b88d53cece)
-   [NetIfSetLinkStatus\(\)](#gaee9c68875ef541ed915045ab7a047ee8)
-   [NetIfSetStatus\(\)](#gaa14fc68a382284491a272992d5c477cb)
-   [Pbuf2NetBuf\(\)](#ga8d44f8dbfa75583d0056702b5a2d32a1)
-   [WifiModuleCreate\(\)](#gaf5d1df53f08cae98ecfd440f9b425709)
-   [WifiModuleDelete\(\)](#gae14e3786e60f16a100197d28bae5a362)
-   [Variable](#section420458945165623)
-   [aborted](#ga32ea10f832c5a03971033d5f44f3ef6c)
-   [abortScan](#gab870d8100c1c9cb60b27c75a44bb30d4)
-   [ackNum](#ga223c54c5ebb2d92ed5f6c50115663b86)
-   [addFeature](#gadfa86fac18c68b890d3b33a269931efc)
-   [addKey](#ga367902162f25b7b4c5b80372bb6a81f2)
-   [addr \[1/2\]](#gacdd7348f71376cd66b3a0079a1c393d5)
-   [addr \[2/2\]](#gabcba7263b501288a2585bfddb77f93c4)
-   [addrLen](#gafc2646cdc533135a303ca91bf9ebe7ec)
-   [addrMask](#ga8d1059e645ca6684e9ea82044e03270b)
-   [aid \[1/2\]](#ga9885111fb46e5fd771df52f260e80e98)
-   [aid \[2/2\]](#ga9c02f712098d5faa35d6febcd0a26bcf)
-   [akmSuites](#ga142aeeaed24db6cd329c0b8b78ab13bc)
-   [ampduDensity](#ga90e3ceab29efbe5b144191176f7f8e44)
-   [ampduFactor](#ga891bf97aba3202dd8c4f1cbdc288c61f)
-   [arry](#ga6d31899685b7a552a5322e93b0ffd972)
-   [assocReq \[1/2\]](#ga7bcd238eb3be90e887638d51139f570d)
-   [assocReq \[2/2\]](#gad02f8946fea9b392a6b630306e50d52f)
-   [assocReqIes](#gac2e13b44df4b4df0018f801f8a9e0494)
-   [assocReqIesLen](#ga7822f8e474e18a4f7ae7cee7cbd9bc7c)
-   [assocResp \[1/2\]](#gad709ecd25bb15fdc7518eeafd47e3706)
-   [assocResp \[2/2\]](#gad58f02ba5767dc3dce6ca4a43c6934b0)
-   [aucArry](#ga94fdc9f1d50e8f8561e2fa539bd7c8c8)
-   [aucResv](#gac0b10633f99311af30dd220ae9d19e34)
-   [aucRsv \[1/2\]](#gaf00464a59d6bda90ad57cd6201736245)
-   [aucRsv \[2/2\]](#gabdd49dff12ed26c47f1935fb2bf3d873)
-   [aucSsid](#ga47c550859928cbc795333cb26b138ba3)
-   [auth \[1/2\]](#ga13a290a08e43034d0949635793335475)
-   [auth \[2/2\]](#ga797e6d02e8d4fdb4bd372d3c5286c6e9)
-   [authAlg](#gafe2c9439abca834df69dba0aa57a6d5f)
-   [authTransaction](#gad8e67419612ed5fea439e74efb16d4c4)
-   [authType](#ga2c9cdaa7b998a7ffb4378f4a6cedbb75)
-   [band \[1/2\]](#gaab4e3330566d5b0b02e7c6117c7b9a73)
-   [band \[2/2\]](#gabfd4562987e1c8b6daea0d10ca8c2751)
-   [bands](#gaf3ab07acceaeff1edc793cb23d739ec5)
-   [beacon \[1/2\]](#ga368a66f24e860ef013989c410fa0fb3e)
-   [beacon \[2/2\]](#ga82b21412a65ba3e436d055fff4388362)
-   [beaconData](#ga80cf5c2a3596c32ddc1de60d51c3e33d)
-   [beaconFound](#ga55c6f1eaedc16b99dc299530a0dc6f83)
-   [beaconInt \[1/2\]](#ga34eacc801b02cefbfe742a6451b95770)
-   [beaconInt \[2/2\]](#ga8438721279093a38779f1ab7f6ed59dc)
-   [beaconInterval](#gad49083c0d110aef00878071800040069)
-   [beaconLossCount](#gaa669232960c93e73558062e466d0fb02)
-   [bitrate](#gab8e1e3d778d0739a728ae5d3a77fe502)
-   [bitrates](#ga4a0d4f26cbf81f839b25c2808e50856a)
-   [bssid \[1/3\]](#gac8415aaa2b1a60e17712776826b2514a)
-   [bssid \[2/3\]](#gacfb1f8dc523cea7d4394b912c0c508ea)
-   [bssid \[3/3\]](#gaf088c497d633df51d8bee24e7a778c22)
-   [bssParam](#ga0b38e5935241d2f3cd05c2e5bba1c8e1)
-   [bufs](#ga49eacbbc8b4231a05464768103b8593f)
-   [cap](#ga56216c033dd738a3100c8e0d9c1dd1a8)
-   [capabInfo \[1/6\]](#gadc4d122edd92d777956cb913aa27918b)
-   [capabInfo \[2/6\]](#ga53356e3d7b67cdeca0e6110dbb8b46f7)
-   [capabInfo \[3/6\]](#ga3e5e0b8af464d5990e451d6a97c6e89b)
-   [capabInfo \[4/6\]](#ga718001853f9317e9108339cfe5e6531b)
-   [capabInfo \[5/6\]](#gaabddc721f70c869a51d5893ea58012cc)
-   [capabInfo \[6/6\]](#ga0389de8c9241c7e8622e3cf643ee8efe)
-   [centerFreq](#ga42300a5593bf6b40a4d823af2dbe2a5d)
-   [centerFreq1](#ga650d64bab38809286d34acd11f292507)
-   [centerFreq2](#ga62d64617036c65e3964657c692a39f6a)
-   [chan](#ga165ba815b4ddb9558f90bd0bf82e23f0)
-   [changeBeacon](#ga833043e11a73c8f53cb918e25715939e)
-   [changeMtu](#ga2035c840c71a43b43451bfe0213ca04a)
-   [changeVirtualIntf](#ga0a4446bf704b9f4b673f68ff97002b1b)
-   [channel](#ga0c59333afe2ac58387c92260a8268de7)
-   [channels \[1/2\]](#gaabb5ffed3a294507d4f51d598fd98717)
-   [channels \[2/2\]](#ga02df34a92ff5010c8b70ed8cdbd90fb1)
-   [check \[1/3\]](#gaf3b4d16f68ab697df71ca8589f00397c)
-   [check \[2/3\]](#gae93142de73db5e7e18f2d247387d79ee)
-   [check \[3/3\]](#gab32c75fd1d8d8985d9861157907a3a74)
-   [chip](#ga213bff4c0d74fb3db3ff7c21bea781ae)
-   [cipher](#ga2efb1151fccead84c0d4257717760936)
-   [cipherGroup](#ga9be34adb7e26191321b38c37b341e20d)
-   [ciphersPairwise](#ga53c85b4e0f5f5e10bb16935fb8a77df0)
-   [cipherSuites](#ga011f5a473787d4700441e4bf7387673a)
-   [connect](#ga9f26a0c3e31e1b57cc8b357964cce3db)
-   [connectedTime](#ga7a260a68741622c415faa30f345802f1)
-   [connectStatus](#ga22925ebc7c0b94465c53b886307c67dd)
-   [controlPort](#ga2f49a07024546730d0cd60e93cb9e450)
-   [controlPortEthertype](#ga67b6c08be0641796798513fbbb13dd73)
-   [controlPortNoEncrypt](#ga020b34dbfd5f961c86ef416873a9c02c)
-   [crypto](#gaa91e37ddf709a3553a6352623ea8c341)
-   [currentAp](#ga451da053aeae74e215da41757196ac2c)
-   [dAddr](#ga5124eb108341354708e52775df8899ef)
-   [dataLen](#gafb7e6f774a44888f5c44c3dffc6c5616)
-   [deauth \[1/2\]](#ga65ccc20a9dd404cfb020ecfe9a3301a1)
-   [deauth \[2/2\]](#ga39aa6151289296b2ee91591899e338a0)
-   [deinit](#gaf4ad8f670757555c0535b5a5fa5fa8d9)
-   [deInit \[1/3\]](#ga371e13402535662210549c3ca3303691)
-   [deInit \[2/3\]](#gaf03445197e62e8d5cc5de5c7bba185dd)
-   [deInit \[3/3\]](#ga378c89a04bb867068d3c86c5680ca9c0)
-   [delFeature](#ga764ebf11b82c57d5185df50fab72a1d8)
-   [delKey](#ga7edb052049a9420b938085322c6a0418)
-   [delStation](#ga974552db5307795e70d5868edccecc1c)
-   [dest](#ga21658fd4eb65ed4559958e3074f21081)
-   [dev \[1/2\]](#gafa78f2abfa4f977cfb3bd52a6ae05d61)
-   [dev \[2/2\]](#gada8e463843d9e5fef133d41fd745dc42)
-   [device](#ga689a86688de16eed6ffa023417967c9a)
-   [disassoc \[1/2\]](#ga1afc8148645370acc808671bac430a66)
-   [disassoc \[2/2\]](#ga1c92855062b3cbbcc94f6e4cf3076473)
-   [disconnect](#ga558d3d417f465ca592dc94c3040b2d1f)
-   [dlist \[1/2\]](#ga6de94d9c8f9dd8d608a091673fa130c4)
-   [dlist \[2/2\]](#ga473ab87a57006bb6ed69c5e5ea666f5c)
-   [dPort](#ga2a188a6b8ee0eccceefe0e17818e8707)
-   [dstAddr](#ga4e602eacdc2481c6d91b1e42e7a7233c)
-   [dtimPeriod \[1/2\]](#gac532b47f0a538e68bb340437d840fbcc)
-   [dtimPeriod \[2/2\]](#gad63b5d23db5e2bf8b9ca57bdb7de4c82)
-   [duration](#gad1ea2da7ade6335e8c273284208d551d)
-   [etherDhost](#ga987c92ec1c7c5e637ba93d18edcf87c4)
-   [etherShost](#gaaee5baebf4a693ad44d0ae9530d9dfbd)
-   [etherType](#ga6a0916fd23f851ba6cd2bcd3700123b2)
-   [fake](#ga82e8bdd989fd03bf9cc3b5f6a14ec05b)
-   [fe](#ga772b7d7c4b5cc3ecdab421a0b2337e91)
-   [feList](#ga347d5b39c9a96835ae85358ba0895cc3)
-   [filled](#ga14e0c28a09471313507c1ef6f704ad8a)
-   [flags \[1/7\]](#gaaf4d141dbf9493524661415d7940b853)
-   [flags \[2/7\]](#ga192ebb83d79d9bed8ee35ceb3d91f1df)
-   [flags \[3/7\]](#gaadedfd33df129639f135a6f5d0322e4e)
-   [flags \[4/7\]](#ga0265e4d32fef1bb7c94f14671763655b)
-   [flags \[5/7\]](#ga0f4b1664afa7f688b0e7fe974e8676a2)
-   [flags \[6/7\]](#ga66be1d87b4d2576cee91cd3867b93701)
-   [flags \[7/7\]](#ga01a8027b2e16aa30a6da3ee99c0f3890)
-   [fragInfo](#gaf329df46f50a5dcf4dd87c103317401b)
-   [fragThreshold](#gafa733ea2e4b2efa2dc10938956a95f85)
-   [frameControl](#ga52e127b6032bc14b0828d775f45c164d)
-   [freq \[1/2\]](#ga9489887bd02837a40e9560f1a4acd211)
-   [freq \[2/2\]](#ga5ca4a2c4e1cdfe1d9e4bd1592855e5a0)
-   [funType](#ga4a20c090f2e28ed317957d4ed5fc28fd)
-   [generation](#ga4b17833011fe840879c7bcd74aac9f9d)
-   [getModule](#gad7c080e7ac22daf18529184da55e910c)
-   [getStats](#ga3dcf9dd183845770dc8589eb98e59fce)
-   [hardHeaderLen](#ga585cec837551180e542b29d263dd585c)
-   [hiddenSsid](#gac5c5a9f217e8fdf4d94cf78f8311d254)
-   [hslConfig](#gae67367af307406e4693e7c4cdba69baf)
-   [htCap](#gaf1a61194a3fdac2516e391534e5e15d6)
-   [htSupported](#gaf5a9bd33d4d6eaf38052d3c52c261db6)
-   [hwValue \[1/2\]](#ga88c500579917b7a4b0167623851abcf2)
-   [hwValue \[2/2\]](#gaf1d7fcab109296f61b1e46315c56ad61)
-   [hwValueShort](#ga0c64e3b8824a84ceab38b2c4c3c53e9c)
-   [id](#ga2d5c09b859bc0faddc8a42339973bdd4)
-   [ie \[1/2\]](#ga92b16a60570fd1d28b948ee43f9b0124)
-   [ie \[2/2\]](#ga8274aa0c44fe19a615c38c67eb799c87)
-   [ieee80211Ptr](#ga3d04317fd4d2c8932808d6dd07fedcf4)
-   [ieLen \[1/2\]](#gaa26674156ac0814fbc1f45b8e11b7b9f)
-   [ieLen \[2/2\]](#gad5c61386055631b64c953fa46c2aad24)
-   [iface](#ga8666b5068c46aa89a3cae49b7a31c224)
-   [ifrData](#gadc2f148a30a6ef88b5938fea193ac9e5)
-   [iftype](#ga8e9277b73be8498a73999151e093693e)
-   [inactiveTime](#ga6326315bb50ed95fc0ce5ce65177cb78)
-   [init \[1/4\]](#gabbafd20c6c6cc8eb20777cdd588b46cd)
-   [init \[2/4\]](#ga24cdc29146b8f84d021328e8a31269a5)
-   [init \[3/4\]](#ga8b09c66c75ed9515bbf5f76e25c86e57)
-   [init \[4/4\]](#gadf3d907844092764d8c8d3ce150e1712)
-   [interfaceModes](#ga33ab965c40e11c007cadf1116113ca21)
-   [interval](#ga691fb611afdc35bbf6951977119c8772)
-   [ioctl](#ga6c3d34c3329316632c7f6b6b19d2f983)
-   [ipAddr](#ga814742f62c24ff2895a18ad157df4874)
-   [key \[1/2\]](#ga0c19dd081453de295f3095c2cf7aced4)
-   [key \[2/2\]](#ga6ca72a4cfcb196dda7c2ca2562a1b20b)
-   [keyIdx](#ga27eb8efb66b131f8495baf2dcaee6eb6)
-   [keyLen \[1/2\]](#gae913f805139a4111b98617ab8e678528)
-   [keyLen \[2/2\]](#ga98603c2c633e6ca1ad940269cfb01e58)
-   [lastRxTime](#gaf3cfb6012fad954900ccded1305e0e73)
-   [legacy](#gaf51b764aa77423df71236454f2804a62)
-   [len \[1/2\]](#ga559e952054ce59e81d2ff9b38634b60c)
-   [len \[2/2\]](#ga90b8c3dd672bad2f722900101db236f2)
-   [LinkLayerType](#ga4758167363bad30116f4bcdb4cc1ae2a)
-   [listenInterval \[1/2\]](#ga4755cf88f3c370bb7e704e7ab1f1f46b)
-   [listenInterval \[2/2\]](#gad95ef561c78f9312941cbd559e11b873)
-   [llid](#gadc926d27f91b736e04f9ba2ffe663aeb)
-   [lock](#gadd22ee64f7d9703d6c4cde54b512aaa0)
-   [mac \[1/2\]](#gaa9ba863f7e3f07f710274cbfecb0080e)
-   [mac \[2/2\]](#ga83cfa2d4899721ac3448d99ea5b0bef2)
-   [macAddr \[1/3\]](#gacbe765a13d3de60f6c4f297234444553)
-   [macAddr \[2/3\]](#ga98f76b11c4cac6945526d048cb925e6c)
-   [macAddr \[3/3\]](#ga84ee6f62e15f1e8252d97b0b3ef55239)
-   [mask](#gabcb55b1def4998381497e79e602a61d5)
-   [maxAntennaGain](#gacd256a8179e084497aad4cacfac77dc2)
-   [maxPower](#gaf998a486d7bc53071e68374a13aa18d8)
-   [maxScanIeLen](#ga249fb8ce5c398f3c6588519e58cd11e9)
-   [maxScanSsids](#gac64622da7ddfc981d13380a66321ee61)
-   [mcs \[1/2\]](#ga5a8aea5e5f47700d6634ec48dc4a1f9f)
-   [mcs \[2/2\]](#gab100d81d329ddf8584ade014d20acc2d)
-   [mem](#gad94b7aff082f5d891a3250dfc6307ce0)
-   [mfp](#ga8212747b66b319e95586ad90d4191300)
-   [mgmt](#ga345b0140ecaa55ffc7c85bf96548efc9)
-   [mgmtLen](#gaa40e6cfe80596087c25e256215123890)
-   [mlPriv](#gac2b0eefb68664e9458311017ce31275b)
-   [module](#ga1d78d86692abec4c85fa96ea5c446509)
-   [moduleConfig](#gaa54566af9b7dda68e119649b3510c858)
-   [modulePrivate](#gab8c955bd3dd2cb79c3c0c3dfdc3b08f5)
-   [mtu](#ga3c55b245d63ce32ea02f2890fc8e75a8)
-   [n\_akmSuites](#ga35627fc7ac0924a52e51427375501f8a)
-   [n\_ciphersPairwise](#gace9dbbf9c1a035b350224b1832d35377)
-   [name \[1/3\]](#ga74b1c5d9a04465f4b47b36ece7470aab)
-   [name \[2/3\]](#gae63e4c5602dbc64bd9905d6b6a4e7aad)
-   [name \[3/3\]](#ga02ee61c30fc06116d5dee320eda37bfe)
-   [nBitrates](#ga355299d64b9af1d889750bda9216734b)
-   [nChannels \[1/2\]](#gaf075c96dac24e5b685d35481c78ecb01)
-   [nChannels \[2/2\]](#ga3150e4a25b1800ee713e08fbf9077116)
-   [nCipherSuites](#gab6cb6ce28cef7f1f5dc0d19380e8ad05)
-   [neededHeadRoom](#ga9241a41c1cb62a68e3d8c93b9dfe4790)
-   [neededTailRoom](#ga3ad6638d07aef608b8d5e4b20a478e03)
-   [netdev](#gacf9e3f94cbac9cf8ae3382aea0d6c5f6)
-   [netDeviceIf](#gaf154f5a9cbf4d297bc6fc7550ae9a819)
-   [netifCateg](#ga95102f11976f69a7c700944614fa06b2)
-   [netifNotify](#ga518102ebc29b985161160ae22b066faf)
-   [notifyType](#ga5b652685d8841c46872427b87507f4e7)
-   [nss](#gac9516b58cac5a7294541958513514c0b)
-   [nSsids](#gaf7bf0f80492f28c7c285f8023505bb8e)
-   [offset \[1/2\]](#ga5f5c974dbd2e5608b3ea2e768e4559ca)
-   [offset \[2/2\]](#gabac9ba66ff160d881083b1f173f411f9)
-   [open](#ga154f75bcfd914b1fb243041186b60a3f)
-   [operationType](#ga98a709ca72bbd2625125b378c08b6d9e)
-   [ops](#ga920007113f95ee9ce9b0d51ca0cf42bc)
-   [origFlags](#gaa8e6146a2fa16a47e794d7d9bbaccf1e)
-   [origMag](#gaf5bc0d20f7c46fbcfd69cb62c3470dfe)
-   [origMpwr](#gaa9666ab4a0f723741328722d1ab74588)
-   [owner](#ga6f725a86ac73ba02449952d3f8fbcff9)
-   [p2pMode](#gad17af431fa1dd6157d3118023459a784)
-   [permAddr](#ga5396b8e87fe6a6be0c7dd789fe289c50)
-   [plid](#ga7dedfef626385689a1baa20e9764ff05)
-   [plinkState](#gaf505fd1078d9f5a0d5374d9538e8d5bb)
-   [prefixSsidScanFlag](#ga5b6c8df255d62a73114aad42c1e4868d)
-   [presetChandef](#ga142433e20a4e8168774cf50dfbbfd27b)
-   [priv](#ga760737c03ad122b360ca8ed814869e4b)
-   [privacy](#ga81e32b68cb7ae4a68b1d42633fc181fe)
-   [probeResp \[1/2\]](#ga27d701ae6c64ae3d17ff24ae2500523e)
-   [probeResp \[2/2\]](#ga4111b0df54692760f9e56b52fe1ba841)
-   [product\_name](#ga97418ebfac2a3a4ecc77c3c98b1ae810)
-   [protocol](#ga029ab0914b5854efe279e442aec3b423)
-   [qmap](#gaa56eababaaaeda2ec724f21889a20ccd)
-   [reasonCode \[1/4\]](#gaa31a88b9f6b93548fe64aa39048bc78d)
-   [reasonCode \[2/4\]](#gabbe22887613c2c96802b092f23898553)
-   [reasonCode \[3/4\]](#gaadcc8f71dfd7b2c5ecc072cceb5fa3bb)
-   [reasonCode \[4/4\]](#ga5fe7610b3bff3864f9a2fee995c907ef)
-   [reassocReq \[1/2\]](#gad48460387d63f16a7b12ae6d16dc48df)
-   [reassocReq \[2/2\]](#ga6e7eeaa3e4d604a221f598e51c3869eb)
-   [reassocResp \[1/2\]](#gab23b4bd33fd0295774a4ca362ea9312d)
-   [reassocResp \[2/2\]](#ga966d7d7ea87b3e2d0446a059f078ded1)
-   [reqIe](#ga1ba76217df6a0a67be62ab623f68ee66)
-   [reqIeLen](#gaade69412094ceaa5374c76513064f00a)
-   [reserved](#ga92cf658154d7d1fddeebc4a01cc317d6)
-   [resv \[1/4\]](#ga8ae51118ee5e1a121bad85055ecad454)
-   [resv \[2/4\]](#ga9bb2fd298749eab513163e3a7a2b03ee)
-   [resv \[3/4\]](#ga7c1cd7fbd4ccdf7babf89394cc78ab77)
-   [resv \[4/4\]](#ga740712d61cb553af65d36d1a65f0a483)
-   [resv1](#ga4bf7e03861cdefd017d6669994a1df43)
-   [rspIe](#ga113ce1420c647c51b89dca5ab436f82e)
-   [rspIeLen](#ga0756bccba43358d534d8c5a254d63686)
-   [rsv \[1/2\]](#gaec41f143c3551e59da63ab2e9d9c9c53)
-   [rsv \[2/2\]](#ga197b5045451ca25a03f478df0bd03514)
-   [rtsThreshold](#ga00874e60aa7dc8c7455732e633586813)
-   [rxBytes \[1/2\]](#ga8445328bc8d5cc4ba8bc5d5f8ec0c1fa)
-   [rxBytes \[2/2\]](#ga809ff3fc1f051abbb655cc7ea6cbd900)
-   [rxDropped](#gae3a86ad63c016badbd0ac72bf572afa3)
-   [rxDroppedMisc](#ga9506e6f1cd855cf8116dd650f68966ac)
-   [rxErrors](#gabf0cb61284e0cba862c5e8db62b63fa9)
-   [rxHighest](#gad76dc235ae05680bdde62564f5a6c10b)
-   [rxMask](#gaaa1851c2f6db9ccf446f70eb272196f5)
-   [rxPackets \[1/2\]](#gac890bb6b9e08670ec2bb1a0c41ab1cdc)
-   [rxPackets \[2/2\]](#ga691401a65931b7753fe1f67749074755)
-   [rxRate](#ga7ccb9050859ba196054590b2294f3a40)
-   [sAddr](#ga22e36dfd118fbe9deee40135f87a0568)
-   [selectQueue](#ga3e08c5be1dbe6e4aa6fc1f930783c295)
-   [seq](#ga00bfccb54d7fc37bc2ddbf9ebf3937bb)
-   [seqCtrl](#gab3b6ce7596b771a8bb0af0edbad416fd)
-   [seqLen](#ga6b1bb1722c1205c1b560c01c58d35018)
-   [seqNum](#ga5409de9f82a50bf5113dafb316118d4b)
-   [set](#ga9c47590735e6ba21c557361770f76338)
-   [setChannel](#ga166ca94a9482995f3e1f58263eeeed02)
-   [setDefaultKey](#gae4e2e0af8777ab0bae98b1816664bddc)
-   [setMacAddr \[1/2\]](#ga177446df24b19e4ddca32e9719d6fe8e)
-   [setMacAddr \[2/2\]](#ga104f6b8049728769f54563aa242850b8)
-   [setMeshId](#ga37e19745783d5dbf8439b9f1f89ca6f5)
-   [setNetIfStatus](#ga334e7e9c31ff9408ba67aed1cb96a174)
-   [setSsid](#ga519c91a244639e25a8c604e284486873)
-   [signal \[1/2\]](#gaf34477153f092bd07bd8a80ca29d16bf)
-   [signal \[2/2\]](#ga20f18f7993df9723a0f3e7520ae715e2)
-   [signalAvg](#ga5423c3f5c2797588018ae3e32582e0bf)
-   [signalType](#ga0c0e8af92ed7d85cbcc04bcf4f13a8b7)
-   [size](#gab8e922b274e1854731b5fd22d8dde62d)
-   [source](#gaa51376bc21358f5c14e8c21ddc9afa00)
-   [specialEtherTypeProcess](#ga8bb9ea881b1bdabe8c45f721310823b1)
-   [specialProcPriv](#ga659f5eb4ee2cef37cb93acea357acb75)
-   [sPort](#gae29f9cbe74e4e7f7543e74bb8d039f15)
-   [srcAddr](#ga636095dd14f2219a50cd5d86e7f94cde)
-   [ssid \[1/2\]](#ga320f45c28aa8ca8095159b8a0a114268)
-   [ssid \[2/2\]](#ga875dd450960cc445dd2a12355bc6912c)
-   [ssidLen \[1/3\]](#ga35c2bd750767a87abf1c45b480124669)
-   [ssidLen \[2/3\]](#ga18a38015e45de3571893b8c1edea991a)
-   [ssidLen \[3/3\]](#gac5c6ea249ba044d37f2b85df506cd898)
-   [ssids](#ga761056fae3d79073bbc33ad3f00a7319)
-   [staFlags](#gae3d8b6844b2838f2622405f27d9eb33b)
-   [startAp](#ga203437a6b1d66758f2217f7154ce1210)
-   [startScan](#ga259da70c25a528287c433af2f7bcf530)
-   [state](#gaf3ac6e671103cb8319d7ed2af62883f2)
-   [stats](#gafdd796dab998fb2ff695af4d50abdc13)
-   [statusCode \[1/4\]](#gaf37ac11db8228fec9975121b199311f7)
-   [statusCode \[2/4\]](#gafffefc2805012b07d7f23dcc3cc014e5)
-   [statusCode \[3/4\]](#ga245f8361fce97aa71072505cac290411)
-   [statusCode \[4/4\]](#gaddcc87402a9e4e6f09098d5e7c25eebe)
-   [stop](#ga5e328f3dc0b610672889e66b33bb7cf8)
-   [stopAp](#gaf30acc8bd9ecd9bffbc46f423423266e)
-   [subtype](#gac649567339d882d98c5f4ba98bbb241e)
-   [timestamp \[1/2\]](#ga9ff8a9a52a3e4f341e7ff49dd7bf76b8)
-   [timestamp \[2/2\]](#ga061a09e9bc3131127aa09d956f60b040)
-   [tos](#ga324f15b4a41342c026ce3ad253ed9498)
-   [totLen](#ga35aa269c5b304d238c65aedaa28e3da5)
-   [ttl](#gad380e64b2d33d75ce04d65126b54fb8f)
-   [txBytes \[1/2\]](#ga3084ceeea5b4c0ab032f59f5c5988ef8)
-   [txBytes \[2/2\]](#ga665048e0ce5b8dffa2a3b69bad0bf231)
-   [txDropped](#ga6d9439773d9721261de50a521c301fd9)
-   [txErrors](#gac95614d9e1d400c6ed6f06b8f6aaf0a0)
-   [txFailed](#gab02c662294106f07045b103fcf4eb689)
-   [txPackets \[1/2\]](#ga0f048248764942c6717dce0695039c1d)
-   [txPackets \[2/2\]](#gac9d132b276538f055db2443e61f00b72)
-   [txParams](#ga9cb852fd0e898070ffb355080d4079cd)
-   [txPetries](#gaae49c0ae8a58b58adf92be62af7147fd)
-   [txRate](#ga959e150b0327d9a30db768aec89426ae)
-   [type](#ga4c59fb9385e56ed8017ee48d36bac554)
-   [updateModule](#ga5166022e5100e57fe0b307a4254e3dc1)
-   [urgent](#ga0c402826ed93d697342d8b1108db7754)
-   [use4Addr](#ga554a530b88a15955fd9859ec08b569f3)
-   [variable \[1/7\]](#ga114bed8793f4e32fba36ca20c9ac10d8)
-   [variable \[2/7\]](#ga69066d587669a7b69106d618e90fbad3)
-   [variable \[3/7\]](#gaf087bcdc5ec6bd2fc84981ccc1b85612)
-   [variable \[4/7\]](#ga27b1d2abd28404a65166381dffdd5d57)
-   [variable \[5/7\]](#gaf330f60c8afa98503226325a3d4328f9)
-   [variable \[6/7\]](#ga0de9d9ef52da27a0a11753d152c2fb64)
-   [variable \[7/7\]](#ga9606f7f13ca77c203e07d48e65608bb3)
-   [versionAndHl](#gae31602cb3fb4f012749e6d44e73bd5bf)
-   [watchdogTime](#ga480ec41047ece56996f42b0f72a6e079)
-   [wdev](#ga09f1cdfc6c524ca96aed6b1894baa720)
-   [width](#gae9ff862b7d4a7145eb00275d57938b4f)
-   [window](#ga55cc45eeabc0f857e51e8864ae45de8e)
-   [wiphy \[1/2\]](#ga86835b49d9ac8e3965d710334d1ecdf2)
-   [wiphy \[2/2\]](#ga43dd029f6f34ccb0255e519aded47478)
-   [wlanType](#gaf957402f9938b5bf37a7c39737f18e69)
-   [wpaVersions](#ga2b21ef556b428238d4dc5009b82087ff)
-   [xmit](#ga5d6e31f59da2eef0998deadd40e13304)

## **Overview**<a name="section219415277165623"></a>

**Description:**

Defines a WLAN module that supports cross-OS migration, component adaptation, and modular assembly and compilation. Driver developers of WLAN vendors can adapt their driver code based on the unified APIs provided by the WLAN module. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section674220326165623"></a>

## Files<a name="files"></a>

<a name="table1989835999165623"></a>
<table><thead align="left"><tr id="row1488216250165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1531333870165623"><a name="p1531333870165623"></a><a name="p1531333870165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1170559085165623"><a name="p1170559085165623"></a><a name="p1170559085165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row118559114165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p777763392165623"><a name="p777763392165623"></a><a name="p777763392165623"></a><a href="hdf_netbuf-h.md">hdf_netbuf.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858927121165623"><a name="p1858927121165623"></a><a name="p1858927121165623"></a>Declares network data buffers and provides APIs for operating buffer queues. </p>
</td>
</tr>
<tr id="row2006480217165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1430439980165623"><a name="p1430439980165623"></a><a name="p1430439980165623"></a><a href="hdf_wifi_event-h.md">hdf_wifi_event.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123862935165623"><a name="p2123862935165623"></a><a name="p2123862935165623"></a>Declares WLAN driver events. </p>
</td>
</tr>
<tr id="row2122755143165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p945897888165623"><a name="p945897888165623"></a><a name="p945897888165623"></a><a href="hdf_wifi_product-h.md">hdf_wifi_product.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1932251751165623"><a name="p1932251751165623"></a><a name="p1932251751165623"></a>Declares the data structure of the WLAN module. </p>
</td>
</tr>
<tr id="row1132528031165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p11710937165623"><a name="p11710937165623"></a><a name="p11710937165623"></a><a href="net_device-h.md">net_device.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p721782267165623"><a name="p721782267165623"></a><a name="p721782267165623"></a>Defines WLAN network device interfaces. </p>
</td>
</tr>
<tr id="row1400841205165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203061363165623"><a name="p203061363165623"></a><a name="p203061363165623"></a><a href="wifi_inc-h.md">wifi_inc.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669103844165623"><a name="p669103844165623"></a><a name="p669103844165623"></a>Describes the data structure of WLAN features and bus. </p>
</td>
</tr>
<tr id="row1525455343165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p883977530165623"><a name="p883977530165623"></a><a name="p883977530165623"></a><a href="wifi_mac80211_ops-h.md">wifi_mac80211_ops.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333690240165623"><a name="p333690240165623"></a><a name="p333690240165623"></a>Declares Media Access Control (MAC) APIs and functions related to control flows. </p>
</td>
</tr>
<tr id="row1130342513165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133504890165623"><a name="p133504890165623"></a><a name="p133504890165623"></a><a href="wifi_module-h.md">wifi_module.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p554144726165623"><a name="p554144726165623"></a><a name="p554144726165623"></a>Provides features of the WLAN module and functions to create and delete modules. </p>
</td>
</tr>
<tr id="row251026645165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p804598268165623"><a name="p804598268165623"></a><a name="p804598268165623"></a><a href="wifi_module_config-h.md">wifi_module_config.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893323853165623"><a name="p1893323853165623"></a><a name="p1893323853165623"></a>Declares the WLAN module configuration. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1109384424165623"></a>
<table><thead align="left"><tr id="row1763034690165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p917304681165623"><a name="p917304681165623"></a><a name="p917304681165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p114133069165623"><a name="p114133069165623"></a><a name="p114133069165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row401664082165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1938993617165623"><a name="p1938993617165623"></a><a name="p1938993617165623"></a><a href="NetBuf.md">NetBuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938440648165623"><a name="p1938440648165623"></a><a name="p1938440648165623"></a>Records and saves a network data buffer. </p>
</td>
</tr>
<tr id="row1974196928165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1121754971165623"><a name="p1121754971165623"></a><a name="p1121754971165623"></a><a href="NetBufQueue.md">NetBufQueue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p478266210165623"><a name="p478266210165623"></a><a name="p478266210165623"></a>Indicates the queues for storing network data. </p>
</td>
</tr>
<tr id="row38519306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668758051165623"><a name="p668758051165623"></a><a name="p668758051165623"></a><a href="RateInfo.md">RateInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138789424165623"><a name="p138789424165623"></a><a name="p138789424165623"></a>Defines the rate information received or sent over WLAN. </p>
</td>
</tr>
<tr id="row1793648301165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1729802401165623"><a name="p1729802401165623"></a><a name="p1729802401165623"></a><a href="StaBssParameters.md">StaBssParameters</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1841047627165623"><a name="p1841047627165623"></a><a name="p1841047627165623"></a>Defines parameters related to the WLAN module that works in station mode. </p>
</td>
</tr>
<tr id="row1108123346165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429767201165623"><a name="p429767201165623"></a><a name="p429767201165623"></a><a href="StaFlagUpdate.md">StaFlagUpdate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704461941165623"><a name="p704461941165623"></a><a name="p704461941165623"></a>Defines the update of the <strong id="b1750196983165623"><a name="b1750196983165623"></a><a name="b1750196983165623"></a>Sta</strong> flag. </p>
</td>
</tr>
<tr id="row921539611165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610035777165623"><a name="p610035777165623"></a><a name="p610035777165623"></a><a href="StationInfo.md">StationInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1294903075165623"><a name="p1294903075165623"></a><a name="p1294903075165623"></a>Defines station information. </p>
</td>
</tr>
<tr id="row800326676165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p597342076165623"><a name="p597342076165623"></a><a name="p597342076165623"></a><a href="Auth.md">Auth</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287257777165623"><a name="p1287257777165623"></a><a name="p1287257777165623"></a>Defines authentication information. </p>
</td>
</tr>
<tr id="row452415861165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1474708889165623"><a name="p1474708889165623"></a><a name="p1474708889165623"></a><a href="Deauth.md">Deauth</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p123331559165623"><a name="p123331559165623"></a><a name="p123331559165623"></a>Defines deauthentication information. </p>
</td>
</tr>
<tr id="row1135610159165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1557822722165623"><a name="p1557822722165623"></a><a name="p1557822722165623"></a><a href="AssocReq.md">AssocReq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215864130165623"><a name="p215864130165623"></a><a name="p215864130165623"></a>Defines station association request. </p>
</td>
</tr>
<tr id="row465633499165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128675455165623"><a name="p2128675455165623"></a><a name="p2128675455165623"></a><a href="AssocResp.md">AssocResp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876527910165623"><a name="p1876527910165623"></a><a name="p1876527910165623"></a>Defines station association response. </p>
</td>
</tr>
<tr id="row1551160483165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p184248515165623"><a name="p184248515165623"></a><a name="p184248515165623"></a><a href="ReassocReq.md">ReassocReq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p814547580165623"><a name="p814547580165623"></a><a name="p814547580165623"></a>Defines station reassociation request. </p>
</td>
</tr>
<tr id="row304059888165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633881012165623"><a name="p633881012165623"></a><a name="p633881012165623"></a><a href="ReassocResp.md">ReassocResp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p195945481165623"><a name="p195945481165623"></a><a name="p195945481165623"></a>Defines station reassociation response. </p>
</td>
</tr>
<tr id="row273240355165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725118000165623"><a name="p1725118000165623"></a><a name="p1725118000165623"></a><a href="Disassoc.md">Disassoc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682670425165623"><a name="p682670425165623"></a><a name="p682670425165623"></a>Defines station disconnection. </p>
</td>
</tr>
<tr id="row649072637165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927932621165623"><a name="p927932621165623"></a><a name="p927932621165623"></a><a href="Beacon.md">Beacon</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631314865165623"><a name="p1631314865165623"></a><a name="p1631314865165623"></a>Defines the update of the <strong id="b246391694165623"><a name="b246391694165623"></a><a name="b246391694165623"></a>Sta</strong> flag. </p>
</td>
</tr>
<tr id="row1797409311165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947225530165623"><a name="p1947225530165623"></a><a name="p1947225530165623"></a><a href="ProbeResp.md">ProbeResp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652330207165623"><a name="p1652330207165623"></a><a name="p1652330207165623"></a>Defines scanning response. </p>
</td>
</tr>
<tr id="row1169254915165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1812351975165623"><a name="p1812351975165623"></a><a name="p1812351975165623"></a><a href="Ieee80211Mgmt.md">Ieee80211Mgmt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230072089165623"><a name="p1230072089165623"></a><a name="p1230072089165623"></a>Defines management frame information. </p>
</td>
</tr>
<tr id="row2075501728165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p479603897165623"><a name="p479603897165623"></a><a name="p479603897165623"></a><a href="ScannedBssInfo.md">ScannedBssInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310740975165623"><a name="p310740975165623"></a><a name="p310740975165623"></a>Represents the scanned BSS information. </p>
</td>
</tr>
<tr id="row1977592382165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p676941128165623"><a name="p676941128165623"></a><a name="p676941128165623"></a><a href="ConnetResult.md">ConnetResult</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419416930165623"><a name="p1419416930165623"></a><a name="p1419416930165623"></a>Defines association results. </p>
</td>
</tr>
<tr id="row1791043107165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20964878165623"><a name="p20964878165623"></a><a name="p20964878165623"></a><a href="HdfWifiProductData.md">HdfWifiProductData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882235283165623"><a name="p1882235283165623"></a><a name="p1882235283165623"></a>Defines the WLAN module. </p>
</td>
</tr>
<tr id="row229694312165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2146529489165623"><a name="p2146529489165623"></a><a name="p2146529489165623"></a><a href="EtherHeader.md">EtherHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1925964438165623"><a name="p1925964438165623"></a><a name="p1925964438165623"></a>Defines the Ethernet header information of a data frame, including the destination address, source address, and Ethernet type. </p>
</td>
</tr>
<tr id="row2128923004165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376451759165623"><a name="p376451759165623"></a><a name="p376451759165623"></a><a href="IpHeader.md">IpHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837503826165623"><a name="p1837503826165623"></a><a name="p1837503826165623"></a>Defines the IP header information of a data frame, including the version number, service type, and total length. </p>
</td>
</tr>
<tr id="row162207060165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190743031165623"><a name="p190743031165623"></a><a name="p190743031165623"></a><a href="UdpHeader.md">UdpHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1820690897165623"><a name="p1820690897165623"></a><a name="p1820690897165623"></a>Defines the UDP header information of a data frame, including the source port number and destination port number. </p>
</td>
</tr>
<tr id="row952880007165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884738833165623"><a name="p884738833165623"></a><a name="p884738833165623"></a><a href="TcpHeader.md">TcpHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719789121165623"><a name="p1719789121165623"></a><a name="p1719789121165623"></a>Defines the TCP header information of a data frame, including the source port number and destination port number. </p>
</td>
</tr>
<tr id="row195078643165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548304672165623"><a name="p1548304672165623"></a><a name="p1548304672165623"></a><a href="IpV4Addr.md">IpV4Addr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2058170881165623"><a name="p2058170881165623"></a><a name="p2058170881165623"></a>Defines an IPv4 address. </p>
</td>
</tr>
<tr id="row2054504761165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1558354572165623"><a name="p1558354572165623"></a><a name="p1558354572165623"></a><a href="NetDevNotify.md">NetDevNotify</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474270586165623"><a name="p1474270586165623"></a><a name="p1474270586165623"></a>Defines a network device notification, including an IP address and the notification type. </p>
</td>
</tr>
<tr id="row1619871040165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1588664993165623"><a name="p1588664993165623"></a><a name="p1588664993165623"></a><a href="IfType.md">IfType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423917234165623"><a name="p423917234165623"></a><a name="p423917234165623"></a>Defines the network port type, for example, the WLAN network port. </p>
</td>
</tr>
<tr id="row2094907501165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961544399165623"><a name="p961544399165623"></a><a name="p961544399165623"></a><a href="IfReq.md">IfReq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378178134165623"><a name="p378178134165623"></a><a name="p378178134165623"></a>Defines ioctrl data. </p>
</td>
</tr>
<tr id="row1734839853165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p663898200165623"><a name="p663898200165623"></a><a name="p663898200165623"></a><a href="NetDevice.md">NetDevice</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034462841165623"><a name="p2034462841165623"></a><a name="p2034462841165623"></a>Defines a network device, including the network interface category and name, and network port type. </p>
</td>
</tr>
<tr id="row1292616453165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1383846538165623"><a name="p1383846538165623"></a><a name="p1383846538165623"></a><a href="NetDeviceInterFace.md">NetDeviceInterFace</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p87260660165623"><a name="p87260660165623"></a><a name="p87260660165623"></a>Defines interfaces that need to be implemented externally by network devices, including initializing, opening, and closing a network device. </p>
</td>
</tr>
<tr id="row294114168165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110247068165623"><a name="p110247068165623"></a><a name="p110247068165623"></a><a href="KeyParams.md">KeyParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353634879165623"><a name="p1353634879165623"></a><a name="p1353634879165623"></a>Describes a key. </p>
</td>
</tr>
<tr id="row1738570332165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110677895165623"><a name="p2110677895165623"></a><a name="p2110677895165623"></a><a href="Ieee80211Channel.md">Ieee80211Channel</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961478534165623"><a name="p1961478534165623"></a><a name="p1961478534165623"></a>Describes a communication channel. </p>
</td>
</tr>
<tr id="row664099954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1293383741165623"><a name="p1293383741165623"></a><a name="p1293383741165623"></a><a href="Ieee80211Rate.md">Ieee80211Rate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p915099115165623"><a name="p915099115165623"></a><a name="p915099115165623"></a>Describes the IEEE 802.11 rate. </p>
</td>
</tr>
<tr id="row1720611307165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313469272165623"><a name="p313469272165623"></a><a name="p313469272165623"></a><a href="Ieee80211McsInfo.md">Ieee80211McsInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671753839165623"><a name="p1671753839165623"></a><a name="p1671753839165623"></a>Describes IEEE 802.11 Modulation and Coding Scheme (MCS) information. </p>
</td>
</tr>
<tr id="row1461691899165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281843201165623"><a name="p1281843201165623"></a><a name="p1281843201165623"></a><a href="Ieee80211StaHtCap.md">Ieee80211StaHtCap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1773843163165623"><a name="p1773843163165623"></a><a name="p1773843163165623"></a>Describes the IEEE 802.11 high-throughput (HT) capability. </p>
</td>
</tr>
<tr id="row296633902165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722570252165623"><a name="p1722570252165623"></a><a name="p1722570252165623"></a><a href="Ieee80211SupportedBand.md">Ieee80211SupportedBand</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2049458886165623"><a name="p2049458886165623"></a><a name="p2049458886165623"></a>Describes IEEE 802.11 band information. </p>
</td>
</tr>
<tr id="row2092776920165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p969887823165623"><a name="p969887823165623"></a><a name="p969887823165623"></a><a href="Wiphy.md">Wiphy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154375154165623"><a name="p1154375154165623"></a><a name="p1154375154165623"></a>Describes a wiphy device. </p>
</td>
</tr>
<tr id="row1677874966165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410394324165623"><a name="p1410394324165623"></a><a name="p1410394324165623"></a><a href="WifiSsid.md">WifiSsid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132857552165623"><a name="p2132857552165623"></a><a name="p2132857552165623"></a>Describes an SSID. </p>
</td>
</tr>
<tr id="row1805108493165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p280052499165623"><a name="p280052499165623"></a><a name="p280052499165623"></a><a href="ChannelDef.md">ChannelDef</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572568190165623"><a name="p1572568190165623"></a><a name="p1572568190165623"></a>Describes a communication channel. </p>
</td>
</tr>
<tr id="row1489984246165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504479770165623"><a name="p1504479770165623"></a><a name="p1504479770165623"></a><a href="WirelessDev.md">WirelessDev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637830692165623"><a name="p1637830692165623"></a><a name="p1637830692165623"></a>Describes a wireless device. </p>
</td>
</tr>
<tr id="row351516781165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611121072165623"><a name="p611121072165623"></a><a name="p611121072165623"></a><a href="WifiScanRequest.md">WifiScanRequest</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982362165165623"><a name="p1982362165165623"></a><a name="p1982362165165623"></a>Describes scan request parameters. </p>
</td>
</tr>
<tr id="row807233549165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725580724165623"><a name="p1725580724165623"></a><a name="p1725580724165623"></a><a href="CryptoSettings.md">CryptoSettings</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p358190592165623"><a name="p358190592165623"></a><a name="p358190592165623"></a>Describes cryptography settings. </p>
</td>
</tr>
<tr id="row2084965412165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352328293165623"><a name="p1352328293165623"></a><a name="p1352328293165623"></a><a href="MacAddress.md">MacAddress</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926317739165623"><a name="p1926317739165623"></a><a name="p1926317739165623"></a>Describes the device MAC address. </p>
</td>
</tr>
<tr id="row1712619370165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p302433076165623"><a name="p302433076165623"></a><a name="p302433076165623"></a><a href="WifiConnectParams.md">WifiConnectParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1210356430165623"><a name="p1210356430165623"></a><a name="p1210356430165623"></a>Describes parameters for a connection request. </p>
</td>
</tr>
<tr id="row1536025314165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608637957165623"><a name="p608637957165623"></a><a name="p608637957165623"></a><a href="VifParams.md">VifParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p251497753165623"><a name="p251497753165623"></a><a name="p251497753165623"></a>Describes virtual API parameters. </p>
</td>
</tr>
<tr id="row1240526196165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p184731660165623"><a name="p184731660165623"></a><a name="p184731660165623"></a><a href="StationDelParameters.md">StationDelParameters</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1007146475165623"><a name="p1007146475165623"></a><a name="p1007146475165623"></a>Describes parameters for canceling a connection. </p>
</td>
</tr>
<tr id="row1546453905165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1046749716165623"><a name="p1046749716165623"></a><a name="p1046749716165623"></a><a href="MacConfigParam.md">MacConfigParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900563244165623"><a name="p1900563244165623"></a><a name="p1900563244165623"></a>Describes MAC configuration parameters. </p>
</td>
</tr>
<tr id="row1746059634165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p677614881165623"><a name="p677614881165623"></a><a name="p677614881165623"></a><a href="Mac80211DisconnectParam.md">Mac80211DisconnectParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1386848848165623"><a name="p1386848848165623"></a><a name="p1386848848165623"></a>Describes disconnection parameters. </p>
</td>
</tr>
<tr id="row373645175165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344670290165623"><a name="p1344670290165623"></a><a name="p1344670290165623"></a><a href="Mac80211Ssids.md">Mac80211Ssids</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346564230165623"><a name="p346564230165623"></a><a name="p346564230165623"></a>Describes SSIDs. </p>
</td>
</tr>
<tr id="row979043112165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097848124165623"><a name="p2097848124165623"></a><a name="p2097848124165623"></a><a href="Mac80211beaconParam.md">Mac80211beaconParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p750916115165623"><a name="p750916115165623"></a><a name="p750916115165623"></a>Describes beacon parameters. </p>
</td>
</tr>
<tr id="row1323102466165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p857495643165623"><a name="p857495643165623"></a><a name="p857495643165623"></a><a href="WifiMac80211Ops.md">WifiMac80211Ops</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787161235165623"><a name="p1787161235165623"></a><a name="p1787161235165623"></a>Describes MAC-layer control APIs that need to be implemented by the driver. </p>
</td>
</tr>
<tr id="row773495619165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p99867967165623"><a name="p99867967165623"></a><a name="p99867967165623"></a><a href="WifiModuleIface.md">WifiModuleIface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p931210094165623"><a name="p931210094165623"></a><a name="p931210094165623"></a>Defines WLAN module APIs. </p>
</td>
</tr>
<tr id="row530639247165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p224875363165623"><a name="p224875363165623"></a><a name="p224875363165623"></a><a href="WifiModule.md">WifiModule</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070293534165623"><a name="p2070293534165623"></a><a name="p2070293534165623"></a>Defines the WLAN module. </p>
</td>
</tr>
<tr id="row1077543611165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720301763165623"><a name="p720301763165623"></a><a name="p720301763165623"></a><a href="WifiFeature.md">WifiFeature</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1273133757165623"><a name="p1273133757165623"></a><a name="p1273133757165623"></a>Defines a WLAN feature. </p>
</td>
</tr>
<tr id="row611247905165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1379542259165623"><a name="p1379542259165623"></a><a name="p1379542259165623"></a><a href="WifiFeatureList.md">WifiFeatureList</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406868667165623"><a name="p406868667165623"></a><a name="p406868667165623"></a>Defines the WLAN feature list. </p>
</td>
</tr>
<tr id="row1847202747165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p409142027165623"><a name="p409142027165623"></a><a name="p409142027165623"></a><a href="HdfWifiChipData.md">HdfWifiChipData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1856603481165623"><a name="p1856603481165623"></a><a name="p1856603481165623"></a>Defines a WLAN chip. </p>
</td>
</tr>
<tr id="row448260009165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140396579165623"><a name="p1140396579165623"></a><a name="p1140396579165623"></a><a href="WifiModuleConfig.md">WifiModuleConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998916052165623"><a name="p1998916052165623"></a><a name="p1998916052165623"></a>Defines the WLAN module configuration. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table635583133165623"></a>
<table><thead align="left"><tr id="row1323651212165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p227312634165623"><a name="p227312634165623"></a><a name="p227312634165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2129102097165623"><a name="p2129102097165623"></a><a name="p2129102097165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1496916819165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720143120165623"><a name="p1720143120165623"></a><a name="p1720143120165623"></a><a href="WLAN.md#ga794c035a19a38acc000146a8f9a4ec80">MAX_NETBUF_RESEVER_SIZE</a>   68</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p555598009165623"><a name="p555598009165623"></a><a name="p555598009165623"></a>Defines the reserved field of a network data buffer used to store private information. </p>
</td>
</tr>
<tr id="row1203620365165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p353519342165623"><a name="p353519342165623"></a><a name="p353519342165623"></a><em id="gae01dbae885bc8abecb82bd865515c081"><a name="gae01dbae885bc8abecb82bd865515c081"></a><a name="gae01dbae885bc8abecb82bd865515c081"></a></em>MAC_ADDR_SIZE    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32781815165623"><a name="p32781815165623"></a><a name="p32781815165623"></a>Indicates a 6-byte MAC address. </p>
</td>
</tr>
<tr id="row177840924165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489950455165623"><a name="p489950455165623"></a><a name="p489950455165623"></a><em id="gad9c939a90358c2cb6b788af7b84821a1"><a name="gad9c939a90358c2cb6b788af7b84821a1"></a><a name="gad9c939a90358c2cb6b788af7b84821a1"></a></em>NET_DEVICE_IFF_RUNNING    IFF_RUNNING</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759484837165623"><a name="p1759484837165623"></a><a name="p1759484837165623"></a>Indicates that the network port is working. </p>
</td>
</tr>
<tr id="row422291109165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1398864206165623"><a name="p1398864206165623"></a><a name="p1398864206165623"></a><em id="ga74e41a940b9c245f2bc8eaba01d4cee2"><a name="ga74e41a940b9c245f2bc8eaba01d4cee2"></a><a name="ga74e41a940b9c245f2bc8eaba01d4cee2"></a></em>ETHER_TYPE_RARP    0x8035</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163513386165623"><a name="p163513386165623"></a><a name="p163513386165623"></a>Indicates Reverse Address Resolution Protocol (RARP). </p>
</td>
</tr>
<tr id="row429424235165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1015060826165623"><a name="p1015060826165623"></a><a name="p1015060826165623"></a><em id="ga3bc75b7ed75e7da0abf818f0f1a769d3"><a name="ga3bc75b7ed75e7da0abf818f0f1a769d3"></a><a name="ga3bc75b7ed75e7da0abf818f0f1a769d3"></a></em>ETHER_TYPE_PAE    0x888e</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360557435165623"><a name="p360557435165623"></a><a name="p360557435165623"></a>Indicates Port Access Entity (PAE). </p>
</td>
</tr>
<tr id="row1161213795165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1842965569165623"><a name="p1842965569165623"></a><a name="p1842965569165623"></a><em id="ga61a8e2c9705e0c7000235c60639f3f97"><a name="ga61a8e2c9705e0c7000235c60639f3f97"></a><a name="ga61a8e2c9705e0c7000235c60639f3f97"></a></em>ETHER_TYPE_IP    0x0800</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p685834469165623"><a name="p685834469165623"></a><a name="p685834469165623"></a>Indicates Internet Protocol (IP). </p>
</td>
</tr>
<tr id="row826351303165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2044979119165623"><a name="p2044979119165623"></a><a name="p2044979119165623"></a><em id="ga4759f448b5669a1f33ff7d6912a1b131"><a name="ga4759f448b5669a1f33ff7d6912a1b131"></a><a name="ga4759f448b5669a1f33ff7d6912a1b131"></a></em>ETHER_TYPE_AARP    0x80f3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p877420508165623"><a name="p877420508165623"></a><a name="p877420508165623"></a>Indicates AppleTalk Address Resolution Protocol (AARP). </p>
</td>
</tr>
<tr id="row2040265014165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574715319165623"><a name="p1574715319165623"></a><a name="p1574715319165623"></a><em id="gaa0b348d7d0f58adb49e152c79b93b519"><a name="gaa0b348d7d0f58adb49e152c79b93b519"></a><a name="gaa0b348d7d0f58adb49e152c79b93b519"></a></em>ETHER_TYPE_IPX    0x8137</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489099308165623"><a name="p489099308165623"></a><a name="p489099308165623"></a>Indicates Internetwork Packet Exchange (IPX). </p>
</td>
</tr>
<tr id="row465776818165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243560244165623"><a name="p1243560244165623"></a><a name="p1243560244165623"></a><em id="ga3f5d778e8eb1a7ad731921a460e6c1dd"><a name="ga3f5d778e8eb1a7ad731921a460e6c1dd"></a><a name="ga3f5d778e8eb1a7ad731921a460e6c1dd"></a></em>ETHER_TYPE_ARP    0x0806</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1577349237165623"><a name="p1577349237165623"></a><a name="p1577349237165623"></a>Indicates Address Resolution Protocol (ARP). </p>
</td>
</tr>
<tr id="row2066886850165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1658716955165623"><a name="p1658716955165623"></a><a name="p1658716955165623"></a><em id="gadd8fcb263b0d4f3e9c09aafe4c6b64e0"><a name="gadd8fcb263b0d4f3e9c09aafe4c6b64e0"></a><a name="gadd8fcb263b0d4f3e9c09aafe4c6b64e0"></a></em>ETHER_TYPE_IPV6    0x86dd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2056699740165623"><a name="p2056699740165623"></a><a name="p2056699740165623"></a>Indicates Internet Protocol version 6 (IPv6). </p>
</td>
</tr>
<tr id="row1691228778165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1445861210165623"><a name="p1445861210165623"></a><a name="p1445861210165623"></a><em id="ga0418380e708e716910958ed2aab3921d"><a name="ga0418380e708e716910958ed2aab3921d"></a><a name="ga0418380e708e716910958ed2aab3921d"></a></em>ETHER_TYPE_TDLS    0x890d</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507727522165623"><a name="p507727522165623"></a><a name="p507727522165623"></a>Indicates Tunneled Direct Link Setup (TDLS). </p>
</td>
</tr>
<tr id="row1089557485165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1951604656165623"><a name="p1951604656165623"></a><a name="p1951604656165623"></a><em id="gaaaa516211cec2b61e3717c5fec36952f"><a name="gaaaa516211cec2b61e3717c5fec36952f"></a><a name="gaaaa516211cec2b61e3717c5fec36952f"></a></em>ETHER_TYPE_VLAN    0x8100</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351626578165623"><a name="p351626578165623"></a><a name="p351626578165623"></a>Indicates Virtual Local Area Network (VLAN). </p>
</td>
</tr>
<tr id="row2094956775165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17849837165623"><a name="p17849837165623"></a><a name="p17849837165623"></a><em id="ga89fb6635bc0c9eab11de63ec141938a6"><a name="ga89fb6635bc0c9eab11de63ec141938a6"></a><a name="ga89fb6635bc0c9eab11de63ec141938a6"></a></em>ETHER_TYPE_WAI    0x88b4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p712557804165623"><a name="p712557804165623"></a><a name="p712557804165623"></a>Indicates WLAN Authentication and Privacy Infrastructure (WAPI). </p>
</td>
</tr>
<tr id="row700227297165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280971692165623"><a name="p1280971692165623"></a><a name="p1280971692165623"></a><em id="ga7da55985d58df9fac85217e1195d4b7c"><a name="ga7da55985d58df9fac85217e1195d4b7c"></a><a name="ga7da55985d58df9fac85217e1195d4b7c"></a></em>ETHER_LLTD_TYPE    0x88D9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p819228648165623"><a name="p819228648165623"></a><a name="p819228648165623"></a>Indicates Link Layer Topology Discovery (LLTD). </p>
</td>
</tr>
<tr id="row1263307066165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p182227824165623"><a name="p182227824165623"></a><a name="p182227824165623"></a><em id="ga0fb3b00b4300fcbd562e07d5f91aaca0"><a name="ga0fb3b00b4300fcbd562e07d5f91aaca0"></a><a name="ga0fb3b00b4300fcbd562e07d5f91aaca0"></a></em>ETHER_ONE_X_TYPE    0x888E</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p456739605165623"><a name="p456739605165623"></a><a name="p456739605165623"></a>Indicates 802.1x network port authentication. </p>
</td>
</tr>
<tr id="row1718544037165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1110824203165623"><a name="p1110824203165623"></a><a name="p1110824203165623"></a><em id="gaefd300f6277931e053c899367ad96536"><a name="gaefd300f6277931e053c899367ad96536"></a><a name="gaefd300f6277931e053c899367ad96536"></a></em>ETHER_TUNNEL_TYPE    0x88bd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2061069548165623"><a name="p2061069548165623"></a><a name="p2061069548165623"></a>Indicates a tunnel protocol. </p>
</td>
</tr>
<tr id="row1069751365165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1539637037165623"><a name="p1539637037165623"></a><a name="p1539637037165623"></a><em id="ga70914271e18c471460d1d00cec8af522"><a name="ga70914271e18c471460d1d00cec8af522"></a><a name="ga70914271e18c471460d1d00cec8af522"></a></em>ETHER_TYPE_PPP_DISC    0x8863</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72610417165623"><a name="p72610417165623"></a><a name="p72610417165623"></a>Indicates the point-to-point discovery type. </p>
</td>
</tr>
<tr id="row319180295165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1645959698165623"><a name="p1645959698165623"></a><a name="p1645959698165623"></a><em id="gaf4b193dda19de66eba7a99b64b3a0c6c"><a name="gaf4b193dda19de66eba7a99b64b3a0c6c"></a><a name="gaf4b193dda19de66eba7a99b64b3a0c6c"></a></em>ETHER_TYPE_PPP_SES    0x8864</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460139280165623"><a name="p460139280165623"></a><a name="p460139280165623"></a>Indicates the point-to-point session discovery type. </p>
</td>
</tr>
<tr id="row39587083165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p572691642165623"><a name="p572691642165623"></a><a name="p572691642165623"></a><em id="ga6fca23e8bd12854706021a45fe3cd352"><a name="ga6fca23e8bd12854706021a45fe3cd352"></a><a name="ga6fca23e8bd12854706021a45fe3cd352"></a></em>ETHER_TYPE_6LO    0xa0ed</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414780313165623"><a name="p1414780313165623"></a><a name="p1414780313165623"></a>Indicates IPv6 over Low Power Wireless Personal Area Networks (6LoWPANs). </p>
</td>
</tr>
<tr id="row86393245165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1037229240165623"><a name="p1037229240165623"></a><a name="p1037229240165623"></a><em id="ga96b31b1ec02746766191916559cec530"><a name="ga96b31b1ec02746766191916559cec530"></a><a name="ga96b31b1ec02746766191916559cec530"></a></em>TCP_PROTOCAL    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353434370165623"><a name="p1353434370165623"></a><a name="p1353434370165623"></a>Indicates the Transmission Control Protocol (TCP). </p>
</td>
</tr>
<tr id="row192341413165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1090974556165623"><a name="p1090974556165623"></a><a name="p1090974556165623"></a><em id="ga06cdba6ef1f4bc477016c6bbae7ce444"><a name="ga06cdba6ef1f4bc477016c6bbae7ce444"></a><a name="ga06cdba6ef1f4bc477016c6bbae7ce444"></a></em>UDP_PROTOCAL    17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898937943165623"><a name="p898937943165623"></a><a name="p898937943165623"></a>Indicates the User Datagram Protocol (UDP). </p>
</td>
</tr>
<tr id="row892156092165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391969473165623"><a name="p391969473165623"></a><a name="p391969473165623"></a><em id="gab7ea98963ef9a6aecac843b0ea6bbcee"><a name="gab7ea98963ef9a6aecac843b0ea6bbcee"></a><a name="gab7ea98963ef9a6aecac843b0ea6bbcee"></a></em>IP_PRI_SHIFT    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808214813165623"><a name="p808214813165623"></a><a name="p808214813165623"></a>Indicates the shift in the priority for an IP address. </p>
</td>
</tr>
<tr id="row1294682512165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861424148165623"><a name="p1861424148165623"></a><a name="p1861424148165623"></a><em id="ga2db7b9e1310a372d11d568e34958e158"><a name="ga2db7b9e1310a372d11d568e34958e158"></a><a name="ga2db7b9e1310a372d11d568e34958e158"></a></em>DHCP_UDP_SRC_PORT    68</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465737035165623"><a name="p465737035165623"></a><a name="p465737035165623"></a>Indicates the source port number of DHCP. </p>
</td>
</tr>
<tr id="row162558238165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352402113165623"><a name="p1352402113165623"></a><a name="p1352402113165623"></a><em id="gad92d590d45b6f76db61dd87fed7fa770"><a name="gad92d590d45b6f76db61dd87fed7fa770"></a><a name="gad92d590d45b6f76db61dd87fed7fa770"></a></em>DHCP_UDP_DES_PORT    67</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733730856165623"><a name="p733730856165623"></a><a name="p733730856165623"></a>Indicates the destination port number of DHCP. </p>
</td>
</tr>
<tr id="row885642192165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1368066831165623"><a name="p1368066831165623"></a><a name="p1368066831165623"></a><a href="WLAN.md#gaf460a45a5e365279ca6bc5b3e8750542">MAX_WIFI_COMPONENT_NAME_LEN</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1020571138165623"><a name="p1020571138165623"></a><a name="p1020571138165623"></a>Indicates the length of the name of a WLAN module or feature. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1908725281165623"></a>
<table><thead align="left"><tr id="row1693708241165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2076720561165623"><a name="p2076720561165623"></a><a name="p2076720561165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1015282665165623"><a name="p1015282665165623"></a><a name="p1015282665165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1242765302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209061690165623"><a name="p209061690165623"></a><a name="p209061690165623"></a><a href="WLAN.md#gac26e4b0cda623f27420f9ce77befbb1f">NetDevice</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p253115207165623"><a name="p253115207165623"></a><a name="p253115207165623"></a>typedef struct <a href="NetDevice.md">NetDevice</a> </p>
<p id="p1004388936165623"><a name="p1004388936165623"></a><a name="p1004388936165623"></a>Defines a network device, including the network interface category and name, and network port type. </p>
</td>
</tr>
<tr id="row199454143165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p324472191165623"><a name="p324472191165623"></a><a name="p324472191165623"></a><a href="WLAN.md#ga3e8945c521d2392cb775494570c560b3">WifiConnectParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533247524165623"><a name="p533247524165623"></a><a name="p533247524165623"></a>typedef struct <a href="WifiConnectParams.md">WifiConnectParams</a> </p>
<p id="p475282547165623"><a name="p475282547165623"></a><a name="p475282547165623"></a>Describes parameters for a connection request. </p>
</td>
</tr>
<tr id="row424423766165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p634955239165623"><a name="p634955239165623"></a><a name="p634955239165623"></a><a href="WLAN.md#ga85f7d8a3795887f090e0a6439b1df6e1">Mac80211SetMacParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628996126165623"><a name="p628996126165623"></a><a name="p628996126165623"></a>typedef struct <a href="MacConfigParam.md">MacConfigParam</a> </p>
<p id="p1003291936165623"><a name="p1003291936165623"></a><a name="p1003291936165623"></a>Describes MAC configuration parameters. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table550218603165623"></a>
<table><thead align="left"><tr id="row1491422980165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p893734043165623"><a name="p893734043165623"></a><a name="p893734043165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p604866675165623"><a name="p604866675165623"></a><a name="p604866675165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row911897847165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1543638712165623"><a name="p1543638712165623"></a><a name="p1543638712165623"></a>{ <a href="WLAN.md#ggafa231099d07583c3ed0981e0bb665f55a0e4808dd476b314c0fdbf417307f8b92">E_HEAD_BUF</a>, <a href="WLAN.md#ggafa231099d07583c3ed0981e0bb665f55a4b374b76d2b9bb60c31a1a540369b6d4">E_DATA_BUF</a>, <a href="WLAN.md#ggafa231099d07583c3ed0981e0bb665f55a316baeacb77ecf28631a76f1dbea872d">E_TAIL_BUF</a>, <a href="WLAN.md#ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19">MAX_BUF_NUM</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2036563036165623"><a name="p2036563036165623"></a><a name="p2036563036165623"></a>Enumerates the segments of a network data buffer. </p>
</td>
</tr>
<tr id="row1836662132165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934800772165623"><a name="p1934800772165623"></a><a name="p1934800772165623"></a><a href="WLAN.md#gaf3e873b51f0cfa077aca9d33ed7a0960">WifiHmacMgmtStatus</a> {   <a href="WLAN.md#ggaf3e873b51f0cfa077aca9d33ed7a0960ad9c7e2f362bd6fcadef189fa2a5d7c63">WIFI_HMAC_MGMT_SUCCESS</a> = 0, <a href="WLAN.md#ggaf3e873b51f0cfa077aca9d33ed7a0960a539c65a358a20b9731fc66fc60ebcbc2">WIFI_HMAC_MGMT_INVALID</a> = 1, <a href="WLAN.md#ggaf3e873b51f0cfa077aca9d33ed7a0960ad1731acef8ddb8c50bcc26ae80fa83a3">WIFI_HMAC_MGMT_TIMEOUT</a> = 2, <a href="WLAN.md#ggaf3e873b51f0cfa077aca9d33ed7a0960a05f532edadae3b6afc80b7575dd46961">WIFI_HMAC_MGMT_REFUSED</a> = 3,   <a href="WLAN.md#ggaf3e873b51f0cfa077aca9d33ed7a0960a9e241ef81e72de130e1fda573ce2a412">WIFI_HMAC_MGMT_TOMANY_REQ</a> = 4, <a href="WLAN.md#ggaf3e873b51f0cfa077aca9d33ed7a0960aa3db4634dc2727e029aef13384bc3940">WIFI_HMAC_MGMT_ALREADY_BSS</a> = 5 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72579841165623"><a name="p72579841165623"></a><a name="p72579841165623"></a>Enumerates MLME management statuses, indicating whether a device is successfully associated or fails to be associated. </p>
</td>
</tr>
<tr id="row1518575911165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337573540165623"><a name="p337573540165623"></a><a name="p337573540165623"></a><a href="WLAN.md#ga530241881cd17e03f8ae254ef1d9755e">NetIfCategory</a> { <a href="WLAN.md#gga530241881cd17e03f8ae254ef1d9755eaab9c78d744764e8f66591ee4a8d7b3cb">LITE_OS</a>, <a href="WLAN.md#gga530241881cd17e03f8ae254ef1d9755eafdfffeab76fab0306aa033c650ae0cfa">RICH_OS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345698794165623"><a name="p1345698794165623"></a><a name="p1345698794165623"></a>Enumerates network interface categories, including lightweight OS and rich OS. </p>
</td>
</tr>
<tr id="row220090365165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1488010500165623"><a name="p1488010500165623"></a><a name="p1488010500165623"></a><a href="WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf">NetIfStatus</a> { <a href="WLAN.md#gga0fb482694e5eac3f48c75de1749c8bafaeda2ad3830d5a42070617fd0211baf95">NETIF_DOWN</a>, <a href="WLAN.md#gga0fb482694e5eac3f48c75de1749c8bafa64a69f6624102c11bd658c09daf0f865">NETIF_UP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2097386489165623"><a name="p2097386489165623"></a><a name="p2097386489165623"></a>Enumerates network interface states, including online and offline. </p>
</td>
</tr>
<tr id="row1016759156165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406763373165623"><a name="p1406763373165623"></a><a name="p1406763373165623"></a><a href="WLAN.md#ga7b1187d116fb065d7927ad9f77edd842">NetIfLinkStatus</a> { <a href="WLAN.md#gga7b1187d116fb065d7927ad9f77edd842a8586d0e791ca4f7026853d85740650b5">NETIF_LINK_DOWN</a>, <a href="WLAN.md#gga7b1187d116fb065d7927ad9f77edd842ac3108dbea78b5f0f928e6e5e4ea045f2">NETIF_LINK_UP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1798639983165623"><a name="p1798639983165623"></a><a name="p1798639983165623"></a>Enumerates network link layer states, including online and offline. </p>
</td>
</tr>
<tr id="row144236028165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1683230492165623"><a name="p1683230492165623"></a><a name="p1683230492165623"></a><a href="WLAN.md#gad3175955d2e6ef3c4f52da9b509d5b4a">NetLinkType</a> { <a href="WLAN.md#ggad3175955d2e6ef3c4f52da9b509d5b4aa2d49c28127ce1d558ad5ea2f92e89fd7">ETHERNET_LINK</a> = 1, <a href="WLAN.md#ggad3175955d2e6ef3c4f52da9b509d5b4aadfed684cd7f64cc1aea5944657866db6">WIFI_LINK</a> = 801 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025753776165623"><a name="p2025753776165623"></a><a name="p2025753776165623"></a>Enumerates data link types, including Ethernet and WLAN. </p>
</td>
</tr>
<tr id="row1291970315165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879017785165623"><a name="p879017785165623"></a><a name="p879017785165623"></a><a href="WLAN.md#ga9c1d6e7df4468671742cb76f72b67af1">ProcessingResult</a> { <a href="WLAN.md#gga9c1d6e7df4468671742cb76f72b67af1a5ce4c56e88c31420a02d3b7f068e0799">PROCESSING_CONTINUE</a>, <a href="WLAN.md#gga9c1d6e7df4468671742cb76f72b67af1a2fcbb133dcd739ab4a04b00bececd70a">PROCESSING_COMPLETE</a>, <a href="WLAN.md#gga9c1d6e7df4468671742cb76f72b67af1afe177a1b88ea1cdcc0e41181c2c73e83">PROCESSING_ERROR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249276487165623"><a name="p249276487165623"></a><a name="p249276487165623"></a>Enumerates data processing results, including continuing processing, processing completed, and error. </p>
</td>
</tr>
<tr id="row1685910440165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p398517042165623"><a name="p398517042165623"></a><a name="p398517042165623"></a><a href="WLAN.md#ga9fb4e578a15db1b0087d7b3831591ced">NetDevTxResult</a> { <a href="WLAN.md#gga9fb4e578a15db1b0087d7b3831591ceda734cacd083ffc8d233cab8d4deb6b38b">NETDEV_TX_OK</a> = 0x00, <a href="WLAN.md#gga9fb4e578a15db1b0087d7b3831591cedaf0a0ac437358f6af42c3e38795c46d35">NETDEV_TX_BUSY</a> = 0x10, <a href="WLAN.md#gga9fb4e578a15db1b0087d7b3831591ceda7eb70cee5761fe8954f94b660c37eaa8">NETDEV_TX_LOCKED</a> = 0x20 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199940643165623"><a name="p1199940643165623"></a><a name="p1199940643165623"></a>Enumerates data sending results, including sending succeeded, other data being sent at the link layer, and data link layer being locked. </p>
</td>
</tr>
<tr id="row1307087964165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1197673627165623"><a name="p1197673627165623"></a><a name="p1197673627165623"></a><a href="WLAN.md#gac69954f56fcc99fc8aac68aa157831c7">Protocol80211IfType</a> {   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a6b209b916aabd18f2a950a82e68b6a4c">PROTOCOL_80211_IFTYPE_UNSPECIFIED</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a0926a98ddc2ceec4ba58ebfc01c5fe35">PROTOCOL_80211_IFTYPE_ADHOC</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7acd26f8cefbd658e9ea02feecefd054fb">PROTOCOL_80211_IFTYPE_STATION</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a9e92654b9ab6ed6eb62868f1e0e4ea8f">PROTOCOL_80211_IFTYPE_AP</a>,   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a991ad1a3f8c43b06c4eeb9dc88acdb1e">PROTOCOL_80211_IFTYPE_AP_VLAN</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7aa25631c32cd6c996a7c96ba4f61299e2">PROTOCOL_80211_IFTYPE_WDS</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a3ff1c1358af5a0c50b64e0ef0e96a970">PROTOCOL_80211_IFTYPE_MONITOR</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a382756b8a71015cd536cdbc113c4f483">PROTOCOL_80211_IFTYPE_MESH_POINT</a>,   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7acfd81d6e484c6f7a3b863327af112cfc">PROTOCOL_80211_IFTYPE_P2P_CLIENT</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7abca0ccb5cf4c14af9b6ff0bd9eeb4173">PROTOCOL_80211_IFTYPE_P2P_GO</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7ad63ad4a5a66892e842e4d75cc82b0755">PROTOCOL_80211_IFTYPE_P2P_DEVICE</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a7f1fa9726ab20597baaa9ebf884b26cd">PROTOCOL_80211_IFTYPE_NUM</a>,   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a37b72ea7c4cd81dd4c427e2d721c9499">PROTOCOL_80211_IFTYPE_MAX</a> = PROTOCOL_80211_IFTYPE_NUM - 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p837371553165623"><a name="p837371553165623"></a><a name="p837371553165623"></a>Enumerates 802.11 network port types, including AP, STA, and P2P. </p>
</td>
</tr>
<tr id="row1696063822165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1524990281165623"><a name="p1524990281165623"></a><a name="p1524990281165623"></a><a href="WLAN.md#ga9023c5dc1cc43758cbb468d78af41c2d">NetdeviceError</a> { <a href="WLAN.md#gga9023c5dc1cc43758cbb468d78af41c2dafe771f5d0d84d17922f466d3eed83d6b">COMMON_ERROR</a> = 1, <a href="WLAN.md#gga9023c5dc1cc43758cbb468d78af41c2daf5426609de8db5782b340a6bcd7e94d6">ADD_LWIP_ERROR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1563757272165623"><a name="p1563757272165623"></a><a name="p1563757272165623"></a>Enumerates network device errors, including common errors and errors in adding network devices to LwIP. </p>
</td>
</tr>
<tr id="row106509080165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p942109149165623"><a name="p942109149165623"></a><a name="p942109149165623"></a><a href="WLAN.md#gaec03ba36d71cc2d5f3209bc24aa6ee10">WifiMainFeatureType</a> {   <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10a038fb1847d290b75b15949b6471b46ad">HDF_WIFI_FEATURE_BASE</a>, <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10aaec6c1686d47187e64fd108e0e797133">HDF_WIFI_FEATURE_AP</a>, <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10a0e814bd1cfc59a253cc575d3548a9d4e">HDF_WIFI_FEATURE_STA</a>, <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10a8e87c1727fa86bf92ee05cad85e7f872">HDF_WIFI_FEATURE_P2P</a>,   <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10ae30b51638bc2c2fb739b3ddec6c5b92b">HDF_WIFI_FEATURE_NAN</a>, <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10ac12422e335003fbd392bff47c53c0352">HDF_WIFI_FEATURE_RTT</a>, <a href="WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10a28ff5971d579c1754e03a5f79a0c9e6f">HDF_WIFI_FEATURE_NUM</a> = 10 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410130354165623"><a name="p1410130354165623"></a><a name="p1410130354165623"></a>Enumerates feature types of a WLAN module. </p>
</td>
</tr>
<tr id="row274892224165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203303710165623"><a name="p1203303710165623"></a><a name="p1203303710165623"></a><a href="WLAN.md#ga1c5537e64f05b5e91b951ddeb66d4261">WifiBusType</a> { <a href="WLAN.md#gga1c5537e64f05b5e91b951ddeb66d4261a0eba50f5eecb33326083a82adbaa0848">BUS_SDIO</a>, <a href="WLAN.md#gga1c5537e64f05b5e91b951ddeb66d4261a2f4f9ff60278d511660c21e211133666">BUS_USB</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1997474097165623"><a name="p1997474097165623"></a><a name="p1997474097165623"></a>Enumerates bus types of a WLAN module. </p>
</td>
</tr>
<tr id="row850330285165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2118686062165623"><a name="p2118686062165623"></a><a name="p2118686062165623"></a><a href="WLAN.md#ga75cba3dc6ab4c5dc5653b037433b3abf">MacSetType</a> { <a href="WLAN.md#gga75cba3dc6ab4c5dc5653b037433b3abfa52532b66ba237505f04a57b382f67cb1">MAC_BEACON_SET</a> = 0, <a href="WLAN.md#gga75cba3dc6ab4c5dc5653b037433b3abfa8bb6332eadf8a54cdcf7d02b6040e7f3">MAC_BEACON_ADD</a> = 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671671255165623"><a name="p1671671255165623"></a><a name="p1671671255165623"></a>Enumerates setting types of MAC addresses. </p>
</td>
</tr>
<tr id="row713703085165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613198740165623"><a name="p613198740165623"></a><a name="p613198740165623"></a><a href="WLAN.md#ga9882f415202cf9acb0f4cdfbc456a88d">Ieee80211Band</a> { <a href="WLAN.md#gga9882f415202cf9acb0f4cdfbc456a88daf339f82c036557f42f668a358aa96da3">IEEE80211_BAND_2GHZ</a>, <a href="WLAN.md#gga9882f415202cf9acb0f4cdfbc456a88da0871c8866251ec4e668e956bb0427cfa">IEEE80211_BAND_5GHZ</a>, <a href="WLAN.md#gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4">IEEE80211_NUM_BANDS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1127938629165623"><a name="p1127938629165623"></a><a name="p1127938629165623"></a>Enumerates frequency bands. </p>
</td>
</tr>
<tr id="row1458172530165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423924644165623"><a name="p423924644165623"></a><a name="p423924644165623"></a><a href="WLAN.md#ga9d902b330de99c24b2a8c3ba7120af21">WifiChannelType</a> { <a href="WLAN.md#gga9d902b330de99c24b2a8c3ba7120af21ae0707e29a1748ee7f33d51acabaf8810">WIFI_CHAN_NO_HT</a>, <a href="WLAN.md#gga9d902b330de99c24b2a8c3ba7120af21a255f513fd4efa8bce0c015086e0588ea">WIFI_CHAN_HT20</a>, <a href="WLAN.md#gga9d902b330de99c24b2a8c3ba7120af21a1c6dbd2c2f6be59e4fa8312fe6009a98">WIFI_CHAN_HT40MINUS</a>, <a href="WLAN.md#gga9d902b330de99c24b2a8c3ba7120af21abdc85daa4bd2fdda2cfb14a975099652">WIFI_CHAN_HT40PLUS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p651208760165623"><a name="p651208760165623"></a><a name="p651208760165623"></a>Enumerates channel types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1027767822165623"></a>
<table><thead align="left"><tr id="row15794426165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p965404748165623"><a name="p965404748165623"></a><a name="p965404748165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p351468615165623"><a name="p351468615165623"></a><a name="p351468615165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row62740678165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1599434364165623"><a name="p1599434364165623"></a><a name="p1599434364165623"></a><a href="WLAN.md#ga6e754d5529b23b413d1fe00102a95db9">NetBufQueueInit</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652294344165623"><a name="p652294344165623"></a><a name="p652294344165623"></a>static void </p>
<p id="p504241971165623"><a name="p504241971165623"></a><a name="p504241971165623"></a>Initializes a network data buffer queue. </p>
</td>
</tr>
<tr id="row236716394165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560660531165623"><a name="p1560660531165623"></a><a name="p1560660531165623"></a><a href="WLAN.md#gaaa5c00efd1dedecf846af4dd108b6701">NetBufQueueSize</a> (const struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050821884165623"><a name="p2050821884165623"></a><a name="p2050821884165623"></a>static uint32_t </p>
<p id="p508705470165623"><a name="p508705470165623"></a><a name="p508705470165623"></a>Obtains the size of a network data buffer queue. </p>
</td>
</tr>
<tr id="row985153518165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453620445165623"><a name="p1453620445165623"></a><a name="p1453620445165623"></a><a href="WLAN.md#ga36297284c60746f2b6895d94ea5e2dc3">NetBufQueueIsEmpty</a> (const struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482037285165623"><a name="p482037285165623"></a><a name="p482037285165623"></a>static bool </p>
<p id="p1265008379165623"><a name="p1265008379165623"></a><a name="p1265008379165623"></a>Checks whether the network data buffer queue is empty. </p>
</td>
</tr>
<tr id="row589450793165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466614723165623"><a name="p466614723165623"></a><a name="p466614723165623"></a><a href="WLAN.md#ga25bf5d56e8afec1bc80080b20c3b7daa">NetBufQueueEnqueue</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q, struct <a href="NetBuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068415640165623"><a name="p1068415640165623"></a><a name="p1068415640165623"></a>void </p>
<p id="p1250540658165623"><a name="p1250540658165623"></a><a name="p1250540658165623"></a>Adds a network data buffer to the tail of a queue. </p>
</td>
</tr>
<tr id="row1565565723165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2115225588165623"><a name="p2115225588165623"></a><a name="p2115225588165623"></a><a href="WLAN.md#ga5ebe7aff6d5187645869f067b0a8f659">NetBufQueueEnqueueHead</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q, struct <a href="NetBuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1075190876165623"><a name="p1075190876165623"></a><a name="p1075190876165623"></a>void </p>
<p id="p1560947635165623"><a name="p1560947635165623"></a><a name="p1560947635165623"></a>Adds a network data buffer to the header of a queue. </p>
</td>
</tr>
<tr id="row238407836165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579485104165623"><a name="p579485104165623"></a><a name="p579485104165623"></a><a href="WLAN.md#ga4ad66d7ca7aabda3aef08fa541dc9ee4">NetBufQueueDequeue</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480774493165623"><a name="p1480774493165623"></a><a name="p1480774493165623"></a>struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p2035473288165623"><a name="p2035473288165623"></a><a name="p2035473288165623"></a>Obtains a network data buffer from the header of a queue and deletes it from the queue. </p>
</td>
</tr>
<tr id="row1432834433165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33248088165623"><a name="p33248088165623"></a><a name="p33248088165623"></a><a href="WLAN.md#ga390319a0419c26c73552bcee6b8d5c32">NetBufQueueDequeueTail</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1987402885165623"><a name="p1987402885165623"></a><a name="p1987402885165623"></a>struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p344162811165623"><a name="p344162811165623"></a><a name="p344162811165623"></a>Obtains a network data buffer from the tail of a queue and deletes it from the queue. </p>
</td>
</tr>
<tr id="row790380873165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838378454165623"><a name="p1838378454165623"></a><a name="p1838378454165623"></a><a href="WLAN.md#ga082b7a173ca09288c3b418ce4e4faa7d">NetBufQueueAtHead</a> (const struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p321604811165623"><a name="p321604811165623"></a><a name="p321604811165623"></a>static struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p919503074165623"><a name="p919503074165623"></a><a name="p919503074165623"></a>Obtains the network data buffer from the header of a queue, without deleting it from the queue. </p>
</td>
</tr>
<tr id="row610283498165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2046972797165623"><a name="p2046972797165623"></a><a name="p2046972797165623"></a><a href="WLAN.md#ga9de36bf1db57bd4eb042e87cb63dae69">NetBufQueueAtTail</a> (const struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216223049165623"><a name="p1216223049165623"></a><a name="p1216223049165623"></a>static struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p93704876165623"><a name="p93704876165623"></a><a name="p93704876165623"></a>Obtains the network data buffer from the tail of a queue, without deleting it from the queue. </p>
</td>
</tr>
<tr id="row1901589590165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94042796165623"><a name="p94042796165623"></a><a name="p94042796165623"></a><a href="WLAN.md#ga79045ebd1636c27bee454e9541498f33">NetBufQueueClear</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2120575193165623"><a name="p2120575193165623"></a><a name="p2120575193165623"></a>void </p>
<p id="p1258383752165623"><a name="p1258383752165623"></a><a name="p1258383752165623"></a>Clears a network data buffer queue and releases the network data buffer in the queue. </p>
</td>
</tr>
<tr id="row1318950005165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131836132165623"><a name="p131836132165623"></a><a name="p131836132165623"></a><a href="WLAN.md#ga2331e6b8c8f1ac4f00f8a1206fb1a3d8">NetBufQueueConcat</a> (struct <a href="NetBufQueue.md">NetBufQueue</a> *q, struct <a href="NetBufQueue.md">NetBufQueue</a> *add)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1444009212165623"><a name="p1444009212165623"></a><a name="p1444009212165623"></a>void </p>
<p id="p1124276412165623"><a name="p1124276412165623"></a><a name="p1124276412165623"></a>Moves all network data buffers from one queue to another and clears the source queue. </p>
</td>
</tr>
<tr id="row896701952165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p424670659165623"><a name="p424670659165623"></a><a name="p424670659165623"></a><a href="WLAN.md#ga5ced2af63a9064b0e33d0aa4e86b3fc1">NetBufAlloc</a> (uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011167426165623"><a name="p1011167426165623"></a><a name="p1011167426165623"></a>struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p1141899534165623"><a name="p1141899534165623"></a><a name="p1141899534165623"></a>Applies for a network data buffer. </p>
</td>
</tr>
<tr id="row1325194643165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160666447165623"><a name="p160666447165623"></a><a name="p160666447165623"></a><a href="WLAN.md#ga9320642699593dfecd79dc30132dd4eb">NetBufFree</a> (struct <a href="NetBuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1183602364165623"><a name="p1183602364165623"></a><a name="p1183602364165623"></a>void </p>
<p id="p210324551165623"><a name="p210324551165623"></a><a name="p210324551165623"></a>Releases a network data buffer. </p>
</td>
</tr>
<tr id="row730902636165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787243218165623"><a name="p1787243218165623"></a><a name="p1787243218165623"></a><a href="WLAN.md#ga74198f03268aadc025f6b76056b09604">NetBufDevAlloc</a> (const struct <a href="NetDevice.md">NetDevice</a> *dev, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p148440268165623"><a name="p148440268165623"></a><a name="p148440268165623"></a>struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p2028291645165623"><a name="p2028291645165623"></a><a name="p2028291645165623"></a>Applies for a network data buffer based on the reserved space and requested size set by a network device. </p>
</td>
</tr>
<tr id="row1639269664165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153993831165623"><a name="p153993831165623"></a><a name="p153993831165623"></a><a href="WLAN.md#gac4ec1cedef616e61038dcb6dbf67d204">NetBufPush</a> (struct <a href="NetBuf.md">NetBuf</a> *nb, uint32_t id, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129028595165623"><a name="p1129028595165623"></a><a name="p1129028595165623"></a>void * </p>
<p id="p1037420799165623"><a name="p1037420799165623"></a><a name="p1037420799165623"></a>Performs operations based on the segment ID of a network data buffer. The function is opposite to that of <a href="WLAN.md#ga81f298aebc5b7772f173e2f6fadc004f">NetBufPop</a>. </p>
</td>
</tr>
<tr id="row849162116165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876846380165623"><a name="p876846380165623"></a><a name="p876846380165623"></a><a href="WLAN.md#ga81f298aebc5b7772f173e2f6fadc004f">NetBufPop</a> (struct <a href="NetBuf.md">NetBuf</a> *nb, uint32_t id, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827766027165623"><a name="p1827766027165623"></a><a name="p1827766027165623"></a>void * </p>
<p id="p1042228086165623"><a name="p1042228086165623"></a><a name="p1042228086165623"></a>Performs operations based on the segment ID of a network data buffer. The function is opposite to that of <a href="WLAN.md#gac4ec1cedef616e61038dcb6dbf67d204">NetBufPush</a>. </p>
</td>
</tr>
<tr id="row1401727262165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p51515162165623"><a name="p51515162165623"></a><a name="p51515162165623"></a><a href="WLAN.md#gacd40d5004291b4aaa5c27703d9379c9c">NetBufGetAddress</a> (const struct <a href="NetBuf.md">NetBuf</a> *nb, uint32_t id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p871542900165623"><a name="p871542900165623"></a><a name="p871542900165623"></a>static uint8_t * </p>
<p id="p1548163118165623"><a name="p1548163118165623"></a><a name="p1548163118165623"></a>Obtains the address of a specified buffer segment in a network data buffer. </p>
</td>
</tr>
<tr id="row834967147165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p476779775165623"><a name="p476779775165623"></a><a name="p476779775165623"></a><a href="WLAN.md#ga09245834fe9f55fe475a0dc226a6a709">NetBufGetRoom</a> (const struct <a href="NetBuf.md">NetBuf</a> *nb, uint32_t id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999005588165623"><a name="p1999005588165623"></a><a name="p1999005588165623"></a>static uint32_t </p>
<p id="p2003741241165623"><a name="p2003741241165623"></a><a name="p2003741241165623"></a>Obtains the size of a specified buffer segment space in a network data buffer. </p>
</td>
</tr>
<tr id="row241653219165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1553214905165623"><a name="p1553214905165623"></a><a name="p1553214905165623"></a><a href="WLAN.md#ga67eeb57ebe467b9caa4f31734955727b">NetBufGetDataLen</a> (const struct <a href="NetBuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p186811473165623"><a name="p186811473165623"></a><a name="p186811473165623"></a>static uint32_t </p>
<p id="p2101143167165623"><a name="p2101143167165623"></a><a name="p2101143167165623"></a>Obtains the actual data length of the data segment of a network data buffer. </p>
</td>
</tr>
<tr id="row712218867165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1749779019165623"><a name="p1749779019165623"></a><a name="p1749779019165623"></a><a href="WLAN.md#ga623e0b15e65f317f746b53b9a4530bdd">NetBufResizeRoom</a> (struct <a href="NetBuf.md">NetBuf</a> *nb, uint32_t head, uint32_t tail)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176836945165623"><a name="p1176836945165623"></a><a name="p1176836945165623"></a>int32_t </p>
<p id="p624938098165623"><a name="p624938098165623"></a><a name="p624938098165623"></a>Adjusts the size of a network data buffer space. </p>
</td>
</tr>
<tr id="row45762574165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523775426165623"><a name="p1523775426165623"></a><a name="p1523775426165623"></a><a href="WLAN.md#ga89ee14a3da1b7b83325045af9c488ef8">NetBufConcat</a> (struct <a href="NetBuf.md">NetBuf</a> *nb, struct <a href="NetBuf.md">NetBuf</a> *cnb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2131348547165623"><a name="p2131348547165623"></a><a name="p2131348547165623"></a>uint32_t </p>
<p id="p1858311545165623"><a name="p1858311545165623"></a><a name="p1858311545165623"></a>Copies data in a network data buffer to another network data buffer. </p>
</td>
</tr>
<tr id="row241019533165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1070294494165623"><a name="p1070294494165623"></a><a name="p1070294494165623"></a><a href="WLAN.md#ga8d44f8dbfa75583d0056702b5a2d32a1">Pbuf2NetBuf</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, struct pbuf *lwipBuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572980302165623"><a name="p572980302165623"></a><a name="p572980302165623"></a>struct <a href="NetBuf.md">NetBuf</a> * </p>
<p id="p953061218165623"><a name="p953061218165623"></a><a name="p953061218165623"></a>Converts the <strong id="b1046858799165623"><a name="b1046858799165623"></a><a name="b1046858799165623"></a>pbuf</strong> structure of Lightweight TCP/IP Stack (lwIP) to a network data buffer. </p>
</td>
</tr>
<tr id="row501649324165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641749904165623"><a name="p1641749904165623"></a><a name="p1641749904165623"></a><a href="WLAN.md#ga88e4943fc1b1f4e31f388bf8eec57476">NetBuf2Pbuf</a> (const struct <a href="NetBuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928425292165623"><a name="p1928425292165623"></a><a name="p1928425292165623"></a>struct pbuf * </p>
<p id="p862669980165623"><a name="p862669980165623"></a><a name="p862669980165623"></a>Converts a network data buffer to the <strong id="b300181205165623"><a name="b300181205165623"></a><a name="b300181205165623"></a>pbuf</strong> structure of Lightweight TCP/IP Stack (lwIP). </p>
</td>
</tr>
<tr id="row405410356165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218099969165623"><a name="p1218099969165623"></a><a name="p1218099969165623"></a><a href="WLAN.md#ga31edc1e9de8835e0e8a9c1e89fad3bd9">HdfWifiEventNewSta</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, const uint8_t *macAddr, uint8_t addrLen, const struct <a href="StationInfo.md">StationInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100460064165623"><a name="p100460064165623"></a><a name="p100460064165623"></a>int32_t </p>
<p id="p940312545165623"><a name="p940312545165623"></a><a name="p940312545165623"></a>Reports a new STA event. </p>
</td>
</tr>
<tr id="row1134762111165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p256642739165623"><a name="p256642739165623"></a><a name="p256642739165623"></a><a href="WLAN.md#ga208ef54b2a601f416a472bb1e21fae7e">HdfWifiEventDelSta</a> (struct <a href="NetDevice.md">NetDevice</a> *netdev, const uint8_t *macAddr, uint8_t addrLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1210387611165623"><a name="p1210387611165623"></a><a name="p1210387611165623"></a>int32_t </p>
<p id="p1594765696165623"><a name="p1594765696165623"></a><a name="p1594765696165623"></a>Reports a station deletion event. </p>
</td>
</tr>
<tr id="row1142136194165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247509817165623"><a name="p247509817165623"></a><a name="p247509817165623"></a><a href="WLAN.md#ga941675fb683212e6e0d8e1529b300482">HdfWifiEventInformBssFrame</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, struct <a href="Wiphy.md">Wiphy</a> *wiphy, const struct <a href="Ieee80211Channel.md">Ieee80211Channel</a> *channel, const struct <a href="ScannedBssInfo.md">ScannedBssInfo</a> *bssInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055728910165623"><a name="p1055728910165623"></a><a name="p1055728910165623"></a>int32_t </p>
<p id="p123678195165623"><a name="p123678195165623"></a><a name="p123678195165623"></a>Reports a scanned BSS event. </p>
</td>
</tr>
<tr id="row1870787181165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427714331165623"><a name="p427714331165623"></a><a name="p427714331165623"></a><a href="WLAN.md#ga41efbd6788a80604b81ae117a363b657">HdfWifiEventScanDone</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, WifiScanStatus status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691103833165623"><a name="p691103833165623"></a><a name="p691103833165623"></a>int32_t </p>
<p id="p1573347316165623"><a name="p1573347316165623"></a><a name="p1573347316165623"></a>Reports a scanning completion event. </p>
</td>
</tr>
<tr id="row428249369165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381482697165623"><a name="p1381482697165623"></a><a name="p1381482697165623"></a><a href="WLAN.md#gaf9e61f36e11d7d2e94e7969a8ecf22f1">HdfWifiEventConnectResult</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, const struct <a href="ConnetResult.md">ConnetResult</a> *result)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006619057165623"><a name="p2006619057165623"></a><a name="p2006619057165623"></a>int32_t </p>
<p id="p441313452165623"><a name="p441313452165623"></a><a name="p441313452165623"></a>Reports a connection result event. </p>
</td>
</tr>
<tr id="row1217900524165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131967636165623"><a name="p131967636165623"></a><a name="p131967636165623"></a><a href="WLAN.md#ga58b1a613d784233a1e84027079e1ea57">HdfWifiEventDisconnected</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, uint16_t reason, const uint8_t *ie, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010419653165623"><a name="p2010419653165623"></a><a name="p2010419653165623"></a>int32_t </p>
<p id="p819594885165623"><a name="p819594885165623"></a><a name="p819594885165623"></a>Reports a disconnection event. </p>
</td>
</tr>
<tr id="row1100730750165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1658892158165623"><a name="p1658892158165623"></a><a name="p1658892158165623"></a><a href="WLAN.md#ga1721c7e1b5af0240a663ea9f0fe12854">HdfWifiEventMgmtTxStatus</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, const uint8_t *buf, size_t len, uint8_t ack)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p254938633165623"><a name="p254938633165623"></a><a name="p254938633165623"></a>int32_t </p>
<p id="p568558038165623"><a name="p568558038165623"></a><a name="p568558038165623"></a>Reports a transmission management status event. </p>
</td>
</tr>
<tr id="row503892204165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2033749326165623"><a name="p2033749326165623"></a><a name="p2033749326165623"></a><a href="WLAN.md#gad47d56e4332ccd14116368444a4b330f">HdfWifiEventRxMgmt</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, int32_t freq, int32_t sigMbm, const uint8_t *buf, size_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306154701165623"><a name="p306154701165623"></a><a name="p306154701165623"></a>int32_t </p>
<p id="p106660633165623"><a name="p106660633165623"></a><a name="p106660633165623"></a>Reports a receive management status event. </p>
</td>
</tr>
<tr id="row78409811165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540288107165623"><a name="p1540288107165623"></a><a name="p1540288107165623"></a><a href="WLAN.md#ga2aa62f7e8e72e8f9df0b2101c08a9d44">HdfWifiEventCsaChannelSwitch</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev, int32_t freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p394706647165623"><a name="p394706647165623"></a><a name="p394706647165623"></a>int32_t </p>
<p id="p208900837165623"><a name="p208900837165623"></a><a name="p208900837165623"></a>Reports a CSA channel switching event. </p>
</td>
</tr>
<tr id="row1215292097165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p534429362165623"><a name="p534429362165623"></a><a name="p534429362165623"></a><a href="WLAN.md#gafda13471995c91e65326a9aa374ae1c9">HdfWifiEventTimeoutDisconnected</a> (const struct <a href="NetDevice.md">NetDevice</a> *netdev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024342400165623"><a name="p1024342400165623"></a><a name="p1024342400165623"></a>int32_t </p>
<p id="p1457006971165623"><a name="p1457006971165623"></a><a name="p1457006971165623"></a>Reports a timeout disconnection event. </p>
</td>
</tr>
<tr id="row401507798165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1860290073165623"><a name="p1860290073165623"></a><a name="p1860290073165623"></a><a href="WLAN.md#ga3e60f4568723471226107848ddbe582f">HdfWifiEventEapolRecv</a> (const char *name, void *context)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1479712220165623"><a name="p1479712220165623"></a><a name="p1479712220165623"></a>int32_t </p>
<p id="p1869035124165623"><a name="p1869035124165623"></a><a name="p1869035124165623"></a>Reports the event of receiving the EAPOL frame and notifies WPA to read the EAPOL frame. </p>
</td>
</tr>
<tr id="row1065329543165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952762415165623"><a name="p952762415165623"></a><a name="p952762415165623"></a><a href="WLAN.md#ga77f15efb80095134d08cc63b62229f21">HdfWifiGetProduct</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614737510165623"><a name="p1614737510165623"></a><a name="p1614737510165623"></a>struct <a href="HdfWifiProductData.md">HdfWifiProductData</a> * </p>
<p id="p135458608165623"><a name="p135458608165623"></a><a name="p135458608165623"></a>Obtains the data structure of the WLAN module. </p>
</td>
</tr>
<tr id="row1496457276165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1840693108165623"><a name="p1840693108165623"></a><a name="p1840693108165623"></a><a href="WLAN.md#ga8d2bff6673ec21ba317d596a84df7ca8">NetDeviceInit</a> (const char *ifName, uint32_t len, <a href="WLAN.md#ga530241881cd17e03f8ae254ef1d9755e">NetIfCategory</a> ifCategory)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777472999165623"><a name="p777472999165623"></a><a name="p777472999165623"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
<p id="p2074941400165623"><a name="p2074941400165623"></a><a name="p2074941400165623"></a>Initializes a network device to obtain its instance. </p>
</td>
</tr>
<tr id="row1208771645165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032635009165623"><a name="p2032635009165623"></a><a name="p2032635009165623"></a><a href="WLAN.md#gaf4a2fa8b1a35d4cadd8247ee8fed60a4">NetDeviceDeInit</a> (struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1714849487165623"><a name="p1714849487165623"></a><a name="p1714849487165623"></a>int32_t </p>
<p id="p144161460165623"><a name="p144161460165623"></a><a name="p144161460165623"></a>Deletes a network device. </p>
</td>
</tr>
<tr id="row1508837673165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p197449964165623"><a name="p197449964165623"></a><a name="p197449964165623"></a><a href="WLAN.md#ga64be10f09b180d3098e9550163131dbd">NetDeviceAdd</a> (struct <a href="NetDevice.md">NetDevice</a> *netDevice, <a href="WLAN.md#gac69954f56fcc99fc8aac68aa157831c7">Protocol80211IfType</a> ifType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639998771165623"><a name="p1639998771165623"></a><a name="p1639998771165623"></a>int32_t </p>
<p id="p1312570583165623"><a name="p1312570583165623"></a><a name="p1312570583165623"></a>Adds a network device to a protocol stack. </p>
</td>
</tr>
<tr id="row2096501881165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p533684560165623"><a name="p533684560165623"></a><a name="p533684560165623"></a><a href="WLAN.md#ga6c93cb701cf2523eaa7bbeabd4acf3ab">NetDeviceDelete</a> (struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1306850018165623"><a name="p1306850018165623"></a><a name="p1306850018165623"></a>int32_t </p>
<p id="p355431544165623"><a name="p355431544165623"></a><a name="p355431544165623"></a>Deletes a network device from a protocol stack. </p>
</td>
</tr>
<tr id="row305208709165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p66297003165623"><a name="p66297003165623"></a><a name="p66297003165623"></a><a href="WLAN.md#ga6d90d1bf783a83db1d838d03f8c1d93a">NetDeviceGetInstByName</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019867577165623"><a name="p1019867577165623"></a><a name="p1019867577165623"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
<p id="p826288868165623"><a name="p826288868165623"></a><a name="p826288868165623"></a>Obtains the initialized network device instance by a specified device name. </p>
</td>
</tr>
<tr id="row600378818165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p287753943165623"><a name="p287753943165623"></a><a name="p287753943165623"></a><a href="WLAN.md#ga20fcbcc248e99917c17223a97fe5d70e">NetDeviceIsAnyInstRunning</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325069379165623"><a name="p325069379165623"></a><a name="p325069379165623"></a>bool </p>
<p id="p196059452165623"><a name="p196059452165623"></a><a name="p196059452165623"></a>Checks whether there are working devices among the added network devices. </p>
</td>
</tr>
<tr id="row2030948330165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p386780953165623"><a name="p386780953165623"></a><a name="p386780953165623"></a><a href="WLAN.md#ga05b08c890c69f3e633447f14e16d30f7">NetDeviceIsInstRunning</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1451434598165623"><a name="p1451434598165623"></a><a name="p1451434598165623"></a>bool </p>
<p id="p841251831165623"><a name="p841251831165623"></a><a name="p841251831165623"></a>Checks whether a specified network device is working. </p>
</td>
</tr>
<tr id="row1481786631165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p543487699165623"><a name="p543487699165623"></a><a name="p543487699165623"></a><a href="WLAN.md#ga8c8d400a6b4eb64445a2b4ea12102c9a">NetDevGetRegisterCount</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1793546899165623"><a name="p1793546899165623"></a><a name="p1793546899165623"></a>uint32_t </p>
<p id="p1346372451165623"><a name="p1346372451165623"></a><a name="p1346372451165623"></a>Obtains the number of added network devices. </p>
</td>
</tr>
<tr id="row1675881291165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1538488943165623"><a name="p1538488943165623"></a><a name="p1538488943165623"></a><a href="WLAN.md#ga5d2a4fd370e2115b4c1fc8ecc46d64ab">NetDeviceGetCap</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817169380165623"><a name="p1817169380165623"></a><a name="p1817169380165623"></a>uint32_t </p>
<p id="p1823478848165623"><a name="p1823478848165623"></a><a name="p1823478848165623"></a>Obtains the maximum number of network devices that can be registered with this system at the same time. </p>
</td>
</tr>
<tr id="row454923768165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p820789883165623"><a name="p820789883165623"></a><a name="p820789883165623"></a><a href="WLAN.md#gab45261476e710c30335975726af3a834">NetDeviceGetInstByIndex</a> (uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234518733165623"><a name="p1234518733165623"></a><a name="p1234518733165623"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
<p id="p1020096836165623"><a name="p1020096836165623"></a><a name="p1020096836165623"></a>Obtains a network device instance based on the index number. </p>
</td>
</tr>
<tr id="row1331762355165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775564422165623"><a name="p775564422165623"></a><a name="p775564422165623"></a><a href="WLAN.md#gadd5c08aa8e65a12db062b1b88d53cece">NetIfSetAddr</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, const <a href="IpV4Addr.md">IpV4Addr</a> *ipAddr, const <a href="IpV4Addr.md">IpV4Addr</a> *netMask, const <a href="IpV4Addr.md">IpV4Addr</a> *gw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2046660484165623"><a name="p2046660484165623"></a><a name="p2046660484165623"></a>int32_t </p>
<p id="p1120364521165623"><a name="p1120364521165623"></a><a name="p1120364521165623"></a>Sets an IP address, mask, and gateway. </p>
</td>
</tr>
<tr id="row687177882165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1506798754165623"><a name="p1506798754165623"></a><a name="p1506798754165623"></a><a href="WLAN.md#gaa14fc68a382284491a272992d5c477cb">NetIfSetStatus</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, <a href="WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf">NetIfStatus</a> status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1135933504165623"><a name="p1135933504165623"></a><a name="p1135933504165623"></a>int32_t </p>
<p id="p1765879011165623"><a name="p1765879011165623"></a><a name="p1765879011165623"></a>Notifies the network layer of the network port state. </p>
</td>
</tr>
<tr id="row1674269104165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625385667165623"><a name="p1625385667165623"></a><a name="p1625385667165623"></a><a href="WLAN.md#gaee9c68875ef541ed915045ab7a047ee8">NetIfSetLinkStatus</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, <a href="WLAN.md#ga7b1187d116fb065d7927ad9f77edd842">NetIfLinkStatus</a> status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2143369092165623"><a name="p2143369092165623"></a><a name="p2143369092165623"></a>int32_t </p>
<p id="p1773348843165623"><a name="p1773348843165623"></a><a name="p1773348843165623"></a>Notifies the network layer of the data link layer status. </p>
</td>
</tr>
<tr id="row749566401165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1754032318165623"><a name="p1754032318165623"></a><a name="p1754032318165623"></a><a href="WLAN.md#ga44006f6e066aff9f6a3310559e781582">NetIfRx</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, struct <a href="NetBuf.md">NetBuf</a> *buff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345134523165623"><a name="p345134523165623"></a><a name="p345134523165623"></a>int32_t </p>
<p id="p625472466165623"><a name="p625472466165623"></a><a name="p625472466165623"></a>Transfers the input data packets from the network side to a protocol stack. </p>
</td>
</tr>
<tr id="row121739652165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362008613165623"><a name="p362008613165623"></a><a name="p362008613165623"></a><a href="WLAN.md#gad252107cdd20e9d3d0ab33fbfc2161e9">NetIfRxNi</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, struct <a href="NetBuf.md">NetBuf</a> *buff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p972705709165623"><a name="p972705709165623"></a><a name="p972705709165623"></a>int32_t </p>
<p id="p1853565349165623"><a name="p1853565349165623"></a><a name="p1853565349165623"></a>Transfers data packets from the network side to a protocol stack in an interrupt processing thread. </p>
</td>
</tr>
<tr id="row1732934698165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p694942897165623"><a name="p694942897165623"></a><a name="p694942897165623"></a><a href="WLAN.md#gae97c7abcf556be34798622a85162c35e">NetIfDhcpsStart</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, char *ip, u16_t ipNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611786969165623"><a name="p1611786969165623"></a><a name="p1611786969165623"></a>int32_t </p>
<p id="p604231280165623"><a name="p604231280165623"></a><a name="p604231280165623"></a>Starts the DHCP server. </p>
</td>
</tr>
<tr id="row1497697296165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372712545165623"><a name="p1372712545165623"></a><a name="p1372712545165623"></a><a href="WLAN.md#gaadfeb819b4cb623870823fa5c9793b4c">NetIfDhcpsStop</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2015064192165623"><a name="p2015064192165623"></a><a name="p2015064192165623"></a>int32_t </p>
<p id="p555833479165623"><a name="p555833479165623"></a><a name="p555833479165623"></a>Stops the DHCP server. </p>
</td>
</tr>
<tr id="row1688309378165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p979099698165623"><a name="p979099698165623"></a><a name="p979099698165623"></a><a href="WLAN.md#ga5fdd93c820b994adf1b76eb8d50e4f88">NetIfDhcpStart</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064347824165623"><a name="p1064347824165623"></a><a name="p1064347824165623"></a>int32_t </p>
<p id="p1646087541165623"><a name="p1646087541165623"></a><a name="p1646087541165623"></a>Starts the DHCP client of a specified network device. </p>
</td>
</tr>
<tr id="row1642950517165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961590709165623"><a name="p961590709165623"></a><a name="p961590709165623"></a><a href="WLAN.md#ga22f97a3fc45841e874ab2072c14e0f3e">NetIfDhcpStop</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556170793165623"><a name="p1556170793165623"></a><a name="p1556170793165623"></a>int32_t </p>
<p id="p1824512893165623"><a name="p1824512893165623"></a><a name="p1824512893165623"></a>Stops the DHCP client of a specified network device. </p>
</td>
</tr>
<tr id="row428245859165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p793641993165623"><a name="p793641993165623"></a><a name="p793641993165623"></a><a href="WLAN.md#ga389ec95a3c8170c4ca74487f8bc1d8ac">NetIfDhcpIsBound</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p384342102165623"><a name="p384342102165623"></a><a name="p384342102165623"></a>int32_t </p>
<p id="p1067262549165623"><a name="p1067262549165623"></a><a name="p1067262549165623"></a>Obtains the DHCP negotiation status of a specified network device. </p>
</td>
</tr>
<tr id="row1314854284165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p954585406165623"><a name="p954585406165623"></a><a name="p954585406165623"></a><a href="WLAN.md#ga6542a735af0fe7496789c3c55380adfa">Mac80211RegisterOps</a> (struct <a href="WifiMac80211Ops.md">WifiMac80211Ops</a> *ops) __attribute__((weak))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787246207165623"><a name="p1787246207165623"></a><a name="p1787246207165623"></a>int32_t </p>
<p id="p1814883925165623"><a name="p1814883925165623"></a><a name="p1814883925165623"></a>Registers a <a href="WifiMac80211Ops.md">WifiMac80211Ops</a> object. </p>
</td>
</tr>
<tr id="row1977873428165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p642939319165623"><a name="p642939319165623"></a><a name="p642939319165623"></a><a href="WLAN.md#gad7c34413d81d55ba090c90404d340c8a">Mac80211GetOps</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786593844165623"><a name="p1786593844165623"></a><a name="p1786593844165623"></a>struct <a href="WifiMac80211Ops.md">WifiMac80211Ops</a> * </p>
<p id="p756930198165623"><a name="p756930198165623"></a><a name="p756930198165623"></a>Obtains the <a href="WifiMac80211Ops.md">WifiMac80211Ops</a> object that the driver needs to implement. </p>
</td>
</tr>
<tr id="row686641476165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p801303944165623"><a name="p801303944165623"></a><a name="p801303944165623"></a><a href="WLAN.md#gaf5d1df53f08cae98ecfd440f9b425709">WifiModuleCreate</a> (const struct HdfConfigWifiModuleConfig *config)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p337664877165623"><a name="p337664877165623"></a><a name="p337664877165623"></a>struct <a href="WifiModule.md">WifiModule</a> * </p>
<p id="p947396180165623"><a name="p947396180165623"></a><a name="p947396180165623"></a>Creates a <a href="WifiModule.md">WifiModule</a> object based on a specified configuration generated by the HCS. </p>
</td>
</tr>
<tr id="row2042023589165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405146954165623"><a name="p405146954165623"></a><a name="p405146954165623"></a><a href="WLAN.md#gae14e3786e60f16a100197d28bae5a362">WifiModuleDelete</a> (struct <a href="WifiModule.md">WifiModule</a> *module)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001705065165623"><a name="p2001705065165623"></a><a name="p2001705065165623"></a>void </p>
<p id="p1845686943165623"><a name="p1845686943165623"></a><a name="p1845686943165623"></a>Deletes a specified <a href="WifiModule.md">WifiModule</a> object. </p>
</td>
</tr>
<tr id="row223385511165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495500817165623"><a name="p1495500817165623"></a><a name="p1495500817165623"></a><a href="WLAN.md#ga395848b77fc10f2213d5b12793861292">DelFeature</a> (struct <a href="WifiModule.md">WifiModule</a> *module, uint16_t featureType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965913666165623"><a name="p1965913666165623"></a><a name="p1965913666165623"></a>int32_t </p>
<p id="p1079231418165623"><a name="p1079231418165623"></a><a name="p1079231418165623"></a>Deletes a specified feature from a specified module. </p>
</td>
</tr>
<tr id="row2013315957165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274087248165623"><a name="p1274087248165623"></a><a name="p1274087248165623"></a><a href="WLAN.md#gae928a69366143780650b73c6b030c3a7">AddFeature</a> (struct <a href="WifiModule.md">WifiModule</a> *module, uint16_t featureType, struct <a href="WifiFeature.md">WifiFeature</a> *featureData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p975869842165623"><a name="p975869842165623"></a><a name="p975869842165623"></a>int32_t </p>
<p id="p508849611165623"><a name="p508849611165623"></a><a name="p508849611165623"></a>Adds a specified feature to a specified module. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section88215858165623"></a>

## **Macro Definition **<a name="section128768446165623"></a>

## MAX\_NETBUF\_RESEVER\_SIZE<a name="ga794c035a19a38acc000146a8f9a4ec80"></a>

```
#define MAX_NETBUF_RESEVER_SIZE   68
```

 **Description:**

Defines the reserved field of a network data buffer used to store private information. 

The length of the reserved field is  **68**  bytes. 

## MAX\_WIFI\_COMPONENT\_NAME\_LEN<a name="gaf460a45a5e365279ca6bc5b3e8750542"></a>

```
#define MAX_WIFI_COMPONENT_NAME_LEN   10
```

 **Description:**

Indicates the length of the name of a WLAN module or feature. 

The name of a WLAN module or feature cannot contain more than 10 characters; otherwise, the name will be truncated and cannot be identified.

## **Typedef **<a name="section1022416497165623"></a>

## Mac80211SetMacParam<a name="ga85f7d8a3795887f090e0a6439b1df6e1"></a>

```
typedef struct [MacConfigParam](MacConfigParam.md) [Mac80211SetMacParam](WLAN.md#ga85f7d8a3795887f090e0a6439b1df6e1)
```

 **Description:**

Describes MAC configuration parameters. 

## NetDevice<a name="gac26e4b0cda623f27420f9ce77befbb1f"></a>

```
typedef struct [NetDevice](NetDevice.md) [NetDevice](NetDevice.md)
```

 **Description:**

Defines a network device, including the network interface category and name, and network port type. 

## WifiConnectParams<a name="ga3e8945c521d2392cb775494570c560b3"></a>

```
typedef struct [WifiConnectParams](WifiConnectParams.md) [WifiConnectParams](WifiConnectParams.md)
```

 **Description:**

Describes parameters for a connection request. 

## **Enumeration Type **<a name="section1302951935165623"></a>

## anonymous enum<a name="gafa231099d07583c3ed0981e0bb665f55"></a>

```
anonymous enum
```

 **Description:**

Enumerates the segments of a network data buffer. 

The entire network data buffer is divided into three segments: a header, data, and a tail. The header and tail are used to extend both ends of the data segment.

<a name="table1105572816165623"></a>
<table><thead align="left"><tr id="row366892788165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1937754141165623"><a name="p1937754141165623"></a><a name="p1937754141165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1299584791165623"><a name="p1299584791165623"></a><a name="p1299584791165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1402487854165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggafa231099d07583c3ed0981e0bb665f55a0e4808dd476b314c0fdbf417307f8b92"><a name="ggafa231099d07583c3ed0981e0bb665f55a0e4808dd476b314c0fdbf417307f8b92"></a><a name="ggafa231099d07583c3ed0981e0bb665f55a0e4808dd476b314c0fdbf417307f8b92"></a></strong>E_HEAD_BUF </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952840140165623"><a name="p1952840140165623"></a><a name="p1952840140165623"></a>Header buffer segment </p>
 </td>
</tr>
<tr id="row1974069946165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggafa231099d07583c3ed0981e0bb665f55a4b374b76d2b9bb60c31a1a540369b6d4"><a name="ggafa231099d07583c3ed0981e0bb665f55a4b374b76d2b9bb60c31a1a540369b6d4"></a><a name="ggafa231099d07583c3ed0981e0bb665f55a4b374b76d2b9bb60c31a1a540369b6d4"></a></strong>E_DATA_BUF </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480513996165623"><a name="p480513996165623"></a><a name="p480513996165623"></a>Data segment </p>
 </td>
</tr>
<tr id="row504522983165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggafa231099d07583c3ed0981e0bb665f55a316baeacb77ecf28631a76f1dbea872d"><a name="ggafa231099d07583c3ed0981e0bb665f55a316baeacb77ecf28631a76f1dbea872d"></a><a name="ggafa231099d07583c3ed0981e0bb665f55a316baeacb77ecf28631a76f1dbea872d"></a></strong>E_TAIL_BUF </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1076638168165623"><a name="p1076638168165623"></a><a name="p1076638168165623"></a>Tail buffer segment </p>
 </td>
</tr>
<tr id="row1824444972165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19"><a name="ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19"></a><a name="ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19"></a></strong>MAX_BUF_NUM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769411465165623"><a name="p769411465165623"></a><a name="p769411465165623"></a>Maximum number of buffer segments </p>
 </td>
</tr>
</tbody>
</table>

## Ieee80211Band<a name="ga9882f415202cf9acb0f4cdfbc456a88d"></a>

```
enum [Ieee80211Band](WLAN.md#ga9882f415202cf9acb0f4cdfbc456a88d)
```

 **Description:**

Enumerates frequency bands. 

<a name="table1169333434165623"></a>
<table><thead align="left"><tr id="row1312089766165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1874916323165623"><a name="p1874916323165623"></a><a name="p1874916323165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1666484144165623"><a name="p1666484144165623"></a><a name="p1666484144165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row618371482165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9882f415202cf9acb0f4cdfbc456a88daf339f82c036557f42f668a358aa96da3"><a name="gga9882f415202cf9acb0f4cdfbc456a88daf339f82c036557f42f668a358aa96da3"></a><a name="gga9882f415202cf9acb0f4cdfbc456a88daf339f82c036557f42f668a358aa96da3"></a></strong>IEEE80211_BAND_2GHZ </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928002749165623"><a name="p1928002749165623"></a><a name="p1928002749165623"></a>2.4 GHz </p>
 </td>
</tr>
<tr id="row1392715922165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9882f415202cf9acb0f4cdfbc456a88da0871c8866251ec4e668e956bb0427cfa"><a name="gga9882f415202cf9acb0f4cdfbc456a88da0871c8866251ec4e668e956bb0427cfa"></a><a name="gga9882f415202cf9acb0f4cdfbc456a88da0871c8866251ec4e668e956bb0427cfa"></a></strong>IEEE80211_BAND_5GHZ </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343420879165623"><a name="p343420879165623"></a><a name="p343420879165623"></a>5 GHz </p>
 </td>
</tr>
<tr id="row2098374665165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4"><a name="gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4"></a><a name="gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4"></a></strong>IEEE80211_NUM_BANDS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p984010950165623"><a name="p984010950165623"></a><a name="p984010950165623"></a>Reserved </p>
 </td>
</tr>
</tbody>
</table>

## MacSetType<a name="ga75cba3dc6ab4c5dc5653b037433b3abf"></a>

```
enum [MacSetType](WLAN.md#ga75cba3dc6ab4c5dc5653b037433b3abf)
```

 **Description:**

Enumerates setting types of MAC addresses. 

<a name="table468550003165623"></a>
<table><thead align="left"><tr id="row62619294165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p194305474165623"><a name="p194305474165623"></a><a name="p194305474165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2072131277165623"><a name="p2072131277165623"></a><a name="p2072131277165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row821973813165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga75cba3dc6ab4c5dc5653b037433b3abfa52532b66ba237505f04a57b382f67cb1"><a name="gga75cba3dc6ab4c5dc5653b037433b3abfa52532b66ba237505f04a57b382f67cb1"></a><a name="gga75cba3dc6ab4c5dc5653b037433b3abfa52532b66ba237505f04a57b382f67cb1"></a></strong>MAC_BEACON_SET </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361726490165623"><a name="p361726490165623"></a><a name="p361726490165623"></a>Setting a beacon MAC address </p>
 </td>
</tr>
<tr id="row259173698165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga75cba3dc6ab4c5dc5653b037433b3abfa8bb6332eadf8a54cdcf7d02b6040e7f3"><a name="gga75cba3dc6ab4c5dc5653b037433b3abfa8bb6332eadf8a54cdcf7d02b6040e7f3"></a><a name="gga75cba3dc6ab4c5dc5653b037433b3abfa8bb6332eadf8a54cdcf7d02b6040e7f3"></a></strong>MAC_BEACON_ADD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1221274259165623"><a name="p1221274259165623"></a><a name="p1221274259165623"></a>Adding a beacon MAC address </p>
 </td>
</tr>
</tbody>
</table>

## NetdeviceError<a name="ga9023c5dc1cc43758cbb468d78af41c2d"></a>

```
enum [NetdeviceError](WLAN.md#ga9023c5dc1cc43758cbb468d78af41c2d)
```

 **Description:**

Enumerates network device errors, including common errors and errors in adding network devices to LwIP. 

<a name="table566302774165623"></a>
<table><thead align="left"><tr id="row294198803165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p970663227165623"><a name="p970663227165623"></a><a name="p970663227165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1461757234165623"><a name="p1461757234165623"></a><a name="p1461757234165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1769632408165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9023c5dc1cc43758cbb468d78af41c2dafe771f5d0d84d17922f466d3eed83d6b"><a name="gga9023c5dc1cc43758cbb468d78af41c2dafe771f5d0d84d17922f466d3eed83d6b"></a><a name="gga9023c5dc1cc43758cbb468d78af41c2dafe771f5d0d84d17922f466d3eed83d6b"></a></strong>COMMON_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459150936165623"><a name="p459150936165623"></a><a name="p459150936165623"></a>Common errors </p>
 </td>
</tr>
<tr id="row351423266165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9023c5dc1cc43758cbb468d78af41c2daf5426609de8db5782b340a6bcd7e94d6"><a name="gga9023c5dc1cc43758cbb468d78af41c2daf5426609de8db5782b340a6bcd7e94d6"></a><a name="gga9023c5dc1cc43758cbb468d78af41c2daf5426609de8db5782b340a6bcd7e94d6"></a></strong>ADD_LWIP_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128785323165623"><a name="p1128785323165623"></a><a name="p1128785323165623"></a>Errors in adding network devices to LwIP </p>
 </td>
</tr>
</tbody>
</table>

## NetDevTxResult<a name="ga9fb4e578a15db1b0087d7b3831591ced"></a>

```
enum [NetDevTxResult](WLAN.md#ga9fb4e578a15db1b0087d7b3831591ced)
```

 **Description:**

Enumerates data sending results, including sending succeeded, other data being sent at the link layer, and data link layer being locked. 

<a name="table1291215008165623"></a>
<table><thead align="left"><tr id="row1952245252165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p473575193165623"><a name="p473575193165623"></a><a name="p473575193165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p605041383165623"><a name="p605041383165623"></a><a name="p605041383165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row126661188165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9fb4e578a15db1b0087d7b3831591ceda734cacd083ffc8d233cab8d4deb6b38b"><a name="gga9fb4e578a15db1b0087d7b3831591ceda734cacd083ffc8d233cab8d4deb6b38b"></a><a name="gga9fb4e578a15db1b0087d7b3831591ceda734cacd083ffc8d233cab8d4deb6b38b"></a></strong>NETDEV_TX_OK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325949692165623"><a name="p325949692165623"></a><a name="p325949692165623"></a>Sending succeeded </p>
 </td>
</tr>
<tr id="row1694868888165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9fb4e578a15db1b0087d7b3831591cedaf0a0ac437358f6af42c3e38795c46d35"><a name="gga9fb4e578a15db1b0087d7b3831591cedaf0a0ac437358f6af42c3e38795c46d35"></a><a name="gga9fb4e578a15db1b0087d7b3831591cedaf0a0ac437358f6af42c3e38795c46d35"></a></strong>NETDEV_TX_BUSY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97263532165623"><a name="p97263532165623"></a><a name="p97263532165623"></a>Other data being sent at the link layer </p>
 </td>
</tr>
<tr id="row956108809165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9fb4e578a15db1b0087d7b3831591ceda7eb70cee5761fe8954f94b660c37eaa8"><a name="gga9fb4e578a15db1b0087d7b3831591ceda7eb70cee5761fe8954f94b660c37eaa8"></a><a name="gga9fb4e578a15db1b0087d7b3831591ceda7eb70cee5761fe8954f94b660c37eaa8"></a></strong>NETDEV_TX_LOCKED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107084423165623"><a name="p107084423165623"></a><a name="p107084423165623"></a>Data link layer being locked </p>
 </td>
</tr>
</tbody>
</table>

## NetIfCategory<a name="ga530241881cd17e03f8ae254ef1d9755e"></a>

```
enum [NetIfCategory](WLAN.md#ga530241881cd17e03f8ae254ef1d9755e)
```

 **Description:**

Enumerates network interface categories, including lightweight OS and rich OS. 

<a name="table1014135491165623"></a>
<table><thead align="left"><tr id="row1451298733165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p34459562165623"><a name="p34459562165623"></a><a name="p34459562165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1312709414165623"><a name="p1312709414165623"></a><a name="p1312709414165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1746021480165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga530241881cd17e03f8ae254ef1d9755eaab9c78d744764e8f66591ee4a8d7b3cb"><a name="gga530241881cd17e03f8ae254ef1d9755eaab9c78d744764e8f66591ee4a8d7b3cb"></a><a name="gga530241881cd17e03f8ae254ef1d9755eaab9c78d744764e8f66591ee4a8d7b3cb"></a></strong>LITE_OS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1665693285165623"><a name="p1665693285165623"></a><a name="p1665693285165623"></a>Lightweight OS </p>
 </td>
</tr>
<tr id="row786926124165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga530241881cd17e03f8ae254ef1d9755eafdfffeab76fab0306aa033c650ae0cfa"><a name="gga530241881cd17e03f8ae254ef1d9755eafdfffeab76fab0306aa033c650ae0cfa"></a><a name="gga530241881cd17e03f8ae254ef1d9755eafdfffeab76fab0306aa033c650ae0cfa"></a></strong>RICH_OS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203565564165623"><a name="p1203565564165623"></a><a name="p1203565564165623"></a>Rich OS </p>
 </td>
</tr>
</tbody>
</table>

## NetIfLinkStatus<a name="ga7b1187d116fb065d7927ad9f77edd842"></a>

```
enum [NetIfLinkStatus](WLAN.md#ga7b1187d116fb065d7927ad9f77edd842)
```

 **Description:**

Enumerates network link layer states, including online and offline. 

<a name="table2115530513165623"></a>
<table><thead align="left"><tr id="row313574894165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p251314860165623"><a name="p251314860165623"></a><a name="p251314860165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1786916092165623"><a name="p1786916092165623"></a><a name="p1786916092165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2132729787165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7b1187d116fb065d7927ad9f77edd842a8586d0e791ca4f7026853d85740650b5"><a name="gga7b1187d116fb065d7927ad9f77edd842a8586d0e791ca4f7026853d85740650b5"></a><a name="gga7b1187d116fb065d7927ad9f77edd842a8586d0e791ca4f7026853d85740650b5"></a></strong>NETIF_LINK_DOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1844642071165623"><a name="p1844642071165623"></a><a name="p1844642071165623"></a>Data link offline </p>
 </td>
</tr>
<tr id="row1614214165165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7b1187d116fb065d7927ad9f77edd842ac3108dbea78b5f0f928e6e5e4ea045f2"><a name="gga7b1187d116fb065d7927ad9f77edd842ac3108dbea78b5f0f928e6e5e4ea045f2"></a><a name="gga7b1187d116fb065d7927ad9f77edd842ac3108dbea78b5f0f928e6e5e4ea045f2"></a></strong>NETIF_LINK_UP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p529845718165623"><a name="p529845718165623"></a><a name="p529845718165623"></a>Data link online </p>
 </td>
</tr>
</tbody>
</table>

## NetIfStatus<a name="ga0fb482694e5eac3f48c75de1749c8baf"></a>

```
enum [NetIfStatus](WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf)
```

 **Description:**

Enumerates network interface states, including online and offline. 

<a name="table887217670165623"></a>
<table><thead align="left"><tr id="row768135441165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1049358424165623"><a name="p1049358424165623"></a><a name="p1049358424165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2054095846165623"><a name="p2054095846165623"></a><a name="p2054095846165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row680820425165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0fb482694e5eac3f48c75de1749c8bafaeda2ad3830d5a42070617fd0211baf95"><a name="gga0fb482694e5eac3f48c75de1749c8bafaeda2ad3830d5a42070617fd0211baf95"></a><a name="gga0fb482694e5eac3f48c75de1749c8bafaeda2ad3830d5a42070617fd0211baf95"></a></strong>NETIF_DOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787519255165623"><a name="p787519255165623"></a><a name="p787519255165623"></a>Network interface offline </p>
 </td>
</tr>
<tr id="row168039271165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0fb482694e5eac3f48c75de1749c8bafa64a69f6624102c11bd658c09daf0f865"><a name="gga0fb482694e5eac3f48c75de1749c8bafa64a69f6624102c11bd658c09daf0f865"></a><a name="gga0fb482694e5eac3f48c75de1749c8bafa64a69f6624102c11bd658c09daf0f865"></a></strong>NETIF_UP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1232820720165623"><a name="p1232820720165623"></a><a name="p1232820720165623"></a>Network interface online </p>
 </td>
</tr>
</tbody>
</table>

## NetLinkType<a name="gad3175955d2e6ef3c4f52da9b509d5b4a"></a>

```
enum [NetLinkType](WLAN.md#gad3175955d2e6ef3c4f52da9b509d5b4a)
```

 **Description:**

Enumerates data link types, including Ethernet and WLAN. 

<a name="table321434337165623"></a>
<table><thead align="left"><tr id="row1964194873165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1740837594165623"><a name="p1740837594165623"></a><a name="p1740837594165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p752410088165623"><a name="p752410088165623"></a><a name="p752410088165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1334168644165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad3175955d2e6ef3c4f52da9b509d5b4aa2d49c28127ce1d558ad5ea2f92e89fd7"><a name="ggad3175955d2e6ef3c4f52da9b509d5b4aa2d49c28127ce1d558ad5ea2f92e89fd7"></a><a name="ggad3175955d2e6ef3c4f52da9b509d5b4aa2d49c28127ce1d558ad5ea2f92e89fd7"></a></strong>ETHERNET_LINK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002114677165623"><a name="p2002114677165623"></a><a name="p2002114677165623"></a>Ethernet </p>
 </td>
</tr>
<tr id="row1106270370165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad3175955d2e6ef3c4f52da9b509d5b4aadfed684cd7f64cc1aea5944657866db6"><a name="ggad3175955d2e6ef3c4f52da9b509d5b4aadfed684cd7f64cc1aea5944657866db6"></a><a name="ggad3175955d2e6ef3c4f52da9b509d5b4aadfed684cd7f64cc1aea5944657866db6"></a></strong>WIFI_LINK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1057475217165623"><a name="p1057475217165623"></a><a name="p1057475217165623"></a>WLAN </p>
 </td>
</tr>
</tbody>
</table>

## ProcessingResult<a name="ga9c1d6e7df4468671742cb76f72b67af1"></a>

```
enum [ProcessingResult](WLAN.md#ga9c1d6e7df4468671742cb76f72b67af1)
```

 **Description:**

Enumerates data processing results, including continuing processing, processing completed, and error. 

<a name="table806440304165623"></a>
<table><thead align="left"><tr id="row1736134797165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p93358569165623"><a name="p93358569165623"></a><a name="p93358569165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1935096366165623"><a name="p1935096366165623"></a><a name="p1935096366165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1501072468165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9c1d6e7df4468671742cb76f72b67af1a5ce4c56e88c31420a02d3b7f068e0799"><a name="gga9c1d6e7df4468671742cb76f72b67af1a5ce4c56e88c31420a02d3b7f068e0799"></a><a name="gga9c1d6e7df4468671742cb76f72b67af1a5ce4c56e88c31420a02d3b7f068e0799"></a></strong>PROCESSING_CONTINUE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570116238165623"><a name="p570116238165623"></a><a name="p570116238165623"></a>Continuing processing </p>
 </td>
</tr>
<tr id="row133930178165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9c1d6e7df4468671742cb76f72b67af1a2fcbb133dcd739ab4a04b00bececd70a"><a name="gga9c1d6e7df4468671742cb76f72b67af1a2fcbb133dcd739ab4a04b00bececd70a"></a><a name="gga9c1d6e7df4468671742cb76f72b67af1a2fcbb133dcd739ab4a04b00bececd70a"></a></strong>PROCESSING_COMPLETE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834238077165623"><a name="p834238077165623"></a><a name="p834238077165623"></a>Processing completed </p>
 </td>
</tr>
<tr id="row1307221058165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9c1d6e7df4468671742cb76f72b67af1afe177a1b88ea1cdcc0e41181c2c73e83"><a name="gga9c1d6e7df4468671742cb76f72b67af1afe177a1b88ea1cdcc0e41181c2c73e83"></a><a name="gga9c1d6e7df4468671742cb76f72b67af1afe177a1b88ea1cdcc0e41181c2c73e83"></a></strong>PROCESSING_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1617163826165623"><a name="p1617163826165623"></a><a name="p1617163826165623"></a>Error </p>
 </td>
</tr>
</tbody>
</table>

## Protocol80211IfType<a name="gac69954f56fcc99fc8aac68aa157831c7"></a>

```
enum [Protocol80211IfType](WLAN.md#gac69954f56fcc99fc8aac68aa157831c7)
```

 **Description:**

Enumerates 802.11 network port types, including AP, STA, and P2P. 

<a name="table1747518797165623"></a>
<table><thead align="left"><tr id="row2111264952165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1100130639165623"><a name="p1100130639165623"></a><a name="p1100130639165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1813662954165623"><a name="p1813662954165623"></a><a name="p1813662954165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1392676748165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a6b209b916aabd18f2a950a82e68b6a4c"><a name="ggac69954f56fcc99fc8aac68aa157831c7a6b209b916aabd18f2a950a82e68b6a4c"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a6b209b916aabd18f2a950a82e68b6a4c"></a></strong>PROTOCOL_80211_IFTYPE_UNSPECIFIED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p70843978165623"><a name="p70843978165623"></a><a name="p70843978165623"></a>Unspecified </p>
 </td>
</tr>
<tr id="row1053710658165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a0926a98ddc2ceec4ba58ebfc01c5fe35"><a name="ggac69954f56fcc99fc8aac68aa157831c7a0926a98ddc2ceec4ba58ebfc01c5fe35"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a0926a98ddc2ceec4ba58ebfc01c5fe35"></a></strong>PROTOCOL_80211_IFTYPE_ADHOC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1288239010165623"><a name="p1288239010165623"></a><a name="p1288239010165623"></a>Ad hoc network </p>
 </td>
</tr>
<tr id="row1338224080165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7acd26f8cefbd658e9ea02feecefd054fb"><a name="ggac69954f56fcc99fc8aac68aa157831c7acd26f8cefbd658e9ea02feecefd054fb"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7acd26f8cefbd658e9ea02feecefd054fb"></a></strong>PROTOCOL_80211_IFTYPE_STATION </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p53173920165623"><a name="p53173920165623"></a><a name="p53173920165623"></a>Workstation </p>
 </td>
</tr>
<tr id="row365016446165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a9e92654b9ab6ed6eb62868f1e0e4ea8f"><a name="ggac69954f56fcc99fc8aac68aa157831c7a9e92654b9ab6ed6eb62868f1e0e4ea8f"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a9e92654b9ab6ed6eb62868f1e0e4ea8f"></a></strong>PROTOCOL_80211_IFTYPE_AP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606200848165623"><a name="p1606200848165623"></a><a name="p1606200848165623"></a>Access point </p>
 </td>
</tr>
<tr id="row102078796165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a991ad1a3f8c43b06c4eeb9dc88acdb1e"><a name="ggac69954f56fcc99fc8aac68aa157831c7a991ad1a3f8c43b06c4eeb9dc88acdb1e"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a991ad1a3f8c43b06c4eeb9dc88acdb1e"></a></strong>PROTOCOL_80211_IFTYPE_AP_VLAN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1169730127165623"><a name="p1169730127165623"></a><a name="p1169730127165623"></a>Virtual access point </p>
 </td>
</tr>
<tr id="row44306302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7aa25631c32cd6c996a7c96ba4f61299e2"><a name="ggac69954f56fcc99fc8aac68aa157831c7aa25631c32cd6c996a7c96ba4f61299e2"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7aa25631c32cd6c996a7c96ba4f61299e2"></a></strong>PROTOCOL_80211_IFTYPE_WDS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1440212399165623"><a name="p1440212399165623"></a><a name="p1440212399165623"></a>Wireless distributed system </p>
 </td>
</tr>
<tr id="row1699915714165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a3ff1c1358af5a0c50b64e0ef0e96a970"><a name="ggac69954f56fcc99fc8aac68aa157831c7a3ff1c1358af5a0c50b64e0ef0e96a970"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a3ff1c1358af5a0c50b64e0ef0e96a970"></a></strong>PROTOCOL_80211_IFTYPE_MONITOR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445220391165623"><a name="p445220391165623"></a><a name="p445220391165623"></a>Listening </p>
 </td>
</tr>
<tr id="row1704640739165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a382756b8a71015cd536cdbc113c4f483"><a name="ggac69954f56fcc99fc8aac68aa157831c7a382756b8a71015cd536cdbc113c4f483"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a382756b8a71015cd536cdbc113c4f483"></a></strong>PROTOCOL_80211_IFTYPE_MESH_POINT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22296460165623"><a name="p22296460165623"></a><a name="p22296460165623"></a>Mesh network </p>
 </td>
</tr>
<tr id="row2090640549165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7acfd81d6e484c6f7a3b863327af112cfc"><a name="ggac69954f56fcc99fc8aac68aa157831c7acfd81d6e484c6f7a3b863327af112cfc"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7acfd81d6e484c6f7a3b863327af112cfc"></a></strong>PROTOCOL_80211_IFTYPE_P2P_CLIENT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394652304165623"><a name="p1394652304165623"></a><a name="p1394652304165623"></a>P2P client </p>
 </td>
</tr>
<tr id="row839979669165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7abca0ccb5cf4c14af9b6ff0bd9eeb4173"><a name="ggac69954f56fcc99fc8aac68aa157831c7abca0ccb5cf4c14af9b6ff0bd9eeb4173"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7abca0ccb5cf4c14af9b6ff0bd9eeb4173"></a></strong>PROTOCOL_80211_IFTYPE_P2P_GO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26457158165623"><a name="p26457158165623"></a><a name="p26457158165623"></a>P2P group owner </p>
 </td>
</tr>
<tr id="row62602129165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7ad63ad4a5a66892e842e4d75cc82b0755"><a name="ggac69954f56fcc99fc8aac68aa157831c7ad63ad4a5a66892e842e4d75cc82b0755"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7ad63ad4a5a66892e842e4d75cc82b0755"></a></strong>PROTOCOL_80211_IFTYPE_P2P_DEVICE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964189053165623"><a name="p1964189053165623"></a><a name="p1964189053165623"></a>P2P device </p>
 </td>
</tr>
<tr id="row2032418455165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a7f1fa9726ab20597baaa9ebf884b26cd"><a name="ggac69954f56fcc99fc8aac68aa157831c7a7f1fa9726ab20597baaa9ebf884b26cd"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a7f1fa9726ab20597baaa9ebf884b26cd"></a></strong>PROTOCOL_80211_IFTYPE_NUM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297733032165623"><a name="p297733032165623"></a><a name="p297733032165623"></a>Number of network ports </p>
 </td>
</tr>
<tr id="row357919316165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac69954f56fcc99fc8aac68aa157831c7a37b72ea7c4cd81dd4c427e2d721c9499"><a name="ggac69954f56fcc99fc8aac68aa157831c7a37b72ea7c4cd81dd4c427e2d721c9499"></a><a name="ggac69954f56fcc99fc8aac68aa157831c7a37b72ea7c4cd81dd4c427e2d721c9499"></a></strong>PROTOCOL_80211_IFTYPE_MAX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1254477839165623"><a name="p1254477839165623"></a><a name="p1254477839165623"></a>Maximum number of 802.11 network port types </p>
 </td>
</tr>
</tbody>
</table>

## WifiBusType<a name="ga1c5537e64f05b5e91b951ddeb66d4261"></a>

```
enum [WifiBusType](WLAN.md#ga1c5537e64f05b5e91b951ddeb66d4261)
```

 **Description:**

Enumerates bus types of a WLAN module. 

<a name="table998917446165623"></a>
<table><thead align="left"><tr id="row756775801165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p391771542165623"><a name="p391771542165623"></a><a name="p391771542165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p979420825165623"><a name="p979420825165623"></a><a name="p979420825165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row664918325165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga1c5537e64f05b5e91b951ddeb66d4261a0eba50f5eecb33326083a82adbaa0848"><a name="gga1c5537e64f05b5e91b951ddeb66d4261a0eba50f5eecb33326083a82adbaa0848"></a><a name="gga1c5537e64f05b5e91b951ddeb66d4261a0eba50f5eecb33326083a82adbaa0848"></a></strong>BUS_SDIO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208682907165623"><a name="p1208682907165623"></a><a name="p1208682907165623"></a>Secure Digital Input and Output (SDIO) </p>
 </td>
</tr>
<tr id="row1462744184165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga1c5537e64f05b5e91b951ddeb66d4261a2f4f9ff60278d511660c21e211133666"><a name="gga1c5537e64f05b5e91b951ddeb66d4261a2f4f9ff60278d511660c21e211133666"></a><a name="gga1c5537e64f05b5e91b951ddeb66d4261a2f4f9ff60278d511660c21e211133666"></a></strong>BUS_USB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p534362225165623"><a name="p534362225165623"></a><a name="p534362225165623"></a>Universal Serial Bus (USB) </p>
 </td>
</tr>
</tbody>
</table>

## WifiChannelType<a name="ga9d902b330de99c24b2a8c3ba7120af21"></a>

```
enum [WifiChannelType](WLAN.md#ga9d902b330de99c24b2a8c3ba7120af21)
```

 **Description:**

Enumerates channel types. 

<a name="table912937437165623"></a>
<table><thead align="left"><tr id="row586645586165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1384016787165623"><a name="p1384016787165623"></a><a name="p1384016787165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1794267044165623"><a name="p1794267044165623"></a><a name="p1794267044165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row175139118165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9d902b330de99c24b2a8c3ba7120af21ae0707e29a1748ee7f33d51acabaf8810"><a name="gga9d902b330de99c24b2a8c3ba7120af21ae0707e29a1748ee7f33d51acabaf8810"></a><a name="gga9d902b330de99c24b2a8c3ba7120af21ae0707e29a1748ee7f33d51acabaf8810"></a></strong>WIFI_CHAN_NO_HT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583527325165623"><a name="p1583527325165623"></a><a name="p1583527325165623"></a>non-HT channel </p>
 </td>
</tr>
<tr id="row250666226165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9d902b330de99c24b2a8c3ba7120af21a255f513fd4efa8bce0c015086e0588ea"><a name="gga9d902b330de99c24b2a8c3ba7120af21a255f513fd4efa8bce0c015086e0588ea"></a><a name="gga9d902b330de99c24b2a8c3ba7120af21a255f513fd4efa8bce0c015086e0588ea"></a></strong>WIFI_CHAN_HT20 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572914991165623"><a name="p1572914991165623"></a><a name="p1572914991165623"></a>20 MHz HT channel </p>
 </td>
</tr>
<tr id="row2053943308165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9d902b330de99c24b2a8c3ba7120af21a1c6dbd2c2f6be59e4fa8312fe6009a98"><a name="gga9d902b330de99c24b2a8c3ba7120af21a1c6dbd2c2f6be59e4fa8312fe6009a98"></a><a name="gga9d902b330de99c24b2a8c3ba7120af21a1c6dbd2c2f6be59e4fa8312fe6009a98"></a></strong>WIFI_CHAN_HT40MINUS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603047428165623"><a name="p1603047428165623"></a><a name="p1603047428165623"></a>40 MHz minus HT channel (The channel is formed by two 20 MHz HT channels, one as the main channel and the other as the auxiliary channel. The center frequency of the main channel is lower than that of the auxiliary channel.) </p>
 </td>
</tr>
<tr id="row911164023165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga9d902b330de99c24b2a8c3ba7120af21abdc85daa4bd2fdda2cfb14a975099652"><a name="gga9d902b330de99c24b2a8c3ba7120af21abdc85daa4bd2fdda2cfb14a975099652"></a><a name="gga9d902b330de99c24b2a8c3ba7120af21abdc85daa4bd2fdda2cfb14a975099652"></a></strong>WIFI_CHAN_HT40PLUS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2051393730165623"><a name="p2051393730165623"></a><a name="p2051393730165623"></a>40 MHz plus HT channel (The channel is formed by two 20 MHz HT channels, one as the main channel and the other as the auxiliary channel. The center frequency of the main channel is higher than that of the auxiliary channel.) </p>
 </td>
</tr>
</tbody>
</table>

## WifiHmacMgmtStatus<a name="gaf3e873b51f0cfa077aca9d33ed7a0960"></a>

```
enum [WifiHmacMgmtStatus](WLAN.md#gaf3e873b51f0cfa077aca9d33ed7a0960)
```

 **Description:**

Enumerates MLME management statuses, indicating whether a device is successfully associated or fails to be associated. 

<a name="table973035387165623"></a>
<table><thead align="left"><tr id="row189657644165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p357593685165623"><a name="p357593685165623"></a><a name="p357593685165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p124438857165623"><a name="p124438857165623"></a><a name="p124438857165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row929440993165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf3e873b51f0cfa077aca9d33ed7a0960ad9c7e2f362bd6fcadef189fa2a5d7c63"><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960ad9c7e2f362bd6fcadef189fa2a5d7c63"></a><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960ad9c7e2f362bd6fcadef189fa2a5d7c63"></a></strong>WIFI_HMAC_MGMT_SUCCESS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625829901165623"><a name="p625829901165623"></a><a name="p625829901165623"></a>Association succeeds </p>
 </td>
</tr>
<tr id="row609659830165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf3e873b51f0cfa077aca9d33ed7a0960a539c65a358a20b9731fc66fc60ebcbc2"><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960a539c65a358a20b9731fc66fc60ebcbc2"></a><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960a539c65a358a20b9731fc66fc60ebcbc2"></a></strong>WIFI_HMAC_MGMT_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462102692165623"><a name="p462102692165623"></a><a name="p462102692165623"></a>Association fails </p>
 </td>
</tr>
<tr id="row1678526189165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf3e873b51f0cfa077aca9d33ed7a0960ad1731acef8ddb8c50bcc26ae80fa83a3"><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960ad1731acef8ddb8c50bcc26ae80fa83a3"></a><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960ad1731acef8ddb8c50bcc26ae80fa83a3"></a></strong>WIFI_HMAC_MGMT_TIMEOUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214259987165623"><a name="p214259987165623"></a><a name="p214259987165623"></a>Association timeout </p>
 </td>
</tr>
<tr id="row1032481603165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf3e873b51f0cfa077aca9d33ed7a0960a05f532edadae3b6afc80b7575dd46961"><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960a05f532edadae3b6afc80b7575dd46961"></a><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960a05f532edadae3b6afc80b7575dd46961"></a></strong>WIFI_HMAC_MGMT_REFUSED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629020676165623"><a name="p629020676165623"></a><a name="p629020676165623"></a>Association refused </p>
 </td>
</tr>
<tr id="row2129358863165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf3e873b51f0cfa077aca9d33ed7a0960a9e241ef81e72de130e1fda573ce2a412"><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960a9e241ef81e72de130e1fda573ce2a412"></a><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960a9e241ef81e72de130e1fda573ce2a412"></a></strong>WIFI_HMAC_MGMT_TOMANY_REQ </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p85741348165623"><a name="p85741348165623"></a><a name="p85741348165623"></a>Repeated association request </p>
 </td>
</tr>
<tr id="row1984780342165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf3e873b51f0cfa077aca9d33ed7a0960aa3db4634dc2727e029aef13384bc3940"><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960aa3db4634dc2727e029aef13384bc3940"></a><a name="ggaf3e873b51f0cfa077aca9d33ed7a0960aa3db4634dc2727e029aef13384bc3940"></a></strong>WIFI_HMAC_MGMT_ALREADY_BSS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339118202165623"><a name="p1339118202165623"></a><a name="p1339118202165623"></a>Associated with the BSS </p>
 </td>
</tr>
</tbody>
</table>

## WifiMainFeatureType<a name="gaec03ba36d71cc2d5f3209bc24aa6ee10"></a>

```
enum [WifiMainFeatureType](WLAN.md#gaec03ba36d71cc2d5f3209bc24aa6ee10)
```

 **Description:**

Enumerates feature types of a WLAN module. 

You can query and register a feature or bind a feature to a WLAN module based on the feature type.

<a name="table2123597796165623"></a>
<table><thead align="left"><tr id="row1465094850165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1812955566165623"><a name="p1812955566165623"></a><a name="p1812955566165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p860278999165623"><a name="p860278999165623"></a><a name="p860278999165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row440662450165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10a038fb1847d290b75b15949b6471b46ad"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a038fb1847d290b75b15949b6471b46ad"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a038fb1847d290b75b15949b6471b46ad"></a></strong>HDF_WIFI_FEATURE_BASE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311677508165623"><a name="p311677508165623"></a><a name="p311677508165623"></a>Base feature </p>
 </td>
</tr>
<tr id="row757582583165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10aaec6c1686d47187e64fd108e0e797133"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10aaec6c1686d47187e64fd108e0e797133"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10aaec6c1686d47187e64fd108e0e797133"></a></strong>HDF_WIFI_FEATURE_AP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071760700165623"><a name="p1071760700165623"></a><a name="p1071760700165623"></a>AP </p>
 </td>
</tr>
<tr id="row1155690808165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10a0e814bd1cfc59a253cc575d3548a9d4e"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a0e814bd1cfc59a253cc575d3548a9d4e"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a0e814bd1cfc59a253cc575d3548a9d4e"></a></strong>HDF_WIFI_FEATURE_STA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2086847293165623"><a name="p2086847293165623"></a><a name="p2086847293165623"></a>Station </p>
 </td>
</tr>
<tr id="row794166849165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10a8e87c1727fa86bf92ee05cad85e7f872"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a8e87c1727fa86bf92ee05cad85e7f872"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a8e87c1727fa86bf92ee05cad85e7f872"></a></strong>HDF_WIFI_FEATURE_P2P </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623408126165623"><a name="p623408126165623"></a><a name="p623408126165623"></a>Peer-to-peer (P2P) </p>
 </td>
</tr>
<tr id="row1769391740165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10ae30b51638bc2c2fb739b3ddec6c5b92b"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10ae30b51638bc2c2fb739b3ddec6c5b92b"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10ae30b51638bc2c2fb739b3ddec6c5b92b"></a></strong>HDF_WIFI_FEATURE_NAN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646123850165623"><a name="p1646123850165623"></a><a name="p1646123850165623"></a>Neighbor Awareness Networking (NAN) </p>
 </td>
</tr>
<tr id="row31069717165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10ac12422e335003fbd392bff47c53c0352"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10ac12422e335003fbd392bff47c53c0352"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10ac12422e335003fbd392bff47c53c0352"></a></strong>HDF_WIFI_FEATURE_RTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903872396165623"><a name="p1903872396165623"></a><a name="p1903872396165623"></a>Round Trip Time (RTT) </p>
 </td>
</tr>
<tr id="row360947930165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaec03ba36d71cc2d5f3209bc24aa6ee10a28ff5971d579c1754e03a5f79a0c9e6f"><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a28ff5971d579c1754e03a5f79a0c9e6f"></a><a name="ggaec03ba36d71cc2d5f3209bc24aa6ee10a28ff5971d579c1754e03a5f79a0c9e6f"></a></strong>HDF_WIFI_FEATURE_NUM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235119805165623"><a name="p1235119805165623"></a><a name="p1235119805165623"></a>Maximum number of features </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section2116187334165623"></a>

## AddFeature\(\)<a name="gae928a69366143780650b73c6b030c3a7"></a>

```
int32_t AddFeature (struct [WifiModule](WifiModule.md) * module, uint16_t featureType, struct [WifiFeature](WifiFeature.md) * featureData )
```

 **Description:**

Adds a specified feature to a specified module. 

**Parameters:**

<a name="table2140500185165623"></a>
<table><thead align="left"><tr id="row1692164081165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1987276683165623"><a name="p1987276683165623"></a><a name="p1987276683165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1522034605165623"><a name="p1522034605165623"></a><a name="p1522034605165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row518590189165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">module</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the module. </td>
</tr>
<tr id="row2024494424165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">featureType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the feature to add. </td>
</tr>
<tr id="row1325811721165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">featureData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the feature to add.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the feature is added successfully; returns a negative value otherwise.

## DelFeature\(\)<a name="ga395848b77fc10f2213d5b12793861292"></a>

```
int32_t DelFeature (struct [WifiModule](WifiModule.md) * module, uint16_t featureType )
```

 **Description:**

Deletes a specified feature from a specified module. 

**Parameters:**

<a name="table1789838866165623"></a>
<table><thead align="left"><tr id="row1120810901165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p592105263165623"><a name="p592105263165623"></a><a name="p592105263165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p121084890165623"><a name="p121084890165623"></a><a name="p121084890165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1311650954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">module</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the module. </td>
</tr>
<tr id="row516270464165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">featureType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the feature to delete.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the feature is deleted successfully; returns  **-1**  otherwise.

## HdfWifiEventConnectResult\(\)<a name="gaf9e61f36e11d7d2e94e7969a8ecf22f1"></a>

```
int32_t HdfWifiEventConnectResult (const struct [NetDevice](NetDevice.md) * netdev, const struct [ConnetResult](ConnetResult.md) * result )
```

 **Description:**

Reports a connection result event. 

**Parameters:**

<a name="table974906645165623"></a>
<table><thead align="left"><tr id="row1458465664165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1173072808165623"><a name="p1173072808165623"></a><a name="p1173072808165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p175068999165623"><a name="p175068999165623"></a><a name="p175068999165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row153268746165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row1336276787165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">result</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the connection result. This parameter cannot be null.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventCsaChannelSwitch\(\)<a name="ga2aa62f7e8e72e8f9df0b2101c08a9d44"></a>

```
int32_t HdfWifiEventCsaChannelSwitch (const struct [NetDevice](NetDevice.md) * netdev, int32_t freq )
```

 **Description:**

Reports a CSA channel switching event. 

**Parameters:**

<a name="table1284007329165623"></a>
<table><thead align="left"><tr id="row1680785805165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p379330510165623"><a name="p379330510165623"></a><a name="p379330510165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p866178316165623"><a name="p866178316165623"></a><a name="p866178316165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1392640689165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row1582089036165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">freq</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frequency of the channel.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventDelSta\(\)<a name="ga208ef54b2a601f416a472bb1e21fae7e"></a>

```
int32_t HdfWifiEventDelSta (struct [NetDevice](NetDevice.md) * netdev, const uint8_t * macAddr, uint8_t addrLen )
```

 **Description:**

Reports a station deletion event. 

**Parameters:**

<a name="table1365915057165623"></a>
<table><thead align="left"><tr id="row2093829228165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1058256026165623"><a name="p1058256026165623"></a><a name="p1058256026165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p665823251165623"><a name="p665823251165623"></a><a name="p665823251165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1473206451165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row2061278244165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">macAddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the MAC address of the station. This parameter cannot be null. </td>
</tr>
<tr id="row567237502165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addrLen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the MAC address of the station. The length is fixed to six bytes.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventDisconnected\(\)<a name="ga58b1a613d784233a1e84027079e1ea57"></a>

```
int32_t HdfWifiEventDisconnected (const struct [NetDevice](NetDevice.md) * netdev, uint16_t reason, const uint8_t * ie, uint32_t len )
```

 **Description:**

Reports a disconnection event. 

**Parameters:**

<a name="table123632422165623"></a>
<table><thead align="left"><tr id="row862558777165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1344666702165623"><a name="p1344666702165623"></a><a name="p1344666702165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1243757764165623"><a name="p1243757764165623"></a><a name="p1243757764165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1974941676165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row1464744512165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">reason</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the reason for disconnection. </td>
</tr>
<tr id="row1229788800165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ie</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the deauth/disassoc frame IE. </td>
</tr>
<tr id="row392455401165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ieLen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the deauth/disassoc IE.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventEapolRecv\(\)<a name="ga3e60f4568723471226107848ddbe582f"></a>

```
int32_t HdfWifiEventEapolRecv (const char * name, void * context )
```

 **Description:**

Reports the event of receiving the EAPOL frame and notifies WPA to read the EAPOL frame. 

**Parameters:**

<a name="table1634623545165623"></a>
<table><thead align="left"><tr id="row1088193898165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p945222215165623"><a name="p945222215165623"></a><a name="p945222215165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p108386585165623"><a name="p108386585165623"></a><a name="p108386585165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row888067720165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network port name, for example, <strong id="b777090978165623"><a name="b777090978165623"></a><a name="b777090978165623"></a>wlan0</strong>. </td>
</tr>
<tr id="row1317337656165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">context</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the context. This parameter is reserved.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise.

## HdfWifiEventInformBssFrame\(\)<a name="ga941675fb683212e6e0d8e1529b300482"></a>

```
int32_t HdfWifiEventInformBssFrame (const struct [NetDevice](NetDevice.md) * netdev, struct [Wiphy](Wiphy.md) * wiphy, const struct [Ieee80211Channel](Ieee80211Channel.md) * channel, const struct [ScannedBssInfo](ScannedBssInfo.md) * bssInfo )
```

 **Description:**

Reports a scanned BSS event. 

**Parameters:**

<a name="table327210583165623"></a>
<table><thead align="left"><tr id="row490116298165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p938028919165623"><a name="p938028919165623"></a><a name="p938028919165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p789403001165623"><a name="p789403001165623"></a><a name="p789403001165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row843405132165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row877945797165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">wiphy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the physical layer of the wireless network. This parameter cannot be null. </td>
</tr>
<tr id="row2125146877165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">channel</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the channel information. This parameter cannot be null. </td>
</tr>
<tr id="row1904995601165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bssInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the BSS information. This parameter cannot be null.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventMgmtTxStatus\(\)<a name="ga1721c7e1b5af0240a663ea9f0fe12854"></a>

```
int32_t HdfWifiEventMgmtTxStatus (const struct [NetDevice](NetDevice.md) * netdev, const uint8_t * buf, size_t len, uint8_t ack )
```

 **Description:**

Reports a transmission management status event. 

**Parameters:**

<a name="table1276311059165623"></a>
<table><thead align="left"><tr id="row1707474371165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p911131116165623"><a name="p911131116165623"></a><a name="p911131116165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p872336759165623"><a name="p872336759165623"></a><a name="p872336759165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row936528536165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row2101683404165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the transmission management frame. This parameter cannot be null. </td>
</tr>
<tr id="row835603360165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the transmission management frame. </td>
</tr>
<tr id="row938377553165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ack</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates whether the transmission management frame is acknowledged.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventNewSta\(\)<a name="ga31edc1e9de8835e0e8a9c1e89fad3bd9"></a>

```
int32_t HdfWifiEventNewSta (const struct [NetDevice](NetDevice.md) * netdev, const uint8_t * macAddr, uint8_t addrLen, const struct [StationInfo](StationInfo.md) * info )
```

 **Description:**

Reports a new STA event. 

**Parameters:**

<a name="table595593488165623"></a>
<table><thead align="left"><tr id="row373099912165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1938463689165623"><a name="p1938463689165623"></a><a name="p1938463689165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1049438031165623"><a name="p1049438031165623"></a><a name="p1049438031165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row530396380165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row812993097165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">macAddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the MAC address of the station. This parameter cannot be null. </td>
</tr>
<tr id="row1068419668165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addrLen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the MAC address of the station. The length is fixed to six bytes. </td>
</tr>
<tr id="row170981561165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the station information.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventRxMgmt\(\)<a name="gad47d56e4332ccd14116368444a4b330f"></a>

```
int32_t HdfWifiEventRxMgmt (const struct [NetDevice](NetDevice.md) * netdev, int32_t freq, int32_t sigMbm, const uint8_t * buf, size_t len )
```

 **Description:**

Reports a receive management status event. 

**Parameters:**

<a name="table1411409025165623"></a>
<table><thead align="left"><tr id="row56687553165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p21846247165623"><a name="p21846247165623"></a><a name="p21846247165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1651291825165623"><a name="p1651291825165623"></a><a name="p1651291825165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1597285393165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row619891556165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">freq</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frequency of receiving management frame. </td>
</tr>
<tr id="row1503806610165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sigMbm</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal strength (in dBm). </td>
</tr>
<tr id="row2038346775165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the receive management frame. This parameter cannot be null. </td>
</tr>
<tr id="row441402832165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the receive management frame.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventScanDone\(\)<a name="ga41efbd6788a80604b81ae117a363b657"></a>

```
int32_t HdfWifiEventScanDone (const struct [NetDevice](NetDevice.md) * netdev, WifiScanStatus status )
```

 **Description:**

Reports a scanning completion event. 

**Parameters:**

<a name="table1333007132165623"></a>
<table><thead align="left"><tr id="row313035486165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1225814998165623"><a name="p1225814998165623"></a><a name="p1225814998165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1618807541165623"><a name="p1618807541165623"></a><a name="p1618807541165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row946184517165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null. </td>
</tr>
<tr id="row1481888930165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the scanning completion status. Value <strong id="b512561793165623"><a name="b512561793165623"></a><a name="b512561793165623"></a>0</strong> indicates that the scanning is successful, and other values indicate that the scanning fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiEventTimeoutDisconnected\(\)<a name="gafda13471995c91e65326a9aa374ae1c9"></a>

```
int32_t HdfWifiEventTimeoutDisconnected (const struct [NetDevice](NetDevice.md) * netdev)
```

 **Description:**

Reports a timeout disconnection event. 

**Parameters:**

<a name="table2016431718165623"></a>
<table><thead align="left"><tr id="row1595362666165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p217686990165623"><a name="p217686990165623"></a><a name="p217686990165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p923392767165623"><a name="p923392767165623"></a><a name="p923392767165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1478780236165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. This parameter cannot be null.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the event is reported successfully; returns  **-1**  otherwise.

## HdfWifiGetProduct\(\)<a name="ga77f15efb80095134d08cc63b62229f21"></a>

```
struct [HdfWifiProductData](HdfWifiProductData.md)* HdfWifiGetProduct (void )
```

 **Description:**

Obtains the data structure of the WLAN module. 

**Returns:**

Returns the pointer to the data structure of the WLAN module. For details, see  [HdfWifiProductData](HdfWifiProductData.md).

## Mac80211GetOps\(\)<a name="gad7c34413d81d55ba090c90404d340c8a"></a>

```
struct [WifiMac80211Ops](WifiMac80211Ops.md)* Mac80211GetOps (void )
```

 **Description:**

Obtains the  [WifiMac80211Ops](WifiMac80211Ops.md)  object that the driver needs to implement. 

**Returns:**

Returns the pointer to the  [WifiMac80211Ops](WifiMac80211Ops.md)  object.

## Mac80211RegisterOps\(\)<a name="ga6542a735af0fe7496789c3c55380adfa"></a>

```
int32_t Mac80211RegisterOps (struct [WifiMac80211Ops](WifiMac80211Ops.md) * ops)
```

 **Description:**

Registers a  [WifiMac80211Ops](WifiMac80211Ops.md)  object. 

**Parameters:**

<a name="table235439172165623"></a>
<table><thead align="left"><tr id="row101007462165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1173478018165623"><a name="p1173478018165623"></a><a name="p1173478018165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1040626393165623"><a name="p1040626393165623"></a><a name="p1040626393165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row177991719165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ops</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="WifiMac80211Ops.md">WifiMac80211Ops</a> object to register.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the  [WifiMac80211Ops](WifiMac80211Ops.md)  object is registered successfully; returns a non-zero value otherwise.

## NetBuf2Pbuf\(\)<a name="ga88e4943fc1b1f4e31f388bf8eec57476"></a>

```
struct pbuf* NetBuf2Pbuf (const struct [NetBuf](NetBuf.md) * nb)
```

 **Description:**

Converts a network data buffer to the  **pbuf**  structure of Lightweight TCP/IP Stack \(lwIP\). 

**Parameters:**

<a name="table1932390326165623"></a>
<table><thead align="left"><tr id="row175012808165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1207151330165623"><a name="p1207151330165623"></a><a name="p1207151330165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1488213646165623"><a name="p1488213646165623"></a><a name="p1488213646165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row926568653165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the  **pbuf**  structure if the operation is successful; returns  **NULL**  otherwise.

## NetBufAlloc\(\)<a name="ga5ced2af63a9064b0e33d0aa4e86b3fc1"></a>

```
struct [NetBuf](NetBuf.md)* NetBufAlloc (uint32_t size)
```

 **Description:**

Applies for a network data buffer. 

**Parameters:**

<a name="table51341090165623"></a>
<table><thead align="left"><tr id="row997200433165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1811056102165623"><a name="p1811056102165623"></a><a name="p1811056102165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1170523137165623"><a name="p1170523137165623"></a><a name="p1170523137165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1375848950165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the network data buffer.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the network data buffer if the operation is successful; returns  **NULL**  otherwise.

## NetBufConcat\(\)<a name="ga89ee14a3da1b7b83325045af9c488ef8"></a>

```
uint32_t NetBufConcat (struct [NetBuf](NetBuf.md) * nb, struct [NetBuf](NetBuf.md) * cnb )
```

 **Description:**

Copies data in a network data buffer to another network data buffer. 

**Parameters:**

<a name="table1805144390165623"></a>
<table><thead align="left"><tr id="row662877073165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p374993884165623"><a name="p374993884165623"></a><a name="p374993884165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1709402867165623"><a name="p1709402867165623"></a><a name="p1709402867165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1877513935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer. </td>
</tr>
<tr id="row1118113337165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cnb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target network data buffer.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetBufDevAlloc\(\)<a name="ga74198f03268aadc025f6b76056b09604"></a>

```
struct [NetBuf](NetBuf.md)* NetBufDevAlloc (const struct [NetDevice](NetDevice.md) * dev, uint32_t size )
```

 **Description:**

Applies for a network data buffer based on the reserved space and requested size set by a network device. 

**Parameters:**

<a name="table787815377165623"></a>
<table><thead align="left"><tr id="row903223576165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1949947878165623"><a name="p1949947878165623"></a><a name="p1949947878165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p651259252165623"><a name="p651259252165623"></a><a name="p651259252165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1192728533165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. </td>
</tr>
<tr id="row1549580224165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the network data buffer applied.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the network data buffer if the operation is successful; returns  **NULL**  otherwise.

## NetBufFree\(\)<a name="ga9320642699593dfecd79dc30132dd4eb"></a>

```
void NetBufFree (struct [NetBuf](NetBuf.md) * nb)
```

 **Description:**

Releases a network data buffer. 

**Parameters:**

<a name="table679931341165623"></a>
<table><thead align="left"><tr id="row374106312165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p591668036165623"><a name="p591668036165623"></a><a name="p591668036165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1156013228165623"><a name="p1156013228165623"></a><a name="p1156013228165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1246523644165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer.</td>
</tr>
</tbody>
</table>

## NetBufGetAddress\(\)<a name="gacd40d5004291b4aaa5c27703d9379c9c"></a>

```
static uint8_t* NetBufGetAddress (const struct [NetBuf](NetBuf.md) * nb, uint32_t id )
```

 **Description:**

Obtains the address of a specified buffer segment in a network data buffer. 

**Parameters:**

<a name="table1371962234165623"></a>
<table><thead align="left"><tr id="row1248690319165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p503164798165623"><a name="p503164798165623"></a><a name="p503164798165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p484657655165623"><a name="p484657655165623"></a><a name="p484657655165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row910022953165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer. </td>
</tr>
<tr id="row40757106165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer segment ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the address of the specified buffer segment if the operation is successful; returns  **NULL**  if the buffer segment ID is invalid.

## NetBufGetDataLen\(\)<a name="ga67eeb57ebe467b9caa4f31734955727b"></a>

```
static uint32_t NetBufGetDataLen (const struct [NetBuf](NetBuf.md) * nb)
```

 **Description:**

Obtains the actual data length of the data segment of a network data buffer. 

**Parameters:**

<a name="table1401182034165623"></a>
<table><thead align="left"><tr id="row45392957165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p694563849165623"><a name="p694563849165623"></a><a name="p694563849165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p516428382165623"><a name="p516428382165623"></a><a name="p516428382165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row927598518165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the actual data length of the data segment.

## NetBufGetRoom\(\)<a name="ga09245834fe9f55fe475a0dc226a6a709"></a>

```
static uint32_t NetBufGetRoom (const struct [NetBuf](NetBuf.md) * nb, uint32_t id )
```

 **Description:**

Obtains the size of a specified buffer segment space in a network data buffer. 

**Parameters:**

<a name="table844773048165623"></a>
<table><thead align="left"><tr id="row1963118597165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p469093204165623"><a name="p469093204165623"></a><a name="p469093204165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p378726515165623"><a name="p378726515165623"></a><a name="p378726515165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1260345302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer. </td>
</tr>
<tr id="row724529745165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer segment ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the size of the specified buffer segment space if the operation is successful; returns  **NULL**  if the buffer segment ID is invalid.

## NetBufPop\(\)<a name="ga81f298aebc5b7772f173e2f6fadc004f"></a>

```
void* NetBufPop (struct [NetBuf](NetBuf.md) * nb, uint32_t id, uint32_t len )
```

 **Description:**

Performs operations based on the segment ID of a network data buffer. The function is opposite to that of  [NetBufPush](WLAN.md#gac4ec1cedef616e61038dcb6dbf67d204). 

Description: 

**Parameters:**

<a name="table1189707014165623"></a>
<table><thead align="left"><tr id="row1338657394165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1896191272165623"><a name="p1896191272165623"></a><a name="p1896191272165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p969606532165623"><a name="p969606532165623"></a><a name="p969606532165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1538545983165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer. </td>
</tr>
<tr id="row873511081165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer segment ID. </td>
</tr>
<tr id="row1852946197165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the operation length.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the start address of the data segment if the operation is successful; returns  **NULL**  if the operation length exceeds the space of a specified buffer segment.

## NetBufPush\(\)<a name="gac4ec1cedef616e61038dcb6dbf67d204"></a>

```
void* NetBufPush (struct [NetBuf](NetBuf.md) * nb, uint32_t id, uint32_t len )
```

 **Description:**

Performs operations based on the segment ID of a network data buffer. The function is opposite to that of  [NetBufPop](WLAN.md#ga81f298aebc5b7772f173e2f6fadc004f). 

Description: 

**Parameters:**

<a name="table1056064214165623"></a>
<table><thead align="left"><tr id="row293106033165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1715255267165623"><a name="p1715255267165623"></a><a name="p1715255267165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1892669514165623"><a name="p1892669514165623"></a><a name="p1892669514165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row701662068165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer. </td>
</tr>
<tr id="row1504207549165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer segment ID. </td>
</tr>
<tr id="row894628547165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the operation length.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the start address of the data segment if the operation is successful; returns  **NULL**  if the operation length exceeds the space of a specified buffer segment.

## NetBufQueueAtHead\(\)<a name="ga082b7a173ca09288c3b418ce4e4faa7d"></a>

```
static struct [NetBuf](NetBuf.md)* NetBufQueueAtHead (const struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Obtains the network data buffer from the header of a queue, without deleting it from the queue. 

**Parameters:**

<a name="table725932319165623"></a>
<table><thead align="left"><tr id="row1124448554165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1104539286165623"><a name="p1104539286165623"></a><a name="p1104539286165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p897887889165623"><a name="p897887889165623"></a><a name="p897887889165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row619908699165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the first network data buffer if the queue is not empty; returns  **NULL**  otherwise.

## NetBufQueueAtTail\(\)<a name="ga9de36bf1db57bd4eb042e87cb63dae69"></a>

```
static struct [NetBuf](NetBuf.md)* NetBufQueueAtTail (const struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Obtains the network data buffer from the tail of a queue, without deleting it from the queue. 

**Parameters:**

<a name="table180925673165623"></a>
<table><thead align="left"><tr id="row258027139165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1915092138165623"><a name="p1915092138165623"></a><a name="p1915092138165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p135801239165623"><a name="p135801239165623"></a><a name="p135801239165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1255445197165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the last network data buffer if the queue is not empty; returns  **NULL**  otherwise.

## NetBufQueueClear\(\)<a name="ga79045ebd1636c27bee454e9541498f33"></a>

```
void NetBufQueueClear (struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Clears a network data buffer queue and releases the network data buffer in the queue. 

**Parameters:**

<a name="table129312976165623"></a>
<table><thead align="left"><tr id="row1925771057165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1001933438165623"><a name="p1001933438165623"></a><a name="p1001933438165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1561959160165623"><a name="p1561959160165623"></a><a name="p1561959160165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row938366044165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

## NetBufQueueConcat\(\)<a name="ga2331e6b8c8f1ac4f00f8a1206fb1a3d8"></a>

```
void NetBufQueueConcat (struct [NetBufQueue](NetBufQueue.md) * q, struct [NetBufQueue](NetBufQueue.md) * add )
```

 **Description:**

Moves all network data buffers from one queue to another and clears the source queue. 

**Parameters:**

<a name="table401085023165623"></a>
<table><thead align="left"><tr id="row610399139165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1820763920165623"><a name="p1820763920165623"></a><a name="p1820763920165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2002383666165623"><a name="p2002383666165623"></a><a name="p2002383666165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1038241492165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target network data buffer queue. </td>
</tr>
<tr id="row392994569165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">add</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the source network data buffer queue.</td>
</tr>
</tbody>
</table>

## NetBufQueueDequeue\(\)<a name="ga4ad66d7ca7aabda3aef08fa541dc9ee4"></a>

```
struct [NetBuf](NetBuf.md)* NetBufQueueDequeue (struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Obtains a network data buffer from the header of a queue and deletes it from the queue. 

**Parameters:**

<a name="table987574875165623"></a>
<table><thead align="left"><tr id="row934478812165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1820384484165623"><a name="p1820384484165623"></a><a name="p1820384484165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p293496942165623"><a name="p293496942165623"></a><a name="p293496942165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1183169873165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the first network data buffer if the queue is not empty; returns  **NULL**  otherwise.

## NetBufQueueDequeueTail\(\)<a name="ga390319a0419c26c73552bcee6b8d5c32"></a>

```
struct [NetBuf](NetBuf.md)* NetBufQueueDequeueTail (struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Obtains a network data buffer from the tail of a queue and deletes it from the queue. 

**Parameters:**

<a name="table1776761141165623"></a>
<table><thead align="left"><tr id="row228293032165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p717509299165623"><a name="p717509299165623"></a><a name="p717509299165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1961564696165623"><a name="p1961564696165623"></a><a name="p1961564696165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row692541484165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the last network data buffer if the queue is not empty; returns  **NULL**  otherwise.

## NetBufQueueEnqueue\(\)<a name="ga25bf5d56e8afec1bc80080b20c3b7daa"></a>

```
void NetBufQueueEnqueue (struct [NetBufQueue](NetBufQueue.md) * q, struct [NetBuf](NetBuf.md) * nb )
```

 **Description:**

Adds a network data buffer to the tail of a queue. 

**Parameters:**

<a name="table1662427177165623"></a>
<table><thead align="left"><tr id="row1883618116165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1966573969165623"><a name="p1966573969165623"></a><a name="p1966573969165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2025649368165623"><a name="p2025649368165623"></a><a name="p2025649368165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2081869815165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue. </td>
</tr>
<tr id="row157146268165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer.</td>
</tr>
</tbody>
</table>

## NetBufQueueEnqueueHead\(\)<a name="ga5ebe7aff6d5187645869f067b0a8f659"></a>

```
void NetBufQueueEnqueueHead (struct [NetBufQueue](NetBufQueue.md) * q, struct [NetBuf](NetBuf.md) * nb )
```

 **Description:**

Adds a network data buffer to the header of a queue. 

**Parameters:**

<a name="table314342170165623"></a>
<table><thead align="left"><tr id="row1494415654165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1780548074165623"><a name="p1780548074165623"></a><a name="p1780548074165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1425925695165623"><a name="p1425925695165623"></a><a name="p1425925695165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1358771656165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue. </td>
</tr>
<tr id="row837731517165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer.</td>
</tr>
</tbody>
</table>

## NetBufQueueInit\(\)<a name="ga6e754d5529b23b413d1fe00102a95db9"></a>

```
static void NetBufQueueInit (struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Initializes a network data buffer queue. 

**Parameters:**

<a name="table925391574165623"></a>
<table><thead align="left"><tr id="row834629282165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1256662766165623"><a name="p1256662766165623"></a><a name="p1256662766165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1748156535165623"><a name="p1748156535165623"></a><a name="p1748156535165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1411095983165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

## NetBufQueueIsEmpty\(\)<a name="ga36297284c60746f2b6895d94ea5e2dc3"></a>

```
static bool NetBufQueueIsEmpty (const struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Checks whether the network data buffer queue is empty. 

**Parameters:**

<a name="table2044191214165623"></a>
<table><thead align="left"><tr id="row2075167609165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p107539040165623"><a name="p107539040165623"></a><a name="p107539040165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p439283233165623"><a name="p439283233165623"></a><a name="p439283233165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row21562930165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the queue is empty; returns  **false**  otherwise.

## NetBufQueueSize\(\)<a name="gaaa5c00efd1dedecf846af4dd108b6701"></a>

```
static uint32_t NetBufQueueSize (const struct [NetBufQueue](NetBufQueue.md) * q)
```

 **Description:**

Obtains the size of a network data buffer queue. 

**Parameters:**

<a name="table1348308878165623"></a>
<table><thead align="left"><tr id="row1023983472165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p43642165623"><a name="p43642165623"></a><a name="p43642165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p262823064165623"><a name="p262823064165623"></a><a name="p262823064165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row738429089165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">q</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer queue.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the size of the network data buffer queue.

## NetBufResizeRoom\(\)<a name="ga623e0b15e65f317f746b53b9a4530bdd"></a>

```
int32_t NetBufResizeRoom (struct [NetBuf](NetBuf.md) * nb, uint32_t head, uint32_t tail )
```

 **Description:**

Adjusts the size of a network data buffer space. 

This function is used to apply for a new network data buffer based on the configured reserved space and the size of the source network data buffer, and copy the actual data to the new network data buffer.

**Parameters:**

<a name="table174979281165623"></a>
<table><thead align="left"><tr id="row1553706917165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p72475013165623"><a name="p72475013165623"></a><a name="p72475013165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p840034361165623"><a name="p840034361165623"></a><a name="p840034361165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row62088114165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network data buffer. </td>
</tr>
<tr id="row1800684958165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the header buffer segment reserved. </td>
</tr>
<tr id="row1496310120165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tail</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the tail buffer segment reserved.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetDevGetRegisterCount\(\)<a name="ga8c8d400a6b4eb64445a2b4ea12102c9a"></a>

```
uint32_t NetDevGetRegisterCount (void )
```

 **Description:**

Obtains the number of added network devices. 

**Returns:**

Returns the number of added network devices.

## NetDeviceAdd\(\)<a name="ga64be10f09b180d3098e9550163131dbd"></a>

```
int32_t NetDeviceAdd (struct [NetDevice](NetDevice.md) * netDevice, [Protocol80211IfType](WLAN.md#gac69954f56fcc99fc8aac68aa157831c7) ifType )
```

 **Description:**

Adds a network device to a protocol stack. 

**Parameters:**

<a name="table1862940479165623"></a>
<table><thead align="left"><tr id="row1646879274165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p651093293165623"><a name="p651093293165623"></a><a name="p651093293165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p252042202165623"><a name="p252042202165623"></a><a name="p252042202165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2145133688165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure obtained during initialization. </td>
</tr>
<tr id="row1137972546165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network port type, as enumerated in <a href="WLAN.md#gac69954f56fcc99fc8aac68aa157831c7">Protocol80211IfType</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value representing  [HDF\_STATUS](DriverUtils.md#ga7e01536ecbe9b17563dd3fe256202a67)  if the operation fails.

## NetDeviceDeInit\(\)<a name="gaf4a2fa8b1a35d4cadd8247ee8fed60a4"></a>

```
int32_t NetDeviceDeInit (struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Deletes a network device. 

**Parameters:**

<a name="table926001621165623"></a>
<table><thead align="left"><tr id="row154094745165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1554670399165623"><a name="p1554670399165623"></a><a name="p1554670399165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1908624047165623"><a name="p1908624047165623"></a><a name="p1908624047165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1273838022165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value representing  [HDF\_STATUS](DriverUtils.md#ga7e01536ecbe9b17563dd3fe256202a67)  if the operation fails.

## NetDeviceDelete\(\)<a name="ga6c93cb701cf2523eaa7bbeabd4acf3ab"></a>

```
int32_t NetDeviceDelete (struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Deletes a network device from a protocol stack. 

**Parameters:**

<a name="table1683124627165623"></a>
<table><thead align="left"><tr id="row273043328165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p877809408165623"><a name="p877809408165623"></a><a name="p877809408165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p259039986165623"><a name="p259039986165623"></a><a name="p259039986165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1221123366165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure <strong id="b872662343165623"><a name="b872662343165623"></a><a name="b872662343165623"></a>netDevice</strong> obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value representing  [HDF\_STATUS](DriverUtils.md#ga7e01536ecbe9b17563dd3fe256202a67)  if the operation fails.

## NetDeviceGetCap\(\)<a name="ga5d2a4fd370e2115b4c1fc8ecc46d64ab"></a>

```
uint32_t NetDeviceGetCap (void )
```

 **Description:**

Obtains the maximum number of network devices that can be registered with this system at the same time. 

**Returns:**

Returns the maximum number of network devices.

## NetDeviceGetInstByIndex\(\)<a name="gab45261476e710c30335975726af3a834"></a>

```
struct [NetDevice](NetDevice.md)* NetDeviceGetInstByIndex (uint32_t index)
```

 **Description:**

Obtains a network device instance based on the index number. 

**Parameters:**

<a name="table1977507252165623"></a>
<table><thead align="left"><tr id="row222879235165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p873396373165623"><a name="p873396373165623"></a><a name="p873396373165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p442182476165623"><a name="p442182476165623"></a><a name="p442182476165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row154016785165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index number.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the network device structure  [NetDevice](NetDevice.md)  if the operation is successful; returns  **NULL**  if the operation fails.

## NetDeviceGetInstByName\(\)<a name="ga6d90d1bf783a83db1d838d03f8c1d93a"></a>

```
struct [NetDevice](NetDevice.md)* NetDeviceGetInstByName (const char * name)
```

 **Description:**

Obtains the initialized network device instance by a specified device name. 

**Parameters:**

<a name="table1648908860165623"></a>
<table><thead align="left"><tr id="row720804130165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p14423980165623"><a name="p14423980165623"></a><a name="p14423980165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1404775075165623"><a name="p1404775075165623"></a><a name="p1404775075165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row542793242165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device name.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the network device structure  [NetDevice](NetDevice.md)  matching the network device name if the operation is successful; returns  **NULL**  if the operation fails.

## NetDeviceInit\(\)<a name="ga8d2bff6673ec21ba317d596a84df7ca8"></a>

```
struct [NetDevice](NetDevice.md)* NetDeviceInit (const char * ifName, uint32_t len, [NetIfCategory](WLAN.md#ga530241881cd17e03f8ae254ef1d9755e) ifCategory )
```

 **Description:**

Initializes a network device to obtain its instance. 

**Parameters:**

<a name="table800221348165623"></a>
<table><thead align="left"><tr id="row1571266358165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1849175437165623"><a name="p1849175437165623"></a><a name="p1849175437165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p332515458165623"><a name="p332515458165623"></a><a name="p332515458165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row645183476165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ifName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device name. </td>
</tr>
<tr id="row370383750165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the network device name. </td>
</tr>
<tr id="row2139749242165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ifCategory</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network port category.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the structure  [NetDevice](NetDevice.md)  for the initialized network device if the operation is successful; returns  **NULL**  if the operation fails.

## NetDeviceIsAnyInstRunning\(\)<a name="ga20fcbcc248e99917c17223a97fe5d70e"></a>

```
bool NetDeviceIsAnyInstRunning (void )
```

 **Description:**

Checks whether there are working devices among the added network devices. 

**Returns:**

Returns  **true**  if the added network devices are working; returns  **false**  if none of the added network devices is working.

## NetDeviceIsInstRunning\(\)<a name="ga05b08c890c69f3e633447f14e16d30f7"></a>

```
bool NetDeviceIsInstRunning (const struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Checks whether a specified network device is working. 

**Parameters:**

<a name="table342924539165623"></a>
<table><thead align="left"><tr id="row280495679165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2012672556165623"><a name="p2012672556165623"></a><a name="p2012672556165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p878994698165623"><a name="p878994698165623"></a><a name="p878994698165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1870245092165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure <strong id="b2047688647165623"><a name="b2047688647165623"></a><a name="b2047688647165623"></a>netDevice</strong> obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the specified network device is working; returns  **false**  otherwise.

## NetIfDhcpIsBound\(\)<a name="ga389ec95a3c8170c4ca74487f8bc1d8ac"></a>

```
int32_t NetIfDhcpIsBound (const struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Obtains the DHCP negotiation status of a specified network device. 

**Parameters:**

<a name="table2118991760165623"></a>
<table><thead align="left"><tr id="row112463963165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2044271658165623"><a name="p2044271658165623"></a><a name="p2044271658165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p938376294165623"><a name="p938376294165623"></a><a name="p938376294165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row669833135165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfDhcpsStart\(\)<a name="gae97c7abcf556be34798622a85162c35e"></a>

```
int32_t NetIfDhcpsStart (const struct [NetDevice](NetDevice.md) * netDevice, char * ip, u16_t ipNum )
```

 **Description:**

Starts the DHCP server. 

**Parameters:**

<a name="table363931565165623"></a>
<table><thead align="left"><tr id="row983935295165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p907711094165623"><a name="p907711094165623"></a><a name="p907711094165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1214995708165623"><a name="p1214995708165623"></a><a name="p1214995708165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1622029865165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure <strong id="b131915848165623"><a name="b131915848165623"></a><a name="b131915848165623"></a>netDevice</strong> obtained during initialization. </td>
</tr>
<tr id="row2064791378165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">beginIp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the IP address to start. </td>
</tr>
<tr id="row649564248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ipNum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of IP addresses.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfDhcpsStop\(\)<a name="gaadfeb819b4cb623870823fa5c9793b4c"></a>

```
int32_t NetIfDhcpsStop (const struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Stops the DHCP server. 

**Parameters:**

<a name="table1348966778165623"></a>
<table><thead align="left"><tr id="row602691316165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1014916191165623"><a name="p1014916191165623"></a><a name="p1014916191165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1860293327165623"><a name="p1860293327165623"></a><a name="p1860293327165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row893053361165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure <strong id="b1626762107165623"><a name="b1626762107165623"></a><a name="b1626762107165623"></a>netDevice</strong> obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfDhcpStart\(\)<a name="ga5fdd93c820b994adf1b76eb8d50e4f88"></a>

```
int32_t NetIfDhcpStart (const struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Starts the DHCP client of a specified network device. 

**Parameters:**

<a name="table2044816716165623"></a>
<table><thead align="left"><tr id="row1447440304165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p165283742165623"><a name="p165283742165623"></a><a name="p165283742165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1221902738165623"><a name="p1221902738165623"></a><a name="p1221902738165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row306203484165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfDhcpStop\(\)<a name="ga22f97a3fc45841e874ab2072c14e0f3e"></a>

```
int32_t NetIfDhcpStop (const struct [NetDevice](NetDevice.md) * netDevice)
```

 **Description:**

Stops the DHCP client of a specified network device. 

**Parameters:**

<a name="table371051081165623"></a>
<table><thead align="left"><tr id="row1636596596165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1998855364165623"><a name="p1998855364165623"></a><a name="p1998855364165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p195679104165623"><a name="p195679104165623"></a><a name="p195679104165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1916760759165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device obtained during initialization.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfRx\(\)<a name="ga44006f6e066aff9f6a3310559e781582"></a>

```
int32_t NetIfRx (const struct [NetDevice](NetDevice.md) * netDevice, struct [NetBuf](NetBuf.md) * buff )
```

 **Description:**

Transfers the input data packets from the network side to a protocol stack. 

**Parameters:**

<a name="table73230779165623"></a>
<table><thead align="left"><tr id="row26147358165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1410178816165623"><a name="p1410178816165623"></a><a name="p1410178816165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1570708954165623"><a name="p1570708954165623"></a><a name="p1570708954165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1368965901165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buff</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network-side data, in Ether format.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfRxNi\(\)<a name="gad252107cdd20e9d3d0ab33fbfc2161e9"></a>

```
int32_t NetIfRxNi (const struct [NetDevice](NetDevice.md) * netDevice, struct [NetBuf](NetBuf.md) * buff )
```

 **Description:**

Transfers data packets from the network side to a protocol stack in an interrupt processing thread. 

**Parameters:**

<a name="table1880607975165623"></a>
<table><thead align="left"><tr id="row1985122212165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1021304431165623"><a name="p1021304431165623"></a><a name="p1021304431165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p952137842165623"><a name="p952137842165623"></a><a name="p952137842165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1958510916165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buff</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network-side data, in Ether format.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value  [HDF\_STATUS](DriverUtils.md#ga7e01536ecbe9b17563dd3fe256202a67)  if the operation fails.

## NetIfSetAddr\(\)<a name="gadd5c08aa8e65a12db062b1b88d53cece"></a>

```
int32_t NetIfSetAddr (const struct [NetDevice](NetDevice.md) * netDevice, const [IpV4Addr](IpV4Addr.md) * ipAddr, const [IpV4Addr](IpV4Addr.md) * netMask, const [IpV4Addr](IpV4Addr.md) * gw )
```

 **Description:**

Sets an IP address, mask, and gateway. 

**Parameters:**

<a name="table1892303129165623"></a>
<table><thead align="left"><tr id="row1513775348165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1548010981165623"><a name="p1548010981165623"></a><a name="p1548010981165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2072364222165623"><a name="p2072364222165623"></a><a name="p2072364222165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row798489930165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device structure <strong id="b661871057165623"><a name="b661871057165623"></a><a name="b661871057165623"></a>netDevice</strong> obtained during initialization. </td>
</tr>
<tr id="row1529226297165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ipAddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the IP address to set. </td>
</tr>
<tr id="row1373431733165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netMask</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the mask to set. </td>
</tr>
<tr id="row34669480165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the gateway to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfSetLinkStatus\(\)<a name="gaee9c68875ef541ed915045ab7a047ee8"></a>

```
int32_t NetIfSetLinkStatus (const struct [NetDevice](NetDevice.md) * netDevice, [NetIfLinkStatus](WLAN.md#ga7b1187d116fb065d7927ad9f77edd842) status )
```

 **Description:**

Notifies the network layer of the data link layer status. 

**Parameters:**

<a name="table1981683615165623"></a>
<table><thead align="left"><tr id="row1751312205165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p135732827165623"><a name="p135732827165623"></a><a name="p135732827165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1857465752165623"><a name="p1857465752165623"></a><a name="p1857465752165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row520652937165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device obtained during initialization. </td>
</tr>
<tr id="row1651491325165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">status Indicates the data link layer status, as enumerated in <strong id="b598239382165623"><a name="b598239382165623"></a><a name="b598239382165623"></a>NetIfLinkSatus</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## NetIfSetStatus\(\)<a name="gaa14fc68a382284491a272992d5c477cb"></a>

```
int32_t NetIfSetStatus (const struct [NetDevice](NetDevice.md) * netDevice, [NetIfStatus](WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf) status )
```

 **Description:**

Notifies the network layer of the network port state. 

**Parameters:**

<a name="table1260372768165623"></a>
<table><thead align="left"><tr id="row1893873308165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p45534978165623"><a name="p45534978165623"></a><a name="p45534978165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p973818299165623"><a name="p973818299165623"></a><a name="p973818299165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1406863594165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netDevice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device obtained during initialization. @paramstatus Indicates the network port state, as enumerated in <strong id="b2019768040165623"><a name="b2019768040165623"></a><a name="b2019768040165623"></a>NetIfSatus</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## Pbuf2NetBuf\(\)<a name="ga8d44f8dbfa75583d0056702b5a2d32a1"></a>

```
struct [NetBuf](NetBuf.md)* Pbuf2NetBuf (const struct [NetDevice](NetDevice.md) * netdev, struct pbuf * lwipBuf )
```

 **Description:**

Converts the  **pbuf**  structure of Lightweight TCP/IP Stack \(lwIP\) to a network data buffer. 

When a network device is specified, the reserved space of the network device will be added to the size of the converted network data buffer.

**Parameters:**

<a name="table926534718165623"></a>
<table><thead align="left"><tr id="row1579300831165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1388665585165623"><a name="p1388665585165623"></a><a name="p1388665585165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p563470371165623"><a name="p563470371165623"></a><a name="p563470371165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row209115275165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">netdev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network device. </td>
</tr>
<tr id="row1736898343165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">lwip_buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data buffer of lwIP.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the network data buffer if the operation is successful; returns  **NULL**  otherwise.

## WifiModuleCreate\(\)<a name="gaf5d1df53f08cae98ecfd440f9b425709"></a>

```
struct [WifiModule](WifiModule.md)* WifiModuleCreate (const struct HdfConfigWifiModuleConfig * config)
```

 **Description:**

Creates a  [WifiModule](WifiModule.md)  object based on a specified configuration generated by the HCS. 

**Parameters:**

<a name="table903554440165623"></a>
<table><thead align="left"><tr id="row1201270820165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p219125743165623"><a name="p219125743165623"></a><a name="p219125743165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p85296745165623"><a name="p85296745165623"></a><a name="p85296745165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2054764323165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">config</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration generated by the HCS.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the created  [WifiModule](WifiModule.md)  object.

## WifiModuleDelete\(\)<a name="gae14e3786e60f16a100197d28bae5a362"></a>

```
void WifiModuleDelete (struct [WifiModule](WifiModule.md) * module)
```

 **Description:**

Deletes a specified  [WifiModule](WifiModule.md)  object. 

**Parameters:**

<a name="table766497164165623"></a>
<table><thead align="left"><tr id="row84326523165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1402237666165623"><a name="p1402237666165623"></a><a name="p1402237666165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p703230348165623"><a name="p703230348165623"></a><a name="p703230348165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1151732573165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">module</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="WifiModule.md">WifiModule</a> object to delete.</td>
</tr>
</tbody>
</table>

## **Variable **<a name="section420458945165623"></a>

## aborted<a name="ga32ea10f832c5a03971033d5f44f3ef6c"></a>

```
uint8_t WifiScanRequest::aborted
```

 **Description:**

Whether to abort the scan 

## abortScan<a name="gab870d8100c1c9cb60b27c75a44bb30d4"></a>

```
int32_t(* WifiMac80211Ops::abortScan) ([NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Stopping a scan 

## ackNum<a name="ga223c54c5ebb2d92ed5f6c50115663b86"></a>

```
uint32_t TcpHeader::ackNum
```

 **Description:**

Acknowledgement number 

## addFeature<a name="gadfa86fac18c68b890d3b33a269931efc"></a>

```
int32_t(* WifiModuleIface::addFeature) (struct [WifiModule](WifiModule.md) *module, uint16_t featureType, struct [WifiFeature](WifiFeature.md) *featureData)
```

 **Description:**

Adding a feature 

## addKey<a name="ga367902162f25b7b4c5b80372bb6a81f2"></a>

```
int32_t(* WifiMac80211Ops::addKey) (struct [NetDevice](NetDevice.md) *netdev, uint8_t keyIndex, bool pairwise, const uint8_t *macAddr, struct [KeyParams](KeyParams.md) *params)
```

 **Description:**

Adding a key with specified parameters 

## addr \[1/2\]<a name="gacdd7348f71376cd66b3a0079a1c393d5"></a>

```
uint8_t MacAddress::addr[ETH_ADDR_LEN]
```

 **Description:**

Device MAC address 

## addr \[2/2\]<a name="gabcba7263b501288a2585bfddb77f93c4"></a>

```
uint32_t IpV4Addr::addr
```

 **Description:**

IPv4 address 

## addrLen<a name="gafc2646cdc533135a303ca91bf9ebe7ec"></a>

```
uint8_t NetDevice::addrLen
```

 **Description:**

MAC address length 

## addrMask<a name="ga8d1059e645ca6684e9ea82044e03270b"></a>

```
uint8_t Wiphy::addrMask[WLAN_MAC_ADDR_LEN]
```

 **Description:**

MAC address mask of the wiphy device. If the device supports multiple virtual MAC addresses, the bit whose value is  **1**  in the mask represents a variable part of the MAC address. 

## aid \[1/2\]<a name="ga9885111fb46e5fd771df52f260e80e98"></a>

```
uint16_t AssocResp::aid
```

 **Description:**

Authentication ID 

## aid \[2/2\]<a name="ga9c02f712098d5faa35d6febcd0a26bcf"></a>

```
uint16_t ReassocResp::aid
```

 **Description:**

Authentication ID 

## akmSuites<a name="ga142aeeaed24db6cd329c0b8b78ab13bc"></a>

```
uint32_t CryptoSettings::akmSuites[NL80211_MAX_NR_AKM_SUITES]
```

 **Description:**

AKM suite data. For details, see  **NL80211\_MAX\_NR\_AKM\_SUITES**. 

## ampduDensity<a name="ga90e3ceab29efbe5b144191176f7f8e44"></a>

```
uint8_t Ieee80211StaHtCap::ampduDensity
```

 **Description:**

Minimum MPDU start spacing 

## ampduFactor<a name="ga891bf97aba3202dd8c4f1cbdc288c61f"></a>

```
uint8_t Ieee80211StaHtCap::ampduFactor
```

 **Description:**

Maximum length of an aggregated MAC Protocol Data Unit \(A-MPDU\) 

## arry<a name="ga6d31899685b7a552a5322e93b0ffd972"></a>

```
uint8_t ScannedBssInfo::arry[2]
```

 **Description:**

Reserved 

## assocReq \[1/2\]<a name="ga7bcd238eb3be90e887638d51139f570d"></a>

```
struct [AssocReq](AssocReq.md) Ieee80211Mgmt::assocReq
```

 **Description:**

Association request 

## assocReq \[2/2\]<a name="gad02f8946fea9b392a6b630306e50d52f"></a>

```
struct { ... } ::assocReq
```

 **Description:**

Association request 

## assocReqIes<a name="gac2e13b44df4b4df0018f801f8a9e0494"></a>

```
const uint8_t* StationInfo::assocReqIes
```

 **Description:**

Information Elements \(IEs\) in Association  [Request](Request.md) 

## assocReqIesLen<a name="ga7822f8e474e18a4f7ae7cee7cbd9bc7c"></a>

```
uint32_t StationInfo::assocReqIesLen
```

 **Description:**

IE length in Association  [Request](Request.md) 

## assocResp \[1/2\]<a name="gad709ecd25bb15fdc7518eeafd47e3706"></a>

```
struct [AssocResp](AssocResp.md) Ieee80211Mgmt::assocResp
```

 **Description:**

Association response 

## assocResp \[2/2\]<a name="gad58f02ba5767dc3dce6ca4a43c6934b0"></a>

```
struct { ... } ::assocResp
```

 **Description:**

Association response 

## aucArry<a name="ga94fdc9f1d50e8f8561e2fa539bd7c8c8"></a>

```
uint8_t Mac80211Ssids::aucArry[MAC80211_SSIDS_AUC_SIZE]
```

 **Description:**

AuC data array 

## aucResv<a name="gac0b10633f99311af30dd220ae9d19e34"></a>

```
uint8_t WifiConnectParams::aucResv[WIFI_CONNECT_PARM_RESV_SIZE]
```

 **Description:**

Reserved field 

## aucRsv \[1/2\]<a name="gaf00464a59d6bda90ad57cd6201736245"></a>

```
uint8_t Ieee80211StaHtCap::aucRsv[IEEE80211_STAHTCAP_RESV]
```

 **Description:**

Reserved field 

## aucRsv \[2/2\]<a name="gabdd49dff12ed26c47f1935fb2bf3d873"></a>

```
uint8_t Wiphy::aucRsv[WIPHY_RSV_SIZE]
```

 **Description:**

Manual alignment of data structures 

## aucSsid<a name="ga47c550859928cbc795333cb26b138ba3"></a>

```
uint8_t Mac80211Ssids::aucSsid[OAL_IEEE80211_MAX_SSID_LEN]
```

 **Description:**

SSID array 

## auth \[1/2\]<a name="ga13a290a08e43034d0949635793335475"></a>

```
struct { ... } ::auth
```

 **Description:**

Authentication Information 

## auth \[2/2\]<a name="ga797e6d02e8d4fdb4bd372d3c5286c6e9"></a>

```
struct [Auth](Auth.md) Ieee80211Mgmt::auth
```

 **Description:**

Authentication Information 

## authAlg<a name="gafe2c9439abca834df69dba0aa57a6d5f"></a>

```
uint16_t Auth::authAlg
```

 **Description:**

Authentication algorithm 

## authTransaction<a name="gad8e67419612ed5fea439e74efb16d4c4"></a>

```
uint16_t Auth::authTransaction
```

 **Description:**

Authentication transaction 

## authType<a name="ga2c9cdaa7b998a7ffb4378f4a6cedbb75"></a>

```
uint8_t WifiConnectParams::authType
```

 **Description:**

Authorization type 

## band \[1/2\]<a name="gaab4e3330566d5b0b02e7c6117c7b9a73"></a>

```
enum [Ieee80211Band](WLAN.md#ga9882f415202cf9acb0f4cdfbc456a88d) Ieee80211Channel::band
```

 **Description:**

Frequency band, either 2.4 GHz or 5 GHz 

## band \[2/2\]<a name="gabfd4562987e1c8b6daea0d10ca8c2751"></a>

```
enum [Ieee80211Band](WLAN.md#ga9882f415202cf9acb0f4cdfbc456a88d) Ieee80211SupportedBand::band
```

 **Description:**

Band matching this data structure description 

## bands<a name="gaf3ab07acceaeff1edc793cb23d739ec5"></a>

```
struct [Ieee80211SupportedBand](Ieee80211SupportedBand.md)* Wiphy::bands[[IEEE80211_NUM_BANDS](WLAN.md#gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4)]
```

 **Description:**

Supported bands 

## beacon \[1/2\]<a name="ga368a66f24e860ef013989c410fa0fb3e"></a>

```
struct [Beacon](Beacon.md) Ieee80211Mgmt::beacon
```

 **Description:**

[Beacon](Beacon.md)  frame 

## beacon \[2/2\]<a name="ga82b21412a65ba3e436d055fff4388362"></a>

```
struct { ... } ::beacon
```

 **Description:**

[Beacon](Beacon.md)  frame 

## beaconData<a name="ga80cf5c2a3596c32ddc1de60d51c3e33d"></a>

```
WifiBeaconData* Mac80211beaconParam::beaconData
```

 **Description:**

[Beacon](Beacon.md)  frame data 

## beaconFound<a name="ga55c6f1eaedc16b99dc299530a0dc6f83"></a>

```
int8_t Ieee80211Channel::beaconFound
```

 **Description:**

When a beacon frame is found in this channel 

## beaconInt \[1/2\]<a name="ga34eacc801b02cefbfe742a6451b95770"></a>

```
uint16_t Beacon::beaconInt
```

 **Description:**

[Beacon](Beacon.md)  interval 

## beaconInt \[2/2\]<a name="ga8438721279093a38779f1ab7f6ed59dc"></a>

```
uint16_t ProbeResp::beaconInt
```

 **Description:**

[Beacon](Beacon.md)  interval 

## beaconInterval<a name="gad49083c0d110aef00878071800040069"></a>

```
uint16_t StaBssParameters::beaconInterval
```

 **Description:**

[Beacon](Beacon.md)  interval 

## beaconLossCount<a name="gaa669232960c93e73558062e466d0fb02"></a>

```
uint32_t StationInfo::beaconLossCount
```

 **Description:**

Number of beacon loss events triggered 

## bitrate<a name="gab8e1e3d778d0739a728ae5d3a77fe502"></a>

```
uint16_t Ieee80211Rate::bitrate
```

 **Description:**

Bit rate, in 100 kbit/s 

## bitrates<a name="ga4a0d4f26cbf81f839b25c2808e50856a"></a>

```
struct [Ieee80211Rate](Ieee80211Rate.md)* Ieee80211SupportedBand::bitrates
```

 **Description:**

An array of supported bit rates 

## bssid \[1/3\]<a name="gac8415aaa2b1a60e17712776826b2514a"></a>

```
uint8_t Ieee80211Mgmt::bssid[6]
```

 **Description:**

BSS ID 

## bssid \[2/3\]<a name="gacfb1f8dc523cea7d4394b912c0c508ea"></a>

```
uint8_t ConnetResult::bssid[ETH_ADDR_LEN]
```

 **Description:**

MAC address of the AP associated with the station 

## bssid \[3/3\]<a name="gaf088c497d633df51d8bee24e7a778c22"></a>

```
uint8_t* WifiConnectParams::bssid
```

 **Description:**

AP basic service set identifier \(BSSID\). If this parameter is not specified, the AP BSSID is automatically obtained from the scan result. 

## bssParam<a name="ga0b38e5935241d2f3cd05c2e5bba1c8e1"></a>

```
struct [StaBssParameters](StaBssParameters.md) StationInfo::bssParam
```

 **Description:**

Current BSS parameters 

## bufs<a name="ga49eacbbc8b4231a05464768103b8593f"></a>

```
struct BufField NetBuf::bufs[[MAX_BUF_NUM](WLAN.md#ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19)]
```

 **Description:**

Defines buffer segments used to record the offset address \(based on the memory buffer address\) and length of each buffer segment, including the header buffer segment, data segment, and tail buffer segment. For details, see  [MAX\_BUF\_NUM](WLAN.md#ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19). 

## cap<a name="ga56216c033dd738a3100c8e0d9c1dd1a8"></a>

```
uint16_t Ieee80211StaHtCap::cap
```

 **Description:**

HT capability table provided in 802.11n 

## capabInfo \[1/6\]<a name="gadc4d122edd92d777956cb913aa27918b"></a>

```
uint16_t AssocReq::capabInfo
```

 **Description:**

WLAN capability information 

## capabInfo \[2/6\]<a name="ga53356e3d7b67cdeca0e6110dbb8b46f7"></a>

```
uint16_t AssocResp::capabInfo
```

 **Description:**

WLAN capability information 

## capabInfo \[3/6\]<a name="ga3e5e0b8af464d5990e451d6a97c6e89b"></a>

```
uint16_t ReassocReq::capabInfo
```

 **Description:**

WLAN capability information 

## capabInfo \[4/6\]<a name="ga718001853f9317e9108339cfe5e6531b"></a>

```
uint16_t ReassocResp::capabInfo
```

 **Description:**

WLAN capability information 

## capabInfo \[5/6\]<a name="gaabddc721f70c869a51d5893ea58012cc"></a>

```
uint16_t Beacon::capabInfo
```

 **Description:**

WLAN capability information 

## capabInfo \[6/6\]<a name="ga0389de8c9241c7e8622e3cf643ee8efe"></a>

```
uint16_t ProbeResp::capabInfo
```

 **Description:**

WLAN capability information 

## centerFreq<a name="ga42300a5593bf6b40a4d823af2dbe2a5d"></a>

```
uint16_t Ieee80211Channel::centerFreq
```

 **Description:**

Center frequency 

## centerFreq1<a name="ga650d64bab38809286d34acd11f292507"></a>

```
int32_t ChannelDef::centerFreq1
```

 **Description:**

Center frequency 1 

## centerFreq2<a name="ga62d64617036c65e3964657c692a39f6a"></a>

```
int32_t ChannelDef::centerFreq2
```

 **Description:**

Center frequency 2 

## chan<a name="ga165ba815b4ddb9558f90bd0bf82e23f0"></a>

```
struct [Ieee80211Channel](Ieee80211Channel.md)* ChannelDef::chan
```

 **Description:**

Channel information 

## changeBeacon<a name="ga833043e11a73c8f53cb918e25715939e"></a>

```
int32_t(* WifiMac80211Ops::changeBeacon) ([NetDevice](NetDevice.md) *netDev, [Mac80211beaconParam](Mac80211beaconParam.md) *param)
```

 **Description:**

Setting the beacon frame based on specified parameters 

## changeMtu<a name="ga2035c840c71a43b43451bfe0213ca04a"></a>

```
int32_t(* NetDeviceInterFace::changeMtu) (struct [NetDevice](NetDevice.md) *netDev, int32_t newMtu)
```

 **Description:**

Changes the maximum number of transmission units. 

## changeVirtualIntf<a name="ga0a4446bf704b9f4b673f68ff97002b1b"></a>

```
int32_t(* WifiMac80211Ops::changeVirtualIntf) ([NetDevice](NetDevice.md) *netDev, uint8_t iftype, uint32_t *flags, struct [VifParams](VifParams.md) *params)
```

 **Description:**

Changing virtual APIs 

## channel<a name="ga0c59333afe2ac58387c92260a8268de7"></a>

```
struct [Ieee80211Channel](Ieee80211Channel.md)* WifiConnectParams::channel
```

 **Description:**

Connection channel. If this parameter is not specified, the connection channel is automatically obtained from the scan result. 

## channels \[1/2\]<a name="gaabb5ffed3a294507d4f51d598fd98717"></a>

```
struct [Ieee80211Channel](Ieee80211Channel.md)* WifiScanRequest::channels[MAX_SCAN_CHANNELS]
```

 **Description:**

Channels to scan for. For details, see  **MAX\_SCAN\_CHANNELS**. 

## channels \[2/2\]<a name="ga02df34a92ff5010c8b70ed8cdbd90fb1"></a>

```
struct [Ieee80211Channel](Ieee80211Channel.md)* Ieee80211SupportedBand::channels
```

 **Description:**

An array of supported channels 

## check \[1/3\]<a name="gaf3b4d16f68ab697df71ca8589f00397c"></a>

```
uint16_t IpHeader::check
```

 **Description:**

Header check 

## check \[2/3\]<a name="gae93142de73db5e7e18f2d247387d79ee"></a>

```
uint16_t UdpHeader::check
```

 **Description:**

Header check 

## check \[3/3\]<a name="gab32c75fd1d8d8985d9861157907a3a74"></a>

```
uint16_t TcpHeader::check
```

 **Description:**

Checksum 

## chip<a name="ga213bff4c0d74fb3db3ff7c21bea781ae"></a>

```
struct [HdfWifiChipData](HdfWifiChipData.md)* WifiFeature::chip
```

 **Description:**

Chip 

## cipher<a name="ga2efb1151fccead84c0d4257717760936"></a>

```
uint32_t KeyParams::cipher
```

 **Description:**

Cipher suite 

## cipherGroup<a name="ga9be34adb7e26191321b38c37b341e20d"></a>

```
uint32_t CryptoSettings::cipherGroup
```

 **Description:**

Cipher group 

## ciphersPairwise<a name="ga53c85b4e0f5f5e10bb16935fb8a77df0"></a>

```
uint32_t CryptoSettings::ciphersPairwise[NL80211_MAX_NR_CIPHER_SUITES]
```

 **Description:**

Unicast cipher suite. For details, see  **NL80211\_MAX\_NR\_CIPHER\_SUITES**. 

## cipherSuites<a name="ga011f5a473787d4700441e4bf7387673a"></a>

```
const uint32_t* Wiphy::cipherSuites
```

 **Description:**

Supported cipher suites 

## connect<a name="ga9f26a0c3e31e1b57cc8b357964cce3db"></a>

```
int32_t(* WifiMac80211Ops::connect) ([NetDevice](NetDevice.md) *netDev, [WifiConnectParams](WifiConnectParams.md) *param)
```

 **Description:**

Starting a connection based on the specified parameters 

## connectedTime<a name="ga7a260a68741622c415faa30f345802f1"></a>

```
uint32_t StationInfo::connectedTime
```

 **Description:**

Duration \(in seconds\) since the last station connection 

## connectStatus<a name="ga22925ebc7c0b94465c53b886307c67dd"></a>

```
uint16_t ConnetResult::connectStatus
```

 **Description:**

Connection status 

## controlPort<a name="ga2f49a07024546730d0cd60e93cb9e450"></a>

```
int8_t CryptoSettings::controlPort
```

 **Description:**

Whether the user space control port is authorized. The value  **true**  indicates that the user space control port is unauthorized. 

## controlPortEthertype<a name="ga67b6c08be0641796798513fbbb13dd73"></a>

```
uint16_t CryptoSettings::controlPortEthertype
```

 **Description:**

Data can be transmitted over an unauthenticated port. 

## controlPortNoEncrypt<a name="ga020b34dbfd5f961c86ef416873a9c02c"></a>

```
int8_t CryptoSettings::controlPortNoEncrypt
```

 **Description:**

Whether to encrypt frames transmitted over the control port. The value  **1**  indicates that the frames are not encrypted. 

## crypto<a name="gaa91e37ddf709a3553a6352623ea8c341"></a>

```
struct [CryptoSettings](CryptoSettings.md) WifiConnectParams::crypto
```

 **Description:**

Cryptography information 

## currentAp<a name="ga451da053aeae74e215da41757196ac2c"></a>

```
uint8_t ReassocReq::currentAp[6]
```

 **Description:**

Current AP 

## dAddr<a name="ga5124eb108341354708e52775df8899ef"></a>

```
uint32_t IpHeader::dAddr
```

 **Description:**

Destination address 

## dataLen<a name="gafb7e6f774a44888f5c44c3dffc6c5616"></a>

```
uint32_t NetBuf::dataLen
```

 **Description:**

Actual data length of the network data buffer 

## deauth \[1/2\]<a name="ga65ccc20a9dd404cfb020ecfe9a3301a1"></a>

```
struct [Deauth](Deauth.md) Ieee80211Mgmt::deauth
```

 **Description:**

Deauthentication Information 

## deauth \[2/2\]<a name="ga39aa6151289296b2ee91591899e338a0"></a>

```
struct { ... } ::deauth
```

 **Description:**

Deauthentication Information 

## deinit<a name="gaf4ad8f670757555c0535b5a5fa5fa8d9"></a>

```
int32_t(* HdfWifiChipData::deinit) (struct [HdfWifiChipData](HdfWifiChipData.md) *chipData)
```

 **Description:**

Function for deinitializing the chip 

## deInit \[1/3\]<a name="ga371e13402535662210549c3ca3303691"></a>

```
void(* NetDeviceInterFace::deInit) (struct [NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Deinitializes a network device to be delete. 

## deInit \[2/3\]<a name="gaf03445197e62e8d5cc5de5c7bba185dd"></a>

```
int32_t(* WifiFeature::deInit) (struct [WifiFeature](WifiFeature.md) *feature)
```

 **Description:**

Function for deinitializing the feature 

## deInit \[3/3\]<a name="ga378c89a04bb867068d3c86c5680ca9c0"></a>

```
int32_t(* WifiModuleIface::deInit) (struct [WifiModule](WifiModule.md) *module)
```

 **Description:**

Deinitializing a WLAN module 

## delFeature<a name="ga764ebf11b82c57d5185df50fab72a1d8"></a>

```
int32_t(* WifiModuleIface::delFeature) (struct [WifiModule](WifiModule.md) *module, uint16_t featureType)
```

 **Description:**

Deleting a feature 

## delKey<a name="ga7edb052049a9420b938085322c6a0418"></a>

```
int32_t(* WifiMac80211Ops::delKey) (struct [NetDevice](NetDevice.md) *netdev, uint8_t keyIndex, bool pairwise, const uint8_t *macAddr)
```

 **Description:**

Deleting a key based on a specified MAC address 

## delStation<a name="ga974552db5307795e70d5868edccecc1c"></a>

```
int32_t(* WifiMac80211Ops::delStation) ([NetDevice](NetDevice.md) *netDev, const uint8_t *macAddr)
```

 **Description:**

Deleting a station with a specified MAC address 

## dest<a name="ga21658fd4eb65ed4559958e3074f21081"></a>

```
uint16_t UdpHeader::dest
```

 **Description:**

Destination port number 

## dev \[1/2\]<a name="gafa78f2abfa4f977cfb3bd52a6ae05d61"></a>

```
void* NetBuf::dev
```

 **Description:**

Network device that receives the network data 

## dev \[2/2\]<a name="gada8e463843d9e5fef133d41fd745dc42"></a>

```
struct [NetDevice](NetDevice.md)* WifiScanRequest::dev
```

 **Description:**

A specified network device to scan for 

## device<a name="ga689a86688de16eed6ffa023417967c9a"></a>

```
struct [HdfDeviceObject](HdfDeviceObject.md)* HdfWifiProductData::device
```

 **Description:**

Structure of the Device Object 

## disassoc \[1/2\]<a name="ga1afc8148645370acc808671bac430a66"></a>

```
struct { ... } ::disassoc
```

 **Description:**

Disconnected 

## disassoc \[2/2\]<a name="ga1c92855062b3cbbcc94f6e4cf3076473"></a>

```
struct [Disassoc](Disassoc.md) Ieee80211Mgmt::disassoc
```

 **Description:**

Disconnected 

## disconnect<a name="ga558d3d417f465ca592dc94c3040b2d1f"></a>

```
int32_t(* WifiMac80211Ops::disconnect) ([NetDevice](NetDevice.md) *netDev, uint16_t reasonCode)
```

 **Description:**

Canceling a connection 

## dlist \[1/2\]<a name="ga6de94d9c8f9dd8d608a091673fa130c4"></a>

```
struct [DListHead](DListHead.md) NetBuf::dlist
```

 **Description:**

Doubly linked list. Generally, multiple network data buffers are linked by using a doubly linked list. 

## dlist \[2/2\]<a name="ga473ab87a57006bb6ed69c5e5ea666f5c"></a>

```
struct [DListHead](DListHead.md) NetBufQueue::dlist
```

 **Description:**

Doubly linked list. Generally, multiple network data buffers are linked by using a doubly linked list. 

## dPort<a name="ga2a188a6b8ee0eccceefe0e17818e8707"></a>

```
uint16_t TcpHeader::dPort
```

 **Description:**

Destination port number 

## dstAddr<a name="ga4e602eacdc2481c6d91b1e42e7a7233c"></a>

```
uint8_t Ieee80211Mgmt::dstAddr[6]
```

 **Description:**

Destination MAC address 

## dtimPeriod \[1/2\]<a name="gac532b47f0a538e68bb340437d840fbcc"></a>

```
uint8_t StaBssParameters::dtimPeriod
```

 **Description:**

Delivery Traffic Indication Message \(DTIM\) period of BSS 

## dtimPeriod \[2/2\]<a name="gad63b5d23db5e2bf8b9ca57bdb7de4c82"></a>

```
int32_t Mac80211beaconParam::dtimPeriod
```

 **Description:**

Delivery Traffic Indication Message \(DTIM\) interval 

## duration<a name="gad1ea2da7ade6335e8c273284208d551d"></a>

```
uint16_t Ieee80211Mgmt::duration
```

 **Description:**

Duration 

## etherDhost<a name="ga987c92ec1c7c5e637ba93d18edcf87c4"></a>

```
uint8_t EtherHeader::etherDhost[[MAC_ADDR_SIZE](WLAN.md#gae01dbae885bc8abecb82bd865515c081)]
```

 **Description:**

Destination address  [MAC\_ADDR\_SIZE](WLAN.md#gae01dbae885bc8abecb82bd865515c081) 

## etherShost<a name="gaaee5baebf4a693ad44d0ae9530d9dfbd"></a>

```
uint8_t EtherHeader::etherShost[[MAC_ADDR_SIZE](WLAN.md#gae01dbae885bc8abecb82bd865515c081)]
```

 **Description:**

Source address  [MAC\_ADDR\_SIZE](WLAN.md#gae01dbae885bc8abecb82bd865515c081) 

## etherType<a name="ga6a0916fd23f851ba6cd2bcd3700123b2"></a>

```
uint16_t EtherHeader::etherType
```

 **Description:**

Ethernet type, such as 0x8035 \(RARP\), 0x888e \(EAPOL\), PAE/802.1x, 0x0800 \(IP\), 0x86dd \(IPV6\), and 0x0806 \(ARP\) 

## fake<a name="ga82e8bdd989fd03bf9cc3b5f6a14ec05b"></a>

```
uint32_t IfReq::fake
```

 **Description:**

magic field 

## fe<a name="ga772b7d7c4b5cc3ecdab421a0b2337e91"></a>

```
struct [WifiFeature](WifiFeature.md)* WifiFeatureList::fe[[HDF_WIFI_FEATURE_NUM](WLAN.md#ggaec03ba36d71cc2d5f3209bc24aa6ee10a28ff5971d579c1754e03a5f79a0c9e6f)]
```

 **Description:**

An array of WLAN features 

## feList<a name="ga347d5b39c9a96835ae85358ba0895cc3"></a>

```
struct [WifiFeatureList](WifiFeatureList.md)* WifiModule::feList
```

 **Description:**

WLAN features 

## filled<a name="ga14e0c28a09471313507c1ef6f704ad8a"></a>

```
uint32_t StationInfo::filled
```

 **Description:**

Flag values of relevant structures 

## flags \[1/7\]<a name="gaaf4d141dbf9493524661415d7940b853"></a>

```
uint8_t RateInfo::flags
```

 **Description:**

Flag field, used to indicate a specific rate transmission type of 802.11n 

## flags \[2/7\]<a name="ga192ebb83d79d9bed8ee35ceb3d91f1df"></a>

```
uint8_t StaBssParameters::flags
```

 **Description:**

Flag, used to indicate a specific rate transmission type of 802.11n 

## flags \[3/7\]<a name="gaadedfd33df129639f135a6f5d0322e4e"></a>

```
uint32_t Ieee80211Channel::flags
```

 **Description:**

WLAN channel flag 

## flags \[4/7\]<a name="ga0265e4d32fef1bb7c94f14671763655b"></a>

```
uint32_t Ieee80211Rate::flags
```

 **Description:**

Rate flag 

## flags \[5/7\]<a name="ga0f4b1664afa7f688b0e7fe974e8676a2"></a>

```
uint32_t Wiphy::flags
```

 **Description:**

[Wiphy](Wiphy.md)  device attributes 

## flags \[6/7\]<a name="ga66be1d87b4d2576cee91cd3867b93701"></a>

```
uint8_t TcpHeader::flags
```

 **Description:**

Flags 

## flags \[7/7\]<a name="ga01a8027b2e16aa30a6da3ee99c0f3890"></a>

```
uint32_t NetDevice::flags
```

 **Description:**

Network port status 

## fragInfo<a name="gaf329df46f50a5dcf4dd87c103317401b"></a>

```
uint16_t IpHeader::fragInfo
```

 **Description:**

Fragmentation information 

## fragThreshold<a name="gafa733ea2e4b2efa2dc10938956a95f85"></a>

```
uint32_t Wiphy::fragThreshold
```

 **Description:**

Fragment threshold 

## frameControl<a name="ga52e127b6032bc14b0828d775f45c164d"></a>

```
uint16_t Ieee80211Mgmt::frameControl
```

 **Description:**

Frame control field 

## freq \[1/2\]<a name="ga9489887bd02837a40e9560f1a4acd211"></a>

```
int16_t ScannedBssInfo::freq
```

 **Description:**

Center frequency of the channel where the BSS is located 

## freq \[2/2\]<a name="ga5ca4a2c4e1cdfe1d9e4bd1592855e5a0"></a>

```
uint16_t ConnetResult::freq
```

 **Description:**

Frequency of the AP 

## funType<a name="ga4a20c090f2e28ed317957d4ed5fc28fd"></a>

```
[IfType](IfType.md) NetDevice::funType
```

 **Description:**

Network port type 

## generation<a name="ga4b17833011fe840879c7bcd74aac9f9d"></a>

```
int32_t StationInfo::generation
```

 **Description:**

Generation number 

## getModule<a name="gad7c080e7ac22daf18529184da55e910c"></a>

```
struct [WifiModule](WifiModule.md)*(* WifiModuleIface::getModule) (void)
```

 **Description:**

Obtaining a WLAN module 

## getStats<a name="ga3dcf9dd183845770dc8589eb98e59fce"></a>

```
struct NetDevStats*(* NetDeviceInterFace::getStats) (struct [NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Obtains the statistics. 

## hardHeaderLen<a name="ga585cec837551180e542b29d263dd585c"></a>

```
uint16_t NetDevice::hardHeaderLen
```

 **Description:**

Header length 

## hiddenSsid<a name="gac5c5a9f217e8fdf4d94cf78f8311d254"></a>

```
uint8_t Mac80211beaconParam::hiddenSsid
```

 **Description:**

Whether to hide the SSID 

## hslConfig<a name="gae67367af307406e4693e7c4cdba69baf"></a>

```
const struct HdfConfigWifiModuleConfig* WifiModuleConfig::hslConfig
```

 **Description:**

Configuration of each feature of the WLAN module 

## htCap<a name="gaf1a61194a3fdac2516e391534e5e15d6"></a>

```
struct [Ieee80211StaHtCap](Ieee80211StaHtCap.md) Ieee80211SupportedBand::htCap
```

 **Description:**

HT capability 

## htSupported<a name="gaf5a9bd33d4d6eaf38052d3c52c261db6"></a>

```
uint8_t Ieee80211StaHtCap::htSupported
```

 **Description:**

Whether the station supports HT 

## hwValue \[1/2\]<a name="ga88c500579917b7a4b0167623851abcf2"></a>

```
uint16_t Ieee80211Channel::hwValue
```

 **Description:**

Hardware information 

## hwValue \[2/2\]<a name="gaf1d7fcab109296f61b1e46315c56ad61"></a>

```
uint16_t Ieee80211Rate::hwValue
```

 **Description:**

Hardware information 

## hwValueShort<a name="ga0c64e3b8824a84ceab38b2c4c3c53e9c"></a>

```
uint16_t Ieee80211Rate::hwValueShort
```

 **Description:**

Hardware information specified when a short preamble is used 

## id<a name="ga2d5c09b859bc0faddc8a42339973bdd4"></a>

```
uint16_t IpHeader::id
```

 **Description:**

Each data packet sent by the host 

## ie \[1/2\]<a name="ga92b16a60570fd1d28b948ee43f9b0124"></a>

```
uint8_t* WifiScanRequest::ie
```

 **Description:**

IEEE 802.11 buffer 

## ie \[2/2\]<a name="ga8274aa0c44fe19a615c38c67eb799c87"></a>

```
uint8_t* WifiConnectParams::ie
```

 **Description:**

IEEE 802.11 information required for the connection 

## ieee80211Ptr<a name="ga3d04317fd4d2c8932808d6dd07fedcf4"></a>

```
struct [WirelessDev](WirelessDev.md)* NetDevice::ieee80211Ptr
```

 **Description:**

Pointer to a wireless device 

## ieLen \[1/2\]<a name="gaa26674156ac0814fbc1f45b8e11b7b9f"></a>

```
uint32_t WifiScanRequest::ieLen
```

 **Description:**

IEEE 802.11 buffer length 

## ieLen \[2/2\]<a name="gad5c61386055631b64c953fa46c2aad24"></a>

```
uint32_t WifiConnectParams::ieLen
```

 **Description:**

IEEE 802.11 length 

## iface<a name="ga8666b5068c46aa89a3cae49b7a31c224"></a>

```
struct [WifiModuleIface](WifiModuleIface.md)* WifiModule::iface
```

 **Description:**

APIs 

## ifrData<a name="gadc2f148a30a6ef88b5938fea193ac9e5"></a>

```
uint8_t* IfReq::ifrData
```

 **Description:**

Data pointer 

## iftype<a name="ga8e9277b73be8498a73999151e093693e"></a>

```
uint8_t WirelessDev::iftype
```

 **Description:**

API type 

## inactiveTime<a name="ga6326315bb50ed95fc0ce5ce65177cb78"></a>

```
uint32_t StationInfo::inactiveTime
```

 **Description:**

Duration \(in milliseconds\) since the last station activity 

## init \[1/4\]<a name="gabbafd20c6c6cc8eb20777cdd588b46cd"></a>

```
int32_t(* HdfWifiChipData::init) (struct [HdfWifiChipData](HdfWifiChipData.md) *chipData, const struct HdfConfigWifiChip *chipConfig)
```

 **Description:**

Function for initializing the chip 

## init \[2/4\]<a name="ga24cdc29146b8f84d021328e8a31269a5"></a>

```
int32_t(* NetDeviceInterFace::init) (struct [NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Initializes a network device to be added. 

## init \[3/4\]<a name="ga8b09c66c75ed9515bbf5f76e25c86e57"></a>

```
int32_t(* WifiFeature::init) (struct [WifiFeature](WifiFeature.md) *feature)
```

 **Description:**

Function for initializing the feature 

## init \[4/4\]<a name="gadf3d907844092764d8c8d3ce150e1712"></a>

```
int32_t(* WifiModuleIface::init) (struct [WifiModule](WifiModule.md) *module)
```

 **Description:**

Initializing a WLAN module 

## interfaceModes<a name="ga33ab965c40e11c007cadf1116113ca21"></a>

```
uint16_t Wiphy::interfaceModes
```

 **Description:**

Bitmask of an API type that is valid for the wiphy device 

## interval<a name="ga691fb611afdc35bbf6951977119c8772"></a>

```
int32_t Mac80211beaconParam::interval
```

 **Description:**

[Beacon](Beacon.md)  interval 

## ioctl<a name="ga6c3d34c3329316632c7f6b6b19d2f983"></a>

```
int32_t(* NetDeviceInterFace::ioctl) (struct [NetDevice](NetDevice.md) *netDev, [IfReq](IfReq.md) *req, int32_t cmd)
```

 **Description:**

Used for the control command word. 

## ipAddr<a name="ga814742f62c24ff2895a18ad157df4874"></a>

```
uint32_t NetDevNotify::ipAddr
```

 **Description:**

IP address 

## key \[1/2\]<a name="ga0c19dd081453de295f3095c2cf7aced4"></a>

```
uint8_t* KeyParams::key
```

 **Description:**

Key content 

## key \[2/2\]<a name="ga6ca72a4cfcb196dda7c2ca2562a1b20b"></a>

```
const uint8_t* WifiConnectParams::key
```

 **Description:**

Wired Equivalent Privacy \(WEP\) key used for Shared Key Authentication \(SKA\) 

## keyIdx<a name="ga27eb8efb66b131f8495baf2dcaee6eb6"></a>

```
uint8_t WifiConnectParams::keyIdx
```

 **Description:**

Index of the WEP key used for SKA 

## keyLen \[1/2\]<a name="gae913f805139a4111b98617ab8e678528"></a>

```
int32_t KeyParams::keyLen
```

 **Description:**

Key length 

## keyLen \[2/2\]<a name="ga98603c2c633e6ca1ad940269cfb01e58"></a>

```
uint8_t WifiConnectParams::keyLen
```

 **Description:**

Key length 

## lastRxTime<a name="gaf3cfb6012fad954900ccded1305e0e73"></a>

```
uint32_t NetDevice::lastRxTime
```

 **Description:**

Last time when data is received 

## legacy<a name="gaf51b764aa77423df71236454f2804a62"></a>

```
uint16_t RateInfo::legacy
```

 **Description:**

100 kbit/s bit rate defined in 802.11a/b/g 

## len \[1/2\]<a name="ga559e952054ce59e81d2ff9b38634b60c"></a>

```
uint32_t NetBuf::len
```

 **Description:**

Length of the memory buffer 

## len \[2/2\]<a name="ga90b8c3dd672bad2f722900101db236f2"></a>

```
uint16_t UdpHeader::len
```

 **Description:**

Length of a data packet 

## LinkLayerType<a name="ga4758167363bad30116f4bcdb4cc1ae2a"></a>

```
[NetLinkType](WLAN.md#gad3175955d2e6ef3c4f52da9b509d5b4a) NetDevice::LinkLayerType
```

 **Description:**

Data link layer type 

## listenInterval \[1/2\]<a name="ga4755cf88f3c370bb7e704e7ab1f1f46b"></a>

```
uint16_t AssocReq::listenInterval
```

 **Description:**

Scan interval 

## listenInterval \[2/2\]<a name="gad95ef561c78f9312941cbd559e11b873"></a>

```
uint16_t ReassocReq::listenInterval
```

 **Description:**

Scan interval 

## llid<a name="gadc926d27f91b736e04f9ba2ffe663aeb"></a>

```
uint16_t StationInfo::llid
```

 **Description:**

Local mesh ID 

## lock<a name="gadd22ee64f7d9703d6c4cde54b512aaa0"></a>

```
struct Spinlock NetBufQueue::lock
```

 **Description:**

Queue operation lock 

## mac \[1/2\]<a name="gaa9ba863f7e3f07f710274cbfecb0080e"></a>

```
uint8_t MacConfigParam::mac[WLAN_MAC_ADDR_LEN]
```

 **Description:**

MAC address. For details about its length, see  **WLAN\_MAC\_ADDR\_LEN**. 

## mac \[2/2\]<a name="ga83cfa2d4899721ac3448d99ea5b0bef2"></a>

```
const uint8_t* StationDelParameters::mac
```

 **Description:**

MAC address of the station to which the connection is to be canceled 

## macAddr \[1/3\]<a name="gacbe765a13d3de60f6c4f297234444553"></a>

```
char NetDevice::macAddr[[MAC_ADDR_SIZE](WLAN.md#gae01dbae885bc8abecb82bd865515c081)]
```

 **Description:**

MAC address  [MAC\_ADDR\_SIZE](WLAN.md#gae01dbae885bc8abecb82bd865515c081) 

## macAddr \[2/3\]<a name="ga98f76b11c4cac6945526d048cb925e6c"></a>

```
uint8_t Mac80211DisconnectParam::macAddr[WLAN_MAC_ADDR_LEN]
```

 **Description:**

Device MAC address 

## macAddr \[3/3\]<a name="ga84ee6f62e15f1e8252d97b0b3ef55239"></a>

```
uint8_t* VifParams::macAddr
```

 **Description:**

MAC address 

## mask<a name="gabcb55b1def4998381497e79e602a61d5"></a>

```
uint32_t StaFlagUpdate::mask
```

 **Description:**

Flag mask 

## maxAntennaGain<a name="gacd256a8179e084497aad4cacfac77dc2"></a>

```
int32_t Ieee80211Channel::maxAntennaGain
```

 **Description:**

Maximum antenna gain, in dBi 

## maxPower<a name="gaf998a486d7bc53071e68374a13aa18d8"></a>

```
int32_t Ieee80211Channel::maxPower
```

 **Description:**

Maximum transmit power, in dBm 

## maxScanIeLen<a name="ga249fb8ce5c398f3c6588519e58cd11e9"></a>

```
uint16_t Wiphy::maxScanIeLen
```

 **Description:**

Maximum SSID length 

## maxScanSsids<a name="gac64622da7ddfc981d13380a66321ee61"></a>

```
uint8_t Wiphy::maxScanSsids
```

 **Description:**

Maximum number of scanned service set identifiers \(SSIDs\) 

## mcs \[1/2\]<a name="ga5a8aea5e5f47700d6634ec48dc4a1f9f"></a>

```
uint8_t RateInfo::mcs
```

 **Description:**

Modulation and Coding Scheme \(MCS\) index of the HT/VHT/HE rate 

## mcs \[2/2\]<a name="gab100d81d329ddf8584ade014d20acc2d"></a>

```
struct [Ieee80211McsInfo](Ieee80211McsInfo.md) Ieee80211StaHtCap::mcs
```

 **Description:**

MCS rate 

## mem<a name="gad94b7aff082f5d891a3250dfc6307ce0"></a>

```
uint8_t* NetBuf::mem
```

 **Description:**

Memory buffer address 

## mfp<a name="ga8212747b66b319e95586ad90d4191300"></a>

```
uint8_t WifiConnectParams::mfp
```

 **Description:**

Whether to enable Management Frame Protection \(MFP\) 

## mgmt<a name="ga345b0140ecaa55ffc7c85bf96548efc9"></a>

```
struct [Ieee80211Mgmt](Ieee80211Mgmt.md)* ScannedBssInfo::mgmt
```

 **Description:**

Start address of the management frame 

## mgmtLen<a name="gaa40e6cfe80596087c25e256215123890"></a>

```
uint32_t ScannedBssInfo::mgmtLen
```

 **Description:**

Management frame length 

## mlPriv<a name="gac2b0eefb68664e9458311017ce31275b"></a>

```
void* NetDevice::mlPriv
```

 **Description:**

Private structure for the driver 

## module<a name="ga1d78d86692abec4c85fa96ea5c446509"></a>

```
struct [WifiModule](WifiModule.md)* HdfWifiProductData::module
```

 **Description:**

Structure of the WLAN module 

## moduleConfig<a name="gaa54566af9b7dda68e119649b3510c858"></a>

```
struct [WifiModuleConfig](WifiModuleConfig.md) WifiModule::moduleConfig
```

 **Description:**

Module configurations 

## modulePrivate<a name="gab8c955bd3dd2cb79c3c0c3dfdc3b08f5"></a>

```
void* WifiModule::modulePrivate
```

 **Description:**

Private data 

## mtu<a name="ga3c55b245d63ce32ea02f2890fc8e75a8"></a>

```
uint32_t NetDevice::mtu
```

 **Description:**

Maximum transmission unit 

## n\_akmSuites<a name="ga35627fc7ac0924a52e51427375501f8a"></a>

```
int32_t CryptoSettings::n_akmSuites
```

 **Description:**

Number of authentication and key management \(AKM\) suites 

## n\_ciphersPairwise<a name="gace9dbbf9c1a035b350224b1832d35377"></a>

```
int32_t CryptoSettings::n_ciphersPairwise
```

 **Description:**

Number of unicast ciphers supported by the access point \(AP\) 

## name \[1/3\]<a name="ga74b1c5d9a04465f4b47b36ece7470aab"></a>

```
char NetDevice::name[IFNAMSIZ]
```

 **Description:**

Network device name  **IFNAMSIZ** 

## name \[2/3\]<a name="gae63e4c5602dbc64bd9905d6b6a4e7aad"></a>

```
char WifiFeature::name[[MAX_WIFI_COMPONENT_NAME_LEN](WLAN.md#gaf460a45a5e365279ca6bc5b3e8750542)]
```

 **Description:**

[Feature](Feature.md)  name, which can contain a maximum of 10 characters 

## name \[3/3\]<a name="ga02ee61c30fc06116d5dee320eda37bfe"></a>

```
char HdfWifiChipData::name[[MAX_WIFI_COMPONENT_NAME_LEN](WLAN.md#gaf460a45a5e365279ca6bc5b3e8750542)]
```

 **Description:**

Chip name 

## nBitrates<a name="ga355299d64b9af1d889750bda9216734b"></a>

```
int32_t Ieee80211SupportedBand::nBitrates
```

 **Description:**

Length of the array of supported bit rates 

## nChannels \[1/2\]<a name="gaf075c96dac24e5b685d35481c78ecb01"></a>

```
int32_t Ieee80211SupportedBand::nChannels
```

 **Description:**

Length of the array of supported channels 

## nChannels \[2/2\]<a name="ga3150e4a25b1800ee713e08fbf9077116"></a>

```
uint32_t WifiScanRequest::nChannels
```

 **Description:**

Number of channels to scan for 

## nCipherSuites<a name="gab6cb6ce28cef7f1f5dc0d19380e8ad05"></a>

```
int32_t Wiphy::nCipherSuites
```

 **Description:**

Number of supported cipher suites 

## neededHeadRoom<a name="ga9241a41c1cb62a68e3d8c93b9dfe4790"></a>

```
uint16_t NetDevice::neededHeadRoom
```

 **Description:**

Length reserved for the header in netbuff[NetBuf](NetBuf.md) 

## neededTailRoom<a name="ga3ad6638d07aef608b8d5e4b20a478e03"></a>

```
uint16_t NetDevice::neededTailRoom
```

 **Description:**

Length reserved for the tail in netbuff[NetBuf](NetBuf.md) 

## netdev<a name="gacf9e3f94cbac9cf8ae3382aea0d6c5f6"></a>

```
struct [NetDevice](NetDevice.md)* WirelessDev::netdev
```

 **Description:**

Network device 

## netDeviceIf<a name="gaf154f5a9cbf4d297bc6fc7550ae9a819"></a>

```
struct [NetDeviceInterFace](NetDeviceInterFace.md)* NetDevice::netDeviceIf
```

 **Description:**

Network device interface 

## netifCateg<a name="ga95102f11976f69a7c700944614fa06b2"></a>

```
[NetIfCategory](WLAN.md#ga530241881cd17e03f8ae254ef1d9755e) NetDevice::netifCateg
```

 **Description:**

Network interface category  [NetIfCategory](WLAN.md#ga530241881cd17e03f8ae254ef1d9755e) 

## netifNotify<a name="ga518102ebc29b985161160ae22b066faf"></a>

```
uint32_t(* NetDeviceInterFace::netifNotify) (struct [NetDevice](NetDevice.md) *netDev, [NetDevNotify](NetDevNotify.md) *notify)
```

 **Description:**

Notifies the network port status. 

## notifyType<a name="ga5b652685d8841c46872427b87507f4e7"></a>

```
uint32_t NetDevNotify::notifyType
```

 **Description:**

Notification type \(reserved\) 

## nss<a name="gac9516b58cac5a7294541958513514c0b"></a>

```
uint8_t RateInfo::nss
```

 **Description:**

Number of streams \(for VHT and HE only\) 

## nSsids<a name="gaf7bf0f80492f28c7c285f8023505bb8e"></a>

```
uint32_t WifiScanRequest::nSsids
```

 **Description:**

Number of SSIDs to scan for 

## offset \[1/2\]<a name="ga5f5c974dbd2e5608b3ea2e768e4559ca"></a>

```
int64_t StationInfo::offset
```

 **Description:**

Time offset of station 

## offset \[2/2\]<a name="gabac9ba66ff160d881083b1f173f411f9"></a>

```
uint8_t TcpHeader::offset
```

 **Description:**

Header length 

## open<a name="ga154f75bcfd914b1fb243041186b60a3f"></a>

```
int32_t(* NetDeviceInterFace::open) (struct [NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Opens the data link layer. 

## operationType<a name="ga98a709ca72bbd2625125b378c08b6d9e"></a>

```
uint8_t Mac80211beaconParam::operationType
```

 **Description:**

Operation type 

## ops<a name="ga920007113f95ee9ce9b0d51ca0cf42bc"></a>

```
struct [WifiMac80211Ops](WifiMac80211Ops.md)* HdfWifiChipData::ops
```

 **Description:**

Chip MAC address 

## origFlags<a name="gaa8e6146a2fa16a47e794d7d9bbaccf1e"></a>

```
uint32_t Ieee80211Channel::origFlags
```

 **Description:**

Channel flags 

## origMag<a name="gaf5bc0d20f7c46fbcfd69cb62c3470dfe"></a>

```
int32_t Ieee80211Channel::origMag
```

 **Description:**

Reserved field 

## origMpwr<a name="gaa9666ab4a0f723741328722d1ab74588"></a>

```
int32_t Ieee80211Channel::origMpwr
```

 **Description:**

Reserved field 

## owner<a name="ga6f725a86ac73ba02449952d3f8fbcff9"></a>

```
struct [NetDevice](NetDevice.md)* NetDevice::owner
```

 **Description:**

Network device 

## p2pMode<a name="gad17af431fa1dd6157d3118023459a784"></a>

```
uint8_t MacConfigParam::p2pMode
```

 **Description:**

Whether the peer-to-peer \(P2P\) mode is used. 

## permAddr<a name="ga5396b8e87fe6a6be0c7dd789fe289c50"></a>

```
uint8_t Wiphy::permAddr[WLAN_MAC_ADDR_LEN]
```

 **Description:**

Permanent MAC address of the wiphy device. For its length, see  **WLAN\_MAC\_ADDR\_LEN**. 

## plid<a name="ga7dedfef626385689a1baa20e9764ff05"></a>

```
uint16_t StationInfo::plid
```

 **Description:**

Peer mesh ID 

## plinkState<a name="gaf505fd1078d9f5a0d5374d9538e8d5bb"></a>

```
uint8_t StationInfo::plinkState
```

 **Description:**

Mesh peer state 

## prefixSsidScanFlag<a name="ga5b6c8df255d62a73114aad42c1e4868d"></a>

```
uint8_t WifiScanRequest::prefixSsidScanFlag
```

 **Description:**

Reserved field 

## presetChandef<a name="ga142433e20a4e8168774cf50dfbbfd27b"></a>

```
struct [ChannelDef](ChannelDef.md) WirelessDev::presetChandef
```

 **Description:**

Channel information 

## priv<a name="ga760737c03ad122b360ca8ed814869e4b"></a>

```
uint8_t Wiphy::priv[WIPHY_PRIV_SIZE]
```

 **Description:**

Reserved field 

## privacy<a name="ga81e32b68cb7ae4a68b1d42633fc181fe"></a>

```
uint8_t WifiConnectParams::privacy
```

 **Description:**

Whether to use a privacy-enabled AP 

## probeResp \[1/2\]<a name="ga27d701ae6c64ae3d17ff24ae2500523e"></a>

```
struct { ... } ::probeResp
```

 **Description:**

Probe response frame 

## probeResp \[2/2\]<a name="ga4111b0df54692760f9e56b52fe1ba841"></a>

```
struct [ProbeResp](ProbeResp.md) Ieee80211Mgmt::probeResp
```

 **Description:**

Probe response frame 

## product\_name<a name="ga97418ebfac2a3a4ecc77c3c98b1ae810"></a>

```
char HdfWifiProductData::product_name[[MAX_WIFI_COMPONENT_NAME_LEN](WLAN.md#gaf460a45a5e365279ca6bc5b3e8750542)]
```

 **Description:**

WLAN module name, which contains a maximum of 10 bytes 

## protocol<a name="ga029ab0914b5854efe279e442aec3b423"></a>

```
uint8_t IpHeader::protocol
```

 **Description:**

Protocol, such as 1 \(ICMP\), 2 \(IGMP\), 6 \(TCP\), 17 \(UDP\), and 89 \(OSPF\) 

## qmap<a name="gaa56eababaaaeda2ec724f21889a20ccd"></a>

```
uint32_t NetBuf::qmap
```

 **Description:**

Queue mappings of the network data buffer 

## reasonCode \[1/4\]<a name="gaa31a88b9f6b93548fe64aa39048bc78d"></a>

```
uint16_t Deauth::reasonCode
```

 **Description:**

Deauthentication cause code 

## reasonCode \[2/4\]<a name="gabbe22887613c2c96802b092f23898553"></a>

```
uint16_t Disassoc::reasonCode
```

 **Description:**

Cause code 

## reasonCode \[3/4\]<a name="gaadcc8f71dfd7b2c5ecc072cceb5fa3bb"></a>

```
uint16_t StationDelParameters::reasonCode
```

 **Description:**

Cause of the cancellation 

## reasonCode \[4/4\]<a name="ga5fe7610b3bff3864f9a2fee995c907ef"></a>

```
uint16_t Mac80211DisconnectParam::reasonCode
```

 **Description:**

Disconnection reason code 

## reassocReq \[1/2\]<a name="gad48460387d63f16a7b12ae6d16dc48df"></a>

```
struct { ... } ::reassocReq
```

 **Description:**

Re-authentication 

## reassocReq \[2/2\]<a name="ga6e7eeaa3e4d604a221f598e51c3869eb"></a>

```
struct [ReassocReq](ReassocReq.md) Ieee80211Mgmt::reassocReq
```

 **Description:**

Re-authentication 

## reassocResp \[1/2\]<a name="gab23b4bd33fd0295774a4ca362ea9312d"></a>

```
struct [ReassocResp](ReassocResp.md) Ieee80211Mgmt::reassocResp
```

 **Description:**

Re-authentication response 

## reassocResp \[2/2\]<a name="ga966d7d7ea87b3e2d0446a059f078ded1"></a>

```
struct { ... } ::reassocResp
```

 **Description:**

Re-authentication response 

## reqIe<a name="ga1ba76217df6a0a67be62ab623f68ee66"></a>

```
uint8_t* ConnetResult::reqIe
```

 **Description:**

Association request IE 

## reqIeLen<a name="gaade69412094ceaa5374c76513064f00a"></a>

```
uint32_t ConnetResult::reqIeLen
```

 **Description:**

Length of the association request IE 

## reserved<a name="ga92cf658154d7d1fddeebc4a01cc317d6"></a>

```
uint8_t Ieee80211McsInfo::reserved[IEEE80211_MACINFO_RESV]
```

 **Description:**

Reserved field 

## resv \[1/4\]<a name="ga8ae51118ee5e1a121bad85055ecad454"></a>

```
uint8_t Ieee80211Channel::resv[IEEE80211_CHANNEL_RESV]
```

 **Description:**

Reserved field 

## resv \[2/4\]<a name="ga9bb2fd298749eab513163e3a7a2b03ee"></a>

```
uint8_t WifiScanRequest::resv[SCAN_REQUEST_RESV_SIZE]
```

 **Description:**

Reserved field 

## resv \[3/4\]<a name="ga7c1cd7fbd4ccdf7babf89394cc78ab77"></a>

```
uint8_t WirelessDev::resv[WIRELESS_DEV_RESV_SIZE]
```

 **Description:**

Reserved field 

## resv \[4/4\]<a name="ga740712d61cb553af65d36d1a65f0a483"></a>

```
uint8_t RateInfo::resv
```

 **Description:**

Reserved 

## resv1<a name="ga4bf7e03861cdefd017d6669994a1df43"></a>

```
uint8_t StationInfo::resv1
```

 **Description:**

Reserved 

## rspIe<a name="ga113ce1420c647c51b89dca5ab436f82e"></a>

```
uint8_t* ConnetResult::rspIe
```

 **Description:**

Association response IE 

## rspIeLen<a name="ga0756bccba43358d534d8c5a254d63686"></a>

```
uint32_t ConnetResult::rspIeLen
```

 **Description:**

Length of the association response IE 

## rsv \[1/2\]<a name="gaec41f143c3551e59da63ab2e9d9c9c53"></a>

```
uint8_t Ieee80211Rate::rsv[IEEE80211_RATE_RESV]
```

 **Description:**

Reserved field 

## rsv \[2/2\]<a name="ga197b5045451ca25a03f478df0bd03514"></a>

```
uint8_t NetBuf::rsv[[MAX_NETBUF_RESEVER_SIZE](WLAN.md#ga794c035a19a38acc000146a8f9a4ec80)]
```

 **Description:**

Reserved field. For details, see  [MAX\_NETBUF\_RESEVER\_SIZE](WLAN.md#ga794c035a19a38acc000146a8f9a4ec80). 

## rtsThreshold<a name="ga00874e60aa7dc8c7455732e633586813"></a>

```
uint32_t Wiphy::rtsThreshold
```

 **Description:**

[Request](Request.md)  To Send \(RTS\) threshold 

## rxBytes \[1/2\]<a name="ga8445328bc8d5cc4ba8bc5d5f8ec0c1fa"></a>

```
uint64_t StationInfo::rxBytes
```

 **Description:**

Received bytes 

## rxBytes \[2/2\]<a name="ga809ff3fc1f051abbb655cc7ea6cbd900"></a>

```
uint32_t NetDevStats::rxBytes
```

 **Description:**

Total number of received bits 

## rxDropped<a name="gae3a86ad63c016badbd0ac72bf572afa3"></a>

```
uint32_t NetDevStats::rxDropped
```

 **Description:**

Packets that are dropped after being received 

## rxDroppedMisc<a name="ga9506e6f1cd855cf8116dd650f68966ac"></a>

```
uint32_t StationInfo::rxDroppedMisc
```

 **Description:**

Number of receive failures 

## rxErrors<a name="gabf0cb61284e0cba862c5e8db62b63fa9"></a>

```
uint32_t NetDevStats::rxErrors
```

 **Description:**

Number of received error packets 

## rxHighest<a name="gad76dc235ae05680bdde62564f5a6c10b"></a>

```
uint16_t Ieee80211McsInfo::rxHighest
```

 **Description:**

Maximum rate for receiving data 

## rxMask<a name="gaaa1851c2f6db9ccf446f70eb272196f5"></a>

```
uint8_t Ieee80211McsInfo::rxMask[IEEE80211_HT_MCS_MASK_LEN]
```

 **Description:**

Mask for receiving data 

## rxPackets \[1/2\]<a name="gac890bb6b9e08670ec2bb1a0c41ab1cdc"></a>

```
uint32_t StationInfo::rxPackets
```

 **Description:**

Received data packets 

## rxPackets \[2/2\]<a name="ga691401a65931b7753fe1f67749074755"></a>

```
uint32_t NetDevStats::rxPackets
```

 **Description:**

Total number of received packets 

## rxRate<a name="ga7ccb9050859ba196054590b2294f3a40"></a>

```
struct [RateInfo](RateInfo.md) StationInfo::rxRate
```

 **Description:**

Receive rate 

## sAddr<a name="ga22e36dfd118fbe9deee40135f87a0568"></a>

```
uint32_t IpHeader::sAddr
```

 **Description:**

Source address 

## selectQueue<a name="ga3e08c5be1dbe6e4aa6fc1f930783c295"></a>

```
uint16_t(* NetDeviceInterFace::selectQueue) (struct [NetDevice](NetDevice.md) *netDev, struct [NetBuf](NetBuf.md) *netBuff)
```

 **Description:**

Selects a priority queue. 

## seq<a name="ga00bfccb54d7fc37bc2ddbf9ebf3937bb"></a>

```
uint8_t* KeyParams::seq
```

 **Description:**

Content of a Temporal Key Integrity Protocol \(TKIP\) or Counter Mode Cipher Block Chaining Message Authentication Code Protocol \(CCMP\) key 

## seqCtrl<a name="gab3b6ce7596b771a8bb0af0edbad416fd"></a>

```
uint16_t Ieee80211Mgmt::seqCtrl
```

 **Description:**

Sequence control 

## seqLen<a name="ga6b1bb1722c1205c1b560c01c58d35018"></a>

```
int32_t KeyParams::seqLen
```

 **Description:**

Length of a TKIP or CCMP key 

## seqNum<a name="ga5409de9f82a50bf5113dafb316118d4b"></a>

```
uint32_t TcpHeader::seqNum
```

 **Description:**

Sequence number 

## set<a name="ga9c47590735e6ba21c557361770f76338"></a>

```
uint32_t StaFlagUpdate::set
```

 **Description:**

Flag value 

## setChannel<a name="ga166ca94a9482995f3e1f58263eeeed02"></a>

```
int32_t(* WifiMac80211Ops::setChannel) ([NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Setting the channel 

## setDefaultKey<a name="gae4e2e0af8777ab0bae98b1816664bddc"></a>

```
int32_t(* WifiMac80211Ops::setDefaultKey) (struct [NetDevice](NetDevice.md) *netdev, uint8_t keyIndex, bool unicast, bool multicas)
```

 **Description:**

Setting the default key 

## setMacAddr \[1/2\]<a name="ga177446df24b19e4ddca32e9719d6fe8e"></a>

```
int32_t(* WifiMac80211Ops::setMacAddr) ([NetDevice](NetDevice.md) *netDev, [Mac80211SetMacParam](WLAN.md#ga85f7d8a3795887f090e0a6439b1df6e1) *param)
```

 **Description:**

Setting the MAC address 

## setMacAddr \[2/2\]<a name="ga104f6b8049728769f54563aa242850b8"></a>

```
int32_t(* NetDeviceInterFace::setMacAddr) (struct [NetDevice](NetDevice.md) *netDev, void *addr)
```

 **Description:**

Sets the MAC address. 

## setMeshId<a name="ga37e19745783d5dbf8439b9f1f89ca6f5"></a>

```
int32_t(* WifiMac80211Ops::setMeshId) ([NetDevice](NetDevice.md) *netDev, const char *meshId, uint32_t meshIdLen)
```

 **Description:**

Setting the mesh ID 

## setNetIfStatus<a name="ga334e7e9c31ff9408ba67aed1cb96a174"></a>

```
void(* NetDeviceInterFace::setNetIfStatus) (struct [NetDevice](NetDevice.md) *netDev, [NetIfStatus](WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf) status)
```

 **Description:**

Sets the network port status. 

## setSsid<a name="ga519c91a244639e25a8c604e284486873"></a>

```
int32_t(* WifiMac80211Ops::setSsid) ([NetDevice](NetDevice.md) *netDev, const uint8_t *ssid, uint32_t ssidLen)
```

 **Description:**

Setting the SSID 

## signal \[1/2\]<a name="gaf34477153f092bd07bd8a80ca29d16bf"></a>

```
int8_t StationInfo::signal
```

 **Description:**

Signal strength 

## signal \[2/2\]<a name="ga20f18f7993df9723a0f3e7520ae715e2"></a>

```
int32_t ScannedBssInfo::signal
```

 **Description:**

Signal strength 

## signalAvg<a name="ga5423c3f5c2797588018ae3e32582e0bf"></a>

```
int8_t StationInfo::signalAvg
```

 **Description:**

Average signal strength 

## signalType<a name="ga0c0e8af92ed7d85cbcc04bcf4f13a8b7"></a>

```
uint8_t Wiphy::signalType
```

 **Description:**

Signal type 

## size<a name="gab8e922b274e1854731b5fd22d8dde62d"></a>

```
uint32_t NetBufQueue::size
```

 **Description:**

Number of network data buffers in the queue 

## source<a name="gaa51376bc21358f5c14e8c21ddc9afa00"></a>

```
uint16_t UdpHeader::source
```

 **Description:**

Source port number 

## specialEtherTypeProcess<a name="ga8bb9ea881b1bdabe8c45f721310823b1"></a>

```
[ProcessingResult](WLAN.md#ga9c1d6e7df4468671742cb76f72b67af1)(* NetDeviceInterFace::specialEtherTypeProcess) (const struct [NetDevice](NetDevice.md) *netDev, struct [NetBuf](NetBuf.md) *buff)
```

 **Description:**

Performs private processing without involving network-layer data. 

## specialProcPriv<a name="ga659f5eb4ee2cef37cb93acea357acb75"></a>

```
void* NetDevice::specialProcPriv
```

 **Description:**

Private structure for data processing 

## sPort<a name="gae29f9cbe74e4e7f7543e74bb8d039f15"></a>

```
uint16_t TcpHeader::sPort
```

 **Description:**

Source port number 

## srcAddr<a name="ga636095dd14f2219a50cd5d86e7f94cde"></a>

```
uint8_t Ieee80211Mgmt::srcAddr[6]
```

 **Description:**

Source MAC address 

## ssid \[1/2\]<a name="ga320f45c28aa8ca8095159b8a0a114268"></a>

```
uint8_t WifiSsid::ssid[IEEE80211_MAX_SSID_LEN]
```

 **Description:**

SSID content, which contains a maximum of 32 bytes 

## ssid \[2/2\]<a name="ga875dd450960cc445dd2a12355bc6912c"></a>

```
uint8_t* WifiConnectParams::ssid
```

 **Description:**

SSID 

## ssidLen \[1/3\]<a name="ga35c2bd750767a87abf1c45b480124669"></a>

```
uint8_t WifiSsid::ssidLen
```

 **Description:**

SSID length 

## ssidLen \[2/3\]<a name="ga18a38015e45de3571893b8c1edea991a"></a>

```
uint32_t WifiConnectParams::ssidLen
```

 **Description:**

SSID length 

## ssidLen \[3/3\]<a name="gac5c6ea249ba044d37f2b85df506cd898"></a>

```
uint8_t Mac80211Ssids::ssidLen
```

 **Description:**

SSID length 

## ssids<a name="ga761056fae3d79073bbc33ad3f00a7319"></a>

```
struct [WifiSsid](WifiSsid.md)* WifiScanRequest::ssids
```

 **Description:**

SSIDs to scan for 

## staFlags<a name="gae3d8b6844b2838f2622405f27d9eb33b"></a>

```
struct [StaFlagUpdate](StaFlagUpdate.md) StationInfo::staFlags
```

 **Description:**

Station flag masks and values 

## startAp<a name="ga203437a6b1d66758f2217f7154ce1210"></a>

```
int32_t(* WifiMac80211Ops::startAp) ([NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Starting an AP 

## startScan<a name="ga259da70c25a528287c433af2f7bcf530"></a>

```
int32_t(* WifiMac80211Ops::startScan) ([NetDevice](NetDevice.md) *netDev, struct [WifiScanRequest](WifiScanRequest.md) *param)
```

 **Description:**

Starting a scan based on the specified parameters 

## state<a name="gaf3ac6e671103cb8319d7ed2af62883f2"></a>

```
char HdfWifiProductData::state
```

 **Description:**

WLAN module state 

## stats<a name="gafdd796dab998fb2ff695af4d50abdc13"></a>

```
struct NetDevStats NetDevice::stats
```

 **Description:**

Network statistics 

## statusCode \[1/4\]<a name="gaf37ac11db8228fec9975121b199311f7"></a>

```
uint16_t Auth::statusCode
```

 **Description:**

Authentication status code 

## statusCode \[2/4\]<a name="gafffefc2805012b07d7f23dcc3cc014e5"></a>

```
uint16_t AssocResp::statusCode
```

 **Description:**

Status code 

## statusCode \[3/4\]<a name="ga245f8361fce97aa71072505cac290411"></a>

```
uint16_t ReassocResp::statusCode
```

 **Description:**

Status code 

## statusCode \[4/4\]<a name="gaddcc87402a9e4e6f09098d5e7c25eebe"></a>

```
uint16_t ConnetResult::statusCode
```

 **Description:**

16-bit status code defined in the IEEE protocol 

## stop<a name="ga5e328f3dc0b610672889e66b33bb7cf8"></a>

```
int32_t(* NetDeviceInterFace::stop) (struct [NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Closes the data link layer. 

## stopAp<a name="gaf30acc8bd9ecd9bffbc46f423423266e"></a>

```
int32_t(* WifiMac80211Ops::stopAp) ([NetDevice](NetDevice.md) *netDev)
```

 **Description:**

Stopping an AP 

## subtype<a name="gac649567339d882d98c5f4ba98bbb241e"></a>

```
uint8_t StationDelParameters::subtype
```

 **Description:**

Cancellation type 

## timestamp \[1/2\]<a name="ga9ff8a9a52a3e4f341e7ff49dd7bf76b8"></a>

```
uint64_t Beacon::timestamp
```

 **Description:**

Timestamp 

## timestamp \[2/2\]<a name="ga061a09e9bc3131127aa09d956f60b040"></a>

```
uint64_t ProbeResp::timestamp
```

 **Description:**

Timestamp 

## tos<a name="ga324f15b4a41342c026ce3ad253ed9498"></a>

```
uint8_t IpHeader::tos
```

 **Description:**

[Service](Service.md)  type 

## totLen<a name="ga35aa269c5b304d238c65aedaa28e3da5"></a>

```
uint16_t IpHeader::totLen
```

 **Description:**

Total length of an IP data packet 

## ttl<a name="gad380e64b2d33d75ce04d65126b54fb8f"></a>

```
uint8_t IpHeader::ttl
```

 **Description:**

Generation time 

## txBytes \[1/2\]<a name="ga3084ceeea5b4c0ab032f59f5c5988ef8"></a>

```
uint64_t StationInfo::txBytes
```

 **Description:**

Transmitted bytes 

## txBytes \[2/2\]<a name="ga665048e0ce5b8dffa2a3b69bad0bf231"></a>

```
uint32_t NetDevStats::txBytes
```

 **Description:**

Total number of transmitted bits 

## txDropped<a name="ga6d9439773d9721261de50a521c301fd9"></a>

```
uint32_t NetDevStats::txDropped
```

 **Description:**

Packets dropped before transmission 

## txErrors<a name="gac95614d9e1d400c6ed6f06b8f6aaf0a0"></a>

```
uint32_t NetDevStats::txErrors
```

 **Description:**

Transmitted error packets 

## txFailed<a name="gab02c662294106f07045b103fcf4eb689"></a>

```
uint32_t StationInfo::txFailed
```

 **Description:**

Number of failed transmissions 

## txPackets \[1/2\]<a name="ga0f048248764942c6717dce0695039c1d"></a>

```
uint32_t StationInfo::txPackets
```

 **Description:**

Transmitted data packets 

## txPackets \[2/2\]<a name="gac9d132b276538f055db2443e61f00b72"></a>

```
uint32_t NetDevStats::txPackets
```

 **Description:**

Total number of transmitted packets 

## txParams<a name="ga9cb852fd0e898070ffb355080d4079cd"></a>

```
uint8_t Ieee80211McsInfo::txParams
```

 **Description:**

Parameters for sending data 

## txPetries<a name="gaae49c0ae8a58b58adf92be62af7147fd"></a>

```
uint32_t StationInfo::txPetries
```

 **Description:**

Number of retransmissions 

## txRate<a name="ga959e150b0327d9a30db768aec89426ae"></a>

```
struct [RateInfo](RateInfo.md) StationInfo::txRate
```

 **Description:**

Transmission rate 

## type<a name="ga4c59fb9385e56ed8017ee48d36bac554"></a>

```
uint16_t HdfWifiChipData::type
```

 **Description:**

Chip type 

## updateModule<a name="ga5166022e5100e57fe0b307a4254e3dc1"></a>

```
int32_t(* WifiModuleIface::updateModule) (struct [WifiModule](WifiModule.md) *module)
```

 **Description:**

Updating a WLAN module based on a specified configuration. 

## urgent<a name="ga0c402826ed93d697342d8b1108db7754"></a>

```
uint16_t TcpHeader::urgent
```

 **Description:**

Urgent pointer 

## use4Addr<a name="ga554a530b88a15955fd9859ec08b569f3"></a>

```
int32_t VifParams::use4Addr
```

 **Description:**

Whether to use a frame containing four addresses 

## variable \[1/7\]<a name="ga114bed8793f4e32fba36ca20c9ac10d8"></a>

```
uint8_t Auth::variable[0]
```

 **Description:**

Algorithm challenge information stored in a flexible array 

## variable \[2/7\]<a name="ga69066d587669a7b69106d618e90fbad3"></a>

```
uint8_t AssocReq::variable[0]
```

 **Description:**

SSID and rate information stored in a flexible array 

## variable \[3/7\]<a name="gaf087bcdc5ec6bd2fc84981ccc1b85612"></a>

```
uint8_t AssocResp::variable[0]
```

 **Description:**

Rate information stored in a flexible array 

## variable \[4/7\]<a name="ga27b1d2abd28404a65166381dffdd5d57"></a>

```
uint8_t ReassocReq::variable[0]
```

 **Description:**

SSID and rate information stored in a flexible array 

## variable \[5/7\]<a name="gaf330f60c8afa98503226325a3d4328f9"></a>

```
uint8_t ReassocResp::variable[0]
```

 **Description:**

Rate information stored in a flexible array 

## variable \[6/7\]<a name="ga0de9d9ef52da27a0a11753d152c2fb64"></a>

```
uint8_t Beacon::variable[0]
```

 **Description:**

SSID and rate information 

## variable \[7/7\]<a name="ga9606f7f13ca77c203e07d48e65608bb3"></a>

```
uint8_t ProbeResp::variable[0]
```

 **Description:**

SSID and rate information 

## versionAndHl<a name="gae31602cb3fb4f012749e6d44e73bd5bf"></a>

```
uint8_t IpHeader::versionAndHl
```

 **Description:**

Version and header length 

## watchdogTime<a name="ga480ec41047ece56996f42b0f72a6e079"></a>

```
int32_t NetDevice::watchdogTime
```

 **Description:**

Watchdog duration 

## wdev<a name="ga09f1cdfc6c524ca96aed6b1894baa720"></a>

```
struct [WirelessDev](WirelessDev.md)* WifiScanRequest::wdev
```

 **Description:**

A specified wireless device to scan for 

## width<a name="gae9ff862b7d4a7145eb00275d57938b4f"></a>

```
enum [WifiChannelType](WLAN.md#ga9d902b330de99c24b2a8c3ba7120af21) ChannelDef::width
```

 **Description:**

Bandwidth 

## window<a name="ga55cc45eeabc0f857e51e8864ae45de8e"></a>

```
uint16_t TcpHeader::window
```

 **Description:**

Window size 

## wiphy \[1/2\]<a name="ga86835b49d9ac8e3965d710334d1ecdf2"></a>

```
struct [Wiphy](Wiphy.md)* WirelessDev::wiphy
```

 **Description:**

[Wiphy](Wiphy.md)  device 

## wiphy \[2/2\]<a name="ga43dd029f6f34ccb0255e519aded47478"></a>

```
struct [Wiphy](Wiphy.md)* WifiScanRequest::wiphy
```

 **Description:**

A specified wiphy device to scan for 

## wlanType<a name="gaf957402f9938b5bf37a7c39737f18e69"></a>

```
[Protocol80211IfType](WLAN.md#gac69954f56fcc99fc8aac68aa157831c7) IfType::wlanType
```

 **Description:**

WLAN network port type: AP or STA 

## wpaVersions<a name="ga2b21ef556b428238d4dc5009b82087ff"></a>

```
uint32_t CryptoSettings::wpaVersions
```

 **Description:**

WPA version 

## xmit<a name="ga5d6e31f59da2eef0998deadd40e13304"></a>

```
[NetDevTxResult](WLAN.md#ga9fb4e578a15db1b0087d7b3831591ced)(* NetDeviceInterFace::xmit) (struct [NetDevice](NetDevice.md) *netDev, struct [NetBuf](NetBuf.md) *netBuff)
```

 **Description:**

Sends data. 

