extern "C" {
    #include <libavutil/log.h>
    #include <libavcodec/codec.h>
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ffmpeg_log(int l, char* t) {
    if(l <= AV_LOG_INFO)
        fprintf(stdout, ">>> %s\n", t);
}

static void log_callback(void *avcl, int level, const char *fmt, va_list vl) 
{
    (void) avcl;
    char log[1024] = {0};
    int n = vsnprintf(log, 1024, fmt, vl);
    if (n > 0 && log[n - 1] == '\n')
        log[n - 1] = 0;
    if (strlen(log) == 0)
        return;
    ffmpeg_log(level, log);
}

void set_log_callback()
{
    // 给 av 解码器注册日志回调函数
    av_log_set_callback(log_callback);
}