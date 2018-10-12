/*
 * CGContext.h
 *
 * CoreGraphics (c) 2000-2012
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#ifndef CGCONTEXT_H_
#define CGCONTEXT_H_

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <stdint.h>

typedef struct CF_BRIDGED_TYPE(id) CGContext *CGContextRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGAffineTransform.h>
#include <CoreGraphics/CGColor.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGFont.h>
#include <CoreGraphics/CGGradient.h>
#include <CoreGraphics/CGImage.h>
#include <CoreGraphics/CGPath.h>
#include <CoreGraphics/CGPattern.h>
#include <CoreGraphics/CGPDFDocument.h>
#include <CoreGraphics/CGShading.h>

CF_IMPLICIT_BRIDGING_ENABLED

CF_ASSUME_NONNULL_BEGIN

/* Drawing modes for paths. */

typedef CF_ENUM (int32_t, CGPathDrawingMode) {
    kCGPathFill,
    kCGPathEOFill,
    kCGPathStroke,
    kCGPathFillStroke,
    kCGPathEOFillStroke
};

/* Drawing modes for text. */

typedef CF_ENUM (int32_t, CGTextDrawingMode) {
    kCGTextFill,
    kCGTextStroke,
    kCGTextFillStroke,
    kCGTextInvisible,
    kCGTextFillClip,
    kCGTextStrokeClip,
    kCGTextFillStrokeClip,
    kCGTextClip
};

/* Text encodings. */

typedef CF_ENUM (int32_t, CGTextEncoding) {
    kCGEncodingFontSpecific,
    kCGEncodingMacRoman
} CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_9, __IPHONE_2_0, __IPHONE_7_0);

/* Interpolation quality. */

typedef CF_ENUM (int32_t, CGInterpolationQuality) {
    kCGInterpolationDefault = 0,  /* Let the context decide. */
    kCGInterpolationNone = 1,     /* Never interpolate. */
    kCGInterpolationLow = 2,      /* Low quality, fast interpolation. */
    kCGInterpolationMedium = 4,   /* Medium quality, slower than kCGInterpolationLow. */
    kCGInterpolationHigh = 3      /* Highest quality, slower than kCGInterpolationMedium. */
};

/* Blend modes.
 
 The blend modes from kCGBlendModeNormal to kCGBlendModeLuminosity are
 supported in Mac OS X 10.4 and later. The Porter-Duff blend modes (from
 kCGBlendModeClear to kCGBlendModePlusLighter) are supported in Mac OS X
 10.5 and later. The names of the Porter-Duff blend modes are historical.
 
 Note that the Porter-Duff blend modes are not necessarily supported in
 every context. In particular, they are only guaranteed to work in
 bitmap-based contexts, such as those created by CGBitmapContextCreate. It
 is your responsibility to make sure that they do what you want when you
 use them in a CGContext. */

typedef CF_ENUM (int32_t, CGBlendMode) {
    /* Available in Mac OS X 10.4 & later. */
    kCGBlendModeNormal,
    kCGBlendModeMultiply,
    kCGBlendModeScreen,
    kCGBlendModeOverlay,
    kCGBlendModeDarken,
    kCGBlendModeLighten,
    kCGBlendModeColorDodge,
    kCGBlendModeColorBurn,
    kCGBlendModeSoftLight,
    kCGBlendModeHardLight,
    kCGBlendModeDifference,
    kCGBlendModeExclusion,
    kCGBlendModeHue,
    kCGBlendModeSaturation,
    kCGBlendModeColor,
    kCGBlendModeLuminosity,
    
    /* Available in Mac OS X 10.5 & later. R, S, and D are, respectively,
     premultiplied result, source, and destination colors with alpha; Ra,
     Sa, and Da are the alpha components of these colors.
     
     The Porter-Duff "source over" mode is called `kCGBlendModeNormal':
     R = S + D*(1 - Sa)
     
     Note that the Porter-Duff "XOR" mode is only titularly related to the
     classical bitmap XOR operation (which is unsupported by
     CoreGraphics). */
    
    kCGBlendModeClear,                  /* R = 0 */
    kCGBlendModeCopy,                   /* R = S */
    kCGBlendModeSourceIn,               /* R = S*Da */
    kCGBlendModeSourceOut,              /* R = S*(1 - Da) */
    kCGBlendModeSourceAtop,             /* R = S*Da + D*(1 - Sa) */
    kCGBlendModeDestinationOver,        /* R = S*(1 - Da) + D */
    kCGBlendModeDestinationIn,          /* R = D*Sa */
    kCGBlendModeDestinationOut,         /* R = D*(1 - Sa) */
    kCGBlendModeDestinationAtop,        /* R = S*(1 - Da) + D*Sa */
    kCGBlendModeXOR,                    /* R = S*(1 - Da) + D*(1 - Sa) */
    kCGBlendModePlusDarker,             /* R = MAX(0, (1 - D) + (1 - S)) */
    kCGBlendModePlusLighter             /* R = MIN(1, S + D) */
};

/* Return the CFTypeID for CGContextRefs. */

CG_EXTERN CFTypeID CGContextGetTypeID(void)
CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/** Graphics state functions. **/

/* Push a copy of the current graphics state onto the graphics state stack.
 Note that the path is not considered part of the graphics state, and is
 not saved. */
#pragma mark - 上下文的状态栈
#pragma mark -压栈操作，保存一份当前图形上下文
/**
 函数的作用是将当前图形状态推入堆栈。之后，您对图形状态所做的修改会影响随后的描画操作，但不影响存储在堆栈中的拷贝。在修改完成后，您可以通过CGContextRestoreGState函数把堆栈顶部的状态弹出，返回到之前的图形状态。这种推入和弹出的方式是回到之前图形状态的快速方法，避免逐个撤消所有的状态修改；这也是将某些状态（比如裁剪路径）恢复到原有设置的唯一方式。
 */
CG_EXTERN void CGContextSaveGState(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Restore the current graphics state from the one on the top of the
 graphics state stack, popping the graphics state stack in the process. */
#pragma mark -出栈操作，恢复一份当前图形上下文
CG_EXTERN void CGContextRestoreGState(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Coordinate space transformations. **/
#pragma mark - 图形上下文的坐标空间转换
/* Scale the current graphics state's transformation matrix (the CTM) by
 `(sx, sy)'. */
#pragma mark -坐标系X,Y缩放
CG_EXTERN void CGContextScaleCTM(CGContextRef cg_nullable c,
                                 CGFloat sx, CGFloat sy)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Translate the current graphics state's transformation matrix (the CTM) by
 `(tx, ty)'. */
#pragma mark -坐标系平移
CG_EXTERN void CGContextTranslateCTM(CGContextRef cg_nullable c,
                                     CGFloat tx, CGFloat ty)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Rotate the current graphics state's transformation matrix (the CTM) by
 `angle' radians. */
#pragma mark -坐标系旋转
CG_EXTERN void CGContextRotateCTM(CGContextRef cg_nullable c, CGFloat angle)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Concatenate the current graphics state's transformation matrix (the CTM)
 with the affine transform `transform'. */
#pragma mark -
CG_EXTERN void CGContextConcatCTM(CGContextRef cg_nullable c,
                                  CGAffineTransform transform)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the current graphics state's transformation matrix. Returns
 CGAffineTransformIdentity in case of inavlid context. */
#pragma mark -获得一份CTM
CG_EXTERN CGAffineTransform CGContextGetCTM(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Drawing attribute functions. **/
#pragma mark - 设置Line属性及连接样式
/* Set the line width in the current graphics state to `width'. */
#pragma mark -设置线宽度
CG_EXTERN void CGContextSetLineWidth(CGContextRef cg_nullable c, CGFloat width)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the line cap in the current graphics state to `cap'. */
#pragma mark -设置顶角样式（kCGLineCapButt, Round, Square）
CG_EXTERN void CGContextSetLineCap(CGContextRef cg_nullable c, CGLineCap cap)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the line join in the current graphics state to `join'. */
#pragma mark -设置连接样式（kCGLineJoinMiter尖的、斜接, Round圆, Bevel斜面）
CG_EXTERN void CGContextSetLineJoin(CGContextRef cg_nullable c, CGLineJoin join)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the miter limit in the current graphics state to `limit'. */
#pragma mark -斜接限制
CG_EXTERN void CGContextSetMiterLimit(CGContextRef cg_nullable c, CGFloat limit)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the line dash patttern in the current graphics state of `c'. */
#pragma mark -设置虚线样式
/**
 参数：phase虚线从那开始绘制；lengths C语言的数组,举个例子: 声明一个数组 CGFloat dash[] = @{3.0, 1.0}意思就是长度为3.0 间隙长度为1.0,以此类推；count lengths数组的个数
 */
CG_EXTERN void CGContextSetLineDash(CGContextRef cg_nullable c, CGFloat phase,
                                    const CGFloat * __nullable lengths, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the path flatness parameter in the current graphics state of `c' to
 `flatness'. */

CG_EXTERN void CGContextSetFlatness(CGContextRef cg_nullable c, CGFloat flatness)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the alpha value in the current graphics state of `c' to `alpha'. */
#pragma mark -设置透明度
CG_EXTERN void CGContextSetAlpha(CGContextRef cg_nullable c, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the blend mode of `context' to `mode'. */

CG_EXTERN void CGContextSetBlendMode(CGContextRef cg_nullable c, CGBlendMode mode)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Path construction functions. **/
#pragma mark - path路径构建功能
/* Note that a context has a single path in use at any time: a path is not
 part of the graphics state. */

/* Begin a new path. The old path is discarded. */

CG_EXTERN void CGContextBeginPath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Start a new subpath at point `(x, y)' in the context's path. */
#pragma mark -设置起始点
CG_EXTERN void CGContextMoveToPoint(CGContextRef cg_nullable c,
                                    CGFloat x, CGFloat y)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Append a straight line segment from the current point to `(x, y)'. */
#pragma mark -添加一根线到终点
CG_EXTERN void CGContextAddLineToPoint(CGContextRef cg_nullable c,
                                       CGFloat x, CGFloat y)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Append a cubic Bezier curve from the current point to `(x,y)', with
 control points `(cp1x, cp1y)' and `(cp2x, cp2y)'. */
#pragma mark -三次曲线函数 参数：控制点1 x y坐标，控制点2 x y坐标，终点 x坐标，终点 y坐标 Note:这里使用必须要设置起点MoveToPoin
CG_EXTERN void CGContextAddCurveToPoint(CGContextRef cg_nullable c, CGFloat cp1x,
                                        CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Append a quadratic curve from the current point to `(x, y)', with control
 point `(cpx, cpy)'. */
#pragma mark -二次曲线函数 参数：控制点 x坐标，控制点 y坐标，终点 x坐标，终点 y坐标 Note:这里使用必须要设置起点MoveToPoin
CG_EXTERN void CGContextAddQuadCurveToPoint(CGContextRef cg_nullable c,
                                            CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Close the current subpath of the context's path. */
#pragma mark -闭合曲线
CG_EXTERN void CGContextClosePath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Path construction convenience functions. **/

/* Add a single rect to the context's path. */
#pragma mark -画矩形，长宽相等就是正方形
CG_EXTERN void CGContextAddRect(CGContextRef cg_nullable c, CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add a set of rects to the context's path. */

CG_EXTERN void CGContextAddRects(CGContextRef cg_nullable c,
                                 const CGRect * __nullable rects, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add a set of lines to the context's path. */
#pragma mark -添加线(点之间) 参数：points点数组，count数组个数
CG_EXTERN void CGContextAddLines(CGContextRef cg_nullable c,
                                 const CGPoint * __nullable points, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add an ellipse inside `rect' to the current path of `context'. See the
 function `CGPathAddEllipseInRect' for more information on how the path
 for the ellipse is constructed. */
#pragma mark -画椭圆，如果长宽相等就是圆
CG_EXTERN void CGContextAddEllipseInRect(CGContextRef cg_nullable c, CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Add an arc of a circle to the context's path, possibly preceded by a
 straight line segment. `(x, y)' is the center of the arc; `radius' is its
 radius; `startAngle' is the angle to the first endpoint of the arc;
 `endAngle' is the angle to the second endpoint of the arc; and
 `clockwise' is 1 if the arc is to be drawn clockwise, 0 otherwise.
 `startAngle' and `endAngle' are measured in radians. */
#pragma mark -画圆
// 参数：圆心的x坐标，圆心的y坐标，圆的半径，开始弧度，结束弧度，0表示顺时针 1表示逆时针
CG_EXTERN void CGContextAddArc(CGContextRef cg_nullable c, CGFloat x, CGFloat y,
                               CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add an arc of a circle to the context's path, possibly preceded by a
 straight line segment. `radius' is the radius of the arc. The arc is
 tangent to the line from the current point to `(x1, y1)', and the line
 from `(x1, y1)' to `(x2, y2)'. */
#pragma mark -弧度：控制点p1和p2是弧线的控制点
CG_EXTERN void CGContextAddArcToPoint(CGContextRef cg_nullable c,
                                      CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add `path' to the path of context. The points in `path' are transformed
 by the CTM of context before they are added. */
#pragma mark -添加路径到上下文（UIBezierPath:UIKit框架 ,CGPathRef:CoreGraphics框架）
CG_EXTERN void CGContextAddPath(CGContextRef cg_nullable c,
                                CGPathRef cg_nullable path)
CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/** Path stroking. **/
#pragma mark - 获取路径信息
/* Replace the path in `context' with the stroked version of the path, using
 the parameters of `context' to calculate the stroked path. The resulting
 path is created such that filling it with the appropriate color will
 produce the same results as stroking the original path. You can use this
 path in the same way you can use the path of any context; for example,
 you can clip to the stroked version of a path by calling this function
 followed by a call to "CGContextClip". */

CG_EXTERN void CGContextReplacePathWithStrokedPath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Path information functions. **/

/* Return true if the path of `context' contains no elements, false
 otherwise. */
#pragma mark -表示目前的图形上下文是否包含任何的子路径。
CG_EXTERN bool CGContextIsPathEmpty(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the current point of the current subpath of the path of
 `context'. */
#pragma mark -返回一个非空的路径中的当前点。
CG_EXTERN CGPoint CGContextGetPathCurrentPoint(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the bounding box of the path of `context'. The bounding box is the
 smallest rectangle completely enclosing all points in the path, including
 control points for Bezier and quadratic curves. */
#pragma mark -返回包含当前路径的最小矩形。
CG_EXTERN CGRect CGContextGetPathBoundingBox(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return a copy of the path of `context'. The returned path is specified in
 the current user space of `context'. */

CG_EXTERN CGPathRef __nullable CGContextCopyPath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* Return true if `point' is contained in the current path of `context'. A
 point is contained within a context's path if it is inside the painted
 region when the path is stroked or filled with opaque colors using the
 path drawing mode `mode'. `point' is specified is user space. */
#pragma mark -检查当前路径中是否包含指定的点。
CG_EXTERN bool CGContextPathContainsPoint(CGContextRef cg_nullable c,
                                          CGPoint point, CGPathDrawingMode mode)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Path drawing functions. **/
#pragma mark - 路径绘图功能

/* Draw the context's path using drawing mode `mode'. */
#pragma mark -指定模式下渲染路径
CG_EXTERN void CGContextDrawPath(CGContextRef cg_nullable c,
                                 CGPathDrawingMode mode)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
/*CGPathDrawingMode是填充方式,枚举类型
 kCGPathFill:只有填充（非零缠绕数填充），不绘制边框
 kCGPathEOFill:奇偶规则填充（多条路径交叉时，奇数交叉填充，偶交叉不填充）
 kCGPathStroke:只有边框
 kCGPathFillStroke：既有边框又有填充
 kCGPathEOFillStroke：奇偶填充并绘制边框
 */

/** Path drawing convenience functions. **/

/* Fill the context's path using the winding-number fill rule. Any open
 subpath of the path is implicitly closed. */
#pragma mark -渲染上下文（Fill填充,实心）
CG_EXTERN void CGContextFillPath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill the context's path using the even-odd fill rule. Any open subpath of
 the path is implicitly closed. */
#pragma mark -奇偶填充
CG_EXTERN void CGContextEOFillPath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Stroke the context's path. */
#pragma mark -渲染上下文（Stroke描边,空心）
CG_EXTERN void CGContextStrokePath(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill `rect' with the current fill color. */
#pragma mark -填充区域
CG_EXTERN void CGContextFillRect(CGContextRef cg_nullable c, CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill `rects', an array of `count' CGRects, with the current fill
 color. */

CG_EXTERN void CGContextFillRects(CGContextRef cg_nullable c,
                                  const CGRect * __nullable rects, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Stroke `rect' with the current stroke color and the current linewidth. */

CG_EXTERN void CGContextStrokeRect(CGContextRef cg_nullable c, CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Stroke `rect' with the current stroke color, using `width' as the the
 line width. */

CG_EXTERN void CGContextStrokeRectWithWidth(CGContextRef cg_nullable c,
                                            CGRect rect, CGFloat width)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Clear `rect' (that is, set the region within the rect to transparent). */
#pragma mark -设置擦除上下文区域
CG_EXTERN void CGContextClearRect(CGContextRef cg_nullable c, CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill an ellipse (an oval) inside `rect'. */

CG_EXTERN void CGContextFillEllipseInRect(CGContextRef cg_nullable c,
                                          CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Stroke an ellipse (an oval) inside `rect'. */

CG_EXTERN void CGContextStrokeEllipseInRect(CGContextRef cg_nullable c,
                                            CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Stroke a sequence of line segments one after another in `context'. The
 line segments are specified by `points', an array of `count' CGPoints.
 This function is equivalent to
 
 CGContextBeginPath(context);
 for (k = 0; k < count; k += 2) {
 CGContextMoveToPoint(context, s[k].x, s[k].y);
 CGContextAddLineToPoint(context, s[k+1].x, s[k+1].y);
 }
 CGContextStrokePath(context); */

CG_EXTERN void CGContextStrokeLineSegments(CGContextRef cg_nullable c,
                                           const CGPoint * __nullable points, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Clipping functions. **/
#pragma mark - 修改剪裁路径

/* Intersect the context's path with the current clip path and use the
 resulting path as the clip path for subsequent rendering operations. Use
 the winding-number fill rule for deciding what's inside the path. */

CG_EXTERN void CGContextClip(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Intersect the context's path with the current clip path and use the
 resulting path as the clip path for subsequent rendering operations. Use
 the even-odd fill rule for deciding what's inside the path. */

CG_EXTERN void CGContextEOClip(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Reset the current clip of `c' to the default value. */

CG_EXTERN void CGContextResetClip(CGContextRef c);

/* Add `mask' transformed to `rect' to the clipping area of `context'. The
 mask, which may be either an image mask or an image, is mapped into the
 specified rectangle and intersected with the current clipping area of the
 context.
 
 If `mask' is an image mask, then it clips in a manner identical to the
 behavior if it were used with "CGContextDrawImage": it indicates an area
 to be masked out (left unchanged) when drawing. The source samples of the
 image mask determine which points of the clipping area are changed,
 acting as an "inverse alpha": if the value of a source sample in the
 image mask is S, then the corresponding point in the current clipping
 area will be multiplied by an alpha of (1-S). (For example, if S is 1,
 then the point in the clipping area becomes clear, while if S is 0, the
 point in the clipping area is unchanged.
 
 If `mask' is an image, then it serves as alpha mask and is blended with
 the current clipping area. The source samples of mask determine which
 points of the clipping area are changed: if the value of the source
 sample in mask is S, then the corresponding point in the current clipping
 area will be multiplied by an alpha of S. (For example, if S is 0, then
 the point in the clipping area becomes clear, while if S is 1, the point
 in the clipping area is unchanged.
 
 If `mask' is an image, then it must be in the DeviceGray color space, may
 not have alpha, and may not be masked by an image mask or masking
 color. */

CG_EXTERN void CGContextClipToMask(CGContextRef cg_nullable c, CGRect rect,
                                   CGImageRef cg_nullable mask)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Return the bounding box of the clip path of `c' in user space. The
 bounding box is the smallest rectangle completely enclosing all points in
 the clip. */

CG_EXTERN CGRect CGContextGetClipBoundingBox(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Clipping convenience functions. **/

/* Intersect the current clipping path with `rect'. Note that this function
 resets the context's path to the empty path. */

CG_EXTERN void CGContextClipToRect(CGContextRef cg_nullable c, CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Intersect the current clipping path with the clipping region formed by
 creating a path consisting of all rects in `rects'. Note that this
 function resets the context's path to the empty path. */

CG_EXTERN void CGContextClipToRects(CGContextRef cg_nullable c,
                                    const CGRect *  rects, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Primitive color functions. **/
#pragma mark - 设置颜色、色彩空间及阴影值
/**
 Quartz 中的颜色是用一组数值来表示。而颜色空间用于解析这些颜色信息，常用颜色空间有 RGB 、CMYK等。
 
 Quartz 支持通用颜色空间、设备独立颜色空间、设备依赖颜色空间、索引颜色空间和模式（Pattern）颜色空间。
 
 iOS不支持设备独立颜色空间和通用颜色空间。iOS应用程序必须使用设备颜色空间。
 */

/* Set the current fill color in the context `c' to `color'. */
#pragma mark -设置填充颜色
CG_EXTERN void CGContextSetFillColorWithColor(CGContextRef cg_nullable c,
                                              CGColorRef cg_nullable color)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/* Set the current stroke color in the context `c' to `color'. */
#pragma mark -设置描边颜色
CG_EXTERN void CGContextSetStrokeColorWithColor(CGContextRef cg_nullable c,
                                                CGColorRef cg_nullable color)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Color space functions. **/
#pragma mark - 创建设备依赖颜色空间
/* Set the current fill color space in `context' to `space'. As a
 side-effect, set the fill color to a default value appropriate for the
 color space. */

CG_EXTERN void CGContextSetFillColorSpace(CGContextRef cg_nullable c,
                                          CGColorSpaceRef cg_nullable space)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `space'. As a
 side-effect, set the stroke color to a default value appropriate for the
 color space. */

CG_EXTERN void CGContextSetStrokeColorSpace(CGContextRef cg_nullable c,
                                            CGColorSpaceRef cg_nullable space)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Color functions. **/

/* Set the components of the current fill color in `context' to the values
 specifed by `components'. The number of elements in `components' must be
 one greater than the number of components in the current fill color space
 (N color components + 1 alpha component). The current fill color space
 must not be a pattern color space. */

CG_EXTERN void CGContextSetFillColor(CGContextRef cg_nullable c,
                                     const CGFloat * cg_nullable components)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the components of the current stroke color in `context' to the values
 specifed by `components'. The number of elements in `components' must be
 one greater than the number of components in the current stroke color
 space (N color components + 1 alpha component). The current stroke color
 space must not be a pattern color space. */

CG_EXTERN void CGContextSetStrokeColor(CGContextRef cg_nullable c,
                                       const CGFloat * cg_nullable components)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Pattern functions. **/

/* Set the components of the current fill color in `context' to the values
 specifed by `components', and set the current fill pattern to `pattern'.
 The number of elements in `components' must be one greater than the
 number of components in the current fill color space (N color components
 + 1 alpha component). The current fill color space must be a pattern
 color space. */

CG_EXTERN void CGContextSetFillPattern(CGContextRef cg_nullable c,
                                       CGPatternRef cg_nullable pattern, const CGFloat * cg_nullable components)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the components of the current stroke color in `context' to the values
 specifed by `components', and set the current stroke pattern to
 `pattern'. The number of elements in `components' must be one greater
 than the number of components in the current stroke color space (N color
 components + 1 alpha component). The current stroke color space must be a
 pattern color space. */

CG_EXTERN void CGContextSetStrokePattern(CGContextRef cg_nullable c,
                                         CGPatternRef cg_nullable pattern, const CGFloat * cg_nullable components)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the pattern phase in the current graphics state of `context' to
 `phase'. */

CG_EXTERN void CGContextSetPatternPhase(CGContextRef cg_nullable c, CGSize phase)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Color convenience functions. **/

/* Set the current fill color space in `context' to `DeviceGray' and set the
 components of the current fill color to `(gray, alpha)'. */

CG_EXTERN void CGContextSetGrayFillColor(CGContextRef cg_nullable c,
                                         CGFloat gray, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `DeviceGray' and set
 the components of the current stroke color to `(gray, alpha)'. */

CG_EXTERN void CGContextSetGrayStrokeColor(CGContextRef cg_nullable c,
                                           CGFloat gray, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current fill color space in `context' to `DeviceRGB' and set the
 components of the current fill color to `(red, green, blue, alpha)'. */

CG_EXTERN void CGContextSetRGBFillColor(CGContextRef cg_nullable c, CGFloat red,
                                        CGFloat green, CGFloat blue, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `DeviceRGB' and set
 the components of the current stroke color to `(red, green, blue,
 alpha)'. */

CG_EXTERN void CGContextSetRGBStrokeColor(CGContextRef cg_nullable c,
                                          CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current fill color space in `context' to `DeviceCMYK' and set the
 components of the current fill color to `(cyan, magenta, yellow, black,
 alpha)'. */

CG_EXTERN void CGContextSetCMYKFillColor(CGContextRef cg_nullable c,
                                         CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `DeviceCMYK' and set
 the components of the current stroke color to `(cyan, magenta, yellow,
 black, alpha)'. */

CG_EXTERN void CGContextSetCMYKStrokeColor(CGContextRef cg_nullable c,
                                           CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Rendering intent. **/

/* Set the rendering intent in the current graphics state of `context' to
 `intent'. */
#pragma mark -设置再现意图
/**
 每个设备都有固定的可复制的颜色范围（gamut），这是设备的物理性质决定的。当图像从一个颜色空间向另一个颜色空间转换时，有些源设备颜色空间中呈现的颜色，不能在目标设备颜色空间中复制出来，这些不能复制的颜色叫色域外（out-of-gamut）颜色。比如 RGB 颜色空间比 CMYK 的颜色空间要大，有些在显示器上能显示的颜色不能在打印机上同样打印出来。因为我们不能在目标设备颜色空间中复制出色域外颜色，我们必须用一些其他颜色来替代他们。颜色空间转换时颜色替换调整的规则就是再现意图。
 
 再现意图用于指定如何将源颜色空间的颜色映射到图形上下文的目标颜色空间的颜色范围内。
 如果不显式的指定再现意图，Quartz 使用“相对色度再现意图”应用于所有绘制（不包含位图图像）。
 对于位图图像，Quartz默认使用“感知再现意图”。
 调用 CGContextSetRenderingIntent(context, kCGRenderingIntentDefault) 来设置再现意图。
 */
CG_EXTERN void CGContextSetRenderingIntent(CGContextRef cg_nullable c,
                                           CGColorRenderingIntent intent)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
/**
 typedef CF_ENUM (int32_t, CGColorRenderingIntent) {
    kCGRenderingIntentDefault,
    kCGRenderingIntentAbsoluteColorimetric,
    kCGRenderingIntentRelativeColorimetric,
    kCGRenderingIntentPerceptual,
    kCGRenderingIntentSaturation
 };
 
 1. kCGRenderingIntentDefault：默认再现意图。
 2. kCGRenderingIntentAbsoluteColorimetric：绝对色度再现意图。将输出设备颜色域外的颜色映射为输出设备域内与之最接近的颜色。这可以产生一个裁减效果，因为色域外的两个不同的颜色值可能被映射为色域内的同一个颜色值。当图形使用的颜色值同时包含在源色域及目标色域内时，这种方法是最好的。常用于logo或者使用专色(spot color)时。
 3. kCGRenderingIntentRelativeColorimetric：相对色度再现意图。转换所有的颜色(包括色域内的)，以补偿图形上下文的白点与输出设备白点之间的色差。
 4. kCGRenderingIntentPerceptual：感知再现意图。通过压缩图形上下文的色域来适应输出设备的色域，并保持源颜色空间的颜色之间的相对性。感知渲染意图适用于相片及其它复杂的高细度图片。
 5. kCGRenderingIntentSaturation：饱和度再现意图。把颜色转换到输出设备色域内时，保持颜色的相对饱和度。结果是包含亮度、饱和度颜色的图片。饱和度意图适用于生成低细度的图片，如描述性图表。
 */

/** Image functions. **/
#pragma mark - 绘制图片
/* Draw `image' in the rectangular area specified by `rect' in the context
 `c'. The image is scaled, if necessary, to fit into `rect'. */
#pragma mark -在指定区域画图片
CG_EXTERN void CGContextDrawImage(CGContextRef cg_nullable c, CGRect rect,
                                  CGImageRef cg_nullable image)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Draw `image' tiled in the context `c'. The image is scaled to the size
 specified by `rect' in user space, positioned at the origin of `rect' in
 user space, then replicated, stepping the width of `rect' horizontally
 and the height of `rect' vertically, to fill the current clip region.
 Unlike patterns, the image is tiled in user space, so transformations
 applied to the CTM affect the final result. */

CG_EXTERN void CGContextDrawTiledImage(CGContextRef cg_nullable c, CGRect rect,
                                       CGImageRef cg_nullable image)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Return the interpolation quality for image rendering of `context'. The
 interpolation quality is a gstate parameter which controls the level of
 interpolation performed when an image is interpolated (for example, when
 scaling the image). Note that it is merely a hint to the context: not all
 contexts support all interpolation quality levels. */

CG_EXTERN CGInterpolationQuality
/**
 返回当前的图形上下文的插值（插值(Interpolation)是在不天生像素的环境下增长图像像素大小的一种方法,在周围像素色彩
 的根蒂根基上用算术公式计算亡失像素的色彩。）质量水平
 */
CGContextGetInterpolationQuality(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the interpolation quality of `context' to `quality'. */
#pragma mark -设置图形上下文的插值质量水平。
CG_EXTERN void CGContextSetInterpolationQuality(CGContextRef cg_nullable c,
                                                CGInterpolationQuality quality)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Shadow support. **/
#pragma mark - 设置阴影

/* Set the shadow parameters in `context'. `offset' specifies a translation
 in base-space; `blur' is a non-negative number specifying the amount of
 blur; `color' specifies the color of the shadow, which may contain a
 non-opaque alpha value. If `color' is NULL, it's equivalent to specifying
 a fully transparent color. The shadow is a gstate parameter. After a
 shadow is specified, all objects drawn subsequently will be shadowed. To
 turn off shadowing, set the shadow color to a fully transparent color (or
 pass NULL as the color), or use the standard gsave/grestore mechanism.
 
 阴影是如何工作的
 Quartz中的阴影是图形状态的一部分。我们可以调用函数CGContextSetShadow来创建，并传入一个图形上下文、偏移值及模糊值。阴影被设置后，任何绘制的对象都有一个阴影，且该阴影在设备RGB颜色空间中呈现出黑色的且alpha值为1/3。换句话说，阴影是用RGBA值{0, 0, 0, 1.0/3.0}设置的。
 我们可以调用函数CGContextSetShadowWithColor来设置彩色阴影，并传递一个图形上下文、 偏移值、模糊值有CGColor颜色对象。颜色值依赖于颜色空间。
 如何在调用CGContextSetShadow或CGContextSetShadowWithColor之前保存了图形状态，我们可以通过恢复图形状态来关闭阴影。我们也可以通过设置阴影颜色为NULL来关闭阴影
 */

CG_EXTERN void CGContextSetShadowWithColor(CGContextRef cg_nullable c,
                                           CGSize offset, CGFloat blur, CGColorRef __nullable color)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/* Equivalent to calling
 CGContextSetShadowWithColor(context, offset, blur, color)
 where color is black with 1/3 alpha (i.e., RGBA = {0, 0, 0, 1.0/3.0}) in
 the DeviceRGB color space.
 
 阴影有三个属性：
 x偏移值，用于指定阴影相对于图片在水平方向上的偏移值。
 y偏移值，用于指定阴影相对于图片在竖直方向上的偏移值。
 模糊(blur)值，用于指定图像是有一个硬边
 CGContextSetShadow(context, CGSizeMake(10, -20), 10);
 */
CG_EXTERN void CGContextSetShadow(CGContextRef cg_nullable c, CGSize offset,
                                  CGFloat blur)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Gradient and shading functions. **/
#pragma mark - 渐变和着色功能
/* Fill the current clipping region of `context' with a linear gradient from
 `startPoint' to `endPoint'. The location 0 of `gradient' corresponds to
 `startPoint'; the location 1 of `gradient' corresponds to `endPoint';
 colors are linearly interpolated between these two points based on the
 values of the gradient's locations. The option flags control whether the
 gradient is drawn before the start point or after the end point. */

CG_EXTERN void CGContextDrawLinearGradient(CGContextRef cg_nullable c,
                                           CGGradientRef cg_nullable gradient, CGPoint startPoint, CGPoint endPoint,
                                           CGGradientDrawingOptions options)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Fill the current clipping region of `context' with a radial gradient
 between two circles defined by the center point and radius of each
 circle. The location 0 of `gradient' corresponds to a circle centered at
 `startCenter' with radius `startRadius'; the location 1 of `gradient'
 corresponds to a circle centered at `endCenter' with radius `endRadius';
 colors are linearly interpolated between these two circles based on the
 values of the gradient's locations. The option flags control whether the
 gradient is drawn before the start circle or after the end circle. */

CG_EXTERN void CGContextDrawRadialGradient(CGContextRef cg_nullable c,
                                           CGGradientRef cg_nullable gradient, CGPoint startCenter, CGFloat startRadius,
                                           CGPoint endCenter, CGFloat endRadius, CGGradientDrawingOptions options)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Fill the current clipping region of `context' with `shading'. */

CG_EXTERN void CGContextDrawShading(CGContextRef cg_nullable c,
                                    cg_nullable CGShadingRef shading)
CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/** Text functions. **/
#pragma mark - 绘制文本
/* Set the current character spacing in `context' to `spacing'. The
 character spacing is added to the displacement between the origin of one
 character and the origin of the next. */

CG_EXTERN void CGContextSetCharacterSpacing(CGContextRef cg_nullable c,
                                            CGFloat spacing)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the user-space point at which text will be drawn in the context `c'
 to `(x, y)'. */

CG_EXTERN void CGContextSetTextPosition(CGContextRef cg_nullable c,
                                        CGFloat x, CGFloat y)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the user-space point at which text will be drawn in `context'. */

CG_EXTERN CGPoint CGContextGetTextPosition(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the text matrix in the context `c' to `t'. */

CG_EXTERN void CGContextSetTextMatrix(CGContextRef cg_nullable c,
                                      CGAffineTransform t)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the text matrix in the context `c'. Returns CGAffineTransformIdentity
 if `c' is not a valid context. */

CG_EXTERN CGAffineTransform CGContextGetTextMatrix(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the text drawing mode in the current graphics state of the context
 `c' to `mode'. */

CG_EXTERN void CGContextSetTextDrawingMode(CGContextRef cg_nullable c,
                                           CGTextDrawingMode mode)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the font in the current graphics state of the context `c' to
 `font'. */

CG_EXTERN void CGContextSetFont(CGContextRef cg_nullable c,
                                CGFontRef cg_nullable font)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the font size in the current graphics state of the context `c' to
 `size'. */

CG_EXTERN void CGContextSetFontSize(CGContextRef cg_nullable c, CGFloat size)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Draw `glyphs', an array of `count' CGGlyphs, at the points specified by
 `positions'. Each element of `positions' specifies the position from the
 associated glyph; the positions are specified in user space. */

CG_EXTERN void CGContextShowGlyphsAtPositions(CGContextRef cg_nullable c,
                                              const CGGlyph * cg_nullable glyphs, const CGPoint * cg_nullable Lpositions,
                                              size_t count)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/** PDF functions. **/
#pragma mark - 绘制PDF
/* Draw `page' in the current user space of the context `c'. */

CG_EXTERN void CGContextDrawPDFPage(CGContextRef cg_nullable c,
                                    CGPDFPageRef cg_nullable page)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Output page functions. **/

/* Begin a new page. */
#pragma mark - 建立一个基于页面的图形上下文

CG_EXTERN void CGContextBeginPage(CGContextRef cg_nullable c,
                                  const CGRect * __nullable mediaBox)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* End the current page. */

CG_EXTERN void CGContextEndPage(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Context functions. **/

/* Equivalent to `CFRetain(c)'. */
#pragma mark - 管理图形上下文
CG_EXTERN CGContextRef cg_nullable CGContextRetain(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Equivalent to `CFRelease(c)'. */

CG_EXTERN void CGContextRelease(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Flush all drawing to the destination. */

CG_EXTERN void CGContextFlush(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Synchronized drawing. */

CG_EXTERN void CGContextSynchronize(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Antialiasing functions. **/
#pragma mark - 锯齿功能
/* Turn on antialiasing if `shouldAntialias' is true; turn it off otherwise.
 This parameter is part of the graphics state. */
#pragma mark -设置图形上下文的抗锯齿开启或关闭
CG_EXTERN void CGContextSetShouldAntialias(CGContextRef cg_nullable c,
                                           bool shouldAntialias)
CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Allow antialiasing in `context' if `allowsAntialiasing' is true; don't
 allow it otherwise. This parameter is not part of the graphics state. A
 context will perform antialiasing if both `allowsAntialiasing' and the
 graphics state parameter `shouldAntialias' are true. */

CG_EXTERN void CGContextSetAllowsAntialiasing(CGContextRef cg_nullable c,
                                              bool allowsAntialiasing)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Font display functions. **/
#pragma mark - 字体展示功能

/* Turn on font smoothing if `shouldSmoothFonts' is true; turn it off
 otherwise. This parameter is part of the graphics state. Note that this
 doesn't guarantee that font smoothing will occur: not all destination
 contexts support font smoothing. */

CG_EXTERN void CGContextSetShouldSmoothFonts(CGContextRef cg_nullable c,
                                             bool shouldSmoothFonts)
CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* If `allowsFontSmoothing' is true, then allow font smoothing when
 displaying text in `context'; otherwise, don't allow font smoothing. This
 parameter is not part of the graphics state. Fonts will be smoothed if
 they are antialiased when drawn and if both `allowsFontSmoothing' and the
 graphics state parameter `shouldSmoothFonts' are true. */

CG_EXTERN void CGContextSetAllowsFontSmoothing(CGContextRef cg_nullable c,
                                               bool allowsFontSmoothing)
CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/* If `shouldSubpixelPositionFonts' is true, then glyphs may be placed at
 subpixel positions (if allowed) when displaying text in `context';
 otherwise, glyphs will be forced to integer pixel boundaries. This
 parameter is part of the graphics state. */

CG_EXTERN void CGContextSetShouldSubpixelPositionFonts(
                                                       CGContextRef cg_nullable c, bool shouldSubpixelPositionFonts)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* If `allowsFontSubpixelPositioning' is true, then allow font subpixel
 positioning when displaying text in `context'; otherwise, don't allow
 subpixel positioning. This parameter is not part of the graphics state. A
 context will place glyphs at subpixel positions if fonts will be
 antialiased when drawn and if both `allowsFontSubpixelPositioning' and
 the graphics state parameter `shouldSubpixelPositionFonts' are true. */

CG_EXTERN void CGContextSetAllowsFontSubpixelPositioning(
                                                         CGContextRef cg_nullable c, bool allowsFontSubpixelPositioning)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* If `shouldSubpixelQuantizeFonts' is true, then quantize the subpixel
 positions of glyphs when displaying text in `context'; otherwise, don't
 quantize the subpixel positions. This parameter is part of the graphics
 state. */

CG_EXTERN void CGContextSetShouldSubpixelQuantizeFonts(
                                                       CGContextRef cg_nullable c, bool shouldSubpixelQuantizeFonts)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* If `allowsFontSubpixelQuantization' is true, then allow font subpixel
 quantization when displaying text in `context'; otherwise, don't allow
 subpixel quantization. This parameter is not part of the graphics state.
 A context quantizes subpixel positions if glyphs will be drawn at
 subpixel positions and `allowsFontSubpixelQuantization' and the graphics
 state parameter `shouldSubpixelQuantizeFonts' are both true. */

CG_EXTERN void CGContextSetAllowsFontSubpixelQuantization(
                                                          CGContextRef cg_nullable c, bool allowsFontSubpixelQuantization)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/** Transparency layer support. **/
#pragma mark - 使用透明图层

/* Begin a transparency layer in `context'. All subsequent drawing
 operations until a corresponding `CGContextEndTransparencyLayer' are
 composited into a fully transparent backdrop (which is treated as a
 separate destination buffer from the context). After the transparency
 layer is ended, the result is composited into the context using the
 global alpha and shadow state of the context. This operation respects the
 clipping region of the context. After a call to this function, all of the
 parameters in the graphics state remain unchanged with the exception of
 the following:
 - The global alpha is set to 1.
 - The shadow is turned off.
 - The blend mode is set to `kCGBlendModeNormal'.
 Ending the transparency layer restores these parameters to the values
 they had before `CGContextBeginTransparencyLayer' was called.
 Transparency layers may be nested. */
/**
 Quartz的透明层类似于许多流行的图形应用中的层。层是独立的实体。Quartz维护为每个上下文维护一个透明层栈，并且透明层是可以嵌套的。但由于层通常是栈的一部分，所以我们不能单独操作它们。
 
 我们通过调用函数CGContextBeginTransparencyLayer来开始一个透明层，该函数需要两个参数：图形上下文与CFDictionary对象。字典中包含我们所提供的指定层额外信息的选项，但由于Quartz 2D API中没有使用字典，所以我们传递一个NULL。在调用这个函数后，图形状态参数保持不变，除了alpha值[默认设置为1]、阴影[默认关闭]、混合模式[默认设置为normal]、及其它影响最终组合的参数。
 在开始透明层操作后，我们可以绘制任何想显示在层上的对象。指定上下文中的绘制操作将被当成一个组合对象绘制到一个透明背景上。这个背景被当作一个独立于图形上下文的目标缓存。
 当绘制完成后，我们调用函数CGContextEndTransparencyLayer。Quartz将结合对象放入上下文，并使用上下文的全局alpha值、阴影状态及裁减区域作用于组合对象。
 
 在透明层中绘制需要三步：
    1.调用函数CGContextBeginTransparencyLayer
    2.在透明层中绘制需要组合的对象
    3.调用函数CGContextEndTransparencyLayer
 */

//直到相应的调用CGContextEndTransparencyLayer，在指定范围内的所有后续绘制操作组合到一个完全透明的背景（它被视为一个单独的目标缓冲区从上下文）
CG_EXTERN void CGContextBeginTransparencyLayer(CGContextRef cg_nullable c,
                                               CFDictionaryRef __nullable auxiliaryInfo)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);
/**
 //代码示例：
 CGContextBeginTransparencyLayer(context, NULL);
 
 CGFloat wd = 300;
 CGFloat ht = 300;
 CGContextSetFillColorWithColor(context, [UIColor greenColor].CGColor);
 CGContextFillRect(context, CGRectMake (wd/3 + 50, ht/2, wd/4, ht/4));
 
 CGContextEndTransparencyLayer(context);
 */


/* Begin a transparency layer in `context'. This function is identical to
 `CGContextBeginTransparencyLayer' except that the content of the
 transparency layer will be bounded by `rect' (specified in user space). */

CG_EXTERN void CGContextBeginTransparencyLayerWithRect(
                                                       CGContextRef cg_nullable c, CGRect rect, CFDictionaryRef __nullable auxInfo)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* End a tranparency layer. */

CG_EXTERN void CGContextEndTransparencyLayer(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** User space to device space tranformations. **/
#pragma mark - 用户空间与设备空间互换
/* Return the affine transform mapping the user space (abstract coordinates)
 of `context' to device space (pixels). */

CG_EXTERN CGAffineTransform
CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef cg_nullable c)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Transform `point' from the user space of `context' to device space. */

CG_EXTERN CGPoint CGContextConvertPointToDeviceSpace(CGContextRef cg_nullable c,
                                                     CGPoint point)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Transform `point' from device space to the user space of `context'. */

CG_EXTERN CGPoint CGContextConvertPointToUserSpace(CGContextRef cg_nullable c,
                                                   CGPoint point)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Transform `size' from the user space of `context' to device space. */

CG_EXTERN CGSize CGContextConvertSizeToDeviceSpace(CGContextRef cg_nullable c,
                                                   CGSize size)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Transform `size' from device space to the user space of `context'. */

CG_EXTERN CGSize CGContextConvertSizeToUserSpace(CGContextRef cg_nullable c,
                                                 CGSize size)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Transform `rect' from the user space of `context' to device space. Since
 affine transforms do not preserve rectangles in general, this function
 returns the smallest rectangle which contains the transformed corner
 points of `rect'. */

CG_EXTERN CGRect CGContextConvertRectToDeviceSpace(CGContextRef cg_nullable c,
                                                   CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Transform `rect' from device space to the user space of `context'. Since
 affine transforms do not preserve rectangles in general, this function
 returns the smallest rectangle which contains the transformed corner
 points of `rect'. */

CG_EXTERN CGRect CGContextConvertRectToUserSpace(CGContextRef cg_nullable c,
                                                 CGRect rect)
CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Deprecated functions. **/

/* DEPRECATED; use the CoreText API instead. */

CG_EXTERN void CGContextSelectFont(CGContextRef cg_nullable c,
                                   const char * cg_nullable name, CGFloat size, CGTextEncoding textEncoding)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_9,
                            __IPHONE_2_0, __IPHONE_7_0);

/* DEPRECATED; use the CoreText API instead. */

CG_EXTERN void CGContextShowText(CGContextRef cg_nullable c,
                                 const char * cg_nullable string, size_t length)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_9,
                            __IPHONE_2_0, __IPHONE_7_0);

/* DEPRECATED; use the CoreText API instead. */

CG_EXTERN void CGContextShowTextAtPoint(CGContextRef cg_nullable c,
                                        CGFloat x, CGFloat y, const char * cg_nullable string, size_t length)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_9,
                            __IPHONE_2_0, __IPHONE_7_0);

/* DEPRECATED; use the CoreText API instead. */

CG_EXTERN void CGContextShowGlyphs(CGContextRef cg_nullable c,
                                   const CGGlyph * __nullable g, size_t count)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_9,
                            __IPHONE_2_0, __IPHONE_7_0);

/* DEPRECATED; use the CoreText API instead. */

CG_EXTERN void CGContextShowGlyphsAtPoint(CGContextRef cg_nullable c, CGFloat x,
                                          CGFloat y, const CGGlyph * __nullable glyphs, size_t count)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_9,
                            __IPHONE_2_0, __IPHONE_7_0);

/* DEPRECATED; use the CoreText API instead. */

CG_EXTERN void CGContextShowGlyphsWithAdvances(CGContextRef cg_nullable c,
                                               const CGGlyph * __nullable glyphs, const CGSize * __nullable advances,
                                               size_t count)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_3, __MAC_10_9,
                            __IPHONE_2_0, __IPHONE_7_0);

/* DEPRECATED; use the CGPDFPage API instead. */

CG_EXTERN void CGContextDrawPDFDocument(CGContextRef cg_nullable c, CGRect rect,
                                        CGPDFDocumentRef cg_nullable document, int page)
CG_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_5,
                            __IPHONE_NA, __IPHONE_NA);

CF_ASSUME_NONNULL_END

CF_IMPLICIT_BRIDGING_DISABLED

#endif /* CGCONTEXT_H_ */
