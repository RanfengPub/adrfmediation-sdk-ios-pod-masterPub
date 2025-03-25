//
//  ADRFMediationCustomBannerAdapterRequestContext.h
//  ADRFMediationSDK
//
//  Created by Suancai on 2023/3/6.
//

#import <ADRFMediationSDK/ADRFMediationCustomAdapterRequestContext.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterBannerRequestContext : ADRFMediationCustomAdapterRequestContext

@property (nonatomic, assign) NSInteger refreshTime;/**< 自刷新时间 */

@property (nonatomic, assign) CGSize adSize;/**< 广告尺寸 */

@end

NS_ASSUME_NONNULL_END
