/*
 * XCTestAssertions.h 断言
 *
 * XCTest  (c) 2013-2015
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

// Copyright (c) 1997-2005, Sen:te (Sente SA).  All rights reserved.
//
// Use of this source code is governed by the following license:
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL Sente SA OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
// OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Note: this license is equivalent to the FreeBSD license.
//
// This notice may not be removed from this file.


#pragma mark - 测试语法
#import <XCTest/XCTestAssertionsImpl.h>

/*!
 * @function XCTFail(...)
 * Generates a failure unconditionally.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTFail(...) \
_XCTPrimitiveFail(self, __VA_ARGS__)
XCTFail(@"this is a fail test");  // 生成一个失败的测试

/*!
 * @define XCTAssertNil(expression, ...)
 * Generates a failure when ((\a expression) != nil).
 * @param expression An expression of id type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNil(expression, ...) \
_XCTPrimitiveAssertNil(self, expression, @#expression, __VA_ARGS__)
XCTAssertNil(@"not a nil string",@"string must be nil"); // XCTAssertNil(a1, format...) 为空判断， a1 为空时通过，反之不通过；
XCTAssertNil(@"",@"string must be nil");  // 注意@"" 一样无法通过
XCTAssertNil(nil,@"object must be nil");


/*!
 * @define XCTAssertNotNil(expression, ...)
 * Generates a failure when ((\a expression) == nil).
 * @param expression An expression of id type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNotNil(expression, ...) \
_XCTPrimitiveAssertNotNil(self, expression, @#expression, __VA_ARGS__)
XCTAssertNotNil(a1, format…) 不为nil 判断，a1不为  nil 时通过，反之不通过；


/*!
 * @define XCTAssert(expression, ...)
 * Generates a failure when ((\a expression) == false).
 * @param expression An expression of boolean type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssert(expression, ...) \
_XCTPrimitiveAssertTrue(self, expression, @#expression, __VA_ARGS__)
XCTAssert(expression, format...) 当expression求值为TRUE时通过； expression 为一个表达式
XCTAssert((2 > 2), @"expression must be true");
XCTAssert((3>2),@"expression is true");


/*!
 * @define XCTAssertTrue(expression, ...)
 * Generates a failure when ((\a expression) == false).
 * @param expression An expression of boolean type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertTrue(expression, ...) \
_XCTPrimitiveAssertTrue(self, expression, @#expression, __VA_ARGS__)
XCTAssertTrue(expression, format...) 当expression求值为TRUE时通过；>0 的都视为 true
XCTAssertTrue(1, @"Can not be zero");


/*!
 * @define XCTAssertFalse(expression, ...)
 * Generates a failure when ((\a expression) != false).
 * @param expression An expression of boolean type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertFalse(expression, ...) \
_XCTPrimitiveAssertFalse(self, expression, @#expression, __VA_ARGS__)
XCTAssertFalse(expression, format...) 当expression求值为False时通过；
XCTAssertFalse((2 < 2), @"expression must be false");


/*!
 * @define XCTAssertEqualObjects(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) not equal to (\a expression2)).
 * @param expression1 An expression of id type.
 * @param expression2 An expression of id type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertEqualObjects(expression1, expression2, ...) \
_XCTPrimitiveAssertEqualObjects(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)
XCTAssertEqualObjects(a1, a2, format...) 判断相等， [a1 isEqual:a2] 值为TRUE时通过，其中一个不为空时，不通过；
XCTAssertEqualObjects(@"1", @"1", @"[a1 isEqual:a2] should return YES");
XCTAssertEqualObjects(@"1", @"2", @"[a1 isEqual:a2] should return YES");


/*!
 * @define XCTAssertNotEqualObjects(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) equal to (\a expression2)).
 * @param expression1 An expression of id type.
 * @param expression2 An expression of id type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNotEqualObjects(expression1, expression2, ...) \
_XCTPrimitiveAssertNotEqualObjects(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)
XCTAssertNotEqualObjects(a1, a2, format...) 判断不等， [a1 isEqual:a2] 值为False时通过，
XCTAssertNotEqualObjects(@"1", @"1", @"[a1 isEqual:a2] should return NO");
XCTAssertNotEqualObjects(@"1", @"2", @"[a1 isEqual:a2] should return NO");


/*!
 * @define XCTAssertEqual(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) != (\a expression2)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertEqual(expression1, expression2, ...) \
_XCTPrimitiveAssertEqual(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)
XCTAssertEqual(a1, a2, format...) 判断相等（当a1和a2是 C语言标量、结构体或联合体时使用,实际测试发现NSString也可以）；
#warning 示例
// 1.比较基本数据类型变量
    XCTAssertEqual(1, 2, @"a1 = a2 shoud be true"); // 无法通过测试
    XCTAssertEqual(1, 1, @"a1 = a2 shoud be true"); // 通过测试

// 2.比较NSString对象
    NSString *str1 = @"1";
    NSString *str2 = @"1";
    NSString *str3 = str1;
    XCTAssertEqual(str1, str2, @"a1 and a2 should point to the same object"); // 通过测试
    XCTAssertEqual(str1, str3, @"a1 and a2 should point to the same object"); // 通过测试

// 3.比较NSArray对象
    NSArray *array1 = @[@1];
    NSArray *array2 = @[@1];
    NSArray *array3 = array1;

    XCTAssertEqual(array1, array2, @"a1 and a2 should point to the same object"); // 无法通过测试
    XCTAssertEqual(array1, array3, @"a1 and a2 should point to the same object"); // 通过测试


/*!
 * @define XCTAssertNotEqual(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) == (\a expression2)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNotEqual(expression1, expression2, ...) \
_XCTPrimitiveAssertNotEqual(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)
XCTAssertNotEqual(a1, a2, format...) 判断不等（当a1和a2是 C语言标量、结构体或联合体时使用）；


/*!
 * @define XCTAssertEqualWithAccuracy(expression1, expression2, accuracy, ...)
 * Generates a failure when (difference between (\a expression1) and (\a expression2) is > (\a accuracy))).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param accuracy An expression of C scalar type describing the maximum difference between \a expression1 and \a expression2 for these values to be considered equal.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertEqualWithAccuracy(expression1, expression2, accuracy, ...) \
_XCTPrimitiveAssertEqualWithAccuracy(self, expression1, @#expression1, expression2, @#expression2, accuracy, @#accuracy, __VA_ARGS__)
XCTAssertEqualWithAccuracy(1.0f, 1.5f, 0.25f, @"a1 = a2 in accuracy should return NO");  // 测试没法通过


/*!
 * @define XCTAssertNotEqualWithAccuracy(expression1, expression2, accuracy, ...)
 * Generates a failure when (difference between (\a expression1) and (\a expression2) is <= (\a accuracy)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param accuracy An expression of C scalar type describing the maximum difference between \a expression1 and \a expression2 for these values to be considered equal.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNotEqualWithAccuracy(expression1, expression2, accuracy, ...) \
_XCTPrimitiveAssertNotEqualWithAccuracy(self, expression1, @#expression1, expression2, @#expression2, accuracy, @#accuracy, __VA_ARGS__)
XCTAssertNotEqualWithAccuracy(a1, a2, accuracy, format...) 判断不等，（double或float类型）提供一个误差范围，当在误差范围以内不等时通过测试；
XCTAssertNotEqualWithAccuracy(1.0f, 1.5f, 0.25f, @"a1 = a2 in accuracy should return NO");  // 测试通过


/*!
 * @define XCTAssertGreaterThan(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) <= (\a expression2)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertGreaterThan(expression1, expression2, ...) \
_XCTPrimitiveAssertGreaterThan(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)

/*!
 * @define XCTAssertGreaterThanOrEqual(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) < (\a expression2)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertGreaterThanOrEqual(expression1, expression2, ...) \
_XCTPrimitiveAssertGreaterThanOrEqual(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)

/*!
 * @define XCTAssertLessThan(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) >= (\a expression2)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertLessThan(expression1, expression2, ...) \
_XCTPrimitiveAssertLessThan(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)

/*!
 * @define XCTAssertLessThanOrEqual(expression1, expression2, ...)
 * Generates a failure when ((\a expression1) > (\a expression2)).
 * @param expression1 An expression of C scalar type.
 * @param expression2 An expression of C scalar type.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertLessThanOrEqual(expression1, expression2, ...) \
_XCTPrimitiveAssertLessThanOrEqual(self, expression1, @#expression1, expression2, @#expression2, __VA_ARGS__)

/*!
 * @define XCTAssertThrows(expression, ...)
 * Generates a failure when ((\a expression) does not throw).
 * @param expression An expression.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertThrows(expression, ...) \
_XCTPrimitiveAssertThrows(self, expression, @#expression, __VA_ARGS__)
XCTAssertThrows(expression, format...) 异常测试，当expression发生异常时通过；反之不通过；


/*!
 * @define XCTAssertThrowsSpecific(expression, exception_class, ...)
 * Generates a failure when ((\a expression) does not throw \a exception_class).
 * @param expression An expression.
 * @param exception_class The class of the exception. Must be NSException, or a subclass of NSException.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertThrowsSpecific(expression, exception_class, ...) \
_XCTPrimitiveAssertThrowsSpecific(self, expression, @#expression, exception_class, __VA_ARGS__)
XCTAssertThrowsSpecific(expression, specificException, format...) 异常测试，当expression发生 specificException 异常时通过；反之发生其他异常或不发生异常均不通过；


/*!
 * @define XCTAssertThrowsSpecificNamed(expression, exception_class, exception_name, ...)
 * Generates a failure when ((\a expression) does not throw \a exception_class with \a exception_name).
 * @param expression An expression.
 * @param exception_class The class of the exception. Must be NSException, or a subclass of NSException.
 * @param exception_name The name of the exception.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertThrowsSpecificNamed(expression, exception_class, exception_name, ...) \
_XCTPrimitiveAssertThrowsSpecificNamed(self, expression, @#expression, exception_class, exception_name, __VA_ARGS__)
XCTAssertThrowsSpecificNamed(expression, specificException, exception_name, format...) 异常测试，当expression发生具体异常、具体异常名称的异常时通过测试，反之不通过；


/*!
 * @define XCTAssertNoThrow(expression, ...)
 * Generates a failure when ((\a expression) throws).
 * @param expression An expression.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNoThrow(expression, ...) \
_XCTPrimitiveAssertNoThrow(self, expression, @#expression, __VA_ARGS__)
XCTAssertNoThrow(expression, format…) 异常测试，当expression没有发生异常时通过测试；


/*!
 * @define XCTAssertNoThrowSpecific(expression, exception_class, ...)
 * Generates a failure when ((\a expression) throws \a exception_class).
 * @param expression An expression.
 * @param exception_class The class of the exception. Must be NSException, or a subclass of NSException.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNoThrowSpecific(expression, exception_class, ...) \
_XCTPrimitiveAssertNoThrowSpecific(self, expression, @#expression, exception_class, __VA_ARGS__)
XCTAssertNoThrowSpecific(expression, specificException, format...)异常测试，当expression没有发生具体异常、具体异常名称的异常时通过测试，反之不通过；


/*!
 * @define XCTAssertNoThrowSpecificNamed(expression, exception_class, exception_name, ...)
 * Generates a failure when ((\a expression) throws \a exception_class with \a exception_name).
 * @param expression An expression.
 * @param exception_class The class of the exception. Must be NSException, or a subclass of NSException.
 * @param exception_name The name of the exception.
 * @param ... An optional supplementary description of the failure. A literal NSString, optionally with string format specifiers. This parameter can be completely omitted.
 */
#define XCTAssertNoThrowSpecificNamed(expression, exception_class, exception_name, ...) \
_XCTPrimitiveAssertNoThrowSpecificNamed(self, expression, @#expression, exception_class, exception_name, __VA_ARGS__)
XCTAssertNoThrowSpecificNamed(expression, specificException, exception_name, format...) 异常测试，当expression没有发生具体异常、具体异常名称的异常时通过测试，反之不通过


