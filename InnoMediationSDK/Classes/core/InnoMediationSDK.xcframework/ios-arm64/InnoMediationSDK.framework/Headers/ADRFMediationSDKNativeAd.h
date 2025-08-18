//
//  ADRFMediationSDKNativeAd.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/4/15.
//

#import <Foundation/Foundation.h>

#import "ADRFMediationAdapterErrorDefine.h"
#import "ADRFMediationAdapterNativeAdData.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ADRFMediationSDKNativeAdStatus) {
    ADRFMediationSDKNativeAdStatusDefault, // 闲置状态
    ADRFMediationSDKNativeAdStatusLoading, // 加载广告中
};

@protocol ADRFMediationSDKNativeAdDelegate;
@class ADRFMediationAdapterNativeAdDataObject;

@interface ADRFMediationSDKNativeAd : NSObject

- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithAdSize:(CGSize)adSize;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/*
 status
 详解：开发者可通过状态值来判断当前广告对象是否正在加载广告
*/
@property (nonatomic, assign, readonly) ADRFMediationSDKNativeAdStatus status;

/**
 代理回调
 */
@property (nonatomic, weak) id<ADRFMediationSDKNativeAdDelegate> delegate;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 场景id
 */
@property (nonatomic, copy, nullable) NSString *scenesId;

/**
 请求超时时间,默认为4s,需要设置3s及以上
*/
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/// 自定义参数
@property (nonatomic, strong) NSDictionary *extryMap;

/**
 加载广告

 @param count 拉取几条广告,建议区间 1~5, 超过可能无法拉取到
 */
- (void)load:(int)count;

/**
 是否静音播放视频 默认YES
 支持平台：天目、易量跃动ads、优量汇、百度、快手、Gromore
 特殊平台：穿山甲（需在穿山甲后台广告位配置处设置）
 */
@property (nonatomic, assign) BOOL muted;

/**
 信息流自动播放，默认WiFi自动播放 开启后WiFi/4G自动播放
 */
@property(nonatomic ,assign) BOOL autoPlay;

@end

@protocol ADRFMediationSDKNativeAdDelegate <NSObject>

@optional

/**
 信息流广告请求成功

 @param nativeAd 广告实例
 @param adViewArray 广告模板集合
 */
- (void)adrf_nativeAdSucessToLoad:(ADRFMediationSDKNativeAd *)nativeAd
                      adViewArray:(NSArray<__kindof UIView<ADRFMediationAdapterNativeAdViewDelegate> *> *)adViewArray;

/**
 信息流广告请求失败

 @param nativeAd 广告实例
 @param errorModel 请求错误描述
 */
- (void)adrf_nativeAdFailToLoad:(ADRFMediationSDKNativeAd *)nativeAd
                     errorModel:(ADRFMediationAdapterErrorDefine *)errorModel;

/**
 信息流广告渲染成功

 @param adView 广告视图
 */
- (void)adrf_nativeAdViewRenderOrRegistSuccess:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告渲染失败

 @param adView 广告视图
 */
- (void)adrf_nativeAdViewRenderOrRegistFail:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告被点击

 @param nativeAd 广告模板
 */
- (void)adrf_nativeAdClicked:(ADRFMediationSDKNativeAd *)nativeAd
                      adView:(__kindof UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告被关闭
 
 @param nativeAd 广告模板
 */
- (void)adrf_nativeAdClose:(ADRFMediationSDKNativeAd *)nativeAd
                    adView:(__kindof UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告被展示
 
 @param nativeAd 广告实例
 */
- (void)adrf_nativeAdExposure:(ADRFMediationSDKNativeAd *)nativeAd
                       adView:(__kindof UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView;

/**
 信息流广告落地页被关闭
 
 @param nativeAd 广告实例
 */
- (void)adrf_nativeAdCloseLandingPage:(ADRFMediationSDKNativeAd *)nativeAd
                       adView:(__kindof UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView;

/**
 视频类型信息流广告player 播放状态更新回调
 支持平台：穿山甲、优量汇、gromore、天目、易量跃动ads
 
 @param nativeAd 广告实例
 */
- (void)adrf_nativeAd:(ADRFMediationSDKNativeAd *)nativeAd
                       adView:(__kindof UIView<ADRFMediationAdapterNativeAdViewDelegate> *)adView playerStatusChanged:(ADRFMediationAdapterNativeMediaPlayerStatus)status;

@end

NS_ASSUME_NONNULL_END
