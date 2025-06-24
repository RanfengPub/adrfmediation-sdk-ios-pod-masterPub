//
//  ADRFMediationAdapterCommonDefine.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/3/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef ADRFMediationAdapterRenderType
#define ADRFMediationAdapterRenderType ADRFMediationAdapterRenderType
typedef NS_ENUM(NSUInteger, ADRFMediationAdapterRenderType) {
    ADRFMediationAdapterRenderTypeExpress = 1,//模版视图类
    ADRFMediationAdapterRenderTypeNative = 2,//原生广告类
    ADRFMediationAdapterRenderTypeExpressPro = 3, //模版2.0,新插屏
};
#endif

#ifndef ADRFMediationAdapterNativeExpressType
#define ADRFMediationAdapterNativeExpressType ADRFMediationAdapterNativeExpressType
typedef NS_ENUM(NSUInteger, ADRFMediationAdapterNativeExpressType) {
    ADRFMediationAdapterNativeExpressTypeDefault = 1, // 上图下文
    ADRFMediationAdapterNativeExpressTypeBottomImage = 2, // 上文下图
    ADRFMediationAdapterNativeExpressTypeLeftImage = 3, // 左图右文
    ADRFMediationAdapterNativeExpressTypeRightImage = 4, // 左文右图
    ADRFMediationAdapterNativeExpressTypeImage = 5, // 纯图
};
#endif

#ifndef ADRFMediationAdapterECPMType
#define ADRFMediationAdapterECPMType ADRFMediationAdapterECPMType
typedef NS_ENUM(NSUInteger, ADRFMediationAdapterECPMType) {
    ADRFMediationAdapterECPMTypeNone = 0, // 未返回
    ADRFMediationAdapterECPMTypeAccurate = 1, // 精准
    ADRFMediationAdapterECPMTypePlatform = 2, // 平台指定
    ADRFMediationAdapterECPMTypeEstimate = 3, // 估算
};
#endif

#ifndef ADRFMediationAdapterNativeMediaPlayerStatus
#define ADRFMediationAdapterNativeMediaPlayerStatus ADRFMediationAdapterNativeMediaPlayerStatus
typedef NS_ENUM(NSUInteger, ADRFMediationAdapterNativeMediaPlayerStatus) {
    ADRFMediationAdapterNativeMediaPlayerStatusInitial = 0,         // 初始状态
    ADRFMediationAdapterNativeMediaPlayerStatusLoading = 1,         // 加载中
    ADRFMediationAdapterNativeMediaPlayerStatusStarted = 2,         // 开始播放
    ADRFMediationAdapterNativeMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    ADRFMediationAdapterNativeMediaPlayerStatusFailed = 4,           // 播放出错
    ADRFMediationAdapterNativeMediaPlayerStatusFinish = 5,          // 播放结束
};
#endif

typedef NSString * ADRFMediationAdapterAdType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeOther;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeSplash;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeBanner;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeNative;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeRewardvod;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeInterstitial;

FOUNDATION_EXPORT ADRFMediationAdapterAdType _Nonnull const ADRFMediationAdapterAdTypeDrawvod;

typedef NSString * ADRFMediationAdapterPlatform NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformOther;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformGDT;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformBU;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformBaidu;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformKS;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformTM;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformRF;

FOUNDATION_EXPORT ADRFMediationAdapterPlatform _Nonnull const ADRFMediationAdapterPlatformGromore;


NS_ASSUME_NONNULL_END
