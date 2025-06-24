//
//  ADRFMediationCustomAdapterSplashRequestContext.h
//  ADRFMediationSDK
//
//  Created by Suancai on 2023/3/6.
//

#import <InnoMediationSDK/ADRFMediationCustomAdapterRequestContext.h>
#import <InnoMediationSDK/ADRFMediationAdapterSplashSkipViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterSplashRequestContext : ADRFMediationCustomAdapterRequestContext

@property (nonatomic, weak, nullable) UIWindow *window;
@property (nonatomic, weak, nullable) UIView *bottomView;/**< 开屏广告底部视图 */
@property (nonatomic, weak) UIView<ADRFMediationAdapterSplashSkipViewProtocol> *skipView;

/**
 激励相关参数
 */
@property (nonatomic, copy, nullable) NSString *userId;
@property (nonatomic, copy, nullable) NSString *extra;

@end

NS_ASSUME_NONNULL_END
