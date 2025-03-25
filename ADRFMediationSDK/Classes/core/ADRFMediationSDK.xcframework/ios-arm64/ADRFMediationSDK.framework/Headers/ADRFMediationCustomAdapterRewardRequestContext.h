//
//  ADRFMediationCustomAdapterRewardRequestContext.h
//  ADRFMediationSDK
//
//  Created by Suancai on 2023/3/6.
//

#import <ADRFMediationSDK/ADRFMediationCustomAdapterRequestContext.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterRewardRequestContext : ADRFMediationCustomAdapterRequestContext

@property (nonatomic, assign) BOOL isMuted;
@property (nonatomic, copy, nullable) NSString *userId;
@property (nonatomic, copy, nullable) NSString *extra;
@property (nonatomic, copy, nullable) NSString *rewardName;
@property (nonatomic, assign, nullable) NSNumber *rewardAmount;

@end

NS_ASSUME_NONNULL_END
