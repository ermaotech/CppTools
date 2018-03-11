#include "FileOperation.h"
#include <algorithm>
#include <iterator>
#include <windows.h>

FileOperation::FileOperation() : dirname_("D:/web/new/"), suffix_("html"),
    file_list_(new std::vector<std::string>()), error_code_(0)
{

}

FileOperation::FileOperation(std::string dir, std::string suffix) :
    dirname_(dir), suffix_(suffix), file_list_(new std::vector<std::string>()),  error_code_(0)
{
    dirname_+= "/";
}

FileOperation::~FileOperation()
{
    delete file_list_;
}

bool FileOperation::RenameFile()
{
    this->FindFiles();
    for(std::string &file_data : *file_list_) {
        //从尾部开始找‘.’，中间的.不修改
//        auto name_iter = std::find(file_data.cbegin(), file_data.cend(), '.');
        auto name_iter = std::find(file_data.crbegin(), file_data.crend(), '.');
        std::string name = std::string(file_data.cbegin(), name_iter.base());
        name += suffix_;
        name = dirname_ + name;

        if ( rename((dirname_ + file_data).c_str(), name.c_str()) != 0) {
            error_code_ = -1;
            err_msg_ += "文件"+ file_data +"更改失败";
        }
    }
    return true;
}

void FileOperation::FindFiles()
{

    LPCSTR dirname = (dirname_ + "*").c_str();
    handle_ = ::FindFirstFileA(dirname, &current_file_);
    if (handle_ != INVALID_HANDLE_VALUE) {
        if (FindNext())
            while (FindNext()) {
                file_list_->push_back(current_file_.cFileName);
            }
    }
    ::FindClose(handle_);
}

bool FileOperation::FindNext()
{
    return ::FindNextFileA(handle_, &current_file_);
}
