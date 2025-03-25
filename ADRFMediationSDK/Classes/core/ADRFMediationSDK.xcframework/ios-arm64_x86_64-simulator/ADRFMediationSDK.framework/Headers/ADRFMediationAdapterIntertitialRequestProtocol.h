//
//  ADRFMediationAdapterIntertitialRequestProtocol.h
//  ADRFMediationSDK
//
//  Created by 陶冶明 on 2020/4/10.
//

#import <UIKit/UIKit.h>
#import <ADRFMediationSDK/ADRFMediationSDKSourceBiddingResult.h>
@class ADRFMediationAdapterInterstitialAdapter;

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationAdapterIntertitialRequestProtocol <NSObject>

- (void)loadIntertitialAd:(ADRFMediationAdapterInterstitialAdapter *)adapter;

- (void)showFromRootViewController:(UIViewController *)viewController;

@optional
/// 询价请求
- (void)biddingRequestWithAdapter:(ADRFMediationAdapterInterstitialAdapter *)adapter;
/// 竞价结果
- (void)biddingResult:(ADRFMediationSDKSourceBiddingResult)result
              Adapter:(ADRFMediationAdapterInterstitialAdapter *)adapter
             AllPrice:(NSArray *)allPrices;;

@end

NS_ASSUME_NONNULL_END
