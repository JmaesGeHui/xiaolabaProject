//
//  Utils.m
//  ZLSwipeableViewDemo
//
//  Created by Zhixuan Lai on 10/25/15.
//  Copyright © 2015 Zhixuan Lai. All rights reserved.
//

#import "Utils.h"

CGVector CGVectorFromCGPoint(CGPoint point) { return CGVectorMake(point.x, point.y); }

CGFloat CGPointMagnitude(CGPoint point) { return sqrtf(powf(point.x, 2) + powf(point.y, 2)); }

CGPoint CGPointNormalized(CGPoint point) {
    CGFloat magnitude = CGPointMagnitude(point);
    return CGPointMake(point.x / magnitude, point.y / magnitude);
}

CGPoint CGPointMultiply(CGPoint point, CGFloat factor) {
    return CGPointMake(point.x * factor, point.y * factor);
}

ZLSwipeableViewDirection ZLSwipeableViewDirectionFromVector(CGVector directionVector) {
    ZLSwipeableViewDirection direction = ZLSwipeableViewDirectionNone;
    NSLog(@"滑动的区域%f,%f",directionVector.dx,directionVector.dy);
    if (ABS(directionVector.dx) > ABS(directionVector.dy)) {
        if (directionVector.dx > 0) {
            direction = ZLSwipeableViewDirectionRight;
        } else {
            direction = ZLSwipeableViewDirectionLeft;
        }
    } else {
        if (directionVector.dy > 0) {
            if (directionVector.dx > 0) {
                direction = ZLSwipeableViewDirectionRight;
            }else {
                direction = ZLSwipeableViewDirectionLeft;
            }
        } else {
            if (directionVector.dx > 0) {
                direction = ZLSwipeableViewDirectionRight;
            }else {
                direction = ZLSwipeableViewDirectionLeft;
            }
        }
    }

    return direction;
}

ZLSwipeableViewDirection ZLSwipeableViewDirectionFromPoint(CGPoint point) {
    return ZLSwipeableViewDirectionFromVector(CGVectorFromCGPoint(point));
}

@implementation Utils

@end