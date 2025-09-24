#
# Be sure to run `pod lib lint ADRFMediationSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'InnoMediationSDKPub'
  s.version          = '4.0.1.06134'
  s.summary          = 'A mediation SDK for integrating multiple ad networks on iOS. '
  s.description      = 'A mediation SDK for integrating multiple ad networks on iOS. integrat gdt,badu,ks,gromore,ranfeng'
  s.homepage         = 'https://github.com/RanfengPub/adrfmediation-sdk-ios-pod-masterPub'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.authors          = {"business@ssdmobile.cn"=>"business@ssdmobile.cn"}
  s.source           = { :git => 'https://github.com/RanfengPub/adrfmediation-sdk-ios-pod-masterPub.git', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'

  s.frameworks = 'UIKit'
  

  s.dependency 'ADRFMediationKitPub', '~> 0.7.6.02251'
  s.dependency 'ADRFMediationNetworkPub', '~> 0.2.1.0'
  s.dependency 'ADRFMediationLocationManagerPub','~> 0.2.1.01301'

  
  s.libraries = 'sqlite3', 'resolv'
  
  s.static_framework = true
  s.requires_arc = true


  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'OTHER_LDFLAGS' => '-ObjC'
  }

  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' } 


  s.default_subspecs = 'core'


  s.subspec 'core' do |sp|
    sp.vendored_frameworks = 'InnoMediationSDK/Classes/core/*.xcframework'
  end



  s.subspec 'InnoMediationSDKPlatforms' do |sp|

    sp.subspec 'gdt' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/gdt/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      ssp.dependency 'GDTMobSDK', '4.15.41'
    end

    sp.subspec 'gdt-without' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/gdt/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
    end


    sp.subspec 'baidu' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/baidu/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      ssp.dependency 'BaiduMobAdSDK', '5.394'
    end

    sp.subspec 'baidu-without' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/baidu/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
    end


    sp.subspec 'ks' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/ks/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      ssp.dependency 'KSAdSDK', '4.6.30.1'
    end

    sp.subspec 'ks-without' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/ks/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
    end


    sp.subspec 'tianmu' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/tianmu/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      ssp.dependency 'TianmuSDK', '3.0.1.2'
    end

    sp.subspec 'tianmu-without' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/tianmu/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
    end


    sp.subspec 'InnoAds' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/InnoAds/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      ssp.dependency 'InnoAdsSDKStandard', '3.0.1.2'
    end

    sp.subspec 'InnoAds-without' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/InnoAds/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
    end
    

    sp.subspec 'bu' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/bu/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      ssp.dependency 'Ads-CN/BUAdSDK', '6.9.1.2'
    end


    sp.subspec 'bu-without' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/bu/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
    end


    sp.subspec 'gromore' do |ssp|
      ssp.vendored_frameworks = 'InnoMediationSDK/Classes/gromore/*.xcframework'
      ssp.dependency 'InnoMediationSDKPub/core'
      # ssp.dependency 'Ads-CN-Beta/CSJMediation', '7.0.0.3'
    end

    # sp.subspec 'gromore-without' do |ssp|
    #   ssp.vendored_frameworks = 'InnoMediationSDK/Classes/gromore/*.xcframework'
    #   ssp.dependency 'InnoMediationSDKPub/core'
    # end


  end


end
