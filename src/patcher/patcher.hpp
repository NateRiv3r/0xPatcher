#ifndef __PATCHER_H__
#define __PATCHER_H__

class Patcher {
    public:
        Patcher() = default;
        void copy_file() const;
        void patch();
};

#endif