//
//  ADRFMediationAdapterNativeAdData+Private.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/4/17.
//

#import "ADRFMediationAdapterNativeAdData.h"

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationAdapterNativeAdData ()

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

- (instancetype)initWithTitle:(NSString *)title
                      content:(NSString *)content
          imageUrlStringArray:(NSArray<NSString *> *)imageUrlStringArray
                    iconImage:(nullable UIImage *)iconImage
                 iconImageUrl:(nullable NSString *)iconImageUrl
          shouldShowMediaView:(BOOL)shouldShowMediaView;

@end

NS_ASSUME_NONNULL_END
