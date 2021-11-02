Pod::Spec.new do |s|
  s.name = "BoomMeeting"
  s.version = "1.0.0.2"
  s.summary = "BoomMeeting SDK."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"zhaozhidan"=>"mybadge@163.com"}
  s.homepage = "https://git.baijiashilian.com/LLL/frondend/boommeeting"
  s.description = "BoomMeeting to create a meeting"
  s.frameworks = ["UIKit", "Foundation", "CoreFoundation", "UserNotifications", "CoreGraphics"]
  s.libraries = ["c", "sqlite3", "stdc++", "resolv", "sqlite3.0", "xml2", "bz", "bz.1.2.5"]
  s.xcconfig = {"CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES"=>"YES", "ENABLE_BITCODE"=>"NO", "GCC_PREPROCESSOR_DEFINITIONS"=>"$(inherited) PODSPEC_NAME=\#{s.name} PODSPEC_VERSION=\#{s.version}", "OTHER_LDFLAGS"=>"-framework BoomCore"}
  s.source = { :git => "https://github.com/lutaohua/BoomMeeting.git", :tag => s.version }
  
  s.dependency 'MJRefresh', '~> 3.5.0'
  s.dependency 'BoomCore', '1.0.1.1'
  s.dependency 'Vloud', '0.4.0'
  s.dependency 'BJLiveBase', '~> 2.10.2'
  s.dependency 'BJLiveBase/Networking', '~> 2.10.2'
  s.dependency 'BJLiveBase/WebImage/AFNetworking', '~> 2.10.2'
  s.dependency 'BJLiveBase/YYModel', '~> 2.10.2'
  s.dependency 'BJLiveBase/HUD', '~> 2.10.2'
  
  s.ios.deployment_target    = '10.0'
  s.ios.vendored_framework   = 'ios/BoomMeeting.framework'
end
