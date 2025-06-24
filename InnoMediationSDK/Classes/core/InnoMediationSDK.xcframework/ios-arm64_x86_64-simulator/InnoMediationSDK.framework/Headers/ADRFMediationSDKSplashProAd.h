//
//  ADRFMediationSDKSplashProAd.h
//  ADRFMediationSDK
//
//  Created by apple on 2024/4/16.
//

#import <UIKit/UIKit.h>
#import <InnoMediationSDK/ADRFMediationAdapterErrorDefine.h>
#import <InnoMediationSDK/ADRFMediationAdapterSplashSkipViewProtocol.h>
#import <InnoMediationSDK/ADRFMediationAdViewInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ADRFMediationSplashProRenderType) {
    ADRFMediationSplashProRenderTypeExpress = 1,//模版开屏
    ADRFMediationSplashProRenderTypeNative = 2,//原生开屏
    ADRFMediationSplashProRenderTypeExpressPro = 3, //开屏模版2.0
};

@protocol ADRFMediationSDKSplashProAdDelegate;

@interface ADRFMediationSDKSplashProAd : NSObject <ADRFMediationAdViewInfoProtocol>

/**
开屏的默认背景色,或者启动页,为nil则代表透明
*/
@property (nonatomic, copy, nullable) UIColor *backgroundColor;

/*
viewControllerForPresentingModalView
详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;

/**
 广告位id
*/
@property (nonatomic, copy, nullable) NSString *posId;

/**
 场景id
 */
@property (nonatomic, copy, nullable) NSString *scenesId;
/**
 用户id （用户在App内的userID，用于激励视频服务器验证，如无需服务器验证可不传）
 */
@property (nonatomic, copy, nullable) NSString *userId;

/**
 其他信息 （服务器端验证回调中包含的可选自定义奖励字符串，可选）
 */
@property (nonatomic, copy, nullable) NSString *extra;

/**
 代理回调
*/
@property (nonatomic, weak) id<ADRFMediationSDKSplashProAdDelegate> delegate;

/**
 开屏请求总超时时间:所有平台轮询的请求等待总时长（不包括图片渲染时间），单位秒，推荐设置为4s，最小值为3s
 开屏各平台分配逻辑:(目前只有开屏需要分配时间，并且理论上分配给到各平台的超时时间不会完全耗尽)
 1、3<=tolerateTimeout<=4:轮询首位平台的超时时间为(tolerateTimeout-1)s，次位为2s，如果后续还有平台统一为1s;
 2、tolerateTimeout>=5:轮询首位平台的超时时间为(tolerateTimeout-2)s，次位为3s，如果后续还有平台统一为2s;
 */
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/**
 跳过按钮的类型，可以通过此接口替换开屏广告的跳过按钮样式；(已不支持自定义跳过按钮功能)
 */
@property (nonatomic, strong, null_resettable) UIView<ADRFMediationAdapterSplashSkipViewProtocol> *skipView;

/**
 是否使用右下角跳过按钮，默认为右上角
 支持平台：穿山甲
 */
@property (nonatomic, assign) BOOL needBottomSkipButton;

/**
 屏蔽摇一摇、扭转手机
 默认NO：不屏蔽，YES：屏蔽
 支持平台：天目、优量汇(仅支持屏蔽摇一摇)、快手
 */
@property (nonatomic, assign) BOOL disableMotion;

/**
 开屏广告是否支持服务端验证
 支持平台：优量汇
 */
- (BOOL)rewardAdCanServerVerrify;

/**
设置保底开屏 （可选）
（App初次启动及InnoMediationSDK未初始化状态保证开屏填充）
 支持平台：穿山甲、优量汇、快手、百度
@param rfPosId 平台广告源id
@param platformListId 后台配置查看networkAdPosListID
@param appId 广告平台AppId，非rf APPid
@param appKey 广告平台AppKey,没有可不传
@param platformPosid 广告平台广告位id
@param renderType 平台广告类型，如：原生，模板。
*/
- (void)setBottomSplashWithRanFengPosid:(NSString *)rfPosId platformListId:(NSString *)platformListId platform:(NSString *)platform appId:(NSString *)appId appKey:(nullable NSString *)appKey platformPosid:(NSString *)platformPosid renderType:(ADRFMediationSplashProRenderType)renderType;

/**
加载开屏广告

@param window 开屏广告展示的window
@param bottomView 底部logo视图, 高度不能超过屏幕的25%
*/
- (void)loadAndShowInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

/**
加载开屏广告

@param window 开屏广告展示的window
*/
- (void)loadAndShowInWindow:(UIWindow *)window;

/**
加载开屏广告

@param window 开屏广告展示的window
*/
- (void)loadAdInWindow:(UIWindow *)window;

/**
加载开屏广告

@param window 开屏广告展示的window
@param bottomView 底部logo视图, 高度不能超过屏幕的25%, 建议: 开屏的广告图片默认640 / 960比例, 可以用 MIN(screenHeight - screenWidth * (960 / 640.0), screenHeight * 0.25) 得出bottomview的高度
*/
- (void)loadAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

/**
展示开屏广告

@param window 开屏广告展示的window
*/
- (void)showAdInWindow:(UIWindow *)window;


@end

@protocol ADRFMediationSDKSplashProAdDelegate <NSObject>

@optional
/**
 开屏加载成功
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdSuccessToLoadAd:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏展现成功
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdSuccessToPresentScreen:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏展现失败
 
 @param splashAd 广告实例
 @param error 具体错误信息
 */
- (void)adrf_splashAdFailToPresentScreen:(ADRFMediationSDKSplashProAd *)splashAd failToPresentScreen:(ADRFMediationAdapterErrorDefine *)error;

/**
 开屏广告点击
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdClicked:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏被跳过
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdSkip:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏被关闭
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdClosed:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏展示
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdEffective:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏关闭落地页
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdCloseLandingPage:(ADRFMediationSDKSplashProAd *)splashAd;

/**
 开屏达到激励条件 （开启服务器验证后请使用服务端验证判断是否达到条件，无需使用本回调做激励达成判断）
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdDidRewardEffective:(ADRFMediationSDKSplashProAd *)splashAd info:(NSDictionary *)info;
@end

NS_ASSUME_NONNULL_END
