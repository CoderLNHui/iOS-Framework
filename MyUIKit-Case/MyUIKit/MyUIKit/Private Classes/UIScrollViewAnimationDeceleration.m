
#import "UIScrollViewAnimationDeceleration.h"

static const CGFloat minimumBounceVelocityBeforeReturning = 100;
static const NSTimeInterval returnAnimationDuration = 0.33;
static const NSTimeInterval physicsTimeStep = 1/120.;
static const CGFloat springTightness = 7;
static const CGFloat springDampening = 15;

static CGFloat Clamp(CGFloat v, CGFloat min, CGFloat max)
{
    return (v < min)? min : (v > max)? max : v;
}

static CGFloat ClampedVelocty(CGFloat v)
{
    const CGFloat V = 200;
    return Clamp(v, -V, V);
}

static CGFloat Spring(CGFloat velocity, CGFloat position, CGFloat restPosition, CGFloat tightness, CGFloat dampening)
{
    const CGFloat d = position - restPosition;
    return (-tightness * d) - (dampening * velocity);
}

static BOOL BounceComponent(NSTimeInterval t, UIScrollViewAnimationDecelerationComponent *c, CGFloat to)
{
    if (c->bounced && c->returnTime != 0) {
        const NSTimeInterval returnBounceTime = MIN(1, ((t - c->returnTime) / returnAnimationDuration));
        c->position = UIQuadraticEaseOut(returnBounceTime, c->returnFrom, to);
        return (returnBounceTime == 1);
    } else if (fabs(to - c->position) > 0) {
        const CGFloat F = Spring(c->velocity, c->position, to, springTightness, springDampening);
        
        c->velocity += F * physicsTimeStep;
        c->position += c->velocity * physicsTimeStep;

        c->bounced = YES;

        if (fabsf(c->velocity) < minimumBounceVelocityBeforeReturning) {
            c->returnFrom = c->position;
            c->returnTime = t;
        }
        
        return NO;
    } else {
        return YES;
    }
}

@implementation UIScrollViewAnimationDeceleration {
    UIScrollViewAnimationDecelerationComponent _x;
    UIScrollViewAnimationDecelerationComponent _y;
    NSTimeInterval _lastMomentumTime;
}

- (id)initWithScrollView:(UIScrollView *)sv velocity:(CGPoint)v;
{
    if ((self=[super initWithScrollView:sv])) {
        _lastMomentumTime = self.beginTime;

        _x.decelerateTime = self.beginTime;
        _x.velocity = ClampedVelocty(v.x);
        _x.position = self.scrollView.contentOffset.x;
        _x.returnFrom = 0;
        _x.returnTime = 0;
        _x.bounced = NO;

        _y.decelerateTime = self.beginTime;
        _y.velocity = ClampedVelocty(v.y);
        _y.position = self.scrollView.contentOffset.y;
        _y.returnFrom = 0;
        _y.returnTime = 0;
        _y.bounced = NO;

        if (_x.velocity == 0) {
            _x.bounced = YES;
            _x.returnTime = self.beginTime;
            _x.returnFrom = _x.position;
        }
        
        if (_y.velocity == 0) {
            _y.bounced = YES;
            _y.returnTime = self.beginTime;
            _y.returnFrom = _y.position;
        }
    }
    return self;
}

- (BOOL)animate
{
    const NSTimeInterval currentTime = [NSDate timeIntervalSinceReferenceDate];
    const BOOL isFinishedWaitingForMomentumScroll = ((currentTime - _lastMomentumTime) > 0.15f);

    BOOL finished = NO;

    while (!finished && currentTime >= self.beginTime) {
        CGPoint confinedOffset = [self.scrollView _confinedContentOffset:CGPointMake(_x.position, _y.position)];
        
        const BOOL verticalIsFinished   = BounceComponent(self.beginTime, &_y, confinedOffset.y);
        const BOOL horizontalIsFinished = BounceComponent(self.beginTime, &_x, confinedOffset.x);
        
        finished = (verticalIsFinished && horizontalIsFinished && isFinishedWaitingForMomentumScroll);

        self.beginTime += physicsTimeStep;
    }

    [self.scrollView _setRestrainedContentOffset:CGPointMake(_x.position, _y.position)];
    
    return finished;
}

@end
