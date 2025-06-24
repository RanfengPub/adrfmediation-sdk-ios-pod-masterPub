//
//  ADRFMediationSDK.h
//  ADRFMediationSDK
//  3.9.9.12036
//  Created by 陈坤 on 2020/3/24.
//  Updated by suancai on 2024/07/22 09:17.
//

#import <UIKit/UIKit.h>
#import <InnoMediationSDK/ADRFMediationAdViewInfoProtocol.h>
#import <InnoMediationSDK/ADRFMediationAdapterCommonDefine.h>
#import <InnoMediationSDK/ADRFMediationAdapterErrorDefine.h>
#import <InnoMediationSDK/ADRFMediationAdapterNativeAdData.h>
#import <InnoMediationSDK/ADRFMediationAdapterSplashSkipViewProtocol.h>
#import <InnoMediationSDK/ADRFMediationSDKBannerAdView.h>
#import <InnoMediationSDK/ADRFMediationSDKDrawvodAd.h>
#import <InnoMediationSDK/ADRFMediationSDKIntertitialAd.h>
#import <InnoMediationSDK/ADRFMediationSDKNativeAd.h>
#import <InnoMediationSDK/ADRFMediationSDKRewardvodAd.h>
#import <InnoMediationSDK/ADRFMediationSDKSplashAd.h>
#import <InnoMediationSDK/ADRFMediationSDKSplashProAd.h>
#import <InnoMediationSDK/ADRFMediationSDKStatusManager.h>
#import <InnoMediationSDK/ADRFMediationSDKCIDModel.h>
#import <InnoMediationSDK/ADRFMediationSDKDrawvodAd.h>
#import <InnoMediationSDK/ADRFMediationAdapterDrawvodAdView.h>
typedef enum ADRFMediationKitLogLevel:NSUInteger ADRFMediationKitLogLevel;

NS_ASSUME_NONNULL_BEGIN

@interface InnoMediationSDK : NSObject

/**
初始化SDK

@param appId 给定的唯一appid
@param completion 启动完成回调
*/
+ (void)initWithAppId:(NSString *)appId completionBlock:(nullable void(^)(NSError *_Nullable error))completion;

/**
 SDK Version
 */
+ (NSString *)getSDKVersion;

/**
 SDK Package Version
 */
+ (NSDictionary *)getAllPlatformVersion;

/**
 设置日志输出等级
 
 @param logLevel 日志输出等级
 */
+ (void)setLogLevel:(ADRFMediationKitLogLevel)logLevel;

/**
 是否开启个性化广告；默认YES，建议初始化SDK之前设置（支持平台：天目、易量跃动ads、穿山甲、优量汇、百度、快手、Gromore）
 */
@property (nonatomic, assign, class) BOOL enablePersonalAd;

/**
 是否允许获取个人信息，必须在SDK初始化之前设置，目前只会影响InnoMediationSDK，不会影响第三方SDK（默认为YES）
 */
@property (nonatomic, assign, class) BOOL enablePersonalInformation;

/**
 是否是接入到flutter项目中
 */
@property (nonatomic, assign, class) BOOL isFlutter;

/**
 传入支持并发的平台，默认支持穿山甲、优量汇、百度、快手（默认支持的不需要再次传入）
 */
@property (nonatomic, strong, class)NSArray <NSString *>*supportConcurrencyCustomPlatform;

/**
 应用市场id
 */
@property (nonatomic, copy, class) NSString *appStoreAppId;

/**
 微信开发者id
 */
@property (nonatomic, copy, class) NSString *wechatAppId;

/**
 cid数组，元素为ADRFMediationSDKCIDModel
 */
@property (nonatomic, copy, class) NSArray<ADRFMediationSDKCIDModel *> *cidInfos;


/**
 设置请求广告的平台，可以指定平台加载广告
 
 @param platformName 指定加载的平台 Eg:toutiao,gdt,baidu,ksad,tianmu,ranfeng,gromore
 */
+ (void)setOnlyPlatform:(NSString *)platformName;


@end

NS_ASSUME_NONNULL_END
