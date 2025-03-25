//
//  ADRFMediationCustomAdapterInterstitalRequestContext.h
//  ADRFMediationSDK
//
//  Created by Suancai on 2023/3/6.
//

#import "ADRFMediationCustomAdapterRequestContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterInterstitalRequestContext : ADRFMediationCustomAdapterRequestContext

@property (nonatomic, assign) NSValue *adSizeValue;
@property (nonatomic, assign) BOOL isFullScreen;
@property (nonatomic, assign) BOOL isMuted;
@property (nonatomic, assign) BOOL detailPageVideoMuted;

@end

NS_ASSUME_NONNULL_END
