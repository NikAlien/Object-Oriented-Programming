#include "FileAdoptList.h"

FileAdoptList::FileAdoptList(const std::string &_filename, const std::string &_repofilename) : Repository(_repofilename) {
    filename = _filename;
}
