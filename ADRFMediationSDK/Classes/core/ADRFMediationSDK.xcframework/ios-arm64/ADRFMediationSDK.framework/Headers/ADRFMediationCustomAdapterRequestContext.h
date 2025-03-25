//
//  ADRFMediationCustomAdapterRequestContext.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterRequestContext : NSObject

// 第三方平台的appid
@property (nonatomic, copy) NSString *appId;
// 第三方平台的Appkey
@property (nonatomic, copy, nullable) NSString *appKey;
// 第三方平台的posId
@property (nonatomic, copy) NSString *posId;
// rf SDK中的posId
@property (nonatomic, copy) NSString *rfPosId;
// 当前控制器（可为nil）
@property (nonatomic, weak, nullable) UIViewController *viewController;




@end

NS_ASSUME_NONNULL_END
