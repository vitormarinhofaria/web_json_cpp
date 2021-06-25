#include "include/xlsxwriter.h"
// #include <emscripten/bind.h>
#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>

size_t file_size = 0;
std::vector<unsigned char> fileBuffer;
char *membuff;

extern "C"
{
    unsigned char *get_sheet()
    {
        return (unsigned char*)membuff;
    }
    void gen_sheet()
    {
        std::cout << "Iniciando\n";
        lxw_workbook *workbook = workbook_new("demo.xlsx");
        lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

        /* Add a format. */
        lxw_format *format = workbook_add_format(workbook);

        /* Set the bold property for the format */
        format_set_bold(format);

        /* Change the column width for clarity. */
        worksheet_set_column(worksheet, 0, 0, 20, NULL);

        /* Write some simple text. */
        worksheet_write_string(worksheet, 0, 0, "Hello", NULL);

        /* Text with formatting. */
        worksheet_write_string(worksheet, 1, 0, "World", format);

        /* Write some numbers. */
        worksheet_write_number(worksheet, 2, 0, 123, NULL);
        worksheet_write_number(worksheet, 3, 0, 123.456, NULL);

        /* Insert an image. */

        workbook_close(workbook);

        std::ifstream input("demo.xlsx", std::ios::in | std::ios::binary | std::ios::ate);

        file_size = input.tellg();
        membuff = new char[file_size];
        input.seekg(0, std::ios::beg);
        input.read(membuff, file_size);
        input.close();

        // copies all data into buffer

        for (int i = 0; i < 15; i++)
        {
            std::cout << "FileBuffer " << (int)membuff[i] << std::endl;
        }
        std::cout << file_size << std::endl;
    }
    int get_file_size()
    {
        gen_sheet();
        return file_size;
    }
}

int main(int argc, char **argv)
{
    std::cout << "Iniciando\n";
    lxw_workbook *workbook = workbook_new("demo.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    /* Add a format. */
    lxw_format *format = workbook_add_format(workbook);

    /* Set the bold property for the format */
    format_set_bold(format);

    /* Change the column width for clarity. */
    worksheet_set_column(worksheet, 0, 0, 20, NULL);

    /* Write some simple text. */
    worksheet_write_string(worksheet, 0, 0, "Hello", NULL);

    /* Text with formatting. */
    worksheet_write_string(worksheet, 1, 0, "World", format);

    /* Write some numbers. */
    worksheet_write_number(worksheet, 2, 0, 123, NULL);
    worksheet_write_number(worksheet, 3, 0, 123.456, NULL);

    /* Insert an image. */

    workbook_close(workbook);

    std::ifstream input("demo.xlsx", std::ios::in | std::ios::binary | std::ios::ate);

    file_size = input.tellg();
    membuff = new char[file_size];
    input.seekg(0, std::ios::beg);
    input.read(membuff, file_size);
    input.close();

    // copies all data into buffer

    for (int i = 0; i < 15; i++)
    {
        std::cout << "FileBuffer " << (int)membuff[i] << std::endl;
    }
    std::cout << file_size << std::endl;
}
