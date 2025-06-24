//
//  ADRFMediationCustomAdapterUnifiedNativeAd.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/9/7.
//

#import <InnoMediationSDK/ADRFMediationCustomAdapterAd.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterUnifiedNativeAdView.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterNativeRequestContext.h>
#import <InnoMediationSDK/ADRFMediationSDKSourceBiddingResult.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationCustomAdapterUnifiedNativeAdProtocol <NSObject>

@required
// MARK: - 需要在子类实现的方法

/// 请求广告方法，必须于子类中实现
/// @param context 主SDK端传入的请求相关参数
- (void)requestAdWithContext:(ADRFMediationCustomAdapterNativeRequestContext *)context;

@optional
// MARK: 需支持竞价时实现

/// 竞价询价请求
- (void)biddingRequestWithContext:(ADRFMediationCustomAdapterNativeRequestContext *)context;

/// 竞价结果，该方法内实现仅处理三方竞价结果上报即可
/// - Parameters:
///   - result: 竞价结果
///   - allPrices: 所有竞价价格
- (void)biddingResult:(ADRFMediationSDKSourceBiddingResult)result
             AllPrice:(NSArray *)allPrices;


@end

@interface ADRFMediationCustomAdapterUnifiedNativeAd : ADRFMediationCustomAdapterAd<ADRFMediationCustomAdapterUnifiedNativeAdProtocol>

// MARK: - 以下方法无需在子类中实现，已在父类中实现，只需子类中调用即可

/// 信息流请求成功
/// @param nativeViews 平台返回的视图数组，使用实现ADRFMediationAdapterNativeAdViewDelegate协议的自定义视图承载后的数组
/// @param eCPM 若为竞价广告，则传递价格（分）
- (void)trackNativeAdSucceedToLoadWithNativeAdViews:(NSArray<UIView<ADRFMediationAdapterNativeAdViewDelegate> *>*)nativeViews ecpm:(double)eCPM;
- (void)trackNativeAdSucceedToLoadWithNativeAdViews:(NSArray<UIView<ADRFMediationAdapterNativeAdViewDelegate> *>*)nativeViews;


/// 信息流请求失败
/// @param error 失败原因
- (void)trackNativeAdFailToLoadWithError:(NSError * _Nullable)error;

/// 信息流广告渲染成功
/// @param nativeView 实现ADRFMediationAdapterNativeAdViewDelegate协议的广告视图
- (void)trackNativeAdRenderSucceedWithNativeView:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)nativeView;

/// 信息流广告渲染失败
/// @param nativeView 实现ADRFMediationAdapterNativeAdViewDelegate协议的广告视图
- (void)trackNativeAdRenderFailedWithNativeView:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)nativeView;

/// 信息流广告展示
/// @param nativeView 实现ADRFMediationAdapterNativeAdViewDelegate协议的广告视图
- (void)trackNativeAdExposuredWithNativeView:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)nativeView;

/// 信息流广告点击
/// @param nativeView 实现ADRFMediationAdapterNativeAdViewDelegate协议的广告视图
- (void)trackNativeAdClickedWithNativeView:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)nativeView;

/// 信息流广告关闭
/// @param nativeView 实现ADRFMediationAdapterNativeAdViewDelegate协议的广告视图
- (void)trackNativeAdClosedWithNativeView:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)nativeView;

/// 信息流广告关闭落地页
/// @param nativeView 实现ADRFMediationAdapterNativeAdViewDelegate协议的广告视图
- (void)trackNativeAdLandingPageClosedWithNativeView:(UIView<ADRFMediationAdapterNativeAdViewDelegate> *)nativeView;

@end

NS_ASSUME_NONNULL_END
