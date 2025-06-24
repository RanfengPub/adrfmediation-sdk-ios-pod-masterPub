//
//  ADRFMediationSDKIntertitialAd.h
//  ADRFMediationSDK
//
//  Created by 陶冶明 on 2020/4/10.
//

#import <UIKit/UIKit.h>
#import <InnoMediationSDK/ADRFMediationAdapterErrorDefine.h>
#import <InnoMediationSDK/ADRFMediationAdViewInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationSDKIntertitialAdDelegate;

@interface ADRFMediationSDKIntertitialAd : NSObject <ADRFMediationAdViewInfoProtocol>

/**
 代理回调
*/
@property (nonatomic, weak) id<ADRFMediationSDKIntertitialAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 请求超时时间,默认为4s,需要设置3s及以上
 */
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 场景id
 */
@property (nonatomic, copy, nullable) NSString *scenesId;

/**
 广告尺寸，需与平台所申请广告位比例一致，否则会导致素材压缩（仅支持部分平台）
 */
@property (nonatomic, assign) CGSize adSize;

/**
 是否静音，默认静音
 支持平台：天目，易量跃动ads，优量汇，快手，Gromore
 特殊平台：穿山甲（需在穿山甲后台广告位配置处设置）
 */
@property (nonatomic, assign) BOOL isMuted;

/**
 是否静音播放详情页，默认静音
 支持平台：优量汇
 */
@property (nonatomic, assign) BOOL detailPageVideoMuted;

/**
 加载广告数据
*/
- (void)loadAdData;

/**
 展示广告
*/
- (void)show;

@end

@protocol ADRFMediationSDKIntertitialAdDelegate <NSObject>

/**
 ADRFMediationSDKIntertitialAd请求成功回调
 
 @param interstitialAd 插屏广告实例对象
*/
- (void)adrf_interstitialAdSuccedToLoad:(ADRFMediationSDKIntertitialAd *)interstitialAd;

/**
 ADRFMediationSDKIntertitialAd请求失败回调

 @param interstitialAd 插屏广告实例对象
 @param error 失败原因
*/
- (void)adrf_interstitialAdFailedToLoad:(ADRFMediationSDKIntertitialAd *)interstitialAd error:(ADRFMediationAdapterErrorDefine *)error;

/**
 ADRFMediationSDKIntertitialAd展示在屏幕内回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)adrf_interstitialAdDidPresent:(ADRFMediationSDKIntertitialAd *)interstitialAd;

/**
 ADRFMediationSDKIntertitialAd展示在屏幕内失败回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)adrf_interstitialAdFailedToPresent:(ADRFMediationSDKIntertitialAd *)interstitialAd error:(NSError *)error;

/**
 ADRFMediationSDKIntertitialAd点击回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)adrf_interstitialAdDidClick:(ADRFMediationSDKIntertitialAd *)interstitialAd;

/**
 ADRFMediationSDKIntertitialAd关闭回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)adrf_interstitialAdDidClose:(ADRFMediationSDKIntertitialAd *)interstitialAd;

/**
 ADRFMediationSDKIntertitialAd展示回调
 
 @param interstitialAd 广告实例
 */
- (void)adrf_interstitialAdExposure:(ADRFMediationSDKIntertitialAd *)interstitialAd;

/**
 ADRFMediationSDKIntertitialAd关闭落地页回调
 
 @param interstitialAd 广告实例
 */
- (void)adrf_interstitialAdCloseLandingPage:(ADRFMediationSDKIntertitialAd *)interstitialAd;

@end


NS_ASSUME_NONNULL_END
