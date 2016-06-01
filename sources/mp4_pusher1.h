#ifndef _MP4_PUSHER1_H_
#define _MP4_PUSHER1_H_

#include <xmedia.h>

#include "media_pusher.h"

namespace flvpusher {

class MP4Parser;

class MP4Pusher1 : public MediaPusher {
public:
    MP4Pusher1(const std::string &input,
            RtmpHandler *&rtmp_hdl);
    virtual ~MP4Pusher1();

    virtual int loop();

    virtual void ask2quit();

private:
    static int parsed_frame_cb(void *, xmedia::Frame *, int);

    int prepare();

    int send_metadata();

private:
    MP4Parser *m_parser;

    int32_t m_prev_ts;
    uint64_t m_tm_start;

    uint32_t m_width;
    uint32_t m_height;
};

}

#endif /* end of _MP4_PUSHER1_H_ */