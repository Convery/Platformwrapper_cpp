/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Basic CSV IO.
*/

#include "../../Stdinclude.h"

// Reimplementation of standard functionality.
#if defined (_WIN32)
char *strsep(char **String, const char *Delimiter)
{
    char *Start = *String;
    char *Part;

    Part = (Start != NULL) ? strpbrk(Start, Delimiter) : NULL;

    if (Part == NULL)
        *String = NULL;
    else
    {
        *Part = '\0';
        *String = Part + 1;
    }

    return Start;
}
#endif

bool CSV::Readfile(const char *Filepath)
{
    FILE *Filehandle{ nullptr };
    char *InputString = new char[1024]();
    size_t Linecount{ 0 };
    char *Tempstring{ nullptr };
    char *Backupstring = InputString;

    // Ensure that the file exists.
    Filehandle = std::fopen(Filepath, "r");
    if (!Filehandle) return false;

    // Clear the old buffer.
    Entrybuffer.clear();

    // For each string in the file.
    while (std::fgets(InputString, 1024, Filehandle))
    {
        // If the line is empty, skip.
        if (strlen(InputString) < 2)
            continue;

        // If the line is a comment, skip.
        if (*InputString == '#')
            continue;

        // Create a new row in the buffer.
        Entrybuffer.push_back(std::vector<std::string>());
        Linecount++;

        // Split the string into tokens.
        while (true)
        {
            // Get next token.
            Tempstring = strsep(&InputString, ",\n\0");

            // Add the token or quit.
            if (Tempstring != nullptr)
            {
                // Remove any spaces before the value.
                while (*Tempstring == ' ')
                    Tempstring++;

                // Append the token and a null string if it's the end of the line.
                Entrybuffer[Linecount - 1].push_back(Tempstring);
            }
            else
                break;
        }

        // Clear the buffer.
        InputString = Backupstring;
        std::memset(InputString, 0, 1024);
    }

    delete[] InputString;
    std::fclose(Filehandle);
    return true;
}
bool CSV::Writefile(const char *Filepath)
{
    FILE *Filehandle{ nullptr };

    // Check that we have anything to write.
    if (Entrybuffer.size() == 0)
        return false;

    // Create the file.
    Filehandle = fopen(Filepath, "w");
    if (!Filehandle) return false;

    // Create the header.
    std::fputs("# This file is generated via Ayrias CSV utility.\n", Filehandle);
    std::fputs("# Layout:", Filehandle);
    for (size_t i = 0; i < Entrybuffer[0].size(); ++i)
        std::fputs(va(" %c,", 0x41 + i).c_str(), Filehandle);
    std::fputs("\n\n", Filehandle);

    // For each row.
    for (auto Iterator = Entrybuffer.begin(); Iterator != Entrybuffer.end(); ++Iterator)
    {
        for (auto Iterator2 = Iterator->begin(); Iterator2 != Iterator->end(); ++Iterator2)
            std::fputs(va(" %s,", Iterator2->c_str()).c_str(), Filehandle);
        std::fputs("\n", Filehandle);
    }

    std::fclose(Filehandle);
    return true;
}
std::string CSV::Getvalue(size_t Row, size_t Col)
{
    // Check rowcount.
    if (Row > Entrybuffer.size() - 1)
        return "";

    // Check colcount.
    if (Col > Entrybuffer[Row].size() - 1)
        return "";

    return Entrybuffer[Row][Col];
}
void CSV::Addrow(std::vector<std::string> Values)
{
    Entrybuffer.push_back(Values);
}
