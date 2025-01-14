//
// Created by lixiaoqing on 2021/8/8.
//

#ifndef LOG_LOG_H
#define LOG_LOG_H


#include <iostream>


/**
 * 下面这些强枚举类不放入 LogCommon 中的原因是：尽量少的避免本头文件暴露过多内容。
 * 如果放在 LogCommon 中的话需要引入 LogCommon.h , 这样会使本头文件暴露过多内容
 */

/**
 * 日志类型。不同类型日志需要写入到不同文件中
 */
enum class LogType {
    Normal = 0,  /* 常规日志，包括 Debug、Info、Warn 级别日志 */
    Error,       /* 错误日志，即 Error 级别日志 */
};

/**
 * 日志级别
 */
enum class LogLevel {
    Debug = 0,
    Info,
    Warn,
    Error
};


/**
 * 日志类。提供日志相关外部接口
 * 该类不可被继承。
 */
class Log final {

public:

    /**
     * 日志初始化操作
     * 注意：必须在调用日志打印接口之前被调用！
     * @param logDir 日志文件的根目录
     */
    static bool Init(const char *root_dir);

    /**
     * 释放资源，退出时调用。
     * 注意：调用此方法后就不能再调用 Log 的相关方法存储日志！
     * @return
     */
    static void Stop();

    /**
     * Debug 日志信息
     * @param tag    标签
     * @param format 格式化字符串
     * @param ...    可变参数
     */
    static void Debug(const char *tag, const char *format, ...);

    static void Info(const char *tag, const char *format, ...);

    static void Warn(const char *tag, const char *format, ...);

    static void Error(const char *tag, const char *format, ...);

public:

    /**
     * 禁用构造函数
     */
    Log() = delete;

    /**
     * 禁用析构函数
     */
    ~Log() = delete;

    /**
     * 禁用拷贝构造函数
     * @param log
     */
    Log(const Log &log) = delete;

    /**
     * 禁用赋值构造函数
     * @param log
     * @return
     */
    Log &operator=(const Log &log) = delete;

private:

    /**
     * 存储日志
     * @param type
     * @param level
     * @param tag
     * @param log
     */
    static bool Save(LogType type, LogLevel level, const char *tag, const char *log);
};


#endif //LOG_LOG_H
