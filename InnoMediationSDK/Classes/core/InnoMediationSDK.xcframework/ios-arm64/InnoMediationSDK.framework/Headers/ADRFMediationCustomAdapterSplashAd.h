//
//  ADRFMediationCustomAdapterSplash.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/25.
//

#import <Foundation/Foundation.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterAd.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterSplashRequestContext.h>
#import <InnoMediationSDK/ADRFMediationSDKSourceBiddingResult.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationCustomAdapterSplashAdProtocol <NSObject>

@required
// MARK: - 必须实现

/// 请求广告方法，必须于子类中实现
/// @param context 主SDK端传入的请求相关参数
- (void)requestAdWithContext:(ADRFMediationCustomAdapterSplashRequestContext *)context;

/// 聚合告知可进行展示时触发，需要在子类实现并调用展示方法
- (void)customAdapter_onAdReceive;


@optional

// MARK: - 可选

// MARK: 需支持竞价时实现

/// 竞价 - 询价请求
- (void)biddingRequestWithContext:(ADRFMediationCustomAdapterSplashRequestContext *)context;

/// 竞价 - 比价结果 (该方法内实现仅处理三方竞价结果上报即可)
/// - Parameters:
///   - result: 竞价结果
///   - allPrices: 所有竞价价格，可根据自定义平台需求，从价格列表中获取一价二价
- (void)biddingResult:(ADRFMediationSDKSourceBiddingResult)result
             AllPrice:(NSArray *)allPrices;

@end


@interface ADRFMediationCustomAdapterSplashAd : ADRFMediationCustomAdapterAd<ADRFMediationCustomAdapterSplashAdProtocol>

// MARK: - 以下方法无需在子类中实现，已在父类中实现，只需子类中调用即可

/// 开屏广告加载完成后，若自定义平台返回的是 View 视图可调用此方法传入开屏视图，会自动处理屏幕旋转等问题
/// 若自定义平台返回的非 UIView，则无需使用该方法来进行展示
/// @param adView 开屏广告视图（如三方平台无返回视图，可传nil）
/// @param isCustomBtn 是否使用自定义跳过按钮（当选择YES时，请隐藏三方平台自带跳过按钮，如果三方平台不支持隐藏即无法自定义跳过按钮）
- (void)showSplashWithAdView:( UIView * _Nullable )adView customSkipBtn:(BOOL)isCustomBtn;

/// 三方平台请求成功时子类适配器中调用方法
/// - Parameter eCPM: 若为竞价广告，则传递价格（元）
- (void)trackSplashAdSucceed:(double)eCPM;
- (void)trackSplashAdSucceed;

/// 三方平台展示回调回调时子类适配器中调用方法
- (void)trackSplashAdDisplay;
/// 三方平台展示成功时子类适配器中调用方法
- (void)trackSplashAdSuccessToPresent;
/// 三方平台请求失败回调时子类适配器中调用方法
- (void)trackSplashAdFailedWithError:(nullable NSError*)error;
/// 三方平台渲染失败回调时子类适配器中调用方法
- (void)trackSplashAdFailedToPresentWithError:(nullable NSError*)error;
/// 三方平台点击时子类适配器中调用方法
- (void)trackSplashAdClicked;
/// 三方平台跳过回调时子类适配器中调用方法
- (void)trackSplashAdSkip;
/// 三方平台关闭回调时子类适配器中调用方法
- (void)trackSplashAdClosed;
/// 三方平台关闭落地页回调时子类适配器中调用方法
- (void)trackSplashAdLandingPageClosed;

@end

NS_ASSUME_NONNULL_END
