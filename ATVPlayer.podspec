Pod::Spec.new do |s|
  s.name = "ATVPlayer"
  s.version = "2.0.4"
  s.summary = "Video Advertising for tvOS"
  s.license = {"text"=>"Copyright 2019 Zensis", "type"=>"Copyright"}
  s.authors = {"Zensis"=>"service@zensis.com"}
  s.homepage = "https://atvplayer.zensis.com"
  s.description = "The tvOS SDK for VAST video ads and SRT subtitles. Monetize your apps on Apple TV."
  s.social_media_url = "https://www.facebook.com/zensis.ltd"
  s.frameworks = ["UIKit", "CoreGraphics"]
  s.libraries = "xml2"
  s.requires_arc = true
  s.xcconfig = {"HEADER_SEARCH_PATHS"=>"$(SDKROOT)/usr/include/libxml2"}
  s.source = { :git => "https://github.com/zensis-ltd/ATVPlayer-cocoapod.git", :tag => s.version.to_s }
  s.tvos.deployment_target    = '10.0'
  s.tvos.vendored_framework   = 'tvos/ATVPlayer.framework'
end
