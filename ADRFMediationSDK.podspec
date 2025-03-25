#
# Be sure to run `pod lib lint ADRFMediationSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ADRFMediationSDK'
  s.version          = '3.9.9.12032'
  s.summary          = 'A short description of ADRFMediationSDK.'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC
  s.homepage         = 'https://github.com/ADRanfeng/adrfmediation-sdk-ios-pod.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.authors = {"business@ssdmobile.cn"=>"business@ssdmobile.cn"}
  s.source           = { :git => 'https://github.com/ADRanfeng/adrfmediation-sdk-ios-pod.git', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'

  s.frameworks = 'UIKit'
  
  s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}

  s.dependency 'ADRFMediationKit', '~> 0.7.4.12031'
  s.dependency 'ADRFMediationNetwork', '~> 0.2.1.0'
  s.dependency 'ADRFMediationLocationManager','~> 0.2.1.01301'
  s.library = 'sqlite3'
  s.static_framework = true
  s.requires_arc = true

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.default_subspecs = 'core'

  s.subspec 'core' do |sp|
    s.vendored_frameworks = 'ADRFMediationSDK/Classes/core/*.xcframework'
  end

  s.subspec 'ADRFMediationSDKPlatforms' do |sp|
    sp.subspec 'gdt' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/gdt/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'GDTMobSDK', '4.15.22'
    end
    sp.subspec 'gdt-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/gdt/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end


    sp.subspec 'baidu' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/baidu/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'BaiduMobAdSDK', '5.373'
    end
    sp.subspec 'baidu-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/baidu/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end


    sp.subspec 'bu' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/bu/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'Ads-CN', '6.5.0.9'
    end
    sp.subspec 'bu-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/bu/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end


    sp.subspec 'ks' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/ks/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'KSAdSDK', '3.3.72'
    end
    sp.subspec 'ks-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/ks/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end


    sp.subspec 'tianmu' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/tianmu/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'TianmuSDK', '2.2.9.2'
    end
    sp.subspec 'tianmu-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/tianmu/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end


    sp.subspec 'ranfeng' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/ranfeng/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'ADRanFengSDK', '2.2.9.2'
    end
    sp.subspec 'ranfeng-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/ranfeng/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end
    
    
    sp.subspec 'gromore' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/gromore/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
      ssp.dependency 'Ads-CN-Beta/CSJMediation', '6.6.0.0'
    end
    sp.subspec 'gromore-without' do |ssp|
      ssp.vendored_frameworks = 'ADRFMediationSDK/Classes/gromore/*.xcframework'
      ssp.dependency 'ADRFMediationSDK/core'
    end

  end
end
