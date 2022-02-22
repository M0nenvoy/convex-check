#include <memory.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "TgaImage.h"

TgaImage::TgaImage (int w, int h)
    : data(nullptr), w(w), h(h) {
    int bytes   = w*h*3;
    data        = new u8 [bytes];
    memset(data, 0, bytes);
}
TgaImage::~TgaImage () {
    delete [] data;
}

bool TgaImage::write2file(const char* filename) {
    int file    = open(filename, O_RDWR | O_CREAT, S_IWRITE | S_IREAD);

    if (file == -1)
        return false;

    TgaHeader header;
    int bytes = w * h * 3;

    memset ( &header, 0, sizeof(header));

    header.image_type   = 2;
    header.w            = w;
    header.h            = h;
    header.pixel_size   = 24;

    write(file, &header, sizeof(header));
    write(file, data, bytes);
    close(file);

    return true;
}

void TgaImage::clear() {
    memset(data, 0, w * h * 3);
}

void TgaImage::set_rgb(const u8 * ptr) {
    int bytes   = w * h;
    int offset  = 0;
    for (int i = 0; i < bytes; i++, offset += 3) {
        data [offset]       = ptr [offset + 2];
        data [offset + 1]   = ptr [offset + 1];
        data [offset + 2]   = ptr [offset];
    }
}
