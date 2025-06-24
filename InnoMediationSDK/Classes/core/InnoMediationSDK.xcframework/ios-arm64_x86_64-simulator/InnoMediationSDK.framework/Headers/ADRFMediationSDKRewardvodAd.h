//
//  ADRFMediationSDKRewardvodAd.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/3/27.
//

#import <UIKit/UIKit.h>
#import <InnoMediationSDK/ADRFMediationAdapterErrorDefine.h>
#import <InnoMediationSDK/ADRFMediationAdViewInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationSDKRewardvodAdDelegate;

@interface ADRFMediationSDKRewardvodAd : NSObject <ADRFMediationAdViewInfoProtocol>

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 请求超时时间,默认为4s,需要设置3s及以上
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 场景id
 */
@property (nonatomic, copy, nullable) NSString *scenesId;

/**
 是否静音，默认静音
 支持平台：天目，易量跃动ads，优量汇，快手，Gromore
 */
@property (nonatomic, assign) BOOL isMuted;

/**
 用户id （用户在App内的userID，用于激励视频服务器验证，如无需服务器验证可不传）
 */
@property (nonatomic, copy, nullable) NSString *userId;

/**
 奖励名称 （用于激励视频服务器验证参数，可选）
 */
@property (nonatomic, copy, nullable) NSString *rewardName;

/**
 奖励数量 （用于激励视频服务器验证参数，可选）
 */
@property (nonatomic, assign,nullable) NSNumber *rewardAmount;

/**
 其他信息 （服务器端验证回调中包含的可选自定义奖励字符串，可选）
 */
@property (nonatomic, copy, nullable) NSString *extraInfo;

/**
 代理回调
 */
@property (nonatomic, weak) id<ADRFMediationSDKRewardvodAdDelegate> delegate;

/**
加载激励视频广告
*/
- (void)loadRewardvodAd;

/**
 激励视频广告是否支持服务端验证
 支持平台：穿山甲、优量汇、百度、快手、Gromore
 */
- (BOOL)rewardvodAdCanServerVerrify;

/**
 激励视频广告是否准备好
 */
- (BOOL)rewardvodAdIsReady;

/**
 激励视频广告物料是否有效
 */
- (BOOL)rewardvodAdIsValid;

/**
 展示激励视频广告
 */
- (void)showRewardvodAd;



@end

@protocol ADRFMediationSDKRewardvodAdDelegate <NSObject>

/**
 广告数据加载成功回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdLoadSuccess:(ADRFMediationSDKRewardvodAd *)rewardvodAd;

/**
 激励视频广告准备好被播放
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdReadyToPlay:(ADRFMediationSDKRewardvodAd *)rewardvodAd;

/**
 视频数据下载成功回调，已经下载过的视频会直接回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdVideoLoadSuccess:(ADRFMediationSDKRewardvodAd *)rewardvodAd;
/**
 视频播放页即将展示回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdWillVisible:(ADRFMediationSDKRewardvodAd *)rewardvodAd;
/**
 视频广告曝光回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdDidVisible:(ADRFMediationSDKRewardvodAd *)rewardvodAd;
/**
 视频播放页关闭回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdDidClose:(ADRFMediationSDKRewardvodAd *)rewardvodAd;
/**
 视频广告信息点击回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdDidClick:(ADRFMediationSDKRewardvodAd *)rewardvodAd;
/**
 视频广告视频播放完成
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdDidPlayFinish:(ADRFMediationSDKRewardvodAd *)rewardvodAd;

/**
 视频广告视频达到奖励条件 （开启服务器验证后请使用服务端验证判断是否达到条件，无需使用本回调做激励达成判断）
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdDidRewardEffective:(ADRFMediationSDKRewardvodAd *)rewardvodAd;

/**
 视频广告请求失败回调
 
 @param rewardvodAd 广告实例
 @param errorModel 具体错误信息
 */
- (void)adrf_rewardvodAdFailToLoad:(ADRFMediationSDKRewardvodAd *)rewardvodAd errorModel:(ADRFMediationAdapterErrorDefine *)errorModel;

/**
 视频广告播放时各种错误回调
 
 @param rewardvodAd 广告实例
 @param errorModel 具体错误信息
 */
- (void)adrf_rewardvodAdPlaying:(ADRFMediationSDKRewardvodAd *)rewardvodAd errorModel:(ADRFMediationAdapterErrorDefine *)errorModel;

/**
 激励视频关闭落地页回调
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdCloseLandingPage:(ADRFMediationSDKRewardvodAd *)rewardvodAd;

/**
 视频广告激励服务验证成功（需等待服务器返回结果后判断是否激励生效）
 
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdServerDidSucceed:(ADRFMediationSDKRewardvodAd *)rewardvodAd;
/**
 视频广告激励服务验证成功（需等待服务器返回结果后判断是否激励生效）,并携带服务验证三方返回的相关参数
 
 支持平台：穿山甲、优量汇、百度、快手
 可通过 [rewardvodAd.adrf_platform isEqualToString:ADRFMediationAdapterPlatformGDT] 来区分渠道
 @param rewardvodAd 广告实例
 */
- (void)adrf_rewardvodAdServerDidSucceed:(ADRFMediationSDKRewardvodAd *)rewardvodAd info:(NSDictionary *)info;
/**
 视频广告完成激励服务验证失败
 
 @param rewardvodAd 广告实例
 @param errorModel 认证失败错误信息
 */
- (void)adrf_rewardvodAdServerDidFailed:(ADRFMediationSDKRewardvodAd *)rewardvodAd errorModel:(ADRFMediationAdapterErrorDefine *)errorModel;

@end

NS_ASSUME_NONNULL_END
