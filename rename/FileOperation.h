#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include <stdio.h>
#include <string>
#include <vector>
#include <windows.h>

class FileOperation
{
public:
    FileOperation();
    FileOperation(std::string dir, std::string suffix);
    ~FileOperation();
    std::string err_msg() const { return err_msg_;}
    int error_code() const { return error_code_;}
    void set_error_code(int error_code) { error_code_ = error_code;}
    void set_err_msg(std::string err_msg) { err_msg_ = err_msg;}
    int Count() const { return file_list_->size();}
    bool RenameFile();
protected:
    void FindFiles();
private:
    std::string dirname_;
    std::string suffix_;
    std::string err_msg_;
    std::vector<std::string> *file_list_;
    WIN32_FIND_DATAA current_file_;
    HANDLE handle_;
    int error_code_;
    bool FindNext();
};

#endif // FILEOPERATION_H
