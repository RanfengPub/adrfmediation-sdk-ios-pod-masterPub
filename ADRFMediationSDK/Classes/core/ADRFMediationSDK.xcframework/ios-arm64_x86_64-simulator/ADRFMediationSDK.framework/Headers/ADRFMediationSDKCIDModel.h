//
//  ADRFMediationSDKCIDModel.h
//  ADRFMediationSDK
//
//  Created by apple on 2024/12/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationSDKCIDModel : NSObject

/**
 *  @param version 版本
 *  @param cid 原值
 *  @param cidMd5 cid原值进行md5后小写输出
 */
- (instancetype)initWithVersion:(NSString *)version cid:(NSString *)cid cidMd5:(NSString *)cidMd5  NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
