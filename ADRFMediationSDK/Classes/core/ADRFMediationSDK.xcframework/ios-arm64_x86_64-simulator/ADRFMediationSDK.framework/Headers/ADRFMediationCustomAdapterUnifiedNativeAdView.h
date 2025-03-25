//
//  ADRFMediationCustomAdapterUnidiedNativeAdView.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/9/7.
//

#import <UIKit/UIKit.h>
#import <ADRFMediationSDK/ADRFMediationAdapterNativeAdData.h>
NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterUnifiedNativeAdView : UIView<ADRFMediationAdapterNativeAdViewDelegate>

- (ADRFMediationAdapterNativeAdData *)getNativeDataWithTitle:(NSString *)title
                                              content:(NSString *)content
                                            imageUrlStringArray:(NSArray<NSString *> *)imageUrlStringArray
                                            iconImage:(nullable UIImage *)iconImage
                                         iconImageUrl:(nullable NSString *)iconImageUrl
                                  shouldShowMediaView:(BOOL)shouldShowMediaView;

@end

NS_ASSUME_NONNULL_END
