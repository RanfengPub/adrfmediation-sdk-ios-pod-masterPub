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

@end

NS_ASSUME_NONNULL_END
