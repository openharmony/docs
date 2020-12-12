# MATH<a name="EN-US_TOPIC_0000001055228010"></a>

-   [Overview](#section1668727741165622)
-   [Summary](#section2135939735165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section561840359165622)
-   [Macro Definition](#section1913429893165622)
-   [isfinite](#ga256d70a32c03904ce13c999c1e9dc35d)
-   [isgreater](#gada788e9d6ce0ca927874ec4e53af1f77)
-   [isgreaterequal](#ga5a7f86a4d3e6139e4913e2e8eba52612)
-   [isinf](#ga2a266c767456556e5c0da234b602b18b)
-   [isless](#ga61079b32084130da4345c2eea93e0d61)
-   [islessequal](#gabf3cb1e5a0aaa1c42dffa9ebb1d78c30)
-   [islessgreater](#ga5e534756b747fd2e9ee19f8fdd93b30b)
-   [isnan](#ga2e1baae9134e580910322362dc23290e)
-   [isnormal](#gad83f5949c4b5d810225b9a834840bac9)
-   [isunordered](#ga33daf51eb7138d477e0b0985c51e4fad)
-   [signbit](#gaa63ffa98f213f62e536b073c28cb3cd8)
-   [Function](#section948971469165622)
-   [acos\(\)](#gae93afe22ff34c79ee97ea3eaf77557db)
-   [acosf\(\)](#ga983a9e1aa7568df39153ea4d8e16653b)
-   [acosh\(\)](#gac862445bcb46911b1782c284829d5e46)
-   [acoshf\(\)](#ga84cfd14c3432390f70b6233d24ad173b)
-   [acoshl\(\)](#ga104456314ba05665d6cbb805e823dd10)
-   [acosl\(\)](#gae84dc6cff92b3417098f16a1811635e4)
-   [asin\(\)](#gaa9528d92a3ae44ad6484da0774604454)
-   [asinf\(\)](#ga7447a7400ca474ba42d127b04d6ee2b7)
-   [asinh\(\)](#ga907297107e93ea9c8a0c8409a8e65079)
-   [asinhf\(\)](#ga1131c65ac49f31ed6774d27106c6394d)
-   [asinhl\(\)](#ga98df355372e19c11634992e4b7e35784)
-   [asinl\(\)](#ga3ace56b4f2a4a9364993a5af676793c5)
-   [atan\(\)](#ga1e2f8f6d64eaa95131bc63fee34970ea)
-   [atan2\(\)](#ga349377202ca14f79eb335b1a421fe4d8)
-   [atan2f\(\)](#gaf9e5469acf7a7bf82f29d86a77f539d4)
-   [atan2l\(\)](#gaa983bf34c931b97d66be8b7bfd03dc48)
-   [atanf\(\)](#gaa582bc257e477e805f4ec384a39a3a8e)
-   [atanh\(\)](#gac07fd7b77fa341563abccf9efcc1a711)
-   [atanhf\(\)](#ga626d9d6644848e74188f37f0f3ddd4f4)
-   [atanhl\(\)](#gab25c31215118cd62672c38f80f010d66)
-   [atanl\(\)](#ga650d8dd23c16c6699d84651a18827d37)
-   [cabs\(\)](#ga82c65f6b05062b620716623ba49ff07f)
-   [cabsf\(\)](#ga59a1f4977dfdf85b51a84bfd56737277)
-   [cabsl\(\)](#ga7e37259e24f3384f376e4d3eb45a9ea8)
-   [cacos\(\)](#ga51a9bcdc7791e50f879c79d64362d7c3)
-   [cacosf\(\)](#ga238bc3dbd59adeb477af18c9a501e04e)
-   [cacosh\(\)](#gaf7286142554fde4ba6316a2b64b96c5c)
-   [cacoshf\(\)](#gabe9dbe34293eef409598b0559435c5ff)
-   [cacoshl\(\)](#gad8e03bbb434b8a9af73e0e3daec045ac)
-   [cacosl\(\)](#ga789143f2859142f58590b2726328025f)
-   [carg\(\)](#ga4a1e5d839db7a1dc6013b2846b2432d9)
-   [cargf\(\)](#ga66334f398567baa3648cd3111ed68d3b)
-   [cargl\(\)](#ga74f3429f1b860581f4d15bea90533fd5)
-   [casin\(\)](#gac43774f89411806a3e0695012cdb7f38)
-   [casinf\(\)](#ga04d2cd1f0b47d3f1b782aeb517151033)
-   [casinh\(\)](#ga6fc1a0c1cbac62ba63e799d7e8f488e0)
-   [casinhf\(\)](#ga8b682e1c311efa5594ec0d0b39c9efe0)
-   [casinhl\(\)](#ga174b8f2a00e771dbbad06fdf0e0ee449)
-   [casinl\(\)](#ga8770350a79904ac151ebb3eebd736188)
-   [catan\(\)](#ga1a77a3240b834af81a23b38f2af6c93d)
-   [catanf\(\)](#ga4d0beef9b3994887e356c6b5c98388d9)
-   [catanh\(\)](#ga376fef7890def8c0e7b2b5a5292be074)
-   [catanhf\(\)](#ga480c29e0eeace893be77a2c61995d2ec)
-   [catanhl\(\)](#gab2422355124f175a41ec092c3b8adf2b)
-   [catanl\(\)](#gaf28ad2f006e49eaa6bbdb97dd143d6cb)
-   [cbrt\(\)](#ga8af00e2203928978e0242b4afd1d899f)
-   [cbrtf\(\)](#ga396c6a553500a355627741e234045bf4)
-   [cbrtl\(\)](#ga521c2f4c10b7bb5363bad058ef56794c)
-   [ccos\(\)](#ga6a25bcd38751910533efde6dad1499c3)
-   [ccosf\(\)](#ga88df5eebfb10b88ed37e444f5b13fd6a)
-   [ccosh\(\)](#ga62c8f7e0cce95bbf670af16376909324)
-   [ccoshf\(\)](#gabe11c35bd81b278ab0e47196c5952662)
-   [ccoshl\(\)](#gad2b7878b871c0266ecb1f58e5bf141a7)
-   [ccosl\(\)](#ga785d8c7b2ac4283d4759dfa6a86779ab)
-   [ceil\(\)](#ga1ea6d7b591132268abc2e843ababd084)
-   [ceilf\(\)](#ga8c1a8db0710bb3f25f643a0fca68fc60)
-   [ceill\(\)](#gae11b7781f057eb7ba5d7ed95be7fdbee)
-   [cexp\(\)](#gab9c654c52efefb54d06d52aa1a1c1827)
-   [cexpf\(\)](#ga8628a449a00228f124c9e53d2236611f)
-   [cexpl\(\)](#ga31a965fe1790cace431516e53f7d0cb5)
-   [cimag\(\)](#ga6c3d7c875ae93700b0a2a32db24b37d3)
-   [cimagf\(\)](#gaac22dc2fffc4326595ff807d441f0675)
-   [cimagl\(\)](#ga4237f0401b8123eaec284c995ced4b04)
-   [clog\(\)](#gaa39c3557d8db10c19571bc0b63fd5529)
-   [clogf\(\)](#ga0c9f343c7d1dabc91f6e4cb868b81152)
-   [clogl\(\)](#ga48efe0bf63314044fafaeb32623fff17)
-   [conj\(\)](#ga6fb30f37aa43eb2e0199ffdc38cac18a)
-   [conjf\(\)](#ga471ecd8d25e722ecae510a635c1a2c53)
-   [conjl\(\)](#ga5156353f4650ed7ee06b152790c1558b)
-   [copysign\(\)](#gad8d1296592a3e783acdd0de21ff58e2e)
-   [copysignf\(\)](#gaf7eb976cc28d0a9a6f0827d01611f979)
-   [copysignl\(\)](#gae60d4866e88abf023d92d33c6351ae6f)
-   [cos\(\)](#ga5e7b53a694b3cf0f2d7debd444140fbd)
-   [cosf\(\)](#ga7b126b2344591e649c21c9ab0b8adb40)
-   [cosh\(\)](#ga3795d3c1f1d30819be56da4e4d67f64b)
-   [coshf\(\)](#ga498b368486b7ce8677820beeb78d8f66)
-   [coshl\(\)](#ga57602cd20f8de2dceea4f05ffb516d82)
-   [cosl\(\)](#ga659287f7399efa8d6bc66dc37c8e35f4)
-   [cpow\(\)](#ga6fd1bd16c6de991f95a4e19e0f2f2a12)
-   [cpowf\(\)](#ga58beb4a3ea7b6ab6bb942900f94179fa)
-   [cpowl\(\)](#gae3ae7292dac86eeec3bb9a06b66f61cb)
-   [cproj\(\)](#gac10f86edf0994d0ee834768633be644e)
-   [cprojf\(\)](#ga9f435a71e44dd1e13eca358e2ca530e6)
-   [cprojl\(\)](#ga2cc437f3ab8e77dbd8fb024c66474915)
-   [creal\(\)](#ga24b1a511efdb973354d81646c5c3bb81)
-   [crealf\(\)](#gad052a3eb4d9f32153173e6bcea9e42ce)
-   [creall\(\)](#ga4ee2baa54a4e51877c59527d2be1a0da)
-   [csin\(\)](#ga1b9030685d326e66a93a35ca8c4bb0f6)
-   [csinf\(\)](#ga76dc89521e12096bc2104c9c0dcc20ea)
-   [csinh\(\)](#ga0c782aa9258a4e11cc3ea57b2dcccfef)
-   [csinhf\(\)](#ga268ba13d67a10e6667bd6b64a1a96351)
-   [csinhl\(\)](#ga0d14ae39cd9a811e42e36512fe6c7e53)
-   [csinl\(\)](#gad594fa6071ea5d383a0c7abaa0c32d80)
-   [csqrt\(\)](#ga7ff172d72bc0474b93e27470ce94494b)
-   [csqrtf\(\)](#gab8e425ba3e5d52d410afc3041bdeadce)
-   [csqrtl\(\)](#ga94a429c220e400a1a6781d6e11cbfafd)
-   [ctan\(\)](#ga665b5dfc1b1f51d3b444f049c6bd95dd)
-   [ctanf\(\)](#ga4301d608cc419f1ba3177fae4f258f30)
-   [ctanh\(\)](#ga9c5cf378e654f3aaed9fb0f5c8223585)
-   [ctanhf\(\)](#gad68db7f429f2104acf52b096c5efb69a)
-   [ctanhl\(\)](#ga2fbb0a9d578343f924c96faed3189805)
-   [ctanl\(\)](#ga7aa0362acd67521c9aac791aa617f953)
-   [erf\(\)](#gaa8b35382a71885eed509a5f87bf5e266)
-   [erfc\(\)](#ga0b6c4cfae41124da64c9a2dcc09e6045)
-   [erfcf\(\)](#gad948b9d3bfcb66c074ffe17326030d41)
-   [erfcl\(\)](#ga8ac2c9e0246c0c8106d04762a9623594)
-   [erff\(\)](#gaabebdd2dd548c14805831297ac129862)
-   [erfl\(\)](#ga6ccdcbbc2f0b22de2add8955e415170e)
-   [exp\(\)](#gae09128febbbe6372cde4fa0c65608a42)
-   [exp10\(\)](#gaea673cadd2aef111e2ee7a813776b768)
-   [exp10f\(\)](#gad27f10a0e30a7fe130c18786bf097e4b)
-   [exp10l\(\)](#ga28c11df4d7b29c9f59ac733fba51bece)
-   [exp2\(\)](#ga86e37219434c0b7978453b6ca88fc5fb)
-   [exp2f\(\)](#gaed26c6708ff2027f9a8214d206eef0e7)
-   [exp2l\(\)](#ga4618e032de8318b72df5cc71f15b5e45)
-   [expf\(\)](#ga0c2bc89b8355a89542ac98d9e2120363)
-   [expl\(\)](#gaed4eb11ef1397c751334311ce5b43920)
-   [expm1\(\)](#gae4963ac40f96d4b1fe8af1b1e90a20bb)
-   [expm1f\(\)](#ga5b8d8815f5c801fdbdb7f7767fbf9af4)
-   [expm1l\(\)](#ga702b0680671cf9ef94017ac04f77358b)
-   [fabs\(\)](#ga8fb5c0b9b43a108724b355136d29d2f9)
-   [fabsf\(\)](#ga9b02e2f3ebf257ac4f4d3ca1da6147d7)
-   [fabsl\(\)](#ga404c051ab9afd74c7ceed207683a235f)
-   [fdim\(\)](#ga800522810eaaed28bd53798bff4b0bfa)
-   [fdimf\(\)](#gaeee3a0bf2804c53c65199590ac4804cf)
-   [fdiml\(\)](#gab88ba65d1861deddbbc5cb5384d6a02e)
-   [finite\(\)](#ga08e754462e6ec13bc05fd41cff9cdd4a)
-   [finitef\(\)](#gaea39ac813876c506f8c351e6c14a5cb7)
-   [floor\(\)](#ga6de60a3e907dcf0bfe3ea8d64f1e8873)
-   [floorf\(\)](#ga0bcc6aa4b3c37bfa73f06ebdecc0d247)
-   [floorl\(\)](#ga211df53cdf5208b9bbfa92e2d9aef97f)
-   [fma\(\)](#gac6df7bd41d198a70da3915a80de5452d)
-   [fmaf\(\)](#gaa6b32a0b7f88680bb59bcfb9c6168ed2)
-   [fmal\(\)](#gaf30b6b26252979964796ffa55dd30120)
-   [fmax\(\)](#ga35e041615ac931b4d848a7b173049301)
-   [fmaxf\(\)](#ga8849bfdbec18ded429fad4772cf60f4b)
-   [fmaxl\(\)](#ga0e31e170115494fdc03b6556844232f3)
-   [fmin\(\)](#gaf0a18b3ac9e461ac48b4cfffb4945a84)
-   [fminf\(\)](#ga9b4132c27f31d39c91c3c6063f378103)
-   [fminl\(\)](#ga8a301190384886aa4e327db265fb5c9f)
-   [fmod\(\)](#ga537296d1a8f9fb621676038b99ba7edf)
-   [fmodf\(\)](#gaf17ec425baca2b5f3882a05b5e19dfb5)
-   [fmodl\(\)](#gaa927d9996fb40db42bd3a6cbe57da9a7)
-   [frexp\(\)](#gae3fa88adf02f16a693f3dccea3c42ef0)
-   [frexpf\(\)](#ga12c36e745d8a9eb4f01c7e0eeb426dd3)
-   [frexpl\(\)](#ga239d50c0595ff8538b9aa3186ac4fd29)
-   [hypot\(\)](#ga6d6a905f61d535f8454190433b8c0ea5)
-   [hypotf\(\)](#ga9fa4a03d7c4abfda7d9ad7b6ff7f6456)
-   [hypotl\(\)](#ga92a0e76d17c34fc1b3b2e7c0868aea6e)
-   [ilogb\(\)](#ga600dd249210d15af31b9a29c2d09d255)
-   [ilogbf\(\)](#gaf53f0f07bb80b1a38fb47773a190e7a7)
-   [ilogbl\(\)](#gafbd166ed232a372f090b8f9fa8441423)
-   [j0\(\)](#gaffb00730a1127dee798137075951ae21)
-   [j0f\(\)](#gafa59b98550749c27995dfb7c70e6783a)
-   [j1\(\)](#ga8cac4aa70c418eba481417f1878b4cee)
-   [j1f\(\)](#ga4b50bbed127a1c57940d600498a3c5c7)
-   [jn\(\)](#gadeff843dc8106ffda5caba6df44c591d)
-   [jnf\(\)](#gac3fcdfd92a775eed4ebd673d7da02525)
-   [ldexp\(\)](#gab3662815756f0bd419dc1b12f4ad905d)
-   [ldexpf\(\)](#gaacd370a7830c29f47239dea1ea2eb7f9)
-   [ldexpl\(\)](#ga454187039ef790629dab1e7724c3c3b2)
-   [lgamma\(\)](#gacd3ebe923fa039624f0b7de3320816bf)
-   [lgammaf\(\)](#ga5900f7bf0093757f1ba36b5940b1e10b)
-   [lgammal\(\)](#ga4dafd3eb6952c8daabe8a98f4a64a7df)
-   [lgammal\_r\(\)](#ga278e86e217081a0268107f0d6876cb9b)
-   [llrint\(\)](#ga64a4201c82f6ee7043a270bbbc6a5e19)
-   [llrintf\(\)](#ga33d95711621def731d3f88c4e606323e)
-   [llrintl\(\)](#ga20e0da115f76608eff4695177f2f605a)
-   [llround\(\)](#ga3e4957daeecea4e616ed1f1870fe4f31)
-   [llroundf\(\)](#ga8259999687e8bd4b5509ca0d69b0ad9d)
-   [llroundl\(\)](#ga82a6d70a29e839514b93bb0699f07bbe)
-   [log\(\)](#gadb302c9aafbaa5e180d9f60ee954bb82)
-   [log10\(\)](#ga6572e82a4891917a9ba7fb2a964f8182)
-   [log10f\(\)](#gae207b1eb007a6c23394dcb6fc7f16adf)
-   [log10l\(\)](#gae824e49a04221dcf66b9791c5df8d6b6)
-   [log1p\(\)](#gac2aac20ab1347498e6e4f209148fea84)
-   [log1pf\(\)](#gacbf820b74779ce35a3c726a3a62bc8ef)
-   [log1pl\(\)](#ga2a632effaace01f30cba42725ae48dfa)
-   [log2\(\)](#ga38bd88274dc5594b4826fd60c8054c8e)
-   [log2f\(\)](#ga79fe62234001b88317245f7599158aaf)
-   [log2l\(\)](#gaa383ae0cab6c24f1bcba661dee0fbd70)
-   [logb\(\)](#gaa34bf5be5c3dab058c532adc2792113c)
-   [logbf\(\)](#ga6939b8381c2f160d26913646ca7ab6c4)
-   [logbl\(\)](#ga2f9c0448126d1a838624e3460217bb84)
-   [logf\(\)](#ga8246b3e17a39b137d0c62670d0c6e336)
-   [logl\(\)](#gaf67da1c28ce33b403f955103f201dfb8)
-   [lrint\(\)](#ga3337db086394bad101bd8d42d891640a)
-   [lrintf\(\)](#ga16173bca19eef93d0230bfb7c86b5740)
-   [lrintl\(\)](#gac6d217e9b96a145f5eeb2a490e6496e6)
-   [lround\(\)](#ga5936ef27aa03815e9c17d557e87a33d7)
-   [lroundf\(\)](#ga0136619b503ddb8ce1a226cd34c9538c)
-   [lroundl\(\)](#gafa865c5b70c9311f0f8701a1af60c715)
-   [modf\(\)](#gafcfe25b77e975450988866fea9d3c9f0)
-   [modff\(\)](#gad8314f66dfe8603f3a166eb466261ce1)
-   [modfl\(\)](#gabacf3b74f8d7e30a70da8ae47c8e4e3e)
-   [nan\(\)](#gaa4ee2f416f261bbd71cda3193c4884c9)
-   [nanf\(\)](#ga7fe43d4c86419daea2c133e8c5c1a17d)
-   [nanl\(\)](#gac92b1a3a1073a630ae0b7084e596d40f)
-   [nearbyint\(\)](#ga61ba6b3078ccbd5aac518e6ca2a757bd)
-   [nearbyintf\(\)](#gab3be3fdcb83a6d7cbd10aa5d891f88bf)
-   [nearbyintl\(\)](#ga4b51faf338f7d4f31224d0c096a8859b)
-   [nextafter\(\)](#gabed1b7ee913471448c2dbe58dff28db3)
-   [nextafterf\(\)](#ga57d2446286a54227595950a2118b349b)
-   [nextafterl\(\)](#ga38691f2f734e77206e4336cdcddd0e5b)
-   [nexttoward\(\)](#gaeb7afe6d08d8daec35aa282c63d7647e)
-   [nexttowardf\(\)](#ga634a1dabb08aa5a4fa6897920eff3c1d)
-   [nexttowardl\(\)](#ga3930cfe4df009d7221db329b910d6e30)
-   [pow\(\)](#gaa56c9494c95edf68386375e97d64159b)
-   [pow10\(\)](#gafbbc60a3627a8de4845c7e99e6134ec8)
-   [pow10f\(\)](#ga2cb598503b85d66abf59e9da06478f1a)
-   [pow10l\(\)](#ga9baf71e9033dd73a9c225a2fc9cca61d)
-   [powf\(\)](#gac6b287549be087f6f0bf03b6fe30499e)
-   [powl\(\)](#ga2f4830e468138e1513b55ca6a92a0f9a)
-   [remainder\(\)](#gaf7df01c4a9038dbf3562b41bc8c3be03)
-   [remainderf\(\)](#ga370ff5cfa842822bfd8ea0a93d441a33)
-   [remainderl\(\)](#gabadbe61e166bbf3031b979661f0e8336)
-   [remquo\(\)](#gac836dc6a979229173eb3d6e2744d82de)
-   [remquof\(\)](#ga15ec704e1894cfa573ac37a65afe009a)
-   [remquol\(\)](#gaacadcc57a95279058f29e657dce4d285)
-   [rint\(\)](#gae1f9edd5049d3ff63b0373a3c15c38c1)
-   [rintf\(\)](#ga48f9341b9310fefa5dd1b0c8c84c99df)
-   [rintl\(\)](#gaedc37bf10d69d2efa2a478f5f5d4b26b)
-   [round\(\)](#ga7df19cf730447c00150569250a4b5e1d)
-   [roundf\(\)](#gade09185c0cf8101fa9e2f25c15041b81)
-   [roundl\(\)](#ga6565127c023ae8f392ce69e3b3f30aa1)
-   [scalb\(\)](#ga14db57dcd8982430d12219bbecd08a05)
-   [scalbf\(\)](#ga9c9db25d2ff9973e0d8638cf42df3999)
-   [scalbln\(\)](#ga947d3d0739c0dc7c46d1eec778d4b6af)
-   [scalblnf\(\)](#ga1aa3cc34e8f84a2a09400c25c578100d)
-   [scalblnl\(\)](#gaeb098df94536b520ced9df59fd353848)
-   [scalbn\(\)](#gaa2fbea1fca1faaebedf2deec71c47189)
-   [scalbnf\(\)](#ga3849b86bb2f39ebccb79b91745f7883f)
-   [scalbnl\(\)](#ga284717e9eceed5bc33389ce33170f907)
-   [significand\(\)](#gafad3bf1f77c516fb8891c72beb51640f)
-   [significandf\(\)](#gac57d7d88e1a9b57c9a129ee4d4a68c42)
-   [sin\(\)](#gaad4af25633b071b0e2cdb8ebd87eca77)
-   [sincos\(\)](#gaf4509ae544cecab0e9a61efdfccb7530)
-   [sincosf\(\)](#gac59adab35511be68e92ad9013d63e866)
-   [sincosl\(\)](#gaf877b78dbe8e265bdf4b975dbc713482)
-   [sinf\(\)](#ga8a7dc2a88e109f4e15b661247665709a)
-   [sinh\(\)](#ga862012e970c977c482507064e2793b45)
-   [sinhf\(\)](#ga1976c7577fb97800f4b926bd042b64ac)
-   [sinhl\(\)](#gad160d5d1bb3f113e96135a4bebe76abe)
-   [sinl\(\)](#gaeb537bfea71fa91192234a666f3a6a25)
-   [sqrt\(\)](#gab87521a75ef827a85807f89a6c10629a)
-   [sqrtf\(\)](#ga46c9a8d40cde7c4d5ab40a67e55316bb)
-   [sqrtl\(\)](#ga9c028a87917b3bb9bba9e75f66cdbd43)
-   [tan\(\)](#gaa48fdfd5eea5f4f9c33496402b9e4039)
-   [tanf\(\)](#ga67d5bfe80effce6adebf5fcbc5a7dae0)
-   [tanh\(\)](#gaf85bcf153d7ae805733927f12329dac1)
-   [tanhf\(\)](#ga74e8f87bb37a338d2cebbb6b1d696593)
-   [tanhl\(\)](#ga94ee8c57b6b2d0bc5466c75bea2bffcf)
-   [tanl\(\)](#ga2151fba6c1e9b4fa5d2af2dcb5c68b17)
-   [tgamma\(\)](#ga54afbf509eea5e9d6f9efdebc572339a)
-   [tgammaf\(\)](#ga2ab69de9110cc2c62ca78b5d20a3a3ae)
-   [tgammal\(\)](#ga8eff39a57115761c5025e08ff2e08c6a)
-   [trunc\(\)](#ga82a151adfde56b28fa8a50355c4f2ff6)
-   [truncf\(\)](#gaa8bb2049c170c9ac5b131fdba029991a)
-   [truncl\(\)](#ga8f9695496a9bb839eb5f728b6bf0c856)
-   [y0\(\)](#gafca57fd80386476e5cd1dd52173103c5)
-   [y0f\(\)](#gaba3cd2d73c1ae75ec2d01ebb2dfc108c)
-   [y1\(\)](#ga369368526a105f3fba6776b11586070c)
-   [y1f\(\)](#ga5f37c38e8985dafae6abca2d1782c160)
-   [yn\(\)](#gae31b4c8c6af724eaa73ad2ebce1aa3ce)
-   [ynf\(\)](#ga47f8750942b731456dd7f2cbf5f55806)

## **Overview**<a name="section1668727741165622"></a>

**Description:**

Provides math functions, such as trigonometric, exponential, logarithmic functions,and perform operations on complex numbers. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2135939735165622"></a>

## Files<a name="files"></a>

<a name="table1560639071165622"></a>
<table><thead align="left"><tr id="row1408870775165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p430764921165622"><a name="p430764921165622"></a><a name="p430764921165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p307524919165622"><a name="p307524919165622"></a><a name="p307524919165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row402634070165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p569398329165622"><a name="p569398329165622"></a><a name="p569398329165622"></a><a href="complex-h.md">complex.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1066220807165622"><a name="p1066220807165622"></a><a name="p1066220807165622"></a>Declares functions to perform operations on complex numbers. </p>
</td>
</tr>
<tr id="row804022087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p450553347165622"><a name="p450553347165622"></a><a name="p450553347165622"></a><a href="fenv-h.md">fenv.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904146516165622"><a name="p904146516165622"></a><a name="p904146516165622"></a>Declares specific functions for performing operations for floating-point exceptions and rounding modes. </p>
</td>
</tr>
<tr id="row765117710165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1486291705165622"><a name="p1486291705165622"></a><a name="p1486291705165622"></a><a href="math-h.md">math.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1148987436165622"><a name="p1148987436165622"></a><a name="p1148987436165622"></a>Provides common math functions. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1782715185165622"></a>
<table><thead align="left"><tr id="row75523812165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2107377135165622"><a name="p2107377135165622"></a><a name="p2107377135165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2111970708165622"><a name="p2111970708165622"></a><a name="p2111970708165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1620346254165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190357181165622"><a name="p190357181165622"></a><a name="p190357181165622"></a><a href="fenv_t.md">fenv_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450473872165622"><a name="p450473872165622"></a><a name="p450473872165622"></a>Defines the floating-point environment. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table146622810165622"></a>
<table><thead align="left"><tr id="row1719644338165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p789975301165622"><a name="p789975301165622"></a><a name="p789975301165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1182849128165622"><a name="p1182849128165622"></a><a name="p1182849128165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1277994423165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1589681300165622"><a name="p1589681300165622"></a><a name="p1589681300165622"></a><em id="ga0fa4878c968311979d497ccc322e0b9b"><a name="ga0fa4878c968311979d497ccc322e0b9b"></a><a name="ga0fa4878c968311979d497ccc322e0b9b"></a></em>complex    _Complex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p363154856165622"><a name="p363154856165622"></a><a name="p363154856165622"></a>Indicates the type of a complex number. </p>
</td>
</tr>
<tr id="row2081446008165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447966615165622"><a name="p1447966615165622"></a><a name="p1447966615165622"></a><em id="ga638c8489adb1fac7204b07ece42998ae"><a name="ga638c8489adb1fac7204b07ece42998ae"></a><a name="ga638c8489adb1fac7204b07ece42998ae"></a></em>FE_INVALID    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p866264710165622"><a name="p866264710165622"></a><a name="p866264710165622"></a>Indicates an invalid floating-point exception. At least one parameter value is not defined in the function. </p>
</td>
</tr>
<tr id="row663287299165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724370840165622"><a name="p724370840165622"></a><a name="p724370840165622"></a><em id="gab1317930189d1a14841893fb4bd9b5a0"><a name="gab1317930189d1a14841893fb4bd9b5a0"></a><a name="gab1317930189d1a14841893fb4bd9b5a0"></a></em>FE_DIVBYZERO    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502863752165622"><a name="p1502863752165622"></a><a name="p1502863752165622"></a>Indicates a pole error exception. The return value is asymptotically infinite when the divisor is zero or the input is asymptotic to zero. </p>
</td>
</tr>
<tr id="row2145741751165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p717945889165622"><a name="p717945889165622"></a><a name="p717945889165622"></a><em id="gad373306add36e7227d9c9620b6962323"><a name="gad373306add36e7227d9c9620b6962323"></a><a name="gad373306add36e7227d9c9620b6962323"></a></em>FE_OVERFLOW    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1986062909165622"><a name="p1986062909165622"></a><a name="p1986062909165622"></a>Indicates an overflow floating-point exception. The result is too large to be represented in the normal return value. </p>
</td>
</tr>
<tr id="row1104018656165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178589264165622"><a name="p178589264165622"></a><a name="p178589264165622"></a><em id="ga57b80dfe7d5ce60c3c76e517fce89ffe"><a name="ga57b80dfe7d5ce60c3c76e517fce89ffe"></a><a name="ga57b80dfe7d5ce60c3c76e517fce89ffe"></a></em>FE_UNDERFLOW    8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394706602165622"><a name="p1394706602165622"></a><a name="p1394706602165622"></a>Indicates an underflow floating-point exception. The result is too small to be represented in the normal return value. </p>
</td>
</tr>
<tr id="row1536188596165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406322504165622"><a name="p1406322504165622"></a><a name="p1406322504165622"></a><em id="ga6e24165ff28571734b3e14530219faab"><a name="ga6e24165ff28571734b3e14530219faab"></a><a name="ga6e24165ff28571734b3e14530219faab"></a></em>FE_INEXACT    16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782884844165622"><a name="p782884844165622"></a><a name="p782884844165622"></a>Indicates an inexact floating-point exception. </p>
</td>
</tr>
<tr id="row478747218165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p849293731165622"><a name="p849293731165622"></a><a name="p849293731165622"></a><em id="ga09e405b3782b934813075e48366dda9a"><a name="ga09e405b3782b934813075e48366dda9a"></a><a name="ga09e405b3782b934813075e48366dda9a"></a></em>FE_ALL_EXCEPT    31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1434576235165622"><a name="p1434576235165622"></a><a name="p1434576235165622"></a>Indicates bitwise OR of all the preceding supported floating-point exceptions. </p>
</td>
</tr>
<tr id="row2138850437165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2112222441165622"><a name="p2112222441165622"></a><a name="p2112222441165622"></a><em id="ga5b5383719a63f98b7c95cc2feccaa1a7"><a name="ga5b5383719a63f98b7c95cc2feccaa1a7"></a><a name="ga5b5383719a63f98b7c95cc2feccaa1a7"></a></em>FE_TONEAREST    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2122765255165622"><a name="p2122765255165622"></a><a name="p2122765255165622"></a>Indicates rounding towards the nearest integer. </p>
</td>
</tr>
<tr id="row1256789001165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p527600180165622"><a name="p527600180165622"></a><a name="p527600180165622"></a><em id="ga5e011a345a41ad4622da05932e83536f"><a name="ga5e011a345a41ad4622da05932e83536f"></a><a name="ga5e011a345a41ad4622da05932e83536f"></a></em>FE_DOWNWARD    0x800000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647450204165622"><a name="p647450204165622"></a><a name="p647450204165622"></a>Indicates rounding towards negative infinity. </p>
</td>
</tr>
<tr id="row2093448280165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927068106165622"><a name="p927068106165622"></a><a name="p927068106165622"></a><em id="ga5aa71a164a4b4d7780570d97058890f1"><a name="ga5aa71a164a4b4d7780570d97058890f1"></a><a name="ga5aa71a164a4b4d7780570d97058890f1"></a></em>FE_UPWARD    0x400000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p841783447165622"><a name="p841783447165622"></a><a name="p841783447165622"></a>Indicates rounding towards positive infinity. </p>
</td>
</tr>
<tr id="row1634806316165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1702571979165622"><a name="p1702571979165622"></a><a name="p1702571979165622"></a><em id="gac171099e006285a9e8be5683be71591c"><a name="gac171099e006285a9e8be5683be71591c"></a><a name="gac171099e006285a9e8be5683be71591c"></a></em>FE_TOWARDZERO    0xc00000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449281604165622"><a name="p1449281604165622"></a><a name="p1449281604165622"></a>Indicates rounding towards zero. </p>
</td>
</tr>
<tr id="row2110543222165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p184369836165622"><a name="p184369836165622"></a><a name="p184369836165622"></a><em id="ga5777a3689f7f4c555df1c643d28b5bc0"><a name="ga5777a3689f7f4c555df1c643d28b5bc0"></a><a name="ga5777a3689f7f4c555df1c643d28b5bc0"></a></em>FE_DFL_ENV    ((const <a href="fenv_t.md">fenv_t</a> *) -1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299661615165622"><a name="p299661615165622"></a><a name="p299661615165622"></a>Defines the default floating-point environment. </p>
</td>
</tr>
<tr id="row1695739016165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817443974165622"><a name="p1817443974165622"></a><a name="p1817443974165622"></a><em id="ga8abfcc76130f3f991d124dd22d7e69bc"><a name="ga8abfcc76130f3f991d124dd22d7e69bc"></a><a name="ga8abfcc76130f3f991d124dd22d7e69bc"></a></em>NAN    (0.0f/0.0f)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p752673564165622"><a name="p752673564165622"></a><a name="p752673564165622"></a>Indicates an undefined or unrepresentable value. </p>
</td>
</tr>
<tr id="row2026445491165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p676885187165622"><a name="p676885187165622"></a><a name="p676885187165622"></a><em id="ga956e2723d559858d08644ac99146e910"><a name="ga956e2723d559858d08644ac99146e910"></a><a name="ga956e2723d559858d08644ac99146e910"></a></em>INFINITY    1e5000f</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p829819556165622"><a name="p829819556165622"></a><a name="p829819556165622"></a>Indicates an infinity. </p>
</td>
</tr>
<tr id="row1707824670165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p592945981165622"><a name="p592945981165622"></a><a name="p592945981165622"></a><em id="gacd69981d54c27fe0ff514645dbfc6359"><a name="gacd69981d54c27fe0ff514645dbfc6359"></a><a name="gacd69981d54c27fe0ff514645dbfc6359"></a></em>HUGE_VALF    <a href="math.md#ga956e2723d559858d08644ac99146e910">INFINITY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1551050912165622"><a name="p1551050912165622"></a><a name="p1551050912165622"></a>Indicates a float infinity. </p>
</td>
</tr>
<tr id="row1112366411165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140513499165622"><a name="p1140513499165622"></a><a name="p1140513499165622"></a><em id="gaf2164b2db92d8a0ed3838ad5c28db971"><a name="gaf2164b2db92d8a0ed3838ad5c28db971"></a><a name="gaf2164b2db92d8a0ed3838ad5c28db971"></a></em>HUGE_VAL    ((double)<a href="math.md#ga956e2723d559858d08644ac99146e910">INFINITY</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p901645296165622"><a name="p901645296165622"></a><a name="p901645296165622"></a>Indicates a double infinity. </p>
</td>
</tr>
<tr id="row57250484165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207016508165622"><a name="p1207016508165622"></a><a name="p1207016508165622"></a><em id="gab8b359c356d4311bf5d4ae6c03f43182"><a name="gab8b359c356d4311bf5d4ae6c03f43182"></a><a name="gab8b359c356d4311bf5d4ae6c03f43182"></a></em>HUGE_VALL    ((long double)<a href="math.md#ga956e2723d559858d08644ac99146e910">INFINITY</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p577160841165622"><a name="p577160841165622"></a><a name="p577160841165622"></a>Indicates a long double infinity. </p>
</td>
</tr>
<tr id="row1824347608165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385154111165622"><a name="p385154111165622"></a><a name="p385154111165622"></a><em id="ga42b212d215eab7142f8272fefcd1c938"><a name="ga42b212d215eab7142f8272fefcd1c938"></a><a name="ga42b212d215eab7142f8272fefcd1c938"></a></em>MATH_ERRNO    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p305726276165622"><a name="p305726276165622"></a><a name="p305726276165622"></a>Indicates an error that occurs in floating-point operations. </p>
</td>
</tr>
<tr id="row939712180165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p689773765165622"><a name="p689773765165622"></a><a name="p689773765165622"></a><em id="gae05ce3fe3745507c8e989f6e9efe0a83"><a name="gae05ce3fe3745507c8e989f6e9efe0a83"></a><a name="gae05ce3fe3745507c8e989f6e9efe0a83"></a></em>MATH_ERREXCEPT    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072907331165622"><a name="p1072907331165622"></a><a name="p1072907331165622"></a>Indicates a floating-point exception. </p>
</td>
</tr>
<tr id="row1560619129165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252594970165622"><a name="p1252594970165622"></a><a name="p1252594970165622"></a><em id="gaa8618aec27dedcd32f494ccf22f3ed42"><a name="gaa8618aec27dedcd32f494ccf22f3ed42"></a><a name="gaa8618aec27dedcd32f494ccf22f3ed42"></a></em>math_errhandling    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936466042165622"><a name="p1936466042165622"></a><a name="p1936466042165622"></a>Indicates the error handling mechanism employed by math functions. </p>
</td>
</tr>
<tr id="row311290604165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247850242165622"><a name="p247850242165622"></a><a name="p247850242165622"></a><em id="ga01e2e5be97c739a5bdcbc619b44f9742"><a name="ga01e2e5be97c739a5bdcbc619b44f9742"></a><a name="ga01e2e5be97c739a5bdcbc619b44f9742"></a></em>FP_ILOGBNAN    (-1-0x7fffffff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2057823177165622"><a name="p2057823177165622"></a><a name="p2057823177165622"></a>Indicates the calculation result of <a href="math.md#ga600dd249210d15af31b9a29c2d09d255">ilogb</a>(<a href="math.md#ga8abfcc76130f3f991d124dd22d7e69bc">NAN</a>). </p>
</td>
</tr>
<tr id="row182453964165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1293977575165622"><a name="p1293977575165622"></a><a name="p1293977575165622"></a><em id="ga9ec0e31304d15c42262b2c4a3b58443c"><a name="ga9ec0e31304d15c42262b2c4a3b58443c"></a><a name="ga9ec0e31304d15c42262b2c4a3b58443c"></a></em>FP_ILOGB0    <a href="math.md#ga01e2e5be97c739a5bdcbc619b44f9742">FP_ILOGBNAN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523163674165622"><a name="p523163674165622"></a><a name="p523163674165622"></a>Indicates the calculation result of <a href="math.md#ga600dd249210d15af31b9a29c2d09d255">ilogb</a>(0). </p>
</td>
</tr>
<tr id="row401370987165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1612417726165622"><a name="p1612417726165622"></a><a name="p1612417726165622"></a><em id="ga1d481cc6e6a8ff729147ed46e61a4c9f"><a name="ga1d481cc6e6a8ff729147ed46e61a4c9f"></a><a name="ga1d481cc6e6a8ff729147ed46e61a4c9f"></a></em>FP_NAN    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559135234165622"><a name="p559135234165622"></a><a name="p559135234165622"></a>Indicates a Not-a-Number (NaN) value. </p>
</td>
</tr>
<tr id="row1216561854165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709686338165622"><a name="p1709686338165622"></a><a name="p1709686338165622"></a><em id="ga4f64bcc64f8b84dd9daf5a4e56abf0ca"><a name="ga4f64bcc64f8b84dd9daf5a4e56abf0ca"></a><a name="ga4f64bcc64f8b84dd9daf5a4e56abf0ca"></a></em>FP_INFINITE    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650376945165622"><a name="p1650376945165622"></a><a name="p1650376945165622"></a>Indicates an infinity. </p>
</td>
</tr>
<tr id="row289173797165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614531437165622"><a name="p614531437165622"></a><a name="p614531437165622"></a><em id="ga32eba50da417c9f303ba49583d5b9f40"><a name="ga32eba50da417c9f303ba49583d5b9f40"></a><a name="ga32eba50da417c9f303ba49583d5b9f40"></a></em>FP_ZERO    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837107072165622"><a name="p1837107072165622"></a><a name="p1837107072165622"></a>Indicates value <strong id="b545918857165622"><a name="b545918857165622"></a><a name="b545918857165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1703446007165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p839980797165622"><a name="p839980797165622"></a><a name="p839980797165622"></a><em id="gadbc0a13ec75c05d238ca12ef1f8c6b2b"><a name="gadbc0a13ec75c05d238ca12ef1f8c6b2b"></a><a name="gadbc0a13ec75c05d238ca12ef1f8c6b2b"></a></em>FP_SUBNORMAL    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167777556165622"><a name="p167777556165622"></a><a name="p167777556165622"></a>Indicates a subnormal. </p>
</td>
</tr>
<tr id="row523296343165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1199863387165622"><a name="p1199863387165622"></a><a name="p1199863387165622"></a><em id="gab9e29bb9e853934c4ba647c840b7e5de"><a name="gab9e29bb9e853934c4ba647c840b7e5de"></a><a name="gab9e29bb9e853934c4ba647c840b7e5de"></a></em>FP_NORMAL    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1290510757165622"><a name="p1290510757165622"></a><a name="p1290510757165622"></a>Indicates a normal value. </p>
</td>
</tr>
<tr id="row144316581165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2027369597165622"><a name="p2027369597165622"></a><a name="p2027369597165622"></a><a href="math.md#ga2a266c767456556e5c0da234b602b18b">isinf</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620222322165622"><a name="p1620222322165622"></a><a name="p1620222322165622"></a>Checks whether the floating-point value <strong id="b1281767711165622"><a name="b1281767711165622"></a><a name="b1281767711165622"></a>x</strong> is an infinity. </p>
</td>
</tr>
<tr id="row475327360165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1915374399165622"><a name="p1915374399165622"></a><a name="p1915374399165622"></a><a href="math.md#ga2e1baae9134e580910322362dc23290e">isnan</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699561915165622"><a name="p1699561915165622"></a><a name="p1699561915165622"></a>Checks whether the floating-point value <strong id="b476936615165622"><a name="b476936615165622"></a><a name="b476936615165622"></a>x</strong> is a NaN value. </p>
</td>
</tr>
<tr id="row1579283080165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p476158215165622"><a name="p476158215165622"></a><a name="p476158215165622"></a><a href="math.md#gad83f5949c4b5d810225b9a834840bac9">isnormal</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1032256540165622"><a name="p1032256540165622"></a><a name="p1032256540165622"></a>Checks whether the floating-point value <strong id="b2008071136165622"><a name="b2008071136165622"></a><a name="b2008071136165622"></a>x</strong> is a normal value. </p>
</td>
</tr>
<tr id="row793341773165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p748030809165622"><a name="p748030809165622"></a><a name="p748030809165622"></a><a href="math.md#ga256d70a32c03904ce13c999c1e9dc35d">isfinite</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1119514915165622"><a name="p1119514915165622"></a><a name="p1119514915165622"></a>Checks whether the floating-point value <strong id="b1639910704165622"><a name="b1639910704165622"></a><a name="b1639910704165622"></a>x</strong> is finite. </p>
</td>
</tr>
<tr id="row1234307776165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p639735629165622"><a name="p639735629165622"></a><a name="p639735629165622"></a><a href="math.md#gaa63ffa98f213f62e536b073c28cb3cd8">signbit</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p347860165165622"><a name="p347860165165622"></a><a name="p347860165165622"></a>Checks whether the sign of the floating-point value <strong id="b58239432165622"><a name="b58239432165622"></a><a name="b58239432165622"></a>x</strong> is negative. </p>
</td>
</tr>
<tr id="row8452753165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229169143165622"><a name="p229169143165622"></a><a name="p229169143165622"></a><a href="math.md#ga33daf51eb7138d477e0b0985c51e4fad">isunordered</a>(x, y)   (<a href="math.md#ga2e1baae9134e580910322362dc23290e">isnan</a>((x)) ? ((void)(y),1) : <a href="math.md#ga2e1baae9134e580910322362dc23290e">isnan</a>((y)))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688688641165622"><a name="p1688688641165622"></a><a name="p1688688641165622"></a>Checks whether floating-point value <strong id="b1942479407165622"><a name="b1942479407165622"></a><a name="b1942479407165622"></a>x</strong> or <strong id="b405189902165622"><a name="b405189902165622"></a><a name="b405189902165622"></a>y</strong> is unordered. </p>
</td>
</tr>
<tr id="row1125917109165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1575322743165622"><a name="p1575322743165622"></a><a name="p1575322743165622"></a><a href="math.md#ga61079b32084130da4345c2eea93e0d61">isless</a>(x, y)   __tg_pred_2(x, y, __isless)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p420902322165622"><a name="p420902322165622"></a><a name="p420902322165622"></a>Checks whether floating-point value <strong id="b1501984782165622"><a name="b1501984782165622"></a><a name="b1501984782165622"></a>x</strong> is less than <strong id="b229330891165622"><a name="b229330891165622"></a><a name="b229330891165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1201033884165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339022856165622"><a name="p1339022856165622"></a><a name="p1339022856165622"></a><a href="math.md#gabf3cb1e5a0aaa1c42dffa9ebb1d78c30">islessequal</a>(x, y)   __tg_pred_2(x, y, __islessequal)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712767387165622"><a name="p1712767387165622"></a><a name="p1712767387165622"></a>Checks whether floating-point value <strong id="b2029662030165622"><a name="b2029662030165622"></a><a name="b2029662030165622"></a>x</strong> is less than or equal to <strong id="b1874647355165622"><a name="b1874647355165622"></a><a name="b1874647355165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1175505632165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566855643165622"><a name="p566855643165622"></a><a name="p566855643165622"></a><a href="math.md#ga5e534756b747fd2e9ee19f8fdd93b30b">islessgreater</a>(x, y)   __tg_pred_2(x, y, __islessgreater)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249659975165622"><a name="p1249659975165622"></a><a name="p1249659975165622"></a>Checks whether floating-point value <strong id="b1363146979165622"><a name="b1363146979165622"></a><a name="b1363146979165622"></a>x</strong> is either less than or greater than <strong id="b2027693684165622"><a name="b2027693684165622"></a><a name="b2027693684165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1292373558165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1400415447165622"><a name="p1400415447165622"></a><a name="p1400415447165622"></a><a href="math.md#gada788e9d6ce0ca927874ec4e53af1f77">isgreater</a>(x, y)   __tg_pred_2(x, y, __isgreater)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840327712165622"><a name="p840327712165622"></a><a name="p840327712165622"></a>Checks whether floating-point value <strong id="b1135180371165622"><a name="b1135180371165622"></a><a name="b1135180371165622"></a>x</strong> is greater than <strong id="b1908302651165622"><a name="b1908302651165622"></a><a name="b1908302651165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1268841170165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1610318519165622"><a name="p1610318519165622"></a><a name="p1610318519165622"></a><a href="math.md#ga5a7f86a4d3e6139e4913e2e8eba52612">isgreaterequal</a>(x, y)   __tg_pred_2(x, y, __isgreaterequal)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1514530672165622"><a name="p1514530672165622"></a><a name="p1514530672165622"></a>Checks whether floating-point value <strong id="b1832069493165622"><a name="b1832069493165622"></a><a name="b1832069493165622"></a>x</strong> is greater than or equal to <strong id="b1591688964165622"><a name="b1591688964165622"></a><a name="b1591688964165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row133015871165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p350464618165622"><a name="p350464618165622"></a><a name="p350464618165622"></a><em id="ga5e9e29217f6ec61105a4520ec5942225"><a name="ga5e9e29217f6ec61105a4520ec5942225"></a><a name="ga5e9e29217f6ec61105a4520ec5942225"></a></em>MAXFLOAT    3.40282346638528859812e+38F</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828372789165622"><a name="p1828372789165622"></a><a name="p1828372789165622"></a>Maximum value of type float. </p>
</td>
</tr>
<tr id="row1908490425165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847921575165622"><a name="p847921575165622"></a><a name="p847921575165622"></a><em id="ga9bf5d952c5c93c70f9e66c9794d406c9"><a name="ga9bf5d952c5c93c70f9e66c9794d406c9"></a><a name="ga9bf5d952c5c93c70f9e66c9794d406c9"></a></em>M_E    2.7182818284590452354 /* e */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610225699165622"><a name="p610225699165622"></a><a name="p610225699165622"></a>Base e of natural logarithms. </p>
</td>
</tr>
<tr id="row623474942165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049147830165622"><a name="p2049147830165622"></a><a name="p2049147830165622"></a><em id="gac5c747ee5bcbe892875672a0b9d8171c"><a name="gac5c747ee5bcbe892875672a0b9d8171c"></a><a name="gac5c747ee5bcbe892875672a0b9d8171c"></a></em>M_LOG2E    1.4426950408889634074 /* log_2 e */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2053084201165622"><a name="p2053084201165622"></a><a name="p2053084201165622"></a>Logarithm to base 2 of <strong id="b398998899165622"><a name="b398998899165622"></a><a name="b398998899165622"></a>M_E</strong> </p>
</td>
</tr>
<tr id="row275141341165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32508266165622"><a name="p32508266165622"></a><a name="p32508266165622"></a><em id="ga9ed2b5582226f3896424ff6d2a3ebb14"><a name="ga9ed2b5582226f3896424ff6d2a3ebb14"></a><a name="ga9ed2b5582226f3896424ff6d2a3ebb14"></a></em>M_LOG10E    0.43429448190325182765 /* log_10 e */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048908494165622"><a name="p2048908494165622"></a><a name="p2048908494165622"></a>Logarithm to base 10 of <strong id="b1253026429165622"><a name="b1253026429165622"></a><a name="b1253026429165622"></a>M_E</strong> </p>
</td>
</tr>
<tr id="row776087784165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578320837165622"><a name="p578320837165622"></a><a name="p578320837165622"></a><em id="ga92428112a5d24721208748774a4f23e6"><a name="ga92428112a5d24721208748774a4f23e6"></a><a name="ga92428112a5d24721208748774a4f23e6"></a></em>M_LN2    0.69314718055994530942 /* log_e 2 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088810674165622"><a name="p2088810674165622"></a><a name="p2088810674165622"></a>Natural logarithm of <strong id="b273536306165622"><a name="b273536306165622"></a><a name="b273536306165622"></a>2</strong> </p>
</td>
</tr>
<tr id="row696401081165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720899990165622"><a name="p720899990165622"></a><a name="p720899990165622"></a><em id="ga0a53871497a155afe91424c28a8ec3c4"><a name="ga0a53871497a155afe91424c28a8ec3c4"></a><a name="ga0a53871497a155afe91424c28a8ec3c4"></a></em>M_LN10    2.30258509299404568402 /* log_e 10 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202938359165622"><a name="p202938359165622"></a><a name="p202938359165622"></a>Natural logarithm of <strong id="b1221853607165622"><a name="b1221853607165622"></a><a name="b1221853607165622"></a>10</strong> </p>
</td>
</tr>
<tr id="row764635833165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1412834458165622"><a name="p1412834458165622"></a><a name="p1412834458165622"></a><em id="gae71449b1cc6e6250b91f539153a7a0d3"><a name="gae71449b1cc6e6250b91f539153a7a0d3"></a><a name="gae71449b1cc6e6250b91f539153a7a0d3"></a></em>M_PI    3.14159265358979323846 /* pi */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940679672165622"><a name="p1940679672165622"></a><a name="p1940679672165622"></a>Ratio of a circle's circumference to its diameter. </p>
</td>
</tr>
<tr id="row1186517631165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472962379165622"><a name="p472962379165622"></a><a name="p472962379165622"></a><em id="ga958e4508ed28ee5cc04249144312c15f"><a name="ga958e4508ed28ee5cc04249144312c15f"></a><a name="ga958e4508ed28ee5cc04249144312c15f"></a></em>M_PI_2    1.57079632679489661923 /* pi/2 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428460910165622"><a name="p1428460910165622"></a><a name="p1428460910165622"></a>Pi divided by <strong id="b218292867165622"><a name="b218292867165622"></a><a name="b218292867165622"></a>2</strong> </p>
</td>
</tr>
<tr id="row673155467165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1810465633165622"><a name="p1810465633165622"></a><a name="p1810465633165622"></a><em id="gaeb24420b096a677f3a2dc5a72b36bf22"><a name="gaeb24420b096a677f3a2dc5a72b36bf22"></a><a name="gaeb24420b096a677f3a2dc5a72b36bf22"></a></em>M_PI_4    0.78539816339744830962 /* pi/4 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1781701932165622"><a name="p1781701932165622"></a><a name="p1781701932165622"></a>Pi divided by <strong id="b50311016165622"><a name="b50311016165622"></a><a name="b50311016165622"></a>4</strong> </p>
</td>
</tr>
<tr id="row1242731702165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306986528165622"><a name="p1306986528165622"></a><a name="p1306986528165622"></a><em id="ga08dfac3cca9601a02fc88356cc078e1d"><a name="ga08dfac3cca9601a02fc88356cc078e1d"></a><a name="ga08dfac3cca9601a02fc88356cc078e1d"></a></em>M_1_PI    0.31830988618379067154 /* 1/pi */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p868692011165622"><a name="p868692011165622"></a><a name="p868692011165622"></a>Reciprocal of pi. </p>
</td>
</tr>
<tr id="row557998549165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229877121165622"><a name="p1229877121165622"></a><a name="p1229877121165622"></a><em id="ga97f6d6514d3d3dd50c3a2a6d622673db"><a name="ga97f6d6514d3d3dd50c3a2a6d622673db"></a><a name="ga97f6d6514d3d3dd50c3a2a6d622673db"></a></em>M_2_PI    0.63661977236758134308 /* 2/pi */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p616043087165622"><a name="p616043087165622"></a><a name="p616043087165622"></a>Two times the reciprocal of pi. </p>
</td>
</tr>
<tr id="row1658166327165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437575888165622"><a name="p437575888165622"></a><a name="p437575888165622"></a><em id="ga631ff334c4a1a6db2e8a7ff4acbe48a5"><a name="ga631ff334c4a1a6db2e8a7ff4acbe48a5"></a><a name="ga631ff334c4a1a6db2e8a7ff4acbe48a5"></a></em>M_2_SQRTPI    1.12837916709551257390 /* 2/<a href="math.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a>(pi) */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p387228786165622"><a name="p387228786165622"></a><a name="p387228786165622"></a>Two times the reciprocal of the square root of pi. </p>
</td>
</tr>
<tr id="row2146293591165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p262811658165622"><a name="p262811658165622"></a><a name="p262811658165622"></a><em id="ga66b3ab30f1332874326ed93969e496e0"><a name="ga66b3ab30f1332874326ed93969e496e0"></a><a name="ga66b3ab30f1332874326ed93969e496e0"></a></em>M_SQRT2    1.41421356237309504880 /* <a href="math.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a>(2) */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278711318165622"><a name="p1278711318165622"></a><a name="p1278711318165622"></a>Square root of <strong id="b2115731245165622"><a name="b2115731245165622"></a><a name="b2115731245165622"></a>2</strong> </p>
</td>
</tr>
<tr id="row758933277165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916687545165622"><a name="p1916687545165622"></a><a name="p1916687545165622"></a><em id="gacdbb2c2f9429f08916f03c8786d2d2d7"><a name="gacdbb2c2f9429f08916f03c8786d2d2d7"></a><a name="gacdbb2c2f9429f08916f03c8786d2d2d7"></a></em>M_SQRT1_2    0.70710678118654752440 /* 1/<a href="math.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a>(2) */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156865103165622"><a name="p156865103165622"></a><a name="p156865103165622"></a>Reciprocal of the square root of <strong id="b43940777165622"><a name="b43940777165622"></a><a name="b43940777165622"></a>2</strong> </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table367266342165622"></a>
<table><thead align="left"><tr id="row111730137165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p417240250165622"><a name="p417240250165622"></a><a name="p417240250165622"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p524782512165622"><a name="p524782512165622"></a><a name="p524782512165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row32034669165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1422536848165622"><a name="p1422536848165622"></a><a name="p1422536848165622"></a>fexcept_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p877937283165622"><a name="p877937283165622"></a><a name="p877937283165622"></a><strong id="ga3eec78fdb9921de3f7254105f546c624"><a name="ga3eec78fdb9921de3f7254105f546c624"></a><a name="ga3eec78fdb9921de3f7254105f546c624"></a></strong> typedef unsigned long </p>
<p id="p1473569115165622"><a name="p1473569115165622"></a><a name="p1473569115165622"></a>Floating-point exception type. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table448550091165622"></a>
<table><thead align="left"><tr id="row1832834576165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p161846816165622"><a name="p161846816165622"></a><a name="p161846816165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p504356283165622"><a name="p504356283165622"></a><a name="p504356283165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row246371585165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658299487165622"><a name="p658299487165622"></a><a name="p658299487165622"></a><a href="math.md#ga51a9bcdc7791e50f879c79d64362d7c3">cacos</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p193880486165622"><a name="p193880486165622"></a><a name="p193880486165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1146235841165622"><a name="p1146235841165622"></a><a name="p1146235841165622"></a>Calculates the arc cosine of the complex number <strong id="b1866765280165622"><a name="b1866765280165622"></a><a name="b1866765280165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row498939640165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519690303165622"><a name="p1519690303165622"></a><a name="p1519690303165622"></a><a href="math.md#ga238bc3dbd59adeb477af18c9a501e04e">cacosf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455207451165622"><a name="p1455207451165622"></a><a name="p1455207451165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p158228843165622"><a name="p158228843165622"></a><a name="p158228843165622"></a>Calculates the arc cosine of the complex number <strong id="b739197894165622"><a name="b739197894165622"></a><a name="b739197894165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row490861516165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2125033369165622"><a name="p2125033369165622"></a><a name="p2125033369165622"></a><a href="math.md#ga789143f2859142f58590b2726328025f">cacosl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570210294165622"><a name="p1570210294165622"></a><a name="p1570210294165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1004187323165622"><a name="p1004187323165622"></a><a name="p1004187323165622"></a>Calculates the arc cosine of the complex number <strong id="b991403305165622"><a name="b991403305165622"></a><a name="b991403305165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row517134670165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p637015819165622"><a name="p637015819165622"></a><a name="p637015819165622"></a><a href="math.md#gac43774f89411806a3e0695012cdb7f38">casin</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304769949165622"><a name="p304769949165622"></a><a name="p304769949165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1545818280165622"><a name="p1545818280165622"></a><a name="p1545818280165622"></a>Calculates the arc sine of the complex number <strong id="b1726303697165622"><a name="b1726303697165622"></a><a name="b1726303697165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1985062107165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448094796165622"><a name="p448094796165622"></a><a name="p448094796165622"></a><a href="math.md#ga04d2cd1f0b47d3f1b782aeb517151033">casinf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p557779620165622"><a name="p557779620165622"></a><a name="p557779620165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p216632736165622"><a name="p216632736165622"></a><a name="p216632736165622"></a>Calculates the arc sine of the complex number <strong id="b335199352165622"><a name="b335199352165622"></a><a name="b335199352165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row959524959165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p273303063165622"><a name="p273303063165622"></a><a name="p273303063165622"></a><a href="math.md#ga8770350a79904ac151ebb3eebd736188">casinl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304178835165622"><a name="p1304178835165622"></a><a name="p1304178835165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1367414214165622"><a name="p1367414214165622"></a><a name="p1367414214165622"></a>Calculates the arc sine of the complex number <strong id="b98218902165622"><a name="b98218902165622"></a><a name="b98218902165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1582934897165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235947518165622"><a name="p235947518165622"></a><a name="p235947518165622"></a><a href="math.md#ga1a77a3240b834af81a23b38f2af6c93d">catan</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65412981165622"><a name="p65412981165622"></a><a name="p65412981165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1846979938165622"><a name="p1846979938165622"></a><a name="p1846979938165622"></a>Calculates the arc tangent of the complex number <strong id="b268816345165622"><a name="b268816345165622"></a><a name="b268816345165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1695814899165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p666818473165622"><a name="p666818473165622"></a><a name="p666818473165622"></a><a href="math.md#ga4d0beef9b3994887e356c6b5c98388d9">catanf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126114654165622"><a name="p1126114654165622"></a><a name="p1126114654165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p573088742165622"><a name="p573088742165622"></a><a name="p573088742165622"></a>Calculates the arc tangent of the complex number <strong id="b1421769773165622"><a name="b1421769773165622"></a><a name="b1421769773165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row733599323165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102118198165622"><a name="p1102118198165622"></a><a name="p1102118198165622"></a><a href="math.md#gaf28ad2f006e49eaa6bbdb97dd143d6cb">catanl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719792972165622"><a name="p1719792972165622"></a><a name="p1719792972165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p559643159165622"><a name="p559643159165622"></a><a name="p559643159165622"></a>Calculates the arc tangent of the complex number <strong id="b960843799165622"><a name="b960843799165622"></a><a name="b960843799165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row413200637165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1685064830165622"><a name="p1685064830165622"></a><a name="p1685064830165622"></a><a href="math.md#ga6a25bcd38751910533efde6dad1499c3">ccos</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942345290165622"><a name="p942345290165622"></a><a name="p942345290165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1686795640165622"><a name="p1686795640165622"></a><a name="p1686795640165622"></a>Calculates the cosine of the complex number <strong id="b842148242165622"><a name="b842148242165622"></a><a name="b842148242165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1180491223165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721010569165622"><a name="p1721010569165622"></a><a name="p1721010569165622"></a><a href="math.md#ga88df5eebfb10b88ed37e444f5b13fd6a">ccosf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1294287427165622"><a name="p1294287427165622"></a><a name="p1294287427165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1343058638165622"><a name="p1343058638165622"></a><a name="p1343058638165622"></a>Calculates the cosine of the complex number <strong id="b958262421165622"><a name="b958262421165622"></a><a name="b958262421165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row832232651165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971119275165622"><a name="p1971119275165622"></a><a name="p1971119275165622"></a><a href="math.md#ga785d8c7b2ac4283d4759dfa6a86779ab">ccosl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p284447213165622"><a name="p284447213165622"></a><a name="p284447213165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p406083919165622"><a name="p406083919165622"></a><a name="p406083919165622"></a>Calculates the cosine of the complex number <strong id="b1627159900165622"><a name="b1627159900165622"></a><a name="b1627159900165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row306092845165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1896332663165622"><a name="p1896332663165622"></a><a name="p1896332663165622"></a><a href="math.md#ga1b9030685d326e66a93a35ca8c4bb0f6">csin</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1264131838165622"><a name="p1264131838165622"></a><a name="p1264131838165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1663180149165622"><a name="p1663180149165622"></a><a name="p1663180149165622"></a>Calculates the sine of the complex number <strong id="b2131713413165622"><a name="b2131713413165622"></a><a name="b2131713413165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row478458172165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p979028161165622"><a name="p979028161165622"></a><a name="p979028161165622"></a><a href="math.md#ga76dc89521e12096bc2104c9c0dcc20ea">csinf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p358402105165622"><a name="p358402105165622"></a><a name="p358402105165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1815663334165622"><a name="p1815663334165622"></a><a name="p1815663334165622"></a>Calculates the sine of the complex number <strong id="b423515301165622"><a name="b423515301165622"></a><a name="b423515301165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row450890843165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755606843165622"><a name="p755606843165622"></a><a name="p755606843165622"></a><a href="math.md#gad594fa6071ea5d383a0c7abaa0c32d80">csinl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1194714055165622"><a name="p1194714055165622"></a><a name="p1194714055165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1156741901165622"><a name="p1156741901165622"></a><a name="p1156741901165622"></a>Calculates the sine of the complex number <strong id="b1844352244165622"><a name="b1844352244165622"></a><a name="b1844352244165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1217642371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170408320165622"><a name="p170408320165622"></a><a name="p170408320165622"></a><a href="math.md#ga665b5dfc1b1f51d3b444f049c6bd95dd">ctan</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p147530493165622"><a name="p147530493165622"></a><a name="p147530493165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p959523643165622"><a name="p959523643165622"></a><a name="p959523643165622"></a>Calculates the tangent of the complex number <strong id="b888886988165622"><a name="b888886988165622"></a><a name="b888886988165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1239342917165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826429832165622"><a name="p826429832165622"></a><a name="p826429832165622"></a><a href="math.md#ga4301d608cc419f1ba3177fae4f258f30">ctanf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704427275165622"><a name="p704427275165622"></a><a name="p704427275165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p366903179165622"><a name="p366903179165622"></a><a name="p366903179165622"></a>Calculates the tangent of the complex number <strong id="b1948938816165622"><a name="b1948938816165622"></a><a name="b1948938816165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row545775831165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1896035343165622"><a name="p1896035343165622"></a><a name="p1896035343165622"></a><a href="math.md#ga7aa0362acd67521c9aac791aa617f953">ctanl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785192615165622"><a name="p785192615165622"></a><a name="p785192615165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p180300158165622"><a name="p180300158165622"></a><a name="p180300158165622"></a>Calculates the tangent of the complex number <strong id="b144228236165622"><a name="b144228236165622"></a><a name="b144228236165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1744274927165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1403841281165622"><a name="p1403841281165622"></a><a name="p1403841281165622"></a><a href="math.md#gaf7286142554fde4ba6316a2b64b96c5c">cacosh</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p576476507165622"><a name="p576476507165622"></a><a name="p576476507165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1339142400165622"><a name="p1339142400165622"></a><a name="p1339142400165622"></a>Calculates the inverse hyperbolic cosine of the complex number <strong id="b676982432165622"><a name="b676982432165622"></a><a name="b676982432165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row357440354165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p586723502165622"><a name="p586723502165622"></a><a name="p586723502165622"></a><a href="math.md#gabe9dbe34293eef409598b0559435c5ff">cacoshf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652803950165622"><a name="p1652803950165622"></a><a name="p1652803950165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p120259332165622"><a name="p120259332165622"></a><a name="p120259332165622"></a>Calculates the inverse hyperbolic cosine of the complex number <strong id="b922571148165622"><a name="b922571148165622"></a><a name="b922571148165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row85912050165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2002776888165622"><a name="p2002776888165622"></a><a name="p2002776888165622"></a><a href="math.md#gad8e03bbb434b8a9af73e0e3daec045ac">cacoshl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1291160150165622"><a name="p1291160150165622"></a><a name="p1291160150165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1888140307165622"><a name="p1888140307165622"></a><a name="p1888140307165622"></a>Calculates the inverse hyperbolic cosine of the complex number <strong id="b820336865165622"><a name="b820336865165622"></a><a name="b820336865165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row760084883165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1837030768165622"><a name="p1837030768165622"></a><a name="p1837030768165622"></a><a href="math.md#ga6fc1a0c1cbac62ba63e799d7e8f488e0">casinh</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450048895165622"><a name="p450048895165622"></a><a name="p450048895165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p344781380165622"><a name="p344781380165622"></a><a name="p344781380165622"></a>Calculates the inverse hyperbolic sine of the complex number <strong id="b1393090912165622"><a name="b1393090912165622"></a><a name="b1393090912165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1736938698165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p618366074165622"><a name="p618366074165622"></a><a name="p618366074165622"></a><a href="math.md#ga8b682e1c311efa5594ec0d0b39c9efe0">casinhf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283827135165622"><a name="p1283827135165622"></a><a name="p1283827135165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1152790835165622"><a name="p1152790835165622"></a><a name="p1152790835165622"></a>Calculates the inverse hyperbolic sine of the complex number <strong id="b672346961165622"><a name="b672346961165622"></a><a name="b672346961165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1098117059165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245772865165622"><a name="p245772865165622"></a><a name="p245772865165622"></a><a href="math.md#ga174b8f2a00e771dbbad06fdf0e0ee449">casinhl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943810290165622"><a name="p943810290165622"></a><a name="p943810290165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p327487604165622"><a name="p327487604165622"></a><a name="p327487604165622"></a>Calculates the inverse hyperbolic sine of the complex number <strong id="b2102879478165622"><a name="b2102879478165622"></a><a name="b2102879478165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1167675980165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1380547532165622"><a name="p1380547532165622"></a><a name="p1380547532165622"></a><a href="math.md#ga376fef7890def8c0e7b2b5a5292be074">catanh</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2092387453165622"><a name="p2092387453165622"></a><a name="p2092387453165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p654386378165622"><a name="p654386378165622"></a><a name="p654386378165622"></a>Calculates the inverse hyperbolic tangent of the complex number <strong id="b1394025920165622"><a name="b1394025920165622"></a><a name="b1394025920165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1595913940165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p895537400165622"><a name="p895537400165622"></a><a name="p895537400165622"></a><a href="math.md#ga480c29e0eeace893be77a2c61995d2ec">catanhf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2068188835165622"><a name="p2068188835165622"></a><a name="p2068188835165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p892377214165622"><a name="p892377214165622"></a><a name="p892377214165622"></a>Calculates the inverse hyperbolic tangent of the complex number <strong id="b1212449899165622"><a name="b1212449899165622"></a><a name="b1212449899165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row432356587165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934521884165622"><a name="p1934521884165622"></a><a name="p1934521884165622"></a><a href="math.md#gab2422355124f175a41ec092c3b8adf2b">catanhl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p816983409165622"><a name="p816983409165622"></a><a name="p816983409165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1176714098165622"><a name="p1176714098165622"></a><a name="p1176714098165622"></a>Calculates the inverse hyperbolic tangent of the complex number <strong id="b129774794165622"><a name="b129774794165622"></a><a name="b129774794165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row266630040165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p589359430165622"><a name="p589359430165622"></a><a name="p589359430165622"></a><a href="math.md#ga62c8f7e0cce95bbf670af16376909324">ccosh</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1994376512165622"><a name="p1994376512165622"></a><a name="p1994376512165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1868810654165622"><a name="p1868810654165622"></a><a name="p1868810654165622"></a>Calculates the hyperbolic cosine of the complex number <strong id="b743796838165622"><a name="b743796838165622"></a><a name="b743796838165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row891831965165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1805807090165622"><a name="p1805807090165622"></a><a name="p1805807090165622"></a><a href="math.md#gabe11c35bd81b278ab0e47196c5952662">ccoshf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p996952576165622"><a name="p996952576165622"></a><a name="p996952576165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1700792078165622"><a name="p1700792078165622"></a><a name="p1700792078165622"></a>Calculates the hyperbolic cosine of the complex number <strong id="b1636877235165622"><a name="b1636877235165622"></a><a name="b1636877235165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row300491406165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376705655165622"><a name="p376705655165622"></a><a name="p376705655165622"></a><a href="math.md#gad2b7878b871c0266ecb1f58e5bf141a7">ccoshl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885456567165622"><a name="p885456567165622"></a><a name="p885456567165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p275380948165622"><a name="p275380948165622"></a><a name="p275380948165622"></a>Calculates the hyperbolic cosine of the complex number <strong id="b72330073165622"><a name="b72330073165622"></a><a name="b72330073165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row92967217165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p694659157165622"><a name="p694659157165622"></a><a name="p694659157165622"></a><a href="math.md#ga0c782aa9258a4e11cc3ea57b2dcccfef">csinh</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1983097903165622"><a name="p1983097903165622"></a><a name="p1983097903165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p559329863165622"><a name="p559329863165622"></a><a name="p559329863165622"></a>Calculates the hyperbolic sine of the complex number <strong id="b1376784062165622"><a name="b1376784062165622"></a><a name="b1376784062165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row123226857165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200581674165622"><a name="p1200581674165622"></a><a name="p1200581674165622"></a><a href="math.md#ga268ba13d67a10e6667bd6b64a1a96351">csinhf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788241333165622"><a name="p788241333165622"></a><a name="p788241333165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1230668329165622"><a name="p1230668329165622"></a><a name="p1230668329165622"></a>Calculates the hyperbolic sine of the complex number <strong id="b1894225748165622"><a name="b1894225748165622"></a><a name="b1894225748165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1658271348165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705808836165622"><a name="p705808836165622"></a><a name="p705808836165622"></a><a href="math.md#ga0d14ae39cd9a811e42e36512fe6c7e53">csinhl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957034486165622"><a name="p957034486165622"></a><a name="p957034486165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1393112282165622"><a name="p1393112282165622"></a><a name="p1393112282165622"></a>Calculates the hyperbolic sine of the complex number <strong id="b1721268255165622"><a name="b1721268255165622"></a><a name="b1721268255165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row770131299165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p683696136165622"><a name="p683696136165622"></a><a name="p683696136165622"></a><a href="math.md#ga9c5cf378e654f3aaed9fb0f5c8223585">ctanh</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738068343165622"><a name="p1738068343165622"></a><a name="p1738068343165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1288103837165622"><a name="p1288103837165622"></a><a name="p1288103837165622"></a>Calculates the hyperbolic tangent of the complex number <strong id="b1246284048165622"><a name="b1246284048165622"></a><a name="b1246284048165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row812664094165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p347595980165622"><a name="p347595980165622"></a><a name="p347595980165622"></a><a href="math.md#gad68db7f429f2104acf52b096c5efb69a">ctanhf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p326401783165622"><a name="p326401783165622"></a><a name="p326401783165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p455527200165622"><a name="p455527200165622"></a><a name="p455527200165622"></a>Calculates the hyperbolic tangent of the complex number <strong id="b1249759884165622"><a name="b1249759884165622"></a><a name="b1249759884165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row273984447165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477092174165622"><a name="p477092174165622"></a><a name="p477092174165622"></a><a href="math.md#ga2fbb0a9d578343f924c96faed3189805">ctanhl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761784352165622"><a name="p761784352165622"></a><a name="p761784352165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p2015408070165622"><a name="p2015408070165622"></a><a name="p2015408070165622"></a>Calculates the hyperbolic tangent of the complex number <strong id="b1673090909165622"><a name="b1673090909165622"></a><a name="b1673090909165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1434649129165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p239663466165622"><a name="p239663466165622"></a><a name="p239663466165622"></a><a href="math.md#gab9c654c52efefb54d06d52aa1a1c1827">cexp</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17282937165622"><a name="p17282937165622"></a><a name="p17282937165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1258223666165622"><a name="p1258223666165622"></a><a name="p1258223666165622"></a>Calculates the base-e exponential of the complex number <strong id="b558301004165622"><a name="b558301004165622"></a><a name="b558301004165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row977557577165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1563652561165622"><a name="p1563652561165622"></a><a name="p1563652561165622"></a><a href="math.md#ga8628a449a00228f124c9e53d2236611f">cexpf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913703228165622"><a name="p1913703228165622"></a><a name="p1913703228165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1049718000165622"><a name="p1049718000165622"></a><a name="p1049718000165622"></a>Calculates the base-e exponential of the complex number <strong id="b554494984165622"><a name="b554494984165622"></a><a name="b554494984165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1555757100165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852076029165622"><a name="p1852076029165622"></a><a name="p1852076029165622"></a><a href="math.md#ga31a965fe1790cace431516e53f7d0cb5">cexpl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p531365366165622"><a name="p531365366165622"></a><a name="p531365366165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p571309539165622"><a name="p571309539165622"></a><a name="p571309539165622"></a>Calculates the base-e exponential of the complex number <strong id="b253926792165622"><a name="b253926792165622"></a><a name="b253926792165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1926228663165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192183131165622"><a name="p1192183131165622"></a><a name="p1192183131165622"></a><a href="math.md#gaa39c3557d8db10c19571bc0b63fd5529">clog</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p968849024165622"><a name="p968849024165622"></a><a name="p968849024165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1184081668165622"><a name="p1184081668165622"></a><a name="p1184081668165622"></a>Calculates the natural (base-e) logarithm of the complex number <strong id="b657809976165622"><a name="b657809976165622"></a><a name="b657809976165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row686612277165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195620995165622"><a name="p195620995165622"></a><a name="p195620995165622"></a><a href="math.md#ga0c9f343c7d1dabc91f6e4cb868b81152">clogf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625946900165622"><a name="p625946900165622"></a><a name="p625946900165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p812399250165622"><a name="p812399250165622"></a><a name="p812399250165622"></a>Calculates the natural (base-e) logarithm of the complex number <strong id="b2029566110165622"><a name="b2029566110165622"></a><a name="b2029566110165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row424187756165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1288723615165622"><a name="p1288723615165622"></a><a name="p1288723615165622"></a><a href="math.md#ga48efe0bf63314044fafaeb32623fff17">clogl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1924859121165622"><a name="p1924859121165622"></a><a name="p1924859121165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1362210606165622"><a name="p1362210606165622"></a><a name="p1362210606165622"></a>Calculates the natural (base-e) logarithm of the complex number <strong id="b1625591270165622"><a name="b1625591270165622"></a><a name="b1625591270165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1357070381165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169660421165622"><a name="p169660421165622"></a><a name="p169660421165622"></a><a href="math.md#ga82c65f6b05062b620716623ba49ff07f">cabs</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579036559165622"><a name="p1579036559165622"></a><a name="p1579036559165622"></a>double </p>
<p id="p574083844165622"><a name="p574083844165622"></a><a name="p574083844165622"></a>Calculates the absolute value of the complex number <strong id="b1847225533165622"><a name="b1847225533165622"></a><a name="b1847225533165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1445380381165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101915324165622"><a name="p1101915324165622"></a><a name="p1101915324165622"></a><a href="math.md#ga59a1f4977dfdf85b51a84bfd56737277">cabsf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1666374875165622"><a name="p1666374875165622"></a><a name="p1666374875165622"></a>float </p>
<p id="p1225779919165622"><a name="p1225779919165622"></a><a name="p1225779919165622"></a>Calculates the absolute value of the complex number <strong id="b1498206794165622"><a name="b1498206794165622"></a><a name="b1498206794165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row899035333165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379331544165622"><a name="p379331544165622"></a><a name="p379331544165622"></a><a href="math.md#ga7e37259e24f3384f376e4d3eb45a9ea8">cabsl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2019502589165622"><a name="p2019502589165622"></a><a name="p2019502589165622"></a>long double </p>
<p id="p1414443212165622"><a name="p1414443212165622"></a><a name="p1414443212165622"></a>Calculates the absolute value of the complex number <strong id="b1437842484165622"><a name="b1437842484165622"></a><a name="b1437842484165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row262310784165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984015327165622"><a name="p984015327165622"></a><a name="p984015327165622"></a><a href="math.md#ga6fd1bd16c6de991f95a4e19e0f2f2a12">cpow</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> x, double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954587546165622"><a name="p954587546165622"></a><a name="p954587546165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p980587018165622"><a name="p980587018165622"></a><a name="p980587018165622"></a>Calculates the value of <strong id="b36293104165622"><a name="b36293104165622"></a><a name="b36293104165622"></a>x</strong> raised to the <strong id="b1192250160165622"><a name="b1192250160165622"></a><a name="b1192250160165622"></a>z</strong> power. </p>
</td>
</tr>
<tr id="row1150273141165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1493315936165622"><a name="p1493315936165622"></a><a name="p1493315936165622"></a><a href="math.md#ga58beb4a3ea7b6ab6bb942900f94179fa">cpowf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> x, float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p31585610165622"><a name="p31585610165622"></a><a name="p31585610165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p322293782165622"><a name="p322293782165622"></a><a name="p322293782165622"></a>Calculates the value of <strong id="b1776307153165622"><a name="b1776307153165622"></a><a name="b1776307153165622"></a>x</strong> raised to the <strong id="b1853030008165622"><a name="b1853030008165622"></a><a name="b1853030008165622"></a>z</strong> power. </p>
</td>
</tr>
<tr id="row2128896104165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056390155165622"><a name="p1056390155165622"></a><a name="p1056390155165622"></a><a href="math.md#gae3ae7292dac86eeec3bb9a06b66f61cb">cpowl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> x, long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629495780165622"><a name="p1629495780165622"></a><a name="p1629495780165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p354775404165622"><a name="p354775404165622"></a><a name="p354775404165622"></a>Calculates the value of <strong id="b1096051803165622"><a name="b1096051803165622"></a><a name="b1096051803165622"></a>x</strong> raised to the <strong id="b427745828165622"><a name="b427745828165622"></a><a name="b427745828165622"></a>z</strong> power. </p>
</td>
</tr>
<tr id="row1073820560165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p102626561165622"><a name="p102626561165622"></a><a name="p102626561165622"></a><a href="math.md#ga7ff172d72bc0474b93e27470ce94494b">csqrt</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1857643030165622"><a name="p1857643030165622"></a><a name="p1857643030165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1781689587165622"><a name="p1781689587165622"></a><a name="p1781689587165622"></a>Calculates the square root of the complex number <strong id="b1763694138165622"><a name="b1763694138165622"></a><a name="b1763694138165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row2032169943165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1965254875165622"><a name="p1965254875165622"></a><a name="p1965254875165622"></a><a href="math.md#gab8e425ba3e5d52d410afc3041bdeadce">csqrtf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p797768860165622"><a name="p797768860165622"></a><a name="p797768860165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p831656302165622"><a name="p831656302165622"></a><a name="p831656302165622"></a>Calculates the square root of the complex number <strong id="b1384722479165622"><a name="b1384722479165622"></a><a name="b1384722479165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row150055421165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p69643290165622"><a name="p69643290165622"></a><a name="p69643290165622"></a><a href="math.md#ga94a429c220e400a1a6781d6e11cbfafd">csqrtl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p334603518165622"><a name="p334603518165622"></a><a name="p334603518165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1729476236165622"><a name="p1729476236165622"></a><a name="p1729476236165622"></a>Calculates the square root of the complex number <strong id="b2100543479165622"><a name="b2100543479165622"></a><a name="b2100543479165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1848930176165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118159323165622"><a name="p1118159323165622"></a><a name="p1118159323165622"></a><a href="math.md#ga4a1e5d839db7a1dc6013b2846b2432d9">carg</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085359841165622"><a name="p1085359841165622"></a><a name="p1085359841165622"></a>double </p>
<p id="p478019678165622"><a name="p478019678165622"></a><a name="p478019678165622"></a>Calculates the phase angle of the complex number <strong id="b1194486015165622"><a name="b1194486015165622"></a><a name="b1194486015165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row833743979165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49569068165622"><a name="p49569068165622"></a><a name="p49569068165622"></a><a href="math.md#ga66334f398567baa3648cd3111ed68d3b">cargf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650283773165622"><a name="p1650283773165622"></a><a name="p1650283773165622"></a>float </p>
<p id="p1767997634165622"><a name="p1767997634165622"></a><a name="p1767997634165622"></a>Calculates the phase angle of the complex number <strong id="b1599162925165622"><a name="b1599162925165622"></a><a name="b1599162925165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1967450927165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229542080165622"><a name="p229542080165622"></a><a name="p229542080165622"></a><a href="math.md#ga74f3429f1b860581f4d15bea90533fd5">cargl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189814081165622"><a name="p189814081165622"></a><a name="p189814081165622"></a>long double </p>
<p id="p426758144165622"><a name="p426758144165622"></a><a name="p426758144165622"></a>Calculates the phase angle of the complex number <strong id="b851344282165622"><a name="b851344282165622"></a><a name="b851344282165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row357875560165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p780011773165622"><a name="p780011773165622"></a><a name="p780011773165622"></a><a href="math.md#ga6c3d7c875ae93700b0a2a32db24b37d3">cimag</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501965705165622"><a name="p1501965705165622"></a><a name="p1501965705165622"></a>double </p>
<p id="p664381321165622"><a name="p664381321165622"></a><a name="p664381321165622"></a>Calculates the imaginary part of the complex number <strong id="b1639766918165622"><a name="b1639766918165622"></a><a name="b1639766918165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row2127053532165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468920186165622"><a name="p1468920186165622"></a><a name="p1468920186165622"></a><a href="math.md#gaac22dc2fffc4326595ff807d441f0675">cimagf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215179247165622"><a name="p215179247165622"></a><a name="p215179247165622"></a>float </p>
<p id="p2093038599165622"><a name="p2093038599165622"></a><a name="p2093038599165622"></a>Calculates the imaginary part of the complex number <strong id="b1411323821165622"><a name="b1411323821165622"></a><a name="b1411323821165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row165422105165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61496616165622"><a name="p61496616165622"></a><a name="p61496616165622"></a><a href="math.md#ga4237f0401b8123eaec284c995ced4b04">cimagl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911301587165622"><a name="p1911301587165622"></a><a name="p1911301587165622"></a>long double </p>
<p id="p1807949757165622"><a name="p1807949757165622"></a><a name="p1807949757165622"></a>Calculates the imaginary part of the complex number <strong id="b952418380165622"><a name="b952418380165622"></a><a name="b952418380165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1281290592165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989433997165622"><a name="p989433997165622"></a><a name="p989433997165622"></a><a href="math.md#ga6fb30f37aa43eb2e0199ffdc38cac18a">conj</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68999134165622"><a name="p68999134165622"></a><a name="p68999134165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p781187697165622"><a name="p781187697165622"></a><a name="p781187697165622"></a>Calculates the conjugate of the complex number <strong id="b109427278165622"><a name="b109427278165622"></a><a name="b109427278165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row658990327165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908899066165622"><a name="p1908899066165622"></a><a name="p1908899066165622"></a><a href="math.md#ga471ecd8d25e722ecae510a635c1a2c53">conjf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1450831972165622"><a name="p1450831972165622"></a><a name="p1450831972165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p572288525165622"><a name="p572288525165622"></a><a name="p572288525165622"></a>Calculates the conjugate of the complex number <strong id="b1748118742165622"><a name="b1748118742165622"></a><a name="b1748118742165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1123261552165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1158701441165622"><a name="p1158701441165622"></a><a name="p1158701441165622"></a><a href="math.md#ga5156353f4650ed7ee06b152790c1558b">conjl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078415778165622"><a name="p2078415778165622"></a><a name="p2078415778165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1496544808165622"><a name="p1496544808165622"></a><a name="p1496544808165622"></a>Calculates the conjugate of the complex number <strong id="b23126315165622"><a name="b23126315165622"></a><a name="b23126315165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row53128892165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569200061165622"><a name="p1569200061165622"></a><a name="p1569200061165622"></a><a href="math.md#gac10f86edf0994d0ee834768633be644e">cproj</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648684453165622"><a name="p1648684453165622"></a><a name="p1648684453165622"></a>double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p2037469283165622"><a name="p2037469283165622"></a><a name="p2037469283165622"></a>Calculates the projection of the complex number <strong id="b1433708224165622"><a name="b1433708224165622"></a><a name="b1433708224165622"></a>z</strong> onto the Riemann sphere. </p>
</td>
</tr>
<tr id="row953301645165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2081564711165622"><a name="p2081564711165622"></a><a name="p2081564711165622"></a><a href="math.md#ga9f435a71e44dd1e13eca358e2ca530e6">cprojf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890053275165622"><a name="p1890053275165622"></a><a name="p1890053275165622"></a>float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p1753194711165622"><a name="p1753194711165622"></a><a name="p1753194711165622"></a>Calculates the projection of the complex number <strong id="b950213924165622"><a name="b950213924165622"></a><a name="b950213924165622"></a>z</strong> onto the Riemann sphere. </p>
</td>
</tr>
<tr id="row1244821643165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112420114165622"><a name="p1112420114165622"></a><a name="p1112420114165622"></a><a href="math.md#ga2cc437f3ab8e77dbd8fb024c66474915">cprojl</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690734263165622"><a name="p1690734263165622"></a><a name="p1690734263165622"></a>long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> </p>
<p id="p511225692165622"><a name="p511225692165622"></a><a name="p511225692165622"></a>Calculates the projection of the complex number <strong id="b1826849375165622"><a name="b1826849375165622"></a><a name="b1826849375165622"></a>z</strong> onto the Riemann sphere. </p>
</td>
</tr>
<tr id="row677968771165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317079455165622"><a name="p1317079455165622"></a><a name="p1317079455165622"></a><a href="math.md#ga24b1a511efdb973354d81646c5c3bb81">creal</a> (double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503320639165622"><a name="p1503320639165622"></a><a name="p1503320639165622"></a>double </p>
<p id="p1374456619165622"><a name="p1374456619165622"></a><a name="p1374456619165622"></a>Calculates the real part of the complex number <strong id="b2012283152165622"><a name="b2012283152165622"></a><a name="b2012283152165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1131535005165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1640382733165622"><a name="p1640382733165622"></a><a name="p1640382733165622"></a><a href="math.md#gad052a3eb4d9f32153173e6bcea9e42ce">crealf</a> (float <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p545982024165622"><a name="p545982024165622"></a><a name="p545982024165622"></a>float </p>
<p id="p1214513503165622"><a name="p1214513503165622"></a><a name="p1214513503165622"></a>Calculates the real part of the complex number <strong id="b185976230165622"><a name="b185976230165622"></a><a name="b185976230165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row800237905165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p950083933165622"><a name="p950083933165622"></a><a name="p950083933165622"></a><a href="math.md#ga4ee2baa54a4e51877c59527d2be1a0da">creall</a> (long double <a href="math.md#ga0fa4878c968311979d497ccc322e0b9b">complex</a> z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1649833591165622"><a name="p1649833591165622"></a><a name="p1649833591165622"></a>long double </p>
<p id="p1253542636165622"><a name="p1253542636165622"></a><a name="p1253542636165622"></a>Calculates the real part of the complex number <strong id="b23225607165622"><a name="b23225607165622"></a><a name="b23225607165622"></a>z</strong>. </p>
</td>
</tr>
<tr id="row1400680085165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1538104736165622"><a name="p1538104736165622"></a><a name="p1538104736165622"></a><a href="math.md#gae93afe22ff34c79ee97ea3eaf77557db">acos</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2128012527165622"><a name="p2128012527165622"></a><a name="p2128012527165622"></a>double </p>
<p id="p1986174798165622"><a name="p1986174798165622"></a><a name="p1986174798165622"></a>Calculates the arc cosine of the double value <strong id="b1678119072165622"><a name="b1678119072165622"></a><a name="b1678119072165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row475508953165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p531231070165622"><a name="p531231070165622"></a><a name="p531231070165622"></a><a href="math.md#ga983a9e1aa7568df39153ea4d8e16653b">acosf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167224851165622"><a name="p167224851165622"></a><a name="p167224851165622"></a>float </p>
<p id="p891490065165622"><a name="p891490065165622"></a><a name="p891490065165622"></a>Calculates the arc cosine of the float value <strong id="b414292455165622"><a name="b414292455165622"></a><a name="b414292455165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row850082450165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372359618165622"><a name="p1372359618165622"></a><a name="p1372359618165622"></a><a href="math.md#gae84dc6cff92b3417098f16a1811635e4">acosl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p851660106165622"><a name="p851660106165622"></a><a name="p851660106165622"></a>long double </p>
<p id="p1054789343165622"><a name="p1054789343165622"></a><a name="p1054789343165622"></a>Calculates the arc cosine of the long double value <strong id="b586962092165622"><a name="b586962092165622"></a><a name="b586962092165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row493767124165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847087172165622"><a name="p847087172165622"></a><a name="p847087172165622"></a><a href="math.md#gac862445bcb46911b1782c284829d5e46">acosh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p858321135165622"><a name="p858321135165622"></a><a name="p858321135165622"></a>double </p>
<p id="p818366571165622"><a name="p818366571165622"></a><a name="p818366571165622"></a>Calculates the inverse hyperbolic cosine of the double value <strong id="b1889977146165622"><a name="b1889977146165622"></a><a name="b1889977146165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row26346372165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1175370387165622"><a name="p1175370387165622"></a><a name="p1175370387165622"></a><a href="math.md#ga84cfd14c3432390f70b6233d24ad173b">acoshf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018717874165622"><a name="p2018717874165622"></a><a name="p2018717874165622"></a>float </p>
<p id="p209998989165622"><a name="p209998989165622"></a><a name="p209998989165622"></a>Calculates the inverse hyperbolic cosine of float value <strong id="b1892797729165622"><a name="b1892797729165622"></a><a name="b1892797729165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row926373681165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835717579165622"><a name="p1835717579165622"></a><a name="p1835717579165622"></a><a href="math.md#ga104456314ba05665d6cbb805e823dd10">acoshl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1009625373165622"><a name="p1009625373165622"></a><a name="p1009625373165622"></a>long double </p>
<p id="p2030451194165622"><a name="p2030451194165622"></a><a name="p2030451194165622"></a>Calculates the inverse hyperbolic cosine of the long double value <strong id="b1743947419165622"><a name="b1743947419165622"></a><a name="b1743947419165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row385097680165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1022161263165622"><a name="p1022161263165622"></a><a name="p1022161263165622"></a><a href="math.md#gaa9528d92a3ae44ad6484da0774604454">asin</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733228430165622"><a name="p1733228430165622"></a><a name="p1733228430165622"></a>double </p>
<p id="p999719306165622"><a name="p999719306165622"></a><a name="p999719306165622"></a>Calculates the arc sine of the double value <strong id="b1591004862165622"><a name="b1591004862165622"></a><a name="b1591004862165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row165002171165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078990687165622"><a name="p2078990687165622"></a><a name="p2078990687165622"></a><a href="math.md#ga7447a7400ca474ba42d127b04d6ee2b7">asinf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154026548165622"><a name="p1154026548165622"></a><a name="p1154026548165622"></a>float </p>
<p id="p1962201013165622"><a name="p1962201013165622"></a><a name="p1962201013165622"></a>Calculates the arc sine of the float value <strong id="b1286061844165622"><a name="b1286061844165622"></a><a name="b1286061844165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1016098973165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p814282104165622"><a name="p814282104165622"></a><a name="p814282104165622"></a><a href="math.md#ga3ace56b4f2a4a9364993a5af676793c5">asinl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p509083802165622"><a name="p509083802165622"></a><a name="p509083802165622"></a>long double </p>
<p id="p1920582340165622"><a name="p1920582340165622"></a><a name="p1920582340165622"></a>Calculates the arc sine of the long double value <strong id="b1584446309165622"><a name="b1584446309165622"></a><a name="b1584446309165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row585860603165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1706764553165622"><a name="p1706764553165622"></a><a name="p1706764553165622"></a><a href="math.md#ga907297107e93ea9c8a0c8409a8e65079">asinh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338788138165622"><a name="p338788138165622"></a><a name="p338788138165622"></a>double </p>
<p id="p522943126165622"><a name="p522943126165622"></a><a name="p522943126165622"></a>Calculates the inverse hyperbolic sine of the double value <strong id="b1245843313165622"><a name="b1245843313165622"></a><a name="b1245843313165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row876228184165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654155167165622"><a name="p654155167165622"></a><a name="p654155167165622"></a><a href="math.md#ga1131c65ac49f31ed6774d27106c6394d">asinhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953692413165622"><a name="p1953692413165622"></a><a name="p1953692413165622"></a>float </p>
<p id="p65990006165622"><a name="p65990006165622"></a><a name="p65990006165622"></a>Calculates the inverse hyperbolic sine of the float value <strong id="b77564810165622"><a name="b77564810165622"></a><a name="b77564810165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row789244666165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1728401412165622"><a name="p1728401412165622"></a><a name="p1728401412165622"></a><a href="math.md#ga98df355372e19c11634992e4b7e35784">asinhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p477148246165622"><a name="p477148246165622"></a><a name="p477148246165622"></a>long double </p>
<p id="p1507107356165622"><a name="p1507107356165622"></a><a name="p1507107356165622"></a>Calculates the inverse hyperbolic sine of the long double value <strong id="b16440306165622"><a name="b16440306165622"></a><a name="b16440306165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1347885152165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1613358436165622"><a name="p1613358436165622"></a><a name="p1613358436165622"></a><a href="math.md#ga1e2f8f6d64eaa95131bc63fee34970ea">atan</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1042394010165622"><a name="p1042394010165622"></a><a name="p1042394010165622"></a>double </p>
<p id="p582873713165622"><a name="p582873713165622"></a><a name="p582873713165622"></a>Calculates the arc tangent of the double value <strong id="b584885896165622"><a name="b584885896165622"></a><a name="b584885896165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row984555063165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1270066364165622"><a name="p1270066364165622"></a><a name="p1270066364165622"></a><a href="math.md#gaa582bc257e477e805f4ec384a39a3a8e">atanf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377241074165622"><a name="p1377241074165622"></a><a name="p1377241074165622"></a>float </p>
<p id="p85337579165622"><a name="p85337579165622"></a><a name="p85337579165622"></a>Calculates the arc tangent of the float value <strong id="b1589345923165622"><a name="b1589345923165622"></a><a name="b1589345923165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row998505845165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2024382575165622"><a name="p2024382575165622"></a><a name="p2024382575165622"></a><a href="math.md#ga650d8dd23c16c6699d84651a18827d37">atanl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1059446131165622"><a name="p1059446131165622"></a><a name="p1059446131165622"></a>long double </p>
<p id="p2142112822165622"><a name="p2142112822165622"></a><a name="p2142112822165622"></a>Calculates the arc tangent of the long double value <strong id="b454156590165622"><a name="b454156590165622"></a><a name="b454156590165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1480646718165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155925611165622"><a name="p155925611165622"></a><a name="p155925611165622"></a><a href="math.md#ga349377202ca14f79eb335b1a421fe4d8">atan2</a> (double y, double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846653752165622"><a name="p846653752165622"></a><a name="p846653752165622"></a>double </p>
<p id="p572246746165622"><a name="p572246746165622"></a><a name="p572246746165622"></a>Calculates the arc tangent of two double values <strong id="b1591583322165622"><a name="b1591583322165622"></a><a name="b1591583322165622"></a>x</strong> and <strong id="b1120590014165622"><a name="b1120590014165622"></a><a name="b1120590014165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row127364674165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360430733165622"><a name="p1360430733165622"></a><a name="p1360430733165622"></a><a href="math.md#gaf9e5469acf7a7bf82f29d86a77f539d4">atan2f</a> (float y, float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1300980632165622"><a name="p1300980632165622"></a><a name="p1300980632165622"></a>float </p>
<p id="p430854965165622"><a name="p430854965165622"></a><a name="p430854965165622"></a>Calculates the arc tangent of two float values <strong id="b246794661165622"><a name="b246794661165622"></a><a name="b246794661165622"></a>x</strong> and <strong id="b1928296244165622"><a name="b1928296244165622"></a><a name="b1928296244165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1604719811165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1067887150165622"><a name="p1067887150165622"></a><a name="p1067887150165622"></a><a href="math.md#gaa983bf34c931b97d66be8b7bfd03dc48">atan2l</a> (long double y, long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1722542966165622"><a name="p1722542966165622"></a><a name="p1722542966165622"></a>long double </p>
<p id="p1429533187165622"><a name="p1429533187165622"></a><a name="p1429533187165622"></a>Calculates the arc tangent of two long double values <strong id="b1811407304165622"><a name="b1811407304165622"></a><a name="b1811407304165622"></a>x</strong> and <strong id="b367345274165622"><a name="b367345274165622"></a><a name="b367345274165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row23999717165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1068218951165622"><a name="p1068218951165622"></a><a name="p1068218951165622"></a><a href="math.md#gac07fd7b77fa341563abccf9efcc1a711">atanh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580632668165622"><a name="p580632668165622"></a><a name="p580632668165622"></a>double </p>
<p id="p1375341778165622"><a name="p1375341778165622"></a><a name="p1375341778165622"></a>Calculates the inverse hyperbolic tangent of the double value <strong id="b2050263362165622"><a name="b2050263362165622"></a><a name="b2050263362165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1047895851165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519895135165622"><a name="p1519895135165622"></a><a name="p1519895135165622"></a><a href="math.md#ga626d9d6644848e74188f37f0f3ddd4f4">atanhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629573046165622"><a name="p629573046165622"></a><a name="p629573046165622"></a>float </p>
<p id="p1393674978165622"><a name="p1393674978165622"></a><a name="p1393674978165622"></a>Calculates the inverse hyperbolic tangent of the float value <strong id="b742000643165622"><a name="b742000643165622"></a><a name="b742000643165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row26059155165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p763949391165622"><a name="p763949391165622"></a><a name="p763949391165622"></a><a href="math.md#gab25c31215118cd62672c38f80f010d66">atanhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p207038744165622"><a name="p207038744165622"></a><a name="p207038744165622"></a>long double </p>
<p id="p51517078165622"><a name="p51517078165622"></a><a name="p51517078165622"></a>Calculates the inverse hyperbolic tangent of the long double value <strong id="b1135737234165622"><a name="b1135737234165622"></a><a name="b1135737234165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row663161935165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633311187165622"><a name="p633311187165622"></a><a name="p633311187165622"></a><a href="math.md#ga8af00e2203928978e0242b4afd1d899f">cbrt</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2620163165622"><a name="p2620163165622"></a><a name="p2620163165622"></a>double </p>
<p id="p612405689165622"><a name="p612405689165622"></a><a name="p612405689165622"></a>Calculates the cube root of the double value <strong id="b641974914165622"><a name="b641974914165622"></a><a name="b641974914165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row892148843165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1820939335165622"><a name="p1820939335165622"></a><a name="p1820939335165622"></a><a href="math.md#ga396c6a553500a355627741e234045bf4">cbrtf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1741851139165622"><a name="p1741851139165622"></a><a name="p1741851139165622"></a>float </p>
<p id="p1153659551165622"><a name="p1153659551165622"></a><a name="p1153659551165622"></a>Calculates the cube root of the float value <strong id="b1533500425165622"><a name="b1533500425165622"></a><a name="b1533500425165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row275196240165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1499954386165622"><a name="p1499954386165622"></a><a name="p1499954386165622"></a><a href="math.md#ga521c2f4c10b7bb5363bad058ef56794c">cbrtl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1562870613165622"><a name="p1562870613165622"></a><a name="p1562870613165622"></a>long double </p>
<p id="p1514256440165622"><a name="p1514256440165622"></a><a name="p1514256440165622"></a>Calculates the cube root of the long double value <strong id="b1252121288165622"><a name="b1252121288165622"></a><a name="b1252121288165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row357885890165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131061121165622"><a name="p2131061121165622"></a><a name="p2131061121165622"></a><a href="math.md#ga1ea6d7b591132268abc2e843ababd084">ceil</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734471928165622"><a name="p1734471928165622"></a><a name="p1734471928165622"></a>double </p>
<p id="p1975580860165622"><a name="p1975580860165622"></a><a name="p1975580860165622"></a>Calculates the minimum integer greater than or equal to the double value <strong id="b358757682165622"><a name="b358757682165622"></a><a name="b358757682165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1922098846165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1968178032165622"><a name="p1968178032165622"></a><a name="p1968178032165622"></a><a href="math.md#ga8c1a8db0710bb3f25f643a0fca68fc60">ceilf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609905883165622"><a name="p609905883165622"></a><a name="p609905883165622"></a>float </p>
<p id="p392140284165622"><a name="p392140284165622"></a><a name="p392140284165622"></a>Calculates the minimum integer greater than or equal to the float value <strong id="b980341013165622"><a name="b980341013165622"></a><a name="b980341013165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row416012436165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1717535038165622"><a name="p1717535038165622"></a><a name="p1717535038165622"></a><a href="math.md#gae11b7781f057eb7ba5d7ed95be7fdbee">ceill</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723801904165622"><a name="p723801904165622"></a><a name="p723801904165622"></a>long double </p>
<p id="p902982046165622"><a name="p902982046165622"></a><a name="p902982046165622"></a>Calculates the minimum integer greater than or equal to the long double value <strong id="b504539801165622"><a name="b504539801165622"></a><a name="b504539801165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1948771690165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651218968165622"><a name="p1651218968165622"></a><a name="p1651218968165622"></a><a href="math.md#gad8d1296592a3e783acdd0de21ff58e2e">copysign</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766378640165622"><a name="p766378640165622"></a><a name="p766378640165622"></a>double </p>
<p id="p1604224059165622"><a name="p1604224059165622"></a><a name="p1604224059165622"></a>Generates a value by combining the magnitude of the double value <strong id="b2137194695165622"><a name="b2137194695165622"></a><a name="b2137194695165622"></a>x</strong> and the sign of the double value <strong id="b1838525810165622"><a name="b1838525810165622"></a><a name="b1838525810165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row105979614165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1931755180165622"><a name="p1931755180165622"></a><a name="p1931755180165622"></a><a href="math.md#gaf7eb976cc28d0a9a6f0827d01611f979">copysignf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2060970569165622"><a name="p2060970569165622"></a><a name="p2060970569165622"></a>float </p>
<p id="p711750503165622"><a name="p711750503165622"></a><a name="p711750503165622"></a>Generates a value by combining the magnitude of the float value <strong id="b1909769068165622"><a name="b1909769068165622"></a><a name="b1909769068165622"></a>x</strong> and the sign of the float value <strong id="b55397559165622"><a name="b55397559165622"></a><a name="b55397559165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1752145442165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080781040165622"><a name="p2080781040165622"></a><a name="p2080781040165622"></a><a href="math.md#gae60d4866e88abf023d92d33c6351ae6f">copysignl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301260352165622"><a name="p1301260352165622"></a><a name="p1301260352165622"></a>long double </p>
<p id="p156105380165622"><a name="p156105380165622"></a><a name="p156105380165622"></a>Generates a value by combining the magnitude of the long double value <strong id="b351734979165622"><a name="b351734979165622"></a><a name="b351734979165622"></a>x</strong> and the sign of the long double value <strong id="b95865934165622"><a name="b95865934165622"></a><a name="b95865934165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1038537323165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2100355051165622"><a name="p2100355051165622"></a><a name="p2100355051165622"></a><a href="math.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1350750342165622"><a name="p1350750342165622"></a><a name="p1350750342165622"></a>double </p>
<p id="p205751030165622"><a name="p205751030165622"></a><a name="p205751030165622"></a>Calculates the cosine of the double value <strong id="b16707749165622"><a name="b16707749165622"></a><a name="b16707749165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2102540196165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545577417165622"><a name="p545577417165622"></a><a name="p545577417165622"></a><a href="math.md#ga7b126b2344591e649c21c9ab0b8adb40">cosf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p817650160165622"><a name="p817650160165622"></a><a name="p817650160165622"></a>float </p>
<p id="p310609212165622"><a name="p310609212165622"></a><a name="p310609212165622"></a>Calculates the cosine of the float value <strong id="b1820347318165622"><a name="b1820347318165622"></a><a name="b1820347318165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1793156895165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845470431165622"><a name="p1845470431165622"></a><a name="p1845470431165622"></a><a href="math.md#ga659287f7399efa8d6bc66dc37c8e35f4">cosl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850545968165622"><a name="p1850545968165622"></a><a name="p1850545968165622"></a>long double </p>
<p id="p1558691881165622"><a name="p1558691881165622"></a><a name="p1558691881165622"></a>Calculates the cosine of the long double value <strong id="b842488175165622"><a name="b842488175165622"></a><a name="b842488175165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row447741398165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063981073165622"><a name="p2063981073165622"></a><a name="p2063981073165622"></a><a href="math.md#ga3795d3c1f1d30819be56da4e4d67f64b">cosh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p218853746165622"><a name="p218853746165622"></a><a name="p218853746165622"></a>double </p>
<p id="p846737726165622"><a name="p846737726165622"></a><a name="p846737726165622"></a>Calculates the hyperbolic cosine of the double value <strong id="b1781665265165622"><a name="b1781665265165622"></a><a name="b1781665265165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2132870466165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p712497025165622"><a name="p712497025165622"></a><a name="p712497025165622"></a><a href="math.md#ga498b368486b7ce8677820beeb78d8f66">coshf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143775534165622"><a name="p1143775534165622"></a><a name="p1143775534165622"></a>float </p>
<p id="p1764115171165622"><a name="p1764115171165622"></a><a name="p1764115171165622"></a>Calculates the hyperbolic cosine of the float value <strong id="b1832556108165622"><a name="b1832556108165622"></a><a name="b1832556108165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1256463430165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1797037199165622"><a name="p1797037199165622"></a><a name="p1797037199165622"></a><a href="math.md#ga57602cd20f8de2dceea4f05ffb516d82">coshl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p430818334165622"><a name="p430818334165622"></a><a name="p430818334165622"></a>long double </p>
<p id="p1185747052165622"><a name="p1185747052165622"></a><a name="p1185747052165622"></a>Calculates the hyperbolic cosine of the long double value <strong id="b223404852165622"><a name="b223404852165622"></a><a name="b223404852165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1192363735165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526335901165622"><a name="p1526335901165622"></a><a name="p1526335901165622"></a><a href="math.md#gaa8b35382a71885eed509a5f87bf5e266">erf</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2108760387165622"><a name="p2108760387165622"></a><a name="p2108760387165622"></a>double </p>
<p id="p201161546165622"><a name="p201161546165622"></a><a name="p201161546165622"></a>Calculates the error function of the double value <strong id="b787225378165622"><a name="b787225378165622"></a><a name="b787225378165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1084842208165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830036584165622"><a name="p830036584165622"></a><a name="p830036584165622"></a><a href="math.md#gaabebdd2dd548c14805831297ac129862">erff</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p738635469165622"><a name="p738635469165622"></a><a name="p738635469165622"></a>float </p>
<p id="p1986719495165622"><a name="p1986719495165622"></a><a name="p1986719495165622"></a>Calculates the error function of the float value <strong id="b1886003898165622"><a name="b1886003898165622"></a><a name="b1886003898165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row181485686165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p926103114165622"><a name="p926103114165622"></a><a name="p926103114165622"></a><a href="math.md#ga6ccdcbbc2f0b22de2add8955e415170e">erfl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671365783165622"><a name="p1671365783165622"></a><a name="p1671365783165622"></a>long double </p>
<p id="p2058312772165622"><a name="p2058312772165622"></a><a name="p2058312772165622"></a>Calculates the error function of the long double value <strong id="b877799134165622"><a name="b877799134165622"></a><a name="b877799134165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1476316078165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641027042165622"><a name="p1641027042165622"></a><a name="p1641027042165622"></a><a href="math.md#ga0b6c4cfae41124da64c9a2dcc09e6045">erfc</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p305451875165622"><a name="p305451875165622"></a><a name="p305451875165622"></a>double </p>
<p id="p2067582365165622"><a name="p2067582365165622"></a><a name="p2067582365165622"></a>Calculates the complementary error function of the double value <strong id="b1171299196165622"><a name="b1171299196165622"></a><a name="b1171299196165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row223104224165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p766524420165622"><a name="p766524420165622"></a><a name="p766524420165622"></a><a href="math.md#gad948b9d3bfcb66c074ffe17326030d41">erfcf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271709405165622"><a name="p1271709405165622"></a><a name="p1271709405165622"></a>float </p>
<p id="p997206464165622"><a name="p997206464165622"></a><a name="p997206464165622"></a>Calculates the complementary error function of the float value <strong id="b677802595165622"><a name="b677802595165622"></a><a name="b677802595165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row181950044165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018074582165622"><a name="p2018074582165622"></a><a name="p2018074582165622"></a><a href="math.md#ga8ac2c9e0246c0c8106d04762a9623594">erfcl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1470871786165622"><a name="p1470871786165622"></a><a name="p1470871786165622"></a>long double </p>
<p id="p2128945719165622"><a name="p2128945719165622"></a><a name="p2128945719165622"></a>Calculates the complementary error function of the long double value <strong id="b445191123165622"><a name="b445191123165622"></a><a name="b445191123165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row383574874165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095766915165622"><a name="p2095766915165622"></a><a name="p2095766915165622"></a><a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p571039098165622"><a name="p571039098165622"></a><a name="p571039098165622"></a>double </p>
<p id="p1800567827165622"><a name="p1800567827165622"></a><a name="p1800567827165622"></a>Calculates the base-e exponential function of the double value <strong id="b915480337165622"><a name="b915480337165622"></a><a name="b915480337165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1617716152165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1309870575165622"><a name="p1309870575165622"></a><a name="p1309870575165622"></a><a href="math.md#ga0c2bc89b8355a89542ac98d9e2120363">expf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480869998165622"><a name="p1480869998165622"></a><a name="p1480869998165622"></a>float </p>
<p id="p1532608030165622"><a name="p1532608030165622"></a><a name="p1532608030165622"></a>Calculates the base-e exponential function of the float value <strong id="b1263734029165622"><a name="b1263734029165622"></a><a name="b1263734029165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2041798610165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237357619165622"><a name="p237357619165622"></a><a name="p237357619165622"></a><a href="math.md#gaed4eb11ef1397c751334311ce5b43920">expl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966124347165622"><a name="p1966124347165622"></a><a name="p1966124347165622"></a>long double </p>
<p id="p1843013686165622"><a name="p1843013686165622"></a><a name="p1843013686165622"></a>Calculates the base-e exponential function of the long double value <strong id="b340278905165622"><a name="b340278905165622"></a><a name="b340278905165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row180267995165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p176712936165622"><a name="p176712936165622"></a><a name="p176712936165622"></a><a href="math.md#ga86e37219434c0b7978453b6ca88fc5fb">exp2</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314443218165622"><a name="p1314443218165622"></a><a name="p1314443218165622"></a>double </p>
<p id="p305115367165622"><a name="p305115367165622"></a><a name="p305115367165622"></a>Calculates the base-2 exponential function of the double value <strong id="b1098037476165622"><a name="b1098037476165622"></a><a name="b1098037476165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row210335491165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816602369165622"><a name="p1816602369165622"></a><a name="p1816602369165622"></a><a href="math.md#gaed26c6708ff2027f9a8214d206eef0e7">exp2f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068356528165622"><a name="p1068356528165622"></a><a name="p1068356528165622"></a>float </p>
<p id="p1306338722165622"><a name="p1306338722165622"></a><a name="p1306338722165622"></a>Calculates the base-2 exponential function of the float value <strong id="b631746312165622"><a name="b631746312165622"></a><a name="b631746312165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2140682921165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560392919165622"><a name="p560392919165622"></a><a name="p560392919165622"></a><a href="math.md#ga4618e032de8318b72df5cc71f15b5e45">exp2l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1374169182165622"><a name="p1374169182165622"></a><a name="p1374169182165622"></a>long double </p>
<p id="p643022015165622"><a name="p643022015165622"></a><a name="p643022015165622"></a>Calculates the base-2 exponential function of the long double value <strong id="b1075989091165622"><a name="b1075989091165622"></a><a name="b1075989091165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1186040563165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809555201165622"><a name="p1809555201165622"></a><a name="p1809555201165622"></a><a href="math.md#gae4963ac40f96d4b1fe8af1b1e90a20bb">expm1</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2056892450165622"><a name="p2056892450165622"></a><a name="p2056892450165622"></a>double </p>
<p id="p663572131165622"><a name="p663572131165622"></a><a name="p663572131165622"></a>Calculates e raised to the power of the double value <strong id="b888376293165622"><a name="b888376293165622"></a><a name="b888376293165622"></a>x</strong> minus one, that is, (e^x)-1. </p>
</td>
</tr>
<tr id="row653627100165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853388020165622"><a name="p853388020165622"></a><a name="p853388020165622"></a><a href="math.md#ga5b8d8815f5c801fdbdb7f7767fbf9af4">expm1f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113891408165622"><a name="p113891408165622"></a><a name="p113891408165622"></a>float </p>
<p id="p1338652506165622"><a name="p1338652506165622"></a><a name="p1338652506165622"></a>Calculates e raised to the power of the float value <strong id="b1200881955165622"><a name="b1200881955165622"></a><a name="b1200881955165622"></a>x</strong> minus one. </p>
</td>
</tr>
<tr id="row339848663165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1436019836165622"><a name="p1436019836165622"></a><a name="p1436019836165622"></a><a href="math.md#ga702b0680671cf9ef94017ac04f77358b">expm1l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844014626165622"><a name="p844014626165622"></a><a name="p844014626165622"></a>long double </p>
<p id="p1340224966165622"><a name="p1340224966165622"></a><a name="p1340224966165622"></a>Calculates e raised to the power of the long double value <strong id="b843886993165622"><a name="b843886993165622"></a><a name="b843886993165622"></a>x</strong> minus one. </p>
</td>
</tr>
<tr id="row587784767165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893285577165622"><a name="p893285577165622"></a><a name="p893285577165622"></a><a href="math.md#ga8fb5c0b9b43a108724b355136d29d2f9">fabs</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p255020289165622"><a name="p255020289165622"></a><a name="p255020289165622"></a>double </p>
<p id="p1628913974165622"><a name="p1628913974165622"></a><a name="p1628913974165622"></a>Calculates the absolute value of the double value <strong id="b1022335722165622"><a name="b1022335722165622"></a><a name="b1022335722165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row81196648165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709239637165622"><a name="p1709239637165622"></a><a name="p1709239637165622"></a><a href="math.md#ga9b02e2f3ebf257ac4f4d3ca1da6147d7">fabsf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962847814165622"><a name="p962847814165622"></a><a name="p962847814165622"></a>float </p>
<p id="p1777221693165622"><a name="p1777221693165622"></a><a name="p1777221693165622"></a>Calculates the absolute value of the float value <strong id="b1375751092165622"><a name="b1375751092165622"></a><a name="b1375751092165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1971352656165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661460165165622"><a name="p1661460165165622"></a><a name="p1661460165165622"></a><a href="math.md#ga404c051ab9afd74c7ceed207683a235f">fabsl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609846000165622"><a name="p609846000165622"></a><a name="p609846000165622"></a>long double </p>
<p id="p1898004405165622"><a name="p1898004405165622"></a><a name="p1898004405165622"></a>Calculates the absolute value of the long double value <strong id="b2030114299165622"><a name="b2030114299165622"></a><a name="b2030114299165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1958320965165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725876175165622"><a name="p1725876175165622"></a><a name="p1725876175165622"></a><a href="math.md#ga800522810eaaed28bd53798bff4b0bfa">fdim</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731658734165622"><a name="p731658734165622"></a><a name="p731658734165622"></a>double </p>
<p id="p17507970165622"><a name="p17507970165622"></a><a name="p17507970165622"></a>Calculates the positive difference between the double value <strong id="b2073980053165622"><a name="b2073980053165622"></a><a name="b2073980053165622"></a>x</strong> and <strong id="b1400709735165622"><a name="b1400709735165622"></a><a name="b1400709735165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row994312980165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p571376564165622"><a name="p571376564165622"></a><a name="p571376564165622"></a><a href="math.md#gaeee3a0bf2804c53c65199590ac4804cf">fdimf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1722807253165622"><a name="p1722807253165622"></a><a name="p1722807253165622"></a>float </p>
<p id="p1942392163165622"><a name="p1942392163165622"></a><a name="p1942392163165622"></a>Calculates the positive difference between the float value <strong id="b996414397165622"><a name="b996414397165622"></a><a name="b996414397165622"></a>x</strong> and <strong id="b232664043165622"><a name="b232664043165622"></a><a name="b232664043165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row836667165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200986018165622"><a name="p200986018165622"></a><a name="p200986018165622"></a><a href="math.md#gab88ba65d1861deddbbc5cb5384d6a02e">fdiml</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825929854165622"><a name="p825929854165622"></a><a name="p825929854165622"></a>long double </p>
<p id="p1331888563165622"><a name="p1331888563165622"></a><a name="p1331888563165622"></a>Calculates the positive difference between the long double value <strong id="b2115633765165622"><a name="b2115633765165622"></a><a name="b2115633765165622"></a>x</strong> and <strong id="b797498479165622"><a name="b797498479165622"></a><a name="b797498479165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row426382233165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p250567377165622"><a name="p250567377165622"></a><a name="p250567377165622"></a><a href="math.md#ga6de60a3e907dcf0bfe3ea8d64f1e8873">floor</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290236167165622"><a name="p290236167165622"></a><a name="p290236167165622"></a>double </p>
<p id="p236788034165622"><a name="p236788034165622"></a><a name="p236788034165622"></a>Obtains the largest integer less than or equal to the double value <strong id="b1415620846165622"><a name="b1415620846165622"></a><a name="b1415620846165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row611509582165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1188068595165622"><a name="p1188068595165622"></a><a name="p1188068595165622"></a><a href="math.md#ga0bcc6aa4b3c37bfa73f06ebdecc0d247">floorf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603358158165622"><a name="p1603358158165622"></a><a name="p1603358158165622"></a>float </p>
<p id="p940840568165622"><a name="p940840568165622"></a><a name="p940840568165622"></a>Obtains the largest integer less than or equal to the float value <strong id="b1441641457165622"><a name="b1441641457165622"></a><a name="b1441641457165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row160640740165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526311235165622"><a name="p1526311235165622"></a><a name="p1526311235165622"></a><a href="math.md#ga211df53cdf5208b9bbfa92e2d9aef97f">floorl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1819953103165622"><a name="p1819953103165622"></a><a name="p1819953103165622"></a>long double </p>
<p id="p154309619165622"><a name="p154309619165622"></a><a name="p154309619165622"></a>Obtains the largest integer less than or equal to the long double value <strong id="b299984534165622"><a name="b299984534165622"></a><a name="b299984534165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1574742349165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406842673165622"><a name="p1406842673165622"></a><a name="p1406842673165622"></a><a href="math.md#gac6df7bd41d198a70da3915a80de5452d">fma</a> (double x, double y, double z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957732903165622"><a name="p957732903165622"></a><a name="p957732903165622"></a>double </p>
<p id="p1135682765165622"><a name="p1135682765165622"></a><a name="p1135682765165622"></a>Calculates the value of <strong id="b1256457282165622"><a name="b1256457282165622"></a><a name="b1256457282165622"></a>x*y+z</strong> and rounds the result up. </p>
</td>
</tr>
<tr id="row235622134165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p572843514165622"><a name="p572843514165622"></a><a name="p572843514165622"></a><a href="math.md#gaa6b32a0b7f88680bb59bcfb9c6168ed2">fmaf</a> (float x, float y, float z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406467612165622"><a name="p406467612165622"></a><a name="p406467612165622"></a>float </p>
<p id="p1645150242165622"><a name="p1645150242165622"></a><a name="p1645150242165622"></a>Calculates the value of <strong id="b1684794074165622"><a name="b1684794074165622"></a><a name="b1684794074165622"></a>x*y+z</strong> and rounds the result up. </p>
</td>
</tr>
<tr id="row233558158165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1580042685165622"><a name="p1580042685165622"></a><a name="p1580042685165622"></a><a href="math.md#gaf30b6b26252979964796ffa55dd30120">fmal</a> (long double x, long double y, long double z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1376747458165622"><a name="p1376747458165622"></a><a name="p1376747458165622"></a>long double </p>
<p id="p372970349165622"><a name="p372970349165622"></a><a name="p372970349165622"></a>Calculates the value of <strong id="b192757880165622"><a name="b192757880165622"></a><a name="b192757880165622"></a>x*y+z</strong> and rounds the result up. </p>
</td>
</tr>
<tr id="row700554627165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806387191165622"><a name="p806387191165622"></a><a name="p806387191165622"></a><a href="math.md#ga35e041615ac931b4d848a7b173049301">fmax</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1974155587165622"><a name="p1974155587165622"></a><a name="p1974155587165622"></a>double </p>
<p id="p1925178131165622"><a name="p1925178131165622"></a><a name="p1925178131165622"></a>Obtains the larger value of two double values <strong id="b1125967875165622"><a name="b1125967875165622"></a><a name="b1125967875165622"></a>x</strong> and <strong id="b296148944165622"><a name="b296148944165622"></a><a name="b296148944165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1848793458165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p266159564165622"><a name="p266159564165622"></a><a name="p266159564165622"></a><a href="math.md#ga8849bfdbec18ded429fad4772cf60f4b">fmaxf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141658221165622"><a name="p1141658221165622"></a><a name="p1141658221165622"></a>float </p>
<p id="p1574625490165622"><a name="p1574625490165622"></a><a name="p1574625490165622"></a>Obtains the larger value of two float values <strong id="b597340161165622"><a name="b597340161165622"></a><a name="b597340161165622"></a>x</strong> and <strong id="b1582254505165622"><a name="b1582254505165622"></a><a name="b1582254505165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row392574522165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p80919783165622"><a name="p80919783165622"></a><a name="p80919783165622"></a><a href="math.md#ga0e31e170115494fdc03b6556844232f3">fmaxl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055275064165622"><a name="p1055275064165622"></a><a name="p1055275064165622"></a>long double </p>
<p id="p1173607514165622"><a name="p1173607514165622"></a><a name="p1173607514165622"></a>Obtains the larger value of two long double values <strong id="b1979453087165622"><a name="b1979453087165622"></a><a name="b1979453087165622"></a>x</strong> and <strong id="b1157359822165622"><a name="b1157359822165622"></a><a name="b1157359822165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1477204390165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p651732722165622"><a name="p651732722165622"></a><a name="p651732722165622"></a><a href="math.md#gaf0a18b3ac9e461ac48b4cfffb4945a84">fmin</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922351068165622"><a name="p1922351068165622"></a><a name="p1922351068165622"></a>double </p>
<p id="p1294031727165622"><a name="p1294031727165622"></a><a name="p1294031727165622"></a>Obtains the smaller value of two double values <strong id="b435143933165622"><a name="b435143933165622"></a><a name="b435143933165622"></a>x</strong> and <strong id="b464830560165622"><a name="b464830560165622"></a><a name="b464830560165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1438657467165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296724322165622"><a name="p1296724322165622"></a><a name="p1296724322165622"></a><a href="math.md#ga9b4132c27f31d39c91c3c6063f378103">fminf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844635902165622"><a name="p844635902165622"></a><a name="p844635902165622"></a>float </p>
<p id="p558686556165622"><a name="p558686556165622"></a><a name="p558686556165622"></a>Obtains the smaller value of two float values <strong id="b1737554684165622"><a name="b1737554684165622"></a><a name="b1737554684165622"></a>x</strong> and <strong id="b499495975165622"><a name="b499495975165622"></a><a name="b499495975165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row960495316165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1672512302165622"><a name="p1672512302165622"></a><a name="p1672512302165622"></a><a href="math.md#ga8a301190384886aa4e327db265fb5c9f">fminl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p548505794165622"><a name="p548505794165622"></a><a name="p548505794165622"></a>long double </p>
<p id="p1893749891165622"><a name="p1893749891165622"></a><a name="p1893749891165622"></a>Obtains the smaller value of two long double values <strong id="b1306883165622"><a name="b1306883165622"></a><a name="b1306883165622"></a>x</strong> and <strong id="b768198466165622"><a name="b768198466165622"></a><a name="b768198466165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1892193907165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279970237165622"><a name="p1279970237165622"></a><a name="p1279970237165622"></a><a href="math.md#ga537296d1a8f9fb621676038b99ba7edf">fmod</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034325484165622"><a name="p2034325484165622"></a><a name="p2034325484165622"></a>double </p>
<p id="p1620273259165622"><a name="p1620273259165622"></a><a name="p1620273259165622"></a>Calculates the remainder of the double value <strong id="b2083882310165622"><a name="b2083882310165622"></a><a name="b2083882310165622"></a>x</strong> divided by the double value <strong id="b1796466268165622"><a name="b1796466268165622"></a><a name="b1796466268165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row529312735165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p852683259165622"><a name="p852683259165622"></a><a name="p852683259165622"></a><a href="math.md#gaf17ec425baca2b5f3882a05b5e19dfb5">fmodf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p478674560165622"><a name="p478674560165622"></a><a name="p478674560165622"></a>float </p>
<p id="p395724277165622"><a name="p395724277165622"></a><a name="p395724277165622"></a>Calculates the remainder of the float value <strong id="b174079261165622"><a name="b174079261165622"></a><a name="b174079261165622"></a>x</strong> divided by the float value <strong id="b798675832165622"><a name="b798675832165622"></a><a name="b798675832165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1665410539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1914173551165622"><a name="p1914173551165622"></a><a name="p1914173551165622"></a><a href="math.md#gaa927d9996fb40db42bd3a6cbe57da9a7">fmodl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808471866165622"><a name="p808471866165622"></a><a name="p808471866165622"></a>long double </p>
<p id="p188684485165622"><a name="p188684485165622"></a><a name="p188684485165622"></a>Calculates the remainder of the long double value <strong id="b1636606216165622"><a name="b1636606216165622"></a><a name="b1636606216165622"></a>x</strong> divided by the long double value <strong id="b1123938743165622"><a name="b1123938743165622"></a><a name="b1123938743165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1665460059165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1689174667165622"><a name="p1689174667165622"></a><a name="p1689174667165622"></a><a href="math.md#gae3fa88adf02f16a693f3dccea3c42ef0">frexp</a> (double x, int *<a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541811635165622"><a name="p1541811635165622"></a><a name="p1541811635165622"></a>double </p>
<p id="p1001868328165622"><a name="p1001868328165622"></a><a name="p1001868328165622"></a>Decomposes the double value <strong id="b1619806377165622"><a name="b1619806377165622"></a><a name="b1619806377165622"></a>x</strong> into a significand and an integral exponent for 2. </p>
</td>
</tr>
<tr id="row1280304800165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041369146165622"><a name="p1041369146165622"></a><a name="p1041369146165622"></a><a href="math.md#ga12c36e745d8a9eb4f01c7e0eeb426dd3">frexpf</a> (float x, int *<a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1049797414165622"><a name="p1049797414165622"></a><a name="p1049797414165622"></a>float </p>
<p id="p1060190545165622"><a name="p1060190545165622"></a><a name="p1060190545165622"></a>Decomposes float value <strong id="b1508801771165622"><a name="b1508801771165622"></a><a name="b1508801771165622"></a>x</strong> into a binary significand and an integral exponent for 2. </p>
</td>
</tr>
<tr id="row788137210165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502119107165622"><a name="p1502119107165622"></a><a name="p1502119107165622"></a><a href="math.md#ga239d50c0595ff8538b9aa3186ac4fd29">frexpl</a> (long double x, int *<a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343909867165622"><a name="p343909867165622"></a><a name="p343909867165622"></a>long double </p>
<p id="p69647900165622"><a name="p69647900165622"></a><a name="p69647900165622"></a>Decomposes long double value <strong id="b28575655165622"><a name="b28575655165622"></a><a name="b28575655165622"></a>x</strong> into a binary significand and an integral exponent for 2. </p>
</td>
</tr>
<tr id="row598869726165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p353639155165622"><a name="p353639155165622"></a><a name="p353639155165622"></a><a href="math.md#ga6d6a905f61d535f8454190433b8c0ea5">hypot</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2063192387165622"><a name="p2063192387165622"></a><a name="p2063192387165622"></a>double </p>
<p id="p1231209575165622"><a name="p1231209575165622"></a><a name="p1231209575165622"></a>Calculates the hypotenuse of a right triangle whose legs are <strong id="b1711242870165622"><a name="b1711242870165622"></a><a name="b1711242870165622"></a>x</strong> and <strong id="b875888139165622"><a name="b875888139165622"></a><a name="b875888139165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row144056165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146384856165622"><a name="p146384856165622"></a><a name="p146384856165622"></a><a href="math.md#ga9fa4a03d7c4abfda7d9ad7b6ff7f6456">hypotf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820469778165622"><a name="p820469778165622"></a><a name="p820469778165622"></a>float </p>
<p id="p1752060360165622"><a name="p1752060360165622"></a><a name="p1752060360165622"></a>Calculates the hypotenuse of a right triangle whose legs are <strong id="b1432128945165622"><a name="b1432128945165622"></a><a name="b1432128945165622"></a>x</strong> and <strong id="b1850861151165622"><a name="b1850861151165622"></a><a name="b1850861151165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row314996997165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p574449538165622"><a name="p574449538165622"></a><a name="p574449538165622"></a><a href="math.md#ga92a0e76d17c34fc1b3b2e7c0868aea6e">hypotl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480232610165622"><a name="p480232610165622"></a><a name="p480232610165622"></a>long double </p>
<p id="p1945576089165622"><a name="p1945576089165622"></a><a name="p1945576089165622"></a>Calculates the hypotenuse of a right triangle whose legs are <strong id="b513132040165622"><a name="b513132040165622"></a><a name="b513132040165622"></a>x</strong> and <strong id="b1419858286165622"><a name="b1419858286165622"></a><a name="b1419858286165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1717270345165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2141182052165622"><a name="p2141182052165622"></a><a name="p2141182052165622"></a><a href="math.md#ga600dd249210d15af31b9a29c2d09d255">ilogb</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140598889165622"><a name="p2140598889165622"></a><a name="p2140598889165622"></a>int </p>
<p id="p1767009568165622"><a name="p1767009568165622"></a><a name="p1767009568165622"></a>Obtains the integral part of the logarithm of double value <strong id="b187293658165622"><a name="b187293658165622"></a><a name="b187293658165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row437730588165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468105252165622"><a name="p1468105252165622"></a><a name="p1468105252165622"></a><a href="math.md#gaf53f0f07bb80b1a38fb47773a190e7a7">ilogbf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966758666165622"><a name="p966758666165622"></a><a name="p966758666165622"></a>int </p>
<p id="p1163378775165622"><a name="p1163378775165622"></a><a name="p1163378775165622"></a>Obtains the integral part of the logarithm of float value <strong id="b579084034165622"><a name="b579084034165622"></a><a name="b579084034165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1385471518165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139974184165622"><a name="p139974184165622"></a><a name="p139974184165622"></a><a href="math.md#gafbd166ed232a372f090b8f9fa8441423">ilogbl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1073628137165622"><a name="p1073628137165622"></a><a name="p1073628137165622"></a>int </p>
<p id="p21385045165622"><a name="p21385045165622"></a><a name="p21385045165622"></a>Obtains the integral part of the logarithm of the long double value <strong id="b63999591165622"><a name="b63999591165622"></a><a name="b63999591165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1587470540165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303588439165622"><a name="p1303588439165622"></a><a name="p1303588439165622"></a><a href="math.md#gab3662815756f0bd419dc1b12f4ad905d">ldexp</a> (double x, int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941830172165622"><a name="p941830172165622"></a><a name="p941830172165622"></a>double </p>
<p id="p948271604165622"><a name="p948271604165622"></a><a name="p948271604165622"></a>Multiplies the double value <strong id="b1192989446165622"><a name="b1192989446165622"></a><a name="b1192989446165622"></a>x</strong> by 2 raised to the power of <strong id="b353500624165622"><a name="b353500624165622"></a><a name="b353500624165622"></a>exp</strong>. </p>
</td>
</tr>
<tr id="row1371134896165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191617761165622"><a name="p191617761165622"></a><a name="p191617761165622"></a><a href="math.md#gaacd370a7830c29f47239dea1ea2eb7f9">ldexpf</a> (float x, int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173789949165622"><a name="p1173789949165622"></a><a name="p1173789949165622"></a>float </p>
<p id="p269389208165622"><a name="p269389208165622"></a><a name="p269389208165622"></a>Multiplies the float value <strong id="b1532213730165622"><a name="b1532213730165622"></a><a name="b1532213730165622"></a>x</strong> by 2 raised to the power of <strong id="b1010977689165622"><a name="b1010977689165622"></a><a name="b1010977689165622"></a>exp</strong>. </p>
</td>
</tr>
<tr id="row802777145165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p939658006165622"><a name="p939658006165622"></a><a name="p939658006165622"></a><a href="math.md#ga454187039ef790629dab1e7724c3c3b2">ldexpl</a> (long double x, int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292761000165622"><a name="p1292761000165622"></a><a name="p1292761000165622"></a>long double </p>
<p id="p1724107972165622"><a name="p1724107972165622"></a><a name="p1724107972165622"></a>Multiplies the long double value <strong id="b807469536165622"><a name="b807469536165622"></a><a name="b807469536165622"></a>x</strong> by 2 raised to the power of <strong id="b2072446531165622"><a name="b2072446531165622"></a><a name="b2072446531165622"></a>exp</strong>. </p>
</td>
</tr>
<tr id="row1369334975165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485166328165622"><a name="p1485166328165622"></a><a name="p1485166328165622"></a><a href="math.md#gacd3ebe923fa039624f0b7de3320816bf">lgamma</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756720947165622"><a name="p756720947165622"></a><a name="p756720947165622"></a>double </p>
<p id="p1774199976165622"><a name="p1774199976165622"></a><a name="p1774199976165622"></a>Calculates the natural logarithm of the absolute value of the gamma function of the double value <strong id="b912811793165622"><a name="b912811793165622"></a><a name="b912811793165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row262835881165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957607363165622"><a name="p1957607363165622"></a><a name="p1957607363165622"></a><a href="math.md#ga5900f7bf0093757f1ba36b5940b1e10b">lgammaf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143208284165622"><a name="p143208284165622"></a><a name="p143208284165622"></a>float </p>
<p id="p1119603571165622"><a name="p1119603571165622"></a><a name="p1119603571165622"></a>Calculates the natural logarithm of the absolute value of the gamma function of the float value <strong id="b295617766165622"><a name="b295617766165622"></a><a name="b295617766165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1047069165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p350517843165622"><a name="p350517843165622"></a><a name="p350517843165622"></a><a href="math.md#ga4dafd3eb6952c8daabe8a98f4a64a7df">lgammal</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p331762578165622"><a name="p331762578165622"></a><a name="p331762578165622"></a>long double </p>
<p id="p1688600476165622"><a name="p1688600476165622"></a><a name="p1688600476165622"></a>Calculates the natural logarithm of the absolute value of the gamma function of the long double value <strong id="b1573285196165622"><a name="b1573285196165622"></a><a name="b1573285196165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row452548150165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279645546165622"><a name="p1279645546165622"></a><a name="p1279645546165622"></a><a href="math.md#ga64a4201c82f6ee7043a270bbbc6a5e19">llrint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459622518165622"><a name="p459622518165622"></a><a name="p459622518165622"></a>long long int </p>
<p id="p1039875664165622"><a name="p1039875664165622"></a><a name="p1039875664165622"></a>Rounds double value <strong id="b300987557165622"><a name="b300987557165622"></a><a name="b300987557165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1368506501165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1717186864165622"><a name="p1717186864165622"></a><a name="p1717186864165622"></a><a href="math.md#ga33d95711621def731d3f88c4e606323e">llrintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118106933165622"><a name="p118106933165622"></a><a name="p118106933165622"></a>long long int </p>
<p id="p199454293165622"><a name="p199454293165622"></a><a name="p199454293165622"></a>Rounds float value <strong id="b802443484165622"><a name="b802443484165622"></a><a name="b802443484165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row984789098165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p104388202165622"><a name="p104388202165622"></a><a name="p104388202165622"></a><a href="math.md#ga20e0da115f76608eff4695177f2f605a">llrintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438795092165622"><a name="p438795092165622"></a><a name="p438795092165622"></a>long long int </p>
<p id="p321052193165622"><a name="p321052193165622"></a><a name="p321052193165622"></a>Rounds long double value <strong id="b2130922710165622"><a name="b2130922710165622"></a><a name="b2130922710165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row2114766079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p646388959165622"><a name="p646388959165622"></a><a name="p646388959165622"></a><a href="math.md#ga3e4957daeecea4e616ed1f1870fe4f31">llround</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135318131165622"><a name="p135318131165622"></a><a name="p135318131165622"></a>long long int </p>
<p id="p1525028112165622"><a name="p1525028112165622"></a><a name="p1525028112165622"></a>Rounds double value <strong id="b1025647538165622"><a name="b1025647538165622"></a><a name="b1025647538165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b1768045811165622"><a name="b1768045811165622"></a><a name="b1768045811165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row160181018165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967202753165622"><a name="p967202753165622"></a><a name="p967202753165622"></a><a href="math.md#ga8259999687e8bd4b5509ca0d69b0ad9d">llroundf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641262459165622"><a name="p641262459165622"></a><a name="p641262459165622"></a>long long int </p>
<p id="p1160070918165622"><a name="p1160070918165622"></a><a name="p1160070918165622"></a>Rounds float value <strong id="b710681110165622"><a name="b710681110165622"></a><a name="b710681110165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b1710056382165622"><a name="b1710056382165622"></a><a name="b1710056382165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1376215214165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669281618165622"><a name="p669281618165622"></a><a name="p669281618165622"></a><a href="math.md#ga82a6d70a29e839514b93bb0699f07bbe">llroundl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1265152045165622"><a name="p1265152045165622"></a><a name="p1265152045165622"></a>long long int </p>
<p id="p1112634317165622"><a name="p1112634317165622"></a><a name="p1112634317165622"></a>Rounds long double value <strong id="b1566671060165622"><a name="b1566671060165622"></a><a name="b1566671060165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b1293303292165622"><a name="b1293303292165622"></a><a name="b1293303292165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1662908197165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12243469165622"><a name="p12243469165622"></a><a name="p12243469165622"></a><a href="math.md#gadb302c9aafbaa5e180d9f60ee954bb82">log</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619347960165622"><a name="p1619347960165622"></a><a name="p1619347960165622"></a>double </p>
<p id="p1764739778165622"><a name="p1764739778165622"></a><a name="p1764739778165622"></a>Calculates the natural logarithm of the double value <strong id="b89425233165622"><a name="b89425233165622"></a><a name="b89425233165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1564877997165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34398367165622"><a name="p34398367165622"></a><a name="p34398367165622"></a><a href="math.md#ga8246b3e17a39b137d0c62670d0c6e336">logf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259219990165622"><a name="p1259219990165622"></a><a name="p1259219990165622"></a>float </p>
<p id="p311872328165622"><a name="p311872328165622"></a><a name="p311872328165622"></a>Calculates the natural logarithm of the float value <strong id="b51292033165622"><a name="b51292033165622"></a><a name="b51292033165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row692114856165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102790645165622"><a name="p2102790645165622"></a><a name="p2102790645165622"></a><a href="math.md#gaf67da1c28ce33b403f955103f201dfb8">logl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239052770165622"><a name="p239052770165622"></a><a name="p239052770165622"></a>long double </p>
<p id="p1430412768165622"><a name="p1430412768165622"></a><a name="p1430412768165622"></a>Calculates the natural logarithm of the long double value <strong id="b19963596165622"><a name="b19963596165622"></a><a name="b19963596165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row25592832165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016833002165622"><a name="p2016833002165622"></a><a name="p2016833002165622"></a><a href="math.md#ga6572e82a4891917a9ba7fb2a964f8182">log10</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870834913165622"><a name="p1870834913165622"></a><a name="p1870834913165622"></a>double </p>
<p id="p640360710165622"><a name="p640360710165622"></a><a name="p640360710165622"></a>Calculates the common logarithm (logarithm with base 10) of the double value <strong id="b1306459583165622"><a name="b1306459583165622"></a><a name="b1306459583165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1226595386165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p561736453165622"><a name="p561736453165622"></a><a name="p561736453165622"></a><a href="math.md#gae207b1eb007a6c23394dcb6fc7f16adf">log10f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1396235115165622"><a name="p1396235115165622"></a><a name="p1396235115165622"></a>float </p>
<p id="p141260083165622"><a name="p141260083165622"></a><a name="p141260083165622"></a>Calculates the common logarithm (logarithm with base 10) of the float value <strong id="b1480074157165622"><a name="b1480074157165622"></a><a name="b1480074157165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row407816616165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1003219172165622"><a name="p1003219172165622"></a><a name="p1003219172165622"></a><a href="math.md#gae824e49a04221dcf66b9791c5df8d6b6">log10l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34433863165622"><a name="p34433863165622"></a><a name="p34433863165622"></a>long double </p>
<p id="p807943774165622"><a name="p807943774165622"></a><a name="p807943774165622"></a>Calculates the common logarithm (logarithm with base 10) of the long double value <strong id="b141003454165622"><a name="b141003454165622"></a><a name="b141003454165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row689988377165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p831825276165622"><a name="p831825276165622"></a><a name="p831825276165622"></a><a href="math.md#gac2aac20ab1347498e6e4f209148fea84">log1p</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1061463520165622"><a name="p1061463520165622"></a><a name="p1061463520165622"></a>double </p>
<p id="p2128496225165622"><a name="p2128496225165622"></a><a name="p2128496225165622"></a>Calculates the natural logarithm of one plus the double value <strong id="b1229328378165622"><a name="b1229328378165622"></a><a name="b1229328378165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row288637898165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335589751165622"><a name="p335589751165622"></a><a name="p335589751165622"></a><a href="math.md#gacbf820b74779ce35a3c726a3a62bc8ef">log1pf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36692060165622"><a name="p36692060165622"></a><a name="p36692060165622"></a>float </p>
<p id="p1915483402165622"><a name="p1915483402165622"></a><a name="p1915483402165622"></a>Calculates the natural logarithm of one plus the float value <strong id="b1144397985165622"><a name="b1144397985165622"></a><a name="b1144397985165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1881191906165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1754910340165622"><a name="p1754910340165622"></a><a name="p1754910340165622"></a><a href="math.md#ga2a632effaace01f30cba42725ae48dfa">log1pl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336260370165622"><a name="p1336260370165622"></a><a name="p1336260370165622"></a>long double </p>
<p id="p1378627984165622"><a name="p1378627984165622"></a><a name="p1378627984165622"></a>Calculates the natural logarithm of one plus the long double value <strong id="b42562266165622"><a name="b42562266165622"></a><a name="b42562266165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1496043857165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1996076191165622"><a name="p1996076191165622"></a><a name="p1996076191165622"></a><a href="math.md#ga38bd88274dc5594b4826fd60c8054c8e">log2</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612465751165622"><a name="p1612465751165622"></a><a name="p1612465751165622"></a>double </p>
<p id="p1770490884165622"><a name="p1770490884165622"></a><a name="p1770490884165622"></a>Calculates the binary logarithm (logarithm with base 2) of the double value <strong id="b1164953348165622"><a name="b1164953348165622"></a><a name="b1164953348165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row969353174165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p710011594165622"><a name="p710011594165622"></a><a name="p710011594165622"></a><a href="math.md#ga79fe62234001b88317245f7599158aaf">log2f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2102110723165622"><a name="p2102110723165622"></a><a name="p2102110723165622"></a>float </p>
<p id="p227819518165622"><a name="p227819518165622"></a><a name="p227819518165622"></a>Calculates the binary logarithm (logarithm with base 2) of the float value <strong id="b1707226404165622"><a name="b1707226404165622"></a><a name="b1707226404165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1796828542165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725355517165622"><a name="p725355517165622"></a><a name="p725355517165622"></a><a href="math.md#gaa383ae0cab6c24f1bcba661dee0fbd70">log2l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p952048493165622"><a name="p952048493165622"></a><a name="p952048493165622"></a>long double </p>
<p id="p1466747696165622"><a name="p1466747696165622"></a><a name="p1466747696165622"></a>Calculates the binary logarithm (logarithm with base 2) of the long double value <strong id="b839612708165622"><a name="b839612708165622"></a><a name="b839612708165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1005885654165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2130766048165622"><a name="p2130766048165622"></a><a name="p2130766048165622"></a><a href="math.md#gaa34bf5be5c3dab058c532adc2792113c">logb</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22122918165622"><a name="p22122918165622"></a><a name="p22122918165622"></a>double </p>
<p id="p901951431165622"><a name="p901951431165622"></a><a name="p901951431165622"></a>Calculates the logarithm of the absolute value of the double value <strong id="b1926494197165622"><a name="b1926494197165622"></a><a name="b1926494197165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1805010161165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2089019426165622"><a name="p2089019426165622"></a><a name="p2089019426165622"></a><a href="math.md#ga6939b8381c2f160d26913646ca7ab6c4">logbf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72654441165622"><a name="p72654441165622"></a><a name="p72654441165622"></a>float </p>
<p id="p1660397455165622"><a name="p1660397455165622"></a><a name="p1660397455165622"></a>Calculates the logarithm of the absolute value of the float value <strong id="b275239386165622"><a name="b275239386165622"></a><a name="b275239386165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1438432308165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806254896165622"><a name="p806254896165622"></a><a name="p806254896165622"></a><a href="math.md#ga2f9c0448126d1a838624e3460217bb84">logbl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1040709103165622"><a name="p1040709103165622"></a><a name="p1040709103165622"></a>long double </p>
<p id="p1606717610165622"><a name="p1606717610165622"></a><a name="p1606717610165622"></a>Calculates the logarithm of the absolute value of the long double value <strong id="b1868231928165622"><a name="b1868231928165622"></a><a name="b1868231928165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1545894581165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1333631736165622"><a name="p1333631736165622"></a><a name="p1333631736165622"></a><a href="math.md#ga3337db086394bad101bd8d42d891640a">lrint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1988465488165622"><a name="p1988465488165622"></a><a name="p1988465488165622"></a>long int </p>
<p id="p1683580295165622"><a name="p1683580295165622"></a><a name="p1683580295165622"></a>Rounds the double value <strong id="b1179186171165622"><a name="b1179186171165622"></a><a name="b1179186171165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1873388490165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1064400432165622"><a name="p1064400432165622"></a><a name="p1064400432165622"></a><a href="math.md#ga16173bca19eef93d0230bfb7c86b5740">lrintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978757119165622"><a name="p1978757119165622"></a><a name="p1978757119165622"></a>long int </p>
<p id="p123432532165622"><a name="p123432532165622"></a><a name="p123432532165622"></a>Rounds the float value <strong id="b1906238156165622"><a name="b1906238156165622"></a><a name="b1906238156165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row825089802165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1126180853165622"><a name="p1126180853165622"></a><a name="p1126180853165622"></a><a href="math.md#gac6d217e9b96a145f5eeb2a490e6496e6">lrintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426091499165622"><a name="p1426091499165622"></a><a name="p1426091499165622"></a>long int </p>
<p id="p1940999946165622"><a name="p1940999946165622"></a><a name="p1940999946165622"></a>Rounds the long double value <strong id="b86384594165622"><a name="b86384594165622"></a><a name="b86384594165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1194523349165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p444457355165622"><a name="p444457355165622"></a><a name="p444457355165622"></a><a href="math.md#ga5936ef27aa03815e9c17d557e87a33d7">lround</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380055859165622"><a name="p380055859165622"></a><a name="p380055859165622"></a>long int </p>
<p id="p1155424334165622"><a name="p1155424334165622"></a><a name="p1155424334165622"></a>Rounds double value <strong id="b784418942165622"><a name="b784418942165622"></a><a name="b784418942165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b1810129990165622"><a name="b1810129990165622"></a><a name="b1810129990165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row645467031165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871890651165622"><a name="p871890651165622"></a><a name="p871890651165622"></a><a href="math.md#ga0136619b503ddb8ce1a226cd34c9538c">lroundf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910829947165622"><a name="p1910829947165622"></a><a name="p1910829947165622"></a>long int </p>
<p id="p1500225412165622"><a name="p1500225412165622"></a><a name="p1500225412165622"></a>Rounds the float value <strong id="b863706886165622"><a name="b863706886165622"></a><a name="b863706886165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b437355055165622"><a name="b437355055165622"></a><a name="b437355055165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1708582894165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265308064165622"><a name="p1265308064165622"></a><a name="p1265308064165622"></a><a href="math.md#gafa865c5b70c9311f0f8701a1af60c715">lroundl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p859838584165622"><a name="p859838584165622"></a><a name="p859838584165622"></a>long int </p>
<p id="p1043379070165622"><a name="p1043379070165622"></a><a name="p1043379070165622"></a>Rounds the long double value <strong id="b136696905165622"><a name="b136696905165622"></a><a name="b136696905165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b1172289702165622"><a name="b1172289702165622"></a><a name="b1172289702165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1601868322165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1903057979165622"><a name="p1903057979165622"></a><a name="p1903057979165622"></a><a href="math.md#gafcfe25b77e975450988866fea9d3c9f0">modf</a> (double x, double *iptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993255034165622"><a name="p1993255034165622"></a><a name="p1993255034165622"></a>double </p>
<p id="p1375403039165622"><a name="p1375403039165622"></a><a name="p1375403039165622"></a>Breaks the double value <strong id="b1481817530165622"><a name="b1481817530165622"></a><a name="b1481817530165622"></a>x</strong> into a signed integral and a fractional part. </p>
</td>
</tr>
<tr id="row842039481165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1319102566165622"><a name="p1319102566165622"></a><a name="p1319102566165622"></a><a href="math.md#gad8314f66dfe8603f3a166eb466261ce1">modff</a> (float x, float *iptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1207292562165622"><a name="p1207292562165622"></a><a name="p1207292562165622"></a>float </p>
<p id="p1509133093165622"><a name="p1509133093165622"></a><a name="p1509133093165622"></a>Breaks the float value <strong id="b1848044717165622"><a name="b1848044717165622"></a><a name="b1848044717165622"></a>x</strong> into a signed integral and a fractional part. </p>
</td>
</tr>
<tr id="row1806657630165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949515906165622"><a name="p1949515906165622"></a><a name="p1949515906165622"></a><a href="math.md#gabacf3b74f8d7e30a70da8ae47c8e4e3e">modfl</a> (long double x, long double *iptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1158846756165622"><a name="p1158846756165622"></a><a name="p1158846756165622"></a>long double </p>
<p id="p172296178165622"><a name="p172296178165622"></a><a name="p172296178165622"></a>Breaks the long double value <strong id="b1627728202165622"><a name="b1627728202165622"></a><a name="b1627728202165622"></a>x</strong> into a signed integral and a fractional part. </p>
</td>
</tr>
<tr id="row2008065685165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1055491445165622"><a name="p1055491445165622"></a><a name="p1055491445165622"></a><a href="math.md#gaa4ee2f416f261bbd71cda3193c4884c9">nan</a> (const char *tagp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913415585165622"><a name="p1913415585165622"></a><a name="p1913415585165622"></a>double </p>
<p id="p1133078641165622"><a name="p1133078641165622"></a><a name="p1133078641165622"></a>Obtains a quiet NaN value of the double type. </p>
</td>
</tr>
<tr id="row2071205519165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845875756165622"><a name="p1845875756165622"></a><a name="p1845875756165622"></a><a href="math.md#ga7fe43d4c86419daea2c133e8c5c1a17d">nanf</a> (const char *tagp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1327141201165622"><a name="p1327141201165622"></a><a name="p1327141201165622"></a>float </p>
<p id="p2116997176165622"><a name="p2116997176165622"></a><a name="p2116997176165622"></a>Obtains a quiet NaN value of the float type. </p>
</td>
</tr>
<tr id="row429973604165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p163898675165622"><a name="p163898675165622"></a><a name="p163898675165622"></a><a href="math.md#gac92b1a3a1073a630ae0b7084e596d40f">nanl</a> (const char *tagp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1187015325165622"><a name="p1187015325165622"></a><a name="p1187015325165622"></a>long double </p>
<p id="p326411068165622"><a name="p326411068165622"></a><a name="p326411068165622"></a>Obtains a quiet NaN value of the long double type. </p>
</td>
</tr>
<tr id="row2035862901165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991289080165622"><a name="p991289080165622"></a><a name="p991289080165622"></a><a href="math.md#ga61ba6b3078ccbd5aac518e6ca2a757bd">nearbyint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433702813165622"><a name="p433702813165622"></a><a name="p433702813165622"></a>double </p>
<p id="p162760309165622"><a name="p162760309165622"></a><a name="p162760309165622"></a>Rounds the double value <strong id="b971201640165622"><a name="b971201640165622"></a><a name="b971201640165622"></a>x</strong> to an integer in floating-point format. </p>
</td>
</tr>
<tr id="row895008787165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1742466836165622"><a name="p1742466836165622"></a><a name="p1742466836165622"></a><a href="math.md#gab3be3fdcb83a6d7cbd10aa5d891f88bf">nearbyintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p842506743165622"><a name="p842506743165622"></a><a name="p842506743165622"></a>float </p>
<p id="p1456521305165622"><a name="p1456521305165622"></a><a name="p1456521305165622"></a>Rounds the float value <strong id="b1856218336165622"><a name="b1856218336165622"></a><a name="b1856218336165622"></a>x</strong> to an integer in floating-point format. </p>
</td>
</tr>
<tr id="row105972156165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1024223371165622"><a name="p1024223371165622"></a><a name="p1024223371165622"></a><a href="math.md#ga4b51faf338f7d4f31224d0c096a8859b">nearbyintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p253482534165622"><a name="p253482534165622"></a><a name="p253482534165622"></a>long double </p>
<p id="p388043530165622"><a name="p388043530165622"></a><a name="p388043530165622"></a>Rounds the long double value <strong id="b2135520165622"><a name="b2135520165622"></a><a name="b2135520165622"></a>x</strong> to an integer in floating-point format. </p>
</td>
</tr>
<tr id="row1322398025165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425585401165622"><a name="p1425585401165622"></a><a name="p1425585401165622"></a><a href="math.md#gabed1b7ee913471448c2dbe58dff28db3">nextafter</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p300888426165622"><a name="p300888426165622"></a><a name="p300888426165622"></a>double </p>
<p id="p2022804993165622"><a name="p2022804993165622"></a><a name="p2022804993165622"></a>Obtains the next representable value following the double value <strong id="b1096130629165622"><a name="b1096130629165622"></a><a name="b1096130629165622"></a>x</strong> in the direction of the double value <strong id="b847025271165622"><a name="b847025271165622"></a><a name="b847025271165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row18079429165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p861305423165622"><a name="p861305423165622"></a><a name="p861305423165622"></a><a href="math.md#ga57d2446286a54227595950a2118b349b">nextafterf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1323389998165622"><a name="p1323389998165622"></a><a name="p1323389998165622"></a>float </p>
<p id="p1092141257165622"><a name="p1092141257165622"></a><a name="p1092141257165622"></a>Obtains the next representable value following the float value <strong id="b2105966954165622"><a name="b2105966954165622"></a><a name="b2105966954165622"></a>x</strong> in the direction of the float value <strong id="b1595939253165622"><a name="b1595939253165622"></a><a name="b1595939253165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1567787743165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912740569165622"><a name="p912740569165622"></a><a name="p912740569165622"></a><a href="math.md#ga38691f2f734e77206e4336cdcddd0e5b">nextafterl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p334226324165622"><a name="p334226324165622"></a><a name="p334226324165622"></a>long double </p>
<p id="p1766935161165622"><a name="p1766935161165622"></a><a name="p1766935161165622"></a>Obtains the next representable value following the long double value <strong id="b532193893165622"><a name="b532193893165622"></a><a name="b532193893165622"></a>x</strong> in the direction of the long double value <strong id="b1171261689165622"><a name="b1171261689165622"></a><a name="b1171261689165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1883596133165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p598558491165622"><a name="p598558491165622"></a><a name="p598558491165622"></a><a href="math.md#gaeb7afe6d08d8daec35aa282c63d7647e">nexttoward</a> (double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028357542165622"><a name="p1028357542165622"></a><a name="p1028357542165622"></a>double </p>
<p id="p2061707786165622"><a name="p2061707786165622"></a><a name="p2061707786165622"></a>Obtains the next representable value following the double value <strong id="b551334713165622"><a name="b551334713165622"></a><a name="b551334713165622"></a>x</strong> in the direction of the long double value <strong id="b1120872030165622"><a name="b1120872030165622"></a><a name="b1120872030165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1656025340165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p650127729165622"><a name="p650127729165622"></a><a name="p650127729165622"></a><a href="math.md#ga634a1dabb08aa5a4fa6897920eff3c1d">nexttowardf</a> (float x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528536668165622"><a name="p528536668165622"></a><a name="p528536668165622"></a>float </p>
<p id="p1888917875165622"><a name="p1888917875165622"></a><a name="p1888917875165622"></a>Obtains the next representable value following the float value <strong id="b1496862028165622"><a name="b1496862028165622"></a><a name="b1496862028165622"></a>x</strong> in the direction of the long double value <strong id="b323881724165622"><a name="b323881724165622"></a><a name="b323881724165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row108944234165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443842864165622"><a name="p1443842864165622"></a><a name="p1443842864165622"></a><a href="math.md#ga3930cfe4df009d7221db329b910d6e30">nexttowardl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1806498081165622"><a name="p1806498081165622"></a><a name="p1806498081165622"></a>long double </p>
<p id="p545596876165622"><a name="p545596876165622"></a><a name="p545596876165622"></a>Obtains the next representable value following the long double value <strong id="b249495628165622"><a name="b249495628165622"></a><a name="b249495628165622"></a>x</strong> in the direction of the long double value <strong id="b1855782887165622"><a name="b1855782887165622"></a><a name="b1855782887165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row112094835165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p766090233165622"><a name="p766090233165622"></a><a name="p766090233165622"></a><a href="math.md#gaa56c9494c95edf68386375e97d64159b">pow</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913104163165622"><a name="p1913104163165622"></a><a name="p1913104163165622"></a>double </p>
<p id="p269260118165622"><a name="p269260118165622"></a><a name="p269260118165622"></a>Obtains the double value <strong id="b1760585808165622"><a name="b1760585808165622"></a><a name="b1760585808165622"></a>x</strong> raised to the power of the double value <strong id="b6206877165622"><a name="b6206877165622"></a><a name="b6206877165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row192067039165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p710927630165622"><a name="p710927630165622"></a><a name="p710927630165622"></a><a href="math.md#gac6b287549be087f6f0bf03b6fe30499e">powf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11066226165622"><a name="p11066226165622"></a><a name="p11066226165622"></a>float </p>
<p id="p389336232165622"><a name="p389336232165622"></a><a name="p389336232165622"></a>Obtains the float value <strong id="b288783076165622"><a name="b288783076165622"></a><a name="b288783076165622"></a>x</strong> raised to the power of the float value <strong id="b308634983165622"><a name="b308634983165622"></a><a name="b308634983165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row125228178165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952497767165622"><a name="p952497767165622"></a><a name="p952497767165622"></a><a href="math.md#ga2cb598503b85d66abf59e9da06478f1a">pow10f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1898180702165622"><a name="p1898180702165622"></a><a name="p1898180702165622"></a>float </p>
<p id="p530445139165622"><a name="p530445139165622"></a><a name="p530445139165622"></a>Calculates the xth power of 10. </p>
</td>
</tr>
<tr id="row1090355194165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p277144725165622"><a name="p277144725165622"></a><a name="p277144725165622"></a><a href="math.md#ga2f4830e468138e1513b55ca6a92a0f9a">powl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312233600165622"><a name="p1312233600165622"></a><a name="p1312233600165622"></a>long double </p>
<p id="p1625629317165622"><a name="p1625629317165622"></a><a name="p1625629317165622"></a>Obtains the long double value <strong id="b1347386637165622"><a name="b1347386637165622"></a><a name="b1347386637165622"></a>x</strong> raised to the power of the long double value <strong id="b581854117165622"><a name="b581854117165622"></a><a name="b581854117165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row122753003165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226958148165622"><a name="p1226958148165622"></a><a name="p1226958148165622"></a><a href="math.md#ga9baf71e9033dd73a9c225a2fc9cca61d">pow10l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167433911165622"><a name="p167433911165622"></a><a name="p167433911165622"></a>long double </p>
<p id="p1756001302165622"><a name="p1756001302165622"></a><a name="p1756001302165622"></a>Calculates the xth power of 10. </p>
</td>
</tr>
<tr id="row329717389165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231492655165622"><a name="p1231492655165622"></a><a name="p1231492655165622"></a><a href="math.md#gaf7df01c4a9038dbf3562b41bc8c3be03">remainder</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93908912165622"><a name="p93908912165622"></a><a name="p93908912165622"></a>double </p>
<p id="p2034107349165622"><a name="p2034107349165622"></a><a name="p2034107349165622"></a>Calculates the remainder of the double value <strong id="b1152758290165622"><a name="b1152758290165622"></a><a name="b1152758290165622"></a>x</strong> divided by the double value <strong id="b1408048557165622"><a name="b1408048557165622"></a><a name="b1408048557165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row2136720737165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995735342165622"><a name="p1995735342165622"></a><a name="p1995735342165622"></a><a href="math.md#ga370ff5cfa842822bfd8ea0a93d441a33">remainderf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p115712726165622"><a name="p115712726165622"></a><a name="p115712726165622"></a>float </p>
<p id="p518423474165622"><a name="p518423474165622"></a><a name="p518423474165622"></a>Calculates the remainder of the float value <strong id="b1431847541165622"><a name="b1431847541165622"></a><a name="b1431847541165622"></a>x</strong> divided by the float value <strong id="b415201074165622"><a name="b415201074165622"></a><a name="b415201074165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row714808896165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1486989398165622"><a name="p1486989398165622"></a><a name="p1486989398165622"></a><a href="math.md#gabadbe61e166bbf3031b979661f0e8336">remainderl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651563240165622"><a name="p1651563240165622"></a><a name="p1651563240165622"></a>long double </p>
<p id="p1798461235165622"><a name="p1798461235165622"></a><a name="p1798461235165622"></a>Calculates the remainder of the long double value <strong id="b158152590165622"><a name="b158152590165622"></a><a name="b158152590165622"></a>x</strong> divided by the long double value <strong id="b2027755954165622"><a name="b2027755954165622"></a><a name="b2027755954165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1942903687165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p534593356165622"><a name="p534593356165622"></a><a name="p534593356165622"></a><a href="math.md#gac836dc6a979229173eb3d6e2744d82de">remquo</a> (double x, double y, int *quo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044704337165622"><a name="p2044704337165622"></a><a name="p2044704337165622"></a>double </p>
<p id="p45939234165622"><a name="p45939234165622"></a><a name="p45939234165622"></a>Calculates the quotient and remainder of the double value <strong id="b1157363105165622"><a name="b1157363105165622"></a><a name="b1157363105165622"></a>x</strong> divided by the double value <strong id="b880231014165622"><a name="b880231014165622"></a><a name="b880231014165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row237624478165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2021413804165622"><a name="p2021413804165622"></a><a name="p2021413804165622"></a><a href="math.md#ga15ec704e1894cfa573ac37a65afe009a">remquof</a> (float x, float y, int *quo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p50143669165622"><a name="p50143669165622"></a><a name="p50143669165622"></a>float </p>
<p id="p555218798165622"><a name="p555218798165622"></a><a name="p555218798165622"></a>Calculates the quotient and remainder of the float value <strong id="b501767298165622"><a name="b501767298165622"></a><a name="b501767298165622"></a>x</strong> divided by the float value <strong id="b668331222165622"><a name="b668331222165622"></a><a name="b668331222165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1999786127165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847632216165622"><a name="p847632216165622"></a><a name="p847632216165622"></a><a href="math.md#gaacadcc57a95279058f29e657dce4d285">remquol</a> (long double x, long double y, int *quo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672976895165622"><a name="p1672976895165622"></a><a name="p1672976895165622"></a>long double </p>
<p id="p1951054441165622"><a name="p1951054441165622"></a><a name="p1951054441165622"></a>Calculates the quotient and remainder of the long double value <strong id="b704250389165622"><a name="b704250389165622"></a><a name="b704250389165622"></a>x</strong> divided by the long double value <strong id="b403279496165622"><a name="b403279496165622"></a><a name="b403279496165622"></a>y</strong>. </p>
</td>
</tr>
<tr id="row54259037165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1624693461165622"><a name="p1624693461165622"></a><a name="p1624693461165622"></a><a href="math.md#gae1f9edd5049d3ff63b0373a3c15c38c1">rint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089512248165622"><a name="p1089512248165622"></a><a name="p1089512248165622"></a>double </p>
<p id="p664996933165622"><a name="p664996933165622"></a><a name="p664996933165622"></a>Rounds the double value <strong id="b1805911068165622"><a name="b1805911068165622"></a><a name="b1805911068165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1531968279165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707866852165622"><a name="p1707866852165622"></a><a name="p1707866852165622"></a><a href="math.md#ga48f9341b9310fefa5dd1b0c8c84c99df">rintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391115239165622"><a name="p391115239165622"></a><a name="p391115239165622"></a>float </p>
<p id="p110299147165622"><a name="p110299147165622"></a><a name="p110299147165622"></a>Rounds the float value <strong id="b213834852165622"><a name="b213834852165622"></a><a name="b213834852165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row89714717165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1272847054165622"><a name="p1272847054165622"></a><a name="p1272847054165622"></a><a href="math.md#gaedc37bf10d69d2efa2a478f5f5d4b26b">rintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1683431768165622"><a name="p1683431768165622"></a><a name="p1683431768165622"></a>long double </p>
<p id="p2077002539165622"><a name="p2077002539165622"></a><a name="p2077002539165622"></a>Rounds the long double value <strong id="b403071814165622"><a name="b403071814165622"></a><a name="b403071814165622"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1172734283165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1576833613165622"><a name="p1576833613165622"></a><a name="p1576833613165622"></a><a href="math.md#ga7df19cf730447c00150569250a4b5e1d">round</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1863580479165622"><a name="p1863580479165622"></a><a name="p1863580479165622"></a>double </p>
<p id="p1050094424165622"><a name="p1050094424165622"></a><a name="p1050094424165622"></a>Rounds the double value <strong id="b1714552129165622"><a name="b1714552129165622"></a><a name="b1714552129165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b1341108966165622"><a name="b1341108966165622"></a><a name="b1341108966165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1886619530165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142829285165622"><a name="p142829285165622"></a><a name="p142829285165622"></a><a href="math.md#gade09185c0cf8101fa9e2f25c15041b81">roundf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97366765165622"><a name="p97366765165622"></a><a name="p97366765165622"></a>float </p>
<p id="p1912911036165622"><a name="p1912911036165622"></a><a name="p1912911036165622"></a>Rounds the float value <strong id="b335379415165622"><a name="b335379415165622"></a><a name="b335379415165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b967533939165622"><a name="b967533939165622"></a><a name="b967533939165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row564377312165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p115783538165622"><a name="p115783538165622"></a><a name="p115783538165622"></a><a href="math.md#ga6565127c023ae8f392ce69e3b3f30aa1">roundl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1668551521165622"><a name="p1668551521165622"></a><a name="p1668551521165622"></a>long double </p>
<p id="p536820962165622"><a name="p536820962165622"></a><a name="p536820962165622"></a>Rounds the long double value <strong id="b665239589165622"><a name="b665239589165622"></a><a name="b665239589165622"></a>x</strong> to the nearest integer, rounding away from <strong id="b269455393165622"><a name="b269455393165622"></a><a name="b269455393165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row372572875165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894335670165622"><a name="p894335670165622"></a><a name="p894335670165622"></a><a href="math.md#ga947d3d0739c0dc7c46d1eec778d4b6af">scalbln</a> (double x, long int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620020135165622"><a name="p1620020135165622"></a><a name="p1620020135165622"></a>double </p>
<p id="p998729579165622"><a name="p998729579165622"></a><a name="p998729579165622"></a>Multiplies the double value <strong id="b1794268249165622"><a name="b1794268249165622"></a><a name="b1794268249165622"></a>x</strong> by <strong id="b894626676165622"><a name="b894626676165622"></a><a name="b894626676165622"></a>FLT_RADIX</strong> raised to the power of the long int value <strong id="b693768078165622"><a name="b693768078165622"></a><a name="b693768078165622"></a>exp</strong>, that is, <strong id="b641298228165622"><a name="b641298228165622"></a><a name="b641298228165622"></a>x*(<strong id="b1590854908165622"><a name="b1590854908165622"></a><a name="b1590854908165622"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row1751841766165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763229586165622"><a name="p1763229586165622"></a><a name="p1763229586165622"></a><a href="math.md#ga1aa3cc34e8f84a2a09400c25c578100d">scalblnf</a> (float x, long int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016338535165622"><a name="p2016338535165622"></a><a name="p2016338535165622"></a>float </p>
<p id="p137775496165622"><a name="p137775496165622"></a><a name="p137775496165622"></a>Multiplies the float value <strong id="b330690466165622"><a name="b330690466165622"></a><a name="b330690466165622"></a>x</strong> by <strong id="b2081840264165622"><a name="b2081840264165622"></a><a name="b2081840264165622"></a>FLT_RADIX</strong> raised to the power of the long int value <strong id="b2036662428165622"><a name="b2036662428165622"></a><a name="b2036662428165622"></a>exp</strong>, that is, <strong id="b262516639165622"><a name="b262516639165622"></a><a name="b262516639165622"></a>x*(<strong id="b641545504165622"><a name="b641545504165622"></a><a name="b641545504165622"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row195076965165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975677851165622"><a name="p1975677851165622"></a><a name="p1975677851165622"></a><a href="math.md#gaeb098df94536b520ced9df59fd353848">scalblnl</a> (long double x, long int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p341149971165622"><a name="p341149971165622"></a><a name="p341149971165622"></a>long double </p>
<p id="p362893488165622"><a name="p362893488165622"></a><a name="p362893488165622"></a>Multiplies the long double value <strong id="b903717757165622"><a name="b903717757165622"></a><a name="b903717757165622"></a>x</strong> by <strong id="b606022041165622"><a name="b606022041165622"></a><a name="b606022041165622"></a>FLT_RADIX</strong> raised to the power of the long int value <strong id="b1017830820165622"><a name="b1017830820165622"></a><a name="b1017830820165622"></a>exp</strong>, that is, <strong id="b784250733165622"><a name="b784250733165622"></a><a name="b784250733165622"></a>x*(<strong id="b112707096165622"><a name="b112707096165622"></a><a name="b112707096165622"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row76683346165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688849234165622"><a name="p688849234165622"></a><a name="p688849234165622"></a><a href="math.md#gaa2fbea1fca1faaebedf2deec71c47189">scalbn</a> (double x, int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p824133872165622"><a name="p824133872165622"></a><a name="p824133872165622"></a>double </p>
<p id="p548245774165622"><a name="p548245774165622"></a><a name="p548245774165622"></a>Multiplies the double value <strong id="b1426617899165622"><a name="b1426617899165622"></a><a name="b1426617899165622"></a>x</strong> by <strong id="b1876368607165622"><a name="b1876368607165622"></a><a name="b1876368607165622"></a>FLT_RADIX</strong> raised to the power of the int value <strong id="b2077639840165622"><a name="b2077639840165622"></a><a name="b2077639840165622"></a>exp</strong>, that is, <strong id="b1041334801165622"><a name="b1041334801165622"></a><a name="b1041334801165622"></a>x*(<strong id="b1598324133165622"><a name="b1598324133165622"></a><a name="b1598324133165622"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row149096406165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p575297111165622"><a name="p575297111165622"></a><a name="p575297111165622"></a><a href="math.md#ga3849b86bb2f39ebccb79b91745f7883f">scalbnf</a> (float x, int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345215032165622"><a name="p345215032165622"></a><a name="p345215032165622"></a>float </p>
<p id="p1000277859165622"><a name="p1000277859165622"></a><a name="p1000277859165622"></a>Multiplies the float value <strong id="b1288574056165622"><a name="b1288574056165622"></a><a name="b1288574056165622"></a>x</strong> by <strong id="b378723144165622"><a name="b378723144165622"></a><a name="b378723144165622"></a>FLT_RADIX</strong> raised to the power of the int value <strong id="b1420986228165622"><a name="b1420986228165622"></a><a name="b1420986228165622"></a>exp</strong>, that is, <strong id="b1009468191165622"><a name="b1009468191165622"></a><a name="b1009468191165622"></a>x*(<strong id="b2062493858165622"><a name="b2062493858165622"></a><a name="b2062493858165622"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row1601712416165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368286661165622"><a name="p368286661165622"></a><a name="p368286661165622"></a><a href="math.md#ga284717e9eceed5bc33389ce33170f907">scalbnl</a> (long double x, int <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p947895864165622"><a name="p947895864165622"></a><a name="p947895864165622"></a>long double </p>
<p id="p388932870165622"><a name="p388932870165622"></a><a name="p388932870165622"></a>Multiplies the long double value <strong id="b1152394751165622"><a name="b1152394751165622"></a><a name="b1152394751165622"></a>x</strong> by <strong id="b204368701165622"><a name="b204368701165622"></a><a name="b204368701165622"></a>FLT_RADIX</strong> raised to the power of the int value <strong id="b259729414165622"><a name="b259729414165622"></a><a name="b259729414165622"></a>exp</strong>, that is, <strong id="b1587745664165622"><a name="b1587745664165622"></a><a name="b1587745664165622"></a>x*(<strong id="b1723422321165622"><a name="b1723422321165622"></a><a name="b1723422321165622"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row892958639165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p982383472165622"><a name="p982383472165622"></a><a name="p982383472165622"></a><a href="math.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952893392165622"><a name="p1952893392165622"></a><a name="p1952893392165622"></a>double </p>
<p id="p1631190649165622"><a name="p1631190649165622"></a><a name="p1631190649165622"></a>Calculates the sine of the double value <strong id="b880533938165622"><a name="b880533938165622"></a><a name="b880533938165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1164086277165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838102657165622"><a name="p1838102657165622"></a><a name="p1838102657165622"></a><a href="math.md#ga8a7dc2a88e109f4e15b661247665709a">sinf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453391402165622"><a name="p453391402165622"></a><a name="p453391402165622"></a>float </p>
<p id="p2090599550165622"><a name="p2090599550165622"></a><a name="p2090599550165622"></a>Calculates the sine of the float value <strong id="b965929195165622"><a name="b965929195165622"></a><a name="b965929195165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row72605105165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111166472165622"><a name="p111166472165622"></a><a name="p111166472165622"></a><a href="math.md#gaeb537bfea71fa91192234a666f3a6a25">sinl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1861782385165622"><a name="p1861782385165622"></a><a name="p1861782385165622"></a>long double </p>
<p id="p597271358165622"><a name="p597271358165622"></a><a name="p597271358165622"></a>Calculates the sine of the long double value <strong id="b1782174739165622"><a name="b1782174739165622"></a><a name="b1782174739165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1284761899165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682583611165622"><a name="p1682583611165622"></a><a name="p1682583611165622"></a><a href="math.md#ga862012e970c977c482507064e2793b45">sinh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761064227165622"><a name="p1761064227165622"></a><a name="p1761064227165622"></a>double </p>
<p id="p825362021165622"><a name="p825362021165622"></a><a name="p825362021165622"></a>Calculates the hyperbolic sine of the double value <strong id="b115681702165622"><a name="b115681702165622"></a><a name="b115681702165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row369053854165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p473073426165622"><a name="p473073426165622"></a><a name="p473073426165622"></a><a href="math.md#ga1976c7577fb97800f4b926bd042b64ac">sinhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p80029893165622"><a name="p80029893165622"></a><a name="p80029893165622"></a>float </p>
<p id="p849600705165622"><a name="p849600705165622"></a><a name="p849600705165622"></a>Calculates the hyperbolic sine of the float value <strong id="b2094420967165622"><a name="b2094420967165622"></a><a name="b2094420967165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row467948810165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748004740165622"><a name="p1748004740165622"></a><a name="p1748004740165622"></a><a href="math.md#gad160d5d1bb3f113e96135a4bebe76abe">sinhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073390258165622"><a name="p2073390258165622"></a><a name="p2073390258165622"></a>long double </p>
<p id="p1711527649165622"><a name="p1711527649165622"></a><a name="p1711527649165622"></a>Calculates the hyperbolic sine of the long double value <strong id="b914831469165622"><a name="b914831469165622"></a><a name="b914831469165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row568355584165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p936869363165622"><a name="p936869363165622"></a><a name="p936869363165622"></a><a href="math.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72132131165622"><a name="p72132131165622"></a><a name="p72132131165622"></a>double </p>
<p id="p1092322628165622"><a name="p1092322628165622"></a><a name="p1092322628165622"></a>Calculates the square root of double value <strong id="b1363925652165622"><a name="b1363925652165622"></a><a name="b1363925652165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1163739319165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688347675165622"><a name="p688347675165622"></a><a name="p688347675165622"></a><a href="math.md#ga46c9a8d40cde7c4d5ab40a67e55316bb">sqrtf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646121859165622"><a name="p1646121859165622"></a><a name="p1646121859165622"></a>float </p>
<p id="p1836401585165622"><a name="p1836401585165622"></a><a name="p1836401585165622"></a>Calculates the square root of the float value <strong id="b123874652165622"><a name="b123874652165622"></a><a name="b123874652165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1733581771165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425841936165622"><a name="p425841936165622"></a><a name="p425841936165622"></a><a href="math.md#ga9c028a87917b3bb9bba9e75f66cdbd43">sqrtl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1360077151165622"><a name="p1360077151165622"></a><a name="p1360077151165622"></a>long double </p>
<p id="p654255665165622"><a name="p654255665165622"></a><a name="p654255665165622"></a>Calculates the square root of the long double value <strong id="b1052495054165622"><a name="b1052495054165622"></a><a name="b1052495054165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row571187400165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p424787192165622"><a name="p424787192165622"></a><a name="p424787192165622"></a><a href="math.md#gaa48fdfd5eea5f4f9c33496402b9e4039">tan</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2035585915165622"><a name="p2035585915165622"></a><a name="p2035585915165622"></a>double </p>
<p id="p1701565123165622"><a name="p1701565123165622"></a><a name="p1701565123165622"></a>Calculates the tangent of the double value <strong id="b1041187562165622"><a name="b1041187562165622"></a><a name="b1041187562165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1316776384165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p239590266165622"><a name="p239590266165622"></a><a name="p239590266165622"></a><a href="math.md#ga67d5bfe80effce6adebf5fcbc5a7dae0">tanf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1997393303165622"><a name="p1997393303165622"></a><a name="p1997393303165622"></a>float </p>
<p id="p261069107165622"><a name="p261069107165622"></a><a name="p261069107165622"></a>Calculates the tangent of the float value <strong id="b241927916165622"><a name="b241927916165622"></a><a name="b241927916165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row303770904165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p574663171165622"><a name="p574663171165622"></a><a name="p574663171165622"></a><a href="math.md#ga2151fba6c1e9b4fa5d2af2dcb5c68b17">tanl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354345892165622"><a name="p1354345892165622"></a><a name="p1354345892165622"></a>long double </p>
<p id="p559672992165622"><a name="p559672992165622"></a><a name="p559672992165622"></a>Calculates the tangent of the long double value <strong id="b291567744165622"><a name="b291567744165622"></a><a name="b291567744165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1176813413165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1105086518165622"><a name="p1105086518165622"></a><a name="p1105086518165622"></a><a href="math.md#gaf85bcf153d7ae805733927f12329dac1">tanh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479327969165622"><a name="p479327969165622"></a><a name="p479327969165622"></a>double </p>
<p id="p11966329165622"><a name="p11966329165622"></a><a name="p11966329165622"></a>Calculates the hyperbolic tangent of the double value <strong id="b1567873049165622"><a name="b1567873049165622"></a><a name="b1567873049165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1249723396165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p505688080165622"><a name="p505688080165622"></a><a name="p505688080165622"></a><a href="math.md#ga74e8f87bb37a338d2cebbb6b1d696593">tanhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560364206165622"><a name="p560364206165622"></a><a name="p560364206165622"></a>float </p>
<p id="p260828916165622"><a name="p260828916165622"></a><a name="p260828916165622"></a>Calculates the hyperbolic tangent of the float value <strong id="b845517320165622"><a name="b845517320165622"></a><a name="b845517320165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1147290934165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2030404936165622"><a name="p2030404936165622"></a><a name="p2030404936165622"></a><a href="math.md#ga94ee8c57b6b2d0bc5466c75bea2bffcf">tanhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p349292610165622"><a name="p349292610165622"></a><a name="p349292610165622"></a>long double </p>
<p id="p1558929228165622"><a name="p1558929228165622"></a><a name="p1558929228165622"></a>Calculates the hyperbolic tangent of the long double value <strong id="b1586367016165622"><a name="b1586367016165622"></a><a name="b1586367016165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2015987181165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658964194165622"><a name="p658964194165622"></a><a name="p658964194165622"></a><a href="math.md#ga54afbf509eea5e9d6f9efdebc572339a">tgamma</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p671722280165622"><a name="p671722280165622"></a><a name="p671722280165622"></a>double </p>
<p id="p767420594165622"><a name="p767420594165622"></a><a name="p767420594165622"></a>Calculates the gamma function of the double value <strong id="b129989014165622"><a name="b129989014165622"></a><a name="b129989014165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row446782535165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607714681165622"><a name="p607714681165622"></a><a name="p607714681165622"></a><a href="math.md#ga2ab69de9110cc2c62ca78b5d20a3a3ae">tgammaf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591476978165622"><a name="p591476978165622"></a><a name="p591476978165622"></a>float </p>
<p id="p436451656165622"><a name="p436451656165622"></a><a name="p436451656165622"></a>Calculates the gamma function of the float value <strong id="b1438047063165622"><a name="b1438047063165622"></a><a name="b1438047063165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row137030210165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1088449156165622"><a name="p1088449156165622"></a><a name="p1088449156165622"></a><a href="math.md#ga8eff39a57115761c5025e08ff2e08c6a">tgammal</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570004962165622"><a name="p570004962165622"></a><a name="p570004962165622"></a>long double </p>
<p id="p1920620511165622"><a name="p1920620511165622"></a><a name="p1920620511165622"></a>Calculates the gamma function of the long double value <strong id="b933328296165622"><a name="b933328296165622"></a><a name="b933328296165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row835121707165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323213088165622"><a name="p1323213088165622"></a><a name="p1323213088165622"></a><a href="math.md#ga82a151adfde56b28fa8a50355c4f2ff6">trunc</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546790480165622"><a name="p546790480165622"></a><a name="p546790480165622"></a>double </p>
<p id="p372336353165622"><a name="p372336353165622"></a><a name="p372336353165622"></a>Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the double value <strong id="b1135538024165622"><a name="b1135538024165622"></a><a name="b1135538024165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row525184237165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p740857539165622"><a name="p740857539165622"></a><a name="p740857539165622"></a><a href="math.md#gaa8bb2049c170c9ac5b131fdba029991a">truncf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893877662165622"><a name="p1893877662165622"></a><a name="p1893877662165622"></a>float </p>
<p id="p1140417681165622"><a name="p1140417681165622"></a><a name="p1140417681165622"></a>Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the float value <strong id="b892765342165622"><a name="b892765342165622"></a><a name="b892765342165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row274500962165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198553172165622"><a name="p1198553172165622"></a><a name="p1198553172165622"></a><a href="math.md#ga8f9695496a9bb839eb5f728b6bf0c856">truncl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479221408165622"><a name="p479221408165622"></a><a name="p479221408165622"></a>long double </p>
<p id="p422542648165622"><a name="p422542648165622"></a><a name="p422542648165622"></a>Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the long double value <strong id="b1853477296165622"><a name="b1853477296165622"></a><a name="b1853477296165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row51214499165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1078544731165622"><a name="p1078544731165622"></a><a name="p1078544731165622"></a><a href="math.md#gaffb00730a1127dee798137075951ae21">j0</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p797020332165622"><a name="p797020332165622"></a><a name="p797020332165622"></a>double </p>
<p id="p704637289165622"><a name="p704637289165622"></a><a name="p704637289165622"></a>Calculates the Bessel function of the first kind of order <strong id="b1700810672165622"><a name="b1700810672165622"></a><a name="b1700810672165622"></a>0</strong> for the double value <strong id="b81129364165622"><a name="b81129364165622"></a><a name="b81129364165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row621584211165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p349183276165622"><a name="p349183276165622"></a><a name="p349183276165622"></a><a href="math.md#ga8cac4aa70c418eba481417f1878b4cee">j1</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314931251165622"><a name="p1314931251165622"></a><a name="p1314931251165622"></a>double </p>
<p id="p1628009967165622"><a name="p1628009967165622"></a><a name="p1628009967165622"></a>Calculates the Bessel function of the first kind of order <strong id="b1766826415165622"><a name="b1766826415165622"></a><a name="b1766826415165622"></a>1</strong> for the double value <strong id="b946199680165622"><a name="b946199680165622"></a><a name="b946199680165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1669910219165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1134376239165622"><a name="p1134376239165622"></a><a name="p1134376239165622"></a><a href="math.md#gadeff843dc8106ffda5caba6df44c591d">jn</a> (int n, double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1958769885165622"><a name="p1958769885165622"></a><a name="p1958769885165622"></a>double </p>
<p id="p930489229165622"><a name="p930489229165622"></a><a name="p930489229165622"></a>Calculates the Bessel function of the first kind of order <strong id="b360993217165622"><a name="b360993217165622"></a><a name="b360993217165622"></a>n</strong> for the double value <strong id="b1383307234165622"><a name="b1383307234165622"></a><a name="b1383307234165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row47236410165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1610499781165622"><a name="p1610499781165622"></a><a name="p1610499781165622"></a><a href="math.md#gafca57fd80386476e5cd1dd52173103c5">y0</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024929503165622"><a name="p1024929503165622"></a><a name="p1024929503165622"></a>double </p>
<p id="p832903311165622"><a name="p832903311165622"></a><a name="p832903311165622"></a>Calculates the Bessel function of the second kind of order <strong id="b2063931241165622"><a name="b2063931241165622"></a><a name="b2063931241165622"></a>0</strong> for the double value <strong id="b693210344165622"><a name="b693210344165622"></a><a name="b693210344165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row601385832165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p522827458165622"><a name="p522827458165622"></a><a name="p522827458165622"></a><a href="math.md#ga369368526a105f3fba6776b11586070c">y1</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p827738457165622"><a name="p827738457165622"></a><a name="p827738457165622"></a>double </p>
<p id="p696096183165622"><a name="p696096183165622"></a><a name="p696096183165622"></a>Calculates the Bessel function of the second kind of order <strong id="b1044974477165622"><a name="b1044974477165622"></a><a name="b1044974477165622"></a>1</strong> for the double value <strong id="b1734575173165622"><a name="b1734575173165622"></a><a name="b1734575173165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2067314455165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p375808280165622"><a name="p375808280165622"></a><a name="p375808280165622"></a><a href="math.md#gae31b4c8c6af724eaa73ad2ebce1aa3ce">yn</a> (int n, double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779158436165622"><a name="p1779158436165622"></a><a name="p1779158436165622"></a>double </p>
<p id="p435842794165622"><a name="p435842794165622"></a><a name="p435842794165622"></a>Calculates the Bessel function of the second kind of order <strong id="b342494414165622"><a name="b342494414165622"></a><a name="b342494414165622"></a>n</strong> for the double value <strong id="b1836642696165622"><a name="b1836642696165622"></a><a name="b1836642696165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1583215305165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501221386165622"><a name="p1501221386165622"></a><a name="p1501221386165622"></a><a href="math.md#ga08e754462e6ec13bc05fd41cff9cdd4a">finite</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578600768165622"><a name="p1578600768165622"></a><a name="p1578600768165622"></a>int </p>
<p id="p1809325746165622"><a name="p1809325746165622"></a><a name="p1809325746165622"></a>Checks whether the double value <strong id="b26530638165622"><a name="b26530638165622"></a><a name="b26530638165622"></a>x</strong> is an infinity or a NaN value. </p>
</td>
</tr>
<tr id="row2004554397165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633884454165622"><a name="p633884454165622"></a><a name="p633884454165622"></a><a href="math.md#gaea39ac813876c506f8c351e6c14a5cb7">finitef</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p681737626165622"><a name="p681737626165622"></a><a name="p681737626165622"></a>int </p>
<p id="p897280683165622"><a name="p897280683165622"></a><a name="p897280683165622"></a>Checks whether the float value <strong id="b102194254165622"><a name="b102194254165622"></a><a name="b102194254165622"></a>x</strong> is an infinity or a NaN value. </p>
</td>
</tr>
<tr id="row852547987165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p494284587165622"><a name="p494284587165622"></a><a name="p494284587165622"></a><a href="math.md#ga14db57dcd8982430d12219bbecd08a05">scalb</a> (double x, double <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144503564165622"><a name="p2144503564165622"></a><a name="p2144503564165622"></a>double </p>
<p id="p216929067165622"><a name="p216929067165622"></a><a name="p216929067165622"></a>Multiplies the double value <strong id="b504942658165622"><a name="b504942658165622"></a><a name="b504942658165622"></a>x</strong> by <strong id="b1803745746165622"><a name="b1803745746165622"></a><a name="b1803745746165622"></a>FLT_RADIX</strong> raised to the power of the double value <strong id="b371291399165622"><a name="b371291399165622"></a><a name="b371291399165622"></a>exp</strong>, that is, x*<strong id="b1526913742165622"><a name="b1526913742165622"></a><a name="b1526913742165622"></a>FLT_RADIX</strong>^exp. </p>
</td>
</tr>
<tr id="row1217002070165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1935606096165622"><a name="p1935606096165622"></a><a name="p1935606096165622"></a><a href="math.md#ga9c9db25d2ff9973e0d8638cf42df3999">scalbf</a> (float x, float <a href="math.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653206111165622"><a name="p1653206111165622"></a><a name="p1653206111165622"></a>float </p>
<p id="p843960756165622"><a name="p843960756165622"></a><a name="p843960756165622"></a>Multiplies the float value <strong id="b85372274165622"><a name="b85372274165622"></a><a name="b85372274165622"></a>x</strong> by <strong id="b821142461165622"><a name="b821142461165622"></a><a name="b821142461165622"></a>FLT_RADIX</strong> raised to the power of the float value <strong id="b970001961165622"><a name="b970001961165622"></a><a name="b970001961165622"></a>exp</strong>, that is, x*<strong id="b1039177457165622"><a name="b1039177457165622"></a><a name="b1039177457165622"></a>FLT_RADIX</strong>^exp. </p>
</td>
</tr>
<tr id="row1273358905165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975815102165622"><a name="p1975815102165622"></a><a name="p1975815102165622"></a><a href="math.md#gafad3bf1f77c516fb8891c72beb51640f">significand</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491253198165622"><a name="p1491253198165622"></a><a name="p1491253198165622"></a>double </p>
<p id="p2057790567165622"><a name="p2057790567165622"></a><a name="p2057790567165622"></a>Obtains the significand of the double value <strong id="b1639170071165622"><a name="b1639170071165622"></a><a name="b1639170071165622"></a>x</strong> scaled to the range [1,2). </p>
</td>
</tr>
<tr id="row759979479165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p244778964165622"><a name="p244778964165622"></a><a name="p244778964165622"></a><a href="math.md#gac57d7d88e1a9b57c9a129ee4d4a68c42">significandf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650997409165622"><a name="p1650997409165622"></a><a name="p1650997409165622"></a>float </p>
<p id="p1089375192165622"><a name="p1089375192165622"></a><a name="p1089375192165622"></a>Obtains the significand of the float value <strong id="b1514218093165622"><a name="b1514218093165622"></a><a name="b1514218093165622"></a>x</strong> scaled to the range [1,2). </p>
</td>
</tr>
<tr id="row316377732165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993203311165622"><a name="p1993203311165622"></a><a name="p1993203311165622"></a><a href="math.md#gafa59b98550749c27995dfb7c70e6783a">j0f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597546616165622"><a name="p1597546616165622"></a><a name="p1597546616165622"></a>float </p>
<p id="p181675723165622"><a name="p181675723165622"></a><a name="p181675723165622"></a>Calculates the Bessel function of the first kind of order <strong id="b1619341458165622"><a name="b1619341458165622"></a><a name="b1619341458165622"></a>0</strong> for the float value <strong id="b1339403212165622"><a name="b1339403212165622"></a><a name="b1339403212165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1634460022165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835604763165622"><a name="p1835604763165622"></a><a name="p1835604763165622"></a><a href="math.md#ga4b50bbed127a1c57940d600498a3c5c7">j1f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p763573644165622"><a name="p763573644165622"></a><a name="p763573644165622"></a>float </p>
<p id="p1242036625165622"><a name="p1242036625165622"></a><a name="p1242036625165622"></a>Calculates the Bessel function of the first kind of order <strong id="b2069848862165622"><a name="b2069848862165622"></a><a name="b2069848862165622"></a>1</strong> for the float value <strong id="b860049467165622"><a name="b860049467165622"></a><a name="b860049467165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row860143370165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229249064165622"><a name="p229249064165622"></a><a name="p229249064165622"></a><a href="math.md#gac3fcdfd92a775eed4ebd673d7da02525">jnf</a> (int n, float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p873337123165622"><a name="p873337123165622"></a><a name="p873337123165622"></a>float </p>
<p id="p2000644242165622"><a name="p2000644242165622"></a><a name="p2000644242165622"></a>Calculates the Bessel function of the first kind of order <strong id="b624554664165622"><a name="b624554664165622"></a><a name="b624554664165622"></a>n</strong> for the float value <strong id="b1836404476165622"><a name="b1836404476165622"></a><a name="b1836404476165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row926738077165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1841141346165622"><a name="p1841141346165622"></a><a name="p1841141346165622"></a><a href="math.md#gaba3cd2d73c1ae75ec2d01ebb2dfc108c">y0f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687325135165622"><a name="p1687325135165622"></a><a name="p1687325135165622"></a>float </p>
<p id="p1316198229165622"><a name="p1316198229165622"></a><a name="p1316198229165622"></a>Calculates the Bessel function of the second kind of order <strong id="b1851475153165622"><a name="b1851475153165622"></a><a name="b1851475153165622"></a>0</strong> for the float value <strong id="b2076926163165622"><a name="b2076926163165622"></a><a name="b2076926163165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1110118368165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996716295165622"><a name="p996716295165622"></a><a name="p996716295165622"></a><a href="math.md#ga5f37c38e8985dafae6abca2d1782c160">y1f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1711658779165622"><a name="p1711658779165622"></a><a name="p1711658779165622"></a>float </p>
<p id="p1024663094165622"><a name="p1024663094165622"></a><a name="p1024663094165622"></a>Calculates the Bessel function of the second kind of order <strong id="b1293333259165622"><a name="b1293333259165622"></a><a name="b1293333259165622"></a>1</strong> for the float value <strong id="b1876633294165622"><a name="b1876633294165622"></a><a name="b1876633294165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row138822079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136382431165622"><a name="p1136382431165622"></a><a name="p1136382431165622"></a><a href="math.md#ga47f8750942b731456dd7f2cbf5f55806">ynf</a> (int n, float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p810408719165622"><a name="p810408719165622"></a><a name="p810408719165622"></a>float </p>
<p id="p1331777119165622"><a name="p1331777119165622"></a><a name="p1331777119165622"></a>Calculates the Bessel function of the second kind of order <strong id="b20093339165622"><a name="b20093339165622"></a><a name="b20093339165622"></a>n</strong> for the float value <strong id="b1546566639165622"><a name="b1546566639165622"></a><a name="b1546566639165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row961000748165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900459268165622"><a name="p1900459268165622"></a><a name="p1900459268165622"></a><a href="math.md#ga278e86e217081a0268107f0d6876cb9b">lgammal_r</a> (long double x, int *signp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33758538165622"><a name="p33758538165622"></a><a name="p33758538165622"></a>long double </p>
<p id="p2024930547165622"><a name="p2024930547165622"></a><a name="p2024930547165622"></a>Calculates the natural logarithm of the absolute value of the gamma function of the double value <strong id="b1031621516165622"><a name="b1031621516165622"></a><a name="b1031621516165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1509985641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459044476165622"><a name="p1459044476165622"></a><a name="p1459044476165622"></a><a href="math.md#gaf4509ae544cecab0e9a61efdfccb7530">sincos</a> (double x, double *<a href="math.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a>, double *<a href="math.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1095889509165622"><a name="p1095889509165622"></a><a name="p1095889509165622"></a>void </p>
<p id="p570516610165622"><a name="p570516610165622"></a><a name="p570516610165622"></a>Calculates the sine and cosine of the double value <strong id="b1146522632165622"><a name="b1146522632165622"></a><a name="b1146522632165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1756548468165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p731622603165622"><a name="p731622603165622"></a><a name="p731622603165622"></a><a href="math.md#gac59adab35511be68e92ad9013d63e866">sincosf</a> (float x, float *<a href="math.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a>, float *<a href="math.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1360913075165622"><a name="p1360913075165622"></a><a name="p1360913075165622"></a>void </p>
<p id="p1515692806165622"><a name="p1515692806165622"></a><a name="p1515692806165622"></a>Calculates the sine and cosine of the float value <strong id="b659211464165622"><a name="b659211464165622"></a><a name="b659211464165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row295142197165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1555683671165622"><a name="p1555683671165622"></a><a name="p1555683671165622"></a><a href="math.md#gaf877b78dbe8e265bdf4b975dbc713482">sincosl</a> (long double x, long double *<a href="math.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a>, long double *<a href="math.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726948204165622"><a name="p1726948204165622"></a><a name="p1726948204165622"></a>void </p>
<p id="p977328494165622"><a name="p977328494165622"></a><a name="p977328494165622"></a>Calculates the sine and cosine of the long double value <strong id="b1827370878165622"><a name="b1827370878165622"></a><a name="b1827370878165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2022379621165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p976478649165622"><a name="p976478649165622"></a><a name="p976478649165622"></a><a href="math.md#gaea673cadd2aef111e2ee7a813776b768">exp10</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1730168228165622"><a name="p1730168228165622"></a><a name="p1730168228165622"></a>double </p>
<p id="p1118817891165622"><a name="p1118817891165622"></a><a name="p1118817891165622"></a>Calculates the base-10 exponential function of the double value <strong id="b532372729165622"><a name="b532372729165622"></a><a name="b532372729165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row393095365165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p910627456165622"><a name="p910627456165622"></a><a name="p910627456165622"></a><a href="math.md#gad27f10a0e30a7fe130c18786bf097e4b">exp10f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864199706165622"><a name="p864199706165622"></a><a name="p864199706165622"></a>float </p>
<p id="p467042127165622"><a name="p467042127165622"></a><a name="p467042127165622"></a>Calculates the base-10 exponential function of the float value <strong id="b973905594165622"><a name="b973905594165622"></a><a name="b973905594165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1454591318165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1992313180165622"><a name="p1992313180165622"></a><a name="p1992313180165622"></a><a href="math.md#ga28c11df4d7b29c9f59ac733fba51bece">exp10l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234692881165622"><a name="p234692881165622"></a><a name="p234692881165622"></a>long double </p>
<p id="p1616706774165622"><a name="p1616706774165622"></a><a name="p1616706774165622"></a>Calculates the base-10 exponential function of the long double value <strong id="b317960469165622"><a name="b317960469165622"></a><a name="b317960469165622"></a>x</strong>. </p>
</td>
</tr>
<tr id="row571432396165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1015626980165622"><a name="p1015626980165622"></a><a name="p1015626980165622"></a><a href="math.md#gafbbc60a3627a8de4845c7e99e6134ec8">pow10</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785794253165622"><a name="p785794253165622"></a><a name="p785794253165622"></a>double </p>
<p id="p1180027962165622"><a name="p1180027962165622"></a><a name="p1180027962165622"></a>Calculates the value of 10 raised to the power <strong id="b939879438165622"><a name="b939879438165622"></a><a name="b939879438165622"></a>x</strong>, which is a double value. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section561840359165622"></a>

## **Macro Definition **<a name="section1913429893165622"></a>

## isfinite<a name="ga256d70a32c03904ce13c999c1e9dc35d"></a>

```
#define isfinite( x)
```

```
Values:( \

sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) < 0x7f800000 : \

sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) < 0x7ffULL<<52 : \

__fpclassifyl(x) > [FP_INFINITE](math.md#ga4f64bcc64f8b84dd9daf5a4e56abf0ca))


```

 **Description:**

Checks whether the floating-point value  **x**  is finite. 

A finite value is any value that is neither an infinity nor a NaN value. 

**Parameters:**

<a name="table138295058165622"></a>
<table><thead align="left"><tr id="row24433629165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p33127381165622"><a name="p33127381165622"></a><a name="p33127381165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1574659518165622"><a name="p1574659518165622"></a><a name="p1574659518165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1591960025165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b584221048165622"><a name="b584221048165622"></a><a name="b584221048165622"></a>x</strong> to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if  **x**  is finite; returns  **0**  otherwise. 

## isgreater<a name="gada788e9d6ce0ca927874ec4e53af1f77"></a>

```
#define isgreater( x,  y )   __tg_pred_2(x, y, __isgreater)
```

 **Description:**

Checks whether floating-point value  **x**  is greater than  **y**. 

**Parameters:**

<a name="table1906912974165622"></a>
<table><thead align="left"><tr id="row1738212681165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1349291420165622"><a name="p1349291420165622"></a><a name="p1349291420165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p950355756165622"><a name="p950355756165622"></a><a name="p950355756165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1156733590165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b341866795165622"><a name="b341866795165622"></a><a name="b341866795165622"></a>x</strong> to check. </td>
</tr>
<tr id="row544835073165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b2073909450165622"><a name="b2073909450165622"></a><a name="b2073909450165622"></a>y</strong> to check. </td>
</tr>
</tbody>
</table>

**Attention:**

If either or both of  **x**  and  **y**  are a NaN value, an exception occurs. This function requires hardware support. 

**Returns:**

Returns  **1**  if  **x**  is greater than  **y**; returns  **0**  otherwise. 

## isgreaterequal<a name="ga5a7f86a4d3e6139e4913e2e8eba52612"></a>

```
#define isgreaterequal( x,  y )   __tg_pred_2(x, y, __isgreaterequal)
```

 **Description:**

Checks whether floating-point value  **x**  is greater than or equal to  **y**. 

**Parameters:**

<a name="table317848355165622"></a>
<table><thead align="left"><tr id="row914169113165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2051365011165622"><a name="p2051365011165622"></a><a name="p2051365011165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1857906585165622"><a name="p1857906585165622"></a><a name="p1857906585165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row979176419165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b835280492165622"><a name="b835280492165622"></a><a name="b835280492165622"></a>x</strong> to check. </td>
</tr>
<tr id="row293899501165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b362694348165622"><a name="b362694348165622"></a><a name="b362694348165622"></a>y</strong> to check. </td>
</tr>
</tbody>
</table>

**Attention:**

If either or both of  **x**  and  **y**  are a NaN value, an exception occurs. This function requires hardware support. 

**Returns:**

Returns  **1**  if  **x**  is greater than or equal to  **y**; returns  **0**  otherwise. 

## isinf<a name="ga2a266c767456556e5c0da234b602b18b"></a>

```
#define isinf( x)
```

```
Values:( \

sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) == 0x7f800000 : \

sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) == 0x7ffULL<<52 : \

__fpclassifyl(x) == [FP_INFINITE](math.md#ga4f64bcc64f8b84dd9daf5a4e56abf0ca))


```

 **Description:**

Checks whether the floating-point value  **x**  is an infinity. 

**Parameters:**

<a name="table456886529165622"></a>
<table><thead align="left"><tr id="row688985159165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p11509247165622"><a name="p11509247165622"></a><a name="p11509247165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1186706650165622"><a name="p1186706650165622"></a><a name="p1186706650165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row259794700165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b1785131297165622"><a name="b1785131297165622"></a><a name="b1785131297165622"></a>x</strong> to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if  **x**  is an infinity; returns  **0**  otherwise. 

## isless<a name="ga61079b32084130da4345c2eea93e0d61"></a>

```
#define isless( x,  y )   __tg_pred_2(x, y, __isless)
```

 **Description:**

Checks whether floating-point value  **x**  is less than  **y**. 

**Parameters:**

<a name="table1971684837165622"></a>
<table><thead align="left"><tr id="row2146890885165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p526727766165622"><a name="p526727766165622"></a><a name="p526727766165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p425626543165622"><a name="p425626543165622"></a><a name="p425626543165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row864860371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b1233185508165622"><a name="b1233185508165622"></a><a name="b1233185508165622"></a>x</strong> to check. </td>
</tr>
<tr id="row1583516803165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b1915716701165622"><a name="b1915716701165622"></a><a name="b1915716701165622"></a>y</strong> to check. </td>
</tr>
</tbody>
</table>

**Attention:**

If either or both of  **x**  and  **y**  are a NaN value, an exception occurs. This function requires hardware support. 

**Returns:**

Returns  **1**  if  **x**  is less than  **y**; returns  **0**  otherwise. 

## islessequal<a name="gabf3cb1e5a0aaa1c42dffa9ebb1d78c30"></a>

```
#define islessequal( x,  y )   __tg_pred_2(x, y, __islessequal)
```

 **Description:**

Checks whether floating-point value  **x**  is less than or equal to  **y**. 

**Parameters:**

<a name="table1763608193165622"></a>
<table><thead align="left"><tr id="row1332345847165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1872603838165622"><a name="p1872603838165622"></a><a name="p1872603838165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p965425706165622"><a name="p965425706165622"></a><a name="p965425706165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row216600758165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b1652558203165622"><a name="b1652558203165622"></a><a name="b1652558203165622"></a>x</strong> to check. </td>
</tr>
<tr id="row1693227900165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b47656672165622"><a name="b47656672165622"></a><a name="b47656672165622"></a>y</strong> to check. </td>
</tr>
</tbody>
</table>

**Attention:**

If either or both of  **x**  and  **y**  are a NaN value, an exception occurs. This function requires hardware support. 

**Returns:**

Returns  **1**  if  **x**  is less than or equal to  **y**; returns  **0**  otherwise. 

## islessgreater<a name="ga5e534756b747fd2e9ee19f8fdd93b30b"></a>

```
#define islessgreater( x,  y )   __tg_pred_2(x, y, __islessgreater)
```

 **Description:**

Checks whether floating-point value  **x**  is either less than or greater than  **y**. 

**Parameters:**

<a name="table856860307165622"></a>
<table><thead align="left"><tr id="row702471818165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p398457498165622"><a name="p398457498165622"></a><a name="p398457498165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p301755121165622"><a name="p301755121165622"></a><a name="p301755121165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row198077527165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b830791973165622"><a name="b830791973165622"></a><a name="b830791973165622"></a>x</strong> to check. </td>
</tr>
<tr id="row162740226165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b464984140165622"><a name="b464984140165622"></a><a name="b464984140165622"></a>y</strong> to check. </td>
</tr>
</tbody>
</table>

**Attention:**

If either or both of  **x**  and  **y**  are a NaN value, an exception occurs. This function requires hardware support. 

**Returns:**

Returns  **1**  if  **x**  is either less than or greater than  **y**; returns  **0**  otherwise. 

## isnan<a name="ga2e1baae9134e580910322362dc23290e"></a>

```
#define isnan( x)
```

```
Values:( \

sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) > 0x7f800000 : \

sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) > 0x7ffULL<<52 : \

__fpclassifyl(x) == [FP_NAN](math.md#ga1d481cc6e6a8ff729147ed46e61a4c9f))


```

 **Description:**

Checks whether the floating-point value  **x**  is a NaN value. 

**Parameters:**

<a name="table900462851165622"></a>
<table><thead align="left"><tr id="row1182329995165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1725105583165622"><a name="p1725105583165622"></a><a name="p1725105583165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p133471899165622"><a name="p133471899165622"></a><a name="p133471899165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row356934594165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b462987820165622"><a name="b462987820165622"></a><a name="b462987820165622"></a>x</strong> to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-zero value if  **x**  is a NaN value; returns  **0**  otherwise. 

## isnormal<a name="gad83f5949c4b5d810225b9a834840bac9"></a>

```
#define isnormal( x)
```

```
Values:( \

sizeof(x) == sizeof(float) ? ((__FLOAT_BITS(x)+0x00800000) & 0x7fffffff) >= 0x01000000 : \

sizeof(x) == sizeof(double) ? ((__DOUBLE_BITS(x)+(1ULL<<52)) & -1ULL>>1) >= 1ULL<<53 : \

__fpclassifyl(x) == [FP_NORMAL](math.md#gab9e29bb9e853934c4ba647c840b7e5de))


```

 **Description:**

Checks whether the floating-point value  **x**  is a normal value. 

A normal value refers to any value that is not an infinity, a NaN value, or  **0**. 

**Parameters:**

<a name="table1990219332165622"></a>
<table><thead align="left"><tr id="row1647511114165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p338276613165622"><a name="p338276613165622"></a><a name="p338276613165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1411165586165622"><a name="p1411165586165622"></a><a name="p1411165586165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row756647523165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b553033051165622"><a name="b553033051165622"></a><a name="b553033051165622"></a>x</strong> to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-zero value if  **x**  is a normal value; returns  **0**  otherwise. 

## isunordered<a name="ga33daf51eb7138d477e0b0985c51e4fad"></a>

```
#define isunordered( x,  y )   ([isnan](math.md#ga2e1baae9134e580910322362dc23290e)((x)) ? ((void)(y),1) : [isnan](math.md#ga2e1baae9134e580910322362dc23290e)((y)))
```

 **Description:**

Checks whether floating-point value  **x**  or  **y**  is unordered. 

An unordered value refers to a NaN value. 

**Parameters:**

<a name="table1498072980165622"></a>
<table><thead align="left"><tr id="row1234492421165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1038432378165622"><a name="p1038432378165622"></a><a name="p1038432378165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p724348715165622"><a name="p724348715165622"></a><a name="p724348715165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row204380988165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b1410891645165622"><a name="b1410891645165622"></a><a name="b1410891645165622"></a>x</strong> to check. </td>
</tr>
<tr id="row1385602874165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b999423184165622"><a name="b999423184165622"></a><a name="b999423184165622"></a>y</strong> to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if either  **x**  or  **y**  is unordered; returns  **0**  otherwise. 

## signbit<a name="gaa63ffa98f213f62e536b073c28cb3cd8"></a>

```
#define signbit( x)
```

```
Values:( \

sizeof(x) == sizeof(float) ? (int)(__FLOAT_BITS(x)>>31) : \

sizeof(x) == sizeof(double) ? (int)(__DOUBLE_BITS(x)>>63) : \

__signbitl(x) )


```

 **Description:**

Checks whether the sign of the floating-point value  **x**  is negative. 

**Parameters:**

<a name="table879172667165622"></a>
<table><thead align="left"><tr id="row1337451460165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p456831002165622"><a name="p456831002165622"></a><a name="p456831002165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p555417642165622"><a name="p555417642165622"></a><a name="p555417642165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1413433265165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the floating-point value <strong id="b1521010862165622"><a name="b1521010862165622"></a><a name="b1521010862165622"></a>x</strong> to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-zero value if the sign of  **x**  is negative; returns  **0**  otherwise. 

## **Function **<a name="section948971469165622"></a>

## acos\(\)<a name="gae93afe22ff34c79ee97ea3eaf77557db"></a>

```
double acos (double x)
```

 **Description:**

Calculates the arc cosine of the double value  **x**. 

**Parameters:**

<a name="table303378498165622"></a>
<table><thead align="left"><tr id="row654800947165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1902506026165622"><a name="p1902506026165622"></a><a name="p1902506026165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1814245116165622"><a name="p1814245116165622"></a><a name="p1814245116165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2145402054165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose arc cosine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc cosine of  **x**  in radians, ranging from 0 to  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+1**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a NaN value and reports a domain error. If  **x**  is out of the range \[-1, 1\], this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## acosf\(\)<a name="ga983a9e1aa7568df39153ea4d8e16653b"></a>

```
float acosf (float x)
```

 **Description:**

Calculates the arc cosine of the float value  **x**. 

**Parameters:**

<a name="table1155357514165622"></a>
<table><thead align="left"><tr id="row756798258165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p339892119165622"><a name="p339892119165622"></a><a name="p339892119165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p817933651165622"><a name="p817933651165622"></a><a name="p817933651165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1266314072165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose arc cosine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc cosine of  **x**  in radians, ranging from 0 to  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+1**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a NaN value and reports a domain error. If  **x**  is out of the range \[-1, 1\], this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## acosh\(\)<a name="gac862445bcb46911b1782c284829d5e46"></a>

```
double acosh (double x)
```

 **Description:**

Calculates the inverse hyperbolic cosine of the double value  **x**. 

**Parameters:**

<a name="table1832202808165622"></a>
<table><thead align="left"><tr id="row1083885670165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p561106405165622"><a name="p561106405165622"></a><a name="p561106405165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p319351827165622"><a name="p319351827165622"></a><a name="p319351827165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1403418387165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose inverse hyperbolic cosine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic cosine of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+1**, this function returns  **+0**. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is less than  **1**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## acoshf\(\)<a name="ga84cfd14c3432390f70b6233d24ad173b"></a>

```
float acoshf (float x)
```

 **Description:**

Calculates the inverse hyperbolic cosine of float value  **x**. 

**Parameters:**

<a name="table686209494165622"></a>
<table><thead align="left"><tr id="row74604238165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1334579327165622"><a name="p1334579327165622"></a><a name="p1334579327165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1976078591165622"><a name="p1976078591165622"></a><a name="p1976078591165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1503504029165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose inverse hyperbolic cosine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic cosine of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+1**, this function returns  **+0**. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is less than  **1**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## acoshl\(\)<a name="ga104456314ba05665d6cbb805e823dd10"></a>

```
long double acoshl (long double x)
```

 **Description:**

Calculates the inverse hyperbolic cosine of the long double value  **x**. 

**Parameters:**

<a name="table2143612362165622"></a>
<table><thead align="left"><tr id="row1510511053165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1102677314165622"><a name="p1102677314165622"></a><a name="p1102677314165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1415467581165622"><a name="p1415467581165622"></a><a name="p1415467581165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row73428493165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose inverse hyperbolic cosine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic cosine of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+1**, this function returns  **+0**. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is less than  **1**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## acosl\(\)<a name="gae84dc6cff92b3417098f16a1811635e4"></a>

```
long double acosl (long double x)
```

 **Description:**

Calculates the arc cosine of the long double value  **x**. 

**Parameters:**

<a name="table749063739165622"></a>
<table><thead align="left"><tr id="row1643216478165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p87259620165622"><a name="p87259620165622"></a><a name="p87259620165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p619159093165622"><a name="p619159093165622"></a><a name="p619159093165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row485738208165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose arc cosine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc cosine of  **x**  in radians, ranging from 0 to  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+1**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a NaN value and reports a domain error. If  **x**  is out of the range \[-1, 1\], this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## asin\(\)<a name="gaa9528d92a3ae44ad6484da0774604454"></a>

```
double asin (double x)
```

 **Description:**

Calculates the arc sine of the double value  **x**. 

**Parameters:**

<a name="table1617640468165622"></a>
<table><thead align="left"><tr id="row421382589165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1057102065165622"><a name="p1057102065165622"></a><a name="p1057102065165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p113235477165622"><a name="p113235477165622"></a><a name="p113235477165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1696257824165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose arc sine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc sine of  **x**  in radians, ranging from -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  to  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**. If  **x**  is out of the range \[-1, 1\], this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## asinf\(\)<a name="ga7447a7400ca474ba42d127b04d6ee2b7"></a>

```
float asinf (float x)
```

 **Description:**

Calculates the arc sine of the float value  **x**. 

**Parameters:**

<a name="table1042372362165622"></a>
<table><thead align="left"><tr id="row1666323964165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1107302228165622"><a name="p1107302228165622"></a><a name="p1107302228165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1583233690165622"><a name="p1583233690165622"></a><a name="p1583233690165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row527294471165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose arc sine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc sine of  **x**  in radians, ranging from -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  to  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**. If  **x**  is out of the range \[-1, 1\], this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## asinh\(\)<a name="ga907297107e93ea9c8a0c8409a8e65079"></a>

```
double asinh (double x)
```

 **Description:**

Calculates the inverse hyperbolic sine of the double value  **x**. 

**Parameters:**

<a name="table243377432165622"></a>
<table><thead align="left"><tr id="row1010290874165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1168725208165622"><a name="p1168725208165622"></a><a name="p1168725208165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1771469316165622"><a name="p1771469316165622"></a><a name="p1771469316165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1642481964165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose inverse hyperbolic sine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic sine of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. 

## asinhf\(\)<a name="ga1131c65ac49f31ed6774d27106c6394d"></a>

```
float asinhf (float x)
```

 **Description:**

Calculates the inverse hyperbolic sine of the float value  **x**. 

**Parameters:**

<a name="table1361598868165622"></a>
<table><thead align="left"><tr id="row204464592165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1164181354165622"><a name="p1164181354165622"></a><a name="p1164181354165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p975050362165622"><a name="p975050362165622"></a><a name="p975050362165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row21393508165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose inverse hyperbolic sine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic sine of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. 

## asinhl\(\)<a name="ga98df355372e19c11634992e4b7e35784"></a>

```
long double asinhl (long double x)
```

 **Description:**

Calculates the inverse hyperbolic sine of the long double value  **x**. 

**Parameters:**

<a name="table1691053399165622"></a>
<table><thead align="left"><tr id="row1318026844165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p365065856165622"><a name="p365065856165622"></a><a name="p365065856165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1852217095165622"><a name="p1852217095165622"></a><a name="p1852217095165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row444225373165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose inverse hyperbolic sine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic sine of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. 

## asinl\(\)<a name="ga3ace56b4f2a4a9364993a5af676793c5"></a>

```
long double asinl (long double x)
```

 **Description:**

Calculates the arc sine of the long double value  **x**. 

**Parameters:**

<a name="table1489422266165622"></a>
<table><thead align="left"><tr id="row682785223165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p996991931165622"><a name="p996991931165622"></a><a name="p996991931165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1033648816165622"><a name="p1033648816165622"></a><a name="p1033648816165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1665971399165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose arc sine is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc sine of  **x**  in radians, ranging from -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  to  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**. If  **x**  is out of the range \[-1, 1\], this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## atan\(\)<a name="ga1e2f8f6d64eaa95131bc63fee34970ea"></a>

```
double atan (double x)
```

 **Description:**

Calculates the arc tangent of the double value  **x**. 

**Parameters:**

<a name="table2029003518165622"></a>
<table><thead align="left"><tr id="row1068448585165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1000121029165622"><a name="p1000121029165622"></a><a name="p1000121029165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1617798195165622"><a name="p1617798195165622"></a><a name="p1617798195165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1619670531165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose arc tangent is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the principal value of the arc tangent of  **x**  in radians, ranging from -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  to  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). 

## atan2\(\)<a name="ga349377202ca14f79eb335b1a421fe4d8"></a>

```
double atan2 (double y, double x )
```

 **Description:**

Calculates the arc tangent of two double values  **x**  and  **y**. 

**Parameters:**

<a name="table1660121078165622"></a>
<table><thead align="left"><tr id="row786150996165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p457605808165622"><a name="p457605808165622"></a><a name="p457605808165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p887217325165622"><a name="p887217325165622"></a><a name="p887217325165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row991222605165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b888198415165622"><a name="b888198415165622"></a><a name="b888198415165622"></a>y</strong> for calculating the arc tangent. </td>
</tr>
<tr id="row634053065165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b2007763962165622"><a name="b2007763962165622"></a><a name="b2007763962165622"></a>x</strong> for calculating the arc tangent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the principal value of the arc tangent of y/x in radians, ranging from  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  to  **[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**. If  **y**  is  **+0**  or  **-0**, and  **x**  is less than  **0**, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is  **+0**  or  **-0**, and  **x**  is greater than  **0**, this function returns  **+0**  or  **-0**, respectively. If  **y**  is less than  **0**  and  **x**  is either  **+0**  or  **-0**, this function returns  **-[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**. If  **y**  is greater than  **0**  and  **x**  is either  **+0**  or  **-0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **y**  is  **+0**  or  **-0**, and  **x**  is  **-0**, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is  **+0**  or  **-0**, and  **x**  is  **+0**, this function returns  **+0**  or  **-0**, respectively. If  **y**  is a finite value greater than or less than  **0**, and  **x**  is a negative infinity, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is a finite value greater than or less than  **0**, and  **x**  is a positive infinity, this function returns  **+0**  or  **-0**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**  or  **-[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a negative infinity, this function returns  **+3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**  or  **-3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a positive infinity, this function returns  **+[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**  or  **-[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**, respectively. 

## atan2f\(\)<a name="gaf9e5469acf7a7bf82f29d86a77f539d4"></a>

```
float atan2f (float y, float x )
```

 **Description:**

Calculates the arc tangent of two float values  **x**  and  **y**. 

**Parameters:**

<a name="table1557012080165622"></a>
<table><thead align="left"><tr id="row661405691165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p871171819165622"><a name="p871171819165622"></a><a name="p871171819165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1385022153165622"><a name="p1385022153165622"></a><a name="p1385022153165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1684727503165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1958393714165622"><a name="b1958393714165622"></a><a name="b1958393714165622"></a>y</strong> for calculating the arc tangent. </td>
</tr>
<tr id="row1461136172165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b192743694165622"><a name="b192743694165622"></a><a name="b192743694165622"></a>x</strong> for calculating the arc tangent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the principal value of the arc tangent of y/x in radians, ranging from  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  to  **[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**. If  **y**  is  **+0**  or  **-0**, and  **x**  is less than  **0**, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is  **+0**  or  **-0**, and  **x**  is greater than  **0**, this function returns  **+0**  or  **-0**, respectively. If  **y**  is less than  **0**  and  **x**  is either  **+0**  or  **-0**, this function returns  **-[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**. If  **y**  is greater than  **0**  and  **x**  is either  **+0**  or  **-0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **y**  is  **+0**  or  **-0**, and  **x**  is  **-0**, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is  **+0**  or  **-0**, and  **x**  is  **+0**, this function returns  **+0**  or  **-0**, respectively. If  **y**  is a finite value greater than or less than  **0**, and  **x**  is a negative infinity, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is a finite value greater than or less than  **0**, and  **x**  is a positive infinity, this function returns  **+0**  or  **-0**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**  or  **-[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a negative infinity, this function returns  **+3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**  or  **-3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a positive infinity, this function returns  **+[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**  or  **-[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**, respectively. 

## atan2l\(\)<a name="gaa983bf34c931b97d66be8b7bfd03dc48"></a>

```
long double atan2l (long double y, long double x )
```

 **Description:**

Calculates the arc tangent of two long double values  **x**  and  **y**. 

**Parameters:**

<a name="table1135779805165622"></a>
<table><thead align="left"><tr id="row1017555744165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1897490918165622"><a name="p1897490918165622"></a><a name="p1897490918165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p395741257165622"><a name="p395741257165622"></a><a name="p395741257165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row377258821165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b430588793165622"><a name="b430588793165622"></a><a name="b430588793165622"></a>y</strong> for calculating the arc tangent. </td>
</tr>
<tr id="row46668842165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b2078108793165622"><a name="b2078108793165622"></a><a name="b2078108793165622"></a>x</strong> for calculating the arc tangent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the principal value of the arc tangent of y/x in radians, ranging from  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  to  **[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**. If  **y**  is  **+0**  or  **-0**, and  **x**  is less than  **0**, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is  **+0**  or  **-0**, and  **x**  is greater than  **0**, this function returns  **+0**  or  **-0**, respectively. If  **y**  is less than  **0**  and  **x**  is either  **+0**  or  **-0**, this function returns  **-[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**. If  **y**  is greater than  **0**  and  **x**  is either  **+0**  or  **-0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **y**  is  **+0**  or  **-0**, and  **x**  is  **-0**, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is  **+0**  or  **-0**, and  **x**  is  **+0**, this function returns  **+0**  or  **-0**, respectively. If  **y**  is a finite value greater than or less than  **0**, and  **x**  is a negative infinity, this function returns  **+[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**  or  **-[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)**, respectively. If  **y**  is a finite value greater than or less than  **0**, and  **x**  is a positive infinity, this function returns  **+0**  or  **-0**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**  or  **-[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a negative infinity, this function returns  **+3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**  or  **-3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**, respectively. If  **y**  is a positive or negative infinity, and  **x**  is a positive infinity, this function returns  **+[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**  or  **-[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)**, respectively. 

## atanf\(\)<a name="gaa582bc257e477e805f4ec384a39a3a8e"></a>

```
float atanf (float x)
```

 **Description:**

Calculates the arc tangent of the float value  **x**. 

**Parameters:**

<a name="table562889184165622"></a>
<table><thead align="left"><tr id="row630646732165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p860454436165622"><a name="p860454436165622"></a><a name="p860454436165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1077211540165622"><a name="p1077211540165622"></a><a name="p1077211540165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2077136141165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose arc tangent is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the principal value of the arc tangent of  **x**  in radians, ranging from -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  to  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  or -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f), respectively. 

## atanh\(\)<a name="gac07fd7b77fa341563abccf9efcc1a711"></a>

```
double atanh (double x)
```

 **Description:**

Calculates the inverse hyperbolic tangent of the double value  **x**. 

**Parameters:**

<a name="table131343639165622"></a>
<table><thead align="left"><tr id="row265693462165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p374056284165622"><a name="p374056284165622"></a><a name="p374056284165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p130516544165622"><a name="p130516544165622"></a><a name="p130516544165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1920409031165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose inverse hyperbolic tangent is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic tangent of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is  **+1**  or  **-1**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), reports a pole error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If the absolute value of  **x**  is greater than  **1**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## atanhf\(\)<a name="ga626d9d6644848e74188f37f0f3ddd4f4"></a>

```
float atanhf (float x)
```

 **Description:**

Calculates the inverse hyperbolic tangent of the float value  **x**. 

**Parameters:**

<a name="table547454688165622"></a>
<table><thead align="left"><tr id="row154206569165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2054734276165622"><a name="p2054734276165622"></a><a name="p2054734276165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p837192305165622"><a name="p837192305165622"></a><a name="p837192305165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1470752762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose inverse hyperbolic tangent is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic tangent of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is  **+1**  or  **-1**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), reports a pole error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If the absolute value of  **x**  is greater than  **1**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## atanhl\(\)<a name="gab25c31215118cd62672c38f80f010d66"></a>

```
long double atanhl (long double x)
```

 **Description:**

Calculates the inverse hyperbolic tangent of the long double value  **x**. 

**Parameters:**

<a name="table74725470165622"></a>
<table><thead align="left"><tr id="row1148800590165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1328514004165622"><a name="p1328514004165622"></a><a name="p1328514004165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1436209489165622"><a name="p1436209489165622"></a><a name="p1436209489165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1099125801165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose inverse hyperbolic tangent is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic tangent of  **x**. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is  **+1**  or  **-1**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), reports a pole error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If the absolute value of  **x**  is greater than  **1**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## atanl\(\)<a name="ga650d8dd23c16c6699d84651a18827d37"></a>

```
long double atanl (long double x)
```

 **Description:**

Calculates the arc tangent of the long double value  **x**. 

**Parameters:**

<a name="table1657146718165622"></a>
<table><thead align="left"><tr id="row721950887165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1586054313165622"><a name="p1586054313165622"></a><a name="p1586054313165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1680194229165622"><a name="p1680194229165622"></a><a name="p1680194229165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row741228062165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose arc tangent is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the principal value of the arc tangent of  **x**  in radians, ranging from -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  to  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f). If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  or -[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f), respectively. 

## cabs\(\)<a name="ga82c65f6b05062b620716623ba49ff07f"></a>

```
double cabs (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the absolute value of the complex number  **z**. 

**Parameters:**

<a name="table2135485645165622"></a>
<table><thead align="left"><tr id="row652372006165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1154163801165622"><a name="p1154163801165622"></a><a name="p1154163801165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1783597326165622"><a name="p1783597326165622"></a><a name="p1783597326165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1969790178165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose absolute value is to be obtained. </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [hypot](math.md#ga6d6a905f61d535f8454190433b8c0ea5)\([cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\) +  [creal](math.md#ga24b1a511efdb973354d81646c5c3bb81)\(z\)\). 

**Returns:**

Returns the absolute value of  **z**  if the operation is successful. 

## cabsf\(\)<a name="ga59a1f4977dfdf85b51a84bfd56737277"></a>

```
float cabsf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the absolute value of the complex number  **z**. 

**Parameters:**

<a name="table512842937165622"></a>
<table><thead align="left"><tr id="row386442287165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1192059842165622"><a name="p1192059842165622"></a><a name="p1192059842165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p866898906165622"><a name="p866898906165622"></a><a name="p866898906165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row304292471165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose absolute value is to be obtained. </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [hypot](math.md#ga6d6a905f61d535f8454190433b8c0ea5)\([cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\) +  [creal](math.md#ga24b1a511efdb973354d81646c5c3bb81)\(z\)\). 

**Returns:**

Returns the absolute value of  **z**  if the operation is successful. 

## cabsl\(\)<a name="ga7e37259e24f3384f376e4d3eb45a9ea8"></a>

```
long double cabsl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the absolute value of the complex number  **z**. 

**Parameters:**

<a name="table1275794490165622"></a>
<table><thead align="left"><tr id="row1768616122165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p449630379165622"><a name="p449630379165622"></a><a name="p449630379165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p277193354165622"><a name="p277193354165622"></a><a name="p277193354165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1553948689165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose absolute value is to be obtained. </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [hypot](math.md#ga6d6a905f61d535f8454190433b8c0ea5)\([cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\) +  [creal](math.md#ga24b1a511efdb973354d81646c5c3bb81)\(z\)\). 

**Returns:**

Returns the absolute value of  **z**  if the operation is successful. 

## cacos\(\)<a name="ga51a9bcdc7791e50f879c79d64362d7c3"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cacos (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table96673321165622"></a>
<table><thead align="left"><tr id="row507909326165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p440732166165622"><a name="p440732166165622"></a><a name="p440732166165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1541726315165622"><a name="p1541726315165622"></a><a name="p1541726315165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row863034284165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose arc cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc cosine of  **z**  if the operation is successful. If  **x**  is  **+0**  or  **-0**  and  **y**  is  **0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  - 0i**. If  **x**  is  **+0**  or  **-0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is not an infinity and  **y**  is an infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  -  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)  -  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)  -  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)  -  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  is a positive or negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  -  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cacosf\(\)<a name="ga238bc3dbd59adeb477af18c9a501e04e"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cacosf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table837245563165622"></a>
<table><thead align="left"><tr id="row727433264165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1964899085165622"><a name="p1964899085165622"></a><a name="p1964899085165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1618871869165622"><a name="p1618871869165622"></a><a name="p1618871869165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2005207213165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose arc cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc cosine of  **z**  if the operation is successful. If  **x**  is  **+0**  or  **-0**  and  **y**  is  **0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  - 0i**. If  **x**  is  **+0**  or  **-0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is not an infinity and  **y**  is an infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)  -  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)  -  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)  -  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  is a positive or negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  -  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cacosh\(\)<a name="gaf7286142554fde4ba6316a2b64b96c5c"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cacosh (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1404115663165622"></a>
<table><thead align="left"><tr id="row355680551165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1327788279165622"><a name="p1327788279165622"></a><a name="p1327788279165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2030734767165622"><a name="p2030734767165622"></a><a name="p2030734767165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row810091417165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose inverse hyperbolic cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic cosine of  **z**  if the operation is successful. If  **x**  is  **0**  and  **y**  is  **0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  + 3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cacoshf\(\)<a name="gabe9dbe34293eef409598b0559435c5ff"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cacoshf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table956876059165622"></a>
<table><thead align="left"><tr id="row238404089165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2085593092165622"><a name="p2085593092165622"></a><a name="p2085593092165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1276624735165622"><a name="p1276624735165622"></a><a name="p1276624735165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1017960561165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose inverse hyperbolic cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic cosine of  **z**  if the operation is successful. If  **x**  is  **0**  and  **y**  is  **0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  + 3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cacoshl\(\)<a name="gad8e03bbb434b8a9af73e0e3daec045ac"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cacoshl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table223400267165622"></a>
<table><thead align="left"><tr id="row1029269155165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1660587173165622"><a name="p1660587173165622"></a><a name="p1660587173165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p49495637165622"><a name="p49495637165622"></a><a name="p49495637165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row308610871165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose inverse hyperbolic cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic cosine of  **z**  if the operation is successful. If  **x**  is  **0**  and  **y**  is  **0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  + 3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cacosl\(\)<a name="ga789143f2859142f58590b2726328025f"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cacosl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1898914399165622"></a>
<table><thead align="left"><tr id="row1951409121165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1011667978165622"><a name="p1011667978165622"></a><a name="p1011667978165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2093695152165622"><a name="p2093695152165622"></a><a name="p2093695152165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row5368325165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose arc cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc cosine of  **z**  if the operation is successful. If  **x**  is  **+0**  or  **-0**  and  **y**  is  **0**, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  - 0i**. If  **x**  is  **+0**  or  **-0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is not an infinity and  **y**  is an infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)  -  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)  -  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)  -  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  is a positive or negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  -  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## carg\(\)<a name="ga4a1e5d839db7a1dc6013b2846b2432d9"></a>

```
double carg (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the phase angle of the complex number  **z**. 

**Parameters:**

<a name="table256475056165622"></a>
<table><thead align="left"><tr id="row1000091697165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p735080036165622"><a name="p735080036165622"></a><a name="p735080036165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1664523611165622"><a name="p1664523611165622"></a><a name="p1664523611165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row753905960165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose phase angle is to be obtained. </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [atan2](math.md#ga349377202ca14f79eb335b1a421fe4d8)\([cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\) +  [creal](math.md#ga24b1a511efdb973354d81646c5c3bb81)\(z\)\). 

**Returns:**

Returns the phase angle of  **z**  if the operation is successful. 

## cargf\(\)<a name="ga66334f398567baa3648cd3111ed68d3b"></a>

```
float cargf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the phase angle of the complex number  **z**. 

**Parameters:**

<a name="table152481086165622"></a>
<table><thead align="left"><tr id="row1456280507165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p358965925165622"><a name="p358965925165622"></a><a name="p358965925165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p617230607165622"><a name="p617230607165622"></a><a name="p617230607165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1356850045165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose phase angle is to be obtained. </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [atan2](math.md#ga349377202ca14f79eb335b1a421fe4d8)\([cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\) +  [creal](math.md#ga24b1a511efdb973354d81646c5c3bb81)\(z\)\). 

**Returns:**

Returns the phase angle of  **z**  if the operation is successful. 

## cargl\(\)<a name="ga74f3429f1b860581f4d15bea90533fd5"></a>

```
long double cargl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the phase angle of the complex number  **z**. 

**Parameters:**

<a name="table458145154165622"></a>
<table><thead align="left"><tr id="row1026329463165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1378248884165622"><a name="p1378248884165622"></a><a name="p1378248884165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p483502797165622"><a name="p483502797165622"></a><a name="p483502797165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1450718360165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [atan2](math.md#ga349377202ca14f79eb335b1a421fe4d8)\([cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\) +  [creal](math.md#ga24b1a511efdb973354d81646c5c3bb81)\(z\)\). 

**Returns:**

Returns the phase angle of  **z**  if the operation is successful. 

## casin\(\)<a name="gac43774f89411806a3e0695012cdb7f38"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) casin (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1771365294165622"></a>
<table><thead align="left"><tr id="row1449533203165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p834025805165622"><a name="p834025805165622"></a><a name="p834025805165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2068453729165622"><a name="p2068453729165622"></a><a name="p2068453729165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1573303665165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose arc sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## casinf\(\)<a name="ga04d2cd1f0b47d3f1b782aeb517151033"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) casinf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1590654675165622"></a>
<table><thead align="left"><tr id="row810084733165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1800115503165622"><a name="p1800115503165622"></a><a name="p1800115503165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p425856819165622"><a name="p425856819165622"></a><a name="p425856819165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2043900310165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose arc sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## casinh\(\)<a name="ga6fc1a0c1cbac62ba63e799d7e8f488e0"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) casinh (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1827405401165622"></a>
<table><thead align="left"><tr id="row1112685248165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1851203429165622"><a name="p1851203429165622"></a><a name="p1851203429165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p208297940165622"><a name="p208297940165622"></a><a name="p208297940165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row878282798165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose inverse hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## casinhf\(\)<a name="ga8b682e1c311efa5594ec0d0b39c9efe0"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) casinhf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1060062429165622"></a>
<table><thead align="left"><tr id="row1464730901165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1428365916165622"><a name="p1428365916165622"></a><a name="p1428365916165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p56201268165622"><a name="p56201268165622"></a><a name="p56201268165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1721812574165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose inverse hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## casinhl\(\)<a name="ga174b8f2a00e771dbbad06fdf0e0ee449"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) casinhl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1348045233165622"></a>
<table><thead align="left"><tr id="row2084133011165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p694125379165622"><a name="p694125379165622"></a><a name="p694125379165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1224944716165622"><a name="p1224944716165622"></a><a name="p1224944716165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1931139496165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose inverse hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## casinl\(\)<a name="ga8770350a79904ac151ebb3eebd736188"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) casinl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table296187224165622"></a>
<table><thead align="left"><tr id="row422817942165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1024614401165622"><a name="p1024614401165622"></a><a name="p1024614401165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p369166937165622"><a name="p369166937165622"></a><a name="p369166937165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row567036633165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose arc sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## catan\(\)<a name="ga1a77a3240b834af81a23b38f2af6c93d"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) catan (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table63879191165622"></a>
<table><thead align="left"><tr id="row142113488165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p649464915165622"><a name="p649464915165622"></a><a name="p649464915165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2137529177165622"><a name="p2137529177165622"></a><a name="p2137529177165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row136719399165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose arc tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  **1**  and  **y**  is  **0**, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## catanf\(\)<a name="ga4d0beef9b3994887e356c6b5c98388d9"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) catanf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table899604305165622"></a>
<table><thead align="left"><tr id="row492040306165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1810378190165622"><a name="p1810378190165622"></a><a name="p1810378190165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p209875844165622"><a name="p209875844165622"></a><a name="p209875844165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row836709787165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose arc tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  **1**  and  **y**  is  **0**, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## catanh\(\)<a name="ga376fef7890def8c0e7b2b5a5292be074"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) catanh (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1545742111165622"></a>
<table><thead align="left"><tr id="row166470297165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1611042945165622"><a name="p1611042945165622"></a><a name="p1611042945165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2048027975165622"><a name="p2048027975165622"></a><a name="p2048027975165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1175437526165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose inverse hyperbolic tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  **1**  and  **y**  is  **0**, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## catanhf\(\)<a name="ga480c29e0eeace893be77a2c61995d2ec"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) catanhf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1838420454165622"></a>
<table><thead align="left"><tr id="row564937589165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1692975961165622"><a name="p1692975961165622"></a><a name="p1692975961165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p503348268165622"><a name="p503348268165622"></a><a name="p503348268165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1576226487165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose inverse hyperbolic tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  **1**  and  **y**  is  **0**, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## catanhl\(\)<a name="gab2422355124f175a41ec092c3b8adf2b"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) catanhl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the inverse hyperbolic tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table671194240165622"></a>
<table><thead align="left"><tr id="row1460909729165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1042371087165622"><a name="p1042371087165622"></a><a name="p1042371087165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1495682945165622"><a name="p1495682945165622"></a><a name="p1495682945165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1201738603165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose inverse hyperbolic tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the inverse hyperbolic tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  **1**  and  **y**  is  **0**, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## catanl\(\)<a name="gaf28ad2f006e49eaa6bbdb97dd143d6cb"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) catanl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the arc tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table626870550165622"></a>
<table><thead align="left"><tr id="row1423762668165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2043612994165622"><a name="p2043612994165622"></a><a name="p2043612994165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p812902254165622"><a name="p812902254165622"></a><a name="p812902254165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1096954322165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose arc tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the arc tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  **1**  and  **y**  is  **0**, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cbrt\(\)<a name="ga8af00e2203928978e0242b4afd1d899f"></a>

```
double cbrt (double x)
```

 **Description:**

Calculates the cube root of the double value  **x**. 

**Parameters:**

<a name="table154655726165622"></a>
<table><thead align="left"><tr id="row1257865019165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p752325791165622"><a name="p752325791165622"></a><a name="p752325791165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p300980631165622"><a name="p300980631165622"></a><a name="p300980631165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row232398901165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose cube root is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cube root if the operation is successful; returns the passed  **x**  if  **x**  is  **+0**,  **-0**, a positive or negative infinity, or a NaN value. 

## cbrtf\(\)<a name="ga396c6a553500a355627741e234045bf4"></a>

```
float cbrtf (float x)
```

 **Description:**

Calculates the cube root of the float value  **x**. 

**Parameters:**

<a name="table1891021680165622"></a>
<table><thead align="left"><tr id="row903746155165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1214754512165622"><a name="p1214754512165622"></a><a name="p1214754512165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1852068904165622"><a name="p1852068904165622"></a><a name="p1852068904165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row512019792165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value whose cube root is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cube root if the operation is successful; returns the passed  **x**  if  **x**  is  **+0**,  **-0**, a positive or negative infinity, or a NaN value. 

## cbrtl\(\)<a name="ga521c2f4c10b7bb5363bad058ef56794c"></a>

```
long double cbrtl (long double x)
```

 **Description:**

Calculates the cube root of the long double value  **x**. 

**Parameters:**

<a name="table290516798165622"></a>
<table><thead align="left"><tr id="row946355699165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1520844880165622"><a name="p1520844880165622"></a><a name="p1520844880165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p579291953165622"><a name="p579291953165622"></a><a name="p579291953165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1108214484165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value whose cube root is to be calculated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cube root if the operation is successful; returns the passed  **x**  if  **x**  is  **+0**,  **-0**, a positive or negative infinity, or a NaN value. 

## ccos\(\)<a name="ga6a25bcd38751910533efde6dad1499c3"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ccos (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table438376458165622"></a>
<table><thead align="left"><tr id="row1060090560165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1475452465165622"><a name="p1475452465165622"></a><a name="p1475452465165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p187580312165622"><a name="p187580312165622"></a><a name="p187580312165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1257993219165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cosine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971). If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is a negative infinity and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is neither an infinity nor  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive or negative infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ccosf\(\)<a name="ga88df5eebfb10b88ed37e444f5b13fd6a"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ccosf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table495424387165622"></a>
<table><thead align="left"><tr id="row1772834539165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p663203086165622"><a name="p663203086165622"></a><a name="p663203086165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p121993024165622"><a name="p121993024165622"></a><a name="p121993024165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1354096337165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cosine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359). If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is a negative infinity and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is neither an infinity nor  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive or negative infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ccosh\(\)<a name="ga62c8f7e0cce95bbf670af16376909324"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ccosh (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table774113867165622"></a>
<table><thead align="left"><tr id="row2006291283165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1257878217165622"><a name="p1257878217165622"></a><a name="p1257878217165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1541434521165622"><a name="p1541434521165622"></a><a name="p1541434521165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row669630356165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose hyperbolic cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic cosine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is neither an infinity nor  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971). If  **x**  is a positive infinity and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive or negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is neither an infinity nor  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ccoshf\(\)<a name="gabe11c35bd81b278ab0e47196c5952662"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ccoshf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table756471007165622"></a>
<table><thead align="left"><tr id="row822776132165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p104576552165622"><a name="p104576552165622"></a><a name="p104576552165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p13731391165622"><a name="p13731391165622"></a><a name="p13731391165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row386116819165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose hyperbolic cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic cosine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is neither an infinity nor  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359). If  **x**  is a positive infinity and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive or negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is neither an infinity nor  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ccoshl\(\)<a name="gad2b7878b871c0266ecb1f58e5bf141a7"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ccoshl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table509764473165622"></a>
<table><thead align="left"><tr id="row1506213622165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1652618690165622"><a name="p1652618690165622"></a><a name="p1652618690165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1944334381165622"><a name="p1944334381165622"></a><a name="p1944334381165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row59538762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose hyperbolic cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic cosine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is neither an infinity nor  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182). If  **x**  is a positive infinity and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive or negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is neither an infinity nor  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ccosl\(\)<a name="ga785d8c7b2ac4283d4759dfa6a86779ab"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ccosl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the cosine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table326931793165622"></a>
<table><thead align="left"><tr id="row1525233649165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2139401245165622"><a name="p2139401245165622"></a><a name="p2139401245165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1382794650165622"><a name="p1382794650165622"></a><a name="p1382794650165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row883851889165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose cosine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cosine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182). If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is a negative infinity and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is neither an infinity nor  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive or negative infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is neither an infinity nor  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ceil\(\)<a name="ga1ea6d7b591132268abc2e843ababd084"></a>

```
double ceil (double x)
```

 **Description:**

Calculates the minimum integer greater than or equal to the double value  **x**. 

**Parameters:**

<a name="table1686614329165622"></a>
<table><thead align="left"><tr id="row279184939165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p995057946165622"><a name="p995057946165622"></a><a name="p995057946165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1491437447165622"><a name="p1491437447165622"></a><a name="p1491437447165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row112058277165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b2113397536165622"><a name="b2113397536165622"></a><a name="b2113397536165622"></a>x</strong> to compare with. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the minimum integer greater than or equal to  **x**  if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## ceilf\(\)<a name="ga8c1a8db0710bb3f25f643a0fca68fc60"></a>

```
float ceilf (float x)
```

 **Description:**

Calculates the minimum integer greater than or equal to the float value  **x**. 

**Parameters:**

<a name="table1665715542165622"></a>
<table><thead align="left"><tr id="row2122031430165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2009782014165622"><a name="p2009782014165622"></a><a name="p2009782014165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p200594995165622"><a name="p200594995165622"></a><a name="p200594995165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row511871116165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1759887517165622"><a name="b1759887517165622"></a><a name="b1759887517165622"></a>x</strong> to compare with. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the minimum integer greater than or equal to  **x**  if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## ceill\(\)<a name="gae11b7781f057eb7ba5d7ed95be7fdbee"></a>

```
long double ceill (long double x)
```

 **Description:**

Calculates the minimum integer greater than or equal to the long double value  **x**. 

**Parameters:**

<a name="table53712096165622"></a>
<table><thead align="left"><tr id="row57559869165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1916205842165622"><a name="p1916205842165622"></a><a name="p1916205842165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p302727586165622"><a name="p302727586165622"></a><a name="p302727586165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row311698761165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b333328015165622"><a name="b333328015165622"></a><a name="b333328015165622"></a>x</strong> to compare with. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the minimum integer greater than or equal to  **x**  if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## cexp\(\)<a name="gab9c654c52efefb54d06d52aa1a1c1827"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cexp (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the base-e exponential of the complex number  **z**. 

The mathematical formula is e^z. z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1503221481165622"></a>
<table><thead align="left"><tr id="row1544848795165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1243767446165622"><a name="p1243767446165622"></a><a name="p1243767446165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p27120243165622"><a name="p27120243165622"></a><a name="p27120243165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row603919119165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose base-e exponential is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-e exponential of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971). If  **x**  is a negative infinity and  **y**  is an infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **0**. If  **x**  is a positive infinity and  **y**  is neither an infinity nor  **0**, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cexpf\(\)<a name="ga8628a449a00228f124c9e53d2236611f"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cexpf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the base-e exponential of the complex number  **z**. 

The mathematical formula is e^z. z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table840815814165622"></a>
<table><thead align="left"><tr id="row1205031335165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2053509391165622"><a name="p2053509391165622"></a><a name="p2053509391165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1005539392165622"><a name="p1005539392165622"></a><a name="p1005539392165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row900236774165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose base-e exponential is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-e exponential of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359). If  **x**  is a negative infinity and  **y**  is an infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **0**. If  **x**  is a positive infinity and  **y**  is neither an infinity nor  **0**, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cexpl\(\)<a name="ga31a965fe1790cace431516e53f7d0cb5"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cexpl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the base-e exponential of the complex number  **z**. 

The mathematical formula is e^z. z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table2096895081165622"></a>
<table><thead align="left"><tr id="row149410625165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1517875299165622"><a name="p1517875299165622"></a><a name="p1517875299165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p610566540165622"><a name="p610566540165622"></a><a name="p610566540165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1383361781165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose base-e exponential is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-e exponential of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **1**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182). If  **x**  is a negative infinity and  **y**  is an infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **0**. If  **x**  is a positive infinity and  **y**  is neither an infinity nor  **0**, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## cimag\(\)<a name="ga6c3d7c875ae93700b0a2a32db24b37d3"></a>

```
double cimag (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the imaginary part of the complex number  **z**. 

 

**Parameters:**

<a name="table1401680482165622"></a>
<table><thead align="left"><tr id="row1669547090165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1643072135165622"><a name="p1643072135165622"></a><a name="p1643072135165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2131860628165622"><a name="p2131860628165622"></a><a name="p2131860628165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1588974305165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose imaginary part is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the imaginary part of  **z**  if the operation is successful. 

## cimagf\(\)<a name="gaac22dc2fffc4326595ff807d441f0675"></a>

```
float cimagf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the imaginary part of the complex number  **z**. 

 

**Parameters:**

<a name="table994305048165622"></a>
<table><thead align="left"><tr id="row571317915165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p747323256165622"><a name="p747323256165622"></a><a name="p747323256165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1698855777165622"><a name="p1698855777165622"></a><a name="p1698855777165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1665992402165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose imaginary part is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the imaginary part of  **z**  if the operation is successful. 

## cimagl\(\)<a name="ga4237f0401b8123eaec284c995ced4b04"></a>

```
long double cimagl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the imaginary part of the complex number  **z**. 

 

**Parameters:**

<a name="table1852770908165622"></a>
<table><thead align="left"><tr id="row270014743165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p17514189165622"><a name="p17514189165622"></a><a name="p17514189165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1686505163165622"><a name="p1686505163165622"></a><a name="p1686505163165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1865482827165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose imaginary part is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the imaginary part of  **z**  if the operation is successful. 

## clog\(\)<a name="gaa39c3557d8db10c19571bc0b63fd5529"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) clog (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the natural \(base-e\) logarithm of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table90673990165622"></a>
<table><thead align="left"><tr id="row709695139165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p30433266165622"><a name="p30433266165622"></a><a name="p30433266165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1334620230165622"><a name="p1334620230165622"></a><a name="p1334620230165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1504706623165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose natural (base-e) logarithm is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural \(base-e\) logarithm of  **z**  if the operation is successful. If  **x**  is  **-0**  and  **y**  is  **+0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  and  **y**  are both  **+0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  + 0i**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  + 3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  + 0i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## clogf\(\)<a name="ga0c9f343c7d1dabc91f6e4cb868b81152"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) clogf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the natural \(base-e\) logarithm of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1487488495165622"></a>
<table><thead align="left"><tr id="row2095950729165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p471747304165622"><a name="p471747304165622"></a><a name="p471747304165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1004002669165622"><a name="p1004002669165622"></a><a name="p1004002669165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1189728747165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose natural (base-e) logarithm is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural \(base-e\) logarithm of  **z**  if the operation is successful. If  **x**  is  **-0**  and  **y**  is  **+0**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  and  **y**  are both  **+0**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  + 0i**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  + 3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  + 0i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## clogl\(\)<a name="ga48efe0bf63314044fafaeb32623fff17"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) clogl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the natural \(base-e\) logarithm of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table614111916165622"></a>
<table><thead align="left"><tr id="row895775626165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1648997076165622"><a name="p1648997076165622"></a><a name="p1648997076165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p172022656165622"><a name="p172022656165622"></a><a name="p172022656165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1169622158165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose natural (base-e) logarithm is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural \(base-e\) logarithm of  **z**  if the operation is successful. If  **x**  is  **-0**  and  **y**  is  **+0**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  and  **y**  are both  **+0**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  + 0i**  and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_2](math.md#ga958e4508ed28ee5cc04249144312c15f)i**. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI](math.md#gae71449b1cc6e6250b91f539153a7a0d3)i**. If  **x**  is a negative infinity and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  + 3\*[M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  + 0i**. If  **x**  and  **y**  are both positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [M\_PI\_4](math.md#gaeb24420b096a677f3a2dc5a72b36bf22)i**. If  **x**  is an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not an infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## conj\(\)<a name="ga6fb30f37aa43eb2e0199ffdc38cac18a"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) conj (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the conjugate of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1045443513165622"></a>
<table><thead align="left"><tr id="row934427464165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p129859527165622"><a name="p129859527165622"></a><a name="p129859527165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p605153810165622"><a name="p605153810165622"></a><a name="p605153810165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row506176854165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose conjugate is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the conjugate of  **z**, which is equal to x - yi. 

## conjf\(\)<a name="ga471ecd8d25e722ecae510a635c1a2c53"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) conjf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the conjugate of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table65174850165622"></a>
<table><thead align="left"><tr id="row199127781165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p121066255165622"><a name="p121066255165622"></a><a name="p121066255165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p252786926165622"><a name="p252786926165622"></a><a name="p252786926165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1116253394165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose conjugate is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the conjugate of  **z**, which is equal to x - yi. 

## conjl\(\)<a name="ga5156353f4650ed7ee06b152790c1558b"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) conjl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the conjugate of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table729424498165622"></a>
<table><thead align="left"><tr id="row76345662165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p754143571165622"><a name="p754143571165622"></a><a name="p754143571165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1087979892165622"><a name="p1087979892165622"></a><a name="p1087979892165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row625070406165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose conjugate is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the conjugate of  **z**, which is equal to x - yi. 

## copysign\(\)<a name="gad8d1296592a3e783acdd0de21ff58e2e"></a>

```
double copysign (double x, double y )
```

 **Description:**

Generates a value by combining the magnitude of the double value  **x**  and the sign of the double value  **y**. 

For example, if  **x**  is  **42.0**  and  **y**  is  **-1.0**, value  **-42.0**  will be generated. 

**Parameters:**

<a name="table1939806238165622"></a>
<table><thead align="left"><tr id="row390417636165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p435360199165622"><a name="p435360199165622"></a><a name="p435360199165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1110978148165622"><a name="p1110978148165622"></a><a name="p1110978148165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row78603741165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b509017459165622"><a name="b509017459165622"></a><a name="b509017459165622"></a>x</strong> whose magnitude will be used. </td>
</tr>
<tr id="row1497883652165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1185059559165622"><a name="b1185059559165622"></a><a name="b1185059559165622"></a>y</strong> whose sign will be used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the generated value if the operation is successful; returns a NaN value with the sign of  **y**  if  **x**  is a NaN value. 

## copysignf\(\)<a name="gaf7eb976cc28d0a9a6f0827d01611f979"></a>

```
float copysignf (float x, float y )
```

 **Description:**

Generates a value by combining the magnitude of the float value  **x**  and the sign of the float value  **y**. 

For example, if  **x**  is  **42.0**  and  **y**  is  **-1.0**, value  **-42.0**  will be generated. 

**Parameters:**

<a name="table271922266165622"></a>
<table><thead align="left"><tr id="row450486435165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1660219603165622"><a name="p1660219603165622"></a><a name="p1660219603165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1066168232165622"><a name="p1066168232165622"></a><a name="p1066168232165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1726008239165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b690120730165622"><a name="b690120730165622"></a><a name="b690120730165622"></a>x</strong> whose magnitude will be used. </td>
</tr>
<tr id="row1019280319165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b952324937165622"><a name="b952324937165622"></a><a name="b952324937165622"></a>y</strong> whose sign will be used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the generated value if the operation is successful; returns a NaN value with the sign of  **y**  if  **x**  is a NaN value. 

## copysignl\(\)<a name="gae60d4866e88abf023d92d33c6351ae6f"></a>

```
long double copysignl (long double x, long double y )
```

 **Description:**

Generates a value by combining the magnitude of the long double value  **x**  and the sign of the long double value  **y**. 

For example, if  **x**  is  **42.0**  and  **y**  is  **-1.0**, value  **-42.0**  will be generated. 

**Parameters:**

<a name="table1133888313165622"></a>
<table><thead align="left"><tr id="row217439108165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1377276581165622"><a name="p1377276581165622"></a><a name="p1377276581165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2118238965165622"><a name="p2118238965165622"></a><a name="p2118238965165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1825333669165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1409020447165622"><a name="b1409020447165622"></a><a name="b1409020447165622"></a>x</strong> whose magnitude will be used. </td>
</tr>
<tr id="row1190355903165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1950369285165622"><a name="b1950369285165622"></a><a name="b1950369285165622"></a>y</strong> whose magnitude will be used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the generated value if the operation is successful; returns a NaN value with the sign of  **y**  if  **x**  is a NaN value. 

## cos\(\)<a name="ga5e7b53a694b3cf0f2d7debd444140fbd"></a>

```
double cos (double x)
```

 **Description:**

Calculates the cosine of the double value  **x**. 

**Parameters:**

<a name="table375552813165622"></a>
<table><thead align="left"><tr id="row32660145165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1391178318165622"><a name="p1391178318165622"></a><a name="p1391178318165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p855310476165622"><a name="p855310476165622"></a><a name="p855310476165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row167436411165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cosine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## cosf\(\)<a name="ga7b126b2344591e649c21c9ab0b8adb40"></a>

```
float cosf (float x)
```

 **Description:**

Calculates the cosine of the float value  **x**. 

**Parameters:**

<a name="table1580012316165622"></a>
<table><thead align="left"><tr id="row505739795165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1348323241165622"><a name="p1348323241165622"></a><a name="p1348323241165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p991400127165622"><a name="p991400127165622"></a><a name="p991400127165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1355905748165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cosine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## cosh\(\)<a name="ga3795d3c1f1d30819be56da4e4d67f64b"></a>

```
double cosh (double x)
```

 **Description:**

Calculates the hyperbolic cosine of the double value  **x**. 

**Parameters:**

<a name="table1717102808165622"></a>
<table><thead align="left"><tr id="row94058668165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1820047040165622"><a name="p1820047040165622"></a><a name="p1820047040165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1048344025165622"><a name="p1048344025165622"></a><a name="p1048344025165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1130533628165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic cosine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **1**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If an overflow range error occurs, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## coshf\(\)<a name="ga498b368486b7ce8677820beeb78d8f66"></a>

```
float coshf (float x)
```

 **Description:**

Calculates the hyperbolic cosine of the float value  **x**. 

**Parameters:**

<a name="table370714360165622"></a>
<table><thead align="left"><tr id="row644631077165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p26889878165622"><a name="p26889878165622"></a><a name="p26889878165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p192123725165622"><a name="p192123725165622"></a><a name="p192123725165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1443626938165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic cosine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **1**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359), sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## coshl\(\)<a name="ga57602cd20f8de2dceea4f05ffb516d82"></a>

```
long double coshl (long double x)
```

 **Description:**

Calculates the hyperbolic cosine of the long double value  **x**. 

**Parameters:**

<a name="table1163457587165622"></a>
<table><thead align="left"><tr id="row1048111648165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1051913084165622"><a name="p1051913084165622"></a><a name="p1051913084165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p14379825165622"><a name="p14379825165622"></a><a name="p14379825165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1448603248165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic cosine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **1**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182), sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## cosl\(\)<a name="ga659287f7399efa8d6bc66dc37c8e35f4"></a>

```
long double cosl (long double x)
```

 **Description:**

Calculates the cosine of the long double value  **x**. 

**Parameters:**

<a name="table1931457831165622"></a>
<table><thead align="left"><tr id="row1459470186165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1746033551165622"><a name="p1746033551165622"></a><a name="p1746033551165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p152989383165622"><a name="p152989383165622"></a><a name="p152989383165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row666453220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the cosine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## cpow\(\)<a name="ga6fd1bd16c6de991f95a4e19e0f2f2a12"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cpow (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) x, double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z )
```

 **Description:**

Calculates the value of  **x**  raised to the  **z**  power. 

The mathematical formula is x^z. 

**Parameters:**

<a name="table1233147927165622"></a>
<table><thead align="left"><tr id="row1140134756165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2112850662165622"><a name="p2112850662165622"></a><a name="p2112850662165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2102234891165622"><a name="p2102234891165622"></a><a name="p2102234891165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1025079415165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the base (a double complex number). </td>
</tr>
<tr id="row538210340165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the exponent (a double complex number). </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **x**  or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [cexp](math.md#gab9c654c52efefb54d06d52aa1a1c1827)\(z\*[clog](math.md#gaa39c3557d8db10c19571bc0b63fd5529)\(x\)\). 

**Returns:**

Returns the value of  **x**  raised to the  **z**  power if the operation is successful. 

## cpowf\(\)<a name="ga58beb4a3ea7b6ab6bb942900f94179fa"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cpowf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) x, float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z )
```

 **Description:**

Calculates the value of  **x**  raised to the  **z**  power. 

The mathematical formula is x^z. 

**Parameters:**

<a name="table241369781165622"></a>
<table><thead align="left"><tr id="row1451423066165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1637588938165622"><a name="p1637588938165622"></a><a name="p1637588938165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1421362549165622"><a name="p1421362549165622"></a><a name="p1421362549165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1626401565165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the base (a float complex number). </td>
</tr>
<tr id="row862571899165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the exponent (a float complex number). </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **x**  or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [cexp](math.md#gab9c654c52efefb54d06d52aa1a1c1827)\(z\*[clog](math.md#gaa39c3557d8db10c19571bc0b63fd5529)\(x\)\). 

**Returns:**

Returns the value of  **x**  raised to the  **z**  power if the operation is successful. 

## cpowl\(\)<a name="gae3ae7292dac86eeec3bb9a06b66f61cb"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cpowl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) x, long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z )
```

 **Description:**

Calculates the value of  **x**  raised to the  **z**  power. 

The mathematical formula is x^z. 

**Parameters:**

<a name="table526009748165622"></a>
<table><thead align="left"><tr id="row1279756134165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1347630703165622"><a name="p1347630703165622"></a><a name="p1347630703165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1419096563165622"><a name="p1419096563165622"></a><a name="p1419096563165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row190816455165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the base (a long double complex number). </td>
</tr>
<tr id="row1694319033165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the exponent (a long double complex number). </td>
</tr>
</tbody>
</table>

**Attention:**

If an error occurs or  **x**  or  **z**  is a positive or negative infinity or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), the returned value is calculated based on the formula  [cexp](math.md#gab9c654c52efefb54d06d52aa1a1c1827)\(z\*[clog](math.md#gaa39c3557d8db10c19571bc0b63fd5529)\(x\)\). 

**Returns:**

Returns the value of  **x**  raised to the  **z**  power if the operation is successful. 

## cproj\(\)<a name="gac10f86edf0994d0ee834768633be644e"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cproj (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the projection of the complex number  **z**  onto the Riemann sphere. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table77914029165622"></a>
<table><thead align="left"><tr id="row944522767165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p398442602165622"><a name="p398442602165622"></a><a name="p398442602165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1731728656165622"><a name="p1731728656165622"></a><a name="p1731728656165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1720553530165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose projection onto the Riemann sphere is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the projection of  **z**  onto the Riemann sphere if the operation is successful. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is an infinity, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971). If  **x**  is an infinity, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  + i\*[copysign](math.md#gad8d1296592a3e783acdd0de21ff58e2e)\(0.0,  [cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\)\). 

## cprojf\(\)<a name="ga9f435a71e44dd1e13eca358e2ca530e6"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cprojf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the projection of the complex number  **z**  onto the Riemann sphere. 

**Parameters:**

<a name="table1365932391165622"></a>
<table><thead align="left"><tr id="row1664683984165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p488680777165622"><a name="p488680777165622"></a><a name="p488680777165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1138386877165622"><a name="p1138386877165622"></a><a name="p1138386877165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row375275482165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose projection onto the Riemann sphere is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the projection of  **z**  onto the Riemann sphere if the operation is successful. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is an infinity, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359). If  **x**  is an infinity, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  + i\*[copysign](math.md#gad8d1296592a3e783acdd0de21ff58e2e)\(0.0,  [cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\)\). 

## cprojl\(\)<a name="ga2cc437f3ab8e77dbd8fb024c66474915"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) cprojl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the projection of the complex number  **z**  onto the Riemann sphere. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table296723106165622"></a>
<table><thead align="left"><tr id="row1616134281165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1756347696165622"><a name="p1756347696165622"></a><a name="p1756347696165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1453962602165622"><a name="p1453962602165622"></a><a name="p1453962602165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row325931180165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose projection onto the Riemann sphere is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the projection of  **z**  onto the Riemann sphere if the operation is successful. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is an infinity, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182). If  **x**  is an infinity, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  + i\*[copysign](math.md#gad8d1296592a3e783acdd0de21ff58e2e)\(0.0,  [cimag](math.md#ga6c3d7c875ae93700b0a2a32db24b37d3)\(z\)\). 

## creal\(\)<a name="ga24b1a511efdb973354d81646c5c3bb81"></a>

```
double creal (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the real part of the complex number  **z**. 

**Parameters:**

<a name="table709224826165622"></a>
<table><thead align="left"><tr id="row853118990165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p896631637165622"><a name="p896631637165622"></a><a name="p896631637165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p582482201165622"><a name="p582482201165622"></a><a name="p582482201165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1479926124165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose real part is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the real part of  **z**  if the operation is successful. 

## crealf\(\)<a name="gad052a3eb4d9f32153173e6bcea9e42ce"></a>

```
float crealf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the real part of the complex number  **z**. 

**Parameters:**

<a name="table1945878476165622"></a>
<table><thead align="left"><tr id="row450711908165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1620106973165622"><a name="p1620106973165622"></a><a name="p1620106973165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1203101354165622"><a name="p1203101354165622"></a><a name="p1203101354165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1626397656165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose real part is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the real part of  **z**  if the operation is successful. 

## creall\(\)<a name="ga4ee2baa54a4e51877c59527d2be1a0da"></a>

```
long double creall (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the real part of the complex number  **z**. 

**Parameters:**

<a name="table1628321030165622"></a>
<table><thead align="left"><tr id="row1975869527165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1033309013165622"><a name="p1033309013165622"></a><a name="p1033309013165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2007576796165622"><a name="p2007576796165622"></a><a name="p2007576796165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1686888177165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose real part is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the real part of  **z**  if the operation is successful. 

## csin\(\)<a name="ga1b9030685d326e66a93a35ca8c4bb0f6"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csin (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table806016706165622"></a>
<table><thead align="left"><tr id="row15137674165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p607514065165622"><a name="p607514065165622"></a><a name="p607514065165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1708897251165622"><a name="p1708897251165622"></a><a name="p1708897251165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row905532234165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive finite value and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csinf\(\)<a name="ga76dc89521e12096bc2104c9c0dcc20ea"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csinf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table2137221492165622"></a>
<table><thead align="left"><tr id="row468563986165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p527734073165622"><a name="p527734073165622"></a><a name="p527734073165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2050640046165622"><a name="p2050640046165622"></a><a name="p2050640046165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1871971231165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive finite value and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csinh\(\)<a name="ga0c782aa9258a4e11cc3ea57b2dcccfef"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csinh (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table540864051165622"></a>
<table><thead align="left"><tr id="row1209841498165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1336443969165622"><a name="p1336443969165622"></a><a name="p1336443969165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p350952822165622"><a name="p350952822165622"></a><a name="p350952822165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1815082162165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive finite value and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csinhf\(\)<a name="ga268ba13d67a10e6667bd6b64a1a96351"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csinhf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table12978444165622"></a>
<table><thead align="left"><tr id="row910518938165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1274832038165622"><a name="p1274832038165622"></a><a name="p1274832038165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1443448552165622"><a name="p1443448552165622"></a><a name="p1443448552165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row111977177165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive finite value and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csinhl\(\)<a name="ga0d14ae39cd9a811e42e36512fe6c7e53"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csinhl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1154644055165622"></a>
<table><thead align="left"><tr id="row921748062165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p108319580165622"><a name="p108319580165622"></a><a name="p108319580165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1646902951165622"><a name="p1646902951165622"></a><a name="p1646902951165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1690940138165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose hyperbolic sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive finite value and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csinl\(\)<a name="gad594fa6071ea5d383a0c7abaa0c32d80"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csinl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the sine of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1423730844165622"></a>
<table><thead align="left"><tr id="row1499235869165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1039200436165622"><a name="p1039200436165622"></a><a name="p1039200436165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1604015506165622"><a name="p1604015506165622"></a><a name="p1604015506165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1358867369165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose sine is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the sine of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is  **0**  and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **0**  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is a positive finite value and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive finite value and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  **0**, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)\*\([cos](math.md#ga5e7b53a694b3cf0f2d7debd444140fbd)\(y\) + i[sin](math.md#gaad4af25633b071b0e2cdb8ebd87eca77)\(y\)\)**. If  **x**  and  **y**  are both positive infinity, this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\) and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **+\(-\)[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  \(the sign bit of the real part of the returned value is uncertain\). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csqrt\(\)<a name="ga7ff172d72bc0474b93e27470ce94494b"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csqrt (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the square root of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table134864956165622"></a>
<table><thead align="left"><tr id="row824382871165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1758822070165622"><a name="p1758822070165622"></a><a name="p1758822070165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p766849869165622"><a name="p766849869165622"></a><a name="p766849869165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1996044661165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose square root is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the square root of  **z**  if the operation is successful. If  **x**  is  **+0**  or  **-0**  and  **y**  is  **+0**, this function returns  **+0 + 0i**. If  **x**  is neither an infinity nor  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  is a finite value or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**. If  **x**  is a negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  + 0i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is any value, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csqrtf\(\)<a name="gab8e425ba3e5d52d410afc3041bdeadce"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csqrtf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the square root of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table752816188165622"></a>
<table><thead align="left"><tr id="row1171470072165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1773123541165622"><a name="p1773123541165622"></a><a name="p1773123541165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1093329542165622"><a name="p1093329542165622"></a><a name="p1093329542165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1294473362165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose square root is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the square root of  **z**  if the operation is successful. If  **x**  is  **+0**  or  **-0**  and  **y**  is  **+0**, this function returns  **+0 + 0i**. If  **x**  is neither an infinity nor  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  is a finite value or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**. If  **x**  is a negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  + 0i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is any value, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## csqrtl\(\)<a name="ga94a429c220e400a1a6781d6e11cbfafd"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) csqrtl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the square root of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1042060017165622"></a>
<table><thead align="left"><tr id="row262012105165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p189280896165622"><a name="p189280896165622"></a><a name="p189280896165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p368262413165622"><a name="p368262413165622"></a><a name="p368262413165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1635313265165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose square root is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the square root of  **z**  if the operation is successful. If  **x**  is  **+0**  or  **-0**  and  **y**  is  **+0**, this function returns  **+0 + 0i**. If  **x**  is neither an infinity nor  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is a positive infinity, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  +  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  is a finite value or  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**. If  **x**  is a negative infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +\(-\)  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)i**  \(the sign bit of the imaginary part of the returned value is uncertain\). If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  + 0i**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)+[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is any value, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ctan\(\)<a name="ga665b5dfc1b1f51d3b444f049c6bd95dd"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ctan (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1400533512165622"></a>
<table><thead align="left"><tr id="row786293879165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1439943479165622"><a name="p1439943479165622"></a><a name="p1439943479165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1070170434165622"><a name="p1070170434165622"></a><a name="p1070170434165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1209714787165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **1**. If  **x**  and  **y**  are both positive infinity, this function returns  **1**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **1**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ctanf\(\)<a name="ga4301d608cc419f1ba3177fae4f258f30"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ctanf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1060913406165622"></a>
<table><thead align="left"><tr id="row1752947243165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p645220691165622"><a name="p645220691165622"></a><a name="p645220691165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p368842445165622"><a name="p368842445165622"></a><a name="p368842445165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1324101369165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **1**. If  **x**  and  **y**  are both positive infinity, this function returns  **1**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **1**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ctanh\(\)<a name="ga9c5cf378e654f3aaed9fb0f5c8223585"></a>

```
double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ctanh (double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table800496638165622"></a>
<table><thead align="left"><tr id="row72723209165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p613586477165622"><a name="p613586477165622"></a><a name="p613586477165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1539566359165622"><a name="p1539566359165622"></a><a name="p1539566359165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1703859300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a double value) whose hyperbolic tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **1**. If  **x**  and  **y**  are both positive infinity, this function returns  **1**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **1**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ctanhf\(\)<a name="gad68db7f429f2104acf52b096c5efb69a"></a>

```
float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ctanhf (float [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1192294414165622"></a>
<table><thead align="left"><tr id="row1690110861165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1078198823165622"><a name="p1078198823165622"></a><a name="p1078198823165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1926424102165622"><a name="p1926424102165622"></a><a name="p1926424102165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1924147026165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a float value) whose hyperbolic tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **1**. If  **x**  and  **y**  are both positive infinity, this function returns  **1**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **1**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ctanhl\(\)<a name="ga2fbb0a9d578343f924c96faed3189805"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ctanhl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the hyperbolic tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1933742031165622"></a>
<table><thead align="left"><tr id="row1996071364165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1611998355165622"><a name="p1611998355165622"></a><a name="p1611998355165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1977999475165622"><a name="p1977999475165622"></a><a name="p1977999475165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1677835903165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose hyperbolic tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **1**. If  **x**  and  **y**  are both positive infinity, this function returns  **1**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **1**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## ctanl\(\)<a name="ga7aa0362acd67521c9aac791aa617f953"></a>

```
long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) ctanl (long double [complex](math.md#ga0fa4878c968311979d497ccc322e0b9b) z)
```

 **Description:**

Calculates the tangent of the complex number  **z**. 

z = x + yi, where i =  [sqrt](math.md#gab87521a75ef827a85807f89a6c10629a)\(-1\) 

**Parameters:**

<a name="table1569953592165622"></a>
<table><thead align="left"><tr id="row1390476915165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1563385966165622"><a name="p1563385966165622"></a><a name="p1563385966165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1625396895165622"><a name="p1625396895165622"></a><a name="p1625396895165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row542656542165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the complex number (a long double value) whose tangent is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the tangent of  **z**  if the operation is successful. If  **x**  and  **y**  are both  **0**, this function returns  **0**. If  **x**  is not an infinity and  **y**  is a positive infinity, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is not an infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and may throw the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a positive infinity and  **y**  is a positive finite value, this function returns  **1**. If  **x**  and  **y**  are both positive infinity, this function returns  **1**. If  **x**  is a positive infinity and  **y**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **1**. If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is  **0**, this function returns  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc). If  **x**  is  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  and  **y**  is not  **0**, this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**  and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  and  **y**  are both  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc), this function returns  **[NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)  +  [NAN](math.md#ga8abfcc76130f3f991d124dd22d7e69bc)i**. 

## erf\(\)<a name="gaa8b35382a71885eed509a5f87bf5e266"></a>

```
double erf (double x)
```

 **Description:**

Calculates the error function of the double value  **x**. 

**Parameters:**

<a name="table1110718680165622"></a>
<table><thead align="left"><tr id="row1972911934165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p725027543165622"><a name="p725027543165622"></a><a name="p725027543165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p452886664165622"><a name="p452886664165622"></a><a name="p452886664165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row274205889165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the error function if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns  **+1**  or  **-1**, respectively. If an underflow range error occurs, this function returns  **2\*x/sqrt\(pi\)**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## erfc\(\)<a name="ga0b6c4cfae41124da64c9a2dcc09e6045"></a>

```
double erfc (double x)
```

 **Description:**

Calculates the complementary error function of the double value  **x**. 

**Parameters:**

<a name="table17616255165622"></a>
<table><thead align="left"><tr id="row635365286165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1701131787165622"><a name="p1701131787165622"></a><a name="p1701131787165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2106385414165622"><a name="p2106385414165622"></a><a name="p2106385414165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1787971253165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the complementary error function if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **1**. If  **x**  is a positive infinity, this function returns  **+0**. If  **x**  is a negative infinity, this function returns  **+2**. If an underflow range error occurs and an unrepresentable value is generated, this function returns  **0.0**. If an underflow range error occurs and a representable value is generated, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## erfcf\(\)<a name="gad948b9d3bfcb66c074ffe17326030d41"></a>

```
float erfcf (float x)
```

 **Description:**

Calculates the complementary error function of the float value  **x**. 

**Parameters:**

<a name="table1891169898165622"></a>
<table><thead align="left"><tr id="row1688234515165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2038199501165622"><a name="p2038199501165622"></a><a name="p2038199501165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1813103106165622"><a name="p1813103106165622"></a><a name="p1813103106165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row695617994165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the complementary error function if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **1**. If  **x**  is a positive infinity, this function returns  **+0**. If  **x**  is a negative infinity, this function returns  **+2**. If an underflow range error occurs and an unrepresentable value is generated, this function returns  **0.0**. If an underflow range error occurs and a representable value is generated, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## erfcl\(\)<a name="ga8ac2c9e0246c0c8106d04762a9623594"></a>

```
long double erfcl (long double x)
```

 **Description:**

Calculates the complementary error function of the long double value  **x**. 

**Parameters:**

<a name="table1419061993165622"></a>
<table><thead align="left"><tr id="row1079188164165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p224122979165622"><a name="p224122979165622"></a><a name="p224122979165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1958739118165622"><a name="p1958739118165622"></a><a name="p1958739118165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row308418481165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the complementary error function if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **1**. If  **x**  is a positive infinity, this function returns  **+0**. If  **x**  is a negative infinity, this function returns  **+2**. If an underflow range error occurs and an unrepresentable value is generated, this function returns  **0.0**. If an underflow range error occurs and a representable value is generated, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## erff\(\)<a name="gaabebdd2dd548c14805831297ac129862"></a>

```
float erff (float x)
```

 **Description:**

Calculates the error function of the float value  **x**. 

**Parameters:**

<a name="table553146713165622"></a>
<table><thead align="left"><tr id="row1065932162165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1566436370165622"><a name="p1566436370165622"></a><a name="p1566436370165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p172602148165622"><a name="p172602148165622"></a><a name="p172602148165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row785877213165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the error function if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns  **+1**  or  **-1**, respectively. If an underflow range error occurs, this function returns  **2\*x/sqrt\(pi\)**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## erfl\(\)<a name="ga6ccdcbbc2f0b22de2add8955e415170e"></a>

```
long double erfl (long double x)
```

 **Description:**

Calculates the error function of the long double value  **x**. 

**Parameters:**

<a name="table413299134165622"></a>
<table><thead align="left"><tr id="row1372321747165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1894479643165622"><a name="p1894479643165622"></a><a name="p1894479643165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p16064742165622"><a name="p16064742165622"></a><a name="p16064742165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2104986650165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the error function if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns  **+1**  or  **-1**, respectively. If an underflow range error occurs, this function returns  **2\*x/sqrt\(pi\)**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## exp\(\)<a name="gae09128febbbe6372cde4fa0c65608a42"></a>

```
double exp (double x)
```

 **Description:**

Calculates the base-e exponential function of the double value  **x**. 

**Parameters:**

<a name="table1060054691165622"></a>
<table><thead align="left"><tr id="row770837967165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p193749320165622"><a name="p193749320165622"></a><a name="p193749320165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1548249346165622"><a name="p1548249346165622"></a><a name="p1548249346165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row102331413165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-e exponential function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **+0**. If an underflow range error occurs, this function returns  **0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. If an overflow range error occurs, this function returns  **+[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## exp10\(\)<a name="gaea673cadd2aef111e2ee7a813776b768"></a>

```
double exp10 (double x)
```

 **Description:**

Calculates the base-10 exponential function of the double value  **x**. 

**Parameters:**

<a name="table484651504165622"></a>
<table><thead align="left"><tr id="row132217484165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1549256227165622"><a name="p1549256227165622"></a><a name="p1549256227165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1593547435165622"><a name="p1593547435165622"></a><a name="p1593547435165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2032172932165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b31134660165622"><a name="b31134660165622"></a><a name="b31134660165622"></a>x</strong> used as the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-10 exponential function of  **x**  if the operation is successful. 

## exp10f\(\)<a name="gad27f10a0e30a7fe130c18786bf097e4b"></a>

```
float exp10f (float x)
```

 **Description:**

Calculates the base-10 exponential function of the float value  **x**. 

**Parameters:**

<a name="table748440443165622"></a>
<table><thead align="left"><tr id="row375777529165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p798776960165622"><a name="p798776960165622"></a><a name="p798776960165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1842491342165622"><a name="p1842491342165622"></a><a name="p1842491342165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1106219744165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1406536663165622"><a name="b1406536663165622"></a><a name="b1406536663165622"></a>x</strong> used as the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-10 exponential function of  **x**  if the operation is successful. 

## exp10l\(\)<a name="ga28c11df4d7b29c9f59ac733fba51bece"></a>

```
long double exp10l (long double x)
```

 **Description:**

Calculates the base-10 exponential function of the long double value  **x**. 

**Parameters:**

<a name="table301884903165622"></a>
<table><thead align="left"><tr id="row316614133165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1847293736165622"><a name="p1847293736165622"></a><a name="p1847293736165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1569951435165622"><a name="p1569951435165622"></a><a name="p1569951435165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1488570264165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b60174534165622"><a name="b60174534165622"></a><a name="b60174534165622"></a>x</strong> used as the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-10 exponential function of  **x**  if the operation is successful. 

## exp2\(\)<a name="ga86e37219434c0b7978453b6ca88fc5fb"></a>

```
double exp2 (double x)
```

 **Description:**

Calculates the base-2 exponential function of the double value  **x**. 

**Parameters:**

<a name="table1845052905165622"></a>
<table><thead align="left"><tr id="row347445081165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p733247422165622"><a name="p733247422165622"></a><a name="p733247422165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p126908529165622"><a name="p126908529165622"></a><a name="p126908529165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row224197823165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-2 exponential function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **+0**. If an underflow range error occurs, this function returns  **0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. If an overflow range error occurs, this function returns  **+[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## exp2f\(\)<a name="gaed26c6708ff2027f9a8214d206eef0e7"></a>

```
float exp2f (float x)
```

 **Description:**

Calculates the base-2 exponential function of the float value  **x**. 

**Parameters:**

<a name="table592655758165622"></a>
<table><thead align="left"><tr id="row709429571165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p149318437165622"><a name="p149318437165622"></a><a name="p149318437165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1913273369165622"><a name="p1913273369165622"></a><a name="p1913273369165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row595593247165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-2 exponential function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **+0**. If an underflow range error occurs, this function returns  **0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. If an overflow range error occurs, this function returns  **+[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## exp2l\(\)<a name="ga4618e032de8318b72df5cc71f15b5e45"></a>

```
long double exp2l (long double x)
```

 **Description:**

Calculates the base-2 exponential function of the long double value  **x**. 

**Parameters:**

<a name="table411475165165622"></a>
<table><thead align="left"><tr id="row1218551904165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1450513068165622"><a name="p1450513068165622"></a><a name="p1450513068165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p733470877165622"><a name="p733470877165622"></a><a name="p733470877165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row671298819165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-2 exponential function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **+0**. If an underflow range error occurs, this function returns  **0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. If an overflow range error occurs, this function returns  **+[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## expf\(\)<a name="ga0c2bc89b8355a89542ac98d9e2120363"></a>

```
float expf (float x)
```

 **Description:**

Calculates the base-e exponential function of the float value  **x**. 

**Parameters:**

<a name="table1034418289165622"></a>
<table><thead align="left"><tr id="row92279612165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p999097444165622"><a name="p999097444165622"></a><a name="p999097444165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p881844922165622"><a name="p881844922165622"></a><a name="p881844922165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row97651691165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-e exponential function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **+0**. If an underflow range error occurs, this function returns  **0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. If an overflow range error occurs, this function returns  **+[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## expl\(\)<a name="gaed4eb11ef1397c751334311ce5b43920"></a>

```
long double expl (long double x)
```

 **Description:**

Calculates the base-e exponential function of the long double value  **x**. 

**Parameters:**

<a name="table1671285954165622"></a>
<table><thead align="left"><tr id="row606669639165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p83432850165622"><a name="p83432850165622"></a><a name="p83432850165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2035378317165622"><a name="p2035378317165622"></a><a name="p2035378317165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row602669144165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the base-e exponential function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **+0**. If an underflow range error occurs, this function returns  **0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. If an overflow range error occurs, this function returns  **+[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## expm1\(\)<a name="gae4963ac40f96d4b1fe8af1b1e90a20bb"></a>

```
double expm1 (double x)
```

 **Description:**

Calculates e raised to the power of the double value  **x**  minus one, that is, \(e^x\)-1. 

**Parameters:**

<a name="table1361009462165622"></a>
<table><thead align="left"><tr id="row1747889149165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p189848090165622"><a name="p189848090165622"></a><a name="p189848090165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1066814727165622"><a name="p1066814727165622"></a><a name="p1066814727165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1320807256165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns e raised to the power of  **x**  minus one if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **-1**. If an overflow range error occurs, this function returns  **+[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## expm1f\(\)<a name="ga5b8d8815f5c801fdbdb7f7767fbf9af4"></a>

```
float expm1f (float x)
```

 **Description:**

Calculates e raised to the power of the float value  **x**  minus one. 

**Parameters:**

<a name="table468918539165622"></a>
<table><thead align="left"><tr id="row461424202165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1651898454165622"><a name="p1651898454165622"></a><a name="p1651898454165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1531837226165622"><a name="p1531837226165622"></a><a name="p1531837226165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1919078149165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns e raised to the power of  **x**  minus one if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **-1**. If an overflow range error occurs, this function returns  **+[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## expm1l\(\)<a name="ga702b0680671cf9ef94017ac04f77358b"></a>

```
long double expm1l (long double x)
```

 **Description:**

Calculates e raised to the power of the long double value  **x**  minus one. 

**Parameters:**

<a name="table1686041386165622"></a>
<table><thead align="left"><tr id="row1239198435165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1695960497165622"><a name="p1695960497165622"></a><a name="p1695960497165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p919134832165622"><a name="p919134832165622"></a><a name="p919134832165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1952783389165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns e raised to the power of  **x**  minus one if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity, this function returns  **-1**. If an overflow range error occurs, this function returns  **+[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## fabs\(\)<a name="ga8fb5c0b9b43a108724b355136d29d2f9"></a>

```
double fabs (double x)
```

 **Description:**

Calculates the absolute value of the double value  **x**. 

**Parameters:**

<a name="table615555224165622"></a>
<table><thead align="left"><tr id="row161806195165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2075735233165622"><a name="p2075735233165622"></a><a name="p2075735233165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p459424342165622"><a name="p459424342165622"></a><a name="p459424342165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row210281578165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the absolute value of  **x**  if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **+0**  if  **x**  is  **-0**; returns a positive infinity if  **x**  is a positive or negative infinity. 

## fabsf\(\)<a name="ga9b02e2f3ebf257ac4f4d3ca1da6147d7"></a>

```
float fabsf (float x)
```

 **Description:**

Calculates the absolute value of the float value  **x**. 

**Parameters:**

<a name="table1868955217165622"></a>
<table><thead align="left"><tr id="row717321860165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p404984508165622"><a name="p404984508165622"></a><a name="p404984508165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p608725784165622"><a name="p608725784165622"></a><a name="p608725784165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row542617612165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the absolute value of  **x**  if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **+0**  if  **x**  is  **-0**; returns a positive infinity if  **x**  is a positive or negative infinity. 

## fabsl\(\)<a name="ga404c051ab9afd74c7ceed207683a235f"></a>

```
long double fabsl (long double x)
```

 **Description:**

Calculates the absolute value of the long double value  **x**. 

**Parameters:**

<a name="table1009836775165622"></a>
<table><thead align="left"><tr id="row715041714165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p706692146165622"><a name="p706692146165622"></a><a name="p706692146165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p558888896165622"><a name="p558888896165622"></a><a name="p558888896165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1239487701165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the absolute value of  **x**  if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **+0**  if  **x**  is  **-0**; returns a positive infinity if  **x**  is a positive or negative infinity. 

## fdim\(\)<a name="ga800522810eaaed28bd53798bff4b0bfa"></a>

```
double fdim (double x, double y )
```

 **Description:**

Calculates the positive difference between the double value  **x**  and  **y**. 

**Parameters:**

<a name="table387467425165622"></a>
<table><thead align="left"><tr id="row1268744705165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1593032420165622"><a name="p1593032420165622"></a><a name="p1593032420165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1325923472165622"><a name="p1325923472165622"></a><a name="p1325923472165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2063754134165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1987501096165622"><a name="b1987501096165622"></a><a name="b1987501096165622"></a>x</strong>. </td>
</tr>
<tr id="row454145461165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b316291807165622"><a name="b316291807165622"></a><a name="b316291807165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the positive difference between  **x**  and  **y**. 

## fdimf\(\)<a name="gaeee3a0bf2804c53c65199590ac4804cf"></a>

```
float fdimf (float x, float y )
```

 **Description:**

Calculates the positive difference between the float value  **x**  and  **y**. 

**Parameters:**

<a name="table1185085473165622"></a>
<table><thead align="left"><tr id="row1587842957165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1320764597165622"><a name="p1320764597165622"></a><a name="p1320764597165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1515118845165622"><a name="p1515118845165622"></a><a name="p1515118845165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row902538999165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b168815704165622"><a name="b168815704165622"></a><a name="b168815704165622"></a>x</strong>. </td>
</tr>
<tr id="row1474139820165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b806892843165622"><a name="b806892843165622"></a><a name="b806892843165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the positive difference between  **x**  and  **y**. 

## fdiml\(\)<a name="gab88ba65d1861deddbbc5cb5384d6a02e"></a>

```
long double fdiml (long double x, long double y )
```

 **Description:**

Calculates the positive difference between the long double value  **x**  and  **y**. 

**Parameters:**

<a name="table604031683165622"></a>
<table><thead align="left"><tr id="row1642195313165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p506155842165622"><a name="p506155842165622"></a><a name="p506155842165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p922874803165622"><a name="p922874803165622"></a><a name="p922874803165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1003477074165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1701120859165622"><a name="b1701120859165622"></a><a name="b1701120859165622"></a>x</strong>. </td>
</tr>
<tr id="row31919635165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1178977703165622"><a name="b1178977703165622"></a><a name="b1178977703165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the positive difference between  **x**  and  **y**. 

## finite\(\)<a name="ga08e754462e6ec13bc05fd41cff9cdd4a"></a>

```
int finite (double x)
```

 **Description:**

Checks whether the double value  **x**  is an infinity or a NaN value. 

**Parameters:**

<a name="table1291905289165622"></a>
<table><thead align="left"><tr id="row1877559649165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p681936478165622"><a name="p681936478165622"></a><a name="p681936478165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p354776106165622"><a name="p354776106165622"></a><a name="p354776106165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row187274498165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if  **x**  is an infinity or a NaN value; returns  **1**  otherwise. 

## finitef\(\)<a name="gaea39ac813876c506f8c351e6c14a5cb7"></a>

```
int finitef (float x)
```

 **Description:**

Checks whether the float value  **x**  is an infinity or a NaN value. 

**Parameters:**

<a name="table1896465843165622"></a>
<table><thead align="left"><tr id="row1694841969165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1332881791165622"><a name="p1332881791165622"></a><a name="p1332881791165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p298031683165622"><a name="p298031683165622"></a><a name="p298031683165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1372053997165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if  **x**  is an infinity or a NaN value; returns  **1**  otherwise. 

## floor\(\)<a name="ga6de60a3e907dcf0bfe3ea8d64f1e8873"></a>

```
double floor (double x)
```

 **Description:**

Obtains the largest integer less than or equal to the double value  **x**. 

**Parameters:**

<a name="table450152610165622"></a>
<table><thead align="left"><tr id="row851368170165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1289495015165622"><a name="p1289495015165622"></a><a name="p1289495015165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1264861366165622"><a name="p1264861366165622"></a><a name="p1264861366165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1294981636165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b838928319165622"><a name="b838928319165622"></a><a name="b838928319165622"></a>x</strong> to compare with. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the largest integer less than or equal to  **x**. 

## floorf\(\)<a name="ga0bcc6aa4b3c37bfa73f06ebdecc0d247"></a>

```
float floorf (float x)
```

 **Description:**

Obtains the largest integer less than or equal to the float value  **x**. 

**Parameters:**

<a name="table775142940165622"></a>
<table><thead align="left"><tr id="row198024100165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1649548435165622"><a name="p1649548435165622"></a><a name="p1649548435165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p286339461165622"><a name="p286339461165622"></a><a name="p286339461165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row972083035165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b604934889165622"><a name="b604934889165622"></a><a name="b604934889165622"></a>x</strong> to compare with. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the largest integer less than or equal to  **x**. 

## floorl\(\)<a name="ga211df53cdf5208b9bbfa92e2d9aef97f"></a>

```
long double floorl (long double x)
```

 **Description:**

Obtains the largest integer less than or equal to the long double value  **x**. 

**Parameters:**

<a name="table1880011652165622"></a>
<table><thead align="left"><tr id="row454522357165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1178919345165622"><a name="p1178919345165622"></a><a name="p1178919345165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1130417929165622"><a name="p1130417929165622"></a><a name="p1130417929165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1098724575165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b518871672165622"><a name="b518871672165622"></a><a name="b518871672165622"></a>x</strong> to compare with. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the largest integer less than or equal to  **x**. 

## fma\(\)<a name="gac6df7bd41d198a70da3915a80de5452d"></a>

```
double fma (double x, double y, double z )
```

 **Description:**

Calculates the value of  **x\*y+z**  and rounds the result up. 

**Parameters:**

<a name="table1528454493165622"></a>
<table><thead align="left"><tr id="row473719002165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p151879769165622"><a name="p151879769165622"></a><a name="p151879769165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p942332880165622"><a name="p942332880165622"></a><a name="p942332880165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row235288372165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1408394786165622"><a name="b1408394786165622"></a><a name="b1408394786165622"></a>x</strong>. </td>
</tr>
<tr id="row157201194165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1038895582165622"><a name="b1038895582165622"></a><a name="b1038895582165622"></a>y</strong>. </td>
</tr>
<tr id="row183237692165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1383712186165622"><a name="b1383712186165622"></a><a name="b1383712186165622"></a>z</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The rounding mode is the same as that set in the system. 

**Returns:**

Returns the calculation result. 

## fmaf\(\)<a name="gaa6b32a0b7f88680bb59bcfb9c6168ed2"></a>

```
float fmaf (float x, float y, float z )
```

 **Description:**

Calculates the value of  **x\*y+z**  and rounds the result up. 

**Parameters:**

<a name="table1333000608165622"></a>
<table><thead align="left"><tr id="row59063911165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p795334223165622"><a name="p795334223165622"></a><a name="p795334223165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2077568894165622"><a name="p2077568894165622"></a><a name="p2077568894165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row594088851165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b992378387165622"><a name="b992378387165622"></a><a name="b992378387165622"></a>x</strong>. </td>
</tr>
<tr id="row1812066262165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b39451332165622"><a name="b39451332165622"></a><a name="b39451332165622"></a>y</strong>. </td>
</tr>
<tr id="row896159791165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1153630560165622"><a name="b1153630560165622"></a><a name="b1153630560165622"></a>z</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The rounding mode is the same as that set in the system. 

**Returns:**

Returns the calculation result. 

## fmal\(\)<a name="gaf30b6b26252979964796ffa55dd30120"></a>

```
long double fmal (long double x, long double y, long double z )
```

 **Description:**

Calculates the value of  **x\*y+z**  and rounds the result up. 

**Parameters:**

<a name="table1332984361165622"></a>
<table><thead align="left"><tr id="row1806452365165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p87313590165622"><a name="p87313590165622"></a><a name="p87313590165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p231762583165622"><a name="p231762583165622"></a><a name="p231762583165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row785512526165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b629595858165622"><a name="b629595858165622"></a><a name="b629595858165622"></a>x</strong>. </td>
</tr>
<tr id="row989633571165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1560839522165622"><a name="b1560839522165622"></a><a name="b1560839522165622"></a>y</strong>. </td>
</tr>
<tr id="row941692177165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">z</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1439578098165622"><a name="b1439578098165622"></a><a name="b1439578098165622"></a>z</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The rounding mode is the same as that set in the system. 

**Returns:**

Returns the calculation result. 

## fmax\(\)<a name="ga35e041615ac931b4d848a7b173049301"></a>

```
double fmax (double x, double y )
```

 **Description:**

Obtains the larger value of two double values  **x**  and  **y**. 

**Parameters:**

<a name="table943900068165622"></a>
<table><thead align="left"><tr id="row821793790165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p508573578165622"><a name="p508573578165622"></a><a name="p508573578165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1507927566165622"><a name="p1507927566165622"></a><a name="p1507927566165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1790918517165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1996893793165622"><a name="b1996893793165622"></a><a name="b1996893793165622"></a>x</strong>. </td>
</tr>
<tr id="row2036803496165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b180127824165622"><a name="b180127824165622"></a><a name="b180127824165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the larger value. 

## fmaxf\(\)<a name="ga8849bfdbec18ded429fad4772cf60f4b"></a>

```
float fmaxf (float x, float y )
```

 **Description:**

Obtains the larger value of two float values  **x**  and  **y**. 

**Parameters:**

<a name="table529766100165622"></a>
<table><thead align="left"><tr id="row78223157165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2027190119165622"><a name="p2027190119165622"></a><a name="p2027190119165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1732053678165622"><a name="p1732053678165622"></a><a name="p1732053678165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row890579702165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b617698706165622"><a name="b617698706165622"></a><a name="b617698706165622"></a>x</strong>. </td>
</tr>
<tr id="row1824924156165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1687133811165622"><a name="b1687133811165622"></a><a name="b1687133811165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the larger value. 

## fmaxl\(\)<a name="ga0e31e170115494fdc03b6556844232f3"></a>

```
long double fmaxl (long double x, long double y )
```

 **Description:**

Obtains the larger value of two long double values  **x**  and  **y**. 

**Parameters:**

<a name="table454334399165622"></a>
<table><thead align="left"><tr id="row785055268165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p910462106165622"><a name="p910462106165622"></a><a name="p910462106165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p730858992165622"><a name="p730858992165622"></a><a name="p730858992165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1462915509165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1730580374165622"><a name="b1730580374165622"></a><a name="b1730580374165622"></a>x</strong>. </td>
</tr>
<tr id="row1173905179165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1090817186165622"><a name="b1090817186165622"></a><a name="b1090817186165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the larger value. 

## fmin\(\)<a name="gaf0a18b3ac9e461ac48b4cfffb4945a84"></a>

```
double fmin (double x, double y )
```

 **Description:**

Obtains the smaller value of two double values  **x**  and  **y**. 

**Parameters:**

<a name="table1323309783165622"></a>
<table><thead align="left"><tr id="row1428531085165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1170684097165622"><a name="p1170684097165622"></a><a name="p1170684097165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p644900452165622"><a name="p644900452165622"></a><a name="p644900452165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row739201049165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b792488165165622"><a name="b792488165165622"></a><a name="b792488165165622"></a>x</strong>. </td>
</tr>
<tr id="row2115383029165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1216248388165622"><a name="b1216248388165622"></a><a name="b1216248388165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the smaller value. 

## fminf\(\)<a name="ga9b4132c27f31d39c91c3c6063f378103"></a>

```
float fminf (float x, float y )
```

 **Description:**

Obtains the smaller value of two float values  **x**  and  **y**. 

**Parameters:**

<a name="table1529149764165622"></a>
<table><thead align="left"><tr id="row1850074550165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p313711461165622"><a name="p313711461165622"></a><a name="p313711461165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1140672181165622"><a name="p1140672181165622"></a><a name="p1140672181165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1328877008165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1669510706165622"><a name="b1669510706165622"></a><a name="b1669510706165622"></a>x</strong>. </td>
</tr>
<tr id="row2091994745165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1562214903165622"><a name="b1562214903165622"></a><a name="b1562214903165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the smaller value. 

## fminl\(\)<a name="ga8a301190384886aa4e327db265fb5c9f"></a>

```
long double fminl (long double x, long double y )
```

 **Description:**

Obtains the smaller value of two long double values  **x**  and  **y**. 

**Parameters:**

<a name="table979937086165622"></a>
<table><thead align="left"><tr id="row330605577165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p750431820165622"><a name="p750431820165622"></a><a name="p750431820165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1091426653165622"><a name="p1091426653165622"></a><a name="p1091426653165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row501553952165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1186105558165622"><a name="b1186105558165622"></a><a name="b1186105558165622"></a>x</strong>. </td>
</tr>
<tr id="row1410161305165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1200721531165622"><a name="b1200721531165622"></a><a name="b1200721531165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the smaller value. 

## fmod\(\)<a name="ga537296d1a8f9fb621676038b99ba7edf"></a>

```
double fmod (double x, double y )
```

 **Description:**

Calculates the remainder of the double value  **x**  divided by the double value  **y**. 

 

**Parameters:**

<a name="table943437029165622"></a>
<table><thead align="left"><tr id="row909133379165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p769558989165622"><a name="p769558989165622"></a><a name="p769558989165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2028739952165622"><a name="p2028739952165622"></a><a name="p2028739952165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row668251673165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b479359686165622"><a name="b479359686165622"></a><a name="b479359686165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row1812933749165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b713774900165622"><a name="b713774900165622"></a><a name="b713774900165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the remainder. 

## fmodf\(\)<a name="gaf17ec425baca2b5f3882a05b5e19dfb5"></a>

```
float fmodf (float x, float y )
```

 **Description:**

Calculates the remainder of the float value  **x**  divided by the float value  **y**. 

**Parameters:**

<a name="table348658188165622"></a>
<table><thead align="left"><tr id="row1901450248165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1096219598165622"><a name="p1096219598165622"></a><a name="p1096219598165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2139844351165622"><a name="p2139844351165622"></a><a name="p2139844351165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row86343234165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1615566420165622"><a name="b1615566420165622"></a><a name="b1615566420165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row1116259601165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b549101395165622"><a name="b549101395165622"></a><a name="b549101395165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the remainder. 

## fmodl\(\)<a name="gaa927d9996fb40db42bd3a6cbe57da9a7"></a>

```
long double fmodl (long double x, long double y )
```

 **Description:**

Calculates the remainder of the long double value  **x**  divided by the long double value  **y**. 

**Parameters:**

<a name="table398939588165622"></a>
<table><thead align="left"><tr id="row1895042990165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p43978765165622"><a name="p43978765165622"></a><a name="p43978765165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2093251030165622"><a name="p2093251030165622"></a><a name="p2093251030165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row435939803165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1017053755165622"><a name="b1017053755165622"></a><a name="b1017053755165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row1750910150165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b480473978165622"><a name="b480473978165622"></a><a name="b480473978165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the remainder. 

## frexp\(\)<a name="gae3fa88adf02f16a693f3dccea3c42ef0"></a>

```
double frexp (double x, int * exp )
```

 **Description:**

Decomposes the double value  **x**  into a significand and an integral exponent for 2. 

The absolute value of the significand ranges from 0.5 \(included\) to 1 \(excluded\). x = significand \* 2^exponent 

**Parameters:**

<a name="table1218960549165622"></a>
<table><thead align="left"><tr id="row785475162165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1188482850165622"><a name="p1188482850165622"></a><a name="p1188482850165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1977066741165622"><a name="p1977066741165622"></a><a name="p1977066741165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row318736790165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1631110225165622"><a name="b1631110225165622"></a><a name="b1631110225165622"></a>x</strong> to decompose. </td>
</tr>
<tr id="row831242360165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary significand of  **x**  if the operation is successful; returns  **0**  if  **x**  is  **0**  \(**exp**  is also  **0**\); returns a NaN value if  **x**  is a NaN value \(**exp**  is not specified\); returns a positive or negative infinity if  **x**  is a positive or negative infinity, respectively \(**exp**  is not specified\). 

## frexpf\(\)<a name="ga12c36e745d8a9eb4f01c7e0eeb426dd3"></a>

```
float frexpf (float x, int * exp )
```

 **Description:**

Decomposes float value  **x**  into a binary significand and an integral exponent for 2. 

The absolute value of the significand ranges from 0.5 \(included\) to 1 \(excluded\). x = significand \* 2^exponent 

**Parameters:**

<a name="table1667784522165622"></a>
<table><thead align="left"><tr id="row1791835890165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p798188601165622"><a name="p798188601165622"></a><a name="p798188601165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1486476637165622"><a name="p1486476637165622"></a><a name="p1486476637165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row595282686165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value to decompose. </td>
</tr>
<tr id="row1668596253165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to an integer where the exponent is stored. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary significand of  **x**  if the operation is successful; returns  **0**  if  **x**  is  **0**  \(**exp**  is also  **0**\); returns a NaN value if  **x**  is a NaN value \(**exp**  is not specified\); returns a positive or negative infinity if  **x**  is a positive or negative infinity \(**exp**  is not specified\). 

## frexpl\(\)<a name="ga239d50c0595ff8538b9aa3186ac4fd29"></a>

```
long double frexpl (long double x, int * exp )
```

 **Description:**

Decomposes long double value  **x**  into a binary significand and an integral exponent for 2. 

The absolute value of the significand ranges from 0.5 \(included\) to 1 \(excluded\). x = significand \* 2^exponent 

**Parameters:**

<a name="table1740123207165622"></a>
<table><thead align="left"><tr id="row1519047918165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p289444849165622"><a name="p289444849165622"></a><a name="p289444849165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1657776396165622"><a name="p1657776396165622"></a><a name="p1657776396165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2012963932165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value to decompose. </td>
</tr>
<tr id="row206544496165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to an integer where the exponent is stored. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary significand of  **x**  if the operation is successful; returns  **0**  if  **x**  is  **0**  \(**exp**  is also  **0**\); returns a NaN value if  **x**  is a NaN value \(**exp**  is not specified\); returns a positive or negative infinity if  **x**  is a positive or negative infinity \(**exp**  is not specified\). 

## hypot\(\)<a name="ga6d6a905f61d535f8454190433b8c0ea5"></a>

```
double hypot (double x, double y )
```

 **Description:**

Calculates the hypotenuse of a right triangle whose legs are  **x**  and  **y**. 

**Parameters:**

<a name="table1193412096165622"></a>
<table><thead align="left"><tr id="row124635003165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1760526730165622"><a name="p1760526730165622"></a><a name="p1760526730165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1837669037165622"><a name="p1837669037165622"></a><a name="p1837669037165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1790909809165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of one side of the right triangle, represented using a double value. </td>
</tr>
<tr id="row837697874165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the other side of the right triangle, represented using a double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hypotenuse of the right triangle. 

## hypotf\(\)<a name="ga9fa4a03d7c4abfda7d9ad7b6ff7f6456"></a>

```
float hypotf (float x, float y )
```

 **Description:**

Calculates the hypotenuse of a right triangle whose legs are  **x**  and  **y**. 

**Parameters:**

<a name="table490942843165622"></a>
<table><thead align="left"><tr id="row326342022165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p461473677165622"><a name="p461473677165622"></a><a name="p461473677165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1336317255165622"><a name="p1336317255165622"></a><a name="p1336317255165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1416132085165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of one side of the right triangle, represented using a float value. </td>
</tr>
<tr id="row1067200773165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the other side of the right triangle, represented using a float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hypotenuse of the right triangle. 

## hypotl\(\)<a name="ga92a0e76d17c34fc1b3b2e7c0868aea6e"></a>

```
long double hypotl (long double x, long double y )
```

 **Description:**

Calculates the hypotenuse of a right triangle whose legs are  **x**  and  **y**. 

**Parameters:**

<a name="table731257374165622"></a>
<table><thead align="left"><tr id="row1135608242165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1249980835165622"><a name="p1249980835165622"></a><a name="p1249980835165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1609167721165622"><a name="p1609167721165622"></a><a name="p1609167721165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row776407953165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of one side of the right triangle, represented using a long double value. </td>
</tr>
<tr id="row214660479165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the other side of the right triangle, represented using a long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hypotenuse of the right triangle. 

## ilogb\(\)<a name="ga600dd249210d15af31b9a29c2d09d255"></a>

```
int ilogb (double x)
```

 **Description:**

Obtains the integral part of the logarithm of double value  **x**. 

**FLT\_RADIX**  is used as the base for the logarithm. 

**Parameters:**

<a name="table783177947165622"></a>
<table><thead align="left"><tr id="row1893348669165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2054885825165622"><a name="p2054885825165622"></a><a name="p2054885825165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1759981640165622"><a name="p1759981640165622"></a><a name="p1759981640165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2120380297165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the integral part of the logarithm of  **x**  if the operation is successful. If  **x**  is  **0**, this function returns  [FP\_ILOGB0](math.md#ga9ec0e31304d15c42262b2c4a3b58443c)  and reports a domain error. If  **x**  is a NaN value, this function returns  [FP\_ILOGBNAN](math.md#ga01e2e5be97c739a5bdcbc619b44f9742)  and reports a domain error. If  **x**  is positive or negative infinity, this function returns  [INT\_MAX](utils.md#ga9ec306f36d50c7375e74f0d1c55a3a67)  and reports a domain error. 

## ilogbf\(\)<a name="gaf53f0f07bb80b1a38fb47773a190e7a7"></a>

```
int ilogbf (float x)
```

 **Description:**

Obtains the integral part of the logarithm of float value  **x**. 

**FLT\_RADIX**  is used as the base for the logarithm. 

**Parameters:**

<a name="table471450270165622"></a>
<table><thead align="left"><tr id="row388257112165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p813557626165622"><a name="p813557626165622"></a><a name="p813557626165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1834475725165622"><a name="p1834475725165622"></a><a name="p1834475725165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1605137986165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the integral part of the logarithm of  **x**  if the operation is successful. If  **x**  is  **0**, this function returns  [FP\_ILOGB0](math.md#ga9ec0e31304d15c42262b2c4a3b58443c)  and reports a domain error. If  **x**  is a NaN value, this function returns  [FP\_ILOGBNAN](math.md#ga01e2e5be97c739a5bdcbc619b44f9742)  and reports a domain error. If  **x**  is positive or negative infinity, this function returns  [INT\_MAX](utils.md#ga9ec306f36d50c7375e74f0d1c55a3a67)  and reports a domain error. 

## ilogbl\(\)<a name="gafbd166ed232a372f090b8f9fa8441423"></a>

```
int ilogbl (long double x)
```

 **Description:**

Obtains the integral part of the logarithm of the long double value  **x**. 

**FLT\_RADIX**  is used as the base for the logarithm. 

**Parameters:**

<a name="table2025226517165622"></a>
<table><thead align="left"><tr id="row1982196020165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p971599215165622"><a name="p971599215165622"></a><a name="p971599215165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1771779215165622"><a name="p1771779215165622"></a><a name="p1771779215165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1809025297165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the integral part of the logarithm of  **x**  if the operation is successful. If  **x**  is  **0**, this function returns  [FP\_ILOGB0](math.md#ga9ec0e31304d15c42262b2c4a3b58443c)  and reports a domain error. If  **x**  is a NaN value, this function returns  [FP\_ILOGBNAN](math.md#ga01e2e5be97c739a5bdcbc619b44f9742)  and reports a domain error. If  **x**  is positive or negative infinity, this function returns  [INT\_MAX](utils.md#ga9ec306f36d50c7375e74f0d1c55a3a67)  and reports a domain error. 

## j0\(\)<a name="gaffb00730a1127dee798137075951ae21"></a>

```
double j0 (double x)
```

 **Description:**

Calculates the Bessel function of the first kind of order  **0**  for the double value  **x**. 

**Parameters:**

<a name="table565725511165622"></a>
<table><thead align="left"><tr id="row1924046690165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1163847124165622"><a name="p1163847124165622"></a><a name="p1163847124165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1244888985165622"><a name="p1244888985165622"></a><a name="p1244888985165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1623181309165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the Bessel function of the first kind of order  **0**  for  **x**  if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **0**  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)  if  **x**  is too large or an overflow range error occurs. 

## j0f\(\)<a name="gafa59b98550749c27995dfb7c70e6783a"></a>

```
float j0f (float x)
```

 **Description:**

Calculates the Bessel function of the first kind of order  **0**  for the float value  **x**. 

**Parameters:**

<a name="table1195519585165622"></a>
<table><thead align="left"><tr id="row1116226859165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1928186715165622"><a name="p1928186715165622"></a><a name="p1928186715165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1203457947165622"><a name="p1203457947165622"></a><a name="p1203457947165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1452627380165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **0**  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)  if  **x**  is too large or an overflow range error occurs. 

## j1\(\)<a name="ga8cac4aa70c418eba481417f1878b4cee"></a>

```
double j1 (double x)
```

 **Description:**

Calculates the Bessel function of the first kind of order  **1**  for the double value  **x**. 

**Parameters:**

<a name="table679615328165622"></a>
<table><thead align="left"><tr id="row537407734165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1815069195165622"><a name="p1815069195165622"></a><a name="p1815069195165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p800822081165622"><a name="p800822081165622"></a><a name="p800822081165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row750576137165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the Bessel function of the first kind of order  **1**  for  **x**  if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **0**  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)  if  **x**  is too large or an overflow range error occurs. 

## j1f\(\)<a name="ga4b50bbed127a1c57940d600498a3c5c7"></a>

```
float j1f (float x)
```

 **Description:**

Calculates the Bessel function of the first kind of order  **1**  for the float value  **x**. 

**Parameters:**

<a name="table940722242165622"></a>
<table><thead align="left"><tr id="row1483015308165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p198833107165622"><a name="p198833107165622"></a><a name="p198833107165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1164593266165622"><a name="p1164593266165622"></a><a name="p1164593266165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2015562690165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **0**  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)  if  **x**  is too large or an overflow range error occurs. 

## jn\(\)<a name="gadeff843dc8106ffda5caba6df44c591d"></a>

```
double jn (int n, double x )
```

 **Description:**

Calculates the Bessel function of the first kind of order  **n**  for the double value  **x**. 

**Parameters:**

<a name="table1863009370165622"></a>
<table><thead align="left"><tr id="row873735818165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p396981219165622"><a name="p396981219165622"></a><a name="p396981219165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p108317568165622"><a name="p108317568165622"></a><a name="p108317568165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1708205711165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the order of the Bessel function of the first kind. </td>
</tr>
<tr id="row394523469165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the Bessel function of the first kind of order  **n**  for  **x**  if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **0**  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)  if  **x**  is too large or an overflow range error occurs. 

## jnf\(\)<a name="gac3fcdfd92a775eed4ebd673d7da02525"></a>

```
float jnf (int n, float x )
```

 **Description:**

Calculates the Bessel function of the first kind of order  **n**  for the float value  **x**. 

**Parameters:**

<a name="table1158748012165622"></a>
<table><thead align="left"><tr id="row1577080535165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p688540085165622"><a name="p688540085165622"></a><a name="p688540085165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1374489324165622"><a name="p1374489324165622"></a><a name="p1374489324165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row609519912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the order of the Bessel function of the first kind. </td>
</tr>
<tr id="row324805076165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **0**  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)  if  **x**  is too large or an overflow range error occurs. 

## ldexp\(\)<a name="gab3662815756f0bd419dc1b12f4ad905d"></a>

```
double ldexp (double x, int exp )
```

 **Description:**

Multiplies the double value  **x**  by 2 raised to the power of  **exp**. 

The calculation formula is x\*2^exp. 

**Parameters:**

<a name="table673030055165622"></a>
<table><thead align="left"><tr id="row688861477165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p295616294165622"><a name="p295616294165622"></a><a name="p295616294165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p66034365165622"><a name="p66034365165622"></a><a name="p66034365165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row53752345165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
<tr id="row2125528072165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result. 

## ldexpf\(\)<a name="gaacd370a7830c29f47239dea1ea2eb7f9"></a>

```
float ldexpf (float x, int exp )
```

 **Description:**

Multiplies the float value  **x**  by 2 raised to the power of  **exp**. 

The calculation formula is x\*2^exp. 

**Parameters:**

<a name="table682927369165622"></a>
<table><thead align="left"><tr id="row490498940165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1075999132165622"><a name="p1075999132165622"></a><a name="p1075999132165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1482841004165622"><a name="p1482841004165622"></a><a name="p1482841004165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row986166421165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
<tr id="row2056694092165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result. 

## ldexpl\(\)<a name="ga454187039ef790629dab1e7724c3c3b2"></a>

```
long double ldexpl (long double x, int exp )
```

 **Description:**

Multiplies the long double value  **x**  by 2 raised to the power of  **exp**. 

The calculation formula is x\*2^exp. 

**Parameters:**

<a name="table187239852165622"></a>
<table><thead align="left"><tr id="row793182420165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p890194646165622"><a name="p890194646165622"></a><a name="p890194646165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p534605764165622"><a name="p534605764165622"></a><a name="p534605764165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1894389964165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
<tr id="row1169228112165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result. 

## lgamma\(\)<a name="gacd3ebe923fa039624f0b7de3320816bf"></a>

```
double lgamma (double x)
```

 **Description:**

Calculates the natural logarithm of the absolute value of the gamma function of the double value  **x**. 

**Parameters:**

<a name="table1212694549165622"></a>
<table><thead align="left"><tr id="row449202943165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p771681538165622"><a name="p771681538165622"></a><a name="p771681538165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1786397557165622"><a name="p1786397557165622"></a><a name="p1786397557165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1361954562165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **1**  or  **2**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If  **x**  is  **0**  or a negative value, this function returns one of +[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)\). If an overflow range error occurs, this function returns one of  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  \* and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## lgammaf\(\)<a name="ga5900f7bf0093757f1ba36b5940b1e10b"></a>

```
float lgammaf (float x)
```

 **Description:**

Calculates the natural logarithm of the absolute value of the gamma function of the float value  **x**. 

**Parameters:**

<a name="table1034372332165622"></a>
<table><thead align="left"><tr id="row1590693158165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p986151989165622"><a name="p986151989165622"></a><a name="p986151989165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1685079645165622"><a name="p1685079645165622"></a><a name="p1685079645165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row125031341165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **1**  or  **2**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If  **x**  is  **0**  or a negative value, this function returns one of +[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359), reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). If an overflow range error occurs, this function returns one of  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## lgammal\(\)<a name="ga4dafd3eb6952c8daabe8a98f4a64a7df"></a>

```
long double lgammal (long double x)
```

 **Description:**

Calculates the natural logarithm of the absolute value of the gamma function of the long double value  **x**. 

**Parameters:**

<a name="table1550817640165622"></a>
<table><thead align="left"><tr id="row1135131097165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p966018816165622"><a name="p966018816165622"></a><a name="p966018816165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p548272646165622"><a name="p548272646165622"></a><a name="p548272646165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1027264550165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **1**  or  **2**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If  **x**  is  **0**  or a negative value, this function returns one of +[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182), reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). If an overflow range error occurs, this function returns one of  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## lgammal\_r\(\)<a name="ga278e86e217081a0268107f0d6876cb9b"></a>

```
long double lgammal_r (long double x, int * signp )
```

 **Description:**

Calculates the natural logarithm of the absolute value of the gamma function of the double value  **x**. 

**Parameters:**

<a name="table1093486798165622"></a>
<table><thead align="left"><tr id="row1862862088165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p829903633165622"><a name="p829903633165622"></a><a name="p829903633165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p385104412165622"><a name="p385104412165622"></a><a name="p385104412165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row156664349165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
<tr id="row1123283229165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">return value of sign. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **1**  or  **2**, this function returns  **+0**. If  **x**  is a positive or negative infinity, this function returns a positive infinity. If  **x**  is  **0**  or a negative value, this function returns one of +[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca)\). If an overflow range error occurs, this function returns one of  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  \* and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## llrint\(\)<a name="ga64a4201c82f6ee7043a270bbbc6a5e19"></a>

```
long long int llrint (double x)
```

 **Description:**

Rounds double value  **x**  to the nearest integer. 

**Parameters:**

<a name="table1127651158165622"></a>
<table><thead align="left"><tr id="row761603993165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p394159793165622"><a name="p394159793165622"></a><a name="p394159793165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p130842172165622"><a name="p130842172165622"></a><a name="p130842172165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row182785522165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value to round. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of  **x**, rounding mode, and rounding direction are specified by  **fegetround**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## llrintf\(\)<a name="ga33d95711621def731d3f88c4e606323e"></a>

```
long long int llrintf (float x)
```

 **Description:**

Rounds float value  **x**  to the nearest integer. 

**Parameters:**

<a name="table1758427715165622"></a>
<table><thead align="left"><tr id="row376213450165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p641452105165622"><a name="p641452105165622"></a><a name="p641452105165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p333688737165622"><a name="p333688737165622"></a><a name="p333688737165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row535797389165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of  **x**, rounding mode, and rounding direction are specified by  **fegetround**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## llrintl\(\)<a name="ga20e0da115f76608eff4695177f2f605a"></a>

```
long long int llrintl (long double x)
```

 **Description:**

Rounds long double value  **x**  to the nearest integer. 

**Parameters:**

<a name="table953934366165622"></a>
<table><thead align="left"><tr id="row130099623165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1804972997165622"><a name="p1804972997165622"></a><a name="p1804972997165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1174558324165622"><a name="p1174558324165622"></a><a name="p1174558324165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row448074416165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of  **x**, rounding mode, and rounding direction are specified by  **fegetround**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## llround\(\)<a name="ga3e4957daeecea4e616ed1f1870fe4f31"></a>

```
long long int llround (double x)
```

 **Description:**

Rounds double value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table1849593845165622"></a>
<table><thead align="left"><tr id="row1039765272165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1130073391165622"><a name="p1130073391165622"></a><a name="p1130073391165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2000358224165622"><a name="p2000358224165622"></a><a name="p2000358224165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row526591311165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## llroundf\(\)<a name="ga8259999687e8bd4b5509ca0d69b0ad9d"></a>

```
long long int llroundf (float x)
```

 **Description:**

Rounds float value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table1121887482165622"></a>
<table><thead align="left"><tr id="row132341602165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p138803452165622"><a name="p138803452165622"></a><a name="p138803452165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p717955929165622"><a name="p717955929165622"></a><a name="p717955929165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row975942756165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## llroundl\(\)<a name="ga82a6d70a29e839514b93bb0699f07bbe"></a>

```
long long int llroundl (long double x)
```

 **Description:**

Rounds long double value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table684142962165622"></a>
<table><thead align="left"><tr id="row344645777165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p509332784165622"><a name="p509332784165622"></a><a name="p509332784165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p652297181165622"><a name="p652297181165622"></a><a name="p652297181165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1256810423165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## log\(\)<a name="gadb302c9aafbaa5e180d9f60ee954bb82"></a>

```
double log (double x)
```

 **Description:**

Calculates the natural logarithm of the double value  **x**. 

**Parameters:**

<a name="table29448646165622"></a>
<table><thead align="left"><tr id="row332128656165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p11237957165622"><a name="p11237957165622"></a><a name="p11237957165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1532127816165622"><a name="p1532127816165622"></a><a name="p1532127816165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row286820364165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log10\(\)<a name="ga6572e82a4891917a9ba7fb2a964f8182"></a>

```
double log10 (double x)
```

 **Description:**

Calculates the common logarithm \(logarithm with base 10\) of the double value  **x**. 

**Parameters:**

<a name="table308341289165622"></a>
<table><thead align="left"><tr id="row1190113110165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p535983283165622"><a name="p535983283165622"></a><a name="p535983283165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1292054371165622"><a name="p1292054371165622"></a><a name="p1292054371165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row238911690165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log10f\(\)<a name="gae207b1eb007a6c23394dcb6fc7f16adf"></a>

```
float log10f (float x)
```

 **Description:**

Calculates the common logarithm \(logarithm with base 10\) of the float value  **x**. 

**Parameters:**

<a name="table554470876165622"></a>
<table><thead align="left"><tr id="row1066337323165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1856483351165622"><a name="p1856483351165622"></a><a name="p1856483351165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p754930340165622"><a name="p754930340165622"></a><a name="p754930340165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2002775592165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log10l\(\)<a name="gae824e49a04221dcf66b9791c5df8d6b6"></a>

```
long double log10l (long double x)
```

 **Description:**

Calculates the common logarithm \(logarithm with base 10\) of the long double value  **x**. 

**Parameters:**

<a name="table1914842538165622"></a>
<table><thead align="left"><tr id="row2030116284165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1600696103165622"><a name="p1600696103165622"></a><a name="p1600696103165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p286723933165622"><a name="p286723933165622"></a><a name="p286723933165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row306263922165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log1p\(\)<a name="gac2aac20ab1347498e6e4f209148fea84"></a>

```
double log1p (double x)
```

 **Description:**

Calculates the natural logarithm of one plus the double value  **x**. 

**Parameters:**

<a name="table2066050734165622"></a>
<table><thead align="left"><tr id="row1115328571165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1787511448165622"><a name="p1787511448165622"></a><a name="p1787511448165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p449602208165622"><a name="p449602208165622"></a><a name="p449602208165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1365293802165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of one plus  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **-1**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is less than  **-1**  \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log1pf\(\)<a name="gacbf820b74779ce35a3c726a3a62bc8ef"></a>

```
float log1pf (float x)
```

 **Description:**

Calculates the natural logarithm of one plus the float value  **x**. 

**Parameters:**

<a name="table677482340165622"></a>
<table><thead align="left"><tr id="row456471598165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p622725865165622"><a name="p622725865165622"></a><a name="p622725865165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1309045188165622"><a name="p1309045188165622"></a><a name="p1309045188165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row536271865165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of one plus  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **-1**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is less than  **-1**  \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log1pl\(\)<a name="ga2a632effaace01f30cba42725ae48dfa"></a>

```
long double log1pl (long double x)
```

 **Description:**

Calculates the natural logarithm of one plus the long double value  **x**. 

**Parameters:**

<a name="table1183109324165622"></a>
<table><thead align="left"><tr id="row1090813642165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p422168040165622"><a name="p422168040165622"></a><a name="p422168040165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2027900962165622"><a name="p2027900962165622"></a><a name="p2027900962165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1265357593165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of one plus  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **-1**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is less than  **-1**  \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log2\(\)<a name="ga38bd88274dc5594b4826fd60c8054c8e"></a>

```
double log2 (double x)
```

 **Description:**

Calculates the binary logarithm \(logarithm with base 2\) of the double value  **x**. 

**Parameters:**

<a name="table1625694143165622"></a>
<table><thead align="left"><tr id="row890396610165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1776437329165622"><a name="p1776437329165622"></a><a name="p1776437329165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1847571140165622"><a name="p1847571140165622"></a><a name="p1847571140165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1866192528165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log2f\(\)<a name="ga79fe62234001b88317245f7599158aaf"></a>

```
float log2f (float x)
```

 **Description:**

Calculates the binary logarithm \(logarithm with base 2\) of the float value  **x**. 

**Parameters:**

<a name="table1607903923165622"></a>
<table><thead align="left"><tr id="row1047168556165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p654199464165622"><a name="p654199464165622"></a><a name="p654199464165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p574981435165622"><a name="p574981435165622"></a><a name="p574981435165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row294550962165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## log2l\(\)<a name="gaa383ae0cab6c24f1bcba661dee0fbd70"></a>

```
long double log2l (long double x)
```

 **Description:**

Calculates the binary logarithm \(logarithm with base 2\) of the long double value  **x**. 

**Parameters:**

<a name="table1073066477165622"></a>
<table><thead align="left"><tr id="row1319139410165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1224585752165622"><a name="p1224585752165622"></a><a name="p1224585752165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1970877567165622"><a name="p1970877567165622"></a><a name="p1970877567165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1635352945165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary \(base-2\) logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## logb\(\)<a name="gaa34bf5be5c3dab058c532adc2792113c"></a>

```
double logb (double x)
```

 **Description:**

Calculates the logarithm of the absolute value of the double value  **x**. 

**FLT\_RADIX**  is used as the base for the logarithm. 

**Parameters:**

<a name="table1130658636165622"></a>
<table><thead align="left"><tr id="row749113200165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1984860080165622"><a name="p1984860080165622"></a><a name="p1984860080165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1831919097165622"><a name="p1831919097165622"></a><a name="p1831919097165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1499579113165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Attention:**

Set  **FLT\_RADIX**  to  **2**  in the  **float.h**  file. 

**Returns:**

Returns the logarithm of the absolute value of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, reports a pole error, and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## logbf\(\)<a name="ga6939b8381c2f160d26913646ca7ab6c4"></a>

```
float logbf (float x)
```

 **Description:**

Calculates the logarithm of the absolute value of the float value  **x**. 

**FLT\_RADIX**  is used as the base for the logarithm. 

**Parameters:**

<a name="table1833060558165622"></a>
<table><thead align="left"><tr id="row1046482931165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1967666042165622"><a name="p1967666042165622"></a><a name="p1967666042165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p649440667165622"><a name="p649440667165622"></a><a name="p649440667165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row541777481165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Attention:**

Set  **FLT\_RADIX**  to  **2**  in the  **float.h**  file. 

**Returns:**

Returns the logarithm of the absolute value of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, reports a pole error, and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## logbl\(\)<a name="ga2f9c0448126d1a838624e3460217bb84"></a>

```
long double logbl (long double x)
```

 **Description:**

Calculates the logarithm of the absolute value of the long double value  **x**. 

**FLT\_RADIX**  is used as the base for the logarithm. 

**Parameters:**

<a name="table843072760165622"></a>
<table><thead align="left"><tr id="row371284832165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1590204184165622"><a name="p1590204184165622"></a><a name="p1590204184165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p918211273165622"><a name="p918211273165622"></a><a name="p918211273165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row95833079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Attention:**

Set  **FLT\_RADIX**  to  **2**  in the  **float.h**  file. 

**Returns:**

Returns the logarithm of the absolute value of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, reports a pole error, and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## logf\(\)<a name="ga8246b3e17a39b137d0c62670d0c6e336"></a>

```
float logf (float x)
```

 **Description:**

Calculates the natural logarithm of the float value  **x**. 

**Parameters:**

<a name="table1065426688165622"></a>
<table><thead align="left"><tr id="row106782767165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1644534563165622"><a name="p1644534563165622"></a><a name="p1644534563165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p790993546165622"><a name="p790993546165622"></a><a name="p790993546165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row107750670165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## logl\(\)<a name="gaf67da1c28ce33b403f955103f201dfb8"></a>

```
long double logl (long double x)
```

 **Description:**

Calculates the natural logarithm of the long double value  **x**. 

**Parameters:**

<a name="table898198560165622"></a>
<table><thead align="left"><tr id="row2075075569165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1014261949165622"><a name="p1014261949165622"></a><a name="p1014261949165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p331160805165622"><a name="p331160805165622"></a><a name="p331160805165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row512082009165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the natural logarithm of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is  **0**, this function returns  **-[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is a negative value \(including a negative infinity\), this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. 

## lrint\(\)<a name="ga3337db086394bad101bd8d42d891640a"></a>

```
long int lrint (double x)
```

 **Description:**

Rounds the double value  **x**  to the nearest integer. 

**Parameters:**

<a name="table85350340165622"></a>
<table><thead align="left"><tr id="row926002937165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1842573830165622"><a name="p1842573830165622"></a><a name="p1842573830165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p366763750165622"><a name="p366763750165622"></a><a name="p366763750165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row943283420165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value to round. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of  **x**, rounding mode, and rounding direction are specified by  **fegetround**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## lrintf\(\)<a name="ga16173bca19eef93d0230bfb7c86b5740"></a>

```
long int lrintf (float x)
```

 **Description:**

Rounds the float value  **x**  to the nearest integer. 

**Parameters:**

<a name="table668196810165622"></a>
<table><thead align="left"><tr id="row736418209165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1362121239165622"><a name="p1362121239165622"></a><a name="p1362121239165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1328899991165622"><a name="p1328899991165622"></a><a name="p1328899991165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row907453129165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value to round. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of  **x**, rounding mode, and rounding direction are specified by  **fegetround**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## lrintl\(\)<a name="gac6d217e9b96a145f5eeb2a490e6496e6"></a>

```
long int lrintl (long double x)
```

 **Description:**

Rounds the long double value  **x**  to the nearest integer. 

**Parameters:**

<a name="table164943730165622"></a>
<table><thead align="left"><tr id="row1189707734165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1962970255165622"><a name="p1962970255165622"></a><a name="p1962970255165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p326196306165622"><a name="p326196306165622"></a><a name="p326196306165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row963484550165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of  **x**, rounding mode, and rounding direction are specified by  **fegetround**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## lround\(\)<a name="ga5936ef27aa03815e9c17d557e87a33d7"></a>

```
long int lround (double x)
```

 **Description:**

Rounds double value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table671369978165622"></a>
<table><thead align="left"><tr id="row1391167622165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1487546060165622"><a name="p1487546060165622"></a><a name="p1487546060165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p837573232165622"><a name="p837573232165622"></a><a name="p837573232165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1042325035165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value to round. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## lroundf\(\)<a name="ga0136619b503ddb8ce1a226cd34c9538c"></a>

```
long int lroundf (float x)
```

 **Description:**

Rounds the float value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table711043601165622"></a>
<table><thead align="left"><tr id="row502398018165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p426165242165622"><a name="p426165242165622"></a><a name="p426165242165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p698969251165622"><a name="p698969251165622"></a><a name="p698969251165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row454001623165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value to round. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## lroundl\(\)<a name="gafa865c5b70c9311f0f8701a1af60c715"></a>

```
long int lroundl (long double x)
```

 **Description:**

Rounds the long double value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table1349046441165622"></a>
<table><thead align="left"><tr id="row1951336335165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1318098621165622"><a name="p1318098621165622"></a><a name="p1318098621165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p909593047165622"><a name="p909593047165622"></a><a name="p909593047165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row146810253165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value to round. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns an unspecified value if  **x**  is a NaN value or an infinity, or the rounded value is outside the specified range, in which case a domain error or overflow range error occurs. 

## modf\(\)<a name="gafcfe25b77e975450988866fea9d3c9f0"></a>

```
double modf (double x, double * iptr )
```

 **Description:**

Breaks the double value  **x**  into a signed integral and a fractional part. 

**Parameters:**

<a name="table1716707477165622"></a>
<table><thead align="left"><tr id="row653520806165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p228778413165622"><a name="p228778413165622"></a><a name="p228778413165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p928938527165622"><a name="p928938527165622"></a><a name="p928938527165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row786297696165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b20326158165622"><a name="b20326158165622"></a><a name="b20326158165622"></a>x</strong>. </td>
</tr>
<tr id="row207337532165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the object where the signed integral part is stored. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the fractional part of  **x**. 

## modff\(\)<a name="gad8314f66dfe8603f3a166eb466261ce1"></a>

```
float modff (float x, float * iptr )
```

 **Description:**

Breaks the float value  **x**  into a signed integral and a fractional part. 

**Parameters:**

<a name="table1339176478165622"></a>
<table><thead align="left"><tr id="row1589685422165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1708813962165622"><a name="p1708813962165622"></a><a name="p1708813962165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p656792016165622"><a name="p656792016165622"></a><a name="p656792016165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row966708567165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b2119190866165622"><a name="b2119190866165622"></a><a name="b2119190866165622"></a>x</strong>. </td>
</tr>
<tr id="row355260775165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the object where the signed integral part is stored. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the fractional part of  **x**. 

## modfl\(\)<a name="gabacf3b74f8d7e30a70da8ae47c8e4e3e"></a>

```
long double modfl (long double x, long double * iptr )
```

 **Description:**

Breaks the long double value  **x**  into a signed integral and a fractional part. 

**Parameters:**

<a name="table734297077165622"></a>
<table><thead align="left"><tr id="row1765963183165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2102212386165622"><a name="p2102212386165622"></a><a name="p2102212386165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p936948583165622"><a name="p936948583165622"></a><a name="p936948583165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1983648193165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b593450110165622"><a name="b593450110165622"></a><a name="b593450110165622"></a>x</strong>. </td>
</tr>
<tr id="row2146263956165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the object where the signed integral part is stored. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the fractional part of  **x**. 

## nan\(\)<a name="gaa4ee2f416f261bbd71cda3193c4884c9"></a>

```
double nan (const char * tagp)
```

 **Description:**

Obtains a quiet NaN value of the double type. 

This function checks whether the input parameter is a NaN value and converts it to the double type. 

**Parameters:**

<a name="table354912238165622"></a>
<table><thead align="left"><tr id="row1608630390165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1771627718165622"><a name="p1771627718165622"></a><a name="p1771627718165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1066960632165622"><a name="p1066960632165622"></a><a name="p1066960632165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1556014513165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tagp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a character constant. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a quiet NaN value if the operation is successful; returns a NaN value otherwise. 

## nanf\(\)<a name="ga7fe43d4c86419daea2c133e8c5c1a17d"></a>

```
float nanf (const char * tagp)
```

 **Description:**

Obtains a quiet NaN value of the float type. 

This function checks whether the input parameter is a NaN value and converts it to the float type. 

**Parameters:**

<a name="table599499602165622"></a>
<table><thead align="left"><tr id="row211521093165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p202449789165622"><a name="p202449789165622"></a><a name="p202449789165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1518479884165622"><a name="p1518479884165622"></a><a name="p1518479884165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1163648673165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tagp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a character constant. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a quiet NaN value if the operation is successful; returns a NaN value otherwise. 

## nanl\(\)<a name="gac92b1a3a1073a630ae0b7084e596d40f"></a>

```
long double nanl (const char * tagp)
```

 **Description:**

Obtains a quiet NaN value of the long double type. 

This function checks whether the input parameter is a NaN value and converts it to the long double type. 

**Parameters:**

<a name="table1143089333165622"></a>
<table><thead align="left"><tr id="row1497951698165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p510676325165622"><a name="p510676325165622"></a><a name="p510676325165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p917049147165622"><a name="p917049147165622"></a><a name="p917049147165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1988890423165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tagp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a character constant. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a quiet NaN value if the operation is successful; returns a NaN value otherwise. 

## nearbyint\(\)<a name="ga61ba6b3078ccbd5aac518e6ca2a757bd"></a>

```
double nearbyint (double x)
```

 **Description:**

Rounds the double value  **x**  to an integer in floating-point format. 

**Parameters:**

<a name="table1036872503165622"></a>
<table><thead align="left"><tr id="row1177159302165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p203088793165622"><a name="p203088793165622"></a><a name="p203088793165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1426145054165622"><a name="p1426145054165622"></a><a name="p1426145054165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1494119304165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1947499393165622"><a name="b1947499393165622"></a><a name="b1947499393165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The rounding mode is specified by  **fegetround**. 

**Returns:**

Returns the rounded value. 

## nearbyintf\(\)<a name="gab3be3fdcb83a6d7cbd10aa5d891f88bf"></a>

```
float nearbyintf (float x)
```

 **Description:**

Rounds the float value  **x**  to an integer in floating-point format. 

**Parameters:**

<a name="table1535384638165622"></a>
<table><thead align="left"><tr id="row1559039679165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p240238472165622"><a name="p240238472165622"></a><a name="p240238472165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p194405765165622"><a name="p194405765165622"></a><a name="p194405765165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1596201452165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b842960550165622"><a name="b842960550165622"></a><a name="b842960550165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The rounding mode is specified by  **fegetround**. 

**Returns:**

Returns the rounded value. 

## nearbyintl\(\)<a name="ga4b51faf338f7d4f31224d0c096a8859b"></a>

```
long double nearbyintl (long double x)
```

 **Description:**

Rounds the long double value  **x**  to an integer in floating-point format. 

**Parameters:**

<a name="table738101283165622"></a>
<table><thead align="left"><tr id="row1775634725165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1244685493165622"><a name="p1244685493165622"></a><a name="p1244685493165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1287686574165622"><a name="p1287686574165622"></a><a name="p1287686574165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1772052045165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Attention:**

The rounding mode is specified by  **fegetround**. 

**Returns:**

Returns the rounded value. 

## nextafter\(\)<a name="gabed1b7ee913471448c2dbe58dff28db3"></a>

```
double nextafter (double x, double y )
```

 **Description:**

Obtains the next representable value following the double value  **x**  in the direction of the double value  **y**. 

**Parameters:**

<a name="table889224505165622"></a>
<table><thead align="left"><tr id="row1330900293165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p761386711165622"><a name="p761386711165622"></a><a name="p761386711165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1851185708165622"><a name="p1851185708165622"></a><a name="p1851185708165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1387041807165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1445976372165622"><a name="b1445976372165622"></a><a name="b1445976372165622"></a>x</strong>. </td>
</tr>
<tr id="row216036843165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b332647358165622"><a name="b332647358165622"></a><a name="b332647358165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **y**  is less than  **x**, this function returns the maximum representable value less than  **x**. 

**Returns:**

Returns the next representable value after  **x**  in the direction of  **y**  if the operation is successful; returns the passed  **y**  if  **x**  is equal to  **y**; returns a NaN value if  **x**  is a NaN value; returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  and reports an overflow range error if  **x**  is a finite value. 

## nextafterf\(\)<a name="ga57d2446286a54227595950a2118b349b"></a>

```
float nextafterf (float x, float y )
```

 **Description:**

Obtains the next representable value following the float value  **x**  in the direction of the float value  **y**. 

**Parameters:**

<a name="table620774175165622"></a>
<table><thead align="left"><tr id="row1143030590165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1013882368165622"><a name="p1013882368165622"></a><a name="p1013882368165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p940943745165622"><a name="p940943745165622"></a><a name="p940943745165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row170477806165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1339282733165622"><a name="b1339282733165622"></a><a name="b1339282733165622"></a>x</strong>. </td>
</tr>
<tr id="row1441696849165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b436363543165622"><a name="b436363543165622"></a><a name="b436363543165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **y**  is less than  **x**, this function returns the maximum representable value less than  **x**. 

**Returns:**

Returns the next representable value following  **x**  in the direction of  **y**  if the operation is successful; returns the passed  **y**  if  **x**  is equal to  **y**; returns a NaN value if  **x**  is a NaN value; returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  and reports an overflow range error if  **x**  is a finite value. 

## nextafterl\(\)<a name="ga38691f2f734e77206e4336cdcddd0e5b"></a>

```
long double nextafterl (long double x, long double y )
```

 **Description:**

Obtains the next representable value following the long double value  **x**  in the direction of the long double value  **y**. 

**Parameters:**

<a name="table1972654925165622"></a>
<table><thead align="left"><tr id="row563345881165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p186859791165622"><a name="p186859791165622"></a><a name="p186859791165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1057388980165622"><a name="p1057388980165622"></a><a name="p1057388980165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row189682045165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b855052149165622"><a name="b855052149165622"></a><a name="b855052149165622"></a>x</strong>. </td>
</tr>
<tr id="row1026775964165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b943664321165622"><a name="b943664321165622"></a><a name="b943664321165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **y**  is less than  **x**, this function returns the maximum representable value less than  **x**. 

**Returns:**

Returns the next representable value after  **x**  in the direction of  **y**  if the operation is successful; returns the passed  **y**  if  **x**  is equal to  **y**; returns a NaN value if  **x**  is a NaN value; returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  and reports an overflow range error if  **x**  is a finite value. 

## nexttoward\(\)<a name="gaeb7afe6d08d8daec35aa282c63d7647e"></a>

```
double nexttoward (double x, long double y )
```

 **Description:**

Obtains the next representable value following the double value  **x**  in the direction of the long double value  **y**. 

**Parameters:**

<a name="table1715422071165622"></a>
<table><thead align="left"><tr id="row314508492165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p82427888165622"><a name="p82427888165622"></a><a name="p82427888165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2115139399165622"><a name="p2115139399165622"></a><a name="p2115139399165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1108767061165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1448942588165622"><a name="b1448942588165622"></a><a name="b1448942588165622"></a>x</strong>. </td>
</tr>
<tr id="row1972357176165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1260490491165622"><a name="b1260490491165622"></a><a name="b1260490491165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **y**  is less than  **x**, this function returns the maximum representable value less than  **x**. 

**Returns:**

Returns the next representable value following  **x**  in the direction of  **y**  if the operation is successful; returns the passed  **y**  if  **x**  is equal to  **y**; returns a NaN value if  **x**  is a NaN value; returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  and reports an overflow range error if  **x**  is a finite value. 

## nexttowardf\(\)<a name="ga634a1dabb08aa5a4fa6897920eff3c1d"></a>

```
float nexttowardf (float x, long double y )
```

 **Description:**

Obtains the next representable value following the float value  **x**  in the direction of the long double value  **y**. 

**Parameters:**

<a name="table1412625610165622"></a>
<table><thead align="left"><tr id="row1024842136165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p319856032165622"><a name="p319856032165622"></a><a name="p319856032165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p972733569165622"><a name="p972733569165622"></a><a name="p972733569165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1808382521165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b2071828983165622"><a name="b2071828983165622"></a><a name="b2071828983165622"></a>x</strong>. </td>
</tr>
<tr id="row2111591927165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1259773118165622"><a name="b1259773118165622"></a><a name="b1259773118165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **y**  is less than  **x**, this function returns the maximum representable value less than  **x**. 

**Returns:**

Returns the next representable value after  **x**  in the direction of  **y**  if the operation is successful; returns the passed  **y**  if  **x**  is equal to  **y**; returns a NaN value if  **x**  is a NaN value; returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  and reports an overflow range error if  **x**  is a finite value. 

## nexttowardl\(\)<a name="ga3930cfe4df009d7221db329b910d6e30"></a>

```
long double nexttowardl (long double x, long double y )
```

 **Description:**

Obtains the next representable value following the long double value  **x**  in the direction of the long double value  **y**. 

**Parameters:**

<a name="table1107374237165622"></a>
<table><thead align="left"><tr id="row1317325850165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1314314542165622"><a name="p1314314542165622"></a><a name="p1314314542165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1175568654165622"><a name="p1175568654165622"></a><a name="p1175568654165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row828010552165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b2020373970165622"><a name="b2020373970165622"></a><a name="b2020373970165622"></a>x</strong>. </td>
</tr>
<tr id="row1380164265165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1572164691165622"><a name="b1572164691165622"></a><a name="b1572164691165622"></a>y</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **y**  is less than  **x**, this function returns the maximum representable value less than  **x**. 

**Returns:**

Returns the next representable value following  **x**  in the direction of  **y**  if the operation is successful; returns the passed  **y**  if  **x**  is equal to  **y**; returns a NaN value if  **x**  is a NaN value; returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  and reports an overflow range error if  **x**  is a finite value. 

## pow\(\)<a name="gaa56c9494c95edf68386375e97d64159b"></a>

```
double pow (double x, double y )
```

 **Description:**

Obtains the double value  **x**  raised to the power of the double value  **y**. 

**Parameters:**

<a name="table1633120354165622"></a>
<table><thead align="left"><tr id="row1733186089165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2122424792165622"><a name="p2122424792165622"></a><a name="p2122424792165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2058880001165622"><a name="p2058880001165622"></a><a name="p2058880001165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1241615755165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b163866524165622"><a name="b163866524165622"></a><a name="b163866524165622"></a>x</strong>, which is used as the base. </td>
</tr>
<tr id="row2145323402165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1581965499165622"><a name="b1581965499165622"></a><a name="b1581965499165622"></a>y</strong>, which is used as the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **y**  is a NaN value, this returns a NaN value, except as specified below. If  **x**  is  **+1**  \(even if  **y**  is a NaN value\), this function returns  **1.0**. If  **y**  is  **0**  \(even if  **x**  is a NaN value\), this function returns  **1.0**. If  **x**  is  **+0**  or  **-0**, and  **y**  is an odd integer greater than  **0**, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **y**  is greater than  **0**  and not an odd integer, this function returns  **+0**. If  **x**  is  **-1**  and  **y**  is a positive or negative infinity, this function returns  **1.0**. If the absolute value of  **x**  is less than  **1**  and  **y**  is a negative infinity, this function returns a positive infinity. If the absolute value of  **x**  is greater than  **1**  and  **y**  is a negative infinity, this function returns  **+0**. If the absolute value of  **x**  is less than  **1**  and  **y**  is a positive infinity, this function returns  **+0**. If the absolute value of  **x**  is greater than  **1**  and  **y**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity and  **y**  is an odd integer less than  **0**, this function returns  **-0**. If  **x**  is a negative infinity and  **y**  is less than  **0**  and not an odd integer, this function returns  **+0**. If  **x**  is a negative infinity and  **y**  is an odd integer greater than  **0**, this function returns a negative infinity. If  **x**  is a negative infinity and  **y**  is greater than  **0**  and not an odd integer, this function returns a positive infinity. If  **x**  is a positive infinity and  **y**  is less than  **0**, this function returns  **+0**. If  **x**  is a positive infinity and  **y**  is greater than  **0**, this function returns a positive infinity. If  **x**  is a negative value and  **y**  is a finite non-integer, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **+0**  or  **-0**  and  **y**  is a negative odd integer, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is  **+0**  or  **-0**  and  **y**  is a negative non-odd integer, this function returns  **+[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If an overflow range error occurs, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971), sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0.0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## pow10\(\)<a name="gafbbc60a3627a8de4845c7e99e6134ec8"></a>

```
double pow10 (double x)
```

 **Description:**

Calculates the value of 10 raised to the power  **x**, which is a double value. 

**Parameters:**

<a name="table527958536165622"></a>
<table><thead align="left"><tr id="row402741386165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1568480537165622"><a name="p1568480537165622"></a><a name="p1568480537165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1954033298165622"><a name="p1954033298165622"></a><a name="p1954033298165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1837559596165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b571649395165622"><a name="b571649395165622"></a><a name="b571649395165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the value of 10 raised to the power  **x**  if the operation is successful. 

## pow10f\(\)<a name="ga2cb598503b85d66abf59e9da06478f1a"></a>

```
float pow10f (float x)
```

 **Description:**

Calculates the xth power of 10. 

Calculates the value of 10 raised to the power  **x**, which is a float value.

**ParametersParameters:**

<a name="table697584269165622"></a>
<table><thead align="left"><tr id="row352413927165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1437668436165622"><a name="p1437668436165622"></a><a name="p1437668436165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p235825586165622"><a name="p235825586165622"></a><a name="p235825586165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row230495677165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value x, which is used as the exponent. </td>
</tr>
<tr id="row588781912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1135860788165622"><a name="b1135860788165622"></a><a name="b1135860788165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If y is 0 \(even if x is a NaN value\), this function returns 1.0. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359), sets errno to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns 0.0, sets errno to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

**Returns:**

Returns the value of 10 raised to the power  **x**  if the operation is successful. 

## pow10l\(\)<a name="ga9baf71e9033dd73a9c225a2fc9cca61d"></a>

```
long double pow10l (long double x)
```

 **Description:**

Calculates the xth power of 10. 

Calculates the value of 10 raised to the power  **x**, which is a long double value.

**ParametersParameters:**

<a name="table1655432756165622"></a>
<table><thead align="left"><tr id="row1011355942165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1931560852165622"><a name="p1931560852165622"></a><a name="p1931560852165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p628650113165622"><a name="p628650113165622"></a><a name="p628650113165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1327018491165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value x, which is used as the exponent. </td>
</tr>
<tr id="row1050116152165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b101974298165622"><a name="b101974298165622"></a><a name="b101974298165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If x is 0, this function returns 1.0. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182), sets errno to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns 0.0, sets errno to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

**Returns:**

Returns the value of 10 raised to the power  **x**  if the operation is successful. 

## powf\(\)<a name="gac6b287549be087f6f0bf03b6fe30499e"></a>

```
float powf (float x, float y )
```

 **Description:**

Obtains the float value  **x**  raised to the power of the float value  **y**. 

**Parameters:**

<a name="table586463324165622"></a>
<table><thead align="left"><tr id="row818617384165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1533202599165622"><a name="p1533202599165622"></a><a name="p1533202599165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1435661801165622"><a name="p1435661801165622"></a><a name="p1435661801165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1667273316165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1674917312165622"><a name="b1674917312165622"></a><a name="b1674917312165622"></a>x</strong>, which is used as the base. </td>
</tr>
<tr id="row463977890165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b756052704165622"><a name="b756052704165622"></a><a name="b756052704165622"></a>y</strong>, which is used as the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **y**  is a NaN value, this returns a NaN value, except as specified below. If  **x**  is  **+1**  \(even if  **y**  is a NaN value\), this function returns  **1.0**. If  **y**  is  **0**  \(even if  **x**  is a NaN value\), this function returns  **1.0**. If  **x**  is  **+0**  or  **-0**, and  **y**  is an odd integer greater than  **0**, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **y**  is greater than  **0**  and not an odd integer, this function returns  **+0**. If  **x**  is  **-1**  and  **y**  is a positive or negative infinity, this function returns  **1.0**. If the absolute value of  **x**  is less than  **1**  and  **y**  is a negative infinity, this function returns a positive infinity. If the absolute value of  **x**  is greater than  **1**  and  **y**  is a negative infinity, this function returns  **+0**. If the absolute value of  **x**  is less than  **1**  and  **y**  is a positive infinity, this function returns  **+0**. If the absolute value of  **x**  is greater than  **1**  and  **y**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity and  **y**  is an odd integer less than  **0**, this function returns  **-0**. If  **x**  is a negative infinity and  **y**  is less than  **0**  and not an odd integer, this function returns  **+0**. If  **x**  is a negative infinity and  **y**  is an odd integer greater than  **0**, this function returns a negative infinity. If  **x**  is a negative infinity and  **y**  is greater than  **0**  and not an odd integer, this function returns a positive infinity. If  **x**  is a positive infinity and  **y**  is less than  **0**, this function returns  **+0**. If  **x**  is a positive infinity and  **y**  is greater than  **0**, this function returns a positive infinity. If  **x**  is a negative value and  **y**  is a finite non-integer, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **+0**  or  **-0**  and  **y**  is a negative odd integer, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359), reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is  **+0**  or  **-0**  and  **y**  is a negative non-odd integer, this function returns  **+[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359), sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0.0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## powl\(\)<a name="ga2f4830e468138e1513b55ca6a92a0f9a"></a>

```
long double powl (long double x, long double y )
```

 **Description:**

Obtains the long double value  **x**  raised to the power of the long double value  **y**. 

 

**Parameters:**

<a name="table696368087165622"></a>
<table><thead align="left"><tr id="row426014735165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p15466389165622"><a name="p15466389165622"></a><a name="p15466389165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1788194234165622"><a name="p1788194234165622"></a><a name="p1788194234165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2047469478165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1199454357165622"><a name="b1199454357165622"></a><a name="b1199454357165622"></a>x</strong>, which is used as the base. </td>
</tr>
<tr id="row449183043165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b533472601165622"><a name="b533472601165622"></a><a name="b533472601165622"></a>y</strong>, which is used as the exponent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **y**  is a NaN value, this returns a NaN value, except as specified below. If  **x**  is  **+1**  \(even if  **y**  is a NaN value\), this function returns  **1.0**. If  **y**  is  **0**  \(even if  **x**  is a NaN value\), this function returns  **1.0**. If  **x**  is  **+0**  or  **-0**, and  **y**  is an odd integer greater than  **0**, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **y**  is greater than  **0**  and not an odd integer, this function returns  **+0**. If  **x**  is  **-1**  and  **y**  is a positive or negative infinity, this function returns  **1.0**. If the absolute value of  **x**  is less than  **1**  and  **y**  is a negative infinity, this function returns a positive infinity. If the absolute value of  **x**  is greater than  **1**  and  **y**  is a negative infinity, this function returns  **+0**. If the absolute value of  **x**  is less than  **1**  and  **y**  is a positive infinity, this function returns  **+0**. If the absolute value of  **x**  is greater than  **1**  and  **y**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative infinity and  **y**  is an odd integer less than  **0**, this function returns  **-0**. If  **x**  is a negative infinity and  **y**  is less than  **0**  and not an odd integer, this function returns  **+0**. If  **x**  is a negative infinity and  **y**  is an odd integer greater than  **0**, this function returns a negative infinity. If  **x**  is a negative infinity and  **y**  is greater than  **0**  and not an odd integer, this function returns a positive infinity. If  **x**  is a positive infinity and  **y**  is less than  **0**, this function returns  **+0**. If  **x**  is a positive infinity and  **y**  is greater than  **0**, this function returns a positive infinity. If  **x**  is a negative value and  **y**  is a finite non-integer, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is  **+0**  or  **-0**  and  **y**  is a negative odd integer, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182), reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If  **x**  is  **+0**  or  **-0**  and  **y**  is a negative non-odd integer, this function returns  **+[HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)**, reports a pole error, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_DIVBYZERO](math.md#gab1317930189d1a14841893fb4bd9b5a0)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182), sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0.0**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## remainder\(\)<a name="gaf7df01c4a9038dbf3562b41bc8c3be03"></a>

```
double remainder (double x, double y )
```

 **Description:**

Calculates the remainder of the double value  **x**  divided by the double value  **y**. 

**Parameters:**

<a name="table1722793361165622"></a>
<table><thead align="left"><tr id="row1673518974165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1077466727165622"><a name="p1077466727165622"></a><a name="p1077466727165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1893319122165622"><a name="p1893319122165622"></a><a name="p1893319122165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row548389386165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b936342422165622"><a name="b936342422165622"></a><a name="b936342422165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row854389068165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1466862738165622"><a name="b1466862738165622"></a><a name="b1466862738165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
</tbody>
</table>

**Attention:**

The return value is  **x-n\*y**, where  **n**  is the value of  **x**/**y**, rounded toward the nearest integer \(with halfway values rounded toward the even number\). For example, if the decimal part of  **x**/**y**  is  **0.5**, the value is rounded to an even number and  **0**  is returned. 

**Returns:**

Returns the remainder if the operation is successful. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **x**  is an infinity and  **y**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. If  **y**  is  **0**  and  **x**  is not a NaN value, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  **FE\_INVAID**  exception. 

## remainderf\(\)<a name="ga370ff5cfa842822bfd8ea0a93d441a33"></a>

```
float remainderf (float x, float y )
```

 **Description:**

Calculates the remainder of the float value  **x**  divided by the float value  **y**. 

**Parameters:**

<a name="table1121971498165622"></a>
<table><thead align="left"><tr id="row2015805409165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p916788548165622"><a name="p916788548165622"></a><a name="p916788548165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p579526664165622"><a name="p579526664165622"></a><a name="p579526664165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1382738277165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1655975321165622"><a name="b1655975321165622"></a><a name="b1655975321165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row1814439147165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1314139918165622"><a name="b1314139918165622"></a><a name="b1314139918165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
</tbody>
</table>

**Attention:**

The return value is  **x-n\*y**, where  **n**  is the value of  **x**/**y**, rounded toward the nearest integer \(with halfway values rounded toward the even number\). For example, if the decimal part of  **x**/**y**  is  **0.5**, the value is rounded to an even number and  **0**  is returned. 

**Returns:**

Returns the remainder if the operation is successful. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **x**  is an infinity and  **y**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. If  **y**  is  **0**  and  **x**  is not a NaN value, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  **FE\_INVAID**  exception. 

## remainderl\(\)<a name="gabadbe61e166bbf3031b979661f0e8336"></a>

```
long double remainderl (long double x, long double y )
```

 **Description:**

Calculates the remainder of the long double value  **x**  divided by the long double value  **y**. 

**Parameters:**

<a name="table731650415165622"></a>
<table><thead align="left"><tr id="row2102810288165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1194907578165622"><a name="p1194907578165622"></a><a name="p1194907578165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1114259926165622"><a name="p1114259926165622"></a><a name="p1114259926165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1841646537165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1867326939165622"><a name="b1867326939165622"></a><a name="b1867326939165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row483244617165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b490539900165622"><a name="b490539900165622"></a><a name="b490539900165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
</tbody>
</table>

**Attention:**

The return value is  **x-n\*y**, where  **n**  is the value of  **x**/**y**, rounded toward the nearest integer \(with halfway values rounded toward the even number\). For example, if the decimal part of  **x**/**y**  is  **0.5**, the value is rounded to an even number and  **0**  is returned. 

**Returns:**

Returns the remainder if the operation is successful. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **x**  is an infinity and  **y**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. If  **y**  is  **0**  and  **x**  is not a NaN value, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  **FE\_INVAID**  exception. 

## remquo\(\)<a name="gac836dc6a979229173eb3d6e2744d82de"></a>

```
double remquo (double x, double y, int * quo )
```

 **Description:**

Calculates the quotient and remainder of the double value  **x**  divided by the double value  **y**. 

The return value is  **x-n\*y**, where  **n**  is the value of  **x**/**y**, rounded toward the nearest integer \(with halfway values rounded toward the even number\). For example, if the decimal part of  **x**/**y**  is  **0.5**, the value is rounded to an even number and  **0**  is returned.  **n**  is converted into a signed binary number, and the sign and the least significant three bits of the binary number are combined and stored to the pointer specified by  **quo**. For example, if  **x**  is  **29.0**  and  **y**  is  **3.0**, the return value is  **-1.0**  and  **n**  is  **10**.  **n**  is converted into a signed binary number  **00001010**. Therefore,  **2**  is stored to the pointer specified by  **quo**. 

**Parameters:**

<a name="table551254920165622"></a>
<table><thead align="left"><tr id="row1803939125165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1664202916165622"><a name="p1664202916165622"></a><a name="p1664202916165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1261738685165622"><a name="p1261738685165622"></a><a name="p1261738685165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row605672183165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1502366956165622"><a name="b1502366956165622"></a><a name="b1502366956165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row792410886165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b476515564165622"><a name="b476515564165622"></a><a name="b476515564165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
<tr id="row1398086919165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">quo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer that stores the quotient. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the remainder if the operation is successful. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **x**  is an infinity and  **y**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. If  **y**  is  **0**  and  **x**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. 

## remquof\(\)<a name="ga15ec704e1894cfa573ac37a65afe009a"></a>

```
float remquof (float x, float y, int * quo )
```

 **Description:**

Calculates the quotient and remainder of the float value  **x**  divided by the float value  **y**. 

The return value is  **x-n\*y**, where  **n**  is the value of  **x**/**y**, rounded toward the nearest integer \(with halfway values rounded toward the even number\). For example, if the decimal part of  **x**/**y**  is  **0.5**, the value is rounded to an even number and  **0**  is returned.  **n**  is converted into a signed binary number, and the sign and the least significant three bits of the binary number are combined and stored to the pointer specified by  **quo**. For example, if  **x**  is  **29.0**  and  **y**  is  **3.0**, the return value is  **-1.0**  and  **n**  is  **10**.  **n**  is converted into a signed binary number  **00001010**. Therefore,  **2**  is stored to the pointer specified by  **quo**. 

**Parameters:**

<a name="table150563120165622"></a>
<table><thead align="left"><tr id="row866699975165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p599077500165622"><a name="p599077500165622"></a><a name="p599077500165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1212802867165622"><a name="p1212802867165622"></a><a name="p1212802867165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1870321749165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b2137902889165622"><a name="b2137902889165622"></a><a name="b2137902889165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row2019177676165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b896539206165622"><a name="b896539206165622"></a><a name="b896539206165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
<tr id="row1311213049165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">quo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer that stores the quotient. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the remainder if the operation is successful. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **x**  is an infinity and  **y**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. If  **y**  is  **0**  and  **x**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. 

## remquol\(\)<a name="gaacadcc57a95279058f29e657dce4d285"></a>

```
long double remquol (long double x, long double y, int * quo )
```

 **Description:**

Calculates the quotient and remainder of the long double value  **x**  divided by the long double value  **y**. 

The return value is  **x-n\*y**, where  **n**  is the value of  **x**/**y**, rounded toward the nearest integer \(with halfway values rounded toward the even number\). For example, if the decimal part of  **x**/**y**  is  **0.5**, the value is rounded to an even number and  **0**  is returned.  **n**  is converted into a signed binary number, and the sign and the least significant three bits of the binary number are combined and stored to the pointer specified by  **quo**. For example, if  **x**  is  **29.0**  and  **y**  is  **3.0**, the return value is  **-1.0**  and  **n**  is  **10**.  **n**  is converted into a signed binary number  **00001010**. Therefore,  **2**  is stored to the pointer specified by  **quo**. 

**Parameters:**

<a name="table1349015156165622"></a>
<table><thead align="left"><tr id="row1234542991165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1360090443165622"><a name="p1360090443165622"></a><a name="p1360090443165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p679335781165622"><a name="p679335781165622"></a><a name="p679335781165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2102437593165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1349515450165622"><a name="b1349515450165622"></a><a name="b1349515450165622"></a>x</strong>, which is used as the numerator. </td>
</tr>
<tr id="row1520464157165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">y</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b774003437165622"><a name="b774003437165622"></a><a name="b774003437165622"></a>y</strong>, which is used as the denominator. </td>
</tr>
<tr id="row1484400392165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">quo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer that stores the quotient. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the remainder if the operation is successful. If  **x**  or  **y**  is a NaN value, this function returns a NaN value. If  **x**  is an infinity and  **y**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. If  **y**  is  **0**  and  **x**  is not a NaN value, this function returns a NaN value, reports a domain error, and throws the  **FE\_INVAID**  exception. 

## rint\(\)<a name="gae1f9edd5049d3ff63b0373a3c15c38c1"></a>

```
double rint (double x)
```

 **Description:**

Rounds the double value  **x**  to the nearest integer. 

**Parameters:**

<a name="table389931980165622"></a>
<table><thead align="left"><tr id="row658584005165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1794227803165622"><a name="p1794227803165622"></a><a name="p1794227803165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p550525720165622"><a name="p550525720165622"></a><a name="p550525720165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1728772036165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Attention:**

POSIX.1-2001 records overflow range errors. If there are two nearest integers, the even integer is returned. For example, if  **x**  is  **0.5**,  **0**  is returned. 

**Returns:**

Returns the nearest integer if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## rintf\(\)<a name="ga48f9341b9310fefa5dd1b0c8c84c99df"></a>

```
float rintf (float x)
```

 **Description:**

Rounds the float value  **x**  to the nearest integer. 

**Parameters:**

<a name="table1624857685165622"></a>
<table><thead align="left"><tr id="row416153057165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1397599143165622"><a name="p1397599143165622"></a><a name="p1397599143165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p818067507165622"><a name="p818067507165622"></a><a name="p818067507165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1476261382165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Attention:**

POSIX.1-2001 records overflow range errors. If there are two nearest integers, the even integer is returned. For example, if  **x**  is  **0.5**,  **0**  is returned. 

**Returns:**

Returns the nearest integer if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## rintl\(\)<a name="gaedc37bf10d69d2efa2a478f5f5d4b26b"></a>

```
long double rintl (long double x)
```

 **Description:**

Rounds the long double value  **x**  to the nearest integer. 

**Parameters:**

<a name="table24019674165622"></a>
<table><thead align="left"><tr id="row1702859977165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p315832897165622"><a name="p315832897165622"></a><a name="p315832897165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p973290558165622"><a name="p973290558165622"></a><a name="p973290558165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row687157441165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Attention:**

POSIX.1-2001 records overflow range errors. If there are two nearest integers, the even integer is returned. For example, if  **x**  is  **0.5**,  **0**  is returned. 

**Returns:**

Returns the nearest integer if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## round\(\)<a name="ga7df19cf730447c00150569250a4b5e1d"></a>

```
double round (double x)
```

 **Description:**

Rounds the double value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table2064851023165622"></a>
<table><thead align="left"><tr id="row2020554901165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p243131779165622"><a name="p243131779165622"></a><a name="p243131779165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p790164805165622"><a name="p790164805165622"></a><a name="p790164805165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row503732152165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b345566234165622"><a name="b345566234165622"></a><a name="b345566234165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. For example, if  **x**  is  **0.5**, the rounded value is  **1**; if  **x**  is  **-0.5**, the rounded value is  **-1**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## roundf\(\)<a name="gade09185c0cf8101fa9e2f25c15041b81"></a>

```
float roundf (float x)
```

 **Description:**

Rounds the float value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table42609125165622"></a>
<table><thead align="left"><tr id="row124518989165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p535904434165622"><a name="p535904434165622"></a><a name="p535904434165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p169665277165622"><a name="p169665277165622"></a><a name="p169665277165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row805828911165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1037321774165622"><a name="b1037321774165622"></a><a name="b1037321774165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. For example, if  **x**  is  **0.5**, the rounded value is  **1**; if  **x**  is  **-0.5**, the rounded value is  **-1**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## roundl\(\)<a name="ga6565127c023ae8f392ce69e3b3f30aa1"></a>

```
long double roundl (long double x)
```

 **Description:**

Rounds the long double value  **x**  to the nearest integer, rounding away from  **0**. 

**Parameters:**

<a name="table219732287165622"></a>
<table><thead align="left"><tr id="row1731076574165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1279050958165622"><a name="p1279050958165622"></a><a name="p1279050958165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1499581211165622"><a name="p1499581211165622"></a><a name="p1499581211165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1381016756165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b885016831165622"><a name="b885016831165622"></a><a name="b885016831165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

Halfway values are rounded away from  **0**. For example, if  **x**  is  **0.5**, the rounded value is  **1**; if  **x**  is  **-0.5**, the rounded value is  **-1**. 

**Returns:**

Returns the nearest integer if the operation is successful; returns the passed  **x**  if  **x**  is an integer,  **+0**,  **-0**, a NaN value, or an infinity. 

## scalb\(\)<a name="ga14db57dcd8982430d12219bbecd08a05"></a>

```
double scalb (double x, double exp )
```

 **Description:**

Multiplies the double value  **x**  by  **FLT\_RADIX**  raised to the power of the double value  **exp**, that is, x\***FLT\_RADIX**^exp. 

**Parameters:**

<a name="table1242503763165622"></a>
<table><thead align="left"><tr id="row1269855496165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2016368914165622"><a name="p2016368914165622"></a><a name="p2016368914165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1808580716165622"><a name="p1808580716165622"></a><a name="p1808580716165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row548039958165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1668741292165622"><a name="b1668741292165622"></a><a name="b1668741292165622"></a>x</strong>. </td>
</tr>
<tr id="row1589242371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## scalbf\(\)<a name="ga9c9db25d2ff9973e0d8638cf42df3999"></a>

```
float scalbf (float x, float exp )
```

 **Description:**

Multiplies the float value  **x**  by  **FLT\_RADIX**  raised to the power of the float value  **exp**, that is, x\***FLT\_RADIX**^exp. 

**Parameters:**

<a name="table1574841297165622"></a>
<table><thead align="left"><tr id="row942708098165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p855109767165622"><a name="p855109767165622"></a><a name="p855109767165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1760007713165622"><a name="p1760007713165622"></a><a name="p1760007713165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1505027827165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b254181694165622"><a name="b254181694165622"></a><a name="b254181694165622"></a>x</strong>. </td>
</tr>
<tr id="row1002321371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## scalbln\(\)<a name="ga947d3d0739c0dc7c46d1eec778d4b6af"></a>

```
double scalbln (double x, long int exp )
```

 **Description:**

Multiplies the double value  **x**  by  **FLT\_RADIX**  raised to the power of the long int value  **exp**, that is,  **x\*\(**FLT\_RADIX**\)^exp**. 

**Parameters:**

<a name="table1665043599165622"></a>
<table><thead align="left"><tr id="row358577103165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p839490141165622"><a name="p839490141165622"></a><a name="p839490141165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1856394988165622"><a name="p1856394988165622"></a><a name="p1856394988165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11491170165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1896264323165622"><a name="b1896264323165622"></a><a name="b1896264323165622"></a>x</strong>. </td>
</tr>
<tr id="row1609960194165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## scalblnf\(\)<a name="ga1aa3cc34e8f84a2a09400c25c578100d"></a>

```
float scalblnf (float x, long int exp )
```

 **Description:**

Multiplies the float value  **x**  by  **FLT\_RADIX**  raised to the power of the long int value  **exp**, that is,  **x\*\(**FLT\_RADIX**\)^exp**. 

**Parameters:**

<a name="table1278668661165622"></a>
<table><thead align="left"><tr id="row2075026867165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p560005659165622"><a name="p560005659165622"></a><a name="p560005659165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p502433141165622"><a name="p502433141165622"></a><a name="p502433141165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1743749261165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b647542834165622"><a name="b647542834165622"></a><a name="b647542834165622"></a>x</strong>. </td>
</tr>
<tr id="row1950683456165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## scalblnl\(\)<a name="gaeb098df94536b520ced9df59fd353848"></a>

```
long double scalblnl (long double x, long int exp )
```

 **Description:**

Multiplies the long double value  **x**  by  **FLT\_RADIX**  raised to the power of the long int value  **exp**, that is,  **x\*\(**FLT\_RADIX**\)^exp**. 

**Parameters:**

<a name="table1273335585165622"></a>
<table><thead align="left"><tr id="row1935231739165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p63396668165622"><a name="p63396668165622"></a><a name="p63396668165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p265142316165622"><a name="p265142316165622"></a><a name="p265142316165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row866797247165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1759218694165622"><a name="b1759218694165622"></a><a name="b1759218694165622"></a>x</strong>. </td>
</tr>
<tr id="row524806900165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## scalbn\(\)<a name="gaa2fbea1fca1faaebedf2deec71c47189"></a>

```
double scalbn (double x, int exp )
```

 **Description:**

Multiplies the double value  **x**  by  **FLT\_RADIX**  raised to the power of the int value  **exp**, that is,  **x\*\(**FLT\_RADIX**\)^exp**. 

**Parameters:**

<a name="table1104446285165622"></a>
<table><thead align="left"><tr id="row1283210666165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p890025963165622"><a name="p890025963165622"></a><a name="p890025963165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p201835020165622"><a name="p201835020165622"></a><a name="p201835020165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row375432988165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b1255865949165622"><a name="b1255865949165622"></a><a name="b1255865949165622"></a>x</strong>. </td>
</tr>
<tr id="row2008773734165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## scalbnf\(\)<a name="ga3849b86bb2f39ebccb79b91745f7883f"></a>

```
float scalbnf (float x, int exp )
```

 **Description:**

Multiplies the float value  **x**  by  **FLT\_RADIX**  raised to the power of the int value  **exp**, that is,  **x\*\(**FLT\_RADIX**\)^exp**. 

**Parameters:**

<a name="table2073321779165622"></a>
<table><thead align="left"><tr id="row1703883997165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2044977891165622"><a name="p2044977891165622"></a><a name="p2044977891165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p358787021165622"><a name="p358787021165622"></a><a name="p358787021165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1087378188165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1965859300165622"><a name="b1965859300165622"></a><a name="b1965859300165622"></a>x</strong>. </td>
</tr>
<tr id="row1208142777165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. If an underflow range error occurs, this function returns  **0**  and throws the  [FE\_UNDERFLOW](math.md#ga57b80dfe7d5ce60c3c76e517fce89ffe)  exception. 

## scalbnl\(\)<a name="ga284717e9eceed5bc33389ce33170f907"></a>

```
long double scalbnl (long double x, int exp )
```

 **Description:**

Multiplies the long double value  **x**  by  **FLT\_RADIX**  raised to the power of the int value  **exp**, that is,  **x\*\(**FLT\_RADIX**\)^exp**. 

**Parameters:**

<a name="table1695711951165622"></a>
<table><thead align="left"><tr id="row1434314280165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p17896594165622"><a name="p17896594165622"></a><a name="p17896594165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p870379861165622"><a name="p870379861165622"></a><a name="p870379861165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row932702594165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1343303195165622"><a name="b1343303195165622"></a><a name="b1343303195165622"></a>x</strong>. </td>
</tr>
<tr id="row1581945117165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value used as the exponent. </td>
</tr>
</tbody>
</table>

**Attention:**

**FLT\_RADIX**  is defined in  **float.h**  and is generally  **2**. 

**Returns:**

Returns the calculation result if the operation is successful. If  **x**  or  **exp**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, and  **exp**  is not a negative infinity, this function returns a positive or negative infinity. If  **x**  is  **+0**  or  **-0**, and  **exp**  is not a positive infinity, this function returns  **+0**  or  **-0**. If  **x**  is  **0**  and  **exp**  is a positive infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If  **x**  is an infinity and  **exp**  is a negative infinity, this function returns a NaN value, reports a domain error, and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  with the sign of  **x**  and throws the  [FE\_OVERFLOW](math.md#gad373306add36e7227d9c9620b6962323)  exception. 

## significand\(\)<a name="gafad3bf1f77c516fb8891c72beb51640f"></a>

```
double significand (double x)
```

 **Description:**

Obtains the significand of the double value  **x**  scaled to the range \[1,2\). 

The calculation formula is x\*2^-[ilogb](math.md#ga600dd249210d15af31b9a29c2d09d255)\(x\). This function is mainly used in certain standardized tests for IEEE 754 conformance. 

**Parameters:**

<a name="table1073035113165622"></a>
<table><thead align="left"><tr id="row1816968883165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1377450761165622"><a name="p1377450761165622"></a><a name="p1377450761165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1373256693165622"><a name="p1373256693165622"></a><a name="p1373256693165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1605266935165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b2130277031165622"><a name="b2130277031165622"></a><a name="b2130277031165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the significand of  **x**  if the operation is successful. 

## significandf\(\)<a name="gac57d7d88e1a9b57c9a129ee4d4a68c42"></a>

```
float significandf (float x)
```

 **Description:**

Obtains the significand of the float value  **x**  scaled to the range \[1,2\). 

The calculation formula is x\*2^-[ilogb](math.md#ga600dd249210d15af31b9a29c2d09d255)\(x\). This function is mainly used in certain standardized tests for IEEE 754 conformance. 

**Parameters:**

<a name="table1511231773165622"></a>
<table><thead align="left"><tr id="row741371998165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1521946254165622"><a name="p1521946254165622"></a><a name="p1521946254165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1339384285165622"><a name="p1339384285165622"></a><a name="p1339384285165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1797089446165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b1200799400165622"><a name="b1200799400165622"></a><a name="b1200799400165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the significand of  **x**  if the operation is successful. 

## sin\(\)<a name="gaad4af25633b071b0e2cdb8ebd87eca77"></a>

```
double sin (double x)
```

 **Description:**

Calculates the sine of the double value  **x**. 

**Parameters:**

<a name="table1025807634165622"></a>
<table><thead align="left"><tr id="row1013828564165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1083218114165622"><a name="p1083218114165622"></a><a name="p1083218114165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1999347759165622"><a name="p1999347759165622"></a><a name="p1999347759165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1799635343165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the sine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sincos\(\)<a name="gaf4509ae544cecab0e9a61efdfccb7530"></a>

```
void sincos (double x, double * sin, double * cos )
```

 **Description:**

Calculates the sine and cosine of the double value  **x**. 

**Parameters:**

<a name="table2007969140165622"></a>
<table><thead align="left"><tr id="row1309818403165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p809472009165622"><a name="p809472009165622"></a><a name="p809472009165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2040317599165622"><a name="p2040317599165622"></a><a name="p2040317599165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row213198049165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose sine and cosine are to be calculated. </td>
</tr>
<tr id="row1778042885165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sin</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained sine. </td>
</tr>
<tr id="row1706335960165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained cosine. </td>
</tr>
</tbody>
</table>

**Attention:**

A domain error occurs if  **x**  is an infinity. In this case, the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception is thrown, and  **sin**  and  **cos**  are both NaN values. If  **x**  is a NaN value,  **sin**  and  **cos**  are both NaN values. 

## sincosf\(\)<a name="gac59adab35511be68e92ad9013d63e866"></a>

```
void sincosf (float x, float * sin, float * cos )
```

 **Description:**

Calculates the sine and cosine of the float value  **x**. 

**Parameters:**

<a name="table803887543165622"></a>
<table><thead align="left"><tr id="row748038078165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1637221421165622"><a name="p1637221421165622"></a><a name="p1637221421165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1869169837165622"><a name="p1869169837165622"></a><a name="p1869169837165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row282293478165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose sine and cosine are to be calculated. </td>
</tr>
<tr id="row1450207029165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sin</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained sine. </td>
</tr>
<tr id="row376254108165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained cosine. </td>
</tr>
</tbody>
</table>

**Attention:**

A domain error occurs if  **x**  is an infinity. In this case, the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception is thrown, and  **sin**  and  **cos**  are both NaN values. If  **x**  is a NaN value,  **sin**  and  **cos**  are both NaN values. 

## sincosl\(\)<a name="gaf877b78dbe8e265bdf4b975dbc713482"></a>

```
void sincosl (long double x, long double * sin, long double * cos )
```

 **Description:**

Calculates the sine and cosine of the long double value  **x**. 

**Parameters:**

<a name="table1780008782165622"></a>
<table><thead align="left"><tr id="row92116493165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1494528487165622"><a name="p1494528487165622"></a><a name="p1494528487165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p861571592165622"><a name="p861571592165622"></a><a name="p861571592165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row130510867165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value whose sine and cosine are to be calculated. </td>
</tr>
<tr id="row864091103165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sin</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained sine. </td>
</tr>
<tr id="row418287784165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained cosine. </td>
</tr>
</tbody>
</table>

**Attention:**

A domain error occurs if  **x**  is an infinity. In this case, the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception is thrown, and  **sin**  and  **cos**  are both NaN values. If  **x**  is a NaN value,  **sin**  and  **cos**  are both NaN values. 

## sinf\(\)<a name="ga8a7dc2a88e109f4e15b661247665709a"></a>

```
float sinf (float x)
```

 **Description:**

Calculates the sine of the float value  **x**. 

**Parameters:**

<a name="table1843402186165622"></a>
<table><thead align="left"><tr id="row1163777368165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1490086596165622"><a name="p1490086596165622"></a><a name="p1490086596165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2029229180165622"><a name="p2029229180165622"></a><a name="p2029229180165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1805500674165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the sine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sinh\(\)<a name="ga862012e970c977c482507064e2793b45"></a>

```
double sinh (double x)
```

 **Description:**

Calculates the hyperbolic sine of the double value  **x**. 

**Parameters:**

<a name="table1706937981165622"></a>
<table><thead align="left"><tr id="row543439138165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1845412953165622"><a name="p1845412953165622"></a><a name="p1845412953165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p737212068165622"><a name="p737212068165622"></a><a name="p737212068165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1429190614165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic sine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  with the sign of  **x**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sinhf\(\)<a name="ga1976c7577fb97800f4b926bd042b64ac"></a>

```
float sinhf (float x)
```

 **Description:**

Calculates the hyperbolic sine of the float value  **x**. 

**Parameters:**

<a name="table549262825165622"></a>
<table><thead align="left"><tr id="row572576053165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1041983432165622"><a name="p1041983432165622"></a><a name="p1041983432165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p186372104165622"><a name="p186372104165622"></a><a name="p186372104165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row611705527165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic sine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  with the sign of  **x**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sinhl\(\)<a name="gad160d5d1bb3f113e96135a4bebe76abe"></a>

```
long double sinhl (long double x)
```

 **Description:**

Calculates the hyperbolic sine of the long double value  **x**. 

**Parameters:**

<a name="table1566482618165622"></a>
<table><thead align="left"><tr id="row1321637937165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2101323691165622"><a name="p2101323691165622"></a><a name="p2101323691165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1649039406165622"><a name="p1649039406165622"></a><a name="p1649039406165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1886380293165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic sine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **+0**  or  **-0**, this function returns  **+0**  or  **-0**, respectively. If  **x**  is a positive or negative infinity, this function returns a positive or negative infinity. If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  with the sign of  **x**, sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sinl\(\)<a name="gaeb537bfea71fa91192234a666f3a6a25"></a>

```
long double sinl (long double x)
```

 **Description:**

Calculates the sine of the long double value  **x**. 

**Parameters:**

<a name="table1569596845165622"></a>
<table><thead align="left"><tr id="row26830611165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1944247812165622"><a name="p1944247812165622"></a><a name="p1944247812165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2015773459165622"><a name="p2015773459165622"></a><a name="p2015773459165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row221886104165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the sine of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive or negative infinity, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sqrt\(\)<a name="gab87521a75ef827a85807f89a6c10629a"></a>

```
double sqrt (double x)
```

 **Description:**

Calculates the square root of double value  **x**. 

**Parameters:**

<a name="table724376065165622"></a>
<table><thead align="left"><tr id="row1531590447165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1110738976165622"><a name="p1110738976165622"></a><a name="p1110738976165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1132461015165622"><a name="p1132461015165622"></a><a name="p1132461015165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1659316873165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the square root of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sqrtf\(\)<a name="ga46c9a8d40cde7c4d5ab40a67e55316bb"></a>

```
float sqrtf (float x)
```

 **Description:**

Calculates the square root of the float value  **x**. 

**Parameters:**

<a name="table2136990430165622"></a>
<table><thead align="left"><tr id="row1073811429165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p200176929165622"><a name="p200176929165622"></a><a name="p200176929165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1256494145165622"><a name="p1256494145165622"></a><a name="p1256494145165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1224656635165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the square root of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## sqrtl\(\)<a name="ga9c028a87917b3bb9bba9e75f66cdbd43"></a>

```
long double sqrtl (long double x)
```

 **Description:**

Calculates the square root of the long double value  **x**. 

**Parameters:**

<a name="table1317764519165622"></a>
<table><thead align="left"><tr id="row1877010842165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p390883349165622"><a name="p390883349165622"></a><a name="p390883349165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1428507436165622"><a name="p1428507436165622"></a><a name="p1428507436165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1845419190165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the square root of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tan\(\)<a name="gaa48fdfd5eea5f4f9c33496402b9e4039"></a>

```
double tan (double x)
```

 **Description:**

Calculates the tangent of the double value  **x**. 

**Parameters:**

<a name="table1233772383165622"></a>
<table><thead align="left"><tr id="row1824939336165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2057738108165622"><a name="p2057738108165622"></a><a name="p2057738108165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1641286482165622"><a name="p1641286482165622"></a><a name="p1641286482165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1619282627165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value, which represents an angle in radians. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the tangent of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tanf\(\)<a name="ga67d5bfe80effce6adebf5fcbc5a7dae0"></a>

```
float tanf (float x)
```

 **Description:**

Calculates the tangent of the float value  **x**. 

**Parameters:**

<a name="table340060998165622"></a>
<table><thead align="left"><tr id="row2091326202165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p912123976165622"><a name="p912123976165622"></a><a name="p912123976165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p688182215165622"><a name="p688182215165622"></a><a name="p688182215165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row297995006165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value, which represents an angle in radians. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the tangent of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tanh\(\)<a name="gaf85bcf153d7ae805733927f12329dac1"></a>

```
double tanh (double x)
```

 **Description:**

Calculates the hyperbolic tangent of the double value  **x**. 

**Parameters:**

<a name="table1957744231165622"></a>
<table><thead align="left"><tr id="row620677653165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p354344996165622"><a name="p354344996165622"></a><a name="p354344996165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p570861940165622"><a name="p570861940165622"></a><a name="p570861940165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1957773300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic tangent of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tanhf\(\)<a name="ga74e8f87bb37a338d2cebbb6b1d696593"></a>

```
float tanhf (float x)
```

 **Description:**

Calculates the hyperbolic tangent of the float value  **x**. 

**Parameters:**

<a name="table907679396165622"></a>
<table><thead align="left"><tr id="row120775768165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p577475527165622"><a name="p577475527165622"></a><a name="p577475527165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1499881370165622"><a name="p1499881370165622"></a><a name="p1499881370165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row917680332165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic tangent of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tanhl\(\)<a name="ga94ee8c57b6b2d0bc5466c75bea2bffcf"></a>

```
long double tanhl (long double x)
```

 **Description:**

Calculates the hyperbolic tangent of the long double value  **x**. 

**Parameters:**

<a name="table246252047165622"></a>
<table><thead align="left"><tr id="row190392035165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p518191835165622"><a name="p518191835165622"></a><a name="p518191835165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1002258443165622"><a name="p1002258443165622"></a><a name="p1002258443165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row307576201165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the hyperbolic tangent of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tanl\(\)<a name="ga2151fba6c1e9b4fa5d2af2dcb5c68b17"></a>

```
long double tanl (long double x)
```

 **Description:**

Calculates the tangent of the long double value  **x**. 

**Parameters:**

<a name="table1507371672165622"></a>
<table><thead align="left"><tr id="row186247258165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p441049143165622"><a name="p441049143165622"></a><a name="p441049143165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p405551272165622"><a name="p405551272165622"></a><a name="p405551272165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1928504284165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value, which represents an angle in radians. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the tangent of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0**, this function returns  **0**. If  **x**  is less than  **-0**, this function returns a NaN value, reports a domain error, sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70), and throws the  [FE\_INVALID](math.md#ga638c8489adb1fac7204b07ece42998ae)  exception. 

## tgamma\(\)<a name="ga54afbf509eea5e9d6f9efdebc572339a"></a>

```
double tgamma (double x)
```

 **Description:**

Calculates the gamma function of the double value  **x**. 

**Parameters:**

<a name="table1619558909165622"></a>
<table><thead align="left"><tr id="row2049749565165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1371416597165622"><a name="p1371416597165622"></a><a name="p1371416597165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1635370781165622"><a name="p1635370781165622"></a><a name="p1635370781165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1226014774165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the gamma function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative integer or negative infinity, this function returns a NaN value, reports a domain error, and sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70). If an underflow range error occurs, this function returns  **+0**. If  **x**  is  **+0**  or  **-0**, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  with the sign of  **x**, reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). If an overflow range error occurs, this function returns  [HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## tgammaf\(\)<a name="ga2ab69de9110cc2c62ca78b5d20a3a3ae"></a>

```
float tgammaf (float x)
```

 **Description:**

Calculates the gamma function of the float value  **x**. 

**Parameters:**

<a name="table1045908966165622"></a>
<table><thead align="left"><tr id="row995062178165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p587261571165622"><a name="p587261571165622"></a><a name="p587261571165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p365799263165622"><a name="p365799263165622"></a><a name="p365799263165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1687268547165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the gamma function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative integer or negative infinity, this function returns a NaN value, reports a domain error, and sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70). If an underflow range error occurs, this function returns  **+0**. If  **x**  is  **+0**  or  **-0**, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  with the sign of  **x**, reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). If an overflow range error occurs, this function returns  [HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## tgammal\(\)<a name="ga8eff39a57115761c5025e08ff2e08c6a"></a>

```
long double tgammal (long double x)
```

 **Description:**

Calculates the gamma function of the long double value  **x**. 

**Parameters:**

<a name="table307067842165622"></a>
<table><thead align="left"><tr id="row765868950165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p677315300165622"><a name="p677315300165622"></a><a name="p677315300165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1742146637165622"><a name="p1742146637165622"></a><a name="p1742146637165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row478192096165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the gamma function of  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is a positive infinity, this function returns a positive infinity. If  **x**  is a negative integer or negative infinity, this function returns a NaN value, reports a domain error, and sets  **errno**  to  [EDOM](utils.md#ga5fe247e079b591a68e0fdbf7caec5b70). If an underflow range error occurs, this function returns  **+0**. If  **x**  is  **+0**  or  **-0**, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  with the sign of  **x**, reports a pole error, and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). If an overflow range error occurs, this function returns  [HUGE\_VALL](math.md#gab8b359c356d4311bf5d4ae6c03f43182)  and sets  **errno**  to  [ERANGE](utils.md#gaa1591a4f3a86360108de5b9ba34980ca). 

## trunc\(\)<a name="ga82a151adfde56b28fa8a50355c4f2ff6"></a>

```
double trunc (double x)
```

 **Description:**

Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the double value  **x**. 

**Parameters:**

<a name="table176437328165622"></a>
<table><thead align="left"><tr id="row398666785165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2053618355165622"><a name="p2053618355165622"></a><a name="p2053618355165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1432929570165622"><a name="p1432929570165622"></a><a name="p1432929570165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2024319851165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value <strong id="b975532547165622"><a name="b975532547165622"></a><a name="b975532547165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the nearest integer whose absolute value is less than or equal to the absolute value of  **x**. 

## truncf\(\)<a name="gaa8bb2049c170c9ac5b131fdba029991a"></a>

```
float truncf (float x)
```

 **Description:**

Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the float value  **x**. 

**Parameters:**

<a name="table1364122278165622"></a>
<table><thead align="left"><tr id="row2008065421165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1746882834165622"><a name="p1746882834165622"></a><a name="p1746882834165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p193365033165622"><a name="p193365033165622"></a><a name="p193365033165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row423687072165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value <strong id="b25821481165622"><a name="b25821481165622"></a><a name="b25821481165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the nearest integer whose absolute value is less than or equal to the absolute value of  **x**. 

## truncl\(\)<a name="ga8f9695496a9bb839eb5f728b6bf0c856"></a>

```
long double truncl (long double x)
```

 **Description:**

Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the long double value  **x**. 

**Parameters:**

<a name="table1055057160165622"></a>
<table><thead align="left"><tr id="row113078076165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1537990400165622"><a name="p1537990400165622"></a><a name="p1537990400165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1394995381165622"><a name="p1394995381165622"></a><a name="p1394995381165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1900014324165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long double value <strong id="b1944485075165622"><a name="b1944485075165622"></a><a name="b1944485075165622"></a>x</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the nearest integer whose absolute value is less than or equal to the absolute value of  **x**. 

## y0\(\)<a name="gafca57fd80386476e5cd1dd52173103c5"></a>

```
double y0 (double x)
```

 **Description:**

Calculates the Bessel function of the second kind of order  **0**  for the double value  **x**. 

**Parameters:**

<a name="table1517652592165622"></a>
<table><thead align="left"><tr id="row457485749165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1545503527165622"><a name="p1545503527165622"></a><a name="p1545503527165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1673574294165622"><a name="p1673574294165622"></a><a name="p1673574294165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1281581388165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the Bessel function of the second kind of order  **0**  for  **x**  if the operation is successful . If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0.0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and reports a pole error. If  **x**  is a negative value, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and reports a range error. If an overflow range error occurs, this function returns  **0.0**. 

## y0f\(\)<a name="gaba3cd2d73c1ae75ec2d01ebb2dfc108c"></a>

```
float y0f (float x)
```

 **Description:**

Calculates the Bessel function of the second kind of order  **0**  for the float value  **x**. 

**Parameters:**

<a name="table1692790199165622"></a>
<table><thead align="left"><tr id="row1727974885165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p224154408165622"><a name="p224154408165622"></a><a name="p224154408165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p489462236165622"><a name="p489462236165622"></a><a name="p489462236165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1777402805165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and reports a pole error if  **x**  is  **0.0**; returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and reports a domain error if  **x**  is a negative value; returns  **0.0**  if an overflow range error occurs. 

## y1\(\)<a name="ga369368526a105f3fba6776b11586070c"></a>

```
double y1 (double x)
```

 **Description:**

Calculates the Bessel function of the second kind of order  **1**  for the double value  **x**. 

**Parameters:**

<a name="table707908585165622"></a>
<table><thead align="left"><tr id="row1073806561165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p908984416165622"><a name="p908984416165622"></a><a name="p908984416165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1757580987165622"><a name="p1757580987165622"></a><a name="p1757580987165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1772383965165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the Bessel function of the second kind of order  **1**  for  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0.0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and reports a pole error. If  **x**  is a negative value, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and reports a range error. If an overflow range error occurs, this function returns  **0.0**. 

## y1f\(\)<a name="ga5f37c38e8985dafae6abca2d1782c160"></a>

```
float y1f (float x)
```

 **Description:**

Calculates the Bessel function of the second kind of order  **1**  for the float value  **x**. 

**Parameters:**

<a name="table1959663450165622"></a>
<table><thead align="left"><tr id="row2132919514165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1469605909165622"><a name="p1469605909165622"></a><a name="p1469605909165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1633263310165622"><a name="p1633263310165622"></a><a name="p1633263310165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row876118565165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and reports a pole error if  **x**  is  **0.0**; returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and reports a domain error if  **x**  is a negative value; returns  **0.0**  if an overflow range error occurs. 

## yn\(\)<a name="gae31b4c8c6af724eaa73ad2ebce1aa3ce"></a>

```
double yn (int n, double x )
```

 **Description:**

Calculates the Bessel function of the second kind of order  **n**  for the double value  **x**. 

**Parameters:**

<a name="table1999251810165622"></a>
<table><thead align="left"><tr id="row1656008298165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p900050263165622"><a name="p900050263165622"></a><a name="p900050263165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1436319403165622"><a name="p1436319403165622"></a><a name="p1436319403165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row194969629165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the order of the Bessel function of the first kind. </td>
</tr>
<tr id="row1634634120165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the Bessel function of the second kind of order  **n**  for  **x**  if the operation is successful. If  **x**  is a NaN value, this function returns a NaN value. If  **x**  is  **0.0**, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and reports a pole error. If  **x**  is a negative value, this function returns  **-[HUGE\_VAL](math.md#gaf2164b2db92d8a0ed3838ad5c28db971)**  and reports a range error. If an overflow range error occurs, this function returns  **0.0**. 

## ynf\(\)<a name="ga47f8750942b731456dd7f2cbf5f55806"></a>

```
float ynf (int n, float x )
```

 **Description:**

Calculates the Bessel function of the second kind of order  **n**  for the float value  **x**. 

**Parameters:**

<a name="table578521607165622"></a>
<table><thead align="left"><tr id="row1405394824165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p341438691165622"><a name="p341438691165622"></a><a name="p341438691165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1493160034165622"><a name="p1493160034165622"></a><a name="p1493160034165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row193210024165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the order of the Bessel function of the second kind. </td>
</tr>
<tr id="row1289929439165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the float value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the calculation result if the operation is successful; returns a NaN value if  **x**  is a NaN value; returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and reports a pole error if  **x**  is  **0.0**; returns  **-[HUGE\_VALF](math.md#gacd69981d54c27fe0ff514645dbfc6359)**  and reports a domain error if  **x**  is a negative value; returns  **0.0**  if an overflow range error occurs. 

