//
//  ATVMediaItem.h
//  ATVPlayer SDK
//
//  Created by Zensis on 29/7/2016.
//  Copyright © 2016 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * An object for setting video metadata.
 */
@interface ATVMediaItem : NSObject

/**
 * Video Url
 */
@property (strong,nonatomic) NSURL *mediaUrl;

/**
 * Video title, will be displayed in "Info"
 */
@property (copy,nonatomic) NSString *videoTitle;

/**
 * Video description, will be displayed in "Info"
 */
@property (copy,nonatomic) NSString *videoDescription;

/**
 * Video thumbnail in  UIImage, will be displayed in "Info"
 */
@property (strong,nonatomic) UIImage *videoThumbnail;

/**
 * Video thumbnail URL, will be displayed in "Info"
 */
@property (strong,nonatomic) NSString *videoThumbnailUrl;

/**
 *Factory method that creates ATVMediaItem object with url .
 *@param url URL of the video.
 */
+ (ATVMediaItem*) itemWithUrl:(NSURL *)url;

@end
