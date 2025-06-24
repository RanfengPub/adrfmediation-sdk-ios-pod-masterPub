//
//  ADRFMediationSDKDrawvodAd.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/4/22.
//

#import <UIKit/UIKit.h>
#import "ADRFMediationAdapterErrorDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ADRFMediationSDKDrawvodAdStatus) {
    ADRFMediationSDKDrawvodAdStatusDefault, // 闲置状态
    ADRFMediationSDKDrawvodAdStatusLoading, // 加载广告中
};

@class ADRFMediationAdapterDrawvodAdView;
@protocol ADRFMediationSDKDrawvodAdDelegate;

@interface ADRFMediationSDKDrawvodAd : NSObject

- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithSize:(CGSize)size;

/**
 代理回调
 */
@property (nonatomic, weak) id<ADRFMediationSDKDrawvodAdDelegate> delegate;

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/*
 status
 详解：开发者可通过状态值来判断当前广告对象是否正在加载广告，支持KVO
*/
@property (nonatomic, assign, readonly) ADRFMediationSDKDrawvodAdStatus status;

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

/**
 加载广告
 @param count 拉取几条广告,建议区间 1~4, 超过可能无法拉取到
*/
- (void)load:(NSInteger)count;

@end

@protocol ADRFMediationSDKDrawvodAdDelegate <NSObject>

/**
 DrawvodAd请求成功
 
 @param drawvodAd 广告实例
 @param drawvodAdViewArray ADMobGenDrawvodAd集合
 */
- (void)adrf_drawvodAdSuccessToLoad:(ADRFMediationSDKDrawvodAd *)drawvodAd drawvodAdArray:(NSArray<ADRFMediationAdapterDrawvodAdView *> *)drawvodAdViewArray;
/**
 DrawvodAd请求失败
 
 @param drawvodAd 广告实例
 @param errorModel 请求错误描述
 */
- (void)adrf_drawvodAdFailToLoad:(ADRFMediationSDKDrawvodAd *)drawvodAd errorModel:(ADRFMediationAdapterErrorDefine *)errorModel;
/**
 DrawvodAd请求成功
 
 @param drawvodAd 广告实例
 @param drawvodAdView  ADMobGenDrawvodAd广告
 */
- (void)adrf_drawvodAdSuccessToRender:(ADRFMediationSDKDrawvodAd *)drawvodAd view:(ADRFMediationAdapterDrawvodAdView *)drawvodAdView;
/**
 DrawvodAd请求成功
 
 @param drawvodAd 广告实例
 @param drawvodAdView  ADMobGenDrawvodAd广告
 */
- (void)adrf_drawvodAdFailToRender:(ADRFMediationSDKDrawvodAd *)drawvodAd view:(ADRFMediationAdapterDrawvodAdView *)drawvodAdView error:(nullable NSError *)error;

/**
 DrawvodAdView播放完成
 
 @param drawvodAdView 广告视图
 */
- (void)adrf_drawvodAdPlayerDidPlayFinish:(ADRFMediationAdapterDrawvodAdView *)drawvodAdView ;

/**
 DrawvodAdView被展示
 
 @param drawvodAdView 广告视图
 */
- (void)adrf_drawvodAdDidExposure:(ADRFMediationAdapterDrawvodAdView *)drawvodAdView;

/**
 DrawvodAdView被点击
 
 @param drawvodAdView 广告视图
 */
- (void)adrf_drawvodAdDidClick:(ADRFMediationAdapterDrawvodAdView *)drawvodAdView;

/**
 DrawvodAdView落地页关闭
 
 @param drawvodAdView 广告视图
 */
- (void)adrf_drawvodAdCloseLandingPage:(ADRFMediationAdapterDrawvodAdView *)drawvodAdView;

@end

NS_ASSUME_NONNULL_END
