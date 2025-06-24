//
//  ADRFMediationCustomAdapterInterstitalAd.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/28.
//

#import <InnoMediationSDK/ADRFMediationCustomAdapterAd.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterInterstitalRequestContext.h>
#import <InnoMediationSDK/ADRFMediationSDKSourceBiddingResult.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationCustomAdapterInterstitalAdProtocol <NSObject>

@required
// MARK: - 需要在子类实现的方法

/// 请求广告方法，必须于子类中实现
/// @param context 主SDK端传入的请求相关参数
- (void)requestAdWithContext:(ADRFMediationCustomAdapterInterstitalRequestContext *)context;

/// 展示插屏广告（在该方法中展示平台插屏广告）
- (void)showInterstitalAdFromViewController:(UIViewController * _Nullable )viewController;

@optional
// MARK: 需支持竞价时实现

/// 竞价询价请求
- (void)biddingRequestWithContext:(ADRFMediationCustomAdapterInterstitalRequestContext *)context;

/// 竞价结果，该方法内实现仅处理三方竞价结果上报即可
/// - Parameters:
///   - result: 竞价结果
///   - allPrices: 所有竞价价格
- (void)biddingResult:(ADRFMediationSDKSourceBiddingResult)result
             AllPrice:(NSArray *)allPrices;

@end

@interface ADRFMediationCustomAdapterInterstitalAd : ADRFMediationCustomAdapterAd<ADRFMediationCustomAdapterInterstitalAdProtocol>


// MARK: - 以下方法无需在子类中实现，已在父类中实现，只需子类中调用即可

/// 三方平台请求成功时,子类适配器中调用方法
/// - Parameter eCPM: 若为竞价广告，则传递价格（元），若非竞价广告，传递 0 即可;
- (void)trackInterstitialAdSuccessToLoad:(double)eCPM;
- (void)trackInterstitialAdSuccessToLoad;

/// 三方平台广告展示时，子类适配器中调用方法
- (void)trackInterstitialAdDidPresent;

/// 三方平台请求失败时，子类适配器中调用方法
- (void)trackInterstitialAdFailToLoadError:(nullable NSError *)error;

/// 三方平台广告展示失败时，子类适配器中调用方法
- (void)trackInterstitialAdFailToPresentError:(nullable NSError *)error;

/// 三方平台广告点击时，子类适配器中调用方法
- (void)trackInterstitialAdDidClick;

/// 三方平台广告关闭时，子类适配器中调用方法
- (void)trackInterstitialAdDidClose;

/// 三方平台广告曝光时，子类适配器中调用方法
- (void)trackInterstitialAdDidExposure;

/// 三方平台广告落地页关闭时，子类适配器中调用方法
- (void)trackInterstitialAdLandingPageClosed;

@end

NS_ASSUME_NONNULL_END
